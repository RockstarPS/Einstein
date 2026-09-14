-- VectorCAST 20.sp7 (04/21/21)
-- Test Case Script
--
-- Environment    : WARNMSG_CORE_TMRSUPPORT
-- Unit(s) Under Test: WarnMsg_Core_TmrSupport
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

-- Subprogram: WarnMsg_Core_TmrSupport_Check_Timer

-- Test Case: WarnMsg_Core_TmrSupport_Check_Timer_TimerIdNegative
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Check_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Check_Timer_TimerIdNegative
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Check_Timer.timer_id:MACRO=eMaxNumof16BitTimers
TEST.END

-- Test Case: WarnMsg_Core_TmrSupport_Check_Timer_TimerNotElapsed
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Check_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Check_Timer_TimerNotElapsed
TEST.IMPORT_FAILURES:
(E) @LINE: 35 TEST.VALUE:WarnMsg_Core_TmrSupport.<<GLOBAL>>.l_WrnMsgCore_TmrSupport_StartedArray_u8[22]:MACRO=MSG_SUPPORT_TMR_RUNNING
    >>> Unknown parameter/object name l_WrnMsgCore_TmrSupport_StartedArray_u8
    >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_TmrSupport.<<GLOBAL>>.l_WrnMsgCore_TmrSupport_Timeout_Array_u32[22]:0
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Check_Timer.timer_id:MACRO=WARNING_CYCLE_TIMER_ID
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.hTimer:MACRO=WARNING_CYCLE_TIMER_ID
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.IsElapsed[0]:MACRO=FALSE
TEST.END

-- Test Case: WarnMsg_Core_TmrSupport_Check_Timer_TimerNotElapsedTimeout
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Check_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Check_Timer_TimerNotElapsedTimeout
TEST.IMPORT_FAILURES:
(E) @LINE: 47 TEST.VALUE:WarnMsg_Core_TmrSupport.<<GLOBAL>>.l_WrnMsgCore_TmrSupport_StartedArray_u8[22]:MACRO=MSG_SUPPORT_TMR_RUNNING
    >>> Unknown parameter/object name l_WrnMsgCore_TmrSupport_StartedArray_u8
    >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_TmrSupport.<<GLOBAL>>.l_WrnMsgCore_TmrSupport_Timeout_Array_u32[22]:300
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Check_Timer.timer_id:MACRO=WARNING_CYCLE_TIMER_ID
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.hTimer:MACRO=WARNING_CYCLE_TIMER_ID
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.IsElapsed[0]:MACRO=FALSE
TEST.END

-- Test Case: WarnMsg_Core_TmrSupport_Check_Timer_TimerNotStarted
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Check_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Check_Timer_TimerNotStarted
TEST.IMPORT_FAILURES:
(E) @LINE: 58 TEST.VALUE:WarnMsg_Core_TmrSupport.<<GLOBAL>>.l_WrnMsgCore_TmrSupport_StartedArray_u8[21]:MACRO=MSG_SUPPORT_TMR_STOPPED
    >>> Unknown parameter/object name l_WrnMsgCore_TmrSupport_StartedArray_u8
    >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Check_Timer.timer_id:MACRO=WARNING_HOLD_TIMER_ID
TEST.END

-- Test Case: WarnMsg_Core_TmrSupport_Check_Timer_TimerStarted
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Check_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Check_Timer_TimerStarted
TEST.IMPORT_FAILURES:
(E) @LINE: 68 TEST.VALUE:WarnMsg_Core_TmrSupport.<<GLOBAL>>.l_WrnMsgCore_TmrSupport_StartedArray_u8[21]:MACRO=MSG_SUPPORT_TMR_RUNNING
    >>> Unknown parameter/object name l_WrnMsgCore_TmrSupport_StartedArray_u8
    >>> Value Line Error - Command Ignored
(E) @LINE: 69 TEST.VALUE:WarnMsg_Core_TmrSupport.<<GLOBAL>>.l_WrnMsgCore_TmrSupport_StartedArray_u8[22]:MACRO=MSG_SUPPORT_TMR_RUNNING
    >>> Unknown parameter/object name l_WrnMsgCore_TmrSupport_StartedArray_u8
    >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_TmrSupport.<<GLOBAL>>.l_WrnMsgCore_TmrSupport_Timeout_Array_u32[21]:63536
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Check_Timer.timer_id:MACRO=WARNING_CYCLE_TIMER_ID
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.hTimer:MACRO=WARNING_CYCLE_TIMER_ID
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.Timeout:63536
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.IsElapsed[0]:1
TEST.END

-- Subprogram: WarnMsg_Core_TmrSupport_Start_Timer

-- Test Case: WarnMsg_Core_TmrSupport_Start_Timer_TimerCountFalseCase
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Start_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Start_Timer_TimerCountFalseCase
TEST.IMPORT_FAILURES:
(E) @LINE: 85 TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsStarted.hTimer:MACRO=WARNING_HOLD_TIMER_ID
    >>> Could not find function TmExt_Timer_IsStarted
    >>>    in unit uut_prototype_stubs.
    >>> Value Line Error - Command Ignored
(E) @LINE: 86 TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsStarted.IsStarted[0]:MACRO=FALSE
    >>> Could not find function TmExt_Timer_IsStarted
    >>>    in unit uut_prototype_stubs.
    >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Start_Timer.timer_id:MACRO=WARNING_HOLD_TIMER_ID
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Start_Timer.timeout_count:65535
TEST.END

-- Test Case: WarnMsg_Core_TmrSupport_Start_Timer_TimerCountNegative
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Start_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Start_Timer_TimerCountNegative
TEST.IMPORT_FAILURES:
(E) @LINE: 96 TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsStarted.hTimer:MACRO=WARNING_HOLD_TIMER_ID
    >>> Could not find function TmExt_Timer_IsStarted
    >>>    in unit uut_prototype_stubs.
    >>> Value Line Error - Command Ignored
(E) @LINE: 97 TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsStarted.IsStarted[0]:MACRO=FALSE
    >>> Could not find function TmExt_Timer_IsStarted
    >>>    in unit uut_prototype_stubs.
    >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Start_Timer.timer_id:MACRO=WARNING_HOLD_TIMER_ID
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Start_Timer.timeout_count:600
TEST.END

-- Test Case: WarnMsg_Core_TmrSupport_Start_Timer_TimerIDNegative
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Start_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Start_Timer_TimerIDNegative
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Start_Timer.timer_id:96
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Start_Timer.timeout_count:63536
TEST.END

-- Test Case: WarnMsg_Core_TmrSupport_Start_Timer_TimerIDPositive
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Start_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Start_Timer_TimerIDPositive
TEST.IMPORT_FAILURES:
(E) @LINE: 116 TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsStarted.hTimer:MACRO=WARNING_HOLD_TIMER_ID
    >>> Could not find function TmExt_Timer_IsStarted
    >>>    in unit uut_prototype_stubs.
    >>> Value Line Error - Command Ignored
(E) @LINE: 117 TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsStarted.IsStarted[0]:MACRO=FALSE
    >>> Could not find function TmExt_Timer_IsStarted
    >>>    in unit uut_prototype_stubs.
    >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Start_Timer.timer_id:MACRO=WARNING_HOLD_TIMER_ID
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Start_Timer.timeout_count:63536
TEST.END

-- Test Case: WarnMsg_Core_TmrSupport_Start_Timer_TimerNotStarted
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Start_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Start_Timer_TimerNotStarted
TEST.IMPORT_FAILURES:
(E) @LINE: 127 TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsStarted.hTimer:MACRO=WARNING_HOLD_TIMER_ID
    >>> Could not find function TmExt_Timer_IsStarted
    >>>    in unit uut_prototype_stubs.
    >>> Value Line Error - Command Ignored
(E) @LINE: 128 TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsStarted.IsStarted[0]:MACRO=TRUE
    >>> Could not find function TmExt_Timer_IsStarted
    >>>    in unit uut_prototype_stubs.
    >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Start_Timer.timer_id:MACRO=WARNING_HOLD_TIMER_ID
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Start_Timer.timeout_count:63536
TEST.END

-- Subprogram: WarnMsg_Core_TmrSupport_Stop_Timer

-- Test Case: WarnMsg_Core_TmrSupport_Stop_Timer_TimerIdNegative
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Stop_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Stop_Timer_TimerIdNegative
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Stop_Timer.timer_id:MACRO=eMaxNumof16BitTimers
TEST.END

-- Test Case: WarnMsg_Core_TmrSupport_Stop_Timer_TimerIdPositive
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Stop_Timer
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Stop_Timer_TimerIdPositive
TEST.VALUE:WarnMsg_Core_TmrSupport.WarnMsg_Core_TmrSupport_Stop_Timer.timer_id:MACRO=WARNING_CYCLE_TIMER_ID
TEST.END

-- Subprogram: WarnMsg_Core_TmrSupport_Task

-- Test Case: WarnMsg_Core_TmrSupport_Task_FunctionCoverage
TEST.UNIT:WarnMsg_Core_TmrSupport
TEST.SUBPROGRAM:WarnMsg_Core_TmrSupport_Task
TEST.NEW
TEST.NAME:WarnMsg_Core_TmrSupport_Task_FunctionCoverage
TEST.END
