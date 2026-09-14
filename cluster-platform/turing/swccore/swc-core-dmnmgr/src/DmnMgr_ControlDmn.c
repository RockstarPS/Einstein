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
//---------------------------------------------------------------------------------------------------------------------

#include "string.h"
#include "DmnMgr_ControlDmn.h"
#include "DmnMgr_Main.h"
#include "Rte_DmnMgr_stubs.h"
#define DMNMGR_START_SEC_CONST_8
#include "MemMap.h"

#define MAX_MONTH 	(12u)
#define YEAR_LEAP	(4u)
/* below macros will be deleted in Phase3 once HL is implemented */
// # define dHLSwcId_DmnMgr 0U
// # define dHLErrorCode_Domain1Reset 0U

#ifdef DMNMGR_FATAL_ERROR_AUX_DATA_LOG
static uint32 DmnMgr_ControlDmnCompldx = 0u;
#endif

#define DMNMGR_STOP_SEC_CONST_8
#include "MemMap.h"

										
#define DMNMGR_START_SEC_CODE_ASIL_B
#include "MemMap.h"

#if 0
static DmnMgr_ReturnType DmnMgr_DmnCtrlSaveHealthReport(EDomainId dmnId);
#endif
#ifndef DMNMGR_RTCDATA_NOTNEEDED
static boolean DmnMgr_RTC_IsSignalValid(tRxSignalStatus Signal_Sts);
static Std_ReturnType DmnMgr_RTC_CalculateMonthDay(uint32 YearDayIn, uint32 YearIn, uint32 *pMonth, uint32 *pDayofMonth);
#endif
extern void Mcu_PerformReset(void);

#ifdef DMNMGR_MCUEXTPERFORMRESET
extern void McuExt_PerformReset(void);
#endif

#ifdef RTE_UNAVAILABLE
extern Std_ReturnType EcuMExt_ResetAcoreAlone(void);
#endif
#ifdef DMNMGR_HEALTH_MONITORING_FUSA_HD
extern void ModeMgr_Set_Backlight_State(uint8 state);
extern void ModeMgr_SocPowerDownUp(void);
#endif
/// @brief This method implements Fetching of last Domain reset reason of the Domains from health manager
///
/// @param dmnId
///
/// @return DmnMgr_ReturnType
///
#if 0
static DmnMgr_ReturnType DmnMgr_DmnCtrlGetHealthReport(void);
#endif
///
///
/// @brief This method implements the Domain System State Change Request Server Operation
///
/// @param DmnId - Domain Id (0 - VIP Domain, 1 - Cluster Domain)
///
/// @param DmnState - Requested System State
///
/// @return Std_ReturnType 
///
Std_ReturnType DmnMgr_DmnSystemStateChangeReq(EDomainId DmnId, ESystemState DmnState) 
{
	SPowerSystemStateReqChange reqDmnState = {DmnId, DmnState};
	#ifdef DMNMGR_MULTIDOMIANS_ENABLE
		SPowerSystemStateReqChange reqestedDmnState = {DmnId, DmnState};
	#endif
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	Std_ReturnType sRet = E_NOT_OK;
	const SDmnMgrUsrCfgList *pCfg = NULL;
	SDmnRunTimeStatus *pDmnSts = NULL;
	uint32 flShutdownVal = DMNMGR_DM_SHUTDOWN;

	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( DmnId, &pDmnSts );

	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
	{
		//Valid dmnId & dmnState Received
		if(( DmnId > EDomainId_VP ) && ( DmnId <= MANAGED_DOMAINS_CNT ) &&  ( DmnState == ESystemState_Shutdown ))
		{			
			if (pDmnSts->dmnStatus != DMN_READY)
			{
				pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_DmnNotReady;
			}
		}

		//Do not accept any new request if previous request is pending
		if(pDmnSts->dmnStateChangeReqStatus == EDmnChangeReqStatus_PrevReqPending )
		{
			ret = DMNMGR_E_NOK;
		}

		if( DMNMGR_E_OK == ret )
		{
			// Send the Request to UCL only if current state is different from the requested state
			if(pDmnSts->dmnCurSystemState != DmnState)
			{
				//Handle special preparation before inform the UCL status change
				switch(DmnState)
				{
					case ESystemState_Shutdown:
						pDmnSts->dmnReqSystemState = DmnState;
						
						//No Awake time set
						if((pDmnSts->dmnSystemAwakeWaitTime == 0u) && (pDmnSts->dmnShutDownWaitTime == 0u))
						{
							ret = DmnMgr_MainGetDmnUsrCfg( DmnId, &pCfg );
							
							if( ( ret == DMNMGR_E_OK) && ( pCfg != NULL ) )
							{
								pDmnSts->dmnShutDownWaitTime = pCfg->dmnTimeForShutdown;
								#ifdef DMNMGR_MULTIDOMIANS_ENABLE
								if(DmnId != EDomainId_IVI)
								#endif
								{
									pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_PrevReqPending;
								}
								
								reqDmnState.domainId = DmnId;
								reqDmnState.state = DmnState;
								
								#ifdef DMNMGR_MULTIDOMIANS_ENABLE
								if(DmnId == EDomainId_Cluster)
								{
									//Send Change Request to UCL
							   		(void) Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&reqDmnState);
								}


								if(DmnId == EDomainId_HSM)
								{
									//Send Change Request to HSM
							   		DMNMGR_HSM_SENDMSG(reqDmnState.state);
								}

								if(DmnId == EDomainId_DM)
								{
									DMNMGR_DM_IPC_SENDMSG(CddIpcConf_IpcComChanId_Cdd_ipcMpu11_EP15, (const void *)&flShutdownVal, (uint32)sizeof(flShutdownVal));
								}
								#endif
							}
							else
							{
								// Handle error appropriately
							}
						}
						else if(pDmnSts->dmnShutDownWaitTime != 0u)
						{
							pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_WaitShutdonwTime;
						}
						else
						{
							pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_WaitAwakeTime;
						}
						break;
					#ifdef DMNMGR_MEET_SYSTEM_REQUEST
					case ESystemState_Meet:
						pDmnSts->dmnReqSystemState = DmnState;
						reqDmnState.domainId = DmnId;
						reqDmnState.state = DmnState;
						
						//Send Change Request to UCL
						(void) Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&reqDmnState);
						break;
					#endif

					case ESystemState_FullRun:
						pDmnSts->dmnReqSystemState = DmnState;
						reqDmnState.domainId = DmnId;
						reqDmnState.state = DmnState;
						
						//Send Change Request to UCL
						(void) Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&reqDmnState);
						break;
					default:
					#ifdef DMNMGR_MULTIDOMIANS_ENABLE	
					if(DmnId == EDomainId_IVI)
					{
										//Send Change Request to IVI domain 
					(void)Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&reqestedDmnState);
					}
					#endif
					break;
				}
			}
			else
			{
				//If Current system state & requested state are same just return success.
				pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_ReqSucceed;
			}
			sRet = E_OK;
		}
		else
		{
			pDmnSts->dmnReqSystemState = EDmnChangeReqStatus_NoReq;
		}
	}
	else
	{
		//Invoke DET
	}
	return sRet;
}

#ifdef DMNMGR_DOMAINCONTROLPROGRAMS_ENABLE
Std_ReturnType DmnMgr_DomainControl_DmnSystemStateChangeReq(SPowerSystemStateReqChange *reqDmnState) 
{
	SPowerSystemStateReqChange ptrdmnState;
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	Std_ReturnType sRet = E_NOT_OK;
	const SDmnMgrUsrCfgList *pCfg = NULL;
	SDmnRunTimeStatus *pDmnSts = NULL;

	memset(&ptrdmnState, 0, sizeof(SPowerSystemStateReqChange));
	memcpy(&ptrdmnState,reqDmnState,sizeof(SPowerSystemStateReqChange));

	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( ptrdmnState.domainId, &pDmnSts );

	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
	{
		//Valid dmnId & dmnState Received
		if(( ptrdmnState.domainId > EDomainId_VP ) && ( ptrdmnState.domainId <= MANAGED_DOMAINS_CNT ) &&  ( ptrdmnState.state == ESystemState_Shutdown ))
		{			
			if (pDmnSts->dmnStatus != DMN_READY)
			{
				pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_DmnNotReady;
			}
		}

		//Do not accept any new request if previous request is pending
		if(pDmnSts->dmnStateChangeReqStatus == EDmnChangeReqStatus_PrevReqPending )
		{
			ret = DMNMGR_E_NOK;
		}

		if( DMNMGR_E_OK == ret )
		{
			// Send the Request to UCL only if current state is different from the requested state
			if(pDmnSts->dmnCurSystemState != ptrdmnState.state)
			{
				//Handle special preparation before inform the UCL status change
				switch(ptrdmnState.state)
				{
					case ESystemState_Shutdown:
						pDmnSts->dmnReqSystemState = ptrdmnState.state;
						
						//No Awake time set
						if((pDmnSts->dmnSystemAwakeWaitTime == 0u) && (pDmnSts->dmnShutDownWaitTime == 0u))
						{
							ret = DmnMgr_MainGetDmnUsrCfg( ptrdmnState.domainId, &pCfg );
							
							if( ( ret == DMNMGR_E_OK) && ( pCfg != NULL ) )
							{
								pDmnSts->dmnShutDownWaitTime = pCfg->dmnTimeForShutdown;
								pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_PrevReqPending;
								//Send Change Request to UCL
							(void)Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&ptrdmnState);
							}
							else
							{
								// Handle error appropriately
							}
						}
						else if(pDmnSts->dmnShutDownWaitTime != 0u)
						{
							pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_WaitShutdonwTime;
						}
						else
						{
							pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_WaitAwakeTime;
						}
						break;
					default:

						(void)Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&ptrdmnState);
					
					break;
				}
			}
			else
			{
				//If Current system state & requested state are same just return success.
				pDmnSts->dmnStateChangeReqStatus = EDmnChangeReqStatus_ReqSucceed;
			}
			sRet = E_OK;
		}
		else
		{
			pDmnSts->dmnReqSystemState = EDmnChangeReqStatus_NoReq;
		}
	}
	else
	{
		//Invoke DET
	}
	return sRet;
}
#endif
///
/// @brief This method implements the Domain System State Change Request Status Server Operation
///
/// @param DmnId - Domain Id (0 - VIP Domain, 1 - Cluster Domain)
///
/// @param DmnStatus - a pointer to save the status
///
/// @return void
///

void DmnMgr_DmnSystemStateChangeStatus(EDomainId DmnId, EDmnChangeReqStatus_t *DmnStatus)
{
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	SDmnRunTimeStatus *pDmnSts = NULL;

	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( DmnId, &pDmnSts );

	if( ( ret == DMNMGR_E_OK ) && ( pDmnSts != NULL ) )
	{
		if((DmnStatus != NULL) && (DmnId <= MANAGED_DOMAINS_CNT) && (DmnId != EDomainId_VP))
		{
			*DmnStatus = pDmnSts->dmnStateChangeReqStatus;
		}
	}
	else
	{
		//Invoke DET
	}
	
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Periodic Function to collect RTC Data from CAN
//---------------------------------------------------------------------------------------------------------------------
#ifndef DMNMGR_RTCDATA_NOTNEEDED								
void DmnMgr_DmnCtrlReqRTCData(void)
{
	SDmnCtrlRTCInfo rtcData;
	DmnMgr_ReturnType ret = DMNMGR_E_NOK;
	SDmnRunTimeStatus *pDmnSts = NULL;

    uint32          HourInL          = 0u;
    tRxSignalStatus HourInStatusL    = eSIGNAL_INVALID;
    uint32          MinuteInL        = 0u;
    tRxSignalStatus MinuteInStatusL  = eSIGNAL_INVALID;
    uint32          SecondInL        = 0u;
    tRxSignalStatus SecondInStatusL  = eSIGNAL_INVALID;	
    uint32          YearInL          = 0u;
    tRxSignalStatus YearInStatusL    = eSIGNAL_INVALID;
    uint32          YearDayInL       = 0u;
    tRxSignalStatus YearDayInStatusL = eSIGNAL_INVALID;

	uint32			MonthInL = 0u;
	uint32			DayInL = 0u;

	ret = DmnMgr_GetDmnRunTimeStatus( EDomainId_Cluster, &pDmnSts );
	if ( ( ret == DMNMGR_E_OK ) && (pDmnSts->dmnStatus == DMN_READY) )
	{
		
		(void) Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue(eGClockSecondIn, (UInt8 *)&(SecondInL), &(SecondInStatusL));
		(void) Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue(eGClockMinIn, (UInt8 *)&(MinuteInL), &(MinuteInStatusL));
		(void) Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue(eGClockHourIn, (UInt8 *)&(HourInL), &(HourInStatusL));
		(void) Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue(eGClockYearIn, (UInt8 *)&(YearInL), &(YearInStatusL));
		(void) Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue(eGClockDayIn, (UInt8 *)&(YearDayInL), &(YearDayInStatusL));

		if (((TRUE == DmnMgr_RTC_IsSignalValid(MinuteInStatusL))&&
			(TRUE == DmnMgr_RTC_IsSignalValid(HourInStatusL))&&
			(TRUE == DmnMgr_RTC_IsSignalValid(YearInStatusL))&&
			(TRUE == DmnMgr_RTC_IsSignalValid(SecondInStatusL))&&
			(TRUE == DmnMgr_RTC_IsSignalValid(YearDayInStatusL))))
		{
			if((Std_ReturnType)E_OK == DmnMgr_RTC_CalculateMonthDay(YearDayInL, YearInL, &MonthInL, &DayInL))
			{
				rtcData.DmnRTCDay = (uint8)(DayInL);       /*misra_c_2012_rule_2_2_violation */
				rtcData.DmnRTCHour = (uint8)(HourInL);
				rtcData.DmnRTCMin = (uint8)(MinuteInL);
				rtcData.DmnRTCSec = (uint8)(SecondInL);
				rtcData.DmnRTCMonth = (uint8)(MonthInL);
				rtcData.DmnRTCYear = (uint16)(YearInL);
				
				#if 0
				(void)Rte_Write_pSR_RTTStatus_RTTStatusData(&rtcData); /* misra_c_2012_directive_4_4_violation */
				#endif
			}
		}
	}
}
#endif	  

DmnMgr_ReturnType DmnMgr_DmnCtrlResetDmn(EDomainId dmnId, uint16 FaultID)
{
	DmnMgr_ReturnType ret = DMNMGR_E_OK;
	uint8 flEDomainId_Cluster = 0;
	SDmnRunTimeStatus *pDmnSts = NULL;

	//Get the RunTime Domian Status
	ret = DmnMgr_GetDmnRunTimeStatus(dmnId, &pDmnSts);

	#ifdef DMNMGR_HEALTH_MONITORING_FUSA_HD 
	boolean DmnMgr_RestrictedStatus = FALSE;
	#endif
	
	//No need to verfy dmnId if the call is internal to Domain Manager.
	//Domain Manager Developer should that proper dmnId is passed to the respective APIs
	flEDomainId_Cluster = EDomainId_Cluster;	
	// Trigger Domain Reset Request server operation
	if((dmnId == flEDomainId_Cluster) && (pDmnSts->dmnCurSystemState != ESystemState_Meet))
	{
		#ifdef DMNMGR_FAILSAFESTATE_CLUSTERESET_FUSA  //If GIP reset is required for heart beat related issue
		if((Std_ReturnType)E_OK == OsTrustedCall_DmnMgr_StopDomainMonitoring(EDomainId_Cluster))
		{
			#ifdef DMNMGR_FUSA_FAULT_EVENT_LOGGING
				CddOsph_FUSA_FaultEvent(DMNMGR_GIP_RESET_CATEGORY_CODE,DMNMGR_GIP_RESET_VALUE_CODE);
			#endif
			#ifdef RTE_UNAVAILABLE
				EcuMExt_ResetAcoreAlone();
			#else
				(void)Rte_Call_rpCS_EcuMExt_ResetAcoreAlone_ResetAcoreAlone();
			#endif
		}
		#endif
		#ifdef DMNMGR_FAILSAFESTATE_ECURESET_FUSA//If ECU reset is required for heart beat related issue
			#ifdef DMNMGR_MCUEXTPERFORMRESET
			McuExt_PerformReset();
			#else
			Mcu_PerformReset();
			#endif
		#endif	
		#ifdef DMNMGR_HEALTH_MONITORING_FUSA_HD 
		#ifdef DMNMGR_MCU_RESET_FUSA_HD //If MCU reset is required for heart beat related issue
			(void)Stub_Read_Powermode_RestrictedMode_Status(&DmnMgr_RestrictedStatus);
			
			if(DmnMgr_RestrictedStatus != TRUE)
			{
				Rte_Call_rpCSModeRequestReset_ResetRequest(EDomainId_VP);
			}
		#else	                       //If SOC power down power up is required for heart beat related issue
		if(E_OK == DmnMgr_StopDomainMonitoring(EDomainId_Cluster))
		{
			ModeMgr_Set_Backlight_State(DMNMGR_BACKLIGHT_OFF);
            ModeMgr_SocPowerDownUp();
		}
		#endif	
		#endif

		#ifdef DMNMGR_FAILSAFESTATE_E4PLATFORM  //if MCU reset is required for heart beat related issue
			DmnMgr_ReportGipHealthError(FaultID);
			ret = E_OK;
		#endif
		
	}
	else
	{
		//Rte_Call_rpCSModeRequestReset_ResetRequest(dmnId);	// Will be replaced with a trusted API for IVI reset
	}
	
	return ret;
}

#if 0 /* Compiler warning fix: Unused function */
//get the Domain reset information from Health Logger
static DmnMgr_ReturnType DmnMgr_DmnCtrlGetHealthReport(void)
{
	DmnMgr_ReturnType ret = DMNMGR_E_OK;
	EDmnResetReason_t dmnRstReason = EDmnHealth_Active;
	uint8 i;
	/*misra_c_2012_rule_2_2_violation*/
	const tHL_LogId lDomainResetLogIdList[MANAGED_DOMAINS_CNT] = {1}; //MDS: Ensure subsequent elements of the array updated properly
	SDmnRunTimeStatus *pAllDmnRunTimeSts = NULL;
	
	//Get the RunTime Domain Status
	ret = DmnMgr_GetDmnRunTimeStatus( EDomainId_Cluster, &pAllDmnRunTimeSts );

	if( ( ret == DMNMGR_E_OK ) && ( pAllDmnRunTimeSts != NULL ) )
	{
		for( i = 0u; i < MANAGED_DOMAINS_CNT; i++)
		{
			if((Std_ReturnType)E_OK == Rte_Call_ppCSHLService_GetLogData(lDomainResetLogIdList[i]
													, (uint8 *)(&(dmnRstReason))
													, sizeof(EDmnResetReason_t)
													, NULL))
			{
				pAllDmnRunTimeSts[i].dmnLastRstReason = dmnRstReason;
			}
			else
			{
				ret = DMNMGR_E_NOK;  /* misra_c_2012_rule_14_3_violation */
			}
		}
	}
	else
	{
		ret = DMNMGR_E_NOK;
		//Invoke DET
	}
	
	return ret;
}
#endif

#ifdef HEALTHLOGGING_ENABLE
///
/// @brief This function reports reset reason to healthlog
///
/// @param DmnID Domain ID
///
/// @param dmnHealthState Domain Health state under faulty condition
///
/// @return void
void DmnMgr_ControlDmnSaveHealthReport(EDomainId DmnID, EDmnHealthState_t dmnHealthState)
{
	uint16 errorCode = 0U;
#ifdef DMNMGR_FATAL_ERROR_AUX_DATA_LOG
	uint8 data[5u] = {0};
#else
	uint8 placeholder;
#endif

	/* Map Domain health status to HealthLog Reset reason/Report code */
	switch (dmnHealthState)
	{
	case EDmnHealth_First_LinkUp_Time_Expired:
		errorCode = DMNMGR_ICOM_UCL_NOT_START;
		break;

	case EDmnHealth_UCL_Fatal_Error:
		errorCode = DMNMGR_ICOM_UCL_FAILURE;
	#ifdef DMNMGR_RESTRICT_UCL_FAILURE_COUNT
		DmnMgr_updateErrorCode(&errorCode);
	#endif
		break;

	case EDmnHealth_First_HB_Rcv_Time_Expired:
		errorCode = DMNMGR_ICOM_GIP_PP_NOT_RECEIVED;
		break;
	
	case EDmnHealth_HB_Miss:
		errorCode = DMNMGR_ICOM_GIP_PP_STOPPED;
		break;
	
	case EDmnHealth_Rcvd_Inv_SeqCnt:
		errorCode = DMNMGR_ICOM_GIP_PP_MISMATCH;
		break;
	
	case EDmnHealth_Fatal_Error:
		errorCode = DMNMGR_ICOM_GIP_FATAL_ERROR;
		break;
	
	case EDmnHealth_Shutdown_Time_Expired:
		errorCode = DMNMGR_ICOM_GIP_SHUTDOWN_TIMEOUT;
		break;
	
	default:
		/* Do nothing */
		break;
	}

	/* At present report HealthLog only for EDomainId_Cluster */
	if((0U != errorCode) &&  (EDomainId_Cluster == DmnID))
	{
	
#ifdef DMNMGR_FATAL_ERROR_AUX_DATA_LOG
		if( DMNMGR_ICOM_GIP_FATAL_ERROR == errorCode )
		{
			data[1u] = (uint8) ((DmnMgr_ControlDmnCompldx >> 24u) & 0xFFu);
			data[2u] = (uint8) ((DmnMgr_ControlDmnCompldx >> 16u) & 0xFFu);
			data[3u] = (uint8) ((DmnMgr_ControlDmnCompldx >> 8u) & 0xFFu);
			data[4u] = (uint8) (DmnMgr_ControlDmnCompldx & 0xFFu);
		}
		else
		{
			/* Do nothing */
		}

		(void)Rte_Call_rpCSHLReport_Report((uint16)0,		/* unused parameter Module ID */
								errorCode,			/* HealthLog Report Code */
								&data[0u],		/* pBuffer */
								(uint16)5u		/* uBufferSize */
								);
#else
		Rte_Call_rpCSHLReport_Report((uint16)0,		/* unused parameter Module ID */
								errorCode,			/* HealthLog Report Code */
								&placeholder,		/* unused parameter *pBuffer */
								(uint16)0			/* unused parameter uBufferSize */
								);
#endif
	}
	else
	{
		/* Invalid errorCode or DmnId */
	}
}
#endif

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Check if the RTC signal received from CAN is valid or not
//---------------------------------------------------------------------------------------------------------------------
#ifndef DMNMGR_RTCDATA_NOTNEEDED
static boolean DmnMgr_RTC_IsSignalValid(tRxSignalStatus Signal_Sts)
{
    boolean ResultL = TRUE;

    if ((eSIGNAL_NEVER_RECEIVED == Signal_Sts)||
        (eSIGNAL_MISSING == Signal_Sts)||
        (eSIGNAL_INVALID == Signal_Sts))
    {
        ResultL = FALSE;
    }

    return(ResultL);
}
#endif
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Calculate the Month and Date from YearDay
//---------------------------------------------------------------------------------------------------------------------
#ifndef DMNMGR_RTCDATA_NOTNEEDED
static Std_ReturnType DmnMgr_RTC_CalculateMonthDay(uint32 YearDayIn,
                                             uint32 YearIn,
                                             uint32 *pMonth,
                                             uint32 *pDayofMonth)
{
    uint8          LeapL     = 0u;
    uint8          MonthIdxL = 0u;
    Std_ReturnType ReturnL   = E_OK;
    static const uint16 DaysofYear[2][13] = {{0u, 31u, 59u, 90u, 120u, 151u, 181u, 212u, 243u, 273u, 304u, 334u, 365u}, \
                                             {0u, 31u, 60u, 91u, 121u, 152u, 182u, 213u, 244u, 274u, 305u, 335u, 366u}};

    /*Check if the Year is Leap year*/
    if((YearIn % YEAR_LEAP) == 0u)
	{
		LeapL = (uint8)TRUE;
	}

    if ((0u < YearDayIn)&&(DaysofYear[LeapL][MAX_MONTH]>= YearDayIn))
    {
        /*Calculate the Month index [0 -11] from the days of year table*/
        /*Calculate the Day of the Month by Subtracting the days up to previous month */
        /*Exit the loop when a month is calculated*/
        for (MonthIdxL = 1u; (MonthIdxL <= MAX_MONTH); MonthIdxL++)
        {
            if (YearDayIn <= DaysofYear[LeapL][MonthIdxL])
            {
                /*Break when a month is calculated*/
                *pMonth      = (uint32) MonthIdxL;
                *pDayofMonth = (uint32) (YearDayIn - DaysofYear[LeapL][MonthIdxL - 1u]);
                break;
            }
        }
    }
    else
    {
        /*Invalid value input as yearDayIn*/
        ReturnL = E_NOT_OK;
    }

    return(ReturnL);
}
#endif

#ifdef DMNMGR_STOPVARREST_STARTDMNMONITOR_UCL_SYCN
extern boolean b_DmnMgr_StopVarReset;
#endif
Std_ReturnType DmnMgr_StartDomainMonitoring(EDomainId DmnID)
{
	Std_ReturnType ret = E_NOT_OK;

	if((Std_ReturnType)E_OK == Rte_Call_rp_CmpLibCmd_UclProxyCdd_Impl_OnCommand(eCmpCmd_Activate))
	{
		(void)DmnMgr_ResetDmnRunTimeStatus(DmnID);
		#ifdef DMNMGR_STOPVARREST_STARTDMNMONITOR_UCL_SYCN
		b_DmnMgr_StopVarReset = TRUE;
		#endif
		ret = E_OK;
	}
	return ret;
}


Std_ReturnType DmnMgr_StopDomainMonitoring(EDomainId DmnID)
{
	//Invoke UCL ShutDown server operation
	Std_ReturnType ret = E_NOT_OK;

	if((Std_ReturnType)E_OK == Rte_Call_rp_CmpLibCmd_UclProxyCdd_Impl_OnCommand(eCmpCmd_DeActivate))
	{
		#ifdef DMNMGR_STOPVARREST_STARTDMNMONITOR_UCL_SYCN
		b_DmnMgr_StopVarReset = FALSE;
		#endif
		(void)DmnMgr_ResetDmnRunTimeStatus(DmnID);
		ret = E_OK;
	}

	return ret;
}

#ifdef DMNMGR_FATAL_ERROR_AUX_DATA_LOG
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Set compldx value for error logging when fatal error occurs. 
//---------------------------------------------------------------------------------------------------------------------
void DmnMgr_ControlDmnSetCompldx(uint32 compldx)
{
	DmnMgr_ControlDmnCompldx = compldx;
}
#endif

#define DMNMGR_STOP_SEC_CODE_ASIL_B
#include "MemMap.h"

