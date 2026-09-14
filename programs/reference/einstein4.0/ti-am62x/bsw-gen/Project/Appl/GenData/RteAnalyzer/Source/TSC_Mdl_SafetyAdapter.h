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
 *          File:  TSC_Mdl_SafetyAdapter.h
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
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxAB_AB(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxABS_MID_ABS_MID(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxBHEXIST_BHEXIST(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxBRK_MID_BRK_MID(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_ABS_B_ABS(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_ALSD_B_ALSD(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BRKW_B_BRKW(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BRKW2_B_BRKW2(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BRLV_B_BRLV(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BRLV2_B_BRLV2(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BUZZE2_B_BUZZE2(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_BUZZER_B_BUZZER(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_CPKB_B_CPKB(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_DACIND_B_DACIND(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_DAINDC_B_DAINDC(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_DAINDP_B_DAINDP(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_EBW_B_EBW(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_EBW2_B_EBW2(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_EPBMID_B_EPBMID(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_EPBWL_B_EPBWL(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxB_PKBLP_B_PKBLP(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxDBKLAB_DBKLAB(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxEBW_MID_EBW_MID(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxECBEXIST_ECBEXIST(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxMCBW_MCBW(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxPBKLAB_PBKLAB(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxPWIINFO_PWIINFO(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxSCSACCEL_SCSACCEL(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxSCSBZR_SCSBZR(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxSLP_WL_SLP_WL(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxTRCCONFL_TRCCONFL(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxTRCCONFR_TRCCONFR(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxTRCCONRL_TRCCONRL(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxTRCCONRR_TRCCONRR(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxTRCOFF_TRCOFF(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxVSCEXIST_VSCEXIST(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_SR_RxVSCOFF_VSCOFF(UInt8 *data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Read_rp_ctrlwss_Clustermode_WSSCurrentClusterMode(ClusterModes *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Write_pp_SafetyAdapter_Appmode_SafetyAdapter_AppMode(VehicleActiveModes data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Write_pp_SafetyAdapter_Clustermode_SafetyAdapter_CurrentClusterMode(UInt8 data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Write_pp_SafetyAdapter_Ign_Substate_SafetyAdapter_Ign_Substate(IgntionSubstateType data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Write_pp_SafetyAdapter_Voltage_SafetyAdapter_HVSD1(UInt8 data);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Write_pp_SafetyAdapter_Voltage_SafetyAdapter_LVSD1(UInt8 data);

/** Client server interfaces */
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_ActivateSilentCommunication(UInt8 Channel);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_CommControlActivateRx(UInt8 Channel);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_CommControlActivateTx(UInt8 Channel);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_CommControlDeActivateRx(UInt8 Channel);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_CommControlDeActivateTx(UInt8 Channel);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_CommControlSetDone(Boolean PduInitRequest);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_GetCurrentComMode(UInt8 Channel, UInt8 *ComMode);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_ReleaseCommunication(UInt8 Channel);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_CAN_RequestCommunication(UInt8 Channel);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_GetBusOffStatus(UInt8 Channel, Boolean *BusOffStatus);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_Get_MCAN_ERR_PIN_Status(Boolean *fl_pin_status_BOOL);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rpComMExt_Init(void);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rp_IOHWab_Din_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rp_IOHWab_Din_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rp_IOHWab_Din_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rp_IOHWab_Din_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rp_Init_rp_Init_CCtrl_Telltale_Init(void);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rp_Init_rp_Init_CView_Telltale_Init(void);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rp_Init_rp_Init_Mdl_Airbag_Init(void);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rp_IoHwAb_ADC_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *AsyncRawAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rp_IoHwAb_ADC_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, SInt32 *ProcessedAdc, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Mdl_SafetyAdapter_Rte_Call_rp_IoHwAb_ADC_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, UInt16 *SyncRawAdc, IoHwAb_ErrorType *ErrorStatus);




