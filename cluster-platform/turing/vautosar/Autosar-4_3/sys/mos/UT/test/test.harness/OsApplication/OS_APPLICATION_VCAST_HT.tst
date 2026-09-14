-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_APPLICATION_VCAST_HT
-- Unit(s) Under Test: OsApplication
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: OsAllowAccess

-- Test Case: OsAllowAccess.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsAllowAccess
TEST.NEW
TEST.NAME:OsAllowAccess.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.END

-- Test Case: OsAllowAccess.002
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsAllowAccess
TEST.NEW
TEST.NAME:OsAllowAccess.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.AppParam.State:0x1
TEST.END

-- Subprogram: OsCheckObjectAccess

-- Test Case: OsCheckObjectAccess.003
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectAccess
TEST.NEW
TEST.NAME:OsCheckObjectAccess.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.STUB:OsApplication.OsPrvGetObjectType
TEST.VALUE:OsApplication.OsPrvGetObjectType.ObjID:0
TEST.VALUE:OsApplication.OsPrvGetObjectType.return:0
TEST.VALUE:OsApplication.OsCheckObjectAccess.AppID:0
TEST.VALUE:OsApplication.OsCheckObjectAccess.ObjType:1
TEST.VALUE:OsApplication.OsCheckObjectAccess.ObjID:0
TEST.END

-- Test Case: OsCheckObjectAccess.004
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectAccess
TEST.NEW
TEST.NAME:OsCheckObjectAccess.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.OsCheckObjectAccess.AppID:4
TEST.VALUE:OsApplication.OsCheckObjectAccess.ObjType:60
TEST.VALUE:OsApplication.OsCheckObjectAccess.ObjID:33
TEST.END

-- Test Case: OsCheckObjectAccess.005
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectAccess
TEST.NEW
TEST.NAME:OsCheckObjectAccess.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.OsCheckObjectAccess.AppID:1
TEST.VALUE:OsApplication.OsCheckObjectAccess.ObjID:86
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].ObjId:86
TEST.END

-- Test Case: OsCheckObjectAccess.006
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectAccess
TEST.NEW
TEST.NAME:OsCheckObjectAccess.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApplication.OsCheckObjectAccess.AppID:0
TEST.VALUE:OsApplication.OsCheckObjectAccess.ObjType:1
TEST.VALUE:OsApplication.OsCheckObjectAccess.ObjID:50
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].ObjId:50
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].ObjType:1
TEST.END

-- Test Case: OsCheckObjectAccess_MAX.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectAccess
TEST.NEW
TEST.NAME:OsCheckObjectAccess_MAX.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:<<ALL_MAX>>
TEST.END

-- Test Case: OsCheckObjectAccess_MID.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectAccess
TEST.NEW
TEST.NAME:OsCheckObjectAccess_MID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:<<ALL_MID>>
TEST.END

-- Test Case: OsCheckObjectAccess_MIN.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectAccess
TEST.NEW
TEST.NAME:OsCheckObjectAccess_MIN.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:<<ALL_MIN>>
TEST.END

-- Test Case: OsCheckObjectAccess_MIN.002
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectAccess
TEST.NEW
TEST.NAME:OsCheckObjectAccess_MIN.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:<<ALL_MIN>>
TEST.END

-- Test Case: OsCheckObjectAccess_MIN.003
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectAccess
TEST.NEW
TEST.NAME:OsCheckObjectAccess_MIN.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:<<ALL_MIN>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsObjRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsObjRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsObjRefConfig[0][0].pAppRef[0].AppId:1
TEST.END

-- Subprogram: OsCheckObjectOwnership

-- Test Case: BASIS-PATH-001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectOwnership
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.OsCheckObjectOwnership.ObjType:<<MIN>>
TEST.VALUE:OsApplication.OsCheckObjectOwnership.ObjID:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectOwnership
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.STUB:OsApplication.OsPrvGetObjectType
TEST.VALUE:OsApplication.OsPrvGetObjectType.return:<<MIN>>
TEST.VALUE:OsApplication.OsCheckObjectOwnership.ObjType:1
TEST.VALUE:OsApplication.OsCheckObjectOwnership.ObjID:<<MIN>>
TEST.END

-- Test Case: OsCheckObjectOwnership.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectOwnership
TEST.NEW
TEST.NAME:OsCheckObjectOwnership.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.OsCheckObjectOwnership.ObjID:Object_ObjectIdMax
TEST.EXPECTED:OsApplication.OsCheckObjectOwnership.return:OS_CFG_APPLICATION_INVALID
TEST.END

-- Test Case: OsCheckObjectOwnership.003
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectOwnership
TEST.NEW
TEST.NAME:OsCheckObjectOwnership.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.STUB:OsApplication.OsPrvGetObjectType
TEST.VALUE:OsApplication.OsPrvGetObjectType.ObjID:3
TEST.VALUE:OsApplication.OsPrvGetObjectType.return:0
TEST.VALUE:OsApplication.OsCheckObjectOwnership.ObjType:3
TEST.VALUE:OsApplication.OsCheckObjectOwnership.ObjID:3
TEST.VALUE:OsApplication.OsCheckObjectOwnership.return:0
TEST.END

-- Test Case: OsCheckObjectOwnership.004
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectOwnership
TEST.NEW
TEST.NAME:OsCheckObjectOwnership.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.STUB:OsApplication.OsPrvGetObjectType
TEST.VALUE:OsApplication.<<GLOBAL>>.OsObjRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsObjRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsObjRefConfig[0][0].pAppRef[0].AppId:0
TEST.VALUE:OsApplication.OsPrvGetObjectType.ObjID:0
TEST.VALUE:OsApplication.OsPrvGetObjectType.return:3
TEST.VALUE:OsApplication.OsCheckObjectOwnership.ObjType:3
TEST.VALUE:OsApplication.OsCheckObjectOwnership.ObjID:0
TEST.END

-- Test Case: OsCheckObjectOwnership_MAX.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectOwnership
TEST.NEW
TEST.NAME:OsCheckObjectOwnership_MAX.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:<<ALL_MAX>>
TEST.END

-- Test Case: OsCheckObjectOwnership_MAX.002
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectOwnership
TEST.NEW
TEST.NAME:OsCheckObjectOwnership_MAX.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:<<ALL_MAX>>
TEST.END

-- Test Case: OsCheckObjectOwnership_MID.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsCheckObjectOwnership
TEST.NEW
TEST.NAME:OsCheckObjectOwnership_MID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:<<ALL_MID>>
TEST.END

-- Subprogram: OsGetAppParam

-- Test Case: OsGetAppParam.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetAppParam
TEST.NEW
TEST.NAME:OsGetAppParam.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.END

-- Test Case: OsGetAppParam.002
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetAppParam
TEST.NEW
TEST.NAME:OsGetAppParam.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.OsGetAppParam.AppId:2
TEST.END

-- Test Case: OsGetAppParam.003
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetAppParam
TEST.NEW
TEST.NAME:OsGetAppParam.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.OsGetAppParam.AppId:5
TEST.END

-- Subprogram: OsGetApplicationId

-- Test Case: OsGetApplicationId.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetApplicationId
TEST.NEW
TEST.NAME:OsGetApplicationId.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.END

-- Subprogram: OsGetApplicationState

-- Test Case: OsGetApplicationState.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetApplicationState
TEST.NEW
TEST.NAME:OsGetApplicationState.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.OsGetApplicationState.Value:<<malloc 1>>
TEST.END

-- Test Case: OsGetApplicationState.002
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetApplicationState
TEST.NEW
TEST.NAME:OsGetApplicationState.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.OsGetApplicationState.Application:3
TEST.VALUE:OsApplication.OsGetApplicationState.Value:<<malloc 1>>
TEST.END

-- Subprogram: OsGetCurrentApplication

-- Test Case: OsGetCurrentApplication.002
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetCurrentApplication
TEST.NEW
TEST.NAME:OsGetCurrentApplication.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:5
TEST.VALUE:OsApplication.OsGetCurrentApplication.return:<<malloc 1>>
TEST.VALUE:OsApplication.OsGetCurrentApplication.return[0].AppId:5
TEST.END

-- Test Case: OsGetCurrentApplication.003
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetCurrentApplication
TEST.NEW
TEST.NAME:OsGetCurrentApplication.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.STUB:OsApplication.OsGetCurrentApplicationID
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:5
TEST.VALUE:OsApplication.OsGetCurrentApplicationID.return:0
TEST.VALUE:OsApplication.OsGetCurrentApplication.return:<<malloc 1>>
TEST.VALUE:OsApplication.OsGetCurrentApplication.return[0].AppId:5
TEST.END

-- Subprogram: OsGetCurrentApplicationID

-- Test Case: OsGetCurrentApplicationID.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetCurrentApplicationID
TEST.NEW
TEST.NAME:OsGetCurrentApplicationID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:2
TEST.END

-- Subprogram: OsGetCurrentObj

-- Test Case: OsGetCurrentObj.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetCurrentObj
TEST.NEW
TEST.NAME:OsGetCurrentObj.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.STUB:OsApplication.OsGetCurrentObjectID
TEST.VALUE:OsApplication.<<GLOBAL>>.OsObjRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].ObjId:0
TEST.VALUE:OsApplication.OsGetCurrentObjectID.return:0
TEST.VALUE:OsApplication.OsGetCurrentObj.return:<<malloc 1>>
TEST.VALUE:OsApplication.OsGetCurrentObj.return[0].ObjId:0
TEST.EXPECTED:OsApplication.OsGetCurrentObj.return[0].ObjId:0
TEST.END

-- Test Case: OsGetCurrentObj.002
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetCurrentObj
TEST.NEW
TEST.NAME:OsGetCurrentObj.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].ObjId:85
TEST.VALUE:OsApplication.OsGetCurrentObj.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].ObjId:85
TEST.END

-- Subprogram: OsGetCurrentObjectID

-- Test Case: OsGetCurrentObjectID.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsGetCurrentObjectID
TEST.NEW
TEST.NAME:OsGetCurrentObjectID.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].ObjId:1
TEST.END

-- Subprogram: OsPrvGetObjectType

-- Test Case: OsPrvGetObjectType.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsPrvGetObjectType
TEST.NEW
TEST.NAME:OsPrvGetObjectType.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.<<GLOBAL>>.OsObjRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsApplication.<<GLOBAL>>.OsObjRefConfig[0][0].ObjType:0
TEST.VALUE:OsApplication.OsPrvGetObjectType.ObjID:0
TEST.END

-- Test Case: OsPrvGetObjectType.002
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsPrvGetObjectType
TEST.NEW
TEST.NAME:OsPrvGetObjectType.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.OsPrvGetObjectType.ObjID:55
TEST.END

-- Test Case: OsPrvGetObjectType.003
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsPrvGetObjectType
TEST.NEW
TEST.NAME:OsPrvGetObjectType.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.VALUE:OsApplication.OsPrvGetObjectType.ObjID:60
TEST.END

-- Subprogram: OsTerminateApplication

-- Test Case: OsTerminateApplication.001
TEST.UNIT:OsApplication
TEST.SUBPROGRAM:OsTerminateApplication
TEST.NEW
TEST.NAME:OsTerminateApplication.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7585
TEST.END_NOTES:
TEST.END
