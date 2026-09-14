-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_METRICS_VCAST_HT
-- Unit(s) Under Test: OsMetrics
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: OsGetContextSwitchMetrics

-- Test Case: OsGetContextSwitchMetrics.001
TEST.UNIT:OsMetrics
TEST.SUBPROGRAM:OsGetContextSwitchMetrics
TEST.NEW
TEST.NAME:OsGetContextSwitchMetrics.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7596
TEST.END_NOTES:
TEST.END

-- Test Case: OsGetContextSwitchMetrics.002
TEST.UNIT:OsMetrics
TEST.SUBPROGRAM:OsGetContextSwitchMetrics
TEST.NEW
TEST.NAME:OsGetContextSwitchMetrics.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7596
TEST.END_NOTES:
TEST.VALUE:OsMetrics.<<GLOBAL>>.osMetrics[2].ValFlag:1
TEST.END

-- Subprogram: OsGetOsInitMetrics

-- Test Case: OsGetOsInitMetrics.001
TEST.UNIT:OsMetrics
TEST.SUBPROGRAM:OsGetOsInitMetrics
TEST.NEW
TEST.NAME:OsGetOsInitMetrics.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7596
TEST.END_NOTES:
TEST.END

-- Test Case: OsGetOsInitMetrics.002
TEST.UNIT:OsMetrics
TEST.SUBPROGRAM:OsGetOsInitMetrics
TEST.NEW
TEST.NAME:OsGetOsInitMetrics.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7596
TEST.END_NOTES:
TEST.VALUE:OsMetrics.<<GLOBAL>>.osMetrics[3].ValFlag:1
TEST.END

-- Subprogram: OsGetResumeTaskMetrics

-- Test Case: OsGetResumeTaskMetrics.001
TEST.UNIT:OsMetrics
TEST.SUBPROGRAM:OsGetResumeTaskMetrics
TEST.NEW
TEST.NAME:OsGetResumeTaskMetrics.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7596
TEST.END_NOTES:
TEST.END

-- Test Case: OsGetResumeTaskMetrics.002
TEST.UNIT:OsMetrics
TEST.SUBPROGRAM:OsGetResumeTaskMetrics
TEST.NEW
TEST.NAME:OsGetResumeTaskMetrics.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7596
TEST.END_NOTES:
TEST.VALUE:OsMetrics.<<GLOBAL>>.osMetrics[1].ValFlag:1
TEST.END

-- Subprogram: OsGetStartTaskMetrics

-- Test Case: OsGetStartTaskMetrics.001
TEST.UNIT:OsMetrics
TEST.SUBPROGRAM:OsGetStartTaskMetrics
TEST.NEW
TEST.NAME:OsGetStartTaskMetrics.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7596
TEST.END_NOTES:
TEST.END

-- Test Case: OsGetStartTaskMetrics.002
TEST.UNIT:OsMetrics
TEST.SUBPROGRAM:OsGetStartTaskMetrics
TEST.NEW
TEST.NAME:OsGetStartTaskMetrics.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7596
TEST.END_NOTES:
TEST.VALUE:OsMetrics.<<GLOBAL>>.osMetrics[0].ValFlag:1
TEST.END

-- Subprogram: OsGetTimerCount

-- Test Case: OsGetTimerCount.001
TEST.UNIT:OsMetrics
TEST.SUBPROGRAM:OsGetTimerCount
TEST.NEW
TEST.NAME:OsGetTimerCount.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7596
TEST.END_NOTES:
TEST.END

-- Subprogram: OsStartDispatchMetric

-- Test Case: OsStartDispatchMetric.001
TEST.UNIT:OsMetrics
TEST.SUBPROGRAM:OsStartDispatchMetric
TEST.NEW
TEST.NAME:OsStartDispatchMetric.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7596
TEST.END_NOTES:
TEST.END
