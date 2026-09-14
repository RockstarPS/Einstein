-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : ECUMUT_VCAST_HT
-- Unit(s) Under Test: EcuM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: EcuM

-- Subprogram: ECUM_REPORT_ERROR

-- Test Case: ECUM_REPORT_ERROR.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:ECUM_REPORT_ERROR
TEST.NEW
TEST.NAME:ECUM_REPORT_ERROR.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_CB_NfyNvMJobEnd

-- Test Case: EcuM_CB_NfyNvMJobEnd.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_CB_NfyNvMJobEnd
TEST.NEW
TEST.NAME:EcuM_CB_NfyNvMJobEnd.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_CB_NfyNvMJobEnd.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_CB_NfyNvMJobEnd
TEST.NEW
TEST.NAME:EcuM_CB_NfyNvMJobEnd.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_CB_NfyNvMJobEnd.ServiceId:13
TEST.END

-- Test Case: EcuM_CB_NfyNvMJobEnd.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_CB_NfyNvMJobEnd
TEST.NEW
TEST.NAME:EcuM_CB_NfyNvMJobEnd.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_CB_NfyNvMJobEnd.ServiceId:12
TEST.END

-- Subprogram: EcuM_ClearWakeupEvent

-- Test Case: EcuM_ClearWakeupEvent.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_ClearWakeupEvent
TEST.NEW
TEST.NAME:EcuM_ClearWakeupEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_EndCheckWakeup

-- Test Case: EcuM_EndCheckWakeup.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_EndCheckWakeup
TEST.NEW
TEST.NAME:EcuM_EndCheckWakeup.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_EnterRunState

-- Test Case: EcuM_EnterRunState.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_EnterRunState
TEST.NEW
TEST.NAME:EcuM_EnterRunState.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_EnterSleep

-- Test Case: EcuM_EnterSleep.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_EnterSleep
TEST.NEW
TEST.NAME:EcuM_EnterSleep.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_EnterSleep.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_EnterSleep
TEST.NEW
TEST.NAME:EcuM_EnterSleep.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.CurrentShutdownMode:2
TEST.END

-- Test Case: EcuM_EnterSleep.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_EnterSleep
TEST.NEW
TEST.NAME:EcuM_EnterSleep.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.EnabledWakeupSource:1
TEST.END

-- Test Case: EcuM_EnterSleep.004
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_EnterSleep
TEST.NEW
TEST.NAME:EcuM_EnterSleep.004
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ValidatedWakeups:9
TEST.END

-- Test Case: EcuM_EnterSleep.005
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_EnterSleep
TEST.NEW
TEST.NAME:EcuM_EnterSleep.005
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ValidatedWakeups:0
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_SleepModeList[0].IsPollingAllowed:1
TEST.END

-- Subprogram: EcuM_GetBootTarget

-- Test Case: EcuM_GetBootTarget.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetBootTarget
TEST.NEW
TEST.NAME:EcuM_GetBootTarget.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_GetExpiredWakeupEvents

-- Test Case: EcuM_GetExpiredWakeupEvents.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetExpiredWakeupEvents
TEST.NEW
TEST.NAME:EcuM_GetExpiredWakeupEvents.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_GetLastShutdownTarget

-- Test Case: EcuM_GetLastShutdownTarget.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetLastShutdownTarget
TEST.NEW
TEST.NAME:EcuM_GetLastShutdownTarget.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_GetLastShutdownTarget.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetLastShutdownTarget
TEST.NEW
TEST.NAME:EcuM_GetLastShutdownTarget.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_GetLastShutdownTarget.shutdownTarget:<<malloc 1>>
TEST.VALUE:EcuM.EcuM_GetLastShutdownTarget.shutdownTarget[0]:0
TEST.VALUE:EcuM.EcuM_GetLastShutdownTarget.sleepMode:<<malloc 1>>
TEST.VALUE:EcuM.EcuM_GetLastShutdownTarget.sleepMode[0]:0
TEST.END

-- Subprogram: EcuM_GetPendingWakeupEvents

-- Test Case: EcuM_GetPendingWakeupEvents.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetPendingWakeupEvents
TEST.NEW
TEST.NAME:EcuM_GetPendingWakeupEvents.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_GetShutdownTarget

-- Test Case: EcuM_GetShutdownTarget.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetShutdownTarget
TEST.NEW
TEST.NAME:EcuM_GetShutdownTarget.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_GetShutdownTarget.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetShutdownTarget
TEST.NEW
TEST.NAME:EcuM_GetShutdownTarget.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_GetShutdownTarget.shutdownTarget:<<malloc 1>>
TEST.VALUE:EcuM.EcuM_GetShutdownTarget.shutdownTarget[0]:0
TEST.VALUE:EcuM.EcuM_GetShutdownTarget.sleepMode:<<malloc 1>>
TEST.VALUE:EcuM.EcuM_GetShutdownTarget.sleepMode[0]:0
TEST.END

-- Subprogram: EcuM_GetState

-- Test Case: EcuM_GetState.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetState
TEST.NEW
TEST.NAME:EcuM_GetState.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_GetState.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetState
TEST.NEW
TEST.NAME:EcuM_GetState.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_GetState.state:<<malloc 1>>
TEST.END

-- Subprogram: EcuM_GetStatusOfWakeupSource

-- Test Case: EcuM_GetStatusOfWakeupSource.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetStatusOfWakeupSource
TEST.NEW
TEST.NAME:EcuM_GetStatusOfWakeupSource.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_GetValidatedWakeupEvents

-- Test Case: EcuM_GetValidatedWakeupEvents.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetValidatedWakeupEvents
TEST.NEW
TEST.NAME:EcuM_GetValidatedWakeupEvents.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_GetVersionInfo

-- Test Case: EcuM_GetVersionInfo.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetVersionInfo
TEST.NEW
TEST.NAME:EcuM_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_GetVersionInfo.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_GetVersionInfo
TEST.NEW
TEST.NAME:EcuM_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_GetVersionInfo.VersionInfo:<<malloc 1>>
TEST.END

-- Subprogram: EcuM_Init

-- Test Case: EcuM_Init.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_Init
TEST.NEW
TEST.NAME:EcuM_Init.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_InternalBufferedComMNotifications

-- Test Case: EcuM_InternalBufferedComMNotifications.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalBufferedComMNotifications
TEST.NEW
TEST.NAME:EcuM_InternalBufferedComMNotifications.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_InternalBufferedComMNotifications.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalBufferedComMNotifications
TEST.NEW
TEST.NAME:EcuM_InternalBufferedComMNotifications.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ComM_BufferedWakeups:1
TEST.END

-- Test Case: EcuM_InternalBufferedComMNotifications.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalBufferedComMNotifications
TEST.NEW
TEST.NAME:EcuM_InternalBufferedComMNotifications.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ComM_BufferedWakeups:1
TEST.VALUE:uut_prototype_stubs.ComM_GetStatus.Status[0]:COMM_INIT
TEST.VALUE:uut_prototype_stubs.ComM_GetStatus.return:0
TEST.END

-- Test Case: EcuM_InternalBufferedComMNotifications.004
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalBufferedComMNotifications
TEST.NEW
TEST.NAME:EcuM_InternalBufferedComMNotifications.004
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ComM_BufferedWakeups:128
TEST.VALUE:uut_prototype_stubs.ComM_GetStatus.Status[0]:COMM_INIT
TEST.VALUE:uut_prototype_stubs.ComM_GetStatus.return:0
TEST.END

-- Subprogram: EcuM_InternalCheckWakupMaskValidity

-- Test Case: EcuM_InternalCheckWakupMaskValidity.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalCheckWakupMaskValidity
TEST.NEW
TEST.NAME:EcuM_InternalCheckWakupMaskValidity.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_InternalCheckWakupMaskValidity.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalCheckWakupMaskValidity
TEST.NEW
TEST.NAME:EcuM_InternalCheckWakupMaskValidity.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.wkpSrcMask:1
TEST.END

-- Test Case: EcuM_InternalCheckWakupMaskValidity.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalCheckWakupMaskValidity
TEST.NEW
TEST.NAME:EcuM_InternalCheckWakupMaskValidity.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.wkpSrcMask:2
TEST.END

-- Test Case: EcuM_InternalCheckWakupMaskValidity.005
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalCheckWakupMaskValidity
TEST.NEW
TEST.NAME:EcuM_InternalCheckWakupMaskValidity.005
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.wkpSrcMask:3
TEST.END

-- Subprogram: EcuM_InternalClearWakeupEvent

-- Test Case: EcuM_InternalClearWakeupEvent.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalClearWakeupEvent
TEST.NEW
TEST.NAME:EcuM_InternalClearWakeupEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_InternalEnterHaltMode

-- Test Case: EcuM_InternalEnterHaltMode.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalEnterHaltMode
TEST.NEW
TEST.NAME:EcuM_InternalEnterHaltMode.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_InternalEnterHaltMode.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalEnterHaltMode
TEST.NEW
TEST.NAME:EcuM_InternalEnterHaltMode.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.CurrentShutdownMode:2
TEST.END

-- Test Case: EcuM_InternalEnterHaltMode.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalEnterHaltMode
TEST.NEW
TEST.NAME:EcuM_InternalEnterHaltMode.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ValidatedWakeups:1
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.CurrentShutdownMode:2
TEST.END

-- Subprogram: EcuM_InternalEnterPollingMode

-- Test Case: EcuM_InternalEnterPollingMode.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalEnterPollingMode
TEST.NEW
TEST.NAME:EcuM_InternalEnterPollingMode.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_InternalKillAllRequests

-- Test Case: EcuM_InternalKillAllRequests.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalKillAllRequests
TEST.NEW
TEST.NAME:EcuM_InternalKillAllRequests.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_InternalKillAllRequests.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalKillAllRequests
TEST.NEW
TEST.NAME:EcuM_InternalKillAllRequests.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x32
TEST.VALUE:EcuM.EcuM_InternalKillAllRequests.mask:1
TEST.END

-- Subprogram: EcuM_InternalReleaseRUN

-- Test Case: EcuM_InternalReleaseRUN.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalReleaseRUN
TEST.NEW
TEST.NAME:EcuM_InternalReleaseRUN.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_InternalReleaseRUN.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalReleaseRUN
TEST.NEW
TEST.NAME:EcuM_InternalReleaseRUN.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.User:13
TEST.END

-- Test Case: EcuM_InternalReleaseRUN.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalReleaseRUN
TEST.NEW
TEST.NAME:EcuM_InternalReleaseRUN.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.User:1
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Mask:1
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Counter_p:<<malloc 1>>
TEST.END

-- Test Case: EcuM_InternalReleaseRUN.004
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalReleaseRUN
TEST.NEW
TEST.NAME:EcuM_InternalReleaseRUN.004
TEST.NOTES:
SoftwareArchitecture::SYS::WdgM::WdgM_Detailed_Design::WdgM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.User:1
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Mask:1
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Counter_p:<<malloc 1>>
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Counter_p[0]:1
TEST.END

-- Test Case: EcuM_InternalReleaseRUN.005
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalReleaseRUN
TEST.NEW
TEST.NAME:EcuM_InternalReleaseRUN.005
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.Users[0]:0xF
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Mask:0x1
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Counter_p:<<malloc 1>>
TEST.EXPECTED:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Mask:0x1
TEST.ATTRIBUTES:EcuM.<<GLOBAL>>.EcuM_InternalParam.Users.Users[0]:EXPECTED_BASE=16
TEST.END

-- Test Case: EcuM_InternalReleaseRUN.006
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalReleaseRUN
TEST.NEW
TEST.NAME:EcuM_InternalReleaseRUN.006
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.Users[0]:0xF
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Mask:0x1
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Counter_p:<<malloc 1>>
TEST.VALUE:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Counter_p[0]:4
TEST.EXPECTED:EcuM.EcuM_InternalReleaseRUN.fl_user_param.Mask:0x1
TEST.ATTRIBUTES:EcuM.<<GLOBAL>>.EcuM_InternalParam.Users.Users[0]:EXPECTED_BASE=16
TEST.END

-- Subprogram: EcuM_InternalRequestRUN

-- Test Case: EcuM_InternalRequestRUN.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalRequestRUN
TEST.NEW
TEST.NAME:EcuM_InternalRequestRUN.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.Counter_p:<<malloc 1>>
TEST.END

-- Test Case: EcuM_InternalRequestRUN.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalRequestRUN
TEST.NEW
TEST.NAME:EcuM_InternalRequestRUN.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.User:13
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.Counter_p:<<malloc 1>>
TEST.END

-- Test Case: EcuM_InternalRequestRUN.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalRequestRUN
TEST.NEW
TEST.NAME:EcuM_InternalRequestRUN.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.KillAllRequestStatus:1
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.Mask:1
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.Counter_p:<<malloc 1>>
TEST.END

-- Test Case: EcuM_InternalRequestRUN.004
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalRequestRUN
TEST.NEW
TEST.NAME:EcuM_InternalRequestRUN.004
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.Users[0]:1
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.User:1
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.Mask:1
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.Counter_p:<<malloc 1>>
TEST.END

-- Test Case: EcuM_InternalRequestRUN.005
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalRequestRUN
TEST.NEW
TEST.NAME:EcuM_InternalRequestRUN.005
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.Counter_p:<<malloc 1>>
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.Counter_p[0]:0xFF
TEST.END

-- Test Case: EcuM_InternalRequestRUN.006
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalRequestRUN
TEST.NEW
TEST.NAME:EcuM_InternalRequestRUN.006
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.Users[0]:0xF
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.Mask:0x1
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.Counter_p:<<malloc 1>>
TEST.VALUE:EcuM.EcuM_InternalRequestRUN.fl_user_param.Counter_p[0]:0xFF
TEST.END

-- Subprogram: EcuM_InternalWakeupSourcesValidation

-- Test Case: EcuM_InternalWakeupSourcesValidation.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalWakeupSourcesValidation
TEST.NEW
TEST.NAME:EcuM_InternalWakeupSourcesValidation.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_InternalWakeupSourcesValidation.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalWakeupSourcesValidation
TEST.NEW
TEST.NAME:EcuM_InternalWakeupSourcesValidation.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.PostedWakeups:0xFF
TEST.END

-- Test Case: EcuM_InternalWakeupSourcesValidation.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalWakeupSourcesValidation
TEST.NEW
TEST.NAME:EcuM_InternalWakeupSourcesValidation.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.PostedWakeups:0xFF
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_ValidationTimeouts[5]:1
TEST.END

-- Test Case: EcuM_InternalWakeupSourcesValidation.004
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalWakeupSourcesValidation
TEST.NEW
TEST.NAME:EcuM_InternalWakeupSourcesValidation.004
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.PostedWakeups:0xFF
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_ValidationTimeouts[5]:3
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_ValidationTimeouts[6..7]:1
TEST.END

-- Test Case: EcuM_InternalWakeupSourcesValidation.005
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_InternalWakeupSourcesValidation
TEST.NEW
TEST.NAME:EcuM_InternalWakeupSourcesValidation.005
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ClearedPostedWakeups:0xFF
TEST.END

-- Subprogram: EcuM_KillAllPostRUNRequests

-- Test Case: EcuM_KillAllPostRUNRequests.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_KillAllPostRUNRequests
TEST.NEW
TEST.NAME:EcuM_KillAllPostRUNRequests.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_KillAllRUNRequests

-- Test Case: EcuM_KillAllRUNRequests.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_KillAllRUNRequests
TEST.NEW
TEST.NAME:EcuM_KillAllRUNRequests.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_MainFunction

-- Test Case: EcuM_MainFunction.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_MainFunction
TEST.NEW
TEST.NAME:EcuM_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_MainFunction.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_MainFunction
TEST.NEW
TEST.NAME:EcuM_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.Timer:1
TEST.END

-- Subprogram: EcuM_QryComMRunRequest

-- Test Case: EcuM_QryComMRunRequest.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_QryComMRunRequest
TEST.NEW
TEST.NAME:EcuM_QryComMRunRequest.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_QryComMRunRequest.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_QryComMRunRequest
TEST.NEW
TEST.NAME:EcuM_QryComMRunRequest.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.ComM_GetState.return:1
TEST.END

-- Subprogram: EcuM_ReleasePOST_RUN

-- Test Case: EcuM_ReleasePOST_RUN.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_ReleasePOST_RUN
TEST.NEW
TEST.NAME:EcuM_ReleasePOST_RUN.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_ReleaseRUN

-- Test Case: EcuM_ReleaseRUN.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_ReleaseRUN
TEST.NEW
TEST.NAME:EcuM_ReleaseRUN.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_RequestPOST_RUN

-- Test Case: EcuM_RequestPOST_RUN.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_RequestPOST_RUN
TEST.NEW
TEST.NAME:EcuM_RequestPOST_RUN.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_RequestRUN

-- Test Case: EcuM_RequestRUN.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_RequestRUN
TEST.NEW
TEST.NAME:EcuM_RequestRUN.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_SelectBootTarget

-- Test Case: EcuM_SelectBootTarget.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SelectBootTarget
TEST.NEW
TEST.NAME:EcuM_SelectBootTarget.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_SelectShutdownTarget

-- Test Case: EcuM_SelectShutdownTarget.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SelectShutdownTarget
TEST.NEW
TEST.NAME:EcuM_SelectShutdownTarget.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_SelectShutdownTarget.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SelectShutdownTarget
TEST.NEW
TEST.NAME:EcuM_SelectShutdownTarget.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:51
TEST.END

-- Test Case: EcuM_SelectShutdownTarget.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SelectShutdownTarget
TEST.NEW
TEST.NAME:EcuM_SelectShutdownTarget.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:51
TEST.VALUE:EcuM.EcuM_SelectShutdownTarget.target:144
TEST.VALUE:EcuM.EcuM_SelectShutdownTarget.mode:3
TEST.END

-- Test Case: EcuM_SelectShutdownTarget.004
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SelectShutdownTarget
TEST.NEW
TEST.NAME:EcuM_SelectShutdownTarget.004
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:51
TEST.VALUE:EcuM.EcuM_SelectShutdownTarget.target:128
TEST.VALUE:EcuM.EcuM_SelectShutdownTarget.mode:3
TEST.END

-- Subprogram: EcuM_SetWakeupEvent

-- Test Case: EcuM_SetWakeupEvent.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SetWakeupEvent
TEST.NEW
TEST.NAME:EcuM_SetWakeupEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_SetWakeupEvent.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SetWakeupEvent
TEST.NEW
TEST.NAME:EcuM_SetWakeupEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_InternalCheckWakupMaskValidity
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.return:8
TEST.END

-- Test Case: EcuM_SetWakeupEvent.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SetWakeupEvent
TEST.NEW
TEST.NAME:EcuM_SetWakeupEvent.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.PostedWakeups:1
TEST.VALUE:EcuM.EcuM_SetWakeupEvent.sources:1
TEST.END

-- Test Case: EcuM_SetWakeupEvent.004
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SetWakeupEvent
TEST.NEW
TEST.NAME:EcuM_SetWakeupEvent.004
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_InternalCheckWakupMaskValidity
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.return:0
TEST.END

-- Test Case: EcuM_SetWakeupEvent.005
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SetWakeupEvent
TEST.NEW
TEST.NAME:EcuM_SetWakeupEvent.005
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_InternalCheckWakupMaskValidity
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.PostedWakeups:1
TEST.VALUE:EcuM.EcuM_SetWakeupEvent.sources:1
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.return:8
TEST.END

-- Test Case: EcuM_SetWakeupEvent.006
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SetWakeupEvent
TEST.NEW
TEST.NAME:EcuM_SetWakeupEvent.006
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_InternalCheckWakupMaskValidity
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.PostedWakeups:0
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[0].ValidationTime:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[0].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[1].ValidationTime:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[1].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[2].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[2].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[3].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[3].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[4].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[4].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[5].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[5].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[6].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[6].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].ValidationTime:15
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].Channel:1
TEST.VALUE:EcuM.EcuM_SetWakeupEvent.sources:1
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.wkpSrcMask:0
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.return:6
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[0].ValidationTime:5
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[1].ValidationTime:5
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[2].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[3].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[4].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[5].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[6].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].ValidationTime:15
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].Channel:1
TEST.EXPECTED:EcuM.EcuM_SetWakeupEvent.sources:1
TEST.EXPECTED:EcuM.EcuM_InternalCheckWakupMaskValidity.wkpSrcMask:1
TEST.END

-- Test Case: EcuM_SetWakeupEvent.007
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SetWakeupEvent
TEST.NEW
TEST.NAME:EcuM_SetWakeupEvent.007
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_InternalCheckWakupMaskValidity
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.PostedWakeups:1
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[0].ValidationTime:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[0].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[1].ValidationTime:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[1].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[2].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[2].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[3].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[3].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[4].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[4].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[5].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[5].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[6].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[6].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].ValidationTime:15
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].Channel:1
TEST.VALUE:EcuM.EcuM_SetWakeupEvent.sources:1
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.wkpSrcMask:0
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.return:6
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[0].ValidationTime:5
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[1].ValidationTime:5
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[2].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[3].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[4].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[5].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[6].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].ValidationTime:15
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].Channel:1
TEST.EXPECTED:EcuM.EcuM_SetWakeupEvent.sources:1
TEST.EXPECTED:EcuM.EcuM_InternalCheckWakupMaskValidity.wkpSrcMask:1
TEST.END

-- Test Case: EcuM_SetWakeupEvent.008
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_SetWakeupEvent
TEST.NEW
TEST.NAME:EcuM_SetWakeupEvent.008
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_InternalCheckWakupMaskValidity
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.PostedWakeups:0
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[0].ValidationTime:0
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[0].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[1].ValidationTime:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[1].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[2].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[2].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[3].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[3].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[4].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[4].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[5].ValidationTime:55
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[5].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[6].ValidationTime:0
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[6].Channel:5
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].ValidationTime:0
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].Channel:1
TEST.VALUE:EcuM.EcuM_SetWakeupEvent.sources:1
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.wkpSrcMask:0
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.return:6
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[0].ValidationTime:0
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[1].ValidationTime:5
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[2].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[3].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[4].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[5].ValidationTime:55
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[6].ValidationTime:0
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].ValidationTime:0
TEST.EXPECTED:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[7].Channel:1
TEST.EXPECTED:EcuM.EcuM_SetWakeupEvent.sources:1
TEST.EXPECTED:EcuM.EcuM_InternalCheckWakupMaskValidity.wkpSrcMask:1
TEST.END

-- Subprogram: EcuM_Shutdown

-- Test Case: EcuM_Shutdown.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_Shutdown
TEST.NEW
TEST.NAME:EcuM_Shutdown.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_Shutdown.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_Shutdown
TEST.NEW
TEST.NAME:EcuM_Shutdown.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.CurrentShutdownTarget:0x90
TEST.END

-- Test Case: EcuM_Shutdown.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_Shutdown
TEST.NEW
TEST.NAME:EcuM_Shutdown.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.CurrentShutdownTarget:0x80
TEST.END

-- Subprogram: EcuM_StartCheckWakeup

-- Test Case: EcuM_StartCheckWakeup.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StartCheckWakeup
TEST.NEW
TEST.NAME:EcuM_StartCheckWakeup.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_StartupTwo

-- Test Case: EcuM_StartupTwo.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StartupTwo
TEST.NEW
TEST.NAME:EcuM_StartupTwo.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Subprogram: EcuM_StateMachine

-- Test Case: EcuM_StateMachine.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_StateMachine.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x13
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMCbkReadAllNotified:1
TEST.END

-- Test Case: EcuM_StateMachine.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x12
TEST.END

-- Test Case: EcuM_StateMachine.004
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.004
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ValidatedWakeups:1
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x12
TEST.END

-- Test Case: EcuM_StateMachine.005
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.005
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x32
TEST.END

-- Test Case: EcuM_StateMachine.006
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.006
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x32
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.RunRequestCounter:1
TEST.END

-- Test Case: EcuM_StateMachine.007
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.007
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x33
TEST.END

-- Test Case: EcuM_StateMachine.008
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.008
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x33
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.RunRequestCounter:1
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.PostRunRequestCounter:1
TEST.END

-- Test Case: EcuM_StateMachine.009
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.009
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x33
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.PostRunRequestCounter:1
TEST.END

-- Test Case: EcuM_StateMachine.010
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.010
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x44
TEST.END

-- Test Case: EcuM_StateMachine.011
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.011
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x44
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.CurrentShutdownTarget:0x50
TEST.END

-- Test Case: EcuM_StateMachine.012
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.012
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x49
TEST.END

-- Test Case: EcuM_StateMachine.013
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.013
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ValidatedWakeups:1
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x49
TEST.END

-- Test Case: EcuM_StateMachine.014
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.014
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x50
TEST.END

-- Test Case: EcuM_StateMachine.015
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.015
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x50
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.CurrentShutdownTarget:0x50
TEST.END

-- Test Case: EcuM_StateMachine.016
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.016
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x22
TEST.END

-- Test Case: EcuM_StateMachine.017
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.017
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ValidatedWakeups:0
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.PostedWakeups:1
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x22
TEST.END

-- Test Case: EcuM_StateMachine.018
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.018
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x23
TEST.END

-- Test Case: EcuM_StateMachine.019
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.019
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ValidatedWakeups:1
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x23
TEST.END

-- Test Case: EcuM_StateMachine.020
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.020
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x25
TEST.END

-- Test Case: EcuM_StateMachine.021
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.021
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x25
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.CurrentShutdownTarget:0x50
TEST.END

-- Test Case: EcuM_StateMachine.022
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.022
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x4D
TEST.END

-- Test Case: EcuM_StateMachine.023
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.023
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_WaitOnNvMWriteAll
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x49
TEST.VALUE:EcuM.EcuM_WaitOnNvMWriteAll.return:1
TEST.END

-- Test Case: EcuM_StateMachine.024
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.024
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_WaitOnNvMCancelWriteAll
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x23
TEST.VALUE:EcuM.EcuM_WaitOnNvMCancelWriteAll.return:1
TEST.END

-- Test Case: EcuM_StateMachine.025
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.025
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_EnterRunState
TEST.STUB:EcuM.EcuM_WaitOnNvMCancelWriteAll
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ValidatedWakeups:128
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x23
TEST.VALUE:EcuM.EcuM_WaitOnNvMCancelWriteAll.return:1
TEST.END

-- Test Case: EcuM_StateMachine.026
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_StateMachine
TEST.NEW
TEST.NAME:EcuM_StateMachine.026
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_WaitOnNvMWriteAll
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0x4D
TEST.VALUE:EcuM.EcuM_WaitOnNvMWriteAll.return:1
TEST.END

-- Subprogram: EcuM_ValidateWakeupEvent

-- Test Case: EcuM_ValidateWakeupEvent.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_ValidateWakeupEvent
TEST.NEW
TEST.NAME:EcuM_ValidateWakeupEvent.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_ValidateWakeupEvent.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_ValidateWakeupEvent
TEST.NEW
TEST.NAME:EcuM_ValidateWakeupEvent.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_InternalCheckWakupMaskValidity
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.return:8
TEST.END

-- Test Case: EcuM_ValidateWakeupEvent.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_ValidateWakeupEvent
TEST.NEW
TEST.NAME:EcuM_ValidateWakeupEvent.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_ValidateWakeupEvent.004
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_ValidateWakeupEvent
TEST.NEW
TEST.NAME:EcuM_ValidateWakeupEvent.004
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.STUB:EcuM.EcuM_InternalCheckWakupMaskValidity
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_WakeupSourceList[6].Channel:255
TEST.VALUE:EcuM.EcuM_InternalCheckWakupMaskValidity.return:6
TEST.END

-- Test Case: EcuM_ValidateWakeupEvent.005
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_ValidateWakeupEvent
TEST.NEW
TEST.NAME:EcuM_ValidateWakeupEvent.005
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.ModuleState:0xFF
TEST.END

-- Subprogram: EcuM_WaitOnNvMCancelWriteAll

-- Test Case: EcuM_WaitOnNvMCancelWriteAll.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMCancelWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMCancelWriteAll.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_WaitOnNvMCancelWriteAll.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMCancelWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMCancelWriteAll.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:2
TEST.END

-- Test Case: EcuM_WaitOnNvMCancelWriteAll.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMCancelWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMCancelWriteAll.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:3
TEST.END

-- Test Case: EcuM_WaitOnNvMCancelWriteAll.004
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMCancelWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMCancelWriteAll.004
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:3
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMJobResult:1
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMCbkNotified:1
TEST.END

-- Test Case: EcuM_WaitOnNvMCancelWriteAll.005
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMCancelWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMCancelWriteAll.005
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.Timer:1
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:3
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMJobResult:0
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMCbkNotified:0
TEST.END

-- Test Case: EcuM_WaitOnNvMCancelWriteAll.006
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMCancelWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMCancelWriteAll.006
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:5
TEST.END

-- Subprogram: EcuM_WaitOnNvMWriteAll

-- Test Case: EcuM_WaitOnNvMWriteAll.001
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMWriteAll.001
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.END

-- Test Case: EcuM_WaitOnNvMWriteAll.002
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMWriteAll.002
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:2
TEST.END

-- Test Case: EcuM_WaitOnNvMWriteAll.003
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMWriteAll.003
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:1
TEST.END

-- Test Case: EcuM_WaitOnNvMWriteAll.004
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMWriteAll.004
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:2
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMCbkNotified:1
TEST.END

-- Test Case: EcuM_WaitOnNvMWriteAll.005
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMWriteAll.005
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.Timer:1
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:2
TEST.END

-- Test Case: EcuM_WaitOnNvMWriteAll.006
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMWriteAll.006
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:4
TEST.END

-- Test Case: EcuM_WaitOnNvMWriteAll.007
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMWriteAll.007
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:4
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMJobResult:1
TEST.END

-- Test Case: EcuM_WaitOnNvMWriteAll.008
TEST.UNIT:EcuM
TEST.SUBPROGRAM:EcuM_WaitOnNvMWriteAll
TEST.NEW
TEST.NAME:EcuM_WaitOnNvMWriteAll.008
TEST.NOTES:
SoftwareArchitecture::SYS::ECUM::EcuM_Detailed_Design::EcuM Class Diagram
Requirement_DICVA-7403
TEST.END_NOTES:
TEST.VALUE:EcuM.<<GLOBAL>>.EcuM_InternalParam.NvMWriteAllStatus:7
TEST.END
