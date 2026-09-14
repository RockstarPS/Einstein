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
 *          File:  TSC_CDisplayCdd.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CDisplayCdd.h"
#include "TSC_CDisplayCdd.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */






Std_ReturnType TSC_CDisplayCdd_Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData(SDisplayCurrentState *data)
{
  return Rte_Read_rpSRDisplayCurrentState_DisplayCurrentStateData(data);
}




Std_ReturnType TSC_CDisplayCdd_Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData(const SDisplaySetPower *data)
{
  return Rte_Write_ppSRDisplaySetPower_DisplaySetPowerData(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CDisplayCdd_Rte_Call_rpIoHwAb_SetDout_SetOutputGroup(IoHwAb_DOutGroupIdType InputId, UInt32 OutputGroup, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_SetDout_SetOutputGroup(InputId, OutputGroup, ErrorStatus);
}
Std_ReturnType TSC_CDisplayCdd_Rte_Call_rpIoHwAb_SetDout_SetOutputPin(IoHwAb_DOutSignalIdType InputId, Boolean OutputSignal, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_SetDout_SetOutputPin(InputId, OutputSignal, ErrorStatus);
}
Std_ReturnType TSC_CDisplayCdd_Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState(EDisplayType DeviceId, EDisplayPowerState CompletedPowerState)
{
  return Rte_Call_rp_CS_Backlight_Notify_NotifyDisplayPowerState(DeviceId, CompletedPowerState);
}
Std_ReturnType TSC_CDisplayCdd_Rte_Call_rp_CS_Backlight_Status_GetStatus(EDisplayType DeviceName, EDeviceStatus *DeviceStatus)
{
  return Rte_Call_rp_CS_Backlight_Status_GetStatus(DeviceName, DeviceStatus);
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













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* CDisplayCdd */
      /* CDisplayCdd */



