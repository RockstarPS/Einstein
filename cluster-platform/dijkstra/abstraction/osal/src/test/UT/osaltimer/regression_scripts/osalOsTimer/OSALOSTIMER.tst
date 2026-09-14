-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSALOSTIMER
-- Unit(s) Under Test: DKOsalOsTimer
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

-- Unit: DKOsalOsTimer

-- Subprogram: (cl)dk::osal::OsTimer::OsTimer

-- Test Case: timer_create_fail
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::OsTimer
TEST.NEW
TEST.NAME:timer_create_fail
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId:3
TEST.VALUE:uut_prototype_stubs.timer_create.return:-1
TEST.EXPECTED:uut_prototype_stubs.timer_create.__clock_id:CLOCK_MONOTONIC
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_create.__timerid
<<uut_prototype_stubs.timer_create.__timerid>> = <<uut_prototype_stubs.timer_create.__timerid>> = &<<DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId>>;
TEST.END_STUB_VAL_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:<<dk::osal::OsTimer instance>>
{{ <<dk::osal::OsTimer instance>> != ( nullptr ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: timer_create_pass
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::OsTimer
TEST.NEW
TEST.NAME:timer_create_pass
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId:3
TEST.EXPECTED:uut_prototype_stubs.timer_create.__clock_id:CLOCK_MONOTONIC
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_create.__timerid
<<uut_prototype_stubs.timer_create.__timerid>> = <<uut_prototype_stubs.timer_create.__timerid>> = &<<DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId>>;
TEST.END_STUB_VAL_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:<<dk::osal::OsTimer instance>>
{{ <<dk::osal::OsTimer instance>> != ( nullptr ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::OsTimer::calcTimeOffsetMS

-- Test Case: calcTimeOffsetMS
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::calcTimeOffsetMS
TEST.NEW
TEST.NAME:calcTimeOffsetMS
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::calcTimeOffsetMS.timeoutMS:3000
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::calcTimeOffsetMS.ts.tv_sec:5
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::calcTimeOffsetMS.ts.tv_nsec:0
TEST.EXPECTED:uut_prototype_stubs.dk::osal::Clock::addTimeOffsetMS.msec:3000
TEST.EXPECTED:uut_prototype_stubs.dk::osal::Clock::addTimeOffsetMS.ts.tv_sec:5
TEST.EXPECTED:uut_prototype_stubs.dk::osal::Clock::addTimeOffsetMS.ts.tv_nsec:0
TEST.END

-- Subprogram: (cl)dk::osal::OsTimer::getCurrentTime

-- Test Case: clock_gettime_fail
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::getCurrentTime
TEST.NEW
TEST.NAME:clock_gettime_fail
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::getCurrentTime.ts.tv_sec:5
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::getCurrentTime.ts.tv_nsec:4
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:-1
TEST.EXPECTED:DKOsalOsTimer.(cl)dk::osal::OsTimer::getCurrentTime.ts.tv_sec:0
TEST.EXPECTED:DKOsalOsTimer.(cl)dk::osal::OsTimer::getCurrentTime.ts.tv_nsec:0
TEST.EXPECTED:uut_prototype_stubs.clock_gettime.__clock_id:CLOCK_MONOTONIC
TEST.END

-- Test Case: clock_gettime_pass
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::getCurrentTime
TEST.NEW
TEST.NAME:clock_gettime_pass
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::getCurrentTime.ts.tv_sec:5
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::getCurrentTime.ts.tv_nsec:4
TEST.EXPECTED:uut_prototype_stubs.clock_gettime.__clock_id:CLOCK_MONOTONIC
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.clock_gettime.__tp.__tp[0].tv_sec
{{<<uut_prototype_stubs.clock_gettime.__tp>>[0].tv_sec == ( 5 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.clock_gettime.__tp.__tp[0].tv_nsec
{{<<uut_prototype_stubs.clock_gettime.__tp>>[0].tv_nsec == ( 4 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::OsTimer::start

-- Test Case: timer_settime_fail
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::start
TEST.NEW
TEST.NAME:timer_settime_fail
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId:3
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::start.expireTime.tv_sec:4
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::start.expireTime.tv_nsec:40
TEST.VALUE:uut_prototype_stubs.timer_settime.return:-1
TEST.EXPECTED:uut_prototype_stubs.timer_settime.__timerid:3
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_value.tv_sec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_value.tv_sec == <<DKOsalOsTimer.(cl)dk::osal::OsTimer::start.expireTime>>.tv_sec}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_value.tv_nsec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_value.tv_nsec == <<DKOsalOsTimer.(cl)dk::osal::OsTimer::start.expireTime>>.tv_nsec}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_interval.tv_sec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_interval.tv_sec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_interval.tv_nsec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_interval.tv_nsec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: timer_settime_pass
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::start
TEST.NEW
TEST.NAME:timer_settime_pass
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId:3
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::start.expireTime.tv_sec:4
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::start.expireTime.tv_nsec:40
TEST.VALUE:uut_prototype_stubs.timer_settime.return:0
TEST.EXPECTED:uut_prototype_stubs.timer_settime.__timerid:3
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_value.tv_sec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_value.tv_sec == <<DKOsalOsTimer.(cl)dk::osal::OsTimer::start.expireTime>>.tv_sec}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_value.tv_nsec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_value.tv_nsec == <<DKOsalOsTimer.(cl)dk::osal::OsTimer::start.expireTime>>.tv_nsec}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_interval.tv_sec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_interval.tv_sec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_interval.tv_nsec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_interval.tv_nsec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::OsTimer::stop

-- Test Case: timer_settime_fail
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::stop
TEST.NEW
TEST.NAME:timer_settime_fail
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId:3
TEST.VALUE:uut_prototype_stubs.timer_settime.return:-1
TEST.EXPECTED:uut_prototype_stubs.timer_settime.__timerid:3
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_value.tv_sec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_value.tv_sec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_value.tv_nsec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_value.tv_nsec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_interval.tv_sec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_interval.tv_sec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_interval.tv_nsec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_interval.tv_nsec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: timer_settime_pass
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::stop
TEST.NEW
TEST.NAME:timer_settime_pass
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId:3
TEST.EXPECTED:uut_prototype_stubs.timer_settime.__timerid:3
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_value.tv_sec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_value.tv_sec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_value.tv_nsec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_value.tv_nsec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_interval.tv_sec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_interval.tv_sec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.timer_settime.__value.__value[0].it_interval.tv_nsec
{{<<uut_prototype_stubs.timer_settime.__value>>[0].it_interval.tv_nsec == ( 0 )}};
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::OsTimer::timeIsLessThan

-- Test Case: ts1_nsec_greater
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::timeIsLessThan
TEST.NEW
TEST.NAME:ts1_nsec_greater
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts1.tv_sec:5
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts1.tv_nsec:6
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts2.tv_sec:5
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts2.tv_nsec:5
TEST.EXPECTED:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.return:false
TEST.END

-- Test Case: ts1_sec_greater
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::timeIsLessThan
TEST.NEW
TEST.NAME:ts1_sec_greater
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts1.tv_sec:6
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts1.tv_nsec:5
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts2.tv_sec:5
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts2.tv_nsec:5
TEST.EXPECTED:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.return:false
TEST.END

-- Test Case: ts1_ts2_equal
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::timeIsLessThan
TEST.NEW
TEST.NAME:ts1_ts2_equal
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts1.tv_sec:5
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts1.tv_nsec:5
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts2.tv_sec:5
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts2.tv_nsec:5
TEST.EXPECTED:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.return:true
TEST.END

-- Test Case: ts2_greater_sec
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::timeIsLessThan
TEST.NEW
TEST.NAME:ts2_greater_sec
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts1.tv_sec:4
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts1.tv_nsec:4
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts2.tv_sec:5
TEST.VALUE:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.ts2.tv_nsec:5
TEST.EXPECTED:DKOsalOsTimer.(cl)dk::osal::OsTimer::timeIsLessThan.return:true
TEST.END

-- Subprogram: (cl)dk::osal::OsTimer::~OsTimer

-- Test Case: timer_delete_fail
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::~OsTimer
TEST.NEW
TEST.NAME:timer_delete_fail
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId:3
TEST.VALUE:uut_prototype_stubs.timer_delete.return:0
TEST.EXPECTED:DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId:0
TEST.EXPECTED:uut_prototype_stubs.timer_delete.__timerid:3
TEST.END

-- Test Case: timer_delete_pass
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::OsTimer::~OsTimer
TEST.NEW
TEST.NAME:timer_delete_pass
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.(cl).dk::osal::OsTimer.dk::osal::OsTimer.<<constructor>>.OsTimer().<<call>>:0
TEST.VALUE:DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId:3
TEST.VALUE:uut_prototype_stubs.timer_delete.return:-1
TEST.EXPECTED:DKOsalOsTimer.<<GLOBAL>>.dk::osal::sTimerId:0
TEST.EXPECTED:uut_prototype_stubs.timer_delete.__timerid:3
TEST.END

-- Subprogram: (cl)dk::osal::sigEventThreadFunction

-- Test Case: sival_ptr_notnull
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::sigEventThreadFunction
TEST.NEW
TEST.NAME:sival_ptr_notnull
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE_USER_CODE:DKOsalOsTimer.(cl)dk::osal::sigEventThreadFunction.sigval.sival_ptr
<<DKOsalOsTimer.(cl)dk::osal::sigEventThreadFunction.sigval>>.sival_ptr = (void*)( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sival_ptr_null
TEST.UNIT:DKOsalOsTimer
TEST.SUBPROGRAM:(cl)dk::osal::sigEventThreadFunction
TEST.NEW
TEST.NAME:sival_ptr_null
TEST.NOTES:
Requirement_AU29610-146974
TEST.END_NOTES:
TEST.VALUE_USER_CODE:DKOsalOsTimer.(cl)dk::osal::sigEventThreadFunction.sigval.sival_ptr
<<DKOsalOsTimer.(cl)dk::osal::sigEventThreadFunction.sigval>>.sival_ptr = (void*)( 0 );
TEST.END_VALUE_USER_CODE:
TEST.END
