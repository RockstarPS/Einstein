-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HSM_APP_VHSMKEYSTORE_HT
-- Unit(s) Under Test: vHsmKeyStore
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: vHsmKeyStore

-- Subprogram: vHsmKeyStore_GetKey

-- Test Case: BASIS-PATH-001
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_GetKey
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != key) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keyId:<<MIN>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.key:<<malloc 9>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.key:<<null>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keysize:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_GetKey
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((void *)0 != key) ==> TRUE
      (2) if (0U == vHsmKeyStore_ValidkeyId(keyId)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:vHsmKeyStore.vHsmKeyStore_ValidkeyId
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.return:1
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keyId:<<MIN>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.key:<<malloc 1>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keysize:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_GetKey
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 != key) ==> TRUE
      (2) if (0U == vHsmKeyStore_ValidkeyId(keyId)) ==> TRUE
      (3) if (keyId == (0x30) || (0x2f) == keyId) ==> FALSE
      (5) if ((uint8)0 != ((vHsmKeyStorage_U8A)[KeyIntID]).keyValid && (e_KeyStoreKeyReadable) == ((vHsmKeyStore_Metadata)[KeyIntID]).KeyRead) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:vHsmKeyStore.vHsmKeyStore_IntKeyId
TEST.STUB:vHsmKeyStore.vHsmKeyStore_ValidkeyId
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStorage_U8A[0].keyValid:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_IntKeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keyId:<<MIN>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.key:<<malloc 1>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keysize:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_GetKey
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((void *)0 != key) ==> TRUE
      (2) if (0U == vHsmKeyStore_ValidkeyId(keyId)) ==> TRUE
      (3) if (keyId == (0x30) || (0x2f) == keyId) ==> FALSE
      (5) if ((uint8)0 != ((vHsmKeyStorage_U8A)[KeyIntID]).keyValid && (e_KeyStoreKeyReadable) == ((vHsmKeyStore_Metadata)[KeyIntID]).KeyRead) ==> TRUE
   Test Case Generation Notes:
            Cannot set value of field for a const class/struct/union for ((vHsmKeyStore_Metadata)[KeyIntID]).KeyRead in branch 5
TEST.END_NOTES:
TEST.STUB:vHsmKeyStore.vHsmKeyStore_IntKeyId
TEST.STUB:vHsmKeyStore.vHsmKeyStore_ValidkeyId
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStorage_U8A[0].keyValid:1
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_IntKeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keyId:<<MIN>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.key:<<malloc 1>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keysize:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_GetKey
TEST.NEW
TEST.NAME:BASIS-PATH-005
TEST.BASIS_PATH:5 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((void *)0 != key) ==> TRUE
      (2) if (0U == vHsmKeyStore_ValidkeyId(keyId)) ==> TRUE
      (3) if (keyId == (0x30) || (0x2f) == keyId) ==> TRUE
      (4) if ((uint8)0 != ((vHsmAsymKeys)[KeyIntID - 15U]).asymkeyvalid && (e_KeyStoreKeyReadable) == ((vHsmKeyStore_Metadata)[KeyIntID]).KeyRead) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:vHsmKeyStore.vHsmKeyStore_IntKeyId
TEST.STUB:vHsmKeyStore.vHsmKeyStore_ValidkeyId
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_IntKeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keyId:48
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.key:<<malloc 1>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keysize:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_GetKey
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((void *)0 != key) ==> TRUE
      (2) if (0U == vHsmKeyStore_ValidkeyId(keyId)) ==> TRUE
      (3) if (keyId == (0x30) || (0x2f) == keyId) ==> TRUE
      (4) if ((uint8)0 != ((vHsmAsymKeys)[KeyIntID - 15U]).asymkeyvalid && (e_KeyStoreKeyReadable) == ((vHsmKeyStore_Metadata)[KeyIntID]).KeyRead) ==> TRUE
   Test Case Generation Notes:
            Cannot set value of field for a const class/struct/union for ((vHsmKeyStore_Metadata)[KeyIntID]).KeyRead in branch 4
TEST.END_NOTES:
TEST.STUB:vHsmKeyStore.vHsmKeyStore_IntKeyId
TEST.STUB:vHsmKeyStore.vHsmKeyStore_ValidkeyId
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_IntKeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keyId:48
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.key:<<malloc 1>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_GetKey.keysize:<<malloc 1>>
TEST.END

-- Subprogram: vHsmKeyStore_Init

-- Test Case: BASIS-PATH-001
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_Init
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0x1U == l_RetVal_E) ==> FALSE
      (5) if (0x5 == l_RetVal_E) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.vHsmCrypt_BlobDecapsulation.return:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_Init
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0x1U == l_RetVal_E) ==> FALSE
      (5) if (0x5 == l_RetVal_E) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.vHsmCrypt_BlobDecapsulation.return:5
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_Init
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (0x1U == l_RetVal_E) ==> TRUE
      (2) for (i < 0xb0 + 2) ==> FALSE
      (4) if (isempty == 1) ==> FALSE
      (5) if (0x5 == l_RetVal_E) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set local variable isempty in branch 4
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.vHsmCrypt_BlobDecapsulation.return:1
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_Init
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (0x1U == l_RetVal_E) ==> TRUE
      (2) for (i < 0xb0 + 2) ==> FALSE
      (4) if (isempty == 1) ==> TRUE
      (5) if (0x5 == l_RetVal_E) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set local variable isempty in branch 4
      Cannot set l_RetVal_E due to assignment
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.vHsmCrypt_BlobDecapsulation.return:1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_Init
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (0x1U == l_RetVal_E) ==> TRUE
      (2) for (i < 0xb0 + 2) ==> TRUE
      (3) if ((vHsmBlob_Nor)[i] != 0xffffffffU) ==> TRUE
      (4) if (isempty == 1) ==> FALSE
      (5) if (0x5 == l_RetVal_E) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set i due to assignment
      Cannot set isempty due to assignment
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmBlob_Nor[0]:<<MIN>>
TEST.VALUE:uut_prototype_stubs.vHsmCrypt_BlobDecapsulation.return:1
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_Init
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (0x1U == l_RetVal_E) ==> TRUE
      (2) for (i < 0xb0 + 2) ==> TRUE
      (3) if ((vHsmBlob_Nor)[i] != 0xffffffffU) ==> FALSE
      (4) if (isempty == 1) ==> FALSE
      (5) if (0x5 == l_RetVal_E) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set i due to assignment
      Cannot set local variable isempty in branch 4
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmBlob_Nor[0]:4294967295
TEST.VALUE:uut_prototype_stubs.vHsmCrypt_BlobDecapsulation.return:1
TEST.END

-- Subprogram: vHsmKeyStore_IntKeyId

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_IntKeyId
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (i < 17U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_IntKeyId.KeyId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_IntKeyId
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (i < 17U) ==> TRUE
      (2) if (((KeyStoreKeyID)[i]).KeyId == KeyId) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable to unknown value in branch 2
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_IntKeyId.KeyId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_IntKeyId
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (i < 17U) ==> TRUE
      (2) if (((KeyStoreKeyID)[i]).KeyId == KeyId) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable to unknown value in branch 2
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_IntKeyId.KeyId:<<MIN>>
TEST.END

-- Subprogram: vHsmKeyStore_MainFunction

-- Test Case: BASIS-PATH-001
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (9) case vHsmKeyStore_State ==> default
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStore_State:e_KeyStore_Idle
TEST.EXPECTED:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStore_State:e_KeyStore_Idle
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) case vHsmKeyStore_State ==> e_KeyStore_KeySet
      (2) if (0U == fl_RetVal_E) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStore_State:e_KeyStore_KeySet
TEST.VALUE:uut_prototype_stubs.vHsmCrypt_BlobEncapsulation.return:1
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) case vHsmKeyStore_State ==> e_KeyStore_KeySet
      (2) if (0U == fl_RetVal_E) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStore_State:e_KeyStore_KeySet
TEST.VALUE:uut_prototype_stubs.vHsmCrypt_BlobEncapsulation.return:0
TEST.END

-- Test Case: BASIS-PATH-007
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-007
TEST.BASIS_PATH:7 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (6) case vHsmKeyStore_State ==> e_KeyStore_KeySetTrigR5Core
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStore_State:e_KeyStore_KeySetTrigR5Core
TEST.END

-- Test Case: BASIS-PATH-008
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-008
TEST.BASIS_PATH:8 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (7) case vHsmKeyStore_State ==> e_KeyStore_R5WriteSuccess
      (8) if ((0) < vHsmBlob_AppCounter) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStore_State:e_KeyStore_R5WriteSuccess
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmBlob_AppCounter:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-009
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-009
TEST.BASIS_PATH:9 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (7) case vHsmKeyStore_State ==> e_KeyStore_R5WriteSuccess
      (8) if ((0) < vHsmBlob_AppCounter) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStore_State:e_KeyStore_R5WriteSuccess
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmBlob_AppCounter:<<MAX>>
TEST.END

-- Subprogram: vHsmKeyStore_SetKey

-- Test Case: BASIS-PATH-001
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_SetKey
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((void *)0 != key) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keyId:<<MIN>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.key:<<malloc 9>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.key:<<null>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keysize:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_SetKey
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 6
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((void *)0 != key) ==> TRUE
      (2) if (0U == vHsmKeyStore_ValidkeyId(keyId)) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:vHsmKeyStore.vHsmKeyStore_ValidkeyId
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.return:1
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keyId:<<MIN>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.key:<<malloc 1>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keysize:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_SetKey
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((void *)0 != key) ==> TRUE
      (2) if (0U == vHsmKeyStore_ValidkeyId(keyId)) ==> TRUE
      (3) if (((vHsmKeyStore_Metadata)[IntkeyId_U32]).KeyLen == keysize) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 3
TEST.END_NOTES:
TEST.STUB:vHsmKeyStore.vHsmKeyStore_ValidkeyId
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keyId:<<MIN>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.key:<<malloc 1>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keysize:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_SetKey
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((void *)0 != key) ==> TRUE
      (2) if (0U == vHsmKeyStore_ValidkeyId(keyId)) ==> TRUE
      (3) if (((vHsmKeyStore_Metadata)[IntkeyId_U32]).KeyLen == keysize) ==> TRUE
      (4) if ((0x2f) == keyId || (0x30) == keyId) ==> FALSE
      (5) if ((e_KeyStore_KeyRead_Done) == vHsmKeyStore_State) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 3
TEST.END_NOTES:
TEST.STUB:vHsmKeyStore.vHsmKeyStore_ValidkeyId
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStore_State:e_KeyStore_Idle
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keyId:<<MIN>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.key:<<malloc 1>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keysize:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_SetKey
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((void *)0 != key) ==> TRUE
      (2) if (0U == vHsmKeyStore_ValidkeyId(keyId)) ==> TRUE
      (3) if (((vHsmKeyStore_Metadata)[IntkeyId_U32]).KeyLen == keysize) ==> TRUE
      (4) if ((0x2f) == keyId || (0x30) == keyId) ==> FALSE
      (5) if ((e_KeyStore_KeyRead_Done) == vHsmKeyStore_State) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 3
TEST.END_NOTES:
TEST.STUB:vHsmKeyStore.vHsmKeyStore_ValidkeyId
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStore_State:e_KeyStore_KeyRead_Done
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keyId:<<MIN>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.key:<<malloc 1>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keysize:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_SetKey
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 6 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((void *)0 != key) ==> TRUE
      (2) if (0U == vHsmKeyStore_ValidkeyId(keyId)) ==> TRUE
      (3) if (((vHsmKeyStore_Metadata)[IntkeyId_U32]).KeyLen == keysize) ==> TRUE
      (4) if ((0x2f) == keyId || (0x30) == keyId) ==> TRUE
      (5) if ((e_KeyStore_KeyRead_Done) == vHsmKeyStore_State) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 3
TEST.END_NOTES:
TEST.STUB:vHsmKeyStore.vHsmKeyStore_ValidkeyId
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStore_State:e_KeyStore_Idle
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keyId:47
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.key:<<malloc 1>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keysize:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL.001
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_SetKey
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((void *)0 != key) ==> TRUE
      (2) if (0U == vHsmKeyStore_ValidkeyId(keyId)) ==> TRUE
      (3) if (((vHsmKeyStore_Metadata)[IntkeyId_U32]).KeyLen == keysize) ==> TRUE
      (4) if ((0x2f) == keyId || (0x30) == keyId) ==> TRUE
      (5) if ((e_KeyStore_KeyRead_Done) == vHsmKeyStore_State) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable to unknown value in branch 3
TEST.END_NOTES:
TEST.STUB:vHsmKeyStore.vHsmKeyStore_ValidkeyId
TEST.VALUE:vHsmKeyStore.<<GLOBAL>>.vHsmKeyStore_State:e_KeyStore_Idle
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.return:0
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keyId:47
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.key:<<malloc 1>>
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_SetKey.keysize:<<MIN>>
TEST.END

-- Subprogram: vHsmKeyStore_ValidkeyId

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_ValidkeyId
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (i < 17U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.KeyId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_ValidkeyId
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (i < 17U) ==> TRUE
      (2) if (((KeyStoreKeyID)[i]).KeyId == KeyId) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable to unknown value in branch 2
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.KeyId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_ValidkeyId
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (i < 17U) ==> TRUE
      (2) if (((KeyStoreKeyID)[i]).KeyId == KeyId) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable to unknown value in branch 2
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_ValidkeyId.KeyId:<<MIN>>
TEST.END

-- Subprogram: vHsmKeyStore_WriteStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:vHsmKeyStore
TEST.SUBPROGRAM:vHsmKeyStore_WriteStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:vHsmKeyStore.vHsmKeyStore_WriteStatus.err:<<MIN>>
TEST.END
