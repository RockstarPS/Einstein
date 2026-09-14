-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_SCHED_VCAST_HT
-- Unit(s) Under Test: OsSched
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: OsSched

-- Subprogram: OsSchedGetNextHighPrioTask

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedGetNextHighPrioTask
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 9 (partial)
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].TaskPriorityBits:0
TEST.END

-- Test Case: OsSchedGetNextHighPrioTask.001
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedGetNextHighPrioTask
TEST.NEW
TEST.NAME:OsSchedGetNextHighPrioTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[0].Head:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[0].pQueue:<<malloc 2>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[0].pQueue:"0"
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.RequestedTaskPriority:0
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskPriority:0
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].TaskPriorityBits:1
TEST.END

-- Test Case: OsSchedGetNextHighPrioTask.001.001
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedGetNextHighPrioTask
TEST.NEW
TEST.NAME:OsSchedGetNextHighPrioTask.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam:<<malloc 1>>
TEST.END

-- Test Case: OsSchedGetNextHighPrioTask.001.002
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedGetNextHighPrioTask
TEST.NEW
TEST.NAME:OsSchedGetNextHighPrioTask.001.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam:<<malloc 1>>
TEST.END

-- Test Case: OsSchedGetNextHighPrioTask.001.003
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedGetNextHighPrioTask
TEST.NEW
TEST.NAME:OsSchedGetNextHighPrioTask.001.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam:<<malloc 1>>
TEST.END

-- Test Case: OsSchedGetNextHighPrioTask.002
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedGetNextHighPrioTask
TEST.NEW
TEST.NAME:OsSchedGetNextHighPrioTask.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskIndex:1
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskPriority:1
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].TaskPriorityBits:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsPriorityQueueDyn[1].pQueue:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsPriorityQueueDyn[1].pQueue[0]:1
TEST.END

-- Test Case: OsSchedGetNextHighPrioTask.003
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedGetNextHighPrioTask
TEST.NEW
TEST.NAME:OsSchedGetNextHighPrioTask.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].pQueue[0]:1
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskIndex:1
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskPriority:16
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].TaskPriorityBits:0xF0000
TEST.END

-- Test Case: OsSchedGetNextHighPrioTask.004
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedGetNextHighPrioTask
TEST.NEW
TEST.NAME:OsSchedGetNextHighPrioTask.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[8].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[8].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[8].pQueue[0]:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].pQueue[0]:1
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskIndex:1
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskPriority:8
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].TaskPriorityBits:0xF00
TEST.END

-- Test Case: OsSchedGetNextHighPrioTask.005
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedGetNextHighPrioTask
TEST.NEW
TEST.NAME:OsSchedGetNextHighPrioTask.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[4].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[4].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[4].pQueue[0]:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[8].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[8].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[8].pQueue[0]:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].pQueue[0]:1
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskIndex:1
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskPriority:4
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].TaskPriorityBits:0xF0
TEST.END

-- Test Case: OsSchedGetNextHighPrioTask.006
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedGetNextHighPrioTask
TEST.NEW
TEST.NAME:OsSchedGetNextHighPrioTask.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[2].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[2].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[2].pQueue[0]:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[4].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[4].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[4].pQueue[0]:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[8].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[8].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[8].pQueue[0]:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[16].pQueue[0]:1
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskIndex:1
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskPriority:2
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].TaskPriorityBits:0x4
TEST.END

-- Test Case: OsSchedGetNextHighPrioTask.007
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedGetNextHighPrioTask
TEST.NEW
TEST.NAME:OsSchedGetNextHighPrioTask.007
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[0].Head:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[0].pQueue:<<malloc 2>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[0].pQueue:"0"
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.RequestedTaskPriority:0
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].RequestedTaskPriority:0x1E
TEST.VALUE:OsSched.OsSchedGetNextHighPrioTask.pOsCtrlParam[0].TaskPriorityBits:0x80000000
TEST.END

-- Subprogram: OsSchedIsTaskSwitchReqd

-- Test Case: BASIS-PATH-001
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedIsTaskSwitchReqd
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam[0].ActiveTaskIndex:<<MIN>>
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam[0].RequestedTaskIndex:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedIsTaskSwitchReqd
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam[0].ActiveTaskIndex:<<MIN>>
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam[0].RequestedTaskIndex:1
TEST.END

-- Test Case: OsSchedIsTaskSwitchReqd.001
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedIsTaskSwitchReqd
TEST.NEW
TEST.NAME:OsSchedIsTaskSwitchReqd.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam:<<malloc 1>>
TEST.END

-- Test Case: OsSchedIsTaskSwitchReqd.001.001
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedIsTaskSwitchReqd
TEST.NEW
TEST.NAME:OsSchedIsTaskSwitchReqd.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam:<<malloc 1>>
TEST.END

-- Test Case: OsSchedIsTaskSwitchReqd.001.002
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedIsTaskSwitchReqd
TEST.NEW
TEST.NAME:OsSchedIsTaskSwitchReqd.001.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam:<<malloc 1>>
TEST.END

-- Test Case: OsSchedIsTaskSwitchReqd.001.003
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedIsTaskSwitchReqd
TEST.NEW
TEST.NAME:OsSchedIsTaskSwitchReqd.001.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam:<<malloc 1>>
TEST.END

-- Test Case: OsSchedIsTaskSwitchReqd.002
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedIsTaskSwitchReqd
TEST.NEW
TEST.NAME:OsSchedIsTaskSwitchReqd.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam[0].ActiveTaskIndex:1
TEST.END

-- Test Case: OsSchedIsTaskSwitchReqd.002.001
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedIsTaskSwitchReqd
TEST.NEW
TEST.NAME:OsSchedIsTaskSwitchReqd.002.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam[0].ActiveTaskIndex:1
TEST.END

-- Test Case: OsSchedIsTaskSwitchReqd.002.002
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedIsTaskSwitchReqd
TEST.NEW
TEST.NAME:OsSchedIsTaskSwitchReqd.002.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam[0].ActiveTaskIndex:1
TEST.END

-- Test Case: OsSchedIsTaskSwitchReqd.002.003
TEST.UNIT:OsSched
TEST.SUBPROGRAM:OsSchedIsTaskSwitchReqd
TEST.NEW
TEST.NAME:OsSchedIsTaskSwitchReqd.002.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam:<<malloc 1>>
TEST.VALUE:OsSched.OsSchedIsTaskSwitchReqd.pOsCtrlParam[0].ActiveTaskIndex:1
TEST.END

-- Subprogram: osSchedGetResource

-- Test Case: osSchedGetResource.003
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedGetResource
TEST.NEW
TEST.NAME:osSchedGetResource.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:50
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskPriority:3
TEST.VALUE:OsSched.osSchedGetResource.pResConfig:<<malloc 2>>
TEST.VALUE:OsSched.osSchedGetResource.pResConfig[0].CeilingPrio:2
TEST.VALUE:OsSched.osSchedGetResource.pResConfig[1].CeilingPrio:2
TEST.END

-- Test Case: osSchedGetResource.004
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedGetResource
TEST.NEW
TEST.NAME:osSchedGetResource.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[0].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskPriority:1
TEST.VALUE:OsSched.osSchedGetResource.pResConfig:<<malloc 2>>
TEST.VALUE:OsSched.osSchedGetResource.pResConfig[0].CeilingPrio:2
TEST.VALUE:OsSched.osSchedGetResource.pResConfig[1].CeilingPrio:2
TEST.END

-- Test Case: osSchedGetResource.005
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedGetResource
TEST.NEW
TEST.NAME:osSchedGetResource.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[0].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskPriority:1
TEST.VALUE:OsSched.osSchedGetResource.pResConfig:<<malloc 2>>
TEST.VALUE:OsSched.osSchedGetResource.pResConfig[0].CeilingPrio:2
TEST.VALUE:OsSched.osSchedGetResource.pResConfig[1].CeilingPrio:2
TEST.END

-- Test Case: osSchedGetResource.006
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedGetResource
TEST.NEW
TEST.NAME:osSchedGetResource.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[0].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0xFF
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskPriority:1
TEST.VALUE:OsSched.osSchedGetResource.pResConfig:<<malloc 2>>
TEST.VALUE:OsSched.osSchedGetResource.pResConfig[0].CeilingPrio:2
TEST.VALUE:OsSched.osSchedGetResource.pResConfig[1].CeilingPrio:2
TEST.END

-- Subprogram: osSchedInsertTask

-- Test Case: BASIS-PATH-001
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedInsertTask
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 6
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.osSchedInsertTask.TaskIndex:<<MAX>>
TEST.END

-- Test Case: osSchedInsertTask.001
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedInsertTask
TEST.NEW
TEST.NAME:osSchedInsertTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Tail:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskPriority:1
TEST.VALUE:OsSched.osSchedInsertTask.TaskIndex:0
TEST.END

-- Test Case: osSchedInsertTask.002
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedInsertTask
TEST.NEW
TEST.NAME:osSchedInsertTask.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[0].Tail:255
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskPriority:23
TEST.VALUE:OsSched.osSchedInsertTask.TaskIndex:0
TEST.END

-- Test Case: osSchedInsertTask.003
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedInsertTask
TEST.NEW
TEST.NAME:osSchedInsertTask.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Tail:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskPriority:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.RequestedTaskPriority:2
TEST.VALUE:OsSched.osSchedInsertTask.TaskIndex:0
TEST.END

-- Test Case: osSchedInsertTask.004
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedInsertTask
TEST.NEW
TEST.NAME:osSchedInsertTask.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Tail:255
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskPriority:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.RequestedTaskPriority:2
TEST.VALUE:OsSched.osSchedInsertTask.TaskIndex:0
TEST.VALUE_USER_CODE:OsSched.<<GLOBAL>>.OsMaxPrioQueueCount
<<OsSched.<<GLOBAL>>.OsMaxPrioQueueCount[1]>> = ( 50 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: osSchedInsertTask.005
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedInsertTask
TEST.NEW
TEST.NAME:osSchedInsertTask.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].pQueue:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskPriority:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.RequestedTaskPriority:2
TEST.VALUE:OsSched.osSchedInsertTask.TaskIndex:0
TEST.VALUE_USER_CODE:OsSched.<<GLOBAL>>.OsMaxPrioQueueCount
<<OsSched.<<GLOBAL>>.OsMaxPrioQueueCount[1]>> = ( 50 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: osSchedReleaseResource

-- Test Case: osSchedReleaseResource.001
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedReleaseResource
TEST.NEW
TEST.NAME:osSchedReleaseResource.001
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskPriority:1
TEST.END

-- Test Case: osSchedReleaseResource.002
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedReleaseResource
TEST.NEW
TEST.NAME:osSchedReleaseResource.002
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskPriority:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.LockDispatcher:1
TEST.END

-- Test Case: osSchedReleaseResource.003
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedReleaseResource
TEST.NEW
TEST.NAME:osSchedReleaseResource.003
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Tail:0
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskPriority:1
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskPriority:21
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.LockDispatcher:1
TEST.END

-- Test Case: osSchedReleaseResource.004
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedReleaseResource
TEST.NEW
TEST.NAME:osSchedReleaseResource.004
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:22
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskPriority:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.LockDispatcher:1
TEST.END

-- Test Case: osSchedReleaseResource.005
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedReleaseResource
TEST.NEW
TEST.NAME:osSchedReleaseResource.005
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:0xFF
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0xFF
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskPriority:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.LockDispatcher:1
TEST.END

-- Test Case: osSchedReleaseResource.006
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedReleaseResource
TEST.NEW
TEST.NAME:osSchedReleaseResource.006
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsMaxPrioQueueCount[1]:3
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskPriority:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.LockDispatcher:1
TEST.END

-- Subprogram: osSchedRemoveTask

-- Test Case: BASIS-PATH-001
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedRemoveTask
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 7
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedRemoveTask
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskPriority:1
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.001
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedRemoveTask
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:1
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskPriority:22
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:1
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.002
TEST.UNIT:OsSched
TEST.SUBPROGRAM:osSchedRemoveTask
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7598
TEST.END_NOTES:
TEST.VALUE:OsSched.<<GLOBAL>>.OsPriorityQueueDyn[1].Head:255
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskPriority:1
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsSched.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsSched.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE_USER_CODE:OsSched.<<GLOBAL>>.OsMaxPrioQueueCount
<<OsSched.<<GLOBAL>>.OsMaxPrioQueueCount[1]>> = ( 255 );
TEST.END_VALUE_USER_CODE:
TEST.END
