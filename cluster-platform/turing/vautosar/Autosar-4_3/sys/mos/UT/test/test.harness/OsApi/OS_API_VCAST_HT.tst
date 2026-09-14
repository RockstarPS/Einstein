-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_API_VCAST_HT
-- Unit(s) Under Test: OsApi
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: OsApi

-- Subprogram: OsApiPrv_IsAllowedAccess

-- Test Case: OsApiPrv_IsAllowedAccess.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApiPrv_IsAllowedAccess
TEST.NEW
TEST.NAME:OsApiPrv_IsAllowedAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0][0].pObjRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0][0].pObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0][0].pObjRef[0].pAppRef[0].AppId:2
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:2
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.TaskId:0
TEST.END

-- Test Case: OsApiPrv_IsAllowedAccess.002
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApiPrv_IsAllowedAccess
TEST.NEW
TEST.NAME:OsApiPrv_IsAllowedAccess.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.TaskId:35
TEST.END

-- Test Case: OsApiPrv_IsAllowedAccess.003
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApiPrv_IsAllowedAccess
TEST.NEW
TEST.NAME:OsApiPrv_IsAllowedAccess.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0][0].pObjRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0][0].pObjRef[0].pAppRef:<<null>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:1
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.TaskId:0
TEST.END

-- Subprogram: OsApi_ActivateTask

-- Test Case: OsApi_ActivateTask.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_ActivateTask
TEST.NEW
TEST.NAME:OsApi_ActivateTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0][0].pAppRef[0].AppId:2
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:2
TEST.VALUE:OsApi.OsApi_ActivateTask.TaskIndex:0
TEST.END

-- Test Case: OsApi_ActivateTask.002
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_ActivateTask
TEST.NEW
TEST.NAME:OsApi_ActivateTask.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:0
TEST.VALUE:OsApi.OsApi_ActivateTask.TaskIndex:0
TEST.END

-- Subprogram: OsApi_AllowAccess

-- Test Case: OsApi_AllowAccess.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_AllowAccess
TEST.NEW
TEST.NAME:OsApi_AllowAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_CallTrustedFunction

-- Test Case: OsApi_CallTrustedFunction.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_CallTrustedFunction
TEST.NEW
TEST.NAME:OsApi_CallTrustedFunction.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_CancelAlarm

-- Test Case: OsApi_CancelAlarm.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_CancelAlarm
TEST.NEW
TEST.NAME:OsApi_CancelAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmAction:3
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:0
TEST.VALUE:OsApi.OsApi_CancelAlarm.AlarmID:0
TEST.END

-- Test Case: OsApi_CancelAlarm.002
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_CancelAlarm
TEST.NEW
TEST.NAME:OsApi_CancelAlarm.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmActivateTaskRef[0].TasksID:0
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmAction:2
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:1
TEST.VALUE:OsApi.OsApi_CancelAlarm.AlarmID:0
TEST.END

-- Test Case: OsApi_CancelAlarm.003
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_CancelAlarm
TEST.NEW
TEST.NAME:OsApi_CancelAlarm.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:0
TEST.VALUE:OsApi.OsApi_CancelAlarm.AlarmID:100
TEST.END

-- Test Case: OsApi_CancelAlarm.004
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_CancelAlarm
TEST.NEW
TEST.NAME:OsApi_CancelAlarm.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmAction:4
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:0
TEST.VALUE:OsApi.OsApi_CancelAlarm.AlarmID:0
TEST.END

-- Subprogram: OsApi_ChainTask

-- Test Case: OsApi_ChainTask.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_ChainTask
TEST.NEW
TEST.NAME:OsApi_ChainTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_CheckISRMemoryAccess

-- Test Case: OsApi_CheckISRMemoryAccess.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_CheckISRMemoryAccess
TEST.NEW
TEST.NAME:OsApi_CheckISRMemoryAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_CheckObjectAccess

-- Test Case: OsApi_CheckObjectAccess.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_CheckObjectAccess
TEST.NEW
TEST.NAME:OsApi_CheckObjectAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_CheckObjectOwnership

-- Test Case: OsApi_CheckObjectOwnership.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_CheckObjectOwnership
TEST.NEW
TEST.NAME:OsApi_CheckObjectOwnership.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_CheckTaskMemoryAccess

-- Test Case: OsApi_CheckTaskMemoryAccess.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_CheckTaskMemoryAccess
TEST.NEW
TEST.NAME:OsApi_CheckTaskMemoryAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_ClearEvent

-- Test Case: OsApi_ClearEvent.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_ClearEvent
TEST.NEW
TEST.NAME:OsApi_ClearEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_DisableAllInterrupts

-- Test Case: OsApi_DisableAllInterrupts.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_DisableAllInterrupts
TEST.NEW
TEST.NAME:OsApi_DisableAllInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_DisableInterruptSource

-- Test Case: OsApi_DisableInterruptSource.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_DisableInterruptSource
TEST.NEW
TEST.NAME:OsApi_DisableInterruptSource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Test Case: OsApi_DisableInterruptSource.002
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_DisableInterruptSource
TEST.NEW
TEST.NAME:OsApi_DisableInterruptSource.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.VALUE:OsApi.OsApi_DisableInterruptSource.ISRID:28
TEST.END

-- Subprogram: OsApi_EnableAllInterrupts

-- Test Case: OsApi_EnableAllInterrupts.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_EnableAllInterrupts
TEST.NEW
TEST.NAME:OsApi_EnableAllInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_EnableInterruptSource

-- Test Case: OsApi_EnableInterruptSource.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_EnableInterruptSource
TEST.NEW
TEST.NAME:OsApi_EnableInterruptSource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetAlarm

-- Test Case: OsApi_GetAlarm.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetAlarm
TEST.NEW
TEST.NAME:OsApi_GetAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetAlarmBase

-- Test Case: OsApi_GetAlarmBase.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetAlarmBase
TEST.NEW
TEST.NAME:OsApi_GetAlarmBase.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetApplicationID

-- Test Case: OsApi_GetApplicationID.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetApplicationID
TEST.NEW
TEST.NAME:OsApi_GetApplicationID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetApplicationState

-- Test Case: OsApi_GetApplicationState.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetApplicationState
TEST.NEW
TEST.NAME:OsApi_GetApplicationState.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetCoreId

-- Test Case: OsApi_GetCoreId.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetCoreId
TEST.NEW
TEST.NAME:OsApi_GetCoreId.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetCounterValue

-- Test Case: OsApi_GetCounterValue.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetCounterValue
TEST.NEW
TEST.NAME:OsApi_GetCounterValue.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetCurrentApplicationID

-- Test Case: OsApi_GetCurrentApplicationID.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetCurrentApplicationID
TEST.NEW
TEST.NAME:OsApi_GetCurrentApplicationID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetElapsedValue

-- Test Case: OsApi_GetElapsedValue.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetElapsedValue
TEST.NEW
TEST.NAME:OsApi_GetElapsedValue.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetEvent

-- Test Case: OsApi_GetEvent.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetEvent
TEST.NEW
TEST.NAME:OsApi_GetEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetISRID

-- Test Case: OsApi_GetISRID.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetISRID
TEST.NEW
TEST.NAME:OsApi_GetISRID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetNumberOfActivatedCores

-- Test Case: OsApi_GetNumberOfActivatedCores.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetNumberOfActivatedCores
TEST.NEW
TEST.NAME:OsApi_GetNumberOfActivatedCores.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetResource

-- Test Case: OsApi_GetResource.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetResource
TEST.NEW
TEST.NAME:OsApi_GetResource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetScheduleTableStatus

-- Test Case: OsApi_GetScheduleTableStatus.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetScheduleTableStatus
TEST.NEW
TEST.NAME:OsApi_GetScheduleTableStatus.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetTaskID

-- Test Case: OsApi_GetTaskID.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetTaskID
TEST.NEW
TEST.NAME:OsApi_GetTaskID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetTaskState

-- Test Case: OsApi_GetTaskState.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetTaskState
TEST.NEW
TEST.NAME:OsApi_GetTaskState.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_GetVersionInfo

-- Test Case: OsApi_GetVersionInfo.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetVersionInfo
TEST.NEW
TEST.NAME:OsApi_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Test Case: OsApi_GetVersionInfo.002
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_GetVersionInfo
TEST.NEW
TEST.NAME:OsApi_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.VALUE:OsApi.OsApi_GetVersionInfo.VersionInfo:<<malloc 1>>
TEST.END

-- Subprogram: OsApi_IncrementCounter

-- Test Case: OsApi_IncrementCounter.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_IncrementCounter
TEST.NEW
TEST.NAME:OsApi_IncrementCounter.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_NextScheduleTable

-- Test Case: OsApi_NextScheduleTable.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_NextScheduleTable
TEST.NEW
TEST.NAME:OsApi_NextScheduleTable.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_ReleaseResource

-- Test Case: OsApi_ReleaseResource.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_ReleaseResource
TEST.NEW
TEST.NAME:OsApi_ReleaseResource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_ResumeAllInterrupts

-- Test Case: OsApi_ResumeAllInterrupts.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_ResumeAllInterrupts
TEST.NEW
TEST.NAME:OsApi_ResumeAllInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_ResumeOSInterrupts

-- Test Case: OsApi_ResumeOSInterrupts.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_ResumeOSInterrupts
TEST.NEW
TEST.NAME:OsApi_ResumeOSInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_Schedule

-- Test Case: OsApi_Schedule.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_Schedule
TEST.NEW
TEST.NAME:OsApi_Schedule.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_SetAbsAlarm

-- Test Case: OsApi_SetAbsAlarm.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_SetAbsAlarm
TEST.NEW
TEST.NAME:OsApi_SetAbsAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_SetEvent

-- Test Case: OsApi_SetEvent.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_SetEvent
TEST.NEW
TEST.NAME:OsApi_SetEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_SetRelAlarm

-- Test Case: OsApi_SetRelAlarm.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_SetRelAlarm
TEST.NEW
TEST.NAME:OsApi_SetRelAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmAction:3
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:0
TEST.VALUE:OsApi.OsApi_SetRelAlarm.AlarmID:0
TEST.END

-- Test Case: OsApi_SetRelAlarm.002
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_SetRelAlarm
TEST.NEW
TEST.NAME:OsApi_SetRelAlarm.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:1
TEST.VALUE:OsApi.OsApi_SetRelAlarm.AlarmID:100
TEST.END

-- Test Case: OsApi_SetRelAlarm.003
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_SetRelAlarm
TEST.NEW
TEST.NAME:OsApi_SetRelAlarm.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmActivateTaskRef[0].TasksID:0
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmTask:0
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmAction:2
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:0
TEST.VALUE:OsApi.OsApi_SetRelAlarm.AlarmID:0
TEST.END

-- Test Case: OsApi_SetRelAlarm.004
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_SetRelAlarm
TEST.NEW
TEST.NAME:OsApi_SetRelAlarm.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmActivateTaskRef[0].TasksID:0
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmTask:0
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmAction:4
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:0
TEST.VALUE:OsApi.OsApi_SetRelAlarm.AlarmID:0
TEST.END

-- Test Case: OsApi_SetRelAlarm.005
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_SetRelAlarm
TEST.NEW
TEST.NAME:OsApi_SetRelAlarm.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmActivateTaskRef[0].TasksID:0
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmTask:0
TEST.VALUE:OsApi.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmAction:2
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0][0].pObjRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.TcbTaskRefConfig[0][0].pAppRef[0].AppId:2
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:2
TEST.VALUE:OsApi.<<GLOBAL>>.OsCtrlParam.ActiveTaskIndex:0
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:1
TEST.VALUE:OsApi.OsApi_SetRelAlarm.AlarmID:0
TEST.END

-- Subprogram: OsApi_SetScheduleTableAsync

-- Test Case: OsApi_SetScheduleTableAsync.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_SetScheduleTableAsync
TEST.NEW
TEST.NAME:OsApi_SetScheduleTableAsync.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_ShutdownOS

-- Test Case: OsApi_ShutdownOS.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_ShutdownOS
TEST.NEW
TEST.NAME:OsApi_ShutdownOS.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:0
TEST.END

-- Test Case: OsApi_ShutdownOS.002
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_ShutdownOS
TEST.NEW
TEST.NAME:OsApi_ShutdownOS.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.STUB:OsApi.OsApiPrv_IsAllowedAccess
TEST.VALUE:OsApi.OsApiPrv_IsAllowedAccess.return:1
TEST.END

-- Subprogram: OsApi_StartCore

-- Test Case: OsApi_StartCore.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_StartCore
TEST.NEW
TEST.NAME:OsApi_StartCore.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_StartNonAutosarCore

-- Test Case: OsApi_StartNonAutosarCore.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_StartNonAutosarCore
TEST.NEW
TEST.NAME:OsApi_StartNonAutosarCore.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_StartScheduleTableAbs

-- Test Case: OsApi_StartScheduleTableAbs.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_StartScheduleTableAbs
TEST.NEW
TEST.NAME:OsApi_StartScheduleTableAbs.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_StartScheduleTableRel

-- Test Case: OsApi_StartScheduleTableRel.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_StartScheduleTableRel
TEST.NEW
TEST.NAME:OsApi_StartScheduleTableRel.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_StartScheduleTableSynchron

-- Test Case: OsApi_StartScheduleTableSynchron.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_StartScheduleTableSynchron
TEST.NEW
TEST.NAME:OsApi_StartScheduleTableSynchron.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_StopScheduleTable

-- Test Case: OsApi_StopScheduleTable.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_StopScheduleTable
TEST.NEW
TEST.NAME:OsApi_StopScheduleTable.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_SuspendAllInterrupts

-- Test Case: OsApi_SuspendAllInterrupts.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_SuspendAllInterrupts
TEST.NEW
TEST.NAME:OsApi_SuspendAllInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_SuspendOSInterrupts

-- Test Case: OsApi_SuspendOSInterrupts.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_SuspendOSInterrupts
TEST.NEW
TEST.NAME:OsApi_SuspendOSInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_SyncScheduleTable

-- Test Case: OsApi_SyncScheduleTable.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_SyncScheduleTable
TEST.NEW
TEST.NAME:OsApi_SyncScheduleTable.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_TerminateApplication

-- Test Case: OsApi_TerminateApplication.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_TerminateApplication
TEST.NEW
TEST.NAME:OsApi_TerminateApplication.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_TerminateTask

-- Test Case: OsApi_TerminateTask.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_TerminateTask
TEST.NEW
TEST.NAME:OsApi_TerminateTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END

-- Subprogram: OsApi_WaitEvent

-- Test Case: OsApi_WaitEvent.001
TEST.UNIT:OsApi
TEST.SUBPROGRAM:OsApi_WaitEvent
TEST.NEW
TEST.NAME:OsApi_WaitEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7584
TEST.END_NOTES:
TEST.END
