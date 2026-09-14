/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Hook.h
 *        Config:  Turing.dpa
 *   ECU-Project:  TuringECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Header file containing definitions for VFB tracing
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Names of available VFB-Trace-Hooks
 **********************************************************************************************************************
 *
 *  Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Return
 *  Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Start
 *  Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Return
 *  Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Start
 *  Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Return
 *  Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Start
 *  Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Return
 *  Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Start
 *  Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Return
 *  Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Start
 *  Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Return
 *  Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Start
 *  Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Return
 *  Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Start
 *  Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Return
 *  Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Start
 *  Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Return
 *  Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Start
 *  Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Return
 *  Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Start
 *  Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Return
 *  Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Start
 *  Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Return
 *  Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Start
 *  Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Return
 *  Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Start
 *  Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Return
 *  Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Start
 *  Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Return
 *  Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Start
 *  Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Return
 *  Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Start
 *  Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Return
 *  Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Start
 *  Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Return
 *  Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Start
 *  Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Return
 *  Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Start
 *  Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Return
 *  Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Start
 *  Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Return
 *  Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Start
 *  Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Return
 *  Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Start
 *  Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Return
 *  Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Start
 *  Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Return
 *  Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Start
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Return
 *  Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Start
 *  Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Return
 *  Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Start
 *  Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Return
 *  Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Start
 *  Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Return
 *  Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Start
 *  Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Return
 *  Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Start
 *  Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Return
 *  Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Start
 *  Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Return
 *  Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Start
 *  Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Return
 *  Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Start
 *  Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Return
 *  Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Start
 *  Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Return
 *  Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Start
 *  Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Return
 *  Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Start
 *  Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Return
 *  Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Start
 *  Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Return
 *  Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Start
 *  Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return
 *  Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start
 *  Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return
 *  Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start
 *  Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Return
 *  Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Start
 *  Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return
 *  Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start
 *  Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return
 *  Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start
 *  Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Return
 *  Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Start
 *  Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Return
 *  Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Start
 *  Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Return
 *  Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Start
 *  Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Return
 *  Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Start
 *  Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Return
 *  Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Start
 *  Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Return
 *  Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Start
 *  Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Return
 *  Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Start
 *  Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Return
 *  Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Start
 *  Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Return
 *  Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Start
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Return
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Start
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Return
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Start
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Return
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Start
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Return
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Start
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Return
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Start
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Return
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Start
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Return
 *  Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Start
 *  Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Return
 *  Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Start
 *  Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Return
 *  Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Start
 *  Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Return
 *  Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Start
 *  Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Return
 *  Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Start
 *  Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Return
 *  Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Start
 *  Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return
 *  Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start
 *  Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return
 *  Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start
 *  Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return
 *  Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start
 *  Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return
 *  Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start
 *  Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Return
 *  Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Start
 *  Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Return
 *  Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Start
 *  Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Return
 *  Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Start
 *  Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Return
 *  Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Start
 *  Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Return
 *  Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Start
 *  Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Return
 *  Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Start
 *  Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Return
 *  Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Start
 *  Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Return
 *  Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Start
 *  Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return
 *  Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start
 *  Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return
 *  Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start
 *  Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return
 *  Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start
 *  Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return
 *  Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start
 *  Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Return
 *  Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Start
 *  Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Return
 *  Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Start
 *  Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Return
 *  Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Start
 *  Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Return
 *  Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Start
 *  Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Return
 *  Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Start
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Return
 *  Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Start
 *  Rte_ComHookRxTOut_DimGeneral_0e65ef90
 *  Rte_ComHookRxTOut_DownTranOfEngCoolantTempCAN_46dad878
 *  Rte_ComHookRxTOut_EngineCoolantTempCAN_46dad878
 *  Rte_ComHookRxTOut_SpeedRef_a9ab8ab7
 *  Rte_ComHookRxTOut_TachoRef_3db35f78
 *  Rte_ComHookRxTOut_WarningWaterTempCAN_46dad878
 *  Rte_ComHookRx_DimGeneral_0e65ef90
 *  Rte_ComHookRx_DownTranOfEngCoolantTempCAN_46dad878
 *  Rte_ComHookRx_EngineCoolantTempCAN_46dad878
 *  Rte_ComHookRx_NewRollingOdo_9d7d00df
 *  Rte_ComHookRx_SG_RxFilteredSpeed_a536058e
 *  Rte_ComHookRx_SpeedRef_a9ab8ab7
 *  Rte_ComHookRx_TachoRef_3db35f78
 *  Rte_ComHookRx_WarningWaterTempCAN_46dad878
 *  Rte_ComHook_BrkLamp_B_Rq_610999c4_SigRx
 *  Rte_ComHook_BtnCES_Down_c0440b7e_SigRx
 *  Rte_ComHook_BtnCES_Left_c0440b7e_SigRx
 *  Rte_ComHook_BtnCES_OK_c0440b7e_SigRx
 *  Rte_ComHook_BtnCES_Right_c0440b7e_SigRx
 *  Rte_ComHook_BtnCES_Up_c0440b7e_SigRx
 *  Rte_ComHook_Button_1_c0440b7e_SigRx
 *  Rte_ComHook_Button_2_c0440b7e_SigRx
 *  Rte_ComHook_Button_3_c0440b7e_SigRx
 *  Rte_ComHook_Button_4_c0440b7e_SigRx
 *  Rte_ComHook_Button_5_c0440b7e_SigRx
 *  Rte_ComHook_DimGeneral_0e65ef90_SigRx
 *  Rte_ComHook_Disable_Neutral_Tow_610999c4_SigRx
 *  Rte_ComHook_DownTranOfEngCoolantTempCAN_46dad878_SigRx
 *  Rte_ComHook_DrStatDrv_B_Actl_610999c4_SigRx
 *  Rte_ComHook_DrStatPsngr_B_Actl_610999c4_SigRx
 *  Rte_ComHook_E2E_RxFilteredSpeedSft_cb1e8587_SigRx
 *  Rte_ComHook_E2E_Rx_CRC_cb1e8587_SigRx
 *  Rte_ComHook_E2E_Rx_SeqNumber_cb1e8587_SigRx
 *  Rte_ComHook_E2E_TxFilteredSpeedSft_701521af_SigTx
 *  Rte_ComHook_E2E_Tx_CRC_701521af_SigTx
 *  Rte_ComHook_E2E_Tx_SeqNumber_701521af_SigTx
 *  Rte_ComHook_Enable_Neutral_Tow_610999c4_SigRx
 *  Rte_ComHook_EngineCoolantTempCAN_46dad878_SigRx
 *  Rte_ComHook_FUEL_LEVEL_CAN_24f27db7_SigRx
 *  Rte_ComHook_KeyPos_70b9e74d_SigRx
 *  Rte_ComHook_LeftTurnOn_365ba238_SigRx
 *  Rte_ComHook_MyKey_Active_610999c4_SigRx
 *  Rte_ComHook_NewRollingOdo_9d7d00df_SigRx
 *  Rte_ComHook_RightTurnOn_365ba238_SigRx
 *  Rte_ComHook_Slow_For_HDC_610999c4_SigRx
 *  Rte_ComHook_SpeedFiltered_15b15a3c_SigTx
 *  Rte_ComHook_SpeedRef_a9ab8ab7_SigRx
 *  Rte_ComHook_TachoFiltered_15b15a3c_SigTx
 *  Rte_ComHook_TachoRef_3db35f78_SigRx
 *  Rte_ComHook_Tire_Press_System_Stat_610999c4_SigRx
 *  Rte_ComHook_WarningWaterTempCAN_46dad878_SigRx
 *  Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Return
 *  Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Start
 *  Rte_FeedbackHook_EcuM_currentMode_currentMode_Return
 *  Rte_FeedbackHook_EcuM_currentMode_currentMode_Start
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Return
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Start
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Return
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Start
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Return
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Start
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Return
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Start
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Return
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Start
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Return
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Start
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Return
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Start
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Return
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Start
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Return
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Start
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Return
 *  Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Start
 *  Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Return
 *  Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Start
 *  Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Return
 *  Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Start
 *  Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Return
 *  Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Start
 *  Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Return
 *  Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Start
 *  Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return
 *  Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start
 *  Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return
 *  Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start
 *  Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return
 *  Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start
 *  Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Return
 *  Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Start
 *  Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Return
 *  Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Start
 *  Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Return
 *  Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Start
 *  Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Return
 *  Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Start
 *  Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Return
 *  Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Start
 *  Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Return
 *  Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Start
 *  Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Return
 *  Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Start
 *  Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Return
 *  Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Start
 *  Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Return
 *  Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Start
 *  Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Return
 *  Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Start
 *  Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Return
 *  Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Start
 *  Rte_ReadHook_EcumExt_NV_Language_Value_Return
 *  Rte_ReadHook_EcumExt_NV_Language_Value_Start
 *  Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Return
 *  Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Start
 *  Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Return
 *  Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Start
 *  Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Return
 *  Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Start
 *  Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Return
 *  Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Start
 *  Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Return
 *  Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Start
 *  Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Return
 *  Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Start
 *  Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Return
 *  Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Start
 *  Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Return
 *  Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Start
 *  Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Return
 *  Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Start
 *  Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Return
 *  Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Start
 *  Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Return
 *  Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Start
 *  Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Return
 *  Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Start
 *  Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Return
 *  Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Start
 *  Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Return
 *  Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Start
 *  Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Return
 *  Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Start
 *  Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Return
 *  Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Start
 *  Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Return
 *  Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Start
 *  Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return
 *  Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start
 *  Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Return
 *  Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Start
 *  Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return
 *  Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start
 *  Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Return
 *  Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Start
 *  Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return
 *  Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start
 *  Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Return
 *  Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Start
 *  Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Return
 *  Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Start
 *  Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Return
 *  Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Start
 *  Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Return
 *  Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Start
 *  Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Return
 *  Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Start
 *  Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Return
 *  Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Start
 *  Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Return
 *  Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Start
 *  Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Return
 *  Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Start
 *  Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Return
 *  Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Start
 *  Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Return
 *  Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Start
 *  Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Return
 *  Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Start
 *  Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Return
 *  Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Start
 *  Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Return
 *  Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Start
 *  Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Start
 *  Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Return
 *  Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Start
 *  Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Return
 *  Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Start
 *  Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Return
 *  Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Start
 *  Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Return
 *  Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Start
 *  Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Return
 *  Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Start
 *  Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Return
 *  Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Start
 *  Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Return
 *  Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Start
 *  Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Return
 *  Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Start
 *  Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Return
 *  Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Start
 *  Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Return
 *  Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Start
 *  Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Return
 *  Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Start
 *  Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Return
 *  Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Start
 *  Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Return
 *  Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Start
 *  Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return
 *  Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start
 *  Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Return
 *  Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Start
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Return
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Start
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Return
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Start
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Return
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Start
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Return
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Start
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Return
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Start
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Return
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Start
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Return
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Start
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Return
 *  Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Start
 *  Rte_Runnable_BswM_BswM_MainFunction_Return
 *  Rte_Runnable_BswM_BswM_MainFunction_Start
 *  Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Return
 *  Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Start
 *  Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Return
 *  Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Start
 *  Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Return
 *  Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Start
 *  Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Return
 *  Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Start
 *  Rte_Runnable_ComM_ComM_MainFunction_0_Return
 *  Rte_Runnable_ComM_ComM_MainFunction_0_Start
 *  Rte_Runnable_ComM_GetCurrentComMode_Return
 *  Rte_Runnable_ComM_GetCurrentComMode_Start
 *  Rte_Runnable_ComM_GetInhibitionStatus_Return
 *  Rte_Runnable_ComM_GetInhibitionStatus_Start
 *  Rte_Runnable_ComM_GetMaxComMode_Return
 *  Rte_Runnable_ComM_GetMaxComMode_Start
 *  Rte_Runnable_ComM_GetRequestedComMode_Return
 *  Rte_Runnable_ComM_GetRequestedComMode_Start
 *  Rte_Runnable_ComM_LimitChannelToNoComMode_Return
 *  Rte_Runnable_ComM_LimitChannelToNoComMode_Start
 *  Rte_Runnable_ComM_LimitECUToNoComMode_Return
 *  Rte_Runnable_ComM_LimitECUToNoComMode_Start
 *  Rte_Runnable_ComM_PreventWakeUp_Return
 *  Rte_Runnable_ComM_PreventWakeUp_Start
 *  Rte_Runnable_ComM_ReadInhibitCounter_Return
 *  Rte_Runnable_ComM_ReadInhibitCounter_Start
 *  Rte_Runnable_ComM_RequestComMode_Return
 *  Rte_Runnable_ComM_RequestComMode_Start
 *  Rte_Runnable_ComM_ResetInhibitCounter_Return
 *  Rte_Runnable_ComM_ResetInhibitCounter_Start
 *  Rte_Runnable_ComM_SetECUGroupClassification_Return
 *  Rte_Runnable_ComM_SetECUGroupClassification_Start
 *  Rte_Runnable_DcmExt_dummy_Return
 *  Rte_Runnable_DcmExt_dummy_Start
 *  Rte_Runnable_Dcm_Dcm_MainFunction_Return
 *  Rte_Runnable_Dcm_Dcm_MainFunction_Start
 *  Rte_Runnable_Dcm_GetActiveProtocol_Return
 *  Rte_Runnable_Dcm_GetActiveProtocol_Start
 *  Rte_Runnable_Dcm_GetSecurityLevel_Return
 *  Rte_Runnable_Dcm_GetSecurityLevel_Start
 *  Rte_Runnable_Dcm_GetSesCtrlType_Return
 *  Rte_Runnable_Dcm_GetSesCtrlType_Start
 *  Rte_Runnable_Dcm_ResetToDefaultSession_Return
 *  Rte_Runnable_Dcm_ResetToDefaultSession_Start
 *  Rte_Runnable_Dem_ClearDTC_Return
 *  Rte_Runnable_Dem_ClearDTC_Start
 *  Rte_Runnable_Dem_DcmClearDTC_Return
 *  Rte_Runnable_Dem_DcmClearDTC_Start
 *  Rte_Runnable_Dem_DcmEnableDTCSetting_Return
 *  Rte_Runnable_Dem_DcmEnableDTCSetting_Start
 *  Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Return
 *  Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Start
 *  Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Return
 *  Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Start
 *  Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Return
 *  Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Start
 *  Rte_Runnable_Dem_Dem_MainFunction_Return
 *  Rte_Runnable_Dem_Dem_MainFunction_Start
 *  Rte_Runnable_Dem_GetDTCOfEvent_Return
 *  Rte_Runnable_Dem_GetDTCOfEvent_Start
 *  Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Return
 *  Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Start
 *  Rte_Runnable_Dem_GetDebouncingOfEvent_Return
 *  Rte_Runnable_Dem_GetDebouncingOfEvent_Start
 *  Rte_Runnable_Dem_GetEventEnableCondition_Return
 *  Rte_Runnable_Dem_GetEventEnableCondition_Start
 *  Rte_Runnable_Dem_GetEventExtendedDataRecord_Return
 *  Rte_Runnable_Dem_GetEventExtendedDataRecord_Start
 *  Rte_Runnable_Dem_GetEventFailed_Return
 *  Rte_Runnable_Dem_GetEventFailed_Start
 *  Rte_Runnable_Dem_GetEventFreezeFrameData_Return
 *  Rte_Runnable_Dem_GetEventFreezeFrameData_Start
 *  Rte_Runnable_Dem_GetEventMemoryOverflow_Return
 *  Rte_Runnable_Dem_GetEventMemoryOverflow_Start
 *  Rte_Runnable_Dem_GetEventStatus_Return
 *  Rte_Runnable_Dem_GetEventStatus_Start
 *  Rte_Runnable_Dem_GetEventTested_Return
 *  Rte_Runnable_Dem_GetEventTested_Start
 *  Rte_Runnable_Dem_GetFaultDetectionCounter_Return
 *  Rte_Runnable_Dem_GetFaultDetectionCounter_Start
 *  Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Return
 *  Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Start
 *  Rte_Runnable_Dem_PostRunRequested_Return
 *  Rte_Runnable_Dem_PostRunRequested_Start
 *  Rte_Runnable_Dem_ResetEventDebounceStatus_Return
 *  Rte_Runnable_Dem_ResetEventDebounceStatus_Start
 *  Rte_Runnable_Dem_ResetEventStatus_Return
 *  Rte_Runnable_Dem_ResetEventStatus_Start
 *  Rte_Runnable_Dem_SetEventStatus_Return
 *  Rte_Runnable_Dem_SetEventStatus_Start
 *  Rte_Runnable_Dem_SetOperationCycleState_Return
 *  Rte_Runnable_Dem_SetOperationCycleState_Start
 *  Rte_Runnable_Det_ReportError_Return
 *  Rte_Runnable_Det_ReportError_Start
 *  Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Return
 *  Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Start
 *  Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Return
 *  Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Start
 *  Rte_Runnable_DimView_CDimView_Impl_MainFunction_Return
 *  Rte_Runnable_DimView_CDimView_Impl_MainFunction_Start
 *  Rte_Runnable_DimView_CDimView_Impl_OnCommand_Return
 *  Rte_Runnable_DimView_CDimView_Impl_OnCommand_Start
 *  Rte_Runnable_DimView_DimView_Impl_DiagAction_Return
 *  Rte_Runnable_DimView_DimView_Impl_DiagAction_Start
 *  Rte_Runnable_DltExt_DltExt_Main_Return
 *  Rte_Runnable_DltExt_DltExt_Main_Start
 *  Rte_Runnable_Dlt_Dlt_MainFunction_Return
 *  Rte_Runnable_Dlt_Dlt_MainFunction_Start
 *  Rte_Runnable_Dlt_SendLogMessage_Return
 *  Rte_Runnable_Dlt_SendLogMessage_Start
 *  Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Return
 *  Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Start
 *  Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Return
 *  Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Start
 *  Rte_Runnable_EctMdl_Runnable_swcECT_Init_Return
 *  Rte_Runnable_EctMdl_Runnable_swcECT_Init_Start
 *  Rte_Runnable_EctMdl_Runnable_swcECT_Step_Return
 *  Rte_Runnable_EctMdl_Runnable_swcECT_Step_Start
 *  Rte_Runnable_EcuM_EcuM_MainFunction_Return
 *  Rte_Runnable_EcuM_EcuM_MainFunction_Start
 *  Rte_Runnable_EcuM_GetBootTarget_Return
 *  Rte_Runnable_EcuM_GetBootTarget_Start
 *  Rte_Runnable_EcuM_GetLastShutdownTarget_Return
 *  Rte_Runnable_EcuM_GetLastShutdownTarget_Start
 *  Rte_Runnable_EcuM_GetShutdownCause_Return
 *  Rte_Runnable_EcuM_GetShutdownCause_Start
 *  Rte_Runnable_EcuM_GetShutdownTarget_Return
 *  Rte_Runnable_EcuM_GetShutdownTarget_Start
 *  Rte_Runnable_EcuM_GetStateWrapper_Return
 *  Rte_Runnable_EcuM_GetStateWrapper_Start
 *  Rte_Runnable_EcuM_ReleasePOSTRUN_Return
 *  Rte_Runnable_EcuM_ReleasePOSTRUN_Start
 *  Rte_Runnable_EcuM_ReleaseRUN_Return
 *  Rte_Runnable_EcuM_ReleaseRUN_Start
 *  Rte_Runnable_EcuM_RequestPOSTRUN_Return
 *  Rte_Runnable_EcuM_RequestPOSTRUN_Start
 *  Rte_Runnable_EcuM_RequestRUN_Return
 *  Rte_Runnable_EcuM_RequestRUN_Start
 *  Rte_Runnable_EcuM_SelectBootTarget_Return
 *  Rte_Runnable_EcuM_SelectBootTarget_Start
 *  Rte_Runnable_EcuM_SelectShutdownCause_Return
 *  Rte_Runnable_EcuM_SelectShutdownCause_Start
 *  Rte_Runnable_EcuM_SelectShutdownTarget_Return
 *  Rte_Runnable_EcuM_SelectShutdownTarget_Start
 *  Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Return
 *  Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Start
 *  Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Return
 *  Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Start
 *  Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Return
 *  Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Start
 *  Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Return
 *  Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Start
 *  Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Return
 *  Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Start
 *  Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Return
 *  Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Start
 *  Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Return
 *  Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Start
 *  Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Return
 *  Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Start
 *  Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Return
 *  Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Start
 *  Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Return
 *  Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Start
 *  Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Return
 *  Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Start
 *  Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Return
 *  Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Start
 *  Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Return
 *  Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Start
 *  Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Return
 *  Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Start
 *  Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Return
 *  Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Start
 *  Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Return
 *  Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Start
 *  Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Return
 *  Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Start
 *  Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Return
 *  Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Start
 *  Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Return
 *  Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Start
 *  Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Return
 *  Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Start
 *  Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Return
 *  Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Start
 *  Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Return
 *  Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Start
 *  Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Return
 *  Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Start
 *  Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Return
 *  Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Start
 *  Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Return
 *  Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Start
 *  Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Return
 *  Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Start
 *  Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Return
 *  Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Start
 *  Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Return
 *  Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Start
 *  Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Return
 *  Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Start
 *  Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Return
 *  Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Start
 *  Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Return
 *  Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Start
 *  Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Return
 *  Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Start
 *  Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Return
 *  Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Start
 *  Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Return
 *  Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Start
 *  Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Return
 *  Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Start
 *  Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Return
 *  Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Start
 *  Rte_Runnable_NvM_EraseBlock_Return
 *  Rte_Runnable_NvM_EraseBlock_Start
 *  Rte_Runnable_NvM_GetErrorStatus_Return
 *  Rte_Runnable_NvM_GetErrorStatus_Start
 *  Rte_Runnable_NvM_InvalidateNvBlock_Return
 *  Rte_Runnable_NvM_InvalidateNvBlock_Start
 *  Rte_Runnable_NvM_NvM_MainFunction_Return
 *  Rte_Runnable_NvM_NvM_MainFunction_Start
 *  Rte_Runnable_NvM_ReadBlock_Return
 *  Rte_Runnable_NvM_ReadBlock_Start
 *  Rte_Runnable_NvM_RestoreBlockDefaults_Return
 *  Rte_Runnable_NvM_RestoreBlockDefaults_Start
 *  Rte_Runnable_NvM_SetBlockProtection_Return
 *  Rte_Runnable_NvM_SetBlockProtection_Start
 *  Rte_Runnable_NvM_SetRamBlockStatus_Return
 *  Rte_Runnable_NvM_SetRamBlockStatus_Start
 *  Rte_Runnable_NvM_WriteBlock_Return
 *  Rte_Runnable_NvM_WriteBlock_Start
 *  Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Return
 *  Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Start
 *  Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Return
 *  Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Start
 *  Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Return
 *  Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Start
 *  Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Return
 *  Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Start
 *  Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Return
 *  Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Start
 *  Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Return
 *  Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Start
 *  Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Return
 *  Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Start
 *  Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Return
 *  Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Start
 *  Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Return
 *  Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Start
 *  Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Return
 *  Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Start
 *  Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Return
 *  Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Start
 *  Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Return
 *  Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Start
 *  Rte_Runnable_PtrView_PtrView_PrepareSub_Return
 *  Rte_Runnable_PtrView_PtrView_PrepareSub_Start
 *  Rte_Runnable_PtrView_PtrView_Start_Return
 *  Rte_Runnable_PtrView_PtrView_Start_Start
 *  Rte_Runnable_PtrView_PtrView_Stop_Return
 *  Rte_Runnable_PtrView_PtrView_Stop_Start
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Return
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Start
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Return
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Start
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Return
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Start
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Return
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Start
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Return
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Start
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Return
 *  Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Start
 *  Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Return
 *  Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Start
 *  Rte_Runnable_SndView_CSndView_Impl_MainFunction_Return
 *  Rte_Runnable_SndView_CSndView_Impl_MainFunction_Start
 *  Rte_Runnable_SndView_CSndView_Impl_Notification_Return
 *  Rte_Runnable_SndView_CSndView_Impl_Notification_Start
 *  Rte_Runnable_SndView_CSndView_Impl_OnCommand_Return
 *  Rte_Runnable_SndView_CSndView_Impl_OnCommand_Start
 *  Rte_Runnable_SndView_SndView_Cancel_Return
 *  Rte_Runnable_SndView_SndView_Cancel_Start
 *  Rte_Runnable_SndView_SndView_Impl_DiagAction_Return
 *  Rte_Runnable_SndView_SndView_Impl_DiagAction_Start
 *  Rte_Runnable_SndView_SndView_Latch_Return
 *  Rte_Runnable_SndView_SndView_Latch_Start
 *  Rte_Runnable_SndView_SndView_ListChange_Return
 *  Rte_Runnable_SndView_SndView_ListChange_Start
 *  Rte_Runnable_SndView_SndView_PrepareSub_Return
 *  Rte_Runnable_SndView_SndView_PrepareSub_Start
 *  Rte_Runnable_SndView_SndView_Prepare_Return
 *  Rte_Runnable_SndView_SndView_Prepare_Start
 *  Rte_Runnable_SndView_SndView_Start_Return
 *  Rte_Runnable_SndView_SndView_Start_Start
 *  Rte_Runnable_SndView_SndView_Stop_Return
 *  Rte_Runnable_SndView_SndView_Stop_Start
 *  Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Return
 *  Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Start
 *  Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Return
 *  Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Start
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Return
 *  Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Start
 *  Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Return
 *  Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Start
 *  Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Return
 *  Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Start
 *  Rte_Runnable_TmExt_TmExt_MainFunction_Return
 *  Rte_Runnable_TmExt_TmExt_MainFunction_Start
 *  Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Return
 *  Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Start
 *  Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Return
 *  Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Start
 *  Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Return
 *  Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Start
 *  Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Return
 *  Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Start
 *  Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Return
 *  Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Start
 *  Rte_Runnable_TtView_CTtView_Impl_MainFunction_Return
 *  Rte_Runnable_TtView_CTtView_Impl_MainFunction_Start
 *  Rte_Runnable_TtView_CTtView_Impl_Notification_Return
 *  Rte_Runnable_TtView_CTtView_Impl_Notification_Start
 *  Rte_Runnable_TtView_CTtView_Impl_OnCommand_Return
 *  Rte_Runnable_TtView_CTtView_Impl_OnCommand_Start
 *  Rte_Runnable_TtView_TtView_Cancel_Return
 *  Rte_Runnable_TtView_TtView_Cancel_Start
 *  Rte_Runnable_TtView_TtView_Latch_Return
 *  Rte_Runnable_TtView_TtView_Latch_Start
 *  Rte_Runnable_TtView_TtView_ListChange_Return
 *  Rte_Runnable_TtView_TtView_ListChange_Start
 *  Rte_Runnable_TtView_TtView_PrepareSub_Return
 *  Rte_Runnable_TtView_TtView_PrepareSub_Start
 *  Rte_Runnable_TtView_TtView_Prepare_Return
 *  Rte_Runnable_TtView_TtView_Prepare_Start
 *  Rte_Runnable_TtView_TtView_Start_Return
 *  Rte_Runnable_TtView_TtView_Start_Start
 *  Rte_Runnable_TtView_TtView_Stop_Return
 *  Rte_Runnable_TtView_TtView_Stop_Start
 *  Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Return
 *  Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Start
 *  Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Return
 *  Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Start
 *  Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Return
 *  Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Start
 *  Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Return
 *  Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Start
 *  Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Return
 *  Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Start
 *  Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Return
 *  Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Start
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Release_Return
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Release_Start
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Return
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Start
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Return
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Start
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Return
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Start
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Return
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Start
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Return
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Start
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Return
 *  Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Start
 *  Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Return
 *  Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Start
 *  Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Return
 *  Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Start
 *  Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Return
 *  Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Start
 *  Rte_SwitchHook_EcuM_currentMode_currentMode_Return
 *  Rte_SwitchHook_EcuM_currentMode_currentMode_Start
 *  Rte_Task_Activate
 *  Rte_Task_Dispatch
 *  Rte_Task_SetEvent
 *  Rte_Task_WaitEvent
 *  Rte_Task_WaitEventRet
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Return
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Start
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Return
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Start
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Return
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Start
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Return
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Start
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Return
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Start
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Return
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Start
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Return
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Start
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Return
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Start
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Return
 *  Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Start
 *  Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Return
 *  Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Start
 *  Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Return
 *  Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Start
 *  Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return
 *  Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start
 *  Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return
 *  Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start
 *  Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return
 *  Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start
 *  Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Return
 *  Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Start
 *  Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Return
 *  Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Start
 *  Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Return
 *  Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Start
 *  Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Return
 *  Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Start
 *  Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return
 *  Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start
 *  Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Return
 *  Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Start
 *  Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Return
 *  Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Start
 *  Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Return
 *  Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Start
 *  Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Return
 *  Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Start
 *  Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Return
 *  Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Start
 *  Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Return
 *  Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Start
 *  Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Return
 *  Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Start
 *  Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return
 *  Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start
 *  Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Return
 *  Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Start
 *  Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Return
 *  Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Start
 *  Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Return
 *  Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Start
 *  Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Return
 *  Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Start
 *  Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Return
 *  Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Start
 *  Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Return
 *  Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Start
 *
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_HOOK_H
# define _RTE_HOOK_H

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */

# include "Rte_Type.h"
# include "Rte_Cfg.h"

# ifndef RTE_VFB_TRACE
#  define RTE_VFB_TRACE (0)
# endif

# define RTE_START_SEC_APPL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# if defined (Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Return)
#  undef Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Return(EIOGroupInId Id, P2VAR(UInt32, AUTOMATIC, RTE_BTNMDL_APPL_VAR) Group); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Return */

# if defined (Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Start)
#  undef Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Start(EIOGroupInId Id, P2VAR(UInt32, AUTOMATIC, RTE_BTNMDL_APPL_VAR) Group); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetGroup_Start */

# if defined (Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Return)
#  undef Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Return(EIOPinInId Id, P2VAR(Boolean, AUTOMATIC, RTE_BTNMDL_APPL_VAR) Pin); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Return */

# if defined (Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Start)
#  undef Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Start(EIOPinInId Id, P2VAR(Boolean, AUTOMATIC, RTE_BTNMDL_APPL_VAR) Pin); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_BtnMdl_rpCS_rDIn_TIIoHwAb_DIn_GetPin_Start */

# if defined (Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Return)
#  undef Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Return(EIOVoltageInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_CDD_TEST_APPL_VAR) Voltage); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Return */

# if defined (Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Start)
#  undef Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Start(EIOVoltageInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_CDD_TEST_APPL_VAR) Voltage); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_CDD_Test_tiCS_TIIoHwAb_AIn_GetVoltage_Start */

# if defined (Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Return)
#  undef Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Return */

# if defined (Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Start)
#  undef Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_DimView_DiagAction_Start */

# if defined (Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Return)
#  undef Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Return */

# if defined (Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Start)
#  undef Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_Gdt_DiagAction_Start */

# if defined (Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Return)
#  undef Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Return */

# if defined (Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Start)
#  undef Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_PtrSpdView_DiagAction_Start */

# if defined (Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Return)
#  undef Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Return */

# if defined (Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Start)
#  undef Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_PtrTachoView_DiagAction_Start */

# if defined (Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Return)
#  undef Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Return */

# if defined (Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Start)
#  undef Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_SndView_DiagAction_Start */

# if defined (Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Return)
#  undef Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Return */

# if defined (Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Start)
#  undef Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DcmExt_TI_Diag_StpCdd_DiagAction_Start */

# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Return)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Return(EIOPeriodOutId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_DIMVIEW_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Return */

# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Start)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Start(EIOPeriodOutId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_DIMVIEW_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_GetPeriodMappedStatus_Start */

# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Return)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Return(EIODutyOutId Id, UInt16 Duty); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Return */

# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Start)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Start(EIODutyOutId Id, UInt16 Duty); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetDuty_Start */

# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Return)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Return(EIOPeriodOutId Id, UInt32 Period); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Return */

# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Start)
#  undef Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Start(EIOPeriodOutId Id, UInt32 Period); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DimView_rpCS_rPwmOut_TIIoHwAb_PwmOut_SetPeriod_Start */

# if defined (Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Return)
#  undef Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Return(P2CONST(Dlt_MessageLogInfoType, AUTOMATIC, RTE_DLTEXT_APPL_DATA) LogInfo, P2CONST(Dlt_VerboseBufferType, AUTOMATIC, RTE_DLTEXT_APPL_DATA) LogData, uint16 LogDataLength); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Return */

# if defined (Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Start)
#  undef Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Start(P2CONST(Dlt_MessageLogInfoType, AUTOMATIC, RTE_DLTEXT_APPL_DATA) LogInfo, P2CONST(Dlt_VerboseBufferType, AUTOMATIC, RTE_DLTEXT_APPL_DATA) LogData, uint16 LogDataLength); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_DltExt_DltExt_SendLogMessage_4096_SendLogMessage_Start */

# if defined (Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Return)
#  undef Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Return */

# if defined (Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Start)
#  undef Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Init_Start */

# if defined (Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Return)
#  undef Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Return */

# if defined (Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Start)
#  undef Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EctMdlWrp_EctMdl_SysIntf_Runnable_swcECT_Step_Start */

# if defined (Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Return(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Start(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_EctMdl_SystemIf_EctMdl_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Return(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Start(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_FuelMdl_SystemIf_FuelMdl_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_HmiCtrl_SystemIf_HmiCtrl_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Return(ECmpCmd arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Start(ECmpCmd arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_OdoMdl_SystemIf_OdoMdl_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_PtrEctView_SystemIf_PtrEctView_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_PtrFuelView_SystemIf_PtrFuelView_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_PtrSpdView_SystemIf_PtrSpdView_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_PtrTachoView_SystemIf_PtrTachoView_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Return(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Start(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_TrcMdl_SystemIf_TrcMdl_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysBtnMdl_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysDimMdl_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysDimView_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysEngMdl_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCdd_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysGdtCtrl_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Return(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Start(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysIoHwAb_TISystem_IoHwAb_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysModMdl_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysSndCdd_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysSndView_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysSpdMdl_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysStpCdd_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysTtMdl_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysTtView_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Return)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Return */

# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Start)
#  undef Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_EcumExt_rpCS_rSys_SysWrnCtrl_TISystem_OnCommand_Start */

# if defined (Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Return)
#  undef Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Return */

# if defined (Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Start)
#  undef Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Init_Start */

# if defined (Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Return)
#  undef Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Return */

# if defined (Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Start)
#  undef Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_FuelMdlWrp_Intf_FuelLevelCAN_Step_Start */

# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Return)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Return(EIOCurrentInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_FUELMDLWRP_APPL_VAR) Current); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Return */

# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Start)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Start(EIOCurrentInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_FUELMDLWRP_APPL_VAR) Current); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetCurrent_Start */

# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Return)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Return(EIOMapStatInId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_FUELMDLWRP_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Return */

# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Start)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Start(EIOMapStatInId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_FUELMDLWRP_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetMappedStatus_Start */

# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Return)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Return(EIOResistanceInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_FUELMDLWRP_APPL_VAR) Resistance); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Return */

# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Start)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Start(EIOResistanceInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_FUELMDLWRP_APPL_VAR) Resistance); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetResistance_Start */

# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Return)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Return(EIOVoltageInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_FUELMDLWRP_APPL_VAR) Voltage); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Return */

# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Start)
#  undef Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Start(EIOVoltageInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_FUELMDLWRP_APPL_VAR) Voltage); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_FuelMdlWrp_tiCS_TIIoHwAb_AIn_GetVoltage_Start */

# if defined (Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Return)
#  undef Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Return */

# if defined (Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Start)
#  undef Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_itCS_TripMdl_ResetTrip_Start */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Return)
#  undef Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Return(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Return */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Start)
#  undef Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Start(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rAck_TIWrnCtrl_Ack_Acknowledge_Start */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Return)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Return(TWrnListMask ListMask, P2VAR(UInt16, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Count); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Return */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Start)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Start(TWrnListMask ListMask, P2VAR(UInt16, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Count); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetCount_Start */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Return)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Return(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Return */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Start)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Start(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetFirst_Start */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Return)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Return(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Return */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Start)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Start(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_GetNext_Start */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Return)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Return */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Start)
#  undef Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rList_TIWrnCtrl_Lists_Release_Start */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return)
#  undef Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_GDTCTRL_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start)
#  undef Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_GDTCTRL_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return)
#  undef Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_GDTCTRL_APPL_DATA) Notification, P2CONST(SPulseNotification, AUTOMATIC, RTE_GDTCTRL_APPL_DATA) Sync); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start)
#  undef Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_GDTCTRL_APPL_DATA) Notification, P2CONST(SPulseNotification, AUTOMATIC, RTE_GDTCTRL_APPL_DATA) Sync); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Return)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Return */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Start)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rSub_TIHmiCtrl_SubReply_Ready_Start */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return */

# if defined (Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start)
#  undef Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_GdtCtrl_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Return)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Return */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Start)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_PrepareSub_Start */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Return)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Return */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Start)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Start_Start */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Return)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Return */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Start)
#  undef Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Gdt_TIHmiCtrl_SubCmd_Stop_Start */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Return)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Return */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Start)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_PrepareSub_Start */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Return)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Return */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Start)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Start_Start */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Return)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Return */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Start)
#  undef Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Ptr_TIHmiCtrl_SubCmd_Stop_Start */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Return)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Return */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Start)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_PrepareSub_Start */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Return)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Return */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Start)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Start_Start */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Return)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Return */

# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Start)
#  undef Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_HmiCtrl_tiCS_Tt_TIHmiCtrl_SubCmd_Stop_Start */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Return)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Return(uint8 Id, uint16 Angle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Return */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Start)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Start(uint8 Id, uint16 Angle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_SetPosDeg_Start */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Return)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Return(uint8 Id, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) pWowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Return */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Start)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Start(uint8 Id, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) pWowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowGetMotSession_Start */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Return)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Return(P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) pWowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Return */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Start)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Start(P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) pWowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowOpenSession_Start */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Return)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Return(uint8 WowSession, Boolean toStart); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Return */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Start)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Start(uint8 WowSession, Boolean toStart); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowRequest_Start */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Return)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Return(uint8 WowSession, uint8 Id, uint16 TargetPos); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Return */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Start)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Start(uint8 WowSession, uint8 Id, uint16 TargetPos); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetMotor_Start */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Return)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Return(uint8 WowSession, uint16 Time, uint8 TimeType); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Return */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Start)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Start(uint8 WowSession, uint16 Time, uint8 TimeType); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowSessionSetTime_Start */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Return)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Return(uint8 WowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Return */

# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Start)
#  undef Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Start(uint8 WowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_ppCS_pStpCdd_TIStpCdd_WowStop_Start */

# if defined (Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Return)
#  undef Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Return */

# if defined (Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Start)
#  undef Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_PtrView_tiCS_TIHmiCtrl_SubReply_Ready_Start */

# if defined (Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Return)
#  undef Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Return(uint16 Frequency, uint8 Volume); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Return */

# if defined (Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Start)
#  undef Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Start(uint16 Frequency, uint8 Volume); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_SndDiag_PlayTone_RequestToPlayTone_Start */

# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Return)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Return(UInt8 ChimeId, P2VAR(EChimeStatus, AUTOMATIC, RTE_SNDVIEW_APPL_VAR) pChimeStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Return */

# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Start)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Start(UInt8 ChimeId, P2VAR(EChimeStatus, AUTOMATIC, RTE_SNDVIEW_APPL_VAR) pChimeStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_CheckStatus_Start */

# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Return)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Return(UInt8 ChimeId); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Return */

# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Start)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Start(UInt8 ChimeId); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStart_Start */

# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Return)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Return(UInt8 ChimeId); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Return */

# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Start)
#  undef Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Start(UInt8 ChimeId); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rCdd_TISndCdd_RequestToStop_Start */

# if defined (Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return)
#  undef Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_SNDVIEW_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return */

# if defined (Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start)
#  undef Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_SNDVIEW_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start */

# if defined (Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return)
#  undef Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_SNDVIEW_APPL_DATA) Notification, P2CONST(SPulseNotification, AUTOMATIC, RTE_SNDVIEW_APPL_DATA) Sync); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return */

# if defined (Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start)
#  undef Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_SNDVIEW_APPL_DATA) Notification, P2CONST(SPulseNotification, AUTOMATIC, RTE_SNDVIEW_APPL_DATA) Sync); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start */

# if defined (Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return)
#  undef Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return */

# if defined (Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start)
#  undef Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start */

# if defined (Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return)
#  undef Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return */

# if defined (Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start)
#  undef Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SndView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start */

# if defined (Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Return)
#  undef Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Return(Dem_EventStatusType EventStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Return */

# if defined (Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Start)
#  undef Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Start(Dem_EventStatusType EventStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SpdMdl_LostFrame_SetEventStatus_Start */

# if defined (Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Return)
#  undef Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Return(Dem_EventStatusType EventStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Return */

# if defined (Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Start)
#  undef Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Start(Dem_EventStatusType EventStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_SpdMdl_OverSpeed_SetEventStatus_Start */

# if defined (Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Return)
#  undef Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Return(P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Return */

# if defined (Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Start)
#  undef Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Start(P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TmExt_rpCS_rNotify_NotifySndView_TITmExt_Notify_Notification_Start */

# if defined (Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Return)
#  undef Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Return(P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Return */

# if defined (Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Start)
#  undef Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Start(P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TmExt_rpCS_rNotify_NotifyTtView_TITmExt_Notify_Notification_Start */

# if defined (Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Return)
#  undef Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Return(P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Return */

# if defined (Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Start)
#  undef Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Start(P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TmExt_tiCS_TITmExt_Notify_Notification_Start */

# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Return)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Return(EIOPinOutId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_TTVIEW_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Return */

# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Start)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Start(EIOPinOutId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_TTVIEW_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_GetPinMappedStatus_Start */

# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Return)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Return(EIOGroupOutId Id, UInt32 Group); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Return */

# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Start)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Start(EIOGroupOutId Id, UInt32 Group); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetGroup_Start */

# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Return)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Return(EIOPinOutId Id, Boolean Digital); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Return */

# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Start)
#  undef Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Start(EIOPinOutId Id, Boolean Digital); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rDO_TIIoHwAb_DOut_SetPin_Start */

# if defined (Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return)
#  undef Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_TTVIEW_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Return */

# if defined (Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start)
#  undef Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_TTVIEW_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_DisableNotification_Start */

# if defined (Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return)
#  undef Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_TTVIEW_APPL_DATA) Notification, P2CONST(SPulseNotification, AUTOMATIC, RTE_TTVIEW_APPL_DATA) Sync); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Return */

# if defined (Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start)
#  undef Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_TTVIEW_APPL_DATA) Notification, P2CONST(SPulseNotification, AUTOMATIC, RTE_TTVIEW_APPL_DATA) Sync); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rPulse_TITmExt_Pulse_EnableNotification_Start */

# if defined (Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return)
#  undef Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Return */

# if defined (Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start)
#  undef Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Ready_Start */

# if defined (Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return)
#  undef Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Return */

# if defined (Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start)
#  undef Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_rpCS_rSync_TIWrnCtrl_SyncReply_Replay_Start */

# if defined (Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Return)
#  undef Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Return */

# if defined (Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Start)
#  undef Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_tiCS_TIHmiCtrl_SubReply_Ready_Start */

# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Return)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Return(TWrnListMask ListMask, P2VAR(UInt16, AUTOMATIC, RTE_TTVIEW_APPL_VAR) Count); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Return */

# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Start)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Start(TWrnListMask ListMask, P2VAR(UInt16, AUTOMATIC, RTE_TTVIEW_APPL_VAR) Count); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetCount_Start */

# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Return)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Return(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_TTVIEW_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Return */

# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Start)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Start(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_TTVIEW_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetFirst_Start */

# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Return)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Return(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_TTVIEW_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Return */

# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Start)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Start(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_TTVIEW_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_GetNext_Start */

# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Return)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Return */

# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Start)
#  undef Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_TtView_tiCS_TIWrnCtrl_Lists_Release_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Cancel_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Latch_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Return(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Start(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_ListChange_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Gdt_TIWrnCtrl_SyncCmd_Prepare_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Cancel_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Latch_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Return(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Start(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_ListChange_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Snd_TIWrnCtrl_SyncCmd_Prepare_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Cancel_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Latch_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Return(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Start(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_ListChange_Start */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Return)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Return */

# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Start)
#  undef Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_CallHook_WrnCtrl_rpCS_rSync_Tt_TIWrnCtrl_SyncCmd_Prepare_Start */

# if defined (Rte_ComHookRxTOut_DimGeneral_0e65ef90) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRxTOut_DimGeneral_0e65ef90 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRxTOut_DimGeneral_0e65ef90)
#  undef Rte_ComHookRxTOut_DimGeneral_0e65ef90 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRxTOut_DimGeneral_0e65ef90(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRxTOut_DimGeneral_0e65ef90() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRxTOut_DimGeneral_0e65ef90 */

# if defined (Rte_ComHookRxTOut_DownTranOfEngCoolantTempCAN_46dad878) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRxTOut_DownTranOfEngCoolantTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRxTOut_DownTranOfEngCoolantTempCAN_46dad878)
#  undef Rte_ComHookRxTOut_DownTranOfEngCoolantTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRxTOut_DownTranOfEngCoolantTempCAN_46dad878(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRxTOut_DownTranOfEngCoolantTempCAN_46dad878() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRxTOut_DownTranOfEngCoolantTempCAN_46dad878 */

# if defined (Rte_ComHookRxTOut_EngineCoolantTempCAN_46dad878) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRxTOut_EngineCoolantTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRxTOut_EngineCoolantTempCAN_46dad878)
#  undef Rte_ComHookRxTOut_EngineCoolantTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRxTOut_EngineCoolantTempCAN_46dad878(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRxTOut_EngineCoolantTempCAN_46dad878() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRxTOut_EngineCoolantTempCAN_46dad878 */

# if defined (Rte_ComHookRxTOut_SpeedRef_a9ab8ab7) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRxTOut_SpeedRef_a9ab8ab7 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRxTOut_SpeedRef_a9ab8ab7)
#  undef Rte_ComHookRxTOut_SpeedRef_a9ab8ab7 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRxTOut_SpeedRef_a9ab8ab7(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRxTOut_SpeedRef_a9ab8ab7() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRxTOut_SpeedRef_a9ab8ab7 */

# if defined (Rte_ComHookRxTOut_TachoRef_3db35f78) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRxTOut_TachoRef_3db35f78 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRxTOut_TachoRef_3db35f78)
#  undef Rte_ComHookRxTOut_TachoRef_3db35f78 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRxTOut_TachoRef_3db35f78(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRxTOut_TachoRef_3db35f78() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRxTOut_TachoRef_3db35f78 */

# if defined (Rte_ComHookRxTOut_WarningWaterTempCAN_46dad878) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRxTOut_WarningWaterTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRxTOut_WarningWaterTempCAN_46dad878)
#  undef Rte_ComHookRxTOut_WarningWaterTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRxTOut_WarningWaterTempCAN_46dad878(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRxTOut_WarningWaterTempCAN_46dad878() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRxTOut_WarningWaterTempCAN_46dad878 */

# if defined (Rte_ComHookRx_DimGeneral_0e65ef90) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRx_DimGeneral_0e65ef90 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRx_DimGeneral_0e65ef90)
#  undef Rte_ComHookRx_DimGeneral_0e65ef90 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRx_DimGeneral_0e65ef90(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRx_DimGeneral_0e65ef90() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRx_DimGeneral_0e65ef90 */

# if defined (Rte_ComHookRx_DownTranOfEngCoolantTempCAN_46dad878) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRx_DownTranOfEngCoolantTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRx_DownTranOfEngCoolantTempCAN_46dad878)
#  undef Rte_ComHookRx_DownTranOfEngCoolantTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRx_DownTranOfEngCoolantTempCAN_46dad878(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRx_DownTranOfEngCoolantTempCAN_46dad878() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRx_DownTranOfEngCoolantTempCAN_46dad878 */

# if defined (Rte_ComHookRx_EngineCoolantTempCAN_46dad878) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRx_EngineCoolantTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRx_EngineCoolantTempCAN_46dad878)
#  undef Rte_ComHookRx_EngineCoolantTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRx_EngineCoolantTempCAN_46dad878(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRx_EngineCoolantTempCAN_46dad878() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRx_EngineCoolantTempCAN_46dad878 */

# if defined (Rte_ComHookRx_NewRollingOdo_9d7d00df) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRx_NewRollingOdo_9d7d00df /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRx_NewRollingOdo_9d7d00df)
#  undef Rte_ComHookRx_NewRollingOdo_9d7d00df /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRx_NewRollingOdo_9d7d00df(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRx_NewRollingOdo_9d7d00df() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRx_NewRollingOdo_9d7d00df */

# if defined (Rte_ComHookRx_SG_RxFilteredSpeed_a536058e) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRx_SG_RxFilteredSpeed_a536058e /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRx_SG_RxFilteredSpeed_a536058e)
#  undef Rte_ComHookRx_SG_RxFilteredSpeed_a536058e /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRx_SG_RxFilteredSpeed_a536058e(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRx_SG_RxFilteredSpeed_a536058e() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRx_SG_RxFilteredSpeed_a536058e */

# if defined (Rte_ComHookRx_SpeedRef_a9ab8ab7) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRx_SpeedRef_a9ab8ab7 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRx_SpeedRef_a9ab8ab7)
#  undef Rte_ComHookRx_SpeedRef_a9ab8ab7 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRx_SpeedRef_a9ab8ab7(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRx_SpeedRef_a9ab8ab7() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRx_SpeedRef_a9ab8ab7 */

# if defined (Rte_ComHookRx_TachoRef_3db35f78) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRx_TachoRef_3db35f78 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRx_TachoRef_3db35f78)
#  undef Rte_ComHookRx_TachoRef_3db35f78 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRx_TachoRef_3db35f78(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRx_TachoRef_3db35f78() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRx_TachoRef_3db35f78 */

# if defined (Rte_ComHookRx_WarningWaterTempCAN_46dad878) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHookRx_WarningWaterTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHookRx_WarningWaterTempCAN_46dad878)
#  undef Rte_ComHookRx_WarningWaterTempCAN_46dad878 /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHookRx_WarningWaterTempCAN_46dad878(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHookRx_WarningWaterTempCAN_46dad878() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHookRx_WarningWaterTempCAN_46dad878 */

# if defined (Rte_ComHook_BrkLamp_B_Rq_610999c4_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_BrkLamp_B_Rq_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_BrkLamp_B_Rq_610999c4_SigRx)
#  undef Rte_ComHook_BrkLamp_B_Rq_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_BrkLamp_B_Rq_610999c4_SigRx(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_BrkLamp_B_Rq_610999c4_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_BrkLamp_B_Rq_610999c4_SigRx */

# if defined (Rte_ComHook_BtnCES_Down_c0440b7e_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_BtnCES_Down_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_BtnCES_Down_c0440b7e_SigRx)
#  undef Rte_ComHook_BtnCES_Down_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_BtnCES_Down_c0440b7e_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_BtnCES_Down_c0440b7e_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_BtnCES_Down_c0440b7e_SigRx */

# if defined (Rte_ComHook_BtnCES_Left_c0440b7e_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_BtnCES_Left_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_BtnCES_Left_c0440b7e_SigRx)
#  undef Rte_ComHook_BtnCES_Left_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_BtnCES_Left_c0440b7e_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_BtnCES_Left_c0440b7e_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_BtnCES_Left_c0440b7e_SigRx */

# if defined (Rte_ComHook_BtnCES_OK_c0440b7e_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_BtnCES_OK_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_BtnCES_OK_c0440b7e_SigRx)
#  undef Rte_ComHook_BtnCES_OK_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_BtnCES_OK_c0440b7e_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_BtnCES_OK_c0440b7e_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_BtnCES_OK_c0440b7e_SigRx */

# if defined (Rte_ComHook_BtnCES_Right_c0440b7e_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_BtnCES_Right_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_BtnCES_Right_c0440b7e_SigRx)
#  undef Rte_ComHook_BtnCES_Right_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_BtnCES_Right_c0440b7e_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_BtnCES_Right_c0440b7e_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_BtnCES_Right_c0440b7e_SigRx */

# if defined (Rte_ComHook_BtnCES_Up_c0440b7e_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_BtnCES_Up_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_BtnCES_Up_c0440b7e_SigRx)
#  undef Rte_ComHook_BtnCES_Up_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_BtnCES_Up_c0440b7e_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_BtnCES_Up_c0440b7e_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_BtnCES_Up_c0440b7e_SigRx */

# if defined (Rte_ComHook_Button_1_c0440b7e_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_Button_1_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_Button_1_c0440b7e_SigRx)
#  undef Rte_ComHook_Button_1_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_Button_1_c0440b7e_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_Button_1_c0440b7e_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_Button_1_c0440b7e_SigRx */

# if defined (Rte_ComHook_Button_2_c0440b7e_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_Button_2_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_Button_2_c0440b7e_SigRx)
#  undef Rte_ComHook_Button_2_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_Button_2_c0440b7e_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_Button_2_c0440b7e_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_Button_2_c0440b7e_SigRx */

# if defined (Rte_ComHook_Button_3_c0440b7e_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_Button_3_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_Button_3_c0440b7e_SigRx)
#  undef Rte_ComHook_Button_3_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_Button_3_c0440b7e_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_Button_3_c0440b7e_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_Button_3_c0440b7e_SigRx */

# if defined (Rte_ComHook_Button_4_c0440b7e_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_Button_4_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_Button_4_c0440b7e_SigRx)
#  undef Rte_ComHook_Button_4_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_Button_4_c0440b7e_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_Button_4_c0440b7e_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_Button_4_c0440b7e_SigRx */

# if defined (Rte_ComHook_Button_5_c0440b7e_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_Button_5_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_Button_5_c0440b7e_SigRx)
#  undef Rte_ComHook_Button_5_c0440b7e_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_Button_5_c0440b7e_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_Button_5_c0440b7e_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_Button_5_c0440b7e_SigRx */

# if defined (Rte_ComHook_DimGeneral_0e65ef90_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_DimGeneral_0e65ef90_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_DimGeneral_0e65ef90_SigRx)
#  undef Rte_ComHook_DimGeneral_0e65ef90_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_DimGeneral_0e65ef90_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_DIMMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_DimGeneral_0e65ef90_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_DimGeneral_0e65ef90_SigRx */

# if defined (Rte_ComHook_Disable_Neutral_Tow_610999c4_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_Disable_Neutral_Tow_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_Disable_Neutral_Tow_610999c4_SigRx)
#  undef Rte_ComHook_Disable_Neutral_Tow_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_Disable_Neutral_Tow_610999c4_SigRx(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_Disable_Neutral_Tow_610999c4_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_Disable_Neutral_Tow_610999c4_SigRx */

# if defined (Rte_ComHook_DownTranOfEngCoolantTempCAN_46dad878_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_DownTranOfEngCoolantTempCAN_46dad878_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_DownTranOfEngCoolantTempCAN_46dad878_SigRx)
#  undef Rte_ComHook_DownTranOfEngCoolantTempCAN_46dad878_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_DownTranOfEngCoolantTempCAN_46dad878_SigRx(P2VAR(Boolean, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_DownTranOfEngCoolantTempCAN_46dad878_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_DownTranOfEngCoolantTempCAN_46dad878_SigRx */

# if defined (Rte_ComHook_DrStatDrv_B_Actl_610999c4_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_DrStatDrv_B_Actl_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_DrStatDrv_B_Actl_610999c4_SigRx)
#  undef Rte_ComHook_DrStatDrv_B_Actl_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_DrStatDrv_B_Actl_610999c4_SigRx(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_DrStatDrv_B_Actl_610999c4_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_DrStatDrv_B_Actl_610999c4_SigRx */

# if defined (Rte_ComHook_DrStatPsngr_B_Actl_610999c4_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_DrStatPsngr_B_Actl_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_DrStatPsngr_B_Actl_610999c4_SigRx)
#  undef Rte_ComHook_DrStatPsngr_B_Actl_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_DrStatPsngr_B_Actl_610999c4_SigRx(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_DrStatPsngr_B_Actl_610999c4_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_DrStatPsngr_B_Actl_610999c4_SigRx */

# if defined (Rte_ComHook_E2E_RxFilteredSpeedSft_cb1e8587_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_E2E_RxFilteredSpeedSft_cb1e8587_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_E2E_RxFilteredSpeedSft_cb1e8587_SigRx)
#  undef Rte_ComHook_E2E_RxFilteredSpeedSft_cb1e8587_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_E2E_RxFilteredSpeedSft_cb1e8587_SigRx(P2VAR(E2E_RxFilteredSpeedSft, AUTOMATIC, RTE_CDD_TEST_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_E2E_RxFilteredSpeedSft_cb1e8587_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_E2E_RxFilteredSpeedSft_cb1e8587_SigRx */

# if defined (Rte_ComHook_E2E_Rx_CRC_cb1e8587_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_E2E_Rx_CRC_cb1e8587_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_E2E_Rx_CRC_cb1e8587_SigRx)
#  undef Rte_ComHook_E2E_Rx_CRC_cb1e8587_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_E2E_Rx_CRC_cb1e8587_SigRx(P2VAR(E2E_Rx_CRC, AUTOMATIC, RTE_CDD_TEST_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_E2E_Rx_CRC_cb1e8587_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_E2E_Rx_CRC_cb1e8587_SigRx */

# if defined (Rte_ComHook_E2E_Rx_SeqNumber_cb1e8587_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_E2E_Rx_SeqNumber_cb1e8587_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_E2E_Rx_SeqNumber_cb1e8587_SigRx)
#  undef Rte_ComHook_E2E_Rx_SeqNumber_cb1e8587_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_E2E_Rx_SeqNumber_cb1e8587_SigRx(P2VAR(E2E_Rx_SeqNumber, AUTOMATIC, RTE_CDD_TEST_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_E2E_Rx_SeqNumber_cb1e8587_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_E2E_Rx_SeqNumber_cb1e8587_SigRx */

# if defined (Rte_ComHook_E2E_TxFilteredSpeedSft_701521af_SigTx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_E2E_TxFilteredSpeedSft_701521af_SigTx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_E2E_TxFilteredSpeedSft_701521af_SigTx)
#  undef Rte_ComHook_E2E_TxFilteredSpeedSft_701521af_SigTx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_E2E_TxFilteredSpeedSft_701521af_SigTx(P2CONST(E2E_TxFilteredSpeedSft, AUTOMATIC, RTE_CDD_TEST_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_E2E_TxFilteredSpeedSft_701521af_SigTx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_E2E_TxFilteredSpeedSft_701521af_SigTx */

# if defined (Rte_ComHook_E2E_Tx_CRC_701521af_SigTx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_E2E_Tx_CRC_701521af_SigTx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_E2E_Tx_CRC_701521af_SigTx)
#  undef Rte_ComHook_E2E_Tx_CRC_701521af_SigTx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_E2E_Tx_CRC_701521af_SigTx(P2CONST(E2E_Tx_CRC, AUTOMATIC, RTE_CDD_TEST_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_E2E_Tx_CRC_701521af_SigTx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_E2E_Tx_CRC_701521af_SigTx */

# if defined (Rte_ComHook_E2E_Tx_SeqNumber_701521af_SigTx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_E2E_Tx_SeqNumber_701521af_SigTx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_E2E_Tx_SeqNumber_701521af_SigTx)
#  undef Rte_ComHook_E2E_Tx_SeqNumber_701521af_SigTx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_E2E_Tx_SeqNumber_701521af_SigTx(P2CONST(E2E_Tx_SeqNumber, AUTOMATIC, RTE_CDD_TEST_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_E2E_Tx_SeqNumber_701521af_SigTx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_E2E_Tx_SeqNumber_701521af_SigTx */

# if defined (Rte_ComHook_Enable_Neutral_Tow_610999c4_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_Enable_Neutral_Tow_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_Enable_Neutral_Tow_610999c4_SigRx)
#  undef Rte_ComHook_Enable_Neutral_Tow_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_Enable_Neutral_Tow_610999c4_SigRx(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_Enable_Neutral_Tow_610999c4_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_Enable_Neutral_Tow_610999c4_SigRx */

# if defined (Rte_ComHook_EngineCoolantTempCAN_46dad878_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_EngineCoolantTempCAN_46dad878_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_EngineCoolantTempCAN_46dad878_SigRx)
#  undef Rte_ComHook_EngineCoolantTempCAN_46dad878_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_EngineCoolantTempCAN_46dad878_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_EngineCoolantTempCAN_46dad878_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_EngineCoolantTempCAN_46dad878_SigRx */

# if defined (Rte_ComHook_FUEL_LEVEL_CAN_24f27db7_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_FUEL_LEVEL_CAN_24f27db7_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_FUEL_LEVEL_CAN_24f27db7_SigRx)
#  undef Rte_ComHook_FUEL_LEVEL_CAN_24f27db7_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_FUEL_LEVEL_CAN_24f27db7_SigRx(P2VAR(FUEL_LEVEL_CAN, AUTOMATIC, RTE_FUELMDLWRP_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_FUEL_LEVEL_CAN_24f27db7_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_FUEL_LEVEL_CAN_24f27db7_SigRx */

# if defined (Rte_ComHook_KeyPos_70b9e74d_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_KeyPos_70b9e74d_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_KeyPos_70b9e74d_SigRx)
#  undef Rte_ComHook_KeyPos_70b9e74d_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_KeyPos_70b9e74d_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_MODMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_KeyPos_70b9e74d_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_KeyPos_70b9e74d_SigRx */

# if defined (Rte_ComHook_LeftTurnOn_365ba238_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_LeftTurnOn_365ba238_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_LeftTurnOn_365ba238_SigRx)
#  undef Rte_ComHook_LeftTurnOn_365ba238_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_LeftTurnOn_365ba238_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_TTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_LeftTurnOn_365ba238_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_LeftTurnOn_365ba238_SigRx */

# if defined (Rte_ComHook_MyKey_Active_610999c4_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_MyKey_Active_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_MyKey_Active_610999c4_SigRx)
#  undef Rte_ComHook_MyKey_Active_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_MyKey_Active_610999c4_SigRx(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_MyKey_Active_610999c4_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_MyKey_Active_610999c4_SigRx */

# if defined (Rte_ComHook_NewRollingOdo_9d7d00df_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_NewRollingOdo_9d7d00df_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_NewRollingOdo_9d7d00df_SigRx)
#  undef Rte_ComHook_NewRollingOdo_9d7d00df_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_NewRollingOdo_9d7d00df_SigRx(P2VAR(UInt16, AUTOMATIC, RTE_ODOMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_NewRollingOdo_9d7d00df_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_NewRollingOdo_9d7d00df_SigRx */

# if defined (Rte_ComHook_RightTurnOn_365ba238_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_RightTurnOn_365ba238_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_RightTurnOn_365ba238_SigRx)
#  undef Rte_ComHook_RightTurnOn_365ba238_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_RightTurnOn_365ba238_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_TTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_RightTurnOn_365ba238_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_RightTurnOn_365ba238_SigRx */

# if defined (Rte_ComHook_Slow_For_HDC_610999c4_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_Slow_For_HDC_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_Slow_For_HDC_610999c4_SigRx)
#  undef Rte_ComHook_Slow_For_HDC_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_Slow_For_HDC_610999c4_SigRx(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_Slow_For_HDC_610999c4_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_Slow_For_HDC_610999c4_SigRx */

# if defined (Rte_ComHook_SpeedFiltered_15b15a3c_SigTx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_SpeedFiltered_15b15a3c_SigTx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_SpeedFiltered_15b15a3c_SigTx)
#  undef Rte_ComHook_SpeedFiltered_15b15a3c_SigTx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_SpeedFiltered_15b15a3c_SigTx(P2CONST(UInt16, AUTOMATIC, RTE_SPDMDL_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_SpeedFiltered_15b15a3c_SigTx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_SpeedFiltered_15b15a3c_SigTx */

# if defined (Rte_ComHook_SpeedRef_a9ab8ab7_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_SpeedRef_a9ab8ab7_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_SpeedRef_a9ab8ab7_SigRx)
#  undef Rte_ComHook_SpeedRef_a9ab8ab7_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_SpeedRef_a9ab8ab7_SigRx(P2VAR(UInt16, AUTOMATIC, RTE_SPDMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_SpeedRef_a9ab8ab7_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_SpeedRef_a9ab8ab7_SigRx */

# if defined (Rte_ComHook_TachoFiltered_15b15a3c_SigTx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_TachoFiltered_15b15a3c_SigTx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_TachoFiltered_15b15a3c_SigTx)
#  undef Rte_ComHook_TachoFiltered_15b15a3c_SigTx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_TachoFiltered_15b15a3c_SigTx(P2CONST(UInt16, AUTOMATIC, RTE_ENGMDL_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_TachoFiltered_15b15a3c_SigTx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_TachoFiltered_15b15a3c_SigTx */

# if defined (Rte_ComHook_TachoRef_3db35f78_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_TachoRef_3db35f78_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_TachoRef_3db35f78_SigRx)
#  undef Rte_ComHook_TachoRef_3db35f78_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_TachoRef_3db35f78_SigRx(P2VAR(UInt16, AUTOMATIC, RTE_ENGMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_TachoRef_3db35f78_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_TachoRef_3db35f78_SigRx */

# if defined (Rte_ComHook_Tire_Press_System_Stat_610999c4_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_Tire_Press_System_Stat_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_Tire_Press_System_Stat_610999c4_SigRx)
#  undef Rte_ComHook_Tire_Press_System_Stat_610999c4_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_Tire_Press_System_Stat_610999c4_SigRx(P2VAR(uint8, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_Tire_Press_System_Stat_610999c4_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_Tire_Press_System_Stat_610999c4_SigRx */

# if defined (Rte_ComHook_WarningWaterTempCAN_46dad878_SigRx) && (RTE_VFB_TRACE == 0)
#  undef Rte_ComHook_WarningWaterTempCAN_46dad878_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ComHook_WarningWaterTempCAN_46dad878_SigRx)
#  undef Rte_ComHook_WarningWaterTempCAN_46dad878_SigRx /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ComHook_WarningWaterTempCAN_46dad878_SigRx(P2VAR(UInt8, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ComHook_WarningWaterTempCAN_46dad878_SigRx(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ComHook_WarningWaterTempCAN_46dad878_SigRx */

# if defined (Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Return)
#  undef Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Return */

# if defined (Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Start)
#  undef Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_FeedbackHook_Dcm_DcmEcuReset_DcmEcuReset_Start */

# if defined (Rte_FeedbackHook_EcuM_currentMode_currentMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_FeedbackHook_EcuM_currentMode_currentMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_FeedbackHook_EcuM_currentMode_currentMode_Return)
#  undef Rte_FeedbackHook_EcuM_currentMode_currentMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_FeedbackHook_EcuM_currentMode_currentMode_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_FeedbackHook_EcuM_currentMode_currentMode_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_FeedbackHook_EcuM_currentMode_currentMode_Return */

# if defined (Rte_FeedbackHook_EcuM_currentMode_currentMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_FeedbackHook_EcuM_currentMode_currentMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_FeedbackHook_EcuM_currentMode_currentMode_Start)
#  undef Rte_FeedbackHook_EcuM_currentMode_currentMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_FeedbackHook_EcuM_currentMode_currentMode_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_FeedbackHook_EcuM_currentMode_currentMode_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_FeedbackHook_EcuM_currentMode_currentMode_Start */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Return)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Return(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Return */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Start)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Start(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB1_BtnSignal_Start */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Return)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Return(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Return */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Start)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Start(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB2_BtnSignal_Start */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Return)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Return(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Return */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Start)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Start(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB3_BtnSignal_Start */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Return)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Return(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Return */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Start)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Start(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB4_BtnSignal_Start */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Return)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Return(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Return */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Start)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Start(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanB5_BtnSignal_Start */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Return)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Return(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Return */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Start)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Start(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Down_BtnSignal_Start */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Return)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Return(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Return */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Start)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Start(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Left_BtnSignal_Start */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Return)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Return(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Return */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Start)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Start(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_OK_BtnSignal_Start */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Return)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Return(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Return */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Start)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Start(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Right_BtnSignal_Start */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Return)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Return(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Return */

# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Start)
#  undef Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Start(P2VAR(UInt8, AUTOMATIC, RTE_BTNMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_BtnMdl_rpSR_rCIn_TIBtnMdl_ComIn_CanBtnCES_Up_BtnSignal_Start */

# if defined (Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Return)
#  undef Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Return(P2VAR(SG_RxFilteredSpeed, AUTOMATIC, RTE_CDD_TEST_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Return */

# if defined (Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Start)
#  undef Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Start(P2VAR(SG_RxFilteredSpeed, AUTOMATIC, RTE_CDD_TEST_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Start */

# if defined (Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Return)
#  undef Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Return(P2VAR(EKeyPos, AUTOMATIC, RTE_CDD_TEST_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Return */

# if defined (Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Start)
#  undef Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Start(P2VAR(EKeyPos, AUTOMATIC, RTE_CDD_TEST_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_CDD_Test_tiSR_TIModMdl_KeyPos_KeyPos_Start */

# if defined (Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Return)
#  undef Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Return(P2VAR(NvM_ECU24BytesNumberType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Return */

# if defined (Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Start)
#  undef Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Start(P2VAR(NvM_ECU24BytesNumberType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ECUDeliveryAssemblyNumber_Value_Start */

# if defined (Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Return)
#  undef Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Return(P2VAR(NvM_ECUSerialNumberType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Return */

# if defined (Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Start)
#  undef Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Start(P2VAR(NvM_ECUSerialNumberType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ECUSerialNumber_Value_Start */

# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return(P2VAR(UInt8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return */

# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start(P2VAR(UInt8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start */

# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return(P2VAR(UInt8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return */

# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start(P2VAR(UInt8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start */

# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return(P2VAR(UInt8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return */

# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start)
#  undef Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start(P2VAR(UInt8, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start */

# if defined (Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Return)
#  undef Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Return(P2VAR(NvM_ProductInfo, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Return */

# if defined (Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Start)
#  undef Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Start(P2VAR(NvM_ProductInfo, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_ProductInfo_Value_Start */

# if defined (Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Return)
#  undef Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Return(P2VAR(NvM_ECU24BytesNumberType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Return */

# if defined (Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Start)
#  undef Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Start(P2VAR(NvM_ECU24BytesNumberType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DcmExt_NV_VehicleManufacturerECUSoftwareNumber_Value_Start */

# if defined (Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Return)
#  undef Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Return(P2VAR(UInt8, AUTOMATIC, RTE_DIMMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Return */

# if defined (Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Start)
#  undef Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Start(P2VAR(UInt8, AUTOMATIC, RTE_DIMMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DimMdl_rpSR_rCIn_TIDimMdl_CIn_RxLevel_Start */

# if defined (Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Return)
#  undef Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Return(P2VAR(UInt16, AUTOMATIC, RTE_DIMVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Return */

# if defined (Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Start)
#  undef Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Start(P2VAR(UInt16, AUTOMATIC, RTE_DIMVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_DimView_tiSR_TIDimMdl_FltLevel_FltLevel_Start */

# if defined (Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Return)
#  undef Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Return(P2VAR(STRUCT_ECT_CONFIGURATION, AUTOMATIC, RTE_ECTMDLWRP_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Return */

# if defined (Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Start)
#  undef Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Start(P2VAR(STRUCT_ECT_CONFIGURATION, AUTOMATIC, RTE_ECTMDLWRP_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdlWrp_NV_EctConfiguration_EctConfiguration_Start */

# if defined (Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Return)
#  undef Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Return(P2VAR(Boolean, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Return */

# if defined (Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Start)
#  undef Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Start(P2VAR(Boolean, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdl_DownTransitionOfEngCoolantTemp_DownTransitionOfEngCoolantTemp_Start */

# if defined (Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Return)
#  undef Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Return(P2VAR(STRUCT_ECT_CONFIGURATION, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Return */

# if defined (Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Start)
#  undef Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Start(P2VAR(STRUCT_ECT_CONFIGURATION, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdl_EctConfiguration_EctConfiguration_Start */

# if defined (Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Return)
#  undef Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Return(P2VAR(UInt8, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Return */

# if defined (Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Start)
#  undef Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Start(P2VAR(UInt8, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdl_EngineCoolantTemp_EngineCoolantTemp_Start */

# if defined (Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Return)
#  undef Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Return(P2VAR(UInt8, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Return */

# if defined (Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Start)
#  undef Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Start(P2VAR(UInt8, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdl_TemperatureUnit_CF_TemperatureUnit_CF_Start */

# if defined (Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Return)
#  undef Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Return(P2VAR(UInt8, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Return */

# if defined (Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Start)
#  undef Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Start(P2VAR(UInt8, AUTOMATIC, RTE_ECTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EctMdl_WarningWaterTemp_WarningWaterTemp_Start */

# if defined (Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Return)
#  undef Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Return(P2VAR(boolean, AUTOMATIC, RTE_ECUMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Return */

# if defined (Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Start)
#  undef Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Start(P2VAR(boolean, AUTOMATIC, RTE_ECUMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EcumExt_NV_Immobilizer_Value_Start */

# if defined (Rte_ReadHook_EcumExt_NV_Language_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EcumExt_NV_Language_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EcumExt_NV_Language_Value_Return)
#  undef Rte_ReadHook_EcumExt_NV_Language_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EcumExt_NV_Language_Value_Return(P2VAR(uint8, AUTOMATIC, RTE_ECUMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EcumExt_NV_Language_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EcumExt_NV_Language_Value_Return */

# if defined (Rte_ReadHook_EcumExt_NV_Language_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EcumExt_NV_Language_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EcumExt_NV_Language_Value_Start)
#  undef Rte_ReadHook_EcumExt_NV_Language_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EcumExt_NV_Language_Value_Start(P2VAR(uint8, AUTOMATIC, RTE_ECUMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EcumExt_NV_Language_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EcumExt_NV_Language_Value_Start */

# if defined (Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Return)
#  undef Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Return(P2VAR(EKeyPos, AUTOMATIC, RTE_ECUMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Return */

# if defined (Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Start)
#  undef Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Start(P2VAR(EKeyPos, AUTOMATIC, RTE_ECUMEXT_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos_Start */

# if defined (Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Return)
#  undef Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Return(P2VAR(UInt16, AUTOMATIC, RTE_ENGMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Return */

# if defined (Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Start)
#  undef Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Start(P2VAR(UInt16, AUTOMATIC, RTE_ENGMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_EngMdl_rpSR_rCIn_TIEngMdl_ComIn_RxRpm_Start */

# if defined (Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Return)
#  undef Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Return(P2VAR(FUEL_LEVEL_CAN, AUTOMATIC, RTE_FUELMDLWRP_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Return */

# if defined (Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Start)
#  undef Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Start(P2VAR(FUEL_LEVEL_CAN, AUTOMATIC, RTE_FUELMDLWRP_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_FuelMdlWrp_ComIn_PI_FUEL_LEVEL_CAN_FUEL_LEVEL_CAN_Start */

# if defined (Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Return)
#  undef Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Return(P2VAR(STRUCT_FUEL_LEVEL_CAN, AUTOMATIC, RTE_FUELMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Return */

# if defined (Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Start)
#  undef Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Start(P2VAR(STRUCT_FUEL_LEVEL_CAN, AUTOMATIC, RTE_FUELMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_FuelMdl_FuelLevelCanR_de_FuelLevelIn_Start */

# if defined (Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Return)
#  undef Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Return(P2VAR(UFIX16_SP01, AUTOMATIC, RTE_FUELMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Return */

# if defined (Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Start)
#  undef Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Start(P2VAR(UFIX16_SP01, AUTOMATIC, RTE_FUELMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_FuelMdl_FuelLevelCanR_de_Tau_Start */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Return)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Return(P2VAR(UInt16, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Return */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Start)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Start(P2VAR(UInt16, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_rEng_TIEngMdl_Out_Tacho_Start */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Return)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Return(P2VAR(Boolean, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Return */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Start)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Start(P2VAR(Boolean, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_IsOverSpeed_Start */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Return)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Return(P2VAR(UInt16, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Return */

# if defined (Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Start)
#  undef Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Start(P2VAR(UInt16, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_rpSR_rSpd_TISpdMdl_Out_Speed_Start */

# if defined (Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Return)
#  undef Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Return(P2VAR(uint32, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Return */

# if defined (Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Start)
#  undef Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Start(P2VAR(uint32, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_tiSR_OdoOutMiles_Miles_Start */

# if defined (Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Return)
#  undef Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Return(P2VAR(sTrcOut, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Return */

# if defined (Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Start)
#  undef Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Start(P2VAR(sTrcOut, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtCtrl_tiSR_TrcOut_deTrcOut_Start */

# if defined (Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Return)
#  undef Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Return(P2VAR(uint32, AUTOMATIC, RTE_GDTDPCONN_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Return */

# if defined (Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Start)
#  undef Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Start(P2VAR(uint32, AUTOMATIC, RTE_GDTDPCONN_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtDpConn_tiSR_OdoOutMiles_Miles_Start */

# if defined (Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Return)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Return(P2VAR(UInt16, AUTOMATIC, RTE_GDTDPCONN_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Return */

# if defined (Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Start)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Start(P2VAR(UInt16, AUTOMATIC, RTE_GDTDPCONN_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtDpConn_tiSR_TIEngMdl_Out_TachoF_Tacho_Start */

# if defined (Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Return)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Return(P2VAR(UInt16, AUTOMATIC, RTE_GDTDPCONN_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Return */

# if defined (Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Start)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Start(P2VAR(UInt16, AUTOMATIC, RTE_GDTDPCONN_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtDpConn_tiSR_TISpdMdl_Out_SpdF_Speed_Start */

# if defined (Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Return)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Return(P2VAR(sTrcOut, AUTOMATIC, RTE_GDTDPCONN_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Return */

# if defined (Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Start)
#  undef Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Start(P2VAR(sTrcOut, AUTOMATIC, RTE_GDTDPCONN_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_GdtDpConn_tiSR_TrcOut_deTrcOut_Start */

# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Return)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Return(P2VAR(UInt8, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Return */

# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Start)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Start(P2VAR(UInt8, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTER_Start */

# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Return)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Return(P2VAR(UInt8, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Return */

# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Start)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Start(P2VAR(UInt8, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_ENTRY_Start */

# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Return)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Return(P2VAR(UInt8, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Return */

# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Start)
#  undef Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Start(P2VAR(UInt8, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_NV_ETM_Timeouts_ETM_EXIT_Start */

# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B3_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B4_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B5_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B6_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_rpSR_pBtnState_B7_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return)
#  undef Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return(P2VAR(EKeyPos, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return */

# if defined (Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start)
#  undef Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start(P2VAR(EKeyPos, AUTOMATIC, RTE_HMICTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_HmiCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start */

# if defined (Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Return)
#  undef Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Return(P2VAR(UInt8, AUTOMATIC, RTE_MODMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Return */

# if defined (Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Start)
#  undef Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Start(P2VAR(UInt8, AUTOMATIC, RTE_MODMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_ModMdl_rpSR_rComIn_TIModMdl_ComIn_RxCarModes_Start */

# if defined (Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return)
#  undef Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return(P2VAR(OdoDataSetType, AUTOMATIC, RTE_ODOMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return */

# if defined (Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start)
#  undef Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start(P2VAR(OdoDataSetType, AUTOMATIC, RTE_ODOMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start */

# if defined (Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Return)
#  undef Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Return(P2VAR(UInt16, AUTOMATIC, RTE_ODOMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Return */

# if defined (Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Start)
#  undef Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Start(P2VAR(UInt16, AUTOMATIC, RTE_ODOMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Start */

# if defined (Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return)
#  undef Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return(P2VAR(UInt8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return */

# if defined (Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start)
#  undef Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start(P2VAR(UInt8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start */

# if defined (Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Return)
#  undef Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Return(P2VAR(UFIX16_SP001, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Return */

# if defined (Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Start)
#  undef Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Start(P2VAR(UFIX16_SP001, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_FuelLevelCanS_de_FuelLevelOut_Start */

# if defined (Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Return)
#  undef Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Return(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Return */

# if defined (Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Start)
#  undef Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Start(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_X_Value_Start */

# if defined (Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Return)
#  undef Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Return(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Return */

# if defined (Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Start)
#  undef Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Start(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Ect_Gauge_Mapping_Table_Y_Value_Start */

# if defined (Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Return)
#  undef Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Return(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Return */

# if defined (Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Start)
#  undef Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Start(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_X_Value_Start */

# if defined (Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Return)
#  undef Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Return(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Return */

# if defined (Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Start)
#  undef Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Start(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Fuel_Gauge_Mapping_Table_Y_Value_Start */

# if defined (Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Return)
#  undef Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Return(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Return */

# if defined (Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Start)
#  undef Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Start(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_X_Value_Start */

# if defined (Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Return)
#  undef Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Return(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Return */

# if defined (Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Start)
#  undef Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Start(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_RPM_Gauge_Mapping_Table_Y_Value_Start */

# if defined (Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Return)
#  undef Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Return(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Return */

# if defined (Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Start)
#  undef Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Start(P2VAR(Gauge_Mapping_Table_X, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_X_Value_Start */

# if defined (Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Return)
#  undef Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Return(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Return */

# if defined (Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Start)
#  undef Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Start(P2VAR(Gauge_Mapping_Table_Y, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_NV_Spd_Gauge_Mapping_Table_Y_Value_Start */

# if defined (Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Return)
#  undef Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Return(P2VAR(UInt16, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Return */

# if defined (Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Start)
#  undef Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Start(P2VAR(UInt16, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_tiSR_TIEngMdl_Out_TachoF_Tacho_Start */

# if defined (Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Return)
#  undef Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Return(P2VAR(UInt16, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Return */

# if defined (Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Start)
#  undef Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Start(P2VAR(UInt16, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_PtrView_tiSR_TISpdMdl_Out_SpdF_Speed_Start */

# if defined (Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Return)
#  undef Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Return(P2VAR(ETtMdlMask, AUTOMATIC, RTE_SNDVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Return */

# if defined (Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Start)
#  undef Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Start(P2VAR(ETtMdlMask, AUTOMATIC, RTE_SNDVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_SndView_tiSR_TITtMdl_TtMask_TtMask_Start */

# if defined (Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Return)
#  undef Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Return(P2VAR(UInt16, AUTOMATIC, RTE_SPDMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Return */

# if defined (Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Start)
#  undef Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Start(P2VAR(UInt16, AUTOMATIC, RTE_SPDMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_SpdMdl_rpSR_rCIn_TISpdMdl_ComIn_RxSpeed_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Return(P2VAR(Gauge_Correction_Table_X, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Start(P2VAR(Gauge_Correction_Table_X, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_X_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Return(P2VAR(Gauge_Correction_Table_Y, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Start(P2VAR(Gauge_Correction_Table_Y, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Ect_Gauge_Correction_Table_Y_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Return(P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Start(P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Ect_Magnetic_Offset_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Return(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Start(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Ect_Sleep_Offset_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Return(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Start(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Ect_Zero_Software_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Return(P2VAR(Gauge_Correction_Table_X, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Start(P2VAR(Gauge_Correction_Table_X, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_X_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Return(P2VAR(Gauge_Correction_Table_Y, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Start(P2VAR(Gauge_Correction_Table_Y, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Fuel_Gauge_Correction_Table_Y_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Return(P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Start(P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Fuel_Magnetic_Offset_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Return(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Start(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Fuel_Sleep_Offset_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Return(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Start(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Fuel_Zero_Software_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Return(P2VAR(Gauge_Correction_Table_X, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Start(P2VAR(Gauge_Correction_Table_X, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_X_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Return(P2VAR(Gauge_Correction_Table_Y, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Start(P2VAR(Gauge_Correction_Table_Y, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_RPM_Gauge_Correction_Table_Y_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Return(P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Start(P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_RPM_Magnetic_Offset_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Return(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Start(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_RPM_Sleep_Offset_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Return(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Start(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_RPM_Zero_Software_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Return(P2VAR(Gauge_Correction_Table_X, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Start(P2VAR(Gauge_Correction_Table_X, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_X_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Return(P2VAR(Gauge_Correction_Table_Y, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Start(P2VAR(Gauge_Correction_Table_Y, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Spd_Gauge_Correction_Table_Y_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Return(P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Start(P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Spd_Magnetic_Offset_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Return(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Start(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Spd_Sleep_Offset_Value_Start */

# if defined (Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Return)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Return(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Return */

# if defined (Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Start)
#  undef Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Start(P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_StpCdd_NV_Spd_Zero_Software_Value_Start */

# if defined (Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Return)
#  undef Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Return(P2VAR(UFIX16_SP001, AUTOMATIC, RTE_TRIPMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Return */

# if defined (Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Start)
#  undef Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Start(P2VAR(UFIX16_SP001, AUTOMATIC, RTE_TRIPMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TripMdl_FuelLevelCanS_de_FuelLevelOut_Start */

# if defined (Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Return)
#  undef Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Return(P2VAR(uint32, AUTOMATIC, RTE_TRIPMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Return */

# if defined (Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Start)
#  undef Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Start(P2VAR(uint32, AUTOMATIC, RTE_TRIPMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TripMdl_tiSR_OdoOutMiles_Miles_Start */

# if defined (Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Return)
#  undef Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Return(P2VAR(EKeyPos, AUTOMATIC, RTE_TRIPMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Return */

# if defined (Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Start)
#  undef Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Start(P2VAR(EKeyPos, AUTOMATIC, RTE_TRIPMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos_Start */

# if defined (Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_TTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_TTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TtMdl_rpSR_rBtn1_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Return)
#  undef Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Return(P2VAR(UInt8, AUTOMATIC, RTE_TTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Return */

# if defined (Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Start)
#  undef Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Start(P2VAR(UInt8, AUTOMATIC, RTE_TTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxLeftTurnOn_Start */

# if defined (Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Return)
#  undef Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Return(P2VAR(UInt8, AUTOMATIC, RTE_TTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Return */

# if defined (Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Start)
#  undef Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Start(P2VAR(UInt8, AUTOMATIC, RTE_TTMDL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TtMdl_rpSR_rComIn_TITtMdl_ComIn_RxRightTurnOn_Start */

# if defined (Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Return)
#  undef Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Return(P2VAR(EBtnState, AUTOMATIC, RTE_TTVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Return */

# if defined (Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Start)
#  undef Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Start(P2VAR(EBtnState, AUTOMATIC, RTE_TTVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TtView_rpSR_pBtnState_B1_TIBtnMdl_State_State_Start */

# if defined (Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Return)
#  undef Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Return(P2VAR(ETtMdlMask, AUTOMATIC, RTE_TTVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Return */

# if defined (Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Start)
#  undef Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Start(P2VAR(ETtMdlMask, AUTOMATIC, RTE_TTVIEW_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_TtView_tiSR_TITtMdl_TtMask_TtMask_Start */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return(P2VAR(EKeyPos, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Return */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start(P2VAR(EKeyPos, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIModMdl_KeyPos_KeyPos_Start */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Return)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Return(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Return */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Start)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Start(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TISpdMdl_Out_IsOverSpeed_Start */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Return)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Return(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Return */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Start)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Start(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_BrkLamp_Start */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Return)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Return(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Return */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Start)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Start(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Disable_Neutral_Tow_Start */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Return)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Return(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Return */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Start)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Start(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatDrv_B_Actl_Start */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Return)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Return(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Return */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Start)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Start(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_DrStatPsngr_B_Actl_Start */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Return)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Return(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Return */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Start)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Start(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Enable_Neutral_Tow_Start */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Return)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Return(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Return */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Start)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Start(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_MyKey_Active_Start */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Return)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Return(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Return */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Start)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Start(P2VAR(Boolean, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Slow_For_HDC_Start */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Return)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Return(P2VAR(uint8, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Return */

# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Start)
#  undef Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Start(P2VAR(uint8, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_ReadHook_WrnCtrl_tiSR_TIWrnCtrl_CIn_Tire_Pres_System_Stat_Start */

# if defined (Rte_Runnable_BswM_BswM_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_BswM_BswM_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_BswM_BswM_MainFunction_Return)
#  undef Rte_Runnable_BswM_BswM_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_BswM_BswM_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_BswM_BswM_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_BswM_BswM_MainFunction_Return */

# if defined (Rte_Runnable_BswM_BswM_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_BswM_BswM_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_BswM_BswM_MainFunction_Start)
#  undef Rte_Runnable_BswM_BswM_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_BswM_BswM_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_BswM_BswM_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_BswM_BswM_MainFunction_Start */

# if defined (Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Return)
#  undef Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Start)
#  undef Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_BtnMdl_CBtnMdl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Return)
#  undef Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Start)
#  undef Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_BtnMdl_CBtnMdl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Return)
#  undef Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Return */

# if defined (Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Start)
#  undef Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_CDD_Test_CDD_Test_MainFunction_Start */

# if defined (Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Return)
#  undef Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Return */

# if defined (Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Start)
#  undef Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_CDD_Test_CDD_Test_StackMeasure_Start */

# if defined (Rte_Runnable_ComM_ComM_MainFunction_0_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_ComM_MainFunction_0_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_ComM_MainFunction_0_Return)
#  undef Rte_Runnable_ComM_ComM_MainFunction_0_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_ComM_MainFunction_0_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_ComM_MainFunction_0_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_ComM_MainFunction_0_Return */

# if defined (Rte_Runnable_ComM_ComM_MainFunction_0_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_ComM_MainFunction_0_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_ComM_MainFunction_0_Start)
#  undef Rte_Runnable_ComM_ComM_MainFunction_0_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_ComM_MainFunction_0_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_ComM_MainFunction_0_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_ComM_MainFunction_0_Start */

# if defined (Rte_Runnable_ComM_GetCurrentComMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_GetCurrentComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_GetCurrentComMode_Return)
#  undef Rte_Runnable_ComM_GetCurrentComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_GetCurrentComMode_Return(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_GetCurrentComMode_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_GetCurrentComMode_Return */

# if defined (Rte_Runnable_ComM_GetCurrentComMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_GetCurrentComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_GetCurrentComMode_Start)
#  undef Rte_Runnable_ComM_GetCurrentComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_GetCurrentComMode_Start(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_GetCurrentComMode_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_GetCurrentComMode_Start */

# if defined (Rte_Runnable_ComM_GetInhibitionStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_GetInhibitionStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_GetInhibitionStatus_Return)
#  undef Rte_Runnable_ComM_GetInhibitionStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_GetInhibitionStatus_Return(NetworkHandleType parg0, P2VAR(ComM_InhibitionStatusType, AUTOMATIC, RTE_COMM_APPL_VAR) Status); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_GetInhibitionStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_GetInhibitionStatus_Return */

# if defined (Rte_Runnable_ComM_GetInhibitionStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_GetInhibitionStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_GetInhibitionStatus_Start)
#  undef Rte_Runnable_ComM_GetInhibitionStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_GetInhibitionStatus_Start(NetworkHandleType parg0, P2VAR(ComM_InhibitionStatusType, AUTOMATIC, RTE_COMM_APPL_VAR) Status); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_GetInhibitionStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_GetInhibitionStatus_Start */

# if defined (Rte_Runnable_ComM_GetMaxComMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_GetMaxComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_GetMaxComMode_Return)
#  undef Rte_Runnable_ComM_GetMaxComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_GetMaxComMode_Return(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_GetMaxComMode_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_GetMaxComMode_Return */

# if defined (Rte_Runnable_ComM_GetMaxComMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_GetMaxComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_GetMaxComMode_Start)
#  undef Rte_Runnable_ComM_GetMaxComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_GetMaxComMode_Start(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_GetMaxComMode_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_GetMaxComMode_Start */

# if defined (Rte_Runnable_ComM_GetRequestedComMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_GetRequestedComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_GetRequestedComMode_Return)
#  undef Rte_Runnable_ComM_GetRequestedComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_GetRequestedComMode_Return(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_GetRequestedComMode_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_GetRequestedComMode_Return */

# if defined (Rte_Runnable_ComM_GetRequestedComMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_GetRequestedComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_GetRequestedComMode_Start)
#  undef Rte_Runnable_ComM_GetRequestedComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_GetRequestedComMode_Start(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_GetRequestedComMode_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_GetRequestedComMode_Start */

# if defined (Rte_Runnable_ComM_LimitChannelToNoComMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_LimitChannelToNoComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_LimitChannelToNoComMode_Return)
#  undef Rte_Runnable_ComM_LimitChannelToNoComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_LimitChannelToNoComMode_Return(NetworkHandleType parg0, boolean Status); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_LimitChannelToNoComMode_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_LimitChannelToNoComMode_Return */

# if defined (Rte_Runnable_ComM_LimitChannelToNoComMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_LimitChannelToNoComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_LimitChannelToNoComMode_Start)
#  undef Rte_Runnable_ComM_LimitChannelToNoComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_LimitChannelToNoComMode_Start(NetworkHandleType parg0, boolean Status); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_LimitChannelToNoComMode_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_LimitChannelToNoComMode_Start */

# if defined (Rte_Runnable_ComM_LimitECUToNoComMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_LimitECUToNoComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_LimitECUToNoComMode_Return)
#  undef Rte_Runnable_ComM_LimitECUToNoComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_LimitECUToNoComMode_Return(boolean Status); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_LimitECUToNoComMode_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_LimitECUToNoComMode_Return */

# if defined (Rte_Runnable_ComM_LimitECUToNoComMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_LimitECUToNoComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_LimitECUToNoComMode_Start)
#  undef Rte_Runnable_ComM_LimitECUToNoComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_LimitECUToNoComMode_Start(boolean Status); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_LimitECUToNoComMode_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_LimitECUToNoComMode_Start */

# if defined (Rte_Runnable_ComM_PreventWakeUp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_PreventWakeUp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_PreventWakeUp_Return)
#  undef Rte_Runnable_ComM_PreventWakeUp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_PreventWakeUp_Return(NetworkHandleType parg0, boolean Status); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_PreventWakeUp_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_PreventWakeUp_Return */

# if defined (Rte_Runnable_ComM_PreventWakeUp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_PreventWakeUp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_PreventWakeUp_Start)
#  undef Rte_Runnable_ComM_PreventWakeUp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_PreventWakeUp_Start(NetworkHandleType parg0, boolean Status); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_PreventWakeUp_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_PreventWakeUp_Start */

# if defined (Rte_Runnable_ComM_ReadInhibitCounter_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_ReadInhibitCounter_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_ReadInhibitCounter_Return)
#  undef Rte_Runnable_ComM_ReadInhibitCounter_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_ReadInhibitCounter_Return(P2VAR(uint16, AUTOMATIC, RTE_COMM_APPL_VAR) CounterValue); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_ReadInhibitCounter_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_ReadInhibitCounter_Return */

# if defined (Rte_Runnable_ComM_ReadInhibitCounter_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_ReadInhibitCounter_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_ReadInhibitCounter_Start)
#  undef Rte_Runnable_ComM_ReadInhibitCounter_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_ReadInhibitCounter_Start(P2VAR(uint16, AUTOMATIC, RTE_COMM_APPL_VAR) CounterValue); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_ReadInhibitCounter_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_ReadInhibitCounter_Start */

# if defined (Rte_Runnable_ComM_RequestComMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_RequestComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_RequestComMode_Return)
#  undef Rte_Runnable_ComM_RequestComMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_RequestComMode_Return(ComM_UserHandleType parg0, ComM_ModeType ComMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_RequestComMode_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_RequestComMode_Return */

# if defined (Rte_Runnable_ComM_RequestComMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_RequestComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_RequestComMode_Start)
#  undef Rte_Runnable_ComM_RequestComMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_RequestComMode_Start(ComM_UserHandleType parg0, ComM_ModeType ComMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_RequestComMode_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_RequestComMode_Start */

# if defined (Rte_Runnable_ComM_ResetInhibitCounter_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_ResetInhibitCounter_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_ResetInhibitCounter_Return)
#  undef Rte_Runnable_ComM_ResetInhibitCounter_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_ResetInhibitCounter_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_ResetInhibitCounter_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_ResetInhibitCounter_Return */

# if defined (Rte_Runnable_ComM_ResetInhibitCounter_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_ResetInhibitCounter_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_ResetInhibitCounter_Start)
#  undef Rte_Runnable_ComM_ResetInhibitCounter_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_ResetInhibitCounter_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_ResetInhibitCounter_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_ResetInhibitCounter_Start */

# if defined (Rte_Runnable_ComM_SetECUGroupClassification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_SetECUGroupClassification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_SetECUGroupClassification_Return)
#  undef Rte_Runnable_ComM_SetECUGroupClassification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_SetECUGroupClassification_Return(ComM_InhibitionStatusType Status); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_SetECUGroupClassification_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_SetECUGroupClassification_Return */

# if defined (Rte_Runnable_ComM_SetECUGroupClassification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ComM_SetECUGroupClassification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ComM_SetECUGroupClassification_Start)
#  undef Rte_Runnable_ComM_SetECUGroupClassification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ComM_SetECUGroupClassification_Start(ComM_InhibitionStatusType Status); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ComM_SetECUGroupClassification_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ComM_SetECUGroupClassification_Start */

# if defined (Rte_Runnable_DcmExt_dummy_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DcmExt_dummy_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DcmExt_dummy_Return)
#  undef Rte_Runnable_DcmExt_dummy_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DcmExt_dummy_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DcmExt_dummy_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DcmExt_dummy_Return */

# if defined (Rte_Runnable_DcmExt_dummy_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DcmExt_dummy_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DcmExt_dummy_Start)
#  undef Rte_Runnable_DcmExt_dummy_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DcmExt_dummy_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DcmExt_dummy_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DcmExt_dummy_Start */

# if defined (Rte_Runnable_Dcm_Dcm_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dcm_Dcm_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dcm_Dcm_MainFunction_Return)
#  undef Rte_Runnable_Dcm_Dcm_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dcm_Dcm_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dcm_Dcm_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dcm_Dcm_MainFunction_Return */

# if defined (Rte_Runnable_Dcm_Dcm_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dcm_Dcm_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dcm_Dcm_MainFunction_Start)
#  undef Rte_Runnable_Dcm_Dcm_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dcm_Dcm_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dcm_Dcm_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dcm_Dcm_MainFunction_Start */

# if defined (Rte_Runnable_Dcm_GetActiveProtocol_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dcm_GetActiveProtocol_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dcm_GetActiveProtocol_Return)
#  undef Rte_Runnable_Dcm_GetActiveProtocol_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dcm_GetActiveProtocol_Return(P2VAR(Dcm_ProtocolType, AUTOMATIC, RTE_DCM_APPL_VAR) ActiveProtocol); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dcm_GetActiveProtocol_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dcm_GetActiveProtocol_Return */

# if defined (Rte_Runnable_Dcm_GetActiveProtocol_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dcm_GetActiveProtocol_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dcm_GetActiveProtocol_Start)
#  undef Rte_Runnable_Dcm_GetActiveProtocol_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dcm_GetActiveProtocol_Start(P2VAR(Dcm_ProtocolType, AUTOMATIC, RTE_DCM_APPL_VAR) ActiveProtocol); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dcm_GetActiveProtocol_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dcm_GetActiveProtocol_Start */

# if defined (Rte_Runnable_Dcm_GetSecurityLevel_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dcm_GetSecurityLevel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dcm_GetSecurityLevel_Return)
#  undef Rte_Runnable_Dcm_GetSecurityLevel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dcm_GetSecurityLevel_Return(P2VAR(Dcm_SecLevelType, AUTOMATIC, RTE_DCM_APPL_VAR) SecLevel); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dcm_GetSecurityLevel_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dcm_GetSecurityLevel_Return */

# if defined (Rte_Runnable_Dcm_GetSecurityLevel_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dcm_GetSecurityLevel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dcm_GetSecurityLevel_Start)
#  undef Rte_Runnable_Dcm_GetSecurityLevel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dcm_GetSecurityLevel_Start(P2VAR(Dcm_SecLevelType, AUTOMATIC, RTE_DCM_APPL_VAR) SecLevel); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dcm_GetSecurityLevel_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dcm_GetSecurityLevel_Start */

# if defined (Rte_Runnable_Dcm_GetSesCtrlType_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dcm_GetSesCtrlType_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dcm_GetSesCtrlType_Return)
#  undef Rte_Runnable_Dcm_GetSesCtrlType_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dcm_GetSesCtrlType_Return(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dcm_GetSesCtrlType_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dcm_GetSesCtrlType_Return */

# if defined (Rte_Runnable_Dcm_GetSesCtrlType_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dcm_GetSesCtrlType_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dcm_GetSesCtrlType_Start)
#  undef Rte_Runnable_Dcm_GetSesCtrlType_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dcm_GetSesCtrlType_Start(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dcm_GetSesCtrlType_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dcm_GetSesCtrlType_Start */

# if defined (Rte_Runnable_Dcm_ResetToDefaultSession_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dcm_ResetToDefaultSession_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dcm_ResetToDefaultSession_Return)
#  undef Rte_Runnable_Dcm_ResetToDefaultSession_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dcm_ResetToDefaultSession_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dcm_ResetToDefaultSession_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dcm_ResetToDefaultSession_Return */

# if defined (Rte_Runnable_Dcm_ResetToDefaultSession_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dcm_ResetToDefaultSession_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dcm_ResetToDefaultSession_Start)
#  undef Rte_Runnable_Dcm_ResetToDefaultSession_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dcm_ResetToDefaultSession_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dcm_ResetToDefaultSession_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dcm_ResetToDefaultSession_Start */

# if defined (Rte_Runnable_Dem_ClearDTC_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_ClearDTC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_ClearDTC_Return)
#  undef Rte_Runnable_Dem_ClearDTC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_ClearDTC_Return(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_ClearDTC_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_ClearDTC_Return */

# if defined (Rte_Runnable_Dem_ClearDTC_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_ClearDTC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_ClearDTC_Start)
#  undef Rte_Runnable_Dem_ClearDTC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_ClearDTC_Start(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_ClearDTC_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_ClearDTC_Start */

# if defined (Rte_Runnable_Dem_DcmClearDTC_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_DcmClearDTC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_DcmClearDTC_Return)
#  undef Rte_Runnable_Dem_DcmClearDTC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_DcmClearDTC_Return(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_DcmClearDTC_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_DcmClearDTC_Return */

# if defined (Rte_Runnable_Dem_DcmClearDTC_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_DcmClearDTC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_DcmClearDTC_Start)
#  undef Rte_Runnable_Dem_DcmClearDTC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_DcmClearDTC_Start(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_DcmClearDTC_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_DcmClearDTC_Start */

# if defined (Rte_Runnable_Dem_DcmEnableDTCSetting_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_DcmEnableDTCSetting_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_DcmEnableDTCSetting_Return)
#  undef Rte_Runnable_Dem_DcmEnableDTCSetting_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_DcmEnableDTCSetting_Return(Dem_DTCGroupType DTCGroup, Dem_DTCKindType DTCKind); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_DcmEnableDTCSetting_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_DcmEnableDTCSetting_Return */

# if defined (Rte_Runnable_Dem_DcmEnableDTCSetting_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_DcmEnableDTCSetting_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_DcmEnableDTCSetting_Start)
#  undef Rte_Runnable_Dem_DcmEnableDTCSetting_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_DcmEnableDTCSetting_Start(Dem_DTCGroupType DTCGroup, Dem_DTCKindType DTCKind); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_DcmEnableDTCSetting_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_DcmEnableDTCSetting_Start */

# if defined (Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Return)
#  undef Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Return(uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8 ExtendedDataNumber, P2VAR(uint8, AUTOMATIC, RTE_DEM_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEM_APPL_VAR) BufSize); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Return(arg1, arg2, arg3, arg4, arg5) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Return */

# if defined (Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Start)
#  undef Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Start(uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8 ExtendedDataNumber, P2VAR(uint8, AUTOMATIC, RTE_DEM_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEM_APPL_VAR) BufSize); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Start(arg1, arg2, arg3, arg4, arg5) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_DcmGetExtendedDataRecordByDTC_Start */

# if defined (Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Return)
#  undef Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Return(uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, RTE_DEM_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEM_APPL_VAR) BufSize); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Return(arg1, arg2, arg3, arg4, arg5) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Return */

# if defined (Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Start)
#  undef Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Start(uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, RTE_DEM_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEM_APPL_VAR) BufSize); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Start(arg1, arg2, arg3, arg4, arg5) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_DcmGetFreezeFrameDataByDTC_Start */

# if defined (Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Return)
#  undef Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Return(P2VAR(uint32, AUTOMATIC, RTE_DEM_APPL_VAR) DTC, P2VAR(sint8, AUTOMATIC, RTE_DEM_APPL_VAR) DTCFaultDetectionCounter); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Return */

# if defined (Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Start)
#  undef Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Start(P2VAR(uint32, AUTOMATIC, RTE_DEM_APPL_VAR) DTC, P2VAR(sint8, AUTOMATIC, RTE_DEM_APPL_VAR) DTCFaultDetectionCounter); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_DcmGetNextFilteredDTCAndFDC_Start */

# if defined (Rte_Runnable_Dem_Dem_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_Dem_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_Dem_MainFunction_Return)
#  undef Rte_Runnable_Dem_Dem_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_Dem_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_Dem_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_Dem_MainFunction_Return */

# if defined (Rte_Runnable_Dem_Dem_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_Dem_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_Dem_MainFunction_Start)
#  undef Rte_Runnable_Dem_Dem_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_Dem_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_Dem_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_Dem_MainFunction_Start */

# if defined (Rte_Runnable_Dem_GetDTCOfEvent_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetDTCOfEvent_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetDTCOfEvent_Return)
#  undef Rte_Runnable_Dem_GetDTCOfEvent_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetDTCOfEvent_Return(Dem_EventIdType parg0, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEM_APPL_VAR) DTCOfEvent); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetDTCOfEvent_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetDTCOfEvent_Return */

# if defined (Rte_Runnable_Dem_GetDTCOfEvent_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetDTCOfEvent_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetDTCOfEvent_Start)
#  undef Rte_Runnable_Dem_GetDTCOfEvent_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetDTCOfEvent_Start(Dem_EventIdType parg0, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEM_APPL_VAR) DTCOfEvent); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetDTCOfEvent_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetDTCOfEvent_Start */

# if defined (Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Return)
#  undef Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Return(P2VAR(uint8, AUTOMATIC, RTE_DEM_APPL_VAR) DTCStatusMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Return */

# if defined (Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Start)
#  undef Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Start(P2VAR(uint8, AUTOMATIC, RTE_DEM_APPL_VAR) DTCStatusMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetDTCStatusAvailabilityMask_Start */

# if defined (Rte_Runnable_Dem_GetDebouncingOfEvent_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetDebouncingOfEvent_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetDebouncingOfEvent_Return)
#  undef Rte_Runnable_Dem_GetDebouncingOfEvent_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetDebouncingOfEvent_Return(Dem_EventIdType parg0, P2VAR(Dem_DebouncingStateType, AUTOMATIC, RTE_DEM_APPL_VAR) DebouncingState); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetDebouncingOfEvent_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetDebouncingOfEvent_Return */

# if defined (Rte_Runnable_Dem_GetDebouncingOfEvent_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetDebouncingOfEvent_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetDebouncingOfEvent_Start)
#  undef Rte_Runnable_Dem_GetDebouncingOfEvent_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetDebouncingOfEvent_Start(Dem_EventIdType parg0, P2VAR(Dem_DebouncingStateType, AUTOMATIC, RTE_DEM_APPL_VAR) DebouncingState); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetDebouncingOfEvent_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetDebouncingOfEvent_Start */

# if defined (Rte_Runnable_Dem_GetEventEnableCondition_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventEnableCondition_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventEnableCondition_Return)
#  undef Rte_Runnable_Dem_GetEventEnableCondition_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventEnableCondition_Return(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEM_APPL_VAR) ConditionFullfilled); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventEnableCondition_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventEnableCondition_Return */

# if defined (Rte_Runnable_Dem_GetEventEnableCondition_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventEnableCondition_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventEnableCondition_Start)
#  undef Rte_Runnable_Dem_GetEventEnableCondition_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventEnableCondition_Start(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEM_APPL_VAR) ConditionFullfilled); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventEnableCondition_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventEnableCondition_Start */

# if defined (Rte_Runnable_Dem_GetEventExtendedDataRecord_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventExtendedDataRecord_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventExtendedDataRecord_Return)
#  undef Rte_Runnable_Dem_GetEventExtendedDataRecord_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventExtendedDataRecord_Return(Dem_EventIdType parg0, uint8 RecordNumber, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEM_APPL_VAR) DestBuffer); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventExtendedDataRecord_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventExtendedDataRecord_Return */

# if defined (Rte_Runnable_Dem_GetEventExtendedDataRecord_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventExtendedDataRecord_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventExtendedDataRecord_Start)
#  undef Rte_Runnable_Dem_GetEventExtendedDataRecord_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventExtendedDataRecord_Start(Dem_EventIdType parg0, uint8 RecordNumber, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEM_APPL_VAR) DestBuffer); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventExtendedDataRecord_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventExtendedDataRecord_Start */

# if defined (Rte_Runnable_Dem_GetEventFailed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventFailed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventFailed_Return)
#  undef Rte_Runnable_Dem_GetEventFailed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventFailed_Return(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEM_APPL_VAR) EventFailed); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventFailed_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventFailed_Return */

# if defined (Rte_Runnable_Dem_GetEventFailed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventFailed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventFailed_Start)
#  undef Rte_Runnable_Dem_GetEventFailed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventFailed_Start(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEM_APPL_VAR) EventFailed); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventFailed_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventFailed_Start */

# if defined (Rte_Runnable_Dem_GetEventFreezeFrameData_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventFreezeFrameData_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventFreezeFrameData_Return)
#  undef Rte_Runnable_Dem_GetEventFreezeFrameData_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventFreezeFrameData_Return(Dem_EventIdType parg0, uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEM_APPL_VAR) DestBuffer); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventFreezeFrameData_Return(arg1, arg2, arg3, arg4, arg5) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventFreezeFrameData_Return */

# if defined (Rte_Runnable_Dem_GetEventFreezeFrameData_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventFreezeFrameData_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventFreezeFrameData_Start)
#  undef Rte_Runnable_Dem_GetEventFreezeFrameData_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventFreezeFrameData_Start(Dem_EventIdType parg0, uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEM_APPL_VAR) DestBuffer); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventFreezeFrameData_Start(arg1, arg2, arg3, arg4, arg5) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventFreezeFrameData_Start */

# if defined (Rte_Runnable_Dem_GetEventMemoryOverflow_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventMemoryOverflow_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventMemoryOverflow_Return)
#  undef Rte_Runnable_Dem_GetEventMemoryOverflow_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventMemoryOverflow_Return(Dem_DTCOriginType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEM_APPL_VAR) OverflowIndication); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventMemoryOverflow_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventMemoryOverflow_Return */

# if defined (Rte_Runnable_Dem_GetEventMemoryOverflow_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventMemoryOverflow_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventMemoryOverflow_Start)
#  undef Rte_Runnable_Dem_GetEventMemoryOverflow_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventMemoryOverflow_Start(Dem_DTCOriginType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEM_APPL_VAR) OverflowIndication); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventMemoryOverflow_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventMemoryOverflow_Start */

# if defined (Rte_Runnable_Dem_GetEventStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventStatus_Return)
#  undef Rte_Runnable_Dem_GetEventStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventStatus_Return(Dem_EventIdType parg0, P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_DEM_APPL_VAR) EventStatusExtended); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventStatus_Return */

# if defined (Rte_Runnable_Dem_GetEventStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventStatus_Start)
#  undef Rte_Runnable_Dem_GetEventStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventStatus_Start(Dem_EventIdType parg0, P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_DEM_APPL_VAR) EventStatusExtended); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventStatus_Start */

# if defined (Rte_Runnable_Dem_GetEventTested_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventTested_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventTested_Return)
#  undef Rte_Runnable_Dem_GetEventTested_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventTested_Return(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEM_APPL_VAR) EventTested); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventTested_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventTested_Return */

# if defined (Rte_Runnable_Dem_GetEventTested_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetEventTested_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetEventTested_Start)
#  undef Rte_Runnable_Dem_GetEventTested_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetEventTested_Start(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEM_APPL_VAR) EventTested); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetEventTested_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetEventTested_Start */

# if defined (Rte_Runnable_Dem_GetFaultDetectionCounter_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetFaultDetectionCounter_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetFaultDetectionCounter_Return)
#  undef Rte_Runnable_Dem_GetFaultDetectionCounter_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetFaultDetectionCounter_Return(Dem_EventIdType parg0, P2VAR(sint8, AUTOMATIC, RTE_DEM_APPL_VAR) FaultDetectionCounter); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetFaultDetectionCounter_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetFaultDetectionCounter_Return */

# if defined (Rte_Runnable_Dem_GetFaultDetectionCounter_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetFaultDetectionCounter_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetFaultDetectionCounter_Start)
#  undef Rte_Runnable_Dem_GetFaultDetectionCounter_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetFaultDetectionCounter_Start(Dem_EventIdType parg0, P2VAR(sint8, AUTOMATIC, RTE_DEM_APPL_VAR) FaultDetectionCounter); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetFaultDetectionCounter_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetFaultDetectionCounter_Start */

# if defined (Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Return)
#  undef Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Return(Dem_DTCOriginType parg0, P2VAR(uint8, AUTOMATIC, RTE_DEM_APPL_VAR) NumberOfEventMemoryEntries); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Return */

# if defined (Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Start)
#  undef Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Start(Dem_DTCOriginType parg0, P2VAR(uint8, AUTOMATIC, RTE_DEM_APPL_VAR) NumberOfEventMemoryEntries); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_GetNumberOfEventMemoryEntries_Start */

# if defined (Rte_Runnable_Dem_PostRunRequested_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_PostRunRequested_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_PostRunRequested_Return)
#  undef Rte_Runnable_Dem_PostRunRequested_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_PostRunRequested_Return(P2VAR(boolean, AUTOMATIC, RTE_DEM_APPL_VAR) IsRequested); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_PostRunRequested_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_PostRunRequested_Return */

# if defined (Rte_Runnable_Dem_PostRunRequested_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_PostRunRequested_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_PostRunRequested_Start)
#  undef Rte_Runnable_Dem_PostRunRequested_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_PostRunRequested_Start(P2VAR(boolean, AUTOMATIC, RTE_DEM_APPL_VAR) IsRequested); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_PostRunRequested_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_PostRunRequested_Start */

# if defined (Rte_Runnable_Dem_ResetEventDebounceStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_ResetEventDebounceStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_ResetEventDebounceStatus_Return)
#  undef Rte_Runnable_Dem_ResetEventDebounceStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_ResetEventDebounceStatus_Return(Dem_EventIdType parg0, Dem_DebounceResetStatusType DebounceResetStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_ResetEventDebounceStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_ResetEventDebounceStatus_Return */

# if defined (Rte_Runnable_Dem_ResetEventDebounceStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_ResetEventDebounceStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_ResetEventDebounceStatus_Start)
#  undef Rte_Runnable_Dem_ResetEventDebounceStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_ResetEventDebounceStatus_Start(Dem_EventIdType parg0, Dem_DebounceResetStatusType DebounceResetStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_ResetEventDebounceStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_ResetEventDebounceStatus_Start */

# if defined (Rte_Runnable_Dem_ResetEventStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_ResetEventStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_ResetEventStatus_Return)
#  undef Rte_Runnable_Dem_ResetEventStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_ResetEventStatus_Return(Dem_EventIdType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_ResetEventStatus_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_ResetEventStatus_Return */

# if defined (Rte_Runnable_Dem_ResetEventStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_ResetEventStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_ResetEventStatus_Start)
#  undef Rte_Runnable_Dem_ResetEventStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_ResetEventStatus_Start(Dem_EventIdType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_ResetEventStatus_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_ResetEventStatus_Start */

# if defined (Rte_Runnable_Dem_SetEventStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_SetEventStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_SetEventStatus_Return)
#  undef Rte_Runnable_Dem_SetEventStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_SetEventStatus_Return(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_SetEventStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_SetEventStatus_Return */

# if defined (Rte_Runnable_Dem_SetEventStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_SetEventStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_SetEventStatus_Start)
#  undef Rte_Runnable_Dem_SetEventStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_SetEventStatus_Start(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_SetEventStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_SetEventStatus_Start */

# if defined (Rte_Runnable_Dem_SetOperationCycleState_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_SetOperationCycleState_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_SetOperationCycleState_Return)
#  undef Rte_Runnable_Dem_SetOperationCycleState_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_SetOperationCycleState_Return(Dem_OperationCycleIdType parg0, Dem_OperationCycleStateType CycleState); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_SetOperationCycleState_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_SetOperationCycleState_Return */

# if defined (Rte_Runnable_Dem_SetOperationCycleState_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dem_SetOperationCycleState_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dem_SetOperationCycleState_Start)
#  undef Rte_Runnable_Dem_SetOperationCycleState_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dem_SetOperationCycleState_Start(Dem_OperationCycleIdType parg0, Dem_OperationCycleStateType CycleState); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dem_SetOperationCycleState_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dem_SetOperationCycleState_Start */

# if defined (Rte_Runnable_Det_ReportError_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Det_ReportError_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Det_ReportError_Return)
#  undef Rte_Runnable_Det_ReportError_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Det_ReportError_Return(uint16 parg0, uint8 InstanceId, uint8 ApiId, uint8 ErrorId); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Det_ReportError_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Det_ReportError_Return */

# if defined (Rte_Runnable_Det_ReportError_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Det_ReportError_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Det_ReportError_Start)
#  undef Rte_Runnable_Det_ReportError_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Det_ReportError_Start(uint16 parg0, uint8 InstanceId, uint8 ApiId, uint8 ErrorId); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Det_ReportError_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Det_ReportError_Start */

# if defined (Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Return)
#  undef Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Start)
#  undef Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DimMdl_CDimMdl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Return)
#  undef Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Start)
#  undef Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DimMdl_CDimMdl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_DimView_CDimView_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DimView_CDimView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DimView_CDimView_Impl_MainFunction_Return)
#  undef Rte_Runnable_DimView_CDimView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DimView_CDimView_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DimView_CDimView_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DimView_CDimView_Impl_MainFunction_Return */

# if defined (Rte_Runnable_DimView_CDimView_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DimView_CDimView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DimView_CDimView_Impl_MainFunction_Start)
#  undef Rte_Runnable_DimView_CDimView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DimView_CDimView_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DimView_CDimView_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DimView_CDimView_Impl_MainFunction_Start */

# if defined (Rte_Runnable_DimView_CDimView_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DimView_CDimView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DimView_CDimView_Impl_OnCommand_Return)
#  undef Rte_Runnable_DimView_CDimView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DimView_CDimView_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DimView_CDimView_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DimView_CDimView_Impl_OnCommand_Return */

# if defined (Rte_Runnable_DimView_CDimView_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DimView_CDimView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DimView_CDimView_Impl_OnCommand_Start)
#  undef Rte_Runnable_DimView_CDimView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DimView_CDimView_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DimView_CDimView_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DimView_CDimView_Impl_OnCommand_Start */

# if defined (Rte_Runnable_DimView_DimView_Impl_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DimView_DimView_Impl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DimView_DimView_Impl_DiagAction_Return)
#  undef Rte_Runnable_DimView_DimView_Impl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DimView_DimView_Impl_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DIMVIEW_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DIMVIEW_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DimView_DimView_Impl_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DimView_DimView_Impl_DiagAction_Return */

# if defined (Rte_Runnable_DimView_DimView_Impl_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DimView_DimView_Impl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DimView_DimView_Impl_DiagAction_Start)
#  undef Rte_Runnable_DimView_DimView_Impl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DimView_DimView_Impl_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_DIMVIEW_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_DIMVIEW_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DimView_DimView_Impl_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DimView_DimView_Impl_DiagAction_Start */

# if defined (Rte_Runnable_DltExt_DltExt_Main_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DltExt_DltExt_Main_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DltExt_DltExt_Main_Return)
#  undef Rte_Runnable_DltExt_DltExt_Main_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DltExt_DltExt_Main_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DltExt_DltExt_Main_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DltExt_DltExt_Main_Return */

# if defined (Rte_Runnable_DltExt_DltExt_Main_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_DltExt_DltExt_Main_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_DltExt_DltExt_Main_Start)
#  undef Rte_Runnable_DltExt_DltExt_Main_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_DltExt_DltExt_Main_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_DltExt_DltExt_Main_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_DltExt_DltExt_Main_Start */

# if defined (Rte_Runnable_Dlt_Dlt_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dlt_Dlt_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dlt_Dlt_MainFunction_Return)
#  undef Rte_Runnable_Dlt_Dlt_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dlt_Dlt_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dlt_Dlt_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dlt_Dlt_MainFunction_Return */

# if defined (Rte_Runnable_Dlt_Dlt_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dlt_Dlt_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dlt_Dlt_MainFunction_Start)
#  undef Rte_Runnable_Dlt_Dlt_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dlt_Dlt_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dlt_Dlt_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dlt_Dlt_MainFunction_Start */

# if defined (Rte_Runnable_Dlt_SendLogMessage_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dlt_SendLogMessage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dlt_SendLogMessage_Return)
#  undef Rte_Runnable_Dlt_SendLogMessage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dlt_SendLogMessage_Return(Dlt_SessionIDType parg0, P2CONST(Dlt_MessageLogInfoType, AUTOMATIC, RTE_DLT_APPL_DATA) LogInfo, P2CONST(Dlt_VerboseBufferType, AUTOMATIC, RTE_DLT_APPL_DATA) LogData, uint16 LogDataLength); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dlt_SendLogMessage_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dlt_SendLogMessage_Return */

# if defined (Rte_Runnable_Dlt_SendLogMessage_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_Dlt_SendLogMessage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_Dlt_SendLogMessage_Start)
#  undef Rte_Runnable_Dlt_SendLogMessage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_Dlt_SendLogMessage_Start(Dlt_SessionIDType parg0, P2CONST(Dlt_MessageLogInfoType, AUTOMATIC, RTE_DLT_APPL_DATA) LogInfo, P2CONST(Dlt_VerboseBufferType, AUTOMATIC, RTE_DLT_APPL_DATA) LogData, uint16 LogDataLength); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_Dlt_SendLogMessage_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_Dlt_SendLogMessage_Start */

# if defined (Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Return)
#  undef Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Start)
#  undef Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EctMdlWrp_CEctMdl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Return)
#  undef Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Return(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Start)
#  undef Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Start(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EctMdlWrp_CEctMdl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_EctMdl_Runnable_swcECT_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EctMdl_Runnable_swcECT_Init_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EctMdl_Runnable_swcECT_Init_Return)
#  undef Rte_Runnable_EctMdl_Runnable_swcECT_Init_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EctMdl_Runnable_swcECT_Init_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EctMdl_Runnable_swcECT_Init_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EctMdl_Runnable_swcECT_Init_Return */

# if defined (Rte_Runnable_EctMdl_Runnable_swcECT_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EctMdl_Runnable_swcECT_Init_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EctMdl_Runnable_swcECT_Init_Start)
#  undef Rte_Runnable_EctMdl_Runnable_swcECT_Init_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EctMdl_Runnable_swcECT_Init_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EctMdl_Runnable_swcECT_Init_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EctMdl_Runnable_swcECT_Init_Start */

# if defined (Rte_Runnable_EctMdl_Runnable_swcECT_Step_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EctMdl_Runnable_swcECT_Step_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EctMdl_Runnable_swcECT_Step_Return)
#  undef Rte_Runnable_EctMdl_Runnable_swcECT_Step_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EctMdl_Runnable_swcECT_Step_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EctMdl_Runnable_swcECT_Step_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EctMdl_Runnable_swcECT_Step_Return */

# if defined (Rte_Runnable_EctMdl_Runnable_swcECT_Step_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EctMdl_Runnable_swcECT_Step_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EctMdl_Runnable_swcECT_Step_Start)
#  undef Rte_Runnable_EctMdl_Runnable_swcECT_Step_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EctMdl_Runnable_swcECT_Step_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EctMdl_Runnable_swcECT_Step_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EctMdl_Runnable_swcECT_Step_Start */

# if defined (Rte_Runnable_EcuM_EcuM_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_EcuM_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_EcuM_MainFunction_Return)
#  undef Rte_Runnable_EcuM_EcuM_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_EcuM_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_EcuM_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_EcuM_MainFunction_Return */

# if defined (Rte_Runnable_EcuM_EcuM_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_EcuM_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_EcuM_MainFunction_Start)
#  undef Rte_Runnable_EcuM_EcuM_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_EcuM_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_EcuM_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_EcuM_MainFunction_Start */

# if defined (Rte_Runnable_EcuM_GetBootTarget_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetBootTarget_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_GetBootTarget_Return)
#  undef Rte_Runnable_EcuM_GetBootTarget_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetBootTarget_Return(P2VAR(EcuM_BootTargetType, AUTOMATIC, RTE_ECUM_APPL_VAR) BootTarget); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_GetBootTarget_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_GetBootTarget_Return */

# if defined (Rte_Runnable_EcuM_GetBootTarget_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetBootTarget_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_GetBootTarget_Start)
#  undef Rte_Runnable_EcuM_GetBootTarget_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetBootTarget_Start(P2VAR(EcuM_BootTargetType, AUTOMATIC, RTE_ECUM_APPL_VAR) BootTarget); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_GetBootTarget_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_GetBootTarget_Start */

# if defined (Rte_Runnable_EcuM_GetLastShutdownTarget_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetLastShutdownTarget_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_GetLastShutdownTarget_Return)
#  undef Rte_Runnable_EcuM_GetLastShutdownTarget_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetLastShutdownTarget_Return(P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) target, P2VAR(EcuM_ModeType, AUTOMATIC, RTE_ECUM_APPL_VAR) resetSleepMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_GetLastShutdownTarget_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_GetLastShutdownTarget_Return */

# if defined (Rte_Runnable_EcuM_GetLastShutdownTarget_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetLastShutdownTarget_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_GetLastShutdownTarget_Start)
#  undef Rte_Runnable_EcuM_GetLastShutdownTarget_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetLastShutdownTarget_Start(P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) target, P2VAR(EcuM_ModeType, AUTOMATIC, RTE_ECUM_APPL_VAR) resetSleepMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_GetLastShutdownTarget_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_GetLastShutdownTarget_Start */

# if defined (Rte_Runnable_EcuM_GetShutdownCause_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetShutdownCause_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_GetShutdownCause_Return)
#  undef Rte_Runnable_EcuM_GetShutdownCause_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetShutdownCause_Return(P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, RTE_ECUM_APPL_VAR) shutdownCause); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_GetShutdownCause_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_GetShutdownCause_Return */

# if defined (Rte_Runnable_EcuM_GetShutdownCause_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetShutdownCause_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_GetShutdownCause_Start)
#  undef Rte_Runnable_EcuM_GetShutdownCause_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetShutdownCause_Start(P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, RTE_ECUM_APPL_VAR) shutdownCause); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_GetShutdownCause_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_GetShutdownCause_Start */

# if defined (Rte_Runnable_EcuM_GetShutdownTarget_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetShutdownTarget_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_GetShutdownTarget_Return)
#  undef Rte_Runnable_EcuM_GetShutdownTarget_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetShutdownTarget_Return(P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) target, P2VAR(EcuM_ModeType, AUTOMATIC, RTE_ECUM_APPL_VAR) resetSleepMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_GetShutdownTarget_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_GetShutdownTarget_Return */

# if defined (Rte_Runnable_EcuM_GetShutdownTarget_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetShutdownTarget_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_GetShutdownTarget_Start)
#  undef Rte_Runnable_EcuM_GetShutdownTarget_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetShutdownTarget_Start(P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) target, P2VAR(EcuM_ModeType, AUTOMATIC, RTE_ECUM_APPL_VAR) resetSleepMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_GetShutdownTarget_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_GetShutdownTarget_Start */

# if defined (Rte_Runnable_EcuM_GetStateWrapper_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetStateWrapper_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_GetStateWrapper_Return)
#  undef Rte_Runnable_EcuM_GetStateWrapper_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetStateWrapper_Return(EcuM_UserType parg0, P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) state); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_GetStateWrapper_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_GetStateWrapper_Return */

# if defined (Rte_Runnable_EcuM_GetStateWrapper_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_GetStateWrapper_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_GetStateWrapper_Start)
#  undef Rte_Runnable_EcuM_GetStateWrapper_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_GetStateWrapper_Start(EcuM_UserType parg0, P2VAR(EcuM_StateType, AUTOMATIC, RTE_ECUM_APPL_VAR) state); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_GetStateWrapper_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_GetStateWrapper_Start */

# if defined (Rte_Runnable_EcuM_ReleasePOSTRUN_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_ReleasePOSTRUN_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_ReleasePOSTRUN_Return)
#  undef Rte_Runnable_EcuM_ReleasePOSTRUN_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_ReleasePOSTRUN_Return(EcuM_UserType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_ReleasePOSTRUN_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_ReleasePOSTRUN_Return */

# if defined (Rte_Runnable_EcuM_ReleasePOSTRUN_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_ReleasePOSTRUN_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_ReleasePOSTRUN_Start)
#  undef Rte_Runnable_EcuM_ReleasePOSTRUN_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_ReleasePOSTRUN_Start(EcuM_UserType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_ReleasePOSTRUN_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_ReleasePOSTRUN_Start */

# if defined (Rte_Runnable_EcuM_ReleaseRUN_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_ReleaseRUN_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_ReleaseRUN_Return)
#  undef Rte_Runnable_EcuM_ReleaseRUN_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_ReleaseRUN_Return(EcuM_UserType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_ReleaseRUN_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_ReleaseRUN_Return */

# if defined (Rte_Runnable_EcuM_ReleaseRUN_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_ReleaseRUN_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_ReleaseRUN_Start)
#  undef Rte_Runnable_EcuM_ReleaseRUN_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_ReleaseRUN_Start(EcuM_UserType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_ReleaseRUN_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_ReleaseRUN_Start */

# if defined (Rte_Runnable_EcuM_RequestPOSTRUN_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_RequestPOSTRUN_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_RequestPOSTRUN_Return)
#  undef Rte_Runnable_EcuM_RequestPOSTRUN_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_RequestPOSTRUN_Return(EcuM_UserType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_RequestPOSTRUN_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_RequestPOSTRUN_Return */

# if defined (Rte_Runnable_EcuM_RequestPOSTRUN_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_RequestPOSTRUN_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_RequestPOSTRUN_Start)
#  undef Rte_Runnable_EcuM_RequestPOSTRUN_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_RequestPOSTRUN_Start(EcuM_UserType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_RequestPOSTRUN_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_RequestPOSTRUN_Start */

# if defined (Rte_Runnable_EcuM_RequestRUN_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_RequestRUN_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_RequestRUN_Return)
#  undef Rte_Runnable_EcuM_RequestRUN_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_RequestRUN_Return(EcuM_UserType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_RequestRUN_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_RequestRUN_Return */

# if defined (Rte_Runnable_EcuM_RequestRUN_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_RequestRUN_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_RequestRUN_Start)
#  undef Rte_Runnable_EcuM_RequestRUN_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_RequestRUN_Start(EcuM_UserType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_RequestRUN_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_RequestRUN_Start */

# if defined (Rte_Runnable_EcuM_SelectBootTarget_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_SelectBootTarget_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_SelectBootTarget_Return)
#  undef Rte_Runnable_EcuM_SelectBootTarget_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_SelectBootTarget_Return(EcuM_BootTargetType BootTarget); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_SelectBootTarget_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_SelectBootTarget_Return */

# if defined (Rte_Runnable_EcuM_SelectBootTarget_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_SelectBootTarget_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_SelectBootTarget_Start)
#  undef Rte_Runnable_EcuM_SelectBootTarget_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_SelectBootTarget_Start(EcuM_BootTargetType BootTarget); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_SelectBootTarget_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_SelectBootTarget_Start */

# if defined (Rte_Runnable_EcuM_SelectShutdownCause_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_SelectShutdownCause_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_SelectShutdownCause_Return)
#  undef Rte_Runnable_EcuM_SelectShutdownCause_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_SelectShutdownCause_Return(EcuM_ShutdownCauseType shutdownCause); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_SelectShutdownCause_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_SelectShutdownCause_Return */

# if defined (Rte_Runnable_EcuM_SelectShutdownCause_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_SelectShutdownCause_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_SelectShutdownCause_Start)
#  undef Rte_Runnable_EcuM_SelectShutdownCause_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_SelectShutdownCause_Start(EcuM_ShutdownCauseType shutdownCause); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_SelectShutdownCause_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_SelectShutdownCause_Start */

# if defined (Rte_Runnable_EcuM_SelectShutdownTarget_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_SelectShutdownTarget_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_SelectShutdownTarget_Return)
#  undef Rte_Runnable_EcuM_SelectShutdownTarget_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_SelectShutdownTarget_Return(EcuM_StateType targetState, EcuM_ModeType resetSleepMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_SelectShutdownTarget_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_SelectShutdownTarget_Return */

# if defined (Rte_Runnable_EcuM_SelectShutdownTarget_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcuM_SelectShutdownTarget_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcuM_SelectShutdownTarget_Start)
#  undef Rte_Runnable_EcuM_SelectShutdownTarget_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcuM_SelectShutdownTarget_Start(EcuM_StateType targetState, EcuM_ModeType resetSleepMode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcuM_SelectShutdownTarget_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcuM_SelectShutdownTarget_Start */

# if defined (Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Return)
#  undef Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Return */

# if defined (Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Start)
#  undef Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EcumExt_CEcumExt_Impl_MainFunction_Start */

# if defined (Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Return)
#  undef Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Start)
#  undef Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EngMdl_CEngMdl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Return)
#  undef Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Start)
#  undef Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_EngMdl_CEngMdl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Return)
#  undef Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Start)
#  undef Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Return)
#  undef Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Return(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Start)
#  undef Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Start(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_FuelMdlWrp_CFuelMdl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Return)
#  undef Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Return */

# if defined (Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Start)
#  undef Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_FuelMdl_FuelLevelCAN_Init_Start */

# if defined (Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Return)
#  undef Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Return */

# if defined (Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Start)
#  undef Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_FuelMdl_FuelLevelCAN_Step_Start */

# if defined (Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Return)
#  undef Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Return */

# if defined (Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Start)
#  undef Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCdd_CGdtCdd_Impl_MainFunction_Start */

# if defined (Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Return)
#  undef Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Return */

# if defined (Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Start)
#  undef Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCdd_CGdtCdd_Impl_OnCommand_Start */

# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Return)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Start)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Return)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Return(P2CONST(SPulseNotification, AUTOMATIC, RTE_GDTCTRL_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Return */

# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Start)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Start(P2CONST(SPulseNotification, AUTOMATIC, RTE_GDTCTRL_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Notification_Start */

# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Return)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Start)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Return)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Return */

# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Start)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_PrepareSub_Start */

# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Return)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Return */

# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Start)
#  undef Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_CGdtCtrl_Impl_Start_Start */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Return)
#  undef Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Return */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Start)
#  undef Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrlRef_SpeedDataRx_Start */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Return)
#  undef Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Return */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Start)
#  undef Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrlRef_TachoDataRx_Start */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Return)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Return */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Start)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_Cancel_Start */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Return)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Return */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Start)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_DiagAction_Start */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Return)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Return */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Start)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_Latch_Start */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Return)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Return(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Return */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Start)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Start(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_ListChange_Start */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Return)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Return */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Start)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_Prepare_Start */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Return)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Return */

# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Start)
#  undef Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtCtrl_GdtCtrl_Stop_Start */

# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Return)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Return */

# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Start)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoKm_Start */

# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Return)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Return */

# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Start)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxOdoMl_Start */

# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Return)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Return */

# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Start)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxSpeed_Start */

# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Return)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Return */

# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Start)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTacho_Start */

# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Return)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Return */

# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Start)
#  undef Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_GdtDpConn_CGdtDpConn_Impl_RxTrip_Start */

# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Return)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Return */

# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Start)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_HmiCtrl_CHmiCtrl_Gdt_Ready_Start */

# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Return)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Start)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Return)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Start)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_HmiCtrl_CHmiCtrl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Return)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Return */

# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Start)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_HmiCtrl_CHmiCtrl_Ptr_Ready_Start */

# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Return)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Return */

# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Start)
#  undef Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_HmiCtrl_CHmiCtrl_Tt_Ready_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Return(EIOCurrentInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Current); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Start(EIOCurrentInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Current); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetCurrent_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Return(EIODutyInId Id, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Duty); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Start(EIODutyInId Id, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Duty); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetDuty_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Return(EIOGroupInId Id, P2VAR(UInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Group); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Start(EIOGroupInId Id, P2VAR(UInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Group); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetGroup_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Return(EIOMapStatInId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_IOHWAB_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Start(EIOMapStatInId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_IOHWAB_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetMappedStatus_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Return(EIOPeriodOutId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_IOHWAB_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Start(EIOPeriodOutId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_IOHWAB_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriodMappedStatus_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Return(EIOPeriodInId Id, P2VAR(UInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Period); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Start(EIOPeriodInId Id, P2VAR(UInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Period); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPeriod_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Return(EIOPinOutId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_IOHWAB_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Start(EIOPinOutId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_IOHWAB_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPinMappedStatus_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Return(EIOPinInId Id, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Pin); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Start(EIOPinInId Id, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Pin); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetPin_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Return(EIOResistanceInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Resistance); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Start(EIOResistanceInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Resistance); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetResistance_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Return(EIOVoltageInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Voltage); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Start(EIOVoltageInId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Voltage); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_GetVoltage_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_MainFunction_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Return(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Start(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_OnCommand_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Return(EIODutyOutId Id, UInt16 Duty); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Start(EIODutyOutId Id, UInt16 Duty); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetDuty_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Return(EIOGroupOutId Id, UInt32 Group); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Start(EIOGroupOutId Id, UInt32 Group); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetGroup_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Return(EIOPeriodOutId Id, UInt32 Period); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Start(EIOPeriodOutId Id, UInt32 Period); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPeriod_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Return(EIOPinOutId Id, Boolean Digital); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Start(EIOPinOutId Id, Boolean Digital); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_Impl_SetPin_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Return(EIOVoltageOutId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_IOHWAB_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Start(EIOVoltageOutId Id, P2VAR(EIOMapStat, AUTOMATIC, RTE_IOHWAB_APPL_VAR) MappedStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltageMappedStatus_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Return(EIOVoltageOutId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Voltage); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Start(EIOVoltageOutId Id, P2VAR(TIOAppData, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Voltage); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_GetVoltage_Start */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Return)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Return(EIOVoltageOutId Id, TIOAppData Voltage); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Return */

# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Start)
#  undef Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Start(EIOVoltageOutId Id, TIOAppData Voltage); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_IoHwAb_CIoHwAb_VOut_Impl_SetVoltage_Start */

# if defined (Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Return)
#  undef Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Start)
#  undef Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ModMdl_CModMdl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Return)
#  undef Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Start)
#  undef Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_ModMdl_CModMdl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Return)
#  undef Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Return */

# if defined (Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Start)
#  undef Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable_Start */

# if defined (Rte_Runnable_NvM_EraseBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_EraseBlock_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_EraseBlock_Return)
#  undef Rte_Runnable_NvM_EraseBlock_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_EraseBlock_Return(NvM_BlockIdType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_EraseBlock_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_EraseBlock_Return */

# if defined (Rte_Runnable_NvM_EraseBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_EraseBlock_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_EraseBlock_Start)
#  undef Rte_Runnable_NvM_EraseBlock_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_EraseBlock_Start(NvM_BlockIdType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_EraseBlock_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_EraseBlock_Start */

# if defined (Rte_Runnable_NvM_GetErrorStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_GetErrorStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_GetErrorStatus_Return)
#  undef Rte_Runnable_NvM_GetErrorStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_GetErrorStatus_Return(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_GetErrorStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_GetErrorStatus_Return */

# if defined (Rte_Runnable_NvM_GetErrorStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_GetErrorStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_GetErrorStatus_Start)
#  undef Rte_Runnable_NvM_GetErrorStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_GetErrorStatus_Start(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_GetErrorStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_GetErrorStatus_Start */

# if defined (Rte_Runnable_NvM_InvalidateNvBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_InvalidateNvBlock_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_InvalidateNvBlock_Return)
#  undef Rte_Runnable_NvM_InvalidateNvBlock_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_InvalidateNvBlock_Return(NvM_BlockIdType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_InvalidateNvBlock_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_InvalidateNvBlock_Return */

# if defined (Rte_Runnable_NvM_InvalidateNvBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_InvalidateNvBlock_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_InvalidateNvBlock_Start)
#  undef Rte_Runnable_NvM_InvalidateNvBlock_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_InvalidateNvBlock_Start(NvM_BlockIdType parg0); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_InvalidateNvBlock_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_InvalidateNvBlock_Start */

# if defined (Rte_Runnable_NvM_NvM_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_NvM_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_NvM_MainFunction_Return)
#  undef Rte_Runnable_NvM_NvM_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_NvM_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_NvM_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_NvM_MainFunction_Return */

# if defined (Rte_Runnable_NvM_NvM_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_NvM_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_NvM_MainFunction_Start)
#  undef Rte_Runnable_NvM_NvM_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_NvM_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_NvM_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_NvM_MainFunction_Start */

# if defined (Rte_Runnable_NvM_ReadBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_ReadBlock_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_ReadBlock_Return)
#  undef Rte_Runnable_NvM_ReadBlock_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_ReadBlock_Return(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_ReadBlock_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_ReadBlock_Return */

# if defined (Rte_Runnable_NvM_ReadBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_ReadBlock_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_ReadBlock_Start)
#  undef Rte_Runnable_NvM_ReadBlock_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_ReadBlock_Start(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_ReadBlock_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_ReadBlock_Start */

# if defined (Rte_Runnable_NvM_RestoreBlockDefaults_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_RestoreBlockDefaults_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_RestoreBlockDefaults_Return)
#  undef Rte_Runnable_NvM_RestoreBlockDefaults_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_RestoreBlockDefaults_Return(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_RestoreBlockDefaults_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_RestoreBlockDefaults_Return */

# if defined (Rte_Runnable_NvM_RestoreBlockDefaults_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_RestoreBlockDefaults_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_RestoreBlockDefaults_Start)
#  undef Rte_Runnable_NvM_RestoreBlockDefaults_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_RestoreBlockDefaults_Start(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_RestoreBlockDefaults_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_RestoreBlockDefaults_Start */

# if defined (Rte_Runnable_NvM_SetBlockProtection_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_SetBlockProtection_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_SetBlockProtection_Return)
#  undef Rte_Runnable_NvM_SetBlockProtection_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_SetBlockProtection_Return(NvM_BlockIdType parg0, boolean ProtectionEnabled); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_SetBlockProtection_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_SetBlockProtection_Return */

# if defined (Rte_Runnable_NvM_SetBlockProtection_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_SetBlockProtection_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_SetBlockProtection_Start)
#  undef Rte_Runnable_NvM_SetBlockProtection_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_SetBlockProtection_Start(NvM_BlockIdType parg0, boolean ProtectionEnabled); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_SetBlockProtection_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_SetBlockProtection_Start */

# if defined (Rte_Runnable_NvM_SetRamBlockStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_SetRamBlockStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_SetRamBlockStatus_Return)
#  undef Rte_Runnable_NvM_SetRamBlockStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_SetRamBlockStatus_Return(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_SetRamBlockStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_SetRamBlockStatus_Return */

# if defined (Rte_Runnable_NvM_SetRamBlockStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_SetRamBlockStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_SetRamBlockStatus_Start)
#  undef Rte_Runnable_NvM_SetRamBlockStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_SetRamBlockStatus_Start(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_SetRamBlockStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_SetRamBlockStatus_Start */

# if defined (Rte_Runnable_NvM_WriteBlock_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_WriteBlock_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_WriteBlock_Return)
#  undef Rte_Runnable_NvM_WriteBlock_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_WriteBlock_Return(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_WriteBlock_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_WriteBlock_Return */

# if defined (Rte_Runnable_NvM_WriteBlock_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_NvM_WriteBlock_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_NvM_WriteBlock_Start)
#  undef Rte_Runnable_NvM_WriteBlock_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_NvM_WriteBlock_Start(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_NvM_WriteBlock_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_NvM_WriteBlock_Start */

# if defined (Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Return)
#  undef Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Start)
#  undef Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_OdoMdl_COdoMdl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Return)
#  undef Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Return(ECmpCmd arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Start)
#  undef Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Start(ECmpCmd arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_OdoMdl_COdoMdl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Return)
#  undef Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Return */

# if defined (Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Start)
#  undef Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrEctView_Impl_MainFunction_Start */

# if defined (Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Return)
#  undef Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Return */

# if defined (Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Start)
#  undef Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrEctView_Impl_OnCommand_Start */

# if defined (Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Return)
#  undef Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Return */

# if defined (Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Start)
#  undef Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrFuelView_Impl_MainFunction_Start */

# if defined (Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Return)
#  undef Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Return */

# if defined (Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Start)
#  undef Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrFuelView_Impl_OnCommand_Start */

# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Return)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Return */

# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Start)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrSpdView_Impl_DiagAction_Start */

# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Return)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Return */

# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Start)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrSpdView_Impl_MainFunction_Start */

# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Return)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Return */

# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Start)
#  undef Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrSpdView_Impl_OnCommand_Start */

# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Return)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Return */

# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Start)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_PTRVIEW_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrTachoView_Impl_DiagAction_Start */

# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Return)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Return */

# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Start)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrTachoView_Impl_MainFunction_Start */

# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Return)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Return */

# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Start)
#  undef Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_CPtrTachoView_Impl_OnCommand_Start */

# if defined (Rte_Runnable_PtrView_PtrView_PrepareSub_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_PtrView_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_PtrView_PrepareSub_Return)
#  undef Rte_Runnable_PtrView_PtrView_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_PtrView_PrepareSub_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_PtrView_PrepareSub_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_PtrView_PrepareSub_Return */

# if defined (Rte_Runnable_PtrView_PtrView_PrepareSub_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_PtrView_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_PtrView_PrepareSub_Start)
#  undef Rte_Runnable_PtrView_PtrView_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_PtrView_PrepareSub_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_PtrView_PrepareSub_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_PtrView_PrepareSub_Start */

# if defined (Rte_Runnable_PtrView_PtrView_Start_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_PtrView_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_PtrView_Start_Return)
#  undef Rte_Runnable_PtrView_PtrView_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_PtrView_Start_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_PtrView_Start_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_PtrView_Start_Return */

# if defined (Rte_Runnable_PtrView_PtrView_Start_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_PtrView_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_PtrView_Start_Start)
#  undef Rte_Runnable_PtrView_PtrView_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_PtrView_Start_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_PtrView_Start_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_PtrView_Start_Start */

# if defined (Rte_Runnable_PtrView_PtrView_Stop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_PtrView_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_PtrView_Stop_Return)
#  undef Rte_Runnable_PtrView_PtrView_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_PtrView_Stop_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_PtrView_Stop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_PtrView_Stop_Return */

# if defined (Rte_Runnable_PtrView_PtrView_Stop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_PtrView_PtrView_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_PtrView_PtrView_Stop_Start)
#  undef Rte_Runnable_PtrView_PtrView_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_PtrView_PtrView_Stop_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_PtrView_PtrView_Stop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_PtrView_PtrView_Stop_Start */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Return)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Return(UInt8 ChimeId, P2VAR(EChimeStatus, AUTOMATIC, RTE_SNDCDD_APPL_VAR) pChimeStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Return */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Start)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Start(UInt8 ChimeId, P2VAR(EChimeStatus, AUTOMATIC, RTE_SNDCDD_APPL_VAR) pChimeStatus); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_CheckStatus_Start */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Return)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Return */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Start)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_MainFunction_Start */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Return)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Return */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Start)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_OnCommand_Start */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Return)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Return(UInt8 ChimeId); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Return */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Start)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Start(UInt8 ChimeId); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStart_Start */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Return)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Return(UInt8 ChimeId); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Return */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Start)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Start(UInt8 ChimeId); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_RequestToStop_Start */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Return)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Return */

# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Start)
#  undef Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_CSndCdd_Impl_ToneProcess_Start */

# if defined (Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Return)
#  undef Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Return(uint16 Frequency, uint8 Volume); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Return */

# if defined (Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Start)
#  undef Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Start(uint16 Frequency, uint8 Volume); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndCdd_SndMgr_RequestToPlayTone_Start */

# if defined (Rte_Runnable_SndView_CSndView_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_CSndView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_CSndView_Impl_MainFunction_Return)
#  undef Rte_Runnable_SndView_CSndView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_CSndView_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_CSndView_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_CSndView_Impl_MainFunction_Return */

# if defined (Rte_Runnable_SndView_CSndView_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_CSndView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_CSndView_Impl_MainFunction_Start)
#  undef Rte_Runnable_SndView_CSndView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_CSndView_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_CSndView_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_CSndView_Impl_MainFunction_Start */

# if defined (Rte_Runnable_SndView_CSndView_Impl_Notification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_CSndView_Impl_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_CSndView_Impl_Notification_Return)
#  undef Rte_Runnable_SndView_CSndView_Impl_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_CSndView_Impl_Notification_Return(P2CONST(SPulseNotification, AUTOMATIC, RTE_SNDVIEW_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_CSndView_Impl_Notification_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_CSndView_Impl_Notification_Return */

# if defined (Rte_Runnable_SndView_CSndView_Impl_Notification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_CSndView_Impl_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_CSndView_Impl_Notification_Start)
#  undef Rte_Runnable_SndView_CSndView_Impl_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_CSndView_Impl_Notification_Start(P2CONST(SPulseNotification, AUTOMATIC, RTE_SNDVIEW_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_CSndView_Impl_Notification_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_CSndView_Impl_Notification_Start */

# if defined (Rte_Runnable_SndView_CSndView_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_CSndView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_CSndView_Impl_OnCommand_Return)
#  undef Rte_Runnable_SndView_CSndView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_CSndView_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_CSndView_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_CSndView_Impl_OnCommand_Return */

# if defined (Rte_Runnable_SndView_CSndView_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_CSndView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_CSndView_Impl_OnCommand_Start)
#  undef Rte_Runnable_SndView_CSndView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_CSndView_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_CSndView_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_CSndView_Impl_OnCommand_Start */

# if defined (Rte_Runnable_SndView_SndView_Cancel_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Cancel_Return)
#  undef Rte_Runnable_SndView_SndView_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Cancel_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Cancel_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Cancel_Return */

# if defined (Rte_Runnable_SndView_SndView_Cancel_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Cancel_Start)
#  undef Rte_Runnable_SndView_SndView_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Cancel_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Cancel_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Cancel_Start */

# if defined (Rte_Runnable_SndView_SndView_Impl_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Impl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Impl_DiagAction_Return)
#  undef Rte_Runnable_SndView_SndView_Impl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Impl_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_SNDVIEW_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_SNDVIEW_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Impl_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Impl_DiagAction_Return */

# if defined (Rte_Runnable_SndView_SndView_Impl_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Impl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Impl_DiagAction_Start)
#  undef Rte_Runnable_SndView_SndView_Impl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Impl_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_SNDVIEW_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_SNDVIEW_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Impl_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Impl_DiagAction_Start */

# if defined (Rte_Runnable_SndView_SndView_Latch_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Latch_Return)
#  undef Rte_Runnable_SndView_SndView_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Latch_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Latch_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Latch_Return */

# if defined (Rte_Runnable_SndView_SndView_Latch_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Latch_Start)
#  undef Rte_Runnable_SndView_SndView_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Latch_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Latch_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Latch_Start */

# if defined (Rte_Runnable_SndView_SndView_ListChange_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_ListChange_Return)
#  undef Rte_Runnable_SndView_SndView_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_ListChange_Return(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_ListChange_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_ListChange_Return */

# if defined (Rte_Runnable_SndView_SndView_ListChange_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_ListChange_Start)
#  undef Rte_Runnable_SndView_SndView_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_ListChange_Start(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_ListChange_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_ListChange_Start */

# if defined (Rte_Runnable_SndView_SndView_PrepareSub_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_PrepareSub_Return)
#  undef Rte_Runnable_SndView_SndView_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_PrepareSub_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_PrepareSub_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_PrepareSub_Return */

# if defined (Rte_Runnable_SndView_SndView_PrepareSub_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_PrepareSub_Start)
#  undef Rte_Runnable_SndView_SndView_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_PrepareSub_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_PrepareSub_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_PrepareSub_Start */

# if defined (Rte_Runnable_SndView_SndView_Prepare_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Prepare_Return)
#  undef Rte_Runnable_SndView_SndView_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Prepare_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Prepare_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Prepare_Return */

# if defined (Rte_Runnable_SndView_SndView_Prepare_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Prepare_Start)
#  undef Rte_Runnable_SndView_SndView_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Prepare_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Prepare_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Prepare_Start */

# if defined (Rte_Runnable_SndView_SndView_Start_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Start_Return)
#  undef Rte_Runnable_SndView_SndView_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Start_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Start_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Start_Return */

# if defined (Rte_Runnable_SndView_SndView_Start_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Start_Start)
#  undef Rte_Runnable_SndView_SndView_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Start_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Start_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Start_Start */

# if defined (Rte_Runnable_SndView_SndView_Stop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Stop_Return)
#  undef Rte_Runnable_SndView_SndView_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Stop_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Stop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Stop_Return */

# if defined (Rte_Runnable_SndView_SndView_Stop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SndView_SndView_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SndView_SndView_Stop_Start)
#  undef Rte_Runnable_SndView_SndView_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SndView_SndView_Stop_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SndView_SndView_Stop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SndView_SndView_Stop_Start */

# if defined (Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Return)
#  undef Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Start)
#  undef Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SpdMdl_CSpdMdl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Return)
#  undef Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Start)
#  undef Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_SpdMdl_CSpdMdl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Return(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Return(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Start(EDcmExtAction Action, P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) Data, P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) Lenght, uint32 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Start(arg1, arg2, arg3, arg4) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_DiagAction_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Return(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Start(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_DisableOrderSampling_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Return(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Start(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_EmergencyStop_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Return(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Start(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_EnableOrderSampling_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Return(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Start(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_EnterHighZMode_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Return(uint8 Id, P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) pAngle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Start(uint8 Id, P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) pAngle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosDeg_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Return(uint8 Id, P2VAR(uint32, AUTOMATIC, RTE_STPCDD_APPL_VAR) pMicrosteps); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Start(uint8 Id, P2VAR(uint32, AUTOMATIC, RTE_STPCDD_APPL_VAR) pMicrosteps); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_GetCurrentPosMicroStp_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Return(uint8 Id, P2VAR(EStpStat, AUTOMATIC, RTE_STPCDD_APPL_VAR) pStat); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Start(uint8 Id, P2VAR(EStpStat, AUTOMATIC, RTE_STPCDD_APPL_VAR) pStat); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_GetStatus_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Return(uint8 Id, P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) pAngle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Start(uint8 Id, P2VAR(uint16, AUTOMATIC, RTE_STPCDD_APPL_VAR) pAngle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosDeg_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Return(uint8 Id, P2VAR(uint32, AUTOMATIC, RTE_STPCDD_APPL_VAR) pMicrosteps); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Start(uint8 Id, P2VAR(uint32, AUTOMATIC, RTE_STPCDD_APPL_VAR) pMicrosteps); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_GetTargetPosMicroStp_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Return(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Start(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_LeaveHighZMode_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_MainFunction_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_OnCommand_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Return(uint8 Id, EStpCalibKind CalibKind, uint16 CalibAngle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Start(uint8 Id, EStpCalibKind CalibKind, uint16 CalibAngle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_ReqCalib_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Return(uint8 Id, uint16 Angle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Start(uint8 Id, uint16 Angle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDegAbsolute_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Return(uint8 Id, uint16 Angle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Start(uint8 Id, uint16 Angle); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosDeg_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Return(uint8 Id, uint32 Microsteps); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Start(uint8 Id, uint32 Microsteps); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_SetPosMicroStp_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Return(uint8 Id, uint8 MaxTorque); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Start(uint8 Id, uint8 MaxTorque); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_SetTorque_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_StartBurnIn_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Return(uint8 Id, uint8 Microsteps); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Start(uint8 Id, uint8 Microsteps); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_StartJumpMicroStp_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_StopBurnIn_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Return(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Start(uint8 Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_StopJumpMicroStp_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Return(uint8 Id, P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) pWowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Start(uint8 Id, P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) pWowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowGetMotSession_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Return(P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) pWowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Start(P2VAR(uint8, AUTOMATIC, RTE_STPCDD_APPL_VAR) pWowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowOpenSession_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Return(uint8 WowSession, Boolean toStart); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Start(uint8 WowSession, Boolean toStart); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowRequest_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Return(uint8 WowSession, uint8 Id, uint16 TargetPos); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Start(uint8 WowSession, uint8 Id, uint16 TargetPos); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetMotor_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Return(uint8 WowSession, uint16 Time, uint8 TimeType); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Start(uint8 WowSession, uint16 Time, uint8 TimeType); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowSessionSetTime_Start */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Return)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Return(uint8 WowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Return */

# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Start)
#  undef Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Start(uint8 WowSession); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_StpCdd_CStpCdd_Impl_WowStop_Start */

# if defined (Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Return)
#  undef Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Return(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Return */

# if defined (Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Start)
#  undef Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Start(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TmExt_CTmExt_Impl_DisableNotification_Start */

# if defined (Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Return)
#  undef Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Return(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification, P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Sync); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Return(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Return */

# if defined (Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Start)
#  undef Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Start(TPulseClientId Client, P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Notification, P2CONST(SPulseNotification, AUTOMATIC, RTE_TMEXT_APPL_DATA) Sync); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Start(arg1, arg2, arg3) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TmExt_CTmExt_Impl_EnableNotification_Start */

# if defined (Rte_Runnable_TmExt_TmExt_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TmExt_TmExt_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TmExt_TmExt_MainFunction_Return)
#  undef Rte_Runnable_TmExt_TmExt_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TmExt_TmExt_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TmExt_TmExt_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TmExt_TmExt_MainFunction_Return */

# if defined (Rte_Runnable_TmExt_TmExt_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TmExt_TmExt_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TmExt_TmExt_MainFunction_Start)
#  undef Rte_Runnable_TmExt_TmExt_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TmExt_TmExt_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TmExt_TmExt_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TmExt_TmExt_MainFunction_Start */

# if defined (Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Return)
#  undef Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Start)
#  undef Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TripMdl_CTripMdl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Return)
#  undef Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Return(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Start)
#  undef Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Start(uint8 arg); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TripMdl_CTripMdl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Return)
#  undef Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Return */

# if defined (Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Start)
#  undef Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TripMdl_CTripMdl_ResetTrip_Start */

# if defined (Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Return)
#  undef Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Start)
#  undef Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtMdl_CTtMdl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Return)
#  undef Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Start)
#  undef Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtMdl_CTtMdl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_TtView_CTtView_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_CTtView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_CTtView_Impl_MainFunction_Return)
#  undef Rte_Runnable_TtView_CTtView_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_CTtView_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_CTtView_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_CTtView_Impl_MainFunction_Return */

# if defined (Rte_Runnable_TtView_CTtView_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_CTtView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_CTtView_Impl_MainFunction_Start)
#  undef Rte_Runnable_TtView_CTtView_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_CTtView_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_CTtView_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_CTtView_Impl_MainFunction_Start */

# if defined (Rte_Runnable_TtView_CTtView_Impl_Notification_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_CTtView_Impl_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_CTtView_Impl_Notification_Return)
#  undef Rte_Runnable_TtView_CTtView_Impl_Notification_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_CTtView_Impl_Notification_Return(P2CONST(SPulseNotification, AUTOMATIC, RTE_TTVIEW_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_CTtView_Impl_Notification_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_CTtView_Impl_Notification_Return */

# if defined (Rte_Runnable_TtView_CTtView_Impl_Notification_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_CTtView_Impl_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_CTtView_Impl_Notification_Start)
#  undef Rte_Runnable_TtView_CTtView_Impl_Notification_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_CTtView_Impl_Notification_Start(P2CONST(SPulseNotification, AUTOMATIC, RTE_TTVIEW_APPL_DATA) Notification); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_CTtView_Impl_Notification_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_CTtView_Impl_Notification_Start */

# if defined (Rte_Runnable_TtView_CTtView_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_CTtView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_CTtView_Impl_OnCommand_Return)
#  undef Rte_Runnable_TtView_CTtView_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_CTtView_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_CTtView_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_CTtView_Impl_OnCommand_Return */

# if defined (Rte_Runnable_TtView_CTtView_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_CTtView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_CTtView_Impl_OnCommand_Start)
#  undef Rte_Runnable_TtView_CTtView_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_CTtView_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_CTtView_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_CTtView_Impl_OnCommand_Start */

# if defined (Rte_Runnable_TtView_TtView_Cancel_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_Cancel_Return)
#  undef Rte_Runnable_TtView_TtView_Cancel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_Cancel_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_Cancel_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_Cancel_Return */

# if defined (Rte_Runnable_TtView_TtView_Cancel_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_Cancel_Start)
#  undef Rte_Runnable_TtView_TtView_Cancel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_Cancel_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_Cancel_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_Cancel_Start */

# if defined (Rte_Runnable_TtView_TtView_Latch_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_Latch_Return)
#  undef Rte_Runnable_TtView_TtView_Latch_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_Latch_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_Latch_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_Latch_Return */

# if defined (Rte_Runnable_TtView_TtView_Latch_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_Latch_Start)
#  undef Rte_Runnable_TtView_TtView_Latch_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_Latch_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_Latch_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_Latch_Start */

# if defined (Rte_Runnable_TtView_TtView_ListChange_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_ListChange_Return)
#  undef Rte_Runnable_TtView_TtView_ListChange_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_ListChange_Return(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_ListChange_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_ListChange_Return */

# if defined (Rte_Runnable_TtView_TtView_ListChange_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_ListChange_Start)
#  undef Rte_Runnable_TtView_TtView_ListChange_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_ListChange_Start(TWrnListMask ListMask); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_ListChange_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_ListChange_Start */

# if defined (Rte_Runnable_TtView_TtView_PrepareSub_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_PrepareSub_Return)
#  undef Rte_Runnable_TtView_TtView_PrepareSub_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_PrepareSub_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_PrepareSub_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_PrepareSub_Return */

# if defined (Rte_Runnable_TtView_TtView_PrepareSub_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_PrepareSub_Start)
#  undef Rte_Runnable_TtView_TtView_PrepareSub_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_PrepareSub_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_PrepareSub_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_PrepareSub_Start */

# if defined (Rte_Runnable_TtView_TtView_Prepare_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_Prepare_Return)
#  undef Rte_Runnable_TtView_TtView_Prepare_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_Prepare_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_Prepare_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_Prepare_Return */

# if defined (Rte_Runnable_TtView_TtView_Prepare_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_Prepare_Start)
#  undef Rte_Runnable_TtView_TtView_Prepare_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_Prepare_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_Prepare_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_Prepare_Start */

# if defined (Rte_Runnable_TtView_TtView_Start_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_Start_Return)
#  undef Rte_Runnable_TtView_TtView_Start_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_Start_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_Start_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_Start_Return */

# if defined (Rte_Runnable_TtView_TtView_Start_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_Start_Start)
#  undef Rte_Runnable_TtView_TtView_Start_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_Start_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_Start_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_Start_Start */

# if defined (Rte_Runnable_TtView_TtView_Stop_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_Stop_Return)
#  undef Rte_Runnable_TtView_TtView_Stop_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_Stop_Return(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_Stop_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_Stop_Return */

# if defined (Rte_Runnable_TtView_TtView_Stop_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_TtView_TtView_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_TtView_TtView_Stop_Start)
#  undef Rte_Runnable_TtView_TtView_Stop_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_TtView_TtView_Stop_Start(EHmiSubId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_TtView_TtView_Stop_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_TtView_TtView_Stop_Start */

# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Return)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Return(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Return */

# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Start)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Start(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_CWrnCtrl_Acknowledge_Start */

# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Return)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Return */

# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Start)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_MainFunction_Start */

# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Return)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Return(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Return */

# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Start)
#  undef Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Start(ECmpCmd Cmd); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_CWrnCtrl_Impl_OnCommand_Start */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Return)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Return(TWrnListMask ListMask, P2VAR(UInt16, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Count); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Return */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Start)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Start(TWrnListMask ListMask, P2VAR(UInt16, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Count); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_GetCount_Start */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Return)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Return(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Return */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Start)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Start(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_GetFirst_Start */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Return)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Return(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Return */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Start)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Start(TWrnListMask List, P2VAR(TWrnId, AUTOMATIC, RTE_WRNCTRL_APPL_VAR) Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_GetNext_Start */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Release_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Release_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Release_Return)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Release_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Release_Return(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Release_Return() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Release_Return */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Release_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Release_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Release_Start)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Release_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Release_Start(void); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Release_Start() ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Release_Start */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Return)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Return */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Start)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Ready_Start */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Return)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Return(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Return */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Start)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Start(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Gdt_Replay_Start */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Return)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Return */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Start)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Ready_Start */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Return)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Return(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Return */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Start)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Start(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Snd_Replay_Start */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Return)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Return(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Return(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Return */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Start)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Start(EWrnReason Reason, TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Start(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Ready_Start */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Return)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Return(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Return */

# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Start)
#  undef Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Start(TWrnId Id); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Runnable_WrnCtrl_WrnCtrl_Replays_Tt_Replay_Start */

# if defined (Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Return)
#  undef Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Return(Rte_ModeType_DcmControlDtcSetting mode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Return */

# if defined (Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Start)
#  undef Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Start(Rte_ModeType_DcmControlDtcSetting mode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_SwitchHook_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Start */

# if defined (Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Return)
#  undef Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Return(Rte_ModeType_DcmDiagnosticSessionControl mode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Return */

# if defined (Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Start)
#  undef Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Start(Rte_ModeType_DcmDiagnosticSessionControl mode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Start */

# if defined (Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Return)
#  undef Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Return(Rte_ModeType_DcmEcuReset mode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Return */

# if defined (Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Start)
#  undef Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Start(Rte_ModeType_DcmEcuReset mode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_SwitchHook_Dcm_DcmEcuReset_DcmEcuReset_Start */

# if defined (Rte_SwitchHook_EcuM_currentMode_currentMode_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_EcuM_currentMode_currentMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_SwitchHook_EcuM_currentMode_currentMode_Return)
#  undef Rte_SwitchHook_EcuM_currentMode_currentMode_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_EcuM_currentMode_currentMode_Return(Rte_ModeType_EcuM_Mode mode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_SwitchHook_EcuM_currentMode_currentMode_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_SwitchHook_EcuM_currentMode_currentMode_Return */

# if defined (Rte_SwitchHook_EcuM_currentMode_currentMode_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_SwitchHook_EcuM_currentMode_currentMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_SwitchHook_EcuM_currentMode_currentMode_Start)
#  undef Rte_SwitchHook_EcuM_currentMode_currentMode_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_SwitchHook_EcuM_currentMode_currentMode_Start(Rte_ModeType_EcuM_Mode mode); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_SwitchHook_EcuM_currentMode_currentMode_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_SwitchHook_EcuM_currentMode_currentMode_Start */

# if defined (Rte_Task_Activate) && (RTE_VFB_TRACE == 0)
#  undef Rte_Task_Activate /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Task_Activate)
#  undef Rte_Task_Activate /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Task_Activate(TaskType task); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Task_Activate(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Task_Activate */

# if defined (Rte_Task_Dispatch) && (RTE_VFB_TRACE == 0)
#  undef Rte_Task_Dispatch /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Task_Dispatch)
#  undef Rte_Task_Dispatch /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Task_Dispatch(TaskType task); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Task_Dispatch(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Task_Dispatch */

# if defined (Rte_Task_SetEvent) && (RTE_VFB_TRACE == 0)
#  undef Rte_Task_SetEvent /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Task_SetEvent)
#  undef Rte_Task_SetEvent /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Task_SetEvent(TaskType task, EventMaskType ev); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Task_SetEvent(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Task_SetEvent */

# if defined (Rte_Task_WaitEvent) && (RTE_VFB_TRACE == 0)
#  undef Rte_Task_WaitEvent /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Task_WaitEvent)
#  undef Rte_Task_WaitEvent /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Task_WaitEvent(TaskType task, EventMaskType ev); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Task_WaitEvent(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Task_WaitEvent */

# if defined (Rte_Task_WaitEventRet) && (RTE_VFB_TRACE == 0)
#  undef Rte_Task_WaitEventRet /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_Task_WaitEventRet)
#  undef Rte_Task_WaitEventRet /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_Task_WaitEventRet(TaskType task, EventMaskType ev); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_Task_WaitEventRet(arg1, arg2) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_Task_WaitEventRet */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Return)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Return(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Return */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Start)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Start(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State_Start */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Return)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Return(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Return */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Start)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Start(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B2_TIBtnMdl_State_State_Start */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Return)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Return(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Return */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Start)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Start(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State_Start */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Return)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Return(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Return */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Start)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Start(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State_Start */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Return)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Return(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Return */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Start)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Start(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State_Start */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Return)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Return(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Return */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Start)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Start(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State_Start */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Return)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Return(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Return */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Start)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Start(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State_Start */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Return)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Return(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Return */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Start)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Start(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B8_TIBtnMdl_State_State_Start */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Return)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Return(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Return */

# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Start)
#  undef Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Start(EBtnState data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_BtnMdl_ppSR_pBtnState_B9_TIBtnMdl_State_State_Start */

# if defined (Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Return)
#  undef Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Return(P2CONST(SG_TxFilteredSpeed, AUTOMATIC, RTE_CDD_TEST_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Return */

# if defined (Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Start)
#  undef Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Start(P2CONST(SG_TxFilteredSpeed, AUTOMATIC, RTE_CDD_TEST_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_CDD_Test_SG_TxFilteredSpeed_SG_TxFilteredSpeed_Start */

# if defined (Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Return)
#  undef Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Return(P2CONST(NvM_ECUSerialNumberType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Return */

# if defined (Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Start)
#  undef Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Start(P2CONST(NvM_ECUSerialNumberType, AUTOMATIC, RTE_DCMEXT_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_DcmExt_NV_ECUSerialNumber_Value_Start */

# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Return */

# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTER_Start */

# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Return */

# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_ENTRY_Start */

# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Return */

# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start)
#  undef Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_DcmExt_NV_ETM_Timeouts_ETM_EXIT_Start */

# if defined (Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Return)
#  undef Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Return(UInt16 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Return */

# if defined (Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Start)
#  undef Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Start(UInt16 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel_Start */

# if defined (Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Return)
#  undef Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Return(P2CONST(STRUCT_ECT_CONFIGURATION, AUTOMATIC, RTE_ECTMDLWRP_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Return */

# if defined (Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Start)
#  undef Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Start(P2CONST(STRUCT_ECT_CONFIGURATION, AUTOMATIC, RTE_ECTMDLWRP_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EctMdlWrp_EctConfiguration_EctConfiguration_Start */

# if defined (Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Return)
#  undef Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Return(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Return */

# if defined (Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Start)
#  undef Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Start(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF_Start */

# if defined (Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Return)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Return(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Return */

# if defined (Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Start)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Start(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EctMdl_EXT_CoolantSuperHot_EXT_CoolantSuperHot_Start */

# if defined (Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Return */

# if defined (Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue_Start */

# if defined (Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Return)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Return(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Return */

# if defined (Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Start)
#  undef Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Start(UInt8 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EctMdl_EXT_CoolantTempUnit_EXT_CoolantTempUnit_Start */

# if defined (Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Return)
#  undef Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Return(UInt16 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Return */

# if defined (Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Start)
#  undef Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Start(UInt16 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EngMdl_TIEngMdl_ComOut_FilteredRpm_Start */

# if defined (Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Return)
#  undef Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Return(UInt16 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Return */

# if defined (Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Start)
#  undef Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Start(UInt16 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho_Start */

# if defined (Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Return)
#  undef Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Return(P2CONST(STRUCT_FUEL_LEVEL_CAN, AUTOMATIC, RTE_FUELMDLWRP_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Return */

# if defined (Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Start)
#  undef Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Start(P2CONST(STRUCT_FUEL_LEVEL_CAN, AUTOMATIC, RTE_FUELMDLWRP_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn_Start */

# if defined (Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Return)
#  undef Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Return(UFIX16_SP01 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Return */

# if defined (Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Start)
#  undef Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Start(UFIX16_SP01 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_FuelMdlWrp_if_FuelLevelCanR_de_Tau_Start */

# if defined (Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Return)
#  undef Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Return(UFIX16_SP001 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Return */

# if defined (Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Start)
#  undef Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Start(UFIX16_SP001 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_FuelMdl_FuelLevelCanS_de_FuelLevelOut_Start */

# if defined (Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Return)
#  undef Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Return(EKeyPos data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Return */

# if defined (Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Start)
#  undef Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Start(EKeyPos data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos_Start */

# if defined (Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return)
#  undef Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return(P2CONST(OdoDataSetType, AUTOMATIC, RTE_ODOMDL_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Return */

# if defined (Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start)
#  undef Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start(P2CONST(OdoDataSetType, AUTOMATIC, RTE_ODOMDL_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_OdoMdl_NV_OdoMdl_NvMOdoData_OdoDataSetArray_Start */

# if defined (Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Return)
#  undef Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Return(uint32 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Return */

# if defined (Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Start)
#  undef Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Start(uint32 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_OdoMdl_tiSR_OdoOutMiles_Miles_Start */

# if defined (Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Return)
#  undef Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Return(UInt16 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Return */

# if defined (Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Start)
#  undef Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Start(UInt16 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_SpdMdl_TISpdMdl_ComOut_FilteredSpeed_Start */

# if defined (Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Return)
#  undef Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Return(Boolean data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Return */

# if defined (Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Start)
#  undef Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Start(Boolean data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed_Start */

# if defined (Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Return)
#  undef Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Return(UInt16 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Return */

# if defined (Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Start)
#  undef Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Start(UInt16 data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed_Start */

# if defined (Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Return)
#  undef Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Return(P2CONST(sTrcOut, AUTOMATIC, RTE_TRIPMDL_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Return */

# if defined (Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Start)
#  undef Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Start(P2CONST(sTrcOut, AUTOMATIC, RTE_TRIPMDL_APPL_DATA) data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_TripMdl_tiSR_TrcOut_deTrcOut_Start */

# if defined (Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Return) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Return)
#  undef Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Return /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Return(ETtMdlMask data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Return(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Return */

# if defined (Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Start) && (RTE_VFB_TRACE == 0)
#  undef Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
# endif
# if defined (Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Start)
#  undef Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Start /* PRQA S 0841 */ /* MD_MSR_19.6 */
FUNC(void, RTE_APPL_CODE) Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Start(ETtMdlMask data); /* PRQA S 0850, 0777 */ /* MD_MSR_19.8, MD_Rte_0777 */
# else
#  define Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Start(arg1) ((void)(0)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* Rte_WriteHook_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask_Start */

# define RTE_STOP_SEC_APPL_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* _RTE_HOOK_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0777:  MISRA rule: 5.1
     Reason:     The defined RTE naming convention may result in identifiers with more than 31 characters. The compliance to this rule is under user's control.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects to be unique within the significant characters.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
