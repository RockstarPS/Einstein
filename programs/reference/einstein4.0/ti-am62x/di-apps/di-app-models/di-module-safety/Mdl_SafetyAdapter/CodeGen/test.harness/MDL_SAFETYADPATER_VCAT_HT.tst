-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : TOYOTA_MDL_SAFETYADPATER_VCAT_HT
-- Unit(s) Under Test: Mdl_SafetyAdapter Mdl_SafetyAdapter_RxCfg
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: Mdl_SafetyAdapter

-- Subprogram: Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (SignalId < 39U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus.SignalId:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (1 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:32
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (1 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0)) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus.SignalId:<<MIN>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_GetRXCAN_MissingOW_BITstatus.001
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:3
TEST.END

-- Subprogram: Mdl_SafetyAdapter_Ign_Networkmode_status

-- Test Case: BASIS-PATH-001-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_Ign_Networkmode_status
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE
TEST.BASIS_PATH:1 of 5 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (fl_network_mode_status_u8 == 2U) ==> FALSE
      (2) if (fl_network_mode_status_u8 == 1U) ==> FALSE
      (3) if (fl_network_mode_status_u8 == 0U) ==> FALSE
      (4) if (fl_Ign_IoHab_Status_S32 == (uint8)2) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable fl_network_mode_status_u8 in branch 1
      Cannot set local variable fl_network_mode_status_u8 in branch 2
      Cannot set local variable fl_network_mode_status_u8 in branch 3
      Cannot set local variable fl_Ign_IoHab_Status_S32 in branch 4
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_Ign_Networkmode_status
TEST.NEW
TEST.NAME:BASIS-PATH-002-TEMPLATE
TEST.BASIS_PATH:2 of 5 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (fl_network_mode_status_u8 == 2U) ==> FALSE
      (2) if (fl_network_mode_status_u8 == 1U) ==> FALSE
      (3) if (fl_network_mode_status_u8 == 0U) ==> FALSE
      (4) if (fl_Ign_IoHab_Status_S32 == (uint8)2) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable fl_network_mode_status_u8 in branch 1
      Cannot set local variable fl_network_mode_status_u8 in branch 2
      Cannot set local variable fl_network_mode_status_u8 in branch 3
      Cannot set local variable fl_Ign_IoHab_Status_S32 in branch 4
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_Ign_Networkmode_status
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE
TEST.BASIS_PATH:3 of 5 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (fl_network_mode_status_u8 == 2U) ==> FALSE
      (2) if (fl_network_mode_status_u8 == 1U) ==> FALSE
      (3) if (fl_network_mode_status_u8 == 0U) ==> TRUE
      (4) if (fl_Ign_IoHab_Status_S32 == (uint8)2) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable fl_network_mode_status_u8 in branch 1
      Cannot set local variable fl_network_mode_status_u8 in branch 2
      Cannot set local variable fl_network_mode_status_u8 in branch 3
      Cannot set local variable fl_Ign_IoHab_Status_S32 in branch 4
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-004-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_Ign_Networkmode_status
TEST.NEW
TEST.NAME:BASIS-PATH-004-TEMPLATE
TEST.BASIS_PATH:4 of 5 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (fl_network_mode_status_u8 == 2U) ==> FALSE
      (2) if (fl_network_mode_status_u8 == 1U) ==> TRUE
      (4) if (fl_Ign_IoHab_Status_S32 == (uint8)2) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable fl_network_mode_status_u8 in branch 1
      Cannot set local variable fl_network_mode_status_u8 in branch 2
      Cannot set local variable fl_Ign_IoHab_Status_S32 in branch 4
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-005-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_Ign_Networkmode_status
TEST.NEW
TEST.NAME:BASIS-PATH-005-TEMPLATE
TEST.BASIS_PATH:5 of 5 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (fl_network_mode_status_u8 == 2U) ==> TRUE
      (4) if (fl_Ign_IoHab_Status_S32 == (uint8)2) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable fl_network_mode_status_u8 in branch 1
      Cannot set local variable fl_Ign_IoHab_Status_S32 in branch 4
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (SignalId < 39U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer.SignalId:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (ByteIndex < 5U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (ByteIndex < 5U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_Mdl_SafetyAdapter_ReloadMissingTimer.SignalId:<<MIN>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetSignalStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetSignalStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) == 1) ==> FALSE
      (2) if (Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) == 1) ==> FALSE
      (3) if (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) == 1) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalInvalid
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetSignalStatus
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) == 1) ==> FALSE
      (2) if (Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) == 1) ==> FALSE
      (3) if (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) == 1) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanGetSignalStatus.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetSignalStatus
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) == 1) ==> FALSE
      (2) if (Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) == 1) ==> TRUE
      (3) if (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) == 1) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanGetSignalStatus.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetSignalStatus
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) == 1) ==> TRUE
      (2) if (Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) == 1) ==> FALSE
      (3) if (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) == 1) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanGetSignalStatus.SignalId:<<MIN>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCanGetSignalStatus.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetSignalStatus
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCanGetSignalStatus.001
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalInvalid
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanIsSignalNREnabled[0]:eSIGNAL_NEVER_RECEIVED
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:6
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanGetSignalStatus.SignalId:6
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanIsSignalInvalid

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalInvalid
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (pSignalConfig->SignalInvalidIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 1 since it requires user code.
      Cannot set variable pSignalConfig in branch 1 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalInvalidIdx:0
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalInvalidStatus[0]:1
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalInvalid.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-001-PARTIAL.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalInvalid
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (pSignalConfig->SignalInvalidIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 1 since it requires user code.
      Cannot set variable pSignalConfig in branch 1 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalInvalidIdx:0
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalInvalidStatus[0]:0
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalInvalid.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalInvalid
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (pSignalConfig->SignalInvalidIdx < 1U) ==> TRUE
      (2) if (ByteIndex < (1U)) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 1 since it requires user code.
      Cannot set variable pSignalConfig in branch 1 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalInvalid.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalInvalid
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (pSignalConfig->SignalInvalidIdx < 1U) ==> TRUE
      (2) if (ByteIndex < (1U)) ==> TRUE
      (3) if (((Mdl_SafetyAdapter_RxCanSignalInvalidStatus)[ByteIndex] & (uint8)(1U << (pSignalConfig->SignalInvalidIdx & 0x7U))) != 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 1 since it requires user code.
      Cannot set variable pSignalConfig in branch 1 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalInvalid.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalInvalid
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (pSignalConfig->SignalInvalidIdx < 1U) ==> TRUE
      (2) if (ByteIndex < (1U)) ==> TRUE
      (3) if (((Mdl_SafetyAdapter_RxCanSignalInvalidStatus)[ByteIndex] & (uint8)(1U << (pSignalConfig->SignalInvalidIdx & 0x7U))) != 0U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 1 since it requires user code.
      Cannot set variable pSignalConfig in branch 1 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalInvalidStatus[0]:<<MAX>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalInvalid.SignalId:<<MIN>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanIsSignalMissing

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ByteIndex < (5U)) ==> FALSE
   Test Case Generation Notes:
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ByteIndex < (5U)) ==> TRUE
      (2) if (((Mdl_SafetyAdapter_RxCanSignalMissingStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingStatus[0]:0
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (ByteIndex < (5U)) ==> TRUE
      (2) if (((Mdl_SafetyAdapter_RxCanSignalMissingStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ==> TRUE
   Test Case Generation Notes:
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingStatus[0]:<<MAX>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:<<MIN>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCanIsSignalMissing.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCanIsSignalMissing.001
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:1
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanIsSignalNR

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (ByteIndex < (5U)) ==> FALSE
   Test Case Generation Notes:
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanGetSignalStatus
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ByteIndex < (5U)) ==> TRUE
      (2) if (((Mdl_SafetyAdapter_RxCanSignalNRStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalNRStatus[0]:0
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (ByteIndex < (5U)) ==> TRUE
      (2) if (((Mdl_SafetyAdapter_RxCanSignalNRStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ==> TRUE
   Test Case Generation Notes:
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalNRStatus[0]:<<MAX>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR.SignalId:<<MIN>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanSetSignalValue

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 9
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MAX>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 9>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<null>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 8 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 8 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.002
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 8 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.003
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 8 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.004
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.004
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 8 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.005
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.005
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 8 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.006
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.006
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 8 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
      Conflict: Cannot resolve multiple comparisons (  ) in branch 8
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
      Conflict: Cannot resolve multiple comparisons (  ) in branch 8
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.002
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
      Conflict: Cannot resolve multiple comparisons (  ) in branch 8
TEST.END_NOTES:
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.003
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
      Conflict: Cannot resolve multiple comparisons (  ) in branch 8
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:40
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.004
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.004
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
      Conflict: Cannot resolve multiple comparisons (  ) in branch 8
TEST.END_NOTES:
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:40
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.005
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.005
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
      Conflict: Cannot resolve multiple comparisons (  ) in branch 8
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:40
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.006
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.006
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (8) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 8 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 8 since it requires user code.
      Conflict: Cannot resolve multiple comparisons (  ) in branch 8
TEST.END_NOTES:
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (7) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 7 since it requires user code.
      Cannot set variable pSignalConfig in branch 7 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 7 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (6) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 6 since it requires user code.
      Cannot set variable pSignalConfig in branch 6 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 6 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (4) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (5) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 3 since it requires user code.
      Cannot set variable pSignalConfig in branch 3 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 4 since it requires user code.
      Cannot set variable pSignalConfig in branch 4 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 4 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 5 since it requires user code.
      Cannot set variable pSignalConfig in branch 5 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 5 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (4) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (5) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 3 since it requires user code.
      Cannot set variable pSignalConfig in branch 3 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 4 since it requires user code.
      Cannot set variable pSignalConfig in branch 4 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 4 since it requires user code.
      Cannot set variable pSignalConfig in branch 5 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 5 since it requires user code.
      Conflict: Cannot resolve multiple comparisons (  ) in branch 5
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (4) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 3 since it requires user code.
      Cannot set variable pSignalConfig in branch 3 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 4 since it requires user code.
      Cannot set variable pSignalConfig in branch 4 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 4 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (SignalId < 39U && pSignalValue != (void *)0) ==> TRUE
      (2) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 3 since it requires user code.
      Cannot set variable pSignalConfig in branch 3 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 3 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCanSetSignalValue.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCanSetSignalValue.001
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<malloc 9>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<null>>
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue:<<null>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanSignalInvalidProcessing

-- Test Case: BASIS-PATH-001-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalInvalidProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE
TEST.BASIS_PATH:1 of 9 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (SignalInvalidIdx < (1U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalInvalidConfig[0].SignalInvalidSigIdx:40
TEST.END

-- Test Case: BASIS-PATH-002-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalInvalidProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-002-TEMPLATE
TEST.BASIS_PATH:2 of 9 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (SignalInvalidIdx < (1U)) ==> TRUE
      (2) if (SignalId < 39U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable pSignalInvalidConfig in branch 2 since it requires user code.
      Cannot set variable pSignalInvalidConfig->SignalInvalidSigIdx in branch 2 since it requires user code.
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalInvalidProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (SignalInvalidIdx < (1U)) ==> TRUE
      (2) if (SignalId < 39U) ==> TRUE
      (3) if (1 == ((((Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled)[ByteIndex] & (uint8)(1U << (SignalInvalidIdx & (0x7U)))) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) != 1) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable pSignalInvalidConfig in branch 2 since it requires user code.
      Cannot set variable pSignalInvalidConfig->SignalInvalidSigIdx in branch 2 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 3
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalInvalidProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) for (SignalInvalidIdx < (1U)) ==> TRUE
      (2) if (SignalId < 39U) ==> TRUE
      (3) if (1 == ((((Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled)[ByteIndex] & (uint8)(1U << (SignalInvalidIdx & (0x7U)))) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) != 1) ==> TRUE
      (4) if (pSignalInvalidConfig->pSignalInvalidCheckFunc != (void *)0) ==> FALSE
      (5) if (InvalidStatus != 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable pSignalInvalidConfig in branch 2 since it requires user code.
      Cannot set variable pSignalInvalidConfig->SignalInvalidSigIdx in branch 2 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 3
      Cannot set variable pSignalInvalidConfig->pSignalInvalidCheckFunc in branch 4 since it has a type which requires user code.
      Cannot set local variable InvalidStatus in branch 5
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalInvalidProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) for (SignalInvalidIdx < (1U)) ==> TRUE
      (2) if (SignalId < 39U) ==> TRUE
      (3) if (1 == ((((Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled)[ByteIndex] & (uint8)(1U << (SignalInvalidIdx & (0x7U)))) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) != 1) ==> TRUE
      (4) if (pSignalInvalidConfig->pSignalInvalidCheckFunc != (void *)0) ==> FALSE
      (5) if (InvalidStatus != 0) ==> TRUE
      (6) if (0 == ((((Mdl_SafetyAdapter_RxCanSignalInvalidStatus)[ByteIndex] & (uint8)(1U << (SignalInvalidIdx & (0x7)))) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] == (0U)) ==> FALSE
      (7) if ((Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] > (0U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable pSignalInvalidConfig in branch 2 since it requires user code.
      Cannot set variable pSignalInvalidConfig->SignalInvalidSigIdx in branch 2 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 3
      Cannot set variable pSignalInvalidConfig->pSignalInvalidCheckFunc in branch 4 since it has a type which requires user code.
      Cannot set local variable InvalidStatus in branch 5
      Cannot set SignalInvalidIdx due to assignment
      Cannot set variable pSignalInvalidConfig in branch 7 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalInvalidStatus[0]:<<MAX>>
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalInvalidCounter[0]:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalInvalidProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) for (SignalInvalidIdx < (1U)) ==> TRUE
      (2) if (SignalId < 39U) ==> TRUE
      (3) if (1 == ((((Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled)[ByteIndex] & (uint8)(1U << (SignalInvalidIdx & (0x7U)))) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) != 1) ==> TRUE
      (4) if (pSignalInvalidConfig->pSignalInvalidCheckFunc != (void *)0) ==> FALSE
      (5) if (InvalidStatus != 0) ==> TRUE
      (6) if (0 == ((((Mdl_SafetyAdapter_RxCanSignalInvalidStatus)[ByteIndex] & (uint8)(1U << (SignalInvalidIdx & (0x7)))) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] == (0U)) ==> FALSE
      (7) if ((Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] > (0U)) ==> TRUE
      (8) if ((Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] == (0U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable pSignalInvalidConfig in branch 2 since it requires user code.
      Cannot set variable pSignalInvalidConfig->SignalInvalidSigIdx in branch 2 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 3
      Cannot set variable pSignalInvalidConfig->pSignalInvalidCheckFunc in branch 4 since it has a type which requires user code.
      Cannot set local variable InvalidStatus in branch 5
      Cannot set SignalInvalidIdx due to assignment
      Cannot set variable pSignalInvalidConfig in branch 7 since it requires user code.
      Cannot set (Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalInvalidStatus[0]:<<MAX>>
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalInvalidCounter[0]:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalInvalidProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) for (SignalInvalidIdx < (1U)) ==> TRUE
      (2) if (SignalId < 39U) ==> TRUE
      (3) if (1 == ((((Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled)[ByteIndex] & (uint8)(1U << (SignalInvalidIdx & (0x7U)))) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) != 1) ==> TRUE
      (4) if (pSignalInvalidConfig->pSignalInvalidCheckFunc != (void *)0) ==> FALSE
      (5) if (InvalidStatus != 0) ==> TRUE
      (6) if (0 == ((((Mdl_SafetyAdapter_RxCanSignalInvalidStatus)[ByteIndex] & (uint8)(1U << (SignalInvalidIdx & (0x7)))) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] == (0U)) ==> FALSE
      (7) if ((Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] > (0U)) ==> TRUE
      (8) if ((Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] == (0U)) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable pSignalInvalidConfig in branch 2 since it requires user code.
      Cannot set variable pSignalInvalidConfig->SignalInvalidSigIdx in branch 2 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 3
      Cannot set variable pSignalInvalidConfig->pSignalInvalidCheckFunc in branch 4 since it has a type which requires user code.
      Cannot set local variable InvalidStatus in branch 5
      Cannot set SignalInvalidIdx due to assignment
      Cannot set variable pSignalInvalidConfig in branch 7 since it requires user code.
      Cannot set (Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalInvalidStatus[0]:<<MAX>>
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalInvalidCounter[0]:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalInvalidProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) for (SignalInvalidIdx < (1U)) ==> TRUE
      (2) if (SignalId < 39U) ==> TRUE
      (3) if (1 == ((((Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled)[ByteIndex] & (uint8)(1U << (SignalInvalidIdx & (0x7U)))) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) != 1) ==> TRUE
      (4) if (pSignalInvalidConfig->pSignalInvalidCheckFunc != (void *)0) ==> FALSE
      (5) if (InvalidStatus != 0) ==> TRUE
      (6) if (0 == ((((Mdl_SafetyAdapter_RxCanSignalInvalidStatus)[ByteIndex] & (uint8)(1U << (SignalInvalidIdx & (0x7)))) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] == (0U)) ==> TRUE
      (7) if ((Mdl_SafetyAdapter_RxCanSignalInvalidCounter)[SignalInvalidIdx] > (0U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable pSignalInvalidConfig in branch 2 since it requires user code.
      Cannot set variable pSignalInvalidConfig->SignalInvalidSigIdx in branch 2 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 3
      Cannot set variable pSignalInvalidConfig->pSignalInvalidCheckFunc in branch 4 since it has a type which requires user code.
      Cannot set local variable InvalidStatus in branch 5
      Cannot set SignalInvalidIdx due to assignment
      Cannot set variable pSignalInvalidConfig in branch 7 since it requires user code.
      Cannot set variable pSignalInvalidConfig->SignalInvalidCounterValue in branch 7 since it requires user code.
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalInvalidProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 9 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) for (SignalInvalidIdx < (1U)) ==> TRUE
      (2) if (SignalId < 39U) ==> TRUE
      (3) if (1 == ((((Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled)[ByteIndex] & (uint8)(1U << (SignalInvalidIdx & (0x7U)))) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalNR(SignalId) != 1) ==> TRUE
      (4) if (pSignalInvalidConfig->pSignalInvalidCheckFunc != (void *)0) ==> TRUE
      (5) if (InvalidStatus != 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable pSignalInvalidConfig in branch 2 since it requires user code.
      Cannot set variable pSignalInvalidConfig->SignalInvalidSigIdx in branch 2 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 3
      Cannot set variable pSignalInvalidConfig->pSignalInvalidCheckFunc in branch 4 since it has a type which requires user code.
      Cannot set InvalidStatus due to assignment
TEST.END_NOTES:
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCanSignalInvalidProcessing.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalInvalidProcessing
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCanSignalInvalidProcessing.001
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanIsSignalNREnabled[0]:1
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanIsSignalInvalidEnabled[0]:1
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanSignalMissingProcessing

-- Test Case: BASIS-PATH-001-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalMissingProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE
TEST.BASIS_PATH:1 of 5 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (SignalId < 39U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalMissingProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-002-TEMPLATE
TEST.BASIS_PATH:2 of 5 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (SignalId < 39U) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Conflict: Unable to validate expression-to-expression comparison in branch 2
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalMissingProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (SignalId < 39U) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
      (3) if ((Mdl_SafetyAdapter_RxCanSignalMissingCounter)[SignalId] > (0U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set SignalId due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingCounter[0]:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalMissingProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) for (SignalId < 39U) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
      (3) if ((Mdl_SafetyAdapter_RxCanSignalMissingCounter)[SignalId] > (0U)) ==> TRUE
      (4) if ((Mdl_SafetyAdapter_RxCanSignalMissingCounter)[SignalId] == (0U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set SignalId due to assignment
      Cannot set (Mdl_SafetyAdapter_RxCanSignalMissingCounter)[SignalId] due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingCounter[0]:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalMissingProcessing
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) for (SignalId < 39U) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
      (3) if ((Mdl_SafetyAdapter_RxCanSignalMissingCounter)[SignalId] > (0U)) ==> TRUE
      (4) if ((Mdl_SafetyAdapter_RxCanSignalMissingCounter)[SignalId] == (0U)) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set SignalId due to assignment
      Cannot set (Mdl_SafetyAdapter_RxCanSignalMissingCounter)[SignalId] due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingCounter[0]:<<MAX>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCanSignalMissingProcessing.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalMissingProcessing
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCanSignalMissingProcessing.001
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled[0]:1
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingCounter[0]:1
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCanSignalMissingProcessing.002
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalMissingProcessing
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCanSignalMissingProcessing.002
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled[0]:1
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingCounter[0]:0
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCanSignalMissingProcessing.003
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanSignalMissingProcessing
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCanSignalMissingProcessing.003
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled[0]:1
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingCounter[0]:2
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanVarInit

-- Test Case: BASIS-PATH-001-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanVarInit
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE
TEST.BASIS_PATH:1 of 3 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (SignalInvalidIdx < 1U) ==> FALSE
      (2) for (SignalId < 39U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Conflict: Unable to validate expression-to-expression comparison in branch 2
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanVarInit
TEST.NEW
TEST.NAME:BASIS-PATH-002-TEMPLATE
TEST.BASIS_PATH:2 of 3 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (SignalInvalidIdx < 1U) ==> FALSE
      (2) for (SignalId < 39U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Conflict: Unable to validate expression-to-expression comparison in branch 2
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanVarInit
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE
TEST.BASIS_PATH:3 of 3 (template)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) for (SignalInvalidIdx < 1U) ==> TRUE
      (2) for (SignalId < 39U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 1
      Cannot set variable pSignalInvalidConfig in branch 2 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 2
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCan_GetSafeSignalValue

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSafeSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((l_Signal_status & 1U) == 1U) ==> FALSE
      (2) if ((l_Signal_status & 2U) == 2U) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable l_Signal_status in branch 1
      Cannot set local variable l_Signal_status in branch 2
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSafeSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((l_Signal_status & 1U) == 1U) ==> FALSE
      (2) if ((l_Signal_status & 2U) == 2U) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable l_Signal_status in branch 1
      Cannot set local variable l_Signal_status in branch 2
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSafeSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((l_Signal_status & 1U) == 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable l_Signal_status in branch 1
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSafeSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.001
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_MISSING
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.002
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSafeSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.002
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.003
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSafeSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.003
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_NEVER_RECEIVED
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSafeSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCan_GetSignalValue

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 20
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 9>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<null>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 9>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<null>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> TRUE
      (11) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 6U)) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) != 0 || Skip_Invalid_Storage != 0)) ==> FALSE
      (12) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) != 0) ==> FALSE
      (13) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (17) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (18) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (19) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 11 since it requires user code.
      Cannot set variable pSignalConfig in branch 11 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 11
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 12 since it requires user code.
      Cannot set variable pSignalConfig in branch 12 since it requires user code.
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 13 since it requires user code.
      Cannot set variable pSignalConfig in branch 13 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 17 since it requires user code.
      Cannot set variable pSignalConfig in branch 17 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 18 since it requires user code.
      Cannot set variable pSignalConfig in branch 18 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 18 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 19 since it requires user code.
      Cannot set variable pSignalConfig in branch 19 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 19 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> TRUE
      (11) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 6U)) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) != 0 || Skip_Invalid_Storage != 0)) ==> FALSE
      (12) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) != 0) ==> FALSE
      (13) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (17) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (18) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (19) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 11 since it requires user code.
      Cannot set variable pSignalConfig in branch 11 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 11
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 12 since it requires user code.
      Cannot set variable pSignalConfig in branch 12 since it requires user code.
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 13 since it requires user code.
      Cannot set variable pSignalConfig in branch 13 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 17 since it requires user code.
      Cannot set variable pSignalConfig in branch 17 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 18 since it requires user code.
      Cannot set variable pSignalConfig in branch 18 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 18 since it requires user code.
      Cannot set variable pSignalConfig in branch 19 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 19 since it requires user code.
      Conflict: Cannot resolve multiple comparisons (  ) in branch 19
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> TRUE
      (11) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 6U)) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) != 0 || Skip_Invalid_Storage != 0)) ==> FALSE
      (12) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) != 0) ==> FALSE
      (13) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (17) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (18) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 11 since it requires user code.
      Cannot set variable pSignalConfig in branch 11 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 11
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 12 since it requires user code.
      Cannot set variable pSignalConfig in branch 12 since it requires user code.
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 13 since it requires user code.
      Cannot set variable pSignalConfig in branch 13 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 17 since it requires user code.
      Cannot set variable pSignalConfig in branch 17 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 18 since it requires user code.
      Cannot set variable pSignalConfig in branch 18 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 18 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> TRUE
      (11) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 6U)) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) != 0 || Skip_Invalid_Storage != 0)) ==> FALSE
      (12) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) != 0) ==> FALSE
      (13) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (17) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 11 since it requires user code.
      Cannot set variable pSignalConfig in branch 11 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 11
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 12 since it requires user code.
      Cannot set variable pSignalConfig in branch 12 since it requires user code.
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 13 since it requires user code.
      Cannot set variable pSignalConfig in branch 13 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 17 since it requires user code.
      Cannot set variable pSignalConfig in branch 17 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 17 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> TRUE
      (11) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 6U)) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) != 0 || Skip_Invalid_Storage != 0)) ==> FALSE
      (12) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) != 0) ==> FALSE
      (13) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> TRUE
      (14) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (15) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (16) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 11 since it requires user code.
      Cannot set variable pSignalConfig in branch 11 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 11
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 12 since it requires user code.
      Cannot set variable pSignalConfig in branch 12 since it requires user code.
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 13 since it requires user code.
      Cannot set variable pSignalConfig in branch 13 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 14 since it requires user code.
      Cannot set variable pSignalConfig in branch 14 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 15 since it requires user code.
      Cannot set variable pSignalConfig in branch 15 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 15 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 16 since it requires user code.
      Cannot set variable pSignalConfig in branch 16 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 16 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> TRUE
      (11) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 6U)) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) != 0 || Skip_Invalid_Storage != 0)) ==> FALSE
      (12) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) != 0) ==> FALSE
      (13) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> TRUE
      (14) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (15) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (16) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 11 since it requires user code.
      Cannot set variable pSignalConfig in branch 11 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 11
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 12 since it requires user code.
      Cannot set variable pSignalConfig in branch 12 since it requires user code.
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 13 since it requires user code.
      Cannot set variable pSignalConfig in branch 13 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 14 since it requires user code.
      Cannot set variable pSignalConfig in branch 14 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 15 since it requires user code.
      Cannot set variable pSignalConfig in branch 15 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 15 since it requires user code.
      Cannot set variable pSignalConfig in branch 16 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 16 since it requires user code.
      Conflict: Cannot resolve multiple comparisons (  ) in branch 16
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> TRUE
      (11) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 6U)) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) != 0 || Skip_Invalid_Storage != 0)) ==> FALSE
      (12) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) != 0) ==> FALSE
      (13) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> TRUE
      (14) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (15) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 11 since it requires user code.
      Cannot set variable pSignalConfig in branch 11 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 11
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 12 since it requires user code.
      Cannot set variable pSignalConfig in branch 12 since it requires user code.
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 13 since it requires user code.
      Cannot set variable pSignalConfig in branch 13 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 14 since it requires user code.
      Cannot set variable pSignalConfig in branch 14 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 15 since it requires user code.
      Cannot set variable pSignalConfig in branch 15 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 15 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> TRUE
      (11) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 6U)) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) != 0 || Skip_Invalid_Storage != 0)) ==> FALSE
      (12) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) != 0) ==> FALSE
      (13) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> TRUE
      (14) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 1U) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 11 since it requires user code.
      Cannot set variable pSignalConfig in branch 11 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 11
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 12 since it requires user code.
      Cannot set variable pSignalConfig in branch 12 since it requires user code.
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 13 since it requires user code.
      Cannot set variable pSignalConfig in branch 13 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 14 since it requires user code.
      Cannot set variable pSignalConfig in branch 14 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 14 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> TRUE
      (11) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 6U)) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) != 0 || Skip_Invalid_Storage != 0)) ==> FALSE
      (12) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) != 0) ==> TRUE
      (13) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (17) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (18) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (19) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 11 since it requires user code.
      Cannot set variable pSignalConfig in branch 11 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 11
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 12 since it requires user code.
      Cannot set variable pSignalConfig in branch 12 since it requires user code.
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 13 since it requires user code.
      Cannot set variable pSignalConfig in branch 13 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 17 since it requires user code.
      Cannot set variable pSignalConfig in branch 17 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 18 since it requires user code.
      Cannot set variable pSignalConfig in branch 18 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 18 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 19 since it requires user code.
      Cannot set variable pSignalConfig in branch 19 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 19 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-012-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-012-PARTIAL
TEST.BASIS_PATH:12 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 12
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> TRUE
      (11) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 6U)) != 0U) ? 1 : 0) && (Mdl_SafetyAdapter_RxCanIsSignalInvalid(SignalId) != 0 || Skip_Invalid_Storage != 0)) ==> TRUE
      (12) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 5U)) != 0U) ? 1 : 0) && Mdl_SafetyAdapter_RxCanIsSignalMissing(SignalId) != 0) ==> FALSE
      (13) if (0 != (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 3U)) != 0U) ? 1 : 0)) ==> FALSE
      (17) if (pSignalConfig->SignalLengthInByte == 1U && pSignalConfig->SignalBufferStartIdx < 39U) ==> FALSE
      (18) if (pSignalConfig->SignalLengthInByte == 2U && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
      (19) if ((pSignalConfig->SignalLengthInByte > 2U && pSignalConfig->SignalLengthInByte <= 4U) && pSignalConfig->SignalBufferStartIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 11 since it requires user code.
      Cannot set variable pSignalConfig in branch 11 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 11
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 12 since it requires user code.
      Cannot set variable pSignalConfig in branch 12 since it requires user code.
      Cannot set variable pSignalConfig->RxSigMonitoringType in branch 13 since it requires user code.
      Cannot set variable pSignalConfig in branch 13 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 17 since it requires user code.
      Cannot set variable pSignalConfig in branch 17 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 18 since it requires user code.
      Cannot set variable pSignalConfig in branch 18 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 18 since it requires user code.
      Cannot set variable pSignalConfig->SignalLengthInByte in branch 19 since it requires user code.
      Cannot set variable pSignalConfig in branch 19 since it requires user code.
      Cannot set variable pSignalConfig->SignalBufferStartIdx in branch 19 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL
TEST.BASIS_PATH:13 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 13
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (SigStatus == 0U) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set GetLocalBuffer due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL
TEST.BASIS_PATH:14 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 14
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (SigStatus == 0U) ==> TRUE
      (4) if (pSignalConfig->SignalGetFunctIdx < 39U) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable pSignalConfig->SignalGetFunctIdx in branch 4 since it requires user code.
      Cannot set variable pSignalConfig in branch 4 since it requires user code.
      Cannot set local variable GetLocalBuffer in branch 10
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-015-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-015-PARTIAL
TEST.BASIS_PATH:15 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 15
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (SigStatus == 0U) ==> TRUE
      (4) if (pSignalConfig->SignalGetFunctIdx < 39U) ==> TRUE
      (5) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 2U)) != 0U) ? 1 : 0) && pSignalConfig->SignalInvalidIdx < 1U) ==> FALSE
      (8) if (0 == Skip_Invalid_Storage) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable pSignalConfig->SignalGetFunctIdx in branch 4 since it requires user code.
      Cannot set variable pSignalConfig in branch 4 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 5
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 5 since it requires user code.
      Cannot set variable pSignalConfig in branch 5 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 8
      Cannot set local variable GetLocalBuffer in branch 10
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-016-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-016-PARTIAL
TEST.BASIS_PATH:16 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 16
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (SigStatus == 0U) ==> TRUE
      (4) if (pSignalConfig->SignalGetFunctIdx < 39U) ==> TRUE
      (5) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 2U)) != 0U) ? 1 : 0) && pSignalConfig->SignalInvalidIdx < 1U) ==> FALSE
      (8) if (0 == Skip_Invalid_Storage) ==> TRUE
      (9) if (pGetSignalFunction != (void *)0) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable pSignalConfig->SignalGetFunctIdx in branch 4 since it requires user code.
      Cannot set variable pSignalConfig in branch 4 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 5
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 5 since it requires user code.
      Cannot set variable pSignalConfig in branch 5 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 8
      Cannot set variable pGetSignalFunction in branch 9 since it has a type which requires user code.
      Cannot set local variable GetLocalBuffer in branch 10
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-017-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-017-PARTIAL
TEST.BASIS_PATH:17 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 17
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (SigStatus == 0U) ==> TRUE
      (4) if (pSignalConfig->SignalGetFunctIdx < 39U) ==> TRUE
      (5) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 2U)) != 0U) ? 1 : 0) && pSignalConfig->SignalInvalidIdx < 1U) ==> FALSE
      (8) if (0 == Skip_Invalid_Storage) ==> TRUE
      (9) if (pGetSignalFunction != (void *)0) ==> TRUE
      (10) if (GetLocalBuffer != 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable pSignalConfig->SignalGetFunctIdx in branch 4 since it requires user code.
      Cannot set variable pSignalConfig in branch 4 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 5
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 5 since it requires user code.
      Cannot set variable pSignalConfig in branch 5 since it requires user code.
      Cannot set local variable Skip_Invalid_Storage in branch 8
      Cannot set variable pGetSignalFunction in branch 9 since it has a type which requires user code.
      Cannot set GetLocalBuffer due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-018-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-018-PARTIAL
TEST.BASIS_PATH:18 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 18
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (SigStatus == 0U) ==> TRUE
      (4) if (pSignalConfig->SignalGetFunctIdx < 39U) ==> TRUE
      (5) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 2U)) != 0U) ? 1 : 0) && pSignalConfig->SignalInvalidIdx < 1U) ==> TRUE
      (6) if (pSignalInvalidConfig->pSignalInvalidCheckFunc != (void *)0) ==> FALSE
      (7) if (0 != InvalidStatus) ==> FALSE
      (8) if (0 == Skip_Invalid_Storage) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable pSignalConfig->SignalGetFunctIdx in branch 4 since it requires user code.
      Cannot set variable pSignalConfig in branch 4 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 5
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 5 since it requires user code.
      Cannot set variable pSignalConfig in branch 5 since it requires user code.
      Cannot set variable pSignalInvalidConfig->pSignalInvalidCheckFunc in branch 6 since it has a type which requires user code.
      Cannot set local variable InvalidStatus in branch 7
      Cannot set local variable Skip_Invalid_Storage in branch 8
      Cannot set local variable GetLocalBuffer in branch 10
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-019-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-019-PARTIAL
TEST.BASIS_PATH:19 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 19
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (SigStatus == 0U) ==> TRUE
      (4) if (pSignalConfig->SignalGetFunctIdx < 39U) ==> TRUE
      (5) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 2U)) != 0U) ? 1 : 0) && pSignalConfig->SignalInvalidIdx < 1U) ==> TRUE
      (6) if (pSignalInvalidConfig->pSignalInvalidCheckFunc != (void *)0) ==> FALSE
      (7) if (0 != InvalidStatus) ==> TRUE
      (8) if (0 == Skip_Invalid_Storage) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable pSignalConfig->SignalGetFunctIdx in branch 4 since it requires user code.
      Cannot set variable pSignalConfig in branch 4 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 5
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 5 since it requires user code.
      Cannot set variable pSignalConfig in branch 5 since it requires user code.
      Cannot set variable pSignalInvalidConfig->pSignalInvalidCheckFunc in branch 6 since it has a type which requires user code.
      Cannot set local variable InvalidStatus in branch 7
      Cannot set Skip_Invalid_Storage due to assignment
      Cannot set GetLocalBuffer due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-020-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-020-PARTIAL
TEST.BASIS_PATH:20 of 20 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 20
      (1) if ((SignalId < 39U && pSignalValue != (void *)0) && pSignalStatus != (void *)0) ==> TRUE
      (2) if (1 == ((((Mdl_SafetyAdapter_RxCanSignal_currentStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
      (3) if (SigStatus == 0U) ==> TRUE
      (4) if (pSignalConfig->SignalGetFunctIdx < 39U) ==> TRUE
      (5) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 2U)) != 0U) ? 1 : 0) && pSignalConfig->SignalInvalidIdx < 1U) ==> TRUE
      (6) if (pSignalInvalidConfig->pSignalInvalidCheckFunc != (void *)0) ==> TRUE
      (7) if (0 != InvalidStatus) ==> FALSE
      (8) if (0 == Skip_Invalid_Storage) ==> FALSE
      (10) if (GetLocalBuffer != 0) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable pSignalConfig->SignalGetFunctIdx in branch 4 since it requires user code.
      Cannot set variable pSignalConfig in branch 4 since it requires user code.
      Conflict: Unable to validate expression-to-expression comparison in branch 5
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 5 since it requires user code.
      Cannot set variable pSignalConfig in branch 5 since it requires user code.
      Cannot set variable pSignalInvalidConfig->pSignalInvalidCheckFunc in branch 6 since it has a type which requires user code.
      Cannot set InvalidStatus due to assignment
      Cannot set local variable Skip_Invalid_Storage in branch 8
      Cannot set local variable GetLocalBuffer in branch 10
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_MaxValue_SignalID_11
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MaxValue_SignalID_11
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanGetSignalFunctConfig[0].pGetSignalFunct:Mdl_SafetyAdapter_RxCanGetB_EBW2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[11]:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:11
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_SCSBZR_oABG1S01_oCAN00_afb82460_Rx:3
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[11]:3
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:3
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MaxValue_SignalID_19
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MaxValue_SignalID_19
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[19]:7
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:19
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_B_EBW_oVSC1S95_oCAN00_c02baff7_Rx:7
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[19]:7
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:7
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MaxValue_SignalID_24
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MaxValue_SignalID_24
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[24]:1
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:24
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:0
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalId:24
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[24]:1
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:1
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MaxValue_SignalID_35
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MaxValue_SignalID_35
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[35]:1
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:35
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalId:35
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[35]:1
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:1
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MaxValue_SignalID_37
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MaxValue_SignalID_37
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[37]:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:37
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:0
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalId:37
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[37]:3
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:3
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MaxValue_SignalID_4
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MaxValue_SignalID_4
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_B_EBW2_oVSC1S97_oCAN00_8a07d685_Rx:7
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[4]:7
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:7
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MaxValue_SignalID_9
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MaxValue_SignalID_9
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[9]:1
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:9
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalId:9
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[9]:1
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:1
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MidValue_SignalID_4
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MidValue_SignalID_4
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_B_EBW2_oVSC1S97_oCAN00_8a07d685_Rx:3
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[4]:3
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:3
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MinValue_SignalID_11
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MinValue_SignalID_11
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:11
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_SCSBZR_oABG1S01_oCAN00_afb82460_Rx:0
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[11]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MinValue_SignalID_19
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MinValue_SignalID_19
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:19
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_B_EBW_oVSC1S95_oCAN00_c02baff7_Rx:0
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[19]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MinValue_SignalID_24
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MinValue_SignalID_24
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[24]:0
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:24
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:0
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalId:24
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[24]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MinValue_SignalID_37
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MinValue_SignalID_37
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:37
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalId:37
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[37]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MinValue_SignalID_4
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MinValue_SignalID_4
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_B_EBW2_oVSC1S97_oCAN00_8a07d685_Rx:0
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[4]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_MinValue_SignalID_9
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_MinValue_SignalID_9
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:9
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalId:9
TEST.VALUE:uut_prototype_stubs.Com_ReceiveSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[9]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.003
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.003
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanGetSignalStatus
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanGetSignalStatus.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue[0]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<null>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.004
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.004
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanGetSignalStatus
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:40
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanGetSignalStatus.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanSetSignalValue.pSignalValue[0]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.006
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.006
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:6
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.return:1
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingStatus[4]:1
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.007
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.007
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.008
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.008
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.009
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.009
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.010
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.010
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.011
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.011
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.012
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.012
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.013
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.013
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.014
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.014
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:6
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.return:1
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingStatus[4]:1
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.015
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.015
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:40
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:6
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.return:1
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingStatus[4]:1
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.016
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.016
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:6
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.return:1
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingStatus[4]:1
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.017
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.017
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:40
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:6
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.return:1
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingStatus[4]:1
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.018
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.018
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:40
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:6
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.return:1
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingStatus[4]:1
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_GetSignalValue.019
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_GetSignalValue.019
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalConfig[0].RxSigMonitoringType:6
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.return:1
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingStatus[4]:1
TEST.END

-- Test Case: Mdl_SafetyAdapter_eSIGNAL_MISSING
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_eSIGNAL_MISSING
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanIsSignalMissingEnabled[4]:1
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_B_EBW2_oVSC1S97_oCAN00_8a07d685_Rx:6
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingStatus[4]:1
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[4]:6
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:6
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_MISSING
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalMissing.SignalId:(2)4
TEST.EXPECTED:Mdl_SafetyAdapter_RxCfg.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalMissingStatus[4]:1
TEST.END

-- Test Case: Mdl_SafetyAdapter_eSIGNAL_NEVER_RECIEVED
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_eSIGNAL_NEVER_RECIEVED
TEST.STUB:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalNRStatus[0]:1
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCanIsSignalNR.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_B_EBW2_oVSC1S97_oCAN00_8a07d685_Rx:0
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignalNRStatus[4]:1
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[4]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_NEVER_RECEIVED
TEST.END

-- Test Case: Mdl_SafetyAdapter_eSIGNAL_OK
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_eSIGNAL_OK
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<null>>
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Rte_B_EBW2_oVSC1S97_oCAN00_8a07d685_Rx:5
TEST.EXPECTED:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSigBufferU8[4]:5
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:5
TEST.EXPECTED:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:eSIGNAL_OK
TEST.END

-- Test Case: Mdl_SafetyAdapter_eSIGNAL_OK.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_eSIGNAL_OK.001
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanGetSignalFunctConfig[4].pGetSignalFunct:<<null>>
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanSignal_currentStatus[0]:16
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.SignalId:4
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalValue[0]:0
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_GetSignalValue.pSignalStatus[0]:0
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCan_SetSignalInitValue

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SetSignalInitValue
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SetSignalInitValue.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SetSignalInitValue.pSignalValue:<<malloc 1>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (SignalId < 39U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus.SignalId:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (BytePosition < 5U) ==> FALSE
   Test Case Generation Notes:
      Cannot set BytePosition due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (BytePosition < 5U) ==> TRUE
   Test Case Generation Notes:
      Cannot set BytePosition due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus.SignalId:<<MIN>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (SignalId < 39U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus.SignalId:<<MAX>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus.pJustRcvdStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (BytePosition < 5U) ==> FALSE
   Test Case Generation Notes:
      Cannot set BytePosition due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.Mdl_SafetyAdapter_RxCanJustRcvdStatus[0]:1
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus.pJustRcvdStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (BytePosition < 5U) ==> TRUE
      (3) if (1 == ((((Mdl_SafetyAdapter_RxCanJustRcvdStatus)[BytePosition] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> FALSE
   Test Case Generation Notes:
      Cannot set BytePosition due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 3
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus.pJustRcvdStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (BytePosition < 5U) ==> TRUE
      (3) if (1 == ((((Mdl_SafetyAdapter_RxCanJustRcvdStatus)[BytePosition] & (uint8)(1U << (SignalId & 0x7))) != 0U) ? 1 : 0)) ==> TRUE
   Test Case Generation Notes:
      Cannot set BytePosition due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 3
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus.pJustRcvdStatus:<<malloc 1>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (SignalId < 39U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl.SignalId:<<MAX>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 2U)) != 0U) ? 1 : 0) && pSignalConfig->SignalInvalidIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl.Status:1
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 2U)) != 0U) ? 1 : 0) && pSignalConfig->SignalInvalidIdx < 1U) ==> TRUE
      (3) if (ByteIndex < (1U) && pSignalConfig->SignalInvalidIdx < 1U) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 3 since it requires user code.
      Cannot set ByteIndex due to assignment
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 3 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 2U)) != 0U) ? 1 : 0) && pSignalConfig->SignalInvalidIdx < 1U) ==> TRUE
      (3) if (ByteIndex < (1U) && pSignalConfig->SignalInvalidIdx < 1U) ==> TRUE
      (4) if (Status == 1) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 3 since it requires user code.
      Cannot set ByteIndex due to assignment
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 3 since it requires user code.
      Cannot set variable pSignalConfig in branch 5 since it requires user code.
      Cannot set variable pSignalInvalidConfig in branch 5 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 2U)) != 0U) ? 1 : 0) && pSignalConfig->SignalInvalidIdx < 1U) ==> TRUE
      (3) if (ByteIndex < (1U) && pSignalConfig->SignalInvalidIdx < 1U) ==> TRUE
      (4) if (Status == 1) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 2 since it requires user code.
      Cannot set variable pSignalConfig in branch 3 since it requires user code.
      Cannot set ByteIndex due to assignment
      Cannot set variable pSignalConfig->SignalInvalidIdx in branch 3 since it requires user code.
      Cannot set variable pSignalConfig in branch 5 since it requires user code.
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalInvalidProcessingControl.SignalId:<<MIN>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (SignalId < 39U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.SignalId:<<MAX>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 1U)) != 0U) ? 1 : 0) && ByteIndex < (5U)) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 1U)) != 0U) ? 1 : 0) && ByteIndex < (5U)) ==> TRUE
      (3) if (Status == 1) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set ByteIndex due to assignment
      Cannot set local variable pSignalConfig in branch 4
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (1 == (((pSignalConfig->RxSigMonitoringType & (uint8)(1U << 1U)) != 0U) ? 1 : 0) && ByteIndex < (5U)) ==> TRUE
      (3) if (Status == 1) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.Status:1
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.001
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.SignalId:6
TEST.END

-- Test Case: Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.002
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl
TEST.NEW
TEST.NAME:Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.002
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalMissingProcessingControl.Status:1
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (SignalId < 39U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl.SignalId:<<MAX>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (ByteIndex < (5U)) ==> FALSE
   Test Case Generation Notes:
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl.Status:1
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (ByteIndex < (5U)) ==> TRUE
      (3) if (Status == 1) ==> FALSE
   Test Case Generation Notes:
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl.SignalId:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (SignalId < 39U) ==> TRUE
      (2) if (ByteIndex < (5U)) ==> TRUE
      (3) if (Status == 1) ==> TRUE
   Test Case Generation Notes:
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_RxCan_SignalNRProcessingControl.SignalId:<<MIN>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_Task

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_Task
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (0U != fl_Current_Clustermode_Status_u8 && 0U == PrevVehState) ==> FALSE
      (2) if (fl_Current_Clustermode_Status_u8 == 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable fl_Current_Clustermode_Status_u8 in branch 1
      Cannot set local variable fl_Current_Clustermode_Status_u8 in branch 2
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.PrevVehState:1
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_Task
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (0U != fl_Current_Clustermode_Status_u8 && 0U == PrevVehState) ==> FALSE
      (2) if (fl_Current_Clustermode_Status_u8 == 1U) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable fl_Current_Clustermode_Status_u8 in branch 1
      Cannot set local variable fl_Current_Clustermode_Status_u8 in branch 2
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.PrevVehState:1
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_Task
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (0U != fl_Current_Clustermode_Status_u8 && 0U == PrevVehState) ==> TRUE
      (2) if (fl_Current_Clustermode_Status_u8 == 1U) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable fl_Current_Clustermode_Status_u8 in branch 1
      Cannot set local variable fl_Current_Clustermode_Status_u8 in branch 2
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.<<GLOBAL>>.PrevVehState:0
TEST.END

-- Subprogram: Mdl_SafetyAdapter_UtilMemSet

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_UtilMemSet
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (pDest != (void *)0) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_UtilMemSet.pDest:<<malloc 9>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_UtilMemSet.pDest:<<null>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_UtilMemSet.Value:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_UtilMemSet.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_UtilMemSet
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (pDest != (void *)0) ==> TRUE
      (2) for (Idx < Length) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_UtilMemSet.pDest:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_UtilMemSet.Value:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_UtilMemSet.Length:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:Mdl_SafetyAdapter
TEST.SUBPROGRAM:Mdl_SafetyAdapter_UtilMemSet
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (pDest != (void *)0) ==> TRUE
      (2) for (Idx < Length) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_UtilMemSet.pDest:<<malloc 1>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_UtilMemSet.Value:<<MIN>>
TEST.VALUE:Mdl_SafetyAdapter.Mdl_SafetyAdapter_UtilMemSet.Length:1
TEST.END

-- Unit: Mdl_SafetyAdapter_RxCfg

-- Subprogram: Mdl_SafetyAdapter_OnDataRx_B_EBW

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_OnDataRx_B_EBW
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_OnDataRx_B_EBW2

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_OnDataRx_B_EBW2
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_OnDataRx_B_EPBWL

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_OnDataRx_B_EPBWL
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_OnDataRx_SCSBZR

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_OnDataRx_SCSBZR
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetAB

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetAB
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetABG_HZD

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetABG_HZD
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetABS_MID

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetABS_MID
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetBHEXIST

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetBHEXIST
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetBRK_MID

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetBRK_MID
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetBRK_MID2

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetBRK_MID2
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_ABS

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_ABS
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_BRKW

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_BRKW
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_BRKW2

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_BRKW2
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_BRLV

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_BRLV
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_BRLV2

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_BRLV2
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_BUZZE2

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_BUZZE2
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_BUZZER

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_BUZZER
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_DAINDC

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_DAINDC
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_DAINDP

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_DAINDP
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_DAINFO

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_DAINFO
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_EBW

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_EBW
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.Mdl_SafetyAdapter_RxCanGetB_EBW.pSignalValue:<<malloc 1>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_EBW2

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_EBW2
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.Mdl_SafetyAdapter_RxCanGetB_EBW2.pSignalValue:<<malloc 1>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_EPBMID

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_EPBMID
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_EPBWL

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_EPBWL
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.Mdl_SafetyAdapter_RxCanGetB_EPBWL.pSignalValue:<<malloc 1>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_HZD

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_HZD
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_MCST

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_MCST
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetB_PKBLP

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetB_PKBLP
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetDBKLAB

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetDBKLAB
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetDDRTWV

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetDDRTWV
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetDDRTWV2

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetDDRTWV2
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetEBW_MID

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetEBW_MID
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetEBW_MID2

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetEBW_MID2
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetEPB01SUM

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetEPB01SUM
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetMCBW

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetMCBW
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetPBKLAB

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetPBKLAB
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetPODT

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetPODT
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetSCSACCEL

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetSCSACCEL
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetSCSBZR

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetSCSBZR
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.VALUE:Mdl_SafetyAdapter_RxCfg.Mdl_SafetyAdapter_RxCanGetSCSBZR.pSignalValue:<<malloc 1>>
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetSLP_WL

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetSLP_WL
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetSM3B1

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetSM3B1
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetTRCOFF

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetTRCOFF
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetVSCEXIST

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetVSCEXIST
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Subprogram: Mdl_SafetyAdapter_RxCanGetVSCOFF

-- Test Case: BASIS-PATH-001
TEST.UNIT:Mdl_SafetyAdapter_RxCfg
TEST.SUBPROGRAM:Mdl_SafetyAdapter_RxCanGetVSCOFF
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END
