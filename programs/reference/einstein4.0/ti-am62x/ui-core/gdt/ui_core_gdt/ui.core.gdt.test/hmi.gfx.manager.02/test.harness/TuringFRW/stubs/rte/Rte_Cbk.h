/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Cbk.h
 *        Config:  Turing.dpa
 *   ECU-Project:  TuringECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Callback header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CBK_H
# define _RTE_CBK_H

# include "Com.h"

# ifndef RTE_COM_VERSION
#  define RTE_COM_VERSION 40U
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * COM Callbacks for Rx Indication
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_DimGeneral_0e65ef90(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_DownTranOfEngCoolantTempCAN_46dad878(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_EngineCoolantTempCAN_46dad878(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_NewRollingOdo_9d7d00df(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_SG_RxFilteredSpeed_a536058e(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_SpeedRef_a9ab8ab7(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_TachoRef_3db35f78(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_COMCbk_WarningWaterTempCAN_46dad878(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 * COM Callbacks for Rx Timeout Notification
 *********************************************************************************************************************/

# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DimGeneral_0e65ef90(uint8 error); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DimGeneral_0e65ef90(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DownTranOfEngCoolantTempCAN_46dad878(uint8 error); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DownTranOfEngCoolantTempCAN_46dad878(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EngineCoolantTempCAN_46dad878(uint8 error); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EngineCoolantTempCAN_46dad878(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_SpeedRef_a9ab8ab7(uint8 error); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_SpeedRef_a9ab8ab7(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_TachoRef_3db35f78(uint8 error); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_TachoRef_3db35f78(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# if RTE_COM_VERSION == 21U
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_WarningWaterTempCAN_46dad878(uint8 error); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_WarningWaterTempCAN_46dad878(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 * NvM-Callback for synchronous copying of the mirror buffer to and from the NvM
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_Rte_3112 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_Rte_3112 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_EOLData(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_Rte_3112 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_EOLData(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_Rte_3112 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_EctConfiguration(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_Rte_3112 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_EctConfiguration(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_Rte_3112 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_Interpolations(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_Rte_3112 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_Interpolations(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_Rte_3112 */

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_Odometer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_Rte_3112 */
FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_Odometer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer); /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_Rte_3112 */


/**********************************************************************************************************************
 * RTE Schedulable entity for COM-Access from different partitions
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_ComSendSignalProxyPeriodic(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* _RTE_CBK_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3112:  MISRA rule: 14.2
     Reason:     The structures of macros are specified in the RTE specification [rte_sws_1236].
     Risk:       No functional risk.
     Prevention: Not required.

*/
