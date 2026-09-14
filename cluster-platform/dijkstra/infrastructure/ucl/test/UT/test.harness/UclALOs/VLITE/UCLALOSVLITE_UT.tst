-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UCLALOSVLITE_UT
-- Unit(s) Under Test: UclALOsVlite_Impl
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

-- Unit: UclALOsVlite_Impl

-- Subprogram: UclALOsVlite_Impl_IUclALOs_DisableAllInterrupts

-- Test Case: UclALOsVlite_Impl_IUclALOs_DisableAllInterrupts.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_DisableAllInterrupts
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_DisableAllInterrupts.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_DisableAllInterrupts.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_EnableAllInterrupts

-- Test Case: UclALOsVlite_Impl_IUclALOs_EnableAllInterrupts.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_EnableAllInterrupts
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_EnableAllInterrupts.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_EnableAllInterrupts.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs

-- Test Case: UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs.general
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs.pInst[0].elapsedTicksInMs:3
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs.pInst[0].pCfg[0].tickResolutionMs:3
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs.return:9
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_GetSystemTimeResolutionMs

-- Test Case: UclALOsVlite_Impl_IUclALOs_GetSystemTimeResolutionMs.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_GetSystemTimeResolutionMs
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_GetSystemTimeResolutionMs.general
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_GetSystemTimeResolutionMs.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_GetSystemTimeResolutionMs.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_GetSystemTimeResolutionMs.pInst[0].pCfg[0].tickResolutionMs:4
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_GetSystemTimeResolutionMs.return:4
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_Initialize

-- Test Case: UclALOsVlite_Impl_IUclALOs_Initialize.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_Initialize
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_Initialize.general
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].maxTimers:3
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Created
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Initialize.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_Memcmp

-- Test Case: UclALOsVlite_Impl_IUclALOs_Memcmp.Size=0
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_Memcmp.Size=0
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_INT1
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_INT1
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.Size:0
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.return:-3
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_Memcmp.memcmp_false
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_Memcmp.memcmp_false
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_INT1
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_INT2
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.Size:100
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.return:-1
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_Memcmp.pDst_false
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_Memcmp.pDst_false
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.pDst:<<null>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_INT1
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.Size:3
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.return:-3
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_Memcmp.pSrc_false
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_Memcmp.pSrc_false
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_INT1
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.pSrc:<<null>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.Size:3
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.return:-3
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_Memcmp.true
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_Memcmp.true
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_INT1
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_INT1
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.Size:3
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcmp.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_Memcpy

-- Test Case: UclALOsVlite_Impl_IUclALOs_Memcpy.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_Memcpy
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_Memcpy.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memcpy.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_Memset

-- Test Case: UclALOsVlite_Impl_IUclALOs_Memset.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_Memset
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_Memset.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Memset.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_MutexCreate

-- Test Case: UclALOsVlite_Impl_IUclALOs_MutexCreate.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_MutexCreate.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_MutexCreate.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_MutexDestroy

-- Test Case: UclALOsVlite_Impl_IUclALOs_MutexDestroy.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_MutexDestroy.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_MutexDestroy.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_MutexLock

-- Test Case: UclALOsVlite_Impl_IUclALOs_MutexLock.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_MutexLock.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_MutexLock.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_MutexTryLock

-- Test Case: UclALOsVlite_Impl_IUclALOs_MutexTryLock.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_MutexTryLock.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_MutexTryLock.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_MutexUnlock

-- Test Case: UclALOsVlite_Impl_IUclALOs_MutexUnlock.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_MutexUnlock.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_MutexUnlock.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_SemCreate

-- Test Case: UclALOsVlite_Impl_IUclALOs_SemCreate.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_SemCreate.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_SemCreate.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_SemDestroy

-- Test Case: UclALOsVlite_Impl_IUclALOs_SemDestroy.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_SemDestroy
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_SemDestroy.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_SemDestroy.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_SemPost

-- Test Case: UclALOsVlite_Impl_IUclALOs_SemPost.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_SemPost.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_SemPost.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_SemWait

-- Test Case: UclALOsVlite_Impl_IUclALOs_SemWait.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_SemWait.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_SemWait.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_Shutdown

-- Test Case: UclALOsVlite_Impl_IUclALOs_Shutdown.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_Shutdown
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_Shutdown.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Shutdown.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_TaskCreate

-- Test Case: UclALOsVlite_Impl_IUclALOs_TaskCreate.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TaskCreate.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TaskCreate.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_TaskDestroy

-- Test Case: UclALOsVlite_Impl_IUclALOs_TaskDestroy.general
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TaskDestroy
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TaskDestroy.general
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TaskDestroy.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_Tick

-- Test Case: UclALOsVlite_Impl_IUclALOs_Tick.001
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_Tick
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_Tick.001
TEST.STUB:UclALOsVlite_Impl.UclALOsVlite_Impl_TimerProcess
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Tick.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Tick.pInst[0].elapsedTicksInMs:1
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_TimerCreate

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerCreate.states_true
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerCreate.states_true
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Destroyed
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT2
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.return:0
TEST.VALUE_USER_CODE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc>> = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerCreate.true
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerCreate.true
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT2
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.return:-1
TEST.VALUE_USER_CODE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc>> = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerCreate.true.pdata_false
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerCreate.true.pdata_false
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pData:<<null>>
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.return:-3
TEST.VALUE_USER_CODE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc>> = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerCreate.true.pfunc_false
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerCreate.true.pfunc_false
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT2
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.return:-3
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerCreate.true.ptimer_false
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerCreate.true.ptimer_false
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pTimerId:<<null>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT2
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.return:-3
TEST.VALUE_USER_CODE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc>> = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerCreate.true.state_uninit
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerCreate.true.state_uninit
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT2
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.return:0
TEST.VALUE_USER_CODE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc>> = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerCreate.true.states_false
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerCreate.true.states_false
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Running
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT2
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.return:0
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.return:-1
TEST.VALUE_USER_CODE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc>> = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerCreate.true.timertype_last
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerCreate.true.timertype_last
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT2
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_Last
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.return:-3
TEST.VALUE_USER_CODE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate.pFunc>> = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_TimerDestroy

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerDestroy.state_destroy
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerDestroy.state_destroy
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Destroyed
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.TimerId:0
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.return:0
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerDestroy.true
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerDestroy.true
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.TimerId:0
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.return:-2
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerDestroy.true.false
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerDestroy.true.false
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.TimerId:6
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy.return:-3
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_TimerStart

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerStart.false
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerStart.false
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].tickResolutionMs:4
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Stopped
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].timeout:0
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.TimerId:20
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.return:-3
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerStart.timeout_false
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerStart.timeout_false
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].tickResolutionMs:4
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Created
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].timeout:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.Timeout:6
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.return:0
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerStart.true
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerStart.true
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].tickResolutionMs:4
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Stopped
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].timeout:0
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.return:0
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerStart.true.created
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerStart.true.created
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].tickResolutionMs:4
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Created
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].timeout:0
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.return:0
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerStart.true.stopped
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerStart.true.stopped
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].tickResolutionMs:4
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Running
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].timeout:0
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart.return:-2
TEST.END

-- Subprogram: UclALOsVlite_Impl_IUclALOs_TimerStop

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerStop.false
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerStop.false
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Running
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.TimerId:6
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.return:-3
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerStop.state_created
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerStop.state_created
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Created
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.return:0
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerStop.state_last
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerStop.state_last
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Last
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.return:-2
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerStop.state_stopped
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerStop.state_stopped
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Stopped
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.return:0
TEST.END

-- Test Case: UclALOsVlite_Impl_IUclALOs_TimerStop.true
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_IUclALOs_TimerStop.true
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].maxTimers:5
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Running
TEST.EXPECTED:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop.return:0
TEST.END

-- Subprogram: UclALOsVlite_Impl_TimerProcess

-- Test Case: UclALOsVlite_Impl_TimerProcess.state_destroy
TEST.UNIT:UclALOsVlite_Impl
TEST.SUBPROGRAM:UclALOsVlite_Impl_TimerProcess
TEST.NEW
TEST.NAME:UclALOsVlite_Impl_TimerProcess.state_destroy
TEST.STUB:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerCreate
TEST.STUB:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStart
TEST.STUB:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerStop
TEST.STUB:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_TimerDestroy
TEST.STUB:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_GetSystemTimeMs
TEST.STUB:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_GetSystemTimeResolutionMs
TEST.STUB:UclALOsVlite_Impl.UclALOsVlite_Impl_IUclALOs_Tick
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_TimerProcess.pInst:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_TimerProcess.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_TimerProcess.pInst[0].pCfg[0].maxTimers:3
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_TimerProcess.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_TimerProcess.pInst[0].pCfg[0].pTimerList[0].state:eUclOsTimerResState_Destroyed
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_TimerProcess.pInst[0].pCfg[0].pTimerList[0].pData:VECTORCAST_INT2
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_TimerProcess.pInst[0].pCfg[0].pTimerList[0].timeout:101
TEST.VALUE:UclALOsVlite_Impl.UclALOsVlite_Impl_TimerProcess.pInst[0].pCfg[0].pTimerList[0].count:100
TEST.VALUE_USER_CODE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2>> = ( 20 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsVlite_Impl.UclALOsVlite_Impl_TimerProcess.pInst.pInst[0].pCfg.pCfg[0].pTimerList.pTimerList[0].pFunc
<<UclALOsVlite_Impl.UclALOsVlite_Impl_TimerProcess.pInst>>[0].pCfg[0].pTimerList[0].pFunc = ( &VECTORCAST_INT2 );
TEST.END_VALUE_USER_CODE:
TEST.END
