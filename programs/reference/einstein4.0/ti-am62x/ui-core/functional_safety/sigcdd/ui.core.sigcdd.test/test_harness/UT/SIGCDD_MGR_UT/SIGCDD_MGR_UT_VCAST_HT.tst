-- VectorCAST 6.4s (05/01/17)
-- Test Case Script
-- 
-- Environment    : SIGCDD_MGR_UT_VCAST_HT
-- Unit(s) Under Test: SigMgrCdd
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: SigMgr_sig_deinit

-- Test Case: SigMgr_sig_deinit.001
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_deinit
TEST.NEW
TEST.NAME:SigMgr_sig_deinit.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.EXPECTED:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.END

-- Subprogram: SigMgr_sig_get_win_crc_data

-- Test Case: SigMgr_sig_get_win_crc_data.001
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_crc_data.001
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.EXPECTED:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.ATTRIBUTES:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:INPUT_BASE=16
TEST.ATTRIBUTES:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:INPUT_BASE=16
TEST.ATTRIBUTES:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:INPUT_BASE=16
TEST.END

-- Test Case: SigMgr_sig_get_win_crc_data.002
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_crc_data.002
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.EXPECTED:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.END

-- Test Case: SigMgr_sig_get_win_crc_data.003
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_crc_data.003
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Test Case: SigMgr_sig_get_win_crc_data.004
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_crc_data.004
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Test Case: SigMgr_sig_get_win_crc_data.005
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_crc_data.005
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Test Case: SigMgr_sig_get_win_crc_data.006
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_crc_data.006
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Test Case: SigMgr_sig_get_win_crc_data.007
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_crc_data.007
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Test Case: SigMgr_sig_get_win_crc_data.008
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_crc_data.008
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Test Case: SigMgr_sig_get_win_crc_data.009
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_crc_data.009
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:3
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Test Case: SigMgr_sig_get_win_crc_data.010
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_crc_data.010
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:1
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_info[0].window:9
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Subprogram: SigMgr_sig_get_win_status

-- Test Case: SigMgr_sig_get_win_status.001
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_status
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_status.001
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_status.p_sw_info[0].window:0
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_get_win_status.return:0
TEST.END

-- Test Case: SigMgr_sig_get_win_status.002
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_status
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_status.002
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_get_win_status.return:0
TEST.END

-- Test Case: SigMgr_sig_get_win_status.003
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_status
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_status.003
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_status.p_sw_info[0].sig_unit:3
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_status.p_sw_info[0].window:0
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_get_win_status.return:0
TEST.END

-- Test Case: SigMgr_sig_get_win_status.004
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_get_win_status
TEST.NEW
TEST.NAME:SigMgr_sig_get_win_status.004
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_get_win_status.p_sw_info[0].window:9
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_get_win_status.return:0
TEST.END

-- Subprogram: SigMgr_sig_init

-- Test Case: SigMgr_sig_init.001
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_init
TEST.NEW
TEST.NAME:SigMgr_sig_init.001
TEST.EXPECTED:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.EXPECTED:SigMgrCdd.<<GLOBAL>>.l_sig0_prev_win_status:0
TEST.END

-- Subprogram: SigMgr_sig_reset_config

-- Test Case: SigMgr_sig_reset_config.001
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_reset_config
TEST.NEW
TEST.NAME:SigMgr_sig_reset_config.001
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_eval_is_enabled:0
TEST.VALUE:SigMgrCdd.<<GLOBAL>>.l_sig0_prev_win_status:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow:<<malloc 1>>
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].control:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winsx:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winsy:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winex:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].winey:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].crc_ref_r:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].crc_ref_g:0
TEST.VALUE:SigMgrCdd.SigMgr_sig_reset_config.p_EvWindow[0].crc_ref_b:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.END

-- Subprogram: SigMgr_sig_stop_evaluation

-- Test Case: SigMgr_sig_stop_evaluation.001
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_stop_evaluation
TEST.NEW
TEST.NAME:SigMgr_sig_stop_evaluation.001
TEST.VALUE:SigMgrCdd.SigMgr_sig_stop_evaluation.p_sig_unit:0
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_stop_evaluation.return:1
TEST.END

-- Test Case: SigMgr_sig_stop_evaluation.002
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_stop_evaluation
TEST.NEW
TEST.NAME:SigMgr_sig_stop_evaluation.002
TEST.VALUE:SigMgrCdd.SigMgr_sig_stop_evaluation.p_sig_unit:1
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_stop_evaluation.return:1
TEST.END

-- Test Case: SigMgr_sig_stop_evaluation.003
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_stop_evaluation
TEST.NEW
TEST.NAME:SigMgr_sig_stop_evaluation.003
TEST.VALUE:SigMgrCdd.SigMgr_sig_stop_evaluation.p_sig_unit:3
TEST.EXPECTED:SigMgrCdd.SigMgr_sig_stop_evaluation.return:0
TEST.END

-- Subprogram: SigMgr_sig_task

-- Test Case: SigMgr_sig_task.001
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_task
TEST.NEW
TEST.NAME:SigMgr_sig_task.001
TEST.VALUE:uut_prototype_stubs.GetEvent.p_task_index:0
TEST.VALUE:uut_prototype_stubs.GetEvent.p_event_out_val:"1"
TEST.EXPECTED:uut_prototype_stubs.GetEvent.p_task_index:0
TEST.END

-- Test Case: SigMgr_sig_task.002
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_task
TEST.NEW
TEST.NAME:SigMgr_sig_task.002
TEST.VALUE:uut_prototype_stubs.GetEvent.p_task_index:0
TEST.VALUE:uut_prototype_stubs.GetEvent.p_event_out_val:"0"
TEST.EXPECTED:uut_prototype_stubs.GetEvent.p_task_index:0
TEST.END

-- Test Case: SigMgr_sig_task.003
TEST.UNIT:SigMgrCdd
TEST.SUBPROGRAM:SigMgr_sig_task
TEST.NEW
TEST.NAME:SigMgr_sig_task.003
TEST.VALUE:uut_prototype_stubs.GetEvent.p_task_index:0
TEST.VALUE:uut_prototype_stubs.GetEvent.p_event_out_val:"1"
TEST.VALUE:uut_prototype_stubs.SigIf_sig_get_windows_status.p_sig_unit:0
TEST.VALUE:uut_prototype_stubs.SigIf_sig_get_windows_status.return:1
TEST.EXPECTED:uut_prototype_stubs.GetEvent.p_task_index:0
TEST.END
