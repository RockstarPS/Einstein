-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_ALARM_VCAST_HT
-- Unit(s) Under Test: OsAlarm
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: OsAlarm

-- Subprogram: Os_CancelAlarm

-- Test Case: Os_CancelAlarm.001
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_CancelAlarm
TEST.NEW
TEST.NAME:Os_CancelAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef[0].AlarmActivated:0
TEST.VALUE:OsAlarm.Os_CancelAlarm.AlarmID:0
TEST.END

-- Test Case: Os_CancelAlarm.002
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_CancelAlarm
TEST.NEW
TEST.NAME:Os_CancelAlarm.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.Os_CancelAlarm.AlarmID:100
TEST.END

-- Test Case: Os_CancelAlarm.003
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_CancelAlarm
TEST.NEW
TEST.NAME:Os_CancelAlarm.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef[0].AlarmActivated:1
TEST.VALUE:OsAlarm.Os_CancelAlarm.AlarmID:0
TEST.END

-- Subprogram: Os_GetAlarm

-- Test Case: Os_GetAlarm.002
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_GetAlarm
TEST.NEW
TEST.NAME:Os_GetAlarm.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.Os_GetAlarm.AlarmID:100
TEST.VALUE:OsAlarm.Os_GetAlarm.Tick:<<malloc 1>>
TEST.VALUE:OsAlarm.Os_GetAlarm.Tick[0]:1
TEST.END

-- Test Case: Os_GetAlarm.004
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_GetAlarm
TEST.NEW
TEST.NAME:Os_GetAlarm.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef[0].AlarmActivated:0
TEST.VALUE:OsAlarm.Os_GetAlarm.AlarmID:0
TEST.VALUE:OsAlarm.Os_GetAlarm.Tick:<<malloc 1>>
TEST.VALUE:OsAlarm.Os_GetAlarm.Tick[0]:1
TEST.END

-- Test Case: Os_GetAlarm.005
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_GetAlarm
TEST.NEW
TEST.NAME:Os_GetAlarm.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef[0].AlarmTime:10
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef[0].AlarmActivated:1
TEST.VALUE:OsAlarm.Os_GetAlarm.AlarmID:0
TEST.VALUE:OsAlarm.Os_GetAlarm.Tick:<<malloc 5>>
TEST.END

-- Subprogram: Os_SetAbsAlarm

-- Test Case: Os_SetAbsAlarm.001
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_SetAbsAlarm
TEST.NEW
TEST.NAME:Os_SetAbsAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef[0].AlarmActivated:0
TEST.VALUE:OsAlarm.Os_SetAbsAlarm.AlarmID:0
TEST.END

-- Test Case: Os_SetAbsAlarm.002
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_SetAbsAlarm
TEST.NEW
TEST.NAME:Os_SetAbsAlarm.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.Os_SetAbsAlarm.AlarmID:100
TEST.END

-- Test Case: Os_SetAbsAlarm.003
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_SetAbsAlarm
TEST.NEW
TEST.NAME:Os_SetAbsAlarm.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef[0].AlarmActivated:1
TEST.END

-- Subprogram: Os_SetRelAlarm

-- Test Case: Os_SetRelAlarm.001
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_SetRelAlarm
TEST.NEW
TEST.NAME:Os_SetRelAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef[0].AlarmActivated:0
TEST.VALUE:OsAlarm.Os_SetRelAlarm.AlarmID:0
TEST.END

-- Test Case: Os_SetRelAlarm.002
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_SetRelAlarm
TEST.NEW
TEST.NAME:Os_SetRelAlarm.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.Os_SetRelAlarm.AlarmID:100
TEST.END

-- Test Case: Os_SetRelAlarm.003
TEST.UNIT:OsAlarm
TEST.SUBPROGRAM:Os_SetRelAlarm
TEST.NEW
TEST.NAME:Os_SetRelAlarm.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7407
TEST.END_NOTES:
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsAlarm.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef[0].AlarmActivated:1
TEST.VALUE:OsAlarm.Os_SetRelAlarm.AlarmID:0
TEST.END
