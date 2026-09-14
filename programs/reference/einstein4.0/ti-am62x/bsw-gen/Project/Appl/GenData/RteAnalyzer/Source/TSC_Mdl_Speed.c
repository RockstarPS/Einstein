/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TSC_Mdl_Speed.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Mdl_Speed.h"
#include "TSC_Mdl_Speed.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */






Std_ReturnType TSC_Mdl_Speed_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
{
  return Rte_Read_rpIgnSubstate_IgnitionSubstate(data);
}

Std_ReturnType TSC_Mdl_Speed_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
{
  return Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(data);
}

Std_ReturnType TSC_Mdl_Speed_Rte_Read_rp_Countrycode_Func_CountryCode_Func(CountryCode_FuncType *data)
{
  return Rte_Read_rp_Countrycode_Func_CountryCode_Func(data);
}

Std_ReturnType TSC_Mdl_Speed_Rte_Read_rp_Dcm_appStop_AppId(IOCtrl_Type *data)
{
  return Rte_Read_rp_Dcm_appStop_AppId(data);
}

Std_ReturnType TSC_Mdl_Speed_Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(UInt16 *data)
{
  return Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(data);
}

Std_ReturnType TSC_Mdl_Speed_Rte_Read_rp_DispDistanceUnit_DisplayUnit(UInt8 *data)
{
  return Rte_Read_rp_DispDistanceUnit_DisplayUnit(data);
}




Std_ReturnType TSC_Mdl_Speed_Rte_Write_pp_SPD_SP1_In_Status_SP1_In_Status(UInt16 data)
{
  return Rte_Write_pp_SPD_SP1_In_Status_SP1_In_Status(data);
}

Std_ReturnType TSC_Mdl_Speed_Rte_Write_pp_SPD_Selection_Table_Speed_Selection_Table(UInt8 data)
{
  return Rte_Write_pp_SPD_Selection_Table_Speed_Selection_Table(data);
}

Std_ReturnType TSC_Mdl_Speed_Rte_Write_pp_SPD_Target2_Status_Spd_Target2_Status(UInt16 data)
{
  return Rte_Write_pp_SPD_Target2_Status_Spd_Target2_Status(data);
}

Std_ReturnType TSC_Mdl_Speed_Rte_Write_pp_SPD_Target_Status_Spd_Target_Status(UInt16 data)
{
  return Rte_Write_pp_SPD_Target_Status_Spd_Target_Status(data);
}

Std_ReturnType TSC_Mdl_Speed_Rte_Write_pp_SPD_Trim2_Status_Spd_Trim2_Status(UInt16 data)
{
  return Rte_Write_pp_SPD_Trim2_Status_Spd_Trim2_Status(data);
}

Std_ReturnType TSC_Mdl_Speed_Rte_Write_pp_SPD_Trim_Status_Spd_Trim_Status(UInt16 data)
{
  return Rte_Write_pp_SPD_Trim_Status_Spd_Trim_Status(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(AdcId, AsyncRawAdc, ErrorStatus);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(AdcId, ProcessedAdc, ErrorStatus);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(AdcId, SyncRawAdc, ErrorStatus);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(tSafeRxSignalId SignalId)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(tSafeRxSignalId SignalId, tSafeRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateByte(UInt8 *ptr_table, UInt8 lookupvalue, UInt8 *Ptr_Lin_Return)
{
  return Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateByte(ptr_table, lookupvalue, Ptr_Lin_Return);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSByte(SInt8 *ptr_table, SInt8 lookupvalue, SInt8 *Ptr_Lin_Return)
{
  return Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSByte(ptr_table, lookupvalue, Ptr_Lin_Return);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSWord(SInt16 *ptr_table, SInt16 lookupvalue, SInt16 *Ptr_Lin_Return)
{
  return Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateSWord(ptr_table, lookupvalue, Ptr_Lin_Return);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateWord(UInt16 *ptr_table, UInt16 lookupvalue, UInt16 *Ptr_Lin_Return)
{
  return Rte_Call_rp_CS_LinerInterpolation_Get_LinearInterpolateWord(ptr_table, lookupvalue, Ptr_Lin_Return);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte(Rte_DT_Arr_u8_28_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Rte_DT_Arr_u8_28_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Rte_DT_Arr_u8_28_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Rte_DT_Arr_u8_2048_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Rte_DT_Arr_u8_1024_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Rte_DT_Arr_u8_16_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Rte_DT_Arr_u8_61_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Rte_DT_Arr_u8_9_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Rte_DT_Arr_u8_10_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Rte_DT_Arr_u8_16_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Rte_DT_Arr_u8_256_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Rte_DT_Arr_u8_46_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Speed_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Ptr);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* Mdl_Speed */
      /* Mdl_Speed */



