-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_MEM_PROTECTION_VCAST_HT
-- Unit(s) Under Test: OsMemProtection
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: OsMemProtPrv_AppMpuSwitch

-- Test Case: OsMemProtPrv_AppMpuSwitch.001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtPrv_AppMpuSwitch
TEST.NEW
TEST.NAME:OsMemProtPrv_AppMpuSwitch.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.END

-- Test Case: OsMemProtPrv_AppMpuSwitch.002
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtPrv_AppMpuSwitch
TEST.NEW
TEST.NAME:OsMemProtPrv_AppMpuSwitch.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.OsMemProtPrv_AppMpuSwitch.Prev:1
TEST.VALUE:OsMemProtection.OsMemProtPrv_AppMpuSwitch.Next:0
TEST.END

-- Subprogram: OsMemProtPrv_MpuSwitch

-- Test Case: OsMemProtPrv_MpuSwitch.001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtPrv_MpuSwitch
TEST.NEW
TEST.NAME:OsMemProtPrv_MpuSwitch.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.OsMemProtPrv_MpuSwitch.AccessId:5
TEST.END

-- Test Case: OsMemProtPrv_MpuSwitch.002
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtPrv_MpuSwitch
TEST.NEW
TEST.NAME:OsMemProtPrv_MpuSwitch.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.OsMemProtPrv_MpuSwitch.AccessId:0
TEST.END

-- Test Case: OsMemProtPrv_MpuSwitch.003
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtPrv_MpuSwitch
TEST.NEW
TEST.NAME:OsMemProtPrv_MpuSwitch.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMPUAccessGroupConfig[0].RegionCount:1
TEST.VALUE:OsMemProtection.OsMemProtPrv_MpuSwitch.AccessId:0
TEST.END

-- Subprogram: OsMemProtPrv_MpuSwitchSafeSegments

-- Test Case: OsMemProtPrv_MpuSwitchSafeSegments.001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtPrv_MpuSwitchSafeSegments
TEST.NEW
TEST.NAME:OsMemProtPrv_MpuSwitchSafeSegments.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.OsMemProtPrv_MpuSwitchSafeSegments.Prev:5
TEST.VALUE:OsMemProtection.OsMemProtPrv_MpuSwitchSafeSegments.Next:5
TEST.END

-- Test Case: OsMemProtPrv_MpuSwitchSafeSegments.002
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtPrv_MpuSwitchSafeSegments
TEST.NEW
TEST.NAME:OsMemProtPrv_MpuSwitchSafeSegments.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.OsMemProtPrv_MpuSwitchSafeSegments.Prev:0
TEST.VALUE:OsMemProtection.OsMemProtPrv_MpuSwitchSafeSegments.Next:0
TEST.END

-- Test Case: OsMemProtPrv_MpuSwitchSafeSegments.003
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtPrv_MpuSwitchSafeSegments
TEST.NEW
TEST.NAME:OsMemProtPrv_MpuSwitchSafeSegments.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMpuAccessGroupDiff[0][0].DiffCount:1
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMpuAccessGroupDiff[0][0].DiffRegions:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMpuAccessGroupDiff[0][0].DiffRegions[0]:0
TEST.VALUE:OsMemProtection.OsMemProtPrv_MpuSwitchSafeSegments.Prev:0
TEST.VALUE:OsMemProtection.OsMemProtPrv_MpuSwitchSafeSegments.Next:0
TEST.END

-- Test Case: OsMemProtPrv_MpuSwitchSafeSegments.004
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtPrv_MpuSwitchSafeSegments
TEST.NEW
TEST.NAME:OsMemProtPrv_MpuSwitchSafeSegments.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMpuAccessGroupDiff[0][0].DiffCount:1
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMpuAccessGroupDiff[0][0].DiffRegions:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMpuAccessGroupDiff[0][0].DiffRegions[0]:0
TEST.VALUE:OsMemProtection.OsMemProtPrv_MpuSwitchSafeSegments.Prev:2
TEST.VALUE:OsMemProtection.OsMemProtPrv_MpuSwitchSafeSegments.Next:0
TEST.END

-- Subprogram: OsMemProtPrv_ObjMpuSwitch

-- Test Case: OsMemProtPrv_ObjMpuSwitch.001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtPrv_ObjMpuSwitch
TEST.NEW
TEST.NAME:OsMemProtPrv_ObjMpuSwitch.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.END

-- Subprogram: OsMemProt_ClearOSStateCntr

-- Test Case: OsMemProt_ClearOSStateCntr.001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_ClearOSStateCntr
TEST.NEW
TEST.NAME:OsMemProt_ClearOSStateCntr.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.END

-- Subprogram: OsMemProt_GetAccessRights

-- Test Case: OsMemProt_GetAccessRights.001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_GetAccessRights
TEST.NEW
TEST.NAME:OsMemProt_GetAccessRights.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.END

-- Test Case: OsMemProt_GetAccessRights.002
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_GetAccessRights
TEST.NEW
TEST.NAME:OsMemProt_GetAccessRights.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.OsMemProt_GetAccessRights.Id:2
TEST.EXPECTED:OsMemProtection.OsMemProt_GetAccessRights.Id:2
TEST.END

-- Test Case: OsMemProt_GetAccessRights.003
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_GetAccessRights
TEST.NEW
TEST.NAME:OsMemProt_GetAccessRights.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.OsMemProt_GetAccessRights.Id:5
TEST.EXPECTED:OsMemProtection.OsMemProt_GetAccessRights.Id:5
TEST.END

-- Subprogram: OsMemProt_MpuSwitch

-- Test Case: OsMemProt_MpuSwitch.001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_MpuSwitch
TEST.NEW
TEST.NAME:OsMemProt_MpuSwitch.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.END

-- Test Case: OsMemProt_MpuSwitch.002
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_MpuSwitch
TEST.NEW
TEST.NAME:OsMemProt_MpuSwitch.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].AccessId:1
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].AccessId:0
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].AccessId:1
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].AccessId:0
TEST.END

-- Test Case: OsMemProt_MpuSwitch.003
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_MpuSwitch
TEST.NEW
TEST.NAME:OsMemProt_MpuSwitch.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:2
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].AccessId:1
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].AccessId:1
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:2
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].AccessId:1
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].AccessId:1
TEST.END

-- Test Case: OsMemProt_MpuSwitch.004
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_MpuSwitch
TEST.NEW
TEST.NAME:OsMemProt_MpuSwitch.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.END

-- Subprogram: OsMemProt_MpuSwitchFromISR

-- Test Case: BASIS-PATH-003.001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_MpuSwitchFromISR
TEST.NEW
TEST.NAME:BASIS-PATH-003.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:<<MIN>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsAppRefListDyn[0]:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsAppRefListDyn[0][0].AccessId:0
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef[0].AppId:0
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:0
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsAppRefListDyn[0][0].AccessId:0
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef[0].AppId:0
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_MpuSwitchFromISR
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:<<MIN>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsAppRefListDyn[0]:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef[0].AppId:0
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:0
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef[0].AppId:0
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.END

-- Test Case: OsMemProt_MpuSwitchFromISR.001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_MpuSwitchFromISR
TEST.NEW
TEST.NAME:OsMemProt_MpuSwitchFromISR.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pLastObjRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:2
TEST.END

-- Test Case: OsMemProt_MpuSwitchFromISR.002
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_MpuSwitchFromISR
TEST.NEW
TEST.NAME:OsMemProt_MpuSwitchFromISR.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[1]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[1][0].AppId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[1][0].AccessId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[2]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[2][0].AppId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[2][0].AccessId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pLastObjRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef[0].AppId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:2
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[1][0].AppId:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[1][0].AccessId:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[2][0].AppId:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[2][0].AccessId:2
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pLastObjRef[0].pAppRef[0].AppId:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:2
TEST.END

-- Test Case: OsMemProt_MpuSwitchFromISR.003
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_MpuSwitchFromISR
TEST.NEW
TEST.NAME:OsMemProt_MpuSwitchFromISR.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[1]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[1][0].AppId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[1][0].AccessId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[2]:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[2][0].AppId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[2][0].AccessId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:2
TEST.EXPECTED:OsMemProtection.<<GLOBAL>>.OsMemProt_MPUState:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[1][0].AppId:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[1][0].AccessId:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[2][0].AppId:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.OsAppRefListDyn[2][0].AccessId:2
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:2
TEST.END

-- Subprogram: OsMemProt_MpuSwitchTrustedCall

-- Test Case: OsMemProt_MpuSwitchTrustedCall.001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_MpuSwitchTrustedCall
TEST.NEW
TEST.NAME:OsMemProt_MpuSwitchTrustedCall.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.END

-- Test Case: OsMemProt_MpuSwitchTrustedCall.002
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProt_MpuSwitchTrustedCall
TEST.NEW
TEST.NAME:OsMemProt_MpuSwitchTrustedCall.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.OsMemProt_MpuSwitchTrustedCall.Prev:0
TEST.VALUE:OsMemProtection.OsMemProt_MpuSwitchTrustedCall.Next:1
TEST.EXPECTED:OsMemProtection.OsMemProt_MpuSwitchTrustedCall.Prev:0
TEST.EXPECTED:OsMemProtection.OsMemProt_MpuSwitchTrustedCall.Next:1
TEST.END

-- Subprogram: OsMemProtectPrv_GetCurrentAccessRightsId

-- Test Case: OsMemProtectPrv_GetCurrentAccessRightsId.001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtectPrv_GetCurrentAccessRightsId
TEST.NEW
TEST.NAME:OsMemProtectPrv_GetCurrentAccessRightsId.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.END

-- Test Case: OsMemProtectPrv_GetCurrentAccessRightsId.002
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtectPrv_GetCurrentAccessRightsId
TEST.NEW
TEST.NAME:OsMemProtectPrv_GetCurrentAccessRightsId.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.END

-- Subprogram: OsMemProtect_Init

-- Test Case: BASIS-PATH-001
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtect_Init
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCoreRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsMemProtection.<<GLOBAL>>.OsCoreRefConfig[0][0].pOsCoreObjRef:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.OsCore_GetCurrentCore.return:0
TEST.END

-- Test Case: OsMemProtect_Init.002
TEST.UNIT:OsMemProtection
TEST.SUBPROGRAM:OsMemProtect_Init
TEST.NEW
TEST.NAME:OsMemProtect_Init.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7591
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.OsCore_GetCurrentCore.return:5
TEST.END
