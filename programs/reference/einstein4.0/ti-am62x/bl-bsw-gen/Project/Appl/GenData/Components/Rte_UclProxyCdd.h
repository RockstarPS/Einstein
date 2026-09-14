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
 *          File:  Rte_UclProxyCdd.h
 *        Config:  BMW.dpa
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <UclProxyCdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_UCLPROXYCDD_H
# define _RTE_UCLPROXYCDD_H

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

# include "Rte_UclProxyCdd_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData(P2VAR(SDiagDIDRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(P2VAR(SDiagIOCtrlRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData(P2VAR(SDiagRoutineRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData(P2VAR(SHealthDumpGetData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(P2VAR(SHealthDumpGetHdr, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_IgnState_IgnStateData(P2VAR(SIgnState, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(P2VAR(SPowerSystemStateReqChange, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(P2CONST(SHealthDomainFatalError, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(P2CONST(SHealthDomainHeartbeat, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDumpData_HealthDumpDataData(P2CONST(SHealthDumpData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(P2CONST(SHealthDumpHdrInfo, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(P2CONST(SPowerExtendShutdownTime, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(P2CONST(SPowerKeepSystemAwake, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData(P2CONST(SPowerSystemState, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData Rte_Receive_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData
#  define Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData Rte_Receive_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData
#  define Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData Rte_Receive_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData
#  define Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData Rte_Receive_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData
#  define Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData Rte_Receive_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData
#  define Rte_Receive_rSR_IgnState_IgnStateData Rte_Receive_UclProxyCdd_rSR_IgnState_IgnStateData


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData Rte_Read_UclProxyCdd_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData


/**********************************************************************************************************************
 * Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData Rte_Send_UclProxyCdd_pSR_HealthDomainFatalError_HealthDomainFatalErrorData
#  define Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData Rte_Send_UclProxyCdd_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData
#  define Rte_Send_pSR_HealthDumpData_HealthDumpDataData Rte_Send_UclProxyCdd_pSR_HealthDumpData_HealthDumpDataData
#  define Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData Rte_Send_UclProxyCdd_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData
#  define Rte_Send_pSR_HealthEventRecord_HealthEventRecordData Rte_Send_UclProxyCdd_pSR_HealthEventRecord_HealthEventRecordData
#  define Rte_Send_UclProxyCdd_pSR_HealthEventRecord_HealthEventRecordData(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData Rte_Send_UclProxyCdd_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData
#  define Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData Rte_Send_UclProxyCdd_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pSR_PowerSystemState_PowerSystemStateData Rte_Write_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DMNMGR_APPL_CODE) DmnMgr_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(arg1, arg2) (DmnMgr_ErrorNotification(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DMNMGR_APPL_CODE) DmnMgr_LinkStatusChanged(UInt8 DLInst, SInt32 Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(arg1, arg2) (DmnMgr_LinkStatusChanged(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define UclProxyCdd_START_SEC_CODE
# include "UclProxyCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CUclProxyCdd_Impl_Initialize CUclProxyCdd_Impl_Initialize
#  define RTE_RUNNABLE_CUclProxyCdd_Impl_MainFunction CUclProxyCdd_Impl_MainFunction
#  define RTE_RUNNABLE_CUclProxyCdd_Impl_OnCommand CUclProxyCdd_Impl_OnCommand
#  define RTE_RUNNABLE_CUclProxyCdd_Impl_Shutdown CUclProxyCdd_Impl_Shutdown
#  define RTE_RUNNABLE_OnDre_HealthDumpGetData OnDre_HealthDumpGetData
#  define RTE_RUNNABLE_OnDre_HealthDumpGetHdr OnDre_HealthDumpGetHdr
#  define RTE_RUNNABLE_OnDre_PowerSystemStateReqChange OnDre_PowerSystemStateReqChange
# endif

FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Initialize(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, UclProxyCdd_CODE) CUclProxyCdd_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Shutdown(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, UclProxyCdd_CODE) OnDre_HealthDumpGetData(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_HealthDumpGetHdr(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_PowerSystemStateReqChange(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define UclProxyCdd_STOP_SEC_CODE
# include "UclProxyCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_UclInitShutdown_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_UCLPROXYCDD_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
