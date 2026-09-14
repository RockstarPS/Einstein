-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_ERROR_VCAST_HT
-- Unit(s) Under Test: OsError
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: OsError

-- Subprogram: OsCheckIntDisEnPair

-- Test Case: OsCheckIntDisEnPair.001
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsCheckIntDisEnPair
TEST.NEW
TEST.NAME:OsCheckIntDisEnPair.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.END

-- Subprogram: OsErr_GetServiceId

-- Test Case: OsErr_GetServiceId.001
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsErr_GetServiceId
TEST.NEW
TEST.NAME:OsErr_GetServiceId.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.END

-- Subprogram: OsErr_InvalidSvcCallHook

-- Test Case: OsErr_InvalidSvcCallHook.001
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsErr_InvalidSvcCallHook
TEST.NEW
TEST.NAME:OsErr_InvalidSvcCallHook.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.osShutdownOS.Error:0
TEST.END

-- Subprogram: OsErr_LogExtendedStatus

-- Test Case: OsErr_LogExtendedStatus.001
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsErr_LogExtendedStatus
TEST.NEW
TEST.NAME:OsErr_LogExtendedStatus.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.VALUE:OsError.OsErr_LogExtendedStatus.Status:1
TEST.VALUE_USER_CODE:OsError.OsErr_LogExtendedStatus.pStatus.pStatus
<<OsError.OsErr_LogExtendedStatus.pStatus>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: OsErr_LogExtendedStatus.002
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsErr_LogExtendedStatus
TEST.NEW
TEST.NAME:OsErr_LogExtendedStatus.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.VALUE:OsError.OsErr_LogExtendedStatus.pStatus:<<malloc 51>>
TEST.VALUE:OsError.OsErr_LogExtendedStatus.pStatus:"&<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>"
TEST.VALUE:OsError.OsErr_LogExtendedStatus.Status:1
TEST.END

-- Subprogram: OsErr_SetErrServiceInfo

-- Test Case: OsErr_SetErrServiceInfo.001
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsErr_SetErrServiceInfo
TEST.NEW
TEST.NAME:OsErr_SetErrServiceInfo.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.END

-- Subprogram: OsErr_osApplicationErrorHook

-- Test Case: OsErr_osApplicationErrorHook.001
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsErr_osApplicationErrorHook
TEST.NEW
TEST.NAME:OsErr_osApplicationErrorHook.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.VALUE:OsError.OsErr_osApplicationErrorHook.ServiceId:1
TEST.VALUE:OsError.OsErr_osApplicationErrorHook.pStatus:<<malloc 2>>
TEST.VALUE:OsError.OsErr_osApplicationErrorHook.pStatus:"1"
TEST.VALUE:OsError.OsErr_osApplicationErrorHook.Status:1
TEST.END

-- Test Case: OsErr_osApplicationErrorHook.002
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsErr_osApplicationErrorHook
TEST.NEW
TEST.NAME:OsErr_osApplicationErrorHook.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.VALUE:OsError.OsErr_osApplicationErrorHook.ServiceId:1
TEST.VALUE:OsError.OsErr_osApplicationErrorHook.Status:1
TEST.VALUE_USER_CODE:OsError.OsErr_osApplicationErrorHook.pStatus
<<OsError.OsErr_osApplicationErrorHook.pStatus>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: OsErr_osFatalErrorHook

-- Test Case: OsErr_osFatalErrorHook.001
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsErr_osFatalErrorHook
TEST.NEW
TEST.NAME:OsErr_osFatalErrorHook.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.VALUE:OsError.OsErr_osFatalErrorHook.ServiceId:1
TEST.VALUE:OsError.OsErr_osFatalErrorHook.Status:1
TEST.VALUE_USER_CODE:OsError.OsErr_osFatalErrorHook.pStatus
<<OsError.OsErr_osFatalErrorHook.pStatus>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: OsErr_osFatalErrorHook.002
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsErr_osFatalErrorHook
TEST.NEW
TEST.NAME:OsErr_osFatalErrorHook.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.VALUE:OsError.OsErr_osFatalErrorHook.ServiceId:1
TEST.VALUE:OsError.OsErr_osFatalErrorHook.pStatus:<<malloc 51>>
TEST.VALUE:OsError.OsErr_osFatalErrorHook.pStatus:"&<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>>"
TEST.VALUE:OsError.OsErr_osFatalErrorHook.Status:1
TEST.END

-- Subprogram: OsErr_osProtectionHook

-- Test Case: OsErr_osProtectionHook.001
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsErr_osProtectionHook
TEST.NEW
TEST.NAME:OsErr_osProtectionHook.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.END

-- Test Case: OsErr_osProtectionHook.002
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsErr_osProtectionHook
TEST.NEW
TEST.NAME:OsErr_osProtectionHook.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.END

-- Subprogram: OsError_InitMemory

-- Test Case: OsError_InitMemory.001
TEST.UNIT:OsError
TEST.SUBPROGRAM:OsError_InitMemory
TEST.NEW
TEST.NAME:OsError_InitMemory.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.END

-- Subprogram: osMissingTerminateError

-- Test Case: osMissingTerminateError.001
TEST.UNIT:OsError
TEST.SUBPROGRAM:osMissingTerminateError
TEST.NEW
TEST.NAME:osMissingTerminateError.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.STUB:OsError.OsErr_osFatalErrorHook
TEST.END

-- Subprogram: osSysErrAssert

-- Test Case: osSysErrAssert.001
TEST.UNIT:OsError
TEST.SUBPROGRAM:osSysErrAssert
TEST.NEW
TEST.NAME:osSysErrAssert.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7588
TEST.END_NOTES:
TEST.STUB:OsError.OsErr_osApplicationErrorHook
TEST.END
