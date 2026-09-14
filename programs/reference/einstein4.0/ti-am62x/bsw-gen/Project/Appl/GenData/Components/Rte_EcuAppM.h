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
 *   ECU-Project:  IC
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
#  define RTE_START_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CTRL_WSS_APPL_CODE) CtrlWSS_CancelSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_SleepOperation_CtrlWSS_CancelSleep CtrlWSS_CancelSleep
#  define RTE_START_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CTRL_WSS_APPL_CODE) CtrlWSS_ReadytoSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_SleepOperation_CtrlWSS_ReadytoSleep CtrlWSS_ReadytoSleep
#  define RTE_START_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CTRL_WSS_APPL_CODE) CtrlWSS_RequestSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_SleepOperation_CtrlWSS_RequestSleep CtrlWSS_RequestSleep
#  define RTE_START_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CBACKLIGHTCDD_APPL_CODE) CBacklightCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CBACKLIGHTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand CBacklightCdd_Impl_OnCommand
#  define RTE_START_SEC_CCDD_ECUBATTERYM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCDD_ECUBATTERYM_APPL_CODE) CCDD_EcuBatteryM_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCDD_ECUBATTERYM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCDD_EcuBatteryM_Impl_OnCommand CCDD_EcuBatteryM_Impl_OnCommand
#  define RTE_START_SEC_CCDD_ECUPOWERM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCDD_ECUPOWERM_APPL_CODE) CCDD_EcuPowerM_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCDD_ECUPOWERM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCDD_EcuPowerM_Impl_OnCommand CCDD_EcuPowerM_Impl_OnCommand
#  define RTE_START_SEC_CCOMABSCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSCTRL_APPL_CODE) CComAbsCtrl_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSCTRL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CComAbsCtrl_Impl_OnCommand CComAbsCtrl_Impl_OnCommand
#  define RTE_START_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDL_APPL_CODE) CComAbsMdl_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CComAbsMdl_Impl_OnCommand CComAbsMdl_Impl_OnCommand
#  define RTE_START_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCOMABSMDLSAFE_APPL_CODE) CComAbsMdlSafe_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCOMABSMDLSAFE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CComAbsMdlSafe_Impl_OnCommand CComAbsMdlSafe_Impl_OnCommand
#  define RTE_START_SEC_CTRL_ILLUMINATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CTRL_ILLUMINATION_APPL_CODE) CCtrl_Illumination_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_ILLUMINATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCtrl_Illumination_Impl_OnCommand CCtrl_Illumination_Impl_OnCommand
#  define RTE_START_SEC_CCTRL_TELLTALE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CCTRL_TELLTALE_APPL_CODE) CCtrl_Telltale_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CCTRL_TELLTALE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCtrl_Telltale_Impl_OnCommand CCtrl_Telltale_Impl_OnCommand
#  define RTE_START_SEC_DCMAPP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DCMAPP_APPL_CODE) CDcmApp_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCMAPP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDcmArp_Impl_OnCommand CDcmApp_Impl_OnCommand
#  define RTE_START_SEC_DEMAPP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMAPP_APPL_CODE) CDemApp_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMAPP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDemArp_Impl_OnCommand CDemApp_Impl_OnCommand
#  define RTE_START_SEC_CDISPLAYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CDISPLAYCDD_APPL_CODE) CDisplayCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDISPLAYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand CDisplayCdd_Impl_OnCommand
#  define RTE_START_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DMNMGR_APPL_CODE) CDmnMgr_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDmnMgr_Impl_OnCommand CDmnMgr_Impl_OnCommand
#  define RTE_START_SEC_CFLTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CFLTM_APPL_CODE) CFltM_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CFLTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFltM_Impl_OnCommand CFltM_Impl_OnCommand
#  define RTE_START_SEC_CFLTMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CFLTMEXT_APPL_CODE) CFltMExt_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CFLTMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFltMExt_Impl_OnCommand CFltMExt_Impl_OnCommand
#  define RTE_START_SEC_GDTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_GDTCDD_APPL_CODE) CGdtCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_GDTCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CGdtCdd_Impl_OnCommand CGdtCdd_Impl_OnCommand
#  define RTE_START_SEC_CIOEXP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CIOEXP_APPL_CODE) CIoExp_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CIOEXP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CIoExp_Impl_OnCommand CIoExp_Impl_OnCommand
#  define RTE_START_SEC_CPMICCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CPMICCDD_APPL_CODE) CPmicCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CPMICCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CPmicCdd_Impl_OnCommand CPmicCdd_Impl_OnCommand
#  define RTE_START_SEC_RTCCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_RTCCDD_APPL_CODE) CRtcCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_RTCCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CRTCCdd_Impl_OnCommand CRtcCdd_Impl_OnCommand
#  define RTE_START_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CRSTM_APPL_CODE) CRstM_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CRstM_Impl_OnCommand CRstM_Impl_OnCommand
#  define RTE_START_SEC_SAFENVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_SAFENVM_APPL_CODE) CSafeNvM_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_SAFENVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeNvM_Impl_OnCommand CSafeNvM_Impl_OnCommand
#  define RTE_START_SEC_CSIGCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CSIGCDD_APPL_CODE) CSigCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CSIGCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSigCdd_Impl_OnCommand CSigCdd_Impl_OnCommand
#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSndCdd_Impl_OnCommand CSafeNvM_Impl_OnCommand
#  define RTE_START_SEC_CSWCDISPMONSF_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CSWCDISPMONSF_APPL_CODE) CSwcDispMonSf_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CSWCDISPMONSF_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDispMonSf_Impl_OnCommand CSwcDispMonSf_Impl_OnCommand
#  define RTE_START_SEC_UCLPROXYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_UCLPROXYCDD_APPL_CODE) CUclProxyCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_UCLPROXYCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CUclProxyCdd_Impl_OnCommand CUclProxyCdd_Impl_OnCommand
#  define RTE_START_SEC_CUPDATECDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CUPDATECDD_APPL_CODE) CUpdateCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CUPDATECDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CUpdateCdd_Impl_OnCommand CUpdateCdd_Impl_OnCommand
#  define RTE_START_SEC_VIEW_ILLUMINATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_VIEW_ILLUMINATION_APPL_CODE) CView_Illumination_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_VIEW_ILLUMINATION_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CView_Illumination_Impl_OnCommand CView_Illumination_Impl_OnCommand
#  define RTE_START_SEC_CVIEW_TELLTALE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CVIEW_TELLTALE_APPL_CODE) CView_Telltale_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CVIEW_TELLTALE_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CView_Telltale_Impl_OnCommand CView_Telltale_Impl_OnCommand
#  define RTE_START_SEC_CWARNMSG_CORE_OBSERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CWARNMSG_CORE_OBSERVER_APPL_CODE) CWarnMsg_Core_Observer_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CWARNMSG_CORE_OBSERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CWarnMsg_Core_Observer_Impl_OnCommand CWarnMsg_Core_Observer_Impl_OnCommand
#  define RTE_START_SEC_CORTST_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CORTST_APPL_CODE) CorTst_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CORTST_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CorTst_Impl_OnCommand CorTst_Impl_OnCommand
#  define RTE_START_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CTRL_WSS_APPL_CODE) Ctrl_WSS_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_Ctrl_WSS_Impl_OnCommand Ctrl_WSS_Impl_OnCommand
#  define RTE_START_SEC_FLSTST_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_FLSTST_APPL_CODE) FlsTst_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_FLSTST_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_FlsTst_Impl_OnCommand FlsTst_Impl_OnCommand
#  define RTE_START_SEC_CMEETCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CMEETCDD_APPL_CODE) CMeetCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CMEETCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_MeetCdd_Impl_OnCommand CMeetCdd_Impl_OnCommand
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) CMemAbstractMdl_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_MemAbstractMdl_Impl_OnCommand CMemAbstractMdl_Impl_OnCommand
#  define RTE_START_SEC_RAMTST_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_RAMTST_APPL_CODE) RamTst_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_RAMTST_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_RamTst_Impl_OnCommand RamTst_Impl_OnCommand
#  define RTE_START_SEC_SYSTST_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_SYSTST_APPL_CODE) SysTst_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_SYSTST_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_SysTst_Impl_OnCommand SysTst_Impl_OnCommand
#  define RTE_START_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CTRL_WSS_APPL_CODE) Ctrl_WSS_CtrlWSS_NotifyNetworkSleep(P2VAR(UInt8, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) NotifyStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTRL_WSS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_NotifySleepStatus_CtrlWSS_NotifyNetworkSleep Ctrl_WSS_CtrlWSS_NotifyNetworkSleep


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

#  define RTE_E_TI_WSS_SWCNotifySleepStatus_E_NOT_OK (1U)

#  define RTE_E_TI_WSS_SleepOperations_E_NOT_OK (1U)

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
