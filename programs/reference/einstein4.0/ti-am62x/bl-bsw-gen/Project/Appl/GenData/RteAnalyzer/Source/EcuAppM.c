/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  EcuAppM.c
 *        Config:  BMW.dpa"
 *     SW-C Type:  EcuAppM
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <EcuAppM>
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

#include "Rte_EcuAppM.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_EcuAppM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void EcuAppM_TestDefines(void);


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
 * UInt16: Integer in interval [0...65535]
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
 * EDisplayType: Enumeration of integer in interval [0...1] with enumerators
 *   e_Display10Inch (0U)
 *   e_DisplayMaxDevice (1U)
 *
 *********************************************************************************************************************/


#define EcuAppM_START_SEC_CODE
#include "EcuAppM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EcuAppM_Init
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Init> of PortPrototype <ppCS_EcuAppM>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSR_SleepStatus_SleepManager_SleepStatus(UInt8 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_service_GetBrightnessValue(EDisplayType DeviceName, UInt16 *BrightnessPercentValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_service_GetThermalValue(EDisplayType DeviceName, UInt32 *TempValueInMilliCelsius)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_service_SetBrightnessValue(EDisplayType DeviceName, UInt16 BrightnessPercentValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand(ECmpCmd cmdP)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand(ECmpCmd cmdP)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepManager_Impl_OnCommand(ECmpCmd cmdP)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void EcuAppM_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuAppM_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EcuAppM_CODE) EcuAppM_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuAppM_Init
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  UInt8 Read_rpSR_SleepStatus_SleepManager_SleepStatus;

  UInt16 Call_rp_CS_Backlight_service_GetBrightnessValue_BrightnessPercentValue = 0U;
  UInt32 Call_rp_CS_Backlight_service_GetThermalValue_TempValueInMilliCelsius = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_EcuAppM_Rte_Read_rpSR_SleepStatus_SleepManager_SleepStatus(&Read_rpSR_SleepStatus_SleepManager_SleepStatus);
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

  fct_status = TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_GetBrightnessValue(0U, &Call_rp_CS_Backlight_service_GetBrightnessValue_BrightnessPercentValue);
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
    case RTE_E_TI_Backlight_Service_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_GetThermalValue(0U, &Call_rp_CS_Backlight_service_GetThermalValue_TempValueInMilliCelsius);
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
    case RTE_E_TI_Backlight_Service_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_SetBrightnessValue(0U, 0U);
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
    case RTE_E_TI_Backlight_Service_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand(0U);
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
    case RTE_E_if_CS_ModeOnCommand_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand(0U);
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
    case RTE_E_if_CS_ModeOnCommand_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepManager_Impl_OnCommand(0U);
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
    case RTE_E_if_CS_ModeOnCommand_E_NOT_OK:
      fct_error = 1;
      break;
  }

  EcuAppM_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EcuAppM_MainFunction
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
 *   Std_ReturnType Rte_Read_rpSR_SleepStatus_SleepManager_SleepStatus(UInt8 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_service_GetBrightnessValue(EDisplayType DeviceName, UInt16 *BrightnessPercentValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_service_GetThermalValue(EDisplayType DeviceName, UInt32 *TempValueInMilliCelsius)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_service_SetBrightnessValue(EDisplayType DeviceName, UInt16 BrightnessPercentValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand(ECmpCmd cmdP)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand(ECmpCmd cmdP)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepManager_Impl_OnCommand(ECmpCmd cmdP)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuAppM_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EcuAppM_CODE) EcuAppM_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuAppM_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  UInt8 Read_rpSR_SleepStatus_SleepManager_SleepStatus;

  UInt16 Call_rp_CS_Backlight_service_GetBrightnessValue_BrightnessPercentValue = 0U;
  UInt32 Call_rp_CS_Backlight_service_GetThermalValue_TempValueInMilliCelsius = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_EcuAppM_Rte_Read_rpSR_SleepStatus_SleepManager_SleepStatus(&Read_rpSR_SleepStatus_SleepManager_SleepStatus);
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

  fct_status = TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_GetBrightnessValue(0U, &Call_rp_CS_Backlight_service_GetBrightnessValue_BrightnessPercentValue);
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
    case RTE_E_TI_Backlight_Service_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_GetThermalValue(0U, &Call_rp_CS_Backlight_service_GetThermalValue_TempValueInMilliCelsius);
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
    case RTE_E_TI_Backlight_Service_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_SetBrightnessValue(0U, 0U);
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
    case RTE_E_TI_Backlight_Service_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand(0U);
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
    case RTE_E_if_CS_ModeOnCommand_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand(0U);
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
    case RTE_E_if_CS_ModeOnCommand_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepManager_Impl_OnCommand(0U);
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
    case RTE_E_if_CS_ModeOnCommand_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EcuAppM_SetWakeupSources
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EcuAppM_SetWakeupSources> of PortPrototype <ppCS_EcuAppM>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSR_SleepStatus_SleepManager_SleepStatus(UInt8 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_service_GetBrightnessValue(EDisplayType DeviceName, UInt16 *BrightnessPercentValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_service_GetThermalValue(EDisplayType DeviceName, UInt32 *TempValueInMilliCelsius)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_Backlight_service_SetBrightnessValue(EDisplayType DeviceName, UInt16 BrightnessPercentValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TI_Backlight_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand(ECmpCmd cmdP)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand(ECmpCmd cmdP)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepManager_Impl_OnCommand(ECmpCmd cmdP)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void EcuAppM_SetWakeupSources(UInt32 WakeupSource)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuAppM_SetWakeupSources_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, EcuAppM_CODE) EcuAppM_SetWakeupSources(UInt32 WakeupSource) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuAppM_SetWakeupSources
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  UInt8 Read_rpSR_SleepStatus_SleepManager_SleepStatus;

  UInt16 Call_rp_CS_Backlight_service_GetBrightnessValue_BrightnessPercentValue = 0U;
  UInt32 Call_rp_CS_Backlight_service_GetThermalValue_TempValueInMilliCelsius = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_EcuAppM_Rte_Read_rpSR_SleepStatus_SleepManager_SleepStatus(&Read_rpSR_SleepStatus_SleepManager_SleepStatus);
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

  fct_status = TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_GetBrightnessValue(0U, &Call_rp_CS_Backlight_service_GetBrightnessValue_BrightnessPercentValue);
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
    case RTE_E_TI_Backlight_Service_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_GetThermalValue(0U, &Call_rp_CS_Backlight_service_GetThermalValue_TempValueInMilliCelsius);
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
    case RTE_E_TI_Backlight_Service_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_SetBrightnessValue(0U, 0U);
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
    case RTE_E_TI_Backlight_Service_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand(0U);
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
    case RTE_E_if_CS_ModeOnCommand_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand(0U);
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
    case RTE_E_if_CS_ModeOnCommand_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepManager_Impl_OnCommand(0U);
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
    case RTE_E_if_CS_ModeOnCommand_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define EcuAppM_STOP_SEC_CODE
#include "EcuAppM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void EcuAppM_TestDefines(void)
{
  /* Enumeration Data Types */

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  EDisplayType Test_EDisplayType_V_1 = e_Display10Inch;
  EDisplayType Test_EDisplayType_V_2 = e_DisplayMaxDevice;
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
