/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  DcmApp.c
 *        Config:  BMW.dpa
 *     SW-C Type:  DcmApp
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <DcmApp>
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

#include "Rte_DcmApp.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_DcmApp.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void DcmApp_TestDefines(void);


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
 * Dcm_NegativeResponseCodeType: Integer in interval [0...255]
 * UInt16: Integer in interval [0...65535]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   eCmpCmd_Init (0U)
 *   eCmpCmd_DeInit (1U)
 *   eCmpCmd_Activate (2U)
 *   eCmpCmd_DeActivate (3U)
 * teDIDOperation: Enumeration of integer in interval [0...7] with enumerators
 *   eRead (0U)
 *   eWrite (1U)
 *   eSTA (2U)
 *   eRCTECU (3U)
 *   eCheckConditions (4U)
 *   eRST2DEFAULT (5U)
 *   eFCS (6U)
 *   eLengthCheck (7U)
 * teDiagOpStatus: Enumeration of integer in interval [0...64] with enumerators
 *   DIAG_INITIAL (0U)
 *   DIAG_PENDING (1U)
 *   DIAG_CANCEL (2U)
 *   DIAG_FORCE_RCRRP_OK (3U)
 *   DIAG_FORCE_RCRRP_NOT_OK (64U)
 * teRoutineOperation: Enumeration of integer in interval [0...2] with enumerators
 *   eRoutineStart (0U)
 *   eRoutineStop (1U)
 *   eRoutineResult (2U)
 *
 *********************************************************************************************************************/


#define DcmApp_START_SEC_CODE
#include "DcmApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDcmApp_DID_DiagAction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DID_DiagAction> of PortPrototype <pp_CS_DID_App_Diag_Action>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CDcmApp_DID_DiagAction(teDiagOpStatus OpStatus, UInt16 DIDNum, UInt8 *Data, UInt8 *pNrc, teDIDOperation eOperation)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_DID_App_Diag_Action_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDcmApp_DID_DiagAction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DcmApp_CODE) CDcmApp_DID_DiagAction(teDiagOpStatus OpStatus, UInt16 DIDNum, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) Data, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) pNrc, teDIDOperation eOperation) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDcmApp_DID_DiagAction (returns application error)
 *********************************************************************************************************************/

  DcmApp_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDcmApp_Diag_Entry_Status
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Diag_Entry_Status> of PortPrototype <pp_CS_DiagEntryStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CDcmApp_Diag_Entry_Status(UInt8 SID, UInt8 *RequestData, UInt16 RequestDataSize, UInt8 ReqType, UInt16 SourceAddress, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_DiagEntrySts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDcmApp_Diag_Entry_Status_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DcmApp_CODE) CDcmApp_Diag_Entry_Status(UInt8 SID, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) RequestData, UInt16 RequestDataSize, UInt8 ReqType, UInt16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCMAPP_APPL_VAR) ErrorCode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDcmApp_Diag_Entry_Status (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDcmApp_Impl_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDcmApp_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DcmApp_CODE) CDcmApp_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDcmApp_Impl_MainFunction
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDcmApp_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd_CDcmApp>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CDcmApp_Impl_OnCommand(ECmpCmd cmdP)
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
 * Symbol: CDcmApp_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DcmApp_CODE) CDcmApp_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDcmApp_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDcmApp_RID_DiagAction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RID_DiagAction> of PortPrototype <pp_CS_RID_App_Diag_Action>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CDcmApp_RID_DiagAction(teDiagOpStatus OpStatus, UInt16 RIDNum, UInt8 *Out_RoutineInfo, UInt8 *Data, UInt16 *DataLength, UInt8 *pNrc, teRoutineOperation eOperation)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TI_RID_App_Diag_Action_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDcmApp_RID_DiagAction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DcmApp_CODE) CDcmApp_RID_DiagAction(teDiagOpStatus OpStatus, UInt16 RIDNum, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) Out_RoutineInfo, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) Data, P2VAR(UInt16, AUTOMATIC, RTE_DCMAPP_APPL_VAR) DataLength, P2VAR(UInt8, AUTOMATIC, RTE_DCMAPP_APPL_VAR) pNrc, teRoutineOperation eOperation) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDcmApp_RID_DiagAction (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define DcmApp_STOP_SEC_CODE
#include "DcmApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void DcmApp_TestDefines(void)
{
  /* Enumeration Data Types */

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  teDIDOperation Test_teDIDOperation_V_1 = eRead;
  teDIDOperation Test_teDIDOperation_V_2 = eWrite;
  teDIDOperation Test_teDIDOperation_V_3 = eSTA;
  teDIDOperation Test_teDIDOperation_V_4 = eRCTECU;
  teDIDOperation Test_teDIDOperation_V_5 = eCheckConditions;
  teDIDOperation Test_teDIDOperation_V_6 = eRST2DEFAULT;
  teDIDOperation Test_teDIDOperation_V_7 = eFCS;
  teDIDOperation Test_teDIDOperation_V_8 = eLengthCheck;

  teDiagOpStatus Test_teDiagOpStatus_V_1 = DIAG_INITIAL;
  teDiagOpStatus Test_teDiagOpStatus_V_2 = DIAG_PENDING;
  teDiagOpStatus Test_teDiagOpStatus_V_3 = DIAG_CANCEL;
  teDiagOpStatus Test_teDiagOpStatus_V_4 = DIAG_FORCE_RCRRP_OK;
  teDiagOpStatus Test_teDiagOpStatus_V_5 = DIAG_FORCE_RCRRP_NOT_OK;

  teRoutineOperation Test_teRoutineOperation_V_1 = eRoutineStart;
  teRoutineOperation Test_teRoutineOperation_V_2 = eRoutineStop;
  teRoutineOperation Test_teRoutineOperation_V_3 = eRoutineResult;
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
