/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  DmnMgr.c
 *        Config:  BMW.dpa
 *     SW-C Type:  DmnMgr
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <DmnMgr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_DmnMgr.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_DmnMgr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void DmnMgr_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Rte_DT_data_u8_32_0: Integer in interval [0...255]
 * SInt32: Integer in interval [-2147483648...2147483647]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   eCmpCmd_Init (0U)
 *   eCmpCmd_DeInit (1U)
 *   eCmpCmd_Activate (2U)
 *   eCmpCmd_DeActivate (3U)
 * EDmnChangeReqStatus_t: Enumeration of integer in interval [0...7] with enumerators
 *   EDmnChangeReqStatus_NoReq (0U)
 *   EDmnChangeReqStatus_WaitAwakeTime (1U)
 *   EDmnChangeReqStatus_WaitShutdonwTime (2U)
 *   EDmnChangeReqStatus_PrevReqPending (3U)
 *   EDmnChangeReqStatus_ReqSucceed (4U)
 *   EDmnChangeReqStatus_ReqFail (5U)
 *   EDmnChangeReqStatus_ReqTimedOut (6U)
 *   EDmnChangeReqStatus_DmnNotReady (7U)
 * EDmnHealthState_t: Enumeration of integer in interval [0...8] with enumerators
 *   EDmnHealth_Active (0U)
 *   EDmnHealth_UCL_Fatal_Error (1U)
 *   EDmnHealth_HB_Miss (2U)
 *   EDmnHealth_Fatal_Error (3U)
 *   EDmnHealth_Rcvd_Inv_SeqCnt (4U)
 *   EDmnHealth_First_HB_Rcv_Time_Expired (5U)
 *   EDmnHealth_First_LinkUp_Time_Expired (6U)
 *   EDmnHealth_Shutdown_Time_Expired (7U)
 *   EDmnHealth_Last (8U)
 * EDmnOverallState_t: Enumeration of integer in interval [0...1] with enumerators
 *   DMN_NOT_READY (0U)
 *   DMN_READY (1U)
 * EDomainId: Enumeration of integer in interval [0...3] with enumerators
 *   EDomainId_VP (0U)
 *   EDomainId_Cluster (1U)
 *   EDomainId_IVI (2U)
 *   EDomainId_Last (3U)
 * ESystemState: Enumeration of integer in interval [0...8] with enumerators
 *   ESystemState_Off (0U)
 *   ESystemState_Startup (1U)
 *   ESystemState_Up (2U)
 *   ESystemState_FullRun (3U)
 *   ESystemState_PrepareShutdown (4U)
 *   ESystemState_Minimal (5U)
 *   ESystemState_Meet (6U)
 *   ESystemState_Shutdown (7U)
 *   ESystemState_Last (8U)
 * EUclLinkState_t: Enumeration of integer in interval [0...3] with enumerators
 *   EUclLinkState_Not_Rcvd (0U)
 *   EUclLinkState_Down (1U)
 *   EUclLinkState_Up (2U)
 *   EUclLinkState_Last (3U)
 *
 * Array Types:
 * ============
 * data_u8_32: Array with 32 element(s) of type Rte_DT_data_u8_32_0
 *
 * Record Types:
 * =============
 * SDmnStatus: Record with elements
 *   dmnId of type EDomainId
 *   linkStatus of type EUclLinkState_t
 *   uclErrCode of type SInt32
 *   dmnHealthState of type EDmnHealthState_t
 *   state of type ESystemState
 *   dmnStatus of type EDmnOverallState_t
 * SHealthDomainFatalError: Record with elements
 *   domainId of type EDomainId
 *   compIdx of type UInt32
 * SHealthDomainHeartbeat: Record with elements
 *   domainId of type EDomainId
 *   seqCnt of type UInt32
 * SHealthDumpData: Record with elements
 *   chunkSize of type UInt32
 *   data of type data_u8_32
 * SHealthDumpGetData: Record with elements
 *   reserved of type UInt8
 * SHealthDumpGetHdr: Record with elements
 *   encrypt of type UInt8
 * SHealthDumpHdrInfo: Record with elements
 *   fileSize of type UInt32
 * SPowerExtendShutdownTime: Record with elements
 *   domainId of type EDomainId
 *   timeoutMs of type UInt32
 * SPowerKeepSystemAwake: Record with elements
 *   domainId of type EDomainId
 *   timeoutMs of type UInt32
 * SPowerSystemState: Record with elements
 *   domainId of type EDomainId
 *   state of type ESystemState
 * SPowerSystemStateReqChange: Record with elements
 *   state of type ESystemState
 *   domainId of type EDomainId
 *
 *********************************************************************************************************************/


#define DmnMgr_START_SEC_CODE
#include "DmnMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDmnMgr_Impl_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData(SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpData_HealthDumpDataData(SHealthDumpData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemState_PowerSystemStateData(SPowerSystemState *data)
 *   Std_ReturnType Rte_Read_rpSR_DmnInfo_SDmnStatus(SDmnStatus *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_HealthDumpGetData_HealthDumpGetDataData(const SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpGetHdr_HealthDumpGetHdrData(const SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(const SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Write_ppSR_DmnInfo_SDmnStatus(const SDmnStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpCS_UclInitShutdown_Impl_Initialize(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_UclInitShutdown_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_UclInitShutdown_Impl_Shutdown(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_UclInitShutdown_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_SleepOperation_CtrlWSS_CancelSleep(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_WSS_SleepOperations_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_SleepOperation_CtrlWSS_ReadytoSleep(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_WSS_SleepOperations_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_SleepOperation_CtrlWSS_RequestSleep(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_WSS_SleepOperations_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDmnMgr_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DmnMgr_CODE) CDmnMgr_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDmnMgr_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SHealthDomainFatalError Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData;
  SHealthDomainHeartbeat Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData;
  SHealthDumpData Receive_rSR_HealthDumpData_HealthDumpDataData;
  SHealthDumpHdrInfo Receive_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData;
  SPowerExtendShutdownTime Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData;
  SPowerKeepSystemAwake Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData;
  SPowerSystemState Read_rSR_PowerSystemState_PowerSystemStateData;
  SDmnStatus Read_rpSR_DmnInfo_SDmnStatus;

  SHealthDumpGetData Send_pSR_HealthDumpGetData_HealthDumpGetDataData = {
  0U
};
  SHealthDumpGetHdr Send_pSR_HealthDumpGetHdr_HealthDumpGetHdrData = {
  0U
};

  SPowerSystemStateReqChange Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SDmnStatus Write_ppSR_DmnInfo_SDmnStatus;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_DmnMgr_Rte_Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Receive_rSR_HealthDumpData_HealthDumpDataData(&Receive_rSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Receive_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Receive_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Read_rSR_PowerSystemState_PowerSystemStateData(&Read_rSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Read_rpSR_DmnInfo_SDmnStatus(&Read_rpSR_DmnInfo_SDmnStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Send_pSR_HealthDumpGetData_HealthDumpGetDataData(&Send_pSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Send_pSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Send_pSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData, 0, sizeof(Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData));
  fct_status = TSC_DmnMgr_Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_ppSR_DmnInfo_SDmnStatus, 0, sizeof(Write_ppSR_DmnInfo_SDmnStatus));
  fct_status = TSC_DmnMgr_Rte_Write_ppSR_DmnInfo_SDmnStatus(&Write_ppSR_DmnInfo_SDmnStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Call_rpCS_UclInitShutdown_Impl_Initialize();
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_UclInitShutdown_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Call_rpCS_UclInitShutdown_Impl_Shutdown();
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_UclInitShutdown_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Call_rp_CS_SleepOperation_CtrlWSS_CancelSleep();
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_WSS_SleepOperations_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Call_rp_CS_SleepOperation_CtrlWSS_ReadytoSleep();
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_WSS_SleepOperations_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DmnMgr_Rte_Call_rp_CS_SleepOperation_CtrlWSS_RequestSleep();
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_TI_WSS_SleepOperations_E_NOT_OK:
      fct_error = 1;
      break;
  }

  DmnMgr_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDmnMgr_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd_CDmnMgr>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CDmnMgr_Impl_OnCommand(ECmpCmd cmdP)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDmnMgr_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DmnMgr_CODE) CDmnMgr_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDmnMgr_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_DmnSystemStateChangeReq
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DmnSystemStateChangeReq> of PortPrototype <ppCS_DmnSystemStateChange>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DmnMgr_DmnSystemStateChangeReq(EDomainId DmnId, ESystemState DmnState)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_DmnSystemStateChange_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_DmnSystemStateChangeReq_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DmnMgr_CODE) DmnMgr_DmnSystemStateChangeReq(EDomainId DmnId, ESystemState DmnState) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_DmnSystemStateChangeReq (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_DmnSystemStateChangeStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DmnSystemStateChangeStatus> of PortPrototype <ppCS_DmnSystemStateChange>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DmnMgr_DmnSystemStateChangeStatus(EDomainId DmnId, EDmnChangeReqStatus_t *DmnStatus)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_DmnSystemStateChangeStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DmnMgr_CODE) DmnMgr_DmnSystemStateChangeStatus(EDomainId DmnId, P2VAR(EDmnChangeReqStatus_t, AUTOMATIC, RTE_DMNMGR_APPL_VAR) DmnStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_DmnSystemStateChangeStatus
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_ErrorNotification
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ErrorNotification> of PortPrototype <ppCS_UclSystemCallbacks>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DmnMgr_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_ErrorNotification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DmnMgr_CODE) DmnMgr_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_ErrorNotification
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_LinkStatusChanged
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <LinkStatusChanged> of PortPrototype <ppCS_UclSystemCallbacks>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DmnMgr_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_LinkStatusChanged_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DmnMgr_CODE) DmnMgr_LinkStatusChanged(UInt8 DLInst, SInt32 Status) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_LinkStatusChanged
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_MonitorDmnExtendShutdownTime
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <PowerExtendShutdownTimeData> of PortPrototype <rSR_PowerExtendShutdownTime>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnExtendShutdownTime_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnExtendShutdownTime(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnExtendShutdownTime
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_MonitorDmnHealthDumpData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <HealthDumpDataData> of PortPrototype <rSR_HealthDumpData>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnHealthDumpData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnHealthDumpData(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnHealthDumpData
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_MonitorDmnHealthDumpHdrInfo
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <HealthDumpHdrInfoData> of PortPrototype <rSR_HealthDumpHdrInfo>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnHealthDumpHdrInfo_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnHealthDumpHdrInfo(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnHealthDumpHdrInfo
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_MonitorDmnHealthFatalError
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <HealthDomainFatalErrorData> of PortPrototype <rSR_HealthDomainFatalError>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnHealthFatalError_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnHealthFatalError(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnHealthFatalError
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_MonitorDmnHeartBeat
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <HealthDomainHeartbeatData> of PortPrototype <rSR_HealthDomainHeartbeat>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnHeartBeat_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnHeartBeat(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnHeartBeat
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_MonitorDmnKeepSystemAwake
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <PowerKeepSystemAwakeData> of PortPrototype <rSR_PowerKeepSystemAwake>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnKeepSystemAwake_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnKeepSystemAwake(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnKeepSystemAwake
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_MonitorDmnPowerSystemState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <PowerSystemStateData> of PortPrototype <rSR_PowerSystemState>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnPowerSystemState_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DmnMgr_CODE) DmnMgr_MonitorDmnPowerSystemState(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_MonitorDmnPowerSystemState
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_StartDomainMonitoring
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <StartDomainMonitoring> of PortPrototype <ppCS_DomainMonitoring>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DmnMgr_StartDomainMonitoring(EDomainId DmnID)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_DmnMonitoring_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_StartDomainMonitoring_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DmnMgr_CODE) DmnMgr_StartDomainMonitoring(EDomainId DmnID) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_StartDomainMonitoring (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmnMgr_StopDomainMonitoring
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <StopDomainMonitoring> of PortPrototype <ppCS_DomainMonitoring>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DmnMgr_StopDomainMonitoring(EDomainId DmnID)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_DmnMonitoring_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_StopDomainMonitoring_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DmnMgr_CODE) DmnMgr_StopDomainMonitoring(EDomainId DmnID) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmnMgr_StopDomainMonitoring (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define DmnMgr_STOP_SEC_CODE
#include "DmnMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void DmnMgr_TestDefines(void)
{
  /* Enumeration Data Types */

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  EDmnChangeReqStatus_t Test_EDmnChangeReqStatus_t_V_1 = EDmnChangeReqStatus_NoReq;
  EDmnChangeReqStatus_t Test_EDmnChangeReqStatus_t_V_2 = EDmnChangeReqStatus_WaitAwakeTime;
  EDmnChangeReqStatus_t Test_EDmnChangeReqStatus_t_V_3 = EDmnChangeReqStatus_WaitShutdonwTime;
  EDmnChangeReqStatus_t Test_EDmnChangeReqStatus_t_V_4 = EDmnChangeReqStatus_PrevReqPending;
  EDmnChangeReqStatus_t Test_EDmnChangeReqStatus_t_V_5 = EDmnChangeReqStatus_ReqSucceed;
  EDmnChangeReqStatus_t Test_EDmnChangeReqStatus_t_V_6 = EDmnChangeReqStatus_ReqFail;
  EDmnChangeReqStatus_t Test_EDmnChangeReqStatus_t_V_7 = EDmnChangeReqStatus_ReqTimedOut;
  EDmnChangeReqStatus_t Test_EDmnChangeReqStatus_t_V_8 = EDmnChangeReqStatus_DmnNotReady;

  EDmnHealthState_t Test_EDmnHealthState_t_V_1 = EDmnHealth_Active;
  EDmnHealthState_t Test_EDmnHealthState_t_V_2 = EDmnHealth_UCL_Fatal_Error;
  EDmnHealthState_t Test_EDmnHealthState_t_V_3 = EDmnHealth_HB_Miss;
  EDmnHealthState_t Test_EDmnHealthState_t_V_4 = EDmnHealth_Fatal_Error;
  EDmnHealthState_t Test_EDmnHealthState_t_V_5 = EDmnHealth_Rcvd_Inv_SeqCnt;
  EDmnHealthState_t Test_EDmnHealthState_t_V_6 = EDmnHealth_First_HB_Rcv_Time_Expired;
  EDmnHealthState_t Test_EDmnHealthState_t_V_7 = EDmnHealth_First_LinkUp_Time_Expired;
  EDmnHealthState_t Test_EDmnHealthState_t_V_8 = EDmnHealth_Shutdown_Time_Expired;
  EDmnHealthState_t Test_EDmnHealthState_t_V_9 = EDmnHealth_Last;

  EDmnOverallState_t Test_EDmnOverallState_t_V_1 = DMN_NOT_READY;
  EDmnOverallState_t Test_EDmnOverallState_t_V_2 = DMN_READY;

  EDomainId Test_EDomainId_V_1 = EDomainId_VP;
  EDomainId Test_EDomainId_V_2 = EDomainId_Cluster;
  EDomainId Test_EDomainId_V_3 = EDomainId_IVI;
  EDomainId Test_EDomainId_V_4 = EDomainId_Last;

  ESystemState Test_ESystemState_V_1 = ESystemState_Off;
  ESystemState Test_ESystemState_V_2 = ESystemState_Startup;
  ESystemState Test_ESystemState_V_3 = ESystemState_Up;
  ESystemState Test_ESystemState_V_4 = ESystemState_FullRun;
  ESystemState Test_ESystemState_V_5 = ESystemState_PrepareShutdown;
  ESystemState Test_ESystemState_V_6 = ESystemState_Minimal;
  ESystemState Test_ESystemState_V_7 = ESystemState_Meet;
  ESystemState Test_ESystemState_V_8 = ESystemState_Shutdown;
  ESystemState Test_ESystemState_V_9 = ESystemState_Last;

  EUclLinkState_t Test_EUclLinkState_t_V_1 = EUclLinkState_Not_Rcvd;
  EUclLinkState_t Test_EUclLinkState_t_V_2 = EUclLinkState_Down;
  EUclLinkState_t Test_EUclLinkState_t_V_3 = EUclLinkState_Up;
  EUclLinkState_t Test_EUclLinkState_t_V_4 = EUclLinkState_Last;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
