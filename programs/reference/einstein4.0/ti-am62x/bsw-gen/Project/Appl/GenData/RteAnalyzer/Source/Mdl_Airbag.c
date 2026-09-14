/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Mdl_Airbag.c
 *        Config:  BMW.dpa
 *     SW-C Type:  Mdl_Airbag
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <Mdl_Airbag>
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

#include "Rte_Mdl_Airbag.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Mdl_Airbag.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Mdl_Airbag_TestDefines(void);


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
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ClusterModes: Enumeration of integer in interval [0...1] with enumerators
 *   CLUSTER_INACTIVE (0U)
 *   CLUSTER_ACTIVE (1U)
 * IgntionSubstateType: Enumeration of integer in interval [0...1] with enumerators
 *   IgnOff (0U)
 *   IgnOn (1U)
 * TT_OP_STATES: Enumeration of integer in interval [0...255] with enumerators
 *   TT_TURN_OFF (0U)
 *   TT_TURN_ON (1U)
 *   TT_FLASH_QUARTER_HZ (2U)
 *   TT_FLASH_HALF_HZ (3U)
 *   TT_FLASH_CSNR_HALF_HZ (4U)
 *   TT_FLASH_0_83_HZ (5U)
 *   TT_FLASH_1HZ (6U)
 *   TT_FLASH_1_33_HZ (7U)
 *   TT_FLASH_1_66_HZ (8U)
 *   TT_FLASH_2HZ (9U)
 *   TT_FLASH_2_5_HZ (10U)
 *   TT_FLASH_2_66_HZ (11U)
 *   TT_FLASH_TRNHZ_Normal (12U)
 *   TT_FLASH_TRNHZ_Fast (13U)
 *   TT_FLASH_TRNHZ_FHL (14U)
 *   TT_FLASH_3HZ (15U)
 *   TT_FLASH_4HZ (16U)
 *   TT_FLASH_5HZ (17U)
 *   TT_FLASH_SYNC_QUARTER_HZ (18U)
 *   TT_FLASH_SYNC_HALF_HZ (19U)
 *   TT_FLASH_SYNC_CSNR_HALF_HZ (20U)
 *   TT_FLASH_SYNC_0_83_HZ (21U)
 *   TT_FLASH_SYNC_1HZ (22U)
 *   TT_FLASH_SYNC_1_33_HZ (23U)
 *   TT_FLASH_SYNC_1_66_HZ (24U)
 *   TT_FLASH_SYNC_2HZ (25U)
 *   TT_FLASH_SYNC_2_5_HZ (26U)
 *   TT_FLASH_SYNC_2_66_HZ (27U)
 *   TT_FLASH_TRNHZ_SYNC_Normal (28U)
 *   TT_FLASH_TRNHZ_SYNC_Fast (29U)
 *   TT_FLASH_TRNHZ_SYNC_FHL (30U)
 *   TT_FLASH_SYNC_4HZ (31U)
 *   TT_FLASH_SYNC_5HZ (32U)
 *   TT_CONFIGURED_OFF (255U)
 * VehicleActiveModes: Enumeration of integer in interval [0...2] with enumerators
 *   NETWORK_SLEEP (0U)
 *   NETWORK_NORMAL (1U)
 *   NETWORK_STANDALONE (2U)
 * tRxSignalId: Enumeration of integer in interval [0...12] with enumerators
 *   eDayNightModeIn (0U)
 *   eIllumination_levelIn (1U)
 *   eAmbient_Light_levelIn (2U)
 *   ePowerModeIn (3U)
 *   eTransportModeIn (4U)
 *   eGearModeIn (5U)
 *   eGearRecommendationIn (6U)
 *   eGearIn (7U)
 *   eWarningIn (8U)
 *   eGearStatusIn (9U)
 *   eEngineSpeedIn (10U)
 *   eTurn_Indicator_ControlIn (11U)
 *   eEndOfRxSignal (12U)
 * tRxSignalJustRcvdStatus: Enumeration of integer in interval [0...1] with enumerators
 *   eJust_Received (0U)
 *   eNot_Just_Received (1U)
 * tRxSignalStatus: Enumeration of integer in interval [0...4] with enumerators
 *   eSIGNAL_OK (0U)
 *   eSIGNAL_MISSING (1U)
 *   eSIGNAL_NEVER_RECEIVED (2U)
 *   eSIGNAL_INVALID (4U)
 * tSafeRxSignalId: Enumeration of integer in interval [0...4] with enumerators
 *   eVehicleSpeedABSIn (0U)
 *   eAirbagIn (1U)
 *   eAlive_101In (2U)
 *   eCRC_101In (3U)
 *   eEndOfSafeRxSignal (4U)
 * tSafeRxSignalJustRcvdStatus: Enumeration of integer in interval [0...1] with enumerators
 *   eJust_Received (0U)
 *   eNot_Just_Received (1U)
 * tSafeRxSignalStatus: Enumeration of integer in interval [0...6] with enumerators
 *   eSIGNAL_OK (0U)
 *   eSIGNAL_MISSING (1U)
 *   eSIGNAL_NEVER_RECEIVED (2U)
 *   eSIGNAL_INVALID (3U)
 *   eSIGNAL_INVALID_CRC (4U)
 *   eSIGNAL_INVALID_ALIVE_COUNTER (5U)
 *   eSIGNAL_REPEATED (6U)
 *
 *********************************************************************************************************************/


#define Mdl_Airbag_START_SEC_CODE
#include "Mdl_Airbag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_Airbag_Init
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Init> of PortPrototype <pp_Init>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Mdl_Airbag_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Airbag_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_Airbag_CODE) Mdl_Airbag_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Airbag_Init
 *********************************************************************************************************************/

  Mdl_Airbag_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_Airbag_Task
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 30ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_VehicleAppMode_WSSCurrentVehicleState(VehicleActiveModes *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_Airbag_TT_Status_CurrentTelltaleStatus(TT_OP_STATES data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rp_CS_CanAdapterRx_RxCan_GetSignalValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanAdapterRx_RxCan_GetSignalValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalClearJustRcvdStatus(tSafeRxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalGetJustRcvdStatus(tSafeRxSignalId SignalId, tSafeRxSignalJustRcvdStatus *pJustRcvdStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalInvalidProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalMissingProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalNRProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Airbag_Task_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_Airbag_CODE) Mdl_Airbag_Task(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Airbag_Task
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  VehicleActiveModes Read_rp_VehicleAppMode_WSSCurrentVehicleState;

  UInt8 Call_rp_CS_CanAdapterRx_RxCan_GetSignalValue_pSignalValue = 0U;
  tSafeRxSignalStatus Call_rp_CS_CanAdapterRx_RxCan_GetSignalValue_pSignalStatus = 0U;
  UInt8 Call_rp_CS_CanAdapterRx_RxCan_GetSignalValueU8Arr_pSignalValue = 0U;
  tSafeRxSignalStatus Call_rp_CS_CanAdapterRx_RxCan_GetSignalValueU8Arr_pSignalStatus = 0U;
  UInt32 Call_rp_CS_CanAdapterRx_RxCan_GetSignalValueU8Arr_pSignalLength = 0U;
  UInt8 Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValue_pSignalValue = 0U;
  UInt8 Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValueU8Arr_pSignaValue = 0U;
  UInt32 Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValueU8Arr_pSignalLength = 0U;
  tSafeRxSignalJustRcvdStatus Call_rp_CS_CanAdapterRx_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus = 0U;
  UInt8 Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalStatus = 0U;
  UInt8 Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalStatus = 0U;
  UInt32 Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalLength = 0U;
  UInt8 Call_rp_CS_CanRx_RxCan_SetSignalInitValue_pSignalValue = 0U;
  UInt8 Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignaValue = 0U;
  UInt32 Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignalLength = 0U;
  tRxSignalJustRcvdStatus Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Mdl_Airbag_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
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

  fct_status = TSC_Mdl_Airbag_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
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

  fct_status = TSC_Mdl_Airbag_Rte_Read_rp_VehicleAppMode_WSSCurrentVehicleState(&Read_rp_VehicleAppMode_WSSCurrentVehicleState);
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

  fct_status = TSC_Mdl_Airbag_Rte_Write_pp_Airbag_TT_Status_CurrentTelltaleStatus(Rte_InitValue_pp_Airbag_TT_Status_CurrentTelltaleStatus);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanAdapterRx_RxCan_GetSignalValue(0U, &Call_rp_CS_CanAdapterRx_RxCan_GetSignalValue_pSignalValue, &Call_rp_CS_CanAdapterRx_RxCan_GetSignalValue_pSignalStatus);
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
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanAdapterRx_RxCan_GetSignalValueU8Arr(0U, &Call_rp_CS_CanAdapterRx_RxCan_GetSignalValueU8Arr_pSignalValue, &Call_rp_CS_CanAdapterRx_RxCan_GetSignalValueU8Arr_pSignalStatus, &Call_rp_CS_CanAdapterRx_RxCan_GetSignalValueU8Arr_pSignalLength);
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
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValue(0U, &Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValue_pSignalValue);
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
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValueU8Arr(0U, &Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValueU8Arr_pSignaValue, &Call_rp_CS_CanAdapterRx_RxCan_SetSignalInitValueU8Arr_pSignalLength);
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
    case RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalClearJustRcvdStatus(0U);
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

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalGetJustRcvdStatus(0U, &Call_rp_CS_CanAdapterRx_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus);
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

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalInvalidProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalMissingProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanAdapterRx_RxCan_SignalNRProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(0U, &Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalValue, &Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalStatus);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(0U, &Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalValue, &Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalStatus, &Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalLength);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(0U, &Call_rp_CS_CanRx_RxCan_SetSignalInitValue_pSignalValue);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(0U, &Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignaValue, &Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignalLength);
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
    case RTE_E_if_CS_ComAbsRx_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(0U);
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

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(0U, &Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus);
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

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Airbag_Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(0U, FALSE);
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


#define Mdl_Airbag_STOP_SEC_CODE
#include "Mdl_Airbag_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Mdl_Airbag_TestDefines(void)
{
  /* Enumeration Data Types */

  ClusterModes Test_ClusterModes_V_1 = CLUSTER_INACTIVE;
  ClusterModes Test_ClusterModes_V_2 = CLUSTER_ACTIVE;

  IgntionSubstateType Test_IgntionSubstateType_V_1 = IgnOff;
  IgntionSubstateType Test_IgntionSubstateType_V_2 = IgnOn;

  TT_OP_STATES Test_TT_OP_STATES_V_1 = TT_TURN_OFF;
  TT_OP_STATES Test_TT_OP_STATES_V_2 = TT_TURN_ON;
  TT_OP_STATES Test_TT_OP_STATES_V_3 = TT_FLASH_QUARTER_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_4 = TT_FLASH_HALF_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_5 = TT_FLASH_CSNR_HALF_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_6 = TT_FLASH_0_83_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_7 = TT_FLASH_1HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_8 = TT_FLASH_1_33_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_9 = TT_FLASH_1_66_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_10 = TT_FLASH_2HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_11 = TT_FLASH_2_5_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_12 = TT_FLASH_2_66_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_13 = TT_FLASH_TRNHZ_Normal;
  TT_OP_STATES Test_TT_OP_STATES_V_14 = TT_FLASH_TRNHZ_Fast;
  TT_OP_STATES Test_TT_OP_STATES_V_15 = TT_FLASH_TRNHZ_FHL;
  TT_OP_STATES Test_TT_OP_STATES_V_16 = TT_FLASH_3HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_17 = TT_FLASH_4HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_18 = TT_FLASH_5HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_19 = TT_FLASH_SYNC_QUARTER_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_20 = TT_FLASH_SYNC_HALF_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_21 = TT_FLASH_SYNC_CSNR_HALF_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_22 = TT_FLASH_SYNC_0_83_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_23 = TT_FLASH_SYNC_1HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_24 = TT_FLASH_SYNC_1_33_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_25 = TT_FLASH_SYNC_1_66_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_26 = TT_FLASH_SYNC_2HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_27 = TT_FLASH_SYNC_2_5_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_28 = TT_FLASH_SYNC_2_66_HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_29 = TT_FLASH_TRNHZ_SYNC_Normal;
  TT_OP_STATES Test_TT_OP_STATES_V_30 = TT_FLASH_TRNHZ_SYNC_Fast;
  TT_OP_STATES Test_TT_OP_STATES_V_31 = TT_FLASH_TRNHZ_SYNC_FHL;
  TT_OP_STATES Test_TT_OP_STATES_V_32 = TT_FLASH_SYNC_4HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_33 = TT_FLASH_SYNC_5HZ;
  TT_OP_STATES Test_TT_OP_STATES_V_34 = TT_CONFIGURED_OFF;

  VehicleActiveModes Test_VehicleActiveModes_V_1 = NETWORK_SLEEP;
  VehicleActiveModes Test_VehicleActiveModes_V_2 = NETWORK_NORMAL;
  VehicleActiveModes Test_VehicleActiveModes_V_3 = NETWORK_STANDALONE;

  tRxSignalId Test_tRxSignalId_V_1 = eDayNightModeIn;
  tRxSignalId Test_tRxSignalId_V_2 = eIllumination_levelIn;
  tRxSignalId Test_tRxSignalId_V_3 = eAmbient_Light_levelIn;
  tRxSignalId Test_tRxSignalId_V_4 = ePowerModeIn;
  tRxSignalId Test_tRxSignalId_V_5 = eTransportModeIn;
  tRxSignalId Test_tRxSignalId_V_6 = eGearModeIn;
  tRxSignalId Test_tRxSignalId_V_7 = eGearRecommendationIn;
  tRxSignalId Test_tRxSignalId_V_8 = eGearIn;
  tRxSignalId Test_tRxSignalId_V_9 = eWarningIn;
  tRxSignalId Test_tRxSignalId_V_10 = eGearStatusIn;
  tRxSignalId Test_tRxSignalId_V_11 = eEngineSpeedIn;
  tRxSignalId Test_tRxSignalId_V_12 = eTurn_Indicator_ControlIn;
  tRxSignalId Test_tRxSignalId_V_13 = eEndOfRxSignal;

  tRxSignalJustRcvdStatus Test_tRxSignalJustRcvdStatus_V_1 = eJust_Received;
  tRxSignalJustRcvdStatus Test_tRxSignalJustRcvdStatus_V_2 = eNot_Just_Received;

  tRxSignalStatus Test_tRxSignalStatus_V_1 = eSIGNAL_OK;
  tRxSignalStatus Test_tRxSignalStatus_V_2 = eSIGNAL_MISSING;
  tRxSignalStatus Test_tRxSignalStatus_V_3 = eSIGNAL_NEVER_RECEIVED;
  tRxSignalStatus Test_tRxSignalStatus_V_4 = eSIGNAL_INVALID;

  tSafeRxSignalId Test_tSafeRxSignalId_V_1 = eVehicleSpeedABSIn;
  tSafeRxSignalId Test_tSafeRxSignalId_V_2 = eAirbagIn;
  tSafeRxSignalId Test_tSafeRxSignalId_V_3 = eAlive_101In;
  tSafeRxSignalId Test_tSafeRxSignalId_V_4 = eCRC_101In;
  tSafeRxSignalId Test_tSafeRxSignalId_V_5 = eEndOfSafeRxSignal;

  tSafeRxSignalJustRcvdStatus Test_tSafeRxSignalJustRcvdStatus_V_1 = eJust_Received;
  tSafeRxSignalJustRcvdStatus Test_tSafeRxSignalJustRcvdStatus_V_2 = eNot_Just_Received;

  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_1 = eSIGNAL_OK;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_2 = eSIGNAL_MISSING;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_3 = eSIGNAL_NEVER_RECEIVED;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_4 = eSIGNAL_INVALID;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_5 = eSIGNAL_INVALID_CRC;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_6 = eSIGNAL_INVALID_ALIVE_COUNTER;
  tSafeRxSignalStatus Test_tSafeRxSignalStatus_V_7 = eSIGNAL_REPEATED;
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
