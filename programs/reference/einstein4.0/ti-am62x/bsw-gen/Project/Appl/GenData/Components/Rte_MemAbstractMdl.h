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
 *          File:  Rte_MemAbstractMdl.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <MemAbstractMdl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MEMABSTRACTMDL_H
# define _RTE_MEMABSTRACTMDL_H

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

# include "Rte_MemAbstractMdl_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_HWModification; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Power_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2 (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Display_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Power_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_HWModification (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Power_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2 Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2 = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Display_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Power_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_HWModification Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_HWModification
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_HWModification(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_HWModification = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(data) (Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define MemAbstractMdl_START_SEC_CODE
# include "MemAbstractMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CMemAbstractMdl_Impl_MainFunction CMemAbstractMdl_Impl_MainFunction
#  define RTE_RUNNABLE_CMemAbstractMdl_Impl_OnCommand CMemAbstractMdl_Impl_OnCommand
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Audio_Element MemAbstractMdl_Get_BsConst_Audio_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Communication_Element MemAbstractMdl_Get_BsConst_Communication_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1 MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2 MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1 MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2 MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1 MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2 MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1 MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2 MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_EngOffTimer_Element MemAbstractMdl_Get_BsConst_EngOffTimer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_FuelGauge_Element MemAbstractMdl_Get_BsConst_FuelGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_OilGauge_Element MemAbstractMdl_Get_BsConst_OilGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1 MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2 MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_PowerGauge_Element MemAbstractMdl_Get_BsConst_PowerGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Power_Element MemAbstractMdl_Get_BsConst_Power_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_RealTimeClock_Element MemAbstractMdl_Get_BsConst_RealTimeClock_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_ServiceReminder_Element MemAbstractMdl_Get_BsConst_ServiceReminder_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_SpeedoGauge_Element MemAbstractMdl_Get_BsConst_SpeedoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_TachoGauge_Element MemAbstractMdl_Get_BsConst_TachoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_TempGauge_Element MemAbstractMdl_Get_BsConst_TempGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1 MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2 MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_TripComputer_Element MemAbstractMdl_Get_BsConst_TripComputer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Warning_Element MemAbstractMdl_Get_BsConst_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsCys_Certicificate_Element MemAbstractMdl_Get_BsCys_Certicificate_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsDiag_Dtc_Element MemAbstractMdl_Get_BsDiag_Dtc_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsDiag_ErrorRecord_Element MemAbstractMdl_Get_BsDiag_ErrorRecord_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_Audio_Element MemAbstractMdl_Get_BsReten_Audio_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_Communication_Element MemAbstractMdl_Get_BsReten_Communication_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_Display_Element MemAbstractMdl_Get_BsReten_Display_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_Gauges_Element MemAbstractMdl_Get_BsReten_Gauges_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_Illumination_Element MemAbstractMdl_Get_BsReten_Illumination_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_Odometer_Element MemAbstractMdl_Get_BsReten_Odometer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_Personalization_Element MemAbstractMdl_Get_BsReten_Personalization_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_Power_Element MemAbstractMdl_Get_BsReten_Power_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_RealTimeClock_Element MemAbstractMdl_Get_BsReten_RealTimeClock_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_Tripcomputer_Element MemAbstractMdl_Get_BsReten_Tripcomputer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_Warning_Element MemAbstractMdl_Get_BsReten_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_CusDlt_Element MemAbstractMdl_Get_BsRt_CusDlt_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_FuelGauge_Element MemAbstractMdl_Get_BsRt_FuelGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_Illumination_Element MemAbstractMdl_Get_BsRt_Illumination_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_Odometer_Element MemAbstractMdl_Get_BsRt_Odometer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_OilGauge_Element MemAbstractMdl_Get_BsRt_OilGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_Personalization_Element MemAbstractMdl_Get_BsRt_Personalization_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_PowerGauge_Element MemAbstractMdl_Get_BsRt_PowerGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_RealTimeClock_Element MemAbstractMdl_Get_BsRt_RealTimeClock_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_SpeedoGauge_Element MemAbstractMdl_Get_BsRt_SpeedoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_TachoGauge_Element MemAbstractMdl_Get_BsRt_TachoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_TempGauge_Element MemAbstractMdl_Get_BsRt_TempGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_TripComputer_Element MemAbstractMdl_Get_BsRt_TripComputer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsRt_Warning_Element MemAbstractMdl_Get_BsRt_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_AssemblyPlantNumber MemAbstractMdl_Get_BsShare_AssemblyPlantNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_EcuPartNumber_Element MemAbstractMdl_Get_BsShare_EcuPartNumber_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_HWModification MemAbstractMdl_Get_BsShare_HWModification
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_PCBSerialNumber MemAbstractMdl_Get_BsShare_PCBSerialNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_ProductSerialNumber MemAbstractMdl_Get_BsShare_ProductSerialNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SMTManufacturingDate MemAbstractMdl_Get_BsShare_SMTManufacturingDate
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SMTPlantNumber MemAbstractMdl_Get_BsShare_SMTPlantNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SwUpdReflash_Element MemAbstractMdl_Get_BsShare_SwUpdReflash_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_VehicleConfig_Element MemAbstractMdl_Get_BsShare_VehicleConfig_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_VisMeet_Element MemAbstractMdl_Get_BsShare_VisMeet_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_VisteonPartNumber MemAbstractMdl_Get_BsShare_VisteonPartNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Audio_Element MemAbstractMdl_Get_Default_BsConst_Audio_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Communication_Element MemAbstractMdl_Get_Default_BsConst_Communication_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy1 MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy2 MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy1 MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy2 MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy1 MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy2 MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy1 MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy2 MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_EngOffTimer_Element MemAbstractMdl_Get_Default_BsConst_EngOffTimer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_FuelGauge_Element MemAbstractMdl_Get_Default_BsConst_FuelGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_OilGauge_Element MemAbstractMdl_Get_Default_BsConst_OilGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy1 MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy2 MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_PowerGauge_Element MemAbstractMdl_Get_Default_BsConst_PowerGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Power_Element MemAbstractMdl_Get_Default_BsConst_Power_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_RealTimeClock_Element MemAbstractMdl_Get_Default_BsConst_RealTimeClock_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_ServiceReminder_Element MemAbstractMdl_Get_Default_BsConst_ServiceReminder_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_SpeedoGauge_Element MemAbstractMdl_Get_Default_BsConst_SpeedoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_TachoGauge_Element MemAbstractMdl_Get_Default_BsConst_TachoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_TempGauge_Element MemAbstractMdl_Get_Default_BsConst_TempGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy1 MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy2 MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_TripComputer_Element MemAbstractMdl_Get_Default_BsConst_TripComputer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsConst_Warning_Element MemAbstractMdl_Get_Default_BsConst_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsCys_Certicificate_Element MemAbstractMdl_Get_Default_BsCys_Certicificate_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsDiag_Dtc_Element MemAbstractMdl_Get_Default_BsDiag_Dtc_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsDiag_ErrorRecord_Element MemAbstractMdl_Get_Default_BsDiag_ErrorRecord_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsReten_Audio_Element MemAbstractMdl_Get_Default_BsReten_Audio_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsReten_Communication_Element MemAbstractMdl_Get_Default_BsReten_Communication_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsReten_Display_Element MemAbstractMdl_Get_Default_BsReten_Display_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsReten_Gauges_Element MemAbstractMdl_Get_Default_BsReten_Gauges_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsReten_Illumination_Element MemAbstractMdl_Get_Default_BsReten_Illumination_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsReten_Odometer_Element MemAbstractMdl_Get_Default_BsReten_Odometer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsReten_Personalization_Element MemAbstractMdl_Get_Default_BsReten_Personalization_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsReten_Power_Element MemAbstractMdl_Get_Default_BsReten_Power_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsReten_RealTimeClock_Element MemAbstractMdl_Get_Default_BsReten_RealTimeClock_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsReten_Tripcomputer_Element MemAbstractMdl_Get_Default_BsReten_Tripcomputer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsReten_Warning_Element MemAbstractMdl_Get_Default_BsReten_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_CusDlt_Element MemAbstractMdl_Get_Default_BsRt_CusDlt_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_FuelGauge_Element MemAbstractMdl_Get_Default_BsRt_FuelGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_Illumination_Element MemAbstractMdl_Get_Default_BsRt_Illumination_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_Odometer_Element MemAbstractMdl_Get_Default_BsRt_Odometer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_OilGauge_Element MemAbstractMdl_Get_Default_BsRt_OilGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_Personalization_Element MemAbstractMdl_Get_Default_BsRt_Personalization_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_PowerGauge_Element MemAbstractMdl_Get_Default_BsRt_PowerGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_RealTimeClock_Element MemAbstractMdl_Get_Default_BsRt_RealTimeClock_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_SpeedoGauge_Element MemAbstractMdl_Get_Default_BsRt_SpeedoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_TachoGauge_Element MemAbstractMdl_Get_Default_BsRt_TachoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_TempGauge_Element MemAbstractMdl_Get_Default_BsRt_TempGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_TripComputer_Element MemAbstractMdl_Get_Default_BsRt_TripComputer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsRt_Warning_Element MemAbstractMdl_Get_Default_BsRt_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_AssemblyManufacturingDate MemAbstractMdl_Get_Default_BsShare_AssemblyManufacturingDate
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_AssemblyPlantNumber MemAbstractMdl_Get_Default_BsShare_AssemblyPlantNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_EcuPartNumber_Element MemAbstractMdl_Get_Default_BsShare_EcuPartNumber_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_HWModification MemAbstractMdl_Get_Default_BsShare_HWModification
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_PCBSerialNumber MemAbstractMdl_Get_Default_BsShare_PCBSerialNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_ProductSerialNumber MemAbstractMdl_Get_Default_BsShare_ProductSerialNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_SMTManufacturingDate MemAbstractMdl_Get_Default_BsShare_SMTManufacturingDate
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_SMTPlantNumber MemAbstractMdl_Get_Default_BsShare_SMTPlantNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_SwUpdFotaFinPrint_Element MemAbstractMdl_Get_Default_BsShare_SwUpdFotaFinPrint_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_SwUpdFotaMode_Element MemAbstractMdl_Get_Default_BsShare_SwUpdFotaMode_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_SwUpdFotaStatus_Element MemAbstractMdl_Get_Default_BsShare_SwUpdFotaStatus_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_SwUpdFotadecrypt_Element MemAbstractMdl_Get_Default_BsShare_SwUpdFotadecrypt_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_SwUpdReflash_Element MemAbstractMdl_Get_Default_BsShare_SwUpdReflash_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_VehicleConfig_Element MemAbstractMdl_Get_Default_BsShare_VehicleConfig_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_VisMeet_EOLEntry_Element MemAbstractMdl_Get_Default_BsShare_VisMeet_EOLEntry_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_VisMeet_Element MemAbstractMdl_Get_Default_BsShare_VisMeet_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_VisteonPCBPartNumber MemAbstractMdl_Get_Default_BsShare_VisteonPCBPartNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_BsShare_VisteonPartNumber MemAbstractMdl_Get_Default_BsShare_VisteonPartNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_RefCys_Certicificate1_Element MemAbstractMdl_Get_Default_RefCys_Certicificate1_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_Default_RefCys_Certicificate_Element MemAbstractMdl_Get_Default_RefCys_Certicificate_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_RefCys_Certicificate1_Element MemAbstractMdl_Get_RefCys_Certicificate1_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_RefCys_Certicificate_Element MemAbstractMdl_Get_RefCys_Certicificate_Element
#  define RTE_RUNNABLE_MemAbstractMdl_NvmWriteStatus MemAbstractMdl_NvmWriteStatus
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Audio_Element MemAbstractMdl_Set_BsConst_Audio_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Communication_Element MemAbstractMdl_Set_BsConst_Communication_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1 MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2 MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1 MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2 MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy1 MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy2 MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy1 MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy2 MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_EngOffTimer_Element MemAbstractMdl_Set_BsConst_EngOffTimer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_FuelGauge_Element MemAbstractMdl_Set_BsConst_FuelGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_OilGauge_Element MemAbstractMdl_Set_BsConst_OilGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1 MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2 MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_PowerGauge_Element MemAbstractMdl_Set_BsConst_PowerGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Power_Element MemAbstractMdl_Set_BsConst_Power_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_RealTimeClock_Element MemAbstractMdl_Set_BsConst_RealTimeClock_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_ServiceReminder_Element MemAbstractMdl_Set_BsConst_ServiceReminder_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_SpeedoGauge_Element MemAbstractMdl_Set_BsConst_SpeedoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_TachoGauge_Element MemAbstractMdl_Set_BsConst_TachoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_TempGauge_Element MemAbstractMdl_Set_BsConst_TempGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1 MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2 MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_TripComputer_Element MemAbstractMdl_Set_BsConst_TripComputer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Warning_Element MemAbstractMdl_Set_BsConst_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsCys_Certicificate_Element MemAbstractMdl_Set_BsCys_Certicificate_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsDiag_Dtc_Element MemAbstractMdl_Set_BsDiag_Dtc_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsDiag_ErrorRecord_Element MemAbstractMdl_Set_BsDiag_ErrorRecord_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_Audio_Element MemAbstractMdl_Set_BsReten_Audio_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_Communication_Element MemAbstractMdl_Set_BsReten_Communication_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_Display_Element MemAbstractMdl_Set_BsReten_Display_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_Gauges_Element MemAbstractMdl_Set_BsReten_Gauges_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_Illumination_Element MemAbstractMdl_Set_BsReten_Illumination_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_Odometer_Element MemAbstractMdl_Set_BsReten_Odometer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_Personalization_Element MemAbstractMdl_Set_BsReten_Personalization_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_Power_Element MemAbstractMdl_Set_BsReten_Power_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_RealTimeClock_Element MemAbstractMdl_Set_BsReten_RealTimeClock_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_Tripcomputer_Element MemAbstractMdl_Set_BsReten_Tripcomputer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_Warning_Element MemAbstractMdl_Set_BsReten_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_CusDlt_Element MemAbstractMdl_Set_BsRt_CusDlt_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_FuelGauge_Element MemAbstractMdl_Set_BsRt_FuelGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_Illumination_Element MemAbstractMdl_Set_BsRt_Illumination_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_Odometer_Element MemAbstractMdl_Set_BsRt_Odometer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_OilGauge_Element MemAbstractMdl_Set_BsRt_OilGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_Personalization_Element MemAbstractMdl_Set_BsRt_Personalization_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_PowerGauge_Element MemAbstractMdl_Set_BsRt_PowerGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_RealTimeClock_Element MemAbstractMdl_Set_BsRt_RealTimeClock_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_SpeedoGauge_Element MemAbstractMdl_Set_BsRt_SpeedoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_TachoGauge_Element MemAbstractMdl_Set_BsRt_TachoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_TempGauge_Element MemAbstractMdl_Set_BsRt_TempGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_TripComputer_Element MemAbstractMdl_Set_BsRt_TripComputer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsRt_Warning_Element MemAbstractMdl_Set_BsRt_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_AssemblyPlantNumber MemAbstractMdl_Set_BsShare_AssemblyPlantNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_EcuPartNumber_Element MemAbstractMdl_Set_BsShare_EcuPartNumber_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_HWModification MemAbstractMdl_Set_BsShare_HWModification
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_PCBSerialNumber MemAbstractMdl_Set_BsShare_PCBSerialNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_ProductSerialNumber MemAbstractMdl_Set_BsShare_ProductSerialNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SMTManufacturingDate MemAbstractMdl_Set_BsShare_SMTManufacturingDate
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SMTPlantNumber MemAbstractMdl_Set_BsShare_SMTPlantNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SwUpdReflash_Element MemAbstractMdl_Set_BsShare_SwUpdReflash_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_VehicleConfig_Element MemAbstractMdl_Set_BsShare_VehicleConfig_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_VisMeet_EOLEntry_Element MemAbstractMdl_Set_BsShare_VisMeet_EOLEntry_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_VisMeet_Element MemAbstractMdl_Set_BsShare_VisMeet_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_VisteonPartNumber MemAbstractMdl_Set_BsShare_VisteonPartNumber
#  define RTE_RUNNABLE_MemAbstractMdl_Set_RefCys_Certicificate1_Element MemAbstractMdl_Set_RefCys_Certicificate1_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_RefCys_Certicificate_Element MemAbstractMdl_Set_RefCys_Certicificate_Element
# endif

FUNC(void, MemAbstractMdl_CODE) CMemAbstractMdl_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) CMemAbstractMdl_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Audio_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Audio_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_EngOffTimer_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_EngOffTimer_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_FuelGauge_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_OilGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_PowerGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Power_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Power_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_RealTimeClock_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_ServiceReminder_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_ServiceReminder_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_SpeedoGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TachoGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TempGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_TripComputer_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Warning_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Warning_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsCys_Certicificate_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsDiag_Dtc_Element(P2VAR(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsDiag_Dtc_Element(P2VAR(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsDiag_ErrorRecord_Element(P2VAR(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsDiag_ErrorRecord_Element(P2VAR(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Audio_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Audio_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Communication_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Communication_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Display_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Display_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Gauges_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Gauges_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Illumination_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Odometer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Odometer_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Personalization_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Personalization_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Power_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Power_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_RealTimeClock_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Tripcomputer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Tripcomputer_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Warning_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_Warning_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_CusDlt_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_CusDlt_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_FuelGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Illumination_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Odometer_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Odometer_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_OilGauge_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Personalization_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Personalization_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_PowerGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_RealTimeClock_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_SpeedoGauge_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TachoGauge_Element(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TempGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_TripComputer_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Warning_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsRt_Warning_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_AssemblyPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_AssemblyPlantNumber(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(P2VAR(Rte_DT_Arr_u8_61_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(P2VAR(Arr_u8_61, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_HWModification(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_PCBSerialNumber(P2VAR(Rte_DT_Arr_u8_9_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_PCBSerialNumber(P2VAR(Arr_u8_9, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_ProductSerialNumber(P2VAR(Rte_DT_Arr_u8_10_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_ProductSerialNumber(P2VAR(Arr_u8_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SMTManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SMTManufacturingDate(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SMTPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SMTPlantNumber(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdReflash_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_SwUpdReflash_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VehicleConfig_Element(P2VAR(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VehicleConfig_Element(P2VAR(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisMeet_Element(P2VAR(Rte_DT_Arr_u8_46_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisMeet_Element(P2VAR(Arr_u8_46, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisteonPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisteonPartNumber(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Audio_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Audio_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Communication_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Communication_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy1(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy2(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_EngOffTimer_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_EngOffTimer_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_FuelGauge_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_OilGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_PowerGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Power_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Power_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_RealTimeClock_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_ServiceReminder_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_ServiceReminder_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_SpeedoGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_TachoGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_TempGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_TripComputer_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Warning_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsConst_Warning_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsCys_Certicificate_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsDiag_Dtc_Element(P2VAR(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsDiag_Dtc_Element(P2VAR(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsDiag_ErrorRecord_Element(P2VAR(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsDiag_ErrorRecord_Element(P2VAR(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Audio_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Audio_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Communication_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Communication_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Display_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Display_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Gauges_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Gauges_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Illumination_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Odometer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Odometer_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Personalization_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Personalization_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Power_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Power_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_RealTimeClock_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Tripcomputer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Tripcomputer_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Warning_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsReten_Warning_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_CusDlt_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_CusDlt_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_FuelGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Illumination_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Odometer_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Odometer_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_OilGauge_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Personalization_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Personalization_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_PowerGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_RealTimeClock_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_SpeedoGauge_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_TachoGauge_Element(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_TempGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_TripComputer_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Warning_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsRt_Warning_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_AssemblyManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_AssemblyManufacturingDate(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_AssemblyPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_AssemblyPlantNumber(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_EcuPartNumber_Element(P2VAR(Rte_DT_Arr_u8_61_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_EcuPartNumber_Element(P2VAR(Arr_u8_61, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_HWModification(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_PCBSerialNumber(P2VAR(Rte_DT_Arr_u8_9_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_PCBSerialNumber(P2VAR(Arr_u8_9, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_ProductSerialNumber(P2VAR(Rte_DT_Arr_u8_10_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_ProductSerialNumber(P2VAR(Arr_u8_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SMTManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SMTManufacturingDate(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SMTPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SMTPlantNumber(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotaFinPrint_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotaFinPrint_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotaMode_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotaMode_Element(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotaStatus_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotaStatus_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotadecrypt_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdFotadecrypt_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdReflash_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_SwUpdReflash_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VehicleConfig_Element(P2VAR(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VehicleConfig_Element(P2VAR(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VisMeet_EOLEntry_Element(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VisMeet_Element(P2VAR(Rte_DT_Arr_u8_46_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VisMeet_Element(P2VAR(Arr_u8_46, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VisteonPCBPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VisteonPCBPartNumber(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VisteonPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_BsShare_VisteonPartNumber(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_RefCys_Certicificate1_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_RefCys_Certicificate1_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_RefCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_Default_RefCys_Certicificate_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_RefCys_Certicificate1_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_RefCys_Certicificate1_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_RefCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_RefCys_Certicificate_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_NvmWriteStatus(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Audio_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Audio_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte(P2CONST(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_BsConst_Illumination_ReservedByte); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte(P2CONST(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_BsConst_Illumination_ReservedByte); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2CONST(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_BsConst_Illumination_ReservedByte_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2CONST(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_BsConst_Illumination_ReservedByte_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2CONST(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_BsConst_Illumination_ReservedByte_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2CONST(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_BsConst_Illumination_ReservedByte_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Communication_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Communication_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b(UInt32 BsConst_Compensation_Line_Shift_b); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 BsConst_Compensation_Line_Shift_b_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m(UInt32 BsConst_Compensation_Line_Slope_m); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 BsConst_Compensation_Line_Slope_m_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable(UInt8 BsConst_Derating_Backlight_Disable); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 BsConst_Derating_Backlight_Disable_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level(UInt16 BsConst_Display_Illum_Max_Level); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 BsConst_Display_Illum_Max_Level_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_EngOffTimer_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_EngOffTimer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_EngOffTimer_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_EngOffTimer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_FuelGauge_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_FuelGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_FuelGauge_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_FuelGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_OilGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_OilGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_OilGauge_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_OilGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PCB_Temperature_Sensor_Conv); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PCB_Temperature_Sensor_Conv); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty(UInt8 BsConst_PWM_boost_bypass_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 BsConst_PWM_boost_bypass_duty_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PowerGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PowerGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_PowerGauge_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PowerGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Power_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Power_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Power_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Power_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_RealTimeClock_Element(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_ServiceReminder_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_ServiceReminder_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_ServiceReminder_Element(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_ServiceReminder_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_SpeedoGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_SpeedoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_SpeedoGauge_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_SpeedoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TachoGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TachoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TachoGauge_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TachoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TempGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TempGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TempGauge_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TempGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Temperature_Sensor_Conv); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Temperature_Sensor_Conv); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Temperature_Sensor_Conv_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Temperature_Sensor_Conv_SafeCopy1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Temperature_Sensor_Conv_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Temperature_Sensor_Conv_SafeCopy2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TripComputer_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TripComputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_TripComputer_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TripComputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Warning_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Warning_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsCys_Certicificate_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsCys_Certicificate_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsCys_Certicificate_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsCys_Certicificate_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsDiag_Dtc_Element(P2CONST(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_Dtc_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsDiag_Dtc_Element(P2CONST(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_Dtc_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsDiag_ErrorRecord_Element(P2CONST(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_ErrorRecord_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsDiag_ErrorRecord_Element(P2CONST(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_ErrorRecord_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Audio_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Audio_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Communication_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Communication_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Display_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Display_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Display_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Display_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Gauges_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Gauges_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Gauges_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Gauges_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Illumination_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Illumination_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Illumination_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Illumination_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Odometer_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Odometer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Odometer_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Odometer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Personalization_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Personalization_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Personalization_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Personalization_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Power_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Power_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Power_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Power_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_RealTimeClock_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Tripcomputer_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Tripcomputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Tripcomputer_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Tripcomputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Warning_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_Warning_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_CusDlt_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_CusDlt_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_CusDlt_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_CusDlt_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_FuelGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_FuelGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_FuelGauge_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_FuelGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Illumination_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Illumination_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Illumination_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Illumination_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Odometer_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Odometer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Odometer_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Odometer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_OilGauge_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_OilGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_OilGauge_Element(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_OilGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Personalization_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Personalization_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Personalization_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Personalization_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_PowerGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_PowerGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_PowerGauge_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_PowerGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_RealTimeClock_Element(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_SpeedoGauge_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_SpeedoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_SpeedoGauge_Element(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_SpeedoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TachoGauge_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TachoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TachoGauge_Element(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TachoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TempGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TempGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TempGauge_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TempGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TripComputer_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TripComputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_TripComputer_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TripComputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Warning_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsRt_Warning_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_AssemblyManufacturingDate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_AssemblyManufacturingDate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_AssemblyPlantNumber(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_AssemblyPlantNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_AssemblyPlantNumber(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_AssemblyPlantNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(P2CONST(Rte_DT_Arr_u8_61_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_EcuPartNumber_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(P2CONST(Arr_u8_61, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_EcuPartNumber_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_HWModification(UInt16 BsShare_HWModification); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_PCBSerialNumber(P2CONST(Rte_DT_Arr_u8_9_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_PCBSerialNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_PCBSerialNumber(P2CONST(Arr_u8_9, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_PCBSerialNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_ProductSerialNumber(P2CONST(Rte_DT_Arr_u8_10_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_ProductSerialNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_ProductSerialNumber(P2CONST(Arr_u8_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_ProductSerialNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SMTManufacturingDate(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SMTManufacturingDate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SMTManufacturingDate(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SMTManufacturingDate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SMTPlantNumber(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SMTPlantNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SMTPlantNumber(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SMTPlantNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaFinPrint_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaFinPrint_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaMode_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaMode_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaStatus_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaStatus_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotadecrypt_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotadecrypt_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdReflash_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdReflash_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_SwUpdReflash_Element(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdReflash_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VehicleConfig_Element(P2CONST(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VehicleConfig_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VehicleConfig_Element(P2CONST(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VehicleConfig_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisMeet_EOLEntry_Element(UInt16 BsShare_VisMeet_EOLEntry_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisMeet_Element(P2CONST(Rte_DT_Arr_u8_46_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisMeet_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisMeet_Element(P2CONST(Arr_u8_46, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisMeet_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber(P2CONST(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisteonPCBPartNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber(P2CONST(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisteonPCBPartNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisteonPartNumber(P2CONST(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisteonPartNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisteonPartNumber(P2CONST(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisteonPartNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_RefCys_Certicificate1_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate1_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_RefCys_Certicificate1_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate1_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_RefCys_Certicificate_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_RefCys_Certicificate_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define MemAbstractMdl_STOP_SEC_CODE
# include "MemAbstractMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_if_CS_MemAbsGet_E_NOT_OK (1U)

#  define RTE_E_if_CS_MemAbsGetDefault_E_NOT_OK (1U)

#  define RTE_E_if_CS_MemAbs_NvMWriteStatus_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MEMABSTRACTMDL_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
