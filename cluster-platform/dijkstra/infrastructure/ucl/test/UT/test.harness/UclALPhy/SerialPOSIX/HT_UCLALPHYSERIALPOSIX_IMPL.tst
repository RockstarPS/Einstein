-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLALPHYSERIALPOSIX_IMPL
-- Unit(s) Under Test: UclALPhySerialPOSIX_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclALPhySerialPOSIX_Impl

-- Subprogram: UclALPhySerialPOSIX_Impl_Hw_Close

-- Test Case: UclALPhySerialPOSIX_Impl_Hw_Close.001
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_Hw_Close
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_Hw_Close.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_Hw_Close.DevFd_Invalid
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_Hw_Close
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_Hw_Close.DevFd_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:-1
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_Hw_Close.Device_Close_Fail
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_Hw_Close
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_Hw_Close.Device_Close_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:uut_prototype_stubs.close.return:UCL_E_NOK
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialPOSIX_Impl_Hw_Open

-- Test Case: UclALPhySerialPOSIX_Impl_Hw_Open.DevFd_Invalid
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_Hw_Open
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_Hw_Open.DevFd_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:0
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Open.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Open.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Open.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_Hw_Open.HwFlowCtrlOn
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_Hw_Open
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_Hw_Open.HwFlowCtrlOn
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyCfg_0.HwFlowCtrlOn:1
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Open.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Open.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Open.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialPOSIX_Impl_Hw_Read

-- Test Case: UclALPhySerialPOSIX_Impl_Hw_Read.BytesRead_GT_Zero
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_Hw_Read
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_Hw_Read.BytesRead_GT_Zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pData[0]:10
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pSize:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.select.return:1
TEST.VALUE:uut_prototype_stubs.read.return:10
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_Hw_Read.BytesRead_LT_Zero
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_Hw_Read
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_Hw_Read.BytesRead_LT_Zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pData[0]:10
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pSize:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.select.return:1
TEST.VALUE:uut_prototype_stubs.read.return:-1
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_Hw_Read.BytesRead_LT_Zero.001
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_Hw_Read
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_Hw_Read.BytesRead_LT_Zero.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pData[0]:10
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pSize:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.select.__readfds[0].fds_bits[0]:0
TEST.VALUE:uut_prototype_stubs.select.return:1
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialPOSIX_Impl_Hw_Write

-- Test Case: UclALPhySerialPOSIX_Impl_Hw_Write.Fail
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_Hw_Write
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_Hw_Write.Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pData[0]:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.Size:10
TEST.VALUE:uut_prototype_stubs.write.return:-1
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_Hw_Write.Fail.BytesSent_EQ_Size
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_Hw_Write
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_Hw_Write.Fail.BytesSent_EQ_Size
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pData[0]:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.Size:10
TEST.VALUE:uut_prototype_stubs.write.return:10
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_Hw_Write.Fail.BytesSent_EQ_Size.001
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_Hw_Write
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_Hw_Write.Fail.BytesSent_EQ_Size.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pData[0]:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.Size:15
TEST.VALUE:uut_prototype_stubs.write.return:10
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.001
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.InstId:0
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclInstCfg.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.002
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Open
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Open.return:UCL_E_NOK
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg
<<UclInstCfg.<<GLOBAL>>.UclALPhyInst_0>>.pCfg = ( &UclALPhyCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Initialize.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialPOSIX_Impl_IUclALPhy_Read

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Read.001
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Read.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Read.Mutex_Lock_Fail
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Read.Mutex_Lock_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Read.PData_NULL
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Read.PData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pData:<<malloc 9>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pData:<<null>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pSize[0]:10
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Read.PSize_Zero
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Read.PSize_Zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pSize:<<null>>
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Read.Size_Zero
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Read.Size_Zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pSize[0]:0
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Read.pInst>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.001
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.002
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Close.return:UCL_E_NOK
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Shutdown.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialPOSIX_Impl_IUclALPhy_Write

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Write.001
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Write.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pData[0]:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.Size:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Write.DevFd_Invalid
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Write.DevFd_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:-1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.Size:10
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Write.Mutex_Lock_Fail
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Write.Mutex_Lock_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.Size:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Write.PData_NULL
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Write.PData_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pData:<<malloc 9>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pData:<<null>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.Size:1
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Write.RB_Full
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Write.RB_Full
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.Size:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_BUFFER_FULL
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.return:UCL_E_BUFFER_FULL
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Write.RB_Write_Fail
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Write.RB_Write_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pData:<<malloc 2>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.Size:10
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_IUclALPhy_Write.Size_Zero
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_IUclALPhy_Write.Size_Zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pData:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.Size:0
TEST.EXPECTED:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_IUclALPhy_Write.pInst>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialPOSIX_Impl_ReceiveTask

-- Test Case: UclALPhySerialPOSIX_Impl_ReceiveTask.001
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_ReceiveTask
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_ReceiveTask.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_ReceiveTask.return:<<null>>
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_ReceiveTask.pData
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_ReceiveTask.pData>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_ReceiveTask.DevFd_Invalid
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_ReceiveTask
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_ReceiveTask.DevFd_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:-1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_ReceiveTask.return:<<null>>
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_ReceiveTask.pData
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_ReceiveTask.pData>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_ReceiveTask.Hw_Read_Ok
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_ReceiveTask
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_ReceiveTask.Hw_Read_Ok
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_ReceiveTask.return:<<null>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Read.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_ReceiveTask.pData
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_ReceiveTask.pData>> = ( &UclALPhyInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialPOSIX_Impl_TransmitTask

-- Test Case: UclALPhySerialPOSIX_Impl_TransmitTask.001
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_TransmitTask
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_TransmitTask.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.return:<<null>>
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_TransmitTask.BytesRead_Zero
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_TransmitTask
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_TransmitTask.BytesRead_Zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.return:<<null>>
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_SemWait.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_TransmitTask.DevFd_Invalid
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_TransmitTask
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_TransmitTask.DevFd_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:-1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.return:<<null>>
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_TransmitTask.Hw_Write_OK
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_TransmitTask
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_TransmitTask.Hw_Write_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.return:<<null>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_SemWait.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_TransmitTask.Hw_Write_OK.001
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_TransmitTask
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_TransmitTask.Hw_Write_OK.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.pCfg[0].txDmaBufferSize:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.return:<<null>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_SemWait.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_TransmitTask.Hw_Write_OK.002
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_TransmitTask
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_TransmitTask.Hw_Write_OK.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.return:<<null>>
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_Hw_Write.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_SemWait.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_TransmitTask.MutexLock_Fail
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_TransmitTask
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_TransmitTask.MutexLock_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.return:<<null>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_SemWait.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialPOSIX_Impl_TransmitTask.SemWait_Fail
TEST.UNIT:UclALPhySerialPOSIX_Impl
TEST.SUBPROGRAM:UclALPhySerialPOSIX_Impl_TransmitTask
TEST.NEW
TEST.NAME:UclALPhySerialPOSIX_Impl_TransmitTask.SemWait_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialPOSIX_Impl.<<GLOBAL>>.UclALPhyInst_0.devFd:1
TEST.VALUE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.return:<<null>>
TEST.VALUE:uut_prototype_stubs.UclALOs_SemWait.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData
<<UclALPhySerialPOSIX_Impl.UclALPhySerialPOSIX_Impl_TransmitTask.pData>> = ( &UclALPhyInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
