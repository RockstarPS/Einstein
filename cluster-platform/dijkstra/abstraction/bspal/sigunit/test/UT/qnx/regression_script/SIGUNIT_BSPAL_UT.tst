-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : SIGUNIT_BSPAL_UT
-- Unit(s) Under Test: CSigUnit_DK_BSPAL
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: dk_bspal_sigunit_eval_win_setup

-- Test Case: dk_bspal_sigunit_eval_win_setup_devctlfail1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_setup
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_setup_devctlfail1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.win_id:1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].eval_win_id_U8:1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].upperleft_x_U16:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].upperleft_y_U16:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].lowerright_x_U16:90
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].lowerright_y_U16:90
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].alpha_U8:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].action_U8:1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].ref_crc.red_U32:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].ref_crc.green_U32:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].ref_crc.blue_U32:0
TEST.VALUE:uut_prototype_stubs.devctl.return:22
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.return:-1
TEST.END

-- Test Case: dk_bspal_sigunit_eval_win_setup_devctlsuccess1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_setup
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_setup_devctlsuccess1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.win_id:1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].eval_win_id_U8:1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].upperleft_x_U16:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].upperleft_y_U16:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].lowerright_x_U16:90
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].lowerright_y_U16:90
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].alpha_U8:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].action_U8:1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].ref_crc.red_U32:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].ref_crc.green_U32:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.p_swconf_SP[0].ref_crc.blue_U32:0
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.return:0
TEST.END

-- Subprogram: dk_bspal_sigunit_eval_win_start

-- Test Case: dk_bspal_sigunit_eval_win_start_devctlfail1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_start
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_start_devctlfail1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_start.eval_win_id:1
TEST.VALUE:uut_prototype_stubs.devctl.return:22
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_start.return:-1
TEST.END

-- Test Case: dk_bspal_sigunit_eval_win_start_devctlsuccess1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_start
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_start_devctlsuccess1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_start.eval_win_id:1
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_start.return:0
TEST.END

-- Subprogram: dk_bspal_sigunit_eval_win_stop

-- Test Case: dk_bspal_sigunit_eval_win_stop_devctlfail1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_stop
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_stop_devctlfail1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_stop.eval_win_id:1
TEST.VALUE:uut_prototype_stubs.devctl.return:22
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_stop.return:-1
TEST.END

-- Test Case: dk_bspal_sigunit_eval_win_stop_devctlfail2
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_stop
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_stop_devctlfail2
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_stop.eval_win_id:1
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_stop.return:0
TEST.END

-- Subprogram: dk_bspal_sigunit_get_win_crc_sts

-- Test Case: dk_bspal_sigunit_get_win_crc_sts_devctlfail1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_get_win_crc_sts
TEST.NEW
TEST.NAME:dk_bspal_sigunit_get_win_crc_sts_devctlfail1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.eval_win_id:1
TEST.VALUE:uut_prototype_stubs.devctl.return:22
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.eval_win_id:1
TEST.END

-- Test Case: dk_bspal_sigunit_get_win_crc_sts_devctlsuccess1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_get_win_crc_sts
TEST.NEW
TEST.NAME:dk_bspal_sigunit_get_win_crc_sts_devctlsuccess1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.eval_win_id:1
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.eval_win_id:1
TEST.END

-- Subprogram: dk_bspal_sigunit_initialize

-- Test Case: dk_bspal_sigunit_initialize_devctlfail2
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_initialize
TEST.NEW
TEST.NAME:dk_bspal_sigunit_initialize_devctlfail2
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.sig_unit_id:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP[0].error_threshold_U8:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP[0].reset_threshold_U8:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP[0].panic_rgba_U32:128
TEST.VALUE:uut_prototype_stubs.devctl.return:22
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.return:-1
TEST.END

-- Test Case: dk_bspal_sigunit_initialize_sigunit_openfaiil1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_initialize
TEST.NEW
TEST.NAME:dk_bspal_sigunit_initialize_sigunit_openfaiil1
TEST.STUB:CSigUnit_DK_BSPAL.sigunit_open
TEST.VALUE:CSigUnit_DK_BSPAL.sigunit_open.return:-1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.sig_unit_id:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP[0].error_threshold_U8:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP[0].reset_threshold_U8:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP[0].panic_rgba_U32:128
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.return:-1
TEST.END

-- Test Case: dk_bspal_sigunit_initialize_success1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_initialize
TEST.NEW
TEST.NAME:dk_bspal_sigunit_initialize_success1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.sig_unit_id:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP[0].error_threshold_U8:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP[0].reset_threshold_U8:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.p_sig_cfg_SP[0].panic_rgba_U32:128
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.return:0
TEST.END

-- Subprogram: dk_bspal_sigunit_shutdown

-- Test Case: dk_bspal_sigunit_shutdow_devctlsuccess1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_shutdown
TEST.NEW
TEST.NAME:dk_bspal_sigunit_shutdow_devctlsuccess1
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_shutdown.return:0
TEST.END

-- Test Case: dk_bspal_sigunit_shutdown_devctlfail1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_shutdown
TEST.NEW
TEST.NAME:dk_bspal_sigunit_shutdown_devctlfail1
TEST.VALUE:uut_prototype_stubs.devctl.return:22
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_shutdown.return:-1
TEST.END

-- Subprogram: sigunit_close

-- Test Case: sigunit_close_fail1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:sigunit_close
TEST.NEW
TEST.NAME:sigunit_close_fail1
TEST.VALUE:uut_prototype_stubs.close.return:-1
TEST.EXPECTED:CSigUnit_DK_BSPAL.sigunit_close.return:0
TEST.END

-- Test Case: sigunit_close_success1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:sigunit_close
TEST.NEW
TEST.NAME:sigunit_close_success1
TEST.VALUE:uut_prototype_stubs.close.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.sigunit_close.return:0
TEST.END

-- Subprogram: sigunit_open

-- Test Case: sigunit_open_openfail2
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:sigunit_open
TEST.NEW
TEST.NAME:sigunit_open_openfail2
TEST.VALUE:CSigUnit_DK_BSPAL.sigunit_open.sig_unit_id:0
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:CSigUnit_DK_BSPAL.sigunit_open.return:-1
TEST.END

-- Test Case: sigunit_open_success1
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:sigunit_open
TEST.NEW
TEST.NAME:sigunit_open_success1
TEST.VALUE:CSigUnit_DK_BSPAL.sigunit_open.sig_unit_id:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.sigunit_open.return:0
TEST.END
