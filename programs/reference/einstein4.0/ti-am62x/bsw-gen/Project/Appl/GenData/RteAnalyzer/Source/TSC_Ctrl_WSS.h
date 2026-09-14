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
 *          File:  TSC_Ctrl_WSS.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted(Boolean *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted(Boolean *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted(Boolean *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpTTStsData_TTIndex(TT_ENUM_TYPE *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpTTStsData_TTStatus(TT_OP_STATES *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rpTelltaleStatusOP_TelltaleOpArray(Rte_DT_TT_OP_Type_0 *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_BlinkStsArray_TTBlinkStatusArray(Rte_DT_TTBlinkArray_0 *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_BlinkStsArray_TTdummyDataForTypes(TTFlashMask *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_HMIOdo_Type_HMI_OdoType(HMI_Odo_Type *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(HMI_Screen_Mode *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_Head_Lamp_Status_Head_Lamp_st(UInt8 *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_IlumDayNightStatus_illumDNStatus(UInt8 *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_Mdl_Pwmout_TC_Dbc_PWMOut_TC_Dbc(UInt8 *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_ShiftPositionDisp_ShiftPositionDisplay(UInt8 *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_Tail_Light_Status_Tail_Light_st(UInt8 *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_TurnHzdTurnL_Status_LeftIndicatorSts(TurnStates *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Read_rp_TurnHzdTurnR_Status_RightIndicatorSts(TurnStates *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppAccModeState_WSSAccState(ModeStatus data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppBaModeState_WSSBaState(ModeStatus data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppBaOfModeState_WSSBaOfState(ModeStatus data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppIgnModeBuzzer_IgnitioBuznstate(IgntionSubstateType data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppIgnSubstate_IgnitionSubstate(IgntionSubstateType data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppIgpCANModeState_WSSIGPCANState(ModeStatus data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_ppIgpModeState_WSSIGPState(ModeStatus data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_ClusterMode_WSSCurrentClusterMode(ClusterModes data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_HMIReady_HMI_ReadyStatus(HMIReadySts_Type data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_Init_ClusterMode_WSSCurrentClusterInitMode(ClusterInitModes data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_SleepStatus_Sleep_Status(SleepType data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_TFTDisplayOn_TFTDisplayOn(DisplayStatus data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_TFTDisplayOnExTurn_TFTDisplayOnExTurn(DisplayStatus data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Write_pp_VehicleAppMode_WSSCurrentVehicleState(VehicleActiveModes data);

/** Sender receiver - Queued - Explicit read */
Std_ReturnType TSC_Ctrl_WSS_Rte_Receive_rpCS_EcuMExt_FuelLidStatus_FuelLidStatus(BOOL_TYPE *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Receive_rpCS_EcuMExt_HazardStatus_HazardStatus(BOOL_TYPE *data);
Std_ReturnType TSC_Ctrl_WSS_Rte_Receive_rpUclHMIReadySts_MainHMIReadyStatusData(SMainHMIReadyStatus *data);

/** Client server interfaces */
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_ActivateSilentCommunication(UInt8 Channel);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlActivateRx(UInt8 Channel);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlActivateTx(UInt8 Channel);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlDeActivateRx(UInt8 Channel);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlDeActivateTx(UInt8 Channel);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_CommControlSetDone(Boolean PduInitRequest);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_GetCurrentComMode(UInt8 Channel, UInt8 *ComMode);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_ReleaseCommunication(UInt8 Channel);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_CAN_RequestCommunication(UInt8 Channel);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_GetBusOffStatus(UInt8 Channel, Boolean *BusOffStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_Get_MCAN_ERR_PIN_Status(Boolean *fl_pin_status_BOOL);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpComMExt_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rpIoHwAb_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_ComAbsRx_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_MemAbs_NvMWriteStatus_NvmWriteStatus(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_GetNvMExtReadAllStatus_NvmExt_GetNvMReadAllStatus(Boolean *Status);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_CancelSleep(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_ReadytoSleep(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_NvMExt_SleepOperations_NvMExt_RequestSleep(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(HTimer hTimer, UInt32 Timeout, Boolean *IsElapsed);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(HTimer hTimer);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted(HTimer hTimer, Boolean *IsStarted);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(HTimer hTimer);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_CWarnMsg_Core_Observer_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Ctrl_Illumination_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Ctrl_warning_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_FastGaugeAdapter_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Dim_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Gear_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Linear_Interpolation_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Speed_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_Tacho_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_TurnHazard_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_wAirbag_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_Mdl_wFuelLidOpen_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_SlowGaugeAdapter_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_View_Speed_Init(void);
Std_ReturnType TSC_Ctrl_WSS_Rte_Call_rp_Init_rp_Init_WarnMsg_Core_TmrSupport_Init(void);




