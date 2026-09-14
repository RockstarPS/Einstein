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
 *          File:  TSC_Mdl_wFuelLidOpen.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Mdl_wFuelLidOpen.h"
#include "TSC_Mdl_wFuelLidOpen.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */






Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
{
  return Rte_Read_rpIgnSubstate_IgnitionSubstate(data);
}

Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
{
  return Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(data);
}








     /* Client Server Interfaces: */
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rpUpdateFuelLidOpenWarning_UpdateWarningStatus(WarningId WarningCurId, WarningStatus WarningCurStatus, WarningEvent WarningCurEvent, UInt32 WarningPayload)
{
  return Rte_Call_rpUpdateFuelLidOpenWarning_UpdateWarningStatus(WarningCurId, WarningCurStatus, WarningCurEvent, WarningPayload);
}
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
{
  return Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalNRProcessingControl(SignalId, Status);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* Mdl_wFuelLidOpen */
      /* Mdl_wFuelLidOpen */



