-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UTP_BSPAL_PWM
-- Unit(s) Under Test: dk_bspal_pwm
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: dk_bspal_pwm_deinit

-- Test Case: dk_bspal_pwm_deinit.001
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_deinit
TEST.NEW
TEST.NAME:dk_bspal_pwm_deinit.001
TEST.END

-- Subprogram: dk_bspal_pwm_export_pin

-- Test Case: dk_bspal_pwm_export_pin.001
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_export_pin
TEST.NEW
TEST.NAME:dk_bspal_pwm_export_pin.001
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.write.return:0
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.END

-- Test Case: dk_bspal_pwm_export_pin.002
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_export_pin
TEST.NEW
TEST.NAME:dk_bspal_pwm_export_pin.002
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_export_pin.003
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_export_pin
TEST.NEW
TEST.NAME:dk_bspal_pwm_export_pin.003
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:-1
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_export_pin.004
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_export_pin
TEST.NEW
TEST.NAME:dk_bspal_pwm_export_pin.004
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.write.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.END

-- Subprogram: dk_bspal_pwm_get_dutycycle

-- Test Case: dk_bspal_pwm_get_dutycycle.001
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_dutycycle
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_dutycycle.001
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.dc_val_U32[0]:24
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.return:0
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.return:0
TEST.END

-- Test Case: dk_bspal_pwm_get_dutycycle.002
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_dutycycle
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_dutycycle.002
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.dc_val_U32[0]:24
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_get_dutycycle.003
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_dutycycle
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_dutycycle.003
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.dc_val_U32[0]:24
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_get_dutycycle.004
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_dutycycle
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_dutycycle.004
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.dc_val_U32[0]:24
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_get_dutycycle.005
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_dutycycle
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_dutycycle.005
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.dc_val_U32[0]:24
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_dutycycle.return:-1
TEST.END

-- Subprogram: dk_bspal_pwm_get_enable

-- Test Case: dk_bspal_pwm_get_enable.001
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_enable
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_enable.001
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.dc_val_U32[0]:1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.return:0
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_enable.return:0
TEST.END

-- Test Case: dk_bspal_pwm_get_enable.002
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_enable
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_enable.002
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.dc_val_U32[0]:1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_enable.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_get_enable.003
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_enable
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_enable.003
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.dc_val_U32[0]:1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_enable.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_get_enable.004
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_enable
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_enable.004
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.dc_val_U32[0]:1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_enable.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_get_enable.005
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_enable
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_enable.005
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.dc_val_U32[0]:1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_enable.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_enable.return:-1
TEST.END

-- Subprogram: dk_bspal_pwm_get_period

-- Test Case: dk_bspal_pwm_get_period.001
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_period
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_period.001
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.dc_val_U32[0]:260156
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.return:0
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_period.return:0
TEST.END

-- Test Case: dk_bspal_pwm_get_period.002
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_period
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_period.002
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.dc_val_U32[0]:260156
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_period.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_get_period.003
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_period
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_period.003
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.dc_val_U32[0]:260156
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_period.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_get_period.004
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_period
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_period.004
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.dc_val_U32[0]:260156
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_period.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_get_period.005
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_get_period
TEST.NEW
TEST.NAME:dk_bspal_pwm_get_period.005
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.dc_val_U32:<<malloc 1>>
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.dc_val_U32[0]:260156
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_get_period.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_get_period.return:-1
TEST.END

-- Subprogram: dk_bspal_pwm_init

-- Test Case: dk_bspal_pwm_init.001
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_init
TEST.NEW
TEST.NAME:dk_bspal_pwm_init.001
TEST.END

-- Subprogram: dk_bspal_pwm_set_dutycycle

-- Test Case: dk_bspal_pwm_set_dutycycle.001
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_dutycycle
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_dutycycle.001
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.return:0
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.return:0
TEST.END

-- Test Case: dk_bspal_pwm_set_dutycycle.002
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_dutycycle
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_dutycycle.002
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_set_dutycycle.003
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_dutycycle
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_dutycycle.003
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_set_dutycycle.004
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_dutycycle
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_dutycycle.004
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_set_dutycycle.005
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_dutycycle
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_dutycycle.005
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_dutycycle.return:-1
TEST.END

-- Subprogram: dk_bspal_pwm_set_enable

-- Test Case: dk_bspal_pwm_set_enable.001
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_enable
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_enable.001
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_enable.p_pin_U8:1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_enable.dc_val_U32:24
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_enable.return:0
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_enable.return:0
TEST.END

-- Test Case: dk_bspal_pwm_set_enable.002
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_enable
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_enable.002
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_enable.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_enable.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_enable.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_set_enable.003
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_enable
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_enable.003
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_enable.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_enable.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_enable.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_set_enable.004
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_enable
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_enable.004
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_enable.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_enable.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_enable.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_set_enable.005
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_enable
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_enable.005
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_enable.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_enable.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_enable.return:-1
TEST.END

-- Subprogram: dk_bspal_pwm_set_period

-- Test Case: dk_bspal_pwm_set_period.001
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_period
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_period.001
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_period.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_period.return:0
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_period.return:0
TEST.END

-- Test Case: dk_bspal_pwm_set_period.002
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_period
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_period.002
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:99
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:-1
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_period.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_period.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_period.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_set_period.003
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_period
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_period.003
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:99
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_period.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_period.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_period.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_set_period.004
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_period
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_period.004
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:99
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_period.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_period.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_period.return:-1
TEST.END

-- Test Case: dk_bspal_pwm_set_period.005
TEST.UNIT:dk_bspal_pwm
TEST.SUBPROGRAM:dk_bspal_pwm_set_period
TEST.NEW
TEST.NAME:dk_bspal_pwm_set_period.005
TEST.STUB:dk_bspal_pwm.dk_bspal_pwm_export_pin
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.p_pin_id_U8:99
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_export_pin.return:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_period.p_pin_U8:0
TEST.VALUE:dk_bspal_pwm.dk_bspal_pwm_set_period.return:-1
TEST.VALUE:uut_prototype_stubs.snprintf.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.EXPECTED:dk_bspal_pwm.dk_bspal_pwm_set_period.return:-1
TEST.END
