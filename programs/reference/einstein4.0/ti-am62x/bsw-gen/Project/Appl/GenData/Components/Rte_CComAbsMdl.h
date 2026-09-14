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
 *          File:  Rte_CComAbsMdl.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CComAbsMdl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CCOMABSMDL_H
# define _RTE_CCOMABSMDL_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CComAbsMdl_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CComAbsMdl_START_SEC_CODE
# include "CComAbsMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CComAbsMdl_Impl_OnCommand CComAbsMdl_Impl_OnCommand
#  define RTE_RUNNABLE_CComAbsMdl_Impl_RxCanMdlMainFunction CComAbsMdl_Impl_RxCanMdlMainFunction
#  define RTE_RUNNABLE_CComAbsMdl_Impl_TxCanMdlMainFunction CComAbsMdl_Impl_TxCanMdlMainFunction
#  define RTE_RUNNABLE_CComAbsMdl_RxCan_GetSignalValue CComAbsMdl_RxCan_GetSignalValue
#  define RTE_RUNNABLE_CComAbsMdl_RxCan_GetSignalValueU8Arr CComAbsMdl_RxCan_GetSignalValueU8Arr
#  define RTE_RUNNABLE_CComAbsMdl_RxCan_SetSignalInitValue CComAbsMdl_RxCan_SetSignalInitValue
#  define RTE_RUNNABLE_CComAbsMdl_RxCan_SetSignalInitValueU8Arr CComAbsMdl_RxCan_SetSignalInitValueU8Arr
#  define RTE_RUNNABLE_CComAbsMdl_RxCan_SignalClearJustRcvdStatus CComAbsMdl_RxCan_SignalClearJustRcvdStatus
#  define RTE_RUNNABLE_CComAbsMdl_RxCan_SignalGetJustRcvdStatus CComAbsMdl_RxCan_SignalGetJustRcvdStatus
#  define RTE_RUNNABLE_CComAbsMdl_RxCan_SignalInvalidProcessingControl CComAbsMdl_RxCan_SignalInvalidProcessingControl
#  define RTE_RUNNABLE_CComAbsMdl_RxCan_SignalMissingProcessingControl CComAbsMdl_RxCan_SignalMissingProcessingControl
#  define RTE_RUNNABLE_CComAbsMdl_RxCan_SignalNRProcessingControl CComAbsMdl_RxCan_SignalNRProcessingControl
#  define RTE_RUNNABLE_CComAbsMdl_TxCan_ClearCanSignalTxConfirmation CComAbsMdl_TxCan_ClearCanSignalTxConfirmation
#  define RTE_RUNNABLE_CComAbsMdl_TxCan_GetCanSignalTxConfirmation CComAbsMdl_TxCan_GetCanSignalTxConfirmation
#  define RTE_RUNNABLE_CComAbsMdl_TxCan_SetSignalFromRetentionBuffer CComAbsMdl_TxCan_SetSignalFromRetentionBuffer
#  define RTE_RUNNABLE_CComAbsMdl_TxCan_SetSignalValue CComAbsMdl_TxCan_SetSignalValue
#  define RTE_RUNNABLE_CComAbsMdl_TxCan_SetSignalValueU8Arr CComAbsMdl_TxCan_SetSignalValueU8Arr
# endif

FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdl_CODE) CComAbsMdl_Impl_RxCanMdlMainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CComAbsMdl_CODE) CComAbsMdl_Impl_TxCanMdlMainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_RxCan_GetSignalValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignaValue, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdl_CODE) CComAbsMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdl_CODE) CComAbsMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, P2VAR(tRxSignalJustRcvdStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pJustRcvdStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdl_CODE) CComAbsMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdl_CODE) CComAbsMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdl_CODE) CComAbsMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdl_CODE) CComAbsMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdl_CODE) CComAbsMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, P2VAR(tTxSigConfirmStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_TxCan_SetSignalValue(tTxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pTxSignalData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pTxSignalData, UInt32 SignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CComAbsMdl_STOP_SEC_CODE
# include "CComAbsMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_if_CS_ComAbsRx_E_NOT_OK (1U)

#  define RTE_E_if_CS_ComAbsTx_E_NOT_OK (1U)

#  define RTE_E_if_CS_MemAbsGet_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CCOMABSMDL_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
