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
 *          File:  Rte_CComAbsMdlSafe.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CComAbsMdlSafe>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CCOMABSMDLSAFE_H
# define _RTE_CCOMABSMDLSAFE_H

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

# include "Rte_CComAbsMdlSafe_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Audio_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Audio_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element MemAbstractMdl_Get_BsConst_Audio_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2VAR(Rte_DT_Arr_u8_28_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 MemAbstractMdl_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element MemAbstractMdl_Get_BsConst_Communication_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1 MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2 MemAbstractMdl_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1 MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2 MemAbstractMdl_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1 MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2 MemAbstractMdl_Get_BsConst_Derating_Backlight_Disable_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1 MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2 MemAbstractMdl_Get_BsConst_Display_Illum_Max_Level_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_EngOffTimer_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_EngOffTimer_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element MemAbstractMdl_Get_BsConst_EngOffTimer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_FuelGauge_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element MemAbstractMdl_Get_BsConst_FuelGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2VAR(Rte_DT_Arr_u16_7_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 MemAbstractMdl_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_OilGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element MemAbstractMdl_Get_BsConst_OilGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 MemAbstractMdl_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1 MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2 MemAbstractMdl_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_PowerGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element MemAbstractMdl_Get_BsConst_PowerGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Power_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Power_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element MemAbstractMdl_Get_BsConst_Power_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_RealTimeClock_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element MemAbstractMdl_Get_BsConst_RealTimeClock_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_ServiceReminder_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_ServiceReminder_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element MemAbstractMdl_Get_BsConst_ServiceReminder_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_SpeedoGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element MemAbstractMdl_Get_BsConst_SpeedoGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TachoGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element MemAbstractMdl_Get_BsConst_TachoGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TempGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element MemAbstractMdl_Get_BsConst_TempGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 MemAbstractMdl_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1 MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2VAR(Rte_DT_T_NV_Temperature_Conversion_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2 MemAbstractMdl_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_TripComputer_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element MemAbstractMdl_Get_BsConst_TripComputer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Warning_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Warning_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element MemAbstractMdl_Get_BsConst_Warning_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsCys_Certicificate_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element MemAbstractMdl_Get_BsCys_Certicificate_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsDiag_Dtc_Element(P2VAR(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsDiag_Dtc_Element(P2VAR(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element MemAbstractMdl_Get_BsDiag_Dtc_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsDiag_ErrorRecord_Element(P2VAR(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsDiag_ErrorRecord_Element(P2VAR(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element MemAbstractMdl_Get_BsDiag_ErrorRecord_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Audio_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Audio_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element MemAbstractMdl_Get_BsReten_Audio_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Communication_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Communication_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element MemAbstractMdl_Get_BsReten_Communication_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Display_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Display_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element MemAbstractMdl_Get_BsReten_Display_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Gauges_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Gauges_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element MemAbstractMdl_Get_BsReten_Gauges_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Illumination_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element MemAbstractMdl_Get_BsReten_Illumination_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Odometer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Odometer_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element MemAbstractMdl_Get_BsReten_Odometer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Personalization_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Personalization_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element MemAbstractMdl_Get_BsReten_Personalization_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Power_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Power_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element MemAbstractMdl_Get_BsReten_Power_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_RealTimeClock_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element MemAbstractMdl_Get_BsReten_RealTimeClock_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Tripcomputer_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Tripcomputer_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element MemAbstractMdl_Get_BsReten_Tripcomputer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Warning_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsReten_Warning_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element MemAbstractMdl_Get_BsReten_Warning_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_CusDlt_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_CusDlt_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element MemAbstractMdl_Get_BsRt_CusDlt_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_FuelGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_FuelGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element MemAbstractMdl_Get_BsRt_FuelGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Illumination_Element(P2VAR(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Illumination_Element(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element MemAbstractMdl_Get_BsRt_Illumination_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Odometer_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Odometer_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element MemAbstractMdl_Get_BsRt_Odometer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_OilGauge_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element MemAbstractMdl_Get_BsRt_OilGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Personalization_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Personalization_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element MemAbstractMdl_Get_BsRt_Personalization_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_PowerGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_PowerGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element MemAbstractMdl_Get_BsRt_PowerGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_RealTimeClock_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_RealTimeClock_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element MemAbstractMdl_Get_BsRt_RealTimeClock_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_SpeedoGauge_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_SpeedoGauge_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element MemAbstractMdl_Get_BsRt_SpeedoGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TachoGauge_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TachoGauge_Element(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element MemAbstractMdl_Get_BsRt_TachoGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TempGauge_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TempGauge_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element MemAbstractMdl_Get_BsRt_TempGauge_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TripComputer_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_TripComputer_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element MemAbstractMdl_Get_BsRt_TripComputer_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Warning_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsRt_Warning_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element MemAbstractMdl_Get_BsRt_Warning_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate MemAbstractMdl_Get_BsShare_AssemblyManufacturingDate
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_AssemblyPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_AssemblyPlantNumber(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber MemAbstractMdl_Get_BsShare_AssemblyPlantNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(P2VAR(Rte_DT_Arr_u8_61_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(P2VAR(Arr_u8_61, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element MemAbstractMdl_Get_BsShare_EcuPartNumber_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_HWModification(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification MemAbstractMdl_Get_BsShare_HWModification
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_PCBSerialNumber(P2VAR(Rte_DT_Arr_u8_9_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_PCBSerialNumber(P2VAR(Arr_u8_9, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber MemAbstractMdl_Get_BsShare_PCBSerialNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_ProductSerialNumber(P2VAR(Rte_DT_Arr_u8_10_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_ProductSerialNumber(P2VAR(Arr_u8_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber MemAbstractMdl_Get_BsShare_ProductSerialNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SMTManufacturingDate(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SMTManufacturingDate(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate MemAbstractMdl_Get_BsShare_SMTManufacturingDate
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SMTPlantNumber(P2VAR(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SMTPlantNumber(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber MemAbstractMdl_Get_BsShare_SMTPlantNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdReflash_Element(P2VAR(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_SwUpdReflash_Element(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element MemAbstractMdl_Get_BsShare_SwUpdReflash_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VehicleConfig_Element(P2VAR(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VehicleConfig_Element(P2VAR(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element MemAbstractMdl_Get_BsShare_VehicleConfig_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element MemAbstractMdl_Get_BsShare_VisMeet_EOLEntry_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisMeet_Element(P2VAR(Rte_DT_Arr_u8_46_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisMeet_Element(P2VAR(Arr_u8_46, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element MemAbstractMdl_Get_BsShare_VisMeet_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber MemAbstractMdl_Get_BsShare_VisteonPCBPartNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisteonPartNumber(P2VAR(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsShare_VisteonPartNumber(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber MemAbstractMdl_Get_BsShare_VisteonPartNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_RefCys_Certicificate1_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_RefCys_Certicificate1_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element MemAbstractMdl_Get_RefCys_Certicificate1_Element
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_RefCys_Certicificate_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_RefCys_Certicificate_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element MemAbstractMdl_Get_RefCys_Certicificate_Element


# endif /* !defined(RTE_CORE) */


# define CComAbsMdlSafe_START_SEC_CODE
# include "CComAbsMdlSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CComAbsMdlSafe_Impl_OnCommand CComAbsMdlSafe_Impl_OnCommand
#  define RTE_RUNNABLE_CComAbsMdlSafe_Impl_RxCanMdlSafeMainFunction CComAbsMdlSafe_Impl_RxCanMdlSafeMainFunction
#  define RTE_RUNNABLE_CComAbsMdlSafe_Impl_TxCanMdlSafeMainFunction CComAbsMdlSafe_Impl_TxCanMdlSafeMainFunction
#  define RTE_RUNNABLE_CComAbsMdlSafe_RxCan_GetSignalValue CComAbsMdlSafe_RxCan_GetSignalValue
#  define RTE_RUNNABLE_CComAbsMdlSafe_RxCan_GetSignalValueU8Arr CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
#  define RTE_RUNNABLE_CComAbsMdlSafe_RxCan_SetSignalInitValue CComAbsMdlSafe_RxCan_SetSignalInitValue
#  define RTE_RUNNABLE_CComAbsMdlSafe_RxCan_SetSignalInitValueU8Arr CComAbsMdlSafe_RxCan_SetSignalInitValueU8Arr
#  define RTE_RUNNABLE_CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus
#  define RTE_RUNNABLE_CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus
#  define RTE_RUNNABLE_CComAbsMdlSafe_RxCan_SignalInvalidProcessingControl CComAbsMdlSafe_RxCan_SignalInvalidProcessingControl
#  define RTE_RUNNABLE_CComAbsMdlSafe_RxCan_SignalMissingProcessingControl CComAbsMdlSafe_RxCan_SignalMissingProcessingControl
#  define RTE_RUNNABLE_CComAbsMdlSafe_RxCan_SignalNRProcessingControl CComAbsMdlSafe_RxCan_SignalNRProcessingControl
#  define RTE_RUNNABLE_CComAbsMdlSafe_TxCan_ClearCanSignalTxConfirmation CComAbsMdlSafe_TxCan_ClearCanSignalTxConfirmation
#  define RTE_RUNNABLE_CComAbsMdlSafe_TxCan_GetCanSignalTxConfirmation CComAbsMdlSafe_TxCan_GetCanSignalTxConfirmation
#  define RTE_RUNNABLE_CComAbsMdlSafe_TxCan_SetSignalFromRetentionBuffer CComAbsMdlSafe_TxCan_SetSignalFromRetentionBuffer
#  define RTE_RUNNABLE_CComAbsMdlSafe_TxCan_SetSignalValue CComAbsMdlSafe_TxCan_SetSignalValue
#  define RTE_RUNNABLE_CComAbsMdlSafe_TxCan_SetSignalValueU8Arr CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
# endif

FUNC(Std_ReturnType, CComAbsMdlSafe_CODE) CComAbsMdlSafe_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdlSafe_CODE) CComAbsMdlSafe_Impl_RxCanMdlSafeMainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CComAbsMdlSafe_CODE) CComAbsMdlSafe_Impl_TxCanMdlSafeMainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CComAbsMdlSafe_CODE) CComAbsMdlSafe_RxCan_GetSignalValue(tSafeRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalValue, P2VAR(tSafeRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdlSafe_CODE) CComAbsMdlSafe_RxCan_GetSignalValueU8Arr(tSafeRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalValue, P2VAR(tSafeRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalStatus, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdlSafe_CODE) CComAbsMdlSafe_RxCan_SetSignalInitValue(tSafeRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdlSafe_CODE) CComAbsMdlSafe_RxCan_SetSignalInitValueU8Arr(tSafeRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignaValue, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pSignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdlSafe_CODE) CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus(tSafeRxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdlSafe_CODE) CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus(tSafeRxSignalId SignalId, P2VAR(tSafeRxSignalJustRcvdStatus, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pJustRcvdStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdlSafe_CODE) CComAbsMdlSafe_RxCan_SignalInvalidProcessingControl(tSafeRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdlSafe_CODE) CComAbsMdlSafe_RxCan_SignalMissingProcessingControl(tSafeRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdlSafe_CODE) CComAbsMdlSafe_RxCan_SignalNRProcessingControl(tSafeRxSignalId SignalId, Boolean Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdlSafe_CODE) CComAbsMdlSafe_TxCan_ClearCanSignalTxConfirmation(tSafeTxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CComAbsMdlSafe_CODE) CComAbsMdlSafe_TxCan_GetCanSignalTxConfirmation(tSafeTxSignalId SignalId, P2VAR(tTxSigConfirmStatus, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdlSafe_CODE) CComAbsMdlSafe_TxCan_SetSignalFromRetentionBuffer(tSafeTxSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdlSafe_CODE) CComAbsMdlSafe_TxCan_SetSignalValue(tSafeTxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pTxSignalData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CComAbsMdlSafe_CODE) CComAbsMdlSafe_TxCan_SetSignalValueU8Arr(tSafeTxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDLSAFE_APPL_VAR) pTxSignalData, UInt32 SignalLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CComAbsMdlSafe_STOP_SEC_CODE
# include "CComAbsMdlSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_if_CS_ComAbsRxSafe_E_NOT_OK (1U)

#  define RTE_E_if_CS_ComAbsTxSafe_E_NOT_OK (1U)

#  define RTE_E_if_CS_MemAbsGet_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CCOMABSMDLSAFE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
