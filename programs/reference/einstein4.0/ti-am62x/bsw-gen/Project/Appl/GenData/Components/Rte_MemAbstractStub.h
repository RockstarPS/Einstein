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
 *          File:  Rte_MemAbstractStub.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <MemAbstractStub>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MEMABSTRACTSTUB_H
# define _RTE_MEMABSTRACTSTUB_H

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

# include "Rte_MemAbstractStub_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(NV_Data_BsConst_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(NV_Data_BsConst_Illumination_Copy1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(NV_Data_BsConst_Illumination_Copy2, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(NV_Data_BsShare_EcuPartNumber, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(NV_Data_BsShare_VisMeet, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BsConst_Compensation_Line_Shift_b_Value (11U)
#  define Rte_InitValue_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value (11U)
#  define Rte_InitValue_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value (11U)
#  define Rte_InitValue_BsConst_Compensation_Line_Slope_m_Value (44433U)
#  define Rte_InitValue_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value (44433U)
#  define Rte_InitValue_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value (44433U)
#  define Rte_InitValue_BsConst_Derating_Backlight_Disable_Value (0U)
#  define Rte_InitValue_BsConst_Derating_Backlight_Disable_SafeCopy1_Value (0U)
#  define Rte_InitValue_BsConst_Derating_Backlight_Disable_SafeCopy2_Value (0U)
#  define Rte_InitValue_BsConst_Display_Illum_Max_Level_Value (670U)
#  define Rte_InitValue_BsConst_Display_Illum_Max_Level_SafeCopy1_Value (670U)
#  define Rte_InitValue_BsConst_Display_Illum_Max_Level_SafeCopy2_Value (670U)
#  define Rte_InitValue_BsConst_PWM_boost_bypass_duty_Value (100U)
#  define Rte_InitValue_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value (100U)
#  define Rte_InitValue_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value (100U)
#  define Rte_InitValue_BsConst_Temp_Threshold_Hysteresis_Derating_Value (68U)
#  define Rte_InitValue_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value (68U)
#  define Rte_InitValue_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value (68U)
#  define Rte_InitValue_BsShare_HWModification_Value (0U)
#  define Rte_InitValue_BsShare_VisMeet_EOLEntry_Element_Value (65535U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Audio_Element_Value(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Audio_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_Value(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_Value(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Communication_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Communication_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_EngOffTimer_Element_Value(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_EngOffTimer_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_FuelGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_FuelGauge_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_OilGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_OilGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_Value(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PowerGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PowerGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Power_Element_Value(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Power_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_RealTimeClock_Element_Value(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_RealTimeClock_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_ServiceReminder_Element_Value(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_ServiceReminder_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_SpeedoGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_SpeedoGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TachoGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TachoGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TempGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TempGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_Value(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TripComputer_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TripComputer_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Warning_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Warning_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsCys_Certicificate_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsCys_Certicificate_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsDiag_Dtc_Element_Value(P2VAR(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsDiag_Dtc_Element_Value(P2VAR(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsDiag_ErrorRecord_Element_Value(P2VAR(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsDiag_ErrorRecord_Element_Value(P2VAR(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Audio_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Audio_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Communication_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Communication_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Display_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Display_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Gauges_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Gauges_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Illumination_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Illumination_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Odometer_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Odometer_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Personalization_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Personalization_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Power_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Power_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_RealTimeClock_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_RealTimeClock_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Tripcomputer_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Tripcomputer_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Warning_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Warning_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_CusDlt_Element_Value(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_CusDlt_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_FuelGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_FuelGauge_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Illumination_Element_Value(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Illumination_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Odometer_Element_Value(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Odometer_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_OilGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_OilGauge_Element_Value(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Personalization_Element_Value(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Personalization_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_PowerGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_PowerGauge_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_RealTimeClock_Element_Value(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_RealTimeClock_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_SpeedoGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_SpeedoGauge_Element_Value(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TachoGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TachoGauge_Element_Value(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TempGauge_Element_Value(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TempGauge_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TripComputer_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TripComputer_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Warning_Element_Value(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Warning_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_AssemblyManufacturingDate_Value(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_AssemblyManufacturingDate_Value(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_AssemblyPlantNumber_Value(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_AssemblyPlantNumber_Value(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_EcuPartNumber_Element_Value(P2VAR(Rte_DT_Arr_u8_61_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_EcuPartNumber_Element_Value(P2VAR(Arr_u8_61, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_PCBSerialNumber_Value(P2VAR(Rte_DT_Arr_u8_9_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_PCBSerialNumber_Value(P2VAR(Arr_u8_9, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_ProductSerialNumber_Value(P2VAR(Rte_DT_Arr_u8_10_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_ProductSerialNumber_Value(P2VAR(Arr_u8_10, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SMTManufacturingDate_Value(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SMTManufacturingDate_Value(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SMTPlantNumber_Value(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SMTPlantNumber_Value(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaFinPrint_Element_Value(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaFinPrint_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaMode_Element_Value(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaMode_Element_Value(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaStatus_Element_Value(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaStatus_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotadecrypt_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotadecrypt_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdReflash_Element_Value(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdReflash_Element_Value(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VehicleConfig_Element_Value(P2VAR(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VehicleConfig_Element_Value(P2VAR(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VisMeet_Element_Value(P2VAR(Rte_DT_Arr_u8_46_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VisMeet_Element_Value(P2VAR(Arr_u8_46, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VisteonPCBPartNumber_Value(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VisteonPCBPartNumber_Value(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VisteonPartNumber_Value(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VisteonPartNumber_Value(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_RefCys_Certicificate1_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_RefCys_Certicificate1_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_RefCys_Certicificate_Element_Value(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_RefCys_Certicificate_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Audio_Element_Value(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Audio_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_Value(P2CONST(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_Value(P2CONST(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value(P2CONST(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value(P2CONST(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value(P2CONST(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value(P2CONST(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Communication_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Communication_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Shift_b_Value(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Slope_m_Value(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Derating_Backlight_Disable_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Derating_Backlight_Disable_SafeCopy1_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Derating_Backlight_Disable_SafeCopy2_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Display_Illum_Max_Level_Value(uint16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Display_Illum_Max_Level_SafeCopy1_Value(uint16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Display_Illum_Max_Level_SafeCopy2_Value(uint16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_EngOffTimer_Element_Value(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_EngOffTimer_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_FuelGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_FuelGauge_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_OilGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_OilGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_Value(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PWM_boost_bypass_duty_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PowerGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PowerGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Power_Element_Value(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Power_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_RealTimeClock_Element_Value(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_RealTimeClock_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_ServiceReminder_Element_Value(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_ServiceReminder_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_SpeedoGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_SpeedoGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TachoGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TachoGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TempGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TempGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_Value(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TripComputer_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TripComputer_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Warning_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Warning_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsCys_Certicificate_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsCys_Certicificate_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsDiag_Dtc_Element_Value(P2CONST(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsDiag_Dtc_Element_Value(P2CONST(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsDiag_ErrorRecord_Element_Value(P2CONST(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsDiag_ErrorRecord_Element_Value(P2CONST(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Audio_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Audio_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Communication_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Communication_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Display_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Display_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Gauges_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Gauges_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Illumination_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Illumination_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Odometer_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Odometer_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Personalization_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Personalization_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Power_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Power_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_RealTimeClock_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_RealTimeClock_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Tripcomputer_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Tripcomputer_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Warning_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Warning_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_CusDlt_Element_Value(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_CusDlt_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_FuelGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_FuelGauge_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Illumination_Element_Value(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Illumination_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Odometer_Element_Value(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Odometer_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_OilGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_OilGauge_Element_Value(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Personalization_Element_Value(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Personalization_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_PowerGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_PowerGauge_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_RealTimeClock_Element_Value(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_RealTimeClock_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_SpeedoGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_SpeedoGauge_Element_Value(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TachoGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TachoGauge_Element_Value(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TempGauge_Element_Value(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TempGauge_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TripComputer_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TripComputer_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Warning_Element_Value(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Warning_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_AssemblyManufacturingDate_Value(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_AssemblyManufacturingDate_Value(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_AssemblyPlantNumber_Value(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_AssemblyPlantNumber_Value(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_EcuPartNumber_Element_Value(P2CONST(Rte_DT_Arr_u8_61_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_EcuPartNumber_Element_Value(P2CONST(Arr_u8_61, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_HWModification_Value(uint16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_PCBSerialNumber_Value(P2CONST(Rte_DT_Arr_u8_9_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_PCBSerialNumber_Value(P2CONST(Arr_u8_9, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_ProductSerialNumber_Value(P2CONST(Rte_DT_Arr_u8_10_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_ProductSerialNumber_Value(P2CONST(Arr_u8_10, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SMTManufacturingDate_Value(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SMTManufacturingDate_Value(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SMTPlantNumber_Value(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SMTPlantNumber_Value(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaFinPrint_Element_Value(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaFinPrint_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaMode_Element_Value(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaMode_Element_Value(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaStatus_Element_Value(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaStatus_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotadecrypt_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotadecrypt_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdReflash_Element_Value(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdReflash_Element_Value(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VehicleConfig_Element_Value(P2CONST(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VehicleConfig_Element_Value(P2CONST(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisMeet_EOLEntry_Element_Value(uint16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisMeet_Element_Value(P2CONST(Rte_DT_Arr_u8_46_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisMeet_Element_Value(P2CONST(Arr_u8_46, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisteonPCBPartNumber_Value(P2CONST(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisteonPCBPartNumber_Value(P2CONST(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisteonPartNumber_Value(P2CONST(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisteonPartNumber_Value(P2CONST(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_RefCys_Certicificate1_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_RefCys_Certicificate1_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_RefCys_Certicificate_Element_Value(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_RefCys_Certicificate_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BsConst_Audio_Element_Value Rte_Read_MemAbstractStub_BsConst_Audio_Element_Value
#  define Rte_Read_BsConst_BsConst_Illumination_ReservedByte_Value Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_Value
#  define Rte_Read_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value
#  define Rte_Read_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value
#  define Rte_Read_BsConst_Communication_Element_Value Rte_Read_MemAbstractStub_BsConst_Communication_Element_Value
#  define Rte_Read_BsConst_Compensation_Line_Shift_b_Value Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Shift_b_Value
#  define Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Shift_b_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Compensation_Line_Shift_b, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value
#  define Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Compensation_Line_Shift_b_SafeCopy1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value
#  define Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Compensation_Line_Shift_b_SafeCopy2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Compensation_Line_Slope_m_Value Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Slope_m_Value
#  define Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Slope_m_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Compensation_Line_Slope_m, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value
#  define Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Compensation_Line_Slope_m_SafeCopy1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value
#  define Rte_Read_MemAbstractStub_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Compensation_Line_Slope_m_SafeCopy2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Derating_Backlight_Disable_Value Rte_Read_MemAbstractStub_BsConst_Derating_Backlight_Disable_Value
#  define Rte_Read_MemAbstractStub_BsConst_Derating_Backlight_Disable_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Derating_Backlight_Disable, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Derating_Backlight_Disable_SafeCopy1_Value Rte_Read_MemAbstractStub_BsConst_Derating_Backlight_Disable_SafeCopy1_Value
#  define Rte_Read_MemAbstractStub_BsConst_Derating_Backlight_Disable_SafeCopy1_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Derating_Backlight_Disable_SafeCopy1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Derating_Backlight_Disable_SafeCopy2_Value Rte_Read_MemAbstractStub_BsConst_Derating_Backlight_Disable_SafeCopy2_Value
#  define Rte_Read_MemAbstractStub_BsConst_Derating_Backlight_Disable_SafeCopy2_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Derating_Backlight_Disable_SafeCopy2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Display_Illum_Max_Level_Value Rte_Read_MemAbstractStub_BsConst_Display_Illum_Max_Level_Value
#  define Rte_Read_MemAbstractStub_BsConst_Display_Illum_Max_Level_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Display_Illum_Max_Level, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Display_Illum_Max_Level_SafeCopy1_Value Rte_Read_MemAbstractStub_BsConst_Display_Illum_Max_Level_SafeCopy1_Value
#  define Rte_Read_MemAbstractStub_BsConst_Display_Illum_Max_Level_SafeCopy1_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Display_Illum_Max_Level_SafeCopy1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Display_Illum_Max_Level_SafeCopy2_Value Rte_Read_MemAbstractStub_BsConst_Display_Illum_Max_Level_SafeCopy2_Value
#  define Rte_Read_MemAbstractStub_BsConst_Display_Illum_Max_Level_SafeCopy2_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Display_Illum_Max_Level_SafeCopy2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_EngOffTimer_Element_Value Rte_Read_MemAbstractStub_BsConst_EngOffTimer_Element_Value
#  define Rte_Read_BsConst_FuelGauge_Element_Value Rte_Read_MemAbstractStub_BsConst_FuelGauge_Element_Value
#  define Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_Value Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_Value
#  define Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value
#  define Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value
#  define Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value
#  define Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value
#  define Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value
#  define Rte_Read_BsConst_OilGauge_Element_Value Rte_Read_MemAbstractStub_BsConst_OilGauge_Element_Value
#  define Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_Value Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_Value
#  define Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value
#  define Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value
#  define Rte_Read_BsConst_PWM_boost_bypass_duty_Value Rte_Read_MemAbstractStub_BsConst_PWM_boost_bypass_duty_Value
#  define Rte_Read_MemAbstractStub_BsConst_PWM_boost_bypass_duty_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_PWM_boost_bypass_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value Rte_Read_MemAbstractStub_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value
#  define Rte_Read_MemAbstractStub_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_PWM_boost_bypass_duty_SafeCopy1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value Rte_Read_MemAbstractStub_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value
#  define Rte_Read_MemAbstractStub_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_PWM_boost_bypass_duty_SafeCopy2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_PowerGauge_Element_Value Rte_Read_MemAbstractStub_BsConst_PowerGauge_Element_Value
#  define Rte_Read_BsConst_Power_Element_Value Rte_Read_MemAbstractStub_BsConst_Power_Element_Value
#  define Rte_Read_BsConst_RealTimeClock_Element_Value Rte_Read_MemAbstractStub_BsConst_RealTimeClock_Element_Value
#  define Rte_Read_BsConst_ServiceReminder_Element_Value Rte_Read_MemAbstractStub_BsConst_ServiceReminder_Element_Value
#  define Rte_Read_BsConst_SpeedoGauge_Element_Value Rte_Read_MemAbstractStub_BsConst_SpeedoGauge_Element_Value
#  define Rte_Read_BsConst_TachoGauge_Element_Value Rte_Read_MemAbstractStub_BsConst_TachoGauge_Element_Value
#  define Rte_Read_BsConst_TempGauge_Element_Value Rte_Read_MemAbstractStub_BsConst_TempGauge_Element_Value
#  define Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_Value Rte_Read_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_Value
#  define Rte_Read_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Temp_Threshold_Hysteresis_Derating, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value Rte_Read_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value
#  define Rte_Read_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value Rte_Read_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value
#  define Rte_Read_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Temperature_Sensor_Conv_Value Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_Value
#  define Rte_Read_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value
#  define Rte_Read_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value
#  define Rte_Read_BsConst_TripComputer_Element_Value Rte_Read_MemAbstractStub_BsConst_TripComputer_Element_Value
#  define Rte_Read_BsConst_Warning_Element_Value Rte_Read_MemAbstractStub_BsConst_Warning_Element_Value
#  define Rte_Read_BsCys_Certicificate_Element_Value Rte_Read_MemAbstractStub_BsCys_Certicificate_Element_Value
#  define Rte_Read_BsDiag_Dtc_Element_Value Rte_Read_MemAbstractStub_BsDiag_Dtc_Element_Value
#  define Rte_Read_BsDiag_ErrorRecord_Element_Value Rte_Read_MemAbstractStub_BsDiag_ErrorRecord_Element_Value
#  define Rte_Read_BsReten_Audio_Element_Value Rte_Read_MemAbstractStub_BsReten_Audio_Element_Value
#  define Rte_Read_BsReten_Communication_Element_Value Rte_Read_MemAbstractStub_BsReten_Communication_Element_Value
#  define Rte_Read_BsReten_Display_Element_Value Rte_Read_MemAbstractStub_BsReten_Display_Element_Value
#  define Rte_Read_BsReten_Gauges_Element_Value Rte_Read_MemAbstractStub_BsReten_Gauges_Element_Value
#  define Rte_Read_BsReten_Illumination_Element_Value Rte_Read_MemAbstractStub_BsReten_Illumination_Element_Value
#  define Rte_Read_BsReten_Odometer_Element_Value Rte_Read_MemAbstractStub_BsReten_Odometer_Element_Value
#  define Rte_Read_BsReten_Personalization_Element_Value Rte_Read_MemAbstractStub_BsReten_Personalization_Element_Value
#  define Rte_Read_BsReten_Power_Element_Value Rte_Read_MemAbstractStub_BsReten_Power_Element_Value
#  define Rte_Read_BsReten_RealTimeClock_Element_Value Rte_Read_MemAbstractStub_BsReten_RealTimeClock_Element_Value
#  define Rte_Read_BsReten_Tripcomputer_Element_Value Rte_Read_MemAbstractStub_BsReten_Tripcomputer_Element_Value
#  define Rte_Read_BsReten_Warning_Element_Value Rte_Read_MemAbstractStub_BsReten_Warning_Element_Value
#  define Rte_Read_BsRt_CusDlt_Element_Value Rte_Read_MemAbstractStub_BsRt_CusDlt_Element_Value
#  define Rte_Read_BsRt_FuelGauge_Element_Value Rte_Read_MemAbstractStub_BsRt_FuelGauge_Element_Value
#  define Rte_Read_BsRt_Illumination_Element_Value Rte_Read_MemAbstractStub_BsRt_Illumination_Element_Value
#  define Rte_Read_BsRt_Odometer_Element_Value Rte_Read_MemAbstractStub_BsRt_Odometer_Element_Value
#  define Rte_Read_BsRt_OilGauge_Element_Value Rte_Read_MemAbstractStub_BsRt_OilGauge_Element_Value
#  define Rte_Read_BsRt_Personalization_Element_Value Rte_Read_MemAbstractStub_BsRt_Personalization_Element_Value
#  define Rte_Read_BsRt_PowerGauge_Element_Value Rte_Read_MemAbstractStub_BsRt_PowerGauge_Element_Value
#  define Rte_Read_BsRt_RealTimeClock_Element_Value Rte_Read_MemAbstractStub_BsRt_RealTimeClock_Element_Value
#  define Rte_Read_BsRt_SpeedoGauge_Element_Value Rte_Read_MemAbstractStub_BsRt_SpeedoGauge_Element_Value
#  define Rte_Read_BsRt_TachoGauge_Element_Value Rte_Read_MemAbstractStub_BsRt_TachoGauge_Element_Value
#  define Rte_Read_BsRt_TempGauge_Element_Value Rte_Read_MemAbstractStub_BsRt_TempGauge_Element_Value
#  define Rte_Read_BsRt_TripComputer_Element_Value Rte_Read_MemAbstractStub_BsRt_TripComputer_Element_Value
#  define Rte_Read_BsRt_Warning_Element_Value Rte_Read_MemAbstractStub_BsRt_Warning_Element_Value
#  define Rte_Read_BsShare_AssemblyManufacturingDate_Value Rte_Read_MemAbstractStub_BsShare_AssemblyManufacturingDate_Value
#  define Rte_Read_BsShare_AssemblyPlantNumber_Value Rte_Read_MemAbstractStub_BsShare_AssemblyPlantNumber_Value
#  define Rte_Read_BsShare_EcuPartNumber_Element_Value Rte_Read_MemAbstractStub_BsShare_EcuPartNumber_Element_Value
#  define Rte_Read_BsShare_HWModification_Value Rte_Read_MemAbstractStub_BsShare_HWModification_Value
#  define Rte_Read_MemAbstractStub_BsShare_HWModification_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_HWModification, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsShare_PCBSerialNumber_Value Rte_Read_MemAbstractStub_BsShare_PCBSerialNumber_Value
#  define Rte_Read_BsShare_ProductSerialNumber_Value Rte_Read_MemAbstractStub_BsShare_ProductSerialNumber_Value
#  define Rte_Read_BsShare_SMTManufacturingDate_Value Rte_Read_MemAbstractStub_BsShare_SMTManufacturingDate_Value
#  define Rte_Read_BsShare_SMTPlantNumber_Value Rte_Read_MemAbstractStub_BsShare_SMTPlantNumber_Value
#  define Rte_Read_BsShare_SwUpdFotaFinPrint_Element_Value Rte_Read_MemAbstractStub_BsShare_SwUpdFotaFinPrint_Element_Value
#  define Rte_Read_BsShare_SwUpdFotaMode_Element_Value Rte_Read_MemAbstractStub_BsShare_SwUpdFotaMode_Element_Value
#  define Rte_Read_BsShare_SwUpdFotaStatus_Element_Value Rte_Read_MemAbstractStub_BsShare_SwUpdFotaStatus_Element_Value
#  define Rte_Read_BsShare_SwUpdFotadecrypt_Element_Value Rte_Read_MemAbstractStub_BsShare_SwUpdFotadecrypt_Element_Value
#  define Rte_Read_BsShare_SwUpdReflash_Element_Value Rte_Read_MemAbstractStub_BsShare_SwUpdReflash_Element_Value
#  define Rte_Read_BsShare_VehicleConfig_Element_Value Rte_Read_MemAbstractStub_BsShare_VehicleConfig_Element_Value
#  define Rte_Read_BsShare_VisMeet_EOLEntry_Element_Value Rte_Read_MemAbstractStub_BsShare_VisMeet_EOLEntry_Element_Value
#  define Rte_Read_MemAbstractStub_BsShare_VisMeet_EOLEntry_Element_Value(data) (*(data) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet.BsShare_VisMeet_EOLEntry_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsShare_VisMeet_Element_Value Rte_Read_MemAbstractStub_BsShare_VisMeet_Element_Value
#  define Rte_Read_BsShare_VisteonPCBPartNumber_Value Rte_Read_MemAbstractStub_BsShare_VisteonPCBPartNumber_Value
#  define Rte_Read_BsShare_VisteonPartNumber_Value Rte_Read_MemAbstractStub_BsShare_VisteonPartNumber_Value
#  define Rte_Read_RefCys_Certicificate1_Element_Value Rte_Read_MemAbstractStub_RefCys_Certicificate1_Element_Value
#  define Rte_Read_RefCys_Certicificate_Element_Value Rte_Read_MemAbstractStub_RefCys_Certicificate_Element_Value


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BsConst_Audio_Element_Value Rte_Write_MemAbstractStub_BsConst_Audio_Element_Value
#  define Rte_Write_BsConst_BsConst_Illumination_ReservedByte_Value Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_Value
#  define Rte_Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value
#  define Rte_Write_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value
#  define Rte_Write_BsConst_Communication_Element_Value Rte_Write_MemAbstractStub_BsConst_Communication_Element_Value
#  define Rte_Write_BsConst_Compensation_Line_Shift_b_Value Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Shift_b_Value
#  define Rte_Write_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value
#  define Rte_Write_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value
#  define Rte_Write_BsConst_Compensation_Line_Slope_m_Value Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Slope_m_Value
#  define Rte_Write_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value
#  define Rte_Write_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value
#  define Rte_Write_BsConst_Derating_Backlight_Disable_Value Rte_Write_MemAbstractStub_BsConst_Derating_Backlight_Disable_Value
#  define Rte_Write_BsConst_Derating_Backlight_Disable_SafeCopy1_Value Rte_Write_MemAbstractStub_BsConst_Derating_Backlight_Disable_SafeCopy1_Value
#  define Rte_Write_BsConst_Derating_Backlight_Disable_SafeCopy2_Value Rte_Write_MemAbstractStub_BsConst_Derating_Backlight_Disable_SafeCopy2_Value
#  define Rte_Write_BsConst_Display_Illum_Max_Level_Value Rte_Write_MemAbstractStub_BsConst_Display_Illum_Max_Level_Value
#  define Rte_Write_BsConst_Display_Illum_Max_Level_SafeCopy1_Value Rte_Write_MemAbstractStub_BsConst_Display_Illum_Max_Level_SafeCopy1_Value
#  define Rte_Write_BsConst_Display_Illum_Max_Level_SafeCopy2_Value Rte_Write_MemAbstractStub_BsConst_Display_Illum_Max_Level_SafeCopy2_Value
#  define Rte_Write_BsConst_EngOffTimer_Element_Value Rte_Write_MemAbstractStub_BsConst_EngOffTimer_Element_Value
#  define Rte_Write_BsConst_FuelGauge_Element_Value Rte_Write_MemAbstractStub_BsConst_FuelGauge_Element_Value
#  define Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_Value
#  define Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value
#  define Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value
#  define Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value
#  define Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value
#  define Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value
#  define Rte_Write_BsConst_OilGauge_Element_Value Rte_Write_MemAbstractStub_BsConst_OilGauge_Element_Value
#  define Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_Value Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_Value
#  define Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value
#  define Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value
#  define Rte_Write_BsConst_PWM_boost_bypass_duty_Value Rte_Write_MemAbstractStub_BsConst_PWM_boost_bypass_duty_Value
#  define Rte_Write_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value Rte_Write_MemAbstractStub_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value
#  define Rte_Write_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value Rte_Write_MemAbstractStub_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value
#  define Rte_Write_BsConst_PowerGauge_Element_Value Rte_Write_MemAbstractStub_BsConst_PowerGauge_Element_Value
#  define Rte_Write_BsConst_Power_Element_Value Rte_Write_MemAbstractStub_BsConst_Power_Element_Value
#  define Rte_Write_BsConst_RealTimeClock_Element_Value Rte_Write_MemAbstractStub_BsConst_RealTimeClock_Element_Value
#  define Rte_Write_BsConst_ServiceReminder_Element_Value Rte_Write_MemAbstractStub_BsConst_ServiceReminder_Element_Value
#  define Rte_Write_BsConst_SpeedoGauge_Element_Value Rte_Write_MemAbstractStub_BsConst_SpeedoGauge_Element_Value
#  define Rte_Write_BsConst_TachoGauge_Element_Value Rte_Write_MemAbstractStub_BsConst_TachoGauge_Element_Value
#  define Rte_Write_BsConst_TempGauge_Element_Value Rte_Write_MemAbstractStub_BsConst_TempGauge_Element_Value
#  define Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_Value Rte_Write_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_Value
#  define Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value Rte_Write_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value
#  define Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value Rte_Write_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value
#  define Rte_Write_BsConst_Temperature_Sensor_Conv_Value Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_Value
#  define Rte_Write_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value
#  define Rte_Write_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value
#  define Rte_Write_BsConst_TripComputer_Element_Value Rte_Write_MemAbstractStub_BsConst_TripComputer_Element_Value
#  define Rte_Write_BsConst_Warning_Element_Value Rte_Write_MemAbstractStub_BsConst_Warning_Element_Value
#  define Rte_Write_BsCys_Certicificate_Element_Value Rte_Write_MemAbstractStub_BsCys_Certicificate_Element_Value
#  define Rte_Write_BsDiag_Dtc_Element_Value Rte_Write_MemAbstractStub_BsDiag_Dtc_Element_Value
#  define Rte_Write_BsDiag_ErrorRecord_Element_Value Rte_Write_MemAbstractStub_BsDiag_ErrorRecord_Element_Value
#  define Rte_Write_BsReten_Audio_Element_Value Rte_Write_MemAbstractStub_BsReten_Audio_Element_Value
#  define Rte_Write_BsReten_Communication_Element_Value Rte_Write_MemAbstractStub_BsReten_Communication_Element_Value
#  define Rte_Write_BsReten_Display_Element_Value Rte_Write_MemAbstractStub_BsReten_Display_Element_Value
#  define Rte_Write_BsReten_Gauges_Element_Value Rte_Write_MemAbstractStub_BsReten_Gauges_Element_Value
#  define Rte_Write_BsReten_Illumination_Element_Value Rte_Write_MemAbstractStub_BsReten_Illumination_Element_Value
#  define Rte_Write_BsReten_Odometer_Element_Value Rte_Write_MemAbstractStub_BsReten_Odometer_Element_Value
#  define Rte_Write_BsReten_Personalization_Element_Value Rte_Write_MemAbstractStub_BsReten_Personalization_Element_Value
#  define Rte_Write_BsReten_Power_Element_Value Rte_Write_MemAbstractStub_BsReten_Power_Element_Value
#  define Rte_Write_BsReten_RealTimeClock_Element_Value Rte_Write_MemAbstractStub_BsReten_RealTimeClock_Element_Value
#  define Rte_Write_BsReten_Tripcomputer_Element_Value Rte_Write_MemAbstractStub_BsReten_Tripcomputer_Element_Value
#  define Rte_Write_BsReten_Warning_Element_Value Rte_Write_MemAbstractStub_BsReten_Warning_Element_Value
#  define Rte_Write_BsRt_CusDlt_Element_Value Rte_Write_MemAbstractStub_BsRt_CusDlt_Element_Value
#  define Rte_Write_BsRt_FuelGauge_Element_Value Rte_Write_MemAbstractStub_BsRt_FuelGauge_Element_Value
#  define Rte_Write_BsRt_Illumination_Element_Value Rte_Write_MemAbstractStub_BsRt_Illumination_Element_Value
#  define Rte_Write_BsRt_Odometer_Element_Value Rte_Write_MemAbstractStub_BsRt_Odometer_Element_Value
#  define Rte_Write_BsRt_OilGauge_Element_Value Rte_Write_MemAbstractStub_BsRt_OilGauge_Element_Value
#  define Rte_Write_BsRt_Personalization_Element_Value Rte_Write_MemAbstractStub_BsRt_Personalization_Element_Value
#  define Rte_Write_BsRt_PowerGauge_Element_Value Rte_Write_MemAbstractStub_BsRt_PowerGauge_Element_Value
#  define Rte_Write_BsRt_RealTimeClock_Element_Value Rte_Write_MemAbstractStub_BsRt_RealTimeClock_Element_Value
#  define Rte_Write_BsRt_SpeedoGauge_Element_Value Rte_Write_MemAbstractStub_BsRt_SpeedoGauge_Element_Value
#  define Rte_Write_BsRt_TachoGauge_Element_Value Rte_Write_MemAbstractStub_BsRt_TachoGauge_Element_Value
#  define Rte_Write_BsRt_TempGauge_Element_Value Rte_Write_MemAbstractStub_BsRt_TempGauge_Element_Value
#  define Rte_Write_BsRt_TripComputer_Element_Value Rte_Write_MemAbstractStub_BsRt_TripComputer_Element_Value
#  define Rte_Write_BsRt_Warning_Element_Value Rte_Write_MemAbstractStub_BsRt_Warning_Element_Value
#  define Rte_Write_BsShare_AssemblyManufacturingDate_Value Rte_Write_MemAbstractStub_BsShare_AssemblyManufacturingDate_Value
#  define Rte_Write_BsShare_AssemblyPlantNumber_Value Rte_Write_MemAbstractStub_BsShare_AssemblyPlantNumber_Value
#  define Rte_Write_BsShare_EcuPartNumber_Element_Value Rte_Write_MemAbstractStub_BsShare_EcuPartNumber_Element_Value
#  define Rte_Write_BsShare_HWModification_Value Rte_Write_MemAbstractStub_BsShare_HWModification_Value
#  define Rte_Write_BsShare_PCBSerialNumber_Value Rte_Write_MemAbstractStub_BsShare_PCBSerialNumber_Value
#  define Rte_Write_BsShare_ProductSerialNumber_Value Rte_Write_MemAbstractStub_BsShare_ProductSerialNumber_Value
#  define Rte_Write_BsShare_SMTManufacturingDate_Value Rte_Write_MemAbstractStub_BsShare_SMTManufacturingDate_Value
#  define Rte_Write_BsShare_SMTPlantNumber_Value Rte_Write_MemAbstractStub_BsShare_SMTPlantNumber_Value
#  define Rte_Write_BsShare_SwUpdFotaFinPrint_Element_Value Rte_Write_MemAbstractStub_BsShare_SwUpdFotaFinPrint_Element_Value
#  define Rte_Write_BsShare_SwUpdFotaMode_Element_Value Rte_Write_MemAbstractStub_BsShare_SwUpdFotaMode_Element_Value
#  define Rte_Write_BsShare_SwUpdFotaStatus_Element_Value Rte_Write_MemAbstractStub_BsShare_SwUpdFotaStatus_Element_Value
#  define Rte_Write_BsShare_SwUpdFotadecrypt_Element_Value Rte_Write_MemAbstractStub_BsShare_SwUpdFotadecrypt_Element_Value
#  define Rte_Write_BsShare_SwUpdReflash_Element_Value Rte_Write_MemAbstractStub_BsShare_SwUpdReflash_Element_Value
#  define Rte_Write_BsShare_VehicleConfig_Element_Value Rte_Write_MemAbstractStub_BsShare_VehicleConfig_Element_Value
#  define Rte_Write_BsShare_VisMeet_EOLEntry_Element_Value Rte_Write_MemAbstractStub_BsShare_VisMeet_EOLEntry_Element_Value
#  define Rte_Write_BsShare_VisMeet_Element_Value Rte_Write_MemAbstractStub_BsShare_VisMeet_Element_Value
#  define Rte_Write_BsShare_VisteonPCBPartNumber_Value Rte_Write_MemAbstractStub_BsShare_VisteonPCBPartNumber_Value
#  define Rte_Write_BsShare_VisteonPartNumber_Value Rte_Write_MemAbstractStub_BsShare_VisteonPartNumber_Value
#  define Rte_Write_RefCys_Certicificate1_Element_Value Rte_Write_MemAbstractStub_RefCys_Certicificate1_Element_Value
#  define Rte_Write_RefCys_Certicificate_Element_Value Rte_Write_MemAbstractStub_RefCys_Certicificate_Element_Value


# endif /* !defined(RTE_CORE) */


# define MemAbstractStub_START_SEC_CODE
# include "MemAbstractStub_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_Audio MemAbstractMdl_NotifyJobEnd_BsConst_Audio
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_Communication MemAbstractMdl_NotifyJobEnd_BsConst_Communication
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_EngOffTimer MemAbstractMdl_NotifyJobEnd_BsConst_EngOffTimer
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_FuelGauge MemAbstractMdl_NotifyJobEnd_BsConst_FuelGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_OilGauge MemAbstractMdl_NotifyJobEnd_BsConst_OilGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_Power MemAbstractMdl_NotifyJobEnd_BsConst_Power
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_PowerGauge MemAbstractMdl_NotifyJobEnd_BsConst_PowerGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_RealTimeClock MemAbstractMdl_NotifyJobEnd_BsConst_RealTimeClock
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_ServiceReminder MemAbstractMdl_NotifyJobEnd_BsConst_ServiceReminder
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_SpeedoGauge MemAbstractMdl_NotifyJobEnd_BsConst_SpeedoGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_TachoGauge MemAbstractMdl_NotifyJobEnd_BsConst_TachoGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_TempGauge MemAbstractMdl_NotifyJobEnd_BsConst_TempGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_TripComputer MemAbstractMdl_NotifyJobEnd_BsConst_TripComputer
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsConst_Warning MemAbstractMdl_NotifyJobEnd_BsConst_Warning
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsCys_Certicificate MemAbstractMdl_NotifyJobEnd_BsCys_Certicificate
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsDiag_Dtc MemAbstractMdl_NotifyJobEnd_BsDiag_Dtc
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsDiag_ErrorRecord MemAbstractMdl_NotifyJobEnd_BsDiag_ErrorRecord
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsReten_Audio MemAbstractMdl_NotifyJobEnd_BsReten_Audio
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsReten_Communication MemAbstractMdl_NotifyJobEnd_BsReten_Communication
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsReten_Display MemAbstractMdl_NotifyJobEnd_BsReten_Display
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsReten_Gauges MemAbstractMdl_NotifyJobEnd_BsReten_Gauges
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsReten_Illumination MemAbstractMdl_NotifyJobEnd_BsReten_Illumination
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsReten_Odometer MemAbstractMdl_NotifyJobEnd_BsReten_Odometer
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsReten_Personalization MemAbstractMdl_NotifyJobEnd_BsReten_Personalization
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsReten_Power MemAbstractMdl_NotifyJobEnd_BsReten_Power
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsReten_RealTimeClock MemAbstractMdl_NotifyJobEnd_BsReten_RealTimeClock
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsReten_Tripcomputer MemAbstractMdl_NotifyJobEnd_BsReten_Tripcomputer
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsReten_Warning MemAbstractMdl_NotifyJobEnd_BsReten_Warning
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_CusDlt MemAbstractMdl_NotifyJobEnd_BsRt_CusDlt
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_FuelGauge MemAbstractMdl_NotifyJobEnd_BsRt_FuelGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_Illumination MemAbstractMdl_NotifyJobEnd_BsRt_Illumination
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_Odometer MemAbstractMdl_NotifyJobEnd_BsRt_Odometer
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_OilGauge MemAbstractMdl_NotifyJobEnd_BsRt_OilGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_Personalization MemAbstractMdl_NotifyJobEnd_BsRt_Personalization
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_PowerGauge MemAbstractMdl_NotifyJobEnd_BsRt_PowerGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_RealTimeClock MemAbstractMdl_NotifyJobEnd_BsRt_RealTimeClock
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_SpeedoGauge MemAbstractMdl_NotifyJobEnd_BsRt_SpeedoGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_TachoGauge MemAbstractMdl_NotifyJobEnd_BsRt_TachoGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_TempGauge MemAbstractMdl_NotifyJobEnd_BsRt_TempGauge
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_TripComputer MemAbstractMdl_NotifyJobEnd_BsRt_TripComputer
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsRt_Warning MemAbstractMdl_NotifyJobEnd_BsRt_Warning
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsShare_EcuPartNumber MemAbstractMdl_NotifyJobEnd_BsShare_EcuPartNumber
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaFinPrint MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaFinPrint
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaMode MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaMode
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaStatus MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaStatus
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotadecrypt MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotadecrypt
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdReflash MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdReflash
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsShare_VehicleConfig MemAbstractMdl_NotifyJobEnd_BsShare_VehicleConfig
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_BsShare_VisMeet MemAbstractMdl_NotifyJobEnd_BsShare_VisMeet
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate
#  define RTE_RUNNABLE_MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate1 MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate1
#  define RTE_RUNNABLE_MemAbstract_MainFunction MemAbstract_MainFunction
# endif

FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_Audio(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_Communication(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_EngOffTimer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_FuelGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_OilGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_Power(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_PowerGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_ServiceReminder(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_SpeedoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_TachoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_TempGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_TripComputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsConst_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsCys_Certicificate(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsDiag_Dtc(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsDiag_ErrorRecord(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Audio(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Communication(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Display(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Gauges(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Odometer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Personalization(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Power(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Tripcomputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsReten_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_CusDlt(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_FuelGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_Odometer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_OilGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_Personalization(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_PowerGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_RealTimeClock(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_SpeedoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_TachoGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_TempGauge(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_TripComputer(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsRt_Warning(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_EcuPartNumber(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaFinPrint(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaMode(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaStatus(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotadecrypt(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdReflash(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_VehicleConfig(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_BsShare_VisMeet(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate1(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstractStub_CODE) MemAbstract_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define MemAbstractStub_STOP_SEC_CODE
# include "MemAbstractStub_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MEMABSTRACTSTUB_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
