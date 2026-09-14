/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  UclProxyCdd.c
 *        Config:  BMW.dpa"
 *     SW-C Type:  UclProxyCdd
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <UclProxyCdd>
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

#include "Rte_UclProxyCdd.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_UclProxyCdd.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void UclProxyCdd_TestDefines(void);


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
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * EDisplayStatus: Enumeration of integer in interval [0...255] with enumerators
 *   EDisplayState_Off (0U)
 *   EDisplayState_On (1U)
 *   EDisplayState_Error (2U)
 *   EDisplayState_Disconnected (3U)
 *   EDisplayState_Last (4U)
 * EDomainId: Enumeration of integer in interval [0...255] with enumerators
 *   EDomainId_VP (0U)
 *   EDomainId_Cluster (1U)
 *   EDomainId_IVI (2U)
 *   EDomainId_Last (3U)
 * EIgnitionStatus: Enumeration of integer in interval [0...255] with enumerators
 *   EIgnitionStatus_Off (0U)
 *   EIgnitionStatus_Acc (1U)
 *   EIgnitionStatus_Start (2U)
 *   EIgnitionStatus_Run (3U)
 *   EIgnitionStatus_Last (4U)
 * ESystemState: Enumeration of integer in interval [0...255] with enumerators
 *   ESystemState_Off (0U)
 *   ESystemState_Startup (1U)
 *   ESystemState_Up (2U)
 *   ESystemState_FullRun (3U)
 *   ESystemState_PrepareShutdown (4U)
 *   ESystemState_Minimal (5U)
 *   ESystemState_Shutdown (6U)
 *   ESystemState_Meet (7U)
 *   ESystemState_Last (8U)
 * EnetReqCmd_t: Enumeration of integer in interval [0...255] with enumerators
 *   EnetReqType_Reset (1U)
 *   EnetReqType_linkStatus (2U)
 *   EnetReqType_SqiVal (3U)
 *   EnetReqType_WorstSqiVal (4U)
 *   EnetReqType_BestSqiVal (5U)
 *   EnetReqType_FaultStatus (6U)
 *   EnetReqType_CableStatus (7U)
 *   EnetReqType_masterSlaveStatus (8U)
 *   EnetReqType_Last (9U)
 * EnetReqMode_t: Enumeration of integer in interval [0...255] with enumerators
 *   EnetReqMode_Read (0U)
 *   EnetReqMode_Write (1U)
 *   EnetReqMode_Last (2U)
 *
 * Array Types:
 * ============
 * data_u8_32: Array with 32 element(s) of type uint8
 * data_u8_8: Array with 8 element(s) of type uint8
 *
 * Record Types:
 * =============
 * SDisplayCurrentState: Record with elements
 *   displayId of type uint32
 *   state of type EDisplayStatus
 * SEnetRegReq: Record with elements
 *   cmd of type EnetReqCmd_t
 *   mode of type EnetReqMode_t
 *   dataLen of type uint8
 *   data of type data_u8_8
 * SEnetRegResp: Record with elements
 *   cmd of type EnetReqCmd_t
 *   respLen of type uint8
 *   response of type data_u8_32
 * SHealthDomainFatalError: Record with elements
 *   domainId of type uint8
 *   compldx of type uint32
 * SHealthDomainHeartbeat: Record with elements
 *   domainId of type uint8
 *   seqCnt of type uint32
 * SHealthDumpGetData: Record with elements
 *   reserved of type uint8
 * SHealthDumpGetHdr: Record with elements
 *   encrypt of type uint8
 * SHealthDumpHdrInfo: Record with elements
 *   fileSize of type uint32
 * SHealthEventRecord: Record with elements
 *   recordType of type uint8
 *   recordLen of type uint8
 *   recordData of type data_u8_8
 * SIgnState: Record with elements
 *   state of type EIgnitionStatus
 * SPowerExtendShutdownTime: Record with elements
 *   domainId of type EDomainId
 *   timeoutMs of type uint32
 * SPowerSystemState: Record with elements
 *   domainId of type EDomainId
 *   state of type ESystemState
 * SPowerSystemStateReqChange: Record with elements
 *   domainId of type EDomainId
 *   state of type ESystemState
 *
 *********************************************************************************************************************/


#define UclProxyCdd_START_SEC_CODE
#include "UclProxyCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CUclProxyCdd_Impl_Initialize
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Initialize> of PortPrototype <ppCS_UclInitShutdown>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CUclProxyCdd_Impl_Initialize(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_UclInitShutdown_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_Initialize_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Initialize(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_Initialize (returns application error)
 *********************************************************************************************************************/

  UclProxyCdd_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CUclProxyCdd_Impl_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rSR_EnetRegReq_EnetRegReqData(SEnetRegReq *data)
 *   Std_ReturnType Rte_Read_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Read_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Read_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EnetRegResp_EnetRegRespData(const SEnetRegResp *data)
 *   Std_ReturnType Rte_Write_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Write_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Write_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Write_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Write_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(uint8 DLInst, sint32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(uint8 DLInst, sint32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) CUclProxyCdd_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SEnetRegReq Read_rSR_EnetRegReq_EnetRegReqData;
  SHealthDumpGetData Read_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Read_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Read_rSR_IgnState_IgnStateData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;

  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEnetRegResp Write_pSR_EnetRegResp_EnetRegRespData;
  SHealthDomainFatalError Write_pSR_HealthDomainFatalError_HealthDomainFatalErrorData;
  SHealthDomainHeartbeat Write_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData;
  SHealthDumpHdrInfo Write_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData;
  SHealthEventRecord Write_pSR_HealthEventRecord_HealthEventRecordData;
  SPowerExtendShutdownTime Write_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_EnetRegReq_EnetRegReqData(&Read_rSR_EnetRegReq_EnetRegReqData);
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

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HealthDumpGetData_HealthDumpGetDataData(&Read_rSR_HealthDumpGetData_HealthDumpGetDataData);
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

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Read_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
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

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IgnState_IgnStateData(&Read_rSR_IgnState_IgnStateData);
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

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
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

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EnetRegResp_EnetRegRespData, 0, sizeof(Write_pSR_EnetRegResp_EnetRegRespData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EnetRegResp_EnetRegRespData(&Write_pSR_EnetRegResp_EnetRegRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HealthDomainFatalError_HealthDomainFatalErrorData, 0, sizeof(Write_pSR_HealthDomainFatalError_HealthDomainFatalErrorData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Write_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData, 0, sizeof(Write_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Write_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData, 0, sizeof(Write_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Write_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HealthEventRecord_HealthEventRecordData, 0, sizeof(Write_pSR_HealthEventRecord_HealthEventRecordData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HealthEventRecord_HealthEventRecordData(&Write_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData, 0, sizeof(Write_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Write_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
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
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
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
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CUclProxyCdd_Impl_OnCommand
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <OnCommand> of PortPrototype <ppCS_UclCmplibCmd>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CUclProxyCdd_Impl_OnCommand(uint8 Cmd)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_UclCmplibCmd_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_OnCommand(uint8 Cmd) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CUclProxyCdd_Impl_Shutdown
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Shutdown> of PortPrototype <ppCS_UclInitShutdown>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CUclProxyCdd_Impl_Shutdown(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_UclInitShutdown_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_Shutdown_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Shutdown(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_Shutdown (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_EnetRegReq
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <EnetRegReqData> of PortPrototype <rSR_EnetRegReq>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_EnetRegReq_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_EnetRegReq(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_EnetRegReq
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_HealthDumpGetData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <HealthDumpGetDataData> of PortPrototype <rSR_HealthDumpGetData>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_HealthDumpGetData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_HealthDumpGetData(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_HealthDumpGetData
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_HealthDumpGetHdr
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <HealthDumpGetHdrData> of PortPrototype <rSR_HealthDumpGetHdr>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_HealthDumpGetHdr_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_HealthDumpGetHdr(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_HealthDumpGetHdr
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_IgnState
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <IgnStateData> of PortPrototype <rSR_IgnState>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_IgnState_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_IgnState(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_IgnState
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_PowerSystemStateReqChange
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <PowerSystemStateReqChangeData> of PortPrototype <rSR_PowerSystemStateReqChange>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_PowerSystemStateReqChange_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_PowerSystemStateReqChange(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_PowerSystemStateReqChange
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define UclProxyCdd_STOP_SEC_CODE
#include "UclProxyCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void UclProxyCdd_TestDefines(void)
{
  /* Enumeration Data Types */

  EDisplayStatus Test_EDisplayStatus_V_1 = EDisplayState_Off;
  EDisplayStatus Test_EDisplayStatus_V_2 = EDisplayState_On;
  EDisplayStatus Test_EDisplayStatus_V_3 = EDisplayState_Error;
  EDisplayStatus Test_EDisplayStatus_V_4 = EDisplayState_Disconnected;
  EDisplayStatus Test_EDisplayStatus_V_5 = EDisplayState_Last;

  EDomainId Test_EDomainId_V_1 = EDomainId_VP;
  EDomainId Test_EDomainId_V_2 = EDomainId_Cluster;
  EDomainId Test_EDomainId_V_3 = EDomainId_IVI;
  EDomainId Test_EDomainId_V_4 = EDomainId_Last;

  EIgnitionStatus Test_EIgnitionStatus_V_1 = EIgnitionStatus_Off;
  EIgnitionStatus Test_EIgnitionStatus_V_2 = EIgnitionStatus_Acc;
  EIgnitionStatus Test_EIgnitionStatus_V_3 = EIgnitionStatus_Start;
  EIgnitionStatus Test_EIgnitionStatus_V_4 = EIgnitionStatus_Run;
  EIgnitionStatus Test_EIgnitionStatus_V_5 = EIgnitionStatus_Last;

  ESystemState Test_ESystemState_V_1 = ESystemState_Off;
  ESystemState Test_ESystemState_V_2 = ESystemState_Startup;
  ESystemState Test_ESystemState_V_3 = ESystemState_Up;
  ESystemState Test_ESystemState_V_4 = ESystemState_FullRun;
  ESystemState Test_ESystemState_V_5 = ESystemState_PrepareShutdown;
  ESystemState Test_ESystemState_V_6 = ESystemState_Minimal;
  ESystemState Test_ESystemState_V_7 = ESystemState_Shutdown;
  ESystemState Test_ESystemState_V_8 = ESystemState_Meet;
  ESystemState Test_ESystemState_V_9 = ESystemState_Last;

  EnetReqCmd_t Test_EnetReqCmd_t_V_1 = EnetReqType_Reset;
  EnetReqCmd_t Test_EnetReqCmd_t_V_2 = EnetReqType_linkStatus;
  EnetReqCmd_t Test_EnetReqCmd_t_V_3 = EnetReqType_SqiVal;
  EnetReqCmd_t Test_EnetReqCmd_t_V_4 = EnetReqType_WorstSqiVal;
  EnetReqCmd_t Test_EnetReqCmd_t_V_5 = EnetReqType_BestSqiVal;
  EnetReqCmd_t Test_EnetReqCmd_t_V_6 = EnetReqType_FaultStatus;
  EnetReqCmd_t Test_EnetReqCmd_t_V_7 = EnetReqType_CableStatus;
  EnetReqCmd_t Test_EnetReqCmd_t_V_8 = EnetReqType_masterSlaveStatus;
  EnetReqCmd_t Test_EnetReqCmd_t_V_9 = EnetReqType_Last;

  EnetReqMode_t Test_EnetReqMode_t_V_1 = EnetReqMode_Read;
  EnetReqMode_t Test_EnetReqMode_t_V_2 = EnetReqMode_Write;
  EnetReqMode_t Test_EnetReqMode_t_V_3 = EnetReqMode_Last;
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
