-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : COMABSSAFE
-- Unit(s) Under Test: ComAbsSafe ComAbsSafe_E2ESM ComAbsSafe_E2ESM_Cfg ComAbsSafe_RxCfg ComAbsSafe_TxCfg
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: ComAbsSafe

-- Subprogram: CComAbsMdlSafe_Impl_RxCanMdlMainFunction

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_Impl_RxCanMdlMainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.onlyOnce:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_Impl_RxCanMdlMainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.onlyOnce:1
TEST.END

-- Subprogram: CComAbsMdlSafe_Impl_TxCanMdlMainFunction

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_Impl_TxCanMdlMainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: CComAbsMdlSafe_RxCan_GetSignalValue

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 18
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MAX>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 9>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<null>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 9>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<null>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.STUB:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<null>>
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalNRStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalNRStatus[0]:1
TEST.ATTRIBUTES:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalInvalidBzStatus[0]:INPUT_BASE=16
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalInvalidBzStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalInvalidBzStatus[0]:1
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalTOStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalTOStatus[0]:1
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalInvalidCRC1Status[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalInvalidCRC1Status[0]:1
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalInvalidCRC2Status[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalInvalidCRC2Status[0]:1
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignal_currentStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignal_currentStatus[0]:0
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignal_currentStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignal_currentStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<null>>
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<null>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.003
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignal_currentStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.004
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.004
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignal_currentStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.005
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.005
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignal_currentStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:3
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:3
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.006
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.006
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignal_currentStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.007
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.007
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignal_currentStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL.008
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL.008
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignal_currentStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:28
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL.003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL.003
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL.004
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL.004
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL.005
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL.005
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL.006
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL.006
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-012-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-012-PARTIAL
TEST.BASIS_PATH:12 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL
TEST.BASIS_PATH:13 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL
TEST.BASIS_PATH:14 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-015-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-015-PARTIAL
TEST.BASIS_PATH:15 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-016-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-016-PARTIAL
TEST.BASIS_PATH:16 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-017-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-017-PARTIAL
TEST.BASIS_PATH:17 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-018-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-018-PARTIAL
TEST.BASIS_PATH:18 of 18 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValue.pSignalStatus:<<malloc 1>>
TEST.END

-- Subprogram: CComAbsMdlSafe_RxCan_GetSignalValueU8Arr

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 15
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MAX>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 9>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<null>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 9>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<null>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:2
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:2
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalNRStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalNRStatus[0]:0x1
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalTOStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalTOStatus[0]:0x1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSigBufferU8ArrLength[0]:0
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:3
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL.003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL.003
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:1
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanRetentionSigBufferU8ArrLength[0]:1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanRetentionSigBufferU8ArrLength[0]:1
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL.004
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL.004
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanRetentionSigBufferU8ArrLength[0]:1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanRetentionSigBufferU8ArrLength[0]:1
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x8
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSigBufferU8NArr[0]:0x55
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSigBufferU8ArrLength[0]:2
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:1
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSigBufferU8NArr[0]:0x55
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSigBufferU8ArrLength[0]:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:1
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalNRStatus[0]:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalInvalidBzStatus[0]:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalTOStatus[0]:0
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalNRStatus[0]:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalInvalidBzStatus[0]:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalTOStatus[0]:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.ATTRIBUTES:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanRetentionSigBufferU8ArrLength[0]:0
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-012-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-012-PARTIAL
TEST.BASIS_PATH:12 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL
TEST.BASIS_PATH:13 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL
TEST.BASIS_PATH:14 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-015-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_GetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-015-PARTIAL
TEST.BASIS_PATH:15 of 15 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_GetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.END

-- Subprogram: CComAbsMdlSafe_RxCan_SetSignalInitValue

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SetSignalInitValue
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SetSignalInitValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SetSignalInitValue.pSignalValue:<<malloc 1>>
TEST.END

-- Subprogram: CComAbsMdlSafe_RxCan_SetSignalInitValueU8Arr

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SetSignalInitValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SetSignalInitValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SetSignalInitValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SetSignalInitValueU8Arr.pSignalLength:<<malloc 1>>
TEST.END

-- Subprogram: CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus.SignalId:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalClearJustRcvdStatus.SignalId:<<MIN>>
TEST.END

-- Subprogram: CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus.SignalId:<<MAX>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus.pJustRcvdStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus.pJustRcvdStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus.pJustRcvdStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfirmStatus[0]:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus.pJustRcvdStatus:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfirmStatus[0]:1
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalGetJustRcvdStatus.SignalId:0
TEST.END

-- Subprogram: CComAbsMdlSafe_RxCan_SignalInvalidProcessingControl

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalInvalidProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: CComAbsMdlSafe_RxCan_SignalMissingProcessingControl

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalMissingProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.SignalId:<<MAX>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalMissingProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalMissingProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.Status:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalMissingProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 5 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.Status:1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalMissingProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 5 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:0x22
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.Status:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:34
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.SignalId:0
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalMissingProcessingControl.Status:1
TEST.END

-- Subprogram: CComAbsMdlSafe_RxCan_SignalNRProcessingControl

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalNRProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalNRProcessingControl.SignalId:<<MAX>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalNRProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalNRProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalNRProcessingControl.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalNRProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalNRProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalNRProcessingControl.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalNRProcessingControl.Status:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_RxCan_SignalNRProcessingControl
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalNRProcessingControl.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_RxCan_SignalNRProcessingControl.Status:1
TEST.END

-- Subprogram: CComAbsMdlSafe_TxCan_SetSignalValue

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 10
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MAX>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 10
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 9>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<null>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:1
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:1
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.003
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.004
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.004
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.005
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.005
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.006
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.006
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.007
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.007
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:1
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:0
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValue.pTxSignalData:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:0
TEST.END

-- Subprogram: CComAbsMdlSafe_TxCan_SetSignalValueU8Arr

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 10
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MAX>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 10
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 9>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<null>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:1
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:1
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:1
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:1
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.003
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0x1
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:0
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData[0]:2
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:1
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:0
TEST.EXPECTED:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:1
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:0
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:0
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsMdlSafe_TxCan_SetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 10 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.pTxSignalData:<<malloc 1>>
TEST.VALUE:ComAbsSafe.CComAbsMdlSafe_TxCan_SetSignalValueU8Arr.SignalLength:1
TEST.END

-- Subprogram: CComAbsSafeTxCan_ClearCanSignalTxConfirmation

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_ClearCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_ClearCanSignalTxConfirmation.SignalId:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_ClearCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_ClearCanSignalTxConfirmation.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_ClearCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_ClearCanSignalTxConfirmation.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_ClearCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0x2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfirmStatus[0]:1
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_ClearCanSignalTxConfirmation.SignalId:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:2
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_ClearCanSignalTxConfirmation.SignalId:0
TEST.END

-- Subprogram: CComAbsSafeTxCan_GetCanSignalTxConfirmation

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_GetCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.SignalId:<<MAX>>
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.pStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_GetCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.pStatus:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_GetCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.pStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_TxCfg.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.EXPECTED:ComAbsSafe_TxCfg.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_GetCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.pStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_TxCfg.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.EXPECTED:ComAbsSafe_TxCfg.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_GetCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfirmStatus[0]:1
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.pStatus:<<malloc 1>>
TEST.VALUE:ComAbsSafe_TxCfg.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfirmStatus[0]:1
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.SignalId:0
TEST.EXPECTED:ComAbsSafe_TxCfg.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_GetCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_GetCanSignalTxConfirmation.pStatus:<<malloc 1>>
TEST.END

-- Subprogram: CComAbsSafeTxCan_SetSignalFromRetentionBuffer

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 14
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:1
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:1
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.003
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.004
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.004
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.005
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.005
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.006
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.006
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034s
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.007
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.007
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.008
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.008
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.009
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.009
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.010
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.010
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.011
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.011
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.012
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.012
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0x0
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.013
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.013
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0x1
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:1
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.014
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.014
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0x1
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:1
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.015
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.015
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0x1
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:1
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.016
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.016
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0x1
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:1
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.017
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.017
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0x1
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalLengthInByte:5
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSetSignalIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:1
TEST.EXPECTED:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-010-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-010-PARTIAL
TEST.BASIS_PATH:10 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-012-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-012-PARTIAL
TEST.BASIS_PATH:12 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL
TEST.BASIS_PATH:13 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafeTxCan_SetSignalFromRetentionBuffer
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL
TEST.BASIS_PATH:14 of 14 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafeTxCan_SetSignalFromRetentionBuffer.SignalId:<<MIN>>
TEST.END

-- Subprogram: CComAbsSafe_Impl_MainFunction

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafe_Impl_MainFunction
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: CComAbsSafe_Impl_OnCommand

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CComAbsSafe_Impl_OnCommand
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.CComAbsSafe_Impl_OnCommand.Cmd:<<MIN>>
TEST.END

-- Subprogram: CmpActivation

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpActive

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpDiag

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: ComAbsSafe_ReloadMissingTimer

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_ReloadMissingTimer
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_ReloadMissingTimer.SignalId:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_ReloadMissingTimer
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_ReloadMissingTimer.SignalId:<<MIN>>
TEST.END

-- Subprogram: ComAbsSafe_RxCanGetSignalStatus

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanGetSignalStatus
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.STUB:ComAbsSafe.ComAbsSafe_RxCanIsSignalMissing
TEST.STUB:ComAbsSafe.ComAbsSafe_RxCanIsSignalNR
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalMissing.return:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalNR.return:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanGetSignalStatus.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanGetSignalStatus
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.STUB:ComAbsSafe.ComAbsSafe_RxCanIsSignalMissing
TEST.STUB:ComAbsSafe.ComAbsSafe_RxCanIsSignalNR
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalMissing.return:1
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalNR.return:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanGetSignalStatus.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanGetSignalStatus
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.STUB:ComAbsSafe.ComAbsSafe_RxCanIsSignalMissing
TEST.STUB:ComAbsSafe.ComAbsSafe_RxCanIsSignalNR
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalMissing.return:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalNR.return:1
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanGetSignalStatus.SignalId:<<MIN>>
TEST.END

-- Subprogram: ComAbsSafe_RxCanIsSignalMissing

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanIsSignalMissing
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 3 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalMissing.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanIsSignalMissing
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (ByteIndex < (4U)) ==> TRUE
      (2) if (((ComAbsSafe_RxCanSignalTOStatus)[ByteIndex] & (uint8)(1U << (SignalId & 0x7U))) != 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set ByteIndex due to assignment
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalTOStatus[0]:0
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalMissing.SignalId:33
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalTOStatus[0]:0
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanIsSignalMissing.SignalId:33
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanIsSignalMissing
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalTOStatus[0]:<<MAX>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalMissing.SignalId:<<MIN>>
TEST.END

-- Subprogram: ComAbsSafe_RxCanIsSignalNR

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanIsSignalNR
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 3 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalNR.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanIsSignalNR
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalNRStatus[0]:<<MAX>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalNR.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalNRStatus[0]:255
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanIsSignalNR.SignalId:0
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanIsSignalNR
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.STUB:ComAbsSafe.ComAbsSafe_RxCanIsSignalMissing
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalNRStatus[0]:<<MAX>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanIsSignalNR.SignalId:33
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanIsSignalNR.SignalId:33
TEST.END

-- Subprogram: ComAbsSafe_RxCanSetSignalStatus_ASIL

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_ASIL
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 7
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:512
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_ASIL
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 7
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:0
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_ASIL
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 7 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_ASIL
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_ASIL
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:0x8
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:0
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:0
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:8
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_ASIL
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:0x16
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:0
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:0
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:22
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL.003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_ASIL
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL.003
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:32
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:0
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:0
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:32
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_ASIL
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 7 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:0
TEST.END

-- Test Case: BASIS-PATH-006
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_ASIL
TEST.NEW
TEST.NAME:BASIS-PATH-006
TEST.BASIS_PATH:6 of 7
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:1
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_ASIL
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SMstatus:1
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalStatus_ASIL.SignalStatus:<<MIN>>
TEST.END

-- Subprogram: ComAbsSafe_RxCanSetSignalStatus_nonASIL

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_nonASIL
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_nonASIL
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalStatus_nonASIL
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END

-- Subprogram: ComAbsSafe_RxCanSetSignalValue

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 9
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MAX>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 9>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<null>>
TEST.END

-- Subprogram: ComAbsSafe_RxCanSetSignalValue

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 9 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 9 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.003
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.004
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.004
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.005
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.005
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:2
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL.006
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL.006
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 9 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 9>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<null>>
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:0
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<null>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 9 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:3
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:3
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 9 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:5
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL.003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL.003
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:26
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL.004
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL.004
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:3
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalBufferStartIdx:0
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 9 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 9 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValue
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 9 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValue.pSignalValue:<<malloc 1>>
TEST.END

-- Subprogram: ComAbsSafe_RxCanSetSignalValueU8Arr

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 8
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MAX>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 9>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<null>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<null>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 8 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 8 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue[0]:0
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:0
TEST.EXPECTED:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue[0]:0
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 8 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength[0]:0
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 8 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:2
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength[0]:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:2
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 8 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.EXPECTED:ComAbsSafe_RxCfg.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:2
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:1
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength[0]:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL.003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL.003
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 8 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:2
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength[0]:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:2
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 8 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength[0]:1
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL.001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL.001
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength[0]:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalGetFunctIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].RxSigMonitoringType:8
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL.002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanSetSignalValueU8Arr
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL.002
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:0
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.SignalId:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_RxCanSetSignalValueU8Arr.pSignalLength[0]:1
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:0
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_RxCanSignalConfig[0].SignalLengthInByte:2
TEST.END

-- Subprogram: ComAbsSafe_RxCanVarInit

-- Test Case: BASIS-PATH-001-TEMPLATE
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanVarInit
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE
TEST.BASIS_PATH:1 of 2 (template)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002-TEMPLATE
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_RxCanVarInit
TEST.NEW
TEST.NAME:BASIS-PATH-002-TEMPLATE
TEST.BASIS_PATH:2 of 2 (template)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: ComAbsSafe_TxCanVarInit

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_TxCanVarInit
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: ComAbsSafe_TxCan_SetCanSignalTxConfirmation

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_TxCan_SetCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_TxCan_SetCanSignalTxConfirmation.SignalId:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_TxCan_SetCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 3 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_TxCan_SetCanSignalTxConfirmation.SignalId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_TxCan_SetCanSignalTxConfirmation
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:0xFF
TEST.VALUE:ComAbsSafe.ComAbsSafe_TxCan_SetCanSignalTxConfirmation.SignalId:<<MIN>>
TEST.EXPECTED:ComAbsSafe.<<GLOBAL>>.ComAbsSafe_TxCanSignalConfig[0].TxSigalProps:255
TEST.END

-- Subprogram: ComAbsSafe_UtilMemSet

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_UtilMemSet
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_UtilMemSet.pDest:<<malloc 9>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_UtilMemSet.pDest:<<null>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_UtilMemSet.Value:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_UtilMemSet.Length:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_UtilMemSet
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_UtilMemSet.pDest:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_UtilMemSet.Value:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_UtilMemSet.Length:0
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:ComAbsSafe
TEST.SUBPROGRAM:ComAbsSafe_UtilMemSet
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
E40_Platform::C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::ComAbsMdlSafe
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsSafe.ComAbsSafe_UtilMemSet.pDest:<<malloc 1>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_UtilMemSet.Value:<<MIN>>
TEST.VALUE:ComAbsSafe.ComAbsSafe_UtilMemSet.Length:1
TEST.END
