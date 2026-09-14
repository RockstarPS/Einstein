/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_DmnMgr.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <DmnMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DMNMGR_H
# define _RTE_DMNMGR_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_DmnMgr_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData(P2VAR(SHealthDomainFatalError, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(P2VAR(SHealthDomainHeartbeat, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_HealthDumpData_HealthDumpDataData(P2VAR(SHealthDumpData, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(P2VAR(SHealthDumpHdrInfo, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(P2VAR(SPowerExtendShutdownTime, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(P2VAR(SPowerKeepSystemAwake, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DmnMgr_rSR_PowerSystemState_PowerSystemStateData(P2VAR(SPowerSystemState, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DmnMgr_rpSR_DmnInfo_SDmnStatus(P2VAR(SDmnStatus, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_DmnMgr_pSR_HealthDumpGetData_HealthDumpGetDataData(P2CONST(SHealthDumpGetData, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_DmnMgr_pSR_HealthDumpGetHdr_HealthDumpGetHdrData(P2CONST(SHealthDumpGetHdr, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(P2CONST(SPowerSystemStateReqChange, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DmnMgr_ppSR_DmnInfo_SDmnStatus(P2CONST(SDmnStatus, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData
#  define Rte_Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData
#  define Rte_Receive_rSR_HealthDumpData_HealthDumpDataData Rte_Receive_DmnMgr_rSR_HealthDumpData_HealthDumpDataData
#  define Rte_Receive_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData Rte_Receive_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData
#  define Rte_Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData
#  define Rte_Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rSR_PowerSystemState_PowerSystemStateData Rte_Read_DmnMgr_rSR_PowerSystemState_PowerSystemStateData
#  define Rte_Read_rpSR_DmnInfo_SDmnStatus Rte_Read_DmnMgr_rpSR_DmnInfo_SDmnStatus


/**********************************************************************************************************************
 * Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Send_pSR_HealthDumpGetData_HealthDumpGetDataData Rte_Send_DmnMgr_pSR_HealthDumpGetData_HealthDumpGetDataData
#  define Rte_Send_pSR_HealthDumpGetHdr_HealthDumpGetHdrData Rte_Send_DmnMgr_pSR_HealthDumpGetHdr_HealthDumpGetHdrData


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData Rte_Write_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData
#  define Rte_Write_ppSR_DmnInfo_SDmnStatus Rte_Write_DmnMgr_ppSR_DmnInfo_SDmnStatus


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_UCLPROXYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_UCLPROXYCDD_APPL_CODE) CUclProxyCdd_Impl_Initialize(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_UCLPROXYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_UclInitShutdown_Impl_Initialize CUclProxyCdd_Impl_Initialize
#  define RTE_START_SEC_UCLPROXYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_UCLPROXYCDD_APPL_CODE) CUclProxyCdd_Impl_Shutdown(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_UCLPROXYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_UclInitShutdown_Impl_Shutdown CUclProxyCdd_Impl_Shutdown
#  define Rte_Call_rp_CS_SleepOperation_CtrlWSS_CancelSleep() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_SleepOperation_CtrlWSS_ReadytoSleep() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_SleepOperation_CtrlWSS_RequestSleep() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define DmnMgr_START_SEC_CODE
# include "DmnMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CDmnMgr_Impl_MainFunction CDmnMgr_Impl_MainFunction
#  define RTE_RUNNABLE_CDmnMgr_Impl_OnCommand CDmnMgr_Impl_OnCommand
#  define RTE_RUNNABLE_DmnMgr_DmnSystemStateChangeReq DmnMgr_DmnSystemStateChangeReq
#  define RTE_RUNNABLE_DmnMgr_DmnSystemStateChangeStatus DmnMgr_DmnSystemStateChangeStatus
#  define RTE_RUNNABLE_DmnMgr_ErrorNotification DmnMgr_ErrorNotification
#  define RTE_RUNNABLE_DmnMgr_LinkStatusChanged DmnMgr_LinkStatusChanged
#  define RTE_RUNNABLE_DmnMgr_MonitorDmnExtendShutdownTime DmnMgr_MonitorDmnExtendShutdownTime
#  define RTE_RUNNABLE_DmnMgr_MonitorDmnHealthDumpData DmnMgr_MonitorDmnHealthDumpData
#  define RTE_RUNNABLE_DmnMgr_MonitorDmnHealthDumpHdrInfo DmnMgr_MonitorDmnHealthDumpHdrInfo
#  define RTE_RUNNABLE_DmnMgr_MonitorDmnHealthFatalError DmnMgr_MonitorDmnHealthFatalError
#  define RTE_RUNNABLE_DmnMgr_MonitorDmnHeartBeat DmnMgr_MonitorDmnHeartBeat
#  define RTE_RUNNABLE_DmnMgr_MonitorDmnKeepSystemAwake DmnMgr_MonitorDmnKeepSystemAwake
#  define RTE_RUNNABLE_DmnMgr_MonitorDmnPowerSystemState DmnMgr_MonitorDmnPowerSystemState
#  define RTE_RUNNABLE_DmnMgr_StartDomainMonitoring DmnMgr_StartDomainMonitoring
#  define RTE_RUNNABLE_DmnMgr_StopDomainMonitoring DmnMgr_StopDomainMonitoring
# endif

FUNC(void, DmnMgr_CODE) CDmnMgr_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, DmnMgr_CODE) CDmnMgr_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DmnMgr_CODE) DmnMgr_DmnSystemStateChangeReq(EDomainId DmnId, ESystemState DmnState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DmnMgr_CODE) DmnMgr_DmnSystemStateChangeStatus(EDomainId DmnId, P2VAR(EDmnChangeReqStatus_t, AUTOMATIC, RTE_DMNMGR_APPL_VAR) DmnStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DmnMgr_CODE) DmnMgr_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DmnMgr_CODE) DmnMgr_LinkStatusChanged(UInt8 DLInst, SInt32 Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnExtendShutdownTime(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnHealthDumpData(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnHealthDumpHdrInfo(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnHealthFatalError(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnHeartBeat(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnKeepSystemAwake(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnPowerSystemState(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, DmnMgr_CODE) DmnMgr_StartDomainMonitoring(EDomainId DmnID); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DmnMgr_CODE) DmnMgr_StopDomainMonitoring(EDomainId DmnID); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define DmnMgr_STOP_SEC_CODE
# include "DmnMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_WSS_SleepOperations_E_NOT_OK (1U)

#  define RTE_E_UclInitShutdown_E_NOT_OK (1U)

#  define RTE_E_if_CS_DmnMonitoring_E_NOT_OK (1U)

#  define RTE_E_if_CS_DmnSystemStateChange_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DMNMGR_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
