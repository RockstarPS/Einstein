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
//#include "ModeAppLib.h"/*3.3-4*/
#include "Rte_DmnMgr_stubs.h"
#include "DmnMgr_PublishDmnStatus.h"
#include "CmpLib.h"

CMPLIB_INSTANCE(DmnMgr)

#define DMNMGR_START_SEC_VAR_NO_INIT_ASIL_B_8
#include "MemMap.h"
static SCmnDmnStatus cmnDmnStatus;
#define DMNMGR_STOP_SEC_VAR_NO_INIT_ASIL_B_8
#include "MemMap.h"

#define DMNMGR_START_SEC_VAR_INIT_ASIL_B_8
#include "MemMap.h"
static const SDmnMgrUsrCfg *pDmnUsrCfg = NULL;
#define DMNMGR_STOP_SEC_VAR_INIT_ASIL_B_8
#include "MemMap.h"

static boolean DmnMgr_DmnShutdownReqSent;
static boolean GIP_Dmn_ShutdownComplete;
static boolean HSM_Dmn_ShutdownComplete;
static boolean DM_Dmn_ShutdownComplete;
static uint32 ShutDown_Fixed_Couter_StartTime_GP;
static uint32 ShutDown_Fixed_Couter_EndTime_GP;
static uint32 ShutDown_Fixed_Couter_StartTime_HSM;
static uint32 ShutDown_Fixed_Couter_EndTime_HSM;
static uint32 ShutDown_Fixed_Couter_StartTime_DM;
static uint32 ShutDown_Fixed_Couter_EndTime_DM;
static uint32 CoreShutdownFailsafeTimeStarted;
static uint32 CoreShutdownFailsafeTimeExpered;

#define DMNMGR_START_SEC_CODE_ASIL_B
#include "MemMap.h"

static Std_ReturnType CmpInit(void);
static Std_ReturnType CmpDeInit(void);
static Std_ReturnType CmpActivation(void);
static Std_ReturnType CmpDeActivation(void);
static Std_ReturnType CmpActive(void);
static void Domain_initconfigurations(void);

static void DmnMgrProcessEvents(void);
static void DmnMgr_MainCheckForFirstHB(EDomainId dmnId, const SDmnMgrUsrCfgList *pCfg);
static void DmnMgr_MainCheckForHBMiss(EDomainId dmnId, const SDmnMgrUsrCfgList *pCfg);
static void DmnMgr_MainCheckForFirstLinkUp(EDomainId dmnId);
static void DmnMgr_MainCheckIfDmnShutRequested(EDomainId dmnId );
static void DmnMgr_MainCheckIfDmnWakeUpRequested(EDomainId dmnId );
static EDomainId DmnMgr_MainGetDomainIdPostIdxCheck(EDomainId dmnId);
Std_ReturnType DmnMgr_CoreDmnShutdownRequest(void);
#ifdef DMNMGR_STOPVARREST_STARTDMNMONITOR_UCL_SYCN
boolean b_DmnMgr_StopVarReset = FALSE;
#endif

static void Domain_initconfigurations(void)
{
	EDomainId uDmnId = 0;
	const SDmnMgrUsrCfg *pDmnMgrUsrCfg;

	pDmnMgrUsrCfg = DmnMgr_UserConfigurations();

	//Get the Domain Configurations from DmnMgr_Cfg
	if(pDmnMgrUsrCfg != NULL)
	{
		pDmnUsrCfg = pDmnMgrUsrCfg;

		//Initialize Domain RunTime Parameters
		for(uDmnId = EDomainId_Cluster; uDmnId <= MANAGED_DOMAINS_CNT; uDmnId++)
		{
			#ifdef DMNMGR_STOPVARREST_STARTDMNMONITOR_UCL_SYCN
			if(FALSE == b_DmnMgr_StopVarReset)
			#endif
			{
				(void)DmnMgr_ResetDmnRunTimeStatus(uDmnId);
			}
		}
	}
}

///
/// @brief This method implements the Domain Manager Component Initialize routine
///
/// @param void
///
/// @return Std_ReturnType
///
static Std_ReturnType CmpInit(void)
{
	Domain_initconfigurations();
	return Rte_Call_rp_CmpLibCmd_UclProxyCdd_Impl_OnCommand(eCmpCmd_Init);
}

///
/// @brief This method implements the Domain Manager Component De-Initialize routine
///
/// @param void
///
/// @return Std_ReturnType
///
static Std_ReturnType CmpDeInit(void)
{	
	return (Std_ReturnType) E_OK;
}

///
/// @brief This method implements the Domain Manager Component Activation routine
///
/// @param void
///
/// @return Std_ReturnType
///
static Std_ReturnType CmpActivation(void)
{	
	Domain_initconfigurations();
	ShutDown_Fixed_Couter_StartTime_GP = 0u;
	ShutDown_Fixed_Couter_StartTime_HSM = 0u;
	ShutDown_Fixed_Couter_StartTime_DM = 0u;
	DmnMgr_DmnShutdownReqSent = FALSE;
	GIP_Dmn_ShutdownComplete = FALSE;
	HSM_Dmn_ShutdownComplete = FALSE;
	DM_Dmn_ShutdownComplete = FALSE;
	return Rte_Call_rp_CmpLibCmd_UclProxyCdd_Impl_OnCommand(eCmpCmd_Activate);
}

///
/// @brief This method implements the Domain Manager Component De-Activation routine
///
/// @param void
///
/// @return Std_ReturnType
///

static Std_ReturnType CmpDeActivation(void)
{
	Std_ReturnType ret = E_NOT_OK;
	
	//DmnMgr Main_A53 Linux Shutdown Request

	if((Std_ReturnType)E_OK == DmnMgr_CoreDmnShutdownRequest())
	{
		if((Std_ReturnType)E_OK == Rte_Call_rp_CmpLibCmd_UclProxyCdd_Impl_OnCommand(eCmpCmd_DeActivate))
		{
			ret = E_OK;
		}
	}

	return ret;
}

Std_ReturnType DmnMgr_CoreDmnShutdownRequest(void)
{
	EDomainId dmnId = 0U;
	Std_ReturnType ret = E_NOT_OK;
	Std_ReturnType sRet = DMNMGR_E_NOK;
	Std_ReturnType rRet = DMNMGR_E_NOK;
	const SDmnMgrUsrCfgList *pCfg = NULL;
	SDmnRunTimeStatus *pDmnSts = NULL;

	if(DmnMgr_DmnShutdownReqSent == FALSE)
	{
		DmnMgr_DmnSystemStateChangeReq(EDomainId_Cluster,ESystemState_Shutdown);
		DmnMgr_DmnSystemStateChangeReq(EDomainId_HSM,ESystemState_Shutdown);
		DmnMgr_DmnSystemStateChangeReq(EDomainId_DM,ESystemState_Shutdown);
		DMNMGR_GET_SYSTEM_TIMER(&CoreShutdownFailsafeTimeStarted);
		DmnMgr_DmnShutdownReqSent = TRUE;
	}
	else
	{
		for( dmnId = EDomainId_Cluster; dmnId <= MANAGED_DOMAINS_CNT; dmnId++ )
		{
			//Get the RunTime Domain Status
			rRet = DmnMgr_GetDmnRunTimeStatus( dmnId, &pDmnSts );
			sRet = DmnMgr_MainGetDmnUsrCfg( dmnId, &pCfg );

			if( ( rRet == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
			{
				if((ESystemState_PrepareShutdown == pDmnSts->dmnCurSystemState)  && ( sRet == DMNMGR_E_OK) && ( pCfg != NULL ))
				{
					if(dmnId == EDomainId_Cluster) 
					{
						if(ShutDown_Fixed_Couter_StartTime_GP == 0u)
						{
							//Start the timer. Capture current OS time
							DMNMGR_GET_SYSTEM_TIMER(&ShutDown_Fixed_Couter_StartTime_GP);
						}
						else
						{
							DMNMGR_GET_SYSTEM_TIMER(&ShutDown_Fixed_Couter_EndTime_GP);
							if((ShutDown_Fixed_Couter_EndTime_GP - ShutDown_Fixed_Couter_StartTime_GP) >= pCfg->dmnTimeforCoreShutdown)
							{
								//Pass GIP shutdown complete status to DmnMgrStatus
								GIP_Dmn_ShutdownComplete = TRUE;
							}
						}
					}
					else
					{
						//do nothing
					}

					if(dmnId == EDomainId_HSM)
					{
						if(ShutDown_Fixed_Couter_StartTime_HSM == 0u)
						{
							DMNMGR_GET_SYSTEM_TIMER(&ShutDown_Fixed_Couter_StartTime_HSM);
						}
						else
						{
							DMNMGR_GET_SYSTEM_TIMER(&ShutDown_Fixed_Couter_EndTime_HSM);
							if((ShutDown_Fixed_Couter_EndTime_HSM - ShutDown_Fixed_Couter_StartTime_HSM) >= pCfg->dmnTimeforCoreShutdown)
							{
								//Pass HSM shutdown complete status to DmnMgrStatus
								HSM_Dmn_ShutdownComplete = TRUE;
							}
						}
					}
					else
					{
						//do nothing
					}

					if(dmnId == EDomainId_DM)
					{
						if(ShutDown_Fixed_Couter_StartTime_DM == 0u)
						{
							DMNMGR_GET_SYSTEM_TIMER(&ShutDown_Fixed_Couter_StartTime_DM);
						}
						else
						{
							DMNMGR_GET_SYSTEM_TIMER(&ShutDown_Fixed_Couter_EndTime_DM);
							if((ShutDown_Fixed_Couter_EndTime_DM - ShutDown_Fixed_Couter_StartTime_DM) >= pCfg->dmnTimeforCoreShutdown)
							{
								//Pass HSM shutdown complete status to DmnMgrStatus
								DM_Dmn_ShutdownComplete = TRUE;
							}
						}
					}
					else
					{
						//do nothing
					}
				}
			}
			else
			{
				//do nothing
			}
		}
	}
	DMNMGR_GET_SYSTEM_TIMER(&CoreShutdownFailsafeTimeExpered);

	if((((GIP_Dmn_ShutdownComplete == TRUE) && \
	(HSM_Dmn_ShutdownComplete == TRUE)) && \
	(DM_Dmn_ShutdownComplete == TRUE)) || \
	((CoreShutdownFailsafeTimeExpered - CoreShutdownFailsafeTimeStarted) >= DMNMGR_CORE_SHUTDOWN_FAILSAFE_TIME))
	{
		ret = E_OK;
	}
	else
	{
		//do nothing
	}

	//Core shutdown not happenned within shutdown time mentioned.
	//Execute the failsafe mecahnism timer and return E_OK

	return ret; 
}

///
/// @brief This method implements the Domain Manager Component Active routine
///
/// @param void
///
/// @return Std_ReturnType
///
static Std_ReturnType CmpActive(void)
{
	DmnMgrProcessEvents();
	
	return (Std_ReturnType) E_OK;
}

///
/// @brief  This method implements the BSW Main Function
///
/// @param void
///
/// @return void
///
void DmnMgr_CmpMain(void)
{	
	//static tModeAppActionsList const sActionsListL = { CmpDeInit, CmpInit, CmpActivation, CmpDeActivation, CmpActive};
	//static tSWCMode DmnMgr_PrevActualMode = eSWCMode_DeInit;
 
	//tModeAppManagementContext sContextL;

	// Read the requested and actual modes
	//Rte_Read_rpSRModeSWCRequestGroup2_RequestedMode(&sContextL.RequestedMode);
	//sContextL.ActualMode = DmnMgr_PrevActualMode;

	// Execute the common application main method
	//(void)ModeAppLib_Main(&sContextL, &sActionsListL);

	// Publish the application mode status data
	//Rte_Call_rpCSModeSWCStatus_SWCStatus(eSWCFeature_DmnMgr,sContextL.ActualMode,FALSE);
	//DmnMgr_PrevActualMode = sContextL.ActualMode;
}

static Std_ReturnType CmpDiag(void)
{
	return (Std_ReturnType) E_OK;
}

static Std_ReturnType CmpDiagReturn(void)
{
	return (Std_ReturnType) E_OK;
}

uint32 DmnMgr_MainGetElapsedTicks( void )
{
	return cmnDmnStatus.elapsedTicks;
}

DmnMgr_ReturnType DmnMgr_MainGetDmnUsrCfg( EDomainId dmnId, const SDmnMgrUsrCfgList **pCfg )
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;

	//if(( pCfg != NULL ) && ( dmnId  > EDomainId_VP) && (dmnId <= pDmnUsrCfg->dmnCnt ))
	if((pDmnUsrCfg != NULL) && ( pCfg != NULL ) && ( dmnId  > EDomainId_VP) && (dmnId <= pDmnUsrCfg->dmnCnt ))
	{
		*pCfg = &((pDmnUsrCfg->pDmnMgrCfgList)[dmnId-1u]);
		ret = DMNMGR_E_OK;
	}

	return ret;
}

///
/// @brief The Domain Manager Periodic Task processes the events received from every Managed Domains
/// and initiate a recovery mechanism in case of domain failures.
///
/// @param void
///
/// @return void
///
static void DmnMgrProcessEvents(void)
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	EDomainId dmnId = 0U;
	const SDmnMgrUsrCfgList *pCfg;
	SDmnRunTimeStatus *pDmnSts = NULL;

	//Domain Manager scheduling count. cert_int30_c vioation fix - wrap around check added
	if( cmnDmnStatus.elapsedTicks <  UINT32_MAX_VALUE )
	{
		cmnDmnStatus.elapsedTicks++;
	}
	else
	{
		//Don't wrap around. Maintain the max value.
	}
	#ifdef DMNMGR_HEALTHEVENT
	DmnMgr_Check_GIPReset();
	#endif
	for( dmnId = EDomainId_Cluster; dmnId <= MANAGED_DOMAINS_CNT; dmnId++ )
	{
		//Get the RunTime Domain Status
		ret = DmnMgr_GetDmnRunTimeStatus( dmnId, &pDmnSts );

		if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
		{
			//Check if First Link UP is received
			if( pDmnSts->isFirstLinkUpRcvd == TRUE )
			{
					//Get the User Domain Configuration
					pCfg = &( pDmnUsrCfg->pDmnMgrCfgList[dmnId-1u] );

						// Check for first HB from immediate next Domain
						if( pDmnSts->dmnHBLastRcvTime == 0u )
						{
							//Update Domain Up timer. cert_int30_c vioation fix - wrap around check added
							if( pDmnSts->dmnUpWaitTime <= ( UINT32_MAX_VALUE - DMNMGR_TASK_PERIOD_MS ) )
							{
								pDmnSts->dmnUpWaitTime += DMNMGR_TASK_PERIOD_MS;
							}
							else
							{
								//Set the maximum possible value instead of wrapping around
								pDmnSts->dmnUpWaitTime = UINT32_MAX_VALUE;
							}

							DmnMgr_MainCheckForFirstHB(dmnId, pCfg);

						}
						else if( DMN_READY == pDmnSts->dmnStatus )
						{
							DmnMgr_MainCheckForHBMiss(dmnId, pCfg);

							DmnMgr_MainCheckIfDmnShutRequested(dmnId);

							DmnMgr_MainCheckIfDmnWakeUpRequested(dmnId);

							//Poll RTC Data
							if(0u == (cmnDmnStatus.elapsedTicks % (DMNMGR_RTC_UPDATE_PERIOD_MS / DMNMGR_TASK_PERIOD_MS)))
							{
								#ifndef DMNMGR_RTCDATA_NOTNEEDED								
								DmnMgr_DmnCtrlReqRTCData();
								#endif
							}
						}
						else
						{
							#ifdef DMNMGR_HB_MISS_MON_UCLDOWN
							if((pDmnSts->dmnUclLinkState == EUclLinkState_Down) && (pDmnSts->dmnHealthState != EDmnHealth_HB_Miss))
							{
								DmnMgr_MainCheckForHBMiss(dmnId, pCfg);
							}
							#else
							/* do nothing */
							#endif
						}
			}
			//If First Link UP from immediate next domain not received, Wait for it
			else
			{
				DmnMgr_MainCheckForFirstLinkUp(dmnId);
			}
		}
	}
}

static void DmnMgr_MainCheckForFirstHB(EDomainId dmnId, const SDmnMgrUsrCfgList *pCfg)
{	
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	SDmnRunTimeStatus *pDmnSts = NULL;

	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( dmnId, &pDmnSts );

	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
	{
		if ( pDmnSts->dmnUpWaitTime >= pCfg->dmnTimeForFirstHBMs )
		{
			//Stop dmnUpWaitTime Timer
			pDmnSts->dmnUpWaitTime = 0;
			//Update Domain Health Status
			pDmnSts ->dmnHealthState = EDmnHealth_First_HB_Rcv_Time_Expired;

			//Find Overall Domain status
			DmnMgr_ConsolidatedDmnStatus(dmnId);

			//Publish the health status of the Domain
			(void)DmnMgr_PublishDmnHealthStaus(dmnId);
			#ifndef DMNMGR_HEALTHEVENT
			//Initiate Domain Reset
			(void)DmnMgr_DmnCtrlResetDmn(dmnId, DMNMGR_GIP_FISRTHB_MISS);
			#else
			DmnMgr_FirstHBMissInfo();
			#endif
			#ifdef HEALTHLOGGING_ENABLE
			/* Report the fault to HealthLog */
			DmnMgr_ControlDmnSaveHealthReport(dmnId, EDmnHealth_First_HB_Rcv_Time_Expired);
			#endif
			
		}
		else
		{
			//Do Nothing
		}
	}
	else
	{
		// Invoke DET
	}
}

static void DmnMgr_MainCheckForHBMiss(EDomainId dmnId, const SDmnMgrUsrCfgList *pCfg)
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	uint32 timeNow;
	uint32 nextHBRcvTime = 0u;
	SDmnRunTimeStatus *pDmnSts = NULL;
	
	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( dmnId, &pDmnSts );
	
	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
	{
		//cert_int30_c violation fix - wrap around check added
		if( pDmnSts->dmnHBMissCount < UINT8_MAX_VALUE )
		{
			//Find next HB receive time. cert_int31_c vioation fix added
			nextHBRcvTime = pDmnSts->dmnHBLastRcvTime + ( pCfg->dmnHBRcvPeriodicityMs * (1u+pDmnSts->dmnHBMissCount));
		}
		else
		{
			//Don't wrap around. Maintain the max value
		}

		timeNow = (  cmnDmnStatus.elapsedTicks * DMNMGR_TASK_PERIOD_MS );
		
		//If next HB receive time lapsed, then count it as HB miss
		if( timeNow > nextHBRcvTime )
		{
			//cert_int30_c violation fix - wrap around check added
			if( pDmnSts->dmnHBMissCount < UINT8_MAX_VALUE )
			{
				pDmnSts->dmnHBMissCount++;
				#ifdef DMNMGR_HEALTHEVENT
				DmnMgr_HBMissCountInfo(pDmnSts->dmnHBMissCount);
				#endif
			}
			else
			{
				//Don't wrap around. Maintain the max value
			}
			
			if( pDmnSts->dmnHBMissCount >= pCfg->dmnHBMissCount )
			{
			
				//Update Domain Health Status
				pDmnSts->dmnHealthState = EDmnHealth_HB_Miss;

				//Find Overall Domain status
				DmnMgr_ConsolidatedDmnStatus(dmnId);

				//Publish the health status of the Domain
				(void)DmnMgr_PublishDmnHealthStaus(dmnId);
				#ifndef DMNMGR_HEALTHEVENT
				//Initiate Domain Reset
				(void)DmnMgr_DmnCtrlResetDmn(dmnId, DMNMGR_GIP_HB_MISS);
				#else
            	DmnMgr_HBMissInfo();
				#endif
				#ifdef HEALTHLOGGING_ENABLE
				/* Report the fault to HealthLog */
				DmnMgr_ControlDmnSaveHealthReport(dmnId, EDmnHealth_HB_Miss);
				#endif
				
			}
		}
	}
	else
	{
		//Invoke DET
	}	
}

static void DmnMgr_MainCheckForFirstLinkUp(EDomainId dmnId )
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	//cert_int30_c vioation fix - wrap around check added
	EDomainId domainID = DmnMgr_MainGetDomainIdPostIdxCheck(dmnId);
	const SDmnMgrUsrCfgList *pCfg = &( (pDmnUsrCfg->pDmnMgrCfgList)[domainID] );
	SDmnRunTimeStatus *pDmnSts = NULL; 
	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( dmnId, &pDmnSts );

	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
	{	
		//cert_int30_c violation fix - wrap around check added
		if( pDmnSts->dmnUpWaitTime <= (UINT32_MAX_VALUE - DMNMGR_TASK_PERIOD_MS) )
		{
			pDmnSts->dmnUpWaitTime += DMNMGR_TASK_PERIOD_MS;
		}
		else
		{
			//Set the maximum possible value instead of wrapping around
			pDmnSts->dmnUpWaitTime = UINT32_MAX_VALUE;
		}
		
		if ( pDmnSts->dmnUpWaitTime >= pCfg->dmnTimeForUclLinkUp )
		{		
			pDmnSts->dmnHealthState = EDmnHealth_First_LinkUp_Time_Expired;

			//Find Overall Domain status
			DmnMgr_ConsolidatedDmnStatus(dmnId);

			//Publish the health status of the Domain
			(void)DmnMgr_PublishDmnHealthStaus(dmnId);
			#ifndef DMNMGR_HEALTHEVENT		
			//Initiate Domain Reset
			(void)DmnMgr_DmnCtrlResetDmn(dmnId, DMNMGR_GIP_LINKUP_FAILED);
			#else
			DmnMgr_ForFirstLinkUpInfo();
			#endif
			#ifdef HEALTHLOGGING_ENABLE
			/* Report the fault to HealthLog */
			DmnMgr_ControlDmnSaveHealthReport(dmnId, EDmnHealth_First_LinkUp_Time_Expired);
			
			#endif
		}
	}
	else
	{
		//Invoke DET
	}
}

static void DmnMgr_MainCheckIfDmnShutRequested(EDomainId dmnId )
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	SDmnRunTimeStatus *pDmnSts = NULL;

	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( dmnId, &pDmnSts );

	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
	{
		//Check If Wait for Domain ShutDown Timer Running
		if(pDmnSts->dmnShutDownWaitTime > 0u)
		{
			if(pDmnSts->dmnShutDownWaitTime <= DMNMGR_TASK_PERIOD_MS)
			{
				//Stop the Wait for Domain ShutDown Timer
				pDmnSts->dmnShutDownWaitTime = 0u;
				
				//Verify if Keep Domain Awake Timer is not running
				if((pDmnSts->dmnSystemAwakeWaitTime == 0u)
					&& (pDmnSts->dmnReqSystemState == ESystemState_Shutdown))
				{
					pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_ReqTimedOut;

					pDmnSts->dmnReqSystemState = EDmnChangeReqStatus_NoReq;
					//Do not initiate Domain Reset here. Mode Manager will check dmnStateChangeReqStatus and initiate Domain Reset

					#ifdef HEALTHLOGGING_ENABLE
					/* Report the fault to HealthLog */
					DmnMgr_ControlDmnSaveHealthReport(dmnId, EDmnHealth_Shutdown_Time_Expired);
					#endif
				}
				else
				{
					//Wait till Awake timer is expired
				}
			}
			else
			{
				pDmnSts->dmnShutDownWaitTime -= DMNMGR_TASK_PERIOD_MS;
			}
		}
	}
	else
	{
		//Invoke DET
	}
}

static void DmnMgr_MainCheckIfDmnWakeUpRequested(EDomainId dmnId )
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	SPowerSystemStateReqChange reqDmnState;
	SDmnRunTimeStatus *pDmnSts = NULL;
	
	//cert_int30_c vioation fix - wrap around check added
	EDomainId domainID = DmnMgr_MainGetDomainIdPostIdxCheck(dmnId);
	const SDmnMgrUsrCfgList *pCfg = &((pDmnUsrCfg->pDmnMgrCfgList)[domainID]);
	
	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( dmnId, &pDmnSts );

	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) && ( pCfg != NULL ) )
	{
		//Verify If Keep Domain Awake Timer is Running
		if(pDmnSts->dmnSystemAwakeWaitTime > 0u)
		{
			if(pDmnSts->dmnSystemAwakeWaitTime <= DMNMGR_TASK_PERIOD_MS)
			{
				//Stop Keep Domain Awake Timer
				pDmnSts->dmnSystemAwakeWaitTime = 0u;

				//Verify if any System state change request received during System Awake Time
				if( pDmnSts->dmnReqSystemState != EDmnChangeReqStatus_NoReq )
				{
					//If Domain State Change Request is delayed due to System Awake Timer, then Send
					//System State Change Request now.
					if(pDmnSts->dmnStateChangeReqStatus == EDmnChangeReqStatus_WaitAwakeTime)
					{
						pDmnSts->dmnShutDownWaitTime = pCfg->dmnTimeForShutdown;
						pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_WaitShutdonwTime;

						reqDmnState.domainId = dmnId;
						reqDmnState.state = pDmnSts->dmnReqSystemState;
						
						//Send Change Request to UCL
						(void)Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&reqDmnState);
					}
					else if(( pDmnSts->dmnStateChangeReqStatus == EDmnChangeReqStatus_WaitShutdonwTime) &&
						( pDmnSts->dmnShutDownWaitTime == 0u))
					{
						pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_ReqTimedOut;
					
						pDmnSts->dmnReqSystemState = EDmnChangeReqStatus_NoReq;
						//Do not initiate Domain Reset here. Mode Manager will check dmnStateChangeReqStatus and initiate Domain Reset

						#ifdef HEALTHLOGGING_ENABLE
						/* Report the fault to HealthLog */
						DmnMgr_ControlDmnSaveHealthReport(dmnId, EDmnHealth_Shutdown_Time_Expired);
						#endif
					}
					else
					{
						/*Do nothing*/
					}
				}
				else
				{
					//Do Nothing
				}
			}
			else
			{
				pDmnSts->dmnSystemAwakeWaitTime -= DMNMGR_TASK_PERIOD_MS;
			}
		}
	}
	else
	{
		//Invoke DET
	}
}

static EDomainId DmnMgr_MainGetDomainIdPostIdxCheck(EDomainId dmnId)
{
	EDomainId retVal = 0u;
	
	if(dmnId > 0u)
	{
		//Valid dmnId. No wrap around.
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
