/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  MemAbstract_Stub_Safe.c
 *        Config:  BMW.dpa
 *     SW-C Type:  MemAbstract_Stub_Safe
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <MemAbstract_Stub_Safe>
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

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * NvM_RequestResultType
 *   
 *
 * NvM_ServiceIdType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_MemAbstract_Stub_Safe.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_MemAbstract_Stub_Safe.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void MemAbstract_Stub_Safe_TestDefines(void);


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
 * Rte_DT_Arr_u8_28_0: Integer in interval [0...255]
 * Rte_DT_T_NV_Temperature_Conversion_0: Integer in interval [0...4294967295]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * NvM_ServiceIdType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_READ_BLOCK (6U)
 *   NVM_WRITE_BLOCK (7U)
 *   NVM_RESTORE_BLOCK_DEFAULTS (8U)
 *   NVM_ERASE_BLOCK (9U)
 *   NVM_INVALIDATE_NV_BLOCK (11U)
 *   NVM_READ_ALL (12U)
 *
 * Array Types:
 * ============
 * Arr_u16_7: Array with 7 element(s) of type Rte_DT_Arr_u16_7_0
 * Arr_u8_28: Array with 28 element(s) of type Rte_DT_Arr_u8_28_0
 * T_NV_Temperature_Conversion: Array with 2 element(s) of type Rte_DT_T_NV_Temperature_Conversion_0
 *
 *********************************************************************************************************************/


#define MemAbstract_Stub_Safe_START_SEC_CODE
#include "MemAbstract_Stub_Safe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_Illumination_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstract_Stub_Safe_CODE) MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination
 *********************************************************************************************************************/

  MemAbstract_Stub_Safe_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_Illumination_Copy1_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy1(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy1_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstract_Stub_Safe_CODE) MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy1(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy1
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <BsConst_Illumination_Copy2_NvMNotifyJobFinished>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy2(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy2_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstract_Stub_Safe_CODE) MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy2(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy2
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MemAbstract_Stub_Safe
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
 *   Std_ReturnType Rte_Read_BsConst_BsConst_Illumination_ReservedByte_Value(Rte_DT_Arr_u8_28_0 *data)
 *     Argument data: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *   Std_ReturnType Rte_Read_BsConst_Compensation_Line_Shift_b_Value(uint32 *data)
 *   Std_ReturnType Rte_Read_BsConst_Compensation_Line_Slope_m_Value(uint32 *data)
 *   Std_ReturnType Rte_Read_BsConst_Derating_Backlight_Disable_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_Display_Illum_Max_Level_Safe_Value(uint16 *data)
 *   Std_ReturnType Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_Value(Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Read_BsConst_PWM_boost_bypass_duty_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_Value(uint8 *data)
 *   Std_ReturnType Rte_Read_BsConst_Temperature_Sensor_Conv_Value(Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BsConst_BsConst_Illumination_ReservedByte_Value(const Rte_DT_Arr_u8_28_0 *data)
 *     Argument data: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *   Std_ReturnType Rte_Write_BsConst_Compensation_Line_Shift_b_Value(uint32 data)
 *   Std_ReturnType Rte_Write_BsConst_Compensation_Line_Slope_m_Value(uint32 data)
 *   Std_ReturnType Rte_Write_BsConst_Derating_Backlight_Disable_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_Display_Illum_Max_Level_Safe_Value(uint16 data)
 *   Std_ReturnType Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(const Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(const Rte_DT_Arr_u16_7_0 *data)
 *     Argument data: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *   Std_ReturnType Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_Value(const Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *   Std_ReturnType Rte_Write_BsConst_PWM_boost_bypass_duty_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_Value(uint8 data)
 *   Std_ReturnType Rte_Write_BsConst_Temperature_Sensor_Conv_Value(const Rte_DT_T_NV_Temperature_Conversion_0 *data)
 *     Argument data: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstract_Stub_Safe_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MemAbstract_Stub_Safe_CODE) MemAbstract_Stub_Safe(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MemAbstract_Stub_Safe
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Arr_u8_28 Read_BsConst_BsConst_Illumination_ReservedByte_Value;
  uint32 Read_BsConst_Compensation_Line_Shift_b_Value;
  uint32 Read_BsConst_Compensation_Line_Slope_m_Value;
  uint8 Read_BsConst_Derating_Backlight_Disable_Value;
  uint16 Read_BsConst_Display_Illum_Max_Level_Safe_Value;
  Arr_u16_7 Read_BsConst_Lookup_Curve_HotSpot_Coef_X_Value;
  Arr_u16_7 Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value;
  T_NV_Temperature_Conversion Read_BsConst_PCB_Temperature_Sensor_Conv_Value;
  uint8 Read_BsConst_PWM_boost_bypass_duty_Value;
  uint8 Read_BsConst_Temp_Threshold_Hysteresis_Derating_Value;
  T_NV_Temperature_Conversion Read_BsConst_Temperature_Sensor_Conv_Value;

  Arr_u8_28 Write_BsConst_BsConst_Illumination_ReservedByte_Value;
  uint32 Write_BsConst_Compensation_Line_Shift_b_Value;
  uint32 Write_BsConst_Compensation_Line_Slope_m_Value;
  uint8 Write_BsConst_Derating_Backlight_Disable_Value;
  uint16 Write_BsConst_Display_Illum_Max_Level_Safe_Value;
  Arr_u16_7 Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value;
  Arr_u16_7 Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value;
  T_NV_Temperature_Conversion Write_BsConst_PCB_Temperature_Sensor_Conv_Value;
  uint8 Write_BsConst_PWM_boost_bypass_duty_Value;
  uint8 Write_BsConst_Temp_Threshold_Hysteresis_Derating_Value;
  T_NV_Temperature_Conversion Write_BsConst_Temperature_Sensor_Conv_Value;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Read_BsConst_BsConst_Illumination_ReservedByte_Value(Read_BsConst_BsConst_Illumination_ReservedByte_Value);
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

  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Read_BsConst_Compensation_Line_Shift_b_Value(&Read_BsConst_Compensation_Line_Shift_b_Value);
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

  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Read_BsConst_Compensation_Line_Slope_m_Value(&Read_BsConst_Compensation_Line_Slope_m_Value);
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

  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Read_BsConst_Derating_Backlight_Disable_Value(&Read_BsConst_Derating_Backlight_Disable_Value);
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

  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Read_BsConst_Display_Illum_Max_Level_Safe_Value(&Read_BsConst_Display_Illum_Max_Level_Safe_Value);
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

  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(Read_BsConst_Lookup_Curve_HotSpot_Coef_X_Value);
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

  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value);
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

  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_Value(Read_BsConst_PCB_Temperature_Sensor_Conv_Value);
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

  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Read_BsConst_PWM_boost_bypass_duty_Value(&Read_BsConst_PWM_boost_bypass_duty_Value);
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

  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_Value(&Read_BsConst_Temp_Threshold_Hysteresis_Derating_Value);
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

  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Read_BsConst_Temperature_Sensor_Conv_Value(Read_BsConst_Temperature_Sensor_Conv_Value);
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

  (void)memset(&Write_BsConst_BsConst_Illumination_ReservedByte_Value, 0, sizeof(Write_BsConst_BsConst_Illumination_ReservedByte_Value));
  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Write_BsConst_BsConst_Illumination_ReservedByte_Value(Write_BsConst_BsConst_Illumination_ReservedByte_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Compensation_Line_Shift_b_Value, 0, sizeof(Write_BsConst_Compensation_Line_Shift_b_Value));
  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Write_BsConst_Compensation_Line_Shift_b_Value(Write_BsConst_Compensation_Line_Shift_b_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Compensation_Line_Slope_m_Value, 0, sizeof(Write_BsConst_Compensation_Line_Slope_m_Value));
  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Write_BsConst_Compensation_Line_Slope_m_Value(Write_BsConst_Compensation_Line_Slope_m_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Derating_Backlight_Disable_Value, 0, sizeof(Write_BsConst_Derating_Backlight_Disable_Value));
  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Write_BsConst_Derating_Backlight_Disable_Value(Write_BsConst_Derating_Backlight_Disable_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Display_Illum_Max_Level_Safe_Value, 0, sizeof(Write_BsConst_Display_Illum_Max_Level_Safe_Value));
  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Write_BsConst_Display_Illum_Max_Level_Safe_Value(Write_BsConst_Display_Illum_Max_Level_Safe_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value, 0, sizeof(Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value));
  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value, 0, sizeof(Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value));
  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_PCB_Temperature_Sensor_Conv_Value, 0, sizeof(Write_BsConst_PCB_Temperature_Sensor_Conv_Value));
  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_Value(Write_BsConst_PCB_Temperature_Sensor_Conv_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_PWM_boost_bypass_duty_Value, 0, sizeof(Write_BsConst_PWM_boost_bypass_duty_Value));
  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Write_BsConst_PWM_boost_bypass_duty_Value(Write_BsConst_PWM_boost_bypass_duty_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Temp_Threshold_Hysteresis_Derating_Value, 0, sizeof(Write_BsConst_Temp_Threshold_Hysteresis_Derating_Value));
  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_Value(Write_BsConst_Temp_Threshold_Hysteresis_Derating_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_BsConst_Temperature_Sensor_Conv_Value, 0, sizeof(Write_BsConst_Temperature_Sensor_Conv_Value));
  fct_status = TSC_MemAbstract_Stub_Safe_Rte_Write_BsConst_Temperature_Sensor_Conv_Value(Write_BsConst_Temperature_Sensor_Conv_Value);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define MemAbstract_Stub_Safe_STOP_SEC_CODE
#include "MemAbstract_Stub_Safe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void MemAbstract_Stub_Safe_TestDefines(void)
{
  /* Enumeration Data Types */

  NvM_RequestResultType Test_NvM_RequestResultType_V_1 = NVM_REQ_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_2 = NVM_REQ_NOT_OK;
  NvM_RequestResultType Test_NvM_RequestResultType_V_3 = NVM_REQ_PENDING;
  NvM_RequestResultType Test_NvM_RequestResultType_V_4 = NVM_REQ_INTEGRITY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_5 = NVM_REQ_BLOCK_SKIPPED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_6 = NVM_REQ_NV_INVALIDATED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_7 = NVM_REQ_CANCELED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_8 = NVM_REQ_REDUNDANCY_FAILED;
  NvM_RequestResultType Test_NvM_RequestResultType_V_9 = NVM_REQ_RESTORED_FROM_ROM;

  NvM_ServiceIdType Test_NvM_ServiceIdType_V_1 = NVM_READ_BLOCK;
  NvM_ServiceIdType Test_NvM_ServiceIdType_V_2 = NVM_WRITE_BLOCK;
  NvM_ServiceIdType Test_NvM_ServiceIdType_V_3 = NVM_RESTORE_BLOCK_DEFAULTS;
  NvM_ServiceIdType Test_NvM_ServiceIdType_V_4 = NVM_ERASE_BLOCK;
  NvM_ServiceIdType Test_NvM_ServiceIdType_V_5 = NVM_INVALIDATE_NV_BLOCK;
  NvM_ServiceIdType Test_NvM_ServiceIdType_V_6 = NVM_READ_ALL;
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
