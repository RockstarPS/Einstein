-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLALOSASR_IMPL
-- Unit(s) Under Test: UclALOsASR_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclALOsASR_Impl

-- Subprogram: UclALOsASR_Impl_IUclALOs_DisableAllInterrupts

-- Test Case: UclALOsASR_Impl_IUclALOs_DisableAllInterrupts.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_DisableAllInterrupts
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_DisableAllInterrupts.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_DisableAllInterrupts.return:UCL_E_OK
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_EnableAllInterrupts

-- Test Case: UclALOsASR_Impl_IUclALOs_EnableAllInterrupts.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_EnableAllInterrupts
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_EnableAllInterrupts.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_EnableAllInterrupts.return:UCL_E_OK
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_GetSystemTimeMs

-- Test Case: UclALOsASR_Impl_IUclALOs_GetSystemTimeMs.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_GetSystemTimeMs
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_GetSystemTimeMs.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.elapsedTicksInMs:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_GetSystemTimeMs.InstId:0
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_GetSystemTimeMs.return:8
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_GetSystemTimeMs.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_GetSystemTimeMs.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_GetSystemTimeResolutionMs

-- Test Case: UclALOsASR_Impl_IUclALOs_GetSystemTimeResolutionMs.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_GetSystemTimeResolutionMs
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_GetSystemTimeResolutionMs.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_GetSystemTimeResolutionMs.return:4
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_GetSystemTimeResolutionMs.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_GetSystemTimeResolutionMs.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_Initialize

-- Test Case: UclALOsASR_Impl_IUclALOs_Initialize.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_Initialize
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_Initialize.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Initialize.InstId:0
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Initialize.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Initialize.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_Memcmp

-- Test Case: UclALOsASR_Impl_IUclALOs_Memcmp.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_Memcmp.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.InstId:1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_STR1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.Size:10
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.return:UCL_E_OK
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_Memcmp.002
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_Memcmp.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.InstId:1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.pDst:<<null>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.pSrc:<<null>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.Size:10
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.return:UCL_E_INVALID_ARGS
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_Memcmp.003
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_Memcmp.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.InstId:1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.pSrc:<<null>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.Size:10
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.return:UCL_E_INVALID_ARGS
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_Memcmp.004
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_Memcmp.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.InstId:1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_STR1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.Size:0
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.return:UCL_E_INVALID_ARGS
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_Memcmp.005
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_Memcmp.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.pInst:<<malloc 1>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.InstId:1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_INT1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.Size:256
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcmp.return:-1
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_Memcpy

-- Test Case: UclALOsASR_Impl_IUclALOs_Memcpy.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_Memcpy
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_Memcpy.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcpy.pDst:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcpy.pSrc:VECTORCAST_STR1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcpy.Size:10
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memcpy.return:UCL_E_OK
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_Memset

-- Test Case: UclALOsASR_Impl_IUclALOs_Memset.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_Memset
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_Memset.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Memset.return:UCL_E_OK
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_MutexCreate

-- Test Case: UclALOsASR_Impl_IUclALOs_MutexCreate.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_MutexCreate.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_MutexCreate.return:UCL_E_OK
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_MutexDestroy

-- Test Case: UclALOsASR_Impl_IUclALOs_MutexDestroy.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_MutexDestroy.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_MutexDestroy.return:UCL_E_OK
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_MutexLock

-- Test Case: UclALOsASR_Impl_IUclALOs_MutexLock.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_MutexLock.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_MutexLock.return:UCL_E_OK
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_MutexTryLock

-- Test Case: UclALOsASR_Impl_IUclALOs_MutexTryLock.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_MutexTryLock.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_MutexUnlock

-- Test Case: UclALOsASR_Impl_IUclALOs_MutexUnlock.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_MutexUnlock.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_MutexUnlock.return:UCL_E_OK
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_SemCreate

-- Test Case: UclALOsASR_Impl_IUclALOs_SemCreate.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_SemCreate.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_SemCreate.return:UCL_E_NOT_SUPPORTED
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_SemDestroy

-- Test Case: UclALOsASR_Impl_IUclALOs_SemDestroy.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_SemDestroy
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_SemDestroy.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_SemDestroy.return:UCL_E_NOT_SUPPORTED
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_SemPost

-- Test Case: UclALOsASR_Impl_IUclALOs_SemPost.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_SemPost.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_SemPost.return:UCL_E_NOT_SUPPORTED
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_SemWait

-- Test Case: UclALOsASR_Impl_IUclALOs_SemWait.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_SemWait.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_SemWait.return:UCL_E_NOT_SUPPORTED
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_Shutdown

-- Test Case: UclALOsASR_Impl_IUclALOs_Shutdown.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_Shutdown
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_Shutdown.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Shutdown.InstId:0
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Shutdown.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Shutdown.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_TaskCreate

-- Test Case: UclALOsASR_Impl_IUclALOs_TaskCreate.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TaskCreate.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TaskCreate.return:UCL_E_NOT_SUPPORTED
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_TaskDestroy

-- Test Case: UclALOsASR_Impl_IUclALOs_TaskDestroy.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TaskDestroy
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TaskDestroy.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TaskDestroy.return:UCL_E_NOT_SUPPORTED
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_Tick

-- Test Case: UclALOsASR_Impl_IUclALOs_Tick.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_Tick
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_Tick.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Tick.InstId:0
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Tick.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_Tick.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_TimerCreate

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerCreate.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerCreate.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclALOsASR_Impl_TimerProcess );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerCreate.No_Timers_Available
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerCreate.No_Timers_Available
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Created
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[1].state:eUclOsTimerResState_Created
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclALOsASR_Impl_TimerProcess );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerCreate.TimerType_Invalid
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerCreate.TimerType_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_Last
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclALOsASR_Impl_TimerProcess );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerCreate.Timer_State_Destroyed
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerCreate.Timer_State_Destroyed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Destroyed
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[1].state:eUclOsTimerResState_Created
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclALOsASR_Impl_TimerProcess );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerCreate.pData_NULL
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerCreate.pData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pData:<<null>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclALOsASR_Impl_TimerProcess );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc_NULL
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerCreate.pTimerId_NULL
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerCreate.pTimerId_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pTimerId:<<null>>
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclALOsASR_Impl_TimerProcess );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_TimerDestroy

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerDestroy.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerDestroy.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Created
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.TimerId:0
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerDestroy.TimerId_Invalid
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerDestroy.TimerId_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.TimerId:2
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerDestroy.Timer_State_Invalid
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerDestroy.Timer_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.TimerId:0
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerDestroy.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_TimerStart

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerStart.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerStart.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Created
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.TimerId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.Timeout:4
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerStart.Timeout_LT_TickResolution
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerStart.Timeout_LT_TickResolution
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Created
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.TimerId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.Timeout:3
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerStart.TimerId_Invalid
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerStart.TimerId_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Created
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.TimerId:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.Timeout:4
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerStart.Timer_State_Invalid
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerStart.Timer_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Destroyed
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.TimerId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.Timeout:4
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerStart.Timer_State_Stopped
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerStart.Timer_State_Stopped
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Stopped
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.TimerId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.Timeout:4
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStart.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsASR_Impl_IUclALOs_TimerStop

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerStop.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerStop.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Running
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.TimerId:0
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerStop.TimerId_Invalid
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerStop.TimerId_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Running
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.TimerId:2
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerStop.Timer_State_Created
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerStop.Timer_State_Created
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Created
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.TimerId:0
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerStop.Timer_State_Invalid
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerStop.Timer_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.TimerId:0
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_IUclALOs_TimerStop.Timer_State_Stopped
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:UclALOsASR_Impl_IUclALOs_TimerStop.Timer_State_Stopped
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Stopped
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:2
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.InstId:0
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.TimerId:0
TEST.EXPECTED:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_IUclALOs_TimerStop.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsASR_Impl_TimerProcess

-- Test Case: UclALOsASR_Impl_TimerProcess.001
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_TimerProcess
TEST.NEW
TEST.NAME:UclALOsASR_Impl_TimerProcess.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Running
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].pFunc:UclTest_TimerTask
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].pData:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].type:eUclOsTimerType_OneShot
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].timeout:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].count:3
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[1].pData:<<null>>
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.InstId:0
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_TimerProcess.Timer_Not_Lapsed
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_TimerProcess
TEST.NEW
TEST.NAME:UclALOsASR_Impl_TimerProcess.Timer_Not_Lapsed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Running
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].pFunc:UclTest_TimerTask
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].pData:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].type:eUclOsTimerType_OneShot
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].timeout:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].count:2
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[1].pData:<<null>>
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.InstId:0
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_TimerProcess.Timer_State_Invalid
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_TimerProcess
TEST.NEW
TEST.NAME:UclALOsASR_Impl_TimerProcess.Timer_State_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Created
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].pFunc:UclTest_TimerTask
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].pData:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].type:eUclOsTimerType_OneShot
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].timeout:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].count:3
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[1].pData:<<null>>
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.InstId:0
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsASR_Impl_TimerProcess.Timer_Type_Periodic
TEST.UNIT:UclALOsASR_Impl
TEST.SUBPROGRAM:UclALOsASR_Impl_TimerProcess
TEST.NEW
TEST.NAME:UclALOsASR_Impl_TimerProcess.Timer_Type_Periodic
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].state:eUclOsTimerResState_Running
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].pFunc:UclTest_TimerTask
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].pData:VECTORCAST_BUFFER
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].timeout:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[0].count:3
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsASRTimerList[1].pData:<<null>>
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.tickResolutionMs:4
TEST.VALUE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.maxTimers:1
TEST.VALUE:UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.InstId:0
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0.pTimerList
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsCfg_0>>.pTimerList = ( &UCLALOSCFG_0_SUclALOsASRTimerList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0.pCfg
<<UclALOsASR_Impl.<<GLOBAL>>.UclALOsInst_0>>.pCfg = ( &UclALOsCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.pInst
<<UclALOsASR_Impl.UclALOsASR_Impl_TimerProcess.pInst>> = ( &UclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
