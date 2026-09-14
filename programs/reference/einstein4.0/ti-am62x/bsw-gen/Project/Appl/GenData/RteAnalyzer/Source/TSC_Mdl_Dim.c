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
 *          File:  TSC_Mdl_Dim.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Mdl_Dim.h"
#include "TSC_Mdl_Dim.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */






Std_ReturnType TSC_Mdl_Dim_Rte_Read_rpEtmSts_Illum_Status(UInt8 *data)
{
  return Rte_Read_rpEtmSts_Illum_Status(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rpEtmTTSts_IllumStatus(UInt8 *data)
{
  return Rte_Read_rpEtmTTSts_IllumStatus(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
{
  return Rte_Read_rpIgnSubstate_IgnitionSubstate(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rpIllum_Etm_IllumStatus(UInt8 *data)
{
  return Rte_Read_rpIllum_Etm_IllumStatus(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rpVehicleAppMode_WSSCurrentVehicleState(VehicleActiveModes *data)
{
  return Rte_Read_rpVehicleAppMode_WSSCurrentVehicleState(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
{
  return Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_Ctrl_Ready_to_Sleep_Ready_to_Sleep(Boolean *data)
{
  return Rte_Read_rp_Ctrl_Ready_to_Sleep_Ready_to_Sleep(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_Dcm_stop_app_AppId(IOCtrl_Type *data)
{
  return Rte_Read_rp_Dcm_stop_app_AppId(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_Diag2F_Rheo_Diag_RheoStat(UInt8 *data)
{
  return Rte_Read_rp_Diag2F_Rheo_Diag_RheoStat(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_EcoRunPresenceFlag_EcoRunPresenceFlag(UInt8 *data)
{
  return Rte_Read_rp_EcoRunPresenceFlag_EcoRunPresenceFlag(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_IlumDayNightRequired_IlumDayNightRequired(UInt8 *data)
{
  return Rte_Read_rp_IlumDayNightRequired_IlumDayNightRequired(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_IlumDayNightStatus_Day_Night_Status(UInt8 *data)
{
  return Rte_Read_rp_IlumDayNightStatus_Day_Night_Status(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(UInt8 *data)
{
  return Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_StopPwmUpdate_channel_id(UInt8 *data)
{
  return Rte_Read_rp_StopPwmUpdate_channel_id(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_TFTDisplayOn_TFTDisplayOn(DisplayStatus *data)
{
  return Rte_Read_rp_TFTDisplayOn_TFTDisplayOn(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_custom_reset_CurrentUserID(UserIdType *data)
{
  return Rte_Read_rp_custom_reset_CurrentUserID(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_custom_reset_CustomizeReset(CustResetType *data)
{
  return Rte_Read_rp_custom_reset_CustomizeReset(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Read_rp_custom_reset_SettingResetResult(SettingResetResult_Type *data)
{
  return Rte_Read_rp_custom_reset_SettingResetResult(data);
}




Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_IllumCtrl_Ip_IllumCtrl_Ip_Data(const IllumCtrl_Ip *data)
{
  return Rte_Write_pp_IllumCtrl_Ip_IllumCtrl_Ip_Data(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_Illum_Transstep_Trans_Stepvlaue(UInt8 data)
{
  return Rte_Write_pp_Illum_Transstep_Trans_Stepvlaue(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_IlluminationDuty_DutyValue(UInt16 data)
{
  return Rte_Write_pp_IlluminationDuty_DutyValue(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_IlumDayNightRequired_ilumDNRequired(UInt8 data)
{
  return Rte_Write_pp_IlumDayNightRequired_ilumDNRequired(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_IlumDayNightStatus_illumDNStatus(UInt8 data)
{
  return Rte_Write_pp_IlumDayNightStatus_illumDNStatus(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_IlumStep_IllumStepValue(UInt8 data)
{
  return Rte_Write_pp_IlumStep_IllumStepValue(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_RGBStep_RGBStepValue(UInt16 data)
{
  return Rte_Write_pp_RGBStep_RGBStepValue(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_RHDW_Dbc_RHDW_Dbc(UInt8 data)
{
  return Rte_Write_pp_RHDW_Dbc_RHDW_Dbc(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_RHUP_Dbc_RHUP_Dbc(UInt8 data)
{
  return Rte_Write_pp_RHUP_Dbc_RHUP_Dbc(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_RheoSwRaw_Status_RawdataStatus(UInt8 data)
{
  return Rte_Write_pp_RheoSwRaw_Status_RawdataStatus(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_RheoSwStatus_SwitchStatus(UInt8 data)
{
  return Rte_Write_pp_RheoSwStatus_SwitchStatus(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_RheostatDayStep_RheostatDayStep(UInt8 data)
{
  return Rte_Write_pp_RheostatDayStep_RheostatDayStep(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_RheostatNightStep_RheostatNightStep(UInt8 data)
{
  return Rte_Write_pp_RheostatNightStep_RheostatNightStep(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_RheostatONSStatus_RheostatONSStatus(UInt8 data)
{
  return Rte_Write_pp_RheostatONSStatus_RheostatONSStatus(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_RheostatSwType_RheostatSwType(UInt8 data)
{
  return Rte_Write_pp_RheostatSwType_RheostatSwType(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_illumRheostatOnSTimer_Rheostat_OnSTime(UInt16 data)
{
  return Rte_Write_pp_illumRheostatOnSTimer_Rheostat_OnSTime(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_illumStarterstatus_StarterStatus_Out(UInt8 data)
{
  return Rte_Write_pp_illumStarterstatus_StarterStatus_Out(data);
}

Std_ReturnType TSC_Mdl_Dim_Rte_Write_pp_illum_rheostat_change_RheoUpdateVal(UInt8 data)
{
  return Rte_Write_pp_illum_rheostat_change_RheoUpdateVal(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(InputId, AsyncInput, ErrorStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_Din_GetInputGroup(InputId, SyncInput, ErrorStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_Din_GetProcessedInput(InputId, InputSignal, ErrorStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_Din_GetSyncRawInput(InputId, SyncInput, ErrorStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rpUpdateDIMWarning_UpdateWarningStatus(WarningId WarningCurId, WarningStatus WarningCurStatus, WarningEvent WarningCurEvent, UInt32 WarningPayload)
{
  return Rte_Call_rpUpdateDIMWarning_UpdateWarningStatus(WarningCurId, WarningCurStatus, WarningCurEvent, WarningPayload);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte(Rte_DT_Arr_u8_28_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Rte_DT_Arr_u8_28_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Rte_DT_Arr_u8_28_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Rte_DT_Arr_u8_2048_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Rte_DT_Arr_u8_1024_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Rte_DT_Arr_u8_16_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Rte_DT_Arr_u8_61_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Rte_DT_Arr_u8_9_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Rte_DT_Arr_u8_10_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Rte_DT_Arr_u8_16_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Rte_DT_Arr_u8_256_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Rte_DT_Arr_u8_46_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Audio_Element(const Rte_DT_Arr_u8_128_0 *BsConst_Audio_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Audio_Element(BsConst_Audio_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte(BsConst_BsConst_Illumination_ReservedByte);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte_SafeCopy1)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(BsConst_BsConst_Illumination_ReservedByte_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte_SafeCopy2)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(BsConst_BsConst_Illumination_ReservedByte_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Communication_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Communication_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Communication_Element(BsConst_Communication_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b(UInt32 BsConst_Compensation_Line_Shift_b)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b(BsConst_Compensation_Line_Shift_b);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy1)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1(BsConst_Compensation_Line_Shift_b_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy2)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2(BsConst_Compensation_Line_Shift_b_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m(UInt32 BsConst_Compensation_Line_Slope_m)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m(BsConst_Compensation_Line_Slope_m);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy1)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1(BsConst_Compensation_Line_Slope_m_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy2)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2(BsConst_Compensation_Line_Slope_m_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable(UInt8 BsConst_Derating_Backlight_Disable)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable(BsConst_Derating_Backlight_Disable);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy1)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable_SafeCopy1(BsConst_Derating_Backlight_Disable_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy2)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Derating_Backlight_Disable_SafeCopy2(BsConst_Derating_Backlight_Disable_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level(UInt16 BsConst_Display_Illum_Max_Level)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level(BsConst_Display_Illum_Max_Level);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy1)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level_SafeCopy1(BsConst_Display_Illum_Max_Level_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy2)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Display_Illum_Max_Level_SafeCopy2(BsConst_Display_Illum_Max_Level_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_EngOffTimer_Element(const Rte_DT_Arr_u8_32_0 *BsConst_EngOffTimer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_EngOffTimer_Element(BsConst_EngOffTimer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_FuelGauge_Element(const Rte_DT_Arr_u8_128_0 *BsConst_FuelGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_FuelGauge_Element(BsConst_FuelGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X(BsConst_Lookup_Curve_HotSpot_Coef_X);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y(BsConst_Lookup_Curve_HotSpot_Coef_Y);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_OilGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_OilGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_OilGauge_Element(BsConst_OilGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv(BsConst_PCB_Temperature_Sensor_Conv);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty(UInt8 BsConst_PWM_boost_bypass_duty)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty(BsConst_PWM_boost_bypass_duty);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy1)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1(BsConst_PWM_boost_bypass_duty_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy2)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2(BsConst_PWM_boost_bypass_duty_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PowerGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_PowerGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PowerGauge_Element(BsConst_PowerGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Power_Element(const Rte_DT_Arr_u8_32_0 *BsConst_Power_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Power_Element(BsConst_Power_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsConst_RealTimeClock_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_RealTimeClock_Element(BsConst_RealTimeClock_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_ServiceReminder_Element(const Rte_DT_Arr_u8_48_0 *BsConst_ServiceReminder_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_ServiceReminder_Element(BsConst_ServiceReminder_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_SpeedoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_SpeedoGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_SpeedoGauge_Element(BsConst_SpeedoGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TachoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TachoGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TachoGauge_Element(BsConst_TachoGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TempGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TempGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TempGauge_Element(BsConst_TempGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating(BsConst_Temp_Threshold_Hysteresis_Derating);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv(BsConst_Temperature_Sensor_Conv);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv_SafeCopy1)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1(BsConst_Temperature_Sensor_Conv_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv_SafeCopy2)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2(BsConst_Temperature_Sensor_Conv_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TripComputer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TripComputer_Element(BsConst_TripComputer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Warning_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Warning_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Warning_Element(BsConst_Warning_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *BsCys_Certicificate_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsCys_Certicificate_Element(BsCys_Certicificate_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_Dtc_Element(const Rte_DT_Arr_u8_2048_0 *BsDiag_Dtc_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_Dtc_Element(BsDiag_Dtc_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_ErrorRecord_Element(const Rte_DT_Arr_u8_1024_0 *BsDiag_ErrorRecord_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_ErrorRecord_Element(BsDiag_ErrorRecord_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Audio_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Audio_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Audio_Element(BsReten_Audio_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Communication_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Communication_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Communication_Element(BsReten_Communication_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Display_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Display_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Display_Element(BsReten_Display_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Gauges_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Gauges_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Gauges_Element(BsReten_Gauges_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Illumination_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Illumination_Element(BsReten_Illumination_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Odometer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Odometer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Odometer_Element(BsReten_Odometer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Personalization_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Personalization_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Personalization_Element(BsReten_Personalization_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Power_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Power_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Power_Element(BsReten_Power_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_RealTimeClock_Element(const Rte_DT_Arr_u8_100_0 *BsReten_RealTimeClock_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_RealTimeClock_Element(BsReten_RealTimeClock_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Tripcomputer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Tripcomputer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Tripcomputer_Element(BsReten_Tripcomputer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Warning_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Warning_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Warning_Element(BsReten_Warning_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_CusDlt_Element(const Rte_DT_Arr_u8_128_0 *BsRt_CusDlt_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_CusDlt_Element(BsRt_CusDlt_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_FuelGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_FuelGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_FuelGauge_Element(BsRt_FuelGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsRt_Illumination_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Illumination_Element(BsRt_Illumination_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Odometer_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Odometer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Odometer_Element(BsRt_Odometer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_OilGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_OilGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_OilGauge_Element(BsRt_OilGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Personalization_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Personalization_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Personalization_Element(BsRt_Personalization_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_PowerGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_PowerGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_PowerGauge_Element(BsRt_PowerGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsRt_RealTimeClock_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_RealTimeClock_Element(BsRt_RealTimeClock_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_SpeedoGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_SpeedoGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_SpeedoGauge_Element(BsRt_SpeedoGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TachoGauge_Element(const Rte_DT_Arr_u8_16_0 *BsRt_TachoGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TachoGauge_Element(BsRt_TachoGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TempGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_TempGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TempGauge_Element(BsRt_TempGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsRt_TripComputer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TripComputer_Element(BsRt_TripComputer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Warning_Element(const Rte_DT_Arr_u8_32_0 *BsRt_Warning_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Warning_Element(BsRt_Warning_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyManufacturingDate(const Rte_DT_Arr_u8_3_0 *BsShare_AssemblyManufacturingDate)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyManufacturingDate(BsShare_AssemblyManufacturingDate);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyPlantNumber(const Rte_DT_Arr_u8_3_0 *BsShare_AssemblyPlantNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyPlantNumber(BsShare_AssemblyPlantNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_EcuPartNumber_Element(const Rte_DT_Arr_u8_61_0 *BsShare_EcuPartNumber_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_EcuPartNumber_Element(BsShare_EcuPartNumber_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_HWModification(UInt16 BsShare_HWModification)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_HWModification(BsShare_HWModification);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_PCBSerialNumber(const Rte_DT_Arr_u8_9_0 *BsShare_PCBSerialNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_PCBSerialNumber(BsShare_PCBSerialNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_ProductSerialNumber(const Rte_DT_Arr_u8_10_0 *BsShare_ProductSerialNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_ProductSerialNumber(BsShare_ProductSerialNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTManufacturingDate(const Rte_DT_Arr_u8_3_0 *BsShare_SMTManufacturingDate)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTManufacturingDate(BsShare_SMTManufacturingDate);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTPlantNumber(const Rte_DT_Arr_u8_3_0 *BsShare_SMTPlantNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTPlantNumber(BsShare_SMTPlantNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaFinPrint_Element(const Rte_DT_Arr_u8_32_0 *BsShare_SwUpdFotaFinPrint_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaFinPrint_Element(BsShare_SwUpdFotaFinPrint_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaMode_Element(const Rte_DT_Arr_u8_16_0 *BsShare_SwUpdFotaMode_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaMode_Element(BsShare_SwUpdFotaMode_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaStatus_Element(const Rte_DT_Arr_u8_48_0 *BsShare_SwUpdFotaStatus_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaStatus_Element(BsShare_SwUpdFotaStatus_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotadecrypt_Element(const Rte_DT_Arr_u8_64_0 *BsShare_SwUpdFotadecrypt_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotadecrypt_Element(BsShare_SwUpdFotadecrypt_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdReflash_Element(const Rte_DT_Arr_u8_8_0 *BsShare_SwUpdReflash_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdReflash_Element(BsShare_SwUpdReflash_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VehicleConfig_Element(const Rte_DT_Arr_u8_256_0 *BsShare_VehicleConfig_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VehicleConfig_Element(BsShare_VehicleConfig_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_EOLEntry_Element(UInt16 BsShare_VisMeet_EOLEntry_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_EOLEntry_Element(BsShare_VisMeet_EOLEntry_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_Element(const Rte_DT_Arr_u8_46_0 *BsShare_VisMeet_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_Element(BsShare_VisMeet_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPCBPartNumber(const Rte_DT_Arr_u8_17_0 *BsShare_VisteonPCBPartNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPCBPartNumber(BsShare_VisteonPCBPartNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPartNumber(const Rte_DT_Arr_u8_17_0 *BsShare_VisteonPartNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPartNumber(BsShare_VisteonPartNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate1_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate1_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate1_Element(RefCys_Certicificate1_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate_Element(RefCys_Certicificate_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_Current_duty_GetPwmCurrentDuty(UInt8 ChannelID, UInt16 *Channel_Duty)
{
  return Rte_Call_rp_Current_duty_GetPwmCurrentDuty(ChannelID, Channel_Duty);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Audio_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Audio_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_BsConst_Illumination_ReservedByte(Rte_DT_Arr_u8_28_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_BsConst_Illumination_ReservedByte(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Rte_DT_Arr_u8_28_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Rte_DT_Arr_u8_28_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Communication_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Communication_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Shift_b(UInt32 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Shift_b(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Slope_m(UInt32 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Slope_m(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Derating_Backlight_Disable(UInt8 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Derating_Backlight_Disable(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Display_Illum_Max_Level(UInt16 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Display_Illum_Max_Level(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_EngOffTimer_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_EngOffTimer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_FuelGauge_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_FuelGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_OilGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_OilGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PCB_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PCB_Temperature_Sensor_Conv(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PWM_boost_bypass_duty(UInt8 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PWM_boost_bypass_duty(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PowerGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_PowerGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Power_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Power_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_ServiceReminder_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_ServiceReminder_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_SpeedoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_SpeedoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_TachoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_TachoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_TempGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_TempGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temp_Threshold_Hysteresis_Derating(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temperature_Sensor_Conv(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_TripComputer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Warning_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsConst_Warning_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsCys_Certicificate_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsDiag_Dtc_Element(Rte_DT_Arr_u8_2048_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsDiag_Dtc_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsDiag_ErrorRecord_Element(Rte_DT_Arr_u8_1024_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsDiag_ErrorRecord_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Audio_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Audio_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Communication_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Communication_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Display_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Display_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Gauges_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Gauges_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Illumination_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Odometer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Odometer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Personalization_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Personalization_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Power_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Power_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_RealTimeClock_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Tripcomputer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Tripcomputer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Warning_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsReten_Warning_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_CusDlt_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_CusDlt_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_FuelGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_FuelGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_Illumination_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_Odometer_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_Odometer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_OilGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_OilGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_Personalization_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_Personalization_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_PowerGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_PowerGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_SpeedoGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_SpeedoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_TachoGauge_Element(Rte_DT_Arr_u8_16_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_TachoGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_TempGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_TempGauge_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_TripComputer_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_Warning_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsRt_Warning_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_AssemblyManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_AssemblyManufacturingDate(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_AssemblyPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_AssemblyPlantNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_EcuPartNumber_Element(Rte_DT_Arr_u8_61_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_EcuPartNumber_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_HWModification(UInt16 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_HWModification(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_PCBSerialNumber(Rte_DT_Arr_u8_9_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_PCBSerialNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_ProductSerialNumber(Rte_DT_Arr_u8_10_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_ProductSerialNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SMTManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SMTManufacturingDate(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SMTPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SMTPlantNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SwUpdFotaFinPrint_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SwUpdFotaFinPrint_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SwUpdFotaMode_Element(Rte_DT_Arr_u8_16_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SwUpdFotaMode_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SwUpdFotaStatus_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SwUpdFotaStatus_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SwUpdFotadecrypt_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SwUpdFotadecrypt_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SwUpdReflash_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_SwUpdReflash_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_VehicleConfig_Element(Rte_DT_Arr_u8_256_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_VehicleConfig_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_VisMeet_EOLEntry_Element(UInt16 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_VisMeet_EOLEntry_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_VisMeet_Element(Rte_DT_Arr_u8_46_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_VisMeet_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_VisteonPCBPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_VisteonPCBPartNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_VisteonPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_BsShare_VisteonPartNumber(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_RefCys_Certicificate1_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_RefCys_Certicificate1_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_GetNVM_IlluminationData_Get_RefCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_GetNVM_IlluminationData_Get_RefCys_Certicificate_Element(Ptr);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(UInt8 VariantID, UInt8 *VariantActiveSt)
{
  return Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(VariantID, VariantActiveSt);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_ILL_ReadyToSleep_SWCSleepStatus(eAppMdl AppModule, eSleepSt SleepStatus)
{
  return Rte_Call_rp_ILL_ReadyToSleep_SWCSleepStatus(AppModule, SleepStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_IoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rp_IoHwAb_ADC_GetAsyncRawAdc(AdcId, AsyncRawAdc, ErrorStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_IoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rp_IoHwAb_ADC_GetProcessedAdc(AdcId, ProcessedAdc, ErrorStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_IoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rp_IoHwAb_ADC_GetSyncRawAdc(AdcId, SyncRawAdc, ErrorStatus);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_PwmWithTime_GetPwmWithTime(IoHwAb_PwmSignalIdType ChannelID, UInt16 TargetDuty, UInt16 TargetTime)
{
  return Rte_Call_rp_PwmWithTime_GetPwmWithTime(ChannelID, TargetDuty, TargetTime);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_PwmWithTimeExp_GetPwmWithTimeExp(IoHwAb_PwmSignalIdType ChannelID, UInt16 TargetDuty, UInt16 TargetTime)
{
  return Rte_Call_rp_PwmWithTimeExp_GetPwmWithTimeExp(ChannelID, TargetDuty, TargetTime);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Audio_Element(const Rte_DT_Arr_u8_128_0 *BsConst_Audio_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Audio_Element(BsConst_Audio_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_BsConst_Illumination_ReservedByte(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_BsConst_Illumination_ReservedByte(BsConst_BsConst_Illumination_ReservedByte);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte_SafeCopy1)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(BsConst_BsConst_Illumination_ReservedByte_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(const Rte_DT_Arr_u8_28_0 *BsConst_BsConst_Illumination_ReservedByte_SafeCopy2)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(BsConst_BsConst_Illumination_ReservedByte_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Communication_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Communication_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Communication_Element(BsConst_Communication_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Shift_b(UInt32 BsConst_Compensation_Line_Shift_b)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Shift_b(BsConst_Compensation_Line_Shift_b);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy1)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1(BsConst_Compensation_Line_Shift_b_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy2)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2(BsConst_Compensation_Line_Shift_b_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Slope_m(UInt32 BsConst_Compensation_Line_Slope_m)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Slope_m(BsConst_Compensation_Line_Slope_m);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy1)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1(BsConst_Compensation_Line_Slope_m_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy2)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2(BsConst_Compensation_Line_Slope_m_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Derating_Backlight_Disable(UInt8 BsConst_Derating_Backlight_Disable)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Derating_Backlight_Disable(BsConst_Derating_Backlight_Disable);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy1)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Derating_Backlight_Disable_SafeCopy1(BsConst_Derating_Backlight_Disable_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy2)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Derating_Backlight_Disable_SafeCopy2(BsConst_Derating_Backlight_Disable_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Display_Illum_Max_Level(UInt16 BsConst_Display_Illum_Max_Level)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Display_Illum_Max_Level(BsConst_Display_Illum_Max_Level);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy1)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Display_Illum_Max_Level_SafeCopy1(BsConst_Display_Illum_Max_Level_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy2)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Display_Illum_Max_Level_SafeCopy2(BsConst_Display_Illum_Max_Level_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_EngOffTimer_Element(const Rte_DT_Arr_u8_32_0 *BsConst_EngOffTimer_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_EngOffTimer_Element(BsConst_EngOffTimer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_FuelGauge_Element(const Rte_DT_Arr_u8_128_0 *BsConst_FuelGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_FuelGauge_Element(BsConst_FuelGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_X(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_X(BsConst_Lookup_Curve_HotSpot_Coef_X);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y(BsConst_Lookup_Curve_HotSpot_Coef_Y);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(const Rte_DT_Arr_u16_7_0 *BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_OilGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_OilGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_OilGauge_Element(BsConst_OilGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PCB_Temperature_Sensor_Conv(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PCB_Temperature_Sensor_Conv(BsConst_PCB_Temperature_Sensor_Conv);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PWM_boost_bypass_duty(UInt8 BsConst_PWM_boost_bypass_duty)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PWM_boost_bypass_duty(BsConst_PWM_boost_bypass_duty);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy1)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1(BsConst_PWM_boost_bypass_duty_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy2)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2(BsConst_PWM_boost_bypass_duty_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PowerGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_PowerGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_PowerGauge_Element(BsConst_PowerGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Power_Element(const Rte_DT_Arr_u8_32_0 *BsConst_Power_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Power_Element(BsConst_Power_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsConst_RealTimeClock_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_RealTimeClock_Element(BsConst_RealTimeClock_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_ServiceReminder_Element(const Rte_DT_Arr_u8_48_0 *BsConst_ServiceReminder_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_ServiceReminder_Element(BsConst_ServiceReminder_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_SpeedoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_SpeedoGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_SpeedoGauge_Element(BsConst_SpeedoGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_TachoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TachoGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_TachoGauge_Element(BsConst_TachoGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_TempGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TempGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_TempGauge_Element(BsConst_TempGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temp_Threshold_Hysteresis_Derating(BsConst_Temp_Threshold_Hysteresis_Derating);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temperature_Sensor_Conv(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temperature_Sensor_Conv(BsConst_Temperature_Sensor_Conv);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv_SafeCopy1)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1(BsConst_Temperature_Sensor_Conv_SafeCopy1);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2(const Rte_DT_T_NV_Temperature_Conversion_0 *BsConst_Temperature_Sensor_Conv_SafeCopy2)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2(BsConst_Temperature_Sensor_Conv_SafeCopy2);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TripComputer_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_TripComputer_Element(BsConst_TripComputer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Warning_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Warning_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsConst_Warning_Element(BsConst_Warning_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *BsCys_Certicificate_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsCys_Certicificate_Element(BsCys_Certicificate_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsDiag_Dtc_Element(const Rte_DT_Arr_u8_2048_0 *BsDiag_Dtc_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsDiag_Dtc_Element(BsDiag_Dtc_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsDiag_ErrorRecord_Element(const Rte_DT_Arr_u8_1024_0 *BsDiag_ErrorRecord_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsDiag_ErrorRecord_Element(BsDiag_ErrorRecord_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Audio_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Audio_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Audio_Element(BsReten_Audio_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Communication_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Communication_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Communication_Element(BsReten_Communication_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Display_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Display_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Display_Element(BsReten_Display_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Gauges_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Gauges_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Gauges_Element(BsReten_Gauges_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Illumination_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Illumination_Element(BsReten_Illumination_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Odometer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Odometer_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Odometer_Element(BsReten_Odometer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Personalization_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Personalization_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Personalization_Element(BsReten_Personalization_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Power_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Power_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Power_Element(BsReten_Power_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_RealTimeClock_Element(const Rte_DT_Arr_u8_100_0 *BsReten_RealTimeClock_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_RealTimeClock_Element(BsReten_RealTimeClock_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Tripcomputer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Tripcomputer_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Tripcomputer_Element(BsReten_Tripcomputer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Warning_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Warning_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsReten_Warning_Element(BsReten_Warning_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_CusDlt_Element(const Rte_DT_Arr_u8_128_0 *BsRt_CusDlt_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_CusDlt_Element(BsRt_CusDlt_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_FuelGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_FuelGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_FuelGauge_Element(BsRt_FuelGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsRt_Illumination_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_Illumination_Element(BsRt_Illumination_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_Odometer_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Odometer_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_Odometer_Element(BsRt_Odometer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_OilGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_OilGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_OilGauge_Element(BsRt_OilGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_Personalization_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Personalization_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_Personalization_Element(BsRt_Personalization_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_PowerGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_PowerGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_PowerGauge_Element(BsRt_PowerGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsRt_RealTimeClock_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_RealTimeClock_Element(BsRt_RealTimeClock_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_SpeedoGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_SpeedoGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_SpeedoGauge_Element(BsRt_SpeedoGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_TachoGauge_Element(const Rte_DT_Arr_u8_16_0 *BsRt_TachoGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_TachoGauge_Element(BsRt_TachoGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_TempGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_TempGauge_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_TempGauge_Element(BsRt_TempGauge_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsRt_TripComputer_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_TripComputer_Element(BsRt_TripComputer_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_Warning_Element(const Rte_DT_Arr_u8_32_0 *BsRt_Warning_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsRt_Warning_Element(BsRt_Warning_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_AssemblyManufacturingDate(const Rte_DT_Arr_u8_3_0 *BsShare_AssemblyManufacturingDate)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_AssemblyManufacturingDate(BsShare_AssemblyManufacturingDate);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_AssemblyPlantNumber(const Rte_DT_Arr_u8_3_0 *BsShare_AssemblyPlantNumber)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_AssemblyPlantNumber(BsShare_AssemblyPlantNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_EcuPartNumber_Element(const Rte_DT_Arr_u8_61_0 *BsShare_EcuPartNumber_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_EcuPartNumber_Element(BsShare_EcuPartNumber_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_HWModification(UInt16 BsShare_HWModification)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_HWModification(BsShare_HWModification);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_PCBSerialNumber(const Rte_DT_Arr_u8_9_0 *BsShare_PCBSerialNumber)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_PCBSerialNumber(BsShare_PCBSerialNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_ProductSerialNumber(const Rte_DT_Arr_u8_10_0 *BsShare_ProductSerialNumber)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_ProductSerialNumber(BsShare_ProductSerialNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SMTManufacturingDate(const Rte_DT_Arr_u8_3_0 *BsShare_SMTManufacturingDate)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SMTManufacturingDate(BsShare_SMTManufacturingDate);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SMTPlantNumber(const Rte_DT_Arr_u8_3_0 *BsShare_SMTPlantNumber)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SMTPlantNumber(BsShare_SMTPlantNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SwUpdFotaFinPrint_Element(const Rte_DT_Arr_u8_32_0 *BsShare_SwUpdFotaFinPrint_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SwUpdFotaFinPrint_Element(BsShare_SwUpdFotaFinPrint_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SwUpdFotaMode_Element(const Rte_DT_Arr_u8_16_0 *BsShare_SwUpdFotaMode_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SwUpdFotaMode_Element(BsShare_SwUpdFotaMode_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SwUpdFotaStatus_Element(const Rte_DT_Arr_u8_48_0 *BsShare_SwUpdFotaStatus_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SwUpdFotaStatus_Element(BsShare_SwUpdFotaStatus_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SwUpdFotadecrypt_Element(const Rte_DT_Arr_u8_64_0 *BsShare_SwUpdFotadecrypt_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SwUpdFotadecrypt_Element(BsShare_SwUpdFotadecrypt_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SwUpdReflash_Element(const Rte_DT_Arr_u8_8_0 *BsShare_SwUpdReflash_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_SwUpdReflash_Element(BsShare_SwUpdReflash_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_VehicleConfig_Element(const Rte_DT_Arr_u8_256_0 *BsShare_VehicleConfig_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_VehicleConfig_Element(BsShare_VehicleConfig_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_VisMeet_EOLEntry_Element(UInt16 BsShare_VisMeet_EOLEntry_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_VisMeet_EOLEntry_Element(BsShare_VisMeet_EOLEntry_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_VisMeet_Element(const Rte_DT_Arr_u8_46_0 *BsShare_VisMeet_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_VisMeet_Element(BsShare_VisMeet_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_VisteonPCBPartNumber(const Rte_DT_Arr_u8_17_0 *BsShare_VisteonPCBPartNumber)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_VisteonPCBPartNumber(BsShare_VisteonPCBPartNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_VisteonPartNumber(const Rte_DT_Arr_u8_17_0 *BsShare_VisteonPartNumber)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_BsShare_VisteonPartNumber(BsShare_VisteonPartNumber);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_RefCys_Certicificate1_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate1_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_RefCys_Certicificate1_Element(RefCys_Certicificate1_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_SetNVM_IlluminationData_Set_RefCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate_Element)
{
  return Rte_Call_rp_SetNVM_IlluminationData_Set_RefCys_Certicificate_Element(RefCys_Certicificate_Element);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_UpdatePwmDirect_GetPwmDirect(IoHwAb_PwmSignalIdType ChannelID, UInt16 TargetDuty)
{
  return Rte_Call_rp_UpdatePwmDirect_GetPwmDirect(ChannelID, TargetDuty);
}
Std_ReturnType TSC_Mdl_Dim_Rte_Call_rp_Variant_Status_GetVariant_Status(UInt8 Variant_Ind, UInt8 *Variant_Status)
{
  return Rte_Call_rp_Variant_Status_GetVariant_Status(Variant_Ind, Variant_Status);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* Mdl_Dim */
      /* Mdl_Dim */



