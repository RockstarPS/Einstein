-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSALCLOCK_UTP
-- Unit(s) Under Test: DKOsalClock
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

-- Unit: DKOsalClock

-- Subprogram: (cl)dk::osal::Clock::addTimeOffsetMS

-- Test Case: add_ms_timespec
TEST.UNIT:DKOsalClock
TEST.SUBPROGRAM:(cl)dk::osal::Clock::addTimeOffsetMS
TEST.NEW
TEST.NAME:add_ms_timespec
TEST.NOTES:
Requirement_AU29610-146968
TEST.END_NOTES:
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetMS.msec:3300
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetMS.ts.tv_sec:5
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetMS.ts.tv_nsec:0
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetMS.ts.tv_sec:8
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetMS.ts.tv_nsec:300000000
TEST.END

-- Test Case: total_ns_greater_than_sec
TEST.UNIT:DKOsalClock
TEST.SUBPROGRAM:(cl)dk::osal::Clock::addTimeOffsetMS
TEST.NEW
TEST.NAME:total_ns_greater_than_sec
TEST.NOTES:
Requirement_AU29610-146968
TEST.END_NOTES:
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetMS.msec:3300
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetMS.ts.tv_sec:5
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetMS.ts.tv_nsec:700000000
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetMS.ts.tv_sec:9
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetMS.ts.tv_nsec:0
TEST.END

-- Subprogram: (cl)dk::osal::Clock::addTimeOffsetUS

-- Test Case: add_us_timespec
TEST.UNIT:DKOsalClock
TEST.SUBPROGRAM:(cl)dk::osal::Clock::addTimeOffsetUS
TEST.NEW
TEST.NAME:add_us_timespec
TEST.NOTES:
Requirement_AU29610-146968
TEST.END_NOTES:
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetUS.usec:6000000
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetUS.ts.tv_sec:4
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetUS.ts.tv_nsec:0
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetUS.ts.tv_sec:10
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetUS.ts.tv_nsec:0
TEST.END

-- Test Case: total_ns_greater_than_sec
TEST.UNIT:DKOsalClock
TEST.SUBPROGRAM:(cl)dk::osal::Clock::addTimeOffsetUS
TEST.NEW
TEST.NAME:total_ns_greater_than_sec
TEST.NOTES:
Requirement_AU29610-146968
TEST.END_NOTES:
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetUS.usec:6600000
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetUS.ts.tv_sec:4
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetUS.ts.tv_nsec:400000000
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetUS.ts.tv_sec:11
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::addTimeOffsetUS.ts.tv_nsec:0
TEST.END

-- Subprogram: (cl)dk::osal::Clock::getMontonicTime

-- Test Case: all_true
TEST.UNIT:DKOsalClock
TEST.SUBPROGRAM:(cl)dk::osal::Clock::getMontonicTime
TEST.NEW
TEST.NAME:all_true
TEST.NOTES:
Requirement_AU29610-146968
TEST.END_NOTES:
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getMontonicTime.ts.tv_sec:5
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getMontonicTime.ts.tv_nsec:400
TEST.VALUE:uut_prototype_stubs.clock_gettime.__tp[0].tv_sec:6
TEST.VALUE:uut_prototype_stubs.clock_gettime.__tp[0].tv_nsec:1200
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::getMontonicTime.ts.tv_sec:6
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::getMontonicTime.ts.tv_nsec:1200
TEST.EXPECTED:uut_prototype_stubs.clock_gettime.__clock_id:2
TEST.END

-- Test Case: clock_gettime_err
TEST.UNIT:DKOsalClock
TEST.SUBPROGRAM:(cl)dk::osal::Clock::getMontonicTime
TEST.NEW
TEST.NAME:clock_gettime_err
TEST.NOTES:
Requirement_AU29610-146968
TEST.END_NOTES:
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getMontonicTime.ts.tv_sec:5
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getMontonicTime.ts.tv_nsec:400
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:-1
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::getMontonicTime.ts.tv_sec:0
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::getMontonicTime.ts.tv_nsec:0
TEST.END

-- Subprogram: (cl)dk::osal::Clock::getSystemTime

-- Test Case: all_true
TEST.UNIT:DKOsalClock
TEST.SUBPROGRAM:(cl)dk::osal::Clock::getSystemTime
TEST.NEW
TEST.NAME:all_true
TEST.NOTES:
Requirement_AU29610-146968
TEST.END_NOTES:
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getSystemTime.ts.tv_sec:5
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getSystemTime.ts.tv_nsec:200
TEST.VALUE:uut_prototype_stubs.clock_gettime.__tp[0].tv_sec:4
TEST.VALUE:uut_prototype_stubs.clock_gettime.__tp[0].tv_nsec:3000
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::getSystemTime.ts.tv_sec:4
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::getSystemTime.ts.tv_nsec:3000
TEST.EXPECTED:uut_prototype_stubs.clock_gettime.__clock_id:0
TEST.END

-- Test Case: clock_gettime_err
TEST.UNIT:DKOsalClock
TEST.SUBPROGRAM:(cl)dk::osal::Clock::getSystemTime
TEST.NEW
TEST.NAME:clock_gettime_err
TEST.NOTES:
Requirement_AU29610-146968
TEST.END_NOTES:
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getSystemTime.ts.tv_sec:5
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getSystemTime.ts.tv_nsec:200
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:-1
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::getSystemTime.ts.tv_sec:0
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::getSystemTime.ts.tv_nsec:0
TEST.END

-- Subprogram: (cl)dk::osal::Clock::getTimeDiffUS

-- Test Case: diff_between_two_timespecs
TEST.UNIT:DKOsalClock
TEST.SUBPROGRAM:(cl)dk::osal::Clock::getTimeDiffUS
TEST.NEW
TEST.NAME:diff_between_two_timespecs
TEST.NOTES:
Requirement_AU29610-146968
TEST.END_NOTES:
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getTimeDiffUS.ts1.tv_sec:3
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getTimeDiffUS.ts1.tv_nsec:400000000
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getTimeDiffUS.ts2.tv_sec:6
TEST.VALUE:DKOsalClock.(cl)dk::osal::Clock::getTimeDiffUS.ts2.tv_nsec:430000000
TEST.EXPECTED:DKOsalClock.(cl)dk::osal::Clock::getTimeDiffUS.return:3030000
TEST.END
