-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UTP_SIGUNIT_BSPAL
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

-- Test Case: dk_bspal_sigunit_eval_win_setup_MAX.001
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_setup
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_setup_MAX.001
TEST.VALUE:<<ALL_MAX>>
TEST.STUB:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.return:-1
TEST.END

-- Test Case: dk_bspal_sigunit_eval_win_setup_MAX.002
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_setup
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_setup_MAX.002
TEST.VALUE:<<ALL_MAX>>
TEST.STUB:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.return:0
TEST.VALUE:uut_prototype_stubs.ioctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_setup.return:0
TEST.END

-- Subprogram: dk_bspal_sigunit_eval_win_start

-- Test Case: dk_bspal_sigunit_eval_win_start.001
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_start
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_start.001
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_start.return:0
TEST.VALUE:uut_prototype_stubs.ioctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_start.return:0
TEST.END

-- Test Case: dk_bspal_sigunit_eval_win_start.002
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_start
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_start.002
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_start.return:-1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_start.return:-1
TEST.END

-- Subprogram: dk_bspal_sigunit_eval_win_stop

-- Test Case: dk_bspal_sigunit_eval_win_stop.001
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_stop
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_stop.001
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_stop.return:0
TEST.VALUE:uut_prototype_stubs.ioctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_stop.return:0
TEST.END

-- Test Case: dk_bspal_sigunit_eval_win_stop.002
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_eval_win_stop
TEST.NEW
TEST.NAME:dk_bspal_sigunit_eval_win_stop.002
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_stop.return:-1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_eval_win_stop.return:-1
TEST.END

-- Subprogram: dk_bspal_sigunit_get_win_crc_sts

-- Test Case: dk_bspal_sigunit_get_win_crc_sts.001
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_get_win_crc_sts
TEST.NEW
TEST.NAME:dk_bspal_sigunit_get_win_crc_sts.001
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.red_U32:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.green_U32:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.blue_U32:0
TEST.VALUE:uut_prototype_stubs.ioctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.red_U32:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.green_U32:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.blue_U32:0
TEST.END

-- Test Case: dk_bspal_sigunit_get_win_crc_sts.002
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_get_win_crc_sts
TEST.NEW
TEST.NAME:dk_bspal_sigunit_get_win_crc_sts.002
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.red_U32:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.green_U32:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.blue_U32:0
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.red_U32:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.green_U32:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_get_win_crc_sts.return.crc.blue_U32:0
TEST.END

-- Subprogram: dk_bspal_sigunit_initialize

-- Test Case: dk_bspal_sigunit_initialize.001
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_initialize
TEST.NEW
TEST.NAME:dk_bspal_sigunit_initialize.001
TEST.STUB:CSigUnit_DK_BSPAL.sigunit_open
TEST.VALUE:CSigUnit_DK_BSPAL.sigunit_open.return:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.return:0
TEST.VALUE:uut_prototype_stubs.ioctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.return:0
TEST.END

-- Test Case: dk_bspal_sigunit_initialize.002
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_initialize
TEST.NEW
TEST.NAME:dk_bspal_sigunit_initialize.002
TEST.STUB:CSigUnit_DK_BSPAL.sigunit_open
TEST.VALUE:CSigUnit_DK_BSPAL.sigunit_open.return:-1
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.return:-1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.return:-1
TEST.END

-- Test Case: dk_bspal_sigunit_initialize.003
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_initialize
TEST.NEW
TEST.NAME:dk_bspal_sigunit_initialize.003
TEST.STUB:CSigUnit_DK_BSPAL.sigunit_open
TEST.VALUE:CSigUnit_DK_BSPAL.sigunit_open.return:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.return:-1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_initialize.return:-1
TEST.END

-- Subprogram: dk_bspal_sigunit_shutdown

-- Test Case: dk_bspal_sigunit_shutdown.001
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_shutdown
TEST.NEW
TEST.NAME:dk_bspal_sigunit_shutdown.001
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_shutdown.return:0
TEST.VALUE:uut_prototype_stubs.ioctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_shutdown.return:0
TEST.END

-- Test Case: dk_bspal_sigunit_shutdown.002
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:dk_bspal_sigunit_shutdown
TEST.NEW
TEST.NAME:dk_bspal_sigunit_shutdown.002
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_shutdown.return:-1
TEST.VALUE:uut_prototype_stubs.ioctl.return:-1
TEST.EXPECTED:CSigUnit_DK_BSPAL.dk_bspal_sigunit_shutdown.return:-1
TEST.END

-- Subprogram: sigunit_close

-- Test Case: sigunit_close.001
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:sigunit_close
TEST.NEW
TEST.NAME:sigunit_close.001
TEST.VALUE:CSigUnit_DK_BSPAL.sigunit_close.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.sigunit_close.return:0
TEST.END

-- Test Case: sigunit_close.002
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:sigunit_close
TEST.NEW
TEST.NAME:sigunit_close.002
TEST.STUB:CSigUnit_DK_BSPAL.dk_bspal_sigunit_shutdown
TEST.VALUE:CSigUnit_DK_BSPAL.<<GLOBAL>>.sig_fd:-1
TEST.VALUE:CSigUnit_DK_BSPAL.sigunit_close.return:0
TEST.VALUE:CSigUnit_DK_BSPAL.dk_bspal_sigunit_shutdown.return:-1
TEST.EXPECTED:CSigUnit_DK_BSPAL.sigunit_close.return:0
TEST.END

-- Subprogram: sigunit_open

-- Test Case: sigunit_open.001
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:sigunit_open
TEST.NEW
TEST.NAME:sigunit_open.001
TEST.VALUE:CSigUnit_DK_BSPAL.<<GLOBAL>>.sig_fd:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.<<GLOBAL>>.sig_fd:0
TEST.END

-- Test Case: sigunit_open.002
TEST.UNIT:CSigUnit_DK_BSPAL
TEST.SUBPROGRAM:sigunit_open
TEST.NEW
TEST.NAME:sigunit_open.002
TEST.VALUE:CSigUnit_DK_BSPAL.sigunit_open.sig_unit_id:0
TEST.VALUE:CSigUnit_DK_BSPAL.sigunit_open.return:-1
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.VALUE:uut_prototype_stubs.dk_Logger_registerContext.logLevel:DLT_LOG_ERROR
TEST.VALUE:uut_prototype_stubs.dk_Logger_log.logLevel:DLT_LOG_ERROR
TEST.VALUE:uut_prototype_stubs.ioctl.return:0
TEST.EXPECTED:CSigUnit_DK_BSPAL.sigunit_open.return:-1
TEST.END
