#include "stub_fkts.h"
#include "b515_vmf_ardu_gw.h"
#include "P32_RF_API.h"
#include "P32_SendQHandler.h"
#include "P32_CmdDefine.h"


#define 	DAB_FRQ_5A	174928	// 0x02ab50
#define 	DAB_FRQ_9A	202928	// 0x0318b0
#define 	DAB_FRQ_11A	216928	// 0x034f60
#define 	DAB_FRQ_11C	220352	// 0x035cc0



int	verbose = 2;



#define VMF_RECEIVER_STACK_SIZE     (64 * 1024)
#define VMF_TRACE_TASK_VMF          "PNP_LOG"
#define VMF_TRID_NAME				VMF_TRACE_TASK_VMF

static  vmf_client_id_t         	vmf_pnp_handle=-1;
unsigned8               			vmf_trid;
extern  vmf_client_id_t         	vmf_connection_handle;


static void *pnp_log_vmf_thread(void *pNoArg);

/*************************************************************************//**
 *
 *   This function will create the pnp_log_vmf_thread\n
 *	 
 *   \param[in]         void
 *
 *   \return            true if OK
 *
 ******************************************************************************/
bool create_pnp_log_vmf_thread(void)
{
    int             iRet;
    pthread_t       th;
    pthread_attr_t  attr;

    /* set thread stack */
    pthread_attr_init( &attr );
    if ( pthread_attr_setstacksize(&attr, VMF_RECEIVER_STACK_SIZE ) != 0 )
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "pthread_attr_setstacksize() failed");
    }

    (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED );
    iRet = pthread_create (&th  , &attr, pnp_log_vmf_thread, NULL);
    pthread_attr_destroy(&attr);
    if (iRet)
    {
        DEBUG_ERROR(VMF_TRACE_TASK_VMF, "pthread_create() failed witg = %d",iRet);
        return false;
    }

    return true;
}


/*************************************************************************//**
 *
 *   VMF thread\n
 *	 This thread will receive all VMF messages
 *
 *   \param[in]         vmf message
 *
 *   \return            void
 *
 ******************************************************************************/
static void *pnp_log_vmf_thread(void *pNoArg)
{
	vmf_ret_t vmf_ret;	
	PN_DEVICEID	devId;
	PN_U8	cmd[15];
	unsigned32	frq;
	int			cnt;
	

	/* connect to VMF */
	if (vmf_pnp_handle < 0)
	{
		vmf_ret = nw_vmf_connect("vmf_pnp_logic", 0, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, VMF_CLIENT_QUEUE_MSG_SIZE_STANDARD);
		if (vmf_ret < 0)
		{
			printf("send_basic_message: connect failed --error %d\n",(int)vmf_ret);
			return;
		}
		else
		{
			vmf_pnp_handle = (vmf_client_id_t)vmf_ret;
		}
	}

    if (VMF_TRACE_REGISTER(&vmf_trid, VMF_TRID_NAME) < 0)
    {
        fprintf(stderr, "CANNOT CONNECT TO VMF TRACER!!!\n");
    }

	delay(1000);
	devId = DEVID_IRIS0;	// 0x0f
	frq = DAB_FRQ_5A;			
	cmd[3] = PN_DANASMIX_NTFY_RESET;
	PN_CmdDanasMixHandler(sizeof(cmd),cmd);		// PN_DANASMIX_NTFY_RESET

	cmd[4] = devId;								// devId = pn_type
	cmd[5] = PNS3030D;
	cmd[6] = (PN_U8)((frq>>16) & 0xff);
	cmd[7] = (PN_U8)((frq>>8) & 0xff);
	cmd[8] = (PN_U8)(frq & 0xff);
	cmd[3] = PN_CMD_INIT_PNS3030;
	PN_CmdDanasMixHandler(sizeof(cmd),cmd);		// PN_CMD_INIT_PNS3030
	
#if 0
	frq = DAB_FRQ_5A;	
	cmd[3] = PN_CMD_SET_FREQUENCY;
	cmd[4] = devId;								// devId = pn_type
	cmd[6] = (PN_U8)((frq>>16) & 0xff);
	cmd[7] = (PN_U8)((frq>>8) & 0xff);
	cmd[8] = (PN_U8)(frq & 0xff);
	PN_CmdDanasMixHandler(sizeof(cmd),cmd);		// PN_CMD_SET_FREQUENCY

	frq = DAB_FRQ_9A;	
	cmd[3] = PN_CMD_SET_FREQUENCY;
	cmd[4] = devId;								// devId = pn_type
	cmd[6] = (PN_U8)((frq>>16) & 0xff);
	cmd[7] = (PN_U8)((frq>>8) & 0xff);
	cmd[8] = (PN_U8)(frq & 0xff);
	PN_CmdDanasMixHandler(sizeof(cmd),cmd);		// PN_CMD_SET_FREQUENCY
#endif
	
	frq = DAB_FRQ_9A;	
	cmd[4] = devId;								// devId = pn_type
	cmd[5] = PNS3030D;
	cmd[6] = (PN_U8)((frq>>16) & 0xff);
	cmd[7] = (PN_U8)((frq>>8) & 0xff);
	cmd[8] = (PN_U8)(frq & 0xff);
	cmd[3] = PN_CMD_SET_SCAN;
	PN_CmdDanasMixHandler(sizeof(cmd),cmd);		// PN_CMD_SET_SCAN

#if 0	
	frq = DAB_FRQ_5A;	
	cmd[4] = devId;								// devId = pn_type
	cmd[5] = PNS3030D;
	cmd[6] = (PN_U8)((frq>>16) & 0xff);
	cmd[7] = (PN_U8)((frq>>8) & 0xff);
	cmd[8] = (PN_U8)(frq & 0xff);
	cmd[3] = PN_CMD_STATUS_CHECK;
	cmd[9] = 0;									// DMB_play_flag 
	PN_CmdDanasMixHandler(sizeof(cmd),cmd);		// PN_CMD_SET_SCAN

	frq = DAB_FRQ_9A;	
	cmd[4] = devId;								// devId = pn_type
	cmd[5] = PNS3030D;
	cmd[6] = (PN_U8)((frq>>16) & 0xff);
	cmd[7] = (PN_U8)((frq>>8) & 0xff);
	cmd[8] = (PN_U8)(frq & 0xff);
	cmd[3] = PN_CMD_STATUS_CHECK;
	cmd[9] = 0;									// DMB_play_flag 
	PN_CmdDanasMixHandler(sizeof(cmd),cmd);		// PN_CMD_SET_SCAN

	frq = DAB_FRQ_11A;	
	cmd[4] = devId;								// devId = pn_type
	cmd[5] = PNS3030D;
	cmd[6] = (PN_U8)((frq>>16) & 0xff);
	cmd[7] = (PN_U8)((frq>>8) & 0xff);
	cmd[8] = (PN_U8)(frq & 0xff);
	cmd[3] = PN_CMD_STATUS_CHECK;
	cmd[9] = 0;									// DMB_play_flag 
	PN_CmdDanasMixHandler(sizeof(cmd),cmd);		// PN_CMD_SET_SCAN

	frq = DAB_FRQ_11C;	
	cmd[4] = devId;								// devId = pn_type
	cmd[5] = PNS3030D;
	cmd[6] = (PN_U8)((frq>>16) & 0xff);
	cmd[7] = (PN_U8)((frq>>8) & 0xff);
	cmd[8] = (PN_U8)(frq & 0xff);
	cmd[3] = PN_CMD_STATUS_CHECK;
	cmd[9] = 0;									// DMB_play_flag 
	PN_CmdDanasMixHandler(sizeof(cmd),cmd);		// PN_CMD_SET_SCAN
	
	
	

	{
		unsigned16	subch_size;

		subch_size = 512;	
		cmd[4] = devId;								// devId = pn_type
		cmd[5] = PNS3030D;
		cmd[6] = (PN_U8)((subch_size>>8) & 0xff);
		cmd[7] = (PN_U8)(subch_size & 0xff);
		cmd[3] = PN_CMD_ENABLE_FIC;
		PN_CmdDanasMixHandler(sizeof(cmd),cmd);		// PN_CMD_SET_SCAN
	}


	
	
	for (cnt=1;cnt<10;cnt++)
	{
		frq = DAB_FRQ_11A;	
		cmd[4] = devId;								// devId = pn_type
		cmd[5] = PNS3030D;
		cmd[6] = (PN_U8)((frq>>16) & 0xff);
		cmd[7] = (PN_U8)((frq>>8) & 0xff);
		cmd[8] = (PN_U8)(frq & 0xff);
		cmd[3] = PN_CMD_RSSI_STATUS;
		PN_CmdDanasMixHandler(sizeof(cmd),cmd);		// PN_CMD_SET_SCAN
		delay(1000);
	}
#endif	
	nw_vmf_disconnect(vmf_connection_handle);
	vmf_connection_handle = 0;
	//delay(1000);
	exit(0);
}


void MakeUsbPacketRcvMsg(PN_U8 *status,PN_U8 cmd,PN_U16 length)
{
 	(void)vmf_send_msg(PN3030D_STAT, cmd, status, length);	
}

void MakeUsbPacketIsrRcvMsg(PN_U8* data ,PN_U16 len)
{
 	(void)vmf_send_msg(PN3030D_STAT, PN3030D_ISRCV_MSG, data, len);	
}

void Delay10us(void)
{
	volatile int delay_cnt;
	#define DELAY_10us 200

	for (delay_cnt=0; delay_cnt< DELAY_10us; delay_cnt++)
	{
		asm("nop");
	}
}


void DelayMs(PN_U16 ms)
{
	DEBUG_INFO_HI(TRACE_STUBS,"delay(%d)",ms);
	delay(ms);
}



void MAX2172_Tuner_Init(PN_U8 pn_type, PN_FLOAT tuner_freq)
{
}



void MAX2172_Tuner_ChangeFreq(PN_U8 tuner,PN_FLOAT tuner_freq)
{
}



void AGC_STAT_MAX2172(PN_U8 tuner, PN_U8 *data0, PN_U8 *data1)
{
}



void PNS3030D_Rst(void)
{
	PN_U8		cmd;
	
	cmd = CMD_RESET;
	(void)vmf_send_cmd2pn(CMD_RESET);
	DEBUG_INFO_HI(TRACE_STUBS,"CMD_RESET");
}



void PN_IrisIntEnable(void)
{
}



void PN_IrisIntDisable(void)
{
}



void SendRegStatus(PN_U8 play_on, PN_U8 data, PN_U8 cmd)
{
}






