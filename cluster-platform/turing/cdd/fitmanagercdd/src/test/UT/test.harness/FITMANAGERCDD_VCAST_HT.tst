-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : FITMANAGERCDD_VCAST_HT
-- Unit(s) Under Test: CDD_FitManager CDD_FitManager_ErrorHandler
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CDD_FitManager

-- Subprogram: CDD_FitManager_CallFaultInjectionHandler

-- Test Case: CDD_FitManager_CallFaultInjectionHandler.ModuleTestHandler!=0
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_CallFaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_FitManager_CallFaultInjectionHandler.ModuleTestHandler!=0
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.LoopCount:0
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.StartStopData:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.TestListID:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.Data:<<malloc 1>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.Data[0]:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.funtest.return:1
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.return:1
TEST.VALUE_USER_CODE:uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData.CDD_FitManager_ModuleConfigData[0].ModuleTestHandler
<<uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData>>[0].ModuleTestHandler = &funtest ;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr.TestConfigDataPtr[1].TestHandler
<<uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData>>[0].TestConfigDataPtr[1].TestHandler = &funtest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: CDD_FitManager_CallFaultInjectionHandler.ReturnType!=1
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_CallFaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_FitManager_CallFaultInjectionHandler.ReturnType!=1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.LoopCount:0
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.StartStopData:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.TestListID:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.Data:<<malloc 1>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.Data[0]:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.funtest.return:0
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.return:0
TEST.VALUE_USER_CODE:uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData.CDD_FitManager_ModuleConfigData[0].ModuleTestHandler
<<uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData>>[0].ModuleTestHandler = &funtest ;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr.TestConfigDataPtr[1].TestHandler
<<uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData>>[0].TestConfigDataPtr[1].TestHandler = &funtest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: CDD_FitManager_CallFaultInjectionHandler.TestHandler=1
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_CallFaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_FitManager_CallFaultInjectionHandler.TestHandler=1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.LoopCount:0
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.StartStopData:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.TestListID:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.Data:<<malloc 1>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.Data[0]:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr[1].TestHandler:<<value error>>
TEST.VALUE:uut_prototype_stubs.funtest.return:1
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.return:1
TEST.VALUE_USER_CODE:uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData.CDD_FitManager_ModuleConfigData[0].ModuleTestHandler
<<uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData>>[0].ModuleTestHandler = &funtest ;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: CDD_FitManager_CallFaultInjectionHandler.else.TestHandler!=1
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_CallFaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_FitManager_CallFaultInjectionHandler.else.TestHandler!=1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.LoopCount:0
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.StartStopData:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.TestListID:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.Data:<<malloc 1>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.Data[0]:1
TEST.VALUE:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.funtest.return:1
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_CallFaultInjectionHandler.return:1
TEST.VALUE_USER_CODE:uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr.TestConfigDataPtr[1].TestHandler
<<uut_prototype_stubs.<<GLOBAL>>.CDD_FitManager_ModuleConfigData>>[0].TestConfigDataPtr[1].TestHandler = &funtest;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CDD_FitManager_DeInit

-- Test Case: CDD_FitManager_DeInit_basic
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_DeInit
TEST.NEW
TEST.NAME:CDD_FitManager_DeInit_basic
TEST.END

-- Subprogram: CDD_FitManager_HandleFaultInjection

-- Test Case: CDD_FitManager_HandleFaultInjection.Data=FitModuleID
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_HandleFaultInjection
TEST.NEW
TEST.NAME:CDD_FitManager_HandleFaultInjection.Data=FitModuleID
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].FitModuleID:0
TEST.VALUE:CDD_FitManager.CDD_FitManager_HandleFaultInjection.Data:<<malloc 1>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_HandleFaultInjection.Data[0]:0
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_HandleFaultInjection.return:1
TEST.END

-- Test Case: CDD_FitManager_HandleFaultInjection.Data[1]&(0x80)=(0x80)
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_HandleFaultInjection
TEST.NEW
TEST.NAME:CDD_FitManager_HandleFaultInjection.Data[1]&(0x80)=(0x80)
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].FitModuleID:0
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestCount:1
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr:<<malloc 1>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_HandleFaultInjection.Data:<<malloc 2>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_HandleFaultInjection.Data[0]:0
TEST.VALUE:CDD_FitManager.CDD_FitManager_HandleFaultInjection.Data[1]:0x80
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_HandleFaultInjection.return:0
TEST.END

-- Test Case: CDD_FitManager_HandleFaultInjection.FitTestID!=TestIDData
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_HandleFaultInjection
TEST.NEW
TEST.NAME:CDD_FitManager_HandleFaultInjection.FitTestID!=TestIDData
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].FitModuleID:0
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestCount:1
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr:<<malloc 1>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_HandleFaultInjection.Data:<<malloc 1>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_HandleFaultInjection.Data[0]:0
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_HandleFaultInjection.return:1
TEST.END

-- Test Case: CDD_FitManager_HandleFaultInjection.FitTestID=TestIDData
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_HandleFaultInjection
TEST.NEW
TEST.NAME:CDD_FitManager_HandleFaultInjection.FitTestID=TestIDData
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].FitModuleID:0
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestCount:1
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr:<<malloc 1>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_HandleFaultInjection.Data:<<malloc 2>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_HandleFaultInjection.Data[0]:0
TEST.VALUE:CDD_FitManager.CDD_FitManager_HandleFaultInjection.Data[1]:0
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_HandleFaultInjection.return:1
TEST.END

-- Subprogram: CDD_FitManager_Init

-- Test Case: CDD_FitManager_Init_basic
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_Init
TEST.NEW
TEST.NAME:CDD_FitManager_Init_basic
TEST.END

-- Subprogram: CDD_FitManager_MainFunction

-- Test Case: CDD_FitManager_MainFunction_basic
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_MainFunction
TEST.NEW
TEST.NAME:CDD_FitManager_MainFunction_basic
TEST.END

-- Subprogram: CDD_FitManager_NonSupervisorCallFaultInjectionHandler

-- Test Case: CDD_FitManager_NonSupervisorCallFaultInjectionHandler.TestHandler!=0
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_NonSupervisorCallFaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_FitManager_NonSupervisorCallFaultInjectionHandler.TestHandler!=0
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].FitModuleID:0
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestCount:1
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr:<<malloc 1>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_NonSupervisorCallFaultInjectionHandler.Data:<<malloc 2>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_NonSupervisorCallFaultInjectionHandler.Data[0]:0
TEST.VALUE:CDD_FitManager.CDD_FitManager_NonSupervisorCallFaultInjectionHandler.Data[1]:0
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_NonSupervisorCallFaultInjectionHandler.return:1
TEST.END

-- Subprogram: CDD_FitManager_RouteFITDID

-- Test Case: CDD_FitManager_RouteFITDID_data=0
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_RouteFITDID
TEST.NEW
TEST.NAME:CDD_FitManager_RouteFITDID_data=0
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_RouteFITDID.return:1
TEST.END

-- Test Case: CDD_FitManager_RouteFITDID_data=1
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_RouteFITDID
TEST.NEW
TEST.NAME:CDD_FitManager_RouteFITDID_data=1
TEST.VALUE:CDD_FitManager.CDD_FitManager_RouteFITDID.Data:<<malloc 2>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_RouteFITDID.Data:"1"
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_RouteFITDID.return:1
TEST.END

-- Subprogram: CDD_FitManager_SupervisorCallFaultInjectionHandler

-- Test Case: CDD_FitManager_SupervisorCallFaultInjectionHandler=True
TEST.UNIT:CDD_FitManager
TEST.SUBPROGRAM:CDD_FitManager_SupervisorCallFaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_FitManager_SupervisorCallFaultInjectionHandler=True
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].FitModuleID:0
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestCount:1
TEST.VALUE:CDD_FitManager.<<GLOBAL>>.CDD_FitManager_ModuleConfigData[0].TestConfigDataPtr:<<malloc 1>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_SupervisorCallFaultInjectionHandler.Data:<<malloc 2>>
TEST.VALUE:CDD_FitManager.CDD_FitManager_SupervisorCallFaultInjectionHandler.Data[0]:0
TEST.VALUE:CDD_FitManager.CDD_FitManager_SupervisorCallFaultInjectionHandler.Data[1]:0
TEST.EXPECTED:CDD_FitManager.CDD_FitManager_SupervisorCallFaultInjectionHandler.return:1
TEST.END

-- Unit: CDD_FitManager_ErrorHandler

-- Subprogram: CDD_FitManager_ReportError

-- Test Case: CDD_FitManager_ReportError.Basic
TEST.UNIT:CDD_FitManager_ErrorHandler
TEST.SUBPROGRAM:CDD_FitManager_ReportError
TEST.NEW
TEST.NAME:CDD_FitManager_ReportError.Basic
TEST.END
