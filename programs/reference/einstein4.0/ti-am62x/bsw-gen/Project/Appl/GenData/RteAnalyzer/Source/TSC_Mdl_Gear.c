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
 *          File:  TSC_Mdl_Gear.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Mdl_Gear.h"
#include "TSC_Mdl_Gear.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */






Std_ReturnType TSC_Mdl_Gear_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
{
  return Rte_Read_rpIgnSubstate_IgnitionSubstate(data);
}

Std_ReturnType TSC_Mdl_Gear_Rte_Read_rpVehicleAppMode_WSSCurrentVehicleState(VehicleActiveModes *data)
{
  return Rte_Read_rpVehicleAppMode_WSSCurrentVehicleState(data);
}

Std_ReturnType TSC_Mdl_Gear_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
{
  return Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(data);
}

Std_ReturnType TSC_Mdl_Gear_Rte_Read_rp_HMI_Ready_Status_HMI_ReadyStatus(HMIReadySts_Type *data)
{
  return Rte_Read_rp_HMI_Ready_Status_HMI_ReadyStatus(data);
}

Std_ReturnType TSC_Mdl_Gear_Rte_Read_rp_PowerTrainState_PowerTrain_Flag(UInt8 *data)
{
  return Rte_Read_rp_PowerTrainState_PowerTrain_Flag(data);
}

Std_ReturnType TSC_Mdl_Gear_Rte_Read_rp_TT_PRND_blink_TIUpdateIndicatorStatus(UInt8 *data)
{
  return Rte_Read_rp_TT_PRND_blink_TIUpdateIndicatorStatus(data);
}




Std_ReturnType TSC_Mdl_Gear_Rte_Write_pp_ShiftPositionDisplay_ShiftPositionDisplay(UInt8 data)
{
  return Rte_Write_pp_ShiftPositionDisplay_ShiftPositionDisplay(data);
}

Std_ReturnType TSC_Mdl_Gear_Rte_Write_pp_Shift_ModeInd_ShiftModeIndicator(ShiftPositionInd data)
{
  return Rte_Write_pp_Shift_ModeInd_ShiftModeIndicator(data);
}

Std_ReturnType TSC_Mdl_Gear_Rte_Write_pp_Shift_Position_ShiftPosition(ShiftPosition data)
{
  return Rte_Write_pp_Shift_Position_ShiftPosition(data);
}

Std_ReturnType TSC_Mdl_Gear_Rte_Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData(const SShiftPosIndStatus *data)
{
  return Rte_Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData(data);
}

Std_ReturnType TSC_Mdl_Gear_Rte_Write_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data(const ShiftposData_Type *data)
{
  return Rte_Write_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(UInt8 VariantID, UInt8 *VariantActiveSt)
{
  return Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(VariantID, VariantActiveSt);
}
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_Variant_Status_GetVariant_Status(UInt8 Variant_Ind, UInt8 *Variant_Status)
{
  return Rte_Call_rp_Variant_Status_GetVariant_Status(Variant_Ind, Variant_Status);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* Mdl_Gear */
      /* Mdl_Gear */



