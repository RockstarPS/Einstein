-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_TASK_VCAST_HT
-- Unit(s) Under Test: OsTask
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: OsTask

-- Subprogram: OsSchedule

-- Test Case: OsSchedule.001
TEST.UNIT:OsTask
TEST.SUBPROGRAM:OsSchedule
TEST.NEW
TEST.NAME:OsSchedule.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: OsSchedule.002
TEST.UNIT:OsTask
TEST.SUBPROGRAM:OsSchedule
TEST.NEW
TEST.NAME:OsSchedule.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:0x1
TEST.END

-- Test Case: OsSchedule.003
TEST.UNIT:OsTask
TEST.SUBPROGRAM:OsSchedule
TEST.NEW
TEST.NAME:OsSchedule.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: OsSchedule.004
TEST.UNIT:OsTask
TEST.SUBPROGRAM:OsSchedule
TEST.NEW
TEST.NAME:OsSchedule.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: OsSchedule.005
TEST.UNIT:OsTask
TEST.SUBPROGRAM:OsSchedule
TEST.NEW
TEST.NAME:OsSchedule.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:osdScheduleAllowedContext
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: OsSchedule.006
TEST.UNIT:OsTask
TEST.SUBPROGRAM:OsSchedule
TEST.NEW
TEST.NAME:OsSchedule.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:2
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.RequestedTaskIndex:6
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.TaskPriorityBits:0x1
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.IntSaveStatus:1
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.IntSaveGlobal:1
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:uut_prototype_stubs.OsSchedIsTaskSwitchReqd.return:1
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: OsSchedule.007
TEST.UNIT:OsTask
TEST.SUBPROGRAM:OsSchedule
TEST.NEW
TEST.NAME:OsSchedule.007
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: OsSchedule.008
TEST.UNIT:OsTask
TEST.SUBPROGRAM:OsSchedule
TEST.NEW
TEST.NAME:OsSchedule.008
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: OsSchedule.009
TEST.UNIT:OsTask
TEST.SUBPROGRAM:OsSchedule
TEST.NEW
TEST.NAME:OsSchedule.009
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:32
TEST.END

-- Test Case: OsSchedule.010
TEST.UNIT:OsTask
TEST.SUBPROGRAM:OsSchedule
TEST.NEW
TEST.NAME:OsSchedule.010
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:osdScheduleAllowedContext
TEST.VALUE:uut_prototype_stubs.OsSchedIsTaskSwitchReqd.return:1
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Subprogram: osActivateTask

-- Test Case: osActivateTask.001
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osActivateTask
TEST.NEW
TEST.NAME:osActivateTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.osActivateTask.TaskIndex:0
TEST.END

-- Test Case: osActivateTask.002
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osActivateTask
TEST.NEW
TEST.NAME:osActivateTask.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
    Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.RequestScheduler:1
TEST.END

-- Test Case: osActivateTask.003
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osActivateTask
TEST.NEW
TEST.NAME:osActivateTask.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.RequestScheduler:1
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.LockDispatcher:1
TEST.END

-- Test Case: osActivateTask.004
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osActivateTask
TEST.NEW
TEST.NAME:osActivateTask.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Subprogram: osGetTaskID

-- Test Case: osGetTaskID.001
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osGetTaskID
TEST.NEW
TEST.NAME:osGetTaskID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TasksID:10
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: osGetTaskID.002
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osGetTaskID
TEST.NEW
TEST.NAME:osGetTaskID.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.osGetTaskID.TaskIdRef:<<malloc 1>>
TEST.END

-- Subprogram: osGetTaskState

-- Test Case: osGetTaskState.001
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osGetTaskState
TEST.NEW
TEST.NAME:osGetTaskState.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: osGetTaskState.002
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osGetTaskState
TEST.NEW
TEST.NAME:osGetTaskState.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.osGetTaskState.TaskState:<<malloc 1>>
TEST.VALUE:OsTask.osGetTaskState.TaskState[0]:1
TEST.END

-- Subprogram: osSysActivateTask

-- Test Case: osSysActivateTask.001
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:27
TEST.END

-- Test Case: osSysActivateTask.002
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: osSysActivateTask.003
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: osSysActivateTask.004
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.IntSaveGlobal:88
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:27
TEST.END

-- Test Case: osSysActivateTask.005
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:27
TEST.END

-- Test Case: osSysActivateTask.006
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:31
TEST.END

-- Test Case: osSysActivateTask.007
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.007
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:27
TEST.END

-- Test Case: osSysActivateTask.008
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.008
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:27
TEST.END

-- Test Case: osSysActivateTask.009
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.009
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.IntSaveGlobal:5
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:27
TEST.END

-- Test Case: osSysActivateTask.010
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.010
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.IntSaveGlobal:5
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:33
TEST.END

-- Test Case: osSysActivateTask.011
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.011
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.IntSaveGlobal:5
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:27
TEST.END

-- Test Case: osSysActivateTask.012
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.012
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:21
TEST.END

-- Test Case: osSysActivateTask.013
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.013
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskMaxActivationCount:1
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ActivationCnt:0
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:0
TEST.END

-- Test Case: osSysActivateTask.014
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysActivateTask
TEST.NEW
TEST.NAME:osSysActivateTask.014
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskMaxActivationCount:2
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ActivationCnt:1
TEST.VALUE:OsTask.osSysActivateTask.TaskIndex:0
TEST.END

-- Subprogram: osSysSchedule

-- Test Case: osSysSchedule.001
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysSchedule
TEST.NEW
TEST.NAME:osSysSchedule.001
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:2
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:2
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:0
TEST.END

-- Test Case: osSysSchedule.002
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysSchedule
TEST.NEW
TEST.NAME:osSysSchedule.002
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:uut_prototype_stubs.OsSchedIsTaskSwitchReqd.return:1
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osSysSchedule.003
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysSchedule
TEST.NEW
TEST.NAME:osSysSchedule.003
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:uut_prototype_stubs.OsSchedIsTaskSwitchReqd.return:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osSysSchedule.004
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysSchedule
TEST.NEW
TEST.NAME:osSysSchedule.004
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:25
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:uut_prototype_stubs.OsSchedIsTaskSwitchReqd.return:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Subprogram: osSysTerminateTask

-- Test Case: osSysTerminateTask.001
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysTerminateTask
TEST.NEW
TEST.NAME:osSysTerminateTask.001
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:2
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:2
TEST.END

-- Test Case: osSysTerminateTask.002
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysTerminateTask
TEST.NEW
TEST.NAME:osSysTerminateTask.002
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:0
TEST.END

-- Test Case: osSysTerminateTask.003
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysTerminateTask
TEST.NEW
TEST.NAME:osSysTerminateTask.003
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ActivationCnt:2
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osSysTerminateTask.004
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osSysTerminateTask
TEST.NEW
TEST.NAME:osSysTerminateTask.004
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ActivationCnt:2
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:0
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:25
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Subprogram: osTerminateTask

-- Test Case: osTerminateTask.001
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osTerminateTask
TEST.NEW
TEST.NAME:osTerminateTask.001
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ActivationCnt:2
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ResCnt:1
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:2
TEST.END

-- Test Case: osTerminateTask.002
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osTerminateTask
TEST.NEW
TEST.NAME:osTerminateTask.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef[0].ActivationCnt:2
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:0x0
TEST.END

-- Test Case: osTerminateTask.004
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osTerminateTask
TEST.NEW
TEST.NAME:osTerminateTask.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: osTerminateTask.005
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osTerminateTask
TEST.NEW
TEST.NAME:osTerminateTask.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: osTerminateTask.006
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osTerminateTask
TEST.NEW
TEST.NAME:osTerminateTask.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.CurrentContext:2
TEST.END

-- Test Case: osTerminateTask.007
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osTerminateTask
TEST.NEW
TEST.NAME:osTerminateTask.007
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Test Case: osTerminateTask.008
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osTerminateTask
TEST.NEW
TEST.NAME:osTerminateTask.008
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:32
TEST.END

-- Test Case: osTerminateTask.009
TEST.UNIT:OsTask
TEST.SUBPROGRAM:osTerminateTask
TEST.NEW
TEST.NAME:osTerminateTask.009
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7607
TEST.END_NOTES:
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTask.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END
