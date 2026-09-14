-- VectorCAST 6.1h (11/11/13)
-- Test Case Script
-- 
-- Environment    : NEW_POPUP_CORE
-- Unit(s) Under Test: hmi_popup_core hmi_popup_core_if
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
--

-- Subprogram: <<INIT>>

-- Test Case: <<INIT>>.001
TEST.SUBPROGRAM:<<INIT>>
TEST.NEW
TEST.NAME:<<INIT>>.001
TEST.END

-- Unit: hmi_popup_core

-- Subprogram: hmi_popup_core_activate_popup

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L0_POPUP_INFO_0_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.003
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L0_POPUP_INFO_0_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.004
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.005
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.005
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.006
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.006
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L1_POPUP_INFO_1_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.007
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.007
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.008
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.008
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L1_POPUP_INFO_1_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.009
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.009
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_ACK_5_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.010
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.010
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.011
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.011
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_PROG_5_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.012
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.012
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.013
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.013
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.014
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.014
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.015
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.015
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L10_POPUP_INFO_10_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.016
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.016
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L10_POPUP_INFO_10_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.017
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.017
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L10_POPUP_INFO_10_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.018
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.018
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.020
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.020
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.021
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.021
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L0_POPUP_INFO_0_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.022
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.022
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L0_POPUP_INFO_0_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.023
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.023
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.024
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.024
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.025
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.025
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L1_POPUP_INFO_1_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.026
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.026
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.027
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.027
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L1_POPUP_INFO_1_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.028
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.028
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_ACK_5_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.029
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.029
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.030
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.030
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_PROG_5_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.031
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.031
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.032
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.032
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.033
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.033
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.034
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.034
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L10_POPUP_INFO_10_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.035
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.035
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L10_POPUP_INFO_10_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.036
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.036
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L10_POPUP_INFO_10_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.037
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.037
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_popup_id:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_activate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_activate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP.038
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP.038
TEST.VALUE:<<ALL_MIN>>
TEST.END

-- Test Case: HMI_POPUP_CORE_ACTIVATE_POPUP_MIN.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_activate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_ACTIVATE_POPUP_MIN.001
TEST.VALUE:<<ALL_MIN>>
TEST.END

-- Subprogram: hmi_popup_core_close_all_popup

-- Test Case: hmi_popup_core_close_all_popup.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_close_all_popup
TEST.NEW
TEST.NAME:hmi_popup_core_close_all_popup.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.END

-- Test Case: hmi_popup_core_close_all_popup.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_close_all_popup
TEST.NEW
TEST.NAME:hmi_popup_core_close_all_popup.002
TEST.VALUE:hmi_popup_core.hmi_popup_core_close_all_popup.p_layer_id:L_POPUP_LAYER5_ID
TEST.END

-- Test Case: hmi_popup_core_close_all_popup.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_close_all_popup
TEST.NEW
TEST.NAME:hmi_popup_core_close_all_popup.003
TEST.VALUE:hmi_popup_core.hmi_popup_core_close_all_popup.p_layer_id:POPUP_MAX_LAYERS
TEST.END

-- Subprogram: hmi_popup_core_close_popup

-- Test Case: HMI_POPUP_CORE_CLOSE_POPUP.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_close_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_CLOSE_POPUP.001
TEST.END

-- Subprogram: hmi_popup_core_deactivate_popup

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.0011
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.0011
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L5_POPUP_PROG_5_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L0_POPUP_INFO_0_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.VALUE:uut_prototype_stubs.hmi_timer_support_check_timer.return:POPUP_TMR_RUNNING
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.003
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L0_POPUP_INFO_0_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.004
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.VALUE:uut_prototype_stubs.hmi_timer_support_check_timer.return:1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.005
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.005
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.006
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.006
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L1_POPUP_INFO_1_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.007
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.007
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.008
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.008
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.009
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.009
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L5_POPUP_ACK_5_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.010
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.010
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.013
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.013
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.014
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.014
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.015
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.015
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L5_POPUP_PROG_5_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.016
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.016
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L0_POPUP_INFO_0_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.VALUE:uut_prototype_stubs.hmi_timer_support_check_timer.return:POPUP_TMR_RUNNING
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.017
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.017
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L0_POPUP_INFO_0_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.018
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.018
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.019
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.019
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.VALUE:uut_prototype_stubs.hmi_timer_support_check_timer.return:1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.020
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.020
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.021
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.021
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L1_POPUP_INFO_1_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.022
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.022
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.023
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.023
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L5_POPUP_ACK_5_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.024
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.024
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.025
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.025
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_DEACTIVATE_POPUP.026
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_DEACTIVATE_POPUP.026
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_popup_id:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_deactivate_popup.return:0
TEST.END

-- Test Case: hmi_popup_core_deactivate_popup.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_deactivate_popup
TEST.NEW
TEST.NAME:hmi_popup_core_deactivate_popup.001
TEST.END

-- Subprogram: hmi_popup_core_focus_handler

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.001
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER0_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:0
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:255
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:0
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.002
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER0_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:GFX_SCR_01
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:2
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:255
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:1
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.004
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:0
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:2
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:10
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.005
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.005
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:GFX_SCR_11
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:2
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:4
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.009
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.009
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER0_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:0
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:255
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:0
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.010
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.010
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:LSH_GOT_FOCUS_STATUS
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:9
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:LSH_GOT_FOCUS_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.011
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.011
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER0_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:GFX_SCR_01
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:2
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:255
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:1
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.012
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.012
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:0
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:2
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:10
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.013
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.013
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:LSH_GOT_FOCUS_STATUS
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:12
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.014
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.014
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:GFX_SCR_11
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:2
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:4
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.015
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.015
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:LSH_GOT_FOCUS_STATUS
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:9
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:LSH_GOT_FOCUS_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.016
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.016
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:LSH_GOT_FOCUS_STATUS
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:12
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.017
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.017
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:0
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:17
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.018
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.018
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:0
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:17
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.018_DEACTI
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.018_DEACTI
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:0
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:6
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:17
TEST.END

-- Test Case: HMI_POPUP_CORE_FOCUS_HANDLER.019
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_focus_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FOCUS_HANDLER.019
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].logic_state_id:0
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_status:6
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].focus_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_focus_handler.p_focus_hndl_status_SP[0].client_id:17
TEST.END

-- Subprogram: hmi_popup_core_forced_deactivate_popup

-- Test Case: HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_forced_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_popup_id:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_forced_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.004
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_popup_id:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.005
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_forced_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.005
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_popup_id:L5_POPUP_PROG_5_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.006
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_forced_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.006
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.011
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_forced_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.011
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_popup_id:L5_POPUP_PROG_5_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.012
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_forced_deactivate_popup
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.012
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.p_anim_id:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_forced_deactivate_popup.return:0
TEST.END

-- Subprogram: hmi_popup_core_get_keypad_content

-- Test Case: HMI_POPUP_CORE_GET_KEYPAD_CONTENT.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_keypad_content
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_KEYPAD_CONTENT.003
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].len_U8:1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry[0]:'a'
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].len_U8:1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_KEYPAD_CONTENT.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_keypad_content
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_KEYPAD_CONTENT.004
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry:<<malloc 3>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].len_U8:3
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry[0]:'1'
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry[1]:'4'
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry[2]:'4'
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.return:3
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_KEYPAD_CONTENT.005
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_keypad_content
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_KEYPAD_CONTENT.005
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].len_U8:1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry[0]:'a'
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].len_U8:1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_KEYPAD_CONTENT.010
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_keypad_content
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_KEYPAD_CONTENT.010
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry:<<malloc 3>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].len_U8:3
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry[0]:'1'
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry[1]:'4'
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.p_keypad_content[0].entry[2]:'4'
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_keypad_content.return:3
TEST.END

-- Subprogram: hmi_popup_core_get_popup_info

-- Test Case: HMI_POPUP_CORE_GET_POPUP_INFO.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_popup_info
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_POPUP_INFO.001
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_layer_id:L_POPUP_LAYER0_ID
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].total_popup_count:L0_POPUP_INFO_0_0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].active_popup_id:L_POPUP_MAX_COUNT
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_POPUP_INFO.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_popup_info
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_POPUP_INFO.002
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_layer_id:L_POPUP_LAYER0_ID
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].total_popup_count:L1_POPUP_PROG_1_0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].active_popup_id:L_POPUP_MAX_COUNT
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_POPUP_INFO.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_popup_info
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_POPUP_INFO.004
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_layer_id:POPUP_MAX_LAYERS
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].total_popup_count:L1_POPUP_PROG_1_0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].active_popup_id:L5_POPUP_ACK_5_0
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_POPUP_INFO.005
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_popup_info
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_POPUP_INFO.005
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_layer_id:L_POPUP_LAYER5_ID
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].total_popup_count:L0_POPUP_INFO_0_2
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].active_popup_id:L5_POPUP_PROG_5_2
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_POPUP_INFO.006
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_popup_info
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_POPUP_INFO.006
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_layer_id:L_POPUP_LAYER0_ID
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].total_popup_count:L0_POPUP_INFO_0_0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].active_popup_id:L_POPUP_MAX_COUNT
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_POPUP_INFO.007
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_popup_info
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_POPUP_INFO.007
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_layer_id:L_POPUP_LAYER0_ID
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].total_popup_count:L1_POPUP_PROG_1_0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].active_popup_id:L_POPUP_MAX_COUNT
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_POPUP_INFO.008
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_popup_info
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_POPUP_INFO.008
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_layer_id:POPUP_MAX_LAYERS
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].total_popup_count:L1_POPUP_PROG_1_0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].active_popup_id:L5_POPUP_ACK_5_0
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_POPUP_INFO.009
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_popup_info
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_POPUP_INFO.009
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_layer_id:L_POPUP_LAYER5_ID
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].total_popup_count:L0_POPUP_INFO_0_2
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].active_popup_id:L5_POPUP_PROG_5_2
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_POPUP_INFO.010
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_popup_info
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_POPUP_INFO.010
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_layer_id:L_POPUP_LAYER10_ID
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].total_popup_count:L0_POPUP_INFO_0_1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].active_popup_id:L10_POPUP_KEYPAD_10_3
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_POPUP_INFO.018
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_popup_info
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_POPUP_INFO.018
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_popup_info.p_layer_id:L_POPUP_LAYER10_ID
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].total_popup_count:L0_POPUP_INFO_0_1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_popup_info.p_info_data[0].active_popup_id:L10_POPUP_KEYPAD_10_3
TEST.END

-- Subprogram: hmi_popup_core_get_progress_bar_counter

-- Test Case: HMI_POPUP_CORE_GET_PROGRESS_BAR_COUNTER.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_progress_bar_counter
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_PROGRESS_BAR_COUNTER.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_progress_bar_counter.p_progress:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_progress_bar_counter.p_progress[0].popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_progress_bar_counter.p_progress[0].cnt_ptr_U8:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_progress_bar_counter.p_progress[0].cnt_ptr_U8[0]:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_progress_bar_counter.p_progress[0].cnt_ptr_U8[0]:1
TEST.END

-- Test Case: HMI_POPUP_CORE_GET_PROGRESS_BAR_COUNTER.004_01
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_get_progress_bar_counter
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_GET_PROGRESS_BAR_COUNTER.004_01
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_progress_bar_counter.p_progress:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_progress_bar_counter.p_progress[0].popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_progress_bar_counter.p_progress[0].cnt_ptr_U8:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_get_progress_bar_counter.p_progress[0].cnt_ptr_U8[0]:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_get_progress_bar_counter.p_progress[0].cnt_ptr_U8[0]:1
TEST.END

-- Subprogram: hmi_popup_core_initialize

-- Test Case: HMI_POPUP_CORE_INITIALIZE.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_initialize
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INITIALIZE.001
TEST.COMPOUND_ONLY
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_popup_status:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INITIALIZE.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_initialize
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INITIALIZE.002
TEST.COMPOUND_ONLY
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[0]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[1]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[2]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[0]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[1]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[2]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_tmr_bit_U8[0]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_tmr_bit_U8[1]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_tmr_bit_U8[2]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_min_tmr_bit_U8_ptr[0]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_min_tmr_bit_U8_ptr[1]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_min_tmr_bit_U8_ptr[2]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_prev_active_popup_id[L_POPUP_LAYER0_ID..L_POPUP_LAYER10_ID]:L_POPUP_MAX_COUNT
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER0_ID..L_POPUP_LAYER10_ID]:L_POPUP_MAX_COUNT
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_popup_status:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INITIALIZE.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_initialize
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INITIALIZE.003
TEST.COMPOUND_ONLY
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_popup_status:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INITIALIZE.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_initialize
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INITIALIZE.004
TEST.COMPOUND_ONLY
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[0]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[1]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[2]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[0]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[1]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[2]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_tmr_bit_U8[0]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_tmr_bit_U8[1]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_tmr_bit_U8[2]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_min_tmr_bit_U8_ptr[0]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_min_tmr_bit_U8_ptr[1]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_min_tmr_bit_U8_ptr[2]:0
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_prev_active_popup_id[L_POPUP_LAYER0_ID..L_POPUP_LAYER10_ID]:L_POPUP_MAX_COUNT
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER0_ID..L_POPUP_LAYER10_ID]:L_POPUP_MAX_COUNT
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_popup_status:0
TEST.END

-- Subprogram: hmi_popup_core_inspect_popup_active

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.003
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.004
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.005
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.005
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.006
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.006
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_INFO_1_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.007
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.007
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.008
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.008
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_INFO_1_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.009
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.009
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_ACK_5_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.010
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.010
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.011
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.011
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_PROG_5_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.012
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.012
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.012F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.012F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.013
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.013
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.013F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.013F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.014
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.014
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L9_POPUP_INFO_9_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.014F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.014F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.018_OUTPUT
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.018_OUTPUT
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_DISPLAY
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.01F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.01F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.028
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.028
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.029
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.029
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.02F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.02F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.030
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.030
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.031
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.031
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.032
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.032
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.033
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.033
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_INFO_1_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.034
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.034
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.035
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.035
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_INFO_1_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.036
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.036
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_ACK_5_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.037
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.037
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.038
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.038
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_PROG_5_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.039
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.039
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.03F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.03F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.040
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.040
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.041
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.041
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.042
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.042
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.043
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.043
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L9_POPUP_INFO_9_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.044
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.044
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.045
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.045
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_DISPLAY
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.046
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.046
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.047
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.047
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.048
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.048
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L0_POPUP_INFO_0_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.049
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.049
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.04F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.04F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.050
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.050
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.051
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.051
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.052
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.052
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_ACK_5_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.053
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.053
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.054
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.054
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_PROG_5_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.05F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.05F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.07F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.07F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.09F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.09F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_ACK_5_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.10F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.10F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Test Case: HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.11F
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_inspect_popup_active
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.11F
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_popup_id:L5_POPUP_PROG_5_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_inspect_popup_active.p_context_type:POPUP_CONTEXT_INPUT
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_inspect_popup_active.return:0
TEST.END

-- Subprogram: hmi_popup_core_presentation_handler

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.007
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.007
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_prev_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_INFO_10_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:GFX_SCR_00
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_ACTIVATED_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.008
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.008
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_prev_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_INFO_10_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:GFX_SCR_00
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_INVALID_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.009
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.009
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_prev_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_INFO_10_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:GFX_SCR_00
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_REFRESH_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.010
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.010
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:GFX_SCR_00
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_ACTIVATED_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.011
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.011
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_DEACTIVATED_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.012
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.012
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_REFRESH_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.017_ACTIV
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.017_ACTIV
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_prev_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_INFO_10_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:GFX_SCR_00
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_ACTIVATED_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.017_DEFAULT
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.017_DEFAULT
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_prev_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_INFO_10_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:GFX_SCR_00
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_INVALID_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.017_REFRESH
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.017_REFRESH
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_prev_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_KEYPAD_10_3
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER10_ID]:L10_POPUP_INFO_10_2
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:GFX_SCR_00
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_REFRESH_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.018_ACTIV
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.018_ACTIV
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:GFX_SCR_00
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_ACTIVATED_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.018_DEACTIVATED
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.018_DEACTIVATED
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_DEACTIVATED_STATUS
TEST.END

-- Test Case: HMI_POPUP_CORE_PRESENTATION_HANDLER.018_REFRESH
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_presentation_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_PRESENTATION_HANDLER.018_REFRESH
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_layer:L_POPUP_LAYER10_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].logic_state_id:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_presentation_handler.p_presn_hndl_status_SP[0].presentation_status:LSH_REFRESH_STATUS
TEST.END

-- Subprogram: hmi_popup_core_remap_button_events

-- Test Case: HMI_POPUP_CORE_REMAP_BUTTON_EVENTS.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_remap_button_events
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_REMAP_BUTTON_EVENTS.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_remap_button_events.p_button_id_U16:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_remap_button_events.p_popup_id:L1_POPUP_KEYPAD_1_1
TEST.END

-- Test Case: HMI_POPUP_CORE_REMAP_BUTTON_EVENTS.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_remap_button_events
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_REMAP_BUTTON_EVENTS.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_remap_button_events.p_button_id_U16:1
TEST.VALUE:hmi_popup_core.hmi_popup_core_remap_button_events.p_popup_id:L1_POPUP_KEYPAD_1_1
TEST.END

-- Subprogram: hmi_popup_core_rx_button_handler

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.001
TEST.COMPOUND_ONLY
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.001_INFO
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.001_INFO
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER0_ID]:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER0_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_00
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0
TEST.VALUE:uut_prototype_stubs.hmi_popup_info_0_0_event_handler.return:POPUP_BTN_BLOCK
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.004_PROG
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.004_PROG
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER0_ID]:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_10
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0
TEST.VALUE:uut_prototype_stubs.hmi_popup_prog_1_0_event_handler.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:17
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x21
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.003
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x11
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.003_INACTIVE
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.003_INACTIVE
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x10
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.INACTIVE
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.INACTIVE
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_CANCEL
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_CANCEL
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_CANCEL
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_CLEAR
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_CLEAR
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_CLEAR
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_DELETE
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_DELETE
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_DELETE1
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_OK
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_OK
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_ok3
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_ACK_ABSORBED
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_ACK_ABSORBED
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_rx_button_handler.return:LSH_STATUS_ABSORBED
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_ACK_PASSED
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_ACK_PASSED
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_NACK_PASSED
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_NACK_PASSED
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_5
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_NACK_PASSED_NOT_MATCH
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_NACK_PASSED_NOT_MATCH
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_9
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.001
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x11
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x21
TEST.VALUE:uut_prototype_stubs.hmi_popup_validation_hndler.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.003
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x41
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.004
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x80
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.INACTIVE
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.INACTIVE
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x0
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.012_NACK_ABSORBED
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.012_NACK_ABSORBED
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_20
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_5
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.012_NACK_ABSORBED.NOT_MATCH
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.012_NACK_ABSORBED.NOT_MATCH
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_20
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_9
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x21
TEST.VALUE:uut_prototype_stubs.hmi_popup_validation_hndler.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.003
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x11
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.INACTIVE
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.INACTIVE
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x0
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.026
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.026
TEST.COMPOUND_ONLY
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.027
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.027
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER0_ID]:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER0_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_00
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0
TEST.VALUE:uut_prototype_stubs.hmi_popup_info_0_0_event_handler.return:POPUP_BTN_BLOCK
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.028
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.028
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER0_ID]:L0_POPUP_INFO_0_0
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_10
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0
TEST.VALUE:uut_prototype_stubs.hmi_popup_prog_1_0_event_handler.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.029
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.029
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:17
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.030
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.030
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x21
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.031
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.031
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x11
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.032
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.032
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x10
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.033
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.033
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.034
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.034
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_CANCEL
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.035
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.035
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_CLEAR
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.036
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.036
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_DELETE1
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.037
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.037
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_ok3
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.038
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.038
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_rx_button_handler.return:LSH_STATUS_ABSORBED
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.039
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.039
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:2
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.040
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.040
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_5
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.041
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.041
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_ACK_1_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER1_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_12
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_9
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.042
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.042
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x11
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.043
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.043
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x21
TEST.VALUE:uut_prototype_stubs.hmi_popup_validation_hndler.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.044
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.044
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x41
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.045
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.045
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x0
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.046
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.046
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_20
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_5
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.047
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.047
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_ACK_5_3
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_20
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:ButtonID_9
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.048
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.048
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x21
TEST.VALUE:uut_prototype_stubs.hmi_popup_validation_hndler.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.049
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.049
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x11
TEST.END

-- Test Case: HMI_POPUP_CORE_RX_BUTTON_HANDLER.050
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_rx_button_handler
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_RX_BUTTON_HANDLER.050
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID]:L5_POPUP_KEYPAD_5_4
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_layer_id:L_POPUP_LAYER5_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].logic_state_id:GFX_SCR_21
TEST.VALUE:hmi_popup_core.hmi_popup_core_rx_button_handler.p_event_hndl_status_SP[0].button_command:0x0
TEST.END

-- Subprogram: hmi_popup_core_set_keypad_content

-- Test Case: HMI_POPUP_CORE_SET_KEYPAD_CONTENT.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_set_keypad_content
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_SET_KEYPAD_CONTENT.003
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].entry:<<malloc 2>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].entry:"a"
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].len_U8:1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_set_keypad_content.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_SET_KEYPAD_CONTENT.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_set_keypad_content
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_SET_KEYPAD_CONTENT.004
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].entry:<<malloc 4>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].entry:"144"
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].len_U8:3
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_set_keypad_content.return:3
TEST.END

-- Test Case: HMI_POPUP_CORE_SET_KEYPAD_CONTENT.005
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_set_keypad_content
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_SET_KEYPAD_CONTENT.005
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].entry:<<malloc 2>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].entry:"a"
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].len_U8:1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_set_keypad_content.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_SET_KEYPAD_CONTENT.010
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_set_keypad_content
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_SET_KEYPAD_CONTENT.010
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].popup_id:L5_POPUP_KEYPAD_5_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].entry:<<malloc 4>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].entry:"144"
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_content.p_keypad_content[0].len_U8:3
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_set_keypad_content.return:3
TEST.END

-- Subprogram: hmi_popup_core_set_keypad_entry

-- Test Case: HMI_POPUP_CORE_SET_KEYPAD_ENTRY.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_set_keypad_entry
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_SET_KEYPAD_ENTRY.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_entry.p_keypad_set:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_entry.p_keypad_set[0].popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_entry.p_keypad_set[0].btn_id:2
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_entry.p_keypad_set[0].btn_state:1
TEST.END

-- Test Case: HMI_POPUP_CORE_SET_KEYPAD_ENTRY.005
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_set_keypad_entry
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_SET_KEYPAD_ENTRY.005
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_entry.p_keypad_set:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_entry.p_keypad_set[0].popup_id:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_entry.p_keypad_set[0].btn_id:2
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_keypad_entry.p_keypad_set[0].btn_state:1
TEST.END

-- Subprogram: hmi_popup_core_set_progress_bar_counter

-- Test Case: HMI_POPUP_CORE_SET_PROGRESS_BAR_COUNTER.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_set_progress_bar_counter
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_SET_PROGRESS_BAR_COUNTER.002
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_progress_bar_counter.p_progress:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_progress_bar_counter.p_progress[0].popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_progress_bar_counter.p_progress[0].cnt_ptr_U8:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_progress_bar_counter.p_progress[0].cnt_ptr_U8[0]:5
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_POPUP_P_0_counter_U8:5
TEST.END

-- Test Case: HMI_POPUP_CORE_SET_PROGRESS_BAR_COUNTER.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_set_progress_bar_counter
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_SET_PROGRESS_BAR_COUNTER.004
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_progress_bar_counter.p_progress:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_progress_bar_counter.p_progress[0].popup_id:L1_POPUP_PROG_1_0
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_progress_bar_counter.p_progress[0].cnt_ptr_U8:<<malloc 1>>
TEST.VALUE:hmi_popup_core.hmi_popup_core_set_progress_bar_counter.p_progress[0].cnt_ptr_U8[0]:5
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_POPUP_P_0_counter_U8:5
TEST.END

-- Subprogram: hmi_popup_core_start_timer

-- Test Case: HMI_POPUP_CORE_START_TIMER.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_start_timer
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_START_TIMER.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_start_timer.p_popup_id:L0_POPUP_INFO_0_1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_start_timer.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_START_TIMER.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_start_timer
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_START_TIMER.003
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_start_timer.p_popup_id:L0_POPUP_INFO_0_1
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_start_timer.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_START_TIMER.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_start_timer
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_START_TIMER.004
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_start_timer.p_popup_id:L10_POPUP_KEYPAD_10_3
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_start_timer.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_START_TIMER.018
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_start_timer
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_START_TIMER.018
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_start_timer.p_popup_id:L10_POPUP_KEYPAD_10_3
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_start_timer.return:1
TEST.END

-- Subprogram: hmi_popup_core_stop_timer

-- Test Case: HMI_POPUP_CORE_STOP_TIMER.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_stop_timer
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_STOP_TIMER.002
TEST.COMPOUND_ONLY
TEST.END

-- Test Case: HMI_POPUP_CORE_STOP_TIMER.003
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_stop_timer
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_STOP_TIMER.003
TEST.COMPOUND_ONLY
TEST.END

-- Test Case: HMI_POPUP_CORE_STOP_TIMER.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_stop_timer
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_STOP_TIMER.004
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_stop_timer.p_popup_id:L10_POPUP_KEYPAD_10_3
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_stop_timer.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_STOP_TIMER.018
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_stop_timer
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_STOP_TIMER.018
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_stop_timer.p_popup_id:L10_POPUP_KEYPAD_10_3
TEST.EXPECTED:hmi_popup_core.hmi_popup_core_stop_timer.return:1
TEST.END

-- Subprogram: hmi_popup_core_task

-- Test Case: HMI_POPUP_CORE_TASK.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_task
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TASK.001
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[0]:13
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[1]:45
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[2]:1
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[0]:10
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[1]:50
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[2]:1
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER0_ID]:L0_POPUP_INFO_0_1
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID..L_POPUP_LAYER10_ID]:L_POPUP_MAX_COUNT
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[0]:13
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[1]:45
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[2]:1
TEST.FLOW
  hmi_popup_core.c.hmi_popup_core_task
  uut_prototype_stubs.hmi_popup_default_focus_handler
  uut_prototype_stubs.hmi_popup_default_focus_handler
  hmi_popup_core.c.hmi_popup_core_task
TEST.END_FLOW
TEST.END

-- Test Case: HMI_POPUP_CORE_TASK.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_task
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TASK.002
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[0]:13
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[1]:45
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_sts_bit_U8[2]:1
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[0]:10
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[1]:50
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[2]:1
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER0_ID]:L0_POPUP_INFO_0_1
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER1_ID]:L1_POPUP_KEYPAD_1_1
TEST.VALUE:hmi_popup_core.<<GLOBAL>>.l_active_popup_id[L_POPUP_LAYER5_ID..L_POPUP_LAYER10_ID]:L_POPUP_MAX_COUNT
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[0]:13
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[1]:45
TEST.EXPECTED:hmi_popup_core.<<GLOBAL>>.l_pp_id_lsh_sts_bit_U8[2]:1
TEST.FLOW
  hmi_popup_core.c.hmi_popup_core_task
  uut_prototype_stubs.hmi_popup_default_focus_handler
  uut_prototype_stubs.hmi_popup_default_focus_handler
  hmi_popup_core.c.hmi_popup_core_task
TEST.END_FLOW
TEST.END

-- Subprogram: hmi_popup_core_timeout_callback

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.002
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.002
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_ATE0_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:257
TEST.END

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.002_MIN
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.002_MIN
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_LAYER0_MIN_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:1025
TEST.VALUE:uut_prototype_stubs.hmi_timer_support_check_timer.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.002_TYPE
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.002_TYPE
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_LAYER0_MIN_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:0x202
TEST.VALUE:uut_prototype_stubs.hmi_timer_support_check_timer.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.004
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.004
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_ATE1_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:0x103
TEST.END

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.004_DEFAULT
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.004_DEFAULT
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_ATE2_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:0x204
TEST.END

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.005
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.005
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_ATE2_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:0x104
TEST.END

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.007
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.007
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_ATE0_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:257
TEST.END

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.008
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.008
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_LAYER0_MIN_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:1025
TEST.VALUE:uut_prototype_stubs.hmi_timer_support_check_timer.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.009
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.009
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_LAYER0_MIN_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:0x202
TEST.VALUE:uut_prototype_stubs.hmi_timer_support_check_timer.return:1
TEST.END

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.010
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.010
TEST.COMPOUND_ONLY
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:FALSE
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_ATE1_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:0x103
TEST.END

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.011
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.011
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_ATE2_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:0x204
TEST.END

-- Test Case: HMI_POPUP_CORE_TIMEOUT_CALLBACK.012
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_core_timeout_callback
TEST.NEW
TEST.NAME:HMI_POPUP_CORE_TIMEOUT_CALLBACK.012
TEST.COMPOUND_ONLY
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_timer_id:GUI_POPUP_ATE2_TMR_ID
TEST.VALUE:hmi_popup_core.hmi_popup_core_timeout_callback.p_event:0x104
TEST.END

-- Subprogram: hmi_popup_keypad_btn_handler

-- Test Case: hmi_popup_keypad_btn_handler.001
TEST.UNIT:hmi_popup_core
TEST.SUBPROGRAM:hmi_popup_keypad_btn_handler
TEST.NEW
TEST.NAME:hmi_popup_keypad_btn_handler.001
TEST.VALUE:hmi_popup_core.hmi_popup_keypad_btn_handler.p_keypad:<<malloc 2>>
TEST.VALUE:hmi_popup_core.hmi_popup_keypad_btn_handler.p_keypad[0].l_curr_multi_press_btn:<<malloc 11>>
TEST.END

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.031
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.026"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.034"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.032
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.026"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.034"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.039"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.051"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.033
TEST.SLOT: "1", "<<COMPOUND>>", "<<COMPOUND>>", "1", "INSPECT<<COMPOUND>>.004"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.014"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.046"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.036
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.034"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.035"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.036"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.037"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.017"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_get_popup_info", "1", "HMI_POPUP_CORE_GET_POPUP_INFO.010"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.045"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.010"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.012"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.026"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.019"
TEST.SLOT: "13", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.011"
TEST.SLOT: "14", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.007"
TEST.SLOT: "15", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.009"
TEST.SLOT: "16", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.008"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.037
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.029"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.029"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.037"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.038
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.052"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.028"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.036"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.029"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.036"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.053"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.030"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.036"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.053"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.038"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.031"
TEST.SLOT: "13", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.039"
TEST.SLOT: "14", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.038"
TEST.SLOT: "15", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.036"
TEST.SLOT: "16", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.032"
TEST.SLOT: "17", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.053"
TEST.SLOT: "18", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.039"
TEST.SLOT: "19", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.038"
TEST.SLOT: "20", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.036"
TEST.SLOT: "21", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.042"
TEST.SLOT: "22", "hmi_popup_core", "hmi_popup_core_get_popup_info", "1", "HMI_POPUP_CORE_GET_POPUP_INFO.008"
TEST.SLOT: "23", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.023"
TEST.SLOT: "24", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.012"
TEST.SLOT: "25", "hmi_popup_core", "hmi_popup_core_get_popup_info", "1", "HMI_POPUP_CORE_GET_POPUP_INFO.009"
TEST.SLOT: "26", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.031"
TEST.SLOT: "27", "hmi_popup_core", "hmi_popup_core_forced_deactivate_popup", "1", "HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.005"
TEST.SLOT: "28", "hmi_popup_core", "hmi_popup_core_forced_deactivate_popup", "1", "HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.006"
TEST.SLOT: "29", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.030"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.039
TEST.COMPOUND_ONLY
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.020"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.021"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.022"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.028"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_get_popup_info", "1", "HMI_POPUP_CORE_GET_POPUP_INFO.007"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.014"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.041
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.032"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.016"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.048"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.050"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.048"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.050"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.049"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.050"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.042
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.029"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.015"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.042"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.045"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.044"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.045"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.044"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.045"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.043"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.045"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.044"
TEST.SLOT: "13", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.045"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.043
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.029"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.015"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_set_keypad_content", "1", "HMI_POPUP_CORE_SET_KEYPAD_CONTENT.004"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_get_keypad_content", "1", "HMI_POPUP_CORE_GET_KEYPAD_CONTENT.004"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.044
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.029"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.015"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.042"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.045"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.044"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.045"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.044"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.045"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.043"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.032"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.016"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.045
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.024"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.014"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.032"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_set_keypad_content", "1", "HMI_POPUP_CORE_SET_KEYPAD_CONTENT.003"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.033"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.029"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.033"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.012"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.012"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.031"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.032"
TEST.SLOT: "13", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.031"
TEST.SLOT: "14", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.032"
TEST.SLOT: "15", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.012"
TEST.SLOT: "16", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.012"
TEST.SLOT: "17", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.031"
TEST.SLOT: "18", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.033"
TEST.SLOT: "19", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.030"
TEST.SLOT: "20", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.033"
TEST.SLOT: "21", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.012"
TEST.SLOT: "22", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.012"
TEST.SLOT: "23", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.012"
TEST.SLOT: "24", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.012"
TEST.SLOT: "25", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.012"
TEST.SLOT: "26", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.050"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.046
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.024"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.032"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.034"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.047
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.024"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.032"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.035"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.048
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.024"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.032"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_set_keypad_content", "1", "HMI_POPUP_CORE_SET_KEYPAD_CONTENT.003"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.036"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.049
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.024"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.032"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.037"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.050
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.025"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.024"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.032"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_set_keypad_content", "1", "HMI_POPUP_CORE_SET_KEYPAD_CONTENT.003"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_get_keypad_content", "1", "HMI_POPUP_CORE_GET_KEYPAD_CONTENT.003"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_set_keypad_entry", "1", "HMI_POPUP_CORE_SET_KEYPAD_ENTRY.002"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.012"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.029"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.051
TEST.SLOT: "1", "<<COMPOUND>>", "<<COMPOUND>>", "1", "<<COMPOUND>>.039"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.029"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.011"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.016"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.008"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.007"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.047"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.052
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.031"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.046"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.039"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.047"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.053
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.026"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.040"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.034"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.041"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.054
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.004"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.055
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.020"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.028"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.027"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.014"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.046"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.056
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.023"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.010"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_get_progress_bar_counter", "1", "HMI_POPUP_CORE_GET_PROGRESS_BAR_COUNTER.002"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.010"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.028"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.010"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.010"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.010"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.010"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.010"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.010"
TEST.SLOT: "13", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.011"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.057
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.023"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_set_progress_bar_counter", "1", "HMI_POPUP_CORE_SET_PROGRESS_BAR_COUNTER.002"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.010"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.049"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.058
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.024"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_remap_button_events", "1", "HMI_POPUP_CORE_REMAP_BUTTON_EVENTS.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.059
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_task", "1", "HMI_POPUP_CORE_TASK.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:<<COMPOUND>>.060
TEST.SLOT: "1", "<<COMPOUND>>", "<<COMPOUND>>", "1", "<<COMPOUND>>.039"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.029"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_start_timer", "1", "HMI_POPUP_CORE_START_TIMER.003"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_stop_timer", "1", "HMI_POPUP_CORE_STOP_TIMER.003"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_start_timer", "1", "HMI_POPUP_CORE_START_TIMER.003"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.007"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.047"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:ACK_PP_ABSORBED<<COMPOUND>>.007
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.007"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.007"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_ACK_ABSORBED"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:ACK_PP_PASSED<<COMPOUND>>.007
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.007"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.007"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_ACK_PASSED"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:ACTIVE_PP_IN_OUTPUT_FOCUS<<COMPOUND>>.018
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.015"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.016"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.017"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.018"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.018"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_get_popup_info", "1", "HMI_POPUP_CORE_GET_POPUP_INFO.018"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.018_OUTPUT"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.01F"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_stop_timer", "1", "HMI_POPUP_CORE_STOP_TIMER.018"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_start_timer", "1", "HMI_POPUP_CORE_START_TIMER.018"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_CLOSE_ALL
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.011"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.012"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_close_all_popup", "1", "hmi_popup_core_close_all_popup.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_CLOSE_ALL_FOR_MAX_LAYER
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.002"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_close_all_popup", "1", "hmi_popup_core_close_all_popup.003"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:CHECK_KEYPAD_BTN
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_set_keypad_entry", "1", "HMI_POPUP_CORE_SET_KEYPAD_ENTRY.002"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.004"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.053"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:DEACTIVATE<<COMPOUND>>.001
TEST.SLOT: "1", "<<COMPOUND>>", "<<COMPOUND>>", "1", "INSPECT<<COMPOUND>>.004"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.001"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.01F"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:DEACTIVATE_ACTIVE_PP<<COMPOUND>>.006
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.030"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.028"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.021"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.020"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.047"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.028"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.036"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.054"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:FOCUS<<COMPOUND>>.018
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.034"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.035"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.036"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.037"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.017"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_get_popup_info", "1", "HMI_POPUP_CORE_GET_POPUP_INFO.010"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.045"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.046"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_stop_timer", "1", "HMI_POPUP_CORE_STOP_TIMER.004"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_start_timer", "1", "HMI_POPUP_CORE_START_TIMER.004"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:FOCUS_PRESENT<<COMPOUND>>.008
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.015"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.016"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.017"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.018"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.018"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_get_popup_info", "1", "HMI_POPUP_CORE_GET_POPUP_INFO.018"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.018_OUTPUT"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.018_ACTIV"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.018_REFRESH"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.018"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.018_DEACTI"
TEST.SLOT: "13", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.018_DEACTIVATED"
TEST.SLOT: "14", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.017_ACTIV"
TEST.SLOT: "15", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.017_REFRESH"
TEST.SLOT: "16", "hmi_popup_core", "hmi_popup_core_presentation_handler", "1", "HMI_POPUP_CORE_PRESENTATION_HANDLER.017_DEFAULT"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:GROUP_PP_ACTIVATE_SAME<<COMPOUND>>.009
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.010"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.010"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.010"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:GROUP_PP_ACTI_DEACTIVATE<<COMPOUND>>.008
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.09F"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.009"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.009"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.010"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.009"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.10F"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.011"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.009"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.10F"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.011"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.012"
TEST.SLOT: "13", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.012"
TEST.SLOT: "14", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.011"
TEST.SLOT: "15", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.009"
TEST.SLOT: "16", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.013"
TEST.SLOT: "17", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.10F"
TEST.SLOT: "18", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.012"
TEST.SLOT: "19", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.011"
TEST.SLOT: "20", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.009"
TEST.SLOT: "21", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.013F"
TEST.SLOT: "22", "hmi_popup_core", "hmi_popup_core_get_popup_info", "1", "HMI_POPUP_CORE_GET_POPUP_INFO.004"
TEST.SLOT: "23", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.009"
TEST.SLOT: "24", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.004"
TEST.SLOT: "25", "hmi_popup_core", "hmi_popup_core_get_popup_info", "1", "HMI_POPUP_CORE_GET_POPUP_INFO.005"
TEST.SLOT: "26", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.012"
TEST.SLOT: "27", "hmi_popup_core", "hmi_popup_core_forced_deactivate_popup", "1", "HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.011"
TEST.SLOT: "28", "hmi_popup_core", "hmi_popup_core_forced_deactivate_popup", "1", "HMI_POPUP_CORE_FORCED_DEACTIVATE_POPUP.012"
TEST.SLOT: "29", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.011"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:INSPECT<<COMPOUND>>.004
TEST.COMPOUND_ONLY
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.001"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.002"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.003"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.001"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_get_popup_info", "1", "HMI_POPUP_CORE_GET_POPUP_INFO.002"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:KEYPAD_PP_DEACTIVATE_<<COMPOUND>>.010
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.003"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.032"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.016"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.029"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.015"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.037"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.042"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:KEYPAD_PP_NUMERIC_<<COMPOUND>>.013
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.013"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.013"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.002"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.INACTIVE"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.002"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.INACTIVE"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.003"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.013_KEYPAD.INACTIVE"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:KEYPAD_PP_NUMERIC_BUTTON_<<COMPOUND>>.010
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.010"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.010"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.001"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.INACTIVE"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.003"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.INACTIVE"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.003"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.INACTIVE"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.002"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.INACTIVE"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.003"
TEST.SLOT: "13", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.INACTIVE"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:KEYPAD_PP_NUMERIC_GET_SET_<<COMPOUND>>.010
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.010"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.010"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_set_keypad_content", "1", "HMI_POPUP_CORE_SET_KEYPAD_CONTENT.010"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_get_keypad_content", "1", "HMI_POPUP_CORE_GET_KEYPAD_CONTENT.010"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:KEYPAD_PP_NUMERIC_VALIDATION<<COMPOUND>>.010
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.010"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.010"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.001"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.INACTIVE"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.003"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.INACTIVE"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.003"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.INACTIVE"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.010_KEYPAD.002"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.013"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.013"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:KEYPAD_PP_RX_<<COMPOUND>>.005
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.005"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.005"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.005"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_set_keypad_content", "1", "HMI_POPUP_CORE_SET_KEYPAD_CONTENT.005"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.INACTIVE"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.INACTIVE"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.005"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.005"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.003"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.003_INACTIVE"
TEST.SLOT: "13", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.003"
TEST.SLOT: "14", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.003_INACTIVE"
TEST.SLOT: "15", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.005"
TEST.SLOT: "16", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.005"
TEST.SLOT: "17", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.003"
TEST.SLOT: "18", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.INACTIVE"
TEST.SLOT: "19", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.002"
TEST.SLOT: "20", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD.INACTIVE"
TEST.SLOT: "21", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.005"
TEST.SLOT: "22", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.005"
TEST.SLOT: "23", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.005"
TEST.SLOT: "24", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.005"
TEST.SLOT: "25", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.005"
TEST.SLOT: "26", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.05F"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:KEYPAD_PP_RX_CANCEL<<COMPOUND>>.005
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.005"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.005"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_CANCEL"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:KEYPAD_PP_RX_CLEAR<<COMPOUND>>.006
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.005"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.005"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_CLEAR"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:KEYPAD_PP_RX_DELETE<<COMPOUND>>.005
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.005"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.005"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_set_keypad_content", "1", "HMI_POPUP_CORE_SET_KEYPAD_CONTENT.005"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_DELETE"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:KEYPAD_PP_RX_OK_<<COMPOUND>>.005
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.005"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.005"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD_OK"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:KEYPAD_PP_TIMEOUT_<<COMPOUND>>.005
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.006"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.005"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.005"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_set_keypad_content", "1", "HMI_POPUP_CORE_SET_KEYPAD_CONTENT.005"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_get_keypad_content", "1", "HMI_POPUP_CORE_GET_KEYPAD_CONTENT.005"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_set_keypad_entry", "1", "HMI_POPUP_CORE_SET_KEYPAD_ENTRY.005"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.005"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.005_KEYPAD"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:MIN_TIMEOUT<<COMPOUND>>.002
TEST.SLOT: "1", "<<COMPOUND>>", "<<COMPOUND>>", "1", "INSPECT<<COMPOUND>>.004"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.002"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.002"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.002"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.002_MIN"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.002"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.02F"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:NACK_PP_ABSORBED<<COMPOUND>>.012
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.012"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.012_NACK_ABSORBED"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.012"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.012_NACK_ABSORBED.NOT_MATCH"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:NACK_PP_PASSED<<COMPOUND>>.007
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.007"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_NACK_PASSED"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.007"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.007_NACK_PASSED_NOT_MATCH"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:POPUP_CORE_INIT<<COMPOUND>>.001
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.002"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:PP_ACTIVE_INSPECT<<COMPOUND>>.001
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.001"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.001"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.001_INFO"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_deactivate_popup", "1", "HMI_POPUP_CORE_DEACTIVATE_POPUP.001"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.01F"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:PROG_BAR_<<COMPOUND>>.004
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.004"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.004"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_get_progress_bar_counter", "1", "HMI_POPUP_CORE_GET_PROGRESS_BAR_COUNTER.004_01"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.004"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_rx_button_handler", "1", "HMI_POPUP_CORE_RX_BUTTON_HANDLER.004_PROG"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.004"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.004"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.004"
TEST.SLOT: "10", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.004"
TEST.SLOT: "11", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.004"
TEST.SLOT: "12", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.004"
TEST.SLOT: "13", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.004_DEFAULT"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:PROG_SET_COUNTER<<COMPOUND>>.004
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.004"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_set_progress_bar_counter", "1", "HMI_POPUP_CORE_SET_PROGRESS_BAR_COUNTER.004"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.004"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.04F"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:REMAP<<COMPOUND>>.005
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.005"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_remap_button_events", "1", "HMI_POPUP_CORE_REMAP_BUTTON_EVENTS.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:SELF_DEACTIVATE_ACTIVE_PP<<COMPOUND>>.006
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.011"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.009"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.002"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.001"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.02F"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.001"
TEST.SLOT: "8", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.009"
TEST.SLOT: "9", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.11F"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:SELF_DEACTIVATE_ON_ACTIVE_PP_<<COMPOUND>>.010
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.013"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.013"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_activate_popup", "1", "HMI_POPUP_CORE_ACTIVATE_POPUP.010"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_focus_handler", "1", "HMI_POPUP_CORE_FOCUS_HANDLER.010"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.010"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.013F"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:TASK<<COMPOUND>>.000
TEST.SLOT: "1", "hmi_popup_core", "hmi_popup_core_initialize", "1", "HMI_POPUP_CORE_INITIALIZE.001"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_task", "1", "HMI_POPUP_CORE_TASK.001"
TEST.END
--

-- COMPOUND TESTS

TEST.SUBPROGRAM:<<COMPOUND>>
TEST.NEW
TEST.NAME:TIMEOUT<<COMPOUND>>.009
TEST.SLOT: "1", "<<COMPOUND>>", "<<COMPOUND>>", "1", "INSPECT<<COMPOUND>>.004"
TEST.SLOT: "2", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.002"
TEST.SLOT: "3", "hmi_popup_core", "hmi_popup_core_start_timer", "1", "HMI_POPUP_CORE_START_TIMER.002"
TEST.SLOT: "4", "hmi_popup_core", "hmi_popup_core_stop_timer", "1", "HMI_POPUP_CORE_STOP_TIMER.002"
TEST.SLOT: "5", "hmi_popup_core", "hmi_popup_core_start_timer", "1", "HMI_POPUP_CORE_START_TIMER.002"
TEST.SLOT: "6", "hmi_popup_core", "hmi_popup_core_timeout_callback", "1", "HMI_POPUP_CORE_TIMEOUT_CALLBACK.002"
TEST.SLOT: "7", "hmi_popup_core", "hmi_popup_core_inspect_popup_active", "1", "HMI_POPUP_CORE_INSPECT_POPUP_ACTIVE.02F"
TEST.END
--
