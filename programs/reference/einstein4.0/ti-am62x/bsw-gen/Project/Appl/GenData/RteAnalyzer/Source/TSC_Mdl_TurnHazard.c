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
 *          File:  TSC_Mdl_TurnHazard.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Mdl_TurnHazard.h"
#include "TSC_Mdl_TurnHazard.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */






Std_ReturnType TSC_Mdl_TurnHazard_Rte_Read_rpCS_ChimeRequest_Chime_Request(EChimeID *data)
{
  return Rte_Read_rpCS_ChimeRequest_Chime_Request(data);
}

Std_ReturnType TSC_Mdl_TurnHazard_Rte_Read_rpCS_ChimeVolume_UpdateChimeVolume(UInt8 *data)
{
  return Rte_Read_rpCS_ChimeVolume_UpdateChimeVolume(data);
}

Std_ReturnType TSC_Mdl_TurnHazard_Rte_Read_rpCS_NvmFlashCustBzr_Nvmdata(UInt8 *data)
{
  return Rte_Read_rpCS_NvmFlashCustBzr_Nvmdata(data);
}

Std_ReturnType TSC_Mdl_TurnHazard_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
{
  return Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(data);
}




Std_ReturnType TSC_Mdl_TurnHazard_Rte_Write_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(TT_OP_STATES data)
{
  return Rte_Write_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(data);
}

Std_ReturnType TSC_Mdl_TurnHazard_Rte_Write_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(TT_OP_STATES data)
{
  return Rte_Write_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(data);
}

Std_ReturnType TSC_Mdl_TurnHazard_Rte_Write_pp_TurnHazard_TurnL_Sts_LeftIndicatorSts(TurnStates data)
{
  return Rte_Write_pp_TurnHazard_TurnL_Sts_LeftIndicatorSts(data);
}

Std_ReturnType TSC_Mdl_TurnHazard_Rte_Write_pp_TurnHazard_TurnR_Sts_RightIndicatorSts(TurnStates data)
{
  return Rte_Write_pp_TurnHazard_TurnR_Sts_RightIndicatorSts(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rpCS_IoHwAbInp_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpCS_IoHwAbInp_GetAsyncRawInput(InputId, AsyncInput, ErrorStatus);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rpCS_IoHwAbInp_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpCS_IoHwAbInp_GetInputGroup(InputId, SyncInput, ErrorStatus);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rpCS_IoHwAbInp_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpCS_IoHwAbInp_GetProcessedInput(InputId, InputSignal, ErrorStatus);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rpCS_IoHwAbInp_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpCS_IoHwAbInp_GetSyncRawInput(InputId, SyncInput, ErrorStatus);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(SignalId, Status);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* Mdl_TurnHazard */
      /* Mdl_TurnHazard */



