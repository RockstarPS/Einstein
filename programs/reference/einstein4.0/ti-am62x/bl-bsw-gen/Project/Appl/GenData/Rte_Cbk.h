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
 *          File:  Rte_Cbk.h
 *        Config:  BMW.dpa"
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Callback header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CBK_H
# define _RTE_CBK_H

# include "Std_Types.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * NvM-Callback for synchronous copying of the mirror buffer to and from the NvM
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */


# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* _RTE_CBK_H */
