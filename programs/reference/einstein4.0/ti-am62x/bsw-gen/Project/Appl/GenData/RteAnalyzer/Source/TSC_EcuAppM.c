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
 *          File:  TSC_EcuAppM.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_EcuAppM.h"
#include "TSC_EcuAppM.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_EcuAppM_Rte_Call_rpCS_EcumExt_ReleaseRUN_ReleaseRUN(EcuM_UserType user)
{
  return Rte_Call_rpCS_EcumExt_ReleaseRUN_ReleaseRUN(user);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rpCS_EcumExt_RequestRUN_RequestRUN(EcuM_UserType user)
{
  return Rte_Call_rpCS_EcumExt_RequestRUN_RequestRUN(user);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rpCS_RequestPower_EcuPowerM_GetDeviceStatus(UInt8 device, UInt8 *status)
{
  return Rte_Call_rpCS_RequestPower_EcuPowerM_GetDeviceStatus(device, status);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rpCS_RequestPower_EcuPowerM_RequestPower(UInt8 device, UInt8 request)
{
  return Rte_Call_rpCS_RequestPower_EcuPowerM_RequestPower(device, request);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_GetBrightnessValue(EDisplayType DeviceName, UInt16 *BrightnessPercentValue)
{
  return Rte_Call_rp_CS_Backlight_service_GetBrightnessValue(DeviceName, BrightnessPercentValue);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_GetThermalValue(EDisplayType DeviceName, UInt32 *TempValueInMilliCelsius)
{
  return Rte_Call_rp_CS_Backlight_service_GetThermalValue(DeviceName, TempValueInMilliCelsius);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CS_Backlight_service_SetBrightnessValue(EDisplayType DeviceName, UInt16 BrightnessPercentValue)
{
  return Rte_Call_rp_CS_Backlight_service_SetBrightnessValue(DeviceName, BrightnessPercentValue);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus(Boolean *Status)
{
  return Rte_Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus(Status);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_CancelSleep(void)
{
  return Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_CancelSleep();
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_ReadytoSleep(void)
{
  return Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_ReadytoSleep();
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_RequestSleep(void)
{
  return Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_RequestSleep();
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CS_NvmExtStartReadAll_NvMExt_ReadAll(void)
{
  return Rte_Call_rp_CS_NvmExtStartReadAll_NvMExt_ReadAll();
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CS_SleepOperation_CtrlWSS_CancelSleep(void)
{
  return Rte_Call_rp_CS_SleepOperation_CtrlWSS_CancelSleep();
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CS_SleepOperation_CtrlWSS_ReadytoSleep(void)
{
  return Rte_Call_rp_CS_SleepOperation_CtrlWSS_ReadytoSleep();
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CS_SleepOperation_CtrlWSS_RequestSleep(void)
{
  return Rte_Call_rp_CS_SleepOperation_CtrlWSS_RequestSleep();
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCDD_EcuBatteryM_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCDD_EcuBatteryM_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCDD_EcuPowerM_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCDD_EcuPowerM_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CComAbsCtrl_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CComAbsCtrl_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CComAbsMdl_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CComAbsMdl_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CComAbsMdlSafe_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CComAbsMdlSafe_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCtrl_Illumination_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCtrl_Illumination_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCtrl_Telltale_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCtrl_Telltale_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDcmArp_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDcmArp_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDemArp_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDemArp_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDmnMgr_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDmnMgr_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFltM_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFltM_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFltMExt_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFltMExt_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CGdtCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CGdtCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CIoExp_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CIoExp_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CPmicCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CPmicCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CRTCCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CRTCCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CRstM_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CRstM_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeNvM_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeNvM_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSigCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSigCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSndCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSndCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDispMonSf_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDispMonSf_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CUclProxyCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CUclProxyCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CUpdateCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CUpdateCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CView_Illumination_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CView_Illumination_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CView_Telltale_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CView_Telltale_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CWarnMsg_Core_Observer_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CWarnMsg_Core_Observer_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CorTst_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CorTst_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_Ctrl_WSS_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_Ctrl_WSS_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_FlsTst_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_FlsTst_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_MeetCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_MeetCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_MemAbstractMdl_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_MemAbstractMdl_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_RamTst_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_RamTst_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_SysTst_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_SysTst_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_NotifySleepStatus_CtrlWSS_NotifyNetworkSleep(UInt8 *NotifyStatus)
{
  return Rte_Call_rp_NotifySleepStatus_CtrlWSS_NotifyNetworkSleep(NotifyStatus);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* EcuAppM */
      /* EcuAppM */



