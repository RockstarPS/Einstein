/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Mdl_Gear.c
 *        Config:  BMW.dpa
 *     SW-C Type:  Mdl_Gear
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <Mdl_Gear>
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

#include "Rte_Mdl_Gear.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Mdl_Gear.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Mdl_Gear_TestDefines(void);


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
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ClusterModes: Enumeration of integer in interval [0...1] with enumerators
 *   CLUSTER_INACTIVE (0U)
 *   CLUSTER_ACTIVE (1U)
 * HMIReadySts_Type: Enumeration of integer in interval [0...1] with enumerators
 *   eHMI_NOT_READY (0U)
 *   eHMI_READY (1U)
 * IgntionSubstateType: Enumeration of integer in interval [0...1] with enumerators
 *   IgnOff (0U)
 *   IgnOn (1U)
 * ShiftPosition: Enumeration of integer in interval [16...96] with enumerators
 *   Shift_PosInd_P (16U)
 *   Shift_PosInd_R (32U)
 *   Shift_PosInd_N (48U)
 *   Shift_PosInd_D (64U)
 *   Shift_PosInd_B (80U)
 *   Shift_PosInd_SD (96U)
 * ShiftPositionInd: Enumeration of integer in interval [1...3] with enumerators
 *   Shift_PosInd_Ind_S (1U)
 *   Shift_PosInd_Ind_M (2U)
 *   Shift_PosInd_Ind_D (3U)
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
 *
 * Record Types:
 * =============
 * SShiftInd: Record with elements
 *   Shift_Ind_Pos of type UInt8
 *   Shift_Ind_BlinkReq of type UInt8
 *   Shift_Ind_DisplayDecState of type UInt8
 *   Shift_Ind_Down of type UInt8
 *   Shift_Ind_Screen_ShiftType of type UInt8
 *   Shift_Ind_Up of type UInt8
 * SShiftPosIndStatus: Record with elements
 *   status of type SShiftInd
 * ShiftposData_Type: Record with elements
 *   Shift_Up_Ind of type UInt8
 *   DisplayDecState of type UInt8
 *   Shift_Ind_Pos of type UInt16
 *   Shift_Down_Ind of type UInt8
 *   Screen_ShiftType of type UInt8
 *
 *********************************************************************************************************************/


#define Mdl_Gear_START_SEC_CODE
#include "Mdl_Gear_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_Gear_Init
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
 *   void Mdl_Gear_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Gear_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_Gear_CODE) Mdl_Gear_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Gear_Init
 *********************************************************************************************************************/

  Mdl_Gear_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Mdl_Gear_Task
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 32ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
 *   Std_ReturnType Rte_Read_rpVehicleAppMode_WSSCurrentVehicleState(VehicleActiveModes *data)
 *   Std_ReturnType Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
 *   Std_ReturnType Rte_Read_rp_HMI_Ready_Status_HMI_ReadyStatus(HMIReadySts_Type *data)
 *   Std_ReturnType Rte_Read_rp_PowerTrainState_PowerTrain_Flag(UInt8 *data)
 *   Std_ReturnType Rte_Read_rp_TT_PRND_blink_TIUpdateIndicatorStatus(UInt8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_ShiftPositionDisplay_ShiftPositionDisplay(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_Shift_ModeInd_ShiftModeIndicator(ShiftPositionInd data)
 *   Std_ReturnType Rte_Write_pp_Shift_Position_ShiftPosition(ShiftPosition data)
 *   Std_ReturnType Rte_Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData(const SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Write_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data(const ShiftposData_Type *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
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
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(UInt8 VariantID, UInt8 *VariantActiveSt)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_Variant_Status_GetVariant_Status(UInt8 Variant_Ind, UInt8 *Variant_Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Gear_Task_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Mdl_Gear_CODE) Mdl_Gear_Task(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Mdl_Gear_Task
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  IgntionSubstateType Read_rpIgnSubstate_IgnitionSubstate;
  VehicleActiveModes Read_rpVehicleAppMode_WSSCurrentVehicleState;
  ClusterModes Read_rp_ClusterMode_WSSCurrentClusterMode;
  HMIReadySts_Type Read_rp_HMI_Ready_Status_HMI_ReadyStatus;
  UInt8 Read_rp_PowerTrainState_PowerTrain_Flag;
  UInt8 Read_rp_TT_PRND_blink_TIUpdateIndicatorStatus;

  SShiftPosIndStatus Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData;
  ShiftposData_Type Write_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data;

  UInt8 Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalStatus = 0U;
  UInt8 Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalStatus = 0U;
  UInt32 Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalLength = 0U;
  UInt8 Call_rp_CS_CanRx_RxCan_SetSignalInitValue_pSignalValue = 0U;
  UInt8 Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignaValue = 0U;
  UInt32 Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignalLength = 0U;
  tRxSignalJustRcvdStatus Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus = 0U;
  UInt8 Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalStatus = 0U;
  UInt8 Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalValue = 0U;
  tRxSignalStatus Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalStatus = 0U;
  UInt32 Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalLength = 0U;
  UInt8 Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue_pSignalValue = 0U;
  UInt8 Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignaValue = 0U;
  UInt32 Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignalLength = 0U;
  tRxSignalJustRcvdStatus Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus = 0U;
  UInt8 Call_rp_Get_Variant_Cfg_Get_Variant_Config_State_VariantActiveSt = 0U;
  UInt8 Call_rp_Variant_Status_GetVariant_Status_Variant_Status = 0U;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Mdl_Gear_Rte_Read_rpIgnSubstate_IgnitionSubstate(&Read_rpIgnSubstate_IgnitionSubstate);
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

  fct_status = TSC_Mdl_Gear_Rte_Read_rpVehicleAppMode_WSSCurrentVehicleState(&Read_rpVehicleAppMode_WSSCurrentVehicleState);
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

  fct_status = TSC_Mdl_Gear_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(&Read_rp_ClusterMode_WSSCurrentClusterMode);
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

  fct_status = TSC_Mdl_Gear_Rte_Read_rp_HMI_Ready_Status_HMI_ReadyStatus(&Read_rp_HMI_Ready_Status_HMI_ReadyStatus);
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

  fct_status = TSC_Mdl_Gear_Rte_Read_rp_PowerTrainState_PowerTrain_Flag(&Read_rp_PowerTrainState_PowerTrain_Flag);
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

  fct_status = TSC_Mdl_Gear_Rte_Read_rp_TT_PRND_blink_TIUpdateIndicatorStatus(&Read_rp_TT_PRND_blink_TIUpdateIndicatorStatus);
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

  fct_status = TSC_Mdl_Gear_Rte_Write_pp_ShiftPositionDisplay_ShiftPositionDisplay(Rte_InitValue_pp_ShiftPositionDisplay_ShiftPositionDisplay);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Gear_Rte_Write_pp_Shift_ModeInd_ShiftModeIndicator(Rte_InitValue_pp_Shift_ModeInd_ShiftModeIndicator);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Gear_Rte_Write_pp_Shift_Position_ShiftPosition(Rte_InitValue_pp_Shift_Position_ShiftPosition);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData, 0, sizeof(Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData));
  fct_status = TSC_Mdl_Gear_Rte_Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData(&Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data, 0, sizeof(Write_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data));
  fct_status = TSC_Mdl_Gear_Rte_Write_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data(&Write_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(0U, &Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalValue, &Call_rp_CS_CanRx_RxCan_GetSignalValue_pSignalStatus);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(0U, &Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalValue, &Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalStatus, &Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr_pSignalLength);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(0U, &Call_rp_CS_CanRx_RxCan_SetSignalInitValue_pSignalValue);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(0U, &Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignaValue, &Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr_pSignalLength);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(0U);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(0U, &Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(0U, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalValue, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValue_pSignalStatus);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(0U, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalValue, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalStatus, &Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr_pSignalLength);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(0U, &Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue_pSignalValue);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(0U, &Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignaValue, &Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr_pSignalLength);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(0U);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(0U, &Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus_pJustRcvdStatus);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(0U, FALSE);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(0U, &Call_rp_Get_Variant_Cfg_Get_Variant_Config_State_VariantActiveSt);
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

  fct_status = TSC_Mdl_Gear_Rte_Call_rp_Variant_Status_GetVariant_Status(0U, &Call_rp_Variant_Status_GetVariant_Status_Variant_Status);
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


#define Mdl_Gear_STOP_SEC_CODE
#include "Mdl_Gear_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Mdl_Gear_TestDefines(void)
{
  /* Enumeration Data Types */

  ClusterModes Test_ClusterModes_V_1 = CLUSTER_INACTIVE;
  ClusterModes Test_ClusterModes_V_2 = CLUSTER_ACTIVE;

  HMIReadySts_Type Test_HMIReadySts_Type_V_1 = eHMI_NOT_READY;
  HMIReadySts_Type Test_HMIReadySts_Type_V_2 = eHMI_READY;

  IgntionSubstateType Test_IgntionSubstateType_V_1 = IgnOff;
  IgntionSubstateType Test_IgntionSubstateType_V_2 = IgnOn;

  ShiftPosition Test_ShiftPosition_V_1 = Shift_PosInd_P;
  ShiftPosition Test_ShiftPosition_V_2 = Shift_PosInd_R;
  ShiftPosition Test_ShiftPosition_V_3 = Shift_PosInd_N;
  ShiftPosition Test_ShiftPosition_V_4 = Shift_PosInd_D;
  ShiftPosition Test_ShiftPosition_V_5 = Shift_PosInd_B;
  ShiftPosition Test_ShiftPosition_V_6 = Shift_PosInd_SD;

  ShiftPositionInd Test_ShiftPositionInd_V_1 = Shift_PosInd_Ind_S;
  ShiftPositionInd Test_ShiftPositionInd_V_2 = Shift_PosInd_Ind_M;
  ShiftPositionInd Test_ShiftPositionInd_V_3 = Shift_PosInd_Ind_D;

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
