-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : SIGCDD_TISITARA_UT
-- Unit(s) Under Test: SigCdd SigIfCdd SigMgrCdd
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: SigCdd

-- Subprogram: CSigCdd_Impl_sig_get_win_crc_data

-- Test Case: 1_get_crc
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CSigCdd_Impl_sig_get_win_crc_data
TEST.NEW
TEST.NAME:1_get_crc
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0xABCDEF
TEST.VALUE:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.AddrTranslateP_getLocalAddr.return:VECTORCAST_INT1
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.EXPECTED:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0xABCDEF
TEST.END

-- Subprogram: CmpActivation

-- Test Case: 1_cmp_activation
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:1_cmp_activation
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:1
TEST.EXPECTED:SigCdd.CmpActivation.return:1
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkMode:1
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.regionId:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkMode:1
TEST.END

-- Subprogram: CmpActive

-- Test Case: 1_cmp_active
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:1_cmp_active
TEST.EXPECTED:SigCdd.CmpActive.return:1
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: 1_cmp_deactivation
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:1_cmp_deactivation
TEST.EXPECTED:SigCdd.CmpDeActivation.return:1
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: 1_cmp_deinit
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:1_cmp_deinit
TEST.EXPECTED:SigCdd.CmpDeInit.return:1
TEST.END

-- Subprogram: CmpDiag

-- Test Case: 1_cmp_diag
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:1_cmp_diag
TEST.EXPECTED:SigCdd.CmpDiag.return:1
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: 1_cmp_diag_return
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:1_cmp_diag_return
TEST.EXPECTED:SigCdd.CmpDiagReturn.return:1
TEST.END

-- Subprogram: CmpInit

-- Test Case: 1_cmp_init
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:1_cmp_init
TEST.EXPECTED:SigCdd.CmpInit.return:1
TEST.END

-- Unit: SigIfCdd

-- Subprogram: SigIf_sig_deinit

-- Test Case: 1_sig_if_deinit_success
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_deinit
TEST.NEW
TEST.NAME:1_sig_if_deinit_success
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:1
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:0
TEST.END

-- Subprogram: SigIf_sig_set_ev_window

-- Test Case: 10_set_config_num_test_pipe_invalid
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:10_set_config_num_test_pipe_invalid
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:3
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[0]:0
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[1]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0..1]:1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0x11
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].ref_crc:0xABCDEF
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.width:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.height:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.referenceSign:0x0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.safetyChkCfg.regionSize.width:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.safetyChkCfg.regionSize.height:0
TEST.END

-- Test Case: 1_set_config_pipe0
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:1_set_config_pipe0
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[0]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0x21
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].ref_crc:0xABCDEF
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.referenceSign:0xABCDEF
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:1
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.width:72
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.height:72
TEST.END

-- Test Case: 2_set_config_vp_win0
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:2_set_config_vp_win0
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[0]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0x31
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].ref_crc:0xABCDEF
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.regionId:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.referenceSign:0xABCDEF
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:1
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.width:72
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.height:72
TEST.END

-- Test Case: 3_set_config_pipe_invalid
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:3_set_config_pipe_invalid
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[0]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0x11
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].ref_crc:0xABCDEF
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.referenceSign:0x0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.width:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.height:0
TEST.END

-- Test Case: 4_set_config_pipe1
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:4_set_config_pipe1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:2
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[0]:0
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[1]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0..1]:1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0x21
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].ref_crc:0xABCDEF
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.width:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.height:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.referenceSign:0xABCDEF
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.safetyChkCfg.safetyChkEnable:1
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.safetyChkCfg.regionSize.width:72
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[1].safetyParams.safetyChkCfg.regionSize.height:72
TEST.ATTRIBUTES:SigIfCdd.<<GLOBAL>>.gDssObjects.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.referenceSign:EXPECTED_BASE=16
TEST.END

-- Test Case: 5_reset_config_vp_win0
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:5_reset_config_vp_win0
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[0]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0x30
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].ref_crc:0xABCDEF
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.regionId:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.referenceSign:0x0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.width:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.height:0
TEST.END

-- Test Case: 6_reset_config_pipe0
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:6_reset_config_pipe0
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[0]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0x20
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].ref_crc:0xABCDEF
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.referenceSign:0x0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.width:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.height:0
TEST.END

-- Test Case: 7_safety_check_disabled_pipe0
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:7_safety_check_disabled_pipe0
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[0]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0x21
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:72
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].ref_crc:0xABCDEF
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.referenceSign:0x0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.width:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.height:0
TEST.END

-- Test Case: 8_set_config_pipe0_invalid_dimensions
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:8_set_config_pipe0_invalid_dimensions
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[0]:0
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0x11
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].ref_crc:0xABCDEF
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.referenceSign:0xABCDEF
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:1
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.width:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.height:0
TEST.END

-- Test Case: 9_set_config_vp_win0_invalid_dimensions
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:9_set_config_vp_win0_invalid_dimensions
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.pipeId[0]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0x31
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].ref_crc:0xABCDEF
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.regionId:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.referenceSign:0xABCDEF
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:1
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.width:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.height:0
TEST.END

-- Subprogram: SigIf_sig_setup_win

-- Test Case: 1_invalid_vp_win_id
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:1_invalid_vp_win_id
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].control:0x21
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winsx:10
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winsy:10
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winex:30
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winey:30
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:CONFIG_DSS_NUM_SAFETY_REGIONS
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:0
TEST.END

-- Test Case: 2_invalid_win_type
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:2_invalid_win_type
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].control:0x31
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winsx:10
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winsy:10
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winex:30
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winey:30
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:CONFIG_DSS_NUM_SAFETY_REGIONS
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:0
TEST.END

-- Subprogram: SigIf_sig_stop_evaluation

-- Test Case: 1_pipeline_safety_check_disabled
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_stop_evaluation
TEST.NEW
TEST.NAME:1_pipeline_safety_check_disabled
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:0
TEST.VALUE:SigIfCdd.SigIf_sig_stop_evaluation.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.END

-- Test Case: 2_pipeline_safety_win_eval_disabled
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_stop_evaluation
TEST.NEW
TEST.NAME:2_pipeline_safety_win_eval_disabled
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.VALUE:SigIfCdd.SigIf_sig_stop_evaluation.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.END

-- Unit: SigMgrCdd

-- Subprogram: SigMgr_sig_deinit

-- Test Case: 1_sig_mgr_deinit
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_deinit
TEST.NEW
TEST.NAME:1_sig_mgr_deinit
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.EXPECTED:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.END

-- Subprogram: SigMgr_sig_get_win_crc_data

-- Test Case: 1_get_vp_win2_crc
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:1_get_vp_win2_crc
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0xABCDEF
TEST.VALUE:uut_prototype_stubs.AddrTranslateP_getLocalAddr.return:VECTORCAST_INT1
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:2
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.AddrTranslateP_getLocalAddr.systemAddr:0x3020A098
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0xABCDEF
TEST.END

-- Test Case: 2_get_vp_win3_crc
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:2_get_vp_win3_crc
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0xABCDEF
TEST.VALUE:uut_prototype_stubs.AddrTranslateP_getLocalAddr.return:VECTORCAST_INT1
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:3
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.AddrTranslateP_getLocalAddr.systemAddr:0x3020A09C
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0xABCDEF
TEST.END

-- Test Case: 3_win_info_ptr_is_invalid
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:3_win_info_ptr_is_invalid
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<null>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Test Case: 4_sig_unit_id_is_invalid
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:4_sig_unit_id_is_invalid
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:MAX_SIG_UNITS
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Test Case: 5_win_id_is_invalid
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:5_win_id_is_invalid
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:MAX_WINDOWS
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Test Case: 6_get_vp_win0_crc
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:6_get_vp_win0_crc
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0xABCDEF
TEST.VALUE:uut_prototype_stubs.AddrTranslateP_getLocalAddr.return:VECTORCAST_INT1
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.AddrTranslateP_getLocalAddr.systemAddr:0x3020A090
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0xABCDEF
TEST.END

-- Test Case: 7_crc_ptr_is_null
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:7_crc_ptr_is_null
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<null>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Test Case: 8_get_vp_win1_crc
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:8_get_vp_win1_crc
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0xABCDEF
TEST.VALUE:uut_prototype_stubs.AddrTranslateP_getLocalAddr.return:VECTORCAST_INT1
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.AddrTranslateP_getLocalAddr.systemAddr:0x3020A094
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0xABCDEF
TEST.END

-- Test Case: 9_eval_is_not_enabled
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:9_eval_is_not_enabled
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.EXPECTED:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.END

-- Subprogram: SigMgr_sig_init

-- Test Case: 1_sig_mgr_init
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_init
TEST.NEW
TEST.NAME:1_sig_mgr_init
TEST.EXPECTED:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.END

-- Test Case: 2_safety_check_pipe_disabled
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_init
TEST.NEW
TEST.NAME:2_safety_check_pipe_disabled
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetySignSeedVal:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.referenceSign:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkMode:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.seedSelectEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.thresholdValue:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.frameSkip:0
TEST.EXPECTED:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.END

-- Subprogram: SigMgr_sig_reset_config

-- Test Case: 1_reset_config
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_reset_config
TEST.NEW
TEST.NAME:1_reset_config
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].control:0x11
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winsx:2
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winsy:3
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winex:4
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winey:5
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].ref_crc:6
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].control:0x0
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winsx:0
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winsy:0
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winex:0
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winey:0
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].ref_crc:0
TEST.END

-- Subprogram: SigMgr_sig_stop_evaluation

-- Test Case: 1_stop_eval_sig0
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_stop_evaluation
TEST.NEW
TEST.NAME:1_stop_eval_sig0
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.numTestPipes:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssConfigPipelineParams.safetyCheck[0]:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.referenceSign:0xABCDEF
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startX:12
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startY:12
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.width:72
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.height:72
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.referenceSign:0xABCDEEF
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:1
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startX:12
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startY:12
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.width:72
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.height:72
TEST.VALUE:SigMgrCdd.SigMgr_sig_stop_evaluation.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.referenceSign:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.width:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].instObj[0].safetyParams.safetyChkCfg.regionSize.height:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.referenceSign:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.width:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.height:0
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_stop_evaluation.return:1
TEST.END

-- Test Case: 2_invalid_sig_unit_id
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_stop_evaluation
TEST.NEW
TEST.NAME:2_invalid_sig_unit_id
TEST.VALUE:SigMgrCdd.SigMgr_sig_stop_evaluation.p_sig_unit:MAX_SIG_UNITS
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_stop_evaluation.return:0
TEST.END

-- Subprogram: SigMgr_sig_task

-- Test Case: 1_new_config_ready
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_task
TEST.NEW
TEST.NAME:1_new_config_ready
TEST.VALUE:uut_prototype_stubs.Rte_Read_rp_SigData_sig0_vp_win0.data[0].control:0x31
TEST.VALUE:uut_prototype_stubs.Rte_Read_rp_SigData_sig0_vp_win0.data[0].winsx:0
TEST.VALUE:uut_prototype_stubs.Rte_Read_rp_SigData_sig0_vp_win0.data[0].winsy:0
TEST.VALUE:uut_prototype_stubs.Rte_Read_rp_SigData_sig0_vp_win0.data[0].winex:72
TEST.VALUE:uut_prototype_stubs.Rte_Read_rp_SigData_sig0_vp_win0.data[0].winey:72
TEST.VALUE:uut_prototype_stubs.Rte_Read_rp_SigData_sig0_vp_win0.data[0].ref_crc:0xDEADBEEF
TEST.VALUE:uut_prototype_stubs.GetEvent.p_task_index:0
TEST.VALUE:uut_prototype_stubs.GetEvent.p_event_out_val[0]:64
TEST.EXPECTED:uut_prototype_stubs.GetEvent.p_task_index:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.regionId:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.referenceSign:0xDEADBEEF
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:1
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startX:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionPos.startY:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.width:72
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.regionSize.height:72
TEST.END

-- Test Case: 2_no_new_config_available
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_task
TEST.NEW
TEST.NAME:2_no_new_config_available
TEST.VALUE:uut_prototype_stubs.GetEvent.p_task_index:0
TEST.VALUE:uut_prototype_stubs.GetEvent.p_event_out_val:"0"
TEST.VALUE:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:0
TEST.EXPECTED:uut_prototype_stubs.GetEvent.p_task_index:0
TEST.EXPECTED:SigIfCdd.<<GLOBAL>>.gDssObjects[0].vpSafetyParams[0].regionSafetyChkCfg.safetyChkCfg.safetyChkEnable:0
TEST.END
