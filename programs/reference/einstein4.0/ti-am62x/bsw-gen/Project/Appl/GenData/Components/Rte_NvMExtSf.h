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
 *          File:  Rte_NvMExtSf.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <NvMExtSf>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_NVMEXTSF_H
# define _RTE_NVMEXTSF_H

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

# include "Rte_NvMExtSf_Type.h"
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
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element MemAbstractMdl_Get_BsConst_Communication_Element
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
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_Audio_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_Audio_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Audio_Element(arg1) (MemAbstractMdl_Set_BsConst_Audio_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_Communication_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_Communication_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Communication_Element(arg1) (MemAbstractMdl_Set_BsConst_Communication_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_EngOffTimer_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_EngOffTimer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_EngOffTimer_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_EngOffTimer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_EngOffTimer_Element(arg1) (MemAbstractMdl_Set_BsConst_EngOffTimer_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_FuelGauge_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_FuelGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_FuelGauge_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_FuelGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_FuelGauge_Element(arg1) (MemAbstractMdl_Set_BsConst_FuelGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_OilGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_OilGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_OilGauge_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_OilGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_OilGauge_Element(arg1) (MemAbstractMdl_Set_BsConst_OilGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_PowerGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PowerGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_PowerGauge_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_PowerGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PowerGauge_Element(arg1) (MemAbstractMdl_Set_BsConst_PowerGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_Power_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Power_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_Power_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Power_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Power_Element(arg1) (MemAbstractMdl_Set_BsConst_Power_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_RealTimeClock_Element(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_RealTimeClock_Element(arg1) (MemAbstractMdl_Set_BsConst_RealTimeClock_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_ServiceReminder_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_ServiceReminder_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_ServiceReminder_Element(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_ServiceReminder_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_ServiceReminder_Element(arg1) (MemAbstractMdl_Set_BsConst_ServiceReminder_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_SpeedoGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_SpeedoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_SpeedoGauge_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_SpeedoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_SpeedoGauge_Element(arg1) (MemAbstractMdl_Set_BsConst_SpeedoGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_TachoGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TachoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_TachoGauge_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TachoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TachoGauge_Element(arg1) (MemAbstractMdl_Set_BsConst_TachoGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_TempGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TempGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_TempGauge_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TempGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TempGauge_Element(arg1) (MemAbstractMdl_Set_BsConst_TempGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_TripComputer_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TripComputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_TripComputer_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_TripComputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TripComputer_Element(arg1) (MemAbstractMdl_Set_BsConst_TripComputer_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_Warning_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsConst_Warning_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Warning_Element(arg1) (MemAbstractMdl_Set_BsConst_Warning_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsCys_Certicificate_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsCys_Certicificate_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsCys_Certicificate_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsCys_Certicificate_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsCys_Certicificate_Element(arg1) (MemAbstractMdl_Set_BsCys_Certicificate_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsDiag_Dtc_Element(P2CONST(Rte_DT_Arr_u8_2048_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_Dtc_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsDiag_Dtc_Element(P2CONST(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_Dtc_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_Dtc_Element(arg1) (MemAbstractMdl_Set_BsDiag_Dtc_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsDiag_ErrorRecord_Element(P2CONST(Rte_DT_Arr_u8_1024_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_ErrorRecord_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsDiag_ErrorRecord_Element(P2CONST(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsDiag_ErrorRecord_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_ErrorRecord_Element(arg1) (MemAbstractMdl_Set_BsDiag_ErrorRecord_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Audio_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Audio_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Audio_Element(arg1) (MemAbstractMdl_Set_BsReten_Audio_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Communication_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Communication_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Communication_Element(arg1) (MemAbstractMdl_Set_BsReten_Communication_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Display_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Display_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Display_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Display_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Display_Element(arg1) (MemAbstractMdl_Set_BsReten_Display_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Gauges_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Gauges_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Gauges_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Gauges_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Gauges_Element(arg1) (MemAbstractMdl_Set_BsReten_Gauges_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Illumination_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Illumination_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Illumination_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Illumination_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Illumination_Element(arg1) (MemAbstractMdl_Set_BsReten_Illumination_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Odometer_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Odometer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Odometer_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Odometer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Odometer_Element(arg1) (MemAbstractMdl_Set_BsReten_Odometer_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Personalization_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Personalization_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Personalization_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Personalization_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Personalization_Element(arg1) (MemAbstractMdl_Set_BsReten_Personalization_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Power_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Power_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Power_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Power_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Power_Element(arg1) (MemAbstractMdl_Set_BsReten_Power_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_RealTimeClock_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsReten_RealTimeClock_Element(arg1) (MemAbstractMdl_Set_BsReten_RealTimeClock_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Tripcomputer_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Tripcomputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Tripcomputer_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Tripcomputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Tripcomputer_Element(arg1) (MemAbstractMdl_Set_BsReten_Tripcomputer_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Warning_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsReten_Warning_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Warning_Element(arg1) (MemAbstractMdl_Set_BsReten_Warning_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_CusDlt_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_CusDlt_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_CusDlt_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_CusDlt_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_CusDlt_Element(arg1) (MemAbstractMdl_Set_BsRt_CusDlt_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_FuelGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_FuelGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_FuelGauge_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_FuelGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_FuelGauge_Element(arg1) (MemAbstractMdl_Set_BsRt_FuelGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_Illumination_Element(P2CONST(Rte_DT_Arr_u8_100_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Illumination_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_Illumination_Element(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Illumination_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Illumination_Element(arg1) (MemAbstractMdl_Set_BsRt_Illumination_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_Odometer_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Odometer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_Odometer_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Odometer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Odometer_Element(arg1) (MemAbstractMdl_Set_BsRt_Odometer_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_OilGauge_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_OilGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_OilGauge_Element(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_OilGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_OilGauge_Element(arg1) (MemAbstractMdl_Set_BsRt_OilGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_Personalization_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Personalization_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_Personalization_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Personalization_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Personalization_Element(arg1) (MemAbstractMdl_Set_BsRt_Personalization_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_PowerGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_PowerGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_PowerGauge_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_PowerGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_PowerGauge_Element(arg1) (MemAbstractMdl_Set_BsRt_PowerGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_RealTimeClock_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_RealTimeClock_Element(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_RealTimeClock_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_RealTimeClock_Element(arg1) (MemAbstractMdl_Set_BsRt_RealTimeClock_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_SpeedoGauge_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_SpeedoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_SpeedoGauge_Element(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_SpeedoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_SpeedoGauge_Element(arg1) (MemAbstractMdl_Set_BsRt_SpeedoGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_TachoGauge_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TachoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_TachoGauge_Element(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TachoGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TachoGauge_Element(arg1) (MemAbstractMdl_Set_BsRt_TachoGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_TempGauge_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TempGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_TempGauge_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TempGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TempGauge_Element(arg1) (MemAbstractMdl_Set_BsRt_TempGauge_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_TripComputer_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TripComputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_TripComputer_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_TripComputer_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TripComputer_Element(arg1) (MemAbstractMdl_Set_BsRt_TripComputer_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_Warning_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsRt_Warning_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsRt_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Warning_Element(arg1) (MemAbstractMdl_Set_BsRt_Warning_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_AssemblyManufacturingDate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_AssemblyManufacturingDate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyManufacturingDate(arg1) (MemAbstractMdl_Set_BsShare_AssemblyManufacturingDate(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_AssemblyPlantNumber(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_AssemblyPlantNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_AssemblyPlantNumber(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_AssemblyPlantNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyPlantNumber(arg1) (MemAbstractMdl_Set_BsShare_AssemblyPlantNumber(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(P2CONST(Rte_DT_Arr_u8_61_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_EcuPartNumber_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(P2CONST(Arr_u8_61, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_EcuPartNumber_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_EcuPartNumber_Element(arg1) (MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_HWModification(UInt16 BsShare_HWModification); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_HWModification(arg1) (MemAbstractMdl_Set_BsShare_HWModification(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_PCBSerialNumber(P2CONST(Rte_DT_Arr_u8_9_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_PCBSerialNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_PCBSerialNumber(P2CONST(Arr_u8_9, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_PCBSerialNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_PCBSerialNumber(arg1) (MemAbstractMdl_Set_BsShare_PCBSerialNumber(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_ProductSerialNumber(P2CONST(Rte_DT_Arr_u8_10_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_ProductSerialNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_ProductSerialNumber(P2CONST(Arr_u8_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_ProductSerialNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_ProductSerialNumber(arg1) (MemAbstractMdl_Set_BsShare_ProductSerialNumber(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SMTManufacturingDate(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SMTManufacturingDate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SMTManufacturingDate(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SMTManufacturingDate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTManufacturingDate(arg1) (MemAbstractMdl_Set_BsShare_SMTManufacturingDate(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SMTPlantNumber(P2CONST(Rte_DT_Arr_u8_3_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SMTPlantNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SMTPlantNumber(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SMTPlantNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTPlantNumber(arg1) (MemAbstractMdl_Set_BsShare_SMTPlantNumber(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaFinPrint_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaFinPrint_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaFinPrint_Element(arg1) (MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaMode_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaMode_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaMode_Element(arg1) (MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaStatus_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotaStatus_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaStatus_Element(arg1) (MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotadecrypt_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdFotadecrypt_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotadecrypt_Element(arg1) (MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SwUpdReflash_Element(P2CONST(Rte_DT_Arr_u8_8_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdReflash_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_SwUpdReflash_Element(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_SwUpdReflash_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdReflash_Element(arg1) (MemAbstractMdl_Set_BsShare_SwUpdReflash_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_VehicleConfig_Element(P2CONST(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VehicleConfig_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_VehicleConfig_Element(P2CONST(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VehicleConfig_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VehicleConfig_Element(arg1) (MemAbstractMdl_Set_BsShare_VehicleConfig_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_VisMeet_EOLEntry_Element(UInt16 BsShare_VisMeet_EOLEntry_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_EOLEntry_Element(arg1) (MemAbstractMdl_Set_BsShare_VisMeet_EOLEntry_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_VisMeet_Element(P2CONST(Rte_DT_Arr_u8_46_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisMeet_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_VisMeet_Element(P2CONST(Arr_u8_46, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisMeet_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_Element(arg1) (MemAbstractMdl_Set_BsShare_VisMeet_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber(P2CONST(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisteonPCBPartNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber(P2CONST(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisteonPCBPartNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPCBPartNumber(arg1) (MemAbstractMdl_Set_BsShare_VisteonPCBPartNumber(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_VisteonPartNumber(P2CONST(Rte_DT_Arr_u8_17_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisteonPartNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BsShare_VisteonPartNumber(P2CONST(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisteonPartNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPartNumber(arg1) (MemAbstractMdl_Set_BsShare_VisteonPartNumber(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_RefCys_Certicificate1_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate1_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_RefCys_Certicificate1_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate1_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate1_Element(arg1) (MemAbstractMdl_Set_RefCys_Certicificate1_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_RefCys_Certicificate_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_RefCys_Certicificate_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) RefCys_Certicificate_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate_Element(arg1) (MemAbstractMdl_Set_RefCys_Certicificate_Element(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define NvMExtSf_START_SEC_CODE
# include "NvMExtSf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CNvMExtSf_Impl_OnCommand CNvMExtSf_Impl_OnCommand
#  define RTE_RUNNABLE_CNvMExtSf_MainFunction CNvMExtSf_MainFunction
# endif

FUNC(Std_ReturnType, NvMExtSf_CODE) CNvMExtSf_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NvMExtSf_CODE) CNvMExtSf_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define NvMExtSf_STOP_SEC_CODE
# include "NvMExtSf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_if_CS_MemAbsGet_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_NVMEXTSF_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
