//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2020] Visteon Corporation
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
//--------------------------------------------------------------------------------------------------------------------
#include "DmnMgr_Main.h"
#include "DmnMgr_MonitorDmn.h"
#include "DmnMgr_ControlDmn.h"
#include "DmnMgr_PublishDmnStatus.h"

#define DMNMGR_START_SEC_VAR_NO_INIT_ASIL_B_8
#include "MemMap.h"

static SDmnRunTimeStatus DmnMgrStatus[MANAGED_DOMAINS_CNT];
#ifdef DMNMGR_MULTIDOMIANS_ENABLE
static SPowerSystemState domainsystemstate;
#endif

#define DMNMGR_STOP_SEC_VAR_NO_INIT_ASIL_B_8
#include "MemMap.h"


#define DMNMGR_START_SEC_CODE_ASIL_B
#include "MemMap.h"

#if 0
static void DmnMgr_MonitorDmnThermalState(void);
#endif
static EDomainId DmnMgr_MonitorGetDomainIdPostIdxCheck(EDomainId dmnId);

#ifdef DNMMGR_UCL_WAKEUP_INTERIM_FIX
static uint8 DmnMgrLinkStatus = 0;
#endif

DmnMgr_ReturnType DmnMgr_ResetDmnRunTimeStatus(EDomainId dmnId)
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	//cert_int30_c vioation fix - wrap around check added.
	EDomainId domainID = DmnMgr_MonitorGetDomainIdPostIdxCheck(dmnId);
	SDmnRunTimeStatus *pDmnSts = NULL;
	
	/* Coverity warning fix - Added a check before accessing array index */
	if(domainID < MANAGED_DOMAINS_CNT)
	{
		pDmnSts = &DmnMgrStatus[domainID];

		pDmnSts->dmnId = dmnId;
					
		//UCL Related Configurations
		pDmnSts->isFirstLinkUpRcvd = FALSE;
		pDmnSts->dmnUclLinkState = EUclLinkState_Not_Rcvd;
		pDmnSts->dmnUclFatalErrorRcvd = 0;

		//Domain System State Related Configuration
		pDmnSts->dmnCurSystemState = UNKNOWN;
		pDmnSts->dmnReqSystemState = EDmnChangeReqStatus_NoReq;
		pDmnSts->dmnStateChangeReqStatus = UNKNOWN;

		//Domain HB Related Configuration
		pDmnSts->dmnHBMissCount = 0u;
		#ifdef DMNMGR_HEALTHEVENT
		DmnMgr_HBMissCountInfo(pDmnSts->dmnHBMissCount);
		#endif
		pDmnSts->dmnLastSeqCount = 0u;
		pDmnSts->dmnHBLastRcvTime = 0u;

		// Various Domain States
		pDmnSts->dmnLastRstReason = UNKNOWN;
		pDmnSts->dmnHealthState = UNKNOWN;//
		#ifdef DMNMGR_FATALERROR_APPLICATION_NOTIFICATION
		pDmnSts->compldx = UNKNOWN;//
		#endif
		pDmnSts->dmnThermalState = UNKNOWN;
		pDmnSts->dmnStatus = DMN_NOT_READY;

		//Domain Manager Timing Configurations
		pDmnSts->dmnExtendShutDownTimeMs = 0u;
		pDmnSts->dmnKeepSystemAwakeMs = 0u;
		pDmnSts->dmnShutDownWaitTime = 0u;
		pDmnSts->dmnSystemAwakeWaitTime = 0u;
		pDmnSts->dmnUpWaitTime = 0u;

		//Domain Manager Statistics
		pDmnSts->ErrStatus.linkUpbfrDownErrCnt = 0u;
		pDmnSts->ErrStatus.linkDownbfrUpErrCnt = 0u;
		pDmnSts->ErrStatus.invalidLinkStatus = 0;
		pDmnSts->ErrStatus.dmnFirstLinkUpExpiry = 0u;
		pDmnSts->ErrStatus.dmnFirstHBExpiry = 0u;

		//Publish all the status to RTE
		(void)DmnMgr_SetDmnInfo_dmnId(&(pDmnSts->dmnId)); 
		(void)DmnMgr_PublishUclLinkStatus(pDmnSts->dmnId);
		(void)DmnMgr_PublishUclFatatError(pDmnSts->dmnId);
		(void)DmnMgr_PublishDmnSystemState(pDmnSts->dmnId);
		(void)DmnMgr_PublishDmnHealthStaus(pDmnSts->dmnId);
		(void)DmnMgr_PublishDmnThermalState(pDmnSts->dmnId);
		
		#ifdef DNMMGR_UCL_WAKEUP_INTERIM_FIX
		if(DmnMgrLinkStatus == 0xA5)
		{
			DmnMgr_LinkStatusChanged(0,-50u);
		}
		#endif

		ret = DMNMGR_E_OK;
	}

	return ret;
}

DmnMgr_ReturnType DmnMgr_GetDmnRunTimeStatus( EDomainId dmnId, SDmnRunTimeStatus **pDmnSts)
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	EDomainId domainID;

	if( pDmnSts != NULL )
	{
		domainID = DmnMgr_MonitorGetDomainIdPostIdxCheck(dmnId);
		
		/* Coverity warning fix - Added a check before accessing array index */
		if( domainID < MANAGED_DOMAINS_CNT )
		{
			*pDmnSts = &DmnMgrStatus[domainID];
			ret = DMNMGR_E_OK;
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DkMsgPowerExtendShutdownTime
//---------------------------------------------------------------------------------------------------------------------
void DmnMgr_MonitorDmnExtendShutdownTime(void)
{
	SPowerExtendShutdownTime extShtTime = {0U};
	uint8 idx;
	
	 if((Std_ReturnType)E_OK == Rte_Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&extShtTime))
	 {
		 if((extShtTime.domainId  > EDomainId_VP) && (extShtTime.domainId <= MANAGED_DOMAINS_CNT))
		 {
			 idx = extShtTime.domainId - 1u;
			//Update the respective DmnMgrStatus database
			DmnMgrStatus[idx].dmnExtendShutDownTimeMs = extShtTime.timeoutMs;
			DmnMgrStatus[idx].dmnShutDownWaitTime = extShtTime.timeoutMs;
		 }
	 }
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DkMsgPowerKeepSystemAwake
//---------------------------------------------------------------------------------------------------------------------
void DmnMgr_MonitorDmnKeepSystemAwake(void)
{
	SPowerKeepSystemAwake sysAwkTime = {0U};
	uint8 idx;
	
	if((Std_ReturnType)E_OK == Rte_Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&sysAwkTime))
	{
		if((sysAwkTime.domainId > EDomainId_VP) && (sysAwkTime.domainId <= MANAGED_DOMAINS_CNT))
		{
			idx = sysAwkTime.domainId-1u;  

			//Update the respective DmnMgrStatus database
			DmnMgrStatus[idx].dmnKeepSystemAwakeMs = sysAwkTime.timeoutMs;
			DmnMgrStatus[idx].dmnSystemAwakeWaitTime = sysAwkTime.timeoutMs;
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DkMsgPowerSystemState
//---------------------------------------------------------------------------------------------------------------------
void DmnMgr_MonitorDmnPowerSystemState(void)
{
	SPowerSystemState dmnSysState = {0U};
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	uint8 idx = 0u; //Initialized to remove compiler warning
	
	if((Std_ReturnType)E_OK == Rte_Read_rSR_PowerSystemState_PowerSystemStateData(&dmnSysState))
	{
		//Validate Received dmnSysState.domainId 
		if((dmnSysState.domainId  > EDomainId_VP) && (dmnSysState.domainId <= MANAGED_DOMAINS_CNT))
		{
			ret = DMNMGR_E_OK;
			idx = dmnSysState.domainId-1U;
			#ifdef DMNMGR_MULTIDOMIANS_ENABLE
			domainsystemstate = dmnSysState;
			#endif
		}
	}
	
	/* Coverity warning fix - Added a check before accessing array index */
	//Validate Received dmnSysState.state		
	if((ret == DMNMGR_E_OK) && ( dmnSysState.state < ESystemState_Last) && ( idx < MANAGED_DOMAINS_CNT ))
	{
		//Update the respective DmnMgrStatus database
		DmnMgrStatus[idx].dmnCurSystemState = dmnSysState.state;
		
		//If there is any Pending System State change request then update the request status
		if(DmnMgrStatus[idx].dmnReqSystemState == DmnMgrStatus[idx].dmnCurSystemState)
		{
			DmnMgrStatus[idx].dmnStateChangeReqStatus = EDmnChangeReqStatus_ReqSucceed;
			
			//Stop the shutdown timer if shutdown request is pending
			if(DmnMgrStatus[idx].dmnReqSystemState == ESystemState_Shutdown)
			{
				DmnMgrStatus[idx].dmnShutDownWaitTime = 0;
			}
			
			DmnMgrStatus[idx].dmnReqSystemState = EDmnChangeReqStatus_NoReq;
		}
		
		//Update Overall Domain status
		DmnMgr_ConsolidatedDmnStatus(dmnSysState.domainId);
		
		//Publish the Domain System State
		(void)DmnMgr_PublishDmnSystemState(dmnSysState.domainId);
	}
	else
	{
		//Do Nothing
	}
}

#ifdef DMNMGR_MULTIDOMIANS_ENABLE
void DmnMgr_Domainsystemstate(SPowerSystemState *systemstates)
{

	*systemstates = domainsystemstate;
}
#endif

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated
//---------------------------------------------------------------------------------------------------------------------
/*
static void HSM_DmnMgr_SystemChangeResponse(ESystemState Response)
{
	HSM Domain Callback to update the state in VIP
}
*/
//---------------------------------------------------------------------------------------------------------------------
void HSM_DmnMgr_SystemChangeResponse(ESystemState Response)
{
	uint8 idx = 0u; //Initialized to remove compiler warning
	SPowerSystemState dmnSysState = {0U};
	if(Response == E_OK)
	{
		idx = EDomainId_HSM - 1;
		dmnSysState.domainId = EDomainId_HSM;
		dmnSysState.state = ESystemState_Shutdown;

		//Update the respective DmnMgrStatus database
		DmnMgrStatus[idx].dmnCurSystemState = dmnSysState.state;

		//If there is any Pending System State change request then update the request status
		if(DmnMgrStatus[idx].dmnReqSystemState == DmnMgrStatus[idx].dmnCurSystemState)
		{
			DmnMgrStatus[idx].dmnStateChangeReqStatus = EDmnChangeReqStatus_ReqSucceed;
			
			//Stop the shutdown timer if shutdown request is pending
			if(DmnMgrStatus[idx].dmnReqSystemState == ESystemState_Shutdown)
			{
				DmnMgrStatus[idx].dmnShutDownWaitTime = 0;
				dmnSysState.state = ESystemState_PrepareShutdown;
				DmnMgrStatus[idx].dmnCurSystemState = dmnSysState.state;
			}
			
			DmnMgrStatus[idx].dmnReqSystemState = EDmnChangeReqStatus_NoReq;
		}
		//Update Overall Domain status
		DmnMgr_ConsolidatedDmnStatus(dmnSysState.domainId);
		
		//Publish the Domain System State
		(void)DmnMgr_PublishDmnSystemState(dmnSysState.domainId);

	}
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated
//---------------------------------------------------------------------------------------------------------------------
/*
static void DM_DmnMgr_SystemChangeResponse(ESystemState Response)
{
	DM Domain Callback to update the state in VIP
}
*/
void DM_DmnMgr_SystemChangeResponse(ESystemState Response)
{
	uint8 idx = 0u; //Initialized to remove compiler warning
	SPowerSystemState dmnSysState = {0U};
	if(Response == E_OK)
	{
		idx = EDomainId_DM - 1;
		dmnSysState.domainId = EDomainId_DM;
		dmnSysState.state = ESystemState_Shutdown;

		//Update the respective DmnMgrStatus database
		DmnMgrStatus[idx].dmnCurSystemState = dmnSysState.state;

		//If there is any Pending System State change request then update the request status
		if(DmnMgrStatus[idx].dmnReqSystemState == DmnMgrStatus[idx].dmnCurSystemState)
		{
			DmnMgrStatus[idx].dmnStateChangeReqStatus = EDmnChangeReqStatus_ReqSucceed;
			
			//Stop the shutdown timer if shutdown request is pending
			if(DmnMgrStatus[idx].dmnReqSystemState == ESystemState_Shutdown)
			{
				DmnMgrStatus[idx].dmnShutDownWaitTime = 0;
				dmnSysState.state = ESystemState_PrepareShutdown;
				DmnMgrStatus[idx].dmnCurSystemState = dmnSysState.state;
			}
			
			DmnMgrStatus[idx].dmnReqSystemState = EDmnChangeReqStatus_NoReq;
		}
		//Update Overall Domain status
		DmnMgr_ConsolidatedDmnStatus(dmnSysState.domainId);
		
		//Publish the Domain System State
		(void)DmnMgr_PublishDmnSystemState(dmnSysState.domainId);

		
	}
}
//---------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DkMsgHealthHeartbeat
//---------------------------------------------------------------------------------------------------------------------
DmnMgr_TimerType DmnMgr_Timer[20];
DmnMgr_TimerType DmnMgr_Timer[] = {0};
uint8 DmnTimer_Idx = 0;
void  DmnMgr_MonitorDmnHeartBeat(void)
{
	SHealthDomainHeartbeat dmnHeartBeat = {0U};
	DmnMgr_ReturnType ret = 0xff;
	const SDmnMgrUsrCfgList *pCfg = NULL;
	uint32 lastSeqCnt;
	uint32 alwdSeqDeviation; // ReadMe_Cfg:Make sure to have minimum configuration of this value as 1 in cfg & Write a configuration validate function in DmnMgr_Main to valid all the input Configuration and raise a DET error immediately
	uint8 idx;
	uint32 ticks;
	uint32 totalSeqCnt;
		
	if((Std_ReturnType)E_OK == Rte_Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&dmnHeartBeat))
	{ 
		//Validate Received dmnSysState.domainId 
		DmnTimer_Idx = (DmnTimer_Idx<20)?DmnTimer_Idx+1:0;
		DMNMGR_GET_SYSTEM_TIMER(&DmnMgr_Timer[DmnTimer_Idx].CurrentTime);
		if((dmnHeartBeat.domainId  > EDomainId_VP) && (dmnHeartBeat.domainId <= MANAGED_DOMAINS_CNT))
		{
			ret = DMNMGR_E_OK;
			idx = dmnHeartBeat.domainId-1u;
		}
		else
		{
			//Do Nothing
		}
		
	}
	
	//Validate Received dmnSysState.state		
	if(ret == DMNMGR_E_OK)
	{
		ret = DmnMgr_MainGetDmnUsrCfg( dmnHeartBeat.domainId, &pCfg );

		if( ( ret == DMNMGR_E_OK) && ( pCfg != NULL ) )
		{
			lastSeqCnt = DmnMgrStatus[idx].dmnLastSeqCount;
			alwdSeqDeviation = pCfg->dmnSeqCntrDeviation;
			
			//If this is the first HB from Domain stop dmnUpWaitTime timer & make Health status as health Active
			if( DmnMgrStatus[idx].dmnHBLastRcvTime == 0u )
			{
				//Stop the dmnUpWaitTime Timer
				DmnMgrStatus[idx].dmnUpWaitTime = 0;

				//Update Domain Health Status
				DmnMgrStatus[idx].dmnHealthState = EDmnHealth_Active;
				//Verify if first Sequence Count from Domain is 0
				if ( dmnHeartBeat.seqCnt != 0u )
				{
					DmnMgrStatus[idx].ErrStatus.RcvdInvalidSeqCnt++;
				}
				else
				{
					//Do Nothing
				}
			}
			//Verify if subsequent sequence counter values are valid
			else
			{
				//cert_int30_c vioation fix - wrap around check added.
				if( ( UINT32_MAX_VALUE - lastSeqCnt ) >  alwdSeqDeviation )
				{
					totalSeqCnt = lastSeqCnt + alwdSeqDeviation;
				}
				else
				{
					//Wrap around Error. Set max value.
					totalSeqCnt = UINT32_MAX_VALUE;
				}
				
				//If Received Sequence Count > than allowed Deviation then Initiate Domain Reset
				if (( dmnHeartBeat.seqCnt > 0u ) && ( (uint32)(dmnHeartBeat.seqCnt) > (totalSeqCnt)))
				{
					DmnMgrStatus[idx].ErrStatus.RcvdInvalidSeqCnt++;
					/* NOTE: Please enable DMNMGR_E_NOK handle below if below line is uncommented. */
					#if 0
					ret = DMNMGR_E_NOK;
					#endif
				}
				else{
					//Do Nothing
				}
			}

			//Update the respective DmnMgrStatus database
			ticks = DmnMgr_MainGetElapsedTicks();
			
			DmnMgrStatus[idx].dmnHBLastRcvTime = ( ticks * DMNMGR_TASK_PERIOD_MS); 
			
			DmnMgrStatus[idx].dmnLastSeqCount = (uint32)(dmnHeartBeat.seqCnt);
			
			DmnMgrStatus[idx].dmnHBMissCount = 0u;
			#ifdef DMNMGR_HEALTHEVENT
			DmnMgr_HBMissCountInfo(DmnMgrStatus[idx].dmnHBMissCount);
			#endif
			#if 0	/* NOTE: Please enable this DMNMGR_E_NOK handle if ret = DMNMGR_E_NOK; statement above is uncommented. */
			if( DMNMGR_E_NOK == ret )
			{
				//Update Domain Health Status
				DmnMgrStatus[idx].dmnHealthState = EDmnHealth_Rcvd_Inv_SeqCnt;

				//Initiate Domain Recovery
				(void)DmnMgr_DmnCtrlResetDmn(dmnHeartBeat.domainId);/*5.1.4-17*/

				#ifdef HEALTHLOGGING_ENABLE
				/* Report the fault to HealthLog */
				DmnMgr_ControlDmnSaveHealthReport(dmnHeartBeat.domainId, EDmnHealth_Rcvd_Inv_SeqCnt);
				#endif
			}
			else{
					//Do Nothing
			}
			#endif
			//Update Overall Domain status
	  	    DmnMgr_ConsolidatedDmnStatus(dmnHeartBeat.domainId);

			//Publish the health status of the Domain
			(void)DmnMgr_PublishDmnHealthStaus(dmnHeartBeat.domainId);

		}

	}
	else
	{
				//Do Nothing
	}
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DkMsgHealthFatalError
//---------------------------------------------------------------------------------------------------------------------
void DmnMgr_MonitorDmnHealthFatalError(void)
{
	SHealthDomainFatalError dmnHealthFatalErr = {0U};
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	uint8 idx;
	if((Std_ReturnType)E_OK == Rte_Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData(&dmnHealthFatalErr))
	{
		//Validate Received dmnSysState.domainId 
		if((dmnHealthFatalErr.domainId  > 0u) && (dmnHealthFatalErr.domainId <= MANAGED_DOMAINS_CNT))
		{
			ret = DMNMGR_E_OK;
			idx = dmnHealthFatalErr.domainId-1u;
		}
	}
	
	//Validate Received dmnSysState.state		
	if(ret == DMNMGR_E_OK)
	{

		//Update the respective DmnMgrStatus database
		DmnMgrStatus[idx].dmnHealthState = EDmnHealth_Fatal_Error;
		#ifdef DMNMGR_FATALERROR_APPLICATION_NOTIFICATION
        DmnMgrStatus[idx].compldx = dmnHealthFatalErr.compldx;
		#endif
		//Update Overall Domain status
		DmnMgr_ConsolidatedDmnStatus(dmnHealthFatalErr.domainId);
		
		//Publish the health fatal error of the Domain
		(void)DmnMgr_PublishDmnHealthStaus(dmnHealthFatalErr.domainId);
		#ifndef DMNMGR_HEALTHEVENT
		//Initiate Doamin Recovery
		(void)DmnMgr_DmnCtrlResetDmn(dmnHealthFatalErr.domainId, DMNMGR_GIP_HEALTH_FATAL_ERROR);
		#else
		DmnMgr_FatalErrorInfo();
		#endif
		#ifdef HEALTHLOGGING_ENABLE
		#ifdef DMNMGR_FATAL_ERROR_AUX_DATA_LOG
		DmnMgr_ControlDmnSetCompldx(dmnHealthFatalErr.compldx);
		#endif
		/* Report the fault to HealthLog */
		DmnMgr_ControlDmnSaveHealthReport(dmnHealthFatalErr.domainId, EDmnHealth_Fatal_Error);
		#endif
	}
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message DkMsgThermalSystemStatus
//---------------------------------------------------------------------------------------------------------------------
/*
static void DmnMgr_MonitorDmnThermalState(void)
{
	Rte_Receive_rSR_Ucl_DkMsgThermalSystemStatus
	
	Update the respective DmnMgrStatus database
	
	Publish the Thermal State Change of the Domain
}
*/
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message HealthDumpData
//---------------------------------------------------------------------------------------------------------------------
void DmnMgr_MonitorDmnHealthDumpData(void)
{
	
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message HealthDumpHdrInfo
//---------------------------------------------------------------------------------------------------------------------
void DmnMgr_MonitorDmnHealthDumpHdrInfo(void)
{
	
}

void DmnMgr_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
{
	(void)DLInst;/*Added to avoid warning*/

	/* No need to change dmnHealthState & dmnUclFatalErrorRcvd for UCL_E_DATA_LOSS (-52) */
	if( DMNMGR_UCL_E_DATA_LOSS != ErrorCode )
	{
		//Update the respective DmnMgrStatus database
		DmnMgrStatus[EDomainId_Cluster-1U].dmnUclFatalErrorRcvd = ErrorCode;
		
		//Update the respective DmnMgrStatus database
		DmnMgrStatus[EDomainId_Cluster-1U].dmnHealthState = EDmnHealth_UCL_Fatal_Error;
		
		//Update Overall Domain status
		DmnMgr_ConsolidatedDmnStatus(EDomainId_Cluster);
		
		//Publish UCL Fatal Error 
		(void)DmnMgr_PublishUclFatatError(EDomainId_Cluster);
		
		//Initiate Domain Recovery: Not applicable for programs based upon Ford S2.8
	}
	else
	{
		/* Do nothing */
	}

	#ifdef HEALTHLOGGING_ENABLE
	/* Report the fault to HealthLog */
	DmnMgr_ControlDmnSaveHealthReport(EDomainId_Cluster, EDmnHealth_UCL_Fatal_Error);
	#endif
}

void DmnMgr_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
{
	(void)DLInst;/*Added to avoid warning*/
	uint8 idx = EDomainId_Cluster-1u; //To do : needs to revisit incase of any domain added
	
	//Update the respective DmnMgrStatus database
	if( Status == -50 )//Link Up
	{
		if( DmnMgrStatus[idx].dmnUclLinkState != EUclLinkState_Down )
		{
			DmnMgrStatus[idx].ErrStatus.linkUpbfrDownErrCnt++;
		}
		
		if( DmnMgrStatus[idx].isFirstLinkUpRcvd != TRUE )
		{ 
			DmnMgrStatus[idx].isFirstLinkUpRcvd = TRUE;
			//Restart the dmnUpWaitTime Timer to monitor time for first heartbeat after linkup.
			// The first HB should be received within dmnTimeForFirstHBMs(configured in cfg) after receiving first link up.
			DmnMgrStatus[idx].dmnUpWaitTime = 0;			
		}
		if(DmnMgrStatus[idx].dmnHealthState == UNKNOWN)
		{
		DmnMgrStatus[idx].dmnHealthState = EDmnHealth_Active;
		}
		
		DmnMgrStatus[idx].dmnUclLinkState = EUclLinkState_Up;
		#ifdef DNMMGR_UCL_WAKEUP_INTERIM_FIX
		DmnMgrLinkStatus = 0xA5;
		#endif	
	}
	else if( Status == -51 )//Link Down
	{
		if( DmnMgrStatus[idx].dmnUclLinkState != EUclLinkState_Up )
		{
			DmnMgrStatus[idx].ErrStatus.linkDownbfrUpErrCnt++;
		}
		
		DmnMgrStatus[idx].dmnUclLinkState = EUclLinkState_Down;
		#ifdef DNMMGR_UCL_WAKEUP_INTERIM_FIX
		DmnMgrLinkStatus = 0;
		#endif
		
	}
	else{
		DmnMgrStatus[idx].ErrStatus.invalidLinkStatus = Status;
	}
	
	//Find Overall Domain status
	DmnMgr_ConsolidatedDmnStatus(DmnMgrStatus[idx].dmnId);

    //Publish the health status of the Domain
	(void)DmnMgr_PublishDmnHealthStaus(DmnMgrStatus[idx].dmnId);
			
	//Publish The Link Status Changed Notification
	(void)DmnMgr_PublishUclLinkStatus((EDomainId)(idx+(uint8)1));
}

void DmnMgr_ConsolidatedDmnStatus(EDomainId dmnId)
{
	uint8 idx = dmnId - (uint8)1;
	if(idx<MANAGED_DOMAINS_CNT)
	{
		#ifndef DMNMGR_MULTIDOMIANS_ENABLE                                 /* multiple domain handling is not enabled */
		if((DmnMgrStatus[idx].dmnUclLinkState == EUclLinkState_Down) ||
		(DmnMgrStatus[idx].dmnUclFatalErrorRcvd == (sint32)-7 ) ||
		(DmnMgrStatus[idx].dmnHealthState != EDmnHealth_Active)||
		(DmnMgrStatus[idx].dmnCurSystemState == ESystemState_Off) || 
		(DmnMgrStatus[idx].dmnCurSystemState == ESystemState_PrepareShutdown) ||
		(DmnMgrStatus[idx].dmnCurSystemState == ESystemState_Shutdown))
		{
			DmnMgrStatus[idx].dmnStatus = DMN_NOT_READY;
		}
		else
		{
			DmnMgrStatus[idx].dmnStatus = DMN_READY;
		}
		#else                                    /* multiple domain handling is enabled */
			DmnMgrStatus[idx].dmnStatus = DMN_READY;    /*workaround untill dmnmgr issues when multiple domains enabled are fixed  */        
		#endif
	}
		
}

static EDomainId DmnMgr_MonitorGetDomainIdPostIdxCheck(EDomainId dmnId)
{
	EDomainId retVal = 0u;
	
	if(dmnId > 0u)
	{
		//Valid dmnId. No unsigned int wrap around.
		retVal = dmnId - (EDomainId)1;
	}
	else
	{
		//Invalid dmnId.
	}
	
	return retVal;
}

#define DMNMGR_STOP_SEC_CODE_ASIL_B
#include "MemMap.h"

