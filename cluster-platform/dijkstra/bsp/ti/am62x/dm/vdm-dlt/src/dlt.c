/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2017. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
/*****************************************************************************
 *  File Name         :  dlt.c                                                *
 *  Module Short Name :  Dlt                                                  *
 *  Description       :  This file contains implementations of the Diagnostic *
 *                       Log and Trace for DM 							      *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 ******************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <drivers/bootloader.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"
#include "FreeRTOS.h"
#include "task.h"
#include "program_cfg.h"
#include <dlt.h>

#ifdef DM_DLT_LOG_ENABLED
/*
 * Local macros
 * ----------------------------------
 */

#define UINT16_SWAP_BYTES(val)  ((((val) & 0xFF) << 8)  | (((val) >> 8) & 0xFF))
#define UINT32_SWAP_BYTES(val)  ((((val) & 0xFF) << 24)  | (((val) & 0xFF00) << 8)   | (((val) >> 8) & 0xFF00)   | (((val) >> 24) & 0xFF))


#define DLT_LOG_RAM_BUF_SIZE 2048
#define DLT_LOG_EMMC_MEM_SIZE (48*512) // 48 sectors
#define EMMC_DLT_DATA_BASE (14698496) // sector number
#define CONFIG_MMCSD_SBL 0
#define NUM_RAM_BUFFERS 2
#define MAX_BUFFERING_TIME 3000 // ms

#ifndef DLT_TEST_LOGGING
#undef DebugP_log
#define DebugP_log(...)
#endif

/*
 * Local types
 * ----------------------------------
 */
typedef struct
{
	uint8_t HTYP; // Bit 0: UEH (Use Extended Header)
                  // Bit 1: MSBF (Most Significant Byte First)
                  // Bit 2: WEID (With ECU ID)
                  // Bit 3: WSID (With Session ID)
                  // Bit 4: WTMS (With Timestamp)
                  // Bit 5-7: VERS (Version Number
	uint8_t MCNT; // message counter
	uint16_t LEN; // Length
    uint32_t ECU; // ECU ID
	// session ID not used uint32_t SEID; // Session ID
	uint32_t TMSP; // Timestamp
} __attribute__((packed)) tDLTMessageHeader;

typedef struct
{
	uint8_t MSIN;// (Message Info)
	uint8_t NOAR;/// (Number of Arguments)
    uint32_t APID;// (Application ID)
    uint32_t CTID;// (Context ID
} __attribute__((packed)) tDLTMessageExtHeader;

typedef struct
{
	uint32_t TypeInfo;
	uint16_t MessageID;
	uint8_t LogData[6];
} __attribute__((packed)) tDLTMessagePayload;

typedef struct
{
	uint32_t TypeInfo;
	uint16_t Length;
	char     text[28];
} __attribute__((packed)) tDLTMessageString;

typedef struct
{
	tDLTMessageHeader header;
	tDLTMessageExtHeader ext_header;
	tDLTMessagePayload payload;
	tDLTMessageString string;
} __attribute__((packed)) tDLTMessage;

typedef struct
{
	tDLTMessage msg[(DLT_LOG_EMMC_MEM_SIZE)/sizeof(tDLTMessage)];
	uint8_t padding[DLT_LOG_EMMC_MEM_SIZE - ((DLT_LOG_EMMC_MEM_SIZE)/sizeof(tDLTMessage))*sizeof(tDLTMessage)];
} __attribute__((packed)) tDLTMemEMMCBuffer;

typedef struct
{
	tDLTMessage msg[(DLT_LOG_RAM_BUF_SIZE)/sizeof(tDLTMessage)];
	uint8_t padding[DLT_LOG_RAM_BUF_SIZE - ((DLT_LOG_RAM_BUF_SIZE)/sizeof(tDLTMessage))*sizeof(tDLTMessage)];
} __attribute__((packed)) tDLTMemRAMBuffer;


typedef struct
{
	uint8_t msgID;
	uint8_t CRC;
	uint8_t Parameter;
} __attribute__((packed)) tDLTVPMessage;

/*
 * Global data
 * ----------------------------------
 */
SemaphoreP_Object DLT_RAM_sem;
extern SemaphoreP_Object eMMC_sem;

/*
 * Local data
 * ----------------------------------
 */
static uint8_t RAM_message_counter=0;
static uint32_t RAM_index[NUM_RAM_BUFFERS];
static uint32_t Buffer_timer_ms = 0;
static bool ReceiverReady = FALSE;
static uint8_t RAMBuffer_index;
static tDLTMemRAMBuffer DLT_RAM_buffer1 __attribute__ ((section (".dlt_buffer1_mem"), aligned (128)));
static tDLTMemRAMBuffer DLT_RAM_buffer2 __attribute__ ((section (".dlt_buffer2_mem"), aligned (128)));
static tDLTMemRAMBuffer * const DLT_RAM_buffer[NUM_RAM_BUFFERS] = {&DLT_RAM_buffer1,&DLT_RAM_buffer2};
static int32_t RAMBuffer_sent=-1;
static bool Initialized = FALSE;
static bool emmcFunctionActive = FALSE;
static bool eMMCOpenFailed = FALSE;
static bool eMMCLogLoaded = FALSE;
static uint8_t eMMC_message_counter=0;
static uint32_t eMMC_index;
static tDLTMemEMMCBuffer DLT_EMMC_buffer __attribute__ ((aligned (128)));

/*
 * Function: ConstructDLTmessage
 * ----------------------------------
 * Initializes a message buffer with DLT format content
 *
 * Returns:
 *  void
 */
static void ConstructDLTmessage(tDLTMessage * pDLTMessage, uint8_t message_counter, DltLogLevelType log_level, uint16_t message_id, uint8_t *logdata, uint32_t logdata_len, char* text)
{
	uint32_t time_u32 = (uint32_t)( GTC_getCount64() / 20000U ); // 0.1ms resolution
	pDLTMessage->header.HTYP = 0x37; // version 1, extended header, MSB, with ECU ID, with time stamp
	pDLTMessage->header.MCNT = message_counter;
	pDLTMessage->header.LEN = UINT16_SWAP_BYTES(sizeof(tDLTMessage));
	memcpy(&pDLTMessage->header.ECU,"DM\0\0",sizeof pDLTMessage->header.ECU);
	pDLTMessage->header.TMSP = UINT32_SWAP_BYTES(time_u32);
	pDLTMessage->ext_header.MSIN = 1 + ((log_level & 7)<< 4);
	pDLTMessage->ext_header.NOAR = 2;
	memcpy(&pDLTMessage->ext_header.APID,"APPB",sizeof pDLTMessage->ext_header.APID);
	memcpy(&pDLTMessage->ext_header.CTID,"CONB",sizeof pDLTMessage->ext_header.CTID);

	// argument 1
	pDLTMessage->payload.TypeInfo = 0x104; // 8-bytes payload
	pDLTMessage->payload.MessageID = UINT16_SWAP_BYTES(message_id);
	if (logdata_len>sizeof pDLTMessage->payload.LogData)
	{
		logdata_len = sizeof pDLTMessage->payload.LogData;
	}
	memset(&pDLTMessage->payload.LogData, 0, sizeof pDLTMessage->payload.LogData);
	memcpy(&pDLTMessage->payload.LogData, logdata, logdata_len);
	
	// argument 2
	memset(&pDLTMessage->string, 0, sizeof pDLTMessage->string);
    pDLTMessage->string.TypeInfo = 0x200; // string type	
	if (text!=NULL)
	{
		int32_t len=strlen(text);
		if (len>sizeof(pDLTMessage->string.text)-1)
		{
			len=sizeof(pDLTMessage->string.text)-1;
		}
		strncpy(pDLTMessage->string.text,text,len);
		pDLTMessage->string.text[sizeof(pDLTMessage->string.text)-1]=0; // termination just in case
		pDLTMessage->string.Length = len+1;
		pDLTMessage->string.Length = UINT16_SWAP_BYTES(pDLTMessage->string.Length);
	}
}

/*
 * Function: mountEMMCbuffer
 * ----------------------------------
 * Determine the current index and message counter from EMMC content
 *
 * Returns:
 *  void
 */
static void mountEMMCbuffer(void)
{
	uint32_t idx;
	const uint32_t count = sizeof(DLT_EMMC_buffer.msg)/sizeof(DLT_EMMC_buffer.msg[0]);
	
	// find the minimal msg counter
	int32_t minidx = -1;
	for (idx=0; idx<count; idx++)
	{
		if( (DLT_EMMC_buffer.msg[idx].header.HTYP==0x37) &&
		    (DLT_EMMC_buffer.msg[idx].header.LEN==UINT16_SWAP_BYTES(sizeof(tDLTMessage))))
		{
			if (minidx==-1) minidx=idx;
			 else
		    if (DLT_EMMC_buffer.msg[idx].header.MCNT < DLT_EMMC_buffer.msg[minidx].header.MCNT)
			{
				minidx = idx;
			}
		}
	}
	if (minidx==-1) 
	{
   		DebugP_log("DLT_EMMC_buffer - Nothing found, initial state\r\n");
		eMMC_message_counter=0;
		eMMC_index=0;
	}
	else
	{
		// find the last msg counter
		eMMC_message_counter=DLT_EMMC_buffer.msg[minidx].header.MCNT;
		eMMC_index=minidx;
		for (idx=minidx; idx<count*2; idx++)
		{
			uint32_t ix=idx;
			if (ix>=count) ix=idx-count;
		    if( (DLT_EMMC_buffer.msg[ix].header.MCNT==eMMC_message_counter) &&
		       (DLT_EMMC_buffer.msg[ix].header.HTYP==0x37) &&
			   (DLT_EMMC_buffer.msg[ix].header.LEN==UINT16_SWAP_BYTES(sizeof(tDLTMessage))))
			{
				eMMC_index++;
     			if (eMMC_index>=count) eMMC_index=eMMC_index-count;
				eMMC_message_counter++;
			} else 
			{
				break;
			}
		}
   		DebugP_log("DLT_EMMC_buffer - eMMC_index=%d, eMMC_message_counter=%d\r\n",eMMC_index,eMMC_message_counter);		
	}
}

/*
 * Function: DLT_LoadEMMCLog
 * ----------------------------------
 * Loads and mounts the EMMC buffer
 *
 * Returns:
 *  void
 */
static void DLT_LoadEMMCLog(void)
{
	if (gMmcsdHandle[CONFIG_MMCSD_SBL] != NULL)
	{
		int32_t status;
		status = MMCSD_read(gMmcsdHandle[CONFIG_MMCSD_SBL], (void*)&DLT_EMMC_buffer, EMMC_DLT_DATA_BASE, (sizeof DLT_EMMC_buffer)/512);
		if (status == SystemP_SUCCESS)
		{
			CacheP_inv(&DLT_EMMC_buffer, sizeof DLT_EMMC_buffer, CacheP_TYPE_ALL);
			emmcFunctionActive = TRUE;
			mountEMMCbuffer();
		}
		else
		{
			DebugP_logError("Can't load DLT log\r\n");
		}
	}
}

/*
 * Function: DLT_LogToEMMC
 * ----------------------------------
 * Log a new message to eMMC
 *
 * Returns:
 *  void
 */
static void DLT_LogToEMMC(DltLogLevelType log_level, uint16_t MsgID, uint8_t* payload, uint32_t payload_size, char *text)
{
	const uint32_t count = sizeof(DLT_EMMC_buffer.msg)/sizeof(DLT_EMMC_buffer.msg[0]);
	if (!emmcFunctionActive && !eMMCOpenFailed)
	{
		SemaphoreP_pend(&eMMC_sem,SystemP_WAIT_FOREVER);
		if (gMmcsdHandle[CONFIG_MMCSD_SBL] == NULL)
		{
			EmmcDriverOpen();
		}
		SemaphoreP_post(&eMMC_sem);
		if (gMmcsdHandle[CONFIG_MMCSD_SBL] == NULL)
		{
			eMMCOpenFailed = TRUE;
			return;
		}
	}

	SemaphoreP_pend(&eMMC_sem,SystemP_WAIT_FOREVER);
	if (!eMMCLogLoaded)
	{
	    DLT_LoadEMMCLog();
		eMMCLogLoaded = TRUE;
	}
	ConstructDLTmessage(&DLT_EMMC_buffer.msg[eMMC_index],eMMC_message_counter++,log_level,MsgID,payload,payload_size, text);
	/*uint8_t* p = (void*)&DLT_EMMC_buffer.msg[eMMC_index];
		int r;
		for (r=0; r<sizeof(tDLTMessage);r++)
		{
			DLT_DebugP_log("%02X ",*p);p++;
		}*/
	eMMC_index++;
	if (eMMC_index>=count)
	{
		eMMC_index=0;
	}
	if (gMmcsdHandle[CONFIG_MMCSD_SBL] != NULL)
	{
   		DebugP_log("eMMC DLT log writing to index %d\r\n",eMMC_index);
		memset(DLT_EMMC_buffer.padding,0,sizeof(DLT_EMMC_buffer.padding));
		CacheP_wb(&DLT_EMMC_buffer, sizeof DLT_EMMC_buffer, CacheP_TYPE_ALL);
		int32_t status = MMCSD_write(gMmcsdHandle[CONFIG_MMCSD_SBL], (void*)&DLT_EMMC_buffer, EMMC_DLT_DATA_BASE, (sizeof DLT_EMMC_buffer)/512);
		if (status != SystemP_SUCCESS)
		{
			emmcFunctionActive = FALSE; // eMMC no longer in sync
       		DebugP_logError("eMMC DLT log write error, logging stopped \r\n");
		}
	}
	SemaphoreP_post(&eMMC_sem);
}

/*
 * Function: SendBufferFullNotification
 * ----------------------------------
 * Send the current buffer number to receiver, switch to next buffer
 *
 * Returns:
 *  void
 */
static void SendBufferFullNotification(void)
{
	tDLTVPMessage msg;
	Buffer_timer_ms = 0;
	RAM_index[RAMBuffer_index]=1+sizeof(DLT_RAM_buffer1.msg)/sizeof(DLT_RAM_buffer1.msg[0]);

	CacheP_wb(DLT_RAM_buffer[RAMBuffer_index], sizeof DLT_RAM_buffer1, CacheP_TYPE_ALL);
	
	RAMBuffer_sent = RAMBuffer_index;

	RAMBuffer_index++;
	
	msg.msgID = 1;
	msg.CRC = 0;
	msg.Parameter = (uint8_t)RAMBuffer_index;

	RPMessage_send(
		&msg, sizeof msg,
		CSL_CORE_ID_MCU_R5FSS0_0, /*remoteCoreEndPt*/ IPC_LOG_BUFFER_MESSAGE_REMOTE_ENDPT,
		IPC_LOG_BUFFER_MESSAGE_ENDPT,
		SystemP_WAIT_FOREVER);

	if (RAMBuffer_index>=NUM_RAM_BUFFERS)
	{
		RAMBuffer_index=0;
	}
}

/*
 * Function: DLT_LogToRAM
 * ----------------------------------
 * Log to the current RAM buffer
 *
 * Returns:
 *  void
 */
static void DLT_LogToRAM(DltLogLevelType log_level, uint16_t MsgID, uint8_t* payload, uint32_t payload_size, char *text)
{
	const uint32_t count = sizeof(DLT_RAM_buffer1.msg)/sizeof(DLT_RAM_buffer1.msg[0]);

	SemaphoreP_pend(&DLT_RAM_sem,SystemP_WAIT_FOREVER);
	if (RAM_index[RAMBuffer_index]<count)
	{
       	DebugP_log("Log message %d,%d\r\n",RAMBuffer_index,RAM_index[RAMBuffer_index]);
		ConstructDLTmessage(&DLT_RAM_buffer[RAMBuffer_index]->msg[RAM_index[RAMBuffer_index]],RAM_message_counter++,log_level,MsgID,payload,payload_size, text);
		RAM_index[RAMBuffer_index]++;
		if (RAM_index[RAMBuffer_index]>=count)
		{
       		DebugP_log("Buffer full\r\n");
			SendBufferFullNotification();
		}
	}	
	SemaphoreP_post(&DLT_RAM_sem);
}


/*
 * Function: callback_DLT_TimerTick
 * ----------------------------------
 * Timer tick callback
 *
 * Returns:
 *  void
 */
void callback_DLT_TimerTick(uint32_t Elapsed_ms)
{
	const uint32_t count = sizeof(DLT_RAM_buffer1.msg)/sizeof(DLT_RAM_buffer1.msg[0]);
	SemaphoreP_pend(&DLT_RAM_sem,SystemP_WAIT_FOREVER);
	if( (RAM_index[RAMBuffer_index]>0) && (RAM_index[RAMBuffer_index]<=count) && (ReceiverReady))
	{
        Buffer_timer_ms += Elapsed_ms;
		if (Buffer_timer_ms>=MAX_BUFFERING_TIME)
		{
            // check next buffer
            uint32_t next = RAMBuffer_index+1;
            if (next>=NUM_RAM_BUFFERS) next=0;
            if (RAM_index[next]==0)
            { // the next buffer is ready, we can send current buffer by timeout
				DebugP_log("Buffer %d timeout\r\n",RAMBuffer_index);
                SendBufferFullNotification();
            }
		}
	}
	SemaphoreP_post(&DLT_RAM_sem);
}

/*
 * Function: callback_DLT_RAM_BufferEmptyNotification
 * ----------------------------------
 * Callback to indicate that a RAM buffer was received and can be reused
 *
 * Returns:
 *  void
 */
void callback_DLT_RAM_BufferEmptyNotification(uint8_t status)
{
	if ( (!ReceiverReady) && (status==1) )
	{  // first message from GIP, enable sending by timeout
		ReceiverReady = TRUE;
	}
	else
	{
		SemaphoreP_pend(&DLT_RAM_sem,SystemP_WAIT_FOREVER);
		if ((RAMBuffer_sent<NUM_RAM_BUFFERS)&&(RAMBuffer_sent>=0))
		{
			RAM_index[RAMBuffer_sent]=0;
			DebugP_log("Buffer %d confirmed\r\n",RAMBuffer_sent);
			memset(DLT_RAM_buffer[RAMBuffer_sent],0,sizeof DLT_RAM_buffer1);
			RAMBuffer_sent = -1;
		}		
		SemaphoreP_post(&DLT_RAM_sem);
	}
}

/*
 * Function: callback_DLT_VP_MESSAGE
 * ----------------------------------
 * Callback to indicate that a DLT vp message is received
 *
 * Returns:
 *  void
 */
void callback_DLT_VP_MESSAGE(uint8_t* recvMsg, uint32_t recvMsgSize)
{
	if (recvMsgSize==sizeof(tDLTVPMessage))
	{
		tDLTVPMessage * pDLTMessage = (tDLTVPMessage*)recvMsg;
		switch (pDLTMessage->msgID)
		{
			case 1: 
			{
				callback_DLT_RAM_BufferEmptyNotification(pDLTMessage->Parameter);
				break;
			}
			case 2:
			{
				/*if (recvMsgSize>=3) callback_DLT_RAM_SetLogLevel(recvMsg[2]);*/
				break;
			}
		}
	}
}


/*
 * Function: DLT_init
 * ----------------------------------
 * Initializes memory
 *
 * Returns:
 *  void
 */
void DLT_init(void)
{
	SemaphoreP_constructMutex(&DLT_RAM_sem);	
	RAM_message_counter=0; RAMBuffer_index=0;
	for (int idx=0; idx<NUM_RAM_BUFFERS; idx++)
	{
		memset(DLT_RAM_buffer[idx],0,sizeof DLT_RAM_buffer1);
		RAM_index[idx]=0; 
	}
	Buffer_timer_ms = 0;
	RAMBuffer_sent = -1;
	Initialized = TRUE;
}

/*
 * Function: DLT_LogMessage
 * ----------------------------------
 * Log a message 
 *
 * Returns:
 *  void
 */
void DLT_LogMessage(DltLogLevelType log_level, uint16_t MsgID, uint8_t* payload, uint32_t payload_size, char *text)
{
	if (Initialized)
	{
		DLT_LogToRAM(log_level,MsgID,payload,payload_size,text);
		if( (log_level == DLT_LOG_FATAL) || (log_level == DLT_LOG_ERROR) )
		{
			DLT_LogToEMMC(log_level,MsgID,payload,payload_size,text);
		}
	}
}

#else

void DLT_init(void) {}
void DLT_LoadEMMCLog(void) {}
void DLT_LogMessage(DltLogLevelType log_level, uint16_t MsgID, uint8_t* payload, uint32_t payload_size, char*text) {}
void callback_DLT_TimerTick(uint32_t Elapsed_ms) {}
void callback_DLT_VP_MESSAGE(uint8_t* recvMsg, uint32_t recvMsgSize) {}
#endif
