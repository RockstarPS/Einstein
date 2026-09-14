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
 *          File:  TSC_Ctrl_WSS.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Ctrl_WSS.h"
#include "TSC_Ctrl_WSS.h"















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





Std_ReturnType TSC_Ctrl_WSS_Rte_Receive_rpCS_EcuMExt_FuelLidStatus_FuelLidStatus(BOOL_TYPE *data)
{
  return Rte_Receive_rpCS_EcuMExt_FuelLidStatus_FuelLidStatus(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Receive_rpCS_EcuMExt_HazardStatus_HazardStatus(BOOL_TYPE *data)
{
  return Rte_Receive_rpCS_EcuMExt_HazardStatus_HazardStatus(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Receive_rpUclHMIReadySts_MainHMIReadyStatusData(SMainHMIReadyStatus *data)
{
  return Rte_Receive_rpUclHMIReadySts_MainHMIReadyStatusData(data);
}


Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted(Boolean *data)
{
  return Rte_Read_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted(Boolean *data)
{
  return Rte_Read_rpSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted(Boolean *data)
{
  return Rte_Read_rpSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpTTStsData_TTIndex(TT_ENUM_TYPE *data)
{
  return Rte_Read_rpTTStsData_TTIndex(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpTTStsData_TTStatus(TT_OP_STATES *data)
{
  return Rte_Read_rpTTStsData_TTStatus(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpTelltaleStatusOP_TelltaleOpArray(Rte_DT_TT_OP_Type_0 *data)
{
  return Rte_Read_rpTelltaleStatusOP_TelltaleOpArray(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_BlinkStsArray_TTBlinkStatusArray(Rte_DT_TTBlinkArray_0 *data)
{
  return Rte_Read_rp_BlinkStsArray_TTBlinkStatusArray(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_BlinkStsArray_TTdummyDataForTypes(TTFlashMask *data)
{
  return Rte_Read_rp_BlinkStsArray_TTdummyDataForTypes(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_HMIOdo_Type_HMI_OdoType(HMI_Odo_Type *data)
{
  return Rte_Read_rp_HMIOdo_Type_HMI_OdoType(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(HMI_Screen_Mode *data)
{
  return Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_Head_Lamp_Status_Head_Lamp_st(UInt8 *data)
{
  return Rte_Read_rp_Head_Lamp_Status_Head_Lamp_st(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_IlumDayNightStatus_illumDNStatus(UInt8 *data)
{
  return Rte_Read_rp_IlumDayNightStatus_illumDNStatus(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_Mdl_Pwmout_TC_Dbc_PWMOut_TC_Dbc(UInt8 *data)
{
  return Rte_Read_rp_Mdl_Pwmout_TC_Dbc_PWMOut_TC_Dbc(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_ShiftPositionDisp_ShiftPositionDisplay(UInt8 *data)
{
  return Rte_Read_rp_ShiftPositionDisp_ShiftPositionDisplay(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_Tail_Light_Status_Tail_Light_st(UInt8 *data)
{
  return Rte_Read_rp_Tail_Light_Status_Tail_Light_st(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_TurnHzdTurnL_Status_LeftIndicatorSts(TurnStates *data)
{
  return Rte_Read_rp_TurnHzdTurnL_Status_LeftIndicatorSts(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_TurnHzdTurnR_Status_RightIndicatorSts(TurnStates *data)
{
  return Rte_Read_rp_TurnHzdTurnR_Status_RightIndicatorSts(data);
}




Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppAccModeState_WSSAccState(ModeStatus data)
{
  return Rte_Write_ppAccModeState_WSSAccState(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppBaModeState_WSSBaState(ModeStatus data)
{
  return Rte_Write_ppBaModeState_WSSBaState(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppBaOfModeState_WSSBaOfState(ModeStatus data)
{
  return Rte_Write_ppBaOfModeState_WSSBaOfState(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppIgnModeBuzzer_IgnitioBuznstate(IgntionSubstateType data)
{
  return Rte_Write_ppIgnModeBuzzer_IgnitioBuznstate(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppIgnSubstate_IgnitionSubstate(IgntionSubstateType data)
{
  return Rte_Write_ppIgnSubstate_IgnitionSubstate(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppIgpCANModeState_WSSIGPCANState(ModeStatus data)
{
  return Rte_Write_ppIgpCANModeState_WSSIGPCANState(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppIgpModeState_WSSIGPState(ModeStatus data)
{
  return Rte_Write_ppIgpModeState_WSSIGPState(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_ClusterMode_WSSCurrentClusterMode(ClusterModes data)
{
  return Rte_Write_pp_ClusterMode_WSSCurrentClusterMode(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_HMIReady_HMI_ReadyStatus(HMIReadySts_Type data)
{
  return Rte_Write_pp_HMIReady_HMI_ReadyStatus(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_Init_ClusterMode_WSSCurrentClusterInitMode(ClusterInitModes data)
{
  return Rte_Write_pp_Init_ClusterMode_WSSCurrentClusterInitMode(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_SleepStatus_Sleep_Status(SleepType data)
{
  return Rte_Write_pp_SleepStatus_Sleep_Status(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_TFTDisplayOn_TFTDisplayOn(DisplayStatus data)
{
  return Rte_Write_pp_TFTDisplayOn_TFTDisplayOn(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_TFTDisplayOnExTurn_TFTDisplayOnExTurn(DisplayStatus data)
{
  return Rte_Write_pp_TFTDisplayOnExTurn_TFTDisplayOnExTurn(data);
}

Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_VehicleAppMode_WSSCurrentVehicleState(VehicleActiveModes data)
{
  return Rte_Write_pp_VehicleAppMode_WSSCurrentVehicleState(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_ActivateSilentCommunication(UInt8 Channel)
{
  return Rte_Call_rpComMExt_CAN_ActivateSilentCommunication(Channel);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlActivateRx(UInt8 Channel)
{
  return Rte_Call_rpComMExt_CAN_CommControlActivateRx(Channel);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlActivateTx(UInt8 Channel)
{
  return Rte_Call_rpComMExt_CAN_CommControlActivateTx(Channel);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlDeActivateRx(UInt8 Channel)
{
  return Rte_Call_rpComMExt_CAN_CommControlDeActivateRx(Channel);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlDeActivateTx(UInt8 Channel)
{
  return Rte_Call_rpComMExt_CAN_CommControlDeActivateTx(Channel);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlSetDone(Boolean PduInitRequest)
{
  return Rte_Call_rpComMExt_CAN_CommControlSetDone(PduInitRequest);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel)
{
  return Rte_Call_rpComMExt_CAN_DeActivateSilentCommunication(Channel);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_GetCurrentComMode(UInt8 Channel, UInt8 *ComMode)
{
  return Rte_Call_rpComMExt_CAN_GetCurrentComMode(Channel, ComMode);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_ReleaseCommunication(UInt8 Channel)
{
  return Rte_Call_rpComMExt_CAN_ReleaseCommunication(Channel);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_RequestCommunication(UInt8 Channel)
{
  return Rte_Call_rpComMExt_CAN_RequestCommunication(Channel);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_GetBusOffStatus(UInt8 Channel, Boolean *BusOffStatus)
{
  return Rte_Call_rpComMExt_GetBusOffStatus(Channel, BusOffStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_Get_MCAN_ERR_PIN_Status(Boolean *fl_pin_status_BOOL)
{
  return Rte_Call_rpComMExt_Get_MCAN_ERR_PIN_Status(fl_pin_status_BOOL);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_Init(void)
{
  return Rte_Call_rpComMExt_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(AdcId, AsyncRawAdc, ErrorStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(AdcId, ProcessedAdc, ErrorStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(AdcId, SyncRawAdc, ErrorStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(InputId, AsyncInput, ErrorStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_Din_GetInputGroup(InputId, SyncInput, ErrorStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_Din_GetProcessedInput(InputId, InputSignal, ErrorStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus)
{
  return Rte_Call_rpIoHwAb_Din_GetSyncRawInput(InputId, SyncInput, ErrorStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
{
  return Rte_Call_rp_CS_ComAbsRx_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rp_CS_ComAbsRx_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_ComAbsRx_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_ComAbsRx_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_ComAbsRx_RxCan_SignalNRProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_MemAbs_NvMWriteStatus_NvmWriteStatus(void)
{
  return Rte_Call_rp_CS_MemAbs_NvMWriteStatus_NvmWriteStatus();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus(Boolean *Status)
{
  return Rte_Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus(Status);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_CancelSleep(void)
{
  return Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_CancelSleep();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_ReadytoSleep(void)
{
  return Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_ReadytoSleep();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_RequestSleep(void)
{
  return Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_RequestSleep();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(HTimer hTimer, UInt32 Timeout, Boolean *IsElapsed)
{
  return Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(hTimer, Timeout, IsElapsed);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(HTimer hTimer)
{
  return Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(hTimer);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted(HTimer hTimer, Boolean *IsStarted)
{
  return Rte_Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted(hTimer, IsStarted);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(HTimer hTimer)
{
  return Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(hTimer);
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_CWarnMsg_Core_Observer_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_CWarnMsg_Core_Observer_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Ctrl_Illumination_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_Ctrl_Illumination_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Ctrl_warning_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_Ctrl_warning_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_FastGaugeAdapter_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_FastGaugeAdapter_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Dim_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_Mdl_Dim_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Gear_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_Mdl_Gear_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Linear_Interpolation_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_Mdl_Linear_Interpolation_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Speed_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_Mdl_Speed_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Tacho_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_Mdl_Tacho_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_TurnHazard_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_Mdl_TurnHazard_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_wAirbag_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_Mdl_wAirbag_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_wFuelLidOpen_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_Mdl_wFuelLidOpen_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_SlowGaugeAdapter_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_SlowGaugeAdapter_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_View_Speed_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_View_Speed_Init();
}
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_WarnMsg_Core_TmrSupport_Init(void)
{
  return Rte_Call_rp_Init_rp_Init_WarnMsg_Core_TmrSupport_Init();
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







     /* Ctrl_WSS */
      /* Ctrl_WSS */



