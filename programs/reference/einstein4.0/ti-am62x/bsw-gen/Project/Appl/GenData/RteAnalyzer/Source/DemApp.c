/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  DemApp.c
 *        Config:  BMW.dpa
 *     SW-C Type:  DemApp
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <DemApp>
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

#include "Rte_DemApp.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_DemApp.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void DemApp_TestDefines(void);


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
 * Dem_EventIdType: Integer in interval [0...65535]
 * Dem_EventStatusType: Integer in interval [0...255]
 * Dem_OperationCycleStateType: Integer in interval [0...255]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   eCmpCmd_Init (0U)
 *   eCmpCmd_DeInit (1U)
 *   eCmpCmd_Activate (2U)
 *   eCmpCmd_DeActivate (3U)
 *
 *********************************************************************************************************************/


#define DemApp_START_SEC_CODE
#include "DemApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDemApp_Impl_MainFunction
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rp_CS_DemExt_ClearDTC_DemExt_ClearDTC(UInt8 ClientId)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_DemExt_ClearDTC_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_DemExt_SetEventStatus_DemExt_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_DemExt_SetEventStatus_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_DemExt_SetOperationCycleState_DemExt_SetOperationCycleState(UInt8 OperationCycleId, Dem_OperationCycleStateType CycleState)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_DemExt_SetOperationCycleState_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CDemApp_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DemApp_CODE) CDemApp_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDemApp_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_DemApp_Rte_Call_rp_CS_DemExt_ClearDTC_DemExt_ClearDTC(0U);
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
    case RTE_E_TI_DemExt_ClearDTC_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DemApp_Rte_Call_rp_CS_DemExt_SetEventStatus_DemExt_SetEventStatus(0U, 0U);
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
    case RTE_E_TI_DemExt_SetEventStatus_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DemApp_Rte_Call_rp_CS_DemExt_SetOperationCycleState_DemExt_SetOperationCycleState(0U, 0U);
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
    case RTE_E_TI_DemExt_SetOperationCycleState_E_NOT_OK:
      fct_error = 1;
      break;
  }

  DemApp_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDemApp_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd_CDemApp>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rp_CS_DemExt_ClearDTC_DemExt_ClearDTC(UInt8 ClientId)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_DemExt_ClearDTC_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_DemExt_SetEventStatus_DemExt_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_DemExt_SetEventStatus_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_DemExt_SetOperationCycleState_DemExt_SetOperationCycleState(UInt8 OperationCycleId, Dem_OperationCycleStateType CycleState)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_DemExt_SetOperationCycleState_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CDemApp_Impl_OnCommand(ECmpCmd cmdP)
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
 * Symbol: CDemApp_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DemApp_CODE) CDemApp_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDemApp_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_DemApp_Rte_Call_rp_CS_DemExt_ClearDTC_DemExt_ClearDTC(0U);
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
    case RTE_E_TI_DemExt_ClearDTC_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DemApp_Rte_Call_rp_CS_DemExt_SetEventStatus_DemExt_SetEventStatus(0U, 0U);
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
    case RTE_E_TI_DemExt_SetEventStatus_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_DemApp_Rte_Call_rp_CS_DemExt_SetOperationCycleState_DemExt_SetOperationCycleState(0U, 0U);
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
    case RTE_E_TI_DemExt_SetOperationCycleState_E_NOT_OK:
      fct_error = 1;
      break;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define DemApp_STOP_SEC_CODE
#include "DemApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void DemApp_TestDefines(void)
{
  /* Enumeration Data Types */

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;
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
