-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLSYS
-- Unit(s) Under Test: UclSys_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclSys_Impl

-- Subprogram: UclSys_Impl_IUclSys_Initialize

-- Test Case: UclSys_Impl_IUclSys_Initialize.OsInit_fail_UCL_E_NOK
TEST.UNIT:UclSys_Impl
TEST.SUBPROGRAM:UclSys_Impl_IUclSys_Initialize
TEST.NEW
TEST.NAME:UclSys_Impl_IUclSys_Initialize.OsInit_fail_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclILSched_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILRouter_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.pInst
<<UclSys_Impl.UclSys_Impl_IUclSys_Initialize.pInst>> = &UclSysInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSys_Impl_IUclSys_Initialize.RouterInit_fail_UCL_E_NOK
TEST.UNIT:UclSys_Impl
TEST.SUBPROGRAM:UclSys_Impl_IUclSys_Initialize
TEST.NEW
TEST.NAME:UclSys_Impl_IUclSys_Initialize.RouterInit_fail_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILSched_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILRouter_Initialize.return:UCL_E_NOK
TEST.EXPECTED:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.pInst
<<UclSys_Impl.UclSys_Impl_IUclSys_Initialize.pInst>> = &UclSysInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSys_Impl_IUclSys_Initialize.return_UCL_E_OK
TEST.UNIT:UclSys_Impl
TEST.SUBPROGRAM:UclSys_Impl_IUclSys_Initialize
TEST.NEW
TEST.NAME:UclSys_Impl_IUclSys_Initialize.return_UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILSched_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILRouter_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.pInst
<<UclSys_Impl.UclSys_Impl_IUclSys_Initialize.pInst>> = &UclSysInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSys_Impl_IUclSys_Initialize.shedInit_fail_UCL_E_NOK
TEST.UNIT:UclSys_Impl
TEST.SUBPROGRAM:UclSys_Impl_IUclSys_Initialize
TEST.NEW
TEST.NAME:UclSys_Impl_IUclSys_Initialize.shedInit_fail_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILSched_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclILRouter_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclSys_Impl.UclSys_Impl_IUclSys_Initialize.pInst
<<UclSys_Impl.UclSys_Impl_IUclSys_Initialize.pInst>> = &UclSysInst_0;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclSys_Impl_IUclSys_Send

-- Test Case: UclSys_Impl_IUclSys_Send.return_UCL_E_NOT_SUPPORTED
TEST.UNIT:UclSys_Impl
TEST.SUBPROGRAM:UclSys_Impl_IUclSys_Send
TEST.NEW
TEST.NAME:UclSys_Impl_IUclSys_Send.return_UCL_E_NOT_SUPPORTED
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSys_Impl.UclSys_Impl_IUclSys_Send.return:UCL_E_NOT_SUPPORTED
TEST.EXPECTED:UclSys_Impl.UclSys_Impl_IUclSys_Send.return:UCL_E_NOT_SUPPORTED
TEST.END

-- Subprogram: UclSys_Impl_IUclSys_Shutdown

-- Test Case: UclSys_Impl_IUclSys_Shutdown.Os_shutdown_fail_UCL_E_NOK
TEST.UNIT:UclSys_Impl
TEST.SUBPROGRAM:UclSys_Impl_IUclSys_Shutdown
TEST.NEW
TEST.NAME:UclSys_Impl_IUclSys_Shutdown.Os_shutdown_fail_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSys_Impl.<<GLOBAL>>.UclSysInst_0.UclSysState:1
TEST.VALUE:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_Shutdown.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclILSched_Shutdown.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILRouter_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.pInst
<<UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSys_Impl_IUclSys_Shutdown.Rout_shutdown_fail_UCL_E_NOK
TEST.UNIT:UclSys_Impl
TEST.SUBPROGRAM:UclSys_Impl_IUclSys_Shutdown
TEST.NEW
TEST.NAME:UclSys_Impl_IUclSys_Shutdown.Rout_shutdown_fail_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSys_Impl.<<GLOBAL>>.UclSysInst_0.UclSysState:1
TEST.VALUE:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_Shutdown.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILSched_Shutdown.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILRouter_Shutdown.return:UCL_E_NOK
TEST.EXPECTED:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.pInst
<<UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSys_Impl_IUclSys_Shutdown.Shed_shutdown_fail_UCL_E_NOK
TEST.UNIT:UclSys_Impl
TEST.SUBPROGRAM:UclSys_Impl_IUclSys_Shutdown
TEST.NEW
TEST.NAME:UclSys_Impl_IUclSys_Shutdown.Shed_shutdown_fail_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSys_Impl.<<GLOBAL>>.UclSysInst_0.UclSysState:1
TEST.VALUE:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_Shutdown.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILSched_Shutdown.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclILRouter_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.pInst
<<UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSys_Impl_IUclSys_Shutdown.return_UCL_E_NOK
TEST.UNIT:UclSys_Impl
TEST.SUBPROGRAM:UclSys_Impl_IUclSys_Shutdown
TEST.NEW
TEST.NAME:UclSys_Impl_IUclSys_Shutdown.return_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSys_Impl.<<GLOBAL>>.UclSysInst_0.UclSysState:0
TEST.VALUE:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_Shutdown.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILSched_Shutdown.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILRouter_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.pInst
<<UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSys_Impl_IUclSys_Shutdown.return_UCL_E_OK
TEST.UNIT:UclSys_Impl
TEST.SUBPROGRAM:UclSys_Impl_IUclSys_Shutdown
TEST.NEW
TEST.NAME:UclSys_Impl_IUclSys_Shutdown.return_UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSys_Impl.<<GLOBAL>>.UclSysInst_0.UclSysState:1
TEST.VALUE:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_Shutdown.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILSched_Shutdown.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclILRouter_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.pInst
<<UclSys_Impl.UclSys_Impl_IUclSys_Shutdown.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclSys_Impl_IUclSys_Task

-- Test Case: UclSys_Impl_IUclSys_Task.return_UCL_E_OK
TEST.UNIT:UclSys_Impl
TEST.SUBPROGRAM:UclSys_Impl_IUclSys_Task
TEST.NEW
TEST.NAME:UclSys_Impl_IUclSys_Task.return_UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSys_Impl.UclSys_Impl_IUclSys_Task.return:UCL_E_OK
TEST.EXPECTED:UclSys_Impl.UclSys_Impl_IUclSys_Task.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclSys_Impl.UclSys_Impl_IUclSys_Task.pInst
<<UclSys_Impl.UclSys_Impl_IUclSys_Task.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
