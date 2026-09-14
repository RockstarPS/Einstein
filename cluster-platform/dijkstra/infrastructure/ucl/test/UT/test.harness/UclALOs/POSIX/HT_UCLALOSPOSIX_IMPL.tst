-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLALOSPOSIX_IMPL
-- Unit(s) Under Test: UclALOsPOSIX_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclALOsPOSIX_Impl

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_DisableAllInterrupts

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_DisableAllInterrupts.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_DisableAllInterrupts
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_DisableAllInterrupts.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_DisableAllInterrupts.InstId:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_DisableAllInterrupts.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_DisableAllInterrupts.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_DisableAllInterrupts.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_EnableAllInterrupts

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_EnableAllInterrupts.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_EnableAllInterrupts
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_EnableAllInterrupts.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_EnableAllInterrupts.InstId:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_EnableAllInterrupts.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_EnableAllInterrupts.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_EnableAllInterrupts.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs.InstId:0
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs.clock_gettime_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs.clock_gettime_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs.InstId:0
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs.return:0
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeResolutionMs

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeResolutionMs.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeResolutionMs
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeResolutionMs.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_Initialize

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_Initialize.Ptherad_sigmaskfail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Initialize
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_Initialize.Ptherad_sigmaskfail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.pthread_sigmask.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_Initialize_Pthread_create_fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Initialize
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_Initialize_Pthread_create_fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.pthread_create.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_Initialize_Success
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Initialize
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_Initialize_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.InstId:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Initialize.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_Memcmp

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_Memcmp.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_Memcmp.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_STR1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_STR1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.Size:10
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pInst>> = (& TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_Memcmp.002
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_Memcmp.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:11
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1..2]:12
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:14
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_STR1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_BUFFER
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.Size:4
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pInst>> = (& TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_Memcmp_PDst_NULL
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_Memcmp_PDst_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:11
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1..2]:12
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:14
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pDst:<<null>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_BUFFER
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.Size:4
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pInst>> = (& TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_Memcmp_PSrc_NULL
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_Memcmp_PSrc_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:11
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1..2]:12
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:14
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_BUFFER
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pSrc:<<null>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.Size:4
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pInst>> = (& TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_Memcmp_Size0
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_Memcmp_Size0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[0]:11
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1..2]:12
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[3]:14
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_BUFFER
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_BUFFER
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.Size:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcmp.pInst>> = (& TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_Memcpy

-- Test Case: Memcpy_Success
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memcpy
TEST.NEW
TEST.NAME:Memcpy_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pDst:VECTORCAST_STR1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pSrc:VECTORCAST_STR1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.Size:10
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Size_Zero
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memcpy
TEST.NEW
TEST.NAME:Size_Zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pDst:VECTORCAST_STR1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pSrc:VECTORCAST_STR1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.Size:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pDst_NULL
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memcpy
TEST.NEW
TEST.NAME:pDst_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pDst:<<null>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pSrc:VECTORCAST_STR1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.Size:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pSrc_NULL
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memcpy
TEST.NEW
TEST.NAME:pSrc_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pDst:VECTORCAST_STR1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pSrc:<<null>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.Size:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memcpy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_Memset

-- Test Case: Size_Zero
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memset
TEST.NEW
TEST.NAME:Size_Zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.pBuffer:VECTORCAST_STR1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.Size:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_Memset.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memset
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_Memset.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.pBuffer:VECTORCAST_STR1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.Size:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pBuffer_NULL
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Memset
TEST.NEW
TEST.NAME:pBuffer_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.pBuffer:<<null>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.Size:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Memset.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_MutexCreate

-- Test Case: MutexId_Zero
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:MutexId_Zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pMutexId:<<null>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_init.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Mutex_State_Invalid
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:Mutex_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[0].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[2].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[3].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[4].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pMutexId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pMutexId[0]:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_MutexCreate.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_MutexCreate.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst[0].pCfg[0].MaxMutex:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pMutexId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pMutexId[0]:2
TEST.VALUE:uut_prototype_stubs.pthread_mutex_init.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_MutexCreate.002
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_MutexCreate.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst[0].pCfg[0].MaxMutex:2
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst[0].pCfg[0].pMutexList:<<malloc 3>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pMutexId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pMutexId[0]:2
TEST.VALUE:uut_prototype_stubs.pthread_mutex_init.return:(2)1,0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pthread_mutex_init_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:pthread_mutex_init_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pMutexId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pMutexId[0]:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_init.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pthread_mutex_init_Fail.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:pthread_mutex_init_Fail.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pMutexId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pMutexId[0]:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_init.return:1
TEST.VALUE:uut_prototype_stubs.pthread_mutexattr_init.return:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst.pInst[0].pCfg.pCfg[0].pMutexList.pMutexList[0].mutex
<<UclALOsPOSIX_Impl.<<GLOBAL>>.pInst>>[0].pCfg[0].pMutexList[0].mutex = 0x1;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_MutexDestroy

-- Test Case: MutexId_GT_MaxMutex
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:MutexId_GT_MaxMutex
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.MutexId:11
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Mutex_State_Invalid
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:Mutex_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.MutexId:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.MutexId:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_destroy.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pthread_mutex_destroy_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:pthread_mutex_destroy_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_UnLocked
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.MutexId:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_destroy.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_MutexLock

-- Test Case: MutexId_GT_MaxMutex
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:MutexId_GT_MaxMutex
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.MutexId:11
TEST.VALUE:uut_prototype_stubs.pthread_mutex_lock.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Mutex_Lock_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:Mutex_Lock_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.MutexId:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_lock.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Mutex_State_Destroyed
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:Mutex_State_Destroyed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.MutexId:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_lock.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Mutex_State_UnInit
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:Mutex_State_UnInit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.MutexId:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_lock.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_MutexLock.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_MutexLock.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.MutexId:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_lock.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexLock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_MutexTryLock

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.MutexId:0
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.InvalidMutexId
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.InvalidMutexId
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.MutexId:6
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.InvalidMutexState
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.InvalidMutexState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[0].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.MutexId:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.LockStatus_EBUSY
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.LockStatus_EBUSY
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.MutexId:0
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:16
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.LockStatus_NEQ_EBUSY
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.LockStatus_NEQ_EBUSY
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.MutexId:0
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:15
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.MutexStateDestroyed
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.MutexStateDestroyed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[0].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.MutexId:0
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexTryLock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_MutexUnlock

-- Test Case: MutexId_GT_MaxMutex
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:MutexId_GT_MaxMutex
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.MutexId:11
TEST.VALUE:uut_prototype_stubs.pthread_mutex_unlock.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Mutex_State_Destroyed
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:Mutex_State_Destroyed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.MutexId:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_unlock.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Mutex_State_UnInit
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:Mutex_State_UnInit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.MutexId:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_unlock.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Mutex_Unlock_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:Mutex_Unlock_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.MutexId:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_unlock.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXMutexList[1].State:eUclOsMutexResState_Locked
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.MutexId:1
TEST.VALUE:uut_prototype_stubs.pthread_mutex_unlock.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_MutexUnlock.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_SemCreate

-- Test Case: Sem_State_Invalid
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:Sem_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pSemId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pSemId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.Val:1
TEST.VALUE:uut_prototype_stubs.sem_init.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_SemCreate.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_SemCreate.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pSemId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pSemId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.Val:1
TEST.VALUE:uut_prototype_stubs.sem_init.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pSemId_NULL
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:pSemId_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pSemId:<<null>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.Val:1
TEST.VALUE:uut_prototype_stubs.sem_init.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sem_init_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:sem_init_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pSemId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pSemId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.Val:1
TEST.VALUE:uut_prototype_stubs.sem_init.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_SemDestroy

-- Test Case: SemId_GT_MaxSem
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemDestroy
TEST.NEW
TEST.NAME:SemId_GT_MaxSem
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.SemId:11
TEST.VALUE:uut_prototype_stubs.sem_destroy.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Sem_State_Invalid
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemDestroy
TEST.NEW
TEST.NAME:Sem_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.SemId:1
TEST.VALUE:uut_prototype_stubs.sem_destroy.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_SemDestroy.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemDestroy
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_SemDestroy.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.SemId:1
TEST.VALUE:uut_prototype_stubs.sem_destroy.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sem_destroy_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemDestroy
TEST.NEW
TEST.NAME:sem_destroy_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.SemId:1
TEST.VALUE:uut_prototype_stubs.sem_destroy.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_SemPost

-- Test Case: SemId_GT_MaxSem
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:SemId_GT_MaxSem
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.SemId:11
TEST.VALUE:uut_prototype_stubs.sem_post.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Sem_State_Destroyed
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:Sem_State_Destroyed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.SemId:1
TEST.VALUE:uut_prototype_stubs.sem_post.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Sem_State_UnInit
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:Sem_State_UnInit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.SemId:1
TEST.VALUE:uut_prototype_stubs.sem_post.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_SemPost.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_SemPost.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.SemId:1
TEST.VALUE:uut_prototype_stubs.sem_post.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sem_post_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:sem_post_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.SemId:1
TEST.VALUE:uut_prototype_stubs.sem_post.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemPost.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_SemWait

-- Test Case: SemId_GT_MaxSem
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:SemId_GT_MaxSem
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.SemId:11
TEST.VALUE:uut_prototype_stubs.sem_wait.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Sem_State_Destroyed
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:Sem_State_Destroyed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.SemId:1
TEST.VALUE:uut_prototype_stubs.sem_wait.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Sem_State_UnInit
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:Sem_State_UnInit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.SemId:1
TEST.VALUE:uut_prototype_stubs.sem_wait.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Sem_wait_fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:Sem_wait_fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.SemId:1
TEST.VALUE:uut_prototype_stubs.sem_wait.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_SemWait.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_SemWait.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXSemList[1].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.SemId:1
TEST.VALUE:uut_prototype_stubs.sem_wait.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_SemWait.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_Shutdown

-- Test Case: Task_State_Created
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Shutdown
TEST.NEW
TEST.NAME:Task_State_Created
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].State:eUclOsTaskResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.InstId:0
TEST.VALUE:uut_prototype_stubs.kill.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Created
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Shutdown
TEST.NEW
TEST.NAME:Timer_State_Created
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.InstId:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Running
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Shutdown
TEST.NEW
TEST.NAME:Timer_State_Running
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.InstId:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_Shutdown.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_TaskCreate

-- Test Case: Task_State_Invalid
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:Task_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].State:eUclOsTaskResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].pData:VECTORCAST_INT2
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pThreadId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pFunc
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pFunc_NULL
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:pFunc_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].State:eUclOsTaskResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pThreadId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pThreadId_NULL
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:pThreadId_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].State:eUclOsTaskResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pThreadId:<<null>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pthread_create_Fail_taskState_destroyed
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:pthread_create_Fail_taskState_destroyed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].State:eUclOsTaskResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].pData:VECTORCAST_INT2
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pThreadId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pFunc
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pthread_create_Success
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:pthread_create_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].State:eUclOsTaskResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].pData:VECTORCAST_INT2
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.pInst[0].pCfg[0].MaxTask:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pThreadId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pFunc
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_TaskDestroy

-- Test Case: Task_State_Invalid
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TaskDestroy
TEST.NEW
TEST.NAME:Task_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].State:eUclOsTaskResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.ThreadId:1
TEST.VALUE:uut_prototype_stubs.pthread_cancel.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ThreadId_GT_MaxTask
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TaskDestroy
TEST.NEW
TEST.NAME:ThreadId_GT_MaxTask
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].State:eUclOsTaskResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.ThreadId:11
TEST.VALUE:uut_prototype_stubs.pthread_cancel.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TaskDestroy
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].State:eUclOsTaskResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.ThreadId:1
TEST.VALUE:uut_prototype_stubs.pthread_cancel.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pthread_Cancel_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TaskDestroy
TEST.NEW
TEST.NAME:pthread_Cancel_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTaskList[1].State:eUclOsTaskResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.ThreadId:1
TEST.VALUE:uut_prototype_stubs.pthread_cancel.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TaskDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_Tick

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_Tick.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_Tick
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_Tick.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_TimerCreate

-- Test Case: PFunc_NULL
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:PFunc_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT3
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Sem_init_fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:Sem_init_fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.VALUE:uut_prototype_stubs.sem_init.return:-1
TEST.VALUE:uut_prototype_stubs.timer_create.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TimerType_Invalid
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:TimerType_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].Type:eUclOsTimerType_OneShot
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT2
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_Last
TEST.VALUE:uut_prototype_stubs.timer_create.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Invalid
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:Timer_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[2].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[3].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[4].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.VALUE:uut_prototype_stubs.timer_create.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_UnInit
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:Timer_State_UnInit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.VALUE:uut_prototype_stubs.timer_create.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pData_NULL
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pData:<<null>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.VALUE:uut_prototype_stubs.timer_create.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pTimerId_NULL
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:pTimerId_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId:<<null>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: pthread_create_failed
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:pthread_create_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.VALUE:uut_prototype_stubs.pthread_create.return:-1
TEST.VALUE:uut_prototype_stubs.timer_create.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: timer_create_fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:timer_create_fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pTimerId[0]:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.VALUE:uut_prototype_stubs.timer_create.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerCreate.pFunc>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_TimerDestroy

-- Test Case: Invalid_Timer_Id
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:Invalid_Timer_Id
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.TimerId:100
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Invalid_Timer_Id.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:Invalid_Timer_Id.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].MaxTimers:200
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].timer:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.TimerId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.return:-3
TEST.VALUE:uut_prototype_stubs.sem_post.return:1
TEST.VALUE:uut_prototype_stubs.timer_delete.return:1
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TimerId_GT_MaxTimers
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:TimerId_GT_MaxTimers
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.TimerId:11
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_Not_Stopped_before_destroy
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:Timer_Not_Stopped_before_destroy
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.TimerId:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Created
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:Timer_State_Created
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.TimerId:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Invalid
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:Timer_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.TimerId:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Stopped
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:Timer_State_Stopped
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Stopped
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.TimerId:1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerDestroy.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_TimerStart

-- Test Case: TimerId_GT_MaxTimers
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:TimerId_GT_MaxTimers
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:FALSE
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.TimerId:11
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.Timeout:10
TEST.VALUE:uut_prototype_stubs.timer_settime.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Invalid
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:Timer_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.TimerId:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.Timeout:10
TEST.VALUE:uut_prototype_stubs.timer_settime.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Stopped
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:Timer_State_Stopped
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:FALSE
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.TimerId:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.Timeout:10
TEST.VALUE:uut_prototype_stubs.timer_settime.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_IUclALOs_TimerStart.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_IUclALOs_TimerStart.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.TimerId:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.Timeout:10
TEST.VALUE:uut_prototype_stubs.timer_settime.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: timer_settime_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:timer_settime_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Stopped
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.TimerId:1
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.Timeout:10
TEST.VALUE:uut_prototype_stubs.timer_settime.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStart.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_IUclALOs_TimerStop

-- Test Case: TimerId_GT_MaxTimers
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:TimerId_GT_MaxTimers
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.TimerId:11
TEST.VALUE:uut_prototype_stubs.timer_settime.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Created
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:Timer_State_Created
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.TimerId:1
TEST.VALUE:uut_prototype_stubs.timer_settime.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Invalid
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:Timer_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.TimerId:1
TEST.VALUE:uut_prototype_stubs.timer_settime.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Running
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:Timer_State_Running
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.TimerId:1
TEST.VALUE:uut_prototype_stubs.timer_settime.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Running_timer_settime_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:Timer_State_Running_timer_settime_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.TimerId:1
TEST.VALUE:uut_prototype_stubs.timer_settime.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Timer_State_Stopped
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:Timer_State_Stopped
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[1].State:eUclOsTimerResState_Stopped
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.InstId:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.TimerId:1
TEST.VALUE:uut_prototype_stubs.timer_settime.return:0
TEST.EXPECTED:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_IUclALOs_TimerStop.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_SignalActionThread

-- Test Case: UclALOsPOSIX_Impl_SignalActionThread.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalActionThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalActionThread.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sem_wait.return:0
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.State
int a = 0;
if(a==0){
<<UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList>>.State = ( eUclOsTimerResState_Running );
a++;
}
else{
<<UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList>>.State = ( eUclOsTimerResState_Destroyed );
}
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.pFunc
<<UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList>>.pFunc = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData>> = ( &uclTimerList );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalActionThread.002
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalActionThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalActionThread.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.return:<<null>>
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.pFunc
<<UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList>>.pFunc = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData>> = ( &uclTimerList );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalActionThread.InvalidTimerState
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalActionThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalActionThread.InvalidTimerState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.return:<<null>>
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.pFunc
<<UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList>>.pFunc = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData>> = ( &uclTimerList );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalActionThread.SemWaitFail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalActionThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalActionThread.SemWaitFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sem_wait.return:-1
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.pFunc
<<UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList>>.pFunc = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData>> = ( &uclTimerList );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalActionThread_Timer_Destroyed
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalActionThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalActionThread_Timer_Destroyed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Destroyed
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sem_wait.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_UnInit
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.pFunc
<<UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList>>.pFunc = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData>> = ( &uclTimerList );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalActionThread_clock_gettime_failed
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalActionThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalActionThread_clock_gettime_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.lastTriggerTime:0
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sem_wait.return:-1
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:-1
TEST.EXPECTED:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Running
TEST.EXPECTED:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.lastTriggerTime:0
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList.pFunc
<<UclALOsPOSIX_Impl.<<GLOBAL>>.uclTimerList>>.pFunc = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalActionThread.pData>> = ( &uclTimerList );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_SignalListenerThread

-- Test Case: UclALOsPOSIX_Impl_SignalListenerThread.ListenerNotReady
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalListenerThread.ListenerNotReady
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:FALSE
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalListenerThread.ListenerNotReady.001
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalListenerThread.ListenerNotReady.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:FALSE
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:1
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalListenerThread.OneShotTimer_SemPost_Success
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalListenerThread.OneShotTimer_SemPost_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:TRUE
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sigwait.__sig[0]:1
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalListenerThread.PeriodicTimer_SemPost_Success
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalListenerThread.PeriodicTimer_SemPost_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:TRUE
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sigwait.__sig[0]:1
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalListenerThread.PeriodicTimer_SemPost_Success.clock_get_time_false
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalListenerThread.PeriodicTimer_SemPost_Success.clock_get_time_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:TRUE
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:1
TEST.VALUE:uut_prototype_stubs.sigwait.__sig[0]:1
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalListenerThread.Rcvd_Invalid_Signal
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalListenerThread.Rcvd_Invalid_Signal
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:TRUE
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalListenerThread.SemPost_Fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalListenerThread.SemPost_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:TRUE
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sem_post.return:-1
TEST.VALUE:uut_prototype_stubs.sigwait.__sig[0]:1
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_SignalListenerThread.SigWait_fail
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_SignalListenerThread.SigWait_fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].sig:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsPOSIXTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:TRUE
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sigwait.return:-1
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsPOSIX_Impl_UpdateTimerStats

-- Test Case: UclALOsPOSIX_Impl_UpdateTimerStats_Timer_Created
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_UpdateTimerStats
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_UpdateTimerStats_Timer_Created
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_UpdateTimerStats.timeNow:111111
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_UpdateTimerStats.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_UpdateTimerStats.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsPOSIX_Impl_UpdateTimerStats_Timer_Unit
TEST.UNIT:UclALOsPOSIX_Impl
TEST.SUBPROGRAM:UclALOsPOSIX_Impl_UpdateTimerStats
TEST.NEW
TEST.NAME:UclALOsPOSIX_Impl_UpdateTimerStats_Timer_Unit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsPOSIX_Impl.<<GLOBAL>>.TestUclALOsInst_0.pCfg[0].pTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_UpdateTimerStats.timeNow:111111
TEST.VALUE_USER_CODE:UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_UpdateTimerStats.pInst
<<UclALOsPOSIX_Impl.UclALOsPOSIX_Impl_UpdateTimerStats.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
