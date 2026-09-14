-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : COMABSMDLSAFE
-- Unit(s) Under Test: ComAbsMdlSafe_RxCfg ComAbsMdlSafe_TxCfg
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: ComAbsMdlSafe_RxCfg

-- Subprogram: CComAbsMdlSafe_OnDataRx_VehicleSpeedABS

-- Test Case: CComAbsMdlSafe_OnDataRx_VehicleSpeedABS.001
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:CComAbsMdlSafe_OnDataRx_VehicleSpeedABS
TEST.NEW
TEST.NAME:CComAbsMdlSafe_OnDataRx_VehicleSpeedABS.001
TEST.END

-- Subprogram: ComAbsMdlSafe_RxCanGetAirbag_FromMsg

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetAirbag_FromMsg
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAirbag_FromMsg.pSignalValue:<<malloc 1>>
TEST.END

-- Subprogram: ComAbsMdlSafe_RxCanGetAlive_101_FromMsg

-- Test Case: ComAbsMdlSafe_RxCanGetAlive_101_FromMsg.001
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetAlive_101_FromMsg
TEST.NEW
TEST.NAME:ComAbsMdlSafe_RxCanGetAlive_101_FromMsg.001
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: ComAbsMdlSafe_RxCanGetCRC_101_FromMsg

-- Test Case: ComAbsMdlSafe_RxCanGetCRC_101_FromMsg.001
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetCRC_101_FromMsg
TEST.NEW
TEST.NAME:ComAbsMdlSafe_RxCanGetCRC_101_FromMsg.001
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Subprogram: ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core

-- Test Case: <<MAX>>
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:<<MAX>>
TEST.END

-- Test Case: <<MID>>
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:<<MID>>
TEST.END

-- Test Case: <<MIN>>
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-001-TEMPLATE
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE
TEST.BASIS_PATH:1 of 12 (template)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-001-TEMPLATE.001
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE.001
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:133
TEST.END

-- Test Case: BASIS-PATH-001-TEMPLATE.002
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE.002
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:E2E_P01STATUS_INITIAL
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].transformerClass:E2E_P01STATUS_INITIAL
TEST.END

-- Test Case: BASIS-PATH-001-TEMPLATE.003
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-001-TEMPLATE.003
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:E2E_P01STATUS_SYNC
TEST.END

-- Test Case: BASIS-PATH-002-TEMPLATE
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-002-TEMPLATE
TEST.BASIS_PATH:2 of 12 (template)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-002-TEMPLATE.001
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-002-TEMPLATE.001
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:138
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE
TEST.BASIS_PATH:3 of 12 (template)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE.001
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE.001
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:E2E_P01STATUS_WRONGCRC
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:140
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE.002
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE.002
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:140
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE.003
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE.003
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:E2E_P01STATUS_WRONGSEQUENCE
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:140
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE.004
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE.004
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:E2E_P01STATUS_SYNC
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:140
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE.005
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE.005
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:E2E_P01STATUS_INITIAL
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:140
TEST.END

-- Test Case: BASIS-PATH-003-TEMPLATE.006
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-003-TEMPLATE.006
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:E2E_P01STATUS_REPEATED
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:140
TEST.END

-- Test Case: BASIS-PATH-004-TEMPLATE
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-004-TEMPLATE
TEST.BASIS_PATH:4 of 12 (template)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-004-TEMPLATE.001
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-004-TEMPLATE.001
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:E2E_P01STATUS_REPEATED
TEST.END

-- Test Case: BASIS-PATH-005-TEMPLATE
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-005-TEMPLATE
TEST.BASIS_PATH:5 of 12 (template)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-006-TEMPLATE
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-006-TEMPLATE
TEST.BASIS_PATH:6 of 12 (template)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-007-TEMPLATE
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-007-TEMPLATE
TEST.BASIS_PATH:7 of 12 (template)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-008-TEMPLATE
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-008-TEMPLATE
TEST.BASIS_PATH:8 of 12 (template)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-009-TEMPLATE
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-009-TEMPLATE
TEST.BASIS_PATH:9 of 12 (template)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-010-TEMPLATE
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-010-TEMPLATE
TEST.BASIS_PATH:10 of 12 (template)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-011-TEMPLATE
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-011-TEMPLATE
TEST.BASIS_PATH:11 of 12 (template)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-012-PARTIAL
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:BASIS-PATH-012-PARTIAL
TEST.BASIS_PATH:12 of 12 (partial)
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:1
TEST.END

-- Test Case: ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core-PARTITIONS
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core-PARTITIONS
TEST.VALUE:<<OPTIONS>>.DATA_PARTITIONS:0
TEST.END

-- Test Case: ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core_MAX.001
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core
TEST.NEW
TEST.NAME:ComAbsMdlSafe_RxCanGetFrom_SG_ABS_Core_MAX.001
TEST.VALUE:<<ALL_MAX>>
TEST.END

-- Subprogram: ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg

-- Test Case: ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg_001
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg
TEST.NEW
TEST.NAME:ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg_001
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Airbag:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Alive_101:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.CRC_101:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.VehicleSpeedABS:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[1].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[2].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[3].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].pGetSignalU8ArrFunct:<<value error>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidSigIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].pSignalInvalidCheckFunc:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalFunctPtrConfig[0]:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrConfig[0]:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSetSignalIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSigalProps:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSetSignalIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSigalProps:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSetSignalIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSigalProps:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue[0]:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAirbag_FromMsg.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAlive_101_FromMsg.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetCRC_101_FromMsg.pSignalValue:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Airbag:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Alive_101:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].CRC_101:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].VehicleSpeedABS:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].transformerClass:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.ComAbsMdlSafeReloadMissingTimer.SignalId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Alive_200:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Battery_Voltage:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].CRC_200:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].errorCode:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].transformerClass:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.return:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.return:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.id:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.return:<<MAX>>
TEST.END

-- Test Case: ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg_002
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg
TEST.NEW
TEST.NAME:ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg_002
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue:<<malloc 1>>
TEST.END

-- Test Case: ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg_003
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg
TEST.NEW
TEST.NAME:ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg_003
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Airbag:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Alive_101:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.CRC_101:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.VehicleSpeedABS:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[1].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[2].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[3].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].pGetSignalU8ArrFunct:<<value error>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidSigIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].pSignalInvalidCheckFunc:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalFunctPtrConfig[0]:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrConfig[0]:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSetSignalIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSigalProps:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSetSignalIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSigalProps:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSetSignalIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSigalProps:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue[0]:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAirbag_FromMsg.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAlive_101_FromMsg.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetCRC_101_FromMsg.pSignalValue:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Airbag:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Alive_101:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].CRC_101:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].VehicleSpeedABS:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].transformerClass:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.ComAbsMdlSafeReloadMissingTimer.SignalId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Alive_200:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Battery_Voltage:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].CRC_200:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].errorCode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].transformerClass:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.return:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.return:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.id:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.return:<<MIN>>
TEST.END

-- Test Case: ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg_004
TEST.UNIT:ComAbsMdlSafe_RxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg
TEST.NEW
TEST.NAME:ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg_004
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Airbag:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Alive_101:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.CRC_101:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.VehicleSpeedABS:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[1].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[2].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[3].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].pGetSignalU8ArrFunct:<<value error>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidSigIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].pSignalInvalidCheckFunc:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalFunctPtrConfig[0]:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrConfig[0]:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSetSignalIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSigalProps:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSetSignalIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSigalProps:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSetSignalIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSigalProps:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue[0]:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAirbag_FromMsg.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAlive_101_FromMsg.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetCRC_101_FromMsg.pSignalValue:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Airbag:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Alive_101:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].CRC_101:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].VehicleSpeedABS:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].transformerClass:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.ComAbsMdlSafeReloadMissingTimer.SignalId:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Alive_200:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Battery_Voltage:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].CRC_200:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].errorCode:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].transformerClass:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.return:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.return:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.id:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.return:<<MID>>
TEST.END

-- Unit: ComAbsMdlSafe_TxCfg

-- Subprogram: ComAbsMdlSafe_TxCanPutTo_COM_HS_Core

-- Test Case: ComAbsMdlSafe_TxCanPutTo_COM_HS_Core_.001
TEST.UNIT:ComAbsMdlSafe_TxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_TxCanPutTo_COM_HS_Core
TEST.NEW
TEST.NAME:ComAbsMdlSafe_TxCanPutTo_COM_HS_Core_.001
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:<<ALL_MAX>>
TEST.STUB:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue[0]:0
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.return:0
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.id:0
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.pSignalValue:<<malloc 2>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.pSignalValue:"0"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.return:0
TEST.END

-- Test Case: ComAbsMdlSafe_TxCanPutTo_COM_HS_Core_002
TEST.UNIT:ComAbsMdlSafe_TxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_TxCanPutTo_COM_HS_Core
TEST.NEW
TEST.NAME:ComAbsMdlSafe_TxCanPutTo_COM_HS_Core_002
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Airbag:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Alive_101:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.CRC_101:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.VehicleSpeedABS:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[1].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[2].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[3].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].pGetSignalU8ArrFunct:<<value error>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidSigIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].pSignalInvalidCheckFunc:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalFunctPtrConfig[0]:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrConfig[0]:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSetSignalIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSigalProps:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSetSignalIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSigalProps:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSetSignalIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSigalProps:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue[0]:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAirbag_FromMsg.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAlive_101_FromMsg.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetCRC_101_FromMsg.pSignalValue:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Airbag:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Alive_101:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].CRC_101:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].VehicleSpeedABS:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].transformerClass:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.ComAbsMdlSafeReloadMissingTimer.SignalId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Alive_200:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Battery_Voltage:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].CRC_200:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].errorCode:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].transformerClass:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.return:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.return:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.id:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.return:<<MAX>>
TEST.END

-- Test Case: ComAbsMdlSafe_TxCanPutTo_COM_HS_Core_003
TEST.UNIT:ComAbsMdlSafe_TxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_TxCanPutTo_COM_HS_Core
TEST.NEW
TEST.NAME:ComAbsMdlSafe_TxCanPutTo_COM_HS_Core_003
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Airbag:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Alive_101:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.CRC_101:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.VehicleSpeedABS:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[1].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[2].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[3].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].pGetSignalU8ArrFunct:<<value error>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidSigIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].pSignalInvalidCheckFunc:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalFunctPtrConfig[0]:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrConfig[0]:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSetSignalIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSigalProps:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSetSignalIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSigalProps:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSetSignalIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSigalProps:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue[0]:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAirbag_FromMsg.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAlive_101_FromMsg.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetCRC_101_FromMsg.pSignalValue:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Airbag:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Alive_101:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].CRC_101:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].VehicleSpeedABS:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].transformerClass:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.ComAbsMdlSafeReloadMissingTimer.SignalId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Alive_200:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Battery_Voltage:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].CRC_200:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].errorCode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].transformerClass:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.return:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.return:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.id:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.return:<<MIN>>
TEST.END

-- Test Case: ComAbsMdlSafe_TxCanPutTo_COM_HS_Core_004
TEST.UNIT:ComAbsMdlSafe_TxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_TxCanPutTo_COM_HS_Core
TEST.NEW
TEST.NAME:ComAbsMdlSafe_TxCanPutTo_COM_HS_Core_004
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Airbag:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Alive_101:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.CRC_101:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.VehicleSpeedABS:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[1].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[2].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[3].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].pGetSignalU8ArrFunct:<<value error>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidSigIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].pSignalInvalidCheckFunc:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalFunctPtrConfig[0]:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrConfig[0]:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSetSignalIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSigalProps:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSetSignalIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSigalProps:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSetSignalIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSigalProps:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue[0]:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAirbag_FromMsg.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAlive_101_FromMsg.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetCRC_101_FromMsg.pSignalValue:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Airbag:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Alive_101:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].CRC_101:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].VehicleSpeedABS:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].transformerClass:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.ComAbsMdlSafeReloadMissingTimer.SignalId:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Alive_200:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Battery_Voltage:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].CRC_200:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].errorCode:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].transformerClass:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.return:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.return:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.id:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.return:<<MID>>
TEST.END

-- Subprogram: ComAbsMdlSafe_TxCanSetSig_Battery_Voltage

-- Test Case: ComAbsMdlSafe_TxCanSetSig_Battery_Voltage_001
TEST.UNIT:ComAbsMdlSafe_TxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_TxCanSetSig_Battery_Voltage
TEST.NEW
TEST.NAME:ComAbsMdlSafe_TxCanSetSig_Battery_Voltage_001
TEST.NOTES:
Class Diagram Path: C_GlobalDesign::SW_Classes::SWC_PACKAGES::SWC_CORE::ComAbsSafe::Class Diagram
Requirement ID: Requirement_PE4TI29141-2034
TEST.END_NOTES:
TEST.VALUE:<<ALL_MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue[0]:0
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.return:0
TEST.END

-- Test Case: ComAbsMdlSafe_TxCanSetSig_Battery_Voltage_002
TEST.UNIT:ComAbsMdlSafe_TxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_TxCanSetSig_Battery_Voltage
TEST.NEW
TEST.NAME:ComAbsMdlSafe_TxCanSetSig_Battery_Voltage_002
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Airbag:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Alive_101:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.CRC_101:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.VehicleSpeedABS:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[1].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[2].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[3].pGetSignalFunct:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].pGetSignalU8ArrFunct:<<value error>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalInvalidIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalGetFunctIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].RxSigMonitoringType:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalMissingCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidSigIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidCounterValue:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].pSignalInvalidCheckFunc:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalFunctPtrConfig[0]:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrConfig[0]:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSetSignalIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSigalProps:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSetSignalIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSigalProps:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalLengthInByte:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalBufferStartIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSetSignalIdx:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSigalProps:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue[0]:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAirbag_FromMsg.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAlive_101_FromMsg.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetCRC_101_FromMsg.pSignalValue:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Airbag:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Alive_101:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].CRC_101:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].VehicleSpeedABS:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].transformerClass:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.ComAbsMdlSafeReloadMissingTimer.SignalId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Alive_200:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Battery_Voltage:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].CRC_200:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].errorCode:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].transformerClass:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.return:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.return:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.id:<<MAX>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.pSignalValue:"<<MAX>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.return:<<MAX>>
TEST.END

-- Test Case: ComAbsMdlSafe_TxCanSetSig_Battery_Voltage_003
TEST.UNIT:ComAbsMdlSafe_TxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_TxCanSetSig_Battery_Voltage
TEST.NEW
TEST.NAME:ComAbsMdlSafe_TxCanSetSig_Battery_Voltage_003
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Airbag:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Alive_101:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.CRC_101:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.VehicleSpeedABS:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[1].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[2].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[3].pGetSignalFunct:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].pGetSignalU8ArrFunct:<<value error>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalInvalidIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalGetFunctIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].RxSigMonitoringType:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalMissingCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidSigIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidCounterValue:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].pSignalInvalidCheckFunc:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalFunctPtrConfig[0]:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrConfig[0]:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSetSignalIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSigalProps:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSetSignalIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSigalProps:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalLengthInByte:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalBufferStartIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSetSignalIdx:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSigalProps:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue[0]:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAirbag_FromMsg.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAlive_101_FromMsg.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetCRC_101_FromMsg.pSignalValue:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Airbag:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Alive_101:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].CRC_101:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].VehicleSpeedABS:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].transformerClass:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.ComAbsMdlSafeReloadMissingTimer.SignalId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Alive_200:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Battery_Voltage:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].CRC_200:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].errorCode:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].transformerClass:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.return:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.return:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.id:<<MIN>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.pSignalValue:"<<MIN>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.return:<<MIN>>
TEST.END

-- Test Case: ComAbsMdlSafe_TxCanSetSig_Battery_Voltage_004
TEST.UNIT:ComAbsMdlSafe_TxCfg
TEST.SUBPROGRAM:ComAbsMdlSafe_TxCanSetSig_Battery_Voltage
TEST.NEW
TEST.NAME:ComAbsMdlSafe_TxCanSetSig_Battery_Voltage_004
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Airbag:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.Alive_101:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.CRC_101:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.msg1.VehicleSpeedABS:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[0].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[1].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[2].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalFunctConfig[3].pGetSignalFunct:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].SignalU8ArrBufferLenIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanGetSignalU8ArrConfig[0].pGetSignalU8ArrFunct:<<value error>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[0].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[1].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[2].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalInvalidIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalGetFunctIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].RxSigMonitoringType:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalConfig[3].SignalMissingCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidSigIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].SignalInvalidCounterValue:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidConfig[0].pSignalInvalidCheckFunc:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalNRStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalMissingStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanJustRcvdStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidCRCStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalInvalidAliveCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignalRepetationCounterStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_RxCanSignal_currentStatus:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalFunctPtrConfig[0]:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSetSignalU8ArrFunctPtrConfig[0]:<<value error>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSetSignalIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[0].TxSigalProps:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSetSignalIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[1].TxSigalProps:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalLengthInByte:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].SignalBufferStartIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSetSignalIdx:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.<<GLOBAL>>.ComAbsMdlSafe_TxCanSignalConfig[2].TxSigalProps:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue:<<malloc 1>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetVehicleSpeedABS_FromMsg.pSignalValue[0]:<<MID>>
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAirbag_FromMsg.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetAlive_101_FromMsg.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_RxCfg.ComAbsMdlSafe_RxCanGetCRC_101_FromMsg.pSignalValue:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Airbag:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].Alive_101:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].CRC_101:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.data[0].VehicleSpeedABS:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].errorCode:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.transformerError[0].transformerClass:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.ComAbsMdlSafeReloadMissingTimer.SignalId:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Alive_200:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].Battery_Voltage:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.data[0].CRC_200:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].errorCode:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.transformerError[0].transformerClass:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS.return:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanSetSig_Battery_Voltage.return:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.id:<<MID>>
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.pSignalValue:"<<MID>>"
TEST.VALUE:ComAbsMdlSafe_TxCfg.ComAbsMdlSafe_TxCanPutTo_COM_HS_Core.return:<<MID>>
TEST.END
