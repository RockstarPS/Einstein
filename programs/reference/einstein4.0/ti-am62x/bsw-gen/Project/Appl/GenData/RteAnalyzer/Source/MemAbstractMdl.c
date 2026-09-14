/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  MemAbstractMdl.c
 *        Config:  BMW.dpa
 *     SW-C Type:  MemAbstractMdl
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <MemAbstractMdl>
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

#include "Rte_MemAbstractMdl.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_MemAbstractMdl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void MemAbstractMdl_TestDefines(void);


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
 * Rte_DT_Arr_u16_7_0: Integer in interval [0...65535]
 * Rte_DT_Arr_u8_100_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_1024_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_10_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_128_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_16_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_17_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_2048_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_256_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_28_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_32_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_3_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_46_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_48_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_61_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_64_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_8_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_9_0: Integer in interval [0...255]
 * Rte_DT_T_NV_Temperature_Conversion_0: Integer in interval [0...4294967295]
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
 *
 * Array Types:
 * ============
 * Arr_u16_7: Array with 7 element(s) of type Rte_DT_Arr_u16_7_0
 * Arr_u8_10: Array with 10 element(s) of type Rte_DT_Arr_u8_10_0
 * Arr_u8_100: Array with 100 element(s) of type Rte_DT_Arr_u8_100_0
 * Arr_u8_1024: Array with 1024 element(s) of type Rte_DT_Arr_u8_1024_0
 * Arr_u8_128: Array with 128 element(s) of type Rte_DT_Arr_u8_128_0
 * Arr_u8_16: Array with 16 element(s) of type Rte_DT_Arr_u8_16_0
 * Arr_u8_17: Array with 17 element(s) of type Rte_DT_Arr_u8_17_0
 * Arr_u8_2048: Array with 2048 element(s) of type Rte_DT_Arr_u8_2048_0
 * Arr_u8_256: Array with 256 element(s) of type Rte_DT_Arr_u8_256_0
 * Arr_u8_28: Array with 28 element(s) of type Rte_DT_Arr_u8_28_0
 * Arr_u8_3: Array with 3 element(s) of type Rte_DT_Arr_u8_3_0
 * Arr_u8_32: Array with 32 element(s) of type Rte_DT_Arr_u8_32_0
 * Arr_u8_46: Array with 46 element(s) of type Rte_DT_Arr_u8_46_0
 * Arr_u8_48: Array with 48 element(s) of type Rte_DT_Arr_u8_48_0
 * Arr_u8_61: Array with 61 element(s) of type Rte_DT_Arr_u8_61_0
 * Arr_u8_64: Array with 64 element(s) of type Rte_DT_Arr_u8_64_0
 * Arr_u8_8: Array with 8 element(s) of type Rte_DT_Arr_u8_8_0
 * Arr_u8_9: Array with 9 element(s) of type Rte_DT_Arr_u8_9_0
 * T_NV_Temperature_Conversion: Array with 2 element(s) of type Rte_DT_T_NV_Temperature_Conversion_0
 *
 *********************************************************************************************************************/


#define MemAbstractMdl_START_SEC_CODE
#include "MemAbstractMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CMemAbstractMdl_Impl_MainFunction
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
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Power_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Display_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Power_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_HWModification(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(UInt8 data)
 *   Std_ReturnType Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(UInt8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CMemAbstractMdl_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) CMemAbstractMdl_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CMemAbstractMdl_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Power_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Power_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Display_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Display_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Power_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Power_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_HWModification(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_HWModification);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber(Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_MemAbstractMdl_Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(Rte_InitValue_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  MemAbstractMdl_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CMemAbstractMdl_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd_MemAbstractMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CMemAbstractMdl_Impl_OnCommand(ECmpCmd cmdP)
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
 * Symbol: CMemAbstractMdl_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) CMemAbstractMdl_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CMemAbstractMdl_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Audio_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Audio_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Audio_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Audio_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_BsConst_Illumination_ReservedByte> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Communication_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Communication_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Communication_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Compensation_Line_Shift_b> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Compensation_Line_Shift_b_SafeCopy1> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Compensation_Line_Shift_b_SafeCopy2> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Compensation_Line_Slope_m> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Compensation_Line_Slope_m_SafeCopy1> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Compensation_Line_Slope_m_SafeCopy2> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Derating_Backlight_Disable> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Derating_Backlight_Disable_SafeCopy1> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Derating_Backlight_Disable_SafeCopy2> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Display_Illum_Max_Level> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level(UInt16 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Display_Illum_Max_Level_SafeCopy1> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Display_Illum_Max_Level_SafeCopy2> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_EngOffTimer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_EngOffTimer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_EngOffTimer_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_EngOffTimer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_EngOffTimer_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_EngOffTimer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_FuelGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_FuelGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_FuelGauge_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_FuelGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_FuelGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Lookup_Curve_HotSpot_Coef_X> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Lookup_Curve_HotSpot_Coef_Y> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_OilGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_OilGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_OilGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_OilGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_OilGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_PCB_Temperature_Sensor_Conv> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_PWM_boost_bypass_duty> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_PWM_boost_bypass_duty_SafeCopy1> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_PWM_boost_bypass_duty_SafeCopy2> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_PowerGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_PowerGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_PowerGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PowerGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_PowerGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Power_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Power_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Power_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Power_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_RealTimeClock_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_ServiceReminder_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_ServiceReminder_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_ServiceReminder_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_ServiceReminder_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_ServiceReminder_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_ServiceReminder_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_SpeedoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_SpeedoGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_SpeedoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_SpeedoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_SpeedoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_TachoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_TachoGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_TachoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TachoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TachoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_TempGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_TempGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_TempGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TempGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TempGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Temp_Threshold_Hysteresis_Derating> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Temperature_Sensor_Conv> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Temperature_Sensor_Conv_SafeCopy1> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Temperature_Sensor_Conv_SafeCopy2> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_TripComputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_TripComputer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TripComputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_TripComputer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsConst_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsConst_Warning_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsConst_Warning_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Warning_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsConst_Warning_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsCys_Certicificate_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsCys_Certicificate_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsCys_Certicificate_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsCys_Certicificate_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsDiag_Dtc_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsDiag_Dtc_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsDiag_Dtc_Element(Rte_DT_Arr_u8_2048_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_2048_0* is of type Arr_u8_2048
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsDiag_Dtc_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsDiag_Dtc_Element(P2VAR(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsDiag_Dtc_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsDiag_ErrorRecord_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsDiag_ErrorRecord_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsDiag_ErrorRecord_Element(Rte_DT_Arr_u8_1024_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_1024_0* is of type Arr_u8_1024
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsDiag_ErrorRecord_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsDiag_ErrorRecord_Element(P2VAR(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsDiag_ErrorRecord_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Audio_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Audio_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Audio_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Audio_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Communication_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Communication_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Communication_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Communication_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Display_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Display_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Display_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Display_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Display_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Display_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Gauges_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Gauges_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Gauges_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Gauges_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Gauges_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Gauges_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Illumination_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Illumination_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Odometer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Odometer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Odometer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Odometer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Odometer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Odometer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Personalization_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Personalization_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Personalization_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Personalization_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Personalization_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Personalization_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Power_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Power_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Power_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Power_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_RealTimeClock_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_RealTimeClock_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Tripcomputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Tripcomputer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Tripcomputer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Tripcomputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Tripcomputer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Tripcomputer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsReten_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsReten_Warning_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsReten_Warning_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Warning_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsReten_Warning_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_CusDlt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_CusDlt_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_CusDlt_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_CusDlt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_CusDlt_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_CusDlt_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_FuelGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_FuelGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_FuelGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_FuelGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_FuelGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_Illumination_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Illumination_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_Odometer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_Odometer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_Odometer_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Odometer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Odometer_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Odometer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_OilGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_OilGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_OilGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_OilGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_OilGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_Personalization_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_Personalization_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_Personalization_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Personalization_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Personalization_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Personalization_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_PowerGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_PowerGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_PowerGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_PowerGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_PowerGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_RealTimeClock_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_SpeedoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_SpeedoGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_SpeedoGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_SpeedoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_SpeedoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_TachoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_TachoGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_TachoGauge_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TachoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TachoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_TempGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_TempGauge_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_TempGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TempGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TempGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_TripComputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_TripComputer_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TripComputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_TripComputer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsRt_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsRt_Warning_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsRt_Warning_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Warning_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsRt_Warning_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_AssemblyManufacturingDate> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_AssemblyPlantNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_AssemblyPlantNumber> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_AssemblyPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_AssemblyPlantNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_AssemblyPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_AssemblyPlantNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_EcuPartNumber_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_EcuPartNumber_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(Rte_DT_Arr_u8_61_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_61_0* is of type Arr_u8_61
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_EcuPartNumber_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(P2VAR(Rte_DT_Arr_u8_61_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_EcuPartNumber_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_HWModification
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_HWModification> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_HWModification(UInt16 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_HWModification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_HWModification(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_HWModification (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_PCBSerialNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_PCBSerialNumber> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_PCBSerialNumber(Rte_DT_Arr_u8_9_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_9_0* is of type Arr_u8_9
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_PCBSerialNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_PCBSerialNumber(P2VAR(Rte_DT_Arr_u8_9_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_PCBSerialNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_ProductSerialNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_ProductSerialNumber> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_ProductSerialNumber(Rte_DT_Arr_u8_10_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_10_0* is of type Arr_u8_10
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_ProductSerialNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_ProductSerialNumber(P2VAR(Rte_DT_Arr_u8_10_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_ProductSerialNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SMTManufacturingDate
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SMTManufacturingDate> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SMTManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SMTManufacturingDate_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SMTManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SMTManufacturingDate (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SMTPlantNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SMTPlantNumber> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SMTPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SMTPlantNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SMTPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SMTPlantNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SwUpdFotaFinPrint_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SwUpdFotaMode_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SwUpdFotaStatus_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SwUpdFotadecrypt_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_SwUpdReflash_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_SwUpdReflash_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_SwUpdReflash_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdReflash_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdReflash_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_SwUpdReflash_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_VehicleConfig_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_VehicleConfig_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_VehicleConfig_Element(Rte_DT_Arr_u8_256_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VehicleConfig_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VehicleConfig_Element(P2VAR(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VehicleConfig_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_VisMeet_EOLEntry_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element(UInt16 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_VisMeet_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_VisMeet_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_VisMeet_Element(Rte_DT_Arr_u8_46_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_46_0* is of type Arr_u8_46
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VisMeet_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisMeet_Element(P2VAR(Rte_DT_Arr_u8_46_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VisMeet_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_VisteonPCBPartNumber> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_BsShare_VisteonPartNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_BsShare_VisteonPartNumber> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_BsShare_VisteonPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VisteonPartNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisteonPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_BsShare_VisteonPartNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Audio_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Audio_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Audio_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Audio_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_BsConst_Illumination_ReservedByte> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Communication_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Communication_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Communication_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Communication_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Compensation_Line_Shift_b> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy1> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy2> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Compensation_Line_Slope_m> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy1> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy2> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Derating_Backlight_Disable> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy1> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy2> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Display_Illum_Max_Level> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level(UInt16 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy1> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy1(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy2> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy2(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_EngOffTimer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_EngOffTimer_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_EngOffTimer_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_EngOffTimer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_EngOffTimer_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_EngOffTimer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_FuelGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_FuelGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_FuelGauge_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_FuelGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_FuelGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_OilGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_OilGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_OilGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_OilGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_OilGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_PCB_Temperature_Sensor_Conv> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_PWM_boost_bypass_duty> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy1> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy2> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_PowerGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_PowerGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PowerGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PowerGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_PowerGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Power_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Power_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Power_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Power_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_RealTimeClock_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_ServiceReminder_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_ServiceReminder_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_ServiceReminder_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_ServiceReminder_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_ServiceReminder_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_ServiceReminder_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_SpeedoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_SpeedoGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_SpeedoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_SpeedoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_SpeedoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_TachoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_TachoGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_TachoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_TachoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_TachoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_TempGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_TempGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_TempGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_TempGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_TempGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Temperature_Sensor_Conv> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy1> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy1 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy2> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy2 (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_TripComputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_TripComputer_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_TripComputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_TripComputer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsConst_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsConst_Warning_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Warning_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Warning_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsConst_Warning_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsCys_Certicificate_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsCys_Certicificate_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsCys_Certicificate_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsCys_Certicificate_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsDiag_Dtc_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsDiag_Dtc_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsDiag_Dtc_Element(Rte_DT_Arr_u8_2048_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_2048_0* is of type Arr_u8_2048
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsDiag_Dtc_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsDiag_Dtc_Element(P2VAR(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsDiag_Dtc_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsDiag_ErrorRecord_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsDiag_ErrorRecord_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsDiag_ErrorRecord_Element(Rte_DT_Arr_u8_1024_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_1024_0* is of type Arr_u8_1024
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsDiag_ErrorRecord_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsDiag_ErrorRecord_Element(P2VAR(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsDiag_ErrorRecord_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsReten_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsReten_Audio_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Audio_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Audio_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Audio_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsReten_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsReten_Communication_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Communication_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Communication_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Communication_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsReten_Display_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsReten_Display_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Display_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Display_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Display_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Display_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsReten_Gauges_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsReten_Gauges_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Gauges_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Gauges_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Gauges_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Gauges_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsReten_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsReten_Illumination_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Illumination_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsReten_Odometer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsReten_Odometer_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Odometer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Odometer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Odometer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Odometer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsReten_Personalization_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsReten_Personalization_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Personalization_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Personalization_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Personalization_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Personalization_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsReten_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsReten_Power_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Power_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Power_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Power_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsReten_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsReten_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsReten_RealTimeClock_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_RealTimeClock_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsReten_Tripcomputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsReten_Tripcomputer_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Tripcomputer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Tripcomputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Tripcomputer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Tripcomputer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsReten_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsReten_Warning_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Warning_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Warning_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsReten_Warning_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_CusDlt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_CusDlt_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_CusDlt_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_CusDlt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_CusDlt_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_CusDlt_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_FuelGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_FuelGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_FuelGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_FuelGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_FuelGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_Illumination_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_Illumination_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_Odometer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_Odometer_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_Odometer_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_Odometer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Odometer_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_Odometer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_OilGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_OilGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_OilGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_OilGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_OilGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_Personalization_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_Personalization_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_Personalization_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_Personalization_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Personalization_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_Personalization_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_PowerGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_PowerGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_PowerGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_PowerGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_PowerGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_RealTimeClock_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_SpeedoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_SpeedoGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_SpeedoGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_SpeedoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_SpeedoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_TachoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_TachoGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_TachoGauge_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_TachoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_TachoGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_TempGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_TempGauge_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_TempGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_TempGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_TempGauge_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_TripComputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_TripComputer_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_TripComputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_TripComputer_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsRt_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsRt_Warning_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsRt_Warning_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Warning_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsRt_Warning_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_AssemblyManufacturingDate
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_AssemblyManufacturingDate> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_AssemblyManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_AssemblyManufacturingDate_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_AssemblyManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_AssemblyManufacturingDate (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_AssemblyPlantNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_AssemblyPlantNumber> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_AssemblyPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_AssemblyPlantNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_AssemblyPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_AssemblyPlantNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_EcuPartNumber_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_EcuPartNumber_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_EcuPartNumber_Element(Rte_DT_Arr_u8_61_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_61_0* is of type Arr_u8_61
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_EcuPartNumber_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_EcuPartNumber_Element(P2VAR(Rte_DT_Arr_u8_61_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_EcuPartNumber_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_HWModification
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_HWModification> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_HWModification(UInt16 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_HWModification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_HWModification(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_HWModification (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_PCBSerialNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_PCBSerialNumber> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_PCBSerialNumber(Rte_DT_Arr_u8_9_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_9_0* is of type Arr_u8_9
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_PCBSerialNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_PCBSerialNumber(P2VAR(Rte_DT_Arr_u8_9_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_PCBSerialNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_ProductSerialNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_ProductSerialNumber> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_ProductSerialNumber(Rte_DT_Arr_u8_10_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_10_0* is of type Arr_u8_10
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_ProductSerialNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_ProductSerialNumber(P2VAR(Rte_DT_Arr_u8_10_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_ProductSerialNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_SMTManufacturingDate
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_SMTManufacturingDate> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SMTManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SMTManufacturingDate_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SMTManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SMTManufacturingDate (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_SMTPlantNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_SMTPlantNumber> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SMTPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SMTPlantNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SMTPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SMTPlantNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_SwUpdFotaFinPrint_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_SwUpdFotaFinPrint_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SwUpdFotaFinPrint_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SwUpdFotaFinPrint_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotaFinPrint_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SwUpdFotaFinPrint_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_SwUpdFotaMode_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_SwUpdFotaMode_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SwUpdFotaMode_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SwUpdFotaMode_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotaMode_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SwUpdFotaMode_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_SwUpdFotaStatus_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_SwUpdFotaStatus_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SwUpdFotaStatus_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SwUpdFotaStatus_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotaStatus_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SwUpdFotaStatus_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_SwUpdFotadecrypt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_SwUpdFotadecrypt_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SwUpdFotadecrypt_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SwUpdFotadecrypt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotadecrypt_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SwUpdFotadecrypt_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_SwUpdReflash_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_SwUpdReflash_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SwUpdReflash_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SwUpdReflash_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdReflash_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_SwUpdReflash_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_VehicleConfig_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_VehicleConfig_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_VehicleConfig_Element(Rte_DT_Arr_u8_256_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_VehicleConfig_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VehicleConfig_Element(P2VAR(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_VehicleConfig_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_VisMeet_EOLEntry_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_VisMeet_EOLEntry_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_VisMeet_EOLEntry_Element(UInt16 *Ptr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_VisMeet_EOLEntry_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VisMeet_EOLEntry_Element(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_VisMeet_EOLEntry_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_VisMeet_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_VisMeet_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_VisMeet_Element(Rte_DT_Arr_u8_46_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_46_0* is of type Arr_u8_46
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_VisMeet_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VisMeet_Element(P2VAR(Rte_DT_Arr_u8_46_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_VisMeet_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_VisteonPCBPartNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_VisteonPCBPartNumber> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_VisteonPCBPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_VisteonPCBPartNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VisteonPCBPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_VisteonPCBPartNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_BsShare_VisteonPartNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_BsShare_VisteonPartNumber> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_BsShare_VisteonPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_VisteonPartNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VisteonPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_BsShare_VisteonPartNumber (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_RefCys_Certicificate1_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_RefCys_Certicificate1_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_RefCys_Certicificate1_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_RefCys_Certicificate1_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_RefCys_Certicificate1_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_RefCys_Certicificate1_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_Default_RefCys_Certicificate_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_Default_RefCys_Certicificate_Element> of PortPrototype <pp_CS_MemAbsGetDefault>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_Default_RefCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_RefCys_Certicificate_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_RefCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_Default_RefCys_Certicificate_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_RefCys_Certicificate1_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_RefCys_Certicificate1_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_RefCys_Certicificate1_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_RefCys_Certicificate1_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_RefCys_Certicificate1_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_RefCys_Certicificate1_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Get_RefCys_Certicificate_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_RefCys_Certicificate_Element> of PortPrototype <pp_CS_MemAbsGet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_Get_RefCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_RefCys_Certicificate_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_RefCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Get_RefCys_Certicificate_Element (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_NvmWriteStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NvmWriteStatus> of PortPrototype <pp_CS_MemAbs_NvMWriteStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MemAbstractMdl_NvmWriteStatus(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_MemAbs_NvMWriteStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NvmWriteStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_NvmWriteStatus(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_NvmWriteStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Audio_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Audio_Element(const Rte_DT_Arr_u8_128_0 *BsConst_Audio_Element)
 *     Argument BsConst_Audio_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Audio_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Audio_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Audio_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_BsConst_Illumination_ReservedByte> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte)
 *     Argument BsConst_BsConst_Illumination_ReservedByte: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte(P2CONST(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_BsConst_Illumination_ReservedByte) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte_SafeCopy1)
 *     Argument BsConst_BsConst_Illumination_ReservedByte_SafeCopy1: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2CONST(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_BsConst_Illumination_ReservedByte_SafeCopy1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte_SafeCopy2)
 *     Argument BsConst_BsConst_Illumination_ReservedByte_SafeCopy2: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2CONST(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_BsConst_Illumination_ReservedByte_SafeCopy2) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Communication_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Communication_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Communication_Element)
 *     Argument BsConst_Communication_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Communication_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Communication_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Communication_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Compensation_Line_Shift_b> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b(UInt32 BsConst_Compensation_Line_Shift_b)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b(UInt32 BsConst_Compensation_Line_Shift_b) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Compensation_Line_Shift_b_SafeCopy1> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy1)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Compensation_Line_Shift_b_SafeCopy2> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy2)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy2) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Compensation_Line_Slope_m> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m(UInt32 BsConst_Compensation_Line_Slope_m)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m(UInt32 BsConst_Compensation_Line_Slope_m) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Compensation_Line_Slope_m_SafeCopy1> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy1)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Compensation_Line_Slope_m_SafeCopy2> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy2)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy2) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Derating_Backlight_Disable> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable(UInt8 BsConst_Derating_Backlight_Disable)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable(UInt8 BsConst_Derating_Backlight_Disable) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Derating_Backlight_Disable_SafeCopy1> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy1)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Derating_Backlight_Disable_SafeCopy2> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy2)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy2) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Display_Illum_Max_Level> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level(UInt16 BsConst_Display_Illum_Max_Level)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level(UInt16 BsConst_Display_Illum_Max_Level) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Display_Illum_Max_Level_SafeCopy1> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy1)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Display_Illum_Max_Level_SafeCopy2> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy2)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy2) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_EngOffTimer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_EngOffTimer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_EngOffTimer_Element(const Rte_DT_Arr_u8_32_0 *BsConst_EngOffTimer_Element)
 *     Argument BsConst_EngOffTimer_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_EngOffTimer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_EngOffTimer_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_EngOffTimer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_EngOffTimer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_FuelGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_FuelGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_FuelGauge_Element(const Rte_DT_Arr_u8_128_0 *BsConst_FuelGauge_Element)
 *     Argument BsConst_FuelGauge_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_FuelGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_FuelGauge_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_FuelGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_FuelGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Lookup_Curve_HotSpot_Coef_X> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_X: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_X) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Lookup_Curve_HotSpot_Coef_Y> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_Y: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_Y) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2)
 *     Argument BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_OilGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_OilGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_OilGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_OilGauge_Element)
 *     Argument BsConst_OilGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_OilGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_OilGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_OilGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_OilGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_PCB_Temperature_Sensor_Conv> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv)
 *     Argument BsConst_PCB_Temperature_Sensor_Conv: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PCB_Temperature_Sensor_Conv) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1)
 *     Argument BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2)
 *     Argument BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_PWM_boost_bypass_duty> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty(UInt8 BsConst_PWM_boost_bypass_duty)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty(UInt8 BsConst_PWM_boost_bypass_duty) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_PWM_boost_bypass_duty_SafeCopy1> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy1)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_PWM_boost_bypass_duty_SafeCopy2> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy2)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy2) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_PowerGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_PowerGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_PowerGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_PowerGauge_Element)
 *     Argument BsConst_PowerGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PowerGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PowerGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PowerGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_PowerGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Power_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Power_Element(const Rte_DT_Arr_u8_32_0 *BsConst_Power_Element)
 *     Argument BsConst_Power_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Power_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Power_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Power_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsConst_RealTimeClock_Element)
 *     Argument BsConst_RealTimeClock_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_RealTimeClock_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_RealTimeClock_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_ServiceReminder_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_ServiceReminder_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_ServiceReminder_Element(const Rte_DT_Arr_u8_48_0 *BsConst_ServiceReminder_Element)
 *     Argument BsConst_ServiceReminder_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_ServiceReminder_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_ServiceReminder_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_ServiceReminder_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_ServiceReminder_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_SpeedoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_SpeedoGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_SpeedoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_SpeedoGauge_Element)
 *     Argument BsConst_SpeedoGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_SpeedoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_SpeedoGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_SpeedoGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_SpeedoGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_TachoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_TachoGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_TachoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TachoGauge_Element)
 *     Argument BsConst_TachoGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TachoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TachoGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TachoGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TachoGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_TempGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_TempGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_TempGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TempGauge_Element)
 *     Argument BsConst_TempGauge_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TempGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TempGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TempGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TempGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Temp_Threshold_Hysteresis_Derating> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Temperature_Sensor_Conv> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv)
 *     Argument BsConst_Temperature_Sensor_Conv: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Temperature_Sensor_Conv) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Temperature_Sensor_Conv_SafeCopy1> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv_SafeCopy1)
 *     Argument BsConst_Temperature_Sensor_Conv_SafeCopy1: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Temperature_Sensor_Conv_SafeCopy1) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Temperature_Sensor_Conv_SafeCopy2> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv_SafeCopy2)
 *     Argument BsConst_Temperature_Sensor_Conv_SafeCopy2: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Temperature_Sensor_Conv_SafeCopy2) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_TripComputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_TripComputer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TripComputer_Element)
 *     Argument BsConst_TripComputer_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TripComputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TripComputer_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TripComputer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_TripComputer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsConst_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsConst_Warning_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsConst_Warning_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Warning_Element)
 *     Argument BsConst_Warning_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Warning_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Warning_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsConst_Warning_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsCys_Certicificate_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsCys_Certicificate_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *BsCys_Certicificate_Element)
 *     Argument BsCys_Certicificate_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsCys_Certicificate_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsCys_Certicificate_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsCys_Certicificate_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsCys_Certicificate_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsDiag_Dtc_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsDiag_Dtc_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsDiag_Dtc_Element(const Rte_DT_Arr_u8_2048_0 *BsDiag_Dtc_Element)
 *     Argument BsDiag_Dtc_Element: Rte_DT_Arr_u8_2048_0* is of type Arr_u8_2048
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsDiag_Dtc_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsDiag_Dtc_Element(P2CONST(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_Dtc_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsDiag_Dtc_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsDiag_ErrorRecord_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsDiag_ErrorRecord_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsDiag_ErrorRecord_Element(const Rte_DT_Arr_u8_1024_0 *BsDiag_ErrorRecord_Element)
 *     Argument BsDiag_ErrorRecord_Element: Rte_DT_Arr_u8_1024_0* is of type Arr_u8_1024
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsDiag_ErrorRecord_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsDiag_ErrorRecord_Element(P2CONST(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_ErrorRecord_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsDiag_ErrorRecord_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Audio_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Audio_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Audio_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Audio_Element)
 *     Argument BsReten_Audio_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Audio_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Audio_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Audio_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Audio_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Communication_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Communication_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Communication_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Communication_Element)
 *     Argument BsReten_Communication_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Communication_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Communication_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Communication_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Communication_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Display_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Display_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Display_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Display_Element)
 *     Argument BsReten_Display_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Display_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Display_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Display_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Display_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Gauges_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Gauges_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Gauges_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Gauges_Element)
 *     Argument BsReten_Gauges_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Gauges_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Gauges_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Gauges_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Gauges_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Illumination_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Illumination_Element)
 *     Argument BsReten_Illumination_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Illumination_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Illumination_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Illumination_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Odometer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Odometer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Odometer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Odometer_Element)
 *     Argument BsReten_Odometer_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Odometer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Odometer_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Odometer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Odometer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Personalization_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Personalization_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Personalization_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Personalization_Element)
 *     Argument BsReten_Personalization_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Personalization_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Personalization_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Personalization_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Personalization_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Power_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Power_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Power_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Power_Element)
 *     Argument BsReten_Power_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Power_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Power_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Power_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Power_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_RealTimeClock_Element(const Rte_DT_Arr_u8_100_0 *BsReten_RealTimeClock_Element)
 *     Argument BsReten_RealTimeClock_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_RealTimeClock_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_RealTimeClock_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Tripcomputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Tripcomputer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Tripcomputer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Tripcomputer_Element)
 *     Argument BsReten_Tripcomputer_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Tripcomputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Tripcomputer_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Tripcomputer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Tripcomputer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsReten_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsReten_Warning_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsReten_Warning_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Warning_Element)
 *     Argument BsReten_Warning_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Warning_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Warning_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsReten_Warning_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_CusDlt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_CusDlt_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_CusDlt_Element(const Rte_DT_Arr_u8_128_0 *BsRt_CusDlt_Element)
 *     Argument BsRt_CusDlt_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_CusDlt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_CusDlt_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_CusDlt_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_CusDlt_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_FuelGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_FuelGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_FuelGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_FuelGauge_Element)
 *     Argument BsRt_FuelGauge_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_FuelGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_FuelGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_FuelGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_FuelGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_Illumination_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_Illumination_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsRt_Illumination_Element)
 *     Argument BsRt_Illumination_Element: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Illumination_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Illumination_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Illumination_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Illumination_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_Odometer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_Odometer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_Odometer_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Odometer_Element)
 *     Argument BsRt_Odometer_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Odometer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Odometer_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Odometer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Odometer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_OilGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_OilGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_OilGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_OilGauge_Element)
 *     Argument BsRt_OilGauge_Element: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_OilGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_OilGauge_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_OilGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_OilGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_Personalization_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_Personalization_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_Personalization_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Personalization_Element)
 *     Argument BsRt_Personalization_Element: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Personalization_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Personalization_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Personalization_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Personalization_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_PowerGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_PowerGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_PowerGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_PowerGauge_Element)
 *     Argument BsRt_PowerGauge_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_PowerGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_PowerGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_PowerGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_PowerGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_RealTimeClock_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_RealTimeClock_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsRt_RealTimeClock_Element)
 *     Argument BsRt_RealTimeClock_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_RealTimeClock_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_RealTimeClock_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_RealTimeClock_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_SpeedoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_SpeedoGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_SpeedoGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_SpeedoGauge_Element)
 *     Argument BsRt_SpeedoGauge_Element: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_SpeedoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_SpeedoGauge_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_SpeedoGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_SpeedoGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_TachoGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_TachoGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_TachoGauge_Element(const Rte_DT_Arr_u8_16_0 *BsRt_TachoGauge_Element)
 *     Argument BsRt_TachoGauge_Element: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TachoGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TachoGauge_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TachoGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TachoGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_TempGauge_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_TempGauge_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_TempGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_TempGauge_Element)
 *     Argument BsRt_TempGauge_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TempGauge_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TempGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TempGauge_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TempGauge_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_TripComputer_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_TripComputer_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsRt_TripComputer_Element)
 *     Argument BsRt_TripComputer_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TripComputer_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TripComputer_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TripComputer_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_TripComputer_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsRt_Warning_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsRt_Warning_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsRt_Warning_Element(const Rte_DT_Arr_u8_32_0 *BsRt_Warning_Element)
 *     Argument BsRt_Warning_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Warning_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Warning_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Warning_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsRt_Warning_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_AssemblyManufacturingDate> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate(const Rte_DT_Arr_u8_3_0 *BsShare_AssemblyManufacturingDate)
 *     Argument BsShare_AssemblyManufacturingDate: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_AssemblyManufacturingDate) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_AssemblyPlantNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_AssemblyPlantNumber> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_AssemblyPlantNumber(const Rte_DT_Arr_u8_3_0 *BsShare_AssemblyPlantNumber)
 *     Argument BsShare_AssemblyPlantNumber: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_AssemblyPlantNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_AssemblyPlantNumber(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_AssemblyPlantNumber) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_AssemblyPlantNumber
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_EcuPartNumber_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_EcuPartNumber_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(const Rte_DT_Arr_u8_61_0 *BsShare_EcuPartNumber_Element)
 *     Argument BsShare_EcuPartNumber_Element: Rte_DT_Arr_u8_61_0* is of type Arr_u8_61
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_EcuPartNumber_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(P2CONST(Rte_DT_Arr_u8_61_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_EcuPartNumber_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_EcuPartNumber_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_HWModification
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_HWModification> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_HWModification(UInt16 BsShare_HWModification)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_HWModification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_HWModification(UInt16 BsShare_HWModification) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_HWModification
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_PCBSerialNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_PCBSerialNumber> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_PCBSerialNumber(const Rte_DT_Arr_u8_9_0 *BsShare_PCBSerialNumber)
 *     Argument BsShare_PCBSerialNumber: Rte_DT_Arr_u8_9_0* is of type Arr_u8_9
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_PCBSerialNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_PCBSerialNumber(P2CONST(Rte_DT_Arr_u8_9_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_PCBSerialNumber) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_PCBSerialNumber
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_ProductSerialNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_ProductSerialNumber> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_ProductSerialNumber(const Rte_DT_Arr_u8_10_0 *BsShare_ProductSerialNumber)
 *     Argument BsShare_ProductSerialNumber: Rte_DT_Arr_u8_10_0* is of type Arr_u8_10
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_ProductSerialNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_ProductSerialNumber(P2CONST(Rte_DT_Arr_u8_10_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_ProductSerialNumber) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_ProductSerialNumber
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SMTManufacturingDate
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SMTManufacturingDate> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SMTManufacturingDate(const Rte_DT_Arr_u8_3_0 *BsShare_SMTManufacturingDate)
 *     Argument BsShare_SMTManufacturingDate: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SMTManufacturingDate_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SMTManufacturingDate(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SMTManufacturingDate) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SMTManufacturingDate
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SMTPlantNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SMTPlantNumber> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SMTPlantNumber(const Rte_DT_Arr_u8_3_0 *BsShare_SMTPlantNumber)
 *     Argument BsShare_SMTPlantNumber: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SMTPlantNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SMTPlantNumber(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SMTPlantNumber) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SMTPlantNumber
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SwUpdFotaFinPrint_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element(const Rte_DT_Arr_u8_32_0 *BsShare_SwUpdFotaFinPrint_Element)
 *     Argument BsShare_SwUpdFotaFinPrint_Element: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaFinPrint_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SwUpdFotaMode_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element(const Rte_DT_Arr_u8_16_0 *BsShare_SwUpdFotaMode_Element)
 *     Argument BsShare_SwUpdFotaMode_Element: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaMode_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SwUpdFotaStatus_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element(const Rte_DT_Arr_u8_48_0 *BsShare_SwUpdFotaStatus_Element)
 *     Argument BsShare_SwUpdFotaStatus_Element: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaStatus_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SwUpdFotadecrypt_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element(const Rte_DT_Arr_u8_64_0 *BsShare_SwUpdFotadecrypt_Element)
 *     Argument BsShare_SwUpdFotadecrypt_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotadecrypt_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_SwUpdReflash_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_SwUpdReflash_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_SwUpdReflash_Element(const Rte_DT_Arr_u8_8_0 *BsShare_SwUpdReflash_Element)
 *     Argument BsShare_SwUpdReflash_Element: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdReflash_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdReflash_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdReflash_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_SwUpdReflash_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_VehicleConfig_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_VehicleConfig_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_VehicleConfig_Element(const Rte_DT_Arr_u8_256_0 *BsShare_VehicleConfig_Element)
 *     Argument BsShare_VehicleConfig_Element: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VehicleConfig_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VehicleConfig_Element(P2CONST(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VehicleConfig_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VehicleConfig_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_VisMeet_EOLEntry_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_VisMeet_EOLEntry_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_VisMeet_EOLEntry_Element(UInt16 BsShare_VisMeet_EOLEntry_Element)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VisMeet_EOLEntry_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisMeet_EOLEntry_Element(UInt16 BsShare_VisMeet_EOLEntry_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VisMeet_EOLEntry_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_VisMeet_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_VisMeet_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_VisMeet_Element(const Rte_DT_Arr_u8_46_0 *BsShare_VisMeet_Element)
 *     Argument BsShare_VisMeet_Element: Rte_DT_Arr_u8_46_0* is of type Arr_u8_46
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VisMeet_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisMeet_Element(P2CONST(Rte_DT_Arr_u8_46_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisMeet_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VisMeet_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_VisteonPCBPartNumber> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber(const Rte_DT_Arr_u8_17_0 *BsShare_VisteonPCBPartNumber)
 *     Argument BsShare_VisteonPCBPartNumber: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber(P2CONST(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisteonPCBPartNumber) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_BsShare_VisteonPartNumber
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_BsShare_VisteonPartNumber> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_BsShare_VisteonPartNumber(const Rte_DT_Arr_u8_17_0 *BsShare_VisteonPartNumber)
 *     Argument BsShare_VisteonPartNumber: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VisteonPartNumber_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisteonPartNumber(P2CONST(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisteonPartNumber) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_BsShare_VisteonPartNumber
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_RefCys_Certicificate1_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_RefCys_Certicificate1_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_RefCys_Certicificate1_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate1_Element)
 *     Argument RefCys_Certicificate1_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_RefCys_Certicificate1_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_RefCys_Certicificate1_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate1_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_RefCys_Certicificate1_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Set_RefCys_Certicificate_Element
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_RefCys_Certicificate_Element> of PortPrototype <pp_CS_MemAbsSet>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Set_RefCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate_Element)
 *     Argument RefCys_Certicificate_Element: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_RefCys_Certicificate_Element_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_RefCys_Certicificate_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate_Element) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Set_RefCys_Certicificate_Element
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define MemAbstractMdl_STOP_SEC_CODE
#include "MemAbstractMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void MemAbstractMdl_TestDefines(void)
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
