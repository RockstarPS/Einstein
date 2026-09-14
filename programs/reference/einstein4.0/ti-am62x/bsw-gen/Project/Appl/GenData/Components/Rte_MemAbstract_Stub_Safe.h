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
 *          File:  Rte_MemAbstract_Stub_Safe.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <MemAbstract_Stub_Safe>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MEMABSTRACT_STUB_SAFE_H
# define _RTE_MEMABSTRACT_STUB_SAFE_H

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

# include "Rte_MemAbstract_Stub_Safe_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Shift_b_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Slope_m_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Derating_Backlight_Disable_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Display_Illum_Max_Level_Safe_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_PWM_boost_bypass_duty_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Temp_Threshold_Hysteresis_Derating_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value(P2CONST(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value(P2CONST(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Shift_b_Value(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Slope_m_Value(uint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Derating_Backlight_Disable_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Display_Illum_Max_Level_Safe_Value(uint16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2CONST(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_PWM_boost_bypass_duty_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Temp_Threshold_Hysteresis_Derating_Value(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value(P2CONST(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BsConst_BsConst_Illumination_ReservedByte_Value Rte_Read_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value
#  define Rte_Read_BsConst_Compensation_Line_Shift_b_Value Rte_Read_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Shift_b_Value
#  define Rte_Read_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Shift_b_Value(data) (*(data) = Rte_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Shift_b_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Compensation_Line_Slope_m_Value Rte_Read_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Slope_m_Value
#  define Rte_Read_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Slope_m_Value(data) (*(data) = Rte_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Slope_m_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Derating_Backlight_Disable_Value Rte_Read_MemAbstract_Stub_Safe_BsConst_Derating_Backlight_Disable_Value
#  define Rte_Read_MemAbstract_Stub_Safe_BsConst_Derating_Backlight_Disable_Value(data) (*(data) = Rte_MemAbstract_Stub_Safe_BsConst_Derating_Backlight_Disable_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Display_Illum_Max_Level_Safe_Value Rte_Read_MemAbstract_Stub_Safe_BsConst_Display_Illum_Max_Level_Safe_Value
#  define Rte_Read_MemAbstract_Stub_Safe_BsConst_Display_Illum_Max_Level_Safe_Value(data) (*(data) = Rte_MemAbstract_Stub_Safe_BsConst_Display_Illum_Max_Level_Safe_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_X_Value Rte_Read_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value
#  define Rte_Read_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value Rte_Read_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value
#  define Rte_Read_BsConst_PCB_Temperature_Sensor_Conv_Value Rte_Read_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value
#  define Rte_Read_BsConst_PWM_boost_bypass_duty_Value Rte_Read_MemAbstract_Stub_Safe_BsConst_PWM_boost_bypass_duty_Value
#  define Rte_Read_MemAbstract_Stub_Safe_BsConst_PWM_boost_bypass_duty_Value(data) (*(data) = Rte_MemAbstract_Stub_Safe_BsConst_PWM_boost_bypass_duty_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Temp_Threshold_Hysteresis_Derating_Value Rte_Read_MemAbstract_Stub_Safe_BsConst_Temp_Threshold_Hysteresis_Derating_Value
#  define Rte_Read_MemAbstract_Stub_Safe_BsConst_Temp_Threshold_Hysteresis_Derating_Value(data) (*(data) = Rte_MemAbstract_Stub_Safe_BsConst_Temp_Threshold_Hysteresis_Derating_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_BsConst_Temperature_Sensor_Conv_Value Rte_Read_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BsConst_BsConst_Illumination_ReservedByte_Value Rte_Write_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value
#  define Rte_Write_BsConst_Compensation_Line_Shift_b_Value Rte_Write_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Shift_b_Value
#  define Rte_Write_BsConst_Compensation_Line_Slope_m_Value Rte_Write_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Slope_m_Value
#  define Rte_Write_BsConst_Derating_Backlight_Disable_Value Rte_Write_MemAbstract_Stub_Safe_BsConst_Derating_Backlight_Disable_Value
#  define Rte_Write_BsConst_Display_Illum_Max_Level_Safe_Value Rte_Write_MemAbstract_Stub_Safe_BsConst_Display_Illum_Max_Level_Safe_Value
#  define Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_X_Value Rte_Write_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value
#  define Rte_Write_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value Rte_Write_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value
#  define Rte_Write_BsConst_PCB_Temperature_Sensor_Conv_Value Rte_Write_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value
#  define Rte_Write_BsConst_PWM_boost_bypass_duty_Value Rte_Write_MemAbstract_Stub_Safe_BsConst_PWM_boost_bypass_duty_Value
#  define Rte_Write_BsConst_Temp_Threshold_Hysteresis_Derating_Value Rte_Write_MemAbstract_Stub_Safe_BsConst_Temp_Threshold_Hysteresis_Derating_Value
#  define Rte_Write_BsConst_Temperature_Sensor_Conv_Value Rte_Write_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value


# endif /* !defined(RTE_CORE) */


# define MemAbstract_Stub_Safe_START_SEC_CODE
# include "MemAbstract_Stub_Safe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination
#  define RTE_RUNNABLE_MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy1 MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy1
#  define RTE_RUNNABLE_MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy2 MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy2
#  define RTE_RUNNABLE_MemAbstract_Stub_Safe MemAbstract_Stub_Safe
# endif

FUNC(void, MemAbstract_Stub_Safe_CODE) MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstract_Stub_Safe_CODE) MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy1(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstract_Stub_Safe_CODE) MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy2(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, MemAbstract_Stub_Safe_CODE) MemAbstract_Stub_Safe(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define MemAbstract_Stub_Safe_STOP_SEC_CODE
# include "MemAbstract_Stub_Safe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MEMABSTRACT_STUB_SAFE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
