-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_BLOCKINSTALLER
-- Unit(s) Under Test: UPDi_BlockInstaller
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: UPDBlockInstaller_Deserialize

-- Test Case: UPDBlockInstaller_Deserialize.001
TEST.UNIT:UPDi_BlockInstaller
TEST.SUBPROGRAM:UPDBlockInstaller_Deserialize
TEST.NEW
TEST.NAME:UPDBlockInstaller_Deserialize.001
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.return:0
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.return:0
TEST.END

-- Test Case: UPDBlockInstaller_Deserialize.002
TEST.UNIT:UPDi_BlockInstaller
TEST.SUBPROGRAM:UPDBlockInstaller_Deserialize
TEST.NEW
TEST.NAME:UPDBlockInstaller_Deserialize.002
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.return:0
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.return:0
TEST.END

-- Test Case: UPDBlockInstaller_Deserialize.003
TEST.UNIT:UPDi_BlockInstaller
TEST.SUBPROGRAM:UPDBlockInstaller_Deserialize
TEST.NEW
TEST.NAME:UPDBlockInstaller_Deserialize.003
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.SizeIn:1
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.data:<<malloc 5>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.data:"arr1"
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.return:0
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.SizeIn:1
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.data:"arr1"
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.return:0
TEST.VALUE_USER_CODE:UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.this
<<UPDi_BlockInstaller.UPDBlockInstaller_Deserialize.this>> = ( &Global_var_08 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDBlockInstaller_GetDataFormat

-- Test Case: UPDBlockInstaller_GetDataFormat.001
TEST.UNIT:UPDi_BlockInstaller
TEST.SUBPROGRAM:UPDBlockInstaller_GetDataFormat
TEST.NEW
TEST.NAME:UPDBlockInstaller_GetDataFormat.001
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_GetDataFormat.pDataFormat:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_GetDataFormat.pDataFormat[0]:eUPDiDataFormat_Invalid
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_GetDataFormat.pDataFormat[0]:eUPDiDataFormat_Raw
TEST.END

-- Subprogram: UPDBlockInstaller_InstallData

-- Test Case: UPDBlockInstaller_InstallData.002
TEST.UNIT:UPDi_BlockInstaller
TEST.SUBPROGRAM:UPDBlockInstaller_InstallData
TEST.NEW
TEST.NAME:UPDBlockInstaller_InstallData.002
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallData.this:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallData.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallData.pSession:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallData.Data:<<malloc 2>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallData.Data:"w"
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallData.Size:2
TEST.VALUE:uut_prototype_stubs.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankActive
TEST.VALUE:uut_prototype_stubs.UPDTarget_GetPartition.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.UPDTarget_GetPartition.return[0].IoAdapter:<<malloc 1>>
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_InstallData.Data:"w"
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_InstallData.Size:2
TEST.EXPECTED:uut_prototype_stubs.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE_USER_CODE:UPDi_BlockInstaller.UPDBlockInstaller_InstallData.pSession.pSession[0].Target
<<UPDi_BlockInstaller.UPDBlockInstaller_InstallData.pSession>>[0].Target = ( &tUPDiInstallSsesession );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDBlockInstaller_InstallErase

-- Test Case: UPDBlockInstaller_InstallErase.001
TEST.UNIT:UPDi_BlockInstaller
TEST.SUBPROGRAM:UPDBlockInstaller_InstallErase
TEST.NEW
TEST.NAME:UPDBlockInstaller_InstallErase.001
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallErase.pSession:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallErase.return:0
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_InstallErase.return:0
TEST.END

-- Test Case: UPDBlockInstaller_InstallErase.002
TEST.UNIT:UPDi_BlockInstaller
TEST.SUBPROGRAM:UPDBlockInstaller_InstallErase
TEST.NEW
TEST.NAME:UPDBlockInstaller_InstallErase.002
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallErase.this:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallErase.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallErase.pSession:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallErase.return:0
TEST.VALUE:uut_prototype_stubs.UPDUpdateMan_GetUpdateBankType.return:eUPDiUpdate_BankInvalid
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_InstallErase.return:0
TEST.END

-- Subprogram: UPDBlockInstaller_InstallExit

-- Test Case: UPDBlockInstaller_InstallExit.001
TEST.UNIT:UPDi_BlockInstaller
TEST.SUBPROGRAM:UPDBlockInstaller_InstallExit
TEST.NEW
TEST.NAME:UPDBlockInstaller_InstallExit.001
TEST.VALUE:UPDi_BlockInstaller.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:10
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.this:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.pSession:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.UPDTarget_InstallExit.this[0].Ram:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.UPDTarget_InstallExit.return:0
TEST.EXPECTED:UPDi_BlockInstaller.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:0
TEST.VALUE_USER_CODE:UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.pSession.pSession[0].Target
<<UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.pSession>>[0].Target = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDBlockInstaller_InstallExit.005
TEST.UNIT:UPDi_BlockInstaller
TEST.SUBPROGRAM:UPDBlockInstaller_InstallExit
TEST.NEW
TEST.NAME:UPDBlockInstaller_InstallExit.005
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.this:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.pSession:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.return:0
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.return:0
TEST.VALUE_USER_CODE:UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.pSession.pSession[0].Target
<<UPDi_BlockInstaller.UPDBlockInstaller_InstallExit.pSession>>[0].Target = ( &tUPDiInstallSsesession );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDBlockInstaller_InstallStart

-- Test Case: UPDBlockInstaller_InstallStart.001
TEST.UNIT:UPDi_BlockInstaller
TEST.SUBPROGRAM:UPDBlockInstaller_InstallStart
TEST.NEW
TEST.NAME:UPDBlockInstaller_InstallStart.001
TEST.VALUE:UPDi_BlockInstaller.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:0
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallStart.this:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallStart.this[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_InstallStart.pSession:<<malloc 1>>
TEST.EXPECTED:UPDi_BlockInstaller.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:0
TEST.VALUE_USER_CODE:UPDi_BlockInstaller.UPDBlockInstaller_InstallStart.pSession.pSession[0].Target
<<UPDi_BlockInstaller.UPDBlockInstaller_InstallStart.pSession>>[0].Target = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDBlockInstaller_Serialize

-- Test Case: UPDBlockInstaller_Serialize.001
TEST.UNIT:UPDi_BlockInstaller
TEST.SUBPROGRAM:UPDBlockInstaller_Serialize
TEST.NEW
TEST.NAME:UPDBlockInstaller_Serialize.001
TEST.VALUE:UPDi_BlockInstaller.UPDBlockInstaller_Serialize.return:0
TEST.EXPECTED:UPDi_BlockInstaller.UPDBlockInstaller_Serialize.return:0
TEST.END
