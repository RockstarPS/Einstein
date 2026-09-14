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
 *        Config:  BMW.dpa"
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_EcuAppM.h"
#include "TSC_EcuAppM.h"








Std_ReturnType TSC_EcuAppM_Rte_Read_rpSR_SleepStatus_SleepManager_SleepStatus(UInt8 *data)
{
  return Rte_Read_rpSR_SleepStatus_SleepManager_SleepStatus(data);
}








     /* Client Server Interfaces: */
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
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCdd_Impl_OnCommand(cmdP);
}
Std_ReturnType TSC_EcuAppM_Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepManager_Impl_OnCommand(ECmpCmd cmdP)
{
  return Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepManager_Impl_OnCommand(cmdP);
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



