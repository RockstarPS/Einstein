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
 *          File:  TSC_CComAbsCtrl.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CComAbsCtrl.h"
#include "TSC_CComAbsCtrl.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_ActivateSilentCommunication(UInt8 Channel)
{
  return Rte_Call_rpCSComMExt_CAN_ActivateSilentCommunication(Channel);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_CommControlActivateRx(UInt8 Channel)
{
  return Rte_Call_rpCSComMExt_CAN_CommControlActivateRx(Channel);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_CommControlActivateTx(UInt8 Channel)
{
  return Rte_Call_rpCSComMExt_CAN_CommControlActivateTx(Channel);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_CommControlDeActivateRx(UInt8 Channel)
{
  return Rte_Call_rpCSComMExt_CAN_CommControlDeActivateRx(Channel);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_CommControlDeActivateTx(UInt8 Channel)
{
  return Rte_Call_rpCSComMExt_CAN_CommControlDeActivateTx(Channel);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_CommControlSetDone(Boolean PduInitRequest)
{
  return Rte_Call_rpCSComMExt_CAN_CommControlSetDone(PduInitRequest);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel)
{
  return Rte_Call_rpCSComMExt_CAN_DeActivateSilentCommunication(Channel);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_GetCurrentComMode(UInt8 Channel, UInt8 *ComMode)
{
  return Rte_Call_rpCSComMExt_CAN_GetCurrentComMode(Channel, ComMode);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_ReleaseCommunication(UInt8 Channel)
{
  return Rte_Call_rpCSComMExt_CAN_ReleaseCommunication(Channel);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_CAN_RequestCommunication(UInt8 Channel)
{
  return Rte_Call_rpCSComMExt_CAN_RequestCommunication(Channel);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_GetBusOffStatus(UInt8 Channel, Boolean *BusOffStatus)
{
  return Rte_Call_rpCSComMExt_GetBusOffStatus(Channel, BusOffStatus);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_Get_MCAN_ERR_PIN_Status(Boolean *fl_pin_status_BOOL)
{
  return Rte_Call_rpCSComMExt_Get_MCAN_ERR_PIN_Status(fl_pin_status_BOOL);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSComMExt_Init(void)
{
  return Rte_Call_rpCSComMExt_Init();
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rpCSRxCanMdl_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rpCSRxCanMdl_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
{
  return Rte_Call_rpCSRxCanMdl_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rpCSRxCanMdl_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rpCSRxCanMdl_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rpCSRxCanMdl_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rpCSRxCanMdl_RxCan_SignalNRProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSTxCanMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId)
{
  return Rte_Call_rpCSTxCanMdl_TxCan_ClearCanSignalTxConfirmation(SignalId);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSTxCanMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, tTxSigConfirmStatus *pStatus)
{
  return Rte_Call_rpCSTxCanMdl_TxCan_GetCanSignalTxConfirmation(SignalId, pStatus);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSTxCanMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId)
{
  return Rte_Call_rpCSTxCanMdl_TxCan_SetSignalFromRetentionBuffer(SignalId);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(tTxSignalId SignalId, UInt8 *pTxSignalData)
{
  return Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValue(SignalId, pTxSignalData);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, UInt8 *pTxSignalData, UInt32 SignalLength)
{
  return Rte_Call_rpCSTxCanMdl_TxCan_SetSignalValueU8Arr(SignalId, pTxSignalData, SignalLength);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rpCS_RxCanMdlSafe_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rpCS_RxCanMdlSafe_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalClearJustRcvdStatus(tSafeRxSignalId SignalId)
{
  return Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalGetJustRcvdStatus(tSafeRxSignalId SignalId, tSafeRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalInvalidProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalMissingProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalNRProcessingControl(tSafeRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rpCS_RxCanMdlSafe_RxCan_SignalNRProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_TxCanMdlSafe_TxCan_ClearCanSignalTxConfirmation(tSafeTxSignalId SignalId)
{
  return Rte_Call_rpCS_TxCanMdlSafe_TxCan_ClearCanSignalTxConfirmation(SignalId);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_TxCanMdlSafe_TxCan_GetCanSignalTxConfirmation(tSafeTxSignalId SignalId, tTxSigConfirmStatus *pStatus)
{
  return Rte_Call_rpCS_TxCanMdlSafe_TxCan_GetCanSignalTxConfirmation(SignalId, pStatus);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalFromRetentionBuffer(tSafeTxSignalId SignalId)
{
  return Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalFromRetentionBuffer(SignalId);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValue(tSafeTxSignalId SignalId, UInt8 *pTxSignalData)
{
  return Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValue(SignalId, pTxSignalData);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValueU8Arr(tSafeTxSignalId SignalId, UInt8 *pTxSignalData, UInt32 SignalLength)
{
  return Rte_Call_rpCS_TxCanMdlSafe_TxCan_SetSignalValueU8Arr(SignalId, pTxSignalData, SignalLength);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rp_CS_IoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rp_CS_IoHwAb_Din_GetAsyncRawInput(InputId, AsyncInput, ErrorStatus);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rp_CS_IoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rp_CS_IoHwAb_Din_GetInputGroup(InputId, SyncInput, ErrorStatus);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rp_CS_IoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rp_CS_IoHwAb_Din_GetProcessedInput(InputId, InputSignal, ErrorStatus);
}
Std_ReturnType TSC_CComAbsCtrl_Rte_Call_rp_CS_IoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rp_CS_IoHwAb_Din_GetSyncRawInput(InputId, SyncInput, ErrorStatus);
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







     /* CComAbsCtrl */
      /* CComAbsCtrl */



