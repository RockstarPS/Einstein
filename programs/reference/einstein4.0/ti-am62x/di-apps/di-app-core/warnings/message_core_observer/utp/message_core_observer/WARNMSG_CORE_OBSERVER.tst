-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : WARNMSG_CORE_OBSERVER
-- Unit(s) Under Test: WarnMsg_Core_Observer WarnMsg_Core_Support
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STANDARD_SPACING_R2
TEST.SCRIPT_FEATURE:OVERLOADED_CONST_SUPPORT
TEST.SCRIPT_FEATURE:UNDERSCORE_NULLPTR
TEST.SCRIPT_FEATURE:FULL_PARAMETER_TYPES
TEST.SCRIPT_FEATURE:STRUCT_DTOR_ADDS_POINTER
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: WarnMsg_Core_Observer

-- Subprogram: CWarnMsg_Core_Observer_Impl_MainFunction

-- Test Case: AW_R01_Impl_MainFunction_Invocation
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CWarnMsg_Core_Observer_Impl_MainFunction
TEST.NEW
TEST.NAME:AW_R01_Impl_MainFunction_Invocation
TEST.END

-- Subprogram: CWarnMsg_Core_Observer_Impl_OnCommand

-- Test Case: AW_R01_Impl_OnCommand_Invocation
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CWarnMsg_Core_Observer_Impl_OnCommand
TEST.NEW
TEST.NAME:AW_R01_Impl_OnCommand_Invocation
TEST.END

-- Subprogram: CmpActivation

-- Test Case: AW_R01_CmpActivation_Invocation
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:AW_R01_CmpActivation_Invocation
TEST.END

-- Subprogram: CmpActive

-- Test Case: AW_R04_TriggerChime
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:AW_R04_TriggerChime
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:53
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1]:2
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[2..3]:1
TEST.VALUE:uut_prototype_stubs.msg_SequencerGetAlertInfo.msgData:VECTORCAST_BUFFER
TEST.EXPECTED:uut_prototype_stubs.WarningSendChimeInfo.SeqStatus:1
TEST.END

-- Test Case: AW_R04_TriggerChimeFalse
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:AW_R04_TriggerChimeFalse
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:53
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1]:2
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[2]:0
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:1
TEST.VALUE:uut_prototype_stubs.msg_SequencerGetAlertInfo.msgData:VECTORCAST_BUFFER
TEST.EXPECTED:uut_prototype_stubs.WarningSendChimeInfo.SeqStatus:0
TEST.END

-- Test Case: AW_R09_AdditionalCheckCdnTest
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:AW_R09_AdditionalCheckCdnTest
TEST.VALUE:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.VALUE:uut_prototype_stubs.MsgCoreExtnAddlActiveChk.AddlChkSts:"TRUE"
TEST.EXPECTED:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.END

-- Test Case: AW_R09_NoActive_Warnings
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:AW_R09_NoActive_Warnings
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0..2]:2
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:1
TEST.VALUE:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.VALUE:uut_prototype_stubs.msg_SequencerGetAlertInfo.msgData:VECTORCAST_BUFFER
TEST.EXPECTED:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.END

-- Test Case: AW_R09_RobinTriggerFail
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:AW_R09_RobinTriggerFail
TEST.END

-- Test Case: AW_R09_TriggerCmpActiveWarnings
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:AW_R09_TriggerCmpActiveWarnings
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:5
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0..3]:-2147483648
TEST.VALUE:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.VALUE:uut_prototype_stubs.SendWarnStsInTask.RetVal:"FALSE"
TEST.VALUE:uut_prototype_stubs.msg_SequencerGetAlertInfo.msgData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.msg_SequencerGetAlertInfo.p_inst:2
TEST.EXPECTED:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.END

-- Test Case: AW_R09_TriggerCmpActiveWarnings_Active_Warn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:AW_R09_TriggerCmpActiveWarnings_Active_Warn
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:2
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1]:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[2]:2
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:1
TEST.VALUE:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.VALUE:uut_prototype_stubs.SendWarnStsInTask.RetVal:"FALSE"
TEST.VALUE:uut_prototype_stubs.msg_SequencerGetAlertInfo.msgData:VECTORCAST_BUFFER
TEST.EXPECTED:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.END

-- Test Case: AW_R09_TriggerRobin
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:AW_R09_TriggerRobin
TEST.VALUE:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.EXPECTED:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.END

-- Test Case: AW_R09_TriggerRobin.001
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:AW_R09_TriggerRobin.001
TEST.VALUE:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.VALUE:uut_prototype_stubs.SendWarnStsInTask.RetVal[0]:1
TEST.EXPECTED:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:0
TEST.END

-- Test Case: AW_R09_TriggerRobin.002
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:AW_R09_TriggerRobin.002
TEST.STUB:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.p_cur_warn_id:MSG_WARNING_TPMS_MANUAL_LEARN_ID_INDEX
TEST.VALUE:uut_prototype_stubs.CheckMsgCoreTrig.RetVal[0]:1
TEST.VALUE:uut_prototype_stubs.SendWarnStsInTask.RetVal[0]:1
TEST.VALUE:uut_prototype_stubs.msg_SequencerGetAlertInfo.msgData:VECTORCAST_INT1
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.p_cur_warn_id:MSG_WARNING_TPMS_MANUAL_LEARN_ID_INDEX
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.Status:1
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: AW_R01_CmpDeActivation_Invocation
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:AW_R01_CmpDeActivation_Invocation
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: AW_R01_CmpDeInit_Invocation
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:AW_R01_CmpDeInit_Invocation
TEST.VALUE:WarnMsg_Core_Observer.CmpDeInit.return:1
TEST.END

-- Subprogram: CmpDiag

-- Test Case: AW_R01_CmpDiag_Invocation
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:AW_R01_CmpDiag_Invocation
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: AW_R01_CmpDiagReturn_Invocation
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:AW_R01_CmpDiagReturn_Invocation
TEST.END

-- Subprogram: CmpInit

-- Test Case: AW_R01_ColdInitTrigger
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:AW_R01_ColdInitTrigger
TEST.VALUE:uut_prototype_stubs.ProgramInitRequest.Data[0]:1
TEST.END

-- Test Case: AW_R01_NoInitRequested
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:AW_R01_NoInitRequested
TEST.VALUE:uut_prototype_stubs.ProgramInitRequest.Data[0]:0
TEST.END

-- Test Case: AW_R01_WarnInitTrigger
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:AW_R01_WarnInitTrigger
TEST.VALUE:uut_prototype_stubs.ProgramInitRequest.Data[0]:2
TEST.END

-- Subprogram: OnDre_UCL_MultiZone_WarnStatus

-- Test Case: OnDre_UCL_MultiZone_WarnStatus.001
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:OnDre_UCL_MultiZone_WarnStatus
TEST.NEW
TEST.NAME:OnDre_UCL_MultiZone_WarnStatus.001
TEST.VALUE:uut_prototype_stubs.UpdPreAckCdns.SeqMsgId:1
TEST.VALUE:uut_prototype_stubs.UpdPreAckCdns.inst:0
TEST.VALUE:uut_prototype_stubs.UpdPreAckCdns.ButtonEvent:"0"
TEST.VALUE:uut_prototype_stubs.UpdPreAckCdns.RetVal:"0"
TEST.END

-- Test Case: OnDre_UCL_MultiZone_WarnStatus.002
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:OnDre_UCL_MultiZone_WarnStatus
TEST.NEW
TEST.NAME:OnDre_UCL_MultiZone_WarnStatus.002
TEST.VALUE:uut_prototype_stubs.UpdPreAckCdns.SeqMsgId:1
TEST.VALUE:uut_prototype_stubs.UpdPreAckCdns.inst:0
TEST.VALUE:uut_prototype_stubs.UpdPreAckCdns.ButtonEvent:"0"
TEST.END

-- Subprogram: WarnMsg_Core_Observer_HideMsgNotification

-- Test Case: AW_R10_HideMsgNotification_ReturnNegative
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_HideMsgNotification
TEST.NEW
TEST.NAME:AW_R10_HideMsgNotification_ReturnNegative
TEST.VALUE:uut_prototype_stubs.CheckHideConditions.RetVal[0]:0
TEST.END

-- Test Case: AW_R10_HideMsgNotification_ReturnPositive
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_HideMsgNotification
TEST.NEW
TEST.NAME:AW_R10_HideMsgNotification_ReturnPositive
TEST.VALUE:uut_prototype_stubs.CheckHideConditions.RetVal[0]:1
TEST.END

-- Subprogram: WarnMsg_Core_Observer_Notify_Status_Cb

-- Test Case: AW_R08_EventNewMsgTimeoutNegativeReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R08_EventNewMsgTimeoutNegativeReturn
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:128
TEST.VALUE:uut_prototype_stubs.CheckEventTimeoutConditions.RetVal[0]:0
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:128
TEST.END

-- Test Case: AW_R08_EventNewMsgTimeoutPositiveReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R08_EventNewMsgTimeoutPositiveReturn
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:2
TEST.VALUE:uut_prototype_stubs.CheckEventTimeoutConditions.RetVal[0]:0
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:2
TEST.END

-- Test Case: AW_R08_EventShowNegativeReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R08_EventShowNegativeReturn
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:8
TEST.VALUE:uut_prototype_stubs.CheckEventShowConditions.RetVal[0]:0
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:8
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.return:0
TEST.END

-- Test Case: AW_R08_EventShowPositiveReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R08_EventShowPositiveReturn
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:8
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Qualifier:53
TEST.VALUE:uut_prototype_stubs.CheckEventShowConditions.RetVal[0]:0
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:8
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Qualifier:53
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.return:0
TEST.END

-- Test Case: AW_R10_EventAckNegativeReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R10_EventAckNegativeReturn
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:1
TEST.VALUE:uut_prototype_stubs.CheckEventAckConditions.RetVal[0]:0
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:1
TEST.END

-- Test Case: AW_R10_EventHiddenPositiveReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R10_EventHiddenPositiveReturn
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:4
TEST.VALUE:uut_prototype_stubs.CheckHideConditions.RetVal[0]:0
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:4
TEST.END

-- Test Case: AW_R10_EventInactiveNegativeReturn_Wrn1
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R10_EventInactiveNegativeReturn_Wrn1
TEST.NOTES:
Warning WRN_NORM_GPF_MEV01_04 is set.
TEST.END_NOTES:
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:32
TEST.VALUE:uut_prototype_stubs.CheckEventInactiveConditions.Qualifier:410
TEST.VALUE:uut_prototype_stubs.CheckEventInactiveConditions.RetVal:"1"
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:32
TEST.END

-- Test Case: AW_R10_EventInactiveNegativeReturn_Wrn2
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R10_EventInactiveNegativeReturn_Wrn2
TEST.NOTES:
Warning WRN_NORM_VCOPE_03 is set.
TEST.END_NOTES:
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:32
TEST.VALUE:uut_prototype_stubs.CheckEventInactiveConditions.Qualifier:416
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:32
TEST.END

-- Test Case: AW_R10_EventInactiveNegativeReturn_Wrn3
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R10_EventInactiveNegativeReturn_Wrn3
TEST.NOTES:
Warning WRN_NORM_SMASTA_52 is set.
TEST.END_NOTES:
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:32
TEST.VALUE:uut_prototype_stubs.CheckEventInactiveConditions.Qualifier:406
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:32
TEST.END

-- Test Case: AW_R10_EventInactiveNegativeReturn_Wrn4
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R10_EventInactiveNegativeReturn_Wrn4
TEST.NOTES:
Warning WRN_NORM_SMASTA_53 is set.
TEST.END_NOTES:
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:32
TEST.VALUE:uut_prototype_stubs.CheckEventInactiveConditions.Qualifier:407
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:32
TEST.END

-- Test Case: AW_R10_EventInactivePoisitiveReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R10_EventInactivePoisitiveReturn
TEST.NOTES:

TEST.END_NOTES:
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:32
TEST.VALUE:uut_prototype_stubs.CheckEventInactiveConditions.Qualifier:1
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:32
TEST.END

-- Test Case: AW_R10_EventTimeoutNegativeReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R10_EventTimeoutNegativeReturn
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:2
TEST.VALUE:uut_prototype_stubs.CheckEventTimeoutConditions.RetVal[0]:0
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:2
TEST.END

-- Test Case: AW_R10_EventTimeoutPositiveReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R10_EventTimeoutPositiveReturn
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:2
TEST.VALUE:uut_prototype_stubs.CheckEventTimeoutConditions.RetVal[0]:0
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:2
TEST.END

-- Test Case: AW_R11_EventAckPositiveReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R11_EventAckPositiveReturn
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:1
TEST.VALUE:uut_prototype_stubs.CheckEventAckConditions.RetVal[0]:0
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:1
TEST.END

-- Test Case: AW_R11_EventHiddenNegativeReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:AW_R11_EventHiddenNegativeReturn
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:4
TEST.VALUE:uut_prototype_stubs.CheckHideConditions.RetVal[0]:0
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:4
TEST.END

-- Test Case: CWarnMsg_Core_Observer_Notify_Status_Cb_Coverage_DefaultCase
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Notify_Status_Cb
TEST.NEW
TEST.NAME:CWarnMsg_Core_Observer_Notify_Status_Cb_Coverage_DefaultCase
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_Notify_Status_Cb.Data[0]:256
TEST.END

-- Subprogram: WarnMsg_Core_Observer_SW_NoOperationTimer

-- Test Case: AW_R07_ValidEvent_Back
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_SW_NoOperationTimer
TEST.NEW
TEST.NAME:AW_R07_ValidEvent_Back
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_SW_NoOperationTimer.pEvent:2
TEST.VALUE:uut_prototype_stubs.TriggerSWNoOperTmrChk.return:1
TEST.EXPECTED:uut_prototype_stubs.TriggerSWNoOperTmrChk.pEvent:2
TEST.EXPECTED:uut_prototype_stubs.TriggerSWNoOperTmrChk.pEventType:0
TEST.END

-- Test Case: AW_R07_ValidEvent_Enter
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_SW_NoOperationTimer
TEST.NEW
TEST.NAME:AW_R07_ValidEvent_Enter
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_SW_NoOperationTimer.pEvent:1
TEST.VALUE:uut_prototype_stubs.TriggerSWNoOperTmrChk.return:1
TEST.EXPECTED:uut_prototype_stubs.TriggerSWNoOperTmrChk.pEvent:1
TEST.END

-- Test Case: AW_R07_ValidEvent_None
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_SW_NoOperationTimer
TEST.NEW
TEST.NAME:AW_R07_ValidEvent_None
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_SW_NoOperationTimer.pEvent:0
TEST.VALUE:uut_prototype_stubs.TriggerSWNoOperTmrChk.return:0
TEST.EXPECTED:uut_prototype_stubs.TriggerSWNoOperTmrChk.pEvent:0
TEST.END

-- Subprogram: WarnMsg_Core_Observer_SendStoreWarnToUCL

-- Test Case: AW_R02_SendStoreWarnToUCL_BufferFull
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_SendStoreWarnToUCL
TEST.NEW
TEST.NAME:AW_R02_SendStoreWarnToUCL_BufferFull
TEST.STUB:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[0]:'1'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[1]:'2'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[2]:'3'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[3]:'4'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[4]:'5'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[5]:'6'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[6]:'7'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[7]:'8'
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.p_message_id:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.return:0
TEST.VALUE:uut_prototype_stubs.msg_StoreGetCurrent.msgData:VECTORCAST_STR1
TEST.END

-- Test Case: AW_R02_SendStoreWarnToUCL_BufferFull.001
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_SendStoreWarnToUCL
TEST.NEW
TEST.NAME:AW_R02_SendStoreWarnToUCL_BufferFull.001
TEST.STUB:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[0]:'1'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[1]:'2'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[2]:'3'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[3]:'4'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[4]:'5'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[5]:'6'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[6]:'7'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[7]:'8'
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.p_message_id:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.return:1
TEST.VALUE:uut_prototype_stubs.msg_StoreGetCurrent.msgData:VECTORCAST_STR1
TEST.END

-- Test Case: AW_R02_SendStoreWarnToUCL_BufferFull.002
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_SendStoreWarnToUCL
TEST.NEW
TEST.NAME:AW_R02_SendStoreWarnToUCL_BufferFull.002
TEST.STUB:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[0]:'1'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[1]:'2'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[2]:'3'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[3]:'4'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[4]:'5'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[5]:'6'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[6]:'7'
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1[7]:'8'
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.p_message_id:MSG_WARNING_WELCOME_ID_INDEX
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.return:1
TEST.VALUE:uut_prototype_stubs.msg_StoreGetCurrent.msgData:VECTORCAST_INT1
TEST.END

-- Subprogram: WarnMsg_Core_Observer_ShowNewMsgNotification

-- Test Case: AW_R09_ShowNewMsgNotification_ReturnNegative
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_ShowNewMsgNotification
TEST.NEW
TEST.NAME:AW_R09_ShowNewMsgNotification_ReturnNegative
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_ShowNewMsgNotification.p_msg_info_S:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.CheckShowConditions.RetVal[0]:0
TEST.END

-- Test Case: AW_R09_ShowNewMsgNotification_ReturnPositve
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_ShowNewMsgNotification
TEST.NEW
TEST.NAME:AW_R09_ShowNewMsgNotification_ReturnPositve
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_ShowNewMsgNotification.p_msg_info_S:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.CheckShowConditions.RetVal[0]:1
TEST.END

-- Subprogram: WarnMsg_Core_Observer_StoreRemoveNotification

-- Test Case: AW_R02_StoreRemoveNotification_FunctionCoverage
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_StoreRemoveNotification
TEST.NEW
TEST.NAME:AW_R02_StoreRemoveNotification_FunctionCoverage
TEST.END

-- Subprogram: WarnMsg_Core_Observer_StoreWarnConfigChk

-- Test Case: AW_R02_StoreWarnConfigChk_OutOfScopeWarnId
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_StoreWarnConfigChk
TEST.NEW
TEST.NAME:AW_R02_StoreWarnConfigChk_OutOfScopeWarnId
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.p_message_id:miMaximum
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.return:0
TEST.END

-- Test Case: AW_R02_StoreWarnConfigChk_PositiveReturn
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_StoreWarnConfigChk
TEST.NEW
TEST.NAME:AW_R02_StoreWarnConfigChk_PositiveReturn
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.p_message_id:miUndefined
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.return:0
TEST.END

-- Test Case: AW_R02_StoreWarnConfigChk_StoreWarnActive
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_StoreWarnConfigChk
TEST.NEW
TEST.NAME:AW_R02_StoreWarnConfigChk_StoreWarnActive
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.return:0
TEST.END

-- Test Case: AW_R02_StoreWarnConfigChk_StoreWarnInActive
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_StoreWarnConfigChk
TEST.NEW
TEST.NAME:AW_R02_StoreWarnConfigChk_StoreWarnInActive
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_StoreWarnConfigChk.return:0
TEST.END

-- Subprogram: WarnMsg_Core_Observer_UpdateToUCL

-- Test Case: AW_R09_UpdateToUCL_InvalidIdCase
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_UpdateToUCL
TEST.NEW
TEST.NAME:AW_R09_UpdateToUCL_InvalidIdCase
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.p_cur_warn_id:miUndefined
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.Status:0
TEST.END

-- Test Case: AW_R09_UpdateToUCL_ValidStatusCase
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_UpdateToUCL
TEST.NEW
TEST.NAME:AW_R09_UpdateToUCL_ValidStatusCase
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.Status:0
TEST.VALUE:uut_prototype_stubs.CheckPreUclTrigCdn.RetVal[0]:0
TEST.END

-- Test Case: AW_R10_UpdateToUCL_InvalidStatusCase
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_UpdateToUCL
TEST.NEW
TEST.NAME:AW_R10_UpdateToUCL_InvalidStatusCase
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.p_cur_warn_id:miMaximum
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.Status:0
TEST.VALUE:uut_prototype_stubs.CheckPreUclTrigCdn.RetVal[0]:1
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.p_cur_warn_id:miMaximum
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.Status:0
TEST.END

-- Test Case: AW_R10_UpdateToUCL_InvalidStatusCase.001
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_UpdateToUCL
TEST.NEW
TEST.NAME:AW_R10_UpdateToUCL_InvalidStatusCase.001
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.p_cur_warn_id:miMaximum
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.Status:1
TEST.VALUE:uut_prototype_stubs.CheckPreUclTrigCdn.RetVal[0]:1
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.p_cur_warn_id:miMaximum
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.Status:1
TEST.END

-- Test Case: AW_R10_UpdateToUCL_InvalidStatusCase.002
TEST.UNIT:WarnMsg_Core_Observer
TEST.SUBPROGRAM:WarnMsg_Core_Observer_UpdateToUCL
TEST.NEW
TEST.NAME:AW_R10_UpdateToUCL_InvalidStatusCase.002
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.p_cur_warn_id:miMaximum
TEST.VALUE:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.Status:255
TEST.VALUE:uut_prototype_stubs.CheckPreUclTrigCdn.RetVal[0]:1
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.p_cur_warn_id:miMaximum
TEST.EXPECTED:WarnMsg_Core_Observer.WarnMsg_Core_Observer_UpdateToUCL.Status:255
TEST.END

-- Unit: WarnMsg_Core_Support

-- Subprogram: WarnMsg_Core_Observer_Warning_Get_status

-- Test Case: WarnMsg_Core_Observer_Warning_Get_status.001
TEST.UNIT:WarnMsg_Core_Support
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Warning_Get_status
TEST.NEW
TEST.NAME:WarnMsg_Core_Observer_Warning_Get_status.001
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarning:1
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentStatus:0
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentEvent:1
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[0]:1
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[1]:2
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[2]:2
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[3]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[4]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[5]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[6]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[7]:3
TEST.VALUE:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.Data[0]:3
TEST.EXPECTED:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.return:0
TEST.END

-- Test Case: WarnMsg_Core_Observer_Warning_Get_status.002
TEST.UNIT:WarnMsg_Core_Support
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Warning_Get_status
TEST.NEW
TEST.NAME:WarnMsg_Core_Observer_Warning_Get_status.002
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarning:1
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentStatus:0
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentEvent:2
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[0]:1
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[1]:2
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[2]:2
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[3]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[4]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[5]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[6]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[7]:3
TEST.VALUE:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.Data[0]:2
TEST.EXPECTED:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.Data[0]:2
TEST.EXPECTED:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.return:0
TEST.END

-- Test Case: WarnMsg_Core_Observer_Warning_Get_status.003
TEST.UNIT:WarnMsg_Core_Support
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Warning_Get_status
TEST.NEW
TEST.NAME:WarnMsg_Core_Observer_Warning_Get_status.003
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarning:1
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentStatus:0
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentEvent:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[0]:1
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[1]:2
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[2]:2
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[3]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[4]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[5]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[6]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[7]:3
TEST.VALUE:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.Data[0]:0
TEST.EXPECTED:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.Data[0]:0
TEST.EXPECTED:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.return:0
TEST.END

-- Test Case: WarnMsg_Core_Observer_Warning_Get_status.004
TEST.UNIT:WarnMsg_Core_Support
TEST.SUBPROGRAM:WarnMsg_Core_Observer_Warning_Get_status
TEST.NEW
TEST.NAME:WarnMsg_Core_Observer_Warning_Get_status.004
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarning:1
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentStatus:1
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentEvent:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[0]:1
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[1]:2
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[2]:2
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[3]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[4]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[5]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[6]:3
TEST.VALUE:uut_prototype_stubs.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[7]:3
TEST.VALUE:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.Data:<<malloc 1>>
TEST.VALUE:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.Data[0]:1
TEST.EXPECTED:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.Data[0]:1
TEST.EXPECTED:WarnMsg_Core_Support.WarnMsg_Core_Observer_Warning_Get_status.return:0
TEST.END
