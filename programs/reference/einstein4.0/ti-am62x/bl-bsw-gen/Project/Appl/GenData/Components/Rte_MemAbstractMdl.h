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
 *        Config:  BMW.dpa"
 *   ECU-Project:  EcuInstance
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
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Power_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element (0U)
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
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element (0U)
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
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element (0U)
#  define Rte_InitValue_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Illumination_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Power_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Audio_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Communication_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Config_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Display_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Power_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFuSa_Warning_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsFusa_Fota_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Display_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Power_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_VisDlt_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element
#  define Rte_Write_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define MemAbstractMdl_START_SEC_CODE
# include "MemAbstractMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Audio_Element MemAbstractMdl_Get_BsConst_Audio_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Communication_Element MemAbstractMdl_Get_BsConst_Communication_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_EngOffTimer_Element MemAbstractMdl_Get_BsConst_EngOffTimer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_FuelGauge_Element MemAbstractMdl_Get_BsConst_FuelGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Illumination_Element MemAbstractMdl_Get_BsConst_Illumination_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_OilGauge_Element MemAbstractMdl_Get_BsConst_OilGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_PowerGauge_Element MemAbstractMdl_Get_BsConst_PowerGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Power_Element MemAbstractMdl_Get_BsConst_Power_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_RealTimeClock_Element MemAbstractMdl_Get_BsConst_RealTimeClock_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_ServiceReminder_Element MemAbstractMdl_Get_BsConst_ServiceReminder_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_SpeedoGauge_Element MemAbstractMdl_Get_BsConst_SpeedoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_TachoGauge_Element MemAbstractMdl_Get_BsConst_TachoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_TempGauge_Element MemAbstractMdl_Get_BsConst_TempGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_TripComputer_Element MemAbstractMdl_Get_BsConst_TripComputer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsConst_Warning_Element MemAbstractMdl_Get_BsConst_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsCys_Certicificate_Element MemAbstractMdl_Get_BsCys_Certicificate_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsDiag_Dtc_Element MemAbstractMdl_Get_BsDiag_Dtc_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsDiag_ErrorRecord_Element MemAbstractMdl_Get_BsDiag_ErrorRecord_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsFuSa_Audio_Element MemAbstractMdl_Get_BsFuSa_Audio_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsFuSa_Communication_Element MemAbstractMdl_Get_BsFuSa_Communication_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsFuSa_Config_Element MemAbstractMdl_Get_BsFuSa_Config_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsFuSa_Display_Element MemAbstractMdl_Get_BsFuSa_Display_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsFuSa_Power_Element MemAbstractMdl_Get_BsFuSa_Power_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsFuSa_Warning_Element MemAbstractMdl_Get_BsFuSa_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsFusa_Fota_Element MemAbstractMdl_Get_BsFusa_Fota_Element
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
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsReten_VisDlt_Element MemAbstractMdl_Get_BsReten_VisDlt_Element
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
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_EcuPartNumber_Element MemAbstractMdl_Get_BsShare_EcuPartNumber_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element MemAbstractMdl_Get_BsShare_SwUpdFotaFinPrint_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element MemAbstractMdl_Get_BsShare_SwUpdFotaMode_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element MemAbstractMdl_Get_BsShare_SwUpdFotaStatus_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element MemAbstractMdl_Get_BsShare_SwUpdFotadecrypt_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_SwUpdReflash_Element MemAbstractMdl_Get_BsShare_SwUpdReflash_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_VehicleConfig_Element MemAbstractMdl_Get_BsShare_VehicleConfig_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_BsShare_VisMeet_Element MemAbstractMdl_Get_BsShare_VisMeet_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_RefCys_Certicificate1_Element MemAbstractMdl_Get_RefCys_Certicificate1_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Get_RefCys_Certicificate_Element MemAbstractMdl_Get_RefCys_Certicificate_Element
#  define RTE_RUNNABLE_MemAbstractMdl_MainFunction MemAbstractMdl_MainFunction
#  define RTE_RUNNABLE_MemAbstractMdl_NvmWriteStatus MemAbstractMdl_NvmWriteStatus
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Audio_Element MemAbstractMdl_Set_BsConst_Audio_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Communication_Element MemAbstractMdl_Set_BsConst_Communication_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_EngOffTimer_Element MemAbstractMdl_Set_BsConst_EngOffTimer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_FuelGauge_Element MemAbstractMdl_Set_BsConst_FuelGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Illumination_Element MemAbstractMdl_Set_BsConst_Illumination_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_OilGauge_Element MemAbstractMdl_Set_BsConst_OilGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_PowerGauge_Element MemAbstractMdl_Set_BsConst_PowerGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Power_Element MemAbstractMdl_Set_BsConst_Power_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_RealTimeClock_Element MemAbstractMdl_Set_BsConst_RealTimeClock_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_ServiceReminder_Element MemAbstractMdl_Set_BsConst_ServiceReminder_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_SpeedoGauge_Element MemAbstractMdl_Set_BsConst_SpeedoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_TachoGauge_Element MemAbstractMdl_Set_BsConst_TachoGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_TempGauge_Element MemAbstractMdl_Set_BsConst_TempGauge_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_TripComputer_Element MemAbstractMdl_Set_BsConst_TripComputer_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsConst_Warning_Element MemAbstractMdl_Set_BsConst_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsCys_Certicificate_Element MemAbstractMdl_Set_BsCys_Certicificate_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsDiag_Dtc_Element MemAbstractMdl_Set_BsDiag_Dtc_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsDiag_ErrorRecord_Element MemAbstractMdl_Set_BsDiag_ErrorRecord_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsFuSa_Audio_Element MemAbstractMdl_Set_BsFuSa_Audio_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsFuSa_Communication_Element MemAbstractMdl_Set_BsFuSa_Communication_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsFuSa_Config_Element MemAbstractMdl_Set_BsFuSa_Config_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsFuSa_Display_Element MemAbstractMdl_Set_BsFuSa_Display_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsFuSa_Power_Element MemAbstractMdl_Set_BsFuSa_Power_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsFuSa_Warning_Element MemAbstractMdl_Set_BsFuSa_Warning_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsFusa_Fota_Element MemAbstractMdl_Set_BsFusa_Fota_Element
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
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsReten_VisDlt_Element MemAbstractMdl_Set_BsReten_VisDlt_Element
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
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_EcuPartNumber_Element MemAbstractMdl_Set_BsShare_EcuPartNumber_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element MemAbstractMdl_Set_BsShare_SwUpdFotaFinPrint_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element MemAbstractMdl_Set_BsShare_SwUpdFotaMode_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element MemAbstractMdl_Set_BsShare_SwUpdFotaStatus_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element MemAbstractMdl_Set_BsShare_SwUpdFotadecrypt_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_SwUpdReflash_Element MemAbstractMdl_Set_BsShare_SwUpdReflash_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_VehicleConfig_Element MemAbstractMdl_Set_BsShare_VehicleConfig_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_BsShare_VisMeet_Element MemAbstractMdl_Set_BsShare_VisMeet_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_RefCys_Certicificate1_Element MemAbstractMdl_Set_RefCys_Certicificate1_Element
#  define RTE_RUNNABLE_MemAbstractMdl_Set_RefCys_Certicificate_Element MemAbstractMdl_Set_RefCys_Certicificate_Element
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Audio_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Audio_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Communication_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
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
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Illumination_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_Illumination_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_OilGauge_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsConst_OilGauge_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
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
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Audio_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Audio_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Communication_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Communication_Element(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Config_Element(P2VAR(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Config_Element(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Display_Element(P2VAR(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Display_Element(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Power_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Power_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Warning_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFuSa_Warning_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFusa_Fota_Element(P2VAR(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsFusa_Fota_Element(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
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
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_VisDlt_Element(P2VAR(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsReten_VisDlt_Element(P2VAR(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
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
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(P2VAR(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_EcuPartNumber_Element(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
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
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisMeet_Element(P2VAR(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_Get_BsShare_VisMeet_Element(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
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
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, MemAbstractMdl_CODE) MemAbstractMdl_NvmWriteStatus(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Audio_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Audio_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Communication_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Communication_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
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
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Illumination_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Illumination_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_Illumination_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_Illumination_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_OilGauge_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_OilGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsConst_OilGauge_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsConst_OilGauge_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
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
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Audio_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Audio_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Audio_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Communication_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Communication_Element(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Communication_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Config_Element(P2CONST(Rte_DT_Arr_u8_16_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Config_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Config_Element(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Config_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Display_Element(P2CONST(Rte_DT_Arr_u8_64_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Display_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Display_Element(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Display_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Power_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Power_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Power_Element(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Power_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Warning_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFuSa_Warning_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFuSa_Warning_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFusa_Fota_Element(P2CONST(Rte_DT_Arr_u8_32_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFusa_Fota_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsFusa_Fota_Element(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsFusa_Fota_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
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
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_VisDlt_Element(P2CONST(Rte_DT_Arr_u8_256_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_VisDlt_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsReten_VisDlt_Element(P2CONST(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsReten_VisDlt_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
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
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(P2CONST(Rte_DT_Arr_u8_128_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_EcuPartNumber_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_EcuPartNumber_Element(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_EcuPartNumber_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
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
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisMeet_Element(P2CONST(Rte_DT_Arr_u8_48_0, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisMeet_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, MemAbstractMdl_CODE) MemAbstractMdl_Set_BsShare_VisMeet_Element(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BsShare_VisMeet_Element); /* PRQA S 0850 */ /* MD_MSR_19.8 */
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

#  define RTE_E_if_CS_MemAbs_NvMWriteStatus_E_NOT_OK (1U)
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
