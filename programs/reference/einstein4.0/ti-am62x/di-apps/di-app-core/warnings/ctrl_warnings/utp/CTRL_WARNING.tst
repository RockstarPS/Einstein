-- VectorCAST 20.sp7 (04/21/21)
-- Test Case Script
--
-- Environment    : CTRL_WARNING
-- Unit(s) Under Test: Ctrl_warning
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

-- Unit: Ctrl_warning

-- Subprogram: Ctrl_warning_GetActiveWarningStatus

-- Test Case: InvldWarnId
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_GetActiveWarningStatus
TEST.NEW
TEST.NAME:InvldWarnId
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[1].ExtWarningCurrentPayload[1]:0
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentStatus:UI_WARNING_STATUS_OFF
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentEvent:UI_WARNING_EVENT_FORCED
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentPayload[0]:1
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentPayload[1]:2
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentPayload[2]:3
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentPayload[3]:4
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarning:700
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus:<<malloc 1>>
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentStatus:UI_WARNING_STATUS_OFF
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentEvent:UI_WARNING_EVENT_NONE
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[0]:0
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[1]:0
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[2]:0
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[3]:0
TEST.END

-- Test Case: WarningEventForced
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_GetActiveWarningStatus
TEST.NEW
TEST.NAME:WarningEventForced
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[1].ExtWarningCurrentPayload[1]:0
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentStatus:UI_WARNING_STATUS_ON
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentEvent:UI_WARNING_EVENT_FORCED
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentPayload[0]:1
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentPayload[1]:2
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentPayload[2]:3
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[600].ExtWarningCurrentPayload[3]:4
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarning:600
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus:<<malloc 1>>
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentStatus:UI_WARNING_STATUS_ON
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentEvent:UI_WARNING_EVENT_FORCED
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[0]:1
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[1]:2
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[2]:3
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[3]:4
TEST.END

-- Test Case: WarningStatusOn
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_GetActiveWarningStatus
TEST.NEW
TEST.NAME:WarningStatusOn
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 28 TEST.VALUE:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].WarningCurrentStatus:UI_WARNING_STATUS_ON
    >>>     >>> Expected a field name from the record type CCAST_11_18
    >>>     >>> Read:     WarningCurrentStatus
    >>> (E) @LINE: 29 TEST.VALUE:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].WarningCurrentPayload:0
    >>>     >>> Expected a field name from the record type CCAST_11_18
    >>>     >>> Read:     WarningCurrentPayload
TEST.END_IMPORT_FAILURES:
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[1].ExtWarningCurrentStatus:UI_WARNING_STATUS_ON
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[1].ExtWarningCurrentEvent:UI_WARNING_EVENT_NONE
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[1].ExtWarningCurrentPayload[1]:0
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarning:1
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus:<<malloc 1>>
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentStatus:UI_WARNING_STATUS_ON
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentEvent:UI_WARNING_EVENT_NONE
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetActiveWarningStatus.CurrentWarningStatus[0].ExtWarningCurrentPayload[1]:0
TEST.END

-- Subprogram: Ctrl_warning_GetWarningDisplayedPayload

-- Test Case: InvldWarnId
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_GetWarningDisplayedPayload
TEST.NEW
TEST.NAME:InvldWarnId
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.CurWarningId:700
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[0]:0
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[1]:0
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[2]:0
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[3]:0
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[4]:0
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[5]:0
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[6]:0
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[7]:0
TEST.END

-- Test Case: ValidWarnId
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_GetWarningDisplayedPayload
TEST.NEW
TEST.NAME:ValidWarnId
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[456].WarningPayloadRecd[0]:1
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[456].WarningPayloadRecd[1]:2
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[456].WarningPayloadRecd[2]:3
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[456].WarningPayloadRecd[3]:4
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[456].WarningPayloadRecd[4]:5
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[456].WarningPayloadRecd[5]:6
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[456].WarningPayloadRecd[6]:7
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[456].WarningPayloadRecd[7]:8
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.CurWarningId:456
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[0]:1
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[1]:2
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[2]:3
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[3]:4
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[4]:5
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[5]:6
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[6]:7
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedPayload.DisplayedPayload[7]:8
TEST.END

-- Subprogram: Ctrl_warning_GetWarningDisplayedStatus

-- Test Case: InvalidWarnId
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_GetWarningDisplayedStatus
TEST.NEW
TEST.NAME:InvalidWarnId
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetWarningDisplayedStatus.CurWarningId:602
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetWarningDisplayedStatus.DisplayedStatus:<<malloc 1>>
TEST.END

-- Test Case: WarningDisplayedStatusOff
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_GetWarningDisplayedStatus
TEST.NEW
TEST.NAME:WarningDisplayedStatusOff
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_DisplydWrnSts_E[56]:UI_WARNING_STATUS_OFF
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetWarningDisplayedStatus.CurWarningId:56
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetWarningDisplayedStatus.DisplayedStatus:<<malloc 1>>
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetWarningDisplayedStatus.DisplayedStatus[0]:0
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedStatus.DisplayedStatus[0]:UI_WARNING_STATUS_OFF
TEST.END

-- Test Case: WarningDisplayedStatusOn
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_GetWarningDisplayedStatus
TEST.NEW
TEST.NAME:WarningDisplayedStatusOn
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_DisplydWrnSts_E[566]:UI_WARNING_STATUS_ON
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetWarningDisplayedStatus.CurWarningId:566
TEST.VALUE:Ctrl_warning.Ctrl_warning_GetWarningDisplayedStatus.DisplayedStatus:<<malloc 1>>
TEST.EXPECTED:Ctrl_warning.Ctrl_warning_GetWarningDisplayedStatus.DisplayedStatus[0]:UI_WARNING_STATUS_ON
TEST.END

-- Subprogram: Ctrl_warning_Get_Red_MasterLamp_Status

-- Test Case: Ctrl_warning_Get_Red_MasterLamp_Status.001
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_Get_Red_MasterLamp_Status
TEST.NEW
TEST.NAME:Ctrl_warning_Get_Red_MasterLamp_Status.001
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Red_MasterLamp_Status.LampStatus:<<malloc 2>>
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Red_MasterLamp_Status.LampStatus:"1"
TEST.END

-- Test Case: Ctrl_warning_Get_Red_MasterLamp_Status.002
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_Get_Red_MasterLamp_Status
TEST.NEW
TEST.NAME:Ctrl_warning_Get_Red_MasterLamp_Status.002
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Red_MasterLamp_Status.LampStatus:<<malloc 2>>
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Red_MasterLamp_Status.LampStatus:"1"
TEST.END

-- Test Case: Ctrl_warning_Get_Red_MasterLamp_Status.003
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_Get_Red_MasterLamp_Status
TEST.NEW
TEST.NAME:Ctrl_warning_Get_Red_MasterLamp_Status.003
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_MasterWarning_Lamp_Red[1]:1
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Red_MasterLamp_Status.LampStatus:<<malloc 1>>
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Red_MasterLamp_Status.LampStatus[0]:1
TEST.END

-- Subprogram: Ctrl_warning_Get_Yellow_MasterLamp_Status

-- Test Case: Ctrl_warning_Get_Yellow_MasterLamp_Status.001
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_Get_Yellow_MasterLamp_Status
TEST.NEW
TEST.NAME:Ctrl_warning_Get_Yellow_MasterLamp_Status.001
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Yellow_MasterLamp_Status.LampStatus:<<malloc 2>>
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Yellow_MasterLamp_Status.LampStatus:"1"
TEST.END

-- Test Case: Ctrl_warning_Get_Yellow_MasterLamp_Status.002
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_Get_Yellow_MasterLamp_Status
TEST.NEW
TEST.NAME:Ctrl_warning_Get_Yellow_MasterLamp_Status.002
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Yellow_MasterLamp_Status.LampStatus:<<malloc 1>>
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Yellow_MasterLamp_Status.LampStatus[0]:1
TEST.END

-- Test Case: Ctrl_warning_Get_Yellow_MasterLamp_Status.003
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_Get_Yellow_MasterLamp_Status
TEST.NEW
TEST.NAME:Ctrl_warning_Get_Yellow_MasterLamp_Status.003
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_MasterWarning_Lamp_Yellow[1]:1
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Yellow_MasterLamp_Status.LampStatus:<<malloc 1>>
TEST.VALUE:Ctrl_warning.Ctrl_warning_Get_Yellow_MasterLamp_Status.LampStatus[0]:1
TEST.END

-- Subprogram: Ctrl_warning_Init

-- Test Case: FunctionCall
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_Init
TEST.NEW
TEST.NAME:FunctionCall
TEST.END

-- Subprogram: Ctrl_warning_SetWarningDisplayedPayload

-- Test Case: InvalidWarnId
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_SetWarningDisplayedPayload
TEST.NEW
TEST.NAME:InvalidWarnId
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningId:700
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[0]:1
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[1]:2
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[2]:3
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[3]:4
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[4]:5
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[5]:6
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[6]:7
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[7]:8
TEST.END

-- Test Case: VldWarnData
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_SetWarningDisplayedPayload
TEST.NEW
TEST.NAME:VldWarnData
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningId:356
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[0]:10
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[1]:21
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[2]:32
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[3]:33
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[4]:45
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[5]:67
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[6]:89
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedPayload.CurWarningDispPayload[7]:90
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[356].WarningPayloadRecd[0]:10
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[356].WarningPayloadRecd[1]:21
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[356].WarningPayloadRecd[2]:32
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[356].WarningPayloadRecd[3]:33
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[356].WarningPayloadRecd[4]:45
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[356].WarningPayloadRecd[5]:67
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[356].WarningPayloadRecd[6]:89
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_DisplayedPayload_A[356].WarningPayloadRecd[7]:90
TEST.END

-- Subprogram: Ctrl_warning_SetWarningDisplayedStatus

-- Test Case: InVldWarnId
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_SetWarningDisplayedStatus
TEST.NEW
TEST.NAME:InVldWarnId
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedStatus.CurWarningId:700
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedStatus.CurWarningDispStatus:UI_WARNING_STATUS_ON
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_DisplydWrnSts_E[600]:UI_WARNING_STATUS_OFF
TEST.END

-- Test Case: StatusShow
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_SetWarningDisplayedStatus
TEST.NEW
TEST.NAME:StatusShow
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedStatus.CurWarningId:600
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedStatus.CurWarningDispStatus:WRNG_NOTIFIED_SHOW
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_DisplydWrnSts_E[600]:WRNG_NOTIFIED_SHOW
TEST.END

-- Test Case: ValidWarnId
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_SetWarningDisplayedStatus
TEST.NEW
TEST.NAME:ValidWarnId
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedStatus.CurWarningId:600
TEST.VALUE:Ctrl_warning.Ctrl_warning_SetWarningDisplayedStatus.CurWarningDispStatus:UI_WARNING_STATUS_ON
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_DisplydWrnSts_E[600]:UI_WARNING_STATUS_ON
TEST.END

-- Subprogram: Ctrl_warning_Task

-- Test Case: FunctionCall
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_Task
TEST.NEW
TEST.NAME:FunctionCall
TEST.END

-- Subprogram: Ctrl_warning_UpdateExtdPayload

-- Test Case: ExtdPayloadInvld
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_UpdateExtdPayload
TEST.NEW
TEST.NAME:ExtdPayloadInvld
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningCurId:700
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[0]:1
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[1]:2
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[2]:3
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[3]:4
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[4]:5
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[5]:6
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[6]:7
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[7]:9
TEST.END

-- Test Case: ExtdPayloadVld
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_UpdateExtdPayload
TEST.NEW
TEST.NAME:ExtdPayloadVld
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningCurId:285
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[0]:1
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[1]:2
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[2]:3
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[3]:4
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[4]:5
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[5]:6
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[6]:7
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateExtdPayload.WarningPayload[7]:9
TEST.END

-- Subprogram: Ctrl_warning_UpdateWarningStatus

-- Test Case: ExtdPayload
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_UpdateWarningStatus
TEST.NEW
TEST.NAME:ExtdPayload
TEST.COMPOUND_ONLY
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurId:285
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurStatus:UI_WARNING_STATUS_ON
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurEvent:UI_WARNING_EVENT_RETRIGGER
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningPayload:0
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[123].ExtWarningCurrentStatus:UI_WARNING_STATUS_OFF
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[123].ExtWarningCurrentEvent:UI_WARNING_EVENT_NONE
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentStatus:UI_WARNING_STATUS_ON
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentEvent:UI_WARNING_EVENT_RETRIGGER
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentPayload[0]:1
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentPayload[1]:2
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentPayload[2]:3
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentPayload[3]:4
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentPayload[4]:5
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentPayload[5]:6
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentPayload[6]:7
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentPayload[7]:9
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ExtdPayoadCalld_u8[285]:1
TEST.END

-- Test Case: ForcedEvent
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_UpdateWarningStatus
TEST.NEW
TEST.NAME:ForcedEvent
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[70].ExtWarningCurrentPayload[1]:0
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurId:123
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurStatus:UI_WARNING_STATUS_ON
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurEvent:UI_WARNING_EVENT_FORCED
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningPayload:0
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[123].ExtWarningCurrentStatus:UI_WARNING_STATUS_ON
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[123].ExtWarningCurrentEvent:UI_WARNING_EVENT_FORCED
TEST.END

-- Test Case: ForcedEvent.001
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_UpdateWarningStatus
TEST.NEW
TEST.NAME:ForcedEvent.001
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[70].ExtWarningCurrentPayload[1]:0
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurId:123
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurStatus:UI_WARNING_STATUS_ON
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurEvent:3
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningPayload:0
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[123].ExtWarningCurrentStatus:UI_WARNING_STATUS_ON
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[123].ExtWarningCurrentEvent:3
TEST.END

-- Test Case: InvalidValidWarningId
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_UpdateWarningStatus
TEST.NEW
TEST.NAME:InvalidValidWarningId
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurId:700
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurStatus:UI_WARNING_STATUS_ON
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurEvent:UI_WARNING_EVENT_NONE
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningPayload:5
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[70].ExtWarningCurrentStatus:UI_WARNING_STATUS_OFF
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[70].ExtWarningCurrentEvent:UI_WARNING_EVENT_NONE
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[70].ExtWarningCurrentPayload[0]:0
TEST.END

-- Test Case: ReTriggerEvent
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_UpdateWarningStatus
TEST.NEW
TEST.NAME:ReTriggerEvent
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[70].ExtWarningCurrentPayload[1]:0
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurId:285
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurStatus:UI_WARNING_STATUS_ON
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurEvent:UI_WARNING_EVENT_RETRIGGER
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningPayload:45
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[123].ExtWarningCurrentStatus:UI_WARNING_STATUS_OFF
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[123].ExtWarningCurrentEvent:UI_WARNING_EVENT_NONE
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentStatus:UI_WARNING_STATUS_ON
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentEvent:UI_WARNING_EVENT_RETRIGGER
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[285].ExtWarningCurrentPayload[0]:45
TEST.END

-- Test Case: ValidWarningId
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_UpdateWarningStatus
TEST.NEW
TEST.NAME:ValidWarningId
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[70].ExtWarningCurrentPayload[1]:0
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurId:70
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurStatus:UI_WARNING_STATUS_ON
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurEvent:UI_WARNING_EVENT_NONE
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningPayload:5
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[70].ExtWarningCurrentStatus:UI_WARNING_STATUS_ON
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[70].ExtWarningCurrentEvent:UI_WARNING_EVENT_NONE
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[70].ExtWarningCurrentPayload[0]:5
TEST.END

-- Test Case: WarningOff
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_UpdateWarningStatus
TEST.NEW
TEST.NAME:WarningOff
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[70].ExtWarningCurrentPayload[1]:0
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurId:123
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurStatus:UI_WARNING_STATUS_OFF
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningCurEvent:UI_WARNING_EVENT_FORCED
TEST.VALUE:Ctrl_warning.Ctrl_warning_UpdateWarningStatus.WarningPayload:0
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[123].ExtWarningCurrentStatus:UI_WARNING_STATUS_OFF
TEST.EXPECTED:Ctrl_warning.<<GLOBAL>>.l_ArbtnWarnData_S[123].ExtWarningCurrentEvent:UI_WARNING_EVENT_NONE
TEST.END

-- Subprogram: Ctrl_warning_Warning_Group_update

-- Test Case: FunctionCall
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:Ctrl_warning_Warning_Group_update
TEST.NEW
TEST.NAME:FunctionCall
TEST.END

-- Subprogram: update_MasterWarning_Lamp

-- Test Case: update_MasterWarning_Lamp.001
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:update_MasterWarning_Lamp
TEST.NEW
TEST.NAME:update_MasterWarning_Lamp.001
TEST.VALUE:Ctrl_warning.update_MasterWarning_Lamp.rtu_warningID:10
TEST.VALUE:Ctrl_warning.update_MasterWarning_Lamp.rtu_WarningStatus:MACRO=UI_WARNING_STATUS_ON
TEST.END

-- Test Case: update_MasterWarning_Lamp.002
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:update_MasterWarning_Lamp
TEST.NEW
TEST.NAME:update_MasterWarning_Lamp.002
TEST.VALUE:Ctrl_warning.update_MasterWarning_Lamp.rtu_warningID:1
TEST.VALUE:Ctrl_warning.update_MasterWarning_Lamp.rtu_WarningStatus:MACRO=UI_WARNING_STATUS_OFF
TEST.END

-- Test Case: update_MasterWarning_Lamp.003
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:update_MasterWarning_Lamp
TEST.NEW
TEST.NAME:update_MasterWarning_Lamp.003
TEST.VALUE:Ctrl_warning.update_MasterWarning_Lamp.rtu_warningID:602
TEST.VALUE:Ctrl_warning.update_MasterWarning_Lamp.rtu_WarningStatus:MACRO=UI_WARNING_STATUS_OFF
TEST.END

-- Test Case: update_MasterWarning_Lamp.004
TEST.UNIT:Ctrl_warning
TEST.SUBPROGRAM:update_MasterWarning_Lamp
TEST.NEW
TEST.NAME:update_MasterWarning_Lamp.004
TEST.VALUE:Ctrl_warning.<<GLOBAL>>.l_WarnAttriArr_A:2
TEST.VALUE:Ctrl_warning.update_MasterWarning_Lamp.rtu_warningID:1
TEST.VALUE:Ctrl_warning.update_MasterWarning_Lamp.rtu_WarningStatus:MACRO=UI_WARNING_STATUS_ON
TEST.END

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:ExtendedPayload
TEST.SLOT: "1", "Ctrl_warning", "Ctrl_warning_UpdateExtdPayload", "1", "ExtdPayloadVld"
TEST.SLOT: "2", "Ctrl_warning", "Ctrl_warning_UpdateWarningStatus", "1", "ExtdPayload"
TEST.END
--
