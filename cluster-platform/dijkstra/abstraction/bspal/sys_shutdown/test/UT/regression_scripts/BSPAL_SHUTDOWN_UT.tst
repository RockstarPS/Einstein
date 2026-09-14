-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : BSPAL_SHUTDOWN_UT
-- Unit(s) Under Test: imx_sys_shutdown qnx_sys_shutdown
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: imx_sys_shutdown

-- Subprogram: board_pre_shutdown

-- Test Case: Open_Fail
TEST.UNIT:imx_sys_shutdown
TEST.SUBPROGRAM:board_pre_shutdown
TEST.NEW
TEST.NAME:Open_Fail
TEST.NOTES:
Requirement_AU29610-147157
TEST.END_NOTES:
TEST.VALUE:imx_sys_shutdown.board_pre_shutdown.p_type_S32:3
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:imx_sys_shutdown.board_pre_shutdown.p_type_S32:3
TEST.END

-- Test Case: Open__Pass
TEST.UNIT:imx_sys_shutdown
TEST.SUBPROGRAM:board_pre_shutdown
TEST.NEW
TEST.NAME:Open__Pass
TEST.NOTES:
Requirement_AU29610-147157
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.close
TEST.VALUE:imx_sys_shutdown.board_pre_shutdown.p_type_S32:3
TEST.VALUE:uut_prototype_stubs.close.return:1
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.delay.return:1
TEST.VALUE:uut_prototype_stubs.devctl.return:11
TEST.EXPECTED:imx_sys_shutdown.board_pre_shutdown.p_type_S32:3
TEST.END

-- Test Case: wdg_failed_to_stop
TEST.UNIT:imx_sys_shutdown
TEST.SUBPROGRAM:board_pre_shutdown
TEST.NEW
TEST.NAME:wdg_failed_to_stop
TEST.NOTES:
Requirement_AU29610-147157
TEST.END_NOTES:
TEST.VALUE:imx_sys_shutdown.board_pre_shutdown.p_type_S32:3
TEST.VALUE:uut_prototype_stubs.devctl.return:11
TEST.EXPECTED:imx_sys_shutdown.board_pre_shutdown.p_type_S32:3
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.open.return
<<uut_prototype_stubs.open.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: wdg_stop_passed
TEST.UNIT:imx_sys_shutdown
TEST.SUBPROGRAM:board_pre_shutdown
TEST.NEW
TEST.NAME:wdg_stop_passed
TEST.NOTES:
Requirement_AU29610-147157
TEST.END_NOTES:
TEST.VALUE:imx_sys_shutdown.board_pre_shutdown.p_type_S32:3
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:imx_sys_shutdown.board_pre_shutdown.p_type_S32:3
TEST.END

-- Subprogram: save_reset_info_to_nv

-- Test Case: Reson_!=_NULL
TEST.UNIT:imx_sys_shutdown
TEST.SUBPROGRAM:save_reset_info_to_nv
TEST.NEW
TEST.NAME:Reson_!=_NULL
TEST.NOTES:
Requirement_AU29610-147157
TEST.END_NOTES:
TEST.VALUE:imx_sys_shutdown.save_reset_info_to_nv.p_reason_C:<<malloc 4>>
TEST.VALUE:imx_sys_shutdown.save_reset_info_to_nv.p_reason_C:"abc"
TEST.EXPECTED:imx_sys_shutdown.save_reset_info_to_nv.p_reason_C:"abc"
TEST.END

-- Test Case: Reson_==_NULL
TEST.UNIT:imx_sys_shutdown
TEST.SUBPROGRAM:save_reset_info_to_nv
TEST.NEW
TEST.NAME:Reson_==_NULL
TEST.NOTES:
Requirement_AU29610-147157
TEST.END_NOTES:
TEST.VALUE_USER_CODE:imx_sys_shutdown.save_reset_info_to_nv.p_reason_C
<<imx_sys_shutdown.save_reset_info_to_nv.p_reason_C>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_USER_CODE:imx_sys_shutdown.save_reset_info_to_nv.p_reason_C
{{ <<imx_sys_shutdown.save_reset_info_to_nv.p_reason_C>> == ( NULL ) }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Unit: qnx_sys_shutdown

-- Subprogram: dk_bspal_sys_shutdown

-- Test Case: dk_bspal_sys_shutdown.default
TEST.UNIT:qnx_sys_shutdown
TEST.SUBPROGRAM:dk_bspal_sys_shutdown
TEST.NEW
TEST.NAME:dk_bspal_sys_shutdown.default
TEST.NOTES:
Requirement_AU29610-147157
TEST.END_NOTES:
TEST.VALUE:qnx_sys_shutdown.dk_bspal_sys_shutdown.p_reason_C:<<malloc 5>>
TEST.VALUE:qnx_sys_shutdown.dk_bspal_sys_shutdown.p_reason_C:"abcd"
TEST.VALUE:qnx_sys_shutdown.dk_bspal_sys_shutdown.return:0
TEST.EXPECTED:qnx_sys_shutdown.dk_bspal_sys_shutdown.return:-1
TEST.VALUE_USER_CODE:qnx_sys_shutdown.dk_bspal_sys_shutdown.p_type_E
<<qnx_sys_shutdown.dk_bspal_sys_shutdown.p_type_E>> = ( 2 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: dk_bspal_sys_shutdown.reboot
TEST.UNIT:qnx_sys_shutdown
TEST.SUBPROGRAM:dk_bspal_sys_shutdown
TEST.NEW
TEST.NAME:dk_bspal_sys_shutdown.reboot
TEST.NOTES:
Requirement_AU29610-147157
TEST.END_NOTES:
TEST.VALUE:qnx_sys_shutdown.dk_bspal_sys_shutdown.p_type_E:ESysShutdown_Reboot
TEST.VALUE:qnx_sys_shutdown.dk_bspal_sys_shutdown.p_reason_C:<<malloc 5>>
TEST.VALUE:qnx_sys_shutdown.dk_bspal_sys_shutdown.p_reason_C:"abcd"
TEST.VALUE:qnx_sys_shutdown.dk_bspal_sys_shutdown.return:0
TEST.EXPECTED:qnx_sys_shutdown.dk_bspal_sys_shutdown.return:0
TEST.END

-- Test Case: dk_bspal_sys_shutdown.shutdown
TEST.UNIT:qnx_sys_shutdown
TEST.SUBPROGRAM:dk_bspal_sys_shutdown
TEST.NEW
TEST.NAME:dk_bspal_sys_shutdown.shutdown
TEST.NOTES:
Requirement_AU29610-147157
TEST.END_NOTES:
TEST.VALUE:qnx_sys_shutdown.dk_bspal_sys_shutdown.p_type_E:ESysShutdown_Shutdown
TEST.VALUE:qnx_sys_shutdown.dk_bspal_sys_shutdown.p_reason_C:<<malloc 5>>
TEST.VALUE:qnx_sys_shutdown.dk_bspal_sys_shutdown.p_reason_C:"abcd"
TEST.VALUE:qnx_sys_shutdown.dk_bspal_sys_shutdown.return:0
TEST.EXPECTED:qnx_sys_shutdown.dk_bspal_sys_shutdown.return:0
TEST.END
