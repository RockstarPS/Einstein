-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_TRAP_VCAST
-- Unit(s) Under Test: OsTrap
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: ActivateTask

-- Test Case: ActivateTask.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ActivateTask
TEST.NEW
TEST.NAME:ActivateTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.STUB:OsTrap.OsHal_TrapHandler
TEST.VALUE:OsTrap.<<GLOBAL>>.OsTrapTable[0].TrapFunc:OsTrap_ActivateTask
TEST.VALUE:OsTrap.OsHal_TrapHandler.FnIndex:0
TEST.END

-- Test Case: ActivateTask.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ActivateTask
TEST.NEW
TEST.NAME:ActivateTask.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: AllowAccess

-- Test Case: AllowAccess.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:AllowAccess
TEST.NEW
TEST.NAME:AllowAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: AllowAccess.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:AllowAccess
TEST.NEW
TEST.NAME:AllowAccess.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: CallTrustedFunction

-- Test Case: CallTrustedFunction.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CallTrustedFunction
TEST.NEW
TEST.NAME:CallTrustedFunction.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: CallTrustedFunction.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CallTrustedFunction
TEST.NEW
TEST.NAME:CallTrustedFunction.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: CancelAlarm

-- Test Case: CancelAlarm.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CancelAlarm
TEST.NEW
TEST.NAME:CancelAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: CancelAlarm.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CancelAlarm
TEST.NEW
TEST.NAME:CancelAlarm.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: ChainTask

-- Test Case: ChainTask.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ChainTask
TEST.NEW
TEST.NAME:ChainTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: ChainTask.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ChainTask
TEST.NEW
TEST.NAME:ChainTask.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: CheckISRMemoryAccess

-- Test Case: CheckISRMemoryAccess.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CheckISRMemoryAccess
TEST.NEW
TEST.NAME:CheckISRMemoryAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: CheckISRMemoryAccess.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CheckISRMemoryAccess
TEST.NEW
TEST.NAME:CheckISRMemoryAccess.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: CheckObjectAccess

-- Test Case: CheckObjectAccess.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CheckObjectAccess
TEST.NEW
TEST.NAME:CheckObjectAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: CheckObjectAccess.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CheckObjectAccess
TEST.NEW
TEST.NAME:CheckObjectAccess.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: CheckObjectOwnership

-- Test Case: CheckObjectOwnership.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CheckObjectOwnership
TEST.NEW
TEST.NAME:CheckObjectOwnership.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: CheckObjectOwnership.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CheckObjectOwnership
TEST.NEW
TEST.NAME:CheckObjectOwnership.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: CheckTaskMemoryAccess

-- Test Case: CheckTaskMemoryAccess.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CheckTaskMemoryAccess
TEST.NEW
TEST.NAME:CheckTaskMemoryAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: CheckTaskMemoryAccess.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:CheckTaskMemoryAccess
TEST.NEW
TEST.NAME:CheckTaskMemoryAccess.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: ClearEvent

-- Test Case: ClearEvent.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ClearEvent
TEST.NEW
TEST.NAME:ClearEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: ClearEvent.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ClearEvent
TEST.NEW
TEST.NAME:ClearEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: DisableAllInterrupts

-- Test Case: DisableAllInterrupts.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:DisableAllInterrupts
TEST.NEW
TEST.NAME:DisableAllInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: DisableAllInterrupts.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:DisableAllInterrupts
TEST.NEW
TEST.NAME:DisableAllInterrupts.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: DisableInterruptSource

-- Test Case: DisableInterruptSource.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:DisableInterruptSource
TEST.NEW
TEST.NAME:DisableInterruptSource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: DisableInterruptSource.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:DisableInterruptSource
TEST.NEW
TEST.NAME:DisableInterruptSource.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: EnableAllInterrupts

-- Test Case: EnableAllInterrupts.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:EnableAllInterrupts
TEST.NEW
TEST.NAME:EnableAllInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: EnableAllInterrupts.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:EnableAllInterrupts
TEST.NEW
TEST.NAME:EnableAllInterrupts.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: EnableInterruptSource

-- Test Case: EnableInterruptSource.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:EnableInterruptSource
TEST.NEW
TEST.NAME:EnableInterruptSource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: EnableInterruptSource.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:EnableInterruptSource
TEST.NEW
TEST.NAME:EnableInterruptSource.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: GetAlarm

-- Test Case: GetAlarm.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetAlarm
TEST.NEW
TEST.NAME:GetAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: GetAlarm.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetAlarm
TEST.NEW
TEST.NAME:GetAlarm.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: GetAlarmBase

-- Test Case: GetAlarmBase.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetAlarmBase
TEST.NEW
TEST.NAME:GetAlarmBase.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetApplicationID

-- Test Case: GetApplicationID.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetApplicationID
TEST.NEW
TEST.NAME:GetApplicationID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetApplicationState

-- Test Case: GetApplicationState.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetApplicationState
TEST.NEW
TEST.NAME:GetApplicationState.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetCoreId

-- Test Case: GetCoreId.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetCoreId
TEST.NEW
TEST.NAME:GetCoreId.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetCounterValue

-- Test Case: GetCounterValue.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetCounterValue
TEST.NEW
TEST.NAME:GetCounterValue.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetCurrentApplicationID

-- Test Case: GetCurrentApplicationID.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetCurrentApplicationID
TEST.NEW
TEST.NAME:GetCurrentApplicationID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetElapsedValue

-- Test Case: GetElapsedValue.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetElapsedValue
TEST.NEW
TEST.NAME:GetElapsedValue.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetEvent

-- Test Case: GetEvent.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetEvent
TEST.NEW
TEST.NAME:GetEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: GetEvent.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetEvent
TEST.NEW
TEST.NAME:GetEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: GetISRID

-- Test Case: GetISRID.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetISRID
TEST.NEW
TEST.NAME:GetISRID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetNumberOfActivatedCores

-- Test Case: GetNumberOfActivatedCores.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetNumberOfActivatedCores
TEST.NEW
TEST.NAME:GetNumberOfActivatedCores.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetResource

-- Test Case: GetResource.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetResource
TEST.NEW
TEST.NAME:GetResource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: GetResource.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetResource
TEST.NEW
TEST.NAME:GetResource.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: GetScheduleTableStatus

-- Test Case: GetScheduleTableStatus.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetScheduleTableStatus
TEST.NEW
TEST.NAME:GetScheduleTableStatus.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetTaskID

-- Test Case: GetTaskID.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetTaskID
TEST.NEW
TEST.NAME:GetTaskID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetTaskState

-- Test Case: GetTaskState.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetTaskState
TEST.NEW
TEST.NAME:GetTaskState.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: GetVersionInfo

-- Test Case: GetVersionInfo.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:GetVersionInfo
TEST.NEW
TEST.NAME:GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: IncrementCounter

-- Test Case: IncrementCounter.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:IncrementCounter
TEST.NEW
TEST.NAME:IncrementCounter.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: IncrementCounter.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:IncrementCounter
TEST.NEW
TEST.NAME:IncrementCounter.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: NextScheduleTable

-- Test Case: NextScheduleTable.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:NextScheduleTable
TEST.NEW
TEST.NAME:NextScheduleTable.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: NextScheduleTable.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:NextScheduleTable
TEST.NEW
TEST.NAME:NextScheduleTable.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: OsHal_TrapHandler

-- Test Case: OsHal_TrapHandler.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsHal_TrapHandler
TEST.NEW
TEST.NAME:OsHal_TrapHandler.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT2
TEST.VALUE:OsTrap.OsHal_TrapHandler.FnIndex:0
TEST.VALUE_USER_CODE:OsTrap.OsHal_TrapHandler.FnParam
<<OsTrap.OsHal_TrapHandler.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: OsHal_TrapHandler.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsHal_TrapHandler
TEST.NEW
TEST.NAME:OsHal_TrapHandler.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.OsHal_TrapHandler.FnIndex:40
TEST.VALUE_USER_CODE:OsTrap.OsHal_TrapHandler.FnParam
<<OsTrap.OsHal_TrapHandler.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_ActivateTask

-- Test Case: OsTrap_ActivateTask.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_ActivateTask
TEST.NEW
TEST.NAME:OsTrap_ActivateTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT3
TEST.VALUE_USER_CODE:OsTrap.OsTrap_ActivateTask.FnParam
<<OsTrap.OsTrap_ActivateTask.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_AllowAccess

-- Test Case: OsTrap_AllowAccess.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_AllowAccess
TEST.NEW
TEST.NAME:OsTrap_AllowAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_FLT1
TEST.VALUE_USER_CODE:OsTrap.OsTrap_AllowAccess.FnParam
<<OsTrap.OsTrap_AllowAccess.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_CallTrustedFunction

-- Test Case: OsTrap_CallTrustedFunction.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_CallTrustedFunction
TEST.NEW
TEST.NAME:OsTrap_CallTrustedFunction.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_FLT1
TEST.VALUE_USER_CODE:OsTrap.OsTrap_CallTrustedFunction.FnParam
<<OsTrap.OsTrap_CallTrustedFunction.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_CancelAlarm

-- Test Case: OsTrap_CancelAlarm.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_CancelAlarm
TEST.NEW
TEST.NAME:OsTrap_CancelAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT3
TEST.VALUE_USER_CODE:OsTrap.OsTrap_CancelAlarm.FnParam
<<OsTrap.OsTrap_CancelAlarm.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_CheckISRMemoryAccess

-- Test Case: OsTrap_CheckISRMemoryAccess.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_CheckISRMemoryAccess
TEST.NEW
TEST.NAME:OsTrap_CheckISRMemoryAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT2
TEST.VALUE_USER_CODE:OsTrap.OsTrap_CheckISRMemoryAccess.FnParam
<<OsTrap.OsTrap_CheckISRMemoryAccess.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_CheckObjectAccess

-- Test Case: OsTrap_CheckObjectAccess.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_CheckObjectAccess
TEST.NEW
TEST.NAME:OsTrap_CheckObjectAccess.001
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT3
TEST.VALUE_USER_CODE:OsTrap.OsTrap_CheckObjectAccess.FnParam
<<OsTrap.OsTrap_CheckObjectAccess.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_CheckObjectOwnership

-- Test Case: OsTrap_CheckObjectOwnership.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_CheckObjectOwnership
TEST.NEW
TEST.NAME:OsTrap_CheckObjectOwnership.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT1
TEST.VALUE_USER_CODE:OsTrap.OsTrap_CheckObjectOwnership.FnParam
<<OsTrap.OsTrap_CheckObjectOwnership.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_CheckTaskMemoryAccess

-- Test Case: OsTrap_CheckTaskMemoryAccess.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_CheckTaskMemoryAccess
TEST.NEW
TEST.NAME:OsTrap_CheckTaskMemoryAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_FLT1
TEST.VALUE_USER_CODE:OsTrap.OsTrap_CheckTaskMemoryAccess.FnParam
<<OsTrap.OsTrap_CheckTaskMemoryAccess.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_ClearEvent

-- Test Case: OsTrap_ClearEvent.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_ClearEvent
TEST.NEW
TEST.NAME:OsTrap_ClearEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_STR1
TEST.VALUE_USER_CODE:OsTrap.OsTrap_ClearEvent.FnParam
<<OsTrap.OsTrap_ClearEvent.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_DisableInterruptSource

-- Test Case: OsTrap_DisableInterruptSource.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_DisableInterruptSource
TEST.NEW
TEST.NAME:OsTrap_DisableInterruptSource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT2
TEST.VALUE_USER_CODE:OsTrap.OsTrap_DisableInterruptSource.FnParam
<<OsTrap.OsTrap_DisableInterruptSource.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_EnableInterruptSource

-- Test Case: OsTrap_EnableInterruptSource.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_EnableInterruptSource
TEST.NEW
TEST.NAME:OsTrap_EnableInterruptSource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT3
TEST.VALUE_USER_CODE:OsTrap.OsTrap_EnableInterruptSource.FnParam
<<OsTrap.OsTrap_EnableInterruptSource.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_GetAlarm

-- Test Case: OsTrap_GetAlarm.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_GetAlarm
TEST.NEW
TEST.NAME:OsTrap_GetAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT3
TEST.VALUE_USER_CODE:OsTrap.OsTrap_GetAlarm.FnParam
<<OsTrap.OsTrap_GetAlarm.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_GetEvent

-- Test Case: OsTrap_GetEvent.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_GetEvent
TEST.NEW
TEST.NAME:OsTrap_GetEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_FLT1
TEST.VALUE_USER_CODE:OsTrap.OsTrap_GetEvent.FnParam
<<OsTrap.OsTrap_GetEvent.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_GetResource

-- Test Case: OsTrap_GetResource.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_GetResource
TEST.NEW
TEST.NAME:OsTrap_GetResource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT3
TEST.VALUE_USER_CODE:OsTrap.OsTrap_GetResource.FnParam
<<OsTrap.OsTrap_GetResource.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_IncrementCounter

-- Test Case: OsTrap_IncrementCounter.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_IncrementCounter
TEST.NEW
TEST.NAME:OsTrap_IncrementCounter.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT2
TEST.VALUE_USER_CODE:OsTrap.OsTrap_IncrementCounter.FnParam
<<OsTrap.OsTrap_IncrementCounter.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_NextScheduleTable

-- Test Case: OsTrap_NextScheduleTable.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_NextScheduleTable
TEST.NEW
TEST.NAME:OsTrap_NextScheduleTable.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT3
TEST.VALUE_USER_CODE:OsTrap.OsTrap_NextScheduleTable.FnParam
<<OsTrap.OsTrap_NextScheduleTable.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_ReleaseResource

-- Test Case: OsTrap_ReleaseResource.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_ReleaseResource
TEST.NEW
TEST.NAME:OsTrap_ReleaseResource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_STR1
TEST.VALUE_USER_CODE:OsTrap.OsTrap_ReleaseResource.FnParam
<<OsTrap.OsTrap_ReleaseResource.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_ResumeAllInterrupts

-- Test Case: OsTrap_ResumeAllInterrupts.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_ResumeAllInterrupts
TEST.NEW
TEST.NAME:OsTrap_ResumeAllInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: OsTrap_ResumeOSInterrupts

-- Test Case: OsTrap_ResumeOSInterrupts.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_ResumeOSInterrupts
TEST.NEW
TEST.NAME:OsTrap_ResumeOSInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: OsTrap_Schedule

-- Test Case: OsTrap_Schedule.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_Schedule
TEST.NEW
TEST.NAME:OsTrap_Schedule.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_FLT1
TEST.VALUE_USER_CODE:OsTrap.OsTrap_Schedule.FnParam
<<OsTrap.OsTrap_Schedule.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_SetAbsAlarm

-- Test Case: OsTrap_SetAbsAlarm.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_SetAbsAlarm
TEST.NEW
TEST.NAME:OsTrap_SetAbsAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT3
TEST.VALUE_USER_CODE:OsTrap.OsTrap_SetAbsAlarm.FnParam
<<OsTrap.OsTrap_SetAbsAlarm.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_SetEvent

-- Test Case: OsTrap_SetEvent.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_SetEvent
TEST.NEW
TEST.NAME:OsTrap_SetEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_BUFFER
TEST.VALUE_USER_CODE:OsTrap.OsTrap_SetEvent.FnParam
<<OsTrap.OsTrap_SetEvent.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_SetRelAlarm

-- Test Case: OsTrap_SetRelAlarm.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_SetRelAlarm
TEST.NEW
TEST.NAME:OsTrap_SetRelAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT2
TEST.VALUE_USER_CODE:OsTrap.OsTrap_SetRelAlarm.FnParam
<<OsTrap.OsTrap_SetRelAlarm.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_ShutdownOS

-- Test Case: OsTrap_ShutdownOS.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_ShutdownOS
TEST.NEW
TEST.NAME:OsTrap_ShutdownOS.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE_USER_CODE:OsTrap.OsTrap_ShutdownOS.FnParam
<<OsTrap.OsTrap_ShutdownOS.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_StartScheduleTableAbs

-- Test Case: OsTrap_StartScheduleTableAbs.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_StartScheduleTableAbs
TEST.NEW
TEST.NAME:OsTrap_StartScheduleTableAbs.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT3
TEST.VALUE_USER_CODE:OsTrap.OsTrap_StartScheduleTableAbs.FnParam
<<OsTrap.OsTrap_StartScheduleTableAbs.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_StartScheduleTableRel

-- Test Case: OsTrap_StartScheduleTableRel.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_StartScheduleTableRel
TEST.NEW
TEST.NAME:OsTrap_StartScheduleTableRel.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT2
TEST.VALUE_USER_CODE:OsTrap.OsTrap_StartScheduleTableRel.FnParam
<<OsTrap.OsTrap_StartScheduleTableRel.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_StopScheduleTable

-- Test Case: OsTrap_StopScheduleTable.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_StopScheduleTable
TEST.NEW
TEST.NAME:OsTrap_StopScheduleTable.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_BUFFER
TEST.VALUE_USER_CODE:OsTrap.OsTrap_StopScheduleTable.FnParam
<<OsTrap.OsTrap_StopScheduleTable.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_SuspendAllInterrupts

-- Test Case: OsTrap_SuspendAllInterrupts.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_SuspendAllInterrupts
TEST.NEW
TEST.NAME:OsTrap_SuspendAllInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: OsTrap_SuspendOSInterrupts

-- Test Case: OsTrap_SuspendOSInterrupts.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_SuspendOSInterrupts
TEST.NEW
TEST.NAME:OsTrap_SuspendOSInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: OsTrap_TerminateApplication

-- Test Case: OsTrap_TerminateApplication.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_TerminateApplication
TEST.NEW
TEST.NAME:OsTrap_TerminateApplication.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT3
TEST.VALUE_USER_CODE:OsTrap.OsTrap_TerminateApplication.FnParam
<<OsTrap.OsTrap_TerminateApplication.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_TerminateTask

-- Test Case: OsTrap_TerminateTask.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_TerminateTask
TEST.NEW
TEST.NAME:OsTrap_TerminateTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_INT2
TEST.VALUE_USER_CODE:OsTrap.OsTrap_TerminateTask.FnParam
<<OsTrap.OsTrap_TerminateTask.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsTrap_WaitEvent

-- Test Case: OsTrap_WaitEvent.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:OsTrap_WaitEvent
TEST.NEW
TEST.NAME:OsTrap_WaitEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:OsTrap.<<GLOBAL>>.FnParam:VECTORCAST_STR1
TEST.VALUE_USER_CODE:OsTrap.OsTrap_WaitEvent.FnParam
<<OsTrap.OsTrap_WaitEvent.FnParam>> = ( &FnParam );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: ReleaseResource

-- Test Case: ReleaseResource.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ReleaseResource
TEST.NEW
TEST.NAME:ReleaseResource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: ReleaseResource.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ReleaseResource
TEST.NEW
TEST.NAME:ReleaseResource.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: ResumeAllInterrupts

-- Test Case: ResumeAllInterrupts.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ResumeAllInterrupts
TEST.NEW
TEST.NAME:ResumeAllInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: ResumeAllInterrupts.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ResumeAllInterrupts
TEST.NEW
TEST.NAME:ResumeAllInterrupts.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: ResumeOSInterrupts

-- Test Case: ResumeOSInterrupts.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ResumeOSInterrupts
TEST.NEW
TEST.NAME:ResumeOSInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: ResumeOSInterrupts.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ResumeOSInterrupts
TEST.NEW
TEST.NAME:ResumeOSInterrupts.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: Schedule

-- Test Case: Schedule.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:Schedule
TEST.NEW
TEST.NAME:Schedule.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: Schedule.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:Schedule
TEST.NEW
TEST.NAME:Schedule.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: SetAbsAlarm

-- Test Case: SetAbsAlarm.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SetAbsAlarm
TEST.NEW
TEST.NAME:SetAbsAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: SetAbsAlarm.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SetAbsAlarm
TEST.NEW
TEST.NAME:SetAbsAlarm.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: SetEvent

-- Test Case: SetEvent.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SetEvent
TEST.NEW
TEST.NAME:SetEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: SetEvent.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SetEvent
TEST.NEW
TEST.NAME:SetEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: SetRelAlarm

-- Test Case: SetRelAlarm.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SetRelAlarm
TEST.NEW
TEST.NAME:SetRelAlarm.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: SetRelAlarm.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SetRelAlarm
TEST.NEW
TEST.NAME:SetRelAlarm.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: SetScheduleTableAsync

-- Test Case: SetScheduleTableAsync.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SetScheduleTableAsync
TEST.NEW
TEST.NAME:SetScheduleTableAsync.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: ShutdownOS

-- Test Case: ShutdownOS.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ShutdownOS
TEST.NEW
TEST.NAME:ShutdownOS.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: ShutdownOS.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:ShutdownOS
TEST.NEW
TEST.NAME:ShutdownOS.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: StartCore

-- Test Case: StartCore.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:StartCore
TEST.NEW
TEST.NAME:StartCore.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: StartNonAutosarCore

-- Test Case: StartNonAutosarCore.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:StartNonAutosarCore
TEST.NEW
TEST.NAME:StartNonAutosarCore.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: StartScheduleTableAbs

-- Test Case: StartScheduleTableAbs.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:StartScheduleTableAbs
TEST.NEW
TEST.NAME:StartScheduleTableAbs.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: StartScheduleTableAbs.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:StartScheduleTableAbs
TEST.NEW
TEST.NAME:StartScheduleTableAbs.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: StartScheduleTableRel

-- Test Case: StartScheduleTableRel.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:StartScheduleTableRel
TEST.NEW
TEST.NAME:StartScheduleTableRel.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: StartScheduleTableRel.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:StartScheduleTableRel
TEST.NEW
TEST.NAME:StartScheduleTableRel.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: StartScheduleTableSynchron

-- Test Case: StartScheduleTableSynchron.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:StartScheduleTableSynchron
TEST.NEW
TEST.NAME:StartScheduleTableSynchron.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: StopScheduleTable

-- Test Case: StopScheduleTable.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:StopScheduleTable
TEST.NEW
TEST.NAME:StopScheduleTable.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: StopScheduleTable.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:StopScheduleTable
TEST.NEW
TEST.NAME:StopScheduleTable.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: SuspendAllInterrupts

-- Test Case: SuspendAllInterrupts.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SuspendAllInterrupts
TEST.NEW
TEST.NAME:SuspendAllInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: SuspendAllInterrupts.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SuspendAllInterrupts
TEST.NEW
TEST.NAME:SuspendAllInterrupts.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: SuspendOSInterrupts

-- Test Case: SuspendOSInterrupts.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SuspendOSInterrupts
TEST.NEW
TEST.NAME:SuspendOSInterrupts.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: SuspendOSInterrupts.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SuspendOSInterrupts
TEST.NEW
TEST.NAME:SuspendOSInterrupts.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: SyncScheduleTable

-- Test Case: SyncScheduleTable.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:SyncScheduleTable
TEST.NEW
TEST.NAME:SyncScheduleTable.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Subprogram: TerminateApplication

-- Test Case: TerminateApplication.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:TerminateApplication
TEST.NEW
TEST.NAME:TerminateApplication.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: TerminateApplication.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:TerminateApplication
TEST.NEW
TEST.NAME:TerminateApplication.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: TerminateTask

-- Test Case: TerminateTask.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:TerminateTask
TEST.NEW
TEST.NAME:TerminateTask.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: TerminateTask.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:TerminateTask
TEST.NEW
TEST.NAME:TerminateTask.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END

-- Subprogram: WaitEvent

-- Test Case: WaitEvent.001
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:WaitEvent
TEST.NEW
TEST.NAME:WaitEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.END

-- Test Case: WaitEvent.002
TEST.UNIT:OsTrap
TEST.SUBPROGRAM:WaitEvent
TEST.NEW
TEST.NAME:WaitEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7610
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCpuHal_IsOsTrapRequired.return:1
TEST.END
