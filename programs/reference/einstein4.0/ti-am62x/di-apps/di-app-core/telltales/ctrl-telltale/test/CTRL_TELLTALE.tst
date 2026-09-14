-- VectorCAST 20.sp7 (04/21/21)
-- Test Case Script
--
-- Environment    : CTRL_TELLTALE
-- Unit(s) Under Test: Ctrl_Telltale_Extn Ctrl_Telltale_blinkctrl Ctrl_telltale Ctrl_telltale_adapter
--
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:REMOVED_CL_PREFIX
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Unit: Ctrl_Telltale_Extn

-- Subprogram: CtrlTtCheckBatteryStatus

-- Test Case: HVSD2_Failure_Cond
TEST.UNIT:Ctrl_Telltale_Extn
TEST.SUBPROGRAM:CtrlTtCheckBatteryStatus
TEST.NEW
TEST.NAME:HVSD2_Failure_Cond
TEST.VALUE:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_HVSD2Flag:0
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.index:3
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.l_turn_on_off:1
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.battery_status:2
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.return:2
TEST.END

-- Test Case: HVSD2_ON_Battery_status_Overvoltage_Testcase
TEST.UNIT:Ctrl_Telltale_Extn
TEST.SUBPROGRAM:CtrlTtCheckBatteryStatus
TEST.NEW
TEST.NAME:HVSD2_ON_Battery_status_Overvoltage_Testcase
TEST.VALUE:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_HVSD2Flag:1
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.index:2
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.l_turn_on_off:1
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.battery_status:2
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.return:2
TEST.END

-- Test Case: HVSD2_ON_Cond_Testcase
TEST.UNIT:Ctrl_Telltale_Extn
TEST.SUBPROGRAM:CtrlTtCheckBatteryStatus
TEST.NEW
TEST.NAME:HVSD2_ON_Cond_Testcase
TEST.VALUE:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_HVSD2Flag:1
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.index:0
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.l_turn_on_off:1
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.battery_status:2
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.return:2
TEST.END

-- Test Case: LVSD2_On_Cond_Testcase
TEST.UNIT:Ctrl_Telltale_Extn
TEST.SUBPROGRAM:CtrlTtCheckBatteryStatus
TEST.NEW
TEST.NAME:LVSD2_On_Cond_Testcase
TEST.VALUE:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_LVSD2Flag:1
TEST.VALUE:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_HVSD2Flag:0
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.index:0
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.l_turn_on_off:1
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.battery_status:0
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.return:0
TEST.END

-- Test Case: Normal_Valid_Testcase
TEST.UNIT:Ctrl_Telltale_Extn
TEST.SUBPROGRAM:CtrlTtCheckBatteryStatus
TEST.NEW
TEST.NAME:Normal_Valid_Testcase
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.index:0
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.l_turn_on_off:1
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.battery_status:1
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckBatteryStatus.return:1
TEST.END

-- Subprogram: CtrlTtCheckProveout

-- Test Case: ATT_R04_Proveout_proveout_cond_check
TEST.UNIT:Ctrl_Telltale_Extn
TEST.SUBPROGRAM:CtrlTtCheckProveout
TEST.NEW
TEST.NAME:ATT_R04_Proveout_proveout_cond_check
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckProveout.index:0
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckProveout.l_turn_on_off:1
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckProveout.tt_state_byte:8
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtCheckProveout.return:1
TEST.END

-- Subprogram: CtrlTtVoltageLviHvi

-- Test Case: HVSD2_Cond_Testcase
TEST.UNIT:Ctrl_Telltale_Extn
TEST.SUBPROGRAM:CtrlTtVoltageLviHvi
TEST.NEW
TEST.NAME:HVSD2_Cond_Testcase
TEST.VALUE:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_HVSD2Flag:1
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtVoltageLviHvi.return:1
TEST.END

-- Test Case: LVSD2_Cond_Testcase
TEST.UNIT:Ctrl_Telltale_Extn
TEST.SUBPROGRAM:CtrlTtVoltageLviHvi
TEST.NEW
TEST.NAME:LVSD2_Cond_Testcase
TEST.VALUE:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_LVSD2Flag:1
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtVoltageLviHvi.return:1
TEST.END

-- Test Case: LVSD2_HVSD2_Failure_Cond
TEST.UNIT:Ctrl_Telltale_Extn
TEST.SUBPROGRAM:CtrlTtVoltageLviHvi
TEST.NEW
TEST.NAME:LVSD2_HVSD2_Failure_Cond
TEST.VALUE:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_LVSD2Flag:0
TEST.VALUE:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_HVSD2Flag:0
TEST.VALUE:Ctrl_Telltale_Extn.CtrlTtVoltageLviHvi.return:0
TEST.END

-- Unit: Ctrl_Telltale_blinkctrl

-- Subprogram: BlinkCtrl_Asynchronous_Flash_Process

-- Test Case: ATT_R06_Flashing_nonsync_Invalid_Index_Testcase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Asynchronous_Flash_Process
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_Invalid_Index_Testcase
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Asynchronous_Flash_Process.Tt_index:24
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_Invalid_PrevTTInputStatus
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Asynchronous_Flash_Process
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_Invalid_PrevTTInputStatus
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_FLASH_SYNC_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_FLASH_SYNC_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_SYNC_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:25
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:22
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:23
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_SYNC_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_SYNC_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_SYNC_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_SYNC_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_SYNC_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_SYNC_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_SYNC_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_SYNC_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_SYNC_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_SYNC_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_FLASH_SYNC_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_FLASH_SYNC_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_FLASH_SYNC_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_SYNC_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_SYNC_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_SYNC_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_SYNC_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Asynchronous_Flash_Process.Tt_index:0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_Pattersize_Reload_Testcase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Asynchronous_Flash_Process
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_Pattersize_Reload_Testcase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PatternSize:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTOnOffCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Asynchronous_Flash_Process.Tt_index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PatternSize:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PatternSize:TT_TURN_ON
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_TTMAXFlashCntr_TTOnOffCntr_valid_Testcase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Asynchronous_Flash_Process
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_TTMAXFlashCntr_TTOnOffCntr_valid_Testcase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTOnOffCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Asynchronous_Flash_Process.Tt_index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_TtOnOffCntr_TestCases
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Asynchronous_Flash_Process
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_TtOnOffCntr_TestCases
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:80
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:40
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:20
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:24
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:20
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:12
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:5
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTOnOffCntr:5
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTOnOffCntr:5
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTOnOffCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:2
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PatternSize:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTOnOffCntr:5
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTOnOffCntr:5
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTOnOffCntr:5
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTOnOffCntr:5
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTOnOffCntr:9
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Asynchronous_Flash_Process.Tt_index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:79
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:39
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:19
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:23
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:19
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:11
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:3
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTOnOffCntr:3
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:3
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTOnOffCntr:3
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTOnOffCntr:3
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTOnOffCntr:3
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTOnOffCntr:3
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTOnOffCntr:3
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTOnOffCntr:8
TEST.END

-- Subprogram: BlinkCtrl_Different_Flash_Process

-- Test Case: ATT_R06_Flashing_nonsync_All_valid_Index_possible_testcase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Different_Flash_Process
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_All_valid_Index_possible_testcase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:80
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:40
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:40
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:60
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:24
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:20
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:15
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:12
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTOnOffCntr:10
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTOnOffCntr:8
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:7
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTOnOffCntr:14
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTOnOffCntr:14
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTOnOffCntr:8
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTOnOffCntr:8
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTOnOffCntr:7
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTOnOffCntr:5
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTOnOffCntr:80
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTOnOffCntr:40
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTOnOffCntr:40
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTOnOffCntr:24
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Different_Flash_Process.Tt_index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:40
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:60
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:20
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:24
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:20
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:15
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:12
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:10
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTOnOffCntr:8
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTOnOffCntr:7
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:14
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTOnOffCntr:8
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTOnOffCntr:7
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTOnOffCntr:5
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTOnOffCntr:5
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTOnOffCntr:80
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTOnOffCntr:40
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTOnOffCntr:60
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMinFlashCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_Invalid_Index_Testcase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Different_Flash_Process
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_Invalid_Index_Testcase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:80
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:40
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:40
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:60
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:24
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:20
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:15
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:12
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTOnOffCntr:10
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTOnOffCntr:8
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:7
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTOnOffCntr:14
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTOnOffCntr:14
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTOnOffCntr:8
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTOnOffCntr:8
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTOnOffCntr:7
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTOnOffCntr:5
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTOnOffCntr:80
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTOnOffCntr:40
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTOnOffCntr:40
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTOnOffCntr:24
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Different_Flash_Process.Tt_index:(22)cTOTAL_TT_CONFIGURED
TEST.END

-- Subprogram: BlinkCtrl_Flash_Min_Max_Cntr_Process

-- Test Case: All_TTMinFlashCntr_TTMaxFlashCntr_Pass_Fail_Cond_Testcase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Flash_Min_Max_Cntr_Process
TEST.NEW
TEST.NAME:All_TTMinFlashCntr_TTMaxFlashCntr_Pass_Fail_Cond_Testcase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTMinFlashCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMaxFlashCntr:2
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTMaxFlashCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].OnePatternFinished:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Flash_Min_Max_Cntr_Process.Tt_index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMaxFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTPhase:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMinFlashCntr:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMaxFlashCntr:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTMinFlashCntr:TT_TURN_OFF
TEST.END

-- Test Case: Invalid_Index_Testcase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Flash_Min_Max_Cntr_Process
TEST.NEW
TEST.NAME:Invalid_Index_Testcase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMaxFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTMaxFlashCntr:cTT_MAX_FLASH_NA
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMaxFlashCntr:2
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTMinFlashCntr:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTMaxFlashCntr:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].OnePatternFinished:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].OnePatternFinished:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Flash_Min_Max_Cntr_Process.Tt_index:(22)cTOTAL_TT_CONFIGURED
TEST.END

-- Subprogram: BlinkCtrl_Prepare_Flash_Process

-- Test Case: ATT_R06_Flashing_nonsync_All_Frequency_Invalid_Index_Testcase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Prepare_Flash_Process
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_All_Frequency_Invalid_Index_Testcase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Prepare_Flash_Process.Tt_index:(22)cTOTAL_TT_CONFIGURED
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Prepare_Flash_Process.Tt_target_phase:(23)TT_TURN_ON
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_All_Frequency_Testcase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Prepare_Flash_Process
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_All_Frequency_Testcase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Prepare_Flash_Process.Tt_index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_Prepare_Flash_Process.Tt_target_phase:(21)TT_TURN_ON,TT_TURN_OFF,TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:80
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:40
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:20
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:24
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:20
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:15
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTOnOffCntr:12
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTOnOffCntr:10
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:8
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTOnOffCntr:7
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTOnOffCntr:14
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTOnOffCntr:5
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTOnOffCntr:5
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTOnOffCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTOnOffCntr:0
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTOnOffCntr:80
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTOnOffCntr:40
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTOnOffCntr:60
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTPhase:cTT_PHASE_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.END

-- Subprogram: BlinkCtrl_TtViewUpdateStatus

-- Test Case: ATT_R06_Flashing_nonsync_All_Index_In_Range_TestCase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_TtViewUpdateStatus
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_All_Index_In_Range_TestCase
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_TtViewUpdateStatus.index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_TtViewUpdateStatus.tt_status:TT_TURN_OFF,TT_TURN_ON,TT_FLASH_QUARTER_HZ,TT_FLASH_HALF_HZ,TT_FLASH_CSNR_HALF_HZ,TT_FLASH_0_83_HZ,TT_FLASH_1HZ,TT_FLASH_1_33_HZ,TT_FLASH_1_66_HZ,TT_FLASH_2HZ,TT_FLASH_2_5_HZ,TT_FLASH_2_66_HZ,TT_FLASH_TRNHZ_Normal,TT_FLASH_TRNHZ_Fast,TT_FLASH_TRNHZ_FHL,TT_FLASH_4HZ,TT_FLASH_5HZ,TT_TURN_OFF,TT_TURN_ON,TT_FLASH_QUARTER_HZ,TT_FLASH_HALF_HZ,TT_FLASH_CSNR_HALF_HZ,TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_1HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_1_33_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_1_66_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_2HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_2_5_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_2_66_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_4HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_FLASH_5HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_0_83_HZ
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_Index_Out_of_Bounds_TestCase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_TtViewUpdateStatus
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_Index_Out_of_Bounds_TestCase
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_TtViewUpdateStatus.index:24
TEST.VALUE:Ctrl_Telltale_blinkctrl.BlinkCtrl_TtViewUpdateStatus.tt_status:TT_TURN_OFF
TEST.END

-- Subprogram: BlinkCtrl_Update_Output

-- Test Case: ATT_R06_Flashing_nonsync_PrevOnstate_CurrOnstate_TestCase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Update_Output
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_PrevOnstate_CurrOnstate_TestCase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_TURN_ON
TEST.ATTRIBUTES:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[6]:INPUT_BASE=8
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_PrevOnstate_CurrentBlinkstate_TestCase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Update_Output
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_PrevOnstate_CurrentBlinkstate_TestCase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTOnOffCntr:4
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTOnOffCntr:4
TEST.ATTRIBUTES:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[6]:INPUT_BASE=8
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_PrevTTinputStatus_Blinking_Testcase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Update_Output
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_PrevTTinputStatus_Blinking_Testcase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_2HZ
TEST.ATTRIBUTES:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[6]:INPUT_BASE=8
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_Process_PrevOFFState_TT_All_Testcases
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:BlinkCtrl_Update_Output
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_Process_PrevOFFState_TT_All_Testcases
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:80
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTPhase:cTT_PHASE_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:40
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTPhase:cTT_PHASE_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:20
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTPhase:cTT_PHASE_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:24
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTPhase:cTT_PHASE_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTOnOffCntr:20
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_1HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTPhase:cTT_PHASE_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTOnOffCntr:15
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTPhase:cTT_PHASE_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTOnOffCntr:12
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTPhase:cTT_PHASE_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_2HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PatternSize:cTT_PHASE_PATTERN_SIZE
TEST.ATTRIBUTES:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[6]:INPUT_BASE=8
TEST.END

-- Subprogram: Process_PrevBlinkState_TT

-- Test Case: ATT_R06_Flashing_nonsync_PrevTTInputStatus_Invalid_Cond
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:Process_PrevBlinkState_TT
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_PrevTTInputStatus_Invalid_Cond
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:MACRO=TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.Process_PrevBlinkState_TT.index:MACRO=TT_ABS_INDEX,MACRO=TT_ADAS_INDEX,MACRO=TT_AIRBAG_INDEX,MACRO=TT_AUTO_HIGH_BEAM_INDEX,MACRO=TT_BRAKE_RED_INDEX,MACRO=TT_BRAKE_HOLD_INDEX,MACRO=TT_BRAKE_HOLD_STANDBY_INDEX,MACRO=TT_BRAKE_YELLOW_INDEX,MACRO=TT_PARKING_BRAKE_INDEX,MACRO=TT_FUEL_INDEX,MACRO=TT_FFOG_INDEX,MACRO=TT_HEAD_INDEX,MACRO=TT_HIGH_BEAM_INDEX,MACRO=TT_PCS_OFF_INDEX,MACRO=TT_READY_INDEX,MACRO=TT_RFOG_INDEX,MACRO=TT_SEAT_BELT_INDEX,MACRO=TT_TAIL_LIGHT_INDEX,MACRO=TT_TRACTION_CTRL_INDEX,MACRO=TT_TURN_HAZARD_RIGHT_INDEX,MACRO=TT_TURN_HAZARD_LEFT_INDEX,MACRO=TT_VCS_OFF_INDEX,MACRO=TT_EWT_INDEX
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_PrevTTInputStatus_TTInputStatus_Not_equal_Cond.001
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:Process_PrevBlinkState_TT
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_PrevTTInputStatus_TTInputStatus_Not_equal_Cond.001
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.Process_PrevBlinkState_TT.index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_PrevTTInputStatus_TTInputStatus_equal_Cond
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:Process_PrevBlinkState_TT
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_PrevTTInputStatus_TTInputStatus_equal_Cond
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.Process_PrevBlinkState_TT.index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_TTMinFlashCntr_Fail_Cond
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:Process_PrevBlinkState_TT
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_TTMinFlashCntr_Fail_Cond
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTMinFlashCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.Process_PrevBlinkState_TT.index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_TTMinFlashCntr_TTInputStatus_False_Cond
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:Process_PrevBlinkState_TT
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_TTMinFlashCntr_TTInputStatus_False_Cond
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTMinFlashCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.Process_PrevBlinkState_TT.index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.END

-- Subprogram: Process_PrevOFFState_TT

-- Test Case: ATT_R06_Flashing_nonsync_TTInputStatus_Condition_check
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:Process_PrevOFFState_TT
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_TTInputStatus_Condition_check
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.Process_PrevOFFState_TT.index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_1HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_2HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_2_5_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_2_66_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_4HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_FLASH_5HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_TTInputStatus_Fail_Condition
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:Process_PrevOFFState_TT
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_TTInputStatus_Fail_Condition
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_SYNC_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.Process_PrevOFFState_TT.index:0,1,2
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_TT_InputStatus_On_Cond_Check
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:Process_PrevOFFState_TT
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_TT_InputStatus_On_Cond_Check
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.Process_PrevOFFState_TT.index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.END

-- Subprogram: Process_PrevONState_TT

-- Test Case: ATT_R06_Flashing_nonsync_TTInputStatus_Fail_Condition
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:Process_PrevONState_TT
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_TTInputStatus_Fail_Condition
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.Process_PrevONState_TT.index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_SYNC_HALF_HZ
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_TTInputStatus_condition_check
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:Process_PrevONState_TT
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_TTInputStatus_condition_check
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.Process_PrevONState_TT.index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_1HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_2HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_2_5_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_2_66_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_4HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_5HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_1HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.END

-- Test Case: ATT_R06_Flashing_nonsync_TT_InputStatus_On_Condition_check
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:Process_PrevONState_TT
TEST.NEW
TEST.NAME:ATT_R06_Flashing_nonsync_TT_InputStatus_On_Condition_check
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.Process_PrevONState_TT.index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.END

-- Subprogram: assignTTStatus

-- Test Case: 2.6__ATT_R06_Flashing_nonsync_TT_Status_Prev_TT_Status_assignment_TestCase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:assignTTStatus
TEST.NEW
TEST.NAME:2.6__ATT_R06_Flashing_nonsync_TT_Status_Prev_TT_Status_assignment_TestCase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:MACRO=TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:MACRO=TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:MACRO=TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:MACRO=TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:MACRO=TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:MACRO=TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:MACRO=TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:MACRO=TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:MACRO=TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:MACRO=TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:MACRO=TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:MACRO=TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:MACRO=TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:MACRO=TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:MACRO=TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:MACRO=TT_FLASH_4HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:MACRO=TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:MACRO=TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:MACRO=TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:MACRO=TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:MACRO=TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:MACRO=TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.assignTTStatus.index:MACRO=TT_ABS_INDEX,MACRO=TT_ADAS_INDEX,MACRO=TT_AIRBAG_INDEX,MACRO=TT_AUTO_HIGH_BEAM_INDEX,MACRO=TT_BRAKE_RED_INDEX,MACRO=TT_BRAKE_HOLD_INDEX,MACRO=TT_BRAKE_HOLD_STANDBY_INDEX,MACRO=TT_BRAKE_YELLOW_INDEX,MACRO=TT_PARKING_BRAKE_INDEX,MACRO=TT_FUEL_INDEX,MACRO=TT_FFOG_INDEX,MACRO=TT_HEAD_INDEX,MACRO=TT_HIGH_BEAM_INDEX,MACRO=TT_PCS_OFF_INDEX,MACRO=TT_READY_INDEX,MACRO=TT_RFOG_INDEX,MACRO=TT_SEAT_BELT_INDEX,MACRO=TT_TAIL_LIGHT_INDEX,MACRO=TT_TRACTION_CTRL_INDEX,MACRO=TT_TURN_HAZARD_RIGHT_INDEX,MACRO=TT_TURN_HAZARD_LEFT_INDEX,MACRO=TT_VCS_OFF_INDEX,MACRO=TT_EWT_INDEX
TEST.VALUE:Ctrl_Telltale_blinkctrl.assignTTStatus.status:MACRO=TT_TURN_OFF,MACRO=TT_TURN_ON,MACRO=TT_FLASH_QUARTER_HZ,MACRO=TT_FLASH_HALF_HZ,MACRO=TT_FLASH_CSNR_HALF_HZ,MACRO=TT_FLASH_0_83_HZ,MACRO=TT_FLASH_1HZ,MACRO=TT_FLASH_1_33_HZ,MACRO=TT_FLASH_1_66_HZ,MACRO=TT_FLASH_2HZ,MACRO=TT_FLASH_2_5_HZ,MACRO=TT_FLASH_2_66_HZ,MACRO=TT_FLASH_TRNHZ_Normal,MACRO=TT_FLASH_TRNHZ_Fast,MACRO=TT_FLASH_TRNHZ_FHL,MACRO=TT_FLASH_4HZ,MACRO=TT_FLASH_5HZ,MACRO=TT_TURN_OFF,MACRO=TT_TURN_ON,MACRO=TT_FLASH_QUARTER_HZ,MACRO=TT_FLASH_HALF_HZ,MACRO=TT_FLASH_CSNR_HALF_HZ,MACRO=TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:MACRO=TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTPhase:MACRO=TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:MACRO=TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTPhase:MACRO=TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:MACRO=TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:MACRO=TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:MACRO=TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:MACRO=TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:MACRO=TT_FLASH_1HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:MACRO=TT_FLASH_1_33_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:MACRO=TT_FLASH_1_66_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:MACRO=TT_FLASH_2HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:MACRO=TT_FLASH_2_5_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:MACRO=TT_FLASH_2_66_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:MACRO=TT_FLASH_TRNHZ_Normal
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:MACRO=TT_FLASH_TRNHZ_Fast
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:MACRO=TT_FLASH_TRNHZ_FHL
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTPhase:MACRO=TT_FLASH_4HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:MACRO=TT_FLASH_5HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:MACRO=TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTPhase:MACRO=TT_TURN_OFF
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:MACRO=TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTPhase:MACRO=TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:MACRO=TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:MACRO=TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:MACRO=TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:MACRO=TT_FLASH_0_83_HZ
TEST.END

-- Subprogram: isOnAllowed

-- Test Case: All_Valid_Failure_Testcase
TEST.UNIT:Ctrl_Telltale_blinkctrl
TEST.SUBPROGRAM:isOnAllowed
TEST.NEW
TEST.NAME:All_Valid_Failure_Testcase
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:1
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:TT_TURN_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[1].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:4
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[3].TTPhase:cTT_PHASE_OFF
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:0
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_TURN_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:80
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:20
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:20
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTOnOffCntr:24
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTOnOffCntr:20
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_1HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:15
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTOnOffCntr:12
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTOnOffCntr:10
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_2HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTOnOffCntr:8
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTOnOffCntr:7
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTOnOffCntr:14
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTPhase:cTT_PHASE_ON
TEST.VALUE:Ctrl_Telltale_blinkctrl.isOnAllowed.index:TT_ABS_INDEX,TT_ADAS_INDEX,TT_AIRBAG_INDEX,TT_AUTO_HIGH_BEAM_INDEX,TT_BRAKE_RED_INDEX,TT_BRAKE_HOLD_INDEX,TT_BRAKE_HOLD_STANDBY_INDEX,TT_BRAKE_YELLOW_INDEX,TT_PARKING_BRAKE_INDEX,TT_FUEL_INDEX,TT_FFOG_INDEX,TT_HEAD_INDEX,TT_HIGH_BEAM_INDEX,TT_PCS_OFF_INDEX,TT_READY_INDEX,TT_RFOG_INDEX,TT_SEAT_BELT_INDEX,TT_TAIL_LIGHT_INDEX,TT_TRACTION_CTRL_INDEX,TT_TURN_HAZARD_RIGHT_INDEX,TT_TURN_HAZARD_LEFT_INDEX,TT_VCS_OFF_INDEX,TT_EWT_INDEX
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:TT_TURN_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[0].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:TT_FLASH_TRNHZ_FHL
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[2].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[4].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[5].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[6].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[7].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:TT_FLASH_1HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[8].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:TT_FLASH_1_33_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[9].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:TT_FLASH_1_66_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[10].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:TT_FLASH_2HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[11].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:TT_FLASH_2_5_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[12].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:TT_FLASH_2_66_HZ
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[13].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[14].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:TT_FLASH_TRNHZ_Fast
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[15].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[16].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[17].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[18].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[19].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[20].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[21].TTPhase:cTT_PHASE_ON
TEST.EXPECTED:Ctrl_Telltale_blinkctrl.<<GLOBAL>>.TTInfoTable[22].TTPhase:cTT_PHASE_ON
TEST.END

-- Unit: Ctrl_telltale

-- Subprogram: CmpActivation

-- Test Case: CmpActivation_Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation_Testcase
TEST.VALUE:Ctrl_telltale.CmpActivation.return:0
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.Testcase
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[0]:1
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[1]:1
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[2]:9
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[3]:5
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[4]:12
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[5]:15
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[6]:7
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[7]:13
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[8]:11
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[9]:1
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[10]:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[11]:1
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[12]:3
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[13]:5
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[14]:1
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[15]:1
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[16]:1
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[17]:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[18]:16
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[19]:1
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[20]:1
TEST.VALUE:Ctrl_telltale.CmpActive.return:0
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[0]:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[1]:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[2]:9
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[3]:5
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[4]:12
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[5]:15
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[6]:7
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[7]:13
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[8]:11
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[9]:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[10]:0
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[11]:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[12]:3
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[13]:5
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[14]:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[15]:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[16]:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[17]:2
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[18]:16
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[19]:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[20]:1
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation_Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation_Testcase
TEST.VALUE:Ctrl_telltale.CmpDeActivation.return:0
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit_Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit_Testcase
TEST.VALUE:Ctrl_telltale.CmpDeInit.return:0
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag_Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag_Testcase
TEST.VALUE:Ctrl_telltale.CmpDiag.return:0
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn_Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn_Testcase
TEST.VALUE:Ctrl_telltale.CmpDiagReturn.return:0
TEST.END

-- Subprogram: CmpInit

-- Test Case: All_Variable_Init_Cond
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:All_Variable_Init_Cond
TEST.MCDC_BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (index < (TT_ENUM_TYPE)23U) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #1, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[0].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[0].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[0].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[0].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[0].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[0].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[0].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[0].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[1].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[1].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[1].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[1].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[1].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[1].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[1].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[1].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[2].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[2].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[2].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[2].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[2].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[2].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[2].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[2].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[3].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[3].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[3].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[3].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[3].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[3].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[3].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[3].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[4].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[4].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[4].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[4].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[4].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[4].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[4].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[4].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[5].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[5].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[5].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[5].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[5].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[5].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[5].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[5].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[6].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[6].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[6].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[6].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[6].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[6].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[6].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[6].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[7].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[7].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[7].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[7].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[7].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[7].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[7].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[7].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[8].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[8].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[8].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[8].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[8].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[8].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[8].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[8].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[9].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[9].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[9].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[9].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[9].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[9].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[9].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[9].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[10].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[10].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[10].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[10].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[10].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[10].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[10].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[10].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[11].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[11].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[11].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[11].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[11].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[11].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[11].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[11].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[12].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[12].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[12].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[12].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[12].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[12].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[12].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[12].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[13].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[13].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[13].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[13].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[13].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[13].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[13].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[13].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[14].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[14].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[14].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[14].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[14].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[14].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[14].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[14].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[15].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[15].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[15].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[15].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[15].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[15].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[15].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[15].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[16].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[16].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[16].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[16].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[16].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[16].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[16].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[16].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[17].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[17].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[17].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[17].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[17].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[17].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[17].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[17].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[18].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[18].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[18].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[18].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[18].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[18].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[18].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[18].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[19].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[19].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[19].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[19].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[19].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[19].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[19].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[19].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[20].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[20].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[20].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[20].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[20].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[20].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[20].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[20].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[21].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[21].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[21].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[21].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[21].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[21].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[21].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[21].OnePatternFinished:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[22].TTOnOffCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[22].TTMinFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[22].TTMaxFlashCntr:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[22].TTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[22].PrevTTInputStatus:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[22].TTPhase:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[22].PatternSize:2
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.TTInfoTable[22].OnePatternFinished:0
TEST.END

-- Test Case: Return_Value_Cond
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:Return_Value_Cond
TEST.MCDC_BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (index < (TT_ENUM_TYPE)23U) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #1, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.CmpInit.return:0
TEST.END

-- Subprogram: CtrlTtGetStateByte

-- Test Case: ATT_R03_vehicle_State_Default_case_
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CtrlTtGetStateByte
TEST.NEW
TEST.NAME:ATT_R03_vehicle_State_Default_case_
TEST.VALUE:Ctrl_telltale.CtrlTtGetStateByte.IgnSts:3
TEST.VALUE:Ctrl_telltale.CtrlTtGetStateByte.tt_state_byte:0
TEST.END

-- Test Case: ATT_R03_vehicle_State_GN_OFF
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CtrlTtGetStateByte
TEST.NEW
TEST.NAME:ATT_R03_vehicle_State_GN_OFF
TEST.MCDC_BASIS_PATH:1 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (CtrlTtIgnSts == 1U) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #1, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.CtrlTtGetStateByte.IgnSts:<<MIN>>
TEST.VALUE:Ctrl_telltale.CtrlTtGetStateByte.tt_state_byte:<<MIN>>
TEST.EXPECTED:Ctrl_telltale.CtrlTtGetStateByte.IgnSts:0
TEST.EXPECTED:Ctrl_telltale.CtrlTtGetStateByte.tt_state_byte:0
TEST.EXPECTED:Ctrl_telltale.CtrlTtGetStateByte.return:4
TEST.END

-- Test Case: ATT_R03_vehicle_State_IGN_ACC
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CtrlTtGetStateByte
TEST.NEW
TEST.NAME:ATT_R03_vehicle_State_IGN_ACC
TEST.MCDC_BASIS_PATH:3 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (CtrlTtIgnSts == 1U) ==> FALSE
      (2) if (CtrlTtIgnSts == 0U) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #2, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.CtrlTtGetStateByte.IgnSts:2
TEST.VALUE:Ctrl_telltale.CtrlTtGetStateByte.tt_state_byte:<<MIN>>
TEST.EXPECTED:Ctrl_telltale.CtrlTtGetStateByte.IgnSts:2
TEST.EXPECTED:Ctrl_telltale.CtrlTtGetStateByte.tt_state_byte:0
TEST.EXPECTED:Ctrl_telltale.CtrlTtGetStateByte.return:2
TEST.END

-- Test Case: ATT_R03_vehicle_State_IGN_CRANK
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CtrlTtGetStateByte
TEST.NEW
TEST.NAME:ATT_R03_vehicle_State_IGN_CRANK
TEST.MCDC_BASIS_PATH:4 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (CtrlTtIgnSts == 1U) ==> FALSE
      (2) if (CtrlTtIgnSts == 0U) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #2, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.CtrlTtGetStateByte.IgnSts:4
TEST.VALUE:Ctrl_telltale.CtrlTtGetStateByte.tt_state_byte:<<MIN>>
TEST.EXPECTED:Ctrl_telltale.CtrlTtGetStateByte.IgnSts:4
TEST.EXPECTED:Ctrl_telltale.CtrlTtGetStateByte.return:1
TEST.END

-- Test Case: ATT_R03_vehicle_State_IGN_ON
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CtrlTtGetStateByte
TEST.NEW
TEST.NAME:ATT_R03_vehicle_State_IGN_ON
TEST.MCDC_BASIS_PATH:2 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (CtrlTtIgnSts == 1U) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #1, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.CtrlTtGetStateByte.IgnSts:1
TEST.VALUE:Ctrl_telltale.CtrlTtGetStateByte.tt_state_byte:<<MIN>>
TEST.VALUE:Ctrl_telltale.CtrlTtGetStateByte.return:8
TEST.EXPECTED:Ctrl_telltale.CtrlTtGetStateByte.IgnSts:1
TEST.EXPECTED:Ctrl_telltale.CtrlTtGetStateByte.tt_state_byte:0
TEST.END

-- Subprogram: CtrlTt_CtrlTtGetStatus

-- Test Case: CtrlTtSts_Status_Cond
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CtrlTt_CtrlTtGetStatus
TEST.NEW
TEST.NAME:CtrlTtSts_Status_Cond
TEST.MCDC_BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (index < (TT_ENUM_TYPE)23U) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #1, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.CtrlTt_CtrlTtGetStatus.index:0
TEST.VALUE:Ctrl_telltale.CtrlTt_CtrlTtGetStatus.tt_status:<<malloc 1>>
TEST.VALUE:Ctrl_telltale.CtrlTt_CtrlTtGetStatus.tt_status[0]:TT_TURN_ON
TEST.END

-- Test Case: Invalid_Index_Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CtrlTt_CtrlTtGetStatus
TEST.NEW
TEST.NAME:Invalid_Index_Testcase
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (index < (TT_ENUM_TYPE)23U) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #1, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.CtrlTt_CtrlTtGetStatus.index:TT_TOTAL_NUM_OF_TELLTALES
TEST.VALUE:Ctrl_telltale.CtrlTt_CtrlTtGetStatus.tt_status:<<malloc 1>>
TEST.VALUE:Ctrl_telltale.CtrlTt_CtrlTtGetStatus.tt_status[0]:TT_TURN_ON
TEST.END

-- Subprogram: CtrlTt_CtrlTtUpdateStatus

-- Test Case: ATT_R01_Telltale_Status_Update_CtrlTtSts_Array_Frequency_index_Cond
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CtrlTt_CtrlTtUpdateStatus
TEST.NEW
TEST.NAME:ATT_R01_Telltale_Status_Update_CtrlTtSts_Array_Frequency_index_Cond
TEST.VALUE:Ctrl_telltale.CtrlTt_CtrlTtUpdateStatus.index:MACRO=TT_ABS_INDEX,MACRO=TT_ADAS_INDEX,MACRO=TT_AIRBAG_INDEX,MACRO=TT_AUTO_HIGH_BEAM_INDEX,MACRO=TT_BRAKE_RED_INDEX,MACRO=TT_BRAKE_HOLD_INDEX,MACRO=TT_BRAKE_HOLD_STANDBY_INDEX,MACRO=TT_BRAKE_YELLOW_INDEX,MACRO=TT_PARKING_BRAKE_INDEX,MACRO=TT_FUEL_INDEX,MACRO=TT_FFOG_INDEX,MACRO=TT_HEAD_INDEX,MACRO=TT_HIGH_BEAM_INDEX,MACRO=TT_PCS_OFF_INDEX,MACRO=TT_READY_INDEX,MACRO=TT_RFOG_INDEX,MACRO=TT_SEAT_BELT_INDEX,MACRO=TT_TAIL_LIGHT_INDEX,MACRO=TT_TRACTION_CTRL_INDEX,MACRO=TT_TURN_HAZARD_RIGHT_INDEX,MACRO=TT_TURN_HAZARD_LEFT_INDEX,MACRO=TT_VCS_OFF_INDEX,MACRO=TT_EWT_INDEX
TEST.VALUE:Ctrl_telltale.CtrlTt_CtrlTtUpdateStatus.tt_status:MACRO=TT_TURN_OFF,MACRO=TT_TURN_ON,MACRO=TT_FLASH_QUARTER_HZ,MACRO=TT_FLASH_HALF_HZ,MACRO=TT_FLASH_CSNR_HALF_HZ,MACRO=TT_FLASH_0_83_HZ,MACRO=TT_FLASH_1HZ,MACRO=TT_FLASH_1_33_HZ,MACRO=TT_FLASH_1_66_HZ,MACRO=TT_FLASH_2HZ,MACRO=TT_FLASH_2_5_HZ,MACRO=TT_FLASH_2_66_HZ,MACRO=TT_FLASH_TRNHZ_Normal,MACRO=TT_FLASH_TRNHZ_Fast,MACRO=TT_FLASH_TRNHZ_FHL,MACRO=TT_FLASH_4HZ,MACRO=TT_FLASH_5HZ,MACRO=TT_TURN_OFF,MACRO=TT_TURN_ON,MACRO=TT_FLASH_QUARTER_HZ,MACRO=TT_FLASH_HALF_HZ,MACRO=TT_FLASH_CSNR_HALF_HZ,MACRO=TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[0]:MACRO=TT_TURN_OFF
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[1]:MACRO=TT_TURN_ON
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[2]:MACRO=TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[3]:MACRO=TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[4]:MACRO=TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[5]:MACRO=TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[6]:MACRO=TT_FLASH_1HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[7]:MACRO=TT_FLASH_1_33_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[8]:MACRO=TT_FLASH_1_66_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[9]:MACRO=TT_FLASH_2HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[10]:MACRO=TT_FLASH_2_5_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[11]:MACRO=TT_FLASH_2_66_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[12]:MACRO=TT_FLASH_TRNHZ_Normal
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[13]:MACRO=TT_FLASH_TRNHZ_Fast
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[14]:MACRO=TT_FLASH_TRNHZ_FHL
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[15]:MACRO=TT_FLASH_4HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[16]:MACRO=TT_FLASH_5HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[17]:MACRO=TT_TURN_OFF
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[18]:MACRO=TT_TURN_ON
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[19]:MACRO=TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[20]:MACRO=TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[21]:MACRO=TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[22]:MACRO=TT_FLASH_0_83_HZ
TEST.END

-- Test Case: ATT_R01_Telltale_Status_Update_Invalid_Index_Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:CtrlTt_CtrlTtUpdateStatus
TEST.NEW
TEST.NAME:ATT_R01_Telltale_Status_Update_Invalid_Index_Testcase
TEST.VALUE:Ctrl_telltale.CtrlTt_CtrlTtUpdateStatus.index:MACRO=TT_TOTAL_NUM_OF_TELLTALES
TEST.VALUE:Ctrl_telltale.CtrlTt_CtrlTtUpdateStatus.tt_status:MACRO=TT_TURN_OFF,MACRO=TT_TURN_ON,MACRO=TT_FLASH_QUARTER_HZ,MACRO=TT_FLASH_HALF_HZ,MACRO=TT_FLASH_CSNR_HALF_HZ,MACRO=TT_FLASH_0_83_HZ,MACRO=TT_FLASH_1HZ,MACRO=TT_FLASH_1_33_HZ,MACRO=TT_FLASH_1_66_HZ,MACRO=TT_FLASH_2HZ,MACRO=TT_FLASH_2_5_HZ,MACRO=TT_FLASH_2_66_HZ,MACRO=TT_FLASH_TRNHZ_Normal,MACRO=TT_FLASH_TRNHZ_Fast,MACRO=TT_FLASH_TRNHZ_FHL,MACRO=TT_FLASH_4HZ,MACRO=TT_FLASH_5HZ,MACRO=TT_TURN_OFF,MACRO=TT_TURN_ON,MACRO=TT_FLASH_QUARTER_HZ,MACRO=TT_FLASH_HALF_HZ,MACRO=TT_FLASH_CSNR_HALF_HZ,MACRO=TT_FLASH_0_83_HZ
TEST.END

-- Subprogram: Ctrl_telltale_Impl_MainFunction

-- Test Case: Main_Function_Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:Ctrl_telltale_Impl_MainFunction
TEST.NEW
TEST.NAME:Main_Function_Testcase
TEST.MCDC_BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) for (index < 23U) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #1, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.END

-- Subprogram: Ctrl_telltale_Impl_OnCommand

-- Test Case: Return_value_Cond
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:Ctrl_telltale_Impl_OnCommand
TEST.NEW
TEST.NAME:Return_value_Cond
TEST.VALUE:Ctrl_telltale.Ctrl_telltale_Impl_OnCommand.return:0
TEST.END

-- Subprogram: InputProcess

-- Test Case: CtrlTtIgnSts_valid_Cond
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:InputProcess
TEST.NEW
TEST.NAME:CtrlTtIgnSts_valid_Cond
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtIgnSts:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.battery_status:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtIgnSts:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.battery_status:0
TEST.END

-- Test Case: lvsd_ON
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:InputProcess
TEST.NEW
TEST.NAME:lvsd_ON
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:1
TEST.VALUE:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_LVSD2Flag:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:1
TEST.EXPECTED:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_LVSD2Flag:1
TEST.END

-- Test Case: lvsd_on_ign_off
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:InputProcess
TEST.NEW
TEST.NAME:lvsd_on_ign_off
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:0
TEST.VALUE:Ctrl_Telltale_Extn.<<GLOBAL>>.Rte_PowerCdd_ppSR_PowerCdd_AVP_LVSD2Flag:1
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.CtrlTtIgnSts:0
TEST.EXPECTED:Ctrl_telltale.<<GLOBAL>>.battery_status:1
TEST.END

-- Subprogram: Process_Ctrl_Telltale

-- Test Case: ALL_Valid_Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:Process_Ctrl_Telltale
TEST.NEW
TEST.NAME:ALL_Valid_Testcase
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) for (index < (TT_ENUM_TYPE)23U) ==> TRUE
      (2) if (((tt_ctrl_ttconfig[index]).Operational_states & tt_state_byte) != 0U) ==> TRUE
      (3) if (255U == tt_ip_array[index]) ==> FALSE
      (4) if (battery_status != 1U) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #4, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 1
      Cannot set index due to assignment
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[0]:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[3]:cTT_CONFIGURED_OFF
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtIgnSts:1
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.battery_status:1
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=TT_TURN_ON
TEST.END

-- Test Case: ATT_R02_Configuration_cTT_CONFIGURED_OFF_Valid_Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:Process_Ctrl_Telltale
TEST.NEW
TEST.NAME:ATT_R02_Configuration_cTT_CONFIGURED_OFF_Valid_Testcase
TEST.MCDC_BASIS_PATH:6 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) for (index < (TT_ENUM_TYPE)23U) ==> TRUE
      (2) if (((tt_ctrl_ttconfig[index]).Operational_states & tt_state_byte) != 0U) ==> TRUE
      (3) if (255U == tt_ip_array[index]) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #3, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set index due to assignment
      Conflict: Unable to control expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[0]:cTT_CONFIGURED_OFF
TEST.END

-- Test Case: Battery_Status_Failure_Cond
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:Process_Ctrl_Telltale
TEST.NEW
TEST.NAME:Battery_Status_Failure_Cond
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) for (index < (TT_ENUM_TYPE)23U) ==> TRUE
      (2) if (((tt_ctrl_ttconfig[index]).Operational_states & tt_state_byte) != 0U) ==> TRUE
      (3) if (255U == tt_ip_array[index]) ==> FALSE
      (4) if (battery_status != 1U) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #4, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 1
      Cannot set index due to assignment
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[0]:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[3]:255
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtIgnSts:1
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.battery_status:0
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate:MACRO=TT_TURN_ON
TEST.END

-- Test Case: Battery_Status_Valid_Testcase
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:Process_Ctrl_Telltale
TEST.NEW
TEST.NAME:Battery_Status_Valid_Testcase
TEST.MCDC_BASIS_PATH:7 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) for (index < (TT_ENUM_TYPE)23U) ==> TRUE
      (2) if (((tt_ctrl_ttconfig[index]).Operational_states & tt_state_byte) != 0U) ==> TRUE
      (3) if (255U == tt_ip_array[index]) ==> FALSE
      (4) if (battery_status != 1U) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #4, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 1
      Cannot set index due to assignment
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.CtrlTtSts[0]:<<MIN>>
TEST.VALUE:Ctrl_telltale.<<GLOBAL>>.battery_status:TT_TURN_ON
TEST.END

-- Test Case: tt_ip_array_adapter_input_Cond
TEST.UNIT:Ctrl_telltale
TEST.SUBPROGRAM:Process_Ctrl_Telltale
TEST.NEW
TEST.NAME:tt_ip_array_adapter_input_Cond
TEST.MCDC_BASIS_PATH:1 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) for (index < (TT_ENUM_TYPE)23U) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #1, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to control expression-to-expression comparison in branch 1
TEST.END_NOTES:
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[0]:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[1]:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[2]:9
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[3]:5
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[4]:12
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[5]:15
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[6]:7
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[7]:13
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[8]:11
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[9]:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[10]:0
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[11]:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[12]:3
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[13]:5
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[14]:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[15]:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[16]:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[17]:2
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[18]:16
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[19]:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[20]:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[21]:2
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[22]:0
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_ADAS_pp_ADAS_TT_Status_CurrentTelltaleStatus:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_AHB_pp_AHB_TT_Status_CurrentTelltaleStatus:5
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Brake_Hold_Standby_pp_Brake_Hold_Standby_TT_Status_CurrentTelltaleStatus:7
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_EWTemp_pp_EWT_TT_Status_CurrentTelltaleStatus:0
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Frontfog_pp_FrontFog_TT_Status_CurrentTelltaleStatus:0
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CFuel_pp_Fuel_TT_Status_CurrentTelltaleStatus:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_HeadTailLight_pp_HeadTailLight_TT_Status_CurrentTelltaleStatus:2
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Hibeam_pp_Hibeam_TT_Status_CurrentTelltaleStatus:3
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Pcs_Off_pp_Pcs_Off_TT_Status_CurrentTelltaleStatus:5
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Ready_pp_Ready_TT_Status_CurrentTelltaleStatus:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Rearfog_pp_RearFog_TT_Status_CurrentTelltaleStatus:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CSeatBelt_pp_Seat_Belt_TT_Status_CurrentTelltaleStatus:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Tpms_pp_Tpms_TT_Status_CurrentTelltaleStatus:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CTurn_Hazard_pp_Turn_L_TT_Status_CurrentTelltaleStatus:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CTurn_Hazard_pp_Turn_R_TT_Status_CurrentTelltaleStatus:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Abs_pp_Abs_TT_Status_CurrentTelltaleStatus:1
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus:9
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_BRAKE_RED_pp_BRAKE_RED_TT_Status_CurrentTelltaleStatus:12
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Brake_Hold_pp_Brake_Hold_TT_Status_CurrentTelltaleStatus:15
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Brake_Yellow_pp_Brake_Yellow_TT_Status_CurrentTelltaleStatus:13
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Parking_Brake_pp_Praking_brake_TT_Status_CurrentTelltaleStatus:11
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Traction_Control_pp_Traction_Control_TT_Status_CurrentTelltaleStatus:16
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_VSC_OFF_pp_VSC_Off_TT_Status_CurrentTelltaleStatus:2
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[0]:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[1]:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[2]:9
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[3]:5
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[4]:12
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[5]:15
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[6]:7
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[7]:13
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[8]:11
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[9]:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[10]:0
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[11]:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[12]:3
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[13]:5
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[14]:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[15]:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[16]:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[17]:2
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[18]:16
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[19]:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[20]:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[21]:2
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[22]:0
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_ADAS_pp_ADAS_TT_Status_CurrentTelltaleStatus:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_AHB_pp_AHB_TT_Status_CurrentTelltaleStatus:5
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Brake_Hold_Standby_pp_Brake_Hold_Standby_TT_Status_CurrentTelltaleStatus:7
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_EWTemp_pp_EWT_TT_Status_CurrentTelltaleStatus:0
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Frontfog_pp_FrontFog_TT_Status_CurrentTelltaleStatus:0
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CFuel_pp_Fuel_TT_Status_CurrentTelltaleStatus:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_HeadTailLight_pp_HeadTailLight_TT_Status_CurrentTelltaleStatus:2
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Hibeam_pp_Hibeam_TT_Status_CurrentTelltaleStatus:3
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Pcs_Off_pp_Pcs_Off_TT_Status_CurrentTelltaleStatus:5
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Ready_pp_Ready_TT_Status_CurrentTelltaleStatus:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Rearfog_pp_RearFog_TT_Status_CurrentTelltaleStatus:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CSeatBelt_pp_Seat_Belt_TT_Status_CurrentTelltaleStatus:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Tpms_pp_Tpms_TT_Status_CurrentTelltaleStatus:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CTurn_Hazard_pp_Turn_L_TT_Status_CurrentTelltaleStatus:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CTurn_Hazard_pp_Turn_R_TT_Status_CurrentTelltaleStatus:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Abs_pp_Abs_TT_Status_CurrentTelltaleStatus:1
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus:9
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_BRAKE_RED_pp_BRAKE_RED_TT_Status_CurrentTelltaleStatus:12
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Brake_Hold_pp_Brake_Hold_TT_Status_CurrentTelltaleStatus:15
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Brake_Yellow_pp_Brake_Yellow_TT_Status_CurrentTelltaleStatus:13
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Parking_Brake_pp_Praking_brake_TT_Status_CurrentTelltaleStatus:11
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Traction_Control_pp_Traction_Control_TT_Status_CurrentTelltaleStatus:16
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_VSC_OFF_pp_VSC_Off_TT_Status_CurrentTelltaleStatus:2
TEST.END

-- Unit: Ctrl_telltale_adapter

-- Subprogram: Ctrl_telltale_Adapter_Task

-- Test Case: tt_ip_array_adapter_valid_Cond
TEST.UNIT:Ctrl_telltale_adapter
TEST.SUBPROGRAM:Ctrl_telltale_Adapter_Task
TEST.NEW
TEST.NAME:tt_ip_array_adapter_valid_Cond
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_ADAS_pp_ADAS_TT_Status_CurrentTelltaleStatus:MACRO=TT_TURN_ON
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_AHB_pp_AHB_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Brake_Hold_Standby_pp_Brake_Hold_Standby_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_1HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_EWTemp_pp_EWT_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Frontfog_pp_FrontFog_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_2_5_HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CFuel_pp_Fuel_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_2HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_HeadTailLight_pp_HeadTailLight_TT_Status_CurrentTelltaleStatus:MACRO=TT_TURN_OFF
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Hibeam_pp_Hibeam_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_TRNHZ_Normal
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Pcs_Off_pp_Pcs_Off_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_TRNHZ_Fast
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Ready_pp_Ready_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_TRNHZ_FHL
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Rearfog_pp_RearFog_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_4HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CSeatBelt_pp_Seat_Belt_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_5HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Tpms_pp_Tpms_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_2_66_HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CTurn_Hazard_pp_Turn_L_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_HALF_HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_CTurn_Hazard_pp_Turn_R_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Abs_pp_Abs_TT_Status_CurrentTelltaleStatus:MACRO=TT_TURN_OFF
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_QUARTER_HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_BRAKE_RED_pp_BRAKE_RED_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_CSNR_HALF_HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Brake_Hold_pp_Brake_Hold_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_0_83_HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Brake_Yellow_pp_Brake_Yellow_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_1_33_HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Parking_Brake_pp_Praking_brake_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_1_66_HZ
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_Traction_Control_pp_Traction_Control_TT_Status_CurrentTelltaleStatus:MACRO=TT_TURN_ON
TEST.VALUE:Ctrl_telltale_adapter.<<GLOBAL>>.Rte_Mdl_VSC_OFF_pp_VSC_Off_TT_Status_CurrentTelltaleStatus:MACRO=TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[0]:MACRO=TT_TURN_OFF
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[1]:MACRO=TT_TURN_ON
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[2]:MACRO=TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[3]:MACRO=TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[4]:MACRO=TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[5]:MACRO=TT_FLASH_0_83_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[6]:MACRO=TT_FLASH_1HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[7]:MACRO=TT_FLASH_1_33_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[8]:MACRO=TT_FLASH_1_66_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[9]:MACRO=TT_FLASH_2HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[10]:MACRO=TT_FLASH_2_5_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[11]:MACRO=TT_FLASH_2_66_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[12]:MACRO=TT_FLASH_TRNHZ_Normal
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[13]:MACRO=TT_FLASH_TRNHZ_Fast
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[14]:MACRO=TT_FLASH_TRNHZ_FHL
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[15]:MACRO=TT_FLASH_4HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[16]:MACRO=TT_FLASH_5HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[17]:MACRO=TT_TURN_OFF
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[18]:MACRO=TT_TURN_ON
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[19]:MACRO=TT_FLASH_QUARTER_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[20]:MACRO=TT_FLASH_HALF_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[21]:MACRO=TT_FLASH_CSNR_HALF_HZ
TEST.EXPECTED:Ctrl_telltale_adapter.<<GLOBAL>>.tt_ip_array_adapter[22]:MACRO=TT_FLASH_0_83_HZ
TEST.END
