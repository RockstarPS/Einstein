-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLALOSANDROID
-- Unit(s) Under Test: UclALOsAndroid_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_DisableAllInterrupts

-- Test Case: UclALOsAndroid_Impl_IUclALOs_DisableAllInterrupts.general_case
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_DisableAllInterrupts
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_DisableAllInterrupts.general_case
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_DisableAllInterrupts.return:-1
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_EnableAllInterrupts

-- Test Case: UclALOsAndroid_Impl_IUclALOs_EnableAllInterrupts.general_case
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_EnableAllInterrupts
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_EnableAllInterrupts.general_case
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_EnableAllInterrupts.return:-1
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_GetSystemTimeMs

-- Test Case: UclALOsAndroid_Impl_IUclALOs_GetSystemTimeMs.clock_gettime_true
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_GetSystemTimeMs
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_GetSystemTimeMs.clock_gettime_true
TEST.VALUE:uut_prototype_stubs.clock_gettime.__clock_id:1
TEST.VALUE:uut_prototype_stubs.clock_gettime.__tp[0].tv_sec:0
TEST.VALUE:uut_prototype_stubs.clock_gettime.__tp[0].tv_nsec:1
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_GetSystemTimeMs.return:0
TEST.END

-- Test Case: UclALOsAndroid_Impl_IUclALOs_GetSystemTimeMs.clock_gettime_true.false
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_GetSystemTimeMs
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_GetSystemTimeMs.clock_gettime_true.false
TEST.VALUE:uut_prototype_stubs.clock_gettime.__clock_id:1
TEST.VALUE:uut_prototype_stubs.clock_gettime.__tp[0].tv_sec:0
TEST.VALUE:uut_prototype_stubs.clock_gettime.__tp[0].tv_nsec:1
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_GetSystemTimeMs.return:0
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_GetSystemTimeResolutionMs

-- Test Case: UclALOsAndroid_Impl_IUclALOs_GetSystemTimeResolutionMs.return_1
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_GetSystemTimeResolutionMs
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_GetSystemTimeResolutionMs.return_1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_GetSystemTimeResolutionMs.return:1
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_Initialize

-- Test Case: UclALOsAndroid_Impl_IUclALOs_Initialize.MaxMutex_updated
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Initialize
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_Initialize.MaxMutex_updated
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxMutex:2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxTask:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxTimers:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.InstId:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.return:0
TEST.END

-- Test Case: UclALOsAndroid_Impl_IUclALOs_Initialize.MaxTask_updated
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Initialize
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_Initialize.MaxTask_updated
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxMutex:2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxTask:2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxTimers:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].pTaskList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.InstId:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.return:0
TEST.END

-- Test Case: UclALOsAndroid_Impl_IUclALOs_Initialize.MaxTask_updated.MaxListTrue
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Initialize
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_Initialize.MaxTask_updated.MaxListTrue
TEST.BASIS_PATH:3 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (i < pInst->pCfg->MaxMutex) ==> FALSE
      (2) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (3) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (4) if ((0) != ret) ==> FALSE
      (5) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
      (6) for (i < pInst->pCfg->MaxSem) ==> FALSE
      (7) if (ret != (0)) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.InstId:1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:0
TEST.VALUE:uut_prototype_stubs.pthread_sigmask.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.return:0
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst>> = ( &TestUclALOsInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALOsAndroid_Impl_IUclALOs_Initialize.MaxTask_updated.pthread_sigmask_nonzero
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Initialize
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_Initialize.MaxTask_updated.pthread_sigmask_nonzero
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxMutex:2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxTask:2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxTimers:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].pTaskList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.pthread_create.return:1
TEST.VALUE:uut_prototype_stubs.pthread_sigmask.return:1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.return:-1
TEST.END

-- Test Case: UclALOsAndroid_Impl_IUclALOs_Initialize.false_case
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Initialize
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_Initialize.false_case
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxMutex:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxTask:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst[0].pCfg[0].MaxTimers:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.InstId:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.return:0
TEST.END

-- Test Case: UclALOsAndroid_Impl_IUclALOs_Initialize.pthread_create
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Initialize
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_Initialize.pthread_create
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (i < pInst->pCfg->MaxMutex) ==> FALSE
      (2) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (3) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (4) if ((0) != ret) ==> FALSE
      (5) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
      (6) for (i < pInst->pCfg->MaxSem) ==> FALSE
      (7) if (ret != (0)) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.InstId:1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:1
TEST.VALUE:uut_prototype_stubs.pthread_sigmask.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.return:-1
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Initialize.pInst>> = ( &TestUclALOsInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_Memcmp

-- Test Case: BASIS-PATH-001.004
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:BASIS-PATH-001.004
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (((void *)0 != pDst && (void *)0 != pSrc) && (0) < Size) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:<<malloc 3>>
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_STR1:"hi"
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_STR1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_BUFFER
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.Size:1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.return:-1
TEST.END

-- Test Case: UclALOsAndroid_Impl_IUclALOs_Memcmp.pDst_null
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_Memcmp.pDst_null
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pDst:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_FLT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.Size:1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.return:-3
TEST.END

-- Test Case: UclALOsAndroid_Impl_IUclALOs_Memcmp.pSrc_null
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_Memcmp.pSrc_null
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_STR1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pSrc:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.Size:1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.return:-3
TEST.END

-- Test Case: UclALOsAndroid_Impl_IUclALOs_Memcmp.size_null
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_Memcmp.size_null
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_INT2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_INT2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.Size:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.return:-3
TEST.END

-- Test Case: UclALOsAndroid_Impl_IUclALOs_Memcmp.true_Case
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_Memcmp.true_Case
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_FLT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.Size:1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.return:0
TEST.END

-- Test Case: UclALOsAndroid_Impl_IUclALOs_Memcmp.true_Case.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memcmp
TEST.NEW
TEST.NAME:UclALOsAndroid_Impl_IUclALOs_Memcmp.true_Case.001
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pDst:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.pSrc:VECTORCAST_FLT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.Size:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.return:-1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcmp.return:0
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_Memcpy

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memcpy
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (((void *)0 != pDst && (void *)0 != pSrc) && (0) < Size) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pDst:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pSrc:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.Size:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.return:-3
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memcpy
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (((void *)0 != pDst && (void *)0 != pSrc) && (0) < Size) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pDst:VECTORCAST_INT3
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pSrc:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.Size:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.return:-3
TEST.END

-- Test Case: BASIS-PATH-001.002
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memcpy
TEST.NEW
TEST.NAME:BASIS-PATH-001.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (((void *)0 != pDst && (void *)0 != pSrc) && (0) < Size) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pDst:VECTORCAST_INT3
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pSrc:VECTORCAST_BUFFER
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.Size:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.return:-3
TEST.END

-- Test Case: BASIS-PATH-001.003
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memcpy
TEST.NEW
TEST.NAME:BASIS-PATH-001.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (((void *)0 != pDst && (void *)0 != pSrc) && (0) < Size) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pDst:VECTORCAST_INT3
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.pSrc:VECTORCAST_BUFFER
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.Size:1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memcpy.return:0
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_Memset

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memset
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != pBuffer && (0) < Size) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.pBuffer:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.val:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.Size:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.return:-3
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memset
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != pBuffer && (0) < Size) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.pBuffer:VECTORCAST_INT2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.val:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.Size:1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.return:0
TEST.END

-- Test Case: BASIS-PATH-001.002
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Memset
TEST.NEW
TEST.NAME:BASIS-PATH-001.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != pBuffer && (0) < Size) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.pBuffer:VECTORCAST_INT2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.val:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.Size:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Memset.return:-3
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_MutexCreate

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != pMutexId) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pMutexId:<<null>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((void *)0 != pMutexId) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pMutexId:<<null>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 != pMutexId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxMutex) ==> FALSE
      (5) if (i == pInst->pCfg->MaxMutex && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg[0].MaxMutex:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pMutexId:<<malloc 1>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.return:-1
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((void *)0 != pMutexId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxMutex) ==> FALSE
      (5) if (i == pInst->pCfg->MaxMutex && Ret != (Ucl_ReturnType)0) ==> TRUE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pMutexId:<<malloc 1>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((void *)0 != pMutexId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxMutex) ==> TRUE
      (3) if ((eUclOsMutexResState_UnInit) == (pInst->pCfg->pMutexList[i]).State || (eUclOsMutexResState_Destroyed) == (pInst->pCfg->pMutexList[i]).State) ==> FALSE
      (5) if (i == pInst->pCfg->MaxMutex && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 5
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst.pCfg.MaxMutex ) in branches 2/5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg[0].MaxMutex:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pMutexId:<<malloc 1>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((void *)0 != pMutexId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxMutex) ==> TRUE
      (3) if ((eUclOsMutexResState_UnInit) == (pInst->pCfg->pMutexList[i]).State || (eUclOsMutexResState_Destroyed) == (pInst->pCfg->pMutexList[i]).State) ==> FALSE
      (5) if (i == pInst->pCfg->MaxMutex && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 5
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst.pCfg.MaxMutex ) in branches 2/5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidMutexList[0].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pMutexId:<<malloc 1>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.return:0
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst>> = ( &TestUclALOsInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((void *)0 != pMutexId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxMutex) ==> TRUE
      (3) if ((eUclOsMutexResState_UnInit) == (pInst->pCfg->pMutexList[i]).State || (eUclOsMutexResState_Destroyed) == (pInst->pCfg->pMutexList[i]).State) ==> TRUE
      (4) if (0 == pthread_mutex_init(&((pInst->pCfg->pMutexList[i]).mutex), &attr)) ==> TRUE
      (5) if (i == pInst->pCfg->MaxMutex && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
      Cannot set Ret due to assignment
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst.pCfg.MaxMutex ) in branches 2/5
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg[0].MaxMutex:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pMutexId:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_init.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.return:0
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexCreate
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((void *)0 != pMutexId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxMutex) ==> TRUE
      (3) if ((eUclOsMutexResState_UnInit) == (pInst->pCfg->pMutexList[i]).State || (eUclOsMutexResState_Destroyed) == (pInst->pCfg->pMutexList[i]).State) ==> TRUE
      (4) if (0 == pthread_mutex_init(&((pInst->pCfg->pMutexList[i]).mutex), &attr)) ==> FALSE
      (5) if (i == pInst->pCfg->MaxMutex && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 5
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst.pCfg.MaxMutex ) in branches 2/5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg[0].MaxMutex:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.pMutexId:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_init.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexCreate.return:-1
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_MutexDestroy

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> FALSE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].MaxMutex:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.MutexId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> FALSE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].MaxMutex:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.MutexId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_Created) == (pInst->pCfg->pMutexList[MutexId]).State || (eUclOsMutexResState_UnLocked) == (pInst->pCfg->pMutexList[MutexId]).State) ==> FALSE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.MutexId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.return:-2
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_Created) == (pInst->pCfg->pMutexList[MutexId]).State || (eUclOsMutexResState_UnLocked) == (pInst->pCfg->pMutexList[MutexId]).State) ==> FALSE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_UnLocked
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.MutexId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.return:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_Created) == (pInst->pCfg->pMutexList[MutexId]).State || (eUclOsMutexResState_UnLocked) == (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == pthread_mutex_destroy(&((pInst->pCfg->pMutexList[MutexId]).mutex))) ==> FALSE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 4
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_destroy.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_Created) == (pInst->pCfg->pMutexList[MutexId]).State || (eUclOsMutexResState_UnLocked) == (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == pthread_mutex_destroy(&((pInst->pCfg->pMutexList[MutexId]).mutex))) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_destroy.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexDestroy.return:0
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_MutexLock

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> FALSE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].MaxMutex:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.MutexId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> FALSE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].MaxMutex:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.MutexId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> FALSE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.MutexId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.return:-2
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == pthread_mutex_lock(&((pInst->pCfg->pMutexList[MutexId]).mutex))) ==> FALSE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 4
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_lock.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == pthread_mutex_lock(&((pInst->pCfg->pMutexList[MutexId]).mutex))) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_lock.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.return:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexLock
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == pthread_mutex_lock(&((pInst->pCfg->pMutexList[MutexId]).mutex))) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_lock.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexLock.return:-2
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_MutexTryLock

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> FALSE
      (5) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].MaxMutex:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.MutexId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> FALSE
      (5) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].MaxMutex:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.MutexId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> FALSE
      (5) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.MutexId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.return:-2
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == LockStatus) ==> FALSE
      (4) if (LockStatus != 16) ==> FALSE
      (5) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 5
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:16
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == LockStatus) ==> FALSE
      (4) if (LockStatus != 16) ==> TRUE
      (5) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 5
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.return:-1
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == LockStatus) ==> TRUE
      (5) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.return:0
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexTryLock
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == LockStatus) ==> TRUE
      (5) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_trylock.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexTryLock.return:-2
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_MutexUnlock

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> FALSE
      (4) if ((Ucl_ReturnType)0 != Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].MaxMutex:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.MutexId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> FALSE
      (4) if ((Ucl_ReturnType)0 != Ret) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].MaxMutex:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.MutexId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> FALSE
      (4) if ((Ucl_ReturnType)0 != Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.MutexId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.return:-2
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == pthread_mutex_unlock(&((pInst->pCfg->pMutexList[MutexId]).mutex))) ==> FALSE
      (4) if ((Ucl_ReturnType)0 != Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 4
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_unlock.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == pthread_mutex_unlock(&((pInst->pCfg->pMutexList[MutexId]).mutex))) ==> TRUE
      (4) if ((Ucl_ReturnType)0 != Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_unlock.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.return:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_MutexUnlock
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (MutexId < pInst->pCfg->MaxMutex) ==> TRUE
      (2) if ((eUclOsMutexResState_UnInit) != (pInst->pCfg->pMutexList[MutexId]).State && (eUclOsMutexResState_Destroyed) != (pInst->pCfg->pMutexList[MutexId]).State) ==> TRUE
      (3) if (0 == pthread_mutex_unlock(&((pInst->pCfg->pMutexList[MutexId]).mutex))) ==> TRUE
      (4) if ((Ucl_ReturnType)0 != Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].MaxMutex:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].pMutexList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.pInst[0].pCfg[0].pMutexList[0].State:eUclOsMutexResState_Destroyed
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.MutexId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_mutex_unlock.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_MutexUnlock.return:-2
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_SemCreate

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != pSemId) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pSemId:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.Val:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((void *)0 != pSemId) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pSemId:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.Val:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 != pSemId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxSem) ==> FALSE
      (5) if (i == pInst->pCfg->MaxSem && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].MaxSem:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pSemId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.Val:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.return:-1
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((void *)0 != pSemId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxSem) ==> FALSE
      (5) if (i == pInst->pCfg->MaxSem && Ret != (Ucl_ReturnType)0) ==> TRUE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pSemId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.Val:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((void *)0 != pSemId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxSem) ==> TRUE
      (3) if ((eUclOsSemResState_UnInit) == (pInst->pCfg->pSemList[i]).State || (eUclOsSemResState_Destroyed) == (pInst->pCfg->pSemList[i]).State) ==> TRUE
      (4) if (sem_init(&((pInst->pCfg->pSemList[i]).sem), 0, Val) < 0) ==> FALSE
      (5) if (i == pInst->pCfg->MaxSem && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
      Cannot set Ret due to assignment
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst.pCfg.MaxSem ) in branches 2/5
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].MaxSem:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pSemId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.Val:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_init.return:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.return:0
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((void *)0 != pSemId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxSem) ==> TRUE
      (3) if ((eUclOsSemResState_UnInit) == (pInst->pCfg->pSemList[i]).State || (eUclOsSemResState_Destroyed) == (pInst->pCfg->pSemList[i]).State) ==> TRUE
      (4) if (sem_init(&((pInst->pCfg->pSemList[i]).sem), 0, Val) < 0) ==> TRUE
      (5) if (i == pInst->pCfg->MaxSem && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 5
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst.pCfg.MaxSem ) in branches 2/5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].MaxSem:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pSemId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.Val:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_init.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.return:-1
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((void *)0 != pSemId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxSem) ==> TRUE
      (3) if ((eUclOsSemResState_UnInit) == (pInst->pCfg->pSemList[i]).State || (eUclOsSemResState_Destroyed) == (pInst->pCfg->pSemList[i]).State) ==> FALSE
      (5) if (i == pInst->pCfg->MaxSem && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 5
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst.pCfg.MaxSem ) in branches 2/5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].MaxSem:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pSemId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.Val:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.return:-1
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemCreate
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((void *)0 != pSemId) ==> TRUE
      (2) for (i < pInst->pCfg->MaxSem) ==> TRUE
      (3) if ((eUclOsSemResState_UnInit) == (pInst->pCfg->pSemList[i]).State || (eUclOsSemResState_Destroyed) == (pInst->pCfg->pSemList[i]).State) ==> FALSE
      (5) if (i == pInst->pCfg->MaxSem && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 5
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst.pCfg.MaxSem ) in branches 2/5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].MaxSem:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_Destroyed
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.pSemId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.Val:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemCreate.return:0
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_SemDestroy

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (SemId < pInst->pCfg->MaxSem) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg[0].MaxSem:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.SemId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SemId < pInst->pCfg->MaxSem) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg[0].MaxSem:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.SemId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SemId < pInst->pCfg->MaxSem) ==> TRUE
      (2) if ((eUclOsSemResState_Created) == (pInst->pCfg->pSemList[SemId]).State) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg[0].MaxSem:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.SemId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.return:-2
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (SemId < pInst->pCfg->MaxSem) ==> TRUE
      (2) if ((eUclOsSemResState_Created) == (pInst->pCfg->pSemList[SemId]).State) ==> TRUE
      (3) if (0 == sem_destroy(&((pInst->pCfg->pSemList[SemId]).sem))) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 4
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg[0].MaxSem:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.SemId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_destroy.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (SemId < pInst->pCfg->MaxSem) ==> TRUE
      (2) if ((eUclOsSemResState_Created) == (pInst->pCfg->pSemList[SemId]).State) ==> TRUE
      (3) if (0 == sem_destroy(&((pInst->pCfg->pSemList[SemId]).sem))) ==> TRUE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg[0].MaxSem:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.SemId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_destroy.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemDestroy.return:0
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_SemPost

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (SemId < pInst->pCfg->MaxSem) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].MaxSem:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.SemId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SemId < pInst->pCfg->MaxSem) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].MaxSem:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.SemId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SemId < pInst->pCfg->MaxSem) ==> TRUE
      (2) if ((eUclOsSemResState_UnInit) != (pInst->pCfg->pSemList[SemId]).State && (eUclOsSemResState_Destroyed) != (pInst->pCfg->pSemList[SemId]).State) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].MaxSem:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.SemId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.return:-2
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (SemId < pInst->pCfg->MaxSem) ==> TRUE
      (2) if ((eUclOsSemResState_UnInit) != (pInst->pCfg->pSemList[SemId]).State && (eUclOsSemResState_Destroyed) != (pInst->pCfg->pSemList[SemId]).State) ==> TRUE
      (3) if (0 == sem_post(&((pInst->pCfg->pSemList[SemId]).sem))) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 4
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].MaxSem:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.SemId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_post.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (SemId < pInst->pCfg->MaxSem) ==> TRUE
      (2) if ((eUclOsSemResState_UnInit) != (pInst->pCfg->pSemList[SemId]).State && (eUclOsSemResState_Destroyed) != (pInst->pCfg->pSemList[SemId]).State) ==> TRUE
      (3) if (0 == sem_post(&((pInst->pCfg->pSemList[SemId]).sem))) ==> TRUE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].MaxSem:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.SemId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_post.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.return:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemPost
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (SemId < pInst->pCfg->MaxSem) ==> TRUE
      (2) if ((eUclOsSemResState_UnInit) != (pInst->pCfg->pSemList[SemId]).State && (eUclOsSemResState_Destroyed) != (pInst->pCfg->pSemList[SemId]).State) ==> TRUE
      (3) if (0 == sem_post(&((pInst->pCfg->pSemList[SemId]).sem))) ==> TRUE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].MaxSem:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_Destroyed
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.SemId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_post.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemPost.return:-2
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_SemWait

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (SemId < pInst->pCfg->MaxSem) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].MaxSem:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.SemId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SemId < pInst->pCfg->MaxSem) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].MaxSem:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.SemId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SemId < pInst->pCfg->MaxSem) ==> TRUE
      (2) if ((eUclOsSemResState_UnInit) != (pInst->pCfg->pSemList[SemId]).State && (eUclOsSemResState_Destroyed) != (pInst->pCfg->pSemList[SemId]).State) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].MaxSem:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.SemId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.return:-2
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (SemId < pInst->pCfg->MaxSem) ==> TRUE
      (2) if ((eUclOsSemResState_UnInit) != (pInst->pCfg->pSemList[SemId]).State && (eUclOsSemResState_Destroyed) != (pInst->pCfg->pSemList[SemId]).State) ==> TRUE
      (3) if (0 == sem_wait(&((pInst->pCfg->pSemList[SemId]).sem))) ==> FALSE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 4
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].MaxSem:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.SemId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_wait.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (SemId < pInst->pCfg->MaxSem) ==> TRUE
      (2) if ((eUclOsSemResState_UnInit) != (pInst->pCfg->pSemList[SemId]).State && (eUclOsSemResState_Destroyed) != (pInst->pCfg->pSemList[SemId]).State) ==> TRUE
      (3) if (0 == sem_wait(&((pInst->pCfg->pSemList[SemId]).sem))) ==> TRUE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].MaxSem:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.SemId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_wait.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.return:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_SemWait
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (SemId < pInst->pCfg->MaxSem) ==> TRUE
      (2) if ((eUclOsSemResState_UnInit) != (pInst->pCfg->pSemList[SemId]).State && (eUclOsSemResState_Destroyed) != (pInst->pCfg->pSemList[SemId]).State) ==> TRUE
      (3) if (0 == sem_wait(&((pInst->pCfg->pSemList[SemId]).sem))) ==> TRUE
      (4) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].MaxSem:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].pSemList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.pInst[0].pCfg[0].pSemList[0].State:eUclOsSemResState_Destroyed
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.SemId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_wait.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_SemWait.return:-2
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_Shutdown

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Shutdown
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 7
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (4) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (5) for (i < pInst->pCfg->MaxMutex) ==> FALSE
      (6) for (i < pInst->pCfg->MaxSem) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTaskList[0].State:eUclOsTaskResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.InstId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.return:0
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Shutdown
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) for (i < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Running) == (pInst->pCfg->pTimerList[i]).State) ==> FALSE
      (3) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[i]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[i]).State) ==> FALSE
      (4) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (5) for (i < pInst->pCfg->MaxMutex) ==> FALSE
      (6) for (i < pInst->pCfg->MaxSem) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxMutex:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxTask:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxSem:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.InstId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.return:0
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Shutdown
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) for (i < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Running) == (pInst->pCfg->pTimerList[i]).State) ==> FALSE
      (3) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[i]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[i]).State) ==> TRUE
      (4) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (5) for (i < pInst->pCfg->MaxMutex) ==> FALSE
      (6) for (i < pInst->pCfg->MaxSem) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxMutex:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxTask:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxSem:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.return:0
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Shutdown
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) for (i < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Running) == (pInst->pCfg->pTimerList[i]).State) ==> TRUE
      (3) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[i]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[i]).State) ==> FALSE
      (4) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (5) for (i < pInst->pCfg->MaxMutex) ==> FALSE
      (6) for (i < pInst->pCfg->MaxSem) ==> FALSE
   Test Case Generation Notes:
      Cannot set i due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxMutex:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxTask:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].MaxSem:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.InstId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_Shutdown.return:0
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_TaskCreate

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != pThreadId && (void *)0 != pFunc) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pThreadId:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((void *)0 != pThreadId && (void *)0 != pFunc) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pThreadId:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 != pThreadId && (void *)0 != pFunc) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (5) if (i == pInst->pCfg->MaxTask && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg[0].MaxTask:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pFunc:UclImpl_TimerTask
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.return:-1
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 != pThreadId && (void *)0 != pFunc) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (5) if (i == pInst->pCfg->MaxTask && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTaskList[0].State:eUclOsTaskResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTaskList[0].pData:VECTORCAST_INT2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.return:0
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pFunc
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.002
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 != pThreadId && (void *)0 != pFunc) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (5) if (i == pInst->pCfg->MaxTask && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTaskList[0].State:eUclOsTaskResState_Destroyed
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTaskList[0].pData:VECTORCAST_INT2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.return:0
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pFunc
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.003
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 != pThreadId && (void *)0 != pFunc) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (5) if (i == pInst->pCfg->MaxTask && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTaskList[0].State:eUclOsTaskResState_Created
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTaskList[0].pData:VECTORCAST_INT2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.return:0
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pFunc
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.004
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.004
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 != pThreadId && (void *)0 != pFunc) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (5) if (i == pInst->pCfg->MaxTask && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTaskList[0].State:eUclOsTaskResState_Created
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTaskList[0].pData:VECTORCAST_INT2
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:-1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.return:-1
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pFunc
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((void *)0 != pThreadId && (void *)0 != pFunc) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTask) ==> FALSE
      (5) if (i == pInst->pCfg->MaxTask && Ret != (Ucl_ReturnType)0) ==> TRUE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((void *)0 != pThreadId && (void *)0 != pFunc) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTask) ==> TRUE
      (3) if ((eUclOsTaskResState_UnInit) == (pInst->pCfg->pTaskList[i]).State || (eUclOsTaskResState_Destroyed) == (pInst->pCfg->pTaskList[i]).State) ==> FALSE
      (5) if (i == pInst->pCfg->MaxTask && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 5
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst.pCfg.MaxTask ) in branches 2/5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg[0].MaxTask:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg[0].pTaskList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg[0].pTaskList[0].State:eUclOsTaskResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((void *)0 != pThreadId && (void *)0 != pFunc) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTask) ==> TRUE
      (3) if ((eUclOsTaskResState_UnInit) == (pInst->pCfg->pTaskList[i]).State || (eUclOsTaskResState_Destroyed) == (pInst->pCfg->pTaskList[i]).State) ==> TRUE
      (4) if (0 == pthread_create(&((pInst->pCfg->pTaskList[i]).thread), 0, pFunc, pData)) ==> TRUE
      (5) if (i == pInst->pCfg->MaxTask && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set i due to assignment
      Cannot set Ret due to assignment
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst.pCfg.MaxTask ) in branches 2/5
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg[0].MaxTask:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg[0].pTaskList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg[0].pTaskList[0].State:eUclOsTaskResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskCreate
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((void *)0 != pThreadId && (void *)0 != pFunc) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTask) ==> TRUE
      (3) if ((eUclOsTaskResState_UnInit) == (pInst->pCfg->pTaskList[i]).State || (eUclOsTaskResState_Destroyed) == (pInst->pCfg->pTaskList[i]).State) ==> TRUE
      (4) if (0 == pthread_create(&((pInst->pCfg->pTaskList[i]).thread), 0, pFunc, pData)) ==> FALSE
      (5) if (i == pInst->pCfg->MaxTask && Ret != (Ucl_ReturnType)0) ==> FALSE
      (6) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 5
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst.pCfg.MaxTask ) in branches 2/5
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg[0].MaxTask:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg[0].pTaskList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pInst[0].pCfg[0].pTaskList[0].State:eUclOsTaskResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pThreadId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.pthread_create.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskCreate.return:-3
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_TaskDestroy

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ThreadId < pInst->pCfg->MaxTask) ==> FALSE
      (3) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg[0].MaxTask:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.ThreadId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ThreadId < pInst->pCfg->MaxTask) ==> FALSE
      (3) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg[0].MaxTask:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.ThreadId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (ThreadId < pInst->pCfg->MaxTask) ==> TRUE
      (2) if ((eUclOsTaskResState_Created) == (pInst->pCfg->pTaskList[ThreadId]).State) ==> FALSE
      (3) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg[0].MaxTask:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg[0].pTaskList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg[0].pTaskList[0].State:eUclOsTaskResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.ThreadId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.return:-2
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TaskDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (ThreadId < pInst->pCfg->MaxTask) ==> TRUE
      (2) if ((eUclOsTaskResState_Created) == (pInst->pCfg->pTaskList[ThreadId]).State) ==> TRUE
      (3) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg[0].MaxTask:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg[0].pTaskList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.pInst[0].pCfg[0].pTaskList[0].State:eUclOsTaskResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.ThreadId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TaskDestroy.return:0
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_Tick

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_Tick
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_TimerCreate

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].MaxTimers:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pFunc:UclImpl_TimerTask
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-1
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].MaxTimers:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pFunc:UclImpl_TimerTask
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.002
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].MaxTimers:0
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pFunc:UclImpl_TimerTask
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:<<null>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_Last
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.003
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].Type:eUclOsTimerType_OneShot
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pFunc:UclImpl_TimerTask
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:0
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst>> = (&TestUclALOsInst_0);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.004
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.004
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].Type:eUclOsTimerType_OneShot
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_Last
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-3
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst>> = (&TestUclALOsInst_0);
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.005
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.005
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].Type:eUclOsTimerType_OneShot
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pFunc:UclImpl_TimerTask
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MIN>>
TEST.VALUE:uut_prototype_stubs.timer_create.return:-1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-1
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst>> = (&TestUclALOsInst_0);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.006
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.006
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:eUclOsTimerType_OneShot
TEST.VALUE:uut_prototype_stubs.pthread_create.return:-1
TEST.VALUE:uut_prototype_stubs.sem_init.return:-1
TEST.VALUE:uut_prototype_stubs.timer_create.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-1
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst>> = (&TestUclALOsInst_0);
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pFunc
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pFunc>> = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.007
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.007
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set local variable Ret in branch 7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].Type:eUclOsTimerType_OneShot
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pFunc:UclImpl_TimerTask
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_create.return:-1
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-1
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst>> = (&TestUclALOsInst_0);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> TRUE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> TRUE
      (3) if ((eUclOsTimerResState_UnInit) == (pInst->pCfg->pTimerList[i]).State) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 7
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst.pCfg.MaxTimers ) in branches 2/7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> TRUE
      (3) if ((eUclOsTimerResState_UnInit) == (pInst->pCfg->pTimerList[i]).State) ==> TRUE
      (4) if (sem_init(&((pInst->pCfg->pTimerList[i]).sem), 0, 0) < 0) ==> FALSE
      (5) if (0 == timer_create(1, &timer_action, &((pInst->pCfg->pTimerList[i]).timer))) ==> TRUE
      (6) if (ret == (0)) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 7
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst.pCfg.MaxTimers ) in branches 2/7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_create.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_init.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.timer_create.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> TRUE
      (3) if ((eUclOsTimerResState_UnInit) == (pInst->pCfg->pTimerList[i]).State) ==> TRUE
      (4) if (sem_init(&((pInst->pCfg->pTimerList[i]).sem), 0, 0) < 0) ==> FALSE
      (5) if (0 == timer_create(1, &timer_action, &((pInst->pCfg->pTimerList[i]).timer))) ==> TRUE
      (6) if (ret == (0)) ==> TRUE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set i due to assignment
      Cannot set Ret due to assignment
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst.pCfg.MaxTimers ) in branches 2/7
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MIN>>
TEST.VALUE:uut_prototype_stubs.pthread_create.return:0
TEST.VALUE:uut_prototype_stubs.sem_init.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.timer_create.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> TRUE
      (3) if ((eUclOsTimerResState_UnInit) == (pInst->pCfg->pTimerList[i]).State) ==> TRUE
      (4) if (sem_init(&((pInst->pCfg->pTimerList[i]).sem), 0, 0) < 0) ==> FALSE
      (5) if (0 == timer_create(1, &timer_action, &((pInst->pCfg->pTimerList[i]).timer))) ==> FALSE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 7
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst.pCfg.MaxTimers ) in branches 2/7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_init.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.timer_create.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-3
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerCreate
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((((void *)0 != pTimerId && (void *)0 != pFunc) && (void *)0 != pData) && (eUclOsTimerType_Last) > TimerType) ==> TRUE
      (2) for (i < pInst->pCfg->MaxTimers) ==> TRUE
      (3) if ((eUclOsTimerResState_UnInit) == (pInst->pCfg->pTimerList[i]).State) ==> TRUE
      (4) if (sem_init(&((pInst->pCfg->pTimerList[i]).sem), 0, 0) < 0) ==> TRUE
      (7) if (i == pInst->pCfg->MaxTimers && Ret != (Ucl_ReturnType)0) ==> FALSE
      (8) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pFunc in branch 1 since it has a type which requires user code.
      Cannot set i due to assignment
      Cannot set local variable Ret in branch 7
      Conflict: Cannot resolve multiple comparisons ( UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst.pCfg.MaxTimers ) in branches 2/7
      Cannot set local variable Ret in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].MaxTimers:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pTimerId:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.pData:VECTORCAST_INT1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.TimerType:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_init.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerCreate.return:-3
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_TimerDestroy

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> FALSE
      (6) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].MaxTimers:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.TimerId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> FALSE
      (6) if (Ret != (Ucl_ReturnType)0) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].MaxTimers:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.TimerId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State) ==> FALSE
      (6) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.TimerId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.return:-2
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State) ==> TRUE
      (3) if (sem_post(&((pInst->pCfg->pTimerList[TimerId]).sem)) == 0) ==> FALSE
      (6) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 6
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.TimerId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_post.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State) ==> TRUE
      (3) if (sem_post(&((pInst->pCfg->pTimerList[TimerId]).sem)) == 0) ==> TRUE
      (4) while ((pInst->pCfg->pTimerList[TimerId]).State != (eUclOsTimerResState_UnInit) && WaitCount) ==> FALSE
      (5) if ((pInst->pCfg->pTimerList[TimerId]).State != (eUclOsTimerResState_UnInit)) ==> FALSE
      (6) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set (pInst->pCfg->pTimerList[TimerId]).State due to assignment
      Cannot set local variable WaitCount in branch 4
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.TimerId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_post.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.return:0
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State) ==> TRUE
      (3) if (sem_post(&((pInst->pCfg->pTimerList[TimerId]).sem)) == 0) ==> TRUE
      (4) while ((pInst->pCfg->pTimerList[TimerId]).State != (eUclOsTimerResState_UnInit) && WaitCount) ==> FALSE
      (5) if ((pInst->pCfg->pTimerList[TimerId]).State != (eUclOsTimerResState_UnInit)) ==> TRUE
      (6) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set (pInst->pCfg->pTimerList[TimerId]).State due to assignment
      Cannot set local variable WaitCount in branch 4
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.TimerId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_post.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.return:0
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerDestroy
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State) ==> TRUE
      (3) if (sem_post(&((pInst->pCfg->pTimerList[TimerId]).sem)) == 0) ==> TRUE
      (4) while ((pInst->pCfg->pTimerList[TimerId]).State != (eUclOsTimerResState_UnInit) && WaitCount) ==> TRUE
      (5) if ((pInst->pCfg->pTimerList[TimerId]).State != (eUclOsTimerResState_UnInit)) ==> FALSE
      (6) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set (pInst->pCfg->pTimerList[TimerId]).State due to assignment
      Cannot set local variable WaitCount in branch 4
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.TimerId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sem_post.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerDestroy.return:0
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_TimerStart

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> FALSE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].MaxTimers:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.TimerId:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.Timeout:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> FALSE
      (5) if (Ret != (Ucl_ReturnType)0) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].MaxTimers:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.TimerId:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.Timeout:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State) ==> FALSE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.TimerId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.Timeout:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.return:-2
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State) ==> FALSE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Stopped
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.TimerId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.Timeout:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.return:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State) ==> TRUE
      (3) if ((eUclOsTimerType_Periodic) == (pInst->pCfg->pTimerList[TimerId]).Type) ==> FALSE
      (4) if (0 == timer_settime((pInst->pCfg->pTimerList[TimerId]).timer, 0, &TimerSpec, 0)) ==> FALSE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 5
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].Type:eUclOsTimerType_OneShot
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.TimerId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.Timeout:<<MIN>>
TEST.VALUE:uut_prototype_stubs.timer_settime.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.return:-1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State) ==> TRUE
      (3) if ((eUclOsTimerType_Periodic) == (pInst->pCfg->pTimerList[TimerId]).Type) ==> FALSE
      (4) if (0 == timer_settime((pInst->pCfg->pTimerList[TimerId]).timer, 0, &TimerSpec, 0)) ==> TRUE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].Type:eUclOsTimerType_OneShot
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.TimerId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.Timeout:<<MIN>>
TEST.VALUE:uut_prototype_stubs.timer_settime.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.return:0
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStart
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State) ==> TRUE
      (3) if ((eUclOsTimerType_Periodic) == (pInst->pCfg->pTimerList[TimerId]).Type) ==> TRUE
      (4) if (0 == timer_settime((pInst->pCfg->pTimerList[TimerId]).timer, 0, &TimerSpec, 0)) ==> FALSE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 5
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.pInst[0].pCfg[0].pTimerList[0].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.TimerId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.Timeout:<<MIN>>
TEST.VALUE:uut_prototype_stubs.timer_settime.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStart.return:-1
TEST.END

-- Subprogram: UclALOsAndroid_Impl_IUclALOs_TimerStop

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> FALSE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].MaxTimers:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.TimerId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.return:-3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> FALSE
      (5) if (Ret != (Ucl_ReturnType)0) ==> TRUE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].MaxTimers:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.TimerId:<<MAX>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.return:-3
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Running) == (pInst->pCfg->pTimerList[TimerId]).State) ==> FALSE
      (4) if ((eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State) ==> FALSE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_UnInit
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.TimerId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.return:-2
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Running) == (pInst->pCfg->pTimerList[TimerId]).State) ==> FALSE
      (4) if ((eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State) ==> FALSE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.TimerId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.return:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Running) == (pInst->pCfg->pTimerList[TimerId]).State) ==> FALSE
      (4) if ((eUclOsTimerResState_Stopped) == (pInst->pCfg->pTimerList[TimerId]).State || (eUclOsTimerResState_Created) == (pInst->pCfg->pTimerList[TimerId]).State) ==> TRUE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Stopped
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.TimerId:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.return:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Running) == (pInst->pCfg->pTimerList[TimerId]).State) ==> TRUE
      (3) if (0 == timer_settime((pInst->pCfg->pTimerList[TimerId]).timer, 0, &TimerSpec, 0)) ==> FALSE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable Ret in branch 5
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.TimerId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.timer_settime.return:<<MIN>>
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.return:-1
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_IUclALOs_TimerStop
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (TimerId < pInst->pCfg->MaxTimers) ==> TRUE
      (2) if ((eUclOsTimerResState_Running) == (pInst->pCfg->pTimerList[TimerId]).State) ==> TRUE
      (3) if (0 == timer_settime((pInst->pCfg->pTimerList[TimerId]).timer, 0, &TimerSpec, 0)) ==> TRUE
      (5) if (Ret != (Ucl_ReturnType)0) ==> FALSE
   Test Case Generation Notes:
      Cannot set Ret due to assignment
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].MaxTimers:<<MAX>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList:<<malloc 1>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.pInst[0].pCfg[0].pTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.InstId:<<MIN>>
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.TimerId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.timer_settime.return:0
TEST.EXPECTED:UclALOsAndroid_Impl.UclALOsAndroid_Impl_IUclALOs_TimerStop.return:0
TEST.END

-- Subprogram: UclALOsAndroid_Impl_SignalActionThread

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalActionThread
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) while (pTimerInfo->State != (eUclOsTimerResState_Destroyed)) ==> TRUE
      (2) if (ret == (0) && pTimerInfo->State != (eUclOsTimerResState_Destroyed)) ==> FALSE
      (3) if (ret != (0)) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable pTimerInfo in branch 1
      Cannot set local variable pTimerInfo in branch 2
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalActionThread.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.sem_wait.return:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalActionThread
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) while (pTimerInfo->State != (eUclOsTimerResState_Destroyed)) ==> TRUE
      (2) if (ret == (0) && pTimerInfo->State != (eUclOsTimerResState_Destroyed)) ==> FALSE
      (3) if (ret != (0)) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable pTimerInfo in branch 1
      Cannot set local variable pTimerInfo in branch 2
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].State:eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].Type:eUclOsTimerType_Periodic
TEST.VALUE:uut_prototype_stubs.sem_wait.return:<<MIN>>
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].sem
<<UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList>>[0].sem = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.sem
<<UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList>>.sem = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.State
int a = 0;
if(a==0){
<<UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList>>.State = ( eUclOsTimerResState_Destroyed );
a++;
}
else{
<<UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList>>.State = ( eUclOsTimerResState_Destroyed );
}
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.pFunc
<<UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList>>.pFunc = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalActionThread.pData
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalActionThread.pData>> = ( &uclTimerList );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.003
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalActionThread
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) while (pTimerInfo->State != (eUclOsTimerResState_Destroyed)) ==> TRUE
      (2) if (ret == (0) && pTimerInfo->State != (eUclOsTimerResState_Destroyed)) ==> FALSE
      (3) if (ret != (0)) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable pTimerInfo in branch 1
      Cannot set local variable pTimerInfo in branch 2
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Destroyed,eUclOsTimerResState_Created
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalActionThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sem_wait.return:0
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.pFunc
<<UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList>>.pFunc = ( &UclImpl_TimerTask );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalActionThread.pData
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalActionThread.pData>> = ( &uclTimerList );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALOsAndroid_Impl_SignalListenerThread

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) while (pInst->isListenerUp) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:1
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData:VECTORCAST_INT1
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) while (pInst->isListenerUp) ==> TRUE
      (2) if (0 == sigwait(&(pInst->newsigmask), &sig)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:1
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sigwait.return:<<MIN>>
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.001
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) while (pInst->isListenerUp) ==> TRUE
      (2) if (0 == sigwait(&(pInst->newsigmask), &sig)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:1
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sigwait.return:0
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.002
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) while (pInst->isListenerUp) ==> TRUE
      (2) if (0 == sigwait(&(pInst->newsigmask), &sig)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:1
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sigwait.return:0
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.003
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) while (pInst->isListenerUp) ==> TRUE
      (2) if (0 == sigwait(&(pInst->newsigmask), &sig)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].sig:1
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:1
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.sig:1
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sigwait.__sig[0]:1
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.004
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.004
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) while (pInst->isListenerUp) ==> TRUE
      (2) if (0 == sigwait(&(pInst->newsigmask), &sig)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].sig:1
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.UCLALOSCFG_0_SUclALOsAndroidTimerList[0].Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.TestUclALOsInst_0.isListenerUp:1
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.sig:1
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.State:eUclOsTimerResState_Running
TEST.VALUE:UclALOsAndroid_Impl.<<GLOBAL>>.uclTimerList.Type:eUclOsTimerType_Periodic
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.return:<<null>>
TEST.VALUE:uut_prototype_stubs.sem_post.return:-1
TEST.VALUE:uut_prototype_stubs.sigwait.__sig[0]:1
TEST.VALUE_USER_CODE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData
<<UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData>> = ( &TestUclALOsInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) while (pInst->isListenerUp) ==> TRUE
      (2) if (0 == sigwait(&(pInst->newsigmask), &sig)) ==> TRUE
      (3) for (i < pCfg->MaxTimers) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.sigwait.return:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) while (pInst->isListenerUp) ==> TRUE
      (2) if (0 == sigwait(&(pInst->newsigmask), &sig)) ==> TRUE
      (3) for (i < pCfg->MaxTimers) ==> TRUE
      (4) if ((eUclOsTimerResState_Running) == pTimerData->State) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
      Cannot set pTimerData due to assignment
      Cannot set local variable pTimerData in branch 4
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.sigwait.return:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) while (pInst->isListenerUp) ==> TRUE
      (2) if (0 == sigwait(&(pInst->newsigmask), &sig)) ==> TRUE
      (3) for (i < pCfg->MaxTimers) ==> TRUE
      (4) if ((eUclOsTimerResState_Running) == pTimerData->State) ==> TRUE
      (5) if (sig == pTimerData->sig) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
      Cannot set pTimerData due to assignment
      Cannot set local variable pTimerData in branch 4
      Cannot set local variable sig in branch 5
      Cannot set local variable pTimerData in branch 5
      Cannot set local variable pTimerData in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.sigwait.return:0
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) while (pInst->isListenerUp) ==> TRUE
      (2) if (0 == sigwait(&(pInst->newsigmask), &sig)) ==> TRUE
      (3) for (i < pCfg->MaxTimers) ==> TRUE
      (4) if ((eUclOsTimerResState_Running) == pTimerData->State) ==> TRUE
      (5) if (sig == pTimerData->sig) ==> TRUE
      (6) if ((eUclOsTimerType_OneShot) == pTimerData->Type) ==> FALSE
      (7) if (0 != ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
      Cannot set pTimerData due to assignment
      Cannot set local variable pTimerData in branch 4
      Cannot set local variable sig in branch 5
      Cannot set local variable pTimerData in branch 5
      Cannot set local variable pTimerData in branch 6
      Cannot set local variable pTimerData in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.sem_post.return:0
TEST.VALUE:uut_prototype_stubs.sigwait.return:0
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) while (pInst->isListenerUp) ==> TRUE
      (2) if (0 == sigwait(&(pInst->newsigmask), &sig)) ==> TRUE
      (3) for (i < pCfg->MaxTimers) ==> TRUE
      (4) if ((eUclOsTimerResState_Running) == pTimerData->State) ==> TRUE
      (5) if (sig == pTimerData->sig) ==> TRUE
      (6) if ((eUclOsTimerType_OneShot) == pTimerData->Type) ==> FALSE
      (7) if (0 != ret) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
      Cannot set pTimerData due to assignment
      Cannot set local variable pTimerData in branch 4
      Cannot set local variable sig in branch 5
      Cannot set local variable pTimerData in branch 5
      Cannot set local variable pTimerData in branch 6
      Cannot set local variable pTimerData in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.sem_post.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.sigwait.return:0
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:UclALOsAndroid_Impl
TEST.SUBPROGRAM:UclALOsAndroid_Impl_SignalListenerThread
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) while (pInst->isListenerUp) ==> TRUE
      (2) if (0 == sigwait(&(pInst->newsigmask), &sig)) ==> TRUE
      (3) for (i < pCfg->MaxTimers) ==> TRUE
      (4) if ((eUclOsTimerResState_Running) == pTimerData->State) ==> TRUE
      (5) if (sig == pTimerData->sig) ==> TRUE
      (6) if ((eUclOsTimerType_OneShot) == pTimerData->Type) ==> TRUE
      (7) if (0 != ret) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
      Cannot set pTimerData due to assignment
      Cannot set local variable pTimerData in branch 4
      Cannot set local variable sig in branch 5
      Cannot set local variable pTimerData in branch 5
      Cannot set local variable pTimerData in branch 6
      Cannot set local variable pTimerData in branch 7
      Cannot set local variable pTimerData in branch 8
TEST.END_NOTES:
TEST.VALUE:UclALOsAndroid_Impl.UclALOsAndroid_Impl_SignalListenerThread.pData:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.sem_post.return:0
TEST.VALUE:uut_prototype_stubs.sigwait.return:0
TEST.END
