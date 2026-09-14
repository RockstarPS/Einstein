-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLALPHYMULINUX_IMPL
-- Unit(s) Under Test: UclALPhyMuLinux_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclALPhyMuLinux_Impl

-- Subprogram: UclALPhyMuLinux_Impl_Hw_GetRemoteMuState

-- Test Case: UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_GetRemoteMuState
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:0
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:0
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull

-- Test Case: UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].SR:0
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].SR:251658240
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty

-- Test Case: UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.True
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.True
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs[0].SR:15728640
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_Hw_MuClose

-- Test Case: UclALPhyMuLinux_Impl_Hw_MuClose.true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_MuClose
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_MuClose.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.pInst[0].pCfg[0].txShmMemPhySize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.pInst[0].pCfg[0].rxShmMemPhySize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.pInst[0].pMuRegs:<<null>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.pInst[0].pTxShMemBuffer:<<malloc 2>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.pInst[0].pTxShMemBuffer:"1"
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.pInst[0].pRxShMemBuffer:<<malloc 2>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.pInst[0].pRxShMemBuffer:"1"
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.return:0
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.return:0
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_Hw_MuOpen

-- Test Case: UclALPhyMuLinux_Impl_Hw_MuOpen.fd_-1
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_MuOpen.fd_-1
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg[0].muBaseAddress:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pTxShMemBuffer:<<malloc 3>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pTxShMemBuffer:"-1"
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.return:-1
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.VALUE:uut_prototype_stubs.mmap.return:VECTORCAST_BUFFER
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.return:-1
TEST.ATTRIBUTES:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]::INPUT_BASE=16
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Hw_MuOpen.if_case_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_MuOpen.if_case_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:-1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1]:-1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg[0].muBaseAddress:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 1>>
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
<<uut_prototype_stubs.mmap.return>> =((void *)-1);
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Hw_MuOpen.mmap_return_fail_RxMembuff
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_MuOpen.mmap_return_fail_RxMembuff
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1]:0
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg[0].muBaseAddress:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.return:0
TEST.ATTRIBUTES:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]::INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
static int cnt=0;
if(cnt ==0){
<<uut_prototype_stubs.mmap.return>> = ( &VECTORCAST_INT1 );
cnt++;
}
else if(cnt == 1){
<<uut_prototype_stubs.mmap.return>> = ( &VECTORCAST_INT1 );
cnt++;
}
else{
<<uut_prototype_stubs.mmap.return>> = ( (void*)-1 );
}

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Hw_MuOpen.mmap_return_fail_Tx
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_MuOpen.mmap_return_fail_Tx
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1]:0
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg[0].muBaseAddress:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.return:0
TEST.ATTRIBUTES:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]::INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
static int cnt=0;
if(cnt ==0){
<<uut_prototype_stubs.mmap.return>> = ( &VECTORCAST_INT1 );
cnt++;
}
else{
<<uut_prototype_stubs.mmap.return>> = ( (void*)-1 );
}

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Hw_MuOpen.pMuRegs_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_MuOpen.pMuRegs_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1]:0
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg[0].muBaseAddress:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.return:0
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.return:0
TEST.ATTRIBUTES:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]::INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap.return
<<uut_prototype_stubs.mmap.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Hw_MuOpen.pMuRegs_zero
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_MuOpen.pMuRegs_zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pCfg[0].muBaseAddress:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.return:0
TEST.VALUE:uut_prototype_stubs.mmap.return:VECTORCAST_INT1
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.return:0
TEST.ATTRIBUTES:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]::INPUT_BASE=16
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_Hw_SetMuState

-- Test Case: UclALPhyMuLinux_Impl_Hw_SetMuState.true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Hw_SetMuState
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Hw_SetMuState.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState.state:1
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState.state:1
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_IUclALPhy_Initialize

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Initialize.All_false_cases
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Initialize.All_false_cases
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Initialize.return:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.return:1
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Initialize.return:1
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Initialize.All_true_cases
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Initialize.All_true_cases
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Initialize.pInst[0].pCfg[0].rxRingBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Initialize.pInst[0].pCfg[0].pRxRingBuffer:<<malloc 2>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Initialize.pInst[0].pCfg[0].pRxRingBuffer:"1"
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Initialize.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Initialize.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Initialize.return:0
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuOpen.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:0
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Initialize.return:0
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_IUclALPhy_Read

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Read.Mutex_lock_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Read.Mutex_lock_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.return:-1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_ReadFrame.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.return:-1
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Read.Mutex_lock_true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Read.Mutex_lock_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pSize[0]:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_ReadFrame.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.return:0
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Read.pData_zero
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Read.pData_zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pData:<<null>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.return:-3
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.return:-3
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Read.pSize_zero
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Read.pSize_zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pSize:<<null>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.return:-3
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.return:-3
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Read.psize_non_zero
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Read.psize_non_zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.return:-3
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Read.return:-3
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_IUclALPhy_Shutdown

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.ret_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.ret_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.return:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.return:1
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.return:1
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.ret_true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.ret_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.pInst[0].txRingBufferMutexId:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.pInst[0].rxRingBufferMutexId:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.pInst[0].timerTaskId:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.return:0
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_MuClose.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerDestroy.return:1
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Shutdown.return:0
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_IUclALPhy_Write

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Write.Mutex_lock_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Write.Mutex_lock_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:0
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:0
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Write.mutex_lock_true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Write.mutex_lock_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:-1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:-1
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Write.pMuRegs_zero
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Write.pMuRegs_zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<null>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:-1
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:-1
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Write.pdata_zero
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Write.pdata_zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pData:<<null>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:-3
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:-3
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Write.ret_true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Write.ret_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:-1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:-1
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:-1
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_IUclALPhy_Write.size_zero
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_IUclALPhy_Write.size_zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pInst[0].pMuRegs:<<null>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.Size:0
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:-3
TEST.EXPECTED:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_IUclALPhy_Write.return:-3
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_MuStateCheckTimerTask

-- Test Case: UclALPhyMuLinux_Impl_MuStateCheckTimerTask.muState_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_MuStateCheckTimerTask.muState_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_MuStateCheckTimerTask.muState_phyCbk_true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_MuStateCheckTimerTask.muState_phyCbk_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].muState:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_MuStateCheckTimerTask.rmtMustate_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_MuStateCheckTimerTask.rmtMustate_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.numIUclALPhyCbk:1
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:2
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:1
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_TimerTask

-- Test Case: UclALPhyMuLinux_Impl_TimerTask.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_TimerTask.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:0
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:2
TEST.EXPECTED:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:0
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_TimerTask.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState_true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_TimerTask.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:0
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].pCfg[0].txShmMemPhyAddr:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].pCfg[0].rxShmMemPhyAddr:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].pTxShMemBuffer:<<malloc 2>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].pTxShMemBuffer:"1"
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].pRxShMemBuffer:<<malloc 2>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].pRxShMemBuffer:"1"
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:1
TEST.EXPECTED:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:0
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_TimerTask.case1_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_TimerTask.case1_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:1
TEST.EXPECTED:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_TimerTask.case1_true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_TimerTask.case1_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:2
TEST.EXPECTED:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_TimerTask.case2_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_TimerTask.case2_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.mu_debug:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:1
TEST.EXPECTED:UclALPhyMuLinux_Impl.<<GLOBAL>>.mu_debug:1
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_TimerTask.case2_true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_TimerTask.case2_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.mu_debug:0
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:2
TEST.EXPECTED:UclALPhyMuLinux_Impl.<<GLOBAL>>.mu_debug:1
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_TimerTask.case3_true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_TimerTask.case3_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_SetMuState
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:3
TEST.EXPECTED:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:3
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_TimerTask.default_true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_TimerTask.default_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:4
TEST.EXPECTED:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:4
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_TimerTask.mdebug_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_TimerTask.mdebug_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:2
TEST.VALUE:UclALPhyMuLinux_Impl.<<GLOBAL>>.mu_debug:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_GetRemoteMuState.return:2
TEST.EXPECTED:UclALPhyMuLinux_Impl.<<GLOBAL>>.mu_debug:1
TEST.VALUE_USER_CODE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData
<<UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuLinux_Impl_Transfer

-- Test Case: UclALPhyMuLinux_Impl_Transfer.TransmitRegisterempty_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Transfer.TransmitRegisterempty_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]:0x2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:0x1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferState:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Transfer.TxSize>0
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Transfer.TxSize>0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Transfer.mutex_lock_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Transfer.mutex_lock_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]:0x2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:0x12340001
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferState:129
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Transfer.mutex_lock_true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Transfer.mutex_lock_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]:0x2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:0x12340001
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferState:129
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Transfer.ret_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Transfer.ret_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Transfer.rxBufferState_false
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Transfer.rxBufferState_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[0]:0x1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].pMuRegs[0].RR[1]:0x2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferState:2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferState:129
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.pInst[0].rxBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.END

-- Test Case: UclALPhyMuLinux_Impl_Transfer.true
TEST.UNIT:UclALPhyMuLinux_Impl
TEST.SUBPROGRAM:UclALPhyMuLinux_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuLinux_Impl_Transfer.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].pMuRegs[0].RR[0]:2
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].pMuRegs[0].RR[1]:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Transfer.pInst[0].txBufferSize:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuLinux_Impl.UclALPhyMuLinux_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.END
