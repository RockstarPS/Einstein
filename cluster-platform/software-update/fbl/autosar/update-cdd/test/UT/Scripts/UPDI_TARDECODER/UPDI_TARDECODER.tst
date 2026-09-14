-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_TARDECODER
-- Unit(s) Under Test: UPDi_TarDecoder
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: UPDTarDecoder_Deserialize

-- Test Case: UPDTarDecoder_Deserialize.001
TEST.UNIT:UPDi_TarDecoder
TEST.SUBPROGRAM:UPDTarDecoder_Deserialize
TEST.NEW
TEST.NAME:UPDTarDecoder_Deserialize.001
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_Deserialize.return:1
TEST.EXPECTED:UPDi_TarDecoder.UPDTarDecoder_Deserialize.return:1
TEST.END

-- Subprogram: UPDTarDecoder_GetDataFormat

-- Test Case: UPDTarDecoder_GetDataFormat.001
TEST.UNIT:UPDi_TarDecoder
TEST.SUBPROGRAM:UPDTarDecoder_GetDataFormat
TEST.NEW
TEST.NAME:UPDTarDecoder_GetDataFormat.001
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_GetDataFormat.pDataFormat:<<malloc 1>>
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_GetDataFormat.return:0
TEST.EXPECTED:UPDi_TarDecoder.UPDTarDecoder_GetDataFormat.return:0
TEST.END

-- Subprogram: UPDTarDecoder_InstallData

-- Test Case: UPDTarDecoder_InstallData.001
TEST.UNIT:UPDi_TarDecoder
TEST.SUBPROGRAM:UPDTarDecoder_InstallData
TEST.NEW
TEST.NAME:UPDTarDecoder_InstallData.001
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_InstallData.return:1
TEST.EXPECTED:UPDi_TarDecoder.UPDTarDecoder_InstallData.return:1
TEST.END

-- Subprogram: UPDTarDecoder_InstallExit

-- Test Case: UPDTarDecoder_InstallExit.001
TEST.UNIT:UPDi_TarDecoder
TEST.SUBPROGRAM:UPDTarDecoder_InstallExit
TEST.NEW
TEST.NAME:UPDTarDecoder_InstallExit.001
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_InstallExit.return:1
TEST.EXPECTED:UPDi_TarDecoder.UPDTarDecoder_InstallExit.return:1
TEST.END

-- Subprogram: UPDTarDecoder_InstallStart

-- Test Case: UPDTarDecoder_InstallStart.001
TEST.UNIT:UPDi_TarDecoder
TEST.SUBPROGRAM:UPDTarDecoder_InstallStart
TEST.NEW
TEST.NAME:UPDTarDecoder_InstallStart.001
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_InstallStart.return:1
TEST.EXPECTED:UPDi_TarDecoder.UPDTarDecoder_InstallStart.return:1
TEST.END

-- Subprogram: UPDTarDecoder_IsInvalid

-- Test Case: UPDTarDecoder_IsInvalid.001
TEST.UNIT:UPDi_TarDecoder
TEST.SUBPROGRAM:UPDTarDecoder_IsInvalid
TEST.NEW
TEST.NAME:UPDTarDecoder_IsInvalid.001
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.return:1
TEST.EXPECTED:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.return:1
TEST.END

-- Test Case: UPDTarDecoder_IsInvalid.002
TEST.UNIT:UPDi_TarDecoder
TEST.SUBPROGRAM:UPDTarDecoder_IsInvalid
TEST.NEW
TEST.NAME:UPDTarDecoder_IsInvalid.002
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.return:1
TEST.EXPECTED:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.return:1
TEST.VALUE_USER_CODE:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.this
<<UPDi_TarDecoder.UPDTarDecoder_IsInvalid.this>> = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarDecoder_IsInvalid.003
TEST.UNIT:UPDi_TarDecoder
TEST.SUBPROGRAM:UPDTarDecoder_IsInvalid
TEST.NEW
TEST.NAME:UPDTarDecoder_IsInvalid.003
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.return:1
TEST.EXPECTED:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.return:1
TEST.VALUE_USER_CODE:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.this
<<UPDi_TarDecoder.UPDTarDecoder_IsInvalid.this>> = ( &global_add );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarDecoder_IsInvalid.004
TEST.UNIT:UPDi_TarDecoder
TEST.SUBPROGRAM:UPDTarDecoder_IsInvalid
TEST.NEW
TEST.NAME:UPDTarDecoder_IsInvalid.004
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.return:1
TEST.EXPECTED:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.return:1
TEST.END

-- Test Case: UPDTarDecoder_IsInvalid.005
TEST.UNIT:UPDi_TarDecoder
TEST.SUBPROGRAM:UPDTarDecoder_IsInvalid
TEST.NEW
TEST.NAME:UPDTarDecoder_IsInvalid.005
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.return:1
TEST.EXPECTED:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.return:1
TEST.VALUE_USER_CODE:UPDi_TarDecoder.UPDTarDecoder_IsInvalid.this
<<UPDi_TarDecoder.UPDTarDecoder_IsInvalid.this>> = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarDecoder_Serialize

-- Test Case: UPDTarDecoder_Serialize.001
TEST.UNIT:UPDi_TarDecoder
TEST.SUBPROGRAM:UPDTarDecoder_Serialize
TEST.NEW
TEST.NAME:UPDTarDecoder_Serialize.001
TEST.VALUE:UPDi_TarDecoder.UPDTarDecoder_Serialize.return:1
TEST.EXPECTED:UPDi_TarDecoder.UPDTarDecoder_Serialize.return:1
TEST.END
