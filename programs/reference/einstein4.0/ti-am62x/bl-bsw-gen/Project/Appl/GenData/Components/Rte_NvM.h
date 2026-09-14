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
 *          File:  Rte_NvM.h
 *        Config:  BMW.dpa"
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <NvM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_NVM_H
# define _RTE_NVM_H

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

# include "Rte_NvM_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Audio_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Communication_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Config_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Display_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Power_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Warning_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFusa_Fota_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_VisDlt_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Audio_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Audio_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Communication_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Communication_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Config_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Config_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Display_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Display_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Power_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Power_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Warning_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Warning_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFusa_Fota_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFusa_Fota_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_VisDlt_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_VisDlt_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1_JobFinished


# endif /* !defined(RTE_CORE) */


# define NvM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_EraseBlock NvM_EraseNvBlock
#  define RTE_RUNNABLE_GetDataIndex NvM_GetDataIndex
#  define RTE_RUNNABLE_GetErrorStatus NvM_GetErrorStatus
#  define RTE_RUNNABLE_InvalidateNvBlock NvM_InvalidateNvBlock
#  define RTE_RUNNABLE_NvM_MainFunction NvM_MainFunction
#  define RTE_RUNNABLE_ReadBlock NvM_ReadBlock
#  define RTE_RUNNABLE_RestoreBlockDefaults NvM_RestoreBlockDefaults
#  define RTE_RUNNABLE_SetBlockProtection NvM_SetBlockProtection
#  define RTE_RUNNABLE_SetDataIndex NvM_SetDataIndex
#  define RTE_RUNNABLE_SetRamBlockStatus NvM_SetRamBlockStatus
#  define RTE_RUNNABLE_WriteBlock NvM_WriteBlock
# endif

FUNC(Std_ReturnType, NvM_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_GetDataIndex(NvM_BlockIdType parg0, P2VAR(uint8, AUTOMATIC, RTE_NVM_APPL_VAR) DataIndex); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(void, NvM_CODE) NvM_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_SetBlockProtection(NvM_BlockIdType parg0, boolean ProtectionEnabled); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_SetDataIndex(NvM_BlockIdType parg0, uint8 DataIndex); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */
FUNC(Std_ReturnType, NvM_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0850, 1330, 3451 */ /* MD_MSR_19.8, MD_Rte_1330, MD_Rte_3451 */

# define NvM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMAdministration_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_NVM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1330:  MISRA rule: 16.4
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
