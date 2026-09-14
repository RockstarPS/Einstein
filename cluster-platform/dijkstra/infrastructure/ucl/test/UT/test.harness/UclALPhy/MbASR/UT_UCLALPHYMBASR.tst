-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLALPHYMBASR
-- Unit(s) Under Test: UclALPhyMbASR_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: UclALPhyMuASR_Impl_Hw_GetRemoteMuState

-- Test Case: UclALPhyMuASR_Impl_Hw_GetRemoteMuState.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_GetRemoteMuState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.return:1
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_IsDataAvailable

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsDataAvailable
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 7 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (6) case (regId) ==> 5U
      (7) if (0U != value) ==> FALSE
   Test Case Generation Notes:
      Cannot set value due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.regId:5
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsDataAvailable
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.regId:5
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsDataAvailable
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.regId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsDataAvailable
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.regId:1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsDataAvailable
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.regId:2
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsDataAvailable
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.regId:3
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsDataAvailable
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.regId:4
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsDataAvailable
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL.001
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.pInst[0].pMuRegs[0].INTSR1:123
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.regId:4
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.return:123
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull

-- Test Case: UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.return:1
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.return:0
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty

-- Test Case: UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.return:1
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsDataAvailable.return:0
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_MuClose

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_MuClose
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuClose.pInst:<<malloc 1>>
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_MuOpen

-- Test Case: UclALPhyMuASR_Impl_Hw_MuOpen.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_MuOpen.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.return:1
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_Hw_MuOpen.002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_MuOpen.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRCfg.muBaseAddress:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 6>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.return:0
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_ReadDataRegister

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_ReadDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.regId:5
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_ReadDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.regId:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_ReadDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.regId:1
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_ReadDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.regId:2
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_ReadDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.regId:3
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_ReadDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.regId:4
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_SetMuState

-- Test Case: UclALPhyMuASR_Impl_Hw_SetMuState.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_SetMuState
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_Hw_SetMuState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.state:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:1
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Hw_WriteDataRegister

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_WriteDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:5
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_WriteDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_WriteDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_WriteDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_WriteDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:3
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Hw_WriteDataRegister
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:4
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:<<MIN>>
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALHwCbk_GpioChanged
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALHwCbk_ReceiveComplete

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALHwCbk_ReceiveComplete
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALHwCbk_TransmitComplete

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALHwCbk_TransmitComplete
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALPhy_Initialize

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Initialize.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Initialize.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.return:1
TEST.VALUE:uut_prototype_stubs.Compat_Get_Cpuid.return:1
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Initialize.002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Initialize.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.return:1
TEST.VALUE:uut_prototype_stubs.Compat_Get_Cpuid.return:0
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Initialize.003
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Initialize.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.return:1
TEST.VALUE:uut_prototype_stubs.Compat_Get_Cpuid.return:3
TEST.END

-- Test Case: UclALPhyMuASR_Impl_IUclALPhy_Initialize.004
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_IUclALPhy_Initialize.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.state:1
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuOpen.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Initialize.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALPhy_Read

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Read
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Read
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Read
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
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pData:<<null>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Read.pSize:<<null>>
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALPhy_Shutdown

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((Ucl_ReturnType)0 == Ret) ==> FALSE
   Test Case Generation Notes:

Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Shutdown.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuClose.return:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Shutdown.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuClose.return:0
TEST.END

-- Test Case: BASIS-PATH-002.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:BASIS-PATH-002.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((Ucl_ReturnType)0 == Ret) ==> TRUE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Shutdown.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_MuClose.return:1
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_IUclALPhy_Write

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 == pData || 0U == Size) ==> FALSE
      (2) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((void *)0 == pData || 0U == Size) ==> FALSE
      (2) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> TRUE
      (3) if ((Ucl_ReturnType)(-1) == Ret) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 == pData || 0U == Size) ==> FALSE
      (2) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> TRUE
      (3) if ((Ucl_ReturnType)(-1) == Ret) ==> TRUE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:-1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((void *)0 == pData || 0U == Size) ==> TRUE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.InstId:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.pData:<<null>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_IUclALPhy_Write.Size:0
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_MuStateCheckTimerTask

-- Test Case: UclALPhyMuASR_Impl_MuStateCheckTimerTask.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_MuStateCheckTimerTask.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.return:VECTORCAST_INT1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.state:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.Status:eUclALPhyPeerReadyStatus_NotReady
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.InstId:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.TimerId:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.pCfg
<<UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst>>.pCfg =&TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuASR_Impl_MuStateCheckTimerTask.002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuASR_Impl_MuStateCheckTimerTask.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.UclALPhyInst_1.muState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.return:VECTORCAST_INT1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.state:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.Status:eUclALPhyPeerReadyStatus_NotReady
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.InstId:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.TimerId:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_SetMuState.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.pCfg
<<UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst>>.pCfg =&TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_TimerTask

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_TimerTask
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) case (pInst->muState) ==> 0U
      (2) if (0U == UclALPhyMuASR_Impl_Hw_GetRemoteMuState(pInst)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData:VECTORCAST_INT1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst[0].muState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:1
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_TimerTask
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) case (pInst->muState) ==> 0U
      (2) if (0U == UclALPhyMuASR_Impl_Hw_GetRemoteMuState(pInst)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.muState:2
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.UclALPhyInst_1.muState:MU_SETUP_ST
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.return:VECTORCAST_INT1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst[0].muState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst[0].muState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:1
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.pCfg
<<UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst>>.pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData>> = ( &UclALPhyInst_1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_TimerTask
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) case (pInst->muState) ==> 0U
      (2) if (0U == UclALPhyMuASR_Impl_Hw_GetRemoteMuState(pInst)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.muState:2
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.UclALPhyInst_1.muState:MU_SETUP_ST
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.return:VECTORCAST_INT1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst[0].muState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst[0].muState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.pCfg
<<UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst>>.pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData>> = ( &UclALPhyInst_1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.003
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_TimerTask
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) case (pInst->muState) ==> 0U
      (2) if (0U == UclALPhyMuASR_Impl_Hw_GetRemoteMuState(pInst)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 1
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData:VECTORCAST_INT1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst[0].muState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_TimerTask
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (3) case (pInst->muState) ==> 1U
      (4) if (1U == UclALPhyMuASR_Impl_Hw_GetRemoteMuState(pInst)) ==> TRUE
      (5) for (i < pInst->numIUclALPhyCbk) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 3
      Cannot set variable pInst->pCfg in branch 5 since it requires user code.
      Cannot set local variable pInst in branch 5
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.UclALPhyInst_1.muState:MU_READY_ST
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData>> = ( &UclALPhyInst_1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_TimerTask
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (3) case (pInst->muState) ==> 1U
      (4) if (1U == UclALPhyMuASR_Impl_Hw_GetRemoteMuState(pInst)) ==> TRUE
      (5) for (i < pInst->numIUclALPhyCbk) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 3
      Cannot set variable pInst->pCfg in branch 5 since it requires user code.
      Cannot set local variable pInst in branch 5
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.UclALPhyInst_1.muState:MU_READY_ST
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst>>[0].pCfg =&TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData>> = ( &UclALPhyInst_1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_TimerTask
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (3) case (pInst->muState) ==> 1U
      (4) if (1U == UclALPhyMuASR_Impl_Hw_GetRemoteMuState(pInst)) ==> TRUE
      (5) for (i < pInst->numIUclALPhyCbk) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 3
      Cannot set variable pInst->pCfg in branch 5 since it requires user code.
      Cannot set local variable pInst in branch 5
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.muState:1
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.UclALPhyInst_1.muState:MU_ERROR_ST
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.pInst[0].muState:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:1
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.pCfg
<<UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst>>.pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData>> = ( &UclALPhyInst_1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_TimerTask
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (6) case (pInst->muState) ==> 2U
      (7) if (2U == UclALPhyMuASR_Impl_Hw_GetRemoteMuState(pInst)) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable pInst in branch 6
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.UclALPhyInst_1.muState:10
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.return:VECTORCAST_INT1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_TimerTask.pData>> = ( &UclALPhyInst_1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuASR_Impl_Transfer

-- Test Case: BASIS-PATH-001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 11
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 1U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 4U)) ==> FALSE
      (6) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 0U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0 != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 3U)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.txBufferSize:2
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.rxBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.rxBufferSize:1
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.UclALPhyCfg_0.txRingBufferSize:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferSize:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:0,1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.return:0x10001
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.pCfg
<<UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst>>.pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>>[0].pCfg =&TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 1U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 4U)) ==> FALSE
      (6) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 0U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0 != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 3U)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.txBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.txBufferSize:2
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.rxBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferSize:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].rxBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.return:2
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.pCfg
<<UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst>>.pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>>[0].pCfg =&TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-001.002
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-001.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 1U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 4U)) ==> FALSE
      (6) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 0U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0 != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 3U)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.txBufferSize:2
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.rxBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.rxBufferSize:1
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.UclALPhyCfg_0.txRingBufferSize:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferSize:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.return:0x10001
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.pCfg
<<UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst>>.pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>>[0].pCfg =&TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-001.003
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-001.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 1U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 4U)) ==> FALSE
      (6) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 0U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0 != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 3U)) ==> FALSE
   Test Case Generation Notes:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.txBufferSize:2
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.rxBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.rxBufferSize:1
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.UclALPhyCfg_0.txRingBufferSize:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferSize:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.return:0x10001
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.pCfg
<<UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst>>.pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>>[0].pCfg =&TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 1U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 4U)) ==> FALSE
      (6) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 0U)) ==> TRUE
      (7) if (1U == pInst->rxBufferState) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0 != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 3U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return 'equal to' and 'not equal to' same value in branches 1/6
      Cannot set pInst->rxBufferState due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 1U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 4U)) ==> FALSE
      (6) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 0U)) ==> TRUE
      (7) if (1U == pInst->rxBufferState) ==> TRUE
      (8) if (1U == pInst->rxBufferState && 0 != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 3U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return 'equal to' and 'not equal to' same value in branches 1/6
      Cannot set pInst->rxBufferState due to assignment
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 1U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 4U)) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> FALSE
      (5) if (0 < TxSize && (Ucl_ReturnType)0 == Ret) ==> FALSE
      (6) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 0U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0 != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 3U)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable TxSize in branch 5
      Cannot set local variable Ret in branch 5
      Conflict: Trying to set variable UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return 'equal to' and 'not equal to' same value in branches 3/8
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRInst.txBufferSize:<<MIN-1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferSize:<<MIN-1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 1U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 4U)) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> FALSE
      (5) if (0 < TxSize && (Ucl_ReturnType)0 == Ret) ==> TRUE
      (6) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 0U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0 != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 3U)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable TxSize in branch 5
      Cannot set local variable Ret in branch 5
      Conflict: Trying to set variable UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return 'equal to' and 'not equal to' same value in branches 3/8
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.<<GLOBAL>>.TestSUclALPhyMuASRCfg.txRingBufferSize:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].txBufferSize:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].rxBufferState:<<MIN>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst[0].txBufferSize:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:2
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:2
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 11 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 1U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 4U)) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> TRUE
      (5) if (0 < TxSize && (Ucl_ReturnType)0 == Ret) ==> FALSE
      (6) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 0U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0 != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 3U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return 'equal to' and 'not equal to' same value in branches 3/8
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.regId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.return:0x10000
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>>[0].pCfg =&TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.001
TEST.UNIT:UclALPhyMbASR_Impl
TEST.SUBPROGRAM:UclALPhyMuASR_Impl_Transfer
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 1U)) ==> FALSE
      (3) if (2U == pInst->txBufferState && 0U != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 4U)) ==> TRUE
      (4) if ((Ucl_ReturnType)0 == UclALOs_MutexLock(0, pInst->txRingBufferMutexId)) ==> TRUE
      (5) if (0 < TxSize && (Ucl_ReturnType)0 == Ret) ==> FALSE
      (6) if (0U != UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull(pInst, 0U)) ==> FALSE
      (8) if (1U == pInst->rxBufferState && 0 != UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty(pInst, 3U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return 'equal to' and 'not equal to' same value in branches 3/8
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister
TEST.STUB:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.regId:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_WriteDataRegister.value:1
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.regId:0
TEST.VALUE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.return:0xFFFFF
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_IsTransmitRegisterEmpty.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Hw_ReadDataRegister.pInst>>[0].pCfg = &TestSUclALPhyMuASRCfg;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst.pInst[0].pCfg
<<UclALPhyMbASR_Impl.UclALPhyMuASR_Impl_Transfer.pInst>>[0].pCfg =&TestSUclALPhyMuASRCfg;
TEST.END_VALUE_USER_CODE:
TEST.END
