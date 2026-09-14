//---------------------------------------------------------------------------------------------------------------------
// VISTEON CORPORATION CONFIDENTIAL
// [2017] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// File Name:       NetworkDTCHandling.c
// Caution:         
//                 
//---------------------------------------------------------------------------------------------------------------------

#include "Platform_Types.h"
#include "NetworkDTCHandling.h"

#ifndef COMABSCTRL_DTC_NOT_IMPLEMENTED_V1

uint8 ComAbsCtrl_GetIgnRunState(void);
uint8 ComAbsCtrl_GetIgnStartState(void);	

/* DTC log periodic timer */
static uint16  dtc_ov_log_timer;
static uint8  dtc_ov_log_timer_expired;

/* DTC log periodic timer */
static uint16  dtc_rv_log_timer;
static uint8  dtc_rv_log_timer_expired;

/* DTC log periodic timer */
static uint16  dtc_rsv_log_timer;
static uint8  dtc_rsv_log_timer_expired;

static uint8  sodr_timer_count_expired;
static uint16 sodr_timer_count;
static uint8  sodl_timer_count_expired;
static uint16 sodl_timer_count;
static uint8  DTCTask10msContainerIndex;




static void	network_delay_dtc_logging(void);
static void network_lost_comm_dtc_process (void);
static void network_invalid_dtc_process (void);
static void network_noupdate_dtc_process (void);

#ifdef COMABSCTRL_DTC_IMPLEMENTATION_2WH
static uint16 l_ErrPassiveMaturityCount;
static uint16 l_BusOffMaturityCount;

static void network_Error_dtc_process (void);

static void network_lost_comm_ECM_dtc_process(void);
static void network_lost_comm_BCM_dtc_process(void);
static void network_lost_comm_LHCM_dtc_process(void);
static void network_lost_comm_RHCM_dtc_process(void);
static void network_lost_comm_ABS_EHCU_dtc_process(void);
#endif

#define SIG_MISSING_1_6SEC_TIMER_MAX	 16
#define DTC_TIMEOUT						 50

#define DTC_TASKS_0MS_OFFSET      		 (0x00u)
#define DTC_TASKS_10MS_OFFSET     		 (0x01u)
#define DTC_TASKS_20MS_OFFSET     		 (0x02u)
#define DTC_TASKS_30MS_OFFSET     		 (0x03u)
#define DTC_TASKS_40MS_OFFSET     		 (0x04u)
#define DTC_TASKS_50MS_OFFSET     		 (0x05u)
#define DTC_TASKS_60MS_OFFSET     		 (0x06u)
#define DTC_TASKS_70MS_OFFSET     		 (0x07u)
#define DTC_TASKS_80MS_OFFSET     		 (0x08u)
#define DTC_TASKS_90MS_OFFSET     		 (0x09u)

void NetworkDTC_Active( void)
{

    /* Process Task Container Depending on Task Index */
    switch (DTCTask10msContainerIndex)
	{
        case DTC_TASKS_0MS_OFFSET:
	    	network_delay_dtc_logging();
  	        network_lost_comm_dtc_process();
			#ifdef COMABSCTRL_DTC_IMPLEMENTATION_2WH
			network_Error_dtc_process();
			#endif
			break;

		/* processed every 100ms with a 50ms offset*/
        case DTC_TASKS_50MS_OFFSET:
		    network_invalid_dtc_process();
			network_noupdate_dtc_process();
			break;

        default:
            /*
            ** For Some Unexplainable Reason, the Task Container Index Has
            ** Gotten out of Range...Restore it to a Proper Value
            */
        break;
    }
    /* Increment the Task Container Index */
    DTCTask10msContainerIndex++;

    /* Check for Rollover and Reset if Necessary */
    if (DTCTask10msContainerIndex > (uint8)DTC_TASKS_90MS_OFFSET)
    {
       DTCTask10msContainerIndex = (uint8)DTC_TASKS_0MS_OFFSET;
    }
}

static void network_delay_dtc_logging(void)
{

//	bool canmdl_lvsd0 =TRUE;
//	bool canmdl_hvsd0 =TRUE;

	boolean canmdl_lvsd0 =FALSE;
	boolean canmdl_hvsd0 =FALSE;

	GET_LVSD0(&canmdl_lvsd0);  
	GET_HVSD0(&canmdl_hvsd0);  

	/*Timer for delaying the dtc logging after the conditions are all correct */

	if (  sodl_timer_count_expired == FALSE )
	{
		sodl_timer_count++;
		if( sodl_timer_count == SIG_MISSING_1_6SEC_TIMER_MAX)
		{
			 sodl_timer_count_expired = TRUE;
			 sodl_timer_count = 0;
		}
	}
	if (  sodr_timer_count_expired == FALSE )
	{
		sodr_timer_count++;
		if( sodr_timer_count == SIG_MISSING_1_6SEC_TIMER_MAX)
		{
			 sodr_timer_count_expired = TRUE;
			 sodr_timer_count = 0;
		}
	}
	/* Timer for DTC's with only normal voltage conditions */
	if(( canmdl_lvsd0 == FALSE) && ( canmdl_hvsd0 == FALSE))
	{
		/*For dtc having only normal voltage check */
		if (  dtc_ov_log_timer_expired == FALSE )
		{
			 dtc_ov_log_timer++;
			if(  dtc_ov_log_timer ==  DTC_TIMEOUT )
			{
				 dtc_ov_log_timer_expired = TRUE;
				 dtc_ov_log_timer = 0;
			}
		}
	}
	else
	{
		 dtc_ov_log_timer = 0;
		 dtc_ov_log_timer_expired = FALSE;
	}

	/* Timer for DTC's with normal voltage & Ign = RUN conditions */
	if((ComAbsCtrl_GetIgnRunState() != FALSE) && ( canmdl_lvsd0 == FALSE) && ( canmdl_hvsd0 == FALSE) )
	{
		if (  dtc_rv_log_timer_expired == FALSE )
		{
			dtc_rv_log_timer++;
			if(  dtc_rv_log_timer ==  DTC_TIMEOUT )
			{
				 dtc_rv_log_timer_expired = TRUE;
				 dtc_rv_log_timer = 0;
			}
		}
	}
	else
	{
		 dtc_rv_log_timer = 0;
		 dtc_rv_log_timer_expired = FALSE;
	}

	/* Timer for DTC's with normal voltage & Ign = RUN/START conditions */
	if((  (ComAbsCtrl_GetIgnRunState() != FALSE) ||( ComAbsCtrl_GetIgnStartState() != FALSE)) && ( canmdl_lvsd0 == FALSE) && ( canmdl_hvsd0 == FALSE))
	{
		if (  dtc_rsv_log_timer_expired == FALSE )
		{
			 dtc_rsv_log_timer++;
			if(  dtc_rsv_log_timer ==  DTC_TIMEOUT )
			{
				 dtc_rsv_log_timer_expired = TRUE;
				 dtc_rsv_log_timer = 0;
			}
		}
	}
	else
	{
		 dtc_rsv_log_timer = 0;
		 dtc_rsv_log_timer_expired = FALSE;
	}

}

#ifdef COMABSCTRL_DTC_IMPLEMENTATION_2WH

#define eSetDTC (1U)
#define eClearDTC (0U)

/* DTCs Supported
****************************************************
****************************************************

CAN Bus Error							0xC001	0x00
High Speed CAN Communication Bus		0xC001	0x92
Lost Comm with ECM						0xC100	0x00
Lost Comm with ABS / EHCU				0xC121	0x00
Lost Comm with BCM						0xC140	0x00
Lost Comm with LHCM						0xC141	0x00
Lost Comm with RHCM						0xC142	0x00
Invalid Data Received From ECM			0xC401	0x67
Invalid Data Received From ECM			0xC401	0x81
Invalid Data Received From ECM			0xC401	0x82
Invalid Data Received From ECM			0xC401	0x83
Invalid Data Received From ECM			0xC401	0x8F
Invalid Data Received From ABS/EHCU		0xC415	0x67
Invalid Data Received From ABS/EHCU		0xC415	0x81
Invalid Data Received From ABS/EHCU		0xC415	0x82
Invalid Data Received From ABS/EHCU		0xC415	0x83
Invalid Data Received From ABS/EHCU		0xC415	0x8F
Invalid Data Received From BCM			0xC422	0x67
Invalid Data Received From BCM			0xC422	0x81
Invalid Data Received From BCM			0xC422	0x82
Invalid Data Received From BCM			0xC422	0x83
Invalid Data Received From BCM			0xC422	0x8F
Invalid Data Received From LHCM			0xC431	0x67
Invalid Data Received From LHCM			0xC431	0x81
Invalid Data Received From LHCM			0xC431	0x82
Invalid Data Received From LHCM			0xC431	0x83
Invalid Data Received From LHCM			0xC431	0x8F
Invalid Data Received From RHCM			0xC443	0x67
Invalid Data Received From RHCM			0xC443	0x81
Invalid Data Received From RHCM			0xC443	0x82
Invalid Data Received From RHCM			0xC443	0x83
Invalid Data Received From RHCM  		0xC443	0x8F

***********************************************
***********************************************/
static void network_noupdate_dtc_process (void)
{
	// No DTCs
}
static void network_Error_dtc_process (void)
{
	/*Bus off error*/
	uint8 Channel = 0;
	boolean ErrorStatus = FALSE;	/*True : Error Passive, False : No Error Passive*/
	
	(void)GET_BUSOFFERROR_STATUS(Channel, &ErrorStatus);

	if(ErrorStatus == TRUE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			if(l_BusOffMaturityCount > 50)	/*Invoked at every 100ms*/
			{
				Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC00100, eSetDTC);			      // Log Bus off error 
			}
			else
			{
				l_BusOffMaturityCount++;
			}
		}
		else
		{
			l_BusOffMaturityCount = 0;
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC00100, eClearDTC);				// Clear Bus off error
		l_BusOffMaturityCount = 0;
	}

	ErrorStatus = FALSE;

	(void)GET_BUSERRORPASSIVE_STATUS(Channel, &ErrorStatus);

	if(ErrorStatus == TRUE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			if(l_ErrPassiveMaturityCount > 50)	/*Invoked at every 100ms*/
			{
				Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC00192, eSetDTC);			      // Log Bus off error 
			}
			else
			{
				l_ErrPassiveMaturityCount++;
			}
		}
		else
		{
			l_ErrPassiveMaturityCount = 0;
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC00192, eClearDTC);				// Clear Error passive
		l_ErrPassiveMaturityCount = 0;
	}


}

static void network_invalid_dtc_process (void)
{
	boolean InitTimeFault = FALSE;
	boolean DLCFault = FALSE;
	boolean RollingCountFault = FALSE;
	boolean CrcFault = FALSE;
	boolean MsgTimingFault = FALSE;

	/*ECM faults*/
	GET_INIT_TIMING_FAULT_ECM(&InitTimeFault);
	GET_DLC_FAULT_ECM(&DLCFault);
	GET_ROLLING_COUNT_FAULT_ECM(&RollingCountFault);
	GET_CRC_FAULT_ECM(&CrcFault);
	GET_MSG_TIMING_FAULT_ECM(&MsgTimingFault);

	if(InitTimeFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40167, eSetDTC);			      // Log ERC_ECM_INVALID_DATA
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40167, eClearDTC);				// Clear ERC_ECM_INVALID_DATA					
	}

	if(DLCFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40181, eSetDTC);			      // Log ERC_ECM_INVALID_DATA
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40181, eClearDTC);				// Clear ERC_ECM_INVALID_DATA					
	}

	if(RollingCountFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40182, eSetDTC);			      // Log ERC_ECM_INVALID_DATA
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40182, eClearDTC);				// Clear ERC_ECM_INVALID_DATA					
	}

	if(CrcFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40183, eSetDTC);			      // Log ERC_ECM_INVALID_DATA
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40183, eClearDTC);				// Clear ERC_ECM_INVALID_DATA					
	}

	if(MsgTimingFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC4018F, eSetDTC);			      // Log ERC_ECM_INVALID_DATA
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC4018F, eClearDTC);				// Clear ERC_ECM_INVALID_DATA					
	}

	/*ABS_EHCU faults*/

	InitTimeFault = FALSE;
	DLCFault = FALSE;
	RollingCountFault = FALSE;
	CrcFault = FALSE;
	MsgTimingFault = FALSE;

	GET_INIT_TIMING_FAULT_ABS_EHCU(&InitTimeFault);
	GET_DLC_FAULT_ABS_EHCU(&DLCFault);
	GET_ROLLING_COUNT_FAULT_ABS_EHCU(&RollingCountFault);
	GET_CRC_FAULT_ABS_EHCU(&CrcFault);
	GET_MSG_TIMING_FAULT_ABS_EHCU(&MsgTimingFault);

	if(InitTimeFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41567, eSetDTC);			      // Log ERC_ABS_EHCU_INVALID_DATA
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41567, eClearDTC);			// Clear ERC_ABS_EHCU_INVALID_DATA						
	}

	if(DLCFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41581, eSetDTC);			      // Log ERC_ABS_EHCU_INVALID_DATA
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41581, eClearDTC);			// Clear ERC_ABS_EHCU_INVALID_DATA						
	}

	if(RollingCountFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41582, eSetDTC);			      // Log ERC_ABS_EHCU_INVALID_DATA
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41582, eClearDTC);			// Clear ERC_ABS_EHCU_INVALID_DATA						
	}

	if(CrcFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41583, eSetDTC);			      // Log ERC_ABS_EHCU_INVALID_DATA
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41583, eClearDTC);			// Clear ERC_ABS_EHCU_INVALID_DATA						
	}

	if(MsgTimingFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC4158F, eSetDTC);			      // Log ERC_ABS_EHCU_INVALID_DATA
		}
	}
	else
	{	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC4158F, eClearDTC);			// Clear ERC_ABS_EHCU_INVALID_DATA						
	}


	/*BCM faults*/

	InitTimeFault = FALSE;
	DLCFault = FALSE;
	RollingCountFault = FALSE;
	CrcFault = FALSE;
	MsgTimingFault = FALSE;

	GET_INIT_TIMING_FAULT_BCM(&InitTimeFault);
	GET_DLC_FAULT_BCM(&DLCFault);
	GET_ROLLING_COUNT_FAULT_BCM(&RollingCountFault);
	GET_CRC_FAULT_BCM(&CrcFault);
	GET_MSG_TIMING_FAULT_BCM(&MsgTimingFault);

	if(InitTimeFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42267, eSetDTC);			      // Log ERC_BCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42267, eClearDTC);			// Clear ERC_BCM_INVALID_DATA
	}

	if(DLCFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42281, eSetDTC);			      // Log ERC_BCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42281, eClearDTC);			// Clear ERC_BCM_INVALID_DATA
	}

	if(RollingCountFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42282, eSetDTC);			      // Log ERC_BCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42282, eClearDTC);			// Clear ERC_BCM_INVALID_DATA
	}

	if(CrcFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42283, eSetDTC);			      // Log ERC_BCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42283, eClearDTC);			// Clear ERC_BCM_INVALID_DATA
	}

	if(MsgTimingFault != FALSE)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC4228F, eSetDTC);			      // Log ERC_BCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC4228F, eClearDTC);			// Clear ERC_BCM_INVALID_DATA
	}

	/*LHCM faults*/

	InitTimeFault = FALSE;
	DLCFault = FALSE;
	RollingCountFault = FALSE;
	CrcFault = FALSE;
	MsgTimingFault = FALSE;

	GET_INIT_TIMING_FAULT_LHCM(&InitTimeFault);
	GET_DLC_FAULT_LHCM(&DLCFault);
	GET_ROLLING_COUNT_FAULT_LHCM(&RollingCountFault);
	GET_CRC_FAULT_LHCM(&CrcFault);
	GET_MSG_TIMING_FAULT_LHCM(&MsgTimingFault);

	if(InitTimeFault != FALSE)
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43167, eSetDTC);			      // Log ERC_LHCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43167, eClearDTC);			// Clear ERC_LHCM_INVALID_DATA
	}

	if(DLCFault != FALSE)
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43181, eSetDTC);			      // Log ERC_LHCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43181, eClearDTC);			// Clear ERC_LHCM_INVALID_DATA
	}

	if(RollingCountFault != FALSE)
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43182, eSetDTC);			      // Log ERC_LHCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43182, eClearDTC);			// Clear ERC_LHCM_INVALID_DATA
	}

	if(CrcFault != FALSE)
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43183, eSetDTC);			      // Log ERC_LHCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43183, eClearDTC);			// Clear ERC_LHCM_INVALID_DATA
	}

	if(MsgTimingFault != FALSE)
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC4318F, eSetDTC);			      // Log ERC_LHCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC4318F, eClearDTC);			// Clear ERC_LHCM_INVALID_DATA
	}

	/*RHCM faults*/

	InitTimeFault = FALSE;
	DLCFault = FALSE;
	RollingCountFault = FALSE;
	CrcFault = FALSE;
	MsgTimingFault = FALSE;

	GET_INIT_TIMING_FAULT_RHCM(&InitTimeFault);
	GET_DLC_FAULT_RHCM(&DLCFault);
	GET_ROLLING_COUNT_FAULT_RHCM(&RollingCountFault);
	GET_CRC_FAULT_RHCM(&CrcFault);
	GET_MSG_TIMING_FAULT_RHCM(&MsgTimingFault);

	if(InitTimeFault != FALSE)
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC44367, eSetDTC);			      // Log ERC_RHCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC44367, eClearDTC);			// Clear ERC_RHCM_INVALID_DATA
	}

	if(DLCFault != FALSE)
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC44381, eSetDTC);			      // Log ERC_RHCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC44381, eClearDTC);			// Clear ERC_RHCM_INVALID_DATA
	}

	if(RollingCountFault != FALSE)
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC44382, eSetDTC);			      // Log ERC_RHCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC44382, eClearDTC);			// Clear ERC_RHCM_INVALID_DATA
	}

	if(CrcFault != FALSE)
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC44383, eSetDTC);			      // Log ERC_RHCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC44383, eClearDTC);			// Clear ERC_RHCM_INVALID_DATA
	}

	if(MsgTimingFault != FALSE)
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC4438F, eSetDTC);			      // Log ERC_RHCM_INVALID_DATA
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC4438F, eClearDTC);			// Clear ERC_RHCM_INVALID_DATA
	}

}
static void network_lost_comm_ECM_dtc_process(void)
{
	/*ECM source*/
	uint16 EngSpdInStatus;
	uint16 VSpdInStatus;
	uint8 GearPosInStatus;
	uint8 MILTTInStatus;
	uint8 CruiseEngagedTTInStatus;
	uint8 CruiseEnabledTTInStatus;
	uint8 JiffyStandTTInStatus;
	uint8 ReverseGearTTInStatus;
	uint8 LowOilPressTTInStatus;
	uint8 LowFuelTTInStatus;
	uint8 LowRangeTTInStatus;
	uint8 CoolantTempTTInStatus;
	uint16 FuelRangeInStatus;
	uint8 FuelPercentInStatus;
	uint32 TotalOdoInStatus;
	uint8 AmbAirTempInStatus;
	uint32 FuelFlowInStatus;
	uint8 VINChar01InStatus;
	uint8 VINChar02InStatus;
	uint8 VINChar03InStatus;
	uint8 VINChar04InStatus;
	uint8 VINChar05InStatus;
	uint8 VINChar06InStatus;
	uint8 VINChar07InStatus;
	uint8 VINChar08InStatus;
	uint8 VINChar09InStatus;
	uint8 VINChar10InStatus;
	uint8 VINChar11InStatus;
	uint8 VINChar12InStatus;
	uint8 VINChar13InStatus;
	uint8 VINChar14InStatus;
	uint8 VINChar15InStatus;
	uint8 VINChar16InStatus;
	uint8 VINChar17InStatus;

	uint8 SigInValue;

	/*To optimise, We can monitor only 1 signal from each message*/
	/*ECM source*/
	/*0x142*/
	GET_CAN_RX_ENGSPDIN(&SigInValue,&EngSpdInStatus);
	GET_CAN_RX_VSPDIN(&SigInValue,&VSpdInStatus);
	GET_CAN_RX_GEARPOSITION(&SigInValue,&GearPosInStatus);
	/*0x146*/
	GET_CAN_RX_MILTTIN(&SigInValue, &MILTTInStatus);
	/*0x342*/
	GET_CAN_RX_CRUISEENGAGEDTTIN(&SigInValue, &CruiseEngagedTTInStatus);
	GET_CAN_RX_CRUISEENABLEDTTIN(&SigInValue, &CruiseEnabledTTInStatus);
	GET_CAN_RX_JIFFYSTATNDTTIN(&SigInValue, &JiffyStandTTInStatus);
	GET_CAN_RX_REVERSEGEARTTIN(&SigInValue, &ReverseGearTTInStatus);
	GET_CAN_RX_LOWOILPRESSTTIN(&SigInValue, &LowOilPressTTInStatus);
	GET_CAN_RX_LOWFUELTTIN(&SigInValue, &LowFuelTTInStatus);
	GET_CAN_RX_LOWRANGETTIN(&SigInValue, &LowRangeTTInStatus);
	GET_CAN_RX_COOLANTTEMPTTIN(&SigInValue, &CoolantTempTTInStatus);
	GET_CAN_RX_FUELRANGEIN(&SigInValue, &FuelRangeInStatus);
	GET_CAN_RX_FUELPERCENTIN(&SigInValue, &FuelPercentInStatus);
	/*0x346*/
	GET_CAN_RX_TOTALODOIN(&SigInValue, &TotalOdoInStatus);
	GET_CAN_RX_AMBAIRTEMPIN(&SigInValue, &AmbAirTempInStatus);
	/*0x348*/
	GET_CAN_RX_FUELFLOWIN(&SigInValue, &FuelFlowInStatus);
	/*0x34D*/
	GET_CAN_RX_VINCHAR01IN(&SigInValue, &VINChar01InStatus);
	GET_CAN_RX_VINCHAR02IN(&SigInValue, &VINChar02InStatus);
	GET_CAN_RX_VINCHAR03IN(&SigInValue, &VINChar03InStatus);
	GET_CAN_RX_VINCHAR04IN(&SigInValue, &VINChar04InStatus);
	GET_CAN_RX_VINCHAR05IN(&SigInValue, &VINChar05InStatus);
	GET_CAN_RX_VINCHAR06IN(&SigInValue, &VINChar06InStatus);
	/*0x34E*/
	GET_CAN_RX_VINCHAR07IN(&SigInValue, &VINChar07InStatus);
	GET_CAN_RX_VINCHAR08IN(&SigInValue, &VINChar08InStatus);
	GET_CAN_RX_VINCHAR09IN(&SigInValue, &VINChar09InStatus);
	GET_CAN_RX_VINCHAR10IN(&SigInValue, &VINChar10InStatus);
	GET_CAN_RX_VINCHAR11IN(&SigInValue, &VINChar11InStatus);
	GET_CAN_RX_VINCHAR12IN(&SigInValue, &VINChar12InStatus);
	/*0x34F*/
	GET_CAN_RX_VINCHAR13IN(&SigInValue, &VINChar13InStatus);
	GET_CAN_RX_VINCHAR14IN(&SigInValue, &VINChar14InStatus);
	GET_CAN_RX_VINCHAR15IN(&SigInValue, &VINChar15InStatus);
	GET_CAN_RX_VINCHAR16IN(&SigInValue, &VINChar16InStatus);
	GET_CAN_RX_VINCHAR17IN(&SigInValue, &VINChar17InStatus);

	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 
	*						 
	*               	    Lost Comm w/ ECM_PCM DTC
	*						0xC10000
	*******************************************************************************/
	if(((EngSpdInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VSpdInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((GearPosInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((MILTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((CruiseEngagedTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((CruiseEnabledTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((JiffyStandTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((ReverseGearTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((LowOilPressTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((LowFuelTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((LowRangeTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((CoolantTempTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((FuelRangeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((FuelPercentInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((TotalOdoInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((AmbAirTempInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((FuelFlowInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar01InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar02InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar03InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar04InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar05InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar06InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar07InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar08InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar09InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar10InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar11InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar12InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar13InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar14InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar15InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar16InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VINChar17InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC10000, eSetDTC);			      // Log ERC_LOST_COMM_ECMPCM_DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC10000, eClearDTC);			// Clear ERC_LOST_COMM_ECMPCM_DTC
	}

}


static void network_lost_comm_BCM_dtc_process(void)
{
	uint8 SigInValue;

	/*BCM source*/
	uint8 e12VBattInStatus;
	uint8 LowTirePressureTTInStatus;
	uint8 AUXLightsTTInStatus;
	uint8 HighBeamTTInStatus;
	uint8 NeutralGearTTInStatus;
	uint8 ParkingBrakeTTInStatus;
	uint8 TurnLeftTTInStatus;
	uint8 TIPTTInStatus;
	uint8 TurnRightTTInStatus;
	uint8 ServiceIndicatorTTInStatus;
	uint8 GenPurposeFaultTTInStatus;
	uint8 PowerModeInStatus;
	uint8 BattVoltInStatus;
	uint8 FOBBatteryInStatus;
	uint8 FOBErrorInStatus;
	uint8 StatusTirePressureRorRRInStatus;
	uint8 StatusTirePressureFInStatus;
	uint8 StatusTirePressureLRInStatus;
	uint8 TirePressureFInStatus;
	uint8 TirePressureRorRRInStatus;
	uint8 TirePressureLRInStatus;
	/*BCM source*/
	/*0x131*/
	GET_CAN_RX_12VBATTIN(&SigInValue,&e12VBattInStatus);
	GET_CAN_RX_LOWRITEPRESSURETTIN(&SigInValue,&LowTirePressureTTInStatus);
	GET_CAN_RX_AUXLIGHTSTTIN(&SigInValue,&AUXLightsTTInStatus);
	GET_CAN_RX_HIGHBEAMTTIN(&SigInValue,&HighBeamTTInStatus);
	GET_CAN_RX_NEUTRALGREARTTIN(&SigInValue,&NeutralGearTTInStatus);
	GET_CAN_RX_PARKINGBRAKETTIN(&SigInValue,&ParkingBrakeTTInStatus);
	GET_CAN_RX_TURNLEFTTTIN(&SigInValue,&TurnLeftTTInStatus);
	GET_CAN_RX_TIPTTIN(&SigInValue,&TIPTTInStatus);
	GET_CAN_RX_TURNRIGHTTTIN(&SigInValue,&TurnRightTTInStatus);
	GET_CAN_RX_SERVICEINDICATORTTIN(&SigInValue,&ServiceIndicatorTTInStatus);
	GET_CAN_RX_GENPURPOSEFAULTTTIN(&SigInValue,&GenPurposeFaultTTInStatus);
	/*0x133*/
	GET_CAN_RX_POWERMODEIN(&SigInValue,&PowerModeInStatus);
	/*0x332*/
	GET_CAN_RX_BATTVOLTIN(&SigInValue,&BattVoltInStatus);
	GET_CAN_RX_FOBBATTERYIN(&SigInValue,&FOBBatteryInStatus);
	GET_CAN_RX_FOBERRORIN(&SigInValue,&FOBErrorInStatus);
	/*0x334*/
	GET_CAN_RX_STATUSTIREPRESSURERRIN(&SigInValue,&StatusTirePressureRorRRInStatus);
	GET_CAN_RX_STATUSTIREPRESSUREFIN(&SigInValue,&StatusTirePressureFInStatus);
	GET_CAN_RX_STATUSTIREPRESSURELRIN(&SigInValue,&StatusTirePressureLRInStatus);
	/*0x33A*/
	GET_CAN_RX_TIREPRESSUREFIN(&SigInValue,&TirePressureFInStatus);
	GET_CAN_RX_TIREPRESSURERRIN(&SigInValue,&TirePressureRorRRInStatus);
	GET_CAN_RX_TIREPRESSURELRIN(&SigInValue,&TirePressureLRInStatus);

	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 
	*						 
	*               	    Lost Comm w/ BCM DTC
	*						0xC14000
	*******************************************************************************/
	if(((e12VBattInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((LowTirePressureTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((AUXLightsTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((HighBeamTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((NeutralGearTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((ParkingBrakeTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((TurnLeftTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((TIPTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((TurnRightTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((ServiceIndicatorTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((GenPurposeFaultTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((PowerModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((BattVoltInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((FOBBatteryInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((FOBErrorInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((StatusTirePressureRorRRInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((StatusTirePressureFInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((StatusTirePressureLRInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((TirePressureFInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((TirePressureRorRRInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((TirePressureLRInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC14000, eSetDTC);			      // Log ERC_LOST_COMM_BCM_DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC14000, eClearDTC);			// Clear ERC_LOST_COMM_BCM_DTC
	}


}


static void network_lost_comm_RHCM_dtc_process(void)
{
	uint8 SigInValue;

	/*RHCM source*/
	uint8 SwRideModeInStatus;
	uint8 SwPlayPauseInStatus;
	uint8 SwVolDownInStatus;
	uint8 SwMediaBwdInStatus;
	uint8 SwMediaFwdInStatus;
	uint8 SwVolUpInStatus;
	uint8 SwTurnRightInStatus;

	/*RHCM source*/
	/*0x15A*/
	GET_CAN_RX_SWRIDEMODEIN(&SigInValue,&SwRideModeInStatus);
	/*0x35A*/
	GET_CAN_RX_SWPLAYPAUSEIN(&SigInValue,&SwPlayPauseInStatus);
	GET_CAN_RX_SWVOLDOWNIN(&SigInValue,&SwVolDownInStatus);
	GET_CAN_RX_SWMEDIABWDIN(&SigInValue,&SwMediaBwdInStatus);
	GET_CAN_RX_SWMEDIAFWDIN(&SigInValue,&SwMediaFwdInStatus);
	GET_CAN_RX_SWVOLUPIN(&SigInValue,&SwVolUpInStatus);
	GET_CAN_RX_SWTURNRIGHTIN(&SigInValue,&SwTurnRightInStatus);


	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 
	*						 
	*               	    Lost Comm w/ RHCM DTC
	*						0xC14200
	*******************************************************************************/
	if(((SwRideModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwPlayPauseInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((SwVolDownInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwMediaBwdInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwMediaFwdInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwVolUpInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwTurnRightInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC14200, eSetDTC);			      // Log ERC_LOST_COMM_RHCM_DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC14200, eClearDTC);			// Clear ERC_LOST_COMM_RHCM_DTC	
	}


}

static void network_lost_comm_ABS_EHCU_dtc_process(void)
{
	uint8 SigInValue;

	/*EHCU source*/
	uint8 TCInfoTTInStatus;
	uint8 VehicleHoldTInStatus;
	uint8 ABSTTInStatus;
	uint8 EHCUConfigInStatus;

	/*EHCU Source*/
	/*0x324*/
	GET_CAN_RX_TCINFOTTIN(&SigInValue,&TCInfoTTInStatus);
	GET_CAN_RX_VEHICLEHOLDTIN(&SigInValue,&VehicleHoldTInStatus);
	GET_CAN_RX_ABSTTIN(&SigInValue,&ABSTTInStatus);
	GET_CAN_RX_EHCUCONFIGIN(&SigInValue,&EHCUConfigInStatus);

	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 
	*						 
	*               	    Lost Comm w/ ABS_EHCU DTC
	*						0xC12100
	*******************************************************************************/
	if(((TCInfoTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((VehicleHoldTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	((ABSTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((EHCUConfigInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC12100, eSetDTC);			      // Log ERC_LOST_COMM_ABS_EHCU_DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC12100, eClearDTC);			// Clear ERC_LOST_COMM_ABS_EHCU_DTC
	}

}

static void network_lost_comm_LHCM_dtc_process(void)
{
	uint8 SigInValue;

	/*LHCM source*/
	uint8 SwTurnLeftInStatus;
	uint8 HeatedGripsTTInStatus;
	uint8 SwOkInStatus;
	uint8 SwDirRightInStatus;
	uint8 SwDirLeftInStatus;
	uint8 SwDirUpInStatus;
	uint8 SwDirDownInStatus;
	uint8 SwBackInStatus;
	uint8 SwHomeInStatus;
	uint8 SwTripInStatus;

	/*LHCM source*/
	/*0x154*/
	GET_CAN_RX_SWTURNLEFTIN(&SigInValue,&SwTurnLeftInStatus);
	GET_CAN_RX_HEATEDGRIPSTTIN(&SigInValue,&HeatedGripsTTInStatus);
	/*0x354*/
	GET_CAN_RX_SWOK_IN(&SigInValue,&SwOkInStatus);
	GET_CAN_RX_SWDIRRIGHTIN(&SigInValue,&SwDirRightInStatus);
	GET_CAN_RX_SWDIRLEFTIN(&SigInValue,&SwDirLeftInStatus);
	GET_CAN_RX_SWDIRUPIN(&SigInValue,&SwDirUpInStatus);
	GET_CAN_RX_SWDIRDOWNIN(&SigInValue,&SwDirDownInStatus);
	GET_CAN_RX_SWBACKIN(&SigInValue,&SwBackInStatus);
	GET_CAN_RX_SWHOMEIN(&SigInValue,&SwHomeInStatus);
	GET_CAN_RX_SWTRIPIN(&SigInValue,&SwTripInStatus);


	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 
	*						 
	*               	    Lost Comm w/ LHCM DTC
	*						0xC14100
	*******************************************************************************/
	if(/*((SwCCSetDecInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||*/
	((SwTurnLeftInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||
	/*((SwFogLampsInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||*/
	((HeatedGripsTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwOkInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwDirRightInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwDirLeftInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwDirUpInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwDirDownInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwBackInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwHomeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((SwTripInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC14100, eSetDTC);			      // Log ERC_LOST_COMM_LHCM_DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC14100, eClearDTC);			// Clear ERC_LOST_COMM_LHCM_DTC
	}

}


static void network_lost_comm_dtc_process(void)
{
	network_lost_comm_ECM_dtc_process();
	network_lost_comm_BCM_dtc_process();
	network_lost_comm_LHCM_dtc_process();
	network_lost_comm_RHCM_dtc_process();
	network_lost_comm_ABS_EHCU_dtc_process();
}
#endif

#ifdef COMABSCTRL_SIG_PROCESSING_ENABLE
#ifndef COMABSCTRL_DTC_NOT_IMPLEMENTED

// LOST COMMUNICATION DTCS

static void network_lost_comm_dtc_process(void)
{
	boolean cf_opt_pt_hybrid_2_status;
	boolean cf_opt_pt_hybrid_2;
	boolean cf_opt_epb_status;
	boolean	cf_opt_abs_status;
	boolean	cf_opt_RSC_warning_chime_status;
	boolean	cf_opt_advance_trac_status;
	boolean	cf_opt_trailer_sway_status;
	boolean cf_opt_selectable_drive_mode_status;
	boolean	cf_opt_driver_beltminder_status;
	boolean	cf_opt_rbm_ec_strategy_status;
	boolean	cf_opt_pass_beltminder_status;
	boolean	cf_opt_mid_pass_beltminder_status;
	boolean	cf_opt_rear_park_aid_status;
	boolean	cf_opt_autopark_status;
	boolean	cf_opt_active_front_steering_status;
	boolean	cf_opt_courtesy_wipe_after_wash_status;
	boolean cf_opt_rain_sensing_wipers_status;
	boolean cf_opt_rear_reverse_gear_wipe;
	boolean cf_opt_bsm_status;
	boolean cf_opt_bttlite;
	boolean cf_opt_cta_status;
	boolean	cf_opt_hybrid_engine_config_status;
	boolean	cf_opt_manregen_status;
	boolean	cf_opt_auto_regen_control_status;
	boolean	cf_opt_odometer_delta_status;
	boolean cf_opt_diesel_warm_up_warnings_status;
	boolean cf_opt_oil_minder_10k_status;
	boolean cf_opt_oil_minder_distance_time_status;
	boolean cf_opt_diesel_engine_config_status;
	boolean cf_opt_tach_signal_status;
	boolean cf_opt_engine_hours_function_status;
	boolean cf_opt_engine_idle_hours_function_status;
	boolean cf_opt_aeis_configuration_status;
	boolean cf_opt_fuellvl_pcm_status;
	boolean cf_opt_turbo_boost_status;
	boolean cf_opt_overspeed_warning_status;
	boolean cf_opt_asld_status;
	boolean cf_opt_intelligentspeedassist_status;
	boolean	cf_opt_trans_type_status;
	boolean	cf_opt_engineairfilterminder_status;
	boolean cf_opt_2wd_4x4_awd_status;
	boolean cf_opt_neutral_tow_status;
	boolean cf_opt_tccm_nt_status;
	boolean cf_opt_e_locker_status;
	boolean cf_opt_shift_by_wire_status;
	boolean	cf_opt_trailer_lighting_status;
	boolean cf_opt_trailer_brake_status;
	boolean cf_opt_mykey_feature_status;
	boolean cf_opt_tc_ivd_rsc_status;
	boolean cf_opt_my_key_volume_status;
	boolean cf_opt_mykey_traction_control_status;
	boolean cf_opt_mykey_spd_limit_mjr_mkt_status;
	boolean cf_opt_emergency_assist_status;
	boolean cf_opt_do_not_disturb_status;
	boolean cf_opt_mykey_911_text_status;
	boolean	cf_opt_perimeter_alarm_with_reduced_guard_control_function_status;	
	boolean	cf_opt_highbeamtelltalesource_status;
	boolean cf_opt_key_in_ignition_reminder_chime_status;
	boolean cf_opt_approach_detection_control_function_status;
	boolean cf_opt_auto_relock_status;
	boolean cf_opt_peps_status;
	boolean cf_opt_intelligent_access_menu_status;
	boolean	cf_opt_locking_feedback_audible_status;
	boolean	cf_opt_locking_feedback_visual_status;
	boolean	cf_opt_global_window_open_status;
	boolean	cf_opt_global_window_close_status;
	boolean cf_opt_daytimerunninglamps_status;
	boolean cf_opt_autolock_status;
	boolean cf_opt_autounlock_status;
	boolean cf_opt_autolamp_status;
	boolean cf_opt_onetwostageunlock_status;
	boolean cf_opt_outside_air_temperature_status;
	boolean cf_opt_remote_start_status;
	boolean cf_opt_easy_entry_easy_exit_configuration_status;
	boolean cf_opt_mirrors_autofold_status;
	boolean	cf_opt_mirrors_reverse_tilt_status;
	boolean cf_opt_trcm_present_status;
	boolean	cf_opt_reverse_brake_assist_status;
	boolean cf_opt_predictive_lighting_configuration_status;
	boolean cf_opt_adaptiveheadlamps_status;
	boolean cf_opt_acc_status;
	boolean cf_opt_settings_menu_status;
	boolean cf_opt_trafficsignrecognition_status;
	boolean cf_opt_slif_status;
	boolean cf_opt_fcw_status;
	boolean cf_opt_auto_high_beam_telltale_status;
	boolean cf_opt_lane_assist_status;
	boolean cf_opt_lane_assist_ncap_aid;
	boolean cf_opt_lane_assist_ncap_alert;
	boolean cf_opt_TSR_config;
	boolean cf_opt_das_status;
	boolean cf_opt_wrongwayalert;
	boolean cf_opt_front_camera_status;
	boolean cf_opt_autohighbeam_menu_status;
	boolean cf_opt_iacc_status;
	boolean cf_opt_trailer_backup_assist_status;
	boolean cf_opt_trailer_reverse_guidance_status;
	boolean cf_opt_trafficjamassist_status;
	boolean cf_opt_highwayassist_status;
	boolean cf_opt_pwr_d_gauge_feature_status;
	boolean cf_opt_transmission_fluid_temp_display;
	boolean cf_opt_oat_status ;
	boolean cf_opt_oat_source_status;
	boolean	cf_opt_driver_beltminder;
	boolean	cf_opt_pass_beltminder; 
	boolean cf_opt_mid_pass_beltminder;
	boolean cf_opt_awdsourcemodule;
	boolean cf_opt_ahudmenu;
	boolean cf_opt_chud;
	boolean cf_opt_primarychimesource;
	boolean cf_opt_emergencycallfault;
	boolean cf_opt_MHEV_Configuration;
	boolean cf_opt_Shift_Out_Of_Neutral;
	boolean cf_opt_EV_Display_Configuration_for_FordVehicles;
	boolean cf_opt_EV_Display_Configuration_for_LincolnVehicles;
	boolean cf_opt_LED_LowBeamFaultIndicator;	
	boolean cf_opt_engine_fuel_type;
	boolean cf_opt_lfr_config;
	boolean cf_opt_upshift_indicator;
	boolean cf_opt_perf_shift_indicator;
	boolean cf_opt_grade_assist_menu;
	boolean cf_opt_mHEV_start_stop_speed_th;
	boolean cf_opt_tcm_present;
	boolean cf_opt_powerliftgate;
    boolean cf_opt_powerliftgatehandsfreemenu;
	boolean cf_opt_frontfogtelltale;
	boolean cf_opt_awd_gaguge_feature;
	boolean cf_opt_Brazil_Cold_Start_Reservoir;
	boolean cf_opt_def_gauge_configuration_status;
	boolean cf_opt_aeis_without_override;
	boolean cf_opt_aeis_with_override;
	boolean cf_opt_doorajarwarning;
	boolean cf_opt_welcome;
	boolean cf_opt_powerslidingdoor;
	boolean cf_opt_DimIIControlMirror;
	boolean cf_opt_hoodajar;
	boolean cf_opt_sidemarker;
	boolean cf_opt_powerslidingdoorleftconfig;
	boolean cf_opt_powerslidingdoorrightconfig;
	boolean cf_opt_R1C1SeatBelt;
	boolean cf_opt_R1C3SeatBelt;
	boolean cf_opt_R1C5SeatBelt;
	boolean cf_opt_R2C1SeatBelt;
	boolean cf_opt_R2C3SeatBelt;
	boolean cf_opt_R2C5SeatBelt;
	boolean cf_opt_R3C1SeatBelt;
	boolean cf_opt_R3C3SeatBelt;
	boolean cf_opt_R3C5SeatBelt;
	boolean cf_opt_R1C1BeltMinderChime;
	boolean cf_opt_R1C3BeltMinderChime;
	boolean cf_opt_R1C5BeltMinderChime;
	boolean cf_opt_PassengerAirbagSetting;
	boolean cf_opt_4x4canhw;
	boolean	cf_opt_running_board_control_function;
	boolean cf_opt_CeramicBrakePadWearIndicator;
	boolean cf_opt_TrailerBrakee2eSignalProtection;
	boolean cf_opt_shiftoutofneutral;
	boolean cf_opt_evdisplayconfigford;
	boolean cf_opt_evdisplayconfiglincoln;
	boolean cf_opt_bevphevconfig;
	boolean cf_opt_mhevconfiguration;
	boolean cf_opt_auto_high_beam_menu;
	boolean cf_opt_autohighbeamtelltale;
	boolean cf_opt_park_lock_allow;
	boolean cf_opt_tail_gate_ajar_warning;
	boolean cf_opt_trunk_ajar_config;
	boolean cf_opt_intelligent_access_config;
	boolean cf_opt_trim_switch_config;
	boolean cf_opt_mislock_chirp_menu;
	boolean cf_opt_silent_mode_config;
	boolean cf_opt_handsfree_lift_gate_config;
	boolean cf_opt_electroniclatch;
	boolean cf_opt_tiretempdisplay;
	boolean	cf_opt_advanceTracConfiguration;  
	boolean cf_opt_ChargePortDoorAjarWarningConfiguration;
#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
	boolean cf_opt_policeidlemode;
	boolean cf_opt_AdvanceTracHardButton;
	boolean	cf_opt_autohold_status;
	boolean cf_opt_R4C1SeatBelt;
	boolean cf_opt_R4C3SeatBelt;
	boolean cf_opt_R4C5SeatBelt;
	boolean cf_opt_adaptiveSteeringMenu;
	boolean cf_opt_rsem_config;
	boolean cf_opt_refp_config;
	boolean cf_opt_msgcentredisplayinterface;
	boolean cf_opt_boundary_alert;
	boolean cf_opt_icppresent;
	boolean cf_opt_icpnetwork;
#endif
	boolean cf_opt_policeliftgateunlock;
	boolean cf_opt_axleoiltempdisplay;
	boolean cf_opt_trailcontrol;
	boolean cf_opt_bevconfig;
	boolean cf_opt_manifoldchargetemp;
	boolean cf_opt_dieselparticulatefilterconfig;
	boolean cf_opt_Indiaover_speed_warning;
	boolean cf_opt_pdcfaultconfig;
	boolean cf_opt_oilpressuresensor;
	boolean cf_opt_airfuelratio;
	boolean cf_opt_oiltemp;
	boolean cf_opt_reverse_warning_status;	
	#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
	boolean cf_opt_TransmissionFluidTemperatureGaugeConfiguration;
	boolean cf_opt_transmissionfluidtempdisplay_status;
	#endif
	boolean cf_opt_powerlockcontrolconfig;
	#ifdef COMABSCTRL_APPLICABLE_ONLY_FOR_V710
    boolean cf_opt_parklockcontrolconfig;
	#endif
	
	uint8   PwrTrainTorqueInStatus;	
	uint8	VSpdQFInValue;
	uint8	VSpdQFInStatus;
	uint8	OdoInStatus;
	uint8 	ParkBrkStatusInStatus;
	uint8	ABSTTInStatus;
	uint8	ABSBrakeTTInStatus;
	uint8   SCTTInStatus;
	uint8	SvcAdvTracChimeRqInStatus;
	uint8	SCOffTTInStatus;
	uint8	TrailerSwayConfigInStatus;
	uint8	DriveModeSelInStatus;
	uint8   DriveModeSelInValue;
	uint8	ActiveDriveModeInStatus;
	//uint8	DriveModeSelectMsgInStatus;
	uint8	DrvModeSelectStatInStatus;
	uint8   RILTTInStatus;
	uint8	OneRowSBDriverInStatus;
	uint8	OneRowSBPassInStatus;
	uint8	PassAirbagStatInStatus;
	uint8	PassSeatDetectInStatus;
	uint8	OneRowSBMiddleInStatus;	
	uint8	ParkAidMesgInStatus;
	uint8	RPAStatInStatus;
	uint8	APASysInStatus;
	uint8	SwMenuInStatus;
	uint8	SwOKInStatus;
	uint8	SwUpInStatus;
	uint8	SwDnInStatus;
	uint8	SwBkInStatus;
	uint8   SwHUDInStatus;
	uint8	PwrPackReadyIn;
	uint8   ChargePortDoorOpenInStatus;
	uint8   VehElRangeInStatus;
	uint8	ICICodBtnIDAInStatus;
	uint8	ICICodBtnIDBInStatus;
	uint8	ICICodBtnIDCInStatus;
	uint8	ICICodBtnIDDInStatus;
	uint8	ICIBtnIDAInStatus;
	uint8	ICIBtnIDBInStatus;
	uint8	ICIBtnIDCInStatus;
	uint8	ICIBtnIDDInStatus;
	uint8	FeatConfigSCCMInStatus;
	uint8	FeatNoSCCMInStatus;
	uint8	LBSMOpInStatus;
	uint8	LBSMSnsrInStatus;
	uint8	LCrossTrafficAlertInStatus;
	uint8	LCrossTrafficOpInStatus;
	uint8	LCrossTrafficSnsrInStatus;
	uint8	LCrossTrafficAlertBrakeInStatus;
	uint8	RBSMOpInStatus;
	uint8	RBSMSnsrInStatus;
	uint8	RCrossTrafficAlertInStatus;
	uint8	RCrossTrafficOpInStatus;
	uint8   BTTRightRqstInStatus;
	uint8	RCrossTrafficSnsrInStatus;
	uint8	RCrossTrafficAlertBrakeInStatus;
	uint8	RegenLevelInStatus;
	uint8	BrakeEventInStatus;
	uint8	EffWhlLvl2InStatus;
	uint8	EffWhlThresInStatus;
	uint8	EngModeMsgTxtInStatus;
	uint8	EffRgnThresInStatus;
	uint8	EngTempInStatus;
	uint8	FSCInStatus;
	uint8	EngTempQFInStatus;	
	uint8	AutoRegenCtrlTTInStatus;
	uint8	OdoTripVerifyInStatus;
	uint8	StopStartTTInStatus;
	uint8	PwrPackStatInStatus;
	uint8	ePRNDLInStatus;
	uint8	DieselEngTeColdInStatus;
	uint8	FuelInletStatusInStatus;
	uint8	EngOilLifeInStatus;
	uint8	W2STTInStatus;
	uint8	WaterInFuelTTInStatus;
	uint8	EngSpdUnfiltInStatus;
	uint8	EngIdlShutDownInStatus;
	uint8   MILTTInStatus;
	uint8   OilPressWarnInStatus;
	uint8	LowFuelWarnInStatus;
	uint8	CruiseControlStatInStatus;
	uint8	EngSpdFiltInStatus;
	uint8   ISASetupInStatus;
	uint8	AWDStatusInStatus;
	uint8	Status4x4InStatus;
	uint8	NeutralTowInStatus;
	uint8 	Status4x4AutoTTIn;
	uint8 	Status4x4LoTTIn;
	uint8 	Status4x4HiTTIn;
	uint8	AWDTorqueInStatus;
	uint8	RearDiffLckMsgInStatus;
	uint8	SvcElockerInStatus;
	uint8	ElockerStatusInStatus;
	uint8	SvcGSMInStatus;
	uint8	TrailerLampsConnectedInStatus;
	uint8	TrailerLeftTurnLampInStatus;
	uint8	TrailerRightTurnLampInStatus;
	uint8	TrailerLampsControlInStatus;
	uint8	TrailerBatteryInStatus;
	uint8	TrailerStopLampInStatus;
	uint8	TrailerParkLampInStatus;
	uint8	TrailerDisconnectedInStatus;
	uint8	TrailerWiringFaultInStatus;
	uint8	TrailerConnectedInStatus;
	uint8	TrailerModuleFaultInStatus;
	uint8	LockMsgTxtInStatus;
	uint8	KeycodeStatInStatus;
	uint8	KeyAdminTotalInStatus;
	uint8	KeyMyKeyTotalInStatus;
	uint8	PESlotStatInStatus;
	uint8	ReduceGuardInStatus;
	uint8	HeadlampOnChimeInStatus;
	uint8	HomeSafeLghtChimeInStatus;
	uint8	ParkLghtChimeInStatus;
	uint8	ParkBrakeChimeInStatus;
	uint8	BrakeFluidStatusInStatus;
	uint8	FeatConfigBCMInStatus;
	uint8	FeatNoBCMInStatus;
	uint8	PersIndexBCMInStatus;
	uint8 	OutsideAirTempStatInStatus;
	uint8	FeatConfigDSMInStatus;
	uint8   FeatNoDSMInStatus;
	uint8 	PersIndexDSMInStatus;
	uint8	IgnStatInStatus;
	uint8	FeatConfigDDMInStatus;
	uint8	FeatNoDDMInStatus;
	uint8	PersIndexDDMInStatus;
	uint8	SvcTRCMInStatus;
	uint8	RBAAlertInStatus;
	uint8	RBAMsgInStatus;
	uint8   FeatConfigHCMInStatus;
	uint8 	FeatNoHCMInStatus;
	uint8	CADSRadarBlockInStatus;
	uint8	ACCStopModeInStatus;
	uint8	CADSAlignIncmpltInStatus;
	uint8	ACCFollowModeInStatus;
	uint8	ACCMsgTxtInStatus;
	uint8	ACCWarningInStatus;
	uint8	ACCModeSelInStatus;
	uint8	ACCTGapInStatus;
	uint8	ACCTGapStatInStatus;
	uint8	ACCStopResumeInStatus;
	uint8	iACCLampInStatus;
	uint8	TSRLimitRstrc2Stat2ndInStatus;
	uint8	TSRLimitRstrc1Stat2ndInStatus;
	uint8	TSRLimitPerm1InStatus;
	uint8	TSROvrTkMsgTxt2ndInStatus;
	uint8	TSRUnitsInStatus;
	uint8   WrongWayWarnInStatus;
	uint8	TSRLimit2InStatus;
	uint8	TSRLimit1InStatus;
	uint8	TSRLimit2StatInStatus;
	uint8	TSRLimit1StatInStatus;
	uint8	TSROvrTkStatInStatus;
	uint8	TSROvrTkMsgTxtInStatus;
	uint8	TSROvrSpdWarnInStatus;
	uint8	FCWDenyInStatus;
	uint8	FCWMsgTxtInStatus;
	uint8	FCWWarnChimeInStatus;
	uint8	FCWPostEventInStatus;
	uint8   FCWWarnStatInStatus;
	uint8	DistIndInStatus;
	uint8	FeatNoCCMInStatus;
	uint8	AutoHighBeamStatInStatus;
	uint8	LADenyStatInStatus;
	uint8	LAHandsOffInStatus;
	uint8	DASStatInStatus;
	uint8	DASWarnInStatus;
	uint8	FeatConfigIPMAInStatus;
	uint8	FeatNoIPMAInStatus;
	uint8	DriverCameraStatInStatus;
	uint8	PersIndexIPMAInStatus;
	uint8	TRGText2InStatus;
	uint8	TRGEnable2InStatus;
	uint8	TJAStatInStatus;
	uint8	TJAMsgTxtInStatus;
	uint8	TJAWarnRqInStatus;
	uint8   TJALaneBiasInStatus;
	uint8	HADispChecksumInStatus;
	uint8	HADispCountsInStatus;
	uint8	LAFeatStatInStatus;
	uint8   DASAlertInStatus;
	uint8	EngTempQFInValue;
	uint8   HUDBrightIn;
	uint8   HUDVertIn;
	uint8   HUDETMIn;
	uint8   HUDStatIn;
	uint8   HUDVertSzIn;
	uint8   HUDSwtchIn;
	uint8   FeatConfigHUDIn;
	uint8   FeatNoHUDIn;
	uint8   AudioChimeSupptIn;
	uint8   AudioChime2NRIn;
	uint8   AudioChimeNRIn;
	uint8   AudioChimeActvIn;
	uint8   AudioChime2ActvIn;
	uint8   ChimeAdjVolIn;
	uint8   ChimeNoIn;
	uint8   Chime2AdjVolIn;
	uint8   Chime2NoIn;
	uint8	E4x4StatusIn;
	uint8   SeatOccRearChimeIn;
	uint8   EmergencyCallFaultIn;
	uint8 	SvcBattTracIn;
	uint8	DcChrgRqIn;
	uint8 	BattTracSoCInStatus;
	uint8   MildHybStatInStatus;
	uint8   RngPerChrgAvgInStatus;
	uint8	PlugActiveInStatus;
	uint8	HybridModeStatInStatus;
	uint8   BattPwWhlInStatus;
	uint8   PwWhlLvlInStatus;
	uint8   EngineActiveInStatus;
	uint8   ASLDChimeInStatus;
	uint8	FuelUsedInStatus;
	uint8	ISAModeInStatus;
	uint8	UpshiftTTInStatus;
	uint8	ShiftIndInStatus;
	uint8	ECSSLampRqDsplyInStatus;
	uint8	GradeAssistDisplayInStatus;
	uint8	ASLDModeInStatus;
	uint8   LEDLBFaultInStatus;
	uint8   FrontFogTTInStatus;
	uint8   AWDPctFLInStatus;
	uint8   AWDPctFRInStatus;
	uint8   AWDPctRLInStatus;
	uint8   AWDPctRRInStatus;
	uint8   KeycodeDigit1InStatus;
	uint8   KeycodeDigit2InStatus;
	uint8   KeycodeDigit3InStatus;
	uint8   KeycodeDigit4InStatus;
	uint8   KeycodeDigit5InStatus;
	uint8   KeycodeDigit6InStatus;
	uint8   KeycodeDigit7InStatus;
	uint8   PLCStatusIn;	
	uint8   WaterInFuelFaltInStatus;
	uint8   EPBStatusInStatus;
	uint8   LifeCycleModeInStatus;
	uint8	DFDoorAjarInStatus;
	uint8	DRDoorAjarInStatus;
	uint8	PFDoorAjarInStatus;
	uint8	PRDoorAjarInStatus;
	uint8 	InnrTailgateAjarInStatus;
	uint8	DimLvlEvntInStatus;
	uint8	IgnKeyTypeInStatus;
	uint8	TailgateTrunkAjarInStatus;
	uint8	HoodAjarInStatus;
	uint8	DimLvlInStatus;
	uint8	UreaLvlPcInStatus;
	uint8	GearPosInStatus;
	uint8	CheckPlugInStatus;	
	uint8   SliderLeftInStatus;
	uint8	SlidingDoorLeftChimeInStatus;
	uint8	SlidingDoorLeftMessageTextInStatus;
	uint8   SliderRightInStatus;
	uint8	SlidingDoorRightChimeInStatus;
	uint8	SlidingDoorRightMessageTextInStatus;
	uint8	TwoRowSBDriverInStatus;
	uint8 	TwoRowSBMiddleInStatus;
	uint8 	TwoRowSBPassInStatus;
	uint8	ThreeRowSBDriverInStatus;
	uint8 	ThreeRowSBMiddleInStatus;
	uint8 	ThreeRowSBPassInStatus;
	uint8	TwoRowDriverSeatDetectInStatus;
	uint8	TwoRowMiddleSeatDetectInStatus;
	uint8	TwoRowPassSeatDetectInStatus;
	uint8	ThreeRowDriverSeatDetectInStatus;
	uint8	ThreeRowMiddleSeatDetectInStatus;
	uint8	ThreeRowPassSeatDetectInStatus;
	uint8	MiddleSeatDetectInStatus;
	uint8   HeaterCoreTempInValue;
	uint8	AdaptHeadlampFailInStatus;
	uint8	RunningBoardStatInStatus;
	uint8   BrakePadWearOutInStatus;
	uint8	TrailerBrkFaultStat2InValue;
	uint8	TrailerBrkFaultCounter2InValue;	
	uint8	TrailerBrkFaultCheckSum2InValue;	
	uint8   AutoHighBeamSCCMIn;
	uint32  SigInValue;
	uint8   BTTLeftRqstInStatus;
	uint8   BTTLeftInStatus;
	#ifdef COMABSCTRL_APPLICABLE_ONLY_FOR_V710
	uint8   PowerLiftgatestatInStatus;
	uint8	NFCDeviceInStatus;
	uint8	ParkLockAvailInStatus;
	uint8	ParkLockTextInStatus;
	uint8 	PowerSystemInStatus;
	#endif
	

#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
	uint8	SvcGearboxTTInStatus;
	uint8	SvcEngineTTInStatus;
	uint8   CruiseCtrlSetSpdInStatus;
	uint8   CruiseOverrideInStatus;
	uint8	OverTempLampInStatus;
	uint8	HeaterCoreTempInStatus;
	uint8	EngOilDayInStatus;
	uint8	DistToNextInStatus;
	uint8	EngOilSrvcInStatus;
	uint8 	EngAirFilterInStatus;
	uint8	TurboBoostInStatus;
	uint8   RearDiffTempInStatus;
	uint8   FuelIndInStatus;
	uint8   VehDispTCSetInStatus;
	uint8   SocThresholdInStatus;
	uint8   FuelRangeL2DsplyEngInStatus;
	uint8   BattElecPerf2InStatus;
	uint8   OPDActvStatInStatus;
	uint8   OPDFaultSysInStatus;
	uint8   EngMnfChrgTempInStatus;
	uint8   VehElAvgTrip1EffInStatus;
	uint8   VehElAvgTrip2EffInStatus;
	uint8   EW2STTInStatus;
	uint8   OilPressInStatus;
	uint8   AFRInStatus;
	uint8   eLatchStatusInStatus;
	uint8	eLatchEventInStatus;
	uint8	eLatchMsgInStatus;
	uint8	SvcBodyModInStatus;
	uint8	KeyInIgnInStatus;
	uint8	NFCDeviceInStatus;
	uint8	TireTempLFDataInStatus;
	uint8	TireTempRFDataInStatus;
	uint8	TireTempOLRDataInStatus;
	uint8	TireTempORRDataInStatus;
	uint8	PoliceIdleMdeInStatus;
	uint8	PoliceLGLockInStatus;
	uint8	VehWlcmFrwlInStatus;
	uint8	VehWlcmFrwlModeInStatus;
	uint8	ParkLockAvailInStatus;
	uint8	ParkLockTextInStatus;
	uint8	ParkLockUnlockInStatus;
	uint8	PowerSystemStatusInStatus;
	uint8	OATInStatus;
	uint8   TrailerBrkFaultStat2InStatus;
	uint8	TrailerBrkFaultCounter2InStatus;
	uint8	TrailerBrkFaultCheckSum2InStatus;
	uint8	APAChimeInStatus;
	uint8 	RegenAnimationInStatus;
	uint8 	BattPwAvailInStatus;
	uint8 	DrvModeSelectMsgInStatus;
	uint8 	TrailOnePdlMsgTxtRqInStatus;
	uint8	DrvSlipCtlModeMsgInStatus;
	uint8	AutoHoldIndInStatus;
	uint8	AutoHoldWarnInStatus;
	uint8	TCDispStatInStatus;
	uint8	SwViewInStatus;
	uint8 	CCDFaultInStatus;
	uint8   PwrDrLGChimeIn;
	uint8   PowerLiftgateStatIn;
	uint8	FrontSteerMsgInStatus;
	uint8	FeatConfigVDMInStatus;
	uint8	FeatNoVDMInStatus;
	uint8	PersIndexVDMInStatus;
	uint8	FourRowSBDriverInStatus;
	uint8	FourRowSBMidInStatus;
	uint8	FourRowSBPassInStatus;
	uint8	TwoRowSBMidDriverInStatus;
	uint8	TwoRowSBMidPassInStatus;
	uint8 	PersIndexHUDInStatus;
	uint8 	HUDRotateInStatus;
	uint8 	RACMBtnIDAInStatus;
	uint8 	RACMBtnIDBInStatus;
	uint8 	RACMBtnIDCInStatus;
	uint8 	RACMBtnIDDInStatus;
	uint8 	RACMCodingBtnIDAInStatus;
	uint8 	RACMCodingBtnIDBInStatus;
	uint8 	RACMCodingBtnIDCInStatus;
	uint8 	RACMCodingBtnIDDInStatus;
	uint8 	RACMSetVolumeInStatus;
	uint8 	RearAudioCtlLckDStInStatus;
	uint8 	RearMnuCtlLckBStInStatus;
	uint8   SwSetInStatus;
	uint8	SwMedInStatus;
	uint8	SwNavInStatus;
	uint8	LMCSwLtInStatus;
	uint8	LMCSwRtInStatus;
	uint8	SwPhoneInStatus;
	uint8	SwHomeInStatus;
	uint8	SwInfoInStatus;	
	uint8	SwPrimaryPosInStatus;
	uint8	SwPrimaryPressInStatus;
  	uint8	HighBeamSCCMInStatus;
	uint8 	BAlertLeftChimeInStatus;
	uint8	BAlertLeftLockInStatus;
	uint8	BAlertLeftStatusInStatus;
	uint8	BAlertLeftMdeSelInStatus;
	uint8	BAlertLeftModeInStatus;
	uint8	BAlertLeftSensorInStatus;
	uint8	BAlertLeftWindowInStatus;
	uint8   BTTRightInStatus;
	uint8 	BAlertRightChimeInStatus;
	uint8	BAlertRightLockInStatus;
	uint8	BAlertRightStatusInStatus;
	uint8	BAlertRightMdeSelInStatus;
	uint8	BAlertRightModeInStatus;
	uint8	BAlertRightSensorInStatus;
	uint8	BAlertRightWindowInStatus;
	uint8 	BtnIDAInStatus;
	uint8 	BtnIDBInStatus;
	uint8 	BtnIDCInStatus;
	uint8 	BtnIDDInStatus;
	uint8 	CodingBtnIDAInStatus;
	uint8 	CodingBtnIDBInStatus;
	uint8 	CodingBtnIDCInStatus;
	uint8 	CodingBtnIDDInStatus;
	uint8 	SetVolumeInStatus;
	uint8 	SetPointVolumeInStatus;
	uint8 	BCPAudibleBeepRqInStatus;
	uint8 	VehElEffAvgInStatus;
	uint8 	PercToDestInStatus;
	uint8 	SoCDisplayInStatus;
#endif

#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
	uint8	ManRgenFilterPfsInStatus;
	uint8	ManRgenTxtRqInStatus;
	uint8	DieselPrtcFilterInStatus;
	uint8	VSpdInStatus;
	uint8	FuelRangeLDsplyEngInStatus;
	uint8	PwrtrainDriveModeInStatus;
	uint8	StrtStpVThrsInStatus;
	uint8	ImmobilizerWarnInStatus;
	uint8	ParklampStatInStatus;
	uint8	LitvalInStatus;
	uint8	BrakeTTInStatus;
	uint8	HighBeamTTInStatus;
	uint8	KeyInIgnChimeInStatus;
	uint8   IgnPassDisplayInStatus;
	uint8   TransTempInStatus;
	uint8   EngOilTempInStatus;
	uint8   TransTempInValue;
#endif
		
	/*VOPS Variables*/
	GET_VOPS_CF_OPT_EPB(& cf_opt_epb_status);
	GET_VOPS_CF_OPT_ABS(& cf_opt_abs_status);
	GET_VOPS_CF_OPT_TC_IVD_RSC(& cf_opt_tc_ivd_rsc_status); 
	GET_VOPS_CF_OPT_RSC_WARNING_CHIME(&cf_opt_RSC_warning_chime_status ); 
	GET_VOPS_CF_OPT_ADVANCE_TRAC(& cf_opt_advance_trac_status);
	GET_VOPS_CF_OPT_TRAILER_SWAY(& cf_opt_trailer_sway_status);
	GET_VOPS_CF_OPT_SELECTABLE_DRIVE_MODE(& cf_opt_selectable_drive_mode_status);
	GET_VOPS_CF_OPT_DRIVER_BELTMINDER(&cf_opt_driver_beltminder_status);
	GET_VOPS_CF_OPT_RBM_EC_STRATEGY(&cf_opt_rbm_ec_strategy_status); 
	GET_VOPS_CF_OPT_PASS_BELTMINDER(&cf_opt_pass_beltminder_status); 
	GET_VOPS_CF_OPT_MID_PASS_BELTMINDER(&cf_opt_mid_pass_beltminder_status);
	GET_VOPS_CF_OPT_REAR_PARK_AID(&cf_opt_rear_park_aid_status);
	GET_VOPS_CF_OPT_AUTOPARK(&cf_opt_autopark_status);
	GET_VOPS_CF_OPT_ACTIVE_FRONT_STEERING(&cf_opt_active_front_steering_status);
	GET_VOPS_CF_OPT_COURTESY_WIPE_AFTER_WASH(&cf_opt_courtesy_wipe_after_wash_status);
	GET_VOPS_CF_OPT_RAIN_SENSING_WIPERS(&cf_opt_rain_sensing_wipers_status);
	GET_VOPS_CF_OPT_REAR_REVERSE_GEAR_WIPE(&cf_opt_rear_reverse_gear_wipe);
	GET_VOPS_CF_OPT_BSM(&cf_opt_bsm_status);
	GET_VOPS_CF_OPT_CTA(&cf_opt_cta_status);
	GET_VOPS_CF_OPT_BTTLITE(&cf_opt_bttlite);
	GET_VOPS_CF_OPT_HYBRID_ENGINE_CONFIG(&cf_opt_hybrid_engine_config_status);
	GET_VOPS_CF_OPT_ACC(&cf_opt_acc_status);
	GET_VOPS_CF_OPT_MANREGEN(&cf_opt_manregen_status);
	GET_VOPS_CF_OPT_AUTO_REGEN_CONTROL(&cf_opt_auto_regen_control_status);
	GET_VOPS_CF_OPT_ODOMETER_DELTA(&cf_opt_odometer_delta_status);
	GET_VOPS_CF_OPT_DIESEL_WARM_UP_WARNINGS_CONFIGURATION(&cf_opt_diesel_warm_up_warnings_status);
	GET_VOPS_CF_OPT_PT_HYBRID_2(&cf_opt_pt_hybrid_2_status);
	GET_VOPS_CF_OPT_PT_HYBRID_2(&cf_opt_pt_hybrid_2);
	GET_VOPS_CF_OPT_OIL_MINDER_DISTANCE_TIME(&cf_opt_oil_minder_distance_time_status);
	GET_VOPS_CF_OPT_DIESEL_ENGINE_CONFIG(&cf_opt_diesel_engine_config_status);
	GET_VOPS_CF_OPT_TACH_SIGNAL(&cf_opt_tach_signal_status);
	GET_VOPS_CF_OPT_ENGINE_HOUR_FUNCTION(&cf_opt_engine_hours_function_status);
	GET_VOPS_CF_OPT_ENGINE_IDLE_HOUR_FUNCTION(&cf_opt_engine_idle_hours_function_status);
	GET_VOPS_CF_OPT_AEIS_CONFIGURATION(&cf_opt_aeis_configuration_status);
	GET_VOPS_CF_OPT_FUELLVL_PCM(&cf_opt_fuellvl_pcm_status);
	GET_VOPS_CF_OPT_TURBO_BOOST(&cf_opt_turbo_boost_status);
	GET_VOPS_CF_OPT_OVERSPEED_WARNING(&cf_opt_overspeed_warning_status);
	GET_VOPS_CF_OPT_ASLD(&cf_opt_asld_status);
	GET_VOPS_CF_OPT_INTELLIGENTSPEEDASSIST(&cf_opt_intelligentspeedassist_status);
	GET_VOPS_CF_OPT_PWR_D_GAUGE_FEATURE(&cf_opt_pwr_d_gauge_feature_status);
	GET_VOPS_CF_OPT_TRANS_TYPE(&cf_opt_trans_type_status);
	GET_VOPS_CF_OPT_OIL_MINDER_10K(&cf_opt_oil_minder_10k_status);
	GET_VOPS_ENGINEAIRFILTERMINDER(&cf_opt_engineairfilterminder_status);
	GET_VOPS_CF_OPT_2WD_4x4_AWD(&cf_opt_2wd_4x4_awd_status);
	GET_VOPS_CF_OPT_NEUTRAL_TOW(&cf_opt_neutral_tow_status);
	GET_VOPS_CF_OPT_TCCM_NT(&cf_opt_tccm_nt_status);
	GET_VOPS_CF_OPT_E_LOCKER(&cf_opt_e_locker_status);
	GET_VOPS_CF_OPT_SHIFT_BY_WIRE(&cf_opt_shift_by_wire_status);
	GET_VOPS_CF_OPT_TRAILER_LIGHTING_STATUS(&cf_opt_trailer_lighting_status);
	GET_VOPS_CF_OPT_TRAILER_BRAKE_CONTROLLER(&cf_opt_trailer_brake_status);
	GET_VOPS_CF_OPT_MYKEY_CONFIGURATION(&cf_opt_mykey_feature_status);
	GET_VOPS_CF_OPT_TC_IVD_RSC(& cf_opt_tc_ivd_rsc_status);
	GET_VOPS_CF_OPT_MYKEY_VOLUME(& cf_opt_my_key_volume_status);
	GET_VOPS_CF_OPT_MYKEY_TRACTION_CONTROL_MENU(& cf_opt_mykey_traction_control_status);
	GET_VOPS_CF_OPT_MYKEY_SPEED_LIMIT_MJR_MKT(& cf_opt_mykey_spd_limit_mjr_mkt_status);
	GET_VOPS_CF_OPT_EMERGENCY_ASSIST(& cf_opt_emergency_assist_status);
	GET_VOPS_CF_OPT_DO_NOT_DISTURB(& cf_opt_do_not_disturb_status);
	GET_VOPS_CF_OPT_MYKEY_911_TEXT(& cf_opt_mykey_911_text_status);
	GET_VOPS_CF_OPT_PERIMETER_ALARM_WITH_REDUCED_GUARD_CONTROL_FUNCTION(&cf_opt_perimeter_alarm_with_reduced_guard_control_function_status);
	GET_VOPS_HIGHBEAMTELLTALESOURCE(&cf_opt_highbeamtelltalesource_status);
	GET_VOPS_CF_OPT_KEY_IN_IGNITION_REMINDER_CHIME(& cf_opt_key_in_ignition_reminder_chime_status);
	GET_VOPS_CF_OPT_APPROACH_DETECTION_CONTROL_FUNCTION(&cf_opt_approach_detection_control_function_status);
	GET_VOPS_CF_OPT_AUTO_RELOCK(&cf_opt_auto_relock_status);
	GET_VOPS_CF_OPT_PEPS(&cf_opt_peps_status);
	GET_VOPS_CF_OPT_INTELLIGENT_ACCESS_MENU(&cf_opt_intelligent_access_menu_status);
	GET_VOPS_CF_OPT_LOCKING_FEEDBACK_AUDIBLE(&cf_opt_locking_feedback_audible_status);
	GET_VOPS_CF_OPT_LOCKING_FEEDBACK_VISUAL(&cf_opt_locking_feedback_visual_status);
	GET_VOPS_CF_OPT_GLOBAL_WINDOW_CLOSE(&cf_opt_global_window_close_status);
	GET_VOPS_CF_OPT_DAYTIMERUNNINGLAMPS_CONFIGURATION(&cf_opt_daytimerunninglamps_status);
	GET_VOPS_CF_OPT_AUTOLOCK_CONFIGURATION(&cf_opt_autolock_status);
	GET_VOPS_CF_OPT_AUTOUNLOCK_CONFIGURATION(&cf_opt_autounlock_status);
	GET_VOPS_CF_OPT_AUTOLAMP_CONFIGURATION(&cf_opt_autolamp_status);
	GET_VOPS_CF_OPT_ONETWOSTAGEUNLOCK_CONFIGURATION(&cf_opt_onetwostageunlock_status);
	GET_VOPS_CF_OPT_OUTSIDE_AIR_TEMPERATURE(&cf_opt_outside_air_temperature_status);
	GET_VOPS_CF_OPT_SETTINGS_MENU(& cf_opt_settings_menu_status);
	GET_VOPS_CF_OPT_REMOTE_START(&cf_opt_remote_start_status);
	GET_VOPS_CF_OPT_EASY_ENTRY_EASY_EXIT_CONFIGURATION(&cf_opt_easy_entry_easy_exit_configuration_status);
	GET_VOPS_CF_OPT_GLOBAL_WINDOW_OPEN(&cf_opt_global_window_open_status);
	GET_VOPS_CF_OPT_MIRRORS_AUTOFOLD_CONFIGURATION(&cf_opt_mirrors_autofold_status);	
    GET_VOPS_CF_OPT_MIRRORS_REVERSE_TILT_CONFIGURATION(&cf_opt_mirrors_reverse_tilt_status);
	GET_VOPS_CF_OPT_TRCM_PRESENT(&cf_opt_trcm_present_status);
	GET_VOPS_CF_OPT_REVERSE_BRAKE_ASSIST(&  cf_opt_reverse_brake_assist_status);
	GET_VOPS_CF_OPT_TRAILER_BACKUP_ASSIST(&cf_opt_trailer_backup_assist_status);
	GET_VOPS_CF_OPT_TRAILER_REVERSE_GUIDANCE(&cf_opt_trailer_reverse_guidance_status);
	GET_VOPS_CF_OPT_PREDICTIVE_LIGHTING_CONFIGURATION(& cf_opt_predictive_lighting_configuration_status); 
	GET_VOPS_ADAPTIVEHEADLAMPS(&cf_opt_adaptiveheadlamps_status);
	GET_VOPS_CF_OPT_ACC(&cf_opt_acc_status);
	GET_VOPS_TRAFFICSIGNRECOGNITION(&cf_opt_trafficsignrecognition_status);
	GET_VOPS_SLIF(&cf_opt_slif_status);
	GET_VOPS_CF_OPT_FCW(&cf_opt_fcw_status);
	GET_VOPS_CF_OPT_AUTO_HIGH_BEAM_TELLTALE(&cf_opt_auto_high_beam_telltale_status);
	GET_VOPS_CF_OPT_LANE_ASSIST(&cf_opt_lane_assist_status);
	GET_VOPS_CF_OPT_DAS(&cf_opt_das_status);
	GET_VOPS_CF_OPT_FRONT_CAMERA(&cf_opt_front_camera_status); 
	GET_VOPS_CF_OPT_AUTOHIGHBEAM_MENU(&cf_opt_autohighbeam_menu_status);
	GET_VOPS_CF_OPT_IACC(&cf_opt_iacc_status);
	GET_VOPS_TRAFFICJAMASSIST(&cf_opt_trafficjamassist_status);
	GET_VOPS_HIGHWAYASSIST(&cf_opt_highwayassist_status);
	GET_VOPS_AWDSOURCEMODULE(&cf_opt_awdsourcemodule);
	GET_VOPS_AHUDMENU(&cf_opt_ahudmenu);
	GET_VOPS_CHUD(&cf_opt_chud);	
	GET_VOPS_PRIMARYCHIMESOURCE(&cf_opt_primarychimesource);
	GET_VOPS_EMERGENCYCALLFAULT(&cf_opt_emergencycallfault);
	GET_VOPS_CF_OPT_MHEV_CONFIGURATION(&cf_opt_MHEV_Configuration);
	GET_VOPS_CF_OPT_SHIFT_OUT_OF_NEUTRAL(&cf_opt_Shift_Out_Of_Neutral);
	GET_VOPS_EVDISPLAY_CONFIG_FORDVEHICLES(&cf_opt_EV_Display_Configuration_for_FordVehicles);
	GET_VOPS_EVDISPLAY_CONFIG_LINCOLNVEHICLES(&cf_opt_EV_Display_Configuration_for_LincolnVehicles);
	GET_VOPS_ENGINE_FUEL_TYPE(&cf_opt_engine_fuel_type);
	GET_VOPS_LFR_CONFIG(&cf_opt_lfr_config);
	GET_VOPS_UPSHIFT_INDICATOR(&cf_opt_upshift_indicator);
	GET_VOPS_PERF_SHIFT_INDICATOR(&cf_opt_perf_shift_indicator);
	GET_VOPS_GRADE_ASSIST_MENU(&cf_opt_grade_assist_menu);
	GET_VOPS_MHEV_START_STOP_SPEED_TH(&cf_opt_mHEV_start_stop_speed_th);
	GET_VOPS_TCM_PRESENT(&cf_opt_tcm_present);
	GET_VOPS_LED_LOWBEAMFAULTINDICATOR(&cf_opt_LED_LowBeamFaultIndicator);
	GET_VOPS_POWERLIFTGATE(&cf_opt_powerliftgate);
	GET_VOPS_POWERLIFTGATEHANDSFREEMENU(&cf_opt_powerliftgatehandsfreemenu);
	GET_VOPS_FRONTFOGTT(&cf_opt_frontfogtelltale);
	GET_VOPS_AWDGAUGEFEATURE(&cf_opt_awd_gaguge_feature);
	GET_VOPS_BRAZILCOLDSTARTRESERVOIR(&cf_opt_Brazil_Cold_Start_Reservoir);
	GET_VOPS_CF_OPT_DEF_GAUGE_CONFIGURATION(&cf_opt_def_gauge_configuration_status);
	GET_VOPS_AEISWITHOVERRIDE(&cf_opt_aeis_with_override);
	GET_VOPS_AEISWITHOUTOVERRIDE(&cf_opt_aeis_without_override);
	GET_VOPS_DOORAJARWARNING(&cf_opt_doorajarwarning);
	GET_VOPS_WELCOME(&cf_opt_welcome);
	GET_VOPS_POWERSLIDINGDOOR(&cf_opt_powerslidingdoor);
	GET_VOPS_DIMIICONTROLMIRROR(&cf_opt_DimIIControlMirror);
	GET_VOPS_HOODAJAR(&cf_opt_hoodajar);
	GET_VOPS_SIDEMARKER(&cf_opt_sidemarker);
	GET_VOPS_POWERSLIDINGDOORLEFTCONFIG(&cf_opt_powerslidingdoorleftconfig);
	GET_VOPS_POWERSLIDINGDOORRIGHTCONFIG(&cf_opt_powerslidingdoorrightconfig);
	GET_VOPS_R1C1SEATBELT(&cf_opt_R1C1SeatBelt);
	GET_VOPS_R1C3SEATBELT(&cf_opt_R1C3SeatBelt);
	GET_VOPS_R1C5SEATBELT(&cf_opt_R1C5SeatBelt);
	GET_VOPS_R2C1SEATBELT(&cf_opt_R2C1SeatBelt);
	GET_VOPS_R2C3SEATBELT(&cf_opt_R2C3SeatBelt);
	GET_VOPS_R2C5SEATBELT(&cf_opt_R2C5SeatBelt);
	GET_VOPS_R3C1SEATBELT(&cf_opt_R3C1SeatBelt);
	GET_VOPS_R3C3SEATBELT(&cf_opt_R3C3SeatBelt);
	GET_VOPS_R3C5SEATBELT(&cf_opt_R3C5SeatBelt);
	GET_VOPS_R1C1BELTMINDERCHIME(&cf_opt_R1C1BeltMinderChime);
	GET_VOPS_R1C3BELTMINDERCHIME(&cf_opt_R1C3BeltMinderChime);
	GET_VOPS_R1C5BELTMINDERCHIME(&cf_opt_R1C5BeltMinderChime);
	GET_VOPS_PASSENGERAIRBAGSETTING(&cf_opt_PassengerAirbagSetting);
	GET_VOPS_4x4CANHA(&cf_opt_4x4canhw);
	GET_VOPS_CF_OPT_RUNNING_BOARD_CONTROL_FUNCTION(&cf_opt_running_board_control_function);
	GET_VOPS_CERAMICBRAKEPADWEARINDICATOR(&cf_opt_CeramicBrakePadWearIndicator);
	GET_VOPS_TRAILERBRAKEE2ESIGNALPROTECTION(&cf_opt_TrailerBrakee2eSignalProtection);
	GET_VOPS_SHIFTOUTOFNEUTRAL(&cf_opt_shiftoutofneutral);
	GET_VOPS_EVDISPLAYCONFIGFORD(&cf_opt_evdisplayconfigford);
	GET_VOPS_EVDISPLAYCONFIGLINCOLN(&cf_opt_evdisplayconfiglincoln);
	GET_VOPS_BEVPHEVCONFIG(&cf_opt_bevphevconfig);
	GET_VOPS_MHEVCONFIGURATION(&cf_opt_mhevconfiguration);
	GET_VOPS_AUTOHIGHBEAMTELLTALE(&cf_opt_autohighbeamtelltale);
	GET_VOPS_AUTO_HIGH_BEAM_MENU(&cf_opt_auto_high_beam_menu);
	GET_VOPS_PARKLOCKALLOWCONFIGURATION(&cf_opt_park_lock_allow);
	GET_VOPS_TAILGATEAJARWARNINGCONFIG(&cf_opt_tail_gate_ajar_warning);
	GET_VOPS_TRUNKAJARCONFIG(&cf_opt_trunk_ajar_config);
	GET_VOPS_INTELLIGENTACCESSCONFIG(&cf_opt_intelligent_access_config);
	GET_VOPS_TRIMSWITCHINHIBITCONFIG(&cf_opt_trim_switch_config);
	GET_VOPS_MISLOCKCHIRPMENU(&cf_opt_mislock_chirp_menu);
	GET_VOPS_SILENTMODECONFIG(&cf_opt_silent_mode_config);
	GET_VOPS_HANDSFREELIFTGATECONFIG(&cf_opt_handsfree_lift_gate_config);
	GET_VOPS_WRONGWAYALERT(&cf_opt_wrongwayalert);
	GET_VOPS_TSRCONFIG(&cf_opt_TSR_config);
	GET_VOPS_LANEASSISTNCAPALERT(&cf_opt_lane_assist_ncap_alert);
	GET_VOPS_LANEASSISTNCAPAID(&cf_opt_lane_assist_ncap_aid);
	GET_VOPS_ELECTRONICLATCH(&cf_opt_electroniclatch);
	GET_VOPS_TIRETEMPDISPLAY(&cf_opt_tiretempdisplay);
	GET_VOPS_ADVANCETRACCONFIGURATION(&cf_opt_advanceTracConfiguration);
	GET_VOPS_CF_OPT_CHARGEPORTDOORAJARWARNINGCONFIGURATION(&cf_opt_ChargePortDoorAjarWarningConfiguration);
	GET_VOPS_POWERLOCKCONTROLCONFIG(&cf_opt_powerlockcontrolconfig);
#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
	GET_VOPS_POLICEIDLEMODE(&cf_opt_policeidlemode);
	GET_VOPS_ADVANCETRACEHARDBUTTON(&cf_opt_AdvanceTracHardButton);
	GET_VOPS_AUTOHOLD(&cf_opt_autohold_status);
	GET_VOPS_R4C1SEATBELT(&cf_opt_R4C1SeatBelt);
	GET_VOPS_R4C3SEATBELT(&cf_opt_R4C3SeatBelt);
	GET_VOPS_R4C5SEATBELT(&cf_opt_R4C5SeatBelt);
	GET_VOPS_ADAPTIVESTEERINGMENU(&cf_opt_adaptiveSteeringMenu);
	GET_VOPS_RSEM(&cf_opt_rsem_config);
	GET_VOPS_REFP(&cf_opt_refp_config);
	GET_VOPS_MSGCENTEREDDISPLAYINTERFACE(&cf_opt_msgcentredisplayinterface);
	GET_VOPS_BOUNDARYALERT(&cf_opt_boundary_alert);
	GET_VOPS_ICPNETWORK(&cf_opt_icpnetwork);
	GET_VOPS_ICPPRESENT(&cf_opt_icppresent);
#endif
	GET_VOPS_POLICELIFTGATEUNLOCK(&cf_opt_policeliftgateunlock);
	GET_VOPS_AXLEOILTEMPDISPLAY(&cf_opt_axleoiltempdisplay);
	GET_VOPS_TRAILCONTROL(&cf_opt_trailcontrol);
	GET_VOPS_BEVCONFIG(&cf_opt_bevconfig);
	GET_VOPS_MANIFOLDCHARGETEMP(&cf_opt_manifoldchargetemp);
	GET_VOPS_DIESELPARTICULATEFILTERCONFIG(&cf_opt_dieselparticulatefilterconfig);
    GET_VOPS_INDIAOVERSPEEDWARNING(&cf_opt_Indiaover_speed_warning);         
	GET_VOPS_PDSFAULTCONFIG(&cf_opt_pdcfaultconfig);     
	GET_VOPS_OILPRESSURESENSOR(&cf_opt_oilpressuresensor);     
	GET_VOPS_AIRTOFUELRATIO(&cf_opt_airfuelratio);  
	GET_VOPS_OILTEMP(&cf_opt_oiltemp);  
	GET_VOPS_CF_OPT_REVERSE_WARNING(&cf_opt_reverse_warning_status); 
	#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC       
	GET_VOPS_TRANSMISSIONFLUIDTEMPGAUGECONFIG(&cf_opt_TransmissionFluidTemperatureGaugeConfiguration); 
	GET_VOPS_TRANSMISSIONFLUIDTEMPDISPLAY(&cf_opt_transmissionfluidtempdisplay_status);
    #endif 
	#ifdef COMABSCTRL_APPLICABLE_ONLY_FOR_V710
	GET_VOPS_PARKLOCKCONTROLCONFIG(&cf_opt_parklockcontrolconfig);
	#endif                        

	/*CAN Signals*/
	GET_CAN_RX_ENGTEMPIN(&SigInValue,&EngTempInStatus);
	GET_CAN_RX_ENGTEMPQFIN(&SigInValue,&EngTempQFInStatus);  
	GET_CAN_RX_ODOIN(&SigInValue,&OdoInStatus);  
	GET_CAN_RX_PWRTRAINTORQUEIN(&SigInValue,&PwrTrainTorqueInStatus);
	GET_CAN_RX_VSPDQFIN(&VSpdQFInValue,&VSpdQFInStatus);
	GET_CAN_RX_PARKBRKSTATUSIN(& SigInValue,& ParkBrkStatusInStatus);
	GET_CAN_RX_ABSTTIN(&SigInValue,&ABSTTInStatus);
	GET_CAN_RX_ABSBRAKETTIN(&SigInValue,&ABSBrakeTTInStatus);
	GET_CAN_RX_SCTTIN(& SigInValue,& SCTTInStatus);
	GET_CAN_RX_SVCADVTRACCHIMERQIN(&SigInValue,&SvcAdvTracChimeRqInStatus); 
	GET_CAN_RX_SCOFFTTIN(&SigInValue,&SCOffTTInStatus);
	GET_CAN_RX_TRAILERSWAYCONFIGIN(&SigInValue,&TrailerSwayConfigInStatus);
	GET_CAN_RX_DRIVEMODESELIN(&SigInValue,&DriveModeSelInStatus);
	GET_CAN_RX_ACTIVEDRIVEMODEIN(&SigInValue,&ActiveDriveModeInStatus);
	GET_CAN_RX_DRVMODESELECTSTATIN(&SigInValue,&DrvModeSelectStatInStatus);
	GET_CAN_RX_RILTTIN(& SigInValue,& RILTTInStatus);
	GET_CAN_RX_ROWSBDRIVERIN(& SigInValue,& OneRowSBDriverInStatus);
	GET_CAN_RX_ROWSBPASSIN(& SigInValue,& OneRowSBPassInStatus);
	GET_CAN_RX_PASSSEATDETECTIN(& SigInValue,& PassSeatDetectInStatus);
	GET_CAN_RX_ROWSBMIDDLEIN(& SigInValue,& OneRowSBMiddleInStatus);
	GET_CAN_RX_PARKAIDMESGIN(& SigInValue,& ParkAidMesgInStatus);
	GET_CAN_RX_RPASTATIN(& SigInValue,& RPAStatInStatus);
	GET_CAN_RX_APASYSIN(& SigInValue,& APASysInStatus);
	GET_CAN_RX_FEATCONFIGSCCMIN(& SigInValue,& FeatConfigSCCMInStatus);      											
    GET_CAN_RX_FEATNOSCCMIN(& SigInValue,& FeatNoSCCMInStatus);
	GET_CAN_RX_LBSMOPIN(& SigInValue,& LBSMOpInStatus);      				
	GET_CAN_RX_LBSMSNSRIN(& SigInValue,& LBSMSnsrInStatus);      			
	GET_CAN_RX_LCROSSTRAFFICALERTIN(& SigInValue,& LCrossTrafficAlertInStatus);      
	GET_CAN_RX_LCROSSTRAFFICOPIN(& SigInValue,& LCrossTrafficOpInStatus);      		
	GET_CAN_RX_LCROSSTRAFFICSNSRIN(& SigInValue,& LCrossTrafficSnsrInStatus);      
	GET_CAN_RX_LCROSSTRAFFICALERTBRAKEIN(& SigInValue,& LCrossTrafficAlertBrakeInStatus);
	GET_CAN_RX_RBSMOPIN(& SigInValue,& RBSMOpInStatus);      				
	GET_CAN_RX_RBSMSNSRIN(& SigInValue,& RBSMSnsrInStatus);      			
	GET_CAN_RX_RCROSSTRAFFICALERTIN(& SigInValue,& RCrossTrafficAlertInStatus);      
	GET_CAN_RX_RCROSSTRAFFICOPIN(& SigInValue,& RCrossTrafficOpInStatus); 
	#ifdef COMABSCTRL_APPLICABLE_ONLY_FOR_V710
	GET_CAN_RX_BTTRIGHTRQSTIN(& SigInValue,& BTTRightRqstInStatus);     
	#endif		
	GET_CAN_RX_RCROSSTRAFFICSNSRIN(& SigInValue,& RCrossTrafficSnsrInStatus);      
	GET_CAN_RX_RCROSSTRAFFICALERTBRAKEIN(& SigInValue,& RCrossTrafficAlertBrakeInStatus);
	GET_CAN_RX_REGENLEVELIN(& SigInValue,& RegenLevelInStatus);
	GET_CAN_RX_BRAKEEVENTIN(& SigInValue,& BrakeEventInStatus);
	GET_CAN_RX_EFFWHLLVL2IN(& SigInValue,& EffWhlLvl2InStatus);    
	GET_CAN_RX_EFFWHLTHRESIN(& SigInValue,& EffWhlThresInStatus);    
	GET_CAN_RX_ENGMODEMSGTXTIN(& SigInValue,& EngModeMsgTxtInStatus);  
	GET_CAN_RX_EFFRGNTHRESIN(& SigInValue,& EffRgnThresInStatus);								
	GET_CAN_RX_FSCIN(&SigInValue,&FSCInStatus);	
	GET_CAN_RX_AUTOREGENCTRLTTIN(&SigInValue,&AutoRegenCtrlTTInStatus);
	GET_CAN_RX_ODOTRIPVERIFYIN(&SigInValue,&OdoTripVerifyInStatus);      						
	GET_CAN_RX_STOPSTARTTTIN(&SigInValue,&StopStartTTInStatus);      							
	GET_CAN_RX_PWRPACKSTATIN(&SigInValue,&PwrPackStatInStatus);
	GET_CAN_RX_EPRNDLIN(&SigInValue,&ePRNDLInStatus);
	GET_CAN_RX_DIESELENGTECOLDIN(&SigInValue,&DieselEngTeColdInStatus);
	GET_CAN_RX_FUELINLETSTATUSIN(&SigInValue,&FuelInletStatusInStatus);
	GET_CAN_RX_ENGOILLIFEIN(&SigInValue,&EngOilLifeInStatus);	
	GET_CAN_RX_W2STTIN(&SigInValue,&W2STTInStatus);
	GET_CAN_RX_WATERINFUELTTIN(&SigInValue,&WaterInFuelTTInStatus);
	GET_CAN_RX_ENGSPDUNFILTIN(&SigInValue,&EngSpdUnfiltInStatus);      						    								
	GET_CAN_RX_ENGIDLSHUTDOWNIN(&SigInValue,&EngIdlShutDownInStatus); 
	GET_CAN_RX_OILPRESSWARNIN(& SigInValue,& OilPressWarnInStatus);  	
	GET_CAN_RX_MILTTIN(& SigInValue,& MILTTInStatus);
	GET_CAN_RX_LOWFUELWARNIN(&SigInValue,&LowFuelWarnInStatus);
	GET_CAN_RX_CRUISECONTROLSTATIN(&SigInValue,&CruiseControlStatInStatus);      					
	GET_CAN_RX_ENGSPDFILTIN(&SigInValue,&EngSpdFiltInStatus);      							     							
	GET_CAN_RX_ISASETUPIN(& SigInValue,& ISASetupInStatus);	
	GET_CAN_RX_ISASETUPIN(&SigInValue,& ISASetupInStatus);
	GET_CAN_RX_AWDSTATUSIN(& SigInValue,& AWDStatusInStatus);			 	
    GET_CAN_RX_4X4STATUSIN(& SigInValue,& Status4x4InStatus);         
    GET_CAN_RX_NEUTRALTOWIN(& SigInValue,& NeutralTowInStatus);
	GET_CAN_RX_4X4AUTOTTIN(&SigInValue,&Status4x4AutoTTIn);
	GET_CAN_RX_4X4LOTTIN(&SigInValue,&Status4x4LoTTIn);
	GET_CAN_RX_4X4HITTIN(&SigInValue,&Status4x4HiTTIn);
	GET_CAN_RX_AWDTORQUEIN(& SigInValue,& AWDTorqueInStatus);      
	GET_CAN_RX_REARDIFFLCKMSGIN(& SigInValue,& RearDiffLckMsgInStatus);  
	GET_CAN_RX_SVCELOCKERIN(& SigInValue,& SvcElockerInStatus);      
	GET_CAN_RX_ELOCKERSTATUSIN(& SigInValue,& ElockerStatusInStatus);
	GET_CAN_RX_SVCGSMIN(&SigInValue,& SvcGSMInStatus);
	GET_CAN_RX_TRAILERLAMPSCONNECTEDIN(&SigInValue,&TrailerLampsConnectedInStatus);
	GET_CAN_RX_TRAILERLEFTTURNLAMPIN(&SigInValue,&TrailerLeftTurnLampInStatus);
	GET_CAN_RX_TRAILERRIGHTTURNLAMPIN(&SigInValue,&TrailerRightTurnLampInStatus);
	GET_CAN_RX_TRAILERLAMPSCONTROLIN(&SigInValue,&TrailerLampsControlInStatus);
	GET_CAN_RX_TRAILERBATTERYIN(&SigInValue,&TrailerBatteryInStatus);
	GET_CAN_RX_TRAILERSTOPLAMPSIN(&SigInValue,&TrailerStopLampInStatus);
	GET_CAN_RX_TRAILERPARKLAMPSIN(&SigInValue,&TrailerParkLampInStatus);
	GET_CAN_RX_TRAILERDISCONNECTEDIN(&SigInValue,&TrailerDisconnectedInStatus);
	GET_CAN_RX_TRAILERWIRINGFAULTIN(&SigInValue,&TrailerWiringFaultInStatus);
	GET_CAN_RX_TRAILERCONNECTEDIN(&SigInValue,&TrailerConnectedInStatus);
	GET_CAN_RX_TRAILERMODULEFAULTIN(&SigInValue,&TrailerModuleFaultInStatus);
	GET_CAN_RX_LOCKMSGTXTIN(&SigInValue,&LockMsgTxtInStatus); 														
	GET_CAN_RX_KEYCODESTATIN(&SigInValue,&KeycodeStatInStatus); 													  	
	GET_CAN_RX_KEYADMINTOTALIN(& SigInValue,& KeyAdminTotalInStatus);
	GET_CAN_RX_KEYMYKEYTOTALIN(& SigInValue,& KeyMyKeyTotalInStatus);
	GET_CAN_RX_PESLOTSTATIN(& SigInValue,& PESlotStatInStatus);
	GET_CAN_RX_REDUCEGUARDIN(&SigInValue,&ReduceGuardInStatus);	
	GET_CAN_RX_HEADLAMPONCHIMEIN(&SigInValue,&HeadlampOnChimeInStatus);	
	GET_CAN_RX_HOMESAFELGHTCHIMEIN(&SigInValue,&HomeSafeLghtChimeInStatus);      											
	GET_CAN_RX_PARKLGHTCHIMEIN(&SigInValue,&ParkLghtChimeInStatus);      												
	GET_CAN_RX_PARKBRAKECHIMEIN(&SigInValue,&ParkBrakeChimeInStatus);      												
	GET_CAN_RX_BRAKEFLUIDSTATUSIN(&SigInValue,&BrakeFluidStatusInStatus);
	GET_CAN_RX_FEATCONFIGBCMIN(&SigInValue,&FeatConfigBCMInStatus); 
	GET_CAN_RX_FEATNOBCMIN(&SigInValue,&FeatNoBCMInStatus);
	GET_CAN_RX_PERSINDEXBCMIN(&SigInValue,&PersIndexBCMInStatus);
	GET_CAN_RX_OUTSIDEAIRTEMPSTATIN(&SigInValue,&OutsideAirTempStatInStatus);
	GET_CAN_RX_FEATCONFIGDSMIN(&SigInValue,&FeatConfigDSMInStatus);
	GET_CAN_RX_FEATNODSMIN(&SigInValue,&FeatNoDSMInStatus);
	GET_CAN_RX_PERSINDEXDSMIN(&SigInValue,&PersIndexDSMInStatus);
	GET_CAN_RX_IGNSTATIN(&SigInValue,&IgnStatInStatus);
	GET_CAN_RX_FEATCONFIGDDMIN(&SigInValue,&FeatConfigDDMInStatus);      													
	GET_CAN_RX_FEATNODDMIN(&SigInValue,&FeatNoDDMInStatus);      													    
	GET_CAN_RX_PERSINDEXDDMIN(&SigInValue,&PersIndexDDMInStatus);
	GET_CAN_RX_SVCTRCMIN(& SigInValue,& SvcTRCMInStatus);
	GET_CAN_RX_RBAMSGIN(& SigInValue,& RBAMsgInStatus);
	GET_CAN_RX_RBAALERTIN(& SigInValue,& RBAAlertInStatus);
	GET_CAN_RX_TRGTEXT2IN(& SigInValue,& TRGText2InStatus);
	GET_CAN_RX_TRGENABLE2IN(& SigInValue,& TRGEnable2InStatus);
	GET_CAN_RX_FEATCONFIGHCMIN(& SigInValue,& FeatConfigHCMInStatus);
	GET_CAN_RX_FEATNOHCMIN(& SigInValue,& FeatNoHCMInStatus);
	GET_CAN_RX_CADSRADARBLOCKIN(& SigInValue,& CADSRadarBlockInStatus);
	GET_CAN_RX_ACCSTOPMODEIN(& SigInValue,& ACCStopModeInStatus);
	GET_CAN_RX_CADSALIGNINCMPLTIN(& SigInValue,& CADSAlignIncmpltInStatus);
	GET_CAN_RX_ACCFOLLOWMODEIN(& SigInValue,& ACCFollowModeInStatus);
	GET_CAN_RX_ACCMSGTXTIN(& SigInValue,& ACCMsgTxtInStatus);
	GET_CAN_RX_ACCWARNINGIN(& SigInValue,& ACCWarningInStatus); 
	GET_CAN_RX_ACCMODESELIN(& SigInValue,& ACCModeSelInStatus);
	GET_CAN_RX_ACCTGAPIN(& SigInValue,& ACCTGapInStatus);
	GET_CAN_RX_ACCTGAPSTATIN(& SigInValue,& ACCTGapStatInStatus);
	GET_CAN_RX_ACCSTOPRESUMEIN(& SigInValue,& ACCStopResumeInStatus);
	GET_CAN_RX_IACCLAMPIN(& SigInValue,& iACCLampInStatus);
	GET_CAN_RX_TSRLIMITRSTRC2STAT2NDIN(& SigInValue,& TSRLimitRstrc2Stat2ndInStatus);
	GET_CAN_RX_TSRLIMITRSTRC1STAT2NDIN(& SigInValue,& TSRLimitRstrc1Stat2ndInStatus);
	GET_CAN_RX_TSRLIMITPERM1IN(& SigInValue,& TSRLimitPerm1InStatus);      									
	GET_CAN_RX_TSROVRTKMSGTXT2NDIN(& SigInValue,& TSROvrTkMsgTxt2ndInStatus);      							
	GET_CAN_RX_TSRUNITSIN(& SigInValue,&TSRUnitsInStatus);     
	GET_CAN_RX_WRONGWAYWARNIN(& SigInValue,&WrongWayWarnInStatus); 												
	GET_CAN_RX_TSRLIMIT2IN(& SigInValue,&  TSRLimit2InStatus);    											
	GET_CAN_RX_TSRLIMIT1IN(& SigInValue,& TSRLimit1InStatus);      											
	GET_CAN_RX_TSRLIMIT2STATIN(& SigInValue,& TSRLimit2StatInStatus);      									
	GET_CAN_RX_TSRLIMIT1STATIN(& SigInValue,& TSRLimit1StatInStatus);      									
	GET_CAN_RX_TSROVRTKSTATIN(& SigInValue,& TSROvrTkStatInStatus);      									
	GET_CAN_RX_TSROVRTKMSGTXTIN(& SigInValue,& TSROvrTkMsgTxtInStatus);      								
	GET_CAN_RX_TSROVRSPDWARNIN(& SigInValue,& TSROvrSpdWarnInStatus); 
	GET_CAN_RX_FCWDENYIN(& SigInValue,& FCWDenyInStatus); 
	GET_CAN_RX_FCWMSGTXTIN(& SigInValue,& FCWMsgTxtInStatus);     															
    GET_CAN_RX_FCWWARNCHIMEIN(& SigInValue,& FCWWarnChimeInStatus); 
	GET_CAN_RX_FCWPOSTEVENTIN(& SigInValue,& FCWPostEventInStatus);
    GET_CAN_RX_FCWWARNSTATIN(& SigInValue,& FCWWarnStatInStatus);
	GET_CAN_RX_DISTINDIN(& SigInValue,& DistIndInStatus);
	GET_CAN_RX_FEATNOCCMIN(& SigInValue,& FeatNoCCMInStatus);
	GET_CAN_RX_AUTOHIGHBEAMSTATIN(& SigInValue,& AutoHighBeamStatInStatus);
	GET_CAN_RX_LADENYSTATIN(& SigInValue,& LADenyStatInStatus);      										
    GET_CAN_RX_LAHANDSOFFIN(& SigInValue,& LAHandsOffInStatus);
	GET_CAN_RX_DASSTATIN(& SigInValue,& DASStatInStatus);      											
    GET_CAN_RX_DASWARNIN(& SigInValue,& DASWarnInStatus);  
	GET_CAN_RX_FEATCONFIGIPMAIN(& SigInValue,& FeatConfigIPMAInStatus);      									
    GET_CAN_RX_FEATNOIPMAIN(& SigInValue,& FeatNoIPMAInStatus);
	GET_CAN_RX_DRIVERCAMERASTATIN(& SigInValue,& DriverCameraStatInStatus);
	GET_CAN_RX_PERSINDEXIPMAIN(& SigInValue,& PersIndexIPMAInStatus);
	GET_CAN_RX_TJASTATIN(&SigInValue,&TJAStatInStatus);
	GET_CAN_RX_TJAMSGTXTIN(&SigInValue,&TJAMsgTxtInStatus);
	GET_CAN_RX_TJAWARNRQIN(&SigInValue,&TJAWarnRqInStatus);
	GET_CAN_RX_TJALANEBIASIN(&SigInValue,&TJALaneBiasInStatus);
	GET_CAN_RX_HADISPCHECKSUMIN(&SigInValue,&HADispChecksumInStatus);
	GET_CAN_RX_HADISPCOUNTSIN(&SigInValue,&HADispCountsInStatus);
	GET_CAN_RX_LAFEATSTATIN(& SigInValue,& LAFeatStatInStatus);
	GET_CAN_RX_DASALERTIN(& SigInValue,& DASAlertInStatus);
	GET_CAN_RX_SWMENUIN(& SigInValue,& SwMenuInStatus);      												  	
    GET_CAN_RX_SWOKIN(& SigInValue,& SwOKInStatus);      												  	
    GET_CAN_RX_SWUPIN(& SigInValue,& SwUpInStatus);				      										
    GET_CAN_RX_SWDNIN(& SigInValue,& SwDnInStatus);				      										
    GET_CAN_RX_SWBKIN(& SigInValue,& SwBkInStatus);
	GET_CAN_RX_SWHUDIN(& SigInValue,& SwHUDInStatus);	
	GET_CAN_RX_ICICODBTNIDAIN(& SigInValue,& ICICodBtnIDAInStatus); 		     									
    GET_CAN_RX_ICICODBTNIDBIN(& SigInValue,& ICICodBtnIDBInStatus);      											
    GET_CAN_RX_ICICODBTNIDCIN(& SigInValue,& ICICodBtnIDCInStatus);      											
    GET_CAN_RX_ICICODBTNIDDIN(& SigInValue,& ICICodBtnIDDInStatus);      											
    GET_CAN_RX_ICIBTNIDAIN(& SigInValue,&ICIBtnIDAInStatus);      												
    GET_CAN_RX_ICIBtnIDBIN(& SigInValue,&ICIBtnIDBInStatus);      												
    GET_CAN_RX_ICIBtnIDCIN(& SigInValue,&ICIBtnIDCInStatus);      												
    GET_CAN_RX_ICIBtnIDDIN(& SigInValue,&ICIBtnIDDInStatus);
	GET_CAN_RX_HUDBRIGHTIN(&SigInValue,&HUDBrightIn);
	GET_CAN_RX_HUDVERTIN(&SigInValue,&HUDVertIn);
	GET_CAN_RX_HUDETMIN(&SigInValue,&HUDETMIn);
	GET_CAN_RX_HUDSTATIN(&SigInValue,&HUDStatIn);	
	GET_CAN_RX_HUDVERTSZIN(&SigInValue,&HUDVertSzIn);
	GET_CAN_RX_HUDSWTCHIN(&SigInValue,&HUDSwtchIn);
	GET_CAN_RX_AUDIOCHIMESUPPTIN(& SigInValue,&AudioChimeSupptIn);      												
    GET_CAN_RX_AUDIOCHIME2NRIN(& SigInValue,&AudioChime2NRIn);      												
    GET_CAN_RX_AUDIOCHIMENRIN(& SigInValue,&AudioChimeNRIn);
	GET_CAN_RX_AUDIOCHIMEACTVIN(&SigInValue,&AudioChimeActvIn);
	GET_CAN_RX_AUDIOCHIME2ACTVIN(&SigInValue,&AudioChime2ActvIn);
	GET_CAN_RX_CHIMEADJVOLIN(&SigInValue,&ChimeAdjVolIn);
	GET_CAN_RX_CHIMENOIN(&SigInValue,&ChimeNoIn);	
	GET_CAN_RX_CHIME2ADJVOLIN(&SigInValue,&Chime2AdjVolIn);
	GET_CAN_RX_CHIME2NOIN(&SigInValue,&Chime2NoIn);
	GET_CAN_RX_E4X4STATUSIN(&SigInValue,&E4x4StatusIn);
	GET_CAN_RX_SEATOCCREARCHIMEIN(&SigInValue,&SeatOccRearChimeIn);
	GET_CAN_RX_EMERGENCYCALLFAULTIN(&SigInValue,&EmergencyCallFaultIn);
	GET_CAN_RX_SVCBATTTRACIN(&SigInValue,&SvcBattTracIn);
	GET_CAN_RX_DCCHRGRQIN(&SigInValue,&DcChrgRqIn);
	GET_CAN_RX_BATTTRACSOCIN(&SigInValue,&BattTracSoCInStatus);
	GET_CAN_RX_MILDHYBSTATIN(&SigInValue,&MildHybStatInStatus);
	GET_CAN_RX_RNGPERCHRGAVGIN(&SigInValue,&RngPerChrgAvgInStatus);
	GET_CAN_RX_PLUGACTIVEIN(&SigInValue,&PlugActiveInStatus);
	GET_CAN_RX_HYBRIDMODESTATIN(&SigInValue,&HybridModeStatInStatus);
	GET_CAN_RX_BATTPWWHLIN(&SigInValue,&BattPwWhlInStatus);
	GET_CAN_RX_PWWHLLVLIN(&SigInValue,&PwWhlLvlInStatus);
	GET_CAN_RX_ENGINEACTIVEIN(&SigInValue,&EngineActiveInStatus);
	GET_CAN_RX_CHARGEPORTDOOROPENIN(&SigInValue,&ChargePortDoorOpenInStatus);
	GET_CAN_RX_VEHELRANGEIN(&SigInValue,&VehElRangeInStatus);
	GET_CAN_RX_ASLDCHIMEIN(&SigInValue,&ASLDChimeInStatus);
	GET_CAN_RX_FUELUSEDIN(&SigInValue,&FuelUsedInStatus);
	GET_CAN_RX_ISAMODEIN(&SigInValue,&ISAModeInStatus);
	GET_CAN_RX_UPSHIFTTTIN(&SigInValue,&UpshiftTTInStatus);
	GET_CAN_RX_SHIFTINDIN(&SigInValue,&ShiftIndInStatus);
	GET_CAN_RX_ECSSLAMPRQDSPLYIN(&SigInValue,&ECSSLampRqDsplyInStatus);
	GET_CAN_RX_ASLDMODEIN(&SigInValue,&ASLDModeInStatus);
	GET_CAN_RX_GRADEASSISTDISPLAYIN(&SigInValue,&GradeAssistDisplayInStatus);
	GET_CAN_RX_LEDLBFAULTIN(&SigInValue,&LEDLBFaultInStatus);
	GET_CAN_RX_FRONTFOGTT(&SigInValue,&FrontFogTTInStatus);
	GET_CAN_RX_AWDPCTFLIN(&SigInValue,&AWDPctFLInStatus);
	GET_CAN_RX_AWDPCTFRIN(&SigInValue,&AWDPctFRInStatus);
	GET_CAN_RX_AWDPCTRLIN(&SigInValue,&AWDPctRLInStatus);
	GET_CAN_RX_AWDPCTRRIN(&SigInValue,&AWDPctRRInStatus);
	GET_CAN_RX_KEYCODEDIGIT1INSTATUS(&SigInValue,&KeycodeDigit1InStatus);
	GET_CAN_RX_KEYCODEDIGIT2INSTATUS(&SigInValue,&KeycodeDigit2InStatus);
	GET_CAN_RX_KEYCODEDIGIT3INSTATUS(&SigInValue,&KeycodeDigit3InStatus);
	GET_CAN_RX_KEYCODEDIGIT4INSTATUS(&SigInValue,&KeycodeDigit4InStatus);
	GET_CAN_RX_KEYCODEDIGIT5INSTATUS(&SigInValue,&KeycodeDigit5InStatus);
	GET_CAN_RX_KEYCODEDIGIT6INSTATUS(&SigInValue,&KeycodeDigit6InStatus);
	GET_CAN_RX_KEYCODEDIGIT7INSTATUS(&SigInValue,&KeycodeDigit7InStatus);
	GET_CAN_RX_PLCSTATUSIN(&SigInValue,&PLCStatusIn);
	GET_CAN_RX_WATERINFUELFALTINSTATUS(&SigInValue,&WaterInFuelFaltInStatus);
	GET_CAN_RX_EPBSTATUSINSTATUS(&SigInValue,&EPBStatusInStatus);
	GET_CAN_RX_LIFECYCLEMODEINSTATUS(&SigInValue,&LifeCycleModeInStatus);
	GET_CAN_RX_DFDOORAJARIN(&SigInValue,&DFDoorAjarInStatus);
	GET_CAN_RX_DRDOORAJARIN(&SigInValue,&DRDoorAjarInStatus);
	GET_CAN_RX_PFDOORAJARIN(&SigInValue,&PFDoorAjarInStatus);
	GET_CAN_RX_PRDOORAJARIN(&SigInValue,&PRDoorAjarInStatus);
	GET_CAN_RX_INNRTAILGATEAJARIN(&SigInValue,&InnrTailgateAjarInStatus);
	GET_CAN_RX_DIMLVLEVNTIN(&SigInValue,&DimLvlEvntInStatus);
	GET_CAN_RX_IGNKEYTYPEIN(&SigInValue,&IgnKeyTypeInStatus);
	GET_CAN_RX_TAILGATETRUNKAJARIN(&SigInValue,&TailgateTrunkAjarInStatus);
	GET_CAN_RX_HOODAJARIN(&SigInValue,&HoodAjarInStatus);
	GET_CAN_RX_DIMLVLIN(&SigInValue,&DimLvlInStatus);	
	GET_CAN_RX_UREALVLPCIN(&SigInValue,&UreaLvlPcInStatus);
	GET_CAN_RX_GEARPOSIN(&SigInValue,&GearPosInStatus);
	GET_CAN_RX_CHECKPLUGIN(&SigInValue,&CheckPlugInStatus);	
	GET_CAN_RX_SLIDERLEFTIN(&SigInValue,&SliderLeftInStatus);
	GET_CAN_RX_SLIDINGDOORLEFTCHIMEIN(&SigInValue,&SlidingDoorLeftChimeInStatus);
	GET_CAN_RX_SLIDINGDOORLEFTMESSAGETEXTIN(&SigInValue,&SlidingDoorLeftMessageTextInStatus);
	GET_CAN_RX_SLIDERRIGHTIN(&SigInValue,&SliderRightInStatus);
	GET_CAN_RX_SLIDINGDOORRIGHTCHIMEIN(&SigInValue,&SlidingDoorRightChimeInStatus);
	GET_CAN_RX_SLIDINGDOORRIGHTMESSAGETEXTIN(&SigInValue,&SlidingDoorRightMessageTextInStatus);
	GET_CAN_RX_PASSAIRBAGSTATINSTATUS(&SigInValue,&PassAirbagStatInStatus);	
	GET_CAN_RX_TWOROWSBDRIVERIN(&SigInValue,&TwoRowSBDriverInStatus);
	GET_CAN_RX_TWOROWSBMIDDLEIN(&SigInValue,&TwoRowSBMiddleInStatus);
	GET_CAN_RX_TWOROWSBPASSIN(&SigInValue,&TwoRowSBPassInStatus);
	GET_CAN_RX_THREEROWSBDRIVERIN(&SigInValue,&ThreeRowSBDriverInStatus);
	GET_CAN_RX_THREEROWSBMIDDLEIN(&SigInValue,&ThreeRowSBMiddleInStatus);
	GET_CAN_RX_THREEROWSBPASSIN(&SigInValue,&ThreeRowSBPassInStatus);
	GET_CAN_RX_TWOROWDRIVERSEATDETECTIN(&SigInValue,&TwoRowDriverSeatDetectInStatus);
	GET_CAN_RX_TWOROWMIDDLESEATDETECTIN(&SigInValue,&TwoRowMiddleSeatDetectInStatus);
	GET_CAN_RX_TWOROWPASSSEATDETECTIN(&SigInValue,&TwoRowPassSeatDetectInStatus);
	GET_CAN_RX_THREEROWDRIVERSEATDETECTIN(&SigInValue,&ThreeRowDriverSeatDetectInStatus);
	GET_CAN_RX_THREEROWMIDDLESEATDETECTIN(&SigInValue,&ThreeRowMiddleSeatDetectInStatus);
	GET_CAN_RX_THREEROWPASSSEATDETECTIN(&SigInValue,&ThreeRowPassSeatDetectInStatus);
	GET_CAN_RX_BTTLEFTIN(&SigInValue, &BTTLeftInStatus);
	GET_CAN_RX_MIDDLESEATDETECT(&SigInValue,&MiddleSeatDetectInStatus);
	GET_CAN_RX_FEATCONFIGHUDIN(&SigInValue,&FeatConfigHUDIn);
	GET_CAN_RX_FEATNOHUDIN(&SigInValue,&FeatNoHUDIn);
	GET_CAN_RX_ADAPTHEADLAMPFAILIN(&SigInValue,&AdaptHeadlampFailInStatus);
	GET_CAN_RX_RUNNINGBOARDSTATIN(&SigInValue,&RunningBoardStatInStatus); 
	GET_CAN_RX_BRAKEPADOUTIN(&SigInValue,&BrakePadWearOutInStatus);
	GET_CAN_RX_AUTOHIGHBEAMSCCMIN(&SigInValue,&AutoHighBeamSCCMIn);	
	GET_CAN_RX_PWRPACKREADYIN(&SigInValue,&PwrPackReadyIn);

#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
	GET_CAN_RX_SVCGEARBOXTTIN(&SigInValue,&SvcGearboxTTInStatus);
	GET_CAN_RX_SVCENGINETTIN(&SigInValue,&SvcEngineTTInStatus);
	GET_CAN_RX_CRUISECTRLSETSPDIN(&SigInValue,&CruiseCtrlSetSpdInStatus);
	GET_CAN_RX_CRUISEOVERRIDEIN(&SigInValue,&CruiseOverrideInStatus);
	GET_CAN_RX_OVERTEMPLAMPIN(&SigInValue,&OverTempLampInStatus);
	GET_CAN_RX_HEATERCORETEMPIN(&HeaterCoreTempInValue,&HeaterCoreTempInStatus);
	GET_CAN_RX_ENGOILDAYIN(&SigInValue,&EngOilDayInStatus);
	GET_CAN_RX_DISTTONEXTIN(&SigInValue,&DistToNextInStatus);
	GET_CAN_RX_ENGOILSRVCIN(&SigInValue,&EngOilSrvcInStatus);
	GET_CAN_RX_ENGAIRFILTERIN(&SigInValue,&EngAirFilterInStatus);
	GET_CAN_RX_TURBOBOOSTIN(&SigInValue,&TurboBoostInStatus);
	GET_CAN_RX_REARDIFFTEMPIN(&SigInValue,&RearDiffTempInStatus);
	GET_CAN_RX_FUELINDIN(&SigInValue,&FuelIndInStatus);
	GET_CAN_RX_VEHDISPTCSETIN(&SigInValue,&VehDispTCSetInStatus);
	GET_CAN_RX_SOCTHRESHOLDIN(&SigInValue,&SocThresholdInStatus);
	GET_CAN_RX_FUELRANGEL2DSPLYENGIN(&SigInValue,&FuelRangeL2DsplyEngInStatus);
	GET_CAN_RX_BATTELECPERF2IN(&SigInValue,&BattElecPerf2InStatus);
	GET_CAN_RX_OPDACTVSTATIN(&SigInValue,&OPDActvStatInStatus);
	GET_CAN_RX_OPDFAULTSYSIN(&SigInValue,&OPDFaultSysInStatus);
	GET_CAN_RX_ENGMNFCHRGTEMPIN(&SigInValue,&EngMnfChrgTempInStatus);
	GET_CAN_RX_VEHELAVGTRIP1EFFIN(&SigInValue,&VehElAvgTrip1EffInStatus);
	GET_CAN_RX_VEHELAVGTRIP2EFFIN(&SigInValue,&VehElAvgTrip2EffInStatus);
	GET_CAN_RX_EW2STTIN(&SigInValue,&EW2STTInStatus);
	GET_CAN_RX_OILPRESSIN(&SigInValue,&OilPressInStatus);
	GET_CAN_RX_AFRIN(&SigInValue,&AFRInStatus);
	GET_CAN_TRAILERBRKFAULTSTAT2IN(&TrailerBrkFaultStat2InValue,&TrailerBrkFaultStat2InStatus);
	GET_CAN_TRAILERBRKFAULTCOUNTER2IN(&TrailerBrkFaultCounter2InValue,&TrailerBrkFaultCounter2InStatus);
	GET_CAN_TRAILERBRKFAULTCHECKSUM2IN(&TrailerBrkFaultCheckSum2InValue,&TrailerBrkFaultCheckSum2InStatus);
	GET_CAN_RX_ELATCHSTATUSIN(&SigInValue,&eLatchStatusInStatus);
	GET_CAN_RX_ELATCHEVENTIN(&SigInValue,&eLatchEventInStatus);
	GET_CAN_RX_ELATCHMSGIN(&SigInValue,&eLatchMsgInStatus);
	GET_CAN_RX_SVCBODYMODIN(&SigInValue,&SvcBodyModInStatus);
	GET_CAN_RX_KEYINIGNIN(&SigInValue,&KeyInIgnInStatus);
	GET_CAN_RX_NFCDEVICEIN(&SigInValue,&NFCDeviceInStatus);
	GET_CAN_RX_TIRETEMPLFDATAIN(&SigInValue,&TireTempLFDataInStatus);
	GET_CAN_RX_TIRETEMPRFDATAIN(&SigInValue,&TireTempRFDataInStatus);
	GET_CAN_RX_TIRETEMPOLRDATAIN(&SigInValue,&TireTempOLRDataInStatus);
	GET_CAN_RX_TIRETEMPORRDATAIN(&SigInValue,&TireTempORRDataInStatus);
	GET_CAN_RX_POLICEIDLEMDEIN(&SigInValue,&PoliceIdleMdeInStatus);
	GET_CAN_RX_POLICELGLOCKIN(&SigInValue,&PoliceLGLockInStatus);
	GET_CAN_RX_VEHWLCMFRWLIN(&SigInValue,&VehWlcmFrwlInStatus);
	GET_CAN_RX_VEHWLCMFRWLMODEIN(&SigInValue,&VehWlcmFrwlModeInStatus);
	GET_CAN_RX_PARKLOCKAVAILIN(&SigInValue,&ParkLockAvailInStatus);
	GET_CAN_RX_PARKLOCKTEXTIN(&SigInValue,&ParkLockTextInStatus);
	GET_CAN_RX_PARKLOCKUNLOCKIN(&SigInValue,&ParkLockUnlockInStatus);
	GET_CAN_RX_POWERSYSTEMSTATUSIN(& SigInValue,& PowerSystemStatusInStatus); 
	GET_CAN_RX_OATINSTATUS(&SigInValue,&OATInStatus);
    GET_CAN_RX_APACHIMEIN(&SigInValue,&APAChimeInStatus);
	GET_CAN_RX_REGENANIMATIONINSTATUS(&SigInValue,&RegenAnimationInStatus);
	GET_CAN_RX_BATTPWAVAILINSTATUS(&SigInValue,&BattPwAvailInStatus);
	GET_CAN_RX_DRVMODESELECTMSGIN(&SigInValue,&DrvModeSelectMsgInStatus);
	GET_CAN_RX_TRAILONEPDLMSGTXTRQINSTATUS(&SigInValue,&TrailOnePdlMsgTxtRqInStatus);
	GET_CAN_RX_DRVSLIPCTLMODEMSGINSTATUS(&SigInValue,&DrvSlipCtlModeMsgInStatus);
	GET_CAN_RX_AUTOHOLDININSTATUS(&SigInValue,&AutoHoldIndInStatus);
	GET_CAN_RX_AUTOHOLDWARNINSTATUS(&SigInValue,&AutoHoldWarnInStatus);
	GET_CAN_RX_TCDISPSTATINSTATUS(&SigInValue,&TCDispStatInStatus);
	GET_CAN_RX_CCDFAULTINSTATUS(&SigInValue,&CCDFaultInStatus);
	GET_CAN_RX_PWRDRLGCHIMEIN(&SigInValue,&PwrDrLGChimeIn);
	GET_CAN_RX_POWERLIFTGATESTATIN(&SigInValue,&PowerLiftgateStatIn);
	GET_CAN_RX_FRONTSTEERMSGINSTATUS(&SigInValue,&FrontSteerMsgInStatus);
	GET_CAN_RX_FEATCONFIGVDMINSTATUS(&SigInValue,&FeatConfigVDMInStatus);
	GET_CAN_RX_FEATNOVDMINSTATUS(&SigInValue,&FeatNoVDMInStatus);
	GET_CAN_RX_PERSINDEXVDMINSTATUS(&SigInValue,&PersIndexVDMInStatus);
	GET_CAN_RX_FOURROWSBDRIVERINSTATUS(&SigInValue,&FourRowSBDriverInStatus);
	GET_CAN_RX_FOURROWSBMIDNSTATUS(&SigInValue,&FourRowSBMidInStatus);
	GET_CAN_RX_FOURROWSBPASSINSTATUS(&SigInValue,&FourRowSBPassInStatus);
	GET_CAN_RX_TWOROWSBMIDDRIVERINSTATUS(&SigInValue,&TwoRowSBMidDriverInStatus);
	GET_CAN_RX_TWOROWSBMIDPASSINSTATUS(&SigInValue,&TwoRowSBMidPassInStatus);
	GET_CAN_RX_PERSINDEXHUDINSTATUS(&SigInValue,&PersIndexHUDInStatus);
	GET_CAN_RX_HUDROTATEIN(&SigInValue,&HUDRotateInStatus);
	GET_CAN_RX_RACMBTNIDAINSTATUS(&SigInValue,&RACMBtnIDAInStatus);
	GET_CAN_RX_RACMBTNIDBINSTATUS(&SigInValue,&RACMBtnIDBInStatus);
	GET_CAN_RX_RACMBTNIDCINSTATUS(&SigInValue,&RACMBtnIDCInStatus);
	GET_CAN_RX_RACMBTNIDDINSTATUS(&SigInValue,&RACMBtnIDDInStatus);
	GET_CAN_RX_RACMCODINGBTNIDAINSTATUS(&SigInValue,&RACMCodingBtnIDAInStatus);
	GET_CAN_RX_RACMCODINGBTNIDBINSTATUS(&SigInValue,&RACMCodingBtnIDBInStatus);
	GET_CAN_RX_RACMCODINGBTNIDCINSTATUS(&SigInValue,&RACMCodingBtnIDCInStatus);
	GET_CAN_RX_RACMCODINGBTNIDDINSTATUS(&SigInValue,&RACMCodingBtnIDDInStatus);
	GET_CAN_RX_RACMSETVOLUMEINSTATUS(&SigInValue,&RACMSetVolumeInStatus);
	GET_CAN_RX_REARAUDIOCTLLCKDSTINSTATUS(&SigInValue,&RearAudioCtlLckDStInStatus);
	GET_CAN_RX_REARMNUCTLLCKBSTINSTATUS(&SigInValue,&RearMnuCtlLckBStInStatus);
	GET_CAN_RX_SWVIEWINSTATUS(&SigInValue,&SwViewInStatus);
	GET_CAN_RX_SWSETINSTATUS(&SigInValue,&SwSetInStatus);
	GET_CAN_RX_SWMEDINSTATUS(&SigInValue,&SwMedInStatus);
	GET_CAN_RX_SWNAVINSTATUS(&SigInValue,&SwNavInStatus);
	GET_CAN_RX_LMCSWLTINSTATUS(&SigInValue,&LMCSwLtInStatus);
	GET_CAN_RX_LMCSWRTINSTATUS(&SigInValue,&LMCSwRtInStatus);
	GET_CAN_RX_SWPHONEINSTATUS(&SigInValue,&SwPhoneInStatus);
	GET_CAN_RX_SWHOMEINSTATUS(&SigInValue,&SwHomeInStatus);
	GET_CAN_RX_SWINFOINSTATUS(&SigInValue,&SwInfoInStatus);
	GET_CAN_RX_SWPRIMARYPOSINSTATUS(&SigInValue,&SwPrimaryPosInStatus);
	GET_CAN_RX_SWPRIMARYPRESSINSTATUS(&SigInValue,&SwPrimaryPressInStatus);
  	GET_CAN_RX_HIGHBEAMSCCMINSTATUS(&SigInValue,&HighBeamSCCMInStatus);
	GET_CAN_RX_BALERTLEFTCHIMEINSTATUS(&SigInValue,&BAlertLeftChimeInStatus);
	GET_CAN_RX_BALERTLEFTLOCKINSTATUS(&SigInValue,&BAlertLeftLockInStatus);
	GET_CAN_RX_BALERTLEFTSTATUSINSTATUS(&SigInValue,&BAlertLeftStatusInStatus);
	GET_CAN_RX_BALERTLEFTMDESELINSTATUS(&SigInValue,&BAlertLeftMdeSelInStatus);
	GET_CAN_RX_BALERTLEFTMODEINSTATUS(&SigInValue,&BAlertLeftModeInStatus);
	GET_CAN_RX_BALERTLEFTSENSORINSTATUS(&SigInValue,&BAlertLeftSensorInStatus);
	GET_CAN_RX_BALERTLEFTWINDOWINSTATUS(&SigInValue,&BAlertLeftWindowInStatus);
	GET_CAN_RX_BTTRIGHTINSTATUS(&SigInValue,&BTTRightInStatus);
	GET_CAN_RX_BALERTRIGHTCHIMEINSTATUS(&SigInValue,&BAlertRightChimeInStatus);
	GET_CAN_RX_BALERTRIGHTLOCKINSTATUS(&SigInValue,&BAlertRightLockInStatus);
	GET_CAN_RX_BALERTRIGHTSTATUSINSTATUS(&SigInValue,&BAlertRightStatusInStatus);
	GET_CAN_RX_BALERTRIGHTMDESELINSTATUS(&SigInValue,&BAlertRightMdeSelInStatus);
	GET_CAN_RX_BALERTRIGHTMODEINSTATUS(&SigInValue,&BAlertRightModeInStatus);
	GET_CAN_RX_BALERTRIGHTSENSORINSTATUS(&SigInValue,&BAlertRightSensorInStatus);
	GET_CAN_RX_BALERTRIGHTWINDOWINSTATUS(&SigInValue,&BAlertRightWindowInStatus);
	GET_CAN_RX_BTNIDAINSTATUS(&SigInValue,&BtnIDAInStatus);
	GET_CAN_RX_BTNIDBINSTATUS(&SigInValue,&BtnIDBInStatus);
	GET_CAN_RX_BTNIDCINSTATUS(&SigInValue,&BtnIDCInStatus);
	GET_CAN_RX_BTNIDDINSTATUS(&SigInValue,&BtnIDDInStatus);
	GET_CAN_RX_CODINGBTNIDAINSTATUS(&SigInValue,&CodingBtnIDAInStatus);
	GET_CAN_RX_CODINGBTNIDBINSTATUS(&SigInValue,&CodingBtnIDBInStatus);
	GET_CAN_RX_CODINGBTNIDCINSTATUS(&SigInValue,&CodingBtnIDCInStatus);
	GET_CAN_RX_CODINGBTNIDDINSTATUS(&SigInValue,&CodingBtnIDDInStatus);
	GET_CAN_RX_SETVOLUMEINSTATUS(&SigInValue,&SetVolumeInStatus);
	GET_CAN_RX_SETPOINTVOLUMEINSTATUS(&SigInValue,&SetPointVolumeInStatus);
	GET_CAN_RX_BCPAUDIBLEBEEPRQINSTATUS(&SigInValue,&BCPAudibleBeepRqInStatus);
	GET_CAN_RX_VEHELEFFAVGINSTATUS(&SigInValue,&VehElEffAvgInStatus);
	GET_CAN_RX_PERCTODESTINSTATUS(&SigInValue,&PercToDestInStatus);
	GET_CAN_RX_SOCDISPLAYINSTATUS(&SigInValue,&SoCDisplayInStatus);
#endif

#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
GET_CAN_RX_MANRGENFILTERPFIN(&SigInValue,&ManRgenFilterPfsInStatus);
GET_CAN_RX_MANRGENTXTRQIN(&SigInValue,&ManRgenTxtRqInStatus);
GET_CAN_RX_DIESELPRTCFILTERIN(&SigInValue,&DieselPrtcFilterInStatus);
GET_CAN_RX_VSPDIN(&SigInValue,&VSpdInStatus);
GET_CAN_RX_FUELRANGELDSPLYENGIN(&SigInValue,&FuelRangeLDsplyEngInStatus); 
GET_CAN_RX_PWRTRAINDRIVEMODEIN(&SigInValue,&PwrtrainDriveModeInStatus);
GET_CAN_RX_STRTSTPVTHRSIN(&SigInValue,&StrtStpVThrsInStatus);
GET_CAN_RX_IMMOBILIZERWARNIN(&SigInValue,&ImmobilizerWarnInStatus);
GET_CAN_RX_PARKLAMPSTATIN(&SigInValue,&ParklampStatInStatus);
GET_CAN_RX_LITVALIN(&SigInValue,&LitvalInStatus);
GET_CAN_RX_BRAKETTIN(&SigInValue,&BrakeTTInStatus);
GET_CAN_RX_HIGHBEAMTTIN(& SigInValue,& HighBeamTTInStatus);
GET_CAN_RX_KEYINIGNCHIMEIN(&SigInValue,&KeyInIgnChimeInStatus);
GET_CAN_RX_TRANSTEMPIN(&TransTempInValue,&TransTempInStatus);
GET_CAN_RX_ENGOILTEMPIN(&SigInValue,&EngOilTempInStatus);
GET_CAN_RX_IGNPASSDISPLAYIN(&SigInValue,&IgnPassDisplayInStatus);
#endif

#ifdef COMABSCTRL_APPLICABLE_ONLY_FOR_V710
GET_CAN_RX_POWERLIFTGATESTATIN(&SigInValue,&PowerLiftgatestatInStatus);
GET_CAN_RX_PARKLOCKAVAILIN(&SigInValue,&ParkLockAvailInStatus);
GET_CAN_RX_PARKLOCKTEXTIN(&SigInValue,&ParkLockTextInStatus);
GET_CAN_RX_NFCDEVICEIN(&SigInValue,&NFCDeviceInStatus);
GET_CAN_RX_POWERSYSTEMIN(&SigInValue,&PowerSystemInStatus);
#endif

	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x18A
	*						ACC Feature Misconfigured DTC
	*						0xC40556
	*******************************************************************************/
	/*if((eConfigStatus_Enabled == cf_opt_acc_status)    							&& 
	    (((CADSRadarBlockInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  	|| 
		((ACCStopModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  	  	|| 
		((CADSAlignIncmpltInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		  		|| 
		((ACCFollowModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  		|| 
		((ACCMsgTxtInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				  		|| 
		((ACCModeSelInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  	    || 
		((ACCTGapInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			    	    || 
		((ACCTGapStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		   	        || 
		((ACCStopResumeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		 	  		|| 
		((iACCLampInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				  		|| 
		((DistIndInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))			      		
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40556, eSetDTC);			     
		}
	}
	else
	{														 	 
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40556, eClearDTC); 
	}*/

	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x4C, 0x382, 0x3B2
	*						Lost Communication With Restraints Control Module
	*               	    Lost Comm w/ RCM DTC
	*						0xC15100
	*******************************************************************************/
	if(
		#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
		(RILTTInStatus == eSIGNAL_MISSING)			     		 //0x4C
		||
		#endif
		(((cf_opt_R1C1SeatBelt != eConfigSeatbelt_SeatNotPresent)				||
		(cf_opt_R1C1BeltMinderChime == eConfigStatus_Enabled))					&& 		
		((OneRowSBDriverInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))				//0x4C
		||
		(((cf_opt_R1C3SeatBelt !=  eConfigSeatbelt_SeatNotPresent) 				||
		(cf_opt_R1C3BeltMinderChime == eConfigStatus_Enabled ))					&& 
		((OneRowSBMiddleInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))		 		//0x4C
		||
		(((cf_opt_R1C5SeatBelt !=  eConfigSeatbelt_SeatNotPresent) 				||
		(cf_opt_R1C5BeltMinderChime == eConfigStatus_Enabled ))					&& 
		((OneRowSBPassInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))					//0x4C
		|| 
		((eConfigStatus_Enabled ==  cf_opt_PassengerAirbagSetting)				&& 
		((PassAirbagStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))				//0x4C
		||
		((cf_opt_R2C1SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((TwoRowSBDriverInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))			 	//0x4C
		||
		((cf_opt_R2C3SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((TwoRowSBMiddleInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))			 	//0x4C
		||
		((cf_opt_R2C5SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((TwoRowSBPassInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))			 		//0x4C
		||
		((cf_opt_R3C1SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((ThreeRowSBDriverInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))			 	//0x4C
		||
		((cf_opt_R3C3SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((ThreeRowSBMiddleInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))			 	//0x4C
		||
		((cf_opt_R3C5SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((ThreeRowSBPassInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))			 	//0x4C
		||
		((cf_opt_R1C5SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((PassSeatDetectInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))			 	//0x4C
		||
		((cf_opt_R1C3SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((MiddleSeatDetectInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))			 	//0x4C
		||
		((cf_opt_R2C1SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((TwoRowDriverSeatDetectInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))		//0x382
		||
		((cf_opt_R2C3SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((TwoRowMiddleSeatDetectInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))		//0x382
		||
		((cf_opt_R2C5SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((TwoRowPassSeatDetectInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))			 //0x382
		#if defined(COMABSCTRL_APPLICABLE_ONLY_FOR_V710) || defined(DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY)
		||
		((cf_opt_R3C1SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((ThreeRowDriverSeatDetectInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))		//0x382
		||
		((cf_opt_R3C3SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((ThreeRowMiddleSeatDetectInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))		//0x382
		||
		((cf_opt_R3C5SeatBelt != eConfigSeatbelt_SeatNotPresent) 				&&
		((ThreeRowPassSeatDetectInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))		//0x382
		#endif
		#ifdef COMABSCTRL_APPLICABLE_ONLY_FOR_V710
		||
		(((eConfigStatus_Enabled == cf_opt_doorajarwarning)							||
		(eConfigTransType_TransAutomatic == cf_opt_trans_type_status)				||
		(eConfigStatus_Enabled == cf_opt_welcome))									&&
		((DFDoorAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))				|| //0x3B2
		
		((eConfigStatus_Enabled == cf_opt_doorajarwarning)							&&
		((DRDoorAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))				|| //0x3B2
		
		(((eConfigStatus_Enabled == cf_opt_doorajarwarning)							&&
		((eConfigPowerSlidingDoor_RightPSD == cf_opt_powerslidingdoor)				||
		(eConfigPowerSlidingDoor_LeftAndRightPSD == cf_opt_powerslidingdoor)		||
		(eConfigStatus_Enabled == cf_opt_welcome)))									&&
		((PFDoorAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))				|| //0x3B2
		
		(((eConfigStatus_Enabled == cf_opt_doorajarwarning)							&&
		((eConfigPowerSlidingDoor_LeftPSD == cf_opt_powerslidingdoor)				||
		(eConfigPowerSlidingDoor_LeftAndRightPSD == cf_opt_powerslidingdoor)))		&&
		((PRDoorAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))				|| //0x3B2
		
		((InnrTailgateAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			 //0x3B2
		#endif	
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((cf_opt_R4C1SeatBelt !=  eConfigSeatbelt_SeatNotPresent) 					&&		
		((FourRowSBDriverInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))		 		 //0x382
		||
		((cf_opt_R4C3SeatBelt !=  eConfigSeatbelt_SeatNotPresent) 					&&		
		((FourRowSBMidInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))		 			 //0x382
		||
		((cf_opt_R4C5SeatBelt !=  eConfigSeatbelt_SeatNotPresent) 					&&		
		((FourRowSBPassInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))		 		 //0x382	
		||
		((TwoRowSBMidDriverInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				 //0x382	Impediment:1650813
		||
		((TwoRowSBMidPassInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				 //0x382   	Impediment:1650813
		#endif
    )
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC15100, eSetDTC);			      // Log ERC_LOST_COMM_RCM_DTC
		}
	}
	else
	{														 	 
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC15100, eClearDTC); // Clear ERC_LOST_COMM_RCM_DTC
	}
	
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x213,0x416, 0x420
	*                 	   Lost Comm w/ ABS
	*                  	   0xC12100
	*					   Lost Communication With Anti-Lock Brake System (ABS) Control Module "A"
	*******************************************************************************/
	if(
		((eConfigStatus_Enabled == cf_opt_epb_status)                                	&& 
		(((ParkBrkStatusInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)							//0x213			
		#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
		||
		((EPBStatusInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)								//0x213
		#endif
		))
		||
		((eConfigStatus_Enabled ==  cf_opt_abs_status) 						        	&& 
		(((ABSTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 						|| 		//0x416
		((ABSBrakeTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))) 							//0x416
		#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
		||
		(((eConfigTCI_IVD_RSC_TC == cf_opt_tc_ivd_rsc_status)					   		||
		(eConfigTCI_IVD_RSC_IVD == cf_opt_tc_ivd_rsc_status)                      		||
		(eConfigTCI_IVD_RSC_RSC == cf_opt_tc_ivd_rsc_status))                     		&&
		((SCTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 						 		//0x416
		#endif
		||
		((eConfigStatus_Enabled == cf_opt_RSC_warning_chime_status)       				&& 
		((SvcAdvTracChimeRqInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 			 		//0x416
		||
		(((eConfigStatus_Enabled == cf_opt_advance_trac_status) 						|| 
		(eConfigStatus_Enabled == cf_opt_advanceTracConfiguration))						&&
		((SCOffTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 						 		//0x416
		||
		((eConfigStatus_Enabled ==  cf_opt_trailer_sway_status) 						&& 
		((TrailerSwayConfigInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 			 		//0x416
		||
		((eConfigStatus_Enabled ==  cf_opt_selectable_drive_mode_status) 				&& 
		(((DriveModeSelInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 				|| 		//0x420
		((ActiveDriveModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 				|| 		//0x420
		((DrvModeSelectStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((DrvModeSelectMsgInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)						//0x420
		#endif
		))
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY		
		|| 
		((cf_opt_trailcontrol == eConfigStatus_Enabled)					 				&& 
		(((TrailOnePdlMsgTxtRqInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||		//0x413
		((TCDispStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))) 							//0x41E
		||
		(((cf_opt_AdvanceTracHardButton ==eConfigStatus_Enabled) 						&&
		(cf_opt_advance_trac_status == eConfigStatus_Disabled))							&&
		((DrvSlipCtlModeMsgInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))						//0x41E
		||
		((eConfigStatus_Enabled == cf_opt_autohold_status) 								&&		//0x41E
		(((AutoHoldIndInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 					|| 		//0x41E
		((AutoHoldWarnInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))
		#endif
		||
		((cf_opt_CeramicBrakePadWearIndicator == eConfigStatus_Enabled)					&&
		((BrakePadWearOutInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))						//0x46A
	)	
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC12100, eSetDTC);		
								// Log ERC_LOST_COMM_ANTI_BRAKE_SYS_MOD DTC
		}
	}
	else
	{														 
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC12100, eClearDTC);  
							// Clear ERC_LOST_COMM_ANTI_BRAKE_SYS_MOD DTC
	}
		
	/******************************************************************************
    * DTC Condition    --> 1) Missing message on 0x3AB, 0x3A8
	*						Lost Communication With Parking Assist Control Module "A" No Sub Type Information
    *               	    Lost Comm w/ PAM DTC
	*						0xC15900
    *******************************************************************************/
	if(
		#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
		((eConfigStatus_Enabled == cf_opt_rear_park_aid_status) 					 && 
		(((RPAStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))        	  	 
		||
		#endif
		((cf_opt_autopark_status != eConfigAutoPark_Disabled) 						 && 
		(((APASysInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								//0x3A8
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((APAChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								//0x3A8
		#endif
		)))
	{
        if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC15900, eSetDTC);	// Log ERC_LOST_COMM_PAM_DTC
		}
	}
	else
	{														 	 // Clear ERC_LOST_COMM_PAM_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC15900, eClearDTC);
	}
		
	/********************************************************************************************************
     * DTC Condition    --> 1) Missing message on 0x82, 0x3E6
	 *						Lost Communication With Steering Column Control Module No Sub Type Information
     *                 		Lost Comm w/ SCCM DTC
	 *						0xC21200
     *********************************************************************************************************/
	if(
		((eConfigStatus_Disabled == cf_opt_active_front_steering_status)       && 
		(((SwMenuInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)	    		  ||
		((SwOKInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		    		  ||
		((SwUpInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			   		  ||
		((SwDnInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		    		  ||
		((SwBkInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		    		  ||
		((SwHUDInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)					
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((SwViewInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				  ||			//0x81
		((SwSetInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)					  ||			//0x81			
		((SwMedInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)					  ||			//0x81
		((SwNavInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)					   				//0x81
		#endif
		)) 
	  	||
		(((eConfigStatus_Enabled == cf_opt_courtesy_wipe_after_wash_status)    	  ||	
		(eConfigStatus_Enabled == cf_opt_rain_sensing_wipers_status)			  ||
		(eConfigStatus_Disabled == cf_opt_settings_menu_status)                   ||
		(eConfigStatus_Enabled == cf_opt_rear_reverse_gear_wipe))                 && 
		(((FeatConfigSCCMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		  ||   			//0x3E6		
		((FeatNoSCCMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))            				//0x3E6
		||
		(((cf_opt_front_camera_status == eConfigStatus_Enabled)		  			  ||
		((cf_opt_autohighbeamtelltale == eConfigAutoHighbeam_SCCM) 			      &&
		(cf_opt_auto_high_beam_menu != eConfigAutoHBMenu_Disabled))) 	  		  && 
		(( AutoHighBeamSCCMIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING))							//0x46B
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((cf_opt_msgcentredisplayinterface == eConfigMsgCenter_SteeringHorizonControlledInterface) &&
		(((SwPrimaryPosInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		  	  ||			//0x81
		((SwPrimaryPressInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))						//0x81
		||
		((eConfigAutoHighbeam_SCCM == cf_opt_highbeamtelltalesource_status)		  &&
		((HighBeamSCCMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))							//0x83
		||
		(((eConfigStatus_Disabled == cf_opt_active_front_steering_status)      	  
		/*||(eConfigStatus_Disabled == cf_opt_can_swc_status)									to be implemented after 1650917 is resolved */
		)		  && 
		(((ICICodBtnIDAInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  ||			//0x2a1
		((ICICodBtnIDBInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  ||			//0x2a1
		((ICICodBtnIDCInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  ||			//0x2a1
		((ICICodBtnIDDInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  ||			//0x2a1
		((ICIBtnIDAInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  	  ||			//0x2a1
		((ICIBtnIDBInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			      ||			//0x2a1
		((ICIBtnIDCInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			      ||			//0x2a1
		((ICIBtnIDDInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))			    			//0x2a1
		||
		((eConfigStatus_Enabled == cf_opt_active_front_steering_status)			  &&
		(((LMCSwLtInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				  ||			//0x81
		((LMCSwRtInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				  ||			//0x81			
		((SwPhoneInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				  ||			//0x81
		((SwHomeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				  ||			//0x81
		((SwInfoInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))								//0x81
		#endif
	)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC21200, eSetDTC); // Log ERC_LOST_COMM_SCCM_DTC
		}
	}
	else
	{														 	 // Clear ERC_LOST_COMM_SCCM_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC21200, eClearDTC);
	}
		
	/******************************************************************************
	 * DTC Condition    --> 1) Missing message on 0x3A6
	 *						Lost Communication With Side Obstacle Detection Control Module "A"
	 *                 		Lost Comm w/ SODL DTC
	 *						0xC23200
     *******************************************************************************/
	  if(
		(((eConfigStatus_Enabled == cf_opt_bsm_status)						     	  ||	
		(eConfigStatus_Enabled == cf_opt_cta_status))  				                  && 
		(((LBSMOpInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		    	      ||
		((LBSMSnsrInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 		   		  	  ||
		((LCrossTrafficAlertInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		  ||
		((LCrossTrafficOpInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		  	  ||
		((LCrossTrafficSnsrInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 		  ||
		((LCrossTrafficAlertBrakeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((BTTLeftInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								//0x3A6 - PDC
		#endif
		))
		#ifdef COMABSCTRL_APPLICABLE_ONLY_FOR_V710		   
		||
		((eConfigStatus_Enabled == cf_opt_bttlite)     &&
		((BTTLeftInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))
		#endif
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((cf_opt_boundary_alert == eConfigStatus_Enabled) 							  && 
		(((BAlertLeftChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			  ||		//0x3A1
		((BAlertLeftLockInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			  ||		//0x3A1
		((BAlertLeftStatusInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			  ||		//0x3A1
		((BAlertLeftMdeSelInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			  ||		//0x3A1
		((BAlertLeftModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			  ||		//0x3A1
		((BAlertLeftSensorInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			  ||		//0x3A1
		((BAlertLeftWindowInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))				    //0x3A1
		#endif
	)                  
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC23200, eSetDTC);			      	// Log ERC_LOST_COMM_SODL_DTC
		}
	}
	else
	{														 	 								// Clear ERC_LOST_COMM_SODL_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC23200, eClearDTC);

	}
		
	/******************************************************************************
     * DTC Condition    --> 1) Missing message on 0x3A7
	 *						Lost Communication With Side Obstacle Detection Control Module "B" No Sub Type Information
     *                 		Lost Comm w/ SODR DTC
	 *						0xC23300
     *******************************************************************************/
	 if(
		(((eConfigStatus_Enabled == cf_opt_bsm_status)						     	  ||	
		(eConfigStatus_Enabled == cf_opt_cta_status))  				                  && 
		(((RBSMOpInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		    	      ||
		((RBSMSnsrInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 		   		  	  ||
		((RCrossTrafficAlertInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		  ||
		((RCrossTrafficOpInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		  	  ||
		((RCrossTrafficSnsrInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 		  
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((RCrossTrafficAlertBrakeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)	 ||
		((BTTRightInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								//0x3A7 - PDC
		#endif
		))
		#ifdef COMABSCTRL_APPLICABLE_ONLY_FOR_V710
	    ||
	    ((eConfigStatus_Enabled==cf_opt_bttlite )                                		&&
	    ((BTTRightRqstInStatus & eSIGNAL_MISSING)==eSIGNAL_MISSING))
	    #endif
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((cf_opt_boundary_alert == eConfigStatus_Enabled) 							    && 
		(((BAlertRightChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||		//0x3A2
		((BAlertRightLockInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			    ||		//0x3A2
		((BAlertRightStatusInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||		//0x3A2
		((BAlertRightMdeSelInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||		//0x3A2
		((BAlertRightModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			    ||		//0x3A2
		((BAlertRightSensorInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||		//0x3A2
		((BAlertRightWindowInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))				    //0x3A2
		#endif
	)                  
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC23300, eSetDTC);			      	// Log ERC_LOST_COMM_SODL_DTC
		}
	}
	else
	{														 	 							 	// Clear ERC_LOST_COMM_SODL_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC23300, eClearDTC);

	}
		
	/******************************************************************************
    * DTC Condition    --> 1) Missing message on 0x365, 0x366, 0x474, 0x368, 0x471
    *               	    Lost Communication with Hybrid/EV Powertrain Control Module "A"
	*						Lost Comm w/ HPCM DTC
	*						0xC29300
    *******************************************************************************/
	if(
		(((cf_opt_shiftoutofneutral == eConfigStatus_Enabled)					||
		(cf_opt_mhevconfiguration == eConfigStatus_Enabled))					&&
		((EffWhlLvl2InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))				 //0x365
		||
		((cf_opt_shiftoutofneutral == eConfigStatus_Enabled)					&&
		(((EffWhlThresInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)   		|| //0x365
		((EngModeMsgTxtInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			|| //0x366
		((EffRgnThresInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)   		|| //0x366
		((BattPwWhlInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				|| //0x366
		((PwWhlLvlInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				|| //0x369
		((EngineActiveInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))) 		   //0x365
		||
		((cf_opt_hybrid_engine_config_status == eConfigStatus_Enabled)          &&
		(((RegenLevelInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||  //0x474
		((BrakeEventInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))			    //0x474
		#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
	 	||
		(((cf_opt_pt_hybrid_2 == eConfigPTHybrid2_BEV)							||
		(cf_opt_pt_hybrid_2 == eConfigPTHybrid2_PHEV)) 							&&
	    ((PwrPackReadyIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING))               	//0X108
		||
		((cf_opt_mhevconfiguration == eConfigStatus_Enabled)					&&
		((MildHybStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))				//0x368
		||
		(((cf_opt_pt_hybrid_2_status == eConfigPTHybrid2_PHEV) 					||
		(cf_opt_evdisplayconfiglincoln == eConfigStatus_Enabled)				||
		(cf_opt_evdisplayconfigford == eConfigStatus_Enabled)) 					&&
		((HybridModeStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))  			//0x368
		||
		((cf_opt_pt_hybrid_2_status == eConfigPTHybrid2_PHEV) 					&&
		((VehElRangeInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))                //0x442
		#endif
		||
		(((cf_opt_pt_hybrid_2_status == eConfigPTHybrid2_BEV)					||
		(cf_opt_pt_hybrid_2_status == eConfigPTHybrid2_PHEV))					&&
		(((RngPerChrgAvgInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)				//0x471
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||		
		((VehElEffAvgInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)				//0x484
		#endif
		))
		||
		((cf_opt_bevphevconfig == eConfigStatus_Enabled) 			     		&&
		(((BattTracSoCInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)	 		||  //0x3B3	;0X252 for PDC
		((PlugActiveInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)	 			||  //0x3B3	;0X366 for PDC
		((CheckPlugInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)))	 		  	//0x3B3	;0X368 for PDC
		||
		((cf_opt_ChargePortDoorAjarWarningConfiguration == eConfigStatus_Enabled) &&
		((ChargePortDoorOpenInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))        //0x422
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((cf_opt_bevconfig == eConfigStatus_Enabled) 			     		 	&&	
		(((PercToDestInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||	//0x311
		((SoCDisplayInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				//0x311
		/*
		||
		((VehElRngeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				
		*/
		))
		#endif
	)
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xc29300, eSetDTC);				// Log ERC_LOST_COMM_HPCM_DTC
		}
	}
	else
	{														 	 // Clear ERC_LOST_COMM_HPCM_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xc29300, eClearDTC);

	}
		
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x14C, 0x156, 0x163,
	*						166, 167, 171, 175, 178, 179, 17C, 17D, 20A, 20B
	*						202, 204, 262, 263, 331, 421, 422, 424, 42C, 42D, 42F 
	*               	    Lost Comm w/ ECM_PCM DTC
	*						0xC10000
	*******************************************************************************/
	if(
	
	((EngTempInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    		     						|| //0x156
	  
	((FSCInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    										|| //0x156
	  
	((EngTempQFInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    									|| //0x156	

	((eConfigStatus_Enabled == cf_opt_odometer_delta_status) 										&& 
	((OdoTripVerifyInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))       							|| //0x166

	((StopStartTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    								|| //0x166

	((PwrPackStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    								|| //0x167
	
	((eConfigStatus_Enabled == cf_opt_pwr_d_gauge_feature_status) 									&& 
	((PwrTrainTorqueInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))           					|| //0x167

	((eConfigTransType_TransAutomatic == cf_opt_trans_type_status) 									&& 
	((ePRNDLInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))       								|| //0x171

	/*((eConfigStatus_Enabled == cf_opt_diesel_engine_config_status) 										&& 
	((DieselEngTeColdInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))       						|| */
	
	((eConfigStatus_Enabled == cf_opt_asld_status)													&&
	(((ASLDChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)       								|| //0x178
	((ASLDModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))       								|| //0x178
	
	((FuelInletStatusInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    							|| //0x179

	((eConfigStatus_Enabled == cf_opt_oil_minder_10k_status) 										&& 
	((EngOilLifeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))       							|| //0x179
		
	((eConfigStatus_Enabled == cf_opt_upshift_indicator) 											&& 
	((UpshiftTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))         							|| //0x179

	((eConfigStatus_Enabled == cf_opt_perf_shift_indicator) 										&& 
	((ShiftIndInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))         							|| //0x179

	((eConfigEngineFuelType_Diesel == cf_opt_engine_fuel_type) 										&& 
	((WaterInFuelTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))    							|| //0x17D

	(((eConfigTransType_TransAutomatic == cf_opt_trans_type_status) 								||
	(eConfigStatus_Enabled == cf_opt_engine_idle_hours_function_status))                            &&
	((VSpdQFInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))    									|| //0x202

	(((eConfigTachSignal_EngAoutNActl == cf_opt_tach_signal_status) 								||         
	(eConfigStatus_Enabled == cf_opt_engine_idle_hours_function_status)                             ||
	(eConfigStatus_Enabled == cf_opt_engine_hours_function_status))                                 &&
	((EngSpdUnfiltInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))       							|| //0x204
	
	((eConfigStatus_Enabled == cf_opt_awd_gaguge_feature) 											&& 
	(((AWDPctFLInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)         							|| //0x262
	((AWDPctFRInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			   							|| //0x262
	((AWDPctRLInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)         								|| //0x262
	((AWDPctRRInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))									|| //0x262
	
	(((eConfigStatus_Enabled == cf_opt_reverse_warning_status)                                      ||
	(eConfigStatus_Enabled == cf_opt_pdcfaultconfig))                                               &&
	((GearPosInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))          							|| //0x38A, 0x230 PDC

	((OilPressWarnInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    	        					|| //0x421
	
	((MILTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    										|| //0x421		

	((CruiseControlStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)	   							|| //0x42C , 0x165 PDC

	((eConfigTachSignal_EngAoutNDsply == cf_opt_tach_signal_status) 								&& 
	((EngSpdFiltInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))     								|| //0x42F

	(((eConfigStatus_Enabled == cf_opt_asld_status)													||
	(eConfigStatus_Enabled == cf_opt_intelligentspeedassist_status))								&& 
	(((ISASetupInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)										|| //0x42D
	((ISAModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))										|| //0x42D
	
	(((eConfigXWD_4x4 == cf_opt_2wd_4x4_awd_status)					    	  						||	
	(eConfigXWD_AWD == cf_opt_2wd_4x4_awd_status)				               	 					|| 
	(eConfig4x4AWDSource_PCM_ECM == cf_opt_awdsourcemodule))	              	  		            && 
	((Status4x4InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))	   		  						|| //0x263

	((eConfigFuelLvlPCM_FuelLvlIPC == cf_opt_fuellvl_pcm_status)									&&
	(((OdoInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)       									|| //0x179
    ((FuelUsedInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))       								|| //0x179

	((eConfigStatus_Enabled == cf_opt_diesel_engine_config_status) 								    &&
	((W2STTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))										   //0x17D

#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
||

	((SvcGearboxTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)          						|| //0x230
	((SvcEngineTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)          						    || //0x179
	((CruiseCtrlSetSpdInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)          					|| //0x77
	((CruiseOverrideInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)          						|| //0x77
	
	(((eConfigPTHybrid2_PHEV == cf_opt_pt_hybrid_2)													|| //0x3
	(eConfigPTHybrid2_BEV == cf_opt_pt_hybrid_2)													|| //0x1
	(eConfigPTHybrid2_FHEV == cf_opt_pt_hybrid_2)) 													&& //0x2
	((OverTempLampInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))    	  							|| //0x185
	
	((eConfigPTHybrid2_PHEV == cf_opt_pt_hybrid_2)													&& //0x3
	((HeaterCoreTempInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))    	  						|| //0x178
	
	((eConfigPTHybrid2_PHEV == cf_opt_oil_minder_distance_time_status)								&& 
	((EngOilDayInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    	  	    					    || //0x17D
	((DistToNextInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    	  	    					|| //0x17D
	((EngOilSrvcInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))    	  	    					|| //0x17D
	
	((cf_opt_engineairfilterminder_status == eConfigStatus_Enabled) 								&& 
	((EngAirFilterInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 								|| //0x27A , 0x20b for PDC
	
	((cf_opt_turbo_boost_status == eConfigStatus_Enabled) 								            && 
	((TurboBoostInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))			    					|| //0x43E
	
	((cf_opt_axleoiltempdisplay == eConfigStatus_Enabled) 		                                    && 
	((RearDiffTempInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))	  							    || //0x424
	
	(((eConfigFuelLvlPCM_FuelLvlPCM == cf_opt_fuellvl_pcm_status) 									|| 
	(eConfigPTHybrid2_BEV != cf_opt_pt_hybrid_2))													&& //0x1
	((FuelIndInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))			        					|| //0x424
	
	((cf_opt_trailcontrol == eConfigStatus_Enabled) 												&& 
	((VehDispTCSetInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 								|| //0x44C
	
	((eConfig4x4AWDSource_PCM_ECM == cf_opt_awdsourcemodule)										&&
	((AWDStatusInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))									||   //0x263
	
	((eConfigFuelLvlPCM_FuelLvlIPC == cf_opt_fuellvl_pcm_status)								    &&
	((FuelRangeL2DsplyEngInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))                           ||   //0x263
	
	((cf_opt_bevconfig == eConfigStatus_Enabled) 							        				&& 
	((SocThresholdInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)									||  //0x311
	((BattElecPerf2InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)									||	//0x311
	((OPDActvStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)									||	//0x480
	((OPDFaultSysInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))									||	//0x480
	
	((cf_opt_manifoldchargetemp == eConfigStatus_Enabled) 					    					&& 
	((EngMnfChrgTempInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								|| //0x17E
	
	((eConfigPTHybrid2_BEV == cf_opt_pt_hybrid_2)													&& //0x1
	((VehElAvgTrip1EffInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								|| //0x380
	((VehElAvgTrip2EffInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								|| //0x381
	
	((eConfigStatus_Enabled == cf_opt_Brazil_Cold_Start_Reservoir)									&&
	((EW2STTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))			   							||	//0x178
	
	((eConfigStatus_Enabled == cf_opt_oilpressuresensor)									        &&
	((OilPressInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))			   			                || //0x43E

	((eConfigStatus_Enabled == cf_opt_airfuelratio)									                &&
	((AFRInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))	                                           //0x43E
	


#endif

#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
||
	/*((eConfigStatus_Enabled == cf_opt_def_gauge_configuration_status) 								&&
	((UreaLvlPcInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))									|| 	
	
	(((eConfigStatus_Enabled == cf_opt_manregen_status) 											&& 
	(eConfigStatus_Enabled == cf_opt_dieselparticulatefilterconfig))                                ||
	(((ManRgenFilterPfsInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								|| 
	((ManRgenTxtRqInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)									|| 
	((DieselPrtcFilterInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))							|| */

	((eConfigStatus_Enabled == cf_opt_Indiaover_speed_warning) 									    &&
	((VSpdInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))   										|| //0x202
	
	((eConfigFuelLvlPCM_FuelLvlIPC == cf_opt_fuellvl_pcm_status) 								    && 
	((FuelRangeLDsplyEngInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))					        || //0x424
			
	/*((eConfigStatus_Disabled == cf_opt_tcm_present) 									            && 
	((PwrtrainDriveModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))        					|| */
	
	((eConfigStatus_Enabled == cf_opt_mHEV_start_stop_speed_th) 								    && 
	((StrtStpVThrsInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))         						||  //0x422
	
	((eConfigStatus_Enabled == cf_opt_auto_regen_control_status) 									&& 
	((AutoRegenCtrlTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))       						|| //0x163		//not defined in msg list	
	
	(((cf_opt_transmissionfluidtempdisplay_status == eConfigStatus_Enabled) 				    	|| 
	(eConfigStatus_Enabled == cf_opt_TransmissionFluidTemperatureGaugeConfiguration))				&& 
	((TransTempInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))									|| //0x230
	
	/*(((eConfigFuelLvlPCM_FuelLvlPCM == cf_opt_fuellvl_pcm_status) 								    ||
	(eConfigStatus_Enabled == cf_opt_lfr_config))                                                   &&
	((LowFuelWarnInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))									|| 	*/
	
	/*((eConfigStatus_Enabled == cf_opt_oiltemp)									                    &&
	((EngOilTempInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))	                                ||	*/
	
	((eConfigStatus_Enabled == cf_opt_grade_assist_menu) 											&& 
	((GradeAssistDisplayInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))       					|| //0x17C			//not defined in msg list	

    (((eConfigStatus_Enabled == cf_opt_aeis_without_override) 									    ||
	(eConfigStatus_Enabled == cf_opt_aeis_with_override))											&& 
	((EngIdlShutDownInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))      							|| //0x421		//not defined in msg list		
	
	((eConfigStatus_Enabled == cf_opt_Brazil_Cold_Start_Reservoir)									&&
	((ECSSLampRqDsplyInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								    //0x178
#endif
	)
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC10000, eSetDTC);			      // Log ERC_LOST_COMM_ECMPCM_DTC
		}
	}
	   else
	{														 	 	                         
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC10000, eClearDTC);				 // Clear ERC_LOST_COMM_ECMPCM_DTC
	}
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x261,0x263, 0x4A2
	*                 		Lost Comm w/ TCCM DTC
	*						0xC10200
	*******************************************************************************/
	//AS PER FORD GENERIC
	if(/*(((((eConfigXWD_4x4 == cf_opt_2wd_4x4_awd_status)				    			||	
	(eConfigXWD_AWD == cf_opt_2wd_4x4_awd_status))									&&
	(eConfigHardWiredCan_CAN == cf_opt_4x4canhw))									|| 
	(eConfig4x4AWDSource_TCCM == cf_opt_awdsourcemodule))							&&
	((AWDStatusInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))					   
	||*/
	((((eConfigXWD_4x4 == cf_opt_2wd_4x4_awd_status)					    	  	||	
	(eConfigXWD_AWD == cf_opt_2wd_4x4_awd_status))									||
	(eConfig4x4AWDSource_TCCM == cf_opt_awdsourcemodule)	              	  		||
	((eConfigStatus_Enabled == cf_opt_neutral_tow_status) 					  		&&
	(eConfigTccmNt_TCCMNeutralTowCapable == cf_opt_tccm_nt_status)))			  	&&      
	((Status4x4InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))	   		  	  	   //0x263
	||
	(((eConfigStatus_Enabled == cf_opt_neutral_tow_status) 					  		&&
	(eConfigTccmNt_TCCMNeutralTowCapable == cf_opt_tccm_nt_status))			  		&&        
	(((Status4x4InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				  	|| //0x263
	((NeutralTowInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))			  		   //0x263
	/*||
	((eConfigStatus_Enabled == cf_opt_pwr_d_gauge_feature_status)					&&
	((AWDTorqueInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))					   
	||
	((eConfigStatus_Enabled == cf_opt_e_locker_status)								&&
	(((SvcElockerInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)							
	#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
	|| 
	((RearDiffLckMsgInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			    
	#endif
	))
	||
	((eConfigXWD_4x4 == cf_opt_2wd_4x4_awd_status)					 			  	&& 
	((Status4x4AutoTTIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)					  	|| 
	((Status4x4LoTTIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				  	  	|| 
	((Status4x4HiTTIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING))*/)				
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC10200, eSetDTC);			      // Log ERC_LOST_COMM_TCCM_DTC
		}
	}
	else
	{														 	 // Clear ERC_LOST_COMM_TCCM_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC10200, eClearDTC);
	}

	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x168
	*               	    Lost Comm w/ GSM DTC
	*						0xC10300
	*******************************************************************************/
	if((eConfigStatus_Enabled == cf_opt_shift_by_wire_status)    				&& 
	((SvcGSMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))  					//0x168
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC10300, eSetDTC);			      
															// Log ERC_LOST_COMM_GSM_DTC
		}
	}
	else
	{														// Clear ERC_LOST_COMM_GSM_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC10300, eClearDTC);
	}
		
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x82
	*                 		Lost Comm w/ SASM DTC
	*						0xC12600
	*******************************************************************************/
	if(((eConfigStatus_Enabled == cf_opt_active_front_steering_status) 
		#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
		&&
		(((SwMenuInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		    	  || //0x82
		((SwOKInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		    		  || //0x82
		((SwUpInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			   		  || //0x82
		((SwDnInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		    		  || //0x82
		((SwBkInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		    		  || //0x82
		((SwHUDInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))					  //0x82
		#endif
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		&&
		(((FrontSteerMsgInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		  || //0x8B
		((ICICodBtnIDAInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  || //0x2A1
		((ICICodBtnIDBInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  || //0x2A1
		((ICICodBtnIDCInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  || //0x2A1
		((ICICodBtnIDDInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  || //0x2A1
		((ICIBtnIDAInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  	  || //0x2A1
		((ICIBtnIDBInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  	  || //0x2A1
		((ICIBtnIDCInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				  || //0x2A1
		((ICIBtnIDDInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))			  	  //0x2A1
		#endif
		)	
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY		  	  
		|| 
		((eConfigStatus_Enabled == cf_opt_adaptiveSteeringMenu)					   &&
		(((FeatConfigVDMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		   || //0x3DF
		((FeatNoVDMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			  	   || //0x3DF
		((PersIndexVDMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))			  //0x3DF
		#endif
	)  		  		 
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC12600, eSetDTC);			      
													// Log ERC_LOST_COMM_SASM_DTC
		}
	}
	else
	{												// Clear ERC_LOST_COMM_SASM_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC12600, eClearDTC);
	}
		
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x443, 0x445
	*               	    Lost Comm w/ TBCM DTC
	*						Lost Communication With Trailer Brake Control Module
	*						0xC13700
	*******************************************************************************/
	if(((eConfigStatus_Enabled == cf_opt_trailer_lighting_status)				  	&&  
	(((TrailerLampsConnectedInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 	  	|| //0x443
	((TrailerLeftTurnLampInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 	  		|| 	
	((TrailerRightTurnLampInStatus  & eSIGNAL_MISSING)== eSIGNAL_MISSING) 	  		|| 	
	((TrailerLampsControlInStatus  & eSIGNAL_MISSING)== eSIGNAL_MISSING) 	      	|| 	
	((TrailerBatteryInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 	  			|| 	
	((TrailerStopLampInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 	      		|| 	
	((TrailerParkLampInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))         	|| 

	((eConfigStatus_Enabled == cf_opt_trailer_brake_status)						    &&  
	(((TrailerDisconnectedInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 	  		|| //0x445
	((TrailerWiringFaultInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 	      	|| 	
	((TrailerConnectedInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 	      		|| 	
	((TrailerModuleFaultInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))			

	#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
	||

	(((eConfigStatus_Enabled == cf_opt_trailer_brake_status)						&& 
	(eConfigStatus_Enabled == cf_opt_TrailerBrakee2eSignalProtection))				&&
	(((TrailerBrkFaultStat2InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 	  	|| //0x4DE
	((TrailerBrkFaultCounter2InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 	    || 	
	((TrailerBrkFaultCheckSum2InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))
	#endif
	)
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC13700, eSetDTC);			      // Log ERC_LOST_COMM_TBCM_DTC
		}
	}
	else
	{														 	 // Clear ERC_LOST_COMM_TBCM_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC13700, eClearDTC);
	}
		
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x331, 0x38D, 0x3B2,  
	*							0x3C3,0x3E3, 0x3E1, 0x3B1
	*                 			Lost Comm w/ BCM DTC
	*							Lost Communication With Body Control Module
	*							0xC14000
	*******************************************************************************/
	if(
		
	((LockMsgTxtInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    		    				|| //0x331
	((KeycodeStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    							|| //0x38D 

	((eConfigStatus_Enabled == cf_opt_mykey_feature_status)				    				    &&
	(((KeyAdminTotalInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)         					|| //0x38D 
	((KeyMyKeyTotalInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))         					|| //0x38D 
	
	(((eConfigStatus_Enabled == cf_opt_mykey_feature_status)				    				&&
	(eConfigStatus_Enabled == cf_opt_peps_status))                              				&&
	((PESlotStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))        						|| //0x38D 
	
	((eConfigStatus_Enabled == cf_opt_powerlockcontrolconfig)						            &&  
	((PLCStatusIn & eSIGNAL_MISSING) == eSIGNAL_MISSING))     	    							|| //0x3B1
		
	((eConfigTransType_TransAutomatic == cf_opt_trans_type_status)								&&  
	((LifeCycleModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))     	    				|| //0x3B2
	
	(((eConfigStatus_Enabled == cf_opt_doorajarwarning)											||
	(eConfigTransType_TransAutomatic == cf_opt_trans_type_status)								||
	(eConfigStatus_Enabled == cf_opt_welcome))													&&
	((DFDoorAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								|| //0x3B2
	
	((eConfigStatus_Enabled == cf_opt_doorajarwarning)											&&
	((DRDoorAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								|| //0x3B2
	
	(((eConfigStatus_Enabled == cf_opt_doorajarwarning)										    ||
	(eConfigStatus_Enabled == cf_opt_welcome))													&&
	((PFDoorAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								|| //0x3B2
	
	((eConfigStatus_Enabled == cf_opt_doorajarwarning)											&&
	((PRDoorAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								|| //0x3B2
	
	((eConfigStatus_Enabled == cf_opt_DimIIControlMirror)										&&
	((DimLvlEvntInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								|| //0x3B2
	
	((eConfigStatus_Enabled == cf_opt_mykey_feature_status)										&&
	((IgnKeyTypeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								|| //0x3B2
	
	((eConfigStatus_Enabled == cf_opt_trunk_ajar_config)                        				&&
	((TailgateTrunkAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))        				|| //0x3B2
	
	((eConfigStatus_Enabled == cf_opt_hoodajar)													&&
	((HoodAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))									|| //0x3B2
	
	(((eConfigStatus_Enabled == cf_opt_welcome)													||
	(eConfigStatus_Enabled == cf_opt_DimIIControlMirror))                       				&&
	((DimLvlInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))									|| //0x3B2
	
	((eConfigStatus_Enabled == cf_opt_frontfogtelltale)											&& 
	((FrontFogTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								|| //0x3B2

	((eConfigStatus_Enabled == cf_opt_perimeter_alarm_with_reduced_guard_control_function_status)&& 
	((ReduceGuardInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))      						|| //0x3C3
	
	((eConfigStatus_Enabled == cf_opt_LED_LowBeamFaultIndicator) 								&& 
	((LEDLBFaultInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								|| //0x3C3

	((HeadlampOnChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)   						|| //0x3C3

	((HomeSafeLghtChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    						|| //0x3C3 
	
	((ParkLghtChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    							|| //0x3C3

	((ParkBrakeChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    						|| //0x3C3

	((BrakeFluidStatusInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    						|| //0x3C3
	
	((eConfigStatus_Enabled == cf_opt_easy_entry_easy_exit_configuration_status) 				&& 
	(((FeatConfigDSMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    						|| //0x3E1
	((FeatNoDSMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))  								|| //0x3E1
	
	(((eConfigStatus_Enabled == cf_opt_approach_detection_control_function_status)				||
	(eConfigStatus_Enabled == cf_opt_powerlockcontrolconfig)                                    ||
	(eConfigStatus_Enabled == cf_opt_auto_relock_status)										||							
	(eConfigStatus_Enabled == cf_opt_trim_switch_config)                            			||
	(eConfigStatus_Enabled == cf_opt_mislock_chirp_menu)                            			||
	(eConfigStatus_Enabled == cf_opt_locking_feedback_audible_status)							||
	(eConfigStatus_Enabled == cf_opt_locking_feedback_visual_status)							||
	(eConfigStatus_Enabled == cf_opt_global_window_open_status)									||
    (eConfigStatus_Enabled == cf_opt_global_window_close_status)                    			||
	(eConfigStatus_Enabled == cf_opt_daytimerunninglamps_status)                    			||
	(eConfigStatus_Enabled == cf_opt_autolock_status)                               			||
	(eConfigStatus_Enabled == cf_opt_autounlock_status)                             			||
	(eConfigStatus_Enabled == cf_opt_intelligent_access_config)                     			||
	((eConfigStatus_Enabled == cf_opt_remote_start_status)										&&
	(eConfigSettingsMenu_Cluster == cf_opt_settings_menu_status))	                			||
	(eConfigStatus_Enabled == cf_opt_silent_mode_config)                            			||
	(eConfigStatus_Enabled == cf_opt_handsfree_lift_gate_config))                   			&&
	((FeatConfigBCMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))      						|| //0x3E3

	(((eConfigStatus_Enabled == cf_opt_approach_detection_control_function_status)				||
	(eConfigStatus_Enabled == cf_opt_powerlockcontrolconfig)                                    ||
	(eConfigStatus_Enabled == cf_opt_auto_relock_status)										||							
	(eConfigStatus_Enabled == cf_opt_trim_switch_config)                            			||
	(eConfigStatus_Enabled == cf_opt_mislock_chirp_menu)                            			||
	(eConfigStatus_Enabled == cf_opt_locking_feedback_audible_status)							||
	(eConfigStatus_Enabled == cf_opt_locking_feedback_visual_status)							||
	(eConfigStatus_Enabled == cf_opt_global_window_open_status)									||
    (eConfigStatus_Enabled == cf_opt_global_window_close_status)                    			||
	(eConfigStatus_Enabled == cf_opt_daytimerunninglamps_status)                    			||
	(eConfigStatus_Enabled == cf_opt_autolock_status)                               			||
	(eConfigStatus_Enabled == cf_opt_autounlock_status)                             			||
	(eConfigStatus_Enabled == cf_opt_intelligent_access_config)                     			||
	((eConfigStatus_Enabled == cf_opt_remote_start_status)										&&
	(eConfigSettingsMenu_Cluster == cf_opt_settings_menu_status))	                			||
	(eConfigStatus_Enabled == cf_opt_silent_mode_config)                            			||
	(eConfigStatus_Enabled == cf_opt_handsfree_lift_gate_config))                   			&&
	((FeatNoBCMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))      			    			|| //0x3E3
	
	(((eConfigStatus_Enabled == cf_opt_daytimerunninglamps_status)								||
	(eConfigStatus_Enabled == cf_opt_powerlockcontrolconfig)                                    ||
	(eConfigStatus_Enabled == cf_opt_autolock_status)											||
	(eConfigStatus_Enabled == cf_opt_autounlock_status)											||		
	(eConfigStatus_Enabled == cf_opt_autolamp_status)											||	
    (eConfigStatus_Enabled == cf_opt_intelligent_access_config)                     			||	
	(eConfigStatus_Enabled == cf_opt_trim_switch_config)                            			||
	(eConfigStatus_Enabled == cf_opt_mislock_chirp_menu)                            			||
	(eConfigStatus_Enabled == cf_opt_locking_feedback_audible_status)							||
	(eConfigStatus_Enabled == cf_opt_onetwostageunlock_status)									||
	(eConfigStatus_Enabled == cf_opt_locking_feedback_visual_status)							||
	((eConfigStatus_Enabled == cf_opt_remote_start_status)										&&
	(eConfigSettingsMenu_Cluster == cf_opt_settings_menu_status)))	                			&&
	((PersIndexBCMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))      						 //0x3E3

#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
||	
	((ImmobilizerWarnInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)   						|| //0x38D 
	
	((eConfigStatus_Enabled == cf_opt_trailer_lighting_status)				    				&&
	((ParklampStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))								|| //0x3B2
	
	((LitvalInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)									|| //0x3B2
	
	((BrakeTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)									|| //0x3C3
	
	((eConfigHighbeam2_BCM == cf_opt_highbeamtelltalesource_status) 							&&  
	((HighBeamTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))     	    					|| //0x3C3
	
	((eConfigStatus_Enabled == cf_opt_key_in_ignition_reminder_chime_status) 					&& 
	((KeyInIgnChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))     						|| //0x3C3
	
	((IgnPassDisplayInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)     						|| //0x140
	
	((eConfigStatus_Enabled == cf_opt_tail_gate_ajar_warning)                                   &&
	((InnrTailgateAjarInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))							|| //0x3B2
	
	(((KeycodeDigit1InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)							&& //0x3B1
	((KeycodeDigit2InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								&& //0x3B1
	((KeycodeDigit3InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								&& //0x3B1
	((KeycodeDigit4InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								&& //0x3B1
	((KeycodeDigit5InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								&& //0x3B1
	((KeycodeDigit6InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								&& //0x3B1
	((KeycodeDigit7InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))		    			       //0x3B1
#endif	
	
#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
	||	

	((eConfigStatus_Enabled == cf_opt_electroniclatch) 					                        && 
	(((eLatchStatusInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                             || //0x331
	((eLatchEventInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)                                || //0x331
	((eLatchMsgInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)))                                || //0x38D
	
    ((SvcBodyModInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    						    || //0x3B2
	/*((KeyInIgnInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)     						        || */
	((NFCDeviceInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)     						    || //0x3C6
	((PowerSystemStatusInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)     				    || //0x432
	
	((eConfigStatus_Enabled == cf_opt_outside_air_temperature_status) 					        && 
	((OATInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))                                      || //0x41A				//conflict in PDC DTC SRD - mentioned as 0x3B
	
	((eConfigStatus_Enabled == cf_opt_tiretempdisplay) 					                        && 
	(((TireTempLFDataInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                           || //0x3BB
	((TireTempRFDataInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)                             || //0x3BB
	((TireTempOLRDataInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)                            || //0x3BB
	((TireTempORRDataInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)))                          || //0x3BB
	
	((eConfigStatus_Enabled == cf_opt_policeidlemode) 					                        && 
	((PoliceIdleMdeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))                            || //0x38D
	
	((eConfigStatus_Enabled == cf_opt_policeliftgateunlock) 					                && 
	((PoliceLGLockInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))                             || //0x3c3
	
	((eConfigStatus_Enabled == cf_opt_welcome)												    &&
	(((VehWlcmFrwlInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)								|| //0x3BA	
	((VehWlcmFrwlModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))						    || //0x3BA
	
	((eConfigStatus_Enabled == cf_opt_powerlockcontrolconfig)                                   &&
	(((ParkLockAvailInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)  							|| //0x246
	((ParkLockTextInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)						        || //0x246
	((ParkLockUnlockInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))						       //0x246
#endif

	#ifdef COMABSCTRL_APPLICABLE_ONLY_FOR_V710
	||
	((eConfigStatus_Enabled == cf_opt_running_board_control_function)							&&
	((RunningBoardStatInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))							   //0x4A5
	/*
    ||
	((PowerLiftgatestatInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)							   
	*/
	||

	((NFCDeviceInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)     						    || //0x3C6	

	((PowerSystemInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING )                                || //0x423	

	((eConfigStatus_Enabled == cf_opt_parklockcontrolconfig) 									 &&
	((ParkLockAvailInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))                             || //0x246

	((eConfigStatus_Enabled == cf_opt_parklockcontrolconfig)                                      &&
	((ParkLockTextInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))	                          	  //0x246
	#endif
	)
	{
	 	if( dtc_rv_log_timer_expired != FALSE)
		{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC14000, eSetDTC);			   // Log ERC_LOST_COMM_BCM_DTC
		}
	}
	else
	{														 	                  
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC14000, eClearDTC);          // Clear ERC_LOST_COMM_BCM_DTC
	}
		
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x3DE
	*						Lost Communication With "Door Control Module A"
	*               	    Lost Comm w/ DDM DTC
	*						0xC19900
	*******************************************************************************/
	if(
		((cf_opt_mirrors_autofold_status == eConfigStatus_Enabled)       		||
		(cf_opt_mirrors_reverse_tilt_status == eConfigStatus_Enabled))    		&& 
		(((FeatConfigDDMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)  		|| 		//0x3DE
		((FeatNoDDMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    			|| 		//0x3DE
		((PersIndexDDMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))					//0x3DE	
	)  		   		
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19900, eSetDTC);			      // Log ERC_LOST_COMM_DDM_DTC
		}
	}
	else
	{														 	 // Clear ERC_LOST_COMM_DDM_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19900, eClearDTC);
	}
		
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x169
	*						Lost Communication With Transmission Range Control Module
	*               	    Lost Comm w/ TRCM DTC
	*						0xC19E00
	*******************************************************************************/
	if(((eConfigStatus_Enabled == cf_opt_shift_by_wire_status)    	&& 
	(eConfigStatus_Enabled == cf_opt_trcm_present_status))    		&& 
	((SvcTRCMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))  		//0x169	
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19E00, eSetDTC);			      // Log ERC_LOST_COMM_TRCM_DTC
		}
	}
	else
	{														 	 // Clear ERC_LOST_COMM_TRCM_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19E00, eClearDTC);
	}
		
	/******************************************************************************
     * DTC Condition    --> 1) Missing message on 0x18A, 0x3D8, 0x3CD,
	 *						 0x4D6
     *                		 Lost Comm w/ IPMA DTC
	 *						 0xC23A00
     *******************************************************************************/
		if(((eConfigStatus_Enabled == cf_opt_acc_status)                                        && 
        (((CADSRadarBlockInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                       || //0x18A
        ((ACCStopModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                           || //0x18A
        ((CADSAlignIncmpltInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                      || //0x18A
        ((ACCFollowModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                         || //0x18A
        ((ACCMsgTxtInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                             || //0x18A
        ((ACCModeSelInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                            || //0x18A
        ((ACCTGapInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                               || //0x18A
        ((ACCTGapStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                           || //0x18A
        ((ACCStopResumeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                         || //0x18A
        ((iACCLampInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))                            || //0x18A
        
        ((cf_opt_TSR_config == eConfigStatus_Enabled)                                           &&
        (((TSRLimitRstrc2Stat2ndInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                || //0x3CD     
        ((TSRLimitRstrc1Stat2ndInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                 || //0x3CD
        ((TSRLimitPerm1InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                         || //0x3CD
        ((TSROvrTkMsgTxt2ndInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                     || //0x3CD
        ((TSRLimit2InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                             || //0x3CD
        ((TSRLimit1InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                             || //0x3CD
        ((TSRLimit2StatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                         || //0x3CD
        ((TSRLimit1StatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                         || //0x3CD
        ((TSROvrTkStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                          || //0x3CD
        ((TSROvrTkMsgTxtInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                        || //0x3CD
        ((TSROvrSpdWarnInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))                       || //0x3CD

        ((cf_opt_trafficsignrecognition_status == eConfigStatus_Enabled)                        &&
        ((TSRUnitsInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))                             || //0x3CD

        ((eConfigStatus_Enabled == cf_opt_wrongwayalert)                                        &&  
        ((WrongWayWarnInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))                         || //0x3CD

        (((eConfigFCW_FCW == cf_opt_fcw_status) || (eConfigFCW_FCW_FDA == cf_opt_fcw_status))   && 
        (((FCWMsgTxtInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                            || //0x18A
        ((FCWPostEventInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                          || //0x18A
        ((DistIndInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))                             || //0x18A

		((eConfigAutoHighbeam_IPMA == cf_opt_auto_high_beam_telltale_status) 				    &&  
		((AutoHighBeamStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))     	  		    ||  //0x3D8

        (((eConfigLaneAssist_LDW == cf_opt_lane_assist_status)                                  ||
        (eConfigLaneAssist_FullLDW_LKA == cf_opt_lane_assist_status)                            ||
        (eConfigLaneAssist_LKSEuroNCAP == cf_opt_lane_assist_status)                            ||
        (eConfigLaneAssistMenu_Menu1 == cf_opt_lane_assist_ncap_alert)                          ||
        (eConfigLaneAssistMenu_Menu2 == cf_opt_lane_assist_ncap_alert)                          ||
        (eConfigLaneAssistMenu_Menu3 == cf_opt_lane_assist_ncap_alert)                          ||
        (eConfigLaneAssistMenu_Menu1 == cf_opt_lane_assist_ncap_aid)                            ||
        (eConfigLaneAssistMenu_Menu2 == cf_opt_lane_assist_ncap_aid)                            ||
        (eConfigLaneAssistMenu_Menu3 == cf_opt_lane_assist_ncap_aid))                           &&
        (((LADenyStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                           || //0x3D8
        ((LAHandsOffInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))                          || //0x3D8

		((eConfigStatus_Enabled == cf_opt_das_status) 							 				&&   
		(((DASStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		          				|| //0x3D8
		((DASWarnInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))				  				|| //0x3D8

		(((eConfigStatus_Enabled == cf_opt_das_status)     	  	 				 				||
		(eConfigStatus_Enabled ==  cf_opt_front_camera_status)) 								&&  
		((DriverCameraStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))		  				|| //0x3D8

        (((eConfigSettingsMenu_Cluster == cf_opt_settings_menu_status)                          &&  
        (eConfigAutoHBMenu_AutoHighBeams ==  cf_opt_autohighbeam_menu_status)                   ||
        (eConfigAutoHBMenu_GlarefreeHighBeams ==  cf_opt_autohighbeam_menu_status)              ||
        (eConfigAutoHBMenu_AdaptiveDrivingBeams ==  cf_opt_autohighbeam_menu_status)            ||
        (eConfigStatus_Enabled == cf_opt_iacc_status)                                           ||
        (eConfigLaneAssist_LDW == cf_opt_lane_assist_status)                                    ||
        (eConfigLaneAssist_FullLDW_LKA == cf_opt_lane_assist_status)                            ||
        (eConfigLaneAssist_LKSEuroNCAP == cf_opt_lane_assist_status)                            ||
        (cf_opt_trafficsignrecognition_status == eConfigStatus_Enabled)                         ||
        (cf_opt_slif_status == eConfigStatus_Enabled)                                           || 
        (eConfigStatus_Enabled == cf_opt_trafficjamassist_status)                               ||
        (eConfigStatus_Enabled ==  cf_opt_highwayassist_status)                                 ||    
        (eConfigStatus_Enabled == cf_opt_das_status)                                            ||   
        (eConfigStatus_Enabled == cf_opt_wrongwayalert))                                       	&&
        (((FeatConfigIPMAInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                       || //0x3D8
        ((FeatNoIPMAInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                            || //0x3D8
        ((PersIndexIPMAInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))                       || //0x3D8

        (((eConfigStatus_Enabled == cf_opt_trafficjamassist_status)                             ||
        (eConfigStatus_Enabled ==  cf_opt_highwayassist_status))                                &&        
        (((TJAMsgTxtInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                            || //0x18A
        ((TJAWarnRqInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)                             || //0x18A
        ((TJALaneBiasInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))                         ||  //0x4D6

        (((eConfigLaneAssist_LDW == cf_opt_lane_assist_status)                                  ||
        (eConfigLaneAssist_FullLDW_LKA == cf_opt_lane_assist_status)                            ||
        (eConfigLaneAssist_LKSEuroNCAP == cf_opt_lane_assist_status))                           &&
        ((LAFeatStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))                           ||

        ((eConfigStatus_Enabled == cf_opt_das_status)                                           &&   
        ((DASAlertInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))                                //0x3D8
    {
           if( dtc_rv_log_timer_expired != FALSE)
        {
            Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC23A00, eSetDTC);               // Log ERC_LOST_COMM_IPMA_SYS_MOD
        }
    }
    else
    {                                                            // Clear ERC_LOST_COMM_IPMA_SYS_MOD DTC
        Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC23A00, eClearDTC);
    
	}
		
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x451
	*						 Lost Communication With Image Processing Module B
	*                		 Lost Comm w/ IPMB DTC
	*						 0xC23B00
	*******************************************************************************/
	if(((eConfigStatus_Enabled == cf_opt_reverse_brake_assist_status)   && 
	(((RBAAlertInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    		|| //0x451
	((RBAMsgInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))))			   //0x451
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC23B00, eSetDTC);			     
		}
	}
	else
	{														 	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC23B00, eClearDTC);
	}
	
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x3DD
	*						Lost Communication With Headlamp Control Module "A"
	*                 		Lost Comm w/ HCM DTC
	*						0xC24100
	*******************************************************************************/
	if(
		(((cf_opt_predictive_lighting_configuration_status == eConfigStatus_Enabled) 		||
		(cf_opt_adaptiveheadlamps_status == eConfigStatus_Enabled))    		        		&& 
		(((FeatConfigHCMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)    				|| 	//0x3DD
		((FeatNoHCMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))						   	//0x33D
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((cf_opt_adaptiveheadlamps_status == eConfigStatus_Enabled) &&
		((AdaptHeadlampFailInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))					//0x334
		#endif
	)					   
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC24100, eSetDTC);			    
		}
	}
	else
	{														 	 
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC24100, eClearDTC);
	}
		
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x22B, 0x3E4
	*                 		Lost Comm w/ AHUD DTC
	*						0xC15800
	*******************************************************************************/
	if(
		(((eConfigStatus_Enabled == cf_opt_ahudmenu)  					||
		(eConfigStatus_Enabled == cf_opt_chud))						    && 
		(((HUDBrightIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			|| //0x22B
		((HUDVertIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			 	|| //0x22B
		((FeatConfigHUDIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		|| //0x3E4
		((FeatNoHUDIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			   //0x3E4
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		|| 
		((PersIndexHUDInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			//0x3E4		
		#endif
		))
		#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
		||
		((HUDSwtchIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				//0x22B	
		#endif
		||
		((eConfigStatus_Enabled == cf_opt_chud)							&&
		(((HUDVertSzIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			||  //0x22B
		((HUDStatIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))			    //0x22B
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY 
		||
		((eConfigStatus_Enabled == cf_opt_ahudmenu)						&&
		((HUDRotateInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))				//0x22B
		#endif
	)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC15800, eSetDTC);			      
		}
	}
	else
	{														 	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC15800, eClearDTC);
	}

	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x223
	*						Lost Communication With "Digital Audio Control Module A"
	*                 		Lost Comm w/ ACM DTC
	*						0xC19300
	*******************************************************************************/
	if(((eConfigChimeSource_AudioDualChime == cf_opt_primarychimesource) ||		
	(eConfigChimeSource_AudioSingleChime == cf_opt_primarychimesource)) && 
	(((AudioChimeSupptIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)	|| //0x223
	((AudioChime2NRIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 		|| //0x223
	((AudioChimeNRIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		|| //0x223
	((AudioChimeActvIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		|| //0x223
	((AudioChime2ActvIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 	|| //0x223
	((ChimeAdjVolIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			|| //0x223
	((ChimeNoIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				|| //0x223
	((Chime2AdjVolIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		|| //0x223
	((Chime2NoIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19300, eSetDTC);			      
		}
	}
	else
	{														 	
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19300, eClearDTC);
	}
		
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x263
	*               	    Lost Comm w/ AWD_DLCM DTC
	*						0xC11D00
	*******************************************************************************/
	if((eConfig4x4AWDSource_AWD_DLCM == cf_opt_awdsourcemodule)     && 
	  ((E4x4StatusIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING))  			
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC11D00, eSetDTC);	     // Log ERC_LOST_COMM_DDM_DTC
		}
	}
	else
	{														 	 // Clear ERC_LOST_COMM_DDM_DTC
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC11D00, eClearDTC);
	}
		
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x4D7
	*               	    Lost Comm w/ Gateway A DTC
	*						0xC14600
	*******************************************************************************/
	if((SeatOccRearChimeIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)  			
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC14600, eSetDTC);	     
		}
	}
	else
	{														 	 
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC14600, eClearDTC);
	}
		
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x27E
	*               	    Lost Comm w TCMU DTC TCUM or Telematic Control Module Unit
	*						0xC19800
	*******************************************************************************/
	if((eConfigStatus_Enabled == cf_opt_emergencycallfault)     && 
	  ((EmergencyCallFaultIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING))  			
	{
	   if( dtc_rsv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19800, eSetDTC);	     
		}
	}
	else
	{														 	 
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19800, eClearDTC);
	}
	
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x42C
	*					   Lost Communication With Battery Charger Control Module "A"
	*                      Lost Comm w/ BCCM DTC
	*                      0xC19B00
	*******************************************************************************/
	if(((eConfigPTHybrid2_PHEV == cf_opt_pt_hybrid_2)				|| //0x3
	(eConfigPTHybrid2_BEV == cf_opt_pt_hybrid_2))					&& //0x1
	((SvcBattTracIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING))    	//0x42c      
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19B00, eSetDTC);                
		}
	}
	else
	{                                                           
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19B00, eClearDTC);     
	}

	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x282
	*                      Lost Comm w/ O-BCCM DTC
	*                      0xC27C00
	*******************************************************************************/
	/* if((eConfigPTHybrid2_BEV == cf_opt_pt_hybrid_2)		&& 
	   ((DcChrgRqIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING))            
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC27C00, eSetDTC);                
		}
	}
	else
	{                                                           
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC27C00, eClearDTC);     
	}  */
	
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x108 
						    	PDC : Missing message on 0x252, 0x366
	*                      Lost Comm w/ BECM DTC
	*                      0xC11100
	* 					   Lost Communication With Battery Energy Control Module "A"
	*******************************************************************************/
	if((((cf_opt_pt_hybrid_2 == eConfigPTHybrid2_PHEV) 										||  //  0x03
		(cf_opt_pt_hybrid_2 == eConfigPTHybrid2_BEV))										&&  //  0x01
		((BattTracSoCInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))						    //  0x108 - FORD GENERIC ;0x252  - FORD PDC									  
		#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
		||
		((cf_opt_pt_hybrid_2 == eConfigPTHybrid2_BEV)										&&  // Impediment - 1650178
		((EffRgnThresInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))							// 0X366
		||
		((EffWhlLvl2InStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)							||
		((EffWhlThresInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)						||	// Impediment - 1655107
		((EngModeMsgTxtInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)						||	// Impediment - 1655107
		((RegenAnimationInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING) 					||	// Impediment - 1655107
		((BattPwAvailInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)
		#endif
	)
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC11100, eSetDTC);                
		}
	}
	else
	{                                                           
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC11100, eClearDTC);     
	}

	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x282, 0x43A
	*               	    Lost Comm w/ DCMG DTC 
	*						0xC20500
	*******************************************************************************/
	if(
		((cf_opt_powerslidingdoor == eConfigPowerSlidingDoor_LeftPSD ) 						|| 
		(cf_opt_powerslidingdoor == eConfigPowerSlidingDoor_LeftAndRightPSD))				&&
		(((SliderLeftInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 						||							//0x43A; 0x4C0 for PDC
		((SlidingDoorLeftChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 				||							//0x282; 0x4C0 for PDC			
		((SlidingDoorLeftMessageTextInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))									//0x282; 0x4C0 for PDC
	)											
	{
	   if( dtc_rsv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC20500, eSetDTC);	     
		}
	}
	else
	{														 	 
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC20500, eClearDTC);
	}
	
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x282, 0x43A
	*               	    Lost Comm w/ DCMH DTC 
	*						0xC20B00
	*******************************************************************************/
	if(
		((eConfigPowerSlidingDoor_RightPSD == cf_opt_powerslidingdoor) 						||
		(eConfigPowerSlidingDoor_LeftAndRightPSD == cf_opt_powerslidingdoor)) 				&&
		(((SliderRightInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 						|| 							//0x43A ; 0x4C1 for PDC
		((SlidingDoorRightChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)				||							//0x282 ; 0x4C1 for PDC					
		((SlidingDoorRightMessageTextInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))
	)									//0x282 ; 0x4C1 for PDC			
	{
	   if( dtc_rsv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC20B00, eSetDTC);	     
		}
	}
	else
	{														 	 
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC20B00, eClearDTC);
	}

	#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x41E
	*               	    Lost Comm w/ VDM DTC 
	*						0xC12200
	*******************************************************************************/
	if(((cf_opt_CeramicBrakePadWearIndicator == eConfigStatus_Enabled)					&&
	  	((BrakePadWearOutInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))				||	//0x41E
	  	((CCDFaultInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))							//0x365					Impediment - 1650175
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC12200, eSetDTC);	     
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC12200, eClearDTC);
	}
	#endif

	#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x313
	*               	    Lost Comm w/ RGTM DTC 
	*						0xC23000
	*******************************************************************************/
    if(
		(cf_opt_powerliftgate == eConfigStatus_Enabled) 					&&
    	(((PwrDrLGChimeIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||  //0x313
		((PowerLiftgateStatIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING))			//0x313
	)
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC23000, eSetDTC);
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC23000, eClearDTC);		
    }
	#endif

	#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x2A2
	*               	    Lost Comm w/ RSEM DTC 
	*						0xC19600
	*******************************************************************************/
	if (
		((cf_opt_rsem_config == eConfigStatus_Disabled)	 								&& 
		(cf_opt_refp_config == eConfigStatus_Enabled)) 									&&
		(((RACMBtnIDAInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING) 					||				//Impediment 1650916
		((RACMBtnIDBInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING) 					||				//Impediment 1650916
		((RACMBtnIDCInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING) 					||				//Impediment 1650916
		((RACMBtnIDDInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING) 					||				//Impediment 1650916
		((RACMCodingBtnIDAInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING) 				||				//Impediment 1665338
		((RACMCodingBtnIDBInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING) 				||				//Impediment 1665338
		((RACMCodingBtnIDCInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING) 				||				//Impediment 1665338
		((RACMCodingBtnIDDInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING) 				||				//Impediment 1665338
		((RACMSetVolumeInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING) 					||				//0x2A2
		((RearAudioCtlLckDStInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||				//0x2A2
		((RearMnuCtlLckBStInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))								//0x2A2
	)
	{
		if(dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19600, eSetDTC);	     
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC19600, eClearDTC);
	}
	#endif

	#ifdef DTC_SIGNALS_APPLICABLE_FOR_DC_ONLY
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x2A0
	*               	    Lost Comm w/ FCIM DTC 
	*						0xC25600
	*******************************************************************************/
    if(((cf_opt_icpnetwork == eConfigStatus_Disabled) 						&&
	(cf_opt_icppresent == eConfigStatus_Disabled))							&&
	(((BtnIDAInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 				||
	((BtnIDBInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 				||
	((BtnIDCInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 				||
	((BtnIDDInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 				||
	((CodingBtnIDAInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||			//IMPEDIMENT - 1657860
	((CodingBtnIDBInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||			//IMPEDIMENT - 1657860
	((CodingBtnIDCInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||			//IMPEDIMENT - 1657860
	((CodingBtnIDDInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||			//IMPEDIMENT - 1657860
	((SetVolumeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			||
	((SetPointVolumeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 		||
	((BCPAudibleBeepRqInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC25600, eSetDTC);
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC25600, eClearDTC);		
    }
	#endif
}

// INVALID DTCs

static void network_invalid_dtc_process (void)
{
	boolean cf_opt_pt_hybrid_2;
	boolean cf_opt_pt_hybrid_2_status;
	boolean cf_opt_pwr_d_gauge_feature_status;
	boolean cf_opt_transmission_fluid_temp_display;
	boolean cf_opt_oat_status ;
	boolean cf_opt_oat_source_status;
	boolean	cf_opt_driver_beltminder;
	boolean	cf_opt_pass_beltminder; 
	boolean cf_opt_mid_pass_beltminder;
	boolean cf_opt_bsm_status;
	boolean cf_opt_cta_status;
	boolean	cf_opt_selectable_drive_mode_status;
	boolean cf_opt_hybrid_engine_config_status;
	boolean cf_opt_mhevstartstopspeedthresholdcontrolfunction;
	boolean cf_opt_tpms_status;
	boolean cf_opt_chinabev_xhevfunction;
	boolean cf_opt_trailer_brake_status;
	boolean cf_opt_TrailerBrakee2eSignalProtection;
	boolean cf_opt_R1C1BeltMinderChime;
	boolean cf_opt_R1C3BeltMinderChime;
	boolean cf_opt_R1C5BeltMinderChime;
	
	uint8	EngTempQFInValue;
	uint8	OdoInStatus;
	uint8   PwrTrainTorqueInStatus;
	uint8	VSpdInStatus;
	uint8	VSpdQFInValue;
	uint8	VSpdQFInStatus;
	uint8   TransTempInStatus;
	uint8   TransTempInValue;
	uint8   OatInStatus;
	uint8	OneRowSBDriverInStatus;
	uint8	OneRowSBPassInStatus;
	uint8	OneRowSBMiddleInStatus;
	uint8	EngTempInStatus;
	uint8	EngTempQFInStatus;
	uint8	HeaterCoreTempInStatus;
	uint8   HeaterCoreTempInValue;
	uint8   LBSMOpInValue;
    uint8   LCrossTrafficSnsrInValue;
    uint8   LCrossTrafficOpInValue;
	uint8   RBSMOpInValue;
    uint8   RCrossTrafficSnsrInValue;
    uint8   RCrossTrafficOpInValue;
	uint8	DriveModeSelInStatus;
	uint8	DrvModeSelectMsgInStatus;
	uint8	DrvModeSelectStatInStatus;
	uint8 	RegenLevelInStatus;
	uint8 	EffWhlLvl2In;
	uint8	VehElRangeIn;
	uint8	TPMSTTInStatus;
	uint8	TPMSTTInValue;
	uint8   BattTracSoCInStatus;
	uint8	OdoInValue;
	uint8   OneRowSBDriverInValue;
	uint8   OneRowSBPassInValue;
	uint8   OneRowSBMiddleInValue;
	uint8   BattTracSoCInValue;
	uint8   DriveModeSelInValue;
	uint8   DrvModeSelectMsgInValue;
	uint8	DrvModeSelectStatInValue;
	uint8	TrailerBrkFaultStat2InValue;
	uint8   TrailerBrkFaultStat2InStatus;
	uint8	TrailerBrkFaultCounter2InValue;
	uint8	TrailerBrkFaultCounter2InStatus;
	uint8	TrailerBrkFaultCheckSum2InValue;
	uint8	TrailerBrkFaultCheckSum2InStatus;
	
	uint32  SigInValue;
	uint8   SigInStatus;
	
	/*VOPS Variables*/
	
	GET_VOPS_CF_OPT_PT_HYBRID_2(&cf_opt_pt_hybrid_2_status); 
	GET_VOPS_CF_OPT_PWR_D_GAUGE_FEATURE(&cf_opt_pwr_d_gauge_feature_status); 
	GET_VOPS_TRANSMISSIONFLUIDTEMPDISPLAY(&cf_opt_transmission_fluid_temp_display);	
	GET_VOPS_CF_OPT_PT_HYBRID_2(&cf_opt_pt_hybrid_2);
	GET_VOPS_OAT(&cf_opt_oat_status);
	GET_VOPS_OATSOURCE(&cf_opt_oat_source_status);
	GET_VOPS_DRIVERBELTMINDER(&cf_opt_driver_beltminder);
	GET_VOPS_PASSBELTMINDER(&cf_opt_pass_beltminder);
	GET_VOPS_MIDPASSBELTMINDER(&cf_opt_mid_pass_beltminder);
	GET_VOPS_CTA(&cf_opt_cta_status); //Cross Traffic 
    GET_VOPS_BSM(&cf_opt_bsm_status); //Side Detect or Blind Spot Monitoring
	GET_VOPS_SELECTABLE_DRIVE_MODE(&cf_opt_selectable_drive_mode_status);
	GET_VOPS_CF_OPT_HYBRID_ENGINE_CONFIG(&cf_opt_hybrid_engine_config_status);
	GET_VOPS_MHEVSTARTSTOPSPEEDTHRESHOLDCONTROLFUNCTION(&cf_opt_mhevstartstopspeedthresholdcontrolfunction);
	GET_VOPS_TPMS(&cf_opt_tpms_status);
	GET_VOPS_CHINABBEV_XHEVFUNCTION(&cf_opt_chinabev_xhevfunction);
	GET_VOPS_CF_OPT_TRAILER_BRAKE_CONTROLLER(&cf_opt_trailer_brake_status);
	GET_VOPS_TRAILERBRAKEE2ESIGNALPROTECTION(&cf_opt_TrailerBrakee2eSignalProtection);
	GET_VOPS_R1C1BELTMINDERCHIME(&cf_opt_R1C1BeltMinderChime);
	GET_VOPS_R1C3BELTMINDERCHIME(&cf_opt_R1C3BeltMinderChime);
	GET_VOPS_R1C5BELTMINDERCHIME(&cf_opt_R1C5BeltMinderChime);
		
	/*CAN signals*/
	GET_CAN_RX_ENGTEMPIN(&SigInValue,&EngTempInStatus);
	GET_CAN_RX_ENGTEMPQFIN(&EngTempQFInValue,&EngTempQFInStatus);
	GET_CAN_RX_HEATERCORETEMPIN(&HeaterCoreTempInValue,&HeaterCoreTempInStatus);  
	GET_CAN_RX_ODOIN(&OdoInValue,&OdoInStatus);  
	GET_CAN_RX_PWRTRAINTORQUEIN(&SigInValue,&PwrTrainTorqueInStatus);
	GET_CAN_RX_VSPDIN(&SigInValue,&VSpdInStatus);   
	GET_CAN_RX_VSPDQFIN(&VSpdQFInValue,&VSpdQFInStatus);
	GET_CAN_RX_TRANSTEMPIN(&TransTempInValue,&TransTempInStatus);
	GET_CAN_RX_OATINSTATUS(&SigInValue,&OatInStatus);
	GET_CAN_RX_1ROWSBDRIVERIN(&OneRowSBDriverInValue,&OneRowSBDriverInStatus);
	GET_CAN_RX_1ROWSBPASSIN(&OneRowSBPassInValue,&OneRowSBPassInStatus);
	GET_CAN_RX_1ROWSBMIDDLEIN(&OneRowSBMiddleInValue,&OneRowSBMiddleInStatus);	
	GET_CAN_RX_LBSMOPIN(&LBSMOpInValue,&SigInStatus);
    GET_CAN_RX_LCROSSTRAFFICSNSRIN(&LCrossTrafficSnsrInValue,&SigInStatus);
    GET_CAN_RX_LCROSSTRAFFICOPIN(&LCrossTrafficOpInValue,&SigInStatus);
    GET_CAN_RX_RBSMOPIN(&RBSMOpInValue,&SigInStatus);
    GET_CAN_RX_RCROSSTRAFFICSNSRIN(&RCrossTrafficSnsrInValue,&SigInStatus);
    GET_CAN_RX_RCROSSTRAFFICOPIN(&RCrossTrafficOpInValue,&SigInStatus);	
	GET_CAN_RX_DRIVEMODESELIN(&DriveModeSelInValue,&DriveModeSelInStatus);
	GET_CAN_RX_DRVMODESELECTMSGIN(&DrvModeSelectMsgInValue,&DrvModeSelectMsgInStatus);
	GET_CAN_RX_DRVMODESELECTSTATIN(&DrvModeSelectStatInValue,&DrvModeSelectStatInStatus);
	GET_CAN_RX_REGENLEVELIN(&SigInValue,&RegenLevelInStatus);
	GET_CAN_RX_EFFWHLLVL2IN(&SigInValue,&EffWhlLvl2In);
	GET_CAN_RX_VEHELRANGEIN(&SigInValue,&VehElRangeIn);
	GET_CAN_RX_TPMSTTIN(&TPMSTTInValue,&TPMSTTInStatus);
	GET_CAN_RX_BATTTRACSOCIN(&BattTracSoCInValue,&BattTracSoCInStatus);
	GET_CAN_TRAILERBRKFAULTSTAT2IN(&TrailerBrkFaultStat2InValue,&TrailerBrkFaultStat2InStatus);
	GET_CAN_TRAILERBRKFAULTCOUNTER2IN(&TrailerBrkFaultCounter2InValue,&TrailerBrkFaultCounter2InStatus);
	GET_CAN_TRAILERBRKFAULTCHECKSUM2IN(&TrailerBrkFaultCheckSum2InValue,&TrailerBrkFaultCheckSum2InStatus);

	/******************************************************************************
    * Invalid Data from TBCM DTC
    * DTC Condition    -->Invalid Signal on 0x4DE
    *    0xC43882
	* Allowed Power Mode - Run 
    ******************************************************************************/
	static uint8 TrailerAfMkChksumRes = 0;
	static uint8 PreviousFaultCounter2 = 0;
	static uint8 TBCM_DTC_FLAG = 0;
	static uint8 TBCM_Invalid_Data_Timer = TBCM_INVALID_TIME; //0.6 Seconds 10ms Periodic Function
		
	if((cf_opt_trailer_brake_status == eConfigStatus_Enabled) 				&& 
	(cf_opt_TrailerBrakee2eSignalProtection == eConfigStatus_Enabled))
	{
		TrailerAfMkChksumRes = ~ (TrailerBrkFaultStat2InValue + TrailerBrkFaultCounter2InValue);

		if(TrailerBrkFaultCounter2InValue == PreviousFaultCounter2)
		{
			if((TBCM_Invalid_Data_Timer == 0U) && (TBCM_Invalid_Data_Timer != 60U))
			{
				TBCM_DTC_FLAG = 0x1;
				if( dtc_rv_log_timer_expired != FALSE)
				{
					Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43882, eSetDTC);  	   
				}
			}
			else
			{
				TBCM_DTC_FLAG = 0x0;
				Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43882, eClearDTC);
				TBCM_Invalid_Data_Timer --;
			}
		}
		else
		{
			PreviousFaultCounter2 = TrailerBrkFaultCounter2InValue;
			if(TrailerAfMkChksumRes == TrailerBrkFaultCheckSum2InValue)
			{
				//Stop the timer
				TBCM_Invalid_Data_Timer == TBCM_INVALID_TIME;
				TBCM_DTC_FLAG = 0x0;
				Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43882, eClearDTC);
			}
			else
			{
				if((TBCM_Invalid_Data_Timer == 0U) && (TBCM_Invalid_Data_Timer != 60U))
				{
					TBCM_DTC_FLAG = 0x1;
					if( dtc_rv_log_timer_expired != FALSE)
					{
						Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43882, eSetDTC);  	   
					}
				}
				else
				{
					TBCM_DTC_FLAG = 0x0;
					Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43882, eClearDTC);
					TBCM_Invalid_Data_Timer --;
				}
			}
		}		
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43882, eClearDTC);
    }
	/******************************************************************************
	* Invalid Data from ECM_PCM DTC
	* DTC Condition    -->Invalid Signal on 0x156, 0x178, 0x179, 0x202
	*     	 0xC40100
	******************************************************************************/
	if(((EngTempInStatus & eSIGNAL_INVALID) == eSIGNAL_INVALID) &&
	((EngTempQFInValue == ENGTEMP_FAULTY_VALUE)	|| // 0x1
	(EngTempQFInValue == ENGTEMP_NOT_WITHIN_SPEC) 	|| //0x2
	(EngTempQFInValue == 0x0))						|| //As per the NW SRD rev 356 0x0 | 0x1 | 0x2
	
	((cf_opt_pt_hybrid_2 == eConfigPTHybrid2_PHEV) && 
	(((HeaterCoreTempInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID) || //0x3FF As per SRD
	(HeaterCoreTempInValue == 0x3FF)))						||
	
	(((OdoInStatus & eSIGNAL_INVALID) == eSIGNAL_INVALID)	|| //0xFF
	(OdoInValue == 0xFF))									|| //As per SRD
	
	(((VSpdInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID) && 
	((VSpdQFInValue == VSPD_FAULTY_VALUE)					||  //0x0
	(VSpdQFInValue == VSPD_NO_DATA_EXISTS))))					//0x1 As per SRD
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation(0xC40100, eSetDTC);
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation(0xC40100, eClearDTC);
	}
	
	/******************************************************************************
    * Unknown Data from ECM_PCM DTC
    * DTC Condition    -->Invalid Signal on 0x156, 0x202
    *    0xC40181 
    ******************************************************************************/
    if((((EngTempInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID) 	&& 
    (EngTempQFInValue == ENGTEMP_NO_DATA_EXISTS)) 					||  //0x1
	
	(((VSpdInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID) 		&& 
	(VSpdQFInValue == VSPD_NO_DATA_EXISTS)))							//0x1
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40181, eSetDTC);  	   
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40181, eClearDTC);		   
    }
	 
	/******************************************************************************
    * Invalid Data from HVAC DTC
    * DTC Condition    -->Invalid Signal on 0x3B3
    *    0xC42400
	* Allowed Power Mode - Run 
    ******************************************************************************/
    if(
    #ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
	(cf_opt_oat_status == eConfigStatus_Enabled) 		&& 			//Impediment - 1642062
	#endif
	(cf_opt_oat_source_status == eConfigOATSource_HVAC)		&& 
    ((OatInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID) 	&&
	(GetRawOutside_Air_Temp_Stat() == (0xFF)))
    {
        if( dtc_rsv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42400, eSetDTC);  	   // Log ERC_INVLD_TPMS_DATA_FROM_SJB DTC
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42400, eClearDTC);		    // Clear ERC_INVLD_TPMS_DATA_FROM_SJB DTC
    }

	/******************************************************************************
    * Unknown Data from HVAC DTC
    * DTC Condition    -->Invalid Signal on 0x3B3
    *     0xC42481
	* Allowed Power Mode - Run 
    ******************************************************************************/
    if(
	#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
	(cf_opt_oat_status == eConfigStatus_Enabled) 		&& 			//Impediment - 1642062
	#endif
	(cf_opt_oat_source_status == eConfigOATSource_HVAC)		&&
    ((OatInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID) 	&&
	(GetRawOutside_Air_Temp_Stat() == 0xFE))
    {
        if( dtc_rsv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42481, eSetDTC);  	   // Log ERC_INVLD_TPMS_DATA_FROM_SJB DTC
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42481, eClearDTC);		    // Clear ERC_INVLD_TPMS_DATA_FROM_SJB DTC
    }

    /******************************************************************************
    * Invalid Data from FCIM DTC
    * DTC Condition    -->Invalid Signal on 0x3B3
    *     0xC55700
	* Allowed Power Mode - Run 
    ******************************************************************************/
    if(
	#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
	(cf_opt_oat_status == eConfigStatus_Enabled) 		&& 			//Impediment - 1642062
	#endif
	(cf_opt_oat_source_status == eConfigOATSource_FCIM) 	&&
    ((OatInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID)	&&
	(GetRawOutside_Air_Temp_Stat() == (0xFF)))
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC55700, eSetDTC);  	   // Log ERC_INVLD_TPMS_DATA_FROM_SJB DTC eConfigOATSource_HVAC
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC55700, eClearDTC);		    // Clear ERC_INVLD_TPMS_DATA_FROM_SJB DTC
    }

	/******************************************************************************
    * Unknown Data from FCIM DTC
    * DTC Condition    -->Invalid Signal on 0x3B3
    *     0xC55781
	* Allowed Power Mode - Run 
    ******************************************************************************/
    if(
	#ifndef DTC_SIGNALS_NOT_APPLICABLE_FOR_DC
	(cf_opt_oat_status == eConfigStatus_Enabled) 		&& 			//Impediment - 1642062
	#endif
	(cf_opt_oat_source_status == eConfigOATSource_FCIM)  	&&
    (( OatInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID) 	&&
	(GetRawOutside_Air_Temp_Stat() == 0xFE))
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC55781, eSetDTC);  	   // Log ERC_INVLD_TPMS_DATA_FROM_SJB DTC
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC55781, eClearDTC);		    // Clear ERC_INVLD_TPMS_DATA_FROM_SJB DTC
    }
	 
	/******************************************************************************
    * Unknown Data from RCM DTC
	*  Messages 0x4C
    * DTC Condition    -->Invalid Signal on 0x4C
    *     0xC45281
    ******************************************************************************/
    if(((eConfigStatus_Enabled ==  cf_opt_R1C1BeltMinderChime) 		 										 && 
	((OneRowSBDriverInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID))										 ||
	
    ((eConfigStatus_Enabled ==  cf_opt_R1C5BeltMinderChime) 				 								 && 
	((OneRowSBPassInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID)) 										 ||
	
	((eConfigStatus_Enabled ==  cf_opt_R1C3BeltMinderChime) 												 && 
	((OneRowSBMiddleInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID)))										 
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC45281, eSetDTC);  	   
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC45281, eClearDTC);		   
    }
	 
	/******************************************************************************
    * Invalid Data from SODL DTC
    * DTC Condition    -->Invalid Signal on 0x3A6
    *      Side_Detect_L_Stat_HS3 0x3A6
	* 0xc53300
    ******************************************************************************/
	if((( cf_opt_bsm_status == eConfigStatus_Enabled )  && \
		((LBSMOpInValue == 0x04) || (LBSMOpInValue == 0x05) || \
		(LBSMOpInValue == 0x06) || (LBSMOpInValue == 0x07))) || \
		(( cf_opt_cta_status == eConfigStatus_Enabled)	&& \
		((LCrossTrafficSnsrInValue == 0x03) || (LCrossTrafficOpInValue   == 0x03))))
	{
		if((dtc_rv_log_timer_expired != FALSE)&& (sodl_timer_count_expired == TRUE))
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53300, eSetDTC);  	   // Log ERC_INVLD_TPMS_DATA_FROM_SJB DTC
		}
	}
	else
	{
		sodl_timer_count = 0;
		sodl_timer_count_expired = FALSE;
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53300, eClearDTC);		    // Clear ERC_INVLD_TPMS_DATA_FROM_SJB DTC
	}
	 
	/******************************************************************************
    * Invalid Data from SODR DTC
    * DTC Condition    -->Invalid Signal on 0x3A7
    *      Side_Detect_R_Stat_HS3 0x3A7
	* 0xC53400
    ******************************************************************************/
    if((( cf_opt_bsm_status == eConfigStatus_Enabled)  			&& \
    ((RBSMOpInValue == 0x04) || (RBSMOpInValue == 0x05) 		|| \
     (RBSMOpInValue == 0x06) || (RBSMOpInValue == 0x07))) 		|| \
    ((cf_opt_cta_status == eConfigStatus_Enabled) 				&& \
    ((RCrossTrafficSnsrInValue == 0x03) || \
     (RCrossTrafficOpInValue   == 0x04) || (RCrossTrafficOpInValue   == 0x05) || \
     (RCrossTrafficOpInValue   == 0x06) || (RCrossTrafficOpInValue   == 0x07))))
	{
		if((dtc_rv_log_timer_expired != FALSE) && (sodr_timer_count_expired == TRUE))
        {
		    Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53400, eSetDTC);  	   // Log ERC_INVLD_TPMS_DATA_FROM_SJB DTC
        }
    }
    else
    {
        sodr_timer_count = 0;
        sodr_timer_count_expired = FALSE;
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53400, eClearDTC);		    // Clear ERC_INVLD_TPMS_DATA_FROM_SJB DTC
    }
	 
	/******************************************************************************

     * Invalid Data from ABS DTC

     * DTC Condition    -->Invalid Signal on 0x420

     * Msg ID:   0x420

     * DTC : 0xC41500

     ******************************************************************************/

    if((cf_opt_selectable_drive_mode_status == eConfigStatus_Enabled)                   && \
    ((((DriveModeSelInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID)                    || //0x420
    (DriveModeSelInValue == 0x1F))                                                      ||
    ((( DrvModeSelectMsgInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID)                || //0x420
    (DrvModeSelectMsgInValue == (0x8||0x9||0xA||0xB||0xC||0XD||0xE||0xF)))              ||                                           
    (((DrvModeSelectStatInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID)                || //0x420
    (DrvModeSelectStatInValue == 0x03))))
    {
    if( dtc_rv_log_timer_expired != FALSE)
  {
    Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41500, eSetDTC);        // Log ERC_INVLD_TPMS_DATA_FROM_SJB DTC
  }
    }
    else
  {
    Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41500, eClearDTC);           // Clear ERC_INVLD_TPMS_DATA_FROM_SJB DTC
  }
	/******************************************************************************
	 * Invalid Data from HPCM DTC
	 * DTC Condition    -->Invalid Signal on 0x474, 0x365
	 * 0xC59400
	 ******************************************************************************/
	if((( cf_opt_hybrid_engine_config_status == TRUE) 					&& 
	(( RegenLevelInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID)) 		|| //0x474 AS FORD PER GENERIC

	((cf_opt_pt_hybrid_2 == eConfigPTHybrid2_MHEV)						&& 
	((EffWhlLvl2In  & eSIGNAL_INVALID) == eSIGNAL_INVALID))				||	//0x365

	(( VehElRangeIn  & eSIGNAL_INVALID) == eSIGNAL_INVALID))
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC59400, eSetDTC);         
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC59400, eClearDTC);        
	}
	 
	/******************************************************************************
    * Invalid Odo Data from ECM_PCM DTC
    * DTC Condition    --> Invalid Signal on 0x179
    *    0xC40186 
    ******************************************************************************/
    if(((OdoInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID)	||
		(OdoInValue == 0xFF))
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
            Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40186, eSetDTC);        
        }
    }
    else
    {
       Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40186, eClearDTC);           
    }
	 
	/******************************************************************************
	* Invalid TPMS Data from SJB DTC
	* DTC Condition    -->Invalid Signal on
	*     Tire_Pressure_Status(0x3B4)  - Tire_Press_Telltale
	* Allowed Power Mode - Run |Start
	******************************************************************************/
	if((cf_opt_tpms_status == eConfigStatus_Enabled) 				&& 
	(((TPMSTTInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID)		||
	(TPMSTTInValue  == 0x03)))											//0x3B4
	{
		if( dtc_rsv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42200, eSetDTC);      
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42200, eClearDTC);          
	}

	/******************************************************************************
	* Invalid Data Received From Battery Energy Control Module "A" (BECM)
	* DTC Condition    -->Invalid Signal on 0x108
	* 					0xC41286
	******************************************************************************/
	if(((cf_opt_chinabev_xhevfunction == eConfigStatus_Enabled)    	&&
	((cf_opt_pt_hybrid_2 == eConfigPTHybrid2_FHEV)					||
	(cf_opt_pt_hybrid_2 == eConfigPTHybrid2_PHEV)))					&&
	(((BattTracSoCInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID) 	||
	(BattTracSoCInValue == 0xFF) || (BattTracSoCInValue == 0xFE)))
	{
		if( dtc_rsv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41286, eSetDTC);      // Log ERC_INVLD_TPMS_DATA_FROM_SJB DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41286, eClearDTC);          // Clear ERC_INVLD_TPMS_DATA_FROM_SJB DTC
	}
	
	/******************************************************************************
	* 		Invalid Data Received From Side Obstacle Detection Control Module "A"
	*		SODL Feature Misconfigured DTC
	* 		DTC Condition    -->	Invalid Signal on 0x3A6
	* 								0xC53356
	******************************************************************************/
	if(((cf_opt_cta_status == eConfigStatus_Enabled)    		&&
	(LCrossTrafficOpInValue == 0x03)) 							|| //0x3A6

	((cf_opt_cta_status == eConfigStatus_Disabled)    			&&
	(LCrossTrafficOpInValue != 0x03)))								//0x3A6
	{
		if( dtc_rsv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53356, eSetDTC);     
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53356, eClearDTC);          
	}
	
	/******************************************************************************
	* 		Invalid Data Received From Side Obstacle Detection Control Module "A"
	*		SODL Feature Misconfigured DTC
	* 		DTC Condition    -->	Invalid Signal on 0x3A7
	* 								0xC53456
	******************************************************************************/
	if(((cf_opt_cta_status == eConfigStatus_Enabled)    		&&
	(RCrossTrafficOpInValue == 0x03)) 							|| //0x3A7

	((cf_opt_cta_status == eConfigStatus_Disabled)    			&&
	(RCrossTrafficOpInValue != 0x03)))								//0x3A7
	{
		if( dtc_rsv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53456, eSetDTC);     
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53456, eClearDTC);          
	}
	
	 
}

// NO UPDATE DTC IMPLEMENTATION

static void network_noupdate_dtc_process (void)
{
	boolean cf_opt_oat_status ;
	boolean cf_opt_oat_source_status;
	boolean cf_opt_running_board_control_function_status;
	boolean cf_opt_offroadscreen_status;
	boolean cf_opt_autohold_status;
	boolean	cf_opt_tc_ivd_rsc_status;
	boolean	cf_opt_adaptiveheadlamps_status;
	boolean	cf_opt_highbeamtelltalesource_status;
    boolean cf_opt_reverse_warning_status;
	boolean cf_opt_def_gauge_configuration_status;
	boolean	cf_opt_engineairfilterminder_status;
	boolean	cf_opt_running_board_control_function;
	boolean	cf_opt_elsd;
	boolean cf_opt_ChargePortDoorAjarWarningConfiguration;
	boolean cf_opt_autohighbeamtelltale;
	boolean cf_opt_powerliftgate;
	boolean cf_opt_approaching_vehicle_audible_system_status;
	boolean cf_opt_epas_status;
    boolean cf_opt_trailerbackupassist_status;	
	boolean cf_opt_pt_hybrid_2;
	boolean cf_opt_auto_high_beam_menu;
	boolean cf_opt_CeramicBrakePadWearIndicator;
	boolean cf_opt_AdvanceTracHardButton;
	boolean cf_opt_AdvanceTrac;
	boolean cf_opt_powerlockcontrolconfig;
	boolean cf_opt_powerlockcontrol;
	boolean	cf_opt_powerslidingdoor;
	boolean cf_opt_tpms_status;
	boolean cf_opt_trans_type_status;
	boolean cf_opt_Autopark_Warning_Configuration;
	boolean cf_opt_BlindSpotAssistWarnings;
	boolean cf_opt_ClearExitAssistMenu;
	boolean cf_opt_trafficsignrecognition_status;
	boolean cf_opt_slif_status;
	boolean cf_opt_tcm_present;
	boolean cf_opt_TransmissionFluidTemperatureGaugeConfiguration;
	boolean cf_opt_diesel_engine_config_status;
	boolean cf_opt_ePRNDLe2eSignalProtection;
	
	uint8   OatInStatus;
	uint8	RunningBoardStatInStatus;
	uint8   RunningBoardStatInValue;
	uint8   PowerSystemStatusInStatus;
	uint8   SteerWhlAngle2InStatus;
	uint8   VehPitchAngleInStatus;
	uint8   VehRollAngleInStatus;
	uint8   AutoHoldIndInStatus;
	uint8   AutoHoldWarnInStatus;
	uint8   ESCOffTTInStatus;
	uint8   AdaptHeadlampFailInStatus;	
	uint8   HighBeamHCMInStatus;
	uint8   CruiseCtrlSetSpdInStatus;
	uint8   CruiseOverrideInStatus;
	uint8	CruiseControlStatInStatus;
	uint8	UreaLvlPcInStatus;
	uint8   TransTempInStatus;
	uint8	TransTempInValue;
	uint8   EngAirFilterInStatus;
	uint8	GearPosInStatus;
	uint8	PowerStepMsgInStatus;
	uint8	SvcELSDInStatus;
	uint8	ChargePortDoorOpenIn;
	uint8	PwrPackReadyIn;
	uint8   PwrDrLGChimeIn;
	uint8   PowerLiftgateStatIn;
	uint8   AutoHighBeamStatIn;
	uint8   AutoHighBeamSCCMIn;
	uint8   HighBeamSCCMIn;
	uint8   PdstrnAlrtFaltInStatus;
	uint8   EPASFailureInStatus;
    uint8   TBATextInStatus;
    uint8   TBAEnableInStatus;
	uint8	ParkLockTextIn;
	uint8   ParkLockAvailIn;
	uint8	OverTempLampInStatus;
	uint8 	BrakePadWearOutInStatus;
	uint8 	DrvSlipCtlModeMsgInStatus;
	uint8	SvcBattTracIn;
	uint8	TPMSTTInStatus;
	uint8   TPMSTTInValue;
	uint8	SlidingDoorLeftChimeInStatus;
	uint8	SlidingDoorRightChimeInStatus;
	uint8   APAChimeInStatus;
	uint8   LCWAMsgInStatus;
	uint8	TSRRegionInStatus;
	uint8	CEAMsgTxRqInStatus;
	uint8	CEAChimeRqInStatus;
	uint8	DcChrgRqInStatus;
	uint8	PwrtrainDriveModeInStatus;
	uint8   ePRNDLInStatus;

	uint32  SigInValue;
	
	/*VOPS Variables*/
	GET_VOPS_OAT(&cf_opt_oat_status);
	GET_VOPS_OATSOURCE(&cf_opt_oat_source_status);
	GET_VOPS_CF_OPT_RUNNING_BOARD_CONTROL_FUNCTION(&cf_opt_running_board_control_function_status);
	GET_VOPS_OFFROADSCREEN(&cf_opt_offroadscreen_status);
	GET_VOPS_AUTOHOLD(&cf_opt_autohold_status);
	GET_VOPS_CF_OPT_TC_IVD_RSC(& cf_opt_tc_ivd_rsc_status); 
	GET_VOPS_ADAPTIVEHEADLAMPS(&cf_opt_adaptiveheadlamps_status);
	GET_VOPS_HIGHBEAMTELLTALESOURCE(&cf_opt_highbeamtelltalesource_status);
	GET_VOPS_CF_OPT_REVERSE_WARNING(&cf_opt_reverse_warning_status);
	GET_VOPS_CF_OPT_DEF_GAUGE_CONFIGURATION(&cf_opt_def_gauge_configuration_status);
	GET_VOPS_ENGINEAIRFILTERMINDER(&cf_opt_engineairfilterminder_status);
	GET_VOPS_CF_OPT_RUNNING_BOARD_CONTROL_FUNCTION(&cf_opt_running_board_control_function);
	GET_VOPS_ELSD(&cf_opt_elsd);
	GET_VOPS_CF_OPT_CHARGEPORTDOORAJARWARNINGCONFIGURATION(&cf_opt_ChargePortDoorAjarWarningConfiguration);
	GET_VOPS_POWERLIFTGATE(&cf_opt_powerliftgate);
	GET_VOPS_AUTOHIGHBEAMTELLTALE(&cf_opt_autohighbeamtelltale);
	GET_VOPS_CF_OPT_APPROACHING_VEHICLE_AUDIBLE_SYSTEM(& cf_opt_approaching_vehicle_audible_system_status);
	GET_VOPS_EPAS(&cf_opt_epas_status);
    GET_VOPS_TRAILERBACKUPASSIST(&cf_opt_trailerbackupassist_status);
	GET_VOPS_CF_OPT_PT_HYBRID_2(&cf_opt_pt_hybrid_2);
	GET_VOPS_AUTO_HIGH_BEAM_MENU(&cf_opt_auto_high_beam_menu);
	GET_VOPS_CERAMICBRAKEPADWEARINDICATOR(&cf_opt_CeramicBrakePadWearIndicator);
	GET_VOPS_ADVANCETRACE(&cf_opt_AdvanceTracHardButton);
	GET_VOPS_ADVANCETRACEHARDBUTTON(&cf_opt_AdvanceTrac);
	GET_VOPS_POWERLOCKCONTROLCONFIG(&cf_opt_powerlockcontrolconfig);
	GET_VOPS_POWERLOCKCONTROL(&cf_opt_powerlockcontrol);	
	GET_VOPS_POWERSLIDINGDOOR(&cf_opt_powerslidingdoor);
	GET_VOPS_TPMS(&cf_opt_tpms_status);
	GET_VOPS_CF_OPT_TRANS_TYPE(&cf_opt_trans_type_status);
	GET_VOPS_AUTOPARKWARNINGCONFIG(&cf_opt_Autopark_Warning_Configuration);
	GET_VOPS_BLINDSPOTASSISTWARNINGS(&cf_opt_BlindSpotAssistWarnings);
	GET_VOPS_CLEAREXITASSISTMENU(&cf_opt_ClearExitAssistMenu);
	GET_VOPS_TRAFFICSIGNRECOGNITION(&cf_opt_trafficsignrecognition_status);
	GET_VOPS_SLIF(&cf_opt_slif_status);
	GET_VOPS_TCM_PRESENT(&cf_opt_tcm_present);
	GET_VOPS_TRANSMISSIONFLUIDTEMPGAUGECONFIG(&cf_opt_TransmissionFluidTemperatureGaugeConfiguration);
	GET_VOPS_CF_OPT_DIESEL_ENGINE_CONFIG(&cf_opt_diesel_engine_config_status);
	GET_VOPS_EPRNDLE2ESIGNALPROTECTION(&cf_opt_ePRNDLe2eSignalProtection);
	
	/*CAN Signals*/
	
	GET_CAN_RX_OATINSTATUS(&SigInValue,&OatInStatus);
	GET_CAN_RX_RUNNINGBOARDSTATIN(&RunningBoardStatInValue,&RunningBoardStatInStatus); 
	GET_CAN_RX_POWERSYSTEMSTATUSIN(& SigInValue,& PowerSystemStatusInStatus); 
	GET_CAN_RX_STEERWHLANGLE2IN(&SigInValue,&SteerWhlAngle2InStatus);
	GET_CAN_RX_VEHPITCHANGLEIN(&SigInValue,&VehPitchAngleInStatus);
	GET_CAN_RX_VEHROLLANGLEIN(&SigInValue,&VehRollAngleInStatus);
	GET_CAN_RX_AUTOHOLDINDIN(&SigInValue,&AutoHoldIndInStatus);
	GET_CAN_RX_AUTOHOLDWARNIN(&SigInValue,&AutoHoldWarnInStatus);
	GET_CAN_RX_ESCOFFTTIN(& SigInValue,& ESCOffTTInStatus); 
	GET_CAN_RX_ADAPTHEADLAMPFAILIN(&SigInValue,&AdaptHeadlampFailInStatus);
	GET_CAN_RX_HIGHBEAMHCMIN(& SigInValue,& HighBeamHCMInStatus);
	GET_CAN_RX_CRUISECTRLSETSPDIN(&SigInValue,&CruiseCtrlSetSpdInStatus);
	GET_CAN_RX_CRUISEOVERRIDEIN(&SigInValue,&CruiseOverrideInStatus);
	GET_CAN_RX_CRUISECONTROLSTATIN(&SigInValue,&CruiseControlStatInStatus);
	GET_CAN_RX_UREALVLPCIN(&SigInValue,&UreaLvlPcInStatus);
	GET_CAN_RX_TRANSTEMPIN(&TransTempInValue,&TransTempInStatus);
	GET_CAN_RX_ENGAIRFILTERIN(&SigInValue,&EngAirFilterInStatus);
	GET_CAN_RX_GEARPOSIN(&SigInValue,&GearPosInStatus);
	GET_CAN_RX_POWERSTEPMSGIN(&SigInValue,&PowerStepMsgInStatus);
	GET_CAN_RX_SVCELSDIN(&SigInValue,&SvcELSDInStatus);
	GET_CAN_RX_PWRPACKREADYIN(&SigInValue,&PwrPackReadyIn);
	GET_CAN_RX_CHARGEPORTDOOROPENIN(&SigInValue,&ChargePortDoorOpenIn);
	GET_CAN_RX_PWRDRLGCHIMEIN(&SigInValue,&PwrDrLGChimeIn);
	GET_CAN_RX_POWERLIFTGATESTATIN(&SigInValue,&PowerLiftgateStatIn);
	GET_CAN_RX_AUTOHIGHBEAMSTATIN(&SigInValue,&AutoHighBeamStatIn);
	GET_CAN_RX_AUTOHIGHBEAMSCCMIN(&SigInValue,&AutoHighBeamSCCMIn);
	GET_CAN_RX_HIGHBEAMSCCMIN(&SigInValue,&HighBeamSCCMIn);
	GET_CAN_RX_PDSTRNALRTFALTIN(&SigInValue,& PdstrnAlrtFaltInStatus);
	GET_CAN_RX_EPASFAILUREIN(&SigInValue,&EPASFailureInStatus);
    GET_CAN_RX_TBATEXTIN(&SigInValue,&TBATextInStatus);
    GET_CAN_RX_TBAENABLEIN(&SigInValue,&TBAEnableInStatus);
	GET_CAN_RX_PARKLOCKTEXTIN(&SigInValue,&ParkLockTextIn);
	GET_CAN_RX_PARKLOCKAVAILIN(&SigInValue,&ParkLockAvailIn);
	GET_CAN_RX_OVERTEMPLAMPIN(&SigInValue,&OverTempLampInStatus);
	GET_CAN_RX_BRAKEPADOUTIN(&SigInValue,&BrakePadWearOutInStatus);
	GET_CAN_RX_DRVSLIPCTLMODEMSG(&SigInValue,&DrvSlipCtlModeMsgInStatus);
	GET_CAN_RX_SVCBATTTRACIN(&SigInValue,&SvcBattTracIn);
	GET_CAN_RX_TPMSTTIN(&TPMSTTInValue,&TPMSTTInStatus);
	GET_CAN_RX_SLIDINGDOORLEFTCHIMEIN(&SigInValue,&SlidingDoorLeftChimeInStatus);
	GET_CAN_RX_SLIDINGDOORRIGHTCHIMEIN(&SigInValue,&SlidingDoorRightChimeInStatus);
	GET_CAN_RX_APACHIMEIN(&SigInValue,&APAChimeInStatus);
	GET_CAN_RX_LCWAMSGIN(&SigInValue,&LCWAMsgInStatus);
	GET_CAN_RX_TSRREGIONIN(&SigInValue,&TSRRegionInStatus);
	GET_CAN_RX_CEAMSGTXRQ(&SigInValue,&CEAMsgTxRqInStatus);
	GET_CAN_RX_CEACHIMERQ(&SigInValue,&CEAChimeRqInStatus);
	GET_CAN_RX_DCCHRGRQIN(&SigInValue,&DcChrgRqInStatus);
	GET_CAN_RX_PWRTRAINDRIVEMODEIN(&SigInValue,&PwrtrainDriveModeInStatus);
	GET_CAN_RX_EPRNDLE2E(&SigInValue,&ePRNDLInStatus);

	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x20A, 0x470, 
	*                      No Update w/ TCM DTC
	*					   Trailer Brake Control Module
	*                      0xC40282
	*******************************************************************************/
	if(((eConfigStatus_Enabled == cf_opt_tcm_present)										&& 
	((PwrtrainDriveModeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 					|| //0x20A

	((eConfigStatus_Enabled == cf_opt_TransmissionFluidTemperatureGaugeConfiguration)		&& 
	((TransTempInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 							|| //0x470

	(((eConfigTransType_TransAutomatic == cf_opt_trans_type_status) 					&& 
	(eConfigStatus_Enabled == cf_opt_diesel_engine_config_status)						&&
	(eConfigStatus_Enabled == cf_opt_ePRNDLe2eSignalProtection))						&&
	((ePRNDLInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))       					 //0x171
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40282, eSetDTC);                
		}
	}
	else
	{                                                           
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40282, eClearDTC);     
	} 

	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x282
	*                      No Update w/ O-BCCM DTC
	*                      0xC57D82
	*******************************************************************************/
	if((eConfigPTHybrid2_BEV == cf_opt_pt_hybrid_2)		&& 
	   ((DcChrgRqInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) //0x282           
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC57D82, eSetDTC);                
		}
	}
	else
	{                                                           
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC57D82, eClearDTC);     
	} 

	/******************************************************************************
	* No Update w/ IPMA DTC
	* DTC Condition    -->Missing Signal on 0x3CA, 0x279
	*     0xC53B82
	* Allowed Power Mode - Run 
	******************************************************************************/
	if(((cf_opt_BlindSpotAssistWarnings == eConfigStatus_Enabled) 		&&
	((LCWAMsgInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))			|| //0x3CA

	((cf_opt_ClearExitAssistMenu == eConfigStatus_Enabled) 		&&
	(((CEAMsgTxRqInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)			|| //0x3CA
	((CEAChimeRqInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))))			   //0x3CA		
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53B82, eSetDTC);  	   // Log No Update w/ IPMA DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53B82, eClearDTC);		    // Clear No Update w/ IPMA DTC
	}

	/******************************************************************************
	* No Update w/ PAM DTC
	* DTC Condition    -->Missing Signal on 0x3A8
	*     0xC45A82
	* Allowed Power Mode - Run 
	******************************************************************************/
	if((cf_opt_Autopark_Warning_Configuration == eConfigStatus_Enabled) 		&&
	((APAChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))					//0x3A8
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC45A82, eSetDTC);  	   // Log No Update w/ PAM DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC45A82, eClearDTC);		    // Clear No Update w/ PAM DTC
	}
	
	/******************************************************************************
	* NoUpdate with ABS DTC
	* Invalid Data Received from Anti-Lock Brake System (ABS) Control Module "A"
	* DTC Condition    -->Missing Signal on 0x431, 0x46A, 0x76, 0x412
	*     0xC41582
	* Allowed Power Mode - Run 
	******************************************************************************/
	if(((cf_opt_offroadscreen_status == eConfigStatus_Enabled)       		&& 
	((SteerWhlAngle2InStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 		|| //0x76

	((VehPitchAngleInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)  		|| //0x412

	((VehRollAngleInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)	 		|| //0x412

	((cf_opt_autohold_status == eConfigStatus_Enabled) 					&&
	(((AutoHoldIndInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 		|| //0x431
	((AutoHoldWarnInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))  	|| //0x431

	(((eConfigTCI_IVD_RSC_IVD == cf_opt_tc_ivd_rsc_status)             		|| //0x2
	(eConfigTCI_IVD_RSC_RSC == cf_opt_tc_ivd_rsc_status))                   && //0x3
	((ESCOffTTInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))				|| //0x46A

	(((eConfigStatus_Enabled == cf_opt_AdvanceTracHardButton)            		&&
	(eConfigStatus_Disabled == cf_opt_AdvanceTrac))   							&&
	((DrvSlipCtlModeMsgInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))		|| //0x46A

	(((cf_opt_CeramicBrakePadWearIndicator == eConfigStatus_Enabled)			&&
	(BrakePadWearOutInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING)))		//0x46A
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41582, eSetDTC);  	   // Log NoUpdate with ABS DTC DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC41582, eClearDTC);		    // Clear NoUpdate with ABS DTC DTC
	}
	
	/******************************************************************************
	* NoUpdate with HVAC 
	* DTC Condition    -->Missing Signal on 0x3B3
	*     0xC42482
	* Allowed Power Mode - Run 
	******************************************************************************/
	if( ( cf_opt_oat_status == eConfigStatus_Enabled) && ( cf_opt_oat_source_status == eConfigOATSource_HVAC)	&& \
		(( OatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42482, eSetDTC);  	   // Log NoUpdate with HVAC DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42482, eClearDTC);		    // Clear NoUpdate with HVAC DTC
	}
	 
    /******************************************************************************
    * NoUpdate with FCIM DTC
    * DTC Condition    -->Missing Signal on 0x3B3
    *     0xC55782
	* Allowed Power Mode - Run 
    ******************************************************************************/
    if((cf_opt_oat_status == eConfigStatus_Enabled) 		&& 
	(cf_opt_oat_source_status == eConfigOATSource_FCIM)		&& 
    ((OatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC55782, eSetDTC);  	   // Log NoUpdate with FCIM DTC
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC55782, eClearDTC);		    // Clear NoUpdate with FCIM DTC
    }
	 
    /******************************************************************************
    * NoUpdate with BCM DTC
    * DTC Condition    --> Missing Signal on 0x38A, 0x42C
    * DTC - 0xC43182
	* Allowed Power Mode - Run 
    ******************************************************************************/
    if((((eConfigStatus_Enabled == cf_opt_powerlockcontrolconfig)||
	(eConfigStatus_Enabled == cf_opt_powerlockcontrol))  &&
	((ParkLockAvailIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)		||
	((ParkLockTextIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING))		||
	
	((PowerSystemStatusInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43182, eSetDTC);  	   // Log NoUpdate with BCM DTC
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43182, eClearDTC);		    // Clear NoUpdate with BCM DTC
    }
	 
	/******************************************************************************
	 * NoUpdate with HCM DTC
	 * DTC Condition    -->Missing Signal on 0x38A
	 *     0xC54282
	 * Allowed Power Mode - Run 
	 ******************************************************************************/
	if((( cf_opt_adaptiveheadlamps_status == eConfigStatus_Enabled) 		&& 
	((AdaptHeadlampFailInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 	|| //0x38A

	((cf_opt_highbeamtelltalesource_status == eConfigHighbeam2_HCM) 		&& 
	((HighBeamHCMInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))				//0x38A
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC54282, eSetDTC);  	    
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC54282, eClearDTC);		    
	}
	/******************************************************************************
	 * NoUpdate with ECM_PCM DTC
	 * DTC Condition    -->Missing Signal on 0x42C, 0x77, 0x108, 0x27A
	 *     
	 * Allowed Power Mode - Run 
	 ******************************************************************************/
	if(((CruiseCtrlSetSpdInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)   	|| //0x77
	((CruiseOverrideInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)     		|| //0x77
	((CruiseControlStatInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 		|| // Message 0x42C

	((eConfigTransType_TransAutomatic == cf_opt_trans_type_status)			    && 
	((GearPosInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))          		|| // Message 0x38A

	(((eConfigPTHybrid2_PHEV == cf_opt_pt_hybrid_2)								|| //0x3
	(eConfigPTHybrid2_BEV == cf_opt_pt_hybrid_2)								|| //0x1
	(eConfigPTHybrid2_FHEV == cf_opt_pt_hybrid_2)) 								&& //0x2
	((OverTempLampInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))    	  		|| //Message 0x108

	((cf_opt_engineairfilterminder_status == eConfigStatus_Enabled) 			&& \
	((EngAirFilterInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))				//0x27A
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40182, eSetDTC);  	   // Log ERC_INVLD_TPMS_DATA_FROM_SJB DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC40182, eClearDTC);		    // Clear ERC_INVLD_TPMS_DATA_FROM_SJB DTC
	}
	 
	/******************************************************************************
    * NoUpdate with RBM
    * DTC Condition    -->Missing Signal on 0x279
    *    
    ******************************************************************************/
    if((cf_opt_running_board_control_function == eConfigStatus_Enabled) && 
	((PowerStepMsgInStatus & eSIGNAL_MISSING) == eSIGNAL_MISSING))
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC54582, eSetDTC);  	   
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC54582, eClearDTC);		   
    } 
	
	/******************************************************************************
    * Running Board Misconfigured DTC
    * DTC Condition    -->Missing Signal on 0x38A, 0x4A5
    *    
    ******************************************************************************/
    if((cf_opt_running_board_control_function == eConfigStatus_Disabled) 	&& 
	((RunningBoardStatInValue == 0x1) 										||  //All_Enabled
	(RunningBoardStatInValue == 0x2)))											//Manually_Deployed
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC54556, eSetDTC);  	   
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC54556, eClearDTC);		   
    } 

	/******************************************************************************
	* NoUpdate with DCMR
	* Lost Communication With Differential Control Module - Rear
	* DTC Condition    --> Missing Signal on 0x46B
	* 0xC13682 
	******************************************************************************/
	if((cf_opt_elsd == eConfigStatus_Enabled) 						&&
	((SvcELSDInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))		//0x46B
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43782, eSetDTC);  	   
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC43782, eClearDTC);		   
	}

	/******************************************************************************
    * NoUpdate with HPCM DTC
    * DTC Condition    --> Missing Signal on 0x108, 0x422
    * 0xC29382 
    ******************************************************************************/
    if(((cf_opt_pt_hybrid_2 == eConfigPTHybrid2_BEV)			||
	(cf_opt_pt_hybrid_2 == eConfigPTHybrid2_PHEV)) 			&&
    (( PwrPackReadyIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 		||
	(( ChargePortDoorOpenIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING))
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
		    Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC29382, eSetDTC);  	   
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC29382, eClearDTC);		   
    }
	 
	/******************************************************************************
    * NoUpdate with RGTM DTC
    * DTC Condition    -->Missing Signal on 0x38A
    * 0xC53182 
    ******************************************************************************/
    if((cf_opt_powerliftgate == eConfigStatus_Enabled) 				&&
    (((PwrDrLGChimeIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 		|| //0x38A
	((PowerLiftgateStatIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))		//0x38A
    {
        if( dtc_rv_log_timer_expired != FALSE)
        {
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53182, eSetDTC);
        }
    }
    else
    {
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC53182, eClearDTC);		
    }
	 
	/******************************************************************************
	* 					NoUpdate with SCCM DTC ( Steering Column Control Module)
	* 					DTC Condition    -->Missing Signal on 0x46B
	* 					0xC42982 
	******************************************************************************/
	if((((cf_opt_autohighbeamtelltale == eConfigAutoHighbeam_SCCM) 				&&
	((cf_opt_auto_high_beam_menu	== eConfigAutoHBMenu_AutoHighBeams) 		|| 
	(cf_opt_auto_high_beam_menu	== eConfigAutoHBMenu_GlarefreeHighBeams) 		|| 
	(cf_opt_auto_high_beam_menu	== eConfigAutoHBMenu_AdaptiveDrivingBeams))) 	&&
	(( AutoHighBeamSCCMIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 				|| //0x46B
	
	((cf_opt_autohighbeamtelltale == eConfigAutoHighbeam_SCCM) 				    &&
	((HighBeamSCCMIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING)))			           //0x46B
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42982, eSetDTC);  	   
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42982, eClearDTC);		   
	}
	 
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x431
	*                      No Update w/ PACM DTC
	*                      0xC13F82
	*******************************************************************************/
	if((eConfigStatus_Enabled == cf_opt_approaching_vehicle_audible_system_status)               && 
	((PdstrnAlrtFaltInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))            
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC13F82, eSetDTC);       // Log ERC_NO_UPDATE_PACM_DTC
		}
	}
	else
	{                                                           
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC13F82, eClearDTC);     // Clear ERC_NO_UPDATE_PACM_DTC
	}
		
	/******************************************************************************
	* 		NoUpdate with PSCM DTC
	* 		DTC Condition    -->Missing Signal on 0x77, 0x281
	* 							0xC42082    
	* 		Allowed Power Mode - Run 
	******************************************************************************/
	if(((cf_opt_epas_status == eConfigStatus_Enabled) 					&& 
	((EPASFailureInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING)) 		/*|| 

	((cf_opt_trailerbackupassist_status == eConfigStatus_Enabled) 		&&
	((TBATextInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING) 			|| 
	((TBAEnableInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))*/)
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42082, eSetDTC);        // Log ERC_INVLD_TPMS_DATA_FROM_SJB DTC
		}
	}
	else
	{
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42082, eClearDTC);            // Clear ERC_INVLD_TPMS_DATA_FROM_SJB DTC
	}
	 
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x42C
	*					   No Update With Battery Charger Control Module "A"
	*                      No Update w/ BCCM DTC
	*                      0xC19B82
	*******************************************************************************/
	if(((eConfigPTHybrid2_PHEV == cf_opt_pt_hybrid_2)				|| //0x3
	(eConfigPTHybrid2_BEV == cf_opt_pt_hybrid_2))					&& //0x1
	((SvcBattTracIn  & eSIGNAL_MISSING) == eSIGNAL_MISSING))    	//0x42c       
	{
	   if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC49C82, eSetDTC);       
		}
	}
	else
	{   
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC49C82, eClearDTC);     
	}
	
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x282
	*                      No Update w/ DCMG DTC (Door Control Module G)
	*                      0xC20582
	*******************************************************************************/
	if(((eConfigPowerSlidingDoor_LeftPSD == cf_opt_powerslidingdoor)				||
	(eConfigPowerSlidingDoor_LeftAndRightPSD == cf_opt_powerslidingdoor))			&& 
	((SlidingDoorLeftChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))			 //0x282
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC20582, eSetDTC);       
		}
	}
	else
	{                                                           
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC20582, eClearDTC);     
	}
	
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x282
	*                      No Update w/ DCMH DTC (Door Control Module H)
	*                      0xC20B82
	*******************************************************************************/
	if(((eConfigPowerSlidingDoor_RightPSD == cf_opt_powerslidingdoor)				||
	(eConfigPowerSlidingDoor_LeftAndRightPSD == cf_opt_powerslidingdoor))			&& 
	((SlidingDoorRightChimeInStatus  & eSIGNAL_MISSING) == eSIGNAL_MISSING))			 //0x282
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC20B82, eSetDTC);       
		}
	}
	else
	{                                                           
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC20B82, eClearDTC);     
	}
	
	/******************************************************************************
	* DTC Condition    --> 1) Missing message on 0x3B4
	*                      No Update w/ BCM DTC (Body Control Module)
	*					   No Update w/ SJB TPMS DTC 
	*                      0xC42282
	*******************************************************************************/
	if((cf_opt_tpms_status == eConfigStatus_Enabled) 				&& 
	(((TPMSTTInStatus  & eSIGNAL_INVALID) == eSIGNAL_INVALID)		||
	(TPMSTTInValue  == 0x03)))		//0x3B4
	{
		if( dtc_rv_log_timer_expired != FALSE)
		{
			Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42282, eSetDTC);       
		}
	}
	else
	{                                                           
		Rte_Call_rpCS_Diagnostics_Service_DTCOperation( 0xC42282, eClearDTC);     
	}	
}


/* Diagnostic Service $14: Clear DTC callback 
   Clear the missing flags
   Restart the missing timers
*/

void ClearDTCTimers(void)
{

	 dtc_ov_log_timer = 0;
	 dtc_ov_log_timer_expired = FALSE;

	 dtc_rv_log_timer = 0;
	 dtc_rv_log_timer_expired = FALSE;

	 dtc_rv_log_timer = 0;
	 dtc_rv_log_timer_expired = FALSE;

	 dtc_rsv_log_timer = 0;
   	 dtc_rsv_log_timer_expired = FALSE;
}

#endif
#endif

#endif
