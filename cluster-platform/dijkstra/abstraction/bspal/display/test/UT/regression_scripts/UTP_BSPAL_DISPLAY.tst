-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UTP_BSPAL_DISPLAY
-- Unit(s) Under Test: dk_bspal_display
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: dk_bspal_display_get_gamma_rgb

-- Test Case: devctl_fail
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_get_gamma_rgb
TEST.NEW
TEST.NAME:devctl_fail
TEST.STUB:uut_prototype_stubs.close
TEST.VALUE:uut_prototype_stubs.devctl.return:1
TEST.EXPECTED:uut_prototype_stubs.close.VCAST_PARAM_1:0
TEST.END

-- Test Case: file_open_fail
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_get_gamma_rgb
TEST.NEW
TEST.NAME:file_open_fail
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_get_gamma_rgb.return:-1
TEST.END

-- Test Case: file_open_fail.001
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_get_gamma_rgb
TEST.NEW
TEST.NAME:file_open_fail.001
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_red_S32:<<malloc 1>>
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_red_S32[0]:3
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_green_S32:<<malloc 1>>
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_green_S32[0]:5
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_blue_S32:<<malloc 1>>
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_blue_S32[0]:7
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_get_gamma_rgb.return:-1
TEST.END

-- Test Case: file_open_fail.002
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_get_gamma_rgb
TEST.NEW
TEST.NAME:file_open_fail.002
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_red_S32:<<malloc 1>>
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_red_S32[0]:3
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_green_S32:<<malloc 1>>
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_green_S32[0]:5
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_blue_S32:<<malloc 1>>
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.p_gamma_blue_S32[0]:7
TEST.VALUE:dk_bspal_display.dk_bspal_display_get_gamma_rgb.return:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_get_gamma_rgb.return:0
TEST.END

-- Subprogram: dk_bspal_display_get_state

-- Test Case: EBspaDisplayState_Disconnected_pass
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_get_state
TEST.NEW
TEST.NAME:EBspaDisplayState_Disconnected_pass
TEST.STUB:uut_prototype_stubs.close
TEST.VALUE:dk_bspal_display.<<GLOBAL>>.l_disp:EBspaDisplayState_On
TEST.VALUE:uut_prototype_stubs.close.VCAST_PARAM_1:2
TEST.VALUE:uut_prototype_stubs.open.return:2
TEST.VALUE:uut_prototype_stubs.devctl.fd:0
TEST.VALUE:uut_prototype_stubs.devctl.dcmd:-2147483648
TEST.EXPECTED:dk_bspal_display.<<GLOBAL>>.l_disp:EBspalDisplayState_Disconnected
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_get_state.return:0
TEST.EXPECTED:uut_prototype_stubs.close.VCAST_PARAM_1:2
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_1:"/dev/display/display0/state"
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_2:0
TEST.EXPECTED:uut_prototype_stubs.devctl.fd:2
TEST.EXPECTED:uut_prototype_stubs.devctl.dcmd:3
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.devctl.dev_data_ptr
display_state_buffer_type_ts *state_ptr;
state_ptr = (display_state_buffer_type_ts *)<<uut_prototype_stubs.devctl.dev_data_ptr>>;
state_ptr->state = DISPLAY_ESTATE_DISCONNECTED;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:dk_bspal_display.dk_bspal_display_get_state.p_value_EP
<<dk_bspal_display.dk_bspal_display_get_state.p_value_EP>> = &<<dk_bspal_display.<<GLOBAL>>.l_disp>>;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EBspaDisplayState_Error_pass
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_get_state
TEST.NEW
TEST.NAME:EBspaDisplayState_Error_pass
TEST.STUB:uut_prototype_stubs.close
TEST.VALUE:dk_bspal_display.<<GLOBAL>>.l_disp:EBspaDisplayState_On
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.dcmd:3
TEST.EXPECTED:dk_bspal_display.<<GLOBAL>>.l_disp:EBspaDisplayState_Error
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_get_state.return:0
TEST.EXPECTED:uut_prototype_stubs.close.VCAST_PARAM_1:0
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_1:"/dev/display/display0/state"
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_2:0
TEST.EXPECTED:uut_prototype_stubs.devctl.fd:0
TEST.EXPECTED:uut_prototype_stubs.devctl.dcmd:3
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.devctl.dev_data_ptr
display_state_buffer_type_ts *state_ptr;
state_ptr = (display_state_buffer_type_ts *)<<uut_prototype_stubs.devctl.dev_data_ptr>>;
state_ptr->state = DISPLAY_ESTATE_ERROR;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:dk_bspal_display.dk_bspal_display_get_state.p_value_EP
<<dk_bspal_display.dk_bspal_display_get_state.p_value_EP>> = &<<dk_bspal_display.<<GLOBAL>>.l_disp>>;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EBspaDisplayState_Off_pass
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_get_state
TEST.NEW
TEST.NAME:EBspaDisplayState_Off_pass
TEST.STUB:uut_prototype_stubs.close
TEST.VALUE:dk_bspal_display.<<GLOBAL>>.l_disp:EBspalDisplayState_Disconnected
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.devctl.dcmd:3
TEST.EXPECTED:dk_bspal_display.<<GLOBAL>>.l_disp:EBspalDisplayState_Off
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_get_state.return:0
TEST.EXPECTED:uut_prototype_stubs.close.VCAST_PARAM_1:0
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_1:"/dev/display/display0/state"
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_2:0
TEST.EXPECTED:uut_prototype_stubs.devctl.fd:0
TEST.EXPECTED:uut_prototype_stubs.devctl.dcmd:3
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.devctl.dev_data_ptr
display_state_buffer_type_ts *state_ptr;
state_ptr = (display_state_buffer_type_ts *)<<uut_prototype_stubs.devctl.dev_data_ptr>>;
state_ptr->state = DISPLAY_ESTATE_OFF;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:dk_bspal_display.dk_bspal_display_get_state.p_value_EP
<<dk_bspal_display.dk_bspal_display_get_state.p_value_EP>> = &<<dk_bspal_display.<<GLOBAL>>.l_disp>>;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EBspaDisplayState_On_pass
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_get_state
TEST.NEW
TEST.NAME:EBspaDisplayState_On_pass
TEST.STUB:uut_prototype_stubs.close
TEST.VALUE:dk_bspal_display.<<GLOBAL>>.l_disp:EBspaDisplayState_Error
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.EXPECTED:dk_bspal_display.<<GLOBAL>>.l_disp:EBspaDisplayState_On
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_get_state.return:0
TEST.EXPECTED:uut_prototype_stubs.close.VCAST_PARAM_1:0
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_1:"/dev/display/display0/state"
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_2:0
TEST.EXPECTED:uut_prototype_stubs.devctl.fd:0
TEST.EXPECTED:uut_prototype_stubs.devctl.dcmd:3
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.devctl.dev_data_ptr
display_state_buffer_type_ts *state_ptr;
state_ptr = (display_state_buffer_type_ts *)<<uut_prototype_stubs.devctl.dev_data_ptr>>;
state_ptr->state = DISPLAY_ESTATE_ON;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:dk_bspal_display.dk_bspal_display_get_state.p_value_EP
<<dk_bspal_display.dk_bspal_display_get_state.p_value_EP>> = &<<dk_bspal_display.<<GLOBAL>>.l_disp>>;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: devctl_fail
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_get_state
TEST.NEW
TEST.NAME:devctl_fail
TEST.STUB:uut_prototype_stubs.close
TEST.VALUE:uut_prototype_stubs.open.return:2
TEST.VALUE:uut_prototype_stubs.devctl.return:1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_get_state.return:-1
TEST.EXPECTED:uut_prototype_stubs.close.VCAST_PARAM_1:2
TEST.FLOW
  dk_bspal_display.c.dk_bspal_display_get_state
  uut_prototype_stubs.open
  uut_prototype_stubs.devctl
  uut_prototype_stubs.close
  dk_bspal_display.c.dk_bspal_display_get_state
TEST.END_FLOW
TEST.END

-- Test Case: open_fail
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_get_state
TEST.NEW
TEST.NAME:open_fail
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_get_state.return:-1
TEST.FLOW
  dk_bspal_display.c.dk_bspal_display_get_state
  uut_prototype_stubs.open
  dk_bspal_display.c.dk_bspal_display_get_state
TEST.END_FLOW
TEST.END

-- Subprogram: dk_bspal_display_set_gamma_rgb

-- Test Case: dk_bspal_display_set_gamma_rgb.001
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_set_gamma_rgb
TEST.NEW
TEST.NAME:dk_bspal_display_set_gamma_rgb.001
TEST.VALUE:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_red_S32:7
TEST.VALUE:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_green_S32:7
TEST.VALUE:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_blue_S32:7
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_red_S32:7
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_green_S32:7
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_blue_S32:7
TEST.END

-- Test Case: dk_bspal_display_set_gamma_rgb.002
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_set_gamma_rgb
TEST.NEW
TEST.NAME:dk_bspal_display_set_gamma_rgb.002
TEST.VALUE:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_red_S32:5
TEST.VALUE:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_green_S32:5
TEST.VALUE:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_blue_S32:5
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_red_S32:5
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_green_S32:5
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_blue_S32:5
TEST.END

-- Test Case: dk_bspal_display_set_gamma_rgb.003
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_set_gamma_rgb
TEST.NEW
TEST.NAME:dk_bspal_display_set_gamma_rgb.003
TEST.VALUE:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_red_S32:-1
TEST.VALUE:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_green_S32:-1
TEST.VALUE:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_blue_S32:-1
TEST.VALUE:uut_prototype_stubs.devctl.return:1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_red_S32:-1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_green_S32:-1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_gamma_rgb.p_gamma_blue_S32:-1
TEST.END

-- Subprogram: dk_bspal_display_set_power

-- Test Case: EBspalDisplayPower_Off_Pass
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_set_power
TEST.NEW
TEST.NAME:EBspalDisplayPower_Off_Pass
TEST.STUB:uut_prototype_stubs.close
TEST.VALUE:dk_bspal_display.dk_bspal_display_set_power.p_value_E:EBspalDisplayPower_Off
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_power.return:0
TEST.EXPECTED:uut_prototype_stubs.close.VCAST_PARAM_1:1
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_1:"/dev/display/display0/power"
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_2:2
TEST.EXPECTED:uut_prototype_stubs.devctl.fd:1
TEST.EXPECTED:uut_prototype_stubs.devctl.dcmd:2
TEST.FLOW
  dk_bspal_display.c.dk_bspal_display_set_power
  uut_prototype_stubs.open
  uut_prototype_stubs.devctl
  uut_prototype_stubs.close
  dk_bspal_display.c.dk_bspal_display_set_power
TEST.END_FLOW
TEST.STUB_EXP_USER_CODE:uut_prototype_stubs.devctl.dev_data_ptr
display_power_buffer_type_ts * l_out;
l_out = (display_power_buffer_type_ts *)(<<uut_prototype_stubs.devctl.dev_data_ptr>>);
{{l_out->power_U8 == DISPLAY_EPOWER_OFF}}
TEST.END_STUB_EXP_USER_CODE:
TEST.END

-- Test Case: EBspalDisplayPower_On_pass
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_set_power
TEST.NEW
TEST.NAME:EBspalDisplayPower_On_pass
TEST.STUB:uut_prototype_stubs.close
TEST.VALUE:dk_bspal_display.dk_bspal_display_set_power.p_value_E:EBspalDisplayPower_On
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_power.return:0
TEST.EXPECTED:uut_prototype_stubs.close.VCAST_PARAM_1:1
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_1:"/dev/display/display0/power"
TEST.EXPECTED:uut_prototype_stubs.open.VCAST_PARAM_2:2
TEST.EXPECTED:uut_prototype_stubs.devctl.fd:1
TEST.EXPECTED:uut_prototype_stubs.devctl.dcmd:2
TEST.FLOW
  dk_bspal_display.c.dk_bspal_display_set_power
  uut_prototype_stubs.open
  uut_prototype_stubs.devctl
  uut_prototype_stubs.close
  dk_bspal_display.c.dk_bspal_display_set_power
TEST.END_FLOW
TEST.STUB_EXP_USER_CODE:uut_prototype_stubs.devctl.dev_data_ptr
display_power_buffer_type_ts * l_out;
l_out = (display_power_buffer_type_ts *)(<<uut_prototype_stubs.devctl.dev_data_ptr>>);
{{l_out->power_U8 == DISPLAY_EPOWER_ON}}
TEST.END_STUB_EXP_USER_CODE:
TEST.END

-- Test Case: devctl_fail
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_set_power
TEST.NEW
TEST.NAME:devctl_fail
TEST.STUB:uut_prototype_stubs.close
TEST.VALUE:uut_prototype_stubs.open.return:2
TEST.VALUE:uut_prototype_stubs.devctl.return:1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_power.return:-1
TEST.EXPECTED:uut_prototype_stubs.close.VCAST_PARAM_1:2
TEST.FLOW
  dk_bspal_display.c.dk_bspal_display_set_power
  uut_prototype_stubs.open
  uut_prototype_stubs.devctl
  uut_prototype_stubs.close
  dk_bspal_display.c.dk_bspal_display_set_power
TEST.END_FLOW
TEST.END

-- Test Case: open_fail
TEST.UNIT:dk_bspal_display
TEST.SUBPROGRAM:dk_bspal_display_set_power
TEST.NEW
TEST.NAME:open_fail
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.EXPECTED:dk_bspal_display.dk_bspal_display_set_power.return:-1
TEST.FLOW
  dk_bspal_display.c.dk_bspal_display_set_power
  uut_prototype_stubs.open
  dk_bspal_display.c.dk_bspal_display_set_power
TEST.END_FLOW
TEST.END
