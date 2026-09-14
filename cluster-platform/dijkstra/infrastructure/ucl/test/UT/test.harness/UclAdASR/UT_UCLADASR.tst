-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLADASR
-- Unit(s) Under Test: UclProxyCdd
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: CUclProxyCdd_Impl_GetStatus

-- Test Case: CUclProxyCdd_Impl_GetStatus.E_NOT_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CUclProxyCdd_Impl_GetStatus
TEST.NEW
TEST.NAME:CUclProxyCdd_Impl_GetStatus.E_NOT_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.CUclProxyCdd_Impl_GetStatus.return:E_NOT_OK
TEST.EXPECTED:UclProxyCdd.CUclProxyCdd_Impl_GetStatus.return:E_NOT_OK
TEST.END

-- Subprogram: CUclProxyCdd_Impl_Initialize

-- Test Case: CUclProxyCdd_Impl_Initialize.uclStackNotRunning_SysInit_Fail
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CUclProxyCdd_Impl_Initialize
TEST.NEW
TEST.NAME:CUclProxyCdd_Impl_Initialize.uclStackNotRunning_SysInit_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.<<GLOBAL>>.UclStackRunning:0
TEST.VALUE:UclProxyCdd.CUclProxyCdd_Impl_Initialize.return:E_NOT_OK
TEST.VALUE:uut_prototype_stubs.UclSys_Initialize.return:UCL_E_NOK
TEST.EXPECTED:UclProxyCdd.CUclProxyCdd_Impl_Initialize.return:E_NOT_OK
TEST.END

-- Test Case: CUclProxyCdd_Impl_Initialize.uclStackRunning_E_NOT_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CUclProxyCdd_Impl_Initialize
TEST.NEW
TEST.NAME:CUclProxyCdd_Impl_Initialize.uclStackRunning_E_NOT_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.<<GLOBAL>>.UclStackRunning:1
TEST.VALUE:UclProxyCdd.CUclProxyCdd_Impl_Initialize.return:E_NOT_OK
TEST.EXPECTED:UclProxyCdd.CUclProxyCdd_Impl_Initialize.return:E_NOT_OK
TEST.END

-- Test Case: CUclProxyCdd_Impl_Initialize.uclStackRunning_initialized
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CUclProxyCdd_Impl_Initialize
TEST.NEW
TEST.NAME:CUclProxyCdd_Impl_Initialize.uclStackRunning_initialized
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.<<GLOBAL>>.UclStackRunning:0
TEST.VALUE:UclProxyCdd.CUclProxyCdd_Impl_Initialize.return:E_OK
TEST.VALUE:uut_prototype_stubs.UclSys_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclProxyCdd.CUclProxyCdd_Impl_Initialize.return:E_OK
TEST.END

-- Subprogram: CUclProxyCdd_Impl_InvalidateSecurityKey

-- Test Case: CUclProxyCdd_Impl_InvalidateSecurityKey.E_NOT_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CUclProxyCdd_Impl_InvalidateSecurityKey
TEST.NEW
TEST.NAME:CUclProxyCdd_Impl_InvalidateSecurityKey.E_NOT_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.CUclProxyCdd_Impl_InvalidateSecurityKey.return:E_NOT_OK
TEST.EXPECTED:UclProxyCdd.CUclProxyCdd_Impl_InvalidateSecurityKey.return:E_NOT_OK
TEST.END

-- Subprogram: CUclProxyCdd_Impl_MainFunction

-- Test Case: CUclProxyCdd_Impl_MainFunction.true
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CUclProxyCdd_Impl_MainFunction
TEST.NEW
TEST.NAME:CUclProxyCdd_Impl_MainFunction.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: CUclProxyCdd_Impl_OnCommand

-- Test Case: CUclProxyCdd_Impl_OnCommand.E_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CUclProxyCdd_Impl_OnCommand
TEST.NEW
TEST.NAME:CUclProxyCdd_Impl_OnCommand.E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.CUclProxyCdd_Impl_OnCommand.return:E_OK
TEST.EXPECTED:UclProxyCdd.CUclProxyCdd_Impl_OnCommand.return:E_OK
TEST.END

-- Subprogram: CUclProxyCdd_Impl_Shutdown

-- Test Case: CUclProxyCdd_Impl_Shutdown.No_shutdown_E_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CUclProxyCdd_Impl_Shutdown
TEST.NEW
TEST.NAME:CUclProxyCdd_Impl_Shutdown.No_shutdown_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.CUclProxyCdd_Impl_Shutdown.return:E_OK
TEST.VALUE:uut_prototype_stubs.UclSys_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclProxyCdd.CUclProxyCdd_Impl_Shutdown.return:E_OK
TEST.END

-- Test Case: CUclProxyCdd_Impl_Shutdown.shutdown_ok_UCL_E_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CUclProxyCdd_Impl_Shutdown
TEST.NEW
TEST.NAME:CUclProxyCdd_Impl_Shutdown.shutdown_ok_UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.CUclProxyCdd_Impl_Shutdown.return:E_NOT_OK
TEST.VALUE:uut_prototype_stubs.UclSys_Shutdown.return:UCL_E_NOK
TEST.EXPECTED:UclProxyCdd.CUclProxyCdd_Impl_Shutdown.return:E_NOT_OK
TEST.END

-- Subprogram: CmpActivation

-- Test Case: CmpActivation.always_E_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation.always_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.CmpActivation.return:E_OK
TEST.EXPECTED:UclProxyCdd.CmpActivation.return:E_OK
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.UclStackNotRunning
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.UclStackNotRunning
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.<<GLOBAL>>.UclStackRunning:0
TEST.VALUE:UclProxyCdd.CmpActive.return:E_OK
TEST.EXPECTED:UclProxyCdd.CmpActive.return:E_OK
TEST.END

-- Test Case: CmpActive.UclStackNotRunning_else_false
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.UclStackNotRunning_else_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.<<GLOBAL>>.UclStackRunning:0
TEST.VALUE:UclProxyCdd.CmpActive.return:E_OK
TEST.VALUE:uut_prototype_stubs.UclSys_Initialize.return:-1
TEST.EXPECTED:UclProxyCdd.CmpActive.return:E_OK
TEST.END

-- Test Case: CmpActive.UclStackRunning
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.UclStackRunning
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.<<GLOBAL>>.UclStackRunning:1
TEST.VALUE:UclProxyCdd.CmpActive.return:E_OK
TEST.EXPECTED:UclProxyCdd.CmpActive.return:E_OK
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation.E_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.CmpDeActivation.return:E_OK
TEST.EXPECTED:UclProxyCdd.CmpDeActivation.return:E_OK
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit.E_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit.E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.CmpDeInit.return:E_OK
TEST.EXPECTED:UclProxyCdd.CmpDeInit.return:E_OK
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag.E_NOT_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.E_NOT_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.CmpDiag.return:E_NOT_OK
TEST.EXPECTED:UclProxyCdd.CmpDiag.return:E_NOT_OK
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn.E_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.CmpDiagReturn.return:E_OK
TEST.EXPECTED:UclProxyCdd.CmpDiagReturn.return:E_OK
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit.E_OK
TEST.UNIT:UclProxyCdd
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclProxyCdd.CmpInit.return:E_OK
TEST.EXPECTED:UclProxyCdd.CmpInit.return:E_OK
TEST.END
