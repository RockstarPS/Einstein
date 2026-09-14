-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSAL_PROCESS_UT
-- Unit(s) Under Test: DKOsalProcess
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STANDARD_SPACING_R2
TEST.SCRIPT_FEATURE:OVERLOADED_CONST_SUPPORT
TEST.SCRIPT_FEATURE:UNDERSCORE_NULLPTR
TEST.SCRIPT_FEATURE:FULL_PARAMETER_TYPES
TEST.SCRIPT_FEATURE:STRUCT_DTOR_ADDS_POINTER
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: DKOsalProcess

-- Subprogram: (cl)dk::osal::Process::Process

-- Test Case: Initialize
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::Process
TEST.NEW
TEST.NAME:Initialize
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Process::createProcess

-- Test Case: Fork_failed
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::createProcess
TEST.NEW
TEST.NAME:Fork_failed
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.fork.return:-1
TEST.EXPECTED:DKOsalProcess.(cl)dk::osal::Process::createProcess.return:-1
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::createProcess
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.fork.return:0
TEST.EXPECTED:DKOsalProcess.(cl)dk::osal::Process::createProcess.return:0
TEST.END

-- Test Case: setenv_Fail
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::createProcess
TEST.NEW
TEST.NAME:setenv_Fail
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.fork.return:0
TEST.VALUE:uut_prototype_stubs.setenv.return:1
TEST.EXPECTED:DKOsalProcess.(cl)dk::osal::Process::createProcess.return:0
TEST.END

-- Subprogram: (cl)dk::osal::Process::getProcessId

-- Test Case: Return_the_pid
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::getProcessId
TEST.NEW
TEST.NAME:Return_the_pid
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Process::getenv

-- Test Case: Return_the_env_values
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::getenv
TEST.NEW
TEST.NAME:Return_the_env_values
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::Process::setenv

-- Test Case: Setenv_failed
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::setenv
TEST.NEW
TEST.NAME:Setenv_failed
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.setenv.return:9
TEST.EXPECTED:DKOsalProcess.(cl)dk::osal::Process::setenv.return:9
TEST.END

-- Test Case: Success
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::setenv
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.VALUE:DKOsalProcess.(cl)dk::osal::Process::setenv.name:<<malloc 1>>
TEST.VALUE:DKOsalProcess.(cl)dk::osal::Process::setenv.name[0]:'0'
TEST.VALUE:DKOsalProcess.(cl)dk::osal::Process::setenv.overwrite:true
TEST.EXPECTED:DKOsalProcess.(cl)dk::osal::Process::setenv.return:0
TEST.END

-- Test Case: Success.001
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::setenv
TEST.NEW
TEST.NAME:Success.001
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.VALUE:DKOsalProcess.(cl)dk::osal::Process::setenv.overwrite:false
TEST.VALUE:DKOsalProcess.(cl)dk::osal::Process::setenv.return:1
TEST.VALUE:uut_prototype_stubs.setenv.return:9
TEST.EXPECTED:DKOsalProcess.(cl)dk::osal::Process::setenv.overwrite:false
TEST.EXPECTED:DKOsalProcess.(cl)dk::osal::Process::setenv.return:9
TEST.END

-- Test Case: Success_overwrite
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::setenv
TEST.NEW
TEST.NAME:Success_overwrite
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.VALUE:DKOsalProcess.(cl)dk::osal::Process::setenv.overwrite:true
TEST.VALUE:uut_prototype_stubs.setenv.return:9
TEST.EXPECTED:DKOsalProcess.(cl)dk::osal::Process::setenv.return:9
TEST.END

-- Subprogram: (cl)dk::osal::Process::unsetenv

-- Test Case: Success
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::unsetenv
TEST.NEW
TEST.NAME:Success
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.unsetenv.return:9
TEST.EXPECTED:DKOsalProcess.(cl)dk::osal::Process::unsetenv.return:9
TEST.END

-- Test Case: Unsetenv_failed
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::unsetenv
TEST.NEW
TEST.NAME:Unsetenv_failed
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.unsetenv.return:9
TEST.EXPECTED:DKOsalProcess.(cl)dk::osal::Process::unsetenv.return:9
TEST.END

-- Test Case: Unsetenv_failed.001
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::unsetenv
TEST.NEW
TEST.NAME:Unsetenv_failed.001
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.VALUE:DKOsalProcess.(cl)dk::osal::Process::unsetenv.name:<<malloc 1>>
TEST.VALUE:DKOsalProcess.(cl)dk::osal::Process::unsetenv.name[0]:'0'
TEST.VALUE:DKOsalProcess.(cl)dk::osal::Process::unsetenv.return:0
TEST.EXPECTED:DKOsalProcess.(cl)dk::osal::Process::unsetenv.return:0
TEST.END

-- Subprogram: (cl)dk::osal::Process::~Process

-- Test Case: DeInitialize
TEST.UNIT:DKOsalProcess
TEST.SUBPROGRAM:(cl)dk::osal::Process::~Process
TEST.NEW
TEST.NAME:DeInitialize
TEST.NOTES:
Requirement_AU29610-146976
TEST.END_NOTES:
TEST.VALUE:DKOsalProcess.<<GLOBAL>>.(cl).dk::osal::Process.dk::osal::Process.<<constructor>>.Process().<<call>>:0
TEST.END
