-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UTP_DESERILIZER_BSPAL
-- Unit(s) Under Test: dk_bspal_deserializer
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: deserializer_ioctl_handler

-- Test Case: deserializer_ioctl_handler_deinit
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:deserializer_ioctl_handler
TEST.NEW
TEST.NAME:deserializer_ioctl_handler_deinit
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.p_ioctl_cmd_S32:1
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.EXPECTED:dk_bspal_deserializer.deserializer_ioctl_handler.return:1
TEST.END

-- Test Case: deserializer_ioctl_handler_init
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:deserializer_ioctl_handler
TEST.NEW
TEST.NAME:deserializer_ioctl_handler_init
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.p_ioctl_cmd_S32:0
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:uut_prototype_stubs.ioctl.return:0
TEST.END

-- Test Case: deserializer_ioctl_handler_open_fail
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:deserializer_ioctl_handler
TEST.NEW
TEST.NAME:deserializer_ioctl_handler_open_fail
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.END

-- Test Case: deserializer_ioctl_streaming_
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:deserializer_ioctl_handler
TEST.NEW
TEST.NAME:deserializer_ioctl_streaming_
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.p_ioctl_cmd_S32:6
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.END

-- Test Case: deserializer_ioctl_streaming_default
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:deserializer_ioctl_handler
TEST.NEW
TEST.NAME:deserializer_ioctl_streaming_default
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.p_ioctl_cmd_S32:7
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.END

-- Test Case: deserializer_ioctl_streaming_link_status
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:deserializer_ioctl_handler
TEST.NEW
TEST.NAME:deserializer_ioctl_streaming_link_status
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.p_ioctl_cmd_S32:4
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.END

-- Test Case: deserializer_ioctl_streaming_start
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:deserializer_ioctl_handler
TEST.NEW
TEST.NAME:deserializer_ioctl_streaming_start
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.p_ioctl_cmd_S32:2
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.END

-- Test Case: deserializer_ioctl_streaming_stop
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:deserializer_ioctl_handler
TEST.NEW
TEST.NAME:deserializer_ioctl_streaming_stop
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.p_ioctl_cmd_S32:3
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.END

-- Test Case: deserializer_ioctl_streaming_stop_error_status
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:deserializer_ioctl_handler
TEST.NEW
TEST.NAME:deserializer_ioctl_streaming_stop_error_status
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.p_ioctl_cmd_S32:5
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.ioctl.return:1
TEST.END

-- Subprogram: dk_bspal_deserializer_configure

-- Test Case: dk_bspal_deserializer_configure_deinit
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_configure
TEST.NEW
TEST.NAME:dk_bspal_deserializer_configure_deinit
TEST.STUB:dk_bspal_deserializer.deserializer_ioctl_handler
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_configure.p_config_cmd_U8:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_configure.return:0
TEST.EXPECTED:dk_bspal_deserializer.dk_bspal_deserializer_configure.p_config_cmd_U8:0
TEST.END

-- Test Case: dk_bspal_deserializer_configure_error
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_configure
TEST.NEW
TEST.NAME:dk_bspal_deserializer_configure_error
TEST.STUB:dk_bspal_deserializer.deserializer_ioctl_handler
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_configure.p_config_cmd_U8:2
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_configure.return:0
TEST.END

-- Test Case: dk_bspal_deserializer_configure_init
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_configure
TEST.NEW
TEST.NAME:dk_bspal_deserializer_configure_init
TEST.STUB:dk_bspal_deserializer.deserializer_ioctl_handler
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_configure.p_config_cmd_U8:1
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_configure.return:0
TEST.END

-- Subprogram: dk_bspal_deserializer_deinit

-- Test Case: dk_bspal_deserializer_deinit
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_deinit
TEST.NEW
TEST.NAME:dk_bspal_deserializer_deinit
TEST.END

-- Subprogram: dk_bspal_deserializer_get_status

-- Test Case: dk_bspal_deserializer_get_status_error_stat
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_get_status
TEST.NEW
TEST.NAME:dk_bspal_deserializer_get_status_error_stat
TEST.STUB:dk_bspal_deserializer.deserializer_ioctl_handler
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_get_status.p_status_type_U8:1
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_get_status.return:0
TEST.EXPECTED:dk_bspal_deserializer.dk_bspal_deserializer_get_status.return:0
TEST.END

-- Test Case: dk_bspal_deserializer_get_status_invalid
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_get_status
TEST.NEW
TEST.NAME:dk_bspal_deserializer_get_status_invalid
TEST.STUB:dk_bspal_deserializer.deserializer_ioctl_handler
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_get_status.p_status_type_U8:2
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_get_status.return:0
TEST.END

-- Test Case: dk_bspal_deserializer_get_status_link_status
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_get_status
TEST.NEW
TEST.NAME:dk_bspal_deserializer_get_status_link_status
TEST.STUB:dk_bspal_deserializer.deserializer_ioctl_handler
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_get_status.p_status_type_U8:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_get_status.return:0
TEST.END

-- Subprogram: dk_bspal_deserializer_init

-- Test Case: dk_bspal_deserializer_init
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_init
TEST.NEW
TEST.NAME:dk_bspal_deserializer_init
TEST.END

-- Subprogram: dk_bspal_deserializer_streaming_control

-- Test Case: dk_bspal_deserializer_streaming_invalid
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_streaming_control
TEST.NEW
TEST.NAME:dk_bspal_deserializer_streaming_invalid
TEST.STUB:dk_bspal_deserializer.deserializer_ioctl_handler
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_streaming_control.p_control_cmd_U8:2
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_streaming_control.return:0
TEST.EXPECTED:dk_bspal_deserializer.dk_bspal_deserializer_streaming_control.return:-1
TEST.END

-- Test Case: dk_bspal_deserializer_streaming_start
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_streaming_control
TEST.NEW
TEST.NAME:dk_bspal_deserializer_streaming_start
TEST.STUB:dk_bspal_deserializer.deserializer_ioctl_handler
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_streaming_control.p_control_cmd_U8:1
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_streaming_control.return:0
TEST.END

-- Test Case: dk_bspal_deserializer_streaming_stop
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_streaming_control
TEST.NEW
TEST.NAME:dk_bspal_deserializer_streaming_stop
TEST.STUB:dk_bspal_deserializer.deserializer_ioctl_handler
TEST.VALUE:dk_bspal_deserializer.deserializer_ioctl_handler.return:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_streaming_control.p_control_cmd_U8:0
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_streaming_control.return:0
TEST.END

-- Subprogram: dk_bspal_deserializer_test_pattern

-- Test Case: dk_bspal_deserializer_test_pattern
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_test_pattern
TEST.NEW
TEST.NAME:dk_bspal_deserializer_test_pattern
TEST.END

-- Test Case: dk_bspal_deserializer_test_pattern_invalid
TEST.UNIT:dk_bspal_deserializer
TEST.SUBPROGRAM:dk_bspal_deserializer_test_pattern
TEST.NEW
TEST.NAME:dk_bspal_deserializer_test_pattern_invalid
TEST.VALUE:dk_bspal_deserializer.dk_bspal_deserializer_test_pattern.p_control_cmd_U8:1
TEST.END
