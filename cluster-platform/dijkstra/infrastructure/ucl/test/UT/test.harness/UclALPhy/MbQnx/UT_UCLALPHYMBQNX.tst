-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLALPHYMBQNX
-- Unit(s) Under Test: UclALPhyMbQnx_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: UclALPhyMuQnx_Impl_Hw_GetRemoteMuState

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:5
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_IsDataAvailable

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (6) case (regId) ==> 5U
      (7) if (0U != value) ==> TRUE
   Test Case Generation Notes:
      Cannot set value due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:5
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (6) case (regId) ==> 5U
      (7) if (0U != value) ==> TRUE
   Test Case Generation Notes:
      Cannot set value due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs[0].INTSR1:32
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:5
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) case (regId) ==> 0U
      (7) if (0U != value) ==> FALSE
   Test Case Generation Notes:
      Cannot set value due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (2) case (regId) ==> 1U
      (7) if (0U != value) ==> FALSE
   Test Case Generation Notes:
      Cannot set value due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (3) case (regId) ==> 2U
      (7) if (0U != value) ==> FALSE
   Test Case Generation Notes:
      Cannot set value due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:2
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (4) case (regId) ==> 3U
      (7) if (0U != value) ==> FALSE
   Test Case Generation Notes:
      Cannot set value due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:3
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (5) case (regId) ==> 4U
      (7) if (0U != value) ==> FALSE
   Test Case Generation Notes:
      Cannot set value due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:4
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_IsDataAvailable.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_IsDataAvailable.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pMuRegs[0].INTSR1:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:7
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.return:1
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.rxRegId:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.return:1
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.NOTES:
   No branches in subprogram
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.rxRegId:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.txRegId:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.NOTES:
   No branches in subprogram
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.txRegId:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.regId:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.return:1
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsDataAvailable.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_MuClose

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuClose.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuClose
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuClose.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pTxShMemBuffer:<<malloc 3>>
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pTxShMemBuffer:"16"
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pRxShMemBuffer:<<malloc 3>>
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pRxShMemBuffer:"16"
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose.return:0
TEST.VALUE:uut_prototype_stubs.munmap_device_memory.return:0
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_MuOpen

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:0
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:-1
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.002
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:2
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxCfg.muBaseAddress:0x100C0000
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:0
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.__addr:<<null>>
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.__len:0x100
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.__physical:0x100C0000
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.return:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap_device_memory.__flags
<<uut_prototype_stubs.mmap_device_memory.__flags>> =  0x00000100 | 0x00000200 | 0x00000800;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.003
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pMuRegs:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxCfg.muBaseAddress:0x100C0000
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:0
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.__addr:<<null>>
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.__len:0x100
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.__physical:0x100C0000
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap_device_memory.__flags
<<uut_prototype_stubs.mmap_device_memory.__flags>> =  0x00000100 | 0x00000200 | 0x00000800;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap_device_memory.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1) 
{ 
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 2; 
<<uut_prototype_stubs.mmap_device_memory.return>> = <<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxCfg>>.muBaseAddress; 
} 
else if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 2) 
{ 
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 3; 
<<uut_prototype_stubs.mmap_device_memory.return>> = <<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxCfg>>.txShmMemPhyAddr; 
} 
else if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 3) 
{ 
<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 4; 
<<uut_prototype_stubs.mmap_device_memory.return>> = MAP_FAILED; 
} 
else 
{ 
} 
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.004
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pMuRegs:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxCfg.muBaseAddress:0x100C0000
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:1
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.__addr:<<null>>
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.__len:0x100
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.__physical:0x100C0000
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap_device_memory.__flags
<<uut_prototype_stubs.mmap_device_memory.__flags>> =  0x00000100 | 0x00000200 | 0x00000800;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap_device_memory.return

TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.005
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:-1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.z:-1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pTxShMemBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxCfg.muBaseAddress:0xFFFF
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:0
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap_device_memory.return
<<uut_prototype_stubs.mmap_device_memory.return>> = ( -1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = ( &TestSUclALPhyMuQnxCfg );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.006
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.006
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:-1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.z:-1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pTxShMemBuffer:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxCfg.muBaseAddress:0xFFFF
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:0
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap_device_memory.return
<<uut_prototype_stubs.mmap_device_memory.return>> = ( -1,0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = ( &TestSUclALPhyMuQnxCfg );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_ReadDataRegister

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (6) case (regId) ==> 5U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:5
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) case (regId) ==> 0U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (2) case (regId) ==> 1U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:1
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (3) case (regId) ==> 2U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:2
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-005
TEST.BASIS_PATH:5 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (4) case (regId) ==> 3U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:3
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-006
TEST.BASIS_PATH:6 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (5) case (regId) ==> 4U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:4
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_SetMuState

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState.state:<<MIN>>
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_WriteDataRegister

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (6) case (regId) ==> 5U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.regId:5
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) case (regId) ==> 0U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.regId:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (2) case (regId) ==> 1U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.regId:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (3) case (regId) ==> 2U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.regId:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-005
TEST.BASIS_PATH:5 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (4) case (regId) ==> 3U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.regId:3
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.NEW
TEST.NAME:BASIS-PATH-006
TEST.BASIS_PATH:6 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (5) case (regId) ==> 4U
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.regId:4
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_IUclALPhy_Initialize

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Initialize.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Initialize.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState.state:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>>[0].pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Initialize.002
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Initialize.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>>[0].pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_IUclALPhy_Read

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (((void *)0 == pData || (void *)0 == pSize) || 0U == *pSize) ==> FALSE
      (2) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->rxRingBufferMutexId)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (((void *)0 == pData || (void *)0 == pSize) || 0U == *pSize) ==> FALSE
      (2) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->rxRingBufferMutexId)) ==> TRUE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (((void *)0 == pData || (void *)0 == pSize) || 0U == *pSize) ==> TRUE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pData:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize:<<null>>
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_IUclALPhy_Shutdown

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.InstId:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose.return:0
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.002
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.InstId:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose.return:1
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_IUclALPhy_Write

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 == pData || 0U == Size) ==> FALSE
      (2) if ((void *)0 == pInst->pMuRegs) ==> FALSE
      (3) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((void *)0 == pData || 0U == Size) ==> FALSE
      (2) if ((void *)0 == pInst->pMuRegs) ==> FALSE
      (3) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> TRUE
      (4) if ((Ucl_ReturnType)(-1) == Ret) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 == pData || 0U == Size) ==> FALSE
      (2) if ((void *)0 == pInst->pMuRegs) ==> FALSE
      (3) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> TRUE
      (4) if ((Ucl_ReturnType)(-1) == Ret) ==> TRUE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:-1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((void *)0 == pData || 0U == Size) ==> FALSE
      (2) if ((void *)0 == pInst->pMuRegs) ==> TRUE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.Size:1
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:BASIS-PATH-005
TEST.BASIS_PATH:5 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((void *)0 == pData || 0U == Size) ==> TRUE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.Size:0
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_MuStateCheckTimerTask

-- Test Case: UclALPhyMuQnx_Impl_MuStateCheckTimerTask.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_MuStateCheckTimerTask.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pIUclALPhyCbk:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pIUclALPhyCbk[0]:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.return:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.Status:eUclALPhyPeerReadyStatus_Ready
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:0
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.pData>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_MuStateCheckTimerTask.002
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_MuStateCheckTimerTask.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.muState:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.return:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:0
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.pData>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_TimerTask

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.muState:MU_ERROR_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.002
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.muState:MU_INIT_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState.state:MU_SETUP_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_SETUP_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:5
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst>>[0].pCfg =  &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.003
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.muState:MU_SETUP_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState.state:MU_SETUP_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_READY_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.value:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:5
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst>>[0].pCfg =  &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.004
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.muState:MU_INIT_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_INIT_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:5
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst>>[0].pCfg =  &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.005
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.muState:MU_SETUP_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState.state:MU_SETUP_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_INIT_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.value:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:5
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst>>[0].pCfg =  &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.006
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.006
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pIUclALPhyCbk:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pIUclALPhyCbk[0]:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.muState:MU_SETUP_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState.state:MU_SETUP_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst[0].numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst[0].pIUclALPhyCbk:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst[0].pIUclALPhyCbk[0]:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_READY_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.value:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst[0].numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst[0].pIUclALPhyCbk:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst[0].pIUclALPhyCbk[0]:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:5
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:1
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.Status:eUclALPhyPeerReadyStatus_Ready
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst>>[0].pCfg =  &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.007
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.007
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.muState:MU_READY_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_READY_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:5
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:MU_READY_ST
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst>>[0].pCfg =  &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.008
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.008
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.muState:MU_READY_ST
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.regId:5
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:MU_READY_ST
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.pInst>>[0].pCfg =  &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.009
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.009
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.muState:6
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.pCfg
<<UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst>>.pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Transfer

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:2
TEST.END

-- Test Case: BASIS-PATH-001.002
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-001.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:1
TEST.END

-- Test Case: BASIS-PATH-001.003
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-001.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:65537
TEST.END

-- Test Case: BASIS-PATH-001.004
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-001.004
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:65537
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> TRUE
      (7) if (1U == pInst->rxBufferState) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return 'equal to' and 'not equal to' same value in branches 1/6
      Cannot set pInst->rxBufferState due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> TRUE
      (7) if (1U == pInst->rxBufferState) ==> TRUE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return 'equal to' and 'not equal to' same value in branches 1/6
      Cannot set pInst->rxBufferState due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> FALSE
      (5) if (0U < TxSize && (Ucl_ReturnType)0 == Ret) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable TxSize in branch 5
      Cannot set local variable Ret in branch 5
      Conflict: Trying to set variable UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return 'equal to' and 'not equal to' same value in branches 3/8
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.txBufferSize:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferSize:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].txBufferSize:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.pInst[0].txBufferSize:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.regId:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.value:2
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:0
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>>[0].pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> FALSE
      (5) if (0U < TxSize && (Ucl_ReturnType)0 == Ret) ==> TRUE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable TxSize in branch 5
      Cannot set local variable Ret in branch 5
      Conflict: Trying to set variable UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return 'equal to' and 'not equal to' same value in branches 3/8
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> TRUE
      (5) if (0U < TxSize && (Ucl_ReturnType)0 == Ret) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return 'equal to' and 'not equal to' same value in branches 3/8
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferSize:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.001
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> TRUE
      (5) if (0U < TxSize && (Ucl_ReturnType)0 == Ret) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return 'equal to' and 'not equal to' same value in branches 3/8
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferSize:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.002
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> TRUE
      (5) if (0U < TxSize && (Ucl_ReturnType)0 == Ret) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return 'equal to' and 'not equal to' same value in branches 3/8
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferSize:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:0
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.003
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> TRUE
      (5) if (0U < TxSize && (Ucl_ReturnType)0 == Ret) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return 'equal to' and 'not equal to' same value in branches 3/8
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:UclALPhyMbQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 3U)) ==> TRUE
      (2) if (2U == pInst->txBufferState) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 0U)) ==> FALSE
      (6) if (0U != UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull(pInst, 4U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0U != UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty(pInst, 1U)) ==> FALSE
   Test Case Generation Notes:
      Cannot set pInst->txBufferState due to assignment
      Conflict: Trying to set variable UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return 'equal to' and 'not equal to' same value in branches 1/6
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister
TEST.STUB:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbQnx_Impl.<<GLOBAL>>.TestSUclALPhyMuQnxInst.rxBufferState:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.regId:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_WriteDataRegister.value:1
TEST.VALUE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_ReadDataRegister.return:1
TEST.STUB_VAL_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst.pInst[0].pCfg
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst>>[0].pCfg = &TestSUclALPhyMuQnxCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst
<<UclALPhyMbQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>> = &TestSUclALPhyMuQnxInst;
TEST.END_VALUE_USER_CODE:
TEST.END
