-- VectorCAST 20.sp7 (04/21/21)
-- Test Case Script
--
-- Environment    : WARNMSG_CORE_OBSERVER_EXTN
-- Unit(s) Under Test: WarnMsg_Core_Observer_Extn
--
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:REMOVED_CL_PREFIX
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Subprogram: CheckEventAckConditions

-- Test Case: CheckEventAckConditions_Call
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckEventAckConditions
TEST.NEW
TEST.NAME:CheckEventAckConditions_Call
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventAckConditions.RetVal:<<malloc 5>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventAckConditions.RetVal:"TRUE"
TEST.END

-- Subprogram: CheckEventHiddenConditions

-- Test Case: CheckEventHiddenConditions_Call
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckEventHiddenConditions
TEST.NEW
TEST.NAME:CheckEventHiddenConditions_Call
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventHiddenConditions.RetVal:<<malloc 5>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventHiddenConditions.RetVal:"TRUE"
TEST.END

-- Subprogram: CheckEventInactiveConditions

-- Test Case: CheckEventInactiveConditions_FalseCdn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckEventInactiveConditions
TEST.NEW
TEST.NAME:CheckEventInactiveConditions_FalseCdn
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.Qualifier:512
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.RetVal:<<malloc 1>>
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.RetVal[0]:MACRO=TRUE
TEST.END

-- Test Case: CheckEventInactiveConditions_GPFWarn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckEventInactiveConditions
TEST.NEW
TEST.NAME:CheckEventInactiveConditions_GPFWarn
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.Qualifier:410
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.RetVal:<<malloc 1>>
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.RetVal[0]:MACRO=TRUE
TEST.END

-- Test Case: CheckEventInactiveConditions_SmartKeySysWarn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckEventInactiveConditions
TEST.NEW
TEST.NAME:CheckEventInactiveConditions_SmartKeySysWarn
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.Qualifier:406
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.RetVal:<<malloc 1>>
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.RetVal[0]:MACRO=TRUE
TEST.END

-- Test Case: CheckEventInactiveConditions_SmartKeySysWarn2
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckEventInactiveConditions
TEST.NEW
TEST.NAME:CheckEventInactiveConditions_SmartKeySysWarn2
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.Qualifier:407
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.RetVal:<<malloc 5>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.RetVal:"TRUE"
TEST.END

-- Test Case: CheckEventInactiveConditions_VoiceOpWarn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckEventInactiveConditions
TEST.NEW
TEST.NAME:CheckEventInactiveConditions_VoiceOpWarn
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.Qualifier:416
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.RetVal:<<malloc 5>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventInactiveConditions.RetVal:"TRUE"
TEST.END

-- Subprogram: CheckEventShowConditions

-- Test Case: CheckEventShowConditions_Call
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckEventShowConditions
TEST.NEW
TEST.NAME:CheckEventShowConditions_Call
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventShowConditions.RetVal:<<malloc 5>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventShowConditions.RetVal:"TRUE"
TEST.END

-- Subprogram: CheckEventTimeoutConditions

-- Test Case: CheckEventTimeoutConditions_Call
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckEventTimeoutConditions
TEST.NEW
TEST.NAME:CheckEventTimeoutConditions_Call
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventTimeoutConditions.RetVal:<<malloc 5>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckEventTimeoutConditions.RetVal:"TRUE"
TEST.END

-- Subprogram: CheckHideConditions

-- Test Case: CheckHideConditions_Call
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckHideConditions
TEST.NEW
TEST.NAME:CheckHideConditions_Call
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckHideConditions.RetVal:<<malloc 5>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckHideConditions.RetVal:"TRUE"
TEST.END

-- Subprogram: CheckInitCall

-- Test Case: CheckWarmInitCall_ClusterActive
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckInitCall
TEST.NEW
TEST.NAME:CheckWarmInitCall_ClusterActive
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevIgnSts_u8:MACRO=IgnOff
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOff
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_ACTIVE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckInitCall.return:MACRO=NO_INIT_REQUESTED
TEST.END

-- Test Case: CheckWarmInitCall_ClusterInactive
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckInitCall
TEST.NEW
TEST.NAME:CheckWarmInitCall_ClusterInactive
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 230 TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckInitCall.RetVal:<<malloc 5>>
    >>>     >>> Unknown parameter/object name RetVal
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 231 TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckInitCall.RetVal:"TRUE"
    >>>     >>> Unknown parameter/object name RetVal
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOff
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_INACTIVE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckInitCall.return:MACRO=NO_INIT_REQUESTED
TEST.END

-- Test Case: CheckWarmInitCall_IgnFail
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckInitCall
TEST.NEW
TEST.NAME:CheckWarmInitCall_IgnFail
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevIgnSts_u8:MACRO=IgnOn
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOn
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_ACTIVE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckInitCall.return:MACRO=NO_INIT_REQUESTED
TEST.END

-- Test Case: CheckWarmInitCall_IgnOn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckInitCall
TEST.NEW
TEST.NAME:CheckWarmInitCall_IgnOn
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 218 TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckInitCall.RetVal:<<malloc 6>>
    >>>     >>> Unknown parameter/object name RetVal
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 219 TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckInitCall.RetVal:"FALSE"
    >>>     >>> Unknown parameter/object name RetVal
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevIgnSts_u8:MACRO=IgnOff
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevStarterSts_u8:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOn
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_ACTIVE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Mdl_Dim_pp_illumStarterstatus_StarterStatus_Out:MACRO=STRTR_STS_OFF
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckInitCall.return:MACRO=WARM_INIT_REQUESTED
TEST.END

-- Test Case: CheckWarmInitCall_IgnOnFail
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckInitCall
TEST.NEW
TEST.NAME:CheckWarmInitCall_IgnOnFail
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevIgnSts_u8:MACRO=IgnOff
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOff
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_ACTIVE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckInitCall.return:MACRO=NO_INIT_REQUESTED
TEST.END

-- Test Case: CheckWarmInitCall_StarterFail
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckInitCall
TEST.NEW
TEST.NAME:CheckWarmInitCall_StarterFail
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevIgnSts_u8:MACRO=IgnOff
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevStarterSts_u8:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOff
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_ACTIVE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Mdl_Dim_pp_illumStarterstatus_StarterStatus_Out:1
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckInitCall.return:MACRO=NO_INIT_REQUESTED
TEST.END

-- Test Case: CheckWarmInitCall_StarterStsFail
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckInitCall
TEST.NEW
TEST.NAME:CheckWarmInitCall_StarterStsFail
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevIgnSts_u8:MACRO=IgnOff
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevStarterSts_u8:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOff
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_ACTIVE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Mdl_Dim_pp_illumStarterstatus_StarterStatus_Out:0
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckInitCall.return:MACRO=WARM_INIT_REQUESTED
TEST.END

-- Test Case: CheckWarmInitCall_UnlockFlagActive
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckInitCall
TEST.NEW
TEST.NAME:CheckWarmInitCall_UnlockFlagActive
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_MasterChime_u8:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOff
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_ACTIVE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_MasterChime_u8:1
TEST.END

-- Subprogram: CheckMsgCoreTrig

-- Test Case: FactpryModeDisabled
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckMsgCoreTrig
TEST.NEW
TEST.NAME:FactpryModeDisabled
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckMsgCoreTrig.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_CDcm_App_pp_FactoryMode_FactoryMode:MACRO=FACTORYMODE_DISABLED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus:MACRO=eHMI_READY
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckMsgCoreTrig.RetVal[0]:MACRO=TRUE
TEST.END

-- Test Case: FactpryModeEnabled
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckMsgCoreTrig
TEST.NEW
TEST.NAME:FactpryModeEnabled
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckMsgCoreTrig.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_CDcm_App_pp_FactoryMode_FactoryMode:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus:MACRO=eHMI_READY
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckMsgCoreTrig.RetVal[0]:MACRO=FALSE
TEST.END

-- Test Case: HmiActivated
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckMsgCoreTrig
TEST.NEW
TEST.NAME:HmiActivated
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckMsgCoreTrig.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus:MACRO=eHMI_READY
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckMsgCoreTrig.RetVal[0]:MACRO=TRUE
TEST.END

-- Test Case: HmiNotActivated
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckMsgCoreTrig
TEST.NEW
TEST.NAME:HmiNotActivated
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckMsgCoreTrig.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_CDcm_App_pp_FactoryMode_FactoryMode:MACRO=FACTORYMODE_DISABLED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus:MACRO=eHMI_NOT_READY
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckMsgCoreTrig.RetVal[0]:MACRO=FALSE
TEST.END

-- Subprogram: CheckPreUclTrigCdn

-- Test Case: CheckPreUclTrigCdn_Call
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckPreUclTrigCdn
TEST.NEW
TEST.NAME:CheckPreUclTrigCdn_Call
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckPreUclTrigCdn.RetVal:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckPreUclTrigCdn.RetVal[0]:MACRO=TRUE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckPreUclTrigCdn.RetVal[0]:MACRO=TRUE
TEST.END

-- Subprogram: CheckShowConditions

-- Test Case: ShowConditionFalse
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckShowConditions
TEST.NEW
TEST.NAME:ShowConditionFalse
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckShowConditions.RetVal:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_CDcm_App_pp_FactoryMode_FactoryMode:0
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckShowConditions.RetVal[0]:MACRO=TRUE
TEST.END

-- Test Case: ShowConditionTrue
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:CheckShowConditions
TEST.NEW
TEST.NAME:ShowConditionTrue
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckShowConditions.RetVal:<<malloc 5>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_CDcm_App_pp_FactoryMode_FactoryMode:1
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.CheckShowConditions.RetVal[0]:MACRO=FALSE
TEST.END

-- Subprogram: DetMessageId

-- Test Case: DetMessageId_FalseCase
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:DetMessageId
TEST.NEW
TEST.NAME:DetMessageId_FalseCase
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:590
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.DetMessageId.return:0
TEST.END

-- Test Case: DetMessageId_TrueCase
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:DetMessageId
TEST.NEW
TEST.NAME:DetMessageId_TrueCase
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:MACRO=WRN_NORM_GRISHU_02
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=WRN_NORM_GRISHU_02
TEST.END

-- Subprogram: MsgCoreExtnAddlAction

-- Test Case: MsgCoreExtnAddlAction_Call
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:MsgCoreExtnAddlAction
TEST.NEW
TEST.NAME:MsgCoreExtnAddlAction_Call
TEST.END

-- Subprogram: MsgCoreExtnAddlActiveChk

-- Test Case: MsgCoreExtnAddlActiveChk_FalseCase
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:MsgCoreExtnAddlActiveChk
TEST.NEW
TEST.NAME:MsgCoreExtnAddlActiveChk_FalseCase
TEST.VALUE:WarnMsg_Core_Observer_Extn.MsgCoreExtnAddlActiveChk.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.MsgCoreExtnAddlActiveChk.Data[0].Id:MSG_WRN_MFLID_MFLID_01_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.MsgCoreExtnAddlActiveChk.AddlChkSts:<<malloc 1>>
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.MsgCoreExtnAddlActiveChk.AddlChkSts[0]:MACRO=FALSE
TEST.END

-- Test Case: MsgCoreExtnAddlActiveChk_InitReq
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:MsgCoreExtnAddlActiveChk
TEST.NEW
TEST.NAME:MsgCoreExtnAddlActiveChk_InitReq
TEST.STUB:WarnMsg_Core_Observer_Extn.CheckInitCall
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckInitCall.return:MACRO=WARM_INIT_REQUESTED
TEST.VALUE:WarnMsg_Core_Observer_Extn.MsgCoreExtnAddlActiveChk.AddlChkSts:<<malloc 1>>
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.MsgCoreExtnAddlActiveChk.AddlChkSts[0]:MACRO=TRUE
TEST.END

-- Subprogram: OnDre_UCL_HudWarnStatus

-- Test Case: UpdPostAckCdns_NoHighPrioWarn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:OnDre_UCL_HudWarnStatus
TEST.NEW
TEST.NAME:UpdPostAckCdns_NoHighPrioWarn
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 529 TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=WARN_INT_NONE
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=WRN_NORM_ALOA_03
TEST.END

-- Subprogram: OnDre_UCL_WarnStatus

-- Test Case: OnDre_UCL_WarnStatus_FunCall
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:OnDre_UCL_WarnStatus
TEST.NEW
TEST.NAME:OnDre_UCL_WarnStatus_FunCall
TEST.END

-- Subprogram: ProgramInitRequest

-- Test Case: ProgramInitRequest_Call
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:ProgramInitRequest
TEST.NEW
TEST.NAME:ProgramInitRequest_Call
TEST.VALUE:WarnMsg_Core_Observer_Extn.ProgramInitRequest.Data:<<malloc 1>>
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.ProgramInitRequest.Data[0]:MACRO=COLD_INIT_REQUESTED
TEST.END

-- Subprogram: SendWarnStsInTask

-- Test Case: SendWarnStsInTask_Call
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:SendWarnStsInTask
TEST.NEW
TEST.NAME:SendWarnStsInTask_Call
TEST.VALUE:WarnMsg_Core_Observer_Extn.SendWarnStsInTask.RetVal:<<malloc 1>>
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.SendWarnStsInTask.RetVal[0]:MACRO=TRUE
TEST.END

-- Subprogram: StoreWarnConfigChk

-- Test Case: StoreWarnConfigChk_InvldId
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:StoreWarnConfigChk
TEST.NEW
TEST.NAME:StoreWarnConfigChk_InvldId
TEST.VALUE:WarnMsg_Core_Observer_Extn.StoreWarnConfigChk.p_message_id:miMaximum
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.StoreWarnConfigChk.return:WRN_FALSE
TEST.END

-- Test Case: StoreWarnConfigChk_NoStore
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:StoreWarnConfigChk
TEST.NEW
TEST.NAME:StoreWarnConfigChk_NoStore
TEST.VALUE:WarnMsg_Core_Observer_Extn.StoreWarnConfigChk.p_message_id:MSG_WRN_NORM_4WDSYS_08_INDEX
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.StoreWarnConfigChk.return:NO_STORE
TEST.END

-- Test Case: StoreWarnConfigChk_Payload
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:StoreWarnConfigChk
TEST.NEW
TEST.NAME:StoreWarnConfigChk_Payload
TEST.VALUE:WarnMsg_Core_Observer_Extn.StoreWarnConfigChk.p_message_id:MSG_WRN_NORM_ADUOFF_VM01_02_INDEX
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.StoreWarnConfigChk.return:WRN_TRUE
TEST.END

-- Test Case: StoreWarnConfigChk_Store
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:StoreWarnConfigChk
TEST.NEW
TEST.NAME:StoreWarnConfigChk_Store
TEST.VALUE:WarnMsg_Core_Observer_Extn.StoreWarnConfigChk.p_message_id:MSG_WRN_NORM_CRAWL_03_INDEX
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.StoreWarnConfigChk.return:WRN_STORE
TEST.END

-- Subprogram: TriggerAlert

-- Test Case: TriggerAlert_FnCall
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:TriggerAlert
TEST.NEW
TEST.NAME:TriggerAlert_FnCall
TEST.END

-- Subprogram: TriggerSWNoOperTmrChk

-- Test Case: TriggerSWNoOperTmrChkEnterCdn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:TriggerSWNoOperTmrChk
TEST.NEW
TEST.NAME:TriggerSWNoOperTmrChkEnterCdn
TEST.VALUE:WarnMsg_Core_Observer_Extn.TriggerSWNoOperTmrChk.pEvent:MACRO=EButtonIDs_Enter
TEST.END

-- Test Case: TriggerSWNoOperTmrChkEnterCdnBackCdn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:TriggerSWNoOperTmrChk
TEST.NEW
TEST.NAME:TriggerSWNoOperTmrChkEnterCdnBackCdn
TEST.VALUE:WarnMsg_Core_Observer_Extn.TriggerSWNoOperTmrChk.pEvent:MACRO=EButtonIDs_Back
TEST.END

-- Test Case: TriggerSWNoOperTmrChkEnterCdnNoBtn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:TriggerSWNoOperTmrChk
TEST.NEW
TEST.NAME:TriggerSWNoOperTmrChkEnterCdnNoBtn
TEST.VALUE:WarnMsg_Core_Observer_Extn.TriggerSWNoOperTmrChk.pEvent:MACRO=EButtonIDs_None
TEST.END

-- Subprogram: UpdPostAckCdns

-- Test Case: UpdPostAckCdns_Call
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdPostAckCdns
TEST.NEW
TEST.NAME:UpdPostAckCdns_Call
TEST.END

-- Subprogram: UpdPreAckCdns

-- Test Case: UpdPreAckCdns_Failure
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdPreAckCdns
TEST.NEW
TEST.NAME:UpdPreAckCdns_Failure
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 565 TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:MACRO=WARNING_DISPLAYED
    >>>     >>> 'WARNING_DISPLAYED' not defined in code
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:MACRO=TotalNumOfWarnings
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.ButtonEvent:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:0
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=TotalNumOfWarnings
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:MACRO=EButtonIDs_Back
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[9]:MACRO=EButtonSts_Short
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal[0]:MACRO=FALSE
TEST.END

-- Test Case: UpdPreAckCdns_NoWarnInDisplay
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdPreAckCdns
TEST.NEW
TEST.NAME:UpdPreAckCdns_NoWarnInDisplay
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:8
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.ButtonEvent:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:0
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:121
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:MACRO=EButtonIDs_Back
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[9]:MACRO=EButtonSts_Short
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal[0]:MACRO=FALSE
TEST.END

-- Test Case: UpdPreAckCdns_WarnInDisplayFalse
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdPreAckCdns
TEST.NEW
TEST.NAME:UpdPreAckCdns_WarnInDisplayFalse
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 595 TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:MACRO=WARNING_DISPLAYED
    >>>     >>> 'WARNING_DISPLAYED' not defined in code
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.ButtonEvent:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:0
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:0
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:MACRO=EButtonIDs_Up
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[9]:MACRO=EButtonSts_Short
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal[0]:MACRO=FALSE
TEST.END

-- Test Case: UpdPreAckCdns_WarnInDisplayIdDifferent
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdPreAckCdns
TEST.NEW
TEST.NAME:UpdPreAckCdns_WarnInDisplayIdDifferent
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 611 TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:MACRO=WARNING_DISPLAYED
    >>>     >>> 'WARNING_DISPLAYED' not defined in code
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.ButtonEvent:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:121
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:MACRO=EButtonIDs_Up
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[9]:MACRO=EButtonSts_Short
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal[0]:MACRO=FALSE
TEST.END

-- Test Case: UpdPreAckCdns_WarnInDisplayInvldId
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdPreAckCdns
TEST.NEW
TEST.NAME:UpdPreAckCdns_WarnInDisplayInvldId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.ButtonEvent:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=TotalNumOfWarnings
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:MACRO=EButtonIDs_Up
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[9]:MACRO=EButtonSts_Short
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal[0]:MACRO=FALSE
TEST.END

-- Test Case: UpdPreAckCdns_WarnInDisplay_FailButton
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdPreAckCdns
TEST.NEW
TEST.NAME:UpdPreAckCdns_WarnInDisplay_FailButton
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.ButtonEvent:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:2
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:0
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:64
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal[0]:MACRO=FALSE
TEST.END

-- Test Case: UpdPreAckCdns_WarnInDisplay_LongEvent
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdPreAckCdns
TEST.NEW
TEST.NAME:UpdPreAckCdns_WarnInDisplay_LongEvent
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 627 TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:MACRO=WARNING_DISPLAYED
    >>>     >>> 'WARNING_DISPLAYED' not defined in code
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.ButtonEvent:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:0
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:35
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal[0]:MACRO=TRUE
TEST.END

-- Test Case: UpdPreAckCdns_WarnInDisplay_OtherEvent
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdPreAckCdns
TEST.NEW
TEST.NAME:UpdPreAckCdns_WarnInDisplay_OtherEvent
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 642 TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:MACRO=WARNING_DISPLAYED
    >>>     >>> 'WARNING_DISPLAYED' not defined in code
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.ButtonEvent:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:2
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:0
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:32
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal[0]:MACRO=TRUE
TEST.END

-- Test Case: UpdPreAckCdns_WarnInDisplay_ShortEvent
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdPreAckCdns
TEST.NEW
TEST.NAME:UpdPreAckCdns_WarnInDisplay_ShortEvent
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 657 TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:MACRO=WARNING_DISPLAYED
    >>>     >>> 'WARNING_DISPLAYED' not defined in code
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.ButtonEvent:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:0
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:34
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.SeqMsgId:3
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.UpdPreAckCdns.RetVal[0]:MACRO=TRUE
TEST.END

-- Subprogram: UpdateWarnCanTx

-- Test Case: UpdateWarnCanTxAppl
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnCanTx
TEST.NEW
TEST.NAME:UpdateWarnCanTxAppl
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 735 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.DispdWarnId:MACRO=WRN_NORM_BVOOPE_02
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 736 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.CanTxFlg:MACRO=TRUE
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=WRN_NORM_BVOOPE_02
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:16
TEST.END

-- Test Case: UpdateWarnCanTxApplStopTx
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnCanTx
TEST.NEW
TEST.NAME:UpdateWarnCanTxApplStopTx
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 744 TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.DispdWarnId:MACRO=WRN_NORM_BVOOPE_02
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 745 TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.CanTxFlg:MACRO=TRUE
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 746 TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_CButton_Mdl_pp_Target_SW_TargetSw:0
    >>>     >>> Unknown parameter/object name Rte_CButton_Mdl_pp_Target_SW_TargetSw
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 751 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.DispdWarnId:MACRO=WRN_NORM_BVOOPE_02
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=WRN_NORM_BVOOPE_02
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:16
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[9]:0
TEST.END

-- Test Case: UpdateWarnCanTxApplStopTxIdChange
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnCanTx
TEST.NEW
TEST.NAME:UpdateWarnCanTxApplStopTxIdChange
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 759 TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.CanTxFlg:MACRO=TRUE
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 763 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.DispdWarnId:MACRO=TotalNumOfWarnings
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 764 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.CanTxFlg:MACRO=FALSE
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=WRN_NORM_BRK_02
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:128
TEST.END

-- Test Case: UpdateWarnCanTxBtnFalse
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnCanTx
TEST.NEW
TEST.NAME:UpdateWarnCanTxBtnFalse
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 772 TEST.STUB:WarnMsg_Core_Observer_Extn.CanTxReset
    >>>     >>> Could not stub WarnMsg_Core_Observer_Extn.CanTxReset
    >>> (E) @LINE: 773 TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.CanTxFlg:MACRO=TRUE
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 778 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.DispdWarnId:MACRO=WRN_NORM_BVOOPE_02
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=WRN_NORM_BVOOPE_02
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[7]:64
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:32
TEST.END

-- Test Case: UpdateWarnCanTxNotAppl
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnCanTx
TEST.NEW
TEST.NAME:UpdateWarnCanTxNotAppl
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 789 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.CanTxFlg:MACRO=FALSE
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=WRN_NORM_ECB_02
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:16
TEST.END

-- Test Case: UpdateWarnCanTxTmrApplFnCall
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnCanTx
TEST.NEW
TEST.NAME:UpdateWarnCanTxTmrApplFnCall
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 800 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.DispdWarnId:MACRO=WRN_NORM_GPF_MEV01_02
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=WRN_NORM_GPF_MEV01_02
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:32
TEST.END

-- Test Case: UpdateWarnCanTxWarnIdExceeded
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnCanTx
TEST.NEW
TEST.NAME:UpdateWarnCanTxWarnIdExceeded
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 811 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CanInfoData_S.CanTxFlg:MACRO=FALSE
    >>>     >>> Unknown parameter/object name l_CanInfoData_S
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:665
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].dynData[8]:32
TEST.END

-- Subprogram: UpdateWarnDataToUCL

-- Test Case: ActiveStoreWarn_ChangeQueue
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ActiveStoreWarn_ChangeQueue
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:16
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 17>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_CRAWL_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[1]:MSG_WRN_NORM_LCA_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[2]:MSG_WRN_NORM_CRAWL_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[3]:MSG_WRN_NORM_LCA_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[4]:MSG_WRN_NORM_LCA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[5]:MSG_WRN_NORM_4WDSYS_10_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[6]:MSG_WRN_NORM_4WDSYS_11_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[7]:MSG_WRN_NORM_ADASTT_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[8]:MSG_WRN_NORM_ADASTT_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[9]:MSG_WRN_NORM_ADASTT_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[10]:MSG_WRN_NORM_ADASTT_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[11]:MSG_WRN_NORM_ADASTT_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[12]:MSG_WRN_NORM_MTS_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[13]:MSG_WRN_NORM_EPB_18_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[14]:MSG_WRN_NORM_EPB_17_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[15]:MSG_WRN_NORM_ONACCP_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[16]:MSG_WRN_NORM_THESEN_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:17
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:17
TEST.END

-- Test Case: ActiveStoreWarn_ChangeQueueCvg
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ActiveStoreWarn_ChangeQueueCvg
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:29
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 31>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_CRAWL_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[1]:MSG_WRN_NORM_LCA_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[2]:MSG_WRN_NORM_CRAWL_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[3]:MSG_WRN_NORM_LCA_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[4]:MSG_WRN_NORM_LCA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[5]:MSG_WRN_NORM_4WDSYS_10_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[6]:MSG_WRN_NORM_4WDSYS_11_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[7]:MSG_WRN_NORM_ADASTT_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[8]:MSG_WRN_NORM_ADASTT_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[9]:MSG_WRN_NORM_ADASTT_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[10]:MSG_WRN_NORM_ADASTT_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[11]:MSG_WRN_NORM_ADASTT_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[12]:MSG_WRN_NORM_MTS_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[13]:MSG_WRN_NORM_EPB_18_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[14]:MSG_WRN_NORM_EPB_17_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[15]:MSG_WRN_NORM_ONACCP_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[16]:MSG_WRN_NORM_THESEN_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[17]:MSG_WRN_NORM_THESEN_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[18]:MSG_WRN_NORM_ACC_VM01_GME12_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[19]:MSG_WRN_NORM_ACC_VM01_GME12_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[20]:MSG_WRN_NORM_ACC_VM01_GME12_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[21]:MSG_WRN_NORM_ACC_VM01_GME12_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[22]:MSG_WRN_NORM_ACC_VM01_GME12_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[23]:MSG_WRN_NORM_ACC_VM01_GME12_08_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[24]:MSG_WRN_NORM_ACC_VM01_GME12_09_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[25]:MSG_WRN_NORM_LDA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[26]:MSG_WRN_NORM_HCS_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[27]:MSG_WRN_NORM_LTA_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[28]:MSG_WRN_NORM_LTA_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[29]:MSG_WRN_NORM_LTA_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[30]:MSG_WRN_NORM_LTA_08_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:30
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:30
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=TRUE
TEST.END

-- Test Case: ActiveStoreWarn_ChangeQueue_LockEna
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ActiveStoreWarn_ChangeQueue_LockEna
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:16
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=TRUE
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 17>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_CRAWL_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[1]:MSG_WRN_NORM_LCA_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[2]:MSG_WRN_NORM_CRAWL_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[3]:MSG_WRN_NORM_LCA_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[4]:MSG_WRN_NORM_LCA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[5]:MSG_WRN_NORM_4WDSYS_10_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[6]:MSG_WRN_NORM_4WDSYS_11_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[7]:MSG_WRN_NORM_ADASTT_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[8]:MSG_WRN_NORM_ADASTT_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[9]:MSG_WRN_NORM_ADASTT_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[10]:MSG_WRN_NORM_ADASTT_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[11]:MSG_WRN_NORM_ADASTT_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[12]:MSG_WRN_NORM_MTS_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[13]:MSG_WRN_NORM_EPB_18_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[14]:MSG_WRN_NORM_EPB_17_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[15]:MSG_WRN_NORM_ONACCP_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[16]:MSG_WRN_NORM_THESEN_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:17
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:16
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=TRUE
TEST.END

-- Test Case: ActiveStoreWarn_ChangeinPayload
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ActiveStoreWarn_ChangeinPayload
TEST.STUB:WarnMsg_Core_Observer_Extn.CheckPayloadChange
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:29
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 31>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_CRAWL_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[1]:MSG_WRN_NORM_LCA_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[2]:MSG_WRN_NORM_CRAWL_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[3]:MSG_WRN_NORM_LCA_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[4]:MSG_WRN_NORM_LCA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[5]:MSG_WRN_NORM_4WDSYS_10_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[6]:MSG_WRN_NORM_4WDSYS_11_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[7]:MSG_WRN_NORM_ADASTT_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[8]:MSG_WRN_NORM_ADASTT_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[9]:MSG_WRN_NORM_ADASTT_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[10]:MSG_WRN_NORM_ADASTT_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[11]:MSG_WRN_NORM_ADASTT_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[12]:MSG_WRN_NORM_MTS_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[13]:MSG_WRN_NORM_EPB_18_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[14]:MSG_WRN_NORM_EPB_17_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[15]:MSG_WRN_NORM_ONACCP_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[16]:MSG_WRN_NORM_THESEN_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[17]:MSG_WRN_NORM_THESEN_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[18]:MSG_WRN_NORM_ACC_VM01_GME12_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[19]:MSG_WRN_NORM_ACC_VM01_GME12_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[20]:MSG_WRN_NORM_ACC_VM01_GME12_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[21]:MSG_WRN_NORM_ACC_VM01_GME12_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[22]:MSG_WRN_NORM_ACC_VM01_GME12_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[23]:MSG_WRN_NORM_ACC_VM01_GME12_08_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[24]:MSG_WRN_NORM_ACC_VM01_GME12_09_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[25]:MSG_WRN_NORM_LDA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[26]:MSG_WRN_NORM_HCS_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[27]:MSG_WRN_NORM_LTA_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[28]:MSG_WRN_NORM_LTA_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[29]:MSG_WRN_NORM_LTA_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[30]:MSG_WRN_NORM_LTA_08_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:29
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckPayloadChange.DispWarnId[0]:MACRO=MSG_WRN_NORM_ADUOFF_VM01_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckPayloadChange.DispWarnId[1]:MACRO=MSG_WRN_NORM_ADUOFF_VM01_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckPayloadChange.return:MACRO=WRN_TRUE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:29
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.END

-- Test Case: ActiveStoreWarn_HmiInterrupt
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ActiveStoreWarn_HmiInterrupt
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:16
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_NextStartIdx_u8:15
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=TRUE
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_CScreenNavi_Mdl_pp_HMIInterruptType_HmiInterruptSts:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 17>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_CRAWL_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[1]:MSG_WRN_NORM_LCA_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[2]:MSG_WRN_NORM_CRAWL_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[3]:MSG_WRN_NORM_LCA_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[4]:MSG_WRN_NORM_LCA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[5]:MSG_WRN_NORM_4WDSYS_10_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[6]:MSG_WRN_NORM_4WDSYS_11_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[7]:MSG_WRN_NORM_ADASTT_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[8]:MSG_WRN_NORM_ADASTT_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[9]:MSG_WRN_NORM_ADASTT_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[10]:MSG_WRN_NORM_ADASTT_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[11]:MSG_WRN_NORM_ADASTT_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[12]:MSG_WRN_NORM_MTS_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[13]:MSG_WRN_NORM_EPB_18_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[14]:MSG_WRN_NORM_EPB_17_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[15]:MSG_WRN_NORM_ONACCP_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[16]:MSG_WRN_NORM_THESEN_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:17
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:16
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.END

-- Test Case: ActiveStoreWarn_LockDis
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ActiveStoreWarn_LockDis
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:29
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 31>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_CRAWL_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[1]:MSG_WRN_NORM_LCA_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[2]:MSG_WRN_NORM_CRAWL_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[3]:MSG_WRN_NORM_LCA_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[4]:MSG_WRN_NORM_LCA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[5]:MSG_WRN_NORM_4WDSYS_10_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[6]:MSG_WRN_NORM_4WDSYS_11_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[7]:MSG_WRN_NORM_ADASTT_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[8]:MSG_WRN_NORM_ADASTT_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[9]:MSG_WRN_NORM_ADASTT_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[10]:MSG_WRN_NORM_ADASTT_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[11]:MSG_WRN_NORM_ADASTT_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[12]:MSG_WRN_NORM_MTS_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[13]:MSG_WRN_NORM_EPB_18_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[14]:MSG_WRN_NORM_EPB_17_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[15]:MSG_WRN_NORM_ONACCP_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[16]:MSG_WRN_NORM_THESEN_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[17]:MSG_WRN_NORM_THESEN_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[18]:MSG_WRN_NORM_ACC_VM01_GME12_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[19]:MSG_WRN_NORM_ACC_VM01_GME12_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[20]:MSG_WRN_NORM_ACC_VM01_GME12_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[21]:MSG_WRN_NORM_ACC_VM01_GME12_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[22]:MSG_WRN_NORM_ACC_VM01_GME12_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[23]:MSG_WRN_NORM_ACC_VM01_GME12_08_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[24]:MSG_WRN_NORM_ACC_VM01_GME12_09_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[25]:MSG_WRN_NORM_LDA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[26]:MSG_WRN_NORM_HCS_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[27]:MSG_WRN_NORM_LTA_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[28]:MSG_WRN_NORM_LTA_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[29]:MSG_WRN_NORM_LTA_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[30]:MSG_WRN_NORM_LTA_08_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:29
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:29
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.END

-- Test Case: ActiveStoreWarn_NoEventHMI
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ActiveStoreWarn_NoEventHMI
TEST.IMPORT_FAILURES:
(E) @LINE: 1064 TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CompletedTx_u8:1
    >>> Unknown parameter/object name l_CompletedTx_u8
    >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.STUB:WarnMsg_Core_Observer_Extn.CheckPayloadChange
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:29
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 31>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_CRAWL_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[1]:MSG_WRN_NORM_LCA_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[2]:MSG_WRN_NORM_CRAWL_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[3]:MSG_WRN_NORM_LCA_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[4]:MSG_WRN_NORM_LCA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[5]:MSG_WRN_NORM_4WDSYS_10_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[6]:MSG_WRN_NORM_4WDSYS_11_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[7]:MSG_WRN_NORM_ADASTT_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[8]:MSG_WRN_NORM_ADASTT_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[9]:MSG_WRN_NORM_ADASTT_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[10]:MSG_WRN_NORM_ADASTT_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[11]:MSG_WRN_NORM_ADASTT_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[12]:MSG_WRN_NORM_MTS_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[13]:MSG_WRN_NORM_EPB_18_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[14]:MSG_WRN_NORM_EPB_17_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[15]:MSG_WRN_NORM_ONACCP_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[16]:MSG_WRN_NORM_THESEN_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[17]:MSG_WRN_NORM_THESEN_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[18]:MSG_WRN_NORM_ACC_VM01_GME12_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[19]:MSG_WRN_NORM_ACC_VM01_GME12_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[20]:MSG_WRN_NORM_ACC_VM01_GME12_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[21]:MSG_WRN_NORM_ACC_VM01_GME12_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[22]:MSG_WRN_NORM_ACC_VM01_GME12_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[23]:MSG_WRN_NORM_ACC_VM01_GME12_08_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[24]:MSG_WRN_NORM_ACC_VM01_GME12_09_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[25]:MSG_WRN_NORM_LDA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[26]:MSG_WRN_NORM_HCS_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[27]:MSG_WRN_NORM_LTA_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[28]:MSG_WRN_NORM_LTA_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[29]:MSG_WRN_NORM_LTA_07_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[30]:MSG_WRN_NORM_LTA_08_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:29
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckPayloadChange.DispWarnId[0]:MACRO=MSG_WRN_NORM_ADUOFF_VM01_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckPayloadChange.DispWarnId[1]:MACRO=MSG_WRN_NORM_ADUOFF_VM01_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.CheckPayloadChange.return:MACRO=WRN_TRUE
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rSR_MessageTabStatusData_MessageTabStatusDataData.data[0].messageTabActvData:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rSR_MessageTabStatusData_MessageTabStatusDataData.return:MACRO=E_NOT_OK
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:29
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.END

-- Test Case: ActiveStoreWarn_Queue
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ActiveStoreWarn_Queue
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 16>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_CRAWL_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[1]:MSG_WRN_NORM_LCA_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[2]:MSG_WRN_NORM_CRAWL_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[3]:MSG_WRN_NORM_LCA_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[4]:MSG_WRN_NORM_LCA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[5]:MSG_WRN_NORM_4WDSYS_10_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[6]:MSG_WRN_NORM_4WDSYS_11_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[7]:MSG_WRN_NORM_ADASTT_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[8]:MSG_WRN_NORM_ADASTT_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[9]:MSG_WRN_NORM_ADASTT_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[10]:MSG_WRN_NORM_ADASTT_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[11]:MSG_WRN_NORM_ADASTT_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[12]:MSG_WRN_NORM_MTS_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[13]:MSG_WRN_NORM_EPB_18_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[14]:MSG_WRN_NORM_EPB_17_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[15]:MSG_WRN_NORM_ONACCP_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:15
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:15
TEST.END

-- Test Case: ActiveStoreWarn_QueuePayload
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ActiveStoreWarn_QueuePayload
TEST.STUB:WarnMsg_Core_Observer_Extn.StoreDataTx
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_ADUOFF_VM01_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[1]:MSG_WRN_NORM_ADUOFF_VM01_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:2
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.StoreDataTx.DispWarnId[0]:MACRO=MSG_WRN_NORM_ADUOFF_VM01_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.StoreDataTx.DispWarnId[1]:MACRO=MSG_WRN_NORM_ADUOFF_VM01_03_INDEX
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:2
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=TRUE
TEST.END

-- Test Case: ActiveStoreWarn_QueueSecIter
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ActiveStoreWarn_QueueSecIter
TEST.IMPORT_FAILURES:
(E) @LINE: 1164 TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_CompletedTx_u8:1
    >>> Unknown parameter/object name l_CompletedTx_u8
    >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:16
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_NextStartIdx_u8:15
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 17>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_CRAWL_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[1]:MSG_WRN_NORM_LCA_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[2]:MSG_WRN_NORM_CRAWL_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[3]:MSG_WRN_NORM_LCA_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[4]:MSG_WRN_NORM_LCA_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[5]:MSG_WRN_NORM_4WDSYS_10_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[6]:MSG_WRN_NORM_4WDSYS_11_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[7]:MSG_WRN_NORM_ADASTT_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[8]:MSG_WRN_NORM_ADASTT_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[9]:MSG_WRN_NORM_ADASTT_04_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[10]:MSG_WRN_NORM_ADASTT_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[11]:MSG_WRN_NORM_ADASTT_06_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[12]:MSG_WRN_NORM_MTS_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[13]:MSG_WRN_NORM_EPB_18_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[14]:MSG_WRN_NORM_EPB_17_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[15]:MSG_WRN_NORM_ONACCP_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[16]:MSG_WRN_NORM_THESEN_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:17
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:17
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_StoreLockFlag_bool:MACRO=FALSE
TEST.END

-- Test Case: ActiveToNoActiveStoreWarn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ActiveToNoActiveStoreWarn
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:0
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:0
TEST.END

-- Test Case: ChangeinActiveStoreWarn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:ChangeinActiveStoreWarn
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_CRAWL_03_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[1]:MSG_WRN_ADAS_LCA_05_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:2
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:2
TEST.END

-- Test Case: NoActiveStoreWarn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:NoActiveStoreWarn
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:0
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:0
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_ActiveStoreCnt_u8:0
TEST.END

-- Test Case: UpdateWarnDataToUCL_HUDInst
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:UpdateWarnDataToUCL_HUDInst
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:5
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=HUD_INSTANCE
TEST.END

-- Test Case: UpdateWarnDataToUCL_WarnInst
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnDataToUCL
TEST.NEW
TEST.NAME:UpdateWarnDataToUCL_WarnInst
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.DispWarnId[0]:MSG_WRN_NORM_CRAWL_02_INDEX
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarningCount:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnDataToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.END

-- Subprogram: UpdateWarnStsToUCL

-- Test Case: UpdateWarnStsToUCL_AdasWarning
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_AdasWarning
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 788 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=WARN_INT_NONE
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_ADAS_OAA_01
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:75
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=ADAS_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=WRN_ADAS_OAA_01
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:MACRO=WRN_ADAS_OAA_01
TEST.END

-- Test Case: UpdateWarnStsToUCL_AdasWarning_FactoryEnabled
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_AdasWarning_FactoryEnabled
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 806 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=FACTORY_INT
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_ADAS_OAA_01
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_CDcm_App_pp_FactoryMode_FactoryMode:1
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=FACTORY_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=TotalNumOfWarnings
TEST.END

-- Test Case: UpdateWarnStsToUCL_AdasWarning_InterruptType
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_AdasWarning_InterruptType
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 841 TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarning:MACRO=WRN_ADAS_OAA_01
    >>>     >>> Could not find function Ctrl_warning_GetActiveWarningStatus
    >>>     >>>    in unit uut_prototype_stubs.
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 842 TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentStatus:MACRO=UI_WARNING_STATUS_ON
    >>>     >>> Could not find function Ctrl_warning_GetActiveWarningStatus
    >>>     >>>    in unit uut_prototype_stubs.
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 843 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=WARN_INT_NONE
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_ADAS_OAA_01
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:75
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=ADAS_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=WRN_ADAS_OAA_01
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:MACRO=WRN_ADAS_OAA_01
TEST.END

-- Test Case: UpdateWarnStsToUCL_FuelLidWarning
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_FuelLidWarning
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 862 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=FUEL_LID_INT
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_MFLID_MFLID_01
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:1
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=FUEL_LID_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=WRN_MFLID_MFLID_01
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:MACRO=WRN_MFLID_MFLID_01
TEST.END

-- Test Case: UpdateWarnStsToUCL_HUDWarning
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_HUDWarning
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_NORM_FCTA_02
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=HUD_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:MACRO=WRN_NORM_FCTA_02
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:293
TEST.VALUE:uut_prototype_stubs.Nvm_Adapter_NVM_Adapter_GetNVM_HM_ONOFF.pNvmData:"1"
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:MACRO=WRN_NORM_FCTA_02
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntHud_HUDWarningInterrupt_State:MACRO=WARN_INT
TEST.END

-- Test Case: UpdateWarnStsToUCL_HUDWarning_Invld
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_HUDWarning_Invld
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:0
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=TotalNumOfWarnings
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=HUD_INSTANCE
TEST.VALUE:uut_prototype_stubs.Nvm_Adapter_NVM_Adapter_GetNVM_HM_ONOFF.pNvmData[0]:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntHud_HUDWarningInterrupt_State:MACRO=WARN_INT_NONE
TEST.END

-- Test Case: UpdateWarnStsToUCL_HUDWarning_NvmOff
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_HUDWarning_NvmOff
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_NORM_FCTA_02
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=HUD_INSTANCE
TEST.VALUE:uut_prototype_stubs.Nvm_Adapter_NVM_Adapter_GetNVM_HM_ONOFF.pNvmData[0]:0
TEST.VALUE:uut_prototype_stubs.Nvm_Adapter_NVM_Adapter_GetNVM_HM_ONOFF.return:0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntHud_HUDWarningInterrupt_State:MACRO=WARN_INT_NONE
TEST.EXPECTED:uut_prototype_stubs.Nvm_Adapter_NVM_Adapter_GetNVM_HM_ONOFF.pNvmData[0]:0
TEST.END

-- Test Case: UpdateWarnStsToUCL_HUDWarning_NvmOn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_HUDWarning_NvmOn
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 966 TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=ALL_INSTANCE
    >>>     >>> 'ALL_INSTANCE' not defined in code
TEST.END_IMPORT_FAILURES:
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_NORM_FCTA_02
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=HUD_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:MACRO=WRN_NORM_FCTA_02
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:293
TEST.VALUE:uut_prototype_stubs.Nvm_Adapter_NVM_Adapter_GetNVM_HM_ONOFF.pNvmData[0]:1
TEST.VALUE:uut_prototype_stubs.Nvm_Adapter_NVM_Adapter_GetNVM_HM_ONOFF.return:0
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:MACRO=WRN_NORM_FCTA_02
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntHud_HUDWarningInterrupt_State:MACRO=WARN_INT
TEST.END

-- Test Case: UpdateWarnStsToUCL_InvldCat
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_InvldCat
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 894 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=WARN_INT_NONE
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.STUB:WarnMsg_Core_Observer_Extn.UpdateWarnInt
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_CUSTMIZE_PERSET_07
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:261
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnInt.return:MACRO=SETTINGS_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=SETTINGS_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=WRN_CUSTMIZE_PERSET_07
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:MACRO=WRN_CUSTMIZE_PERSET_07
TEST.END

-- Test Case: UpdateWarnStsToUCL_InvldWarning
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_InvldWarning
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 911 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=WARN_INT_NONE
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_CDcm_App_pp_FactoryMode_FactoryMode:0
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=TotalNumOfWarnings
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=WARN_INT_NONE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=TotalNumOfWarnings
TEST.END

-- Test Case: UpdateWarnStsToUCL_NomalWarning
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_NomalWarning
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 927 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=WARN_INT_NONE
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_NORM_EXWUOC_18
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:74
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=WARN_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=WRN_NORM_EXWUOC_18
TEST.END

-- Test Case: UpdateWarnStsToUCL_NomalWarning_FactoryEnabled
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_NomalWarning_FactoryEnabled
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 944 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=FACTORY_INT
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_NORM_EXWUOC_18
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_CDcm_App_pp_FactoryMode_FactoryMode:1
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=FACTORY_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=TotalNumOfWarnings
TEST.END

-- Test Case: UpdateWarnStsToUCL_NomalWarning_InterruptType
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_NomalWarning_InterruptType
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 954 TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_TriggeredWarnSts_A[519]:MACRO=UI_WARNING_STATUS_ON
    >>>     >>> Unknown parameter/object name l_TriggeredWarnSts_A
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 961 TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarning:MACRO=WRN_NORM_EXWUOC_18
    >>>     >>> Could not find function Ctrl_warning_GetActiveWarningStatus
    >>>     >>>    in unit uut_prototype_stubs.
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 962 TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentStatus:MACRO=UI_WARNING_STATUS_ON
    >>>     >>> Could not find function Ctrl_warning_GetActiveWarningStatus
    >>>     >>>    in unit uut_prototype_stubs.
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 963 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=WARN_INT_NONE
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_NORM_EXWUOC_18
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:74
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=WARN_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=WRN_NORM_EXWUOC_18
TEST.END

-- Test Case: UpdateWarnStsToUCL_NomalWarning_New
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_NomalWarning_New
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_NORM_EXWUOC_18
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.MsgType:MACRO=MSG_NEW
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:74
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=WARN_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=WRN_NORM_EXWUOC_18
TEST.END

-- Test Case: UpdateWarnStsToUCL_ProSrvInt
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_ProSrvInt
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 981 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=WARN_INT_NONE
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_PROSRV_PROSRV_02
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:367
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=PROSRV_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=WRN_PROSRV_PROSRV_02
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:MACRO=WRN_PROSRV_PROSRV_02
TEST.END

-- Test Case: UpdateWarnStsToUCL_SettingsInt
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_SettingsInt
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 1000 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=WARN_INT_NONE
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_CUSTMIZE_PERSET_07
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:349
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=SETTINGS_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=WRN_CUSTMIZE_PERSET_07
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.DetMessageId.RxdWarnId:MACRO=WRN_CUSTMIZE_PERSET_07
TEST.END

-- Test Case: UpdateWarnStsToUCL_TransportWarning
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_TransportWarning
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 1017 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=TRANSPORT_INT
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_TRANSPORT_TPACP_REQ02
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=TRANSPORT_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=WRN_TRANSPORT_TPACP_REQ02
TEST.END

-- Test Case: UpdateWarnStsToUCL_UnlockWarning
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:UpdateWarnStsToUCL
TEST.NEW
TEST.NAME:UpdateWarnStsToUCL_UnlockWarning
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 1034 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State:MACRO=UNLOCK_MODE_INT
    >>>     >>> Unknown parameter/object name Rte_WarnMsg_Core_Observer_pp_WarnHighInt_WarningHighInterrupt_State
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.STUB:WarnMsg_Core_Observer_Extn.DetMessageId
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].show:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].warningId:MACRO=WRN_DOOR_UNLMOD_02
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:<<malloc 2>>
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.UclDataTx[0].dynData:"0"
TEST.VALUE:WarnMsg_Core_Observer_Extn.UpdateWarnStsToUCL.WarnInst:MACRO=DEFAULT_INSTANCE
TEST.VALUE:WarnMsg_Core_Observer_Extn.DetMessageId.return:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_CDcm_App_pp_FactoryMode_FactoryMode:MACRO=FACTORYMODE_DISABLED
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnInt_WarningInterrupt_State:MACRO=UNLOCK_MODE_INT
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_WarnMsg_Core_Observer_pp_WarnIntId_WarningInterrupt_Identifier:MACRO=WRN_DOOR_UNLMOD_02
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.Rte_CDcm_App_pp_FactoryMode_FactoryMode:MACRO=FACTORYMODE_DISABLED
TEST.END

-- Subprogram: WarnMsg_Core_Observer_GetCurrIgnSts

-- Test Case: WarnMsg_Core_Observer_GetCurrIgnSts_ClusterFalse
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarnMsg_Core_Observer_GetCurrIgnSts
TEST.NEW
TEST.NAME:WarnMsg_Core_Observer_GetCurrIgnSts_ClusterFalse
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOn
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_INACTIVE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.WarnMsg_Core_Observer_GetCurrIgnSts.return:MACRO=APPLICATION_INACTIVE
TEST.END

-- Test Case: WarnMsg_Core_Observer_GetCurrIgnSts_IgnOff
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarnMsg_Core_Observer_GetCurrIgnSts
TEST.NEW
TEST.NAME:WarnMsg_Core_Observer_GetCurrIgnSts_IgnOff
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOff
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_ACTIVE
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.WarnMsg_Core_Observer_GetCurrIgnSts.return:MACRO=LIMITED
TEST.END

-- Test Case: WarnMsg_Core_Observer_GetCurrIgnSts_IgnOn
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarnMsg_Core_Observer_GetCurrIgnSts
TEST.NEW
TEST.NAME:WarnMsg_Core_Observer_GetCurrIgnSts_IgnOn
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOn
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_ACTIVE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_CScreenNavi_Mdl_pp_HMIInterruptType_HmiInterruptSts:1
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.WarnMsg_Core_Observer_GetCurrIgnSts.return:MACRO=NORMAL
TEST.END

-- Test Case: WarnMsg_Core_Observer_GetCurrIgnSts_ScreenBlank
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarnMsg_Core_Observer_GetCurrIgnSts
TEST.NEW
TEST.NAME:WarnMsg_Core_Observer_GetCurrIgnSts_ScreenBlank
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 1275 TEST.EXPECTED:WarnMsg_Core_Observer_Extn.WarnMsg_Core_Observer_GetCurrIgnSts.return:MACRO=FREEZE_IGN_MODE
    >>>     >>> 'FREEZE_IGN_MODE' not defined in code
TEST.END_IMPORT_FAILURES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=IgnOn
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode:MACRO=CLUSTER_ACTIVE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_CScreenNavi_Mdl_pp_HMIInterruptType_HmiInterruptSts:0
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.WarnMsg_Core_Observer_GetCurrIgnSts.return:MACRO=MSG_FREEZE_IGN_MODE
TEST.END

-- Subprogram: WarningSendChimeInfo

-- Test Case: WarningSendChimeInfo_ChimeCompleted
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarningSendChimeInfo
TEST.NEW
TEST.NAME:WarningSendChimeInfo_ChimeCompleted
TEST.VALUE:WarnMsg_Core_Observer_Extn.WarningSendChimeInfo.SeqStatus:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:121
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeId:MACRO=eSND_Master_Caution_BZR
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeStatus[0]:MACRO=eChimeStat_Completed
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_MasterChime_u8:MACRO=ChimeRelease
TEST.END

-- Test Case: WarningSendChimeInfo_ChimeIdle
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarningSendChimeInfo
TEST.NEW
TEST.NAME:WarningSendChimeInfo_ChimeIdle
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevWarnId_u16:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.WarningSendChimeInfo.SeqStatus:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:121
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeStatus[0]:MACRO=eChimeStat_Idle
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_MasterChime_u8:MACRO=ChimeRelease
TEST.END

-- Test Case: WarningSendChimeInfo_ChimeRelease
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarningSendChimeInfo
TEST.NEW
TEST.NAME:WarningSendChimeInfo_ChimeRelease
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 1184 TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:MACRO=WARNING_DISPLAYED
    >>>     >>> 'WARNING_DISPLAYED' not defined in code
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevWarnId_u16:121
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_MasterChime_u8:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.WarningSendChimeInfo.SeqStatus:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:121
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.return:MACRO=E_OK
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeId:MACRO=eSND_Master_Caution_BZR
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeStatus[0]:MACRO=eChimeStat_Completed
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_MasterChime_u8:MACRO=ChimeRelease
TEST.END

-- Test Case: WarningSendChimeInfo_ChimeRequest
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarningSendChimeInfo
TEST.NEW
TEST.NAME:WarningSendChimeInfo_ChimeRequest
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 1200 TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:MACRO=WARNING_DISPLAYED
    >>>     >>> 'WARNING_DISPLAYED' not defined in code
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevWarnId_u16:121
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_MasterChime_u8:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.WarningSendChimeInfo.SeqStatus:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:121
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.return:MACRO=E_OK
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeId:MACRO=eSND_Master_Caution_BZR
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeStatus[0]:MACRO=eChimeStat_Idle
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_MasterChime_u8:MACRO=ChimeRequest
TEST.END

-- Test Case: WarningSendChimeInfo_InVldChimeRelease
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarningSendChimeInfo
TEST.NEW
TEST.NAME:WarningSendChimeInfo_InVldChimeRelease
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_MasterChime_u8:121
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=TotalNumOfWarnings
TEST.END

-- Test Case: WarningSendChimeInfo_MasterChimeRelease
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarningSendChimeInfo
TEST.NEW
TEST.NAME:WarningSendChimeInfo_MasterChimeRelease
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevWarnId_u16:121
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_MasterChime_u8:0
TEST.VALUE:WarnMsg_Core_Observer_Extn.WarningSendChimeInfo.SeqStatus:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:121
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.return:MACRO=E_OK
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeId:MACRO=eSND_Master_Caution_BZR
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeStatus[0]:MACRO=eChimeStat_Completed
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_MasterChime_u8:MACRO=ChimeRelease
TEST.END

-- Test Case: WarningSendChimeInfo_WarnIdCdnFail
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarningSendChimeInfo
TEST.NEW
TEST.NAME:WarningSendChimeInfo_WarnIdCdnFail
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 1225 TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:MACRO=WARNING_DISPLAYED
    >>>     >>> 'WARNING_DISPLAYED' not defined in code
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevWarnId_u16:121
TEST.VALUE:WarnMsg_Core_Observer_Extn.WarningSendChimeInfo.SeqStatus:2
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=WRN_NORM_EPB_18
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.return:MACRO=E_OK
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeId:137
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeStatus[0]:1
TEST.END

-- Test Case: WarningSendChimeInfo_WarnIdFalse
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarningSendChimeInfo
TEST.NEW
TEST.NAME:WarningSendChimeInfo_WarnIdFalse
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=TotalNumOfWarnings
TEST.END

-- Test Case: WarningSendChimeInfo_WarnIdInvld
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarningSendChimeInfo
TEST.NEW
TEST.NAME:WarningSendChimeInfo_WarnIdInvld
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:5
TEST.END

-- Test Case: WarningSendChimeInfo_WarnIdVld.001
TEST.UNIT:WarnMsg_Core_Observer_Extn
TEST.SUBPROGRAM:WarningSendChimeInfo
TEST.NEW
TEST.NAME:WarningSendChimeInfo_WarnIdVld.001
TEST.VALUE:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevWarnId_u16:1
TEST.VALUE:WarnMsg_Core_Observer_Extn.WarningSendChimeInfo.SeqStatus:MACRO=MSG_NEW
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].visible:1
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.data[0].warningId:MACRO=WRN_NORM_TPWSR_01
TEST.VALUE:uut_prototype_stubs.Rte_Read_WarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData.return:MACRO=E_OK
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeId:MACRO=eSND_Master_Caution_BZR
TEST.VALUE:uut_prototype_stubs.AppSndCtrl_SndCtrl_CheckChimeStatus.pChimeStatus[0]:1
TEST.EXPECTED:WarnMsg_Core_Observer_Extn.<<GLOBAL>>.l_PrevWarnId_u16:MACRO=WRN_NORM_TPWSR_01
TEST.END
