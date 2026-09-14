-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RTCDRVCDD_IMX8QXP
-- Unit(s) Under Test: RtcDrvCdd_IMX8QXP
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

-- Subprogram: ReadBoardTemp

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:ReadBoardTemp
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 2 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)0 == IoHwAb_GetAsyncRawAdc(29U, &adcVal, &status) && 4U == status) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 1
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.pTemp:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:ReadBoardTemp
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 2 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)0 == IoHwAb_GetAsyncRawAdc(29U, &adcVal, &status) && 4U == status) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable status in branch 1
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.pTemp:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:ReadBoardTemp
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)0 == IoHwAb_GetAsyncRawAdc(29U, &adcVal, &status) && 4U == status) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable status in branch 1
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.pTemp:<<malloc 1>>
TEST.END

-- Test Case: ReadBoardTemp.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:ReadBoardTemp
TEST.NEW
TEST.NAME:ReadBoardTemp.001
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.pTemp:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.pTemp[0]:1
TEST.VALUE:uut_prototype_stubs.OsTrustedCall_IoHwAb_GetAsyncRawAdc.return:1
TEST.END

-- Test Case: ReadBoardTemp.002
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:ReadBoardTemp
TEST.NEW
TEST.NAME:ReadBoardTemp.002
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.pTemp:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.OsTrustedCall_IoHwAb_GetAsyncRawAdc.ErrorStatus[0]:1
TEST.END

-- Subprogram: RtcDrvCdd_Activate

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_Activate
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U == resetReason) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.ResetReason_GlobalVar.return:1
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_Activate
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U == resetReason) ==> TRUE
      (2) if ((uint8)0 == ReadBoardTemp(&temp)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.ReadBoardTemp
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.return:1
TEST.VALUE:uut_prototype_stubs.ResetReason_GlobalVar.return:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_Activate
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (0U == resetReason) ==> TRUE
      (2) if ((uint8)0 == ReadBoardTemp(&temp)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.ReadBoardTemp
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.return:0
TEST.VALUE:uut_prototype_stubs.ResetReason_GlobalVar.return:0
TEST.END

-- Test Case: RtcDrvCdd_Activate.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_Activate
TEST.NEW
TEST.NAME:RtcDrvCdd_Activate.001
TEST.VALUE_USER_CODE:<<testcase>>
#undef RTC_ALARM_FUNCTIONALITY_ENABLED
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: RtcDrvCdd_AlarmInterruptHandler

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_AlarmInterruptHandler
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U == sc_irq_status(rtc_ipc, 297U, 2U, &status)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_irq_status.return:1
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_AlarmInterruptHandler
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U == sc_irq_status(rtc_ipc, 297U, 2U, &status)) ==> TRUE
      (2) if ((status & 1U << 0U) != 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 2
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_irq_status.return:0
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_AlarmInterruptHandler
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (0U == sc_irq_status(rtc_ipc, 297U, 2U, &status)) ==> TRUE
      (2) if ((status & 1U << 0U) != 0U) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable status in branch 2
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_irq_status.return:0
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_AlarmInterruptHandler
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (0U == sc_irq_status(rtc_ipc, 297U, 2U, &status)) ==> TRUE
      (2) if ((status & 1U << 0U) != 0U) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable status in branch 2
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_irq_enable.mask:1
TEST.VALUE:uut_prototype_stubs.sc_irq_enable.return:0
TEST.VALUE:uut_prototype_stubs.sc_irq_status.status[0]:1
TEST.VALUE:uut_prototype_stubs.sc_irq_status.return:0
TEST.END

-- Test Case: RtcDrvCdd_AlarmInterruptHandler.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_AlarmInterruptHandler
TEST.NEW
TEST.NAME:RtcDrvCdd_AlarmInterruptHandler.001
TEST.VALUE:uut_prototype_stubs.sc_ipc_open.return:1
TEST.END

-- Subprogram: RtcDrvCdd_ClearAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_ClearAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U == sc_timer_cancel_rtc_alarm(rtc_ipc)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_timer_cancel_rtc_alarm.return:1
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_ClearAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U == sc_timer_cancel_rtc_alarm(rtc_ipc)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_ipc_open.return:1
TEST.VALUE:uut_prototype_stubs.sc_timer_cancel_rtc_alarm.return:1
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_ClearAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U == sc_timer_cancel_rtc_alarm(rtc_ipc)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_timer_cancel_rtc_alarm.return:0
TEST.END

-- Subprogram: RtcDrvCdd_ClearPeriodicAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_ClearPeriodicAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcDrvCdd_DeActivate

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_DeActivate
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcDrvCdd_DeInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_DeInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: RtcDrvCdd_DisableAlarmNotification

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_DisableAlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U == sc_irq_enable(rtc_ipc, 297U, 2U, 1U << 0U, 0)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_irq_enable.return:1
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_DisableAlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U == sc_irq_enable(rtc_ipc, 297U, 2U, 1U << 0U, 0)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_irq_enable.return:0
TEST.END

-- Test Case: BASIS-PATH-002.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_DisableAlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-002.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U == sc_irq_enable(rtc_ipc, 297U, 2U, 1U << 0U, 0)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_ipc_open.return:1
TEST.VALUE:uut_prototype_stubs.sc_irq_enable.return:0
TEST.END

-- Subprogram: RtcDrvCdd_EnableAlarmNotification

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_EnableAlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U == sc_irq_enable(rtc_ipc, 297U, 2U, 1U << 0U, 1)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_irq_enable.return:1
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_EnableAlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U == sc_irq_enable(rtc_ipc, 297U, 2U, 1U << 0U, 1)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_irq_enable.return:0
TEST.END

-- Test Case: BASIS-PATH-002.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_EnableAlarmNotification
TEST.NEW
TEST.NAME:BASIS-PATH-002.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U == sc_irq_enable(rtc_ipc, 297U, 2U, 1U << 0U, 1)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_ipc_open.return:1
TEST.VALUE:uut_prototype_stubs.sc_irq_enable.return:0
TEST.END

-- Subprogram: RtcDrvCdd_GetTime

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_GetTime
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U == sc_timer_get_rtc_time(rtc_ipc, &(p_time->year), &(p_time->month), &(p_time->day), &(p_time->hour), &(p_time->minute), &(p_time->second))) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_GetTime.p_time:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.sc_timer_get_rtc_time.return:1
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_GetTime
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U == sc_timer_get_rtc_time(rtc_ipc, &(p_time->year), &(p_time->month), &(p_time->day), &(p_time->hour), &(p_time->minute), &(p_time->second))) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_GetTime.p_time:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.sc_timer_get_rtc_time.return:0
TEST.END

-- Test Case: RtcDrvCdd_GetTime.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_GetTime
TEST.NEW
TEST.NAME:RtcDrvCdd_GetTime.001
TEST.VALUE:uut_prototype_stubs.sc_ipc_open.return:1
TEST.END

-- Subprogram: RtcDrvCdd_Init

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_Init
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U == sc_ipc_open(&rtc_ipc, (uint32)0x41480000UL)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_ipc_open.return:1
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_Init
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U == sc_ipc_open(&rtc_ipc, (uint32)0x41480000UL)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.sc_ipc_open.return:0
TEST.END

-- Subprogram: RtcDrvCdd_MainFunction

-- Test Case: BASIS-PATH-001-TEMPLATE
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE
TEST.BASIS_PATH:1 of 3 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (RtcDrvCdd_TempCompCnter >= (uint8)10) ==> FALSE
   Test Case Generation Notes:
      Cannot set RtcDrvCdd_TempCompCnter due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (RtcDrvCdd_TempCompCnter >= (uint8)10) ==> TRUE
      (2) if ((uint8)0 == ReadBoardTemp(&boardTemp)) ==> FALSE
   Test Case Generation Notes:
      Cannot set RtcDrvCdd_TempCompCnter due to assignment
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.ReadBoardTemp
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.return:1
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (RtcDrvCdd_TempCompCnter >= (uint8)10) ==> TRUE
      (2) if ((uint8)0 == ReadBoardTemp(&boardTemp)) ==> TRUE
   Test Case Generation Notes:
      Cannot set RtcDrvCdd_TempCompCnter due to assignment
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.ReadBoardTemp
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.return:0
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (RtcDrvCdd_TempCompCnter >= (uint8)10) ==> TRUE
      (2) if ((uint8)0 == ReadBoardTemp(&boardTemp)) ==> TRUE
   Test Case Generation Notes:
      Cannot set RtcDrvCdd_TempCompCnter due to assignment
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.ReadBoardTemp
TEST.VALUE:RtcDrvCdd_IMX8QXP.<<GLOBAL>>.RtcDrvCdd_TempCompCnter:20
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.return:0
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.002
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (RtcDrvCdd_TempCompCnter >= (uint8)10) ==> TRUE
      (2) if ((uint8)0 == ReadBoardTemp(&boardTemp)) ==> TRUE
   Test Case Generation Notes:
      Cannot set RtcDrvCdd_TempCompCnter due to assignment
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.ReadBoardTemp
TEST.VALUE:RtcDrvCdd_IMX8QXP.<<GLOBAL>>.RtcDrvCdd_TempCompCnter:20
TEST.VALUE:RtcDrvCdd_IMX8QXP.ReadBoardTemp.return:1
TEST.END

-- Subprogram: RtcDrvCdd_SetAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_SetAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)0 == RtcDrvCdd_EnableAlarmNotification()) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_SetAlarm.p_alarm:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification.return:1
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_SetAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)0 == RtcDrvCdd_EnableAlarmNotification()) ==> TRUE
      (2) if (0U == sc_timer_set_rtc_alarm(rtc_ipc, p_alarm->year, p_alarm->month, p_alarm->day, p_alarm->hour, p_alarm->minute, p_alarm->second)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_SetAlarm.p_alarm:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification.return:0
TEST.VALUE:uut_prototype_stubs.sc_timer_set_rtc_alarm.return:1
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_SetAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((uint8)0 == RtcDrvCdd_EnableAlarmNotification()) ==> TRUE
      (2) if (0U == sc_timer_set_rtc_alarm(rtc_ipc, p_alarm->year, p_alarm->month, p_alarm->day, p_alarm->hour, p_alarm->minute, p_alarm->second)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_SetAlarm.p_alarm:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification.return:0
TEST.VALUE:uut_prototype_stubs.sc_timer_set_rtc_alarm.return:0
TEST.END

-- Test Case: BASIS-PATH-003.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_SetAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-003.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((uint8)0 == RtcDrvCdd_EnableAlarmNotification()) ==> TRUE
      (2) if (0U == sc_timer_set_rtc_alarm(rtc_ipc, p_alarm->year, p_alarm->month, p_alarm->day, p_alarm->hour, p_alarm->minute, p_alarm->second)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_SetAlarm.p_alarm:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification.return:0
TEST.VALUE:uut_prototype_stubs.sc_ipc_open.return:1
TEST.VALUE:uut_prototype_stubs.sc_timer_set_rtc_alarm.return:0
TEST.END

-- Subprogram: RtcDrvCdd_SetPeriodicAlarm

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_SetPeriodicAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((uint8)0 == RtcDrvCdd_EnableAlarmNotification()) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_SetPeriodicAlarm.p_alarm:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification.return:1
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_SetPeriodicAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((uint8)0 == RtcDrvCdd_EnableAlarmNotification()) ==> TRUE
      (2) if (0U == sc_timer_set_rtc_periodic_alarm(rtc_ipc, (uint32_t)(*p_alarm))) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_SetPeriodicAlarm.p_alarm:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification.return:0
TEST.VALUE:uut_prototype_stubs.sc_timer_set_rtc_periodic_alarm.return:1
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_SetPeriodicAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((uint8)0 == RtcDrvCdd_EnableAlarmNotification()) ==> TRUE
      (2) if (0U == sc_timer_set_rtc_periodic_alarm(rtc_ipc, (uint32_t)(*p_alarm))) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_SetPeriodicAlarm.p_alarm:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification.return:0
TEST.VALUE:uut_prototype_stubs.sc_timer_set_rtc_periodic_alarm.return:0
TEST.END

-- Test Case: BASIS-PATH-003.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_SetPeriodicAlarm
TEST.NEW
TEST.NAME:BASIS-PATH-003.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((uint8)0 == RtcDrvCdd_EnableAlarmNotification()) ==> TRUE
      (2) if (0U == sc_timer_set_rtc_periodic_alarm(rtc_ipc, (uint32_t)(*p_alarm))) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_SetPeriodicAlarm.p_alarm:<<malloc 1>>
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_EnableAlarmNotification.return:0
TEST.VALUE:uut_prototype_stubs.sc_ipc_open.return:1
TEST.VALUE:uut_prototype_stubs.sc_timer_set_rtc_periodic_alarm.return:0
TEST.END

-- Subprogram: RtcDrvCdd_SetTime

-- Test Case: BASIS-PATH-001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_SetTime
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U == sc_timer_set_rtc_time(rtc_ipc, p_time->year, p_time->month, p_time->day, p_time->hour, p_time->minute, p_time->second)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_SetTime.p_time:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.sc_timer_set_rtc_time.return:1
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_SetTime
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U == sc_timer_set_rtc_time(rtc_ipc, p_time->year, p_time->month, p_time->day, p_time->hour, p_time->minute, p_time->second)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_SetTime.p_time:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.sc_timer_set_rtc_time.return:0
TEST.END

-- Test Case: RtcDrvCdd_SetTime.001
TEST.UNIT:RtcDrvCdd_IMX8QXP
TEST.SUBPROGRAM:RtcDrvCdd_SetTime
TEST.NEW
TEST.NAME:RtcDrvCdd_SetTime.001
TEST.VALUE:RtcDrvCdd_IMX8QXP.RtcDrvCdd_SetTime.p_time:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.sc_ipc_open.return:1
TEST.END
