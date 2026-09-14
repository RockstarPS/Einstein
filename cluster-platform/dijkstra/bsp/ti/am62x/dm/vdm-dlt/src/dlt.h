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
 *  File Name         :  dlt.h                                                *
 *  Module Short Name :  Dlt                                                  *
 *  Description       :  This file contains implementations of the Diagnostic *
 *                       Log and Trace for DM 							      *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 ******************************************************************************/
#ifndef DLT_H
#define DLT_H
typedef enum
{
	DLT_LOG_OFF,
	DLT_LOG_FATAL,
	DLT_LOG_ERROR,
	DLT_LOG_WARN,
	DLT_LOG_INFO,
	DLT_LOG_DEBUG,
	DLT_LOG_VERBOSE
} DltLogLevelType;

#define IPC_LOG_BUFFER_MESSAGE_ENDPT 14
#define IPC_LOG_BUFFER_MESSAGE_REMOTE_ENDPT 14
#define IPC_CONFIRM_BUFFER_MESSAGE_REMOTE_ENDPT 14

//#define DLT_TEST_LOGGING

extern SemaphoreP_Object DLT_sem;

extern void DLT_init(void);
extern void DLT_LogMessage(DltLogLevelType log_level, uint16_t MsgID, uint8_t* payload, uint32_t payload_size, char*text);
extern void callback_DLT_TimerTick(uint32_t Elapsed_ms);
extern void	callback_DLT_VP_MESSAGE(uint8_t* recvMsg, uint32_t recvMsgSize);						
extern void EmmcDriverOpen(void);
#endif
