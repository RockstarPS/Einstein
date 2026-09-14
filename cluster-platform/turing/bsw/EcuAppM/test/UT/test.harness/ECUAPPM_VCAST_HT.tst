-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : ECUAPPM_VCAST_HT
-- Unit(s) Under Test: EcuAppM EcuAppM_CmdProcessing EcuAppM_Errorhandler
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: EcuAppM

-- Subprogram: EcuAppM_ClearWakeupSources

-- Test Case: EcuAppM_ClearWakeupSources.EcuAppM_InitStatus!=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_ClearWakeupSources
TEST.NEW
TEST.NAME:EcuAppM_ClearWakeupSources.EcuAppM_InitStatus!=1
TEST.END

-- Test Case: EcuAppM_ClearWakeupSources.EcuAppM_InitStatus=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_ClearWakeupSources
TEST.NEW
TEST.NAME:EcuAppM_ClearWakeupSources.EcuAppM_InitStatus=1
TEST.VALUE:EcuAppM.<<GLOBAL>>.EcuAppM_InitStatus:1
TEST.END

-- Subprogram: EcuAppM_GetApplicationSleepStatus

-- Test Case: EcuAppM_GetApplicationSleepStatus.EcuAppM_InitStatus!=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_GetApplicationSleepStatus
TEST.NEW
TEST.NAME:EcuAppM_GetApplicationSleepStatus.EcuAppM_InitStatus!=1
TEST.EXPECTED:EcuAppM.EcuAppM_GetApplicationSleepStatus.return:1
TEST.END

-- Test Case: EcuAppM_GetApplicationSleepStatus.EcuAppM_InitStatus=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_GetApplicationSleepStatus
TEST.NEW
TEST.NAME:EcuAppM_GetApplicationSleepStatus.EcuAppM_InitStatus=1
TEST.VALUE:EcuAppM.<<GLOBAL>>.EcuAppM_InitStatus:1
TEST.EXPECTED:EcuAppM.EcuAppM_GetApplicationSleepStatus.return:0
TEST.END

-- Subprogram: EcuAppM_GetWakeupEventStatus

-- Test Case: EcuAppM_GetWakeupEventStatus.EcuAppM_InitStatus!=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_GetWakeupEventStatus
TEST.NEW
TEST.NAME:EcuAppM_GetWakeupEventStatus.EcuAppM_InitStatus!=1
TEST.EXPECTED:EcuAppM.EcuAppM_GetWakeupEventStatus.return:0
TEST.END

-- Test Case: EcuAppM_GetWakeupEventStatus.EcuAppM_InitStatus=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_GetWakeupEventStatus
TEST.NEW
TEST.NAME:EcuAppM_GetWakeupEventStatus.EcuAppM_InitStatus=1
TEST.VALUE:EcuAppM.<<GLOBAL>>.EcuAppM_InitStatus:1
TEST.EXPECTED:EcuAppM.EcuAppM_GetWakeupEventStatus.return:0
TEST.END

-- Subprogram: EcuAppM_GetWakeupSources

-- Test Case: EcuAppM_GetWakeupSources.EcuAppM_InitStatus!=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_GetWakeupSources
TEST.NEW
TEST.NAME:EcuAppM_GetWakeupSources.EcuAppM_InitStatus!=1
TEST.END

-- Subprogram: EcuAppM_Init

-- Test Case: EcuAppM_Init.EcuAppM_InitStatus!=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_Init
TEST.NEW
TEST.NAME:EcuAppM_Init.EcuAppM_InitStatus!=1
TEST.END

-- Test Case: EcuAppM_Init.EcuAppM_InitStatus=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_Init
TEST.NEW
TEST.NAME:EcuAppM_Init.EcuAppM_InitStatus=1
TEST.VALUE:EcuAppM.<<GLOBAL>>.EcuAppM_InitStatus:1
TEST.END

-- Subprogram: EcuAppM_MainFunction

-- Test Case: EcuAppM_MainFunction.EcuAppM_InitStatus!=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_MainFunction
TEST.NEW
TEST.NAME:EcuAppM_MainFunction.EcuAppM_InitStatus!=1
TEST.END

-- Test Case: EcuAppM_MainFunction.EcuAppM_InitStatus=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_MainFunction
TEST.NEW
TEST.NAME:EcuAppM_MainFunction.EcuAppM_InitStatus=1
TEST.VALUE:EcuAppM.<<GLOBAL>>.EcuAppM_InitStatus:1
TEST.END

-- Subprogram: EcuAppM_SetEcuAppMState

-- Test Case: EcuAppM_SetEcuAppMState.EcuAppM_InitStatus!=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_SetEcuAppMState
TEST.NEW
TEST.NAME:EcuAppM_SetEcuAppMState.EcuAppM_InitStatus!=1
TEST.END

-- Test Case: EcuAppM_SetEcuAppMState.EcuAppM_InitStatus=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_SetEcuAppMState
TEST.NEW
TEST.NAME:EcuAppM_SetEcuAppMState.EcuAppM_InitStatus=1
TEST.VALUE:EcuAppM.<<GLOBAL>>.EcuAppM_InitStatus:1
TEST.END

-- Subprogram: EcuAppM_SetWakeupSources

-- Test Case: EcuAppM_SetWakeupSources.EcuAppM_InitStatus!=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_SetWakeupSources
TEST.NEW
TEST.NAME:EcuAppM_SetWakeupSources.EcuAppM_InitStatus!=1
TEST.END

-- Test Case: EcuAppM_SetWakeupSources.EcuAppM_InitStatus=1
TEST.UNIT:EcuAppM
TEST.SUBPROGRAM:EcuAppM_SetWakeupSources
TEST.NEW
TEST.NAME:EcuAppM_SetWakeupSources.EcuAppM_InitStatus=1
TEST.VALUE:EcuAppM.<<GLOBAL>>.EcuAppM_InitStatus:1
TEST.END

-- Unit: EcuAppM_CmdProcessing

-- Subprogram: EcuAppM_DispatchSafeGroupStateChangeRequest

-- Test Case: EcuAppM_DispatchSafeGroupStateChangeRequest.001
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_DispatchSafeGroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_DispatchSafeGroupStateChangeRequest.001
TEST.END

-- Subprogram: EcuAppM_GroupStateChangeRequest

-- Test Case: EcuAppM_GroupStateChangeRequest.GrpCmd=eGroup_StateActivation
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.GrpCmd=eGroup_StateActivation
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateActivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.GrpCmd=eGroup_StateDeActivation
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.GrpCmd=eGroup_StateDeActivation
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateDeactivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.GrpCmd=eGroup_StateInit
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.GrpCmd=eGroup_StateInit
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateInit
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SA.CmpStatus!=1
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SA.CmpStatus!=1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0][0].CmpStatus:1
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateActivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SA.CmpStatus=1
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SA.CmpStatus=1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateActivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SA.CmpStatus=1.001
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SA.CmpStatus=1.001
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0][0].CmpStatus:2
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateActivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SA.Group>6
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SA.Group>6
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.Groupid:6
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateActivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:0
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SA.pCmpLifeCycleMgrApi!=0
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SA.pCmpLifeCycleMgrApi!=0
TEST.VALUE:uut_prototype_stubs.funtest.return:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0][0].CmpStatus:1
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateActivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:3
TEST.VALUE_USER_CODE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList.EcuAppM_GroupContainerList[0].pCmpContainerList.pCmpContainerList[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi
<<EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList>>[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi = &funtest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SA.pCmpLifeCycleMgrApi=E_OK
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SA.pCmpLifeCycleMgrApi=E_OK
TEST.VALUE:uut_prototype_stubs.funtest.return:0
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0][0].CmpStatus:1
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateActivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.VALUE_USER_CODE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList.EcuAppM_GroupContainerList[0].pCmpContainerList.pCmpContainerList[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi
<<EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList>>[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi = &funtest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SD.CmpStatus!=2
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SD.CmpStatus!=2
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0][0].CmpStatus:1
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateDeactivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SD.CmpStatus=2
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SD.CmpStatus=2
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0][0].CmpStatus:2
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateDeactivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SD.Group!=0
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SD.Group!=0
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0][0].CmpStatus:2
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.Groupid:1
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateDeactivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SD.Group>6
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SD.Group>6
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0][0].CmpStatus:2
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.Groupid:6
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateDeactivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:0
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SD.pCmpLifeCycleMgrApi!=0
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SD.pCmpLifeCycleMgrApi!=0
TEST.VALUE:uut_prototype_stubs.funtest.return:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0][0].CmpStatus:2
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateDeactivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:3
TEST.VALUE_USER_CODE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList.EcuAppM_GroupContainerList[0].pCmpContainerList.pCmpContainerList[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi
<<EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList>>[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi = &funtest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SD.pCmpLifeCycleMgrApi=E_OK
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SD.pCmpLifeCycleMgrApi=E_OK
TEST.VALUE:uut_prototype_stubs.funtest.return:0
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0][0].CmpStatus:2
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateDeactivation
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.VALUE_USER_CODE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList.EcuAppM_GroupContainerList[0].pCmpContainerList.pCmpContainerList[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi
<<EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList>>[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi = &funtest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SI.CmpStatus!=0
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SI.CmpStatus!=0
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0][0].CmpStatus:1
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateInit
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SI.CmpStatus=0
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SI.CmpStatus=0
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateInit
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SI.Group>6
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SI.Group>6
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.Groupid:6
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateInit
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:0
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SI.pCmpLifeCycleMgrApi!=0
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SI.pCmpLifeCycleMgrApi!=0
TEST.VALUE:uut_prototype_stubs.funtest.return:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateInit
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:3
TEST.VALUE_USER_CODE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList.EcuAppM_GroupContainerList[0].pCmpContainerList.pCmpContainerList[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi
<<EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList>>[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi = &funtest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest.SI.pCmpLifeCycleMgrApi=E_OK
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest.SI.pCmpLifeCycleMgrApi=E_OK
TEST.VALUE:uut_prototype_stubs.funtest.return:0
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].NumOfComponents:1
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList[0].pCmpContainerList[0]:<<malloc 1>>
TEST.VALUE:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.GroupCmd:eGroup_StateInit
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:2
TEST.VALUE_USER_CODE:EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList.EcuAppM_GroupContainerList[0].pCmpContainerList.pCmpContainerList[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi
<<EcuAppM_CmdProcessing.<<GLOBAL>>.EcuAppM_GroupContainerList>>[0].pCmpContainerList[0][0].pCmpLifeCycleMgrApi = &funtest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuAppM_GroupStateChangeRequest=True
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequest
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequest=True
TEST.EXPECTED:EcuAppM_CmdProcessing.EcuAppM_GroupStateChangeRequest.return:0
TEST.END

-- Subprogram: EcuAppM_GroupStateChangeRequestProcessing

-- Test Case: EcuAppM_GroupStateChangeRequestProcessing.001
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_GroupStateChangeRequestProcessing
TEST.NEW
TEST.NAME:EcuAppM_GroupStateChangeRequestProcessing.001
TEST.END

-- Subprogram: EcuAppM_SafeGroupStateChangeRequestProcessing

-- Test Case: EcuAppM_SafeGroupStateChangeRequestProcessing.001
TEST.UNIT:EcuAppM_CmdProcessing
TEST.SUBPROGRAM:EcuAppM_SafeGroupStateChangeRequestProcessing
TEST.NEW
TEST.NAME:EcuAppM_SafeGroupStateChangeRequestProcessing.001
TEST.END

-- Unit: EcuAppM_Errorhandler

-- Subprogram: EcuAppM_ReportError

-- Test Case: EcuAppM_ReportError=True
TEST.UNIT:EcuAppM_Errorhandler
TEST.SUBPROGRAM:EcuAppM_ReportError
TEST.NEW
TEST.NAME:EcuAppM_ReportError=True
TEST.END
