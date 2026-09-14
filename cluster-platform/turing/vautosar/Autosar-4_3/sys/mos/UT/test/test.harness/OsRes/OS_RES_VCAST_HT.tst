-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_RES_VCAST_HT
-- Unit(s) Under Test: OsRes
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: OsRes

-- Subprogram: OsRes_InitMemory

-- Test Case: OsRes_InitMemory.001
TEST.UNIT:OsRes
TEST.SUBPROGRAM:OsRes_InitMemory
TEST.NEW
TEST.NAME:OsRes_InitMemory.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.END

-- Subprogram: osGetResource

-- Test Case: osGetResource.001
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osGetResource
TEST.NEW
TEST.NAME:osGetResource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].ResId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:OsRes.osGetResource.Res:0
TEST.END

-- Test Case: osGetResource.002
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osGetResource
TEST.NEW
TEST.NAME:osGetResource.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].ResId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0][0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].NumofpAppRef:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AccessId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:OsRes.osGetResource.Res:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osGetResource.003
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osGetResource
TEST.NEW
TEST.NAME:osGetResource.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:2
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].ResId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0][0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].NumofpAppRef:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AccessId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:OsRes.osGetResource.Res:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osGetResource.004
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osGetResource
TEST.NEW
TEST.NAME:osGetResource.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:2
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].ResId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0][0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].NumofpAppRef:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AccessId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:OsRes.osGetResource.Res:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osGetResource.006
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osGetResource
TEST.NEW
TEST.NAME:osGetResource.006
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.osGetResource.Res:3
TEST.END

-- Test Case: osGetResource.009
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osGetResource
TEST.NEW
TEST.NAME:osGetResource.009
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.IntSaveGlobal:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:OsRes.osGetResource.Res:15
TEST.VALUE:OsRes.osGetResource.return:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osGetResource.014
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osGetResource
TEST.NEW
TEST.NAME:osGetResource.014
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].ResId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0][0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].NumofpAppRef:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AccessId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:OsRes.osGetResource.Res:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Subprogram: osReleaseResource

-- Test Case: osReleaseResource.001
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osReleaseResource
TEST.NEW
TEST.NAME:osReleaseResource.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:OsRes.osReleaseResource.Res:1
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:0
TEST.END

-- Test Case: osReleaseResource.002
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osReleaseResource
TEST.NEW
TEST.NAME:osReleaseResource.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].ResId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0][0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].NumofpAppRef:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:OsRes.osReleaseResource.Res:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:0
TEST.END

-- Test Case: osReleaseResource.003
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osReleaseResource
TEST.NEW
TEST.NAME:osReleaseResource.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].ResId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0][0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].NumofpAppRef:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.RequestScheduler:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.LockDispatcher:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:OsRes.osReleaseResource.Res:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osReleaseResource.004
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osReleaseResource
TEST.NEW
TEST.NAME:osReleaseResource.004
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].ResId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0][0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].NumofpAppRef:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.RequestScheduler:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.LockDispatcher:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:OsRes.osReleaseResource.Res:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Test Case: osReleaseResource.005
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osReleaseResource
TEST.NEW
TEST.NAME:osReleaseResource.005
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7597
TEST.END_NOTES:
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].ResId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0][0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].NumofpAppRef:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.RequestScheduler:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.LockDispatcher:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:OsRes.osReleaseResource.Res:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END

-- Subprogram: osSysReleaseResource

-- Test Case: osSysReleaseResource.001
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osSysReleaseResource
TEST.NEW
TEST.NAME:osSysReleaseResource.001
TEST.VALUE:OsRes.osSysReleaseResource.Res:2
TEST.END

-- Test Case: osSysReleaseResource.002
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osSysReleaseResource
TEST.NEW
TEST.NAME:osSysReleaseResource.002
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0][0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].NumofpAppRef:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:0
TEST.VALUE:OsRes.osSysReleaseResource.Res:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:0
TEST.END

-- Test Case: osSysReleaseResource.003
TEST.UNIT:OsRes
TEST.SUBPROGRAM:osSysReleaseResource
TEST.NEW
TEST.NAME:osSysReleaseResource.003
TEST.VALUE:OsRes.<<GLOBAL>>.OsResOccupationCtr[0]:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0]:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].pAppRef[0][0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsResRefConfig[0][0].NumofpAppRef:1
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef:<<malloc 1>>
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.pActiveObjRef[0].pAppRef[0].AppId:0
TEST.VALUE:OsRes.<<GLOBAL>>.OsCtrlParam.CurrentContext:1
TEST.VALUE:OsRes.osSysReleaseResource.Res:0
TEST.VALUE:uut_prototype_stubs.osCheckInterruptsEnabled.return:1
TEST.END
