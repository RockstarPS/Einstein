/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Dlt.c
 *        Config:  BMW.dpa
 *     SW-C Type:  Dlt
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <Dlt>
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

#include "Rte_Dlt.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Dlt.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Dlt_TestDefines(void);


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
 * Boolean: Boolean
 * Dlt_MessageArgumentCount: Integer in interval [0...65535]
 * Dlt_MessageOptionsType: Integer in interval [0...255]
 * Dlt_SessionIDType: Integer in interval [0...4294967295]
 * Rte_DT_Dlt_ApplicationIDType_0: Integer in interval [0...255]
 * Rte_DT_Dlt_ContextIDType_0: Integer in interval [0...255]
 * Rte_DT_Dlt_LogChannelNameType_0: Integer in interval [0...255]
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * Dlt_AssignmentOperation: Enumeration of integer in interval [1...2] with enumerators
 *   DLT_ASSIGN_ADD (1U)
 *   DLT_ASSIGN_REMOVE (2U)
 * Dlt_MessageLogLevelType: Enumeration of integer in interval [0...6] with enumerators
 *   DLT_LOG_OFF (0U)
 *   DLT_LOG_FATAL (1U)
 *   DLT_LOG_ERROR (2U)
 *   DLT_LOG_WARN (3U)
 *   DLT_LOG_INFO (4U)
 *   DLT_LOG_DEBUG (5U)
 *   DLT_LOG_VERBOSE (6U)
 * Dlt_MessageTraceType: Enumeration of integer in interval [1...5] with enumerators
 *   DLT_TRACE_VARIABLE (1U)
 *   DLT_TRACE_FUNCTION_IN (2U)
 *   DLT_TRACE_FUNCTION_OUT (3U)
 *   DLT_TRACE_STATE (4U)
 *   DLT_TRACE_VFB (5U)
 *
 * Array Types:
 * ============
 * Dlt_ApplicationIDType: Array with 4 element(s) of type Rte_DT_Dlt_ApplicationIDType_0
 * Dlt_ContextIDType: Array with 4 element(s) of type Rte_DT_Dlt_ContextIDType_0
 * Dlt_LogChannelNameType: Array with 4 element(s) of type Rte_DT_Dlt_LogChannelNameType_0
 *
 * Record Types:
 * =============
 * Dlt_ApplicationIdInfoType: Record with elements
 *   appId of type Dlt_ApplicationIDType
 *   contextIdCount of type UInt16
 *   contextInfoList of type Dlt_ContextIdInfoType
 *   appDescLen of type UInt16
 *   appDesc of type UInt8
 * Dlt_ContextIdInfoType: Record with elements
 *   contextId of type Dlt_ContextIDType
 *   logLevel of type Dlt_MessageLogLevelType
 *   traceStatus of type UInt8
 *   lenContextDescription of type UInt16
 *   contextDesc of type UInt8
 * Dlt_LogInfoType: Record with elements
 *   appIdCount of type UInt16
 *   appIdInfo of type Dlt_ApplicationIdInfoType
 * Dlt_MessageLogInfoType: Record with elements
 *   argCount of type Dlt_MessageArgumentCount
 *   logLevel of type Dlt_MessageLogLevelType
 *   options of type Dlt_MessageOptionsType
 *   contextId of type Dlt_ContextIDType
 *   appId of type Dlt_ApplicationIDType
 * Dlt_MessageTraceInfoType: Record with elements
 *   traceInfo of type Dlt_MessageTraceType
 *   options of type Dlt_MessageOptionsType
 *   context of type Dlt_ContextIDType
 *   appId of type Dlt_ApplicationIDType
 *
 *********************************************************************************************************************/


#define Dlt_START_SEC_CODE
#include "Dlt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_DetForwardErrorTrace
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DetForwardErrorTrace> of PortPrototype <ppCS_Dlt_DetForwardErrorTrace>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Dlt_DetForwardErrorTrace(UInt16 moduleId, UInt8 instanceId, UInt8 apiId, UInt8 errorId)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_DetForwardErrorTrace_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Dlt_CODE) Dlt_DetForwardErrorTrace(UInt16 moduleId, UInt8 instanceId, UInt8 apiId, UInt8 errorId) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_DetForwardErrorTrace
 *********************************************************************************************************************/

  Dlt_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_GetDefaultLogLevel
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDefaultLogLevel> of PortPrototype <ppCS_Dlt_GetDefaultLogLevel>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_GetDefaultLogLevel(Dlt_MessageLogLevelType *defaultLogLevel)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_GetDefaultLogLevel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetDefaultLogLevel_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetDefaultLogLevel(P2VAR(Dlt_MessageLogLevelType, AUTOMATIC, RTE_DLT_APPL_VAR) defaultLogLevel) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetDefaultLogLevel (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_GetDefaultTraceStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDefaultTraceStatus> of PortPrototype <ppCS_Dlt_GetDefaultTraceStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_GetDefaultTraceStatus(Rte_DT_Dlt_LogChannelNameType_0 *logChannelName, Boolean *traceStatus)
 *     Argument logChannelName: Rte_DT_Dlt_LogChannelNameType_0* is of type Dlt_LogChannelNameType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_GetDefaultTraceStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetDefaultTraceStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetDefaultTraceStatus(P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetDefaultTraceStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_GetLogChannelNames
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetLogChannelNames> of PortPrototype <ppCS_Dlt_GetLogChannelNames>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_GetLogChannelNames(UInt8 *numberOfLogChannels, Rte_DT_Dlt_LogChannelNameType_0 *logChannelNames)
 *     Argument logChannelNames: Rte_DT_Dlt_LogChannelNameType_0* is of type Dlt_LogChannelNameType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_GetLogChannelNames_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetLogChannelNames_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogChannelNames(P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) numberOfLogChannels, P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelNames) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetLogChannelNames (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_GetLogChannelThreshold
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetLogChannelThreshold> of PortPrototype <ppCS_Dlt_GetLogChannelThreshold>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_GetLogChannelThreshold(Rte_DT_Dlt_LogChannelNameType_0 *logChannelName, Dlt_MessageLogLevelType *logChannelThreshold, Boolean *traceStatus)
 *     Argument logChannelName: Rte_DT_Dlt_LogChannelNameType_0* is of type Dlt_LogChannelNameType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_GetLogChannelThreshold_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetLogChannelThreshold_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogChannelThreshold(P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, P2VAR(Dlt_MessageLogLevelType, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelThreshold, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetLogChannelThreshold (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_GetLogInfo
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetLogInfo> of PortPrototype <ppCS_Dlt_GetLogInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_GetLogInfo(UInt8 options, Rte_DT_Dlt_ApplicationIDType_0 *appId, Rte_DT_Dlt_ContextIDType_0 *contextId, UInt8 *status, Dlt_LogInfoType *logInfo)
 *     Argument appId: Rte_DT_Dlt_ApplicationIDType_0* is of type Dlt_ApplicationIDType
 *     Argument contextId: Rte_DT_Dlt_ContextIDType_0* is of type Dlt_ContextIDType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_GetLogInfo_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetLogInfo_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetLogInfo(UInt8 options, P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) status, P2VAR(Dlt_LogInfoType, AUTOMATIC, RTE_DLT_APPL_VAR) logInfo) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetLogInfo (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_GetTraceStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetTraceStatus> of PortPrototype <ppCS_Dlt_GetTraceStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_GetTraceStatus(Rte_DT_Dlt_ApplicationIDType_0 *appId, Rte_DT_Dlt_ContextIDType_0 *contextId, Boolean *traceStatus)
 *     Argument appId: Rte_DT_Dlt_ApplicationIDType_0* is of type Dlt_ApplicationIDType
 *     Argument contextId: Rte_DT_Dlt_ContextIDType_0* is of type Dlt_ContextIDType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_GetTraceStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetTraceStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_GetTraceStatus(P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(Boolean, AUTOMATIC, RTE_DLT_APPL_VAR) traceStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_GetTraceStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_InjectCall_SESSION
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InjectCall_SESSION> of PortPrototype <ppCS_Dlt_InjectCall_SESSION>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Dlt_InjectCall_SESSION(Rte_DT_Dlt_ApplicationIDType_0 *appId, Rte_DT_Dlt_ContextIDType_0 *contextId, UInt32 serviceId, UInt32 dataLength, UInt8 *data)
 *     Argument appId: Rte_DT_Dlt_ApplicationIDType_0* is of type Dlt_ApplicationIDType
 *     Argument contextId: Rte_DT_Dlt_ContextIDType_0* is of type Dlt_ContextIDType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_InjectCall_SESSION_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Dlt_CODE) Dlt_InjectCall_SESSION(P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, UInt32 serviceId, UInt32 dataLength, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) data) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_InjectCall_SESSION
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rpCS_EcumExt_GetResetReason_GetResetReason(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_EcuMExt_GetResetReason_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Dlt_CODE) Dlt_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Dlt_Rte_Call_rpCS_EcumExt_GetResetReason_GetResetReason();
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
    case RTE_E_TI_EcuMExt_GetResetReason_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_RegisterContext
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RegisterContext> of PortPrototype <ppCS_Dlt_RegisterContext>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_RegisterContext(Dlt_SessionIDType sessionId, Rte_DT_Dlt_ApplicationIDType_0 *appId, Rte_DT_Dlt_ContextIDType_0 *contextId, UInt8 *appDescription, UInt8 lenAppDescription, UInt8 *contextDescription, UInt8 lenContextDescription)
 *     Argument appId: Rte_DT_Dlt_ApplicationIDType_0* is of type Dlt_ApplicationIDType
 *     Argument contextId: Rte_DT_Dlt_ContextIDType_0* is of type Dlt_ContextIDType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_RegisterContext_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_RegisterContext_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_RegisterContext(Dlt_SessionIDType sessionId, P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) appDescription, UInt8 lenAppDescription, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) contextDescription, UInt8 lenContextDescription) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_RegisterContext (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_ResetToFactoryDefault
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetToFactoryDefault> of PortPrototype <ppCS_Dlt_ResetToFactoryDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_ResetToFactoryDefault(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_ResetToFactoryDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_ResetToFactoryDefault_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_ResetToFactoryDefault(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_ResetToFactoryDefault (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_SendLogMessage
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SendLogMessage> of PortPrototype <ppCS_Dlt_SendLogMessage>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_SendLogMessage(Dlt_SessionIDType sessionId, const Dlt_MessageLogInfoType *logInfo, UInt8 *logData, UInt16 logDataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_SendLogMessage_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SendLogMessage_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_SendLogMessage(Dlt_SessionIDType sessionId, P2CONST(Dlt_MessageLogInfoType, AUTOMATIC, RTE_DLT_APPL_DATA) logInfo, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) logData, UInt16 logDataLength) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SendLogMessage (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_SendTraceMessage
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SendTraceMessage> of PortPrototype <ppCS_Dlt_SendTraceMessage>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_SendTraceMessage(Dlt_SessionIDType sessionId, const Dlt_MessageTraceInfoType *traceInfo, UInt8 *traceData, UInt16 traceDataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_SendTraceMessage_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SendTraceMessage_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_SendTraceMessage(Dlt_SessionIDType sessionId, P2CONST(Dlt_MessageTraceInfoType, AUTOMATIC, RTE_DLT_APPL_DATA) traceInfo, P2VAR(UInt8, AUTOMATIC, RTE_DLT_APPL_VAR) traceData, UInt16 traceDataLength) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SendTraceMessage (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_SetDefaultLogLevel
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetDefaultLogLevel> of PortPrototype <ppCS_Dlt_SetDefaultLogLevel>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_SetDefaultLogLevel(Dlt_MessageLogLevelType newLogLevel)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_SetDefaultLogLevel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetDefaultLogLevel_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetDefaultLogLevel(Dlt_MessageLogLevelType newLogLevel) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetDefaultLogLevel (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_SetDefaultTraceStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetDefaultTraceStatus> of PortPrototype <ppCS_Dlt_SetDefaultTraceStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_SetDefaultTraceStatus(Boolean newTraceStatus, Rte_DT_Dlt_LogChannelNameType_0 *logChannelName)
 *     Argument logChannelName: Rte_DT_Dlt_LogChannelNameType_0* is of type Dlt_LogChannelNameType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_SetDefaultTraceStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetDefaultTraceStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetDefaultTraceStatus(Boolean newTraceStatus, P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetDefaultTraceStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_SetLogChannelAssignment
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetLogChannelAssignment> of PortPrototype <ppCS_Dlt_SetLogChannelAssignment>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_SetLogChannelAssignment(Rte_DT_Dlt_ApplicationIDType_0 *appId, Rte_DT_Dlt_ContextIDType_0 *contextId, Rte_DT_Dlt_LogChannelNameType_0 *logChannelName, Dlt_AssignmentOperation addRemoveOp)
 *     Argument appId: Rte_DT_Dlt_ApplicationIDType_0* is of type Dlt_ApplicationIDType
 *     Argument contextId: Rte_DT_Dlt_ContextIDType_0* is of type Dlt_ContextIDType
 *     Argument logChannelName: Rte_DT_Dlt_LogChannelNameType_0* is of type Dlt_LogChannelNameType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_SetLogChannelAssignment_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetLogChannelAssignment_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogChannelAssignment(P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, Dlt_AssignmentOperation addRemoveOp) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetLogChannelAssignment (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_SetLogChannelThreshold
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetLogChannelThreshold> of PortPrototype <ppCS_Dlt_SetLogChannelThreshold>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_SetLogChannelThreshold(Rte_DT_Dlt_LogChannelNameType_0 *logChannelName, Dlt_MessageLogLevelType newThreshold, Boolean newTraceStatus)
 *     Argument logChannelName: Rte_DT_Dlt_LogChannelNameType_0* is of type Dlt_LogChannelNameType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_SetLogChannelThreshold_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetLogChannelThreshold_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogChannelThreshold(P2VAR(Rte_DT_Dlt_LogChannelNameType_0, AUTOMATIC, RTE_DLT_APPL_VAR) logChannelName, Dlt_MessageLogLevelType newThreshold, Boolean newTraceStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetLogChannelThreshold (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_SetLogLevel
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetLogLevel> of PortPrototype <ppCS_Dlt_SetLogLevel>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_SetLogLevel(Rte_DT_Dlt_ApplicationIDType_0 *appId, Rte_DT_Dlt_ContextIDType_0 *contextId, Dlt_MessageLogLevelType newLogLevel)
 *     Argument appId: Rte_DT_Dlt_ApplicationIDType_0* is of type Dlt_ApplicationIDType
 *     Argument contextId: Rte_DT_Dlt_ContextIDType_0* is of type Dlt_ContextIDType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_SetLogLevel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetLogLevel_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetLogLevel(P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, Dlt_MessageLogLevelType newLogLevel) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetLogLevel (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_SetTraceStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetTraceStatus> of PortPrototype <ppCS_Dlt_SetTraceStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_SetTraceStatus(Rte_DT_Dlt_ApplicationIDType_0 *appId, Rte_DT_Dlt_ContextIDType_0 *contextId, Boolean newTraceStatus)
 *     Argument appId: Rte_DT_Dlt_ApplicationIDType_0* is of type Dlt_ApplicationIDType
 *     Argument contextId: Rte_DT_Dlt_ContextIDType_0* is of type Dlt_ContextIDType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_SetTraceStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetTraceStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_SetTraceStatus(P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId, Boolean newTraceStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_SetTraceStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_StoreConfiguration
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <StoreConfiguration> of PortPrototype <ppCS_Dlt_StoreConfiguration>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_StoreConfiguration(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_StoreConfiguration_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_StoreConfiguration_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_StoreConfiguration(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_StoreConfiguration (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dlt_UnregisterContext
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <UnregisterContext> of PortPrototype <ppCS_Dlt_UnregisterContext>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dlt_UnregisterContext(Dlt_SessionIDType sessionId, Rte_DT_Dlt_ApplicationIDType_0 *appId, Rte_DT_Dlt_ContextIDType_0 *contextId)
 *     Argument appId: Rte_DT_Dlt_ApplicationIDType_0* is of type Dlt_ApplicationIDType
 *     Argument contextId: Rte_DT_Dlt_ContextIDType_0* is of type Dlt_ContextIDType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_If_CS_Dlt_UnregisterContext_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_UnregisterContext_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dlt_CODE) Dlt_UnregisterContext(Dlt_SessionIDType sessionId, P2VAR(Rte_DT_Dlt_ApplicationIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) appId, P2VAR(Rte_DT_Dlt_ContextIDType_0, AUTOMATIC, RTE_DLT_APPL_VAR) contextId) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dlt_UnregisterContext (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Dlt_STOP_SEC_CODE
#include "Dlt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Dlt_TestDefines(void)
{
  /* Enumeration Data Types */

  Dlt_AssignmentOperation Test_Dlt_AssignmentOperation_V_1 = DLT_ASSIGN_ADD;
  Dlt_AssignmentOperation Test_Dlt_AssignmentOperation_V_2 = DLT_ASSIGN_REMOVE;

  Dlt_MessageLogLevelType Test_Dlt_MessageLogLevelType_V_1 = DLT_LOG_OFF;
  Dlt_MessageLogLevelType Test_Dlt_MessageLogLevelType_V_2 = DLT_LOG_FATAL;
  Dlt_MessageLogLevelType Test_Dlt_MessageLogLevelType_V_3 = DLT_LOG_ERROR;
  Dlt_MessageLogLevelType Test_Dlt_MessageLogLevelType_V_4 = DLT_LOG_WARN;
  Dlt_MessageLogLevelType Test_Dlt_MessageLogLevelType_V_5 = DLT_LOG_INFO;
  Dlt_MessageLogLevelType Test_Dlt_MessageLogLevelType_V_6 = DLT_LOG_DEBUG;
  Dlt_MessageLogLevelType Test_Dlt_MessageLogLevelType_V_7 = DLT_LOG_VERBOSE;

  Dlt_MessageTraceType Test_Dlt_MessageTraceType_V_1 = DLT_TRACE_VARIABLE;
  Dlt_MessageTraceType Test_Dlt_MessageTraceType_V_2 = DLT_TRACE_FUNCTION_IN;
  Dlt_MessageTraceType Test_Dlt_MessageTraceType_V_3 = DLT_TRACE_FUNCTION_OUT;
  Dlt_MessageTraceType Test_Dlt_MessageTraceType_V_4 = DLT_TRACE_STATE;
  Dlt_MessageTraceType Test_Dlt_MessageTraceType_V_5 = DLT_TRACE_VFB;
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
