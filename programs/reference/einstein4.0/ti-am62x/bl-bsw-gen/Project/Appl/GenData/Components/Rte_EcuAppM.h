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
 *          File:  Rte_EcuAppM.h
 *        Config:  BMW.dpa
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <EcuAppM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_ECUAPPM_H
# define _RTE_ECUAPPM_H

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

# include "Rte_EcuAppM_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_INIT) Rte_CSleepManager_ppSR_SleepStatus_SleepManager_SleepStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_rpSR_SleepStatus_SleepManager_SleepStatus (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpSR_SleepStatus_SleepManager_SleepStatus Rte_Read_EcuAppM_rpSR_SleepStatus_SleepManager_SleepStatus
#  define Rte_Read_EcuAppM_rpSR_SleepStatus_SleepManager_SleepStatus(data) (*(data) = Rte_CSleepManager_ppSR_SleepStatus_SleepManager_SleepStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ECUMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_ECUMEXT_APPL_CODE) EcuMExt_ReleaseRUN(EcuM_UserType user); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_ECUMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_EcumExt_ReleaseRUN_ReleaseRUN EcuMExt_ReleaseRUN
#  define RTE_START_SEC_ECUMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_ECUMEXT_APPL_CODE) EcuMExt_RequestRUN(EcuM_UserType user); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_ECUMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_EcumExt_RequestRUN_RequestRUN EcuMExt_RequestRUN
#  define RTE_START_SEC_CCDD_ECUPOWERM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCDD_ECUPOWERM_APPL_CODE) EcuPowerM_GetDeviceStatus(UInt8 device, P2VAR(UInt8, AUTOMATIC, RTE_CCDD_ECUPOWERM_APPL_VAR) status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCDD_ECUPOWERM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_RequestPower_EcuPowerM_GetDeviceStatus EcuPowerM_GetDeviceStatus
#  define RTE_START_SEC_CCDD_ECUPOWERM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCDD_ECUPOWERM_APPL_CODE) EcuPowerM_RequestPower(UInt8 device, UInt8 request); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCDD_ECUPOWERM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpCS_RequestPower_EcuPowerM_RequestPower EcuPowerM_RequestPower
#  define RTE_START_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CBACKLIGHTCDD_APPL_CODE) CBacklightCdd_GetBrightnessValue(EDisplayType DeviceName, P2VAR(UInt16, AUTOMATIC, RTE_CBACKLIGHTCDD_APPL_VAR) BrightnessPercentValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_Backlight_service_GetBrightnessValue CBacklightCdd_GetBrightnessValue
#  define RTE_START_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CBACKLIGHTCDD_APPL_CODE) CBacklightCdd_GetThermalValue(EDisplayType DeviceName, P2VAR(UInt32, AUTOMATIC, RTE_CBACKLIGHTCDD_APPL_VAR) TempValueInMilliCelsius); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_Backlight_service_GetThermalValue CBacklightCdd_GetThermalValue
#  define RTE_START_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CBACKLIGHTCDD_APPL_CODE) CBacklightCdd_SetBrightnessValue(EDisplayType DeviceName, UInt16 BrightnessPercentValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_Backlight_service_SetBrightnessValue CBacklightCdd_SetBrightnessValue
#  define RTE_START_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_NVMEXT_APPL_CODE) NvmExt_GetNvMReadAllStatus(P2VAR(Boolean, AUTOMATIC, RTE_NVMEXT_APPL_VAR) Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus(arg1) (NvmExt_GetNvMReadAllStatus(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMEXT_APPL_CODE) NvMExt_CancelSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_CancelSleep NvMExt_CancelSleep
#  define RTE_START_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMEXT_APPL_CODE) NvMExt_ReadytoSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_ReadytoSleep NvMExt_ReadytoSleep
#  define RTE_START_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMEXT_APPL_CODE) NvMExt_RequestSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_RequestSleep NvMExt_RequestSleep
#  define RTE_START_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_NVMEXT_APPL_CODE) NvMExt_ReadAll(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_NvmExtStartReadAll_NvMExt_ReadAll() (NvMExt_ReadAll(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CBACKLIGHTCDD_APPL_CODE) CBacklightCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand CBacklightCdd_Impl_OnCommand
#  define RTE_START_SEC_CBATTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CBATTMDL_APPL_CODE) CBattMdl_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CBATTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBattMdl_Impl_OnCommand CBattMdl_Impl_OnCommand
#  define RTE_START_SEC_CCDD_ECUPOWERM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCDD_ECUPOWERM_APPL_CODE) CCDD_EcuPowerM_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCDD_ECUPOWERM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCDD_EcuPowerM_Impl_OnCommand CCDD_EcuPowerM_Impl_OnCommand
#  define RTE_START_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DMNMGR_APPL_CODE) CDmnMgr_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand CDmnMgr_Impl_OnCommand
#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDmnMgr_Impl_OnCommand CDmnMgr_Impl_OnCommand
#  define RTE_START_SEC_RTCCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_RTCCDD_APPL_CODE) pp_CmpLibCmd_CRTCCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_RTCCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CRTCCdd_Impl_OnCommand pp_CmpLibCmd_CRTCCdd_Impl_OnCommand
#  define RTE_START_SEC_CSLEEPMANAGER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CSLEEPMANAGER_APPL_CODE) CSleepManager_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CSLEEPMANAGER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepManager_Impl_OnCommand CSleepManager_Impl_OnCommand
#  define RTE_START_SEC_CDISPLAYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CDISPLAYCDD_APPL_CODE) CDisplayCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDISPLAYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSndCdd_Impl_OnCommand CDisplayCdd_Impl_OnCommand
#  define RTE_START_SEC_UCLPROXYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_UCLPROXYCDD_APPL_CODE) CUclProxyCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_UCLPROXYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CUclProxyCdd_Impl_OnCommand CUclProxyCdd_Impl_OnCommand


# endif /* !defined(RTE_CORE) */


# define EcuAppM_START_SEC_CODE
# include "EcuAppM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_EcuAppM_Init EcuAppM_Init
#  define RTE_RUNNABLE_EcuAppM_MainFunction EcuAppM_MainFunction
#  define RTE_RUNNABLE_EcuAppM_SetWakeupSources EcuAppM_SetWakeupSources
# endif

FUNC(void, EcuAppM_CODE) EcuAppM_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, EcuAppM_CODE) EcuAppM_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, EcuAppM_CODE) EcuAppM_SetWakeupSources(UInt32 WakeupSource); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define EcuAppM_STOP_SEC_CODE
# include "EcuAppM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_Backlight_Service_E_NOT_OK (1U)

#  define RTE_E_TI_EcuMExt_ReleaseRUN_E_NOT_OK (1U)

#  define RTE_E_TI_EcuMExt_RequestRUN_E_NOT_OK (1U)

#  define RTE_E_TI_EcuPowerM_E_NOT_OK (1U)

#  define RTE_E_TI_NvMExt_SleepOperations_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_ECUAPPM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
