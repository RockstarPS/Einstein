-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_COUNTER_VCAST_HT
-- Unit(s) Under Test: OsCounter
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: OsCounter

-- Subprogram: OsGetCounterValue

-- Test Case: OsGetCounterValue.003
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetCounterValue
TEST.NEW
TEST.NAME:OsGetCounterValue.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.OsGetCounterValue.CounterID:5
TEST.END

-- Test Case: OsGetCounterValue.004
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetCounterValue
TEST.NEW
TEST.NAME:OsGetCounterValue.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetCounterValue.CounterID:1
TEST.VALUE:OsCounter.OsGetCounterValue.Value:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetCounterValue.Value[0]:5
TEST.VALUE:OsCounter.OsGetCounterValue.return:0
TEST.END

-- Subprogram: OsGetElapsedValue

-- Test Case: OsGetElapsedValue.001
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetElapsedValue
TEST.NEW
TEST.NAME:OsGetElapsedValue.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.END

-- Test Case: OsGetElapsedValue.002
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetElapsedValue
TEST.NEW
TEST.NAME:OsGetElapsedValue.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.END

-- Test Case: OsGetElapsedValue.003
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetElapsedValue
TEST.NEW
TEST.NAME:OsGetElapsedValue.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.END

-- Test Case: OsGetElapsedValue.004
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetElapsedValue
TEST.NEW
TEST.NAME:OsGetElapsedValue.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.END

-- Test Case: OsGetElapsedValue.005
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetElapsedValue
TEST.NEW
TEST.NAME:OsGetElapsedValue.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetElapsedValue.Value:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetElapsedValue.Value[0]:2
TEST.VALUE:OsCounter.OsGetElapsedValue.ElapsedValue:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetElapsedValue.ElapsedValue[0]:5
TEST.END

-- Test Case: OsGetElapsedValue.006
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetElapsedValue
TEST.NEW
TEST.NAME:OsGetElapsedValue.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:NULL
TEST.END

-- Test Case: OsGetElapsedValue.007
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetElapsedValue
TEST.NEW
TEST.NAME:OsGetElapsedValue.007
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:NULL
TEST.VALUE:OsCounter.OsGetElapsedValue.CounterID:5
TEST.VALUE:OsCounter.OsGetElapsedValue.Value:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetElapsedValue.Value[0]:0xFFFFFFFF
TEST.VALUE:OsCounter.OsGetElapsedValue.ElapsedValue:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetElapsedValue.ElapsedValue[0]:0xFFFFFFFF
TEST.END

-- Test Case: OsGetElapsedValue.008
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetElapsedValue
TEST.NEW
TEST.NAME:OsGetElapsedValue.008
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.OsGetElapsedValue.Value:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetElapsedValue.Value[0]:0xFFFF
TEST.ATTRIBUTES:OsCounter.OsGetElapsedValue.ElapsedValue[0]:INPUT_BASE=16
TEST.END

-- Test Case: OsGetElapsedValue.009
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetElapsedValue
TEST.NEW
TEST.NAME:OsGetElapsedValue.009
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterParam[0].TickCount:1
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterParam[0].TickCount:1
TEST.VALUE:OsCounter.OsGetElapsedValue.Value:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetElapsedValue.Value[0]:0xFFFFFFFF
TEST.VALUE:OsCounter.OsGetElapsedValue.ElapsedValue:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetElapsedValue.ElapsedValue[0]:0x0
TEST.VALUE:uut_prototype_stubs.OsErr_osApplicationErrorHook.ServiceId:0x11
TEST.VALUE:uut_prototype_stubs.OsErr_osApplicationErrorHook.pStatus[0]:0x1
TEST.VALUE:uut_prototype_stubs.OsErr_osApplicationErrorHook.Status:8
TEST.END

-- Test Case: OsGetElapsedValue.010
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsGetElapsedValue
TEST.NEW
TEST.NAME:OsGetElapsedValue.010
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterParam[0].TickCount:0xFFFFFFFF
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterParam[0].TickCount:0xFFFFFFFF
TEST.VALUE:OsCounter.OsGetElapsedValue.Value:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetElapsedValue.Value[0]:0xFFFFFFFF
TEST.VALUE:OsCounter.OsGetElapsedValue.ElapsedValue:<<malloc 1>>
TEST.VALUE:OsCounter.OsGetElapsedValue.ElapsedValue[0]:0x0
TEST.VALUE:uut_prototype_stubs.OsErr_osApplicationErrorHook.ServiceId:0x11
TEST.VALUE:uut_prototype_stubs.OsErr_osApplicationErrorHook.pStatus[0]:0x1
TEST.VALUE:uut_prototype_stubs.OsErr_osApplicationErrorHook.Status:8
TEST.END

-- Subprogram: OsIncrementCounter

-- Test Case: OsIncrementCounter.001
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsIncrementCounter
TEST.NEW
TEST.NAME:OsIncrementCounter.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterType:HARDWARE
TEST.VALUE:OsCounter.OsIncrementCounter.CounterId:0
TEST.END

-- Test Case: OsIncrementCounter.002
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsIncrementCounter
TEST.NEW
TEST.NAME:OsIncrementCounter.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.OsIncrementCounter.CounterId:3
TEST.END

-- Test Case: OsIncrementCounter.003
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:OsIncrementCounter
TEST.NEW
TEST.NAME:OsIncrementCounter.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterType:SOFTWARE
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsCounter.OsIncrementCounter.CounterId:0
TEST.END

-- Subprogram: osIncrementHardwareCounters

-- Test Case: osIncrementHardwareCounters.001
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:osIncrementHardwareCounters
TEST.NEW
TEST.NAME:osIncrementHardwareCounters.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterType:HARDWARE
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterType:HARDWARE
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterParam:<<malloc 1>>
TEST.END

-- Test Case: osIncrementHardwareCounters.002
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:osIncrementHardwareCounters
TEST.NEW
TEST.NAME:osIncrementHardwareCounters.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterType:SOFTWARE
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterType:SOFTWARE
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterParam:<<malloc 1>>
TEST.END

-- Subprogram: osResetCounter

-- Test Case: osResetCounter.001
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:osResetCounter
TEST.NEW
TEST.NAME:osResetCounter.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1]:<<malloc 1>>
TEST.VALUE:OsCounter.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterParam:<<malloc 1>>
TEST.END

-- Test Case: osResetCounter.002
TEST.UNIT:OsCounter
TEST.SUBPROGRAM:osResetCounter
TEST.NEW
TEST.NAME:osResetCounter.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7587
TEST.END_NOTES:
TEST.VALUE:OsCounter.osResetCounter.CounterId:2
TEST.END
