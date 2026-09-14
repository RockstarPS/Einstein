-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RUNTIME_MSGCMN_UT
-- Unit(s) Under Test: dk_runtime_msgcmn
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

-- Test Case: 01_Empty_buffer
TEST.UNIT:dk_runtime_msgcmn
TEST.SUBPROGRAM:(cl)dk::runtime::core::createMap
TEST.NEW
TEST.NAME:01_Empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.FLOW
  dk_runtime_msgcmn.cpp.(cl)dk::runtime::core::createMap
  dk_runtime_msgcmn.cpp.(cl)dk::runtime::core::createMap
TEST.END_FLOW
TEST.END

-- Test Case: 02_Non_Empty_buffer
TEST.UNIT:dk_runtime_msgcmn
TEST.SUBPROGRAM:(cl)dk::runtime::core::createMap
TEST.NEW
TEST.NAME:02_Non_Empty_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::Runtime
Runtime in GIP_INFRA::Library::runtime(bmw)
TEST.END_NOTES:
TEST.VALUE:dk_runtime_msgcmn.(cl)dk::runtime::core::createMap.size:1
TEST.VALUE:dk_runtime_msgcmn.(cl)dk::runtime::core::createMap.msgList:<<malloc 1>>
TEST.EXPECTED:dk_runtime_msgcmn.(cl)dk::runtime::core::createMap.size:1
TEST.FLOW
  dk_runtime_msgcmn.cpp.(cl)dk::runtime::core::createMap
  dk_runtime_msgcmn.cpp.(cl)dk::runtime::core::createMap
TEST.END_FLOW
TEST.END
