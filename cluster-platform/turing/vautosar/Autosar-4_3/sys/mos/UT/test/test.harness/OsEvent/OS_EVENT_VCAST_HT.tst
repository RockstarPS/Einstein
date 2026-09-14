-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_EVENT_VCAST_HT
-- Unit(s) Under Test: OsEvent
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: OsEvent

-- Subprogram: osClearEvent

-- Test Case: osClearEvent.001
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osClearEvent
TEST.NEW
TEST.NAME:osClearEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.END

-- Test Case: osClearEvent.002
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osClearEvent
TEST.NEW
TEST.NAME:osClearEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:2
TEST.END

-- Test Case: osClearEvent.003
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osClearEvent
TEST.NEW
TEST.NAME:osClearEvent.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:2
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.END

-- Test Case: osClearEvent.004
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osClearEvent
TEST.NEW
TEST.NAME:osClearEvent.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:2
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:21
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.END

-- Subprogram: osGetEvent

-- Test Case: osGetEvent.001
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osGetEvent
TEST.NEW
TEST.NAME:osGetEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: osGetEvent.002
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osGetEvent
TEST.NEW
TEST.NAME:osGetEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.osGetEvent.Event:<<malloc 1>>
TEST.VALUE:OsEvent.osGetEvent.Event[0]:1
TEST.END

-- Test Case: osGetEvent.003
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osGetEvent
TEST.NEW
TEST.NAME:osGetEvent.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:4
TEST.VALUE:OsEvent.osGetEvent.Event:<<malloc 1>>
TEST.VALUE:OsEvent.osGetEvent.Event[0]:1
TEST.END

-- Test Case: osGetEvent.004
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osGetEvent
TEST.NEW
TEST.NAME:osGetEvent.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:3
TEST.VALUE:OsEvent.osGetEvent.Event:<<malloc 1>>
TEST.VALUE:OsEvent.osGetEvent.Event[0]:1
TEST.END

-- Test Case: osGetEvent.005
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osGetEvent
TEST.NEW
TEST.NAME:osGetEvent.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:3
TEST.VALUE:OsEvent.osGetEvent.TaskIndex:21
TEST.VALUE:OsEvent.osGetEvent.Event:<<malloc 1>>
TEST.VALUE:OsEvent.osGetEvent.Event[0]:1
TEST.END

-- Subprogram: osSetEvent

-- Test Case: osSetEvent.001
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSetEvent
TEST.NEW
TEST.NAME:osSetEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: osSetEvent.002
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSetEvent
TEST.NEW
TEST.NAME:osSetEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:0
TEST.END

-- Test Case: osSetEvent.003
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSetEvent
TEST.NEW
TEST.NAME:osSetEvent.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:4
TEST.END

-- Test Case: osSetEvent.004
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSetEvent
TEST.NEW
TEST.NAME:osSetEvent.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:0
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:0
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:2
TEST.END

-- Test Case: osSetEvent.005
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSetEvent
TEST.NEW
TEST.NAME:osSetEvent.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:2
TEST.END

-- Test Case: osSetEvent.006
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSetEvent
TEST.NEW
TEST.NAME:osSetEvent.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:2
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.RequestScheduler:1
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.LockDispatcher:0
TEST.VALUE:uut_prototype_stubs.Os_GetContext.return:1
TEST.END

-- Test Case: osSetEvent.007
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSetEvent
TEST.NEW
TEST.NAME:osSetEvent.007
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:2
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.RequestScheduler:1
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.LockDispatcher:1
TEST.VALUE:uut_prototype_stubs.Os_GetContext.return:1
TEST.END

-- Test Case: osSetEvent.008
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSetEvent
TEST.NEW
TEST.NAME:osSetEvent.008
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:2
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.RequestScheduler:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.LockDispatcher:1
TEST.VALUE:uut_prototype_stubs.Os_GetContext.return:1
TEST.END

-- Test Case: osSetEvent.009
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSetEvent
TEST.NEW
TEST.NAME:osSetEvent.009
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:2
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.RequestScheduler:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.LockDispatcher:1
TEST.VALUE:OsEvent.osSetEvent.TaskIndex:21
TEST.VALUE:uut_prototype_stubs.Os_GetContext.return:1
TEST.END

-- Subprogram: osSysSetEvent

-- Test Case: osSysSetEvent.001
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysSetEvent
TEST.NEW
TEST.NAME:osSysSetEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.osSysSetEvent.TaskIndex:21
TEST.END

-- Test Case: osSysSetEvent.002
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysSetEvent
TEST.NEW
TEST.NAME:osSysSetEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:0
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.osSysSetEvent.TaskIndex:0
TEST.END

-- Test Case: osSysSetEvent.003
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysSetEvent
TEST.NEW
TEST.NAME:osSysSetEvent.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:2
TEST.VALUE:OsEvent.osSysSetEvent.TaskIndex:0
TEST.END

-- Test Case: osSysSetEvent.004
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysSetEvent
TEST.NEW
TEST.NAME:osSysSetEvent.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:4
TEST.VALUE:OsEvent.osSysSetEvent.TaskIndex:0
TEST.END

-- Test Case: osSysSetEvent.005
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysSetEvent
TEST.NEW
TEST.NAME:osSysSetEvent.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:0
TEST.VALUE:OsEvent.osSysSetEvent.TaskIndex:0
TEST.END

-- Test Case: osSysSetEvent.006
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysSetEvent
TEST.NEW
TEST.NAME:osSysSetEvent.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:0
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:0
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].State:2
TEST.VALUE:OsEvent.osSysSetEvent.TaskIndex:0
TEST.END

-- Subprogram: osSysWaitEvent

-- Test Case: osSysWaitEvent.001
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysWaitEvent
TEST.NEW
TEST.NAME:osSysWaitEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:0
TEST.END

-- Test Case: osSysWaitEvent.002
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysWaitEvent
TEST.NEW
TEST.NAME:osSysWaitEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:2
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osSysWaitEvent.003
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysWaitEvent
TEST.NEW
TEST.NAME:osSysWaitEvent.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:1
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osSysWaitEvent.004
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysWaitEvent
TEST.NEW
TEST.NAME:osSysWaitEvent.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:2
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osSysWaitEvent.005
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysWaitEvent
TEST.NEW
TEST.NAME:osSysWaitEvent.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:0
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:OsEvent.osSysWaitEvent.EventMask:1
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osSysWaitEvent.006
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysWaitEvent
TEST.NEW
TEST.NAME:osSysWaitEvent.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:OsEvent.osSysWaitEvent.EventMask:1
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osSysWaitEvent.007
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osSysWaitEvent
TEST.NEW
TEST.NAME:osSysWaitEvent.007
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:21
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:0
TEST.END

-- Subprogram: osWaitEvent

-- Test Case: osWaitEvent.001
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osWaitEvent
TEST.NEW
TEST.NAME:osWaitEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:0
TEST.END

-- Test Case: osWaitEvent.002
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osWaitEvent
TEST.NEW
TEST.NAME:osWaitEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:21
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osWaitEvent.003
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osWaitEvent
TEST.NEW
TEST.NAME:osWaitEvent.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:2
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osWaitEvent.004
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osWaitEvent
TEST.NEW
TEST.NAME:osWaitEvent.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:1
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osWaitEvent.005
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osWaitEvent
TEST.NEW
TEST.NAME:osWaitEvent.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:2
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osWaitEvent.006
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osWaitEvent
TEST.NEW
TEST.NAME:osWaitEvent.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osWaitEvent.007
TEST.UNIT:OsEvent
TEST.SUBPROGRAM:osWaitEvent
TEST.NEW
TEST.NAME:osWaitEvent.007
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7589
TEST.END_NOTES:
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksType:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].WaitEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].SetEventMask:1
TEST.VALUE:OsEvent.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsEvent.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:OsEvent.osWaitEvent.EventMask:1
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END
