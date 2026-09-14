-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_AESDECODER
-- Unit(s) Under Test: UPDi_AesDecoder
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: CbcDecrypt_FBLNotify_callback

-- Test Case: CbcDecrypt_FBLNotify_callback.001
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:CbcDecrypt_FBLNotify_callback
TEST.NEW
TEST.NAME:CbcDecrypt_FBLNotify_callback.001
TEST.VALUE:UPDi_AesDecoder.CbcDecrypt_FBLNotify_callback.Result:0
TEST.EXPECTED:UPDi_AesDecoder.CbcDecrypt_FBLNotify_callback.Result:0
TEST.END

-- Test Case: CbcDecrypt_FBLNotify_callback.002
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:CbcDecrypt_FBLNotify_callback
TEST.NEW
TEST.NAME:CbcDecrypt_FBLNotify_callback.002
TEST.VALUE:UPDi_AesDecoder.CbcDecrypt_FBLNotify_callback.Result:2
TEST.EXPECTED:UPDi_AesDecoder.CbcDecrypt_FBLNotify_callback.Result:2
TEST.END

-- Subprogram: UPDAesDecoder_Deserialize

-- Test Case: UPDAesDecoder_Deserialize.001
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_Deserialize
TEST.NEW
TEST.NAME:UPDAesDecoder_Deserialize.001
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_Deserialize.return:1
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_Deserialize.return:1
TEST.END

-- Subprogram: UPDAesDecoder_GetDataFormat

-- Test Case: UPDAesDecoder_GetDataFormat.001
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_GetDataFormat
TEST.NEW
TEST.NAME:UPDAesDecoder_GetDataFormat.001
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_GetDataFormat.pDataFormat:<<malloc 1>>
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_GetDataFormat.pDataFormat[0]:eUPDiDataFormat_Invalid
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_GetDataFormat.pDataFormat[0]:eUPDiDataFormat_Enc
TEST.END

-- Subprogram: UPDAesDecoder_InstallData

-- Test Case: UPDAesDecoder_InstallData.001
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_InstallData
TEST.NEW
TEST.NAME:UPDAesDecoder_InstallData.001
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.return:2
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallData.return:2
TEST.VALUE_USER_CODE:UPDi_AesDecoder.UPDAesDecoder_InstallData.this
<<UPDi_AesDecoder.UPDAesDecoder_InstallData.this>> = ( &tUPDiAesDecoder_02 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDAesDecoder_InstallData.002
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_InstallData
TEST.NEW
TEST.NAME:UPDAesDecoder_InstallData.002
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.return:2
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallData.return:2
TEST.VALUE_USER_CODE:UPDi_AesDecoder.UPDAesDecoder_InstallData.this
<<UPDi_AesDecoder.UPDAesDecoder_InstallData.this>> = ( &tUPDiAesDecoder_02 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDAesDecoder_InstallData.003
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_InstallData
TEST.NEW
TEST.NAME:UPDAesDecoder_InstallData.003
TEST.VALUE:UPDi_AesDecoder.<<GLOBAL>>.Decyption_State:1
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.pSession:<<malloc 1>>
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.Data:<<malloc 2>>
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.Data:"w"
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.Size:2
TEST.VALUE:uut_prototype_stubs.Crypto_She_SymDecrypt.return:2
TEST.EXPECTED:UPDi_AesDecoder.<<GLOBAL>>.Decyption_State:1
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallData.Data:"w"
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallData.Size:2
TEST.VALUE_USER_CODE:UPDi_AesDecoder.UPDAesDecoder_InstallData.this
<<UPDi_AesDecoder.UPDAesDecoder_InstallData.this>> = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDAesDecoder_InstallData.006
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_InstallData
TEST.NEW
TEST.NAME:UPDAesDecoder_InstallData.006
TEST.STUB:UPDi_AesDecoder.UncypherData
TEST.VALUE:UPDi_AesDecoder.<<GLOBAL>>.Decyption_State:1
TEST.VALUE:UPDi_AesDecoder.UncypherData.return:1
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.pSession:<<malloc 1>>
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.Data:<<malloc 2>>
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.Data:"w"
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.Size:50000
TEST.VALUE:uut_prototype_stubs.Crypto_She_SymDecrypt.return:2
TEST.EXPECTED:UPDi_AesDecoder.<<GLOBAL>>.Decyption_State:1
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallData.Data:"w"
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallData.Size:50000
TEST.VALUE_USER_CODE:UPDi_AesDecoder.UPDAesDecoder_InstallData.this
<<UPDi_AesDecoder.UPDAesDecoder_InstallData.this>> = ( &tUPDiAesDcoder );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDAesDecoder_InstallData.007
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_InstallData
TEST.NEW
TEST.NAME:UPDAesDecoder_InstallData.007
TEST.STUB:UPDi_AesDecoder.UncypherData
TEST.VALUE:UPDi_AesDecoder.<<GLOBAL>>.Decyption_State:1
TEST.VALUE:UPDi_AesDecoder.<<GLOBAL>>.DecrytionDone:1
TEST.VALUE:UPDi_AesDecoder.UncypherData.return:1
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.pSession:<<malloc 1>>
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.Data:<<malloc 2>>
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.Data:"w"
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallData.Size:50000
TEST.VALUE:uut_prototype_stubs.Crypto_She_SymDecrypt.return:2
TEST.EXPECTED:UPDi_AesDecoder.<<GLOBAL>>.Decyption_State:1
TEST.EXPECTED:UPDi_AesDecoder.<<GLOBAL>>.DecrytionDone:0
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallData.Data:"w"
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallData.Size:50000
TEST.VALUE_USER_CODE:UPDi_AesDecoder.UPDAesDecoder_InstallData.this
<<UPDi_AesDecoder.UPDAesDecoder_InstallData.this>> = ( &tUPDiAesDcoder );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDAesDecoder_InstallExit

-- Test Case: UPDAesDecoder_InstallExit.001
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_InstallExit
TEST.NEW
TEST.NAME:UPDAesDecoder_InstallExit.001
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallExit.pSession:<<malloc 1>>
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallExit.return:0
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallExit.return:0
TEST.VALUE_USER_CODE:UPDi_AesDecoder.UPDAesDecoder_InstallExit.this
<<UPDi_AesDecoder.UPDAesDecoder_InstallExit.this>> = ( &tUPDiAesDecoder_02 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDAesDecoder_InstallExit.002
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_InstallExit
TEST.NEW
TEST.NAME:UPDAesDecoder_InstallExit.002
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallExit.return:0
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallExit.return:0
TEST.VALUE_USER_CODE:UPDi_AesDecoder.UPDAesDecoder_InstallExit.this
<<UPDi_AesDecoder.UPDAesDecoder_InstallExit.this>> = ( &tUPDiAesDcoder );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDAesDecoder_InstallStart

-- Test Case: UPDAesDecoder_InstallStart.001
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDAesDecoder_InstallStart.001
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallStart.pSession:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_Enc
TEST.EXPECTED:uut_prototype_stubs.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_Enc
TEST.VALUE_USER_CODE:UPDi_AesDecoder.UPDAesDecoder_InstallStart.this
<<UPDi_AesDecoder.UPDAesDecoder_InstallStart.this>> = ( &tUPDiAesDecoder_02 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDAesDecoder_InstallStart.002
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDAesDecoder_InstallStart.002
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallStart.pSession:<<malloc 1>>
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallStart.return:0
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallStart.return:0
TEST.VALUE_USER_CODE:UPDi_AesDecoder.UPDAesDecoder_InstallStart.this
<<UPDi_AesDecoder.UPDAesDecoder_InstallStart.this>> = ( &tUPDiAesDcoder );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDAesDecoder_InstallStart.003
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDAesDecoder_InstallStart.003
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallStart.pSession:<<malloc 1>>
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_InstallStart.return:1
TEST.VALUE:uut_prototype_stubs.UPDInstallMan_AllocBuffer.return:1
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_InstallStart.return:1
TEST.VALUE_USER_CODE:UPDi_AesDecoder.UPDAesDecoder_InstallStart.this
<<UPDi_AesDecoder.UPDAesDecoder_InstallStart.this>> = ( &tUPDiAesDcoder );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDAesDecoder_Serialize

-- Test Case: UPDAesDecoder_Serialize.001
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UPDAesDecoder_Serialize
TEST.NEW
TEST.NAME:UPDAesDecoder_Serialize.001
TEST.VALUE:UPDi_AesDecoder.UPDAesDecoder_Serialize.return:1
TEST.EXPECTED:UPDi_AesDecoder.UPDAesDecoder_Serialize.return:1
TEST.END

-- Subprogram: UncypherData

-- Test Case: UncypherData.001
TEST.UNIT:UPDi_AesDecoder
TEST.SUBPROGRAM:UncypherData
TEST.NEW
TEST.NAME:UncypherData.001
TEST.VALUE:UPDi_AesDecoder.<<GLOBAL>>.u16Used1:1
TEST.EXPECTED:UPDi_AesDecoder.<<GLOBAL>>.u16Used1:1
TEST.END
