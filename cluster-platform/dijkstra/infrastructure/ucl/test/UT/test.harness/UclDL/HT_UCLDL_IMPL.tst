-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLDL_IMPL
-- Unit(s) Under Test: UclDL_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclDL_Impl

-- Subprogram: UclDL_Impl_BpsTimerExpired

-- Test Case: UclDL_Impl_BpsTimerExpired.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_BpsTimerExpired
TEST.NEW
TEST.NAME:UclDL_Impl_BpsTimerExpired.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_BpsTimerExpired.pInst
<<UclDL_Impl.UclDL_Impl_BpsTimerExpired.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_CobsDecode

-- Test Case: UclDL_Impl_CobsDecode.001
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_CobsDecode
TEST.NEW
TEST.NAME:UclDL_Impl_CobsDecode.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsDecode.d:<<malloc 500>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsDecode.dsize:500
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsDecode.ssize:302
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsDecode.return:300
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_CobsDecode.s.s
<<UclDL_Impl.UclDL_Impl_CobsDecode.s>> = ( &TestCobsDecodebuffer[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_CobsDecode_withimproperframe
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_CobsDecode
TEST.NEW
TEST.NAME:UclDL_Impl_CobsDecode_withimproperframe
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsDecode.d:<<malloc 500>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsDecode.dsize:500
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsDecode.ssize:100
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsDecode.return:0
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_CobsDecode.s.s
<<UclDL_Impl.UclDL_Impl_CobsDecode.s>> = ( &TestCobsDecodebuffer[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_CobsDecode_withimproperinputs
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_CobsDecode
TEST.NEW
TEST.NAME:UclDL_Impl_CobsDecode_withimproperinputs
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestCobsDecodebuffer[0]:0x23
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsDecode.d:<<malloc 500>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsDecode.dsize:50
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsDecode.ssize:302
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsDecode.return:0
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_CobsDecode.s.s
<<UclDL_Impl.UclDL_Impl_CobsDecode.s>> = ( &TestCobsDecodebuffer[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_CobsEncode

-- Test Case: UclDL_Impl_CobsEncode.001
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_CobsEncode
TEST.NEW
TEST.NAME:UclDL_Impl_CobsEncode.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsEncode.d:<<malloc 500>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsEncode.dsize:498
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsEncode.ssize:300
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.d[0]:0x1
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.d[1]:0xFF
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.d[2]:0xAA
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.d[3]:0xAA
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.d[256]:0x2D
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.d[257]:0xAA
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.d[258]:0xAA
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.d[298]:0xAA
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.d[299]:0xAA
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.d[300]:0xAA
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.d[301]:0x1
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.return:302
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_CobsEncode.s.s
<<UclDL_Impl.UclDL_Impl_CobsEncode.s>> = ( &TestInputbuffer[0]);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_CobsEncode_Withimproperinputs
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_CobsEncode
TEST.NEW
TEST.NAME:UclDL_Impl_CobsEncode_Withimproperinputs
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsEncode.d:<<malloc 500>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsEncode.dsize:100
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsEncode.ssize:300
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_CobsEncode.return:0
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_CobsEncode.s.s
<<UclDL_Impl.UclDL_Impl_CobsEncode.s>> = ( &TestInputbuffer[0]);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_Decrypt

-- Test Case: UclDL_Impl_Decrypt.001
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_Decrypt
TEST.NEW
TEST.NAME:UclDL_Impl_Decrypt.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.CryInst:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.pData:<<malloc 100>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.Size:100
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Start.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Decrypt.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Done.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_Decrypt.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Decrypt.pInst
<<UclDL_Impl.UclDL_Impl_Decrypt.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Decrypt.pIV.pIV
<<UclDL_Impl.UclDL_Impl_Decrypt.pIV>> = ( &TxIvBuffer );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_Decrypt.numIUclAlCrypto_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_Decrypt
TEST.NEW
TEST.NAME:UclDL_Impl_Decrypt.numIUclAlCrypto_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.pInst:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.pInst[0].numIUclALPhy:0
TEST.END

-- Test Case: UclDL_Impl_Decrypt_CBCdecryptfailedfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_Decrypt
TEST.NEW
TEST.NAME:UclDL_Impl_Decrypt_CBCdecryptfailedfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.CryInst:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.pData:<<malloc 100>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.Size:100
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Start.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Decrypt.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Done.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_Decrypt.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Decrypt.pInst
<<UclDL_Impl.UclDL_Impl_Decrypt.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Decrypt.pIV.pIV
<<UclDL_Impl.UclDL_Impl_Decrypt.pIV>> = ( &TxIvBuffer );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_Decrypt_CBCstartfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_Decrypt
TEST.NEW
TEST.NAME:UclDL_Impl_Decrypt_CBCstartfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.CryInst:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.pData:<<malloc 100>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.Size:100
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Start.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Decrypt.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Done.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_Decrypt.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Decrypt.pInst
<<UclDL_Impl.UclDL_Impl_Decrypt.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Decrypt.pIV.pIV
<<UclDL_Impl.UclDL_Impl_Decrypt.pIV>> = ( &TxIvBuffer );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_Encrypt

-- Test Case: UclDL_Impl_Encrypt.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_Encrypt
TEST.NEW
TEST.NAME:UclDL_Impl_Encrypt.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_Encrypt.CryInst:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_Encrypt.pData:<<malloc 100>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_Encrypt.Size:100
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Start.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Encrypt.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Done.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_Encrypt.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Encrypt.pInst
<<UclDL_Impl.UclDL_Impl_Encrypt.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Encrypt.pIV.pIV
<<UclDL_Impl.UclDL_Impl_Encrypt.pIV>> = ( &TxIvBuffer );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_Encrypt_CBCEncryptfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_Encrypt
TEST.NEW
TEST.NAME:UclDL_Impl_Encrypt_CBCEncryptfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_Encrypt.CryInst:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_Encrypt.pData:<<malloc 100>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_Encrypt.Size:100
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Start.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Encrypt.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Done.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_Encrypt.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Encrypt.pInst
<<UclDL_Impl.UclDL_Impl_Encrypt.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Encrypt.pIV.pIV
<<UclDL_Impl.UclDL_Impl_Encrypt.pIV>> = ( &TxIvBuffer );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_Encrypt_CBCstartfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_Encrypt
TEST.NEW
TEST.NAME:UclDL_Impl_Encrypt_CBCstartfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_Encrypt.CryInst:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_Encrypt.pData:<<malloc 100>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_Encrypt.Size:100
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Start.return:UCL_E_NOK,(2)UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Encrypt.return:UCL_E_OK,UCL_E_NOK,UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CBC_Done.return:(2)UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_Encrypt.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Encrypt.pInst
<<UclDL_Impl.UclDL_Impl_Encrypt.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_Encrypt.pIV.pIV
<<UclDL_Impl.UclDL_Impl_Encrypt.pIV>> = ( &TxIvBuffer );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_GetCMAC

-- Test Case: UclDL_Impl_GetCMAC.false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_GetCMAC
TEST.NEW
TEST.NAME:UclDL_Impl_GetCMAC.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pInst:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pInst[0].numIUclALPhy:0
TEST.END

-- Test Case: UclDL_Impl_GetCMAC.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_GetCMAC
TEST.NEW
TEST.NAME:UclDL_Impl_GetCMAC.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.CryInst:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.KeyType:eUclALCryptoKeyType_EK
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pData:<<malloc 100>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.DataSize:100
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult:<<malloc 4>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:4
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CMAC_Start.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CMAC_Process.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CMAC_Done.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_GetCMAC.pInst
<<UclDL_Impl.UclDL_Impl_GetCMAC.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_GetCMAC_CMACstartfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_GetCMAC
TEST.NEW
TEST.NAME:UclDL_Impl_GetCMAC_CMACstartfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.CryInst:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.KeyType:eUclALCryptoKeyType_EK
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pData:<<malloc 100>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.DataSize:100
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult:<<malloc 4>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:4
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CMAC_Start.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CMAC_Process.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_CMAC_Done.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_GetCMAC.pInst
<<UclDL_Impl.UclDL_Impl_GetCMAC.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_GetFreeSlot

-- Test Case: UclDL_Impl_GetFreeSlot.Mutex_lock_pass_for_loop
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_GetFreeSlot
TEST.NEW
TEST.NAME:UclDL_Impl_GetFreeSlot.Mutex_lock_pass_for_loop
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId[0]:1
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[1]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[2]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[3]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[4]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[5]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[6]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[7]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[15]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[16]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[17]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[18]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[19]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[20]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[21]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst
<<UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_GetFreeSlot.for_loop
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_GetFreeSlot
TEST.NEW
TEST.NAME:UclDL_Impl_GetFreeSlot.for_loop
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 1>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].isFree:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId[0]:1
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst
<<UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_GetFreeSlot.isFree
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_GetFreeSlot
TEST.NEW
TEST.NAME:UclDL_Impl_GetFreeSlot.isFree
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 1>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].msgId:0x1234
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].isFree:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId[0]:2
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst
<<UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_GetFreeSlot.msgId_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_GetFreeSlot
TEST.NEW
TEST.NAME:UclDL_Impl_GetFreeSlot.msgId_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 3>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].msgId:0x1234
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].isFree:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[1].isFree:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[2].isFree:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId:<<malloc 5>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId:"abcd"
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst
<<UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_GetFreeSlot.pSlotId_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_GetFreeSlot
TEST.NEW
TEST.NAME:UclDL_Impl_GetFreeSlot.pSlotId_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 3>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].isFree:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[1].isFree:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[2].isFree:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId:<<malloc 5>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId:"abcd"
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst
<<UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_GetFreeSlot_MutexLockFail
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_GetFreeSlot
TEST.NEW
TEST.NAME:UclDL_Impl_GetFreeSlot_MutexLockFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_GetFreeSlot.pSlotId[0]:0
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_GetFreeSlot.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst
<<UclDL_Impl.UclDL_Impl_GetFreeSlot.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_HeartBeatTimerExpired

-- Test Case: UclDL_Impl_HeartBeatTimerExpired_State_Active
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_HeartBeatTimerExpired
TEST.NEW
TEST.NAME:UclDL_Impl_HeartBeatTimerExpired_State_Active
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_HeartBeatTimerExpired.pInst
<<UclDL_Impl.UclDL_Impl_HeartBeatTimerExpired.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_HeartBeatTimerExpired_State_NotActive
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_HeartBeatTimerExpired
TEST.NEW
TEST.NAME:UclDL_Impl_HeartBeatTimerExpired_State_NotActive
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_RxOnly
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_HeartBeatTimerExpired.pInst
<<UclDL_Impl.UclDL_Impl_HeartBeatTimerExpired.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_HeartBeatTimerExpired_State_SendHBfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_HeartBeatTimerExpired
TEST.NEW
TEST.NAME:UclDL_Impl_HeartBeatTimerExpired_State_SendHBfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendHeartBeat
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendHeartBeat.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_HeartBeatTimerExpired.pInst
<<UclDL_Impl.UclDL_Impl_HeartBeatTimerExpired.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_IUclALPhyCbk_FatalError

-- Test Case: UclDL_Impl_IUclALPhyCbk_FatalError.001
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclALPhyCbk_FatalError
TEST.NEW
TEST.NAME:UclDL_Impl_IUclALPhyCbk_FatalError.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_FatalError.status:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_FatalError.pInst
<<UclDL_Impl.UclDL_Impl_IUclALPhyCbk_FatalError.pInst>> = (& UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged

-- Test Case: UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged_InvalidPeerRdy
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged
TEST.NEW
TEST.NAME:UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged_InvalidPeerRdy
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Initializing
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.status:eUclALPhyPeerReadyStatus_Last
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Initializing
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.pInst
<<UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged_PeerNtRdy
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged
TEST.NEW
TEST.NAME:UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged_PeerNtRdy
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Initializing
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.status:eUclALPhyPeerReadyStatus_NotReady
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_RxOnly
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.pInst
<<UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged_PeerRdy_InvalidDLstate
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged
TEST.NEW
TEST.NAME:UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged_PeerRdy_InvalidDLstate
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Shutdown
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.status:eUclALPhyPeerReadyStatus_Ready
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Shutdown
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.pInst
<<UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged_PeerReadyState
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged
TEST.NEW
TEST.NAME:UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged_PeerReadyState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Initializing
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.status:eUclALPhyPeerReadyStatus_Ready
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.pInst
<<UclDL_Impl.UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable

-- Test Case: UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable.false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable
TEST.NEW
TEST.NAME:UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.receiveProcessingMode:UCLDL_RX_PROCESS_SCHEDULED
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable.InstId:0
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable.pInst
<<UclDL_Impl.UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable
TEST.NEW
TEST.NAME:UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.receiveProcessingMode:UCLDL_RX_PROCESS_ONDEMAND
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable.InstId:0
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable.pInst
<<UclDL_Impl.UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_IUclDL_GetStats

-- Test Case: UclDL_Impl_IUclDL_GetStats.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_GetStats
TEST.NEW
TEST.NAME:UclDL_Impl_IUclDL_GetStats.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.UclALOs_Memcpy
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_GetStats.pInst:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_GetStats.pDLStats:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.UclALOs_Memcpy.InstId:0
TEST.END

-- Subprogram: UclDL_Impl_IUclDL_Initialize

-- Test Case: UclDL_Impl_IUclDL_Initialize.003
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Initialize
TEST.NEW
TEST.NAME:UclDL_Impl_IUclDL_Initialize.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALPhy_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Initialize.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_IUclDL_Initialize.TimerStart_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Initialize
TEST.NEW
TEST.NAME:UclDL_Impl_IUclDL_Initialize.TimerStart_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhy_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Initialize.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_IUclDL_Initialize.True_cases
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Initialize
TEST.NEW
TEST.NAME:UclDL_Impl_IUclDL_Initialize.True_cases
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_HeartBeatTimerExpired
TEST.STUB:UclDL_Impl.UclDL_Impl_BpsTimerExpired
TEST.STUB:UclDL_Impl.UclDL_Impl_LinkDownTimerExpired
TEST.STUB:UclDL_Impl.UclDL_Impl_SecurityTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.numIUclALCrypto:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pIUclALCrypto:<<malloc 2>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pIUclALCrypto[0]:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pIUclALCrypto[1]:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhy_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Initialize.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_IUclDL_Initialize.numIUclAlCrypto>0
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Initialize
TEST.NEW
TEST.NAME:UclDL_Impl_IUclDL_Initialize.numIUclAlCrypto>0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.numIUclALCrypto:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Initialize.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_IUclDL_Initialize.numIUclAlCrypto_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Initialize
TEST.NEW
TEST.NAME:UclDL_Impl_IUclDL_Initialize.numIUclAlCrypto_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Initialize.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Initialize.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_IUclDL_Send

-- Test Case: 001.UclDL_Impl_IUclDL_Send_NomalMsg_withNULLptr
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:001.UclDL_Impl_IUclDL_Send_NomalMsg_withNULLptr
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<null>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Send.return:UCL_E_INVALID_ARGS
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[3]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[4]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[5]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[6]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[7]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[15]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:INPUT_BASE=10
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 002.UclDL_Impl_IUclDL_Send_NormalMsg_PayloadNULL
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:002.UclDL_Impl_IUclDL_Send_NormalMsg_PayloadNULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1000
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 9>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<null>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:0
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Send.return:UCL_E_INVALID_ARGS
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[3]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[4]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[5]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[6]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[7]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 003.UclDL_Impl_IUclDL_Send_NormalMsg_ImproperSize
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:003.UclDL_Impl_IUclDL_Send_NormalMsg_ImproperSize
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1000
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:0
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Send.return:UCL_E_INVALID_ARGS
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 004.UclDL_Impl_IUclDL_Send_MsgInvaliddMsgHdr
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:004.UclDL_Impl_IUclDL_Send_MsgInvaliddMsgHdr
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x180
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1000
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:16
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Send.return:UCL_E_INVALID_ARGS
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 005.UclDL_Impl_IUclDL_Send_NomalMsg_InvalidState
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:005.UclDL_Impl_IUclDL_Send_NomalMsg_InvalidState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1000
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:16
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Send.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 005.UclDL_Impl_IUclDL_Send_SecureMessage_Unauthenticatedstate
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:005.UclDL_Impl_IUclDL_Send_SecureMessage_Unauthenticatedstate
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableSecurity:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x80
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1000
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:16
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Send.return:UCL_E_INVALID_STATE
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 005.UclDL_Impl_IUclDL_Send_SecureMessage_Unauthenticatedstate.false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:005.UclDL_Impl_IUclDL_Send_SecureMessage_Unauthenticatedstate.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableSecurity:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_Authenticated
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x80
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1000
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 005.UclDL_Impl_IUclDL_Send_SecureMessage_msg_hdr_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:005.UclDL_Impl_IUclDL_Send_SecureMessage_msg_hdr_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableSecurity:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_Authenticated
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 006.UclDL_Impl_IUclDL_Send_NormalMessagewithNoFreeSlot
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:006.UclDL_Impl_IUclDL_Send_NormalMessagewithNoFreeSlot
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetFreeSlot
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableSecurity:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_Authenticated
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x40
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1000
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.return:UCL_E_BUSY
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.MutexId:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Send.return:UCL_E_BUSY
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 007.UclDL_Impl_IUclDL_Send_Mutex_lock_fail
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:007.UclDL_Impl_IUclDL_Send_Mutex_lock_fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendMessage
TEST.STUB:UclDL_Impl.UclDL_Impl_GetFreeSlot
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableTSC:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.txCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:0x5577
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 2>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendMessage.return:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_MutexLock.return
static int cnt = 0;
if(cnt ==0){
<<uut_prototype_stubs.UclALOs_MutexLock.return>> = ( UCL_E_OK );
cnt++;
}
else{
<<uut_prototype_stubs.UclALOs_MutexLock.return>> = ( UCL_E_NOK );
}
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 007.UclDL_Impl_IUclDL_Send_NormalMessage_IsSrc_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:007.UclDL_Impl_IUclDL_Send_NormalMessage_IsSrc_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendMessage
TEST.STUB:UclDL_Impl.UclDL_Impl_GetFreeSlot
TEST.STUB:uut_prototype_stubs.UclALOs_Memcpy
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.nodeId:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 4>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableTSC:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.txCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:0x5577
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 2>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendMessage.return:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 007.UclDL_Impl_IUclDL_Send_NormalMessage_Send_msg_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:007.UclDL_Impl_IUclDL_Send_NormalMessage_Send_msg_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendMessage
TEST.STUB:UclDL_Impl.UclDL_Impl_GetFreeSlot
TEST.STUB:uut_prototype_stubs.UclALOs_Memcpy
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.nodeId:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableTSC:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.txCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:0x5577
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 2>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendMessage.return:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 007.UclDL_Impl_IUclDL_Send_NormalMessage_node_id_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:007.UclDL_Impl_IUclDL_Send_NormalMessage_node_id_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendMessage
TEST.STUB:UclDL_Impl.UclDL_Impl_GetFreeSlot
TEST.STUB:uut_prototype_stubs.UclALOs_Memcpy
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.nodeId:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableTSC:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.txCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:0x5577
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 2>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendMessage.return:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 007.UclDL_Impl_IUclDL_Send_NormalMessage_tx_work_buff
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:007.UclDL_Impl_IUclDL_Send_NormalMessage_tx_work_buff
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendMessage
TEST.STUB:UclDL_Impl.UclDL_Impl_GetFreeSlot
TEST.STUB:uut_prototype_stubs.UclALOs_Memcpy
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.nodeId:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.txWorkBufferSize:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableTSC:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.txCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:0x5577
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 2>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendMessage.return:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 007.UclDL_Impl_IUclDL_Send_NormalMessage_withTSC
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:007.UclDL_Impl_IUclDL_Send_NormalMessage_withTSC
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendMessage
TEST.STUB:UclDL_Impl.UclDL_Impl_GetFreeSlot
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableTSC:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.txCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:0x5577
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 2>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendMessage.return:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 007.UclDL_Impl_IUclDL_Send_Securelevel1_Message_CMACfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:007.UclDL_Impl_IUclDL_Send_Securelevel1_Message_CMACfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetFreeSlot
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.txCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x80
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 2>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.return:UCL_E_OK
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xF1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xF2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xF3
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xF4
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:4
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Send.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 007.UclDL_Impl_IUclDL_Send_Securelevel2_Message.003
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:007.UclDL_Impl_IUclDL_Send_Securelevel2_Message.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetFreeSlot
TEST.STUB:UclDL_Impl.UclDL_Impl_Encrypt
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.txCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x100
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 2>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.return:UCL_E_OK
TEST.VALUE:UclDL_Impl.UclDL_Impl_Encrypt.return:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xF1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xF2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xF3
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xF4
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:4
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 007.UclDL_Impl_IUclDL_Send_Securelevel2_Message_Cobsfail
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Send
TEST.NEW
TEST.NAME:007.UclDL_Impl_IUclDL_Send_Securelevel2_Message_Cobsfail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetFreeSlot
TEST.STUB:UclDL_Impl.UclDL_Impl_Encrypt
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.STUB:UclDL_Impl.UclDL_Impl_CobsEncode
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.txCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.InstId:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgHdr:0x80
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload:<<malloc 2>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pMsg[0].Size:2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetFreeSlot.return:UCL_E_OK
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xF1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xF2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xF3
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xF4
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:4
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsEncode.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Send.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Send.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_IUclDL_Shutdown

-- Test Case: UclDL_Impl_IUclDL_Shutdown.shutdown_state
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Shutdown
TEST.NEW
TEST.NAME:UclDL_Impl_IUclDL_Shutdown.shutdown_state
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Shutdown.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhy_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Shutdown.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Shutdown.pInst>> = (& UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_IUclDL_Shutdown.up_state_for_loop
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_IUclDL_Shutdown
TEST.NEW
TEST.NAME:UclDL_Impl_IUclDL_Shutdown.up_state_for_loop
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.UclDL_Impl_IUclDL_Shutdown.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhy_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_IUclDL_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_IUclDL_Shutdown.pInst
<<UclDL_Impl.UclDL_Impl_IUclDL_Shutdown.pInst>> = (& UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_LinkDownTimerExpired

-- Test Case: UclDL_Impl_LinkDownTimerExpired.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_LinkDownTimerExpired
TEST.NEW
TEST.NAME:UclDL_Impl_LinkDownTimerExpired.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Recovery
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_LinkDownTimerExpired.pInst
<<UclDL_Impl.UclDL_Impl_LinkDownTimerExpired.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_NofityErrorCallback

-- Test Case: UclDL_Impl_NofityErrorCallback.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_NofityErrorCallback
TEST.NEW
TEST.NAME:UclDL_Impl_NofityErrorCallback.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_NofityErrorCallback.pInst
<<UclDL_Impl.UclDL_Impl_NofityErrorCallback.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_NofityLinkStatusChanged

-- Test Case: UclDL_Impl_NofityLinkStatusChanged.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_NofityLinkStatusChanged
TEST.NEW
TEST.NAME:UclDL_Impl_NofityLinkStatusChanged.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_NofityLinkStatusChanged.pInst
<<UclDL_Impl.UclDL_Impl_NofityLinkStatusChanged.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_NofityMsgReceived

-- Test Case: UclDL_Impl_NofityMsgReceived.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_NofityMsgReceived
TEST.NEW
TEST.NAME:UclDL_Impl_NofityMsgReceived.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_NofityMsgReceived.pInst
<<UclDL_Impl.UclDL_Impl_NofityMsgReceived.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_NotifyMsgTransmitStatus

-- Test Case: UclDL_Impl_NotifyMsgTransmitStatus.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_NotifyMsgTransmitStatus
TEST.NEW
TEST.NAME:UclDL_Impl_NotifyMsgTransmitStatus.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_NotifyMsgTransmitStatus.pInst
<<UclDL_Impl.UclDL_Impl_NotifyMsgTransmitStatus.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_ProcessAck

-- Test Case: UclDL_Impl_ProcessAck.Ack_status_0x5Au
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessAck
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessAck.Ack_status_0x5Au
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 1>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].msgId:0x1234
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].isFree:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.avgAckLatency:6
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.AckStatus:0x5A
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:2580
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessAck.pInst
<<UclDL_Impl.UclDL_Impl_ProcessAck.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessAck.Mutex_lock_fasle
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessAck
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessAck.Mutex_lock_fasle
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.pInst:<<malloc 1>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.AckStatus:0x6A
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.END

-- Test Case: UclDL_Impl_ProcessAck.Mutex_lock_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessAck
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessAck.Mutex_lock_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.avgAckLatency:6
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.AckStatus:0x0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:2580
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessAck.pInst
<<UclDL_Impl.UclDL_Impl_ProcessAck.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessAck.for_loop_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessAck
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessAck.for_loop_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 1>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].msgId:0x1234
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].isFree:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.avgAckLatency:6
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.AckStatus:0x0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:2580
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessAck.pInst
<<UclDL_Impl.UclDL_Impl_ProcessAck.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessAck.isFree_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessAck
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessAck.isFree_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 1>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].msgId:0x1234
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].isFree:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.avgAckLatency:6
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.AckStatus:0x0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:2580
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessAck.pInst
<<UclDL_Impl.UclDL_Impl_ProcessAck.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessAck.msgId_no_match
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessAck
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessAck.msgId_no_match
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 1>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].msgId:0x123
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].isFree:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.avgAckLatency:6
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_ProcessAck.AckStatus:0x0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:2580
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessAck.pInst
<<UclDL_Impl.UclDL_Impl_ProcessAck.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_ProcessAckTimer

-- Test Case: UclDL_Impl_ProcessAckTimer.for_loop
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessAckTimer
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessAckTimer.for_loop
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 1>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].isFree:1
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:3010
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessAckTimer.pInst
<<UclDL_Impl.UclDL_Impl_ProcessAckTimer.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessAckTimer.for_loop_timeNow_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessAckTimer
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessAckTimer.for_loop_timeNow_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxAckTimeoutMs:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 1>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].isFree:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].timestamp:1
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:17107567574646778907
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessAckTimer.pInst
<<UclDL_Impl.UclDL_Impl_ProcessAckTimer.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessAckTimer.mutex_lock_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessAckTimer
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessAckTimer.mutex_lock_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxAckTimeoutMs:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxTxAckQueueSize:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue:<<malloc 1>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].isFree:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pAckQueue[0].timestamp:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.ackQueueProtectMutexId:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:17107567574646778907
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_MutexLock.MutexId
<<uut_prototype_stubs.UclALOs_MutexLock.MutexId>> = ( &UclDLInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessAckTimer.pInst
<<UclDL_Impl.UclDL_Impl_ProcessAckTimer.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_ProcessReceive

-- Test Case: UclDL_Impl_ProcessReceive_Nodeid_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_Nodeid_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCRC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.nodeId:3
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCRC.return:0xF5F2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x8
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0x5A
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxAckMsgs:0
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_NormalMsg.msghdr_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_NormalMsg.msghdr_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCRC
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCRC.return:0xF5F2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x11
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[13]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[14]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[15]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[16]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[17]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[18]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[19]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:20
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxMsgs:1
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_NormalMsg_FramewithNoPayload
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_NormalMsg_FramewithNoPayload
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x11
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:7
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxMsgs:0
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UCLDLCFG_0_RxWorkgBuffer.UCLDLCFG_0_RxWorkgBuffer[19]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[15]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[16]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[17]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[18]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[19]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_NormalMsg_SpuriousFrames
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_NormalMsg_SpuriousFrames
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SecurityValidateTSC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableTSC:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.rxCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:0x5577
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x13
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x55
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0x77
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[13]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[14]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[15]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[16]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[17]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[18]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[19]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[20]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxMsgs:0
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_NormalMsg_WithImproperChecksum
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_NormalMsg_WithImproperChecksum
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x11
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[13]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[14]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[15]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[16]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[17]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[18]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[19]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:20
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxChksumErr:1
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UCLDLCFG_0_RxWorkgBuffer.UCLDLCFG_0_RxWorkgBuffer[19]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_Securelevel1Msg_WithInvalidCMAC
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_Securelevel1Msg_WithInvalidCMAC
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.numIUclALCrypto:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xF2,(3)0xF1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xF2,0xF1,(2)0xF2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:(2)0xF3,0xF2,0xF3
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:(3)0xF4,0xF2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:(4)4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x15
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x80
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[13]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[14]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[15]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[16]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[17]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[18]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[19]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[20]:0xF3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0xF4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[22]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:23
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:(4)UCL_E_OK,UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_Securelevel1Msg_numIUclAlCrypto<0
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_Securelevel1Msg_numIUclAlCrypto<0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.numIUclALCrypto:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xF2,(3)0xF1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xF2,0xF1,(2)0xF2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:(2)0xF3,0xF2,0xF3
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:(3)0xF4,0xF2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:(4)4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x15
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x80
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[13]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[14]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[15]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[16]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[17]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[18]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[19]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[20]:0xF3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0xF4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[22]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:23
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:(4)UCL_E_OK,UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_Securelevel2Msg
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_Securelevel2Msg
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xF1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xF2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xF3
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xF4
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x15
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x80
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[13]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[14]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[15]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[16]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[17]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[18]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[19]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[20]:0xF3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0xF4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[22]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:23
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxMsgs:1
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_Securelevel2Msg.MsgHdr_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_Securelevel2Msg.MsgHdr_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_IUclDL_Send
TEST.STUB:UclDL_Impl.UclDL_Impl_Decrypt
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.rxWorkBufferSize:10
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.rxCobsOverheadBytes:3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.probe_x:2
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.CryInst:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.return:UCL_E_NOK
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.CryInst:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xF1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xF2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xF3
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xF4
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:4
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.Val:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.Size:4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x15
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x80
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[13]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[14]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[15]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[16]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[17]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[18]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[19]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[20]:0xF3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0xF4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[22]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:23
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[3]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[4]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[5]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_enableTSC.ret_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_enableTSC.ret_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_IUclDL_Send
TEST.STUB:UclDL_Impl.UclDL_Impl_Decrypt
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.STUB:UclDL_Impl.UclDL_Impl_SecurityValidateTSC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.rxWorkBufferSize:10
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer:<<malloc 6>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[0]:0x0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[1]:0x3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[2]:0x4
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[3]:0x4
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[4]:0x4
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[5]:0x4
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableTSC:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.rxCobsOverheadBytes:3
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.CryInst:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.return:UCL_E_NOK
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.CryInst:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xF1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xF2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xF3
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xF4
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:4
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.return:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.Val:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.Size:4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x15
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x80
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[13]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[14]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[15]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[16]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[17]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[18]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[19]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[20]:0xF3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0xF4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[22]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:23
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_enableTSC.ret_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_enableTSC.ret_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_IUclDL_Send
TEST.STUB:UclDL_Impl.UclDL_Impl_Decrypt
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.STUB:UclDL_Impl.UclDL_Impl_SecurityValidateTSC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.rxWorkBufferSize:10
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer:<<malloc 6>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[0]:0x0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[1]:0x3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[2]:0x4
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[3]:0x4
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[4]:0x4
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRxWorkBuffer[5]:0x4
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableTSC:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.rxCobsOverheadBytes:3
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.CryInst:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_Decrypt.return:UCL_E_NOK
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.CryInst:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xF1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xF2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xF3
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xF4
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:4
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.return:-1
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.Val:0
TEST.VALUE:uut_prototype_stubs.UclALOs_Memset.Size:4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x15
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x80
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[13]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[14]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[15]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[16]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[17]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[18]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[19]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[20]:0xF3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0xF4
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[22]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:23
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_msgdeclen_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_msgdeclen_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x7
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0xF
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x5A
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:9
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxAckMsgs:0
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UCLDLCFG_0_RxWorkgBuffer.UCLDLCFG_0_RxWorkgBuffer[19]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_numPhyRecoveryAttempts>0
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_numPhyRecoveryAttempts>0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCRC
TEST.STUB:UclDL_Impl.UclDL_Impl_SecurityValidateTSC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableTSC:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.rxCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.numPhyRecoveryAttempts:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:0x5577
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCRC.return:0xF5F2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x13
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x55
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0x77
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[13]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[14]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[15]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[16]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[17]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[18]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[19]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[20]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:22
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxMsgs:1
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_p2p_Ack
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_p2p_Ack
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCRC
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCRC.return:0xF5F2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x8
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0x5A
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxAckMsgs:1
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_p2p_HeartBeat.005
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_p2p_HeartBeat.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCRC
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCRC.return:0xF5F2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x7
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:9
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxHbMsgs:1
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_p2p_KVVReq
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_p2p_KVVReq
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCRC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableSecurity:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.rxCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCRC.return:0xF5F2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x40
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x8
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:13
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxMsgs:1
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxHbMsgs:0
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_p2p_KVVRes.009.001
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_p2p_KVVRes.009.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCRC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableSecurity:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.rxCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCRC.return:0xF5F2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x40
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x8
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:13
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxMsgs:1
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxHbMsgs:0
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_p2p_KVVRes_case3
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_p2p_KVVRes_case3
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCRC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableSecurity:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.rxCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCRC.return:0xF5F2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x40
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x8
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:13
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxMsgs:1
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxHbMsgs:0
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_p2p_RecvSeed_RS1_case0
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_p2p_RecvSeed_RS1_case0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCRC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableSecurity:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCRC.return:0xF5F2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x40
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x7
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:13
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxMsgs:1
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_p2p_enable_security_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_p2p_enable_security_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCRC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableSecurity:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.rxCobsOverheadBytes:1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCRC.return:0xF5F2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x3
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x40
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x8
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x1
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[9]:0xA5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[10]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[11]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[12]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[21]:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:13
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxMsgs:1
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxHbMsgs:0
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ProcessReceive_rxCobsOverheadBytes_out_of_bound
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ProcessReceive
TEST.NEW
TEST.NAME:UclDL_Impl_ProcessReceive_rxCobsOverheadBytes_out_of_bound
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCRC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.nodeId:3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.rxWorkBufferSize:10
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.rxCobsOverheadBytes:11
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCRC.return:0xF5F2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[0]:0x0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[1]:0x8
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[2]:0x2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[3]:0x2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[4]:0x12
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[5]:0x34
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[6]:0x5A
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[7]:0xF5
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pData[8]:0xF2
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.pSize[0]:10
TEST.VALUE:uut_prototype_stubs.UclALPhy_Read.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.stats.rxAckMsgs:0
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.UclALPhy_Read.pData[21]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.pCfg
<<UclDL_Impl.<<GLOBAL>>.UclDLInst_0>>.pCfg = ( &UclDLCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_ReInitPhy

-- Test Case: UclDL_Impl_ReInitPhy.false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ReInitPhy
TEST.NEW
TEST.NAME:UclDL_Impl_ReInitPhy.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.UclALPhy_Shutdown.return:UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_ReInitPhy.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ReInitPhy.pInst
<<UclDL_Impl.UclDL_Impl_ReInitPhy.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_ReInitPhy.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_ReInitPhy
TEST.NEW
TEST.NAME:UclDL_Impl_ReInitPhy.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.UclALPhy_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_ReInitPhy.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_ReInitPhy.pInst
<<UclDL_Impl.UclDL_Impl_ReInitPhy.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SecurityGenerateSessionKey

-- Test Case: UclDL_Impl_SecurityGenerateSessionKey.001
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityGenerateSessionKey
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityGenerateSessionKey.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[0]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[1]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[2]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[3]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[4]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[5]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[6]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[7]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[8]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[9]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[10]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[11]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[12]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[13]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[14]:0xAA
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestSKbuffer[15]:0xAA
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.pInst
<<UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityGenerateSessionKey.002
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityGenerateSessionKey
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityGenerateSessionKey.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.pInst
<<UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityGenerateSessionKey.pRS1_buffer
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityGenerateSessionKey
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityGenerateSessionKey.pRS1_buffer
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRS1Buffer:<<null>>
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRS2Buffer:<<null>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.pInst
<<UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityGenerateSessionKey.pRS1_buffer_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityGenerateSessionKey
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityGenerateSessionKey.pRS1_buffer_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.pRS2Buffer:<<null>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xAA
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.pInst
<<UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.pInst>> = ( &UclDLInst_0  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SecurityRecvKVVRequest

-- Test Case: UclDL_Impl_SecurityRecvKVVRequest.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvKVVRequest
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvKVVRequest.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.STUB:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[0]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[1]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[2]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[3]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[4]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[5]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[6]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[7]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[8]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[9]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[10]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[11]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[12]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[13]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[14]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[15]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KVVReq
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[8]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[9]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[10]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[11]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[12]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[13]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[14]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[15]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.Size:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_Authenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[3]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[4]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[5]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[6]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[7]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvKVVRequest_GetCMACfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvKVVRequest
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvKVVRequest_GetCMACfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.STUB:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[0]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[1]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[2]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[3]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[4]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[5]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[6]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[7]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[8]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[9]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[10]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[11]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[12]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[13]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[14]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[15]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KVVReq
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_NOK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[8]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[9]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[10]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[11]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[12]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[13]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[14]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[15]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.Size:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[3]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[4]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[5]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[6]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[7]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvKVVRequest_Invalid_state
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvKVVRequest
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvKVVRequest_Invalid_state
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.STUB:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[0]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[1]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[2]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[3]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[4]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[5]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[6]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[7]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[8]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[9]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[10]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[11]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[12]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[13]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[14]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[15]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_RS2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[8]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[9]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[10]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[11]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[12]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[13]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[14]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[15]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.Size:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_RS2
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[3]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[4]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[5]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[6]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[7]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvKVVRequest_Keymismatch
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvKVVRequest
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvKVVRequest_Keymismatch
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.STUB:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[0]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[1]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[2]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[3]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[4]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[5]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[6]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[7]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[8]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[9]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[10]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[11]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[12]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[13]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[14]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[15]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KVVReq
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xA3
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[8]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[9]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[10]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[11]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[12]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[13]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[14]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[15]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.Size:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[3]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[4]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[5]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[6]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[7]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvKVVRequest_KvvResponsefail
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvKVVRequest
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvKVVRequest_KvvResponsefail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.STUB:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[0]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[1]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[2]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[3]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[4]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[5]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[6]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[7]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[8]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[9]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[10]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[11]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[12]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[13]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[14]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.TestKVVReqbuffer[15]:0xA1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KVVReq
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[8]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[9]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[10]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[11]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[12]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[13]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[14]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pData[15]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.Size:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse.return:UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[0]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[1]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[2]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[3]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[4]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[5]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[6]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[7]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityValidateKVVRequest.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvKVVRequest.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SecurityRecvKVVResponse

-- Test Case: UclDL_Impl_SecurityRecvKVVResponse
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvKVVResponse
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvKVVResponse
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KVVResp
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData:<<malloc 20>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[16]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[17]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[18]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[19]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.Size:20
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestkvvResbuffer[0]:0xA5
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestkvvResbuffer[1]:0xA5
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestkvvResbuffer[2]:0xA5
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestkvvResbuffer[3]:0xA5
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_Authenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[16]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[17]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvKVVResponse_GetCmacfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvKVVResponse
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvKVVResponse_GetCmacfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KVVResp
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_NOK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData:<<malloc 20>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[16]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[17]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[18]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[19]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.Size:20
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[16]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[17]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvKVVResponse_Invalidstate
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvKVVResponse
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvKVVResponse_Invalidstate
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_RS2
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData:<<malloc 20>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[16]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[17]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[18]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[19]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.Size:20
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_RS2
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[16]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[17]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvKVVResponse_Keymismatch
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvKVVResponse
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvKVVResponse_Keymismatch
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KVVResp
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData:<<malloc 20>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[9]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[16]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[17]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[18]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[19]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.Size:20
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestkvvResbuffer[0]:0xA5
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestkvvResbuffer[1]:0xA5
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestkvvResbuffer[2]:0xA5
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.TestkvvResbuffer[3]:0xA5
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[16]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[17]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvKVVResponse_NegativeKeyResponse
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvKVVResponse
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvKVVResponse_NegativeKeyResponse
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KVVResp
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:16
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_OK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData:<<malloc 20>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[8]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[9]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[10]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[11]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[12]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[13]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[14]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[15]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[16]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[17]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[18]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pData[19]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.Size:20
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[16]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[17]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvKVVResponse.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SecurityRecvSeed

-- Test Case: UclDL_Impl_SecurityRecvSeed_SecurityType_InvalidSeedType
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvSeed
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvSeed_SecurityType_InvalidSeedType
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.SeedType:0xFF
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData:<<malloc 8>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[0]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[1]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[2]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[3]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[4]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[5]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[6]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[7]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvSeed_SecurityType_RS1_InvalidMsglen
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvSeed
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvSeed_SecurityType_RS1_InvalidMsglen
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.SeedType:UCLDL_P2P_MSG_SECURITY_RS1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData:<<malloc 8>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.Size:4
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[0]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[1]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[2]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[3]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[4]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[5]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[6]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[7]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.TestCryptbuffer.TestCryptbuffer[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvSeed_SecurityType_RS1_Keygenfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvSeed
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvSeed_SecurityType_RS1_Keygenfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.SeedType:UCLDL_P2P_MSG_SECURITY_RS1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData:<<malloc 8>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.Size:8
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[0]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[1]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[2]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[3]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[4]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[5]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[6]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[7]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvSeed_SecurityType_RS1_SendSeedFcn_Failed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvSeed
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvSeed_SecurityType_RS1_SendSeedFcn_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SecuritySendSeed
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecuritySendSeed.return:UCL_E_NOK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.SeedType:UCLDL_P2P_MSG_SECURITY_RS1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData:<<malloc 8>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[0]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[1]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[2]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[3]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[4]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[5]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[6]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[7]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvSeed_SecurityType_RS2
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvSeed
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvSeed_SecurityType_RS2
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_RS2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.SeedType:UCLDL_P2P_MSG_SECURITY_RS2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData:<<malloc 8>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[0]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[1]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[2]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[3]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[4]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[5]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[6]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[7]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KVVResp
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.TestCryptbuffer.TestCryptbuffer[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvSeed_SecurityType_RS2_GenSeedKeyfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvSeed
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvSeed_SecurityType_RS2_GenSeedKeyfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_RS2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.SeedType:UCLDL_P2P_MSG_SECURITY_RS2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData:<<malloc 8>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.Size:8
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[0]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[1]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[2]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[3]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[4]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[5]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[6]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[7]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvSeed_SecurityType_RS2_InvalidMsglen
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvSeed
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvSeed_SecurityType_RS2_InvalidMsglen
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_RS2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.SeedType:UCLDL_P2P_MSG_SECURITY_RS2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData:<<malloc 8>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.Size:4
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[0]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[1]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[2]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[3]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[4]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[5]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[6]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[7]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvSeed_SecurityType_RS2_Invalidstate
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvSeed
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvSeed_SecurityType_RS2_Invalidstate
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KVVReq
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.SeedType:UCLDL_P2P_MSG_SECURITY_RS2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData:<<malloc 8>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[0]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[1]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[2]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[3]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[4]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[5]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[6]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[7]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KVVReq
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityRecvSeed_SecurityType_RS2_SendKVVfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityRecvSeed
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityRecvSeed_SecurityType_RS2_SendKVVfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SecuritySendKVVRequest
TEST.STUB:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_RS2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.SeedType:UCLDL_P2P_MSG_SECURITY_RS2
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData:<<malloc 8>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[0]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[1]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[2]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[3]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[4]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[5]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[6]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[7]:0xA1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.Size:8
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecuritySendKVVRequest.return:UCL_E_NOK
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityGenerateSessionKey.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[0]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[1]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[2]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[3]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[4]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[5]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[6]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.pResult[7]:0xF1
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.Size:8
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[8]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[9]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[10]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[11]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[12]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[13]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[14]:INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pData[15]:INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst
<<UclDL_Impl.UclDL_Impl_SecurityRecvSeed.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SecuritySendKVVRequest

-- Test Case: UclDL_Impl_SecuritySendKVVRequest.subcase_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecuritySendKVVRequest
TEST.NEW
TEST.NAME:UclDL_Impl_SecuritySendKVVRequest.subcase_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:8
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SecuritySendKVVRequest.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecuritySendKVVRequest.pInst
<<UclDL_Impl.UclDL_Impl_SecuritySendKVVRequest.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecuritySendKVVRequest.subcase_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecuritySendKVVRequest
TEST.NEW
TEST.NAME:UclDL_Impl_SecuritySendKVVRequest.subcase_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pInst:<<null>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.pResult[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.ResultSize:8
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SecuritySendKVVRequest.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecuritySendKVVRequest.pInst
<<UclDL_Impl.UclDL_Impl_SecuritySendKVVRequest.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SecuritySendKVVResponse

-- Test Case: UclDL_Impl_SecuritySendKVVResponse.003
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecuritySendKVVResponse
TEST.NEW
TEST.NAME:UclDL_Impl_SecuritySendKVVResponse.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendP2PMessage
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse.pInst
<<UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecuritySendKVVResponse.false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecuritySendKVVResponse
TEST.NEW
TEST.NAME:UclDL_Impl_SecuritySendKVVResponse.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendP2PMessage
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE:UclDL_Impl.UclDL_Impl_GetCMAC.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse.pInst
<<UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecuritySendKVVResponse.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecuritySendKVVResponse
TEST.NEW
TEST.NAME:UclDL_Impl_SecuritySendKVVResponse.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendP2PMessage
TEST.STUB:UclDL_Impl.UclDL_Impl_GetCMAC
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse.pInst
<<UclDL_Impl.UclDL_Impl_SecuritySendKVVResponse.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SecuritySendSeed

-- Test Case: UclDL_Impl_SecuritySendSeed_Subfunctionfailed
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecuritySendSeed
TEST.NEW
TEST.NAME:UclDL_Impl_SecuritySendSeed_Subfunctionfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendP2PMessage
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SecuritySendSeed.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecuritySendSeed.pInst
<<UclDL_Impl.UclDL_Impl_SecuritySendSeed.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecuritySendSeed_Subfunctionfailed.003
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecuritySendSeed
TEST.NEW
TEST.NAME:UclDL_Impl_SecuritySendSeed_Subfunctionfailed.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendP2PMessage
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALCrypto_Random.return:UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SecuritySendSeed.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecuritySendSeed.pInst
<<UclDL_Impl.UclDL_Impl_SecuritySendSeed.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SecurityStartKeyNegotiation

-- Test Case: UclDL_Impl_SecurityStartKeyNegotiation.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityStartKeyNegotiation
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityStartKeyNegotiation.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableSecurity:TRUE
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[0]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[1]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[2]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[3]:UclDL_Impl_HeartBeatTimerExpired
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KeyNegotiation
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityStartKeyNegotiation.pInst
<<UclDL_Impl.UclDL_Impl_SecurityStartKeyNegotiation.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityStartKeyNegotiation_InvalidState
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityStartKeyNegotiation
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityStartKeyNegotiation_InvalidState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.enableSecurity:(2)TRUE,FALSE
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active,eUclDLState_Shutdown,eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KeyNegotiation,(2)eUclDLAuthState_UnAuthenticated
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[0]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[1]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[2]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[3]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityStartKeyNegotiation.pInst
<<UclDL_Impl.UclDL_Impl_SecurityStartKeyNegotiation.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SecurityTimerExpired

-- Test Case: UclDL_Impl_SecurityTimerExpired_NonkeyNegotiationstate
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityTimerExpired
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityTimerExpired_NonkeyNegotiationstate
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_RS2,eUclDLAuthState_KVVReq,eUclDLAuthState_KVVResp,eUclDLAuthState_Last
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityTimerExpired.pInst
<<UclDL_Impl.UclDL_Impl_SecurityTimerExpired.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityTimerExpired_SecuritySendSeed_return_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityTimerExpired
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityTimerExpired_SecuritySendSeed_return_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SecuritySendSeed
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KeyNegotiation
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecuritySendSeed.return:UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityTimerExpired.pInst
<<UclDL_Impl.UclDL_Impl_SecurityTimerExpired.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityTimerExpired_keyNegotiationstate.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityTimerExpired
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityTimerExpired_keyNegotiationstate.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SecuritySendSeed
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_KeyNegotiation
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecuritySendSeed.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_RS2
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityTimerExpired.pInst
<<UclDL_Impl.UclDL_Impl_SecurityTimerExpired.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SecurityValidateTSC

-- Test Case: UclDL_Impl_SecurityValidateTSC>TOLERANCE>VALIDSTATE
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityValidateTSC
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityValidateTSC>TOLERANCE>VALIDSTATE
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.tscToleranceMs:50
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_Authenticated
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:1200
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.RxTSC:1100
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.pInst
<<UclDL_Impl.UclDL_Impl_SecurityValidateTSC.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityValidateTSC>TOLERANCE_INVALIDSTATE
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityValidateTSC
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityValidateTSC>TOLERANCE_INVALIDSTATE
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.tscToleranceMs:50
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_UnAuthenticated
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:1200
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.RxTSC:1100
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.pInst
<<UclDL_Impl.UclDL_Impl_SecurityValidateTSC.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityValidateTSC_OVERFLOW
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityValidateTSC
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityValidateTSC_OVERFLOW
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.tscToleranceMs:1000
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.authState:eUclDLAuthState_Authenticated
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:10
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.RxTSC:65500
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:10
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.pInst
<<UclDL_Impl.UclDL_Impl_SecurityValidateTSC.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityValidateTSC_T1>T2
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityValidateTSC
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityValidateTSC_T1>T2
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.tscToleranceMs:1000
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:1100
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.RxTSC:1200
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:1200
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.pInst
<<UclDL_Impl.UclDL_Impl_SecurityValidateTSC.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SecurityValidateTSC_T2>T1
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SecurityValidateTSC
TEST.NEW
TEST.NAME:UclDL_Impl_SecurityValidateTSC_T2>T1
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.tscToleranceMs:1000
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:1200
TEST.VALUE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.RxTSC:1100
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:1200
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SecurityValidateTSC.pInst
<<UclDL_Impl.UclDL_Impl_SecurityValidateTSC.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SendAck

-- Test Case: UclDL_Impl_SendAck.false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SendAck
TEST.NEW
TEST.NAME:UclDL_Impl_SendAck.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendN2NMessage
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendAck.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendAck.AckStatus:UCLDL_ACK_SUCCESS
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.return:1
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SendAck.pInst
<<UclDL_Impl.UclDL_Impl_SendAck.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SendAck.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SendAck
TEST.NEW
TEST.NAME:UclDL_Impl_SendAck.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendAck.MsgId:0x1234
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendAck.AckStatus:UCLDL_ACK_SUCCESS
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.ackMsgScratchBuffer.ackMsgScratchBuffer[8]:INPUT_BASE=16,EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SendAck.pInst
<<UclDL_Impl.UclDL_Impl_SendAck.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SendHeartBeat

-- Test Case: UclDL_Impl_SendHeartBeat.false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SendHeartBeat
TEST.NEW
TEST.NAME:UclDL_Impl_SendHeartBeat.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_SendP2PMessage
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.hbMsgScratchBuffer[0]:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.hbMsgScratchBuffer[1]:6
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.hbMsgScratchBuffer[2]:3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.hbMsgScratchBuffer[3]:165
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.hbMsgScratchBuffer[4]:165
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.hbMsgScratchBuffer[5]:245
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.hbMsgScratchBuffer[6]:242
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.hbMsgScratchBuffer[7]:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.return:UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SendHeartBeat.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SendHeartBeat.pInst
<<UclDL_Impl.UclDL_Impl_SendHeartBeat.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SendHeartBeat.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SendHeartBeat
TEST.NEW
TEST.NAME:UclDL_Impl_SendHeartBeat.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SendHeartBeat.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SendHeartBeat.pInst
<<UclDL_Impl.UclDL_Impl_SendHeartBeat.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SendMessage

-- Test Case: UclDL_Impl_SendMessage.false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SendMessage
TEST.NEW
TEST.NAME:UclDL_Impl_SendMessage.false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendMessage.phyInstId:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Write.return:UCL_E_NOK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SendMessage.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SendMessage.pInst
<<UclDL_Impl.UclDL_Impl_SendMessage.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SendMessage.true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SendMessage
TEST.NEW
TEST.NAME:UclDL_Impl_SendMessage.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendMessage.phyInstId:0
TEST.VALUE:uut_prototype_stubs.UclALPhy_Write.return:UCL_E_OK
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SendMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SendMessage.pInst
<<UclDL_Impl.UclDL_Impl_SendMessage.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SendN2NMessage

-- Test Case: UclDL_Impl_SendN2NMessage.Size<0
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SendN2NMessage
TEST.NEW
TEST.NAME:UclDL_Impl_SendN2NMessage.Size<0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_CobsEncode
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.N2NMsgType:0x0
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.MsgId:0x3
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.Size:0
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.return:8
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsEncode.return:0
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[3]::INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[4]::INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[5]::INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[6]::INPUT_BASE=16
TEST.ATTRIBUTES:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[7]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pInst
<<UclDL_Impl.UclDL_Impl_SendN2NMessage.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SendN2NMessage.pMsgBuffer_0
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SendN2NMessage
TEST.NEW
TEST.NAME:UclDL_Impl_SendN2NMessage.pMsgBuffer_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.N2NMsgType:0x1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.MsgId:0x3
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendN2NMessage.return:8
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SendN2NMessage.pInst
<<UclDL_Impl.UclDL_Impl_SendN2NMessage.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_SendP2PMessage

-- Test Case: UclDL_Impl_SendP2PMessage.sendMessage_true
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SendP2PMessage
TEST.NEW
TEST.NAME:UclDL_Impl_SendP2PMessage.sendMessage_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_CobsEncode
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.P2PMsgType:0x1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.MsgId:0x3
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.Size:8
TEST.VALUE:UclDL_Impl.UclDL_Impl_CobsEncode.return:0
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pInst
<<UclDL_Impl.UclDL_Impl_SendP2PMessage.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SendP2PMessage_pMsgBuffer_0
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SendP2PMessage
TEST.NEW
TEST.NAME:UclDL_Impl_SendP2PMessage_pMsgBuffer_0
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.P2PMsgType:0x8
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.MsgId:0x3
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.Size:8
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SendP2PMessage.return:UCL_E_NOK
TEST.ATTRIBUTES:UclDL_Impl.<<GLOBAL>>.TestCryptbuffer.TestCryptbuffer[15]:INPUT_BASE=16,EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pInst
<<UclDL_Impl.UclDL_Impl_SendP2PMessage.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_SendP2PMessage_true_cases
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_SendP2PMessage
TEST.NEW
TEST.NAME:UclDL_Impl_SendP2PMessage_true_cases
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.P2PMsgType:0x1
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.MsgId:0x3
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload:<<malloc 16>>
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[0]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[1]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[2]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[3]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[4]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[5]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[6]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pPayload[7]:0xA5
TEST.VALUE:UclDL_Impl.UclDL_Impl_SendP2PMessage.Size:8
TEST.EXPECTED:UclDL_Impl.UclDL_Impl_SendP2PMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_SendP2PMessage.pInst
<<UclDL_Impl.UclDL_Impl_SendP2PMessage.pInst>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclDL_Impl_TimerTask

-- Test Case: UclDL_Impl_TimerTask_InValidState
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_TimerTask
TEST.NEW
TEST.NAME:UclDL_Impl_TimerTask_InValidState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_ProcessReceive
TEST.STUB:UclDL_Impl.UclDL_Impl_ProcessAckTimer
TEST.STUB:UclDL_Impl.UclDL_Impl_ReInitPhy
TEST.STUB:UclDL_Impl.UclDL_Impl_NofityErrorCallback
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.receiveProcessingMode:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxPhyRecoveryAttempts:(3)5
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:(2)eUclDLState_Recovery
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[0]:3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[1]:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[2]:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[3]:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[0]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[1]:UclDL_Impl_BpsTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[2]:UclDL_Impl_LinkDownTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[3]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.numPhyRecoveryAttempts:2,3,7
TEST.VALUE:UclDL_Impl.UclDL_Impl_ReInitPhy.return:UCL_E_OK,(2)UCL_E_NOK
TEST.STUB_VAL_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_TimerTask.pData
<<UclDL_Impl.UclDL_Impl_TimerTask.pData>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_TimerTask_InValidState.numPhyRecAttempts=255
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_TimerTask
TEST.NEW
TEST.NAME:UclDL_Impl_TimerTask_InValidState.numPhyRecAttempts=255
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_ProcessReceive
TEST.STUB:UclDL_Impl.UclDL_Impl_ProcessAckTimer
TEST.STUB:UclDL_Impl.UclDL_Impl_ReInitPhy
TEST.STUB:UclDL_Impl.UclDL_Impl_NofityErrorCallback
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.receiveProcessingMode:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxPhyRecoveryAttempts:(3)5
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:(2)eUclDLState_Recovery
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[0]:3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[1]:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[2]:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[3]:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[0]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[1]:UclDL_Impl_BpsTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[2]:UclDL_Impl_LinkDownTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[3]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.numPhyRecoveryAttempts:2,3,255
TEST.VALUE:UclDL_Impl.UclDL_Impl_ReInitPhy.return:UCL_E_OK,(2)UCL_E_NOK
TEST.STUB_VAL_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_TimerTask.pData
<<UclDL_Impl.UclDL_Impl_TimerTask.pData>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_TimerTask_InValidState.pInst->state_false
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_TimerTask
TEST.NEW
TEST.NAME:UclDL_Impl_TimerTask_InValidState.pInst->state_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_ProcessReceive
TEST.STUB:UclDL_Impl.UclDL_Impl_ProcessAckTimer
TEST.STUB:UclDL_Impl.UclDL_Impl_ReInitPhy
TEST.STUB:UclDL_Impl.UclDL_Impl_NofityErrorCallback
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.receiveProcessingMode:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.maxPhyRecoveryAttempts:(3)5
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Shutdown
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[0]:3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[1]:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[2]:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[3]:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[0]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[1]:UclDL_Impl_BpsTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[2]:UclDL_Impl_LinkDownTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[3]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.numPhyRecoveryAttempts:2,3,7
TEST.VALUE:UclDL_Impl.UclDL_Impl_ReInitPhy.return:UCL_E_OK,(2)UCL_E_NOK
TEST.STUB_VAL_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_TimerTask.pData
<<UclDL_Impl.UclDL_Impl_TimerTask.pData>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_TimerTask_ValidState
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_TimerTask
TEST.NEW
TEST.NAME:UclDL_Impl_TimerTask_ValidState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_ProcessReceive
TEST.STUB:UclDL_Impl.UclDL_Impl_ProcessAckTimer
TEST.STUB:UclDL_Impl.UclDL_Impl_ReInitPhy
TEST.STUB:UclDL_Impl.UclDL_Impl_NofityErrorCallback
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.receiveProcessingMode:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active,eUclDLState_RxOnly
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[0]:3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[1]:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[2]:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[3]:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[0]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[1]:UclDL_Impl_BpsTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[2]:UclDL_Impl_LinkDownTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[3]:UclDL_Impl_HeartBeatTimerExpired
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:2
TEST.STUB_VAL_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_TimerTask.pData
<<UclDL_Impl.UclDL_Impl_TimerTask.pData>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclDL_Impl_TimerTask_ValidState.processing_mode_change
TEST.UNIT:UclDL_Impl
TEST.SUBPROGRAM:UclDL_Impl_TimerTask
TEST.NEW
TEST.NAME:UclDL_Impl_TimerTask_ValidState.processing_mode_change
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclDL_Impl.UclDL_Impl_ProcessReceive
TEST.STUB:UclDL_Impl.UclDL_Impl_ProcessAckTimer
TEST.STUB:UclDL_Impl.UclDL_Impl_ReInitPhy
TEST.STUB:UclDL_Impl.UclDL_Impl_NofityErrorCallback
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLCfg_0.receiveProcessingMode:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.state:eUclDLState_Active
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[0]:3
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[1]:2
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[2]:1
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimers[3]:0
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[0]:UclDL_Impl_HeartBeatTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[1]:UclDL_Impl_BpsTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[2]:UclDL_Impl_LinkDownTimerExpired
TEST.VALUE:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.localTimersCbk[3]:UclDL_Impl_HeartBeatTimerExpired
TEST.EXPECTED:UclDL_Impl.<<GLOBAL>>.UclDLInst_0.tscCounter:1
TEST.STUB_VAL_USER_CODE:UclDL_Impl.UclDL_Impl_ProcessReceive.pInst
<<UclDL_Impl.UclDL_Impl_ProcessReceive.pInst>> = ( &UclDLInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclDL_Impl.UclDL_Impl_TimerTask.pData
<<UclDL_Impl.UclDL_Impl_TimerTask.pData>> = ( &UclDLInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
