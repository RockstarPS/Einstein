-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLALPHYMUQNX_IMPL
-- Unit(s) Under Test: UclALPhyMuQnx_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclALPhyMuQnx_Impl

-- Subprogram: UclALPhyMuQnx_Impl_Hw_GetRemoteMuState

-- Test Case: UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:7
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:7
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[1]::EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull

-- Test Case: UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:0xF000000
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.rxRegId:3
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.002
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:0x0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.rxRegId:0
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:0
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty

-- Test Case: UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:0xF00000
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.txRegId:3
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.002
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:0x0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.txRegId:3
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:0
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_MuClose

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuClose.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuClose
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuClose.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_MuOpen

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.return:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:0
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:UCL_E_OK
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.002
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.return:<<null>>
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:0
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:UCL_E_OK
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.004
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:0
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:UCL_E_NOK
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap_device_memory.return
int var = -1;
int var1 = 0;
int *ptr= &var;
int *ptr1 = &var1;
static int count =0;
if(count == 0)
{
<<uut_prototype_stubs.mmap_device_memory.return>> = *ptr1;
count = count+1;
}
else if(count ==1)
{
<<uut_prototype_stubs.mmap_device_memory.return>> = *ptr;
}
else
{
}
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.005
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:0
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:UCL_E_NOK
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap_device_memory.return
int var = -1;
int var1 = 0;
int *ptr= &var;
int *ptr1 = &var1;
static int count =0;
if(count == 0)
{
<<uut_prototype_stubs.mmap_device_memory.return>> = *ptr1;
count = count+1;
}
else if(count ==1)
{
<<uut_prototype_stubs.mmap_device_memory.return>> = *ptr;
}
else
{
}
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.006
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.006
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:0
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:UCL_E_NOK
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap_device_memory.return
int var = 0;
int var1 = 0;
int var2 =-1;
int *ptr= &var;
int *ptr1 = &var1;
int *ptr2 = &var2;
static int count =0;
if(count == 0)
{
<<uut_prototype_stubs.mmap_device_memory.return>> = *ptr1;
count = count+1;
}
else if(count == 1)
{
<<uut_prototype_stubs.mmap_device_memory.return>> = *ptr;
count = count +1;
}
else if(count == 2)
{
<<uut_prototype_stubs.mmap_device_memory.return>> = *ptr2;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.MMapFail
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.MMapFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:-1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_BUFFER[1]:-1
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:0
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:UCL_E_NOK
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.mmap_device_memory.return
<<uut_prototype_stubs.mmap_device_memory.return>> = ( -1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Hw_MuOpen.ThreadCtlFail
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_MuOpen.ThreadCtlFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_memory.return:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:-1
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:UCL_E_NOK
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Hw_SetMuState

-- Test Case: UclALPhyMuQnx_Impl_Hw_SetMuState.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Hw_SetMuState
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Hw_SetMuState.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.CR:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState.state:1
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:1
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.CR:1
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_SetMuState.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_IUclALPhy_Initialize

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Initialize.003
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Initialize.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Initialize.004
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Initialize.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuOpen.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Initialize.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_IUclALPhy_Read

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Read.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Read.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pData:<<malloc 10>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize:<<malloc 4>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Read.IPSizeNULL
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Read.IPSizeNULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pData:<<malloc 10>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize:<<null>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Read.InputBufferNULL
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Read.InputBufferNULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pData:<<null>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize:<<malloc 4>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Read.MutexLockFailed
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Read.MutexLockFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pData:<<malloc 10>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize:<<malloc 4>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Read.ZeroByteIPBuffer
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Read.ZeroByteIPBuffer
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pData:<<malloc 10>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize:<<malloc 4>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pSize[0]:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_IUclALPhy_Shutdown

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.return:UCL_E_OK
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.002
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_MuClose.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Shutdown.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_IUclALPhy_Write

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_MUNotMapped
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_MUNotMapped
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<null>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<malloc 10>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.Size:10
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Write.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Write.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<malloc 10>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.Size:10
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Write.InputBufferNull
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Write.InputBufferNull
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<malloc 9>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<null>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.Size:0
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Write.MutexFail
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Write.MutexFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<malloc 10>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.Size:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Write.RbWriteFailed
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Write.RbWriteFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<malloc 10>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.Size:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_IUclALPhy_Write.ZeroByteWrite
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_IUclALPhy_Write.ZeroByteWrite
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pData:<<malloc 10>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.Size:0
TEST.EXPECTED:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_MuStateCheckTimerTask

-- Test Case: UclALPhyMuQnx_Impl_MuStateCheckTimerTask_MuStateLocked
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_MuStateCheckTimerTask_MuStateLocked
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_READY_ST
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_READY_ST
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_MuStateCheckTimerTask_MuStateReadyMuStateSetUp
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_MuStateCheckTimerTask_MuStateReadyMuStateSetUp
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_READY_ST
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_SETUP_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_ERROR_ST
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_MuStateCheckTimerTask_MuStateSetUpMuStateReady
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_MuStateCheckTimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_MuStateCheckTimerTask_MuStateSetUpMuStateReady
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs:<<malloc 1>>
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_SETUP_ST
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muStateChkTimerTaskId:1
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_READY_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_ERROR_ST
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_MuStateCheckTimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_TimerTask

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.MuStateInit
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.MuStateInit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_INIT_ST
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferSize:100
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:0x1
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_SETUP_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_SETUP_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]:0x80E00000
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[1]:0x80E02000
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[2..3]:MU_BUFFER_IDLE
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateError
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateError
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_ERROR_ST
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_SETUP_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]:MU_BUFFER_IDLE
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[1]:MU_BUFFER_IDLE
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[2..3]:MU_BUFFER_IDLE
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[1]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateReady
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateReady
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_READY_ST
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferSize:100
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:0xFF00002
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_READY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[1]:0x640002
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateReady.RemoteMuStateStateSetUp
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateReady.RemoteMuStateStateSetUp
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_READY_ST
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_SETUP_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_READY_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0..3]:MU_BUFFER_IDLE
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateReady.RemoteMuStateStateSetUp.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateReady.RemoteMuStateStateSetUp.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_READY_ST
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.mu_debug:1
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:2
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_READY_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0..3]:MU_BUFFER_IDLE
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateSetUp
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateSetUp
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_SETUP_ST
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_READY_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_IDLE
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferSize:MU_BUFFER_SIZE
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[1]:0x4000002
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateSetUp.RemoteMuStateSetUp
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.MuStateInit.MuStateSetUp.RemoteMuStateSetUp
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_SETUP_ST
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_SETUP_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_SETUP_ST
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.MuStateInit.RemoteMuStateInit
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.MuStateInit.RemoteMuStateInit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:MU_INIT_ST
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_INIT_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0..1]:0x0
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[2..3]:0
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.CR:0
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_TimerTask.MuStateInit.RemoteMuStateInit.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_TimerTask.MuStateInit.RemoteMuStateInit.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.muState:4
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.return:<<null>>
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_GetRemoteMuState.return:MU_INIT_ST
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0..1]:0x0
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[2..3]:0
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.CR:0
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_TimerTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhyMuQnx_Impl_Transfer

-- Test Case: UclALPhyMuQnx_Impl_Transfer.MutexLockFail
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Transfer.MutexLockFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]:0
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:0x800007
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]:0x0
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Transfer.RB_read_fail
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Transfer.RB_read_fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]:0
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:0x800007
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]:0x0
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Transfer.RR1Empty
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Transfer.RR1Empty
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]:0
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:0x800007
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]:0x0
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Transfer.RxBufferStateZero
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Transfer.RxBufferStateZero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferSize:100
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx2.SR:0xCC00007
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_READY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_IDLE
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx2 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Transfer.RxSizeZero
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Transfer.RxSizeZero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_READY
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferSize:100
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx1.SR:0xF00000
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsTransmitRegisterEmpty.return:1
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_READY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx1.TR[1]:0x640002
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx1 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Transfer.TR0Full
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Transfer.TR0Full
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferSize:100
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]:0
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:0x4400007
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]:0x0
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[1]:0x640002
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Transfer.TR0Full.001
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Transfer.TR0Full.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferSize:100
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx3.SR:0xC400007
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_IDLE
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx3.TR[1]:0x640002
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx3
 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Transfer.TR0Full.002
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Transfer.TR0Full.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferSize:100
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx3.SR:0xC400007
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_IDLE
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_EMPTY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx3.TR[1]:0x640002
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx3
 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhyMuQnx_Impl_Transfer.TR1Full
TEST.UNIT:UclALPhyMuQnx_Impl
TEST.SUBPROGRAM:UclALPhyMuQnx_Impl_Transfer
TEST.NEW
TEST.NAME:UclALPhyMuQnx_Impl_Transfer.TR1Full
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull
TEST.VALUE:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.SR:0x800007
TEST.VALUE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Hw_IsReceiveRegisterFull.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.txBufferState:MU_BUFFER_READY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.rxBufferState:MU_BUFFER_READY
TEST.EXPECTED:UclALPhyMuQnx_Impl.<<GLOBAL>>.MuQnx.TR[0]:0xA0001
TEST.ATTRIBUTES:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs[0].TR[1]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0.pMuRegs
<<UclALPhyMuQnx_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pMuRegs = ( &MuQnx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst
<<UclALPhyMuQnx_Impl.UclALPhyMuQnx_Impl_Transfer.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
