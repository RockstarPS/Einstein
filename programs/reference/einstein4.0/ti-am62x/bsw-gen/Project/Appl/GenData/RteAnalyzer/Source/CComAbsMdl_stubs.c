/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CComAbsMdl_stubs.c
 *        Config:  BMW.dpa
 *     SW-C Type:  CComAbsMdl_stubs
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <CComAbsMdl_stubs>
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

#include "Rte_CComAbsMdl_stubs.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CComAbsMdl_stubs.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CComAbsMdl_stubs_TestDefines(void);


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
 * Alive_101: Integer in interval [0...15]
 * Ambient_Light_level: Integer in interval [0...100]
 * CRC_101: Integer in interval [0...255]
 * CurrentStateIC: Boolean
 * DayNightMode: Boolean
 * Debug1_Byte0: Integer in interval [0...255]
 * Debug1_Byte1: Integer in interval [0...255]
 * Debug1_Byte2: Integer in interval [0...255]
 * Debug1_Byte3: Integer in interval [0...255]
 * Debug1_Byte4: Integer in interval [0...255]
 * Debug1_Byte5: Integer in interval [0...255]
 * Debug1_Byte6: Integer in interval [0...255]
 * Debug1_Byte7: Integer in interval [0...255]
 * Debug2_Byte0: Integer in interval [0...255]
 * Debug2_Byte1: Integer in interval [0...255]
 * Debug2_Byte2: Integer in interval [0...255]
 * Debug2_Byte3: Integer in interval [0...255]
 * Debug2_Byte4: Integer in interval [0...255]
 * Debug2_Byte5: Integer in interval [0...255]
 * Debug2_Byte6: Integer in interval [0...255]
 * Debug2_Byte7: Integer in interval [0...255]
 * Debug3_Byte0: Integer in interval [0...255]
 * Debug3_Byte1: Integer in interval [0...255]
 * Debug3_Byte2: Integer in interval [0...255]
 * Debug3_Byte3: Integer in interval [0...255]
 * Debug3_Byte4: Integer in interval [0...255]
 * Debug3_Byte5: Integer in interval [0...255]
 * Debug3_Byte6: Integer in interval [0...255]
 * Debug3_Byte7: Integer in interval [0...255]
 * Debug4_Byte0: Integer in interval [0...255]
 * Debug4_Byte1: Integer in interval [0...255]
 * Debug4_Byte2: Integer in interval [0...255]
 * Debug4_Byte3: Integer in interval [0...255]
 * Debug4_Byte4: Integer in interval [0...255]
 * Debug4_Byte5: Integer in interval [0...255]
 * Debug4_Byte6: Integer in interval [0...255]
 * Debug4_Byte7: Integer in interval [0...255]
 * Debug5_Byte0: Integer in interval [0...255]
 * Debug5_Byte1: Integer in interval [0...255]
 * Debug5_Byte2: Integer in interval [0...255]
 * Debug5_Byte3: Integer in interval [0...255]
 * Debug5_Byte4: Integer in interval [0...255]
 * Debug5_Byte5: Integer in interval [0...255]
 * Debug5_Byte6: Integer in interval [0...255]
 * Debug5_Byte7: Integer in interval [0...255]
 * EngineSpeed: Integer in interval [0...65535]
 * FV_Tx: Integer in interval [0...15]
 * Gear: Integer in interval [0...15]
 * GearMode: Boolean
 * Illumination_PWM: Integer in interval [0...100]
 * Illumination_level: Integer in interval [0...255]
 * MAC_Tx: Integer in interval [0...268435455]
 * Odometer: Integer in interval [0...1609343]
 * PreviousStateIC: Integer in interval [-4...3]
 * SecureTxByte0: Integer in interval [0...255]
 * SecureTxByte1: Integer in interval [0...255]
 * SecureTxByte2: Integer in interval [0...255]
 * SecureTxByte3: Integer in interval [0...255]
 * TransportMode: Boolean
 * Turn_Indicator_Control: Integer in interval [0...3]
 * UInt8: Integer in interval [0...255]
 * UserData1_IC: Integer in interval [0...255]
 * UserData2_IC: Integer in interval [0...255]
 * UserData3_IC: Integer in interval [0...255]
 * UserData4_IC: Integer in interval [0...255]
 * UserData5_IC: Integer in interval [0...255]
 * VehicleSpeedABS: Integer in interval [0...65535]
 * VehicleSpeedIC: Integer in interval [0...65535]
 * Warning: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * Airbag: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 *   Cx2_Blink (2U)
 *   Cx3_Reserved (3U)
 * GearRecommendation: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_No_Indication (0U)
 *   Cx1_GearUp (1U)
 *   Cx2_GearDown (2U)
 *   Cx3_GearUpBlink (3U)
 *   Cx4_GearDownBlinkl (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * GearStatus: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_On (0U)
 *   Cx01_Blink (1U)
 * PowerMode: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Awake (1U)
 *   Cx2_Accessory (2U)
 *   Cx3_Ignition_On (3U)
 *   Cx4_Run_Engine_or_Motor_on_ (4U)
 *
 * Array Types:
 * ============
 * Diag_Buffer_Tx_USDT: Array with 8 element(s) of type UInt8
 * Diag_Buffer_Tx_UUDT: Array with 8 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * SG_ABS: Record with elements
 *   Airbag of type Airbag
 *   Alive_101 of type Alive_101
 *   CRC_101 of type CRC_101
 *   VehicleSpeedABS of type VehicleSpeedABS
 *
 *********************************************************************************************************************/


#define CComAbsMdl_stubs_START_SEC_CODE
#include "CComAbsMdl_stubs_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_stubs_MainFunction
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
 *   Std_ReturnType Rte_Read_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS(SG_ABS *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxAlive_101_Alive_101(Alive_101 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxAmbient_Light_level_Ambient_Light_level(Ambient_Light_level *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxCRC_101_CRC_101(CRC_101 *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxDayNightMode_DayNightMode(DayNightMode *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxEngineSpeed_EngineSpeed(EngineSpeed *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxGear_Gear(Gear *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxGearMode_GearMode(GearMode *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxGearRecommendation_GearRecommendation(GearRecommendation *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxGearStatus_GearStatus(GearStatus *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxIllumination_level_Illumination_level(Illumination_level *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxPowerMode_PowerMode(PowerMode *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxTransportMode_TransportMode(TransportMode *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxTurn_Indicator_Control_Turn_Indicator_Control(Turn_Indicator_Control *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxVehicleSpeedABS_VehicleSpeedABS(VehicleSpeedABS *data)
 *   Std_ReturnType Rte_Read_rp_SR_RxWarning_Warning(Warning *data)
 *   boolean Rte_IsUpdated_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS(void)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *   uint32 E2EPW_Read_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS(SG_ABS *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_SR_TxCurrentStateIC_CurrentStateIC(CurrentStateIC data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug1_Byte0_Debug1_Byte0(Debug1_Byte0 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug1_Byte1_Debug1_Byte1(Debug1_Byte1 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug1_Byte2_Debug1_Byte2(Debug1_Byte2 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug1_Byte3_Debug1_Byte3(Debug1_Byte3 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug1_Byte4_Debug1_Byte4(Debug1_Byte4 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug1_Byte5_Debug1_Byte5(Debug1_Byte5 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug1_Byte6_Debug1_Byte6(Debug1_Byte6 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug1_Byte7_Debug1_Byte7(Debug1_Byte7 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug2_Byte0_Debug2_Byte0(Debug2_Byte0 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug2_Byte1_Debug2_Byte1(Debug2_Byte1 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug2_Byte2_Debug2_Byte2(Debug2_Byte2 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug2_Byte3_Debug2_Byte3(Debug2_Byte3 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug2_Byte4_Debug2_Byte4(Debug2_Byte4 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug2_Byte5_Debug2_Byte5(Debug2_Byte5 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug2_Byte6_Debug2_Byte6(Debug2_Byte6 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug2_Byte7_Debug2_Byte7(Debug2_Byte7 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug3_Byte0_Debug3_Byte0(Debug3_Byte0 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug3_Byte1_Debug3_Byte1(Debug3_Byte1 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug3_Byte2_Debug3_Byte2(Debug3_Byte2 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug3_Byte3_Debug3_Byte3(Debug3_Byte3 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug3_Byte4_Debug3_Byte4(Debug3_Byte4 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug3_Byte5_Debug3_Byte5(Debug3_Byte5 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug3_Byte6_Debug3_Byte6(Debug3_Byte6 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug3_Byte7_Debug3_Byte7(Debug3_Byte7 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug4_Byte0_Debug4_Byte0(Debug4_Byte0 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug4_Byte1_Debug4_Byte1(Debug4_Byte1 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug4_Byte2_Debug4_Byte2(Debug4_Byte2 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug4_Byte3_Debug4_Byte3(Debug4_Byte3 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug4_Byte4_Debug4_Byte4(Debug4_Byte4 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug4_Byte5_Debug4_Byte5(Debug4_Byte5 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug4_Byte6_Debug4_Byte6(Debug4_Byte6 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug4_Byte7_Debug4_Byte7(Debug4_Byte7 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug5_Byte0_Debug5_Byte0(Debug5_Byte0 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug5_Byte1_Debug5_Byte1(Debug5_Byte1 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug5_Byte2_Debug5_Byte2(Debug5_Byte2 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug5_Byte3_Debug5_Byte3(Debug5_Byte3 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug5_Byte4_Debug5_Byte4(Debug5_Byte4 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug5_Byte5_Debug5_Byte5(Debug5_Byte5 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug5_Byte6_Debug5_Byte6(Debug5_Byte6 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDebug5_Byte7_Debug5_Byte7(Debug5_Byte7 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT(const UInt8 *data)
 *     Argument data: UInt8* is of type Diag_Buffer_Tx_USDT
 *   Std_ReturnType Rte_Write_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT(const UInt8 *data)
 *     Argument data: UInt8* is of type Diag_Buffer_Tx_UUDT
 *   Std_ReturnType Rte_Write_pp_SR_TxFV_Tx_FV_Tx(FV_Tx data)
 *   Std_ReturnType Rte_Write_pp_SR_TxIllumination_PWM_Illumination_PWM(Illumination_PWM data)
 *   Std_ReturnType Rte_Write_pp_SR_TxMAC_Tx_MAC_Tx(MAC_Tx data)
 *   Std_ReturnType Rte_Write_pp_SR_TxOdometer_Odometer(Odometer data)
 *   Std_ReturnType Rte_Write_pp_SR_TxPreviousStateIC_PreviousStateIC(PreviousStateIC data)
 *   Std_ReturnType Rte_Write_pp_SR_TxSecureTxByte0_SecureTxByte0(SecureTxByte0 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxSecureTxByte1_SecureTxByte1(SecureTxByte1 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxSecureTxByte2_SecureTxByte2(SecureTxByte2 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxSecureTxByte3_SecureTxByte3(SecureTxByte3 data)
 *   Std_ReturnType Rte_Write_pp_SR_TxUserData1_IC_UserData1_IC(UserData1_IC data)
 *   Std_ReturnType Rte_Write_pp_SR_TxUserData2_IC_UserData2_IC(UserData2_IC data)
 *   Std_ReturnType Rte_Write_pp_SR_TxUserData3_IC_UserData3_IC(UserData3_IC data)
 *   Std_ReturnType Rte_Write_pp_SR_TxUserData4_IC_UserData4_IC(UserData4_IC data)
 *   Std_ReturnType Rte_Write_pp_SR_TxUserData5_IC_UserData5_IC(UserData5_IC data)
 *   Std_ReturnType Rte_Write_pp_SR_TxVehicleSpeedIC_VehicleSpeedIC(VehicleSpeedIC data)
 *
 *   E2E Protection Wrapper API:
 *   ---------------------------
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_stubs_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsMdl_stubs_CODE) CComAbsMdl_stubs_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_stubs_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SG_ABS Read_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS;
  boolean IsUpdated_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS;
  Alive_101 Read_rp_SR_RxAlive_101_Alive_101;
  Ambient_Light_level Read_rp_SR_RxAmbient_Light_level_Ambient_Light_level;
  CRC_101 Read_rp_SR_RxCRC_101_CRC_101;
  DayNightMode Read_rp_SR_RxDayNightMode_DayNightMode;
  EngineSpeed Read_rp_SR_RxEngineSpeed_EngineSpeed;
  Gear Read_rp_SR_RxGear_Gear;
  GearMode Read_rp_SR_RxGearMode_GearMode;
  GearRecommendation Read_rp_SR_RxGearRecommendation_GearRecommendation;
  GearStatus Read_rp_SR_RxGearStatus_GearStatus;
  Illumination_level Read_rp_SR_RxIllumination_level_Illumination_level;
  PowerMode Read_rp_SR_RxPowerMode_PowerMode;
  TransportMode Read_rp_SR_RxTransportMode_TransportMode;
  Turn_Indicator_Control Read_rp_SR_RxTurn_Indicator_Control_Turn_Indicator_Control;
  VehicleSpeedABS Read_rp_SR_RxVehicleSpeedABS_VehicleSpeedABS;
  Warning Read_rp_SR_RxWarning_Warning;

  Diag_Buffer_Tx_USDT Write_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT;
  Diag_Buffer_Tx_UUDT Write_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  IsUpdated_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS = TSC_CComAbsMdl_stubs_Rte_IsUpdated_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS();

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS(&Read_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxAlive_101_Alive_101(&Read_rp_SR_RxAlive_101_Alive_101);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxAmbient_Light_level_Ambient_Light_level(&Read_rp_SR_RxAmbient_Light_level_Ambient_Light_level);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxCRC_101_CRC_101(&Read_rp_SR_RxCRC_101_CRC_101);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxDayNightMode_DayNightMode(&Read_rp_SR_RxDayNightMode_DayNightMode);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxEngineSpeed_EngineSpeed(&Read_rp_SR_RxEngineSpeed_EngineSpeed);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxGear_Gear(&Read_rp_SR_RxGear_Gear);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxGearMode_GearMode(&Read_rp_SR_RxGearMode_GearMode);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxGearRecommendation_GearRecommendation(&Read_rp_SR_RxGearRecommendation_GearRecommendation);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxGearStatus_GearStatus(&Read_rp_SR_RxGearStatus_GearStatus);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxIllumination_level_Illumination_level(&Read_rp_SR_RxIllumination_level_Illumination_level);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxPowerMode_PowerMode(&Read_rp_SR_RxPowerMode_PowerMode);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxTransportMode_TransportMode(&Read_rp_SR_RxTransportMode_TransportMode);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxTurn_Indicator_Control_Turn_Indicator_Control(&Read_rp_SR_RxTurn_Indicator_Control_Turn_Indicator_Control);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxVehicleSpeedABS_VehicleSpeedABS(&Read_rp_SR_RxVehicleSpeedABS_VehicleSpeedABS);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxWarning_Warning(&Read_rp_SR_RxWarning_Warning);
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

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxCurrentStateIC_CurrentStateIC(Rte_InitValue_pp_SR_TxCurrentStateIC_CurrentStateIC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte0_Debug1_Byte0(Rte_InitValue_pp_SR_TxDebug1_Byte0_Debug1_Byte0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte1_Debug1_Byte1(Rte_InitValue_pp_SR_TxDebug1_Byte1_Debug1_Byte1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte2_Debug1_Byte2(Rte_InitValue_pp_SR_TxDebug1_Byte2_Debug1_Byte2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte3_Debug1_Byte3(Rte_InitValue_pp_SR_TxDebug1_Byte3_Debug1_Byte3);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte4_Debug1_Byte4(Rte_InitValue_pp_SR_TxDebug1_Byte4_Debug1_Byte4);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte5_Debug1_Byte5(Rte_InitValue_pp_SR_TxDebug1_Byte5_Debug1_Byte5);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte6_Debug1_Byte6(Rte_InitValue_pp_SR_TxDebug1_Byte6_Debug1_Byte6);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte7_Debug1_Byte7(Rte_InitValue_pp_SR_TxDebug1_Byte7_Debug1_Byte7);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte0_Debug2_Byte0(Rte_InitValue_pp_SR_TxDebug2_Byte0_Debug2_Byte0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte1_Debug2_Byte1(Rte_InitValue_pp_SR_TxDebug2_Byte1_Debug2_Byte1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte2_Debug2_Byte2(Rte_InitValue_pp_SR_TxDebug2_Byte2_Debug2_Byte2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte3_Debug2_Byte3(Rte_InitValue_pp_SR_TxDebug2_Byte3_Debug2_Byte3);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte4_Debug2_Byte4(Rte_InitValue_pp_SR_TxDebug2_Byte4_Debug2_Byte4);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte5_Debug2_Byte5(Rte_InitValue_pp_SR_TxDebug2_Byte5_Debug2_Byte5);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte6_Debug2_Byte6(Rte_InitValue_pp_SR_TxDebug2_Byte6_Debug2_Byte6);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte7_Debug2_Byte7(Rte_InitValue_pp_SR_TxDebug2_Byte7_Debug2_Byte7);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte0_Debug3_Byte0(Rte_InitValue_pp_SR_TxDebug3_Byte0_Debug3_Byte0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte1_Debug3_Byte1(Rte_InitValue_pp_SR_TxDebug3_Byte1_Debug3_Byte1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte2_Debug3_Byte2(Rte_InitValue_pp_SR_TxDebug3_Byte2_Debug3_Byte2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte3_Debug3_Byte3(Rte_InitValue_pp_SR_TxDebug3_Byte3_Debug3_Byte3);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte4_Debug3_Byte4(Rte_InitValue_pp_SR_TxDebug3_Byte4_Debug3_Byte4);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte5_Debug3_Byte5(Rte_InitValue_pp_SR_TxDebug3_Byte5_Debug3_Byte5);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte6_Debug3_Byte6(Rte_InitValue_pp_SR_TxDebug3_Byte6_Debug3_Byte6);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte7_Debug3_Byte7(Rte_InitValue_pp_SR_TxDebug3_Byte7_Debug3_Byte7);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte0_Debug4_Byte0(Rte_InitValue_pp_SR_TxDebug4_Byte0_Debug4_Byte0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte1_Debug4_Byte1(Rte_InitValue_pp_SR_TxDebug4_Byte1_Debug4_Byte1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte2_Debug4_Byte2(Rte_InitValue_pp_SR_TxDebug4_Byte2_Debug4_Byte2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte3_Debug4_Byte3(Rte_InitValue_pp_SR_TxDebug4_Byte3_Debug4_Byte3);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte4_Debug4_Byte4(Rte_InitValue_pp_SR_TxDebug4_Byte4_Debug4_Byte4);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte5_Debug4_Byte5(Rte_InitValue_pp_SR_TxDebug4_Byte5_Debug4_Byte5);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte6_Debug4_Byte6(Rte_InitValue_pp_SR_TxDebug4_Byte6_Debug4_Byte6);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte7_Debug4_Byte7(Rte_InitValue_pp_SR_TxDebug4_Byte7_Debug4_Byte7);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte0_Debug5_Byte0(Rte_InitValue_pp_SR_TxDebug5_Byte0_Debug5_Byte0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte1_Debug5_Byte1(Rte_InitValue_pp_SR_TxDebug5_Byte1_Debug5_Byte1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte2_Debug5_Byte2(Rte_InitValue_pp_SR_TxDebug5_Byte2_Debug5_Byte2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte3_Debug5_Byte3(Rte_InitValue_pp_SR_TxDebug5_Byte3_Debug5_Byte3);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte4_Debug5_Byte4(Rte_InitValue_pp_SR_TxDebug5_Byte4_Debug5_Byte4);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte5_Debug5_Byte5(Rte_InitValue_pp_SR_TxDebug5_Byte5_Debug5_Byte5);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte6_Debug5_Byte6(Rte_InitValue_pp_SR_TxDebug5_Byte6_Debug5_Byte6);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte7_Debug5_Byte7(Rte_InitValue_pp_SR_TxDebug5_Byte7_Debug5_Byte7);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT, 0, sizeof(Write_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT));
  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT(Write_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT, 0, sizeof(Write_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT));
  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT(Write_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxFV_Tx_FV_Tx(Rte_InitValue_pp_SR_TxFV_Tx_FV_Tx);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxIllumination_PWM_Illumination_PWM(Rte_InitValue_pp_SR_TxIllumination_PWM_Illumination_PWM);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxMAC_Tx_MAC_Tx(Rte_InitValue_pp_SR_TxMAC_Tx_MAC_Tx);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxOdometer_Odometer(Rte_InitValue_pp_SR_TxOdometer_Odometer);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxPreviousStateIC_PreviousStateIC(Rte_InitValue_pp_SR_TxPreviousStateIC_PreviousStateIC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxSecureTxByte0_SecureTxByte0(Rte_InitValue_pp_SR_TxSecureTxByte0_SecureTxByte0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxSecureTxByte1_SecureTxByte1(Rte_InitValue_pp_SR_TxSecureTxByte1_SecureTxByte1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxSecureTxByte2_SecureTxByte2(Rte_InitValue_pp_SR_TxSecureTxByte2_SecureTxByte2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxSecureTxByte3_SecureTxByte3(Rte_InitValue_pp_SR_TxSecureTxByte3_SecureTxByte3);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxUserData1_IC_UserData1_IC(Rte_InitValue_pp_SR_TxUserData1_IC_UserData1_IC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxUserData2_IC_UserData2_IC(Rte_InitValue_pp_SR_TxUserData2_IC_UserData2_IC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxUserData3_IC_UserData3_IC(Rte_InitValue_pp_SR_TxUserData3_IC_UserData3_IC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxUserData4_IC_UserData4_IC(Rte_InitValue_pp_SR_TxUserData4_IC_UserData4_IC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxUserData5_IC_UserData5_IC(Rte_InitValue_pp_SR_TxUserData5_IC_UserData5_IC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxVehicleSpeedIC_VehicleSpeedIC(Rte_InitValue_pp_SR_TxVehicleSpeedIC_VehicleSpeedIC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  CComAbsMdl_stubs_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CComAbsMdl_stubs_STOP_SEC_CODE
#include "CComAbsMdl_stubs_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CComAbsMdl_stubs_TestDefines(void)
{
  /* Enumeration Data Types */

  Airbag Test_Airbag_V_1 = Cx0_Off;
  Airbag Test_Airbag_V_2 = Cx1_On;
  Airbag Test_Airbag_V_3 = Cx2_Blink;
  Airbag Test_Airbag_V_4 = Cx3_Reserved;

  GearRecommendation Test_GearRecommendation_V_1 = Cx0_No_Indication;
  GearRecommendation Test_GearRecommendation_V_2 = Cx1_GearUp;
  GearRecommendation Test_GearRecommendation_V_3 = Cx2_GearDown;
  GearRecommendation Test_GearRecommendation_V_4 = Cx3_GearUpBlink;
  GearRecommendation Test_GearRecommendation_V_5 = Cx4_GearDownBlinkl;
  GearRecommendation Test_GearRecommendation_V_6 = Cx5_Reserved;
  GearRecommendation Test_GearRecommendation_V_7 = Cx6_Reserved;
  GearRecommendation Test_GearRecommendation_V_8 = Cx7_Reserved;

  GearStatus Test_GearStatus_V_1 = Cx00_On;
  GearStatus Test_GearStatus_V_2 = Cx01_Blink;

  PowerMode Test_PowerMode_V_1 = Cx0_Off;
  PowerMode Test_PowerMode_V_2 = Cx1_Awake;
  PowerMode Test_PowerMode_V_3 = Cx2_Accessory;
  PowerMode Test_PowerMode_V_4 = Cx3_Ignition_On;
  PowerMode Test_PowerMode_V_5 = Cx4_Run_Engine_or_Motor_on_;
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
