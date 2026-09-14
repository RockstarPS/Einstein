-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_ABSTRACTINSTALLER
-- Unit(s) Under Test: UPDi_AbstractInstaller
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: UPDAbstractInstaller_Deserialize

-- Test Case: UPDAbstractInstaller_Deserialize.001
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_Deserialize
TEST.NEW
TEST.NAME:UPDAbstractInstaller_Deserialize.001
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_Deserialize.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_Deserialize.return:1
TEST.END

-- Test Case: UPDAbstractInstaller_Deserialize.002
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_Deserialize
TEST.NEW
TEST.NAME:UPDAbstractInstaller_Deserialize.002
TEST.STUB:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:0
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_Deserialize.return:0
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_Deserialize.return:0
TEST.VALUE_USER_CODE:UPDi_AbstractInstaller.UPDAbstractInstaller_Deserialize.this
<<UPDi_AbstractInstaller.UPDAbstractInstaller_Deserialize.this>> = ( &tUPDiAbstractInsaman );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDAbstractInstaller_Deserialize.004
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_Deserialize
TEST.NEW
TEST.NAME:UPDAbstractInstaller_Deserialize.004
TEST.STUB:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_Deserialize.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_Deserialize.return:1
TEST.END

-- Subprogram: UPDAbstractInstaller_GetDataFormat

-- Test Case: UPDAbstractInstaller_GetDataFormat.001
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_GetDataFormat
TEST.NEW
TEST.NAME:UPDAbstractInstaller_GetDataFormat.001
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_GetDataFormat.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_GetDataFormat.return:1
TEST.END

-- Subprogram: UPDAbstractInstaller_InstallData

-- Test Case: UPDAbstractInstaller_InstallData.001
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_InstallData
TEST.NEW
TEST.NAME:UPDAbstractInstaller_InstallData.001
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallData.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallData.return:1
TEST.END

-- Test Case: UPDAbstractInstaller_InstallData.002
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_InstallData
TEST.NEW
TEST.NAME:UPDAbstractInstaller_InstallData.002
TEST.STUB:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:0
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallData.return:0
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallData.return:0
TEST.VALUE_USER_CODE:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallData.this
<<UPDi_AbstractInstaller.UPDAbstractInstaller_InstallData.this>> = ( &tUPDiAbstractInsaman );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDAbstractInstaller_InstallErase

-- Test Case: UPDAbstractInstaller_InstallErase.001
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_InstallErase
TEST.NEW
TEST.NAME:UPDAbstractInstaller_InstallErase.001
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallErase.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallErase.return:1
TEST.END

-- Subprogram: UPDAbstractInstaller_InstallExit

-- Test Case: UPDAbstractInstaller_InstallExit.001
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_InstallExit
TEST.NEW
TEST.NAME:UPDAbstractInstaller_InstallExit.001
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallExit.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallExit.return:1
TEST.END

-- Test Case: UPDAbstractInstaller_InstallExit.002
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_InstallExit
TEST.NEW
TEST.NAME:UPDAbstractInstaller_InstallExit.002
TEST.STUB:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:0
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallExit.pSession:<<malloc 1>>
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallExit.return:0
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallExit.return:0
TEST.STUB_VAL_USER_CODE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.this
<<UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.this>> = ( &tUPDiAbstractInsaman );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallExit.this
<<UPDi_AbstractInstaller.UPDAbstractInstaller_InstallExit.this>> = ( &tUPDiAbstractInsaman );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDAbstractInstaller_InstallStart

-- Test Case: UPDAbstractInstaller_InstallStart.001
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_InstallStart
TEST.NEW
TEST.NAME:UPDAbstractInstaller_InstallStart.001
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallStart.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_InstallStart.return:1
TEST.END

-- Subprogram: UPDAbstractInstaller_IsInvalid

-- Test Case: UPDAbstractInstaller_IsInvalid.001
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_IsInvalid
TEST.NEW
TEST.NAME:UPDAbstractInstaller_IsInvalid.001
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.END

-- Test Case: UPDAbstractInstaller_IsInvalid.002
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_IsInvalid
TEST.NEW
TEST.NAME:UPDAbstractInstaller_IsInvalid.002
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.END

-- Test Case: UPDAbstractInstaller_IsInvalid.003
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_IsInvalid
TEST.NEW
TEST.NAME:UPDAbstractInstaller_IsInvalid.003
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.END

-- Test Case: UPDAbstractInstaller_IsInvalid.004
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_IsInvalid
TEST.NEW
TEST.NAME:UPDAbstractInstaller_IsInvalid.004
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.END

-- Test Case: UPDAbstractInstaller_IsInvalid.005
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_IsInvalid
TEST.NEW
TEST.NAME:UPDAbstractInstaller_IsInvalid.005
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.END

-- Test Case: UPDAbstractInstaller_IsInvalid.006
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_IsInvalid
TEST.NEW
TEST.NAME:UPDAbstractInstaller_IsInvalid.006
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.END

-- Test Case: UPDAbstractInstaller_IsInvalid.007
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_IsInvalid
TEST.NEW
TEST.NAME:UPDAbstractInstaller_IsInvalid.007
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.END

-- Test Case: UPDAbstractInstaller_IsInvalid.008
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_IsInvalid
TEST.NEW
TEST.NAME:UPDAbstractInstaller_IsInvalid.008
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:0
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:0
TEST.VALUE_USER_CODE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.this
<<UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.this>> = ( &AbstractInstll );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDAbstractInstaller_Serialize

-- Test Case: UPDAbstractInstaller_Serialize.001
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_Serialize
TEST.NEW
TEST.NAME:UPDAbstractInstaller_Serialize.001
TEST.STUB:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:0
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_Serialize.return:0
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_Serialize.return:0
TEST.VALUE_USER_CODE:UPDi_AbstractInstaller.UPDAbstractInstaller_Serialize.this
<<UPDi_AbstractInstaller.UPDAbstractInstaller_Serialize.this>> = ( &tUPDiAbstractInsaman );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDAbstractInstaller_Serialize.004
TEST.UNIT:UPDi_AbstractInstaller
TEST.SUBPROGRAM:UPDAbstractInstaller_Serialize
TEST.NEW
TEST.NAME:UPDAbstractInstaller_Serialize.004
TEST.STUB:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_IsInvalid.return:1
TEST.VALUE:UPDi_AbstractInstaller.UPDAbstractInstaller_Serialize.return:1
TEST.EXPECTED:UPDi_AbstractInstaller.UPDAbstractInstaller_Serialize.return:1
TEST.END
