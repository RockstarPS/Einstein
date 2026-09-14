-- VectorCAST 20.sp7 (04/21/21)
-- Test Case Script
--
-- Environment    : UTP_DISPLAY
-- Unit(s) Under Test: CDisplay_interface
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

-- Unit: CDisplay_interface

-- Subprogram: Deinit_Display

-- Test Case: DEINIT_TIANMA_DISPLAY_SUCCESS
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Deinit_Display
TEST.NEW
TEST.NAME:DEINIT_TIANMA_DISPLAY_SUCCESS
TEST.EXPECTED:CDisplay_interface.Deinit_Display.return:0
TEST.END

-- Subprogram: Enable_Display

-- Test Case: Set_Display_StateOff_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Enable_Display
TEST.NEW
TEST.NAME:Set_Display_StateOff_fail
TEST.STUB:CDisplay_interface.Set_Display_State
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.l_state:0
TEST.VALUE:CDisplay_interface.Set_Display_State.return:1
TEST.EXPECTED:CDisplay_interface.Enable_Display.return:1
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_value.p_value_BOOL:false
TEST.VALUE_USER_CODE:CDisplay_interface.Enable_Display.p_enable_display_U8
<<CDisplay_interface.Enable_Display.p_enable_display_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Set_Display_StateOn_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Enable_Display
TEST.NEW
TEST.NAME:Set_Display_StateOn_fail
TEST.STUB:CDisplay_interface.Set_Display_State
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.l_state:1
TEST.VALUE:CDisplay_interface.Set_Display_State.return:1
TEST.EXPECTED:CDisplay_interface.Enable_Display.return:1
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_value.p_value_BOOL:true
TEST.VALUE_USER_CODE:CDisplay_interface.Enable_Display.p_enable_display_U8
<<CDisplay_interface.Enable_Display.p_enable_display_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: dk_bspal_dio_set_valueOff_rst_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Enable_Display
TEST.NEW
TEST.NAME:dk_bspal_dio_set_valueOff_rst_fail
TEST.STUB:CDisplay_interface.Set_Display_State
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.l_state:0
TEST.VALUE:CDisplay_interface.Set_Display_State.return:0
TEST.EXPECTED:CDisplay_interface.Enable_Display.return:1
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_value.p_value_BOOL:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk_bspal_dio_set_value.return
++temp;
if(temp==1)
<<uut_prototype_stubs.dk_bspal_dio_set_value.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:CDisplay_interface.Enable_Display.p_enable_display_U8
<<CDisplay_interface.Enable_Display.p_enable_display_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: dk_bspal_dio_set_valueOff_stby_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Enable_Display
TEST.NEW
TEST.NAME:dk_bspal_dio_set_valueOff_stby_fail
TEST.STUB:CDisplay_interface.Set_Display_State
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.l_state:0
TEST.VALUE:CDisplay_interface.Set_Display_State.return:0
TEST.EXPECTED:CDisplay_interface.Enable_Display.return:0
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_value.p_value_BOOL:false
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk_bspal_dio_set_value.return
++temp;
if(temp==2)
<<uut_prototype_stubs.dk_bspal_dio_set_value.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:CDisplay_interface.Enable_Display.p_enable_display_U8
<<CDisplay_interface.Enable_Display.p_enable_display_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: dk_bspal_dio_set_valueOn_rst_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Enable_Display
TEST.NEW
TEST.NAME:dk_bspal_dio_set_valueOn_rst_fail
TEST.STUB:CDisplay_interface.Set_Display_State
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.l_state:1
TEST.EXPECTED:CDisplay_interface.Enable_Display.return:1
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_value.p_value_BOOL:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk_bspal_dio_set_value.return
++temp;
if(temp==1)
<<uut_prototype_stubs.dk_bspal_dio_set_value.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:CDisplay_interface.Enable_Display.p_enable_display_U8
<<CDisplay_interface.Enable_Display.p_enable_display_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: dk_bspal_dio_set_valueOn_stby_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Enable_Display
TEST.NEW
TEST.NAME:dk_bspal_dio_set_valueOn_stby_fail
TEST.STUB:CDisplay_interface.Set_Display_State
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.l_state:1
TEST.VALUE:CDisplay_interface.Set_Display_State.return:0
TEST.EXPECTED:CDisplay_interface.Enable_Display.return:0
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_value.p_value_BOOL:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk_bspal_dio_set_value.return
++temp;
if(temp==2)
<<uut_prototype_stubs.dk_bspal_dio_set_value.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:CDisplay_interface.Enable_Display.p_enable_display_U8
<<CDisplay_interface.Enable_Display.p_enable_display_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: invalid_parameter
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Enable_Display
TEST.NEW
TEST.NAME:invalid_parameter
TEST.STUB:CDisplay_interface.Set_Display_State
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.l_state:3
TEST.EXPECTED:CDisplay_interface.Enable_Display.return:1
TEST.VALUE_USER_CODE:CDisplay_interface.Enable_Display.p_enable_display_U8
<<CDisplay_interface.Enable_Display.p_enable_display_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: Get_Display_Power

-- Test Case: Get_Display_Power_off
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Get_Display_Power
TEST.NEW
TEST.NAME:Get_Display_Power_off
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.lcd_on_BOOL:true
TEST.EXPECTED:CDisplay_interface.<<GLOBAL>>.l_state:MACRO=DISPLAY_EPOWER_ON
TEST.VALUE_USER_CODE:CDisplay_interface.Get_Display_Power.p_power_U8
<<CDisplay_interface.Get_Display_Power.p_power_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Get_Display_Power_on
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Get_Display_Power
TEST.NEW
TEST.NAME:Get_Display_Power_on
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.lcd_on_BOOL:false
TEST.EXPECTED:CDisplay_interface.<<GLOBAL>>.l_state:MACRO=DISPLAY_EPOWER_OFF
TEST.VALUE_USER_CODE:CDisplay_interface.Get_Display_Power.p_power_U8
<<CDisplay_interface.Get_Display_Power.p_power_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: Get_Display_Power_Devctl

-- Test Case: Get_Display_Power_Devctl_off
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Get_Display_Power_Devctl
TEST.NEW
TEST.NAME:Get_Display_Power_Devctl_off
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.lcd_on_BOOL:false
TEST.EXPECTED:CDisplay_interface.<<GLOBAL>>.l_state:MACRO=DISPLAY_EPOWER_OFF
TEST.VALUE_USER_CODE:CDisplay_interface.Get_Display_Power_Devctl.p_value_U8
<<CDisplay_interface.Get_Display_Power_Devctl.p_value_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Get_Display_Power_Devctl_on
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Get_Display_Power_Devctl
TEST.NEW
TEST.NAME:Get_Display_Power_Devctl_on
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.lcd_on_BOOL:true
TEST.EXPECTED:CDisplay_interface.<<GLOBAL>>.l_state:MACRO=DISPLAY_EPOWER_ON
TEST.VALUE_USER_CODE:CDisplay_interface.Get_Display_Power_Devctl.p_value_U8
<<CDisplay_interface.Get_Display_Power_Devctl.p_value_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: Get_Display_Thermal_Temperature_Value

-- Test Case: Get_Display_Thermal_Temperature_Value.001
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Get_Display_Thermal_Temperature_Value
TEST.NEW
TEST.NAME:Get_Display_Thermal_Temperature_Value.001
TEST.VALUE:CDisplay_interface.Get_Display_Thermal_Temperature_Value.p_value_U8:<<malloc 2>>
TEST.VALUE:CDisplay_interface.Get_Display_Thermal_Temperature_Value.p_value_U8:"1"
TEST.EXPECTED:CDisplay_interface.Get_Display_Thermal_Temperature_Value.return:0
TEST.END

-- Subprogram: Get_Display_Thermal_Temperature_Value_Devctl

-- Test Case: Get_Display_Thermal_Temperature_Value_Devctl.001
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Get_Display_Thermal_Temperature_Value_Devctl
TEST.NEW
TEST.NAME:Get_Display_Thermal_Temperature_Value_Devctl.001
TEST.VALUE:CDisplay_interface.Get_Display_Thermal_Temperature_Value_Devctl.p_temp_U32:<<malloc 1>>
TEST.EXPECTED:CDisplay_interface.Get_Display_Thermal_Temperature_Value_Devctl.return:0
TEST.END

-- Subprogram: Get_Display_state

-- Test Case: DISPLAY_STATE_OFF
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Get_Display_state
TEST.NEW
TEST.NAME:DISPLAY_STATE_OFF
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.lcd_on_BOOL:false
TEST.VALUE:CDisplay_interface.Get_Display_state.p_state_U8:<<malloc 1>>
TEST.VALUE:CDisplay_interface.Get_Display_state.p_state_U8:""
TEST.EXPECTED:CDisplay_interface.Get_Display_state.return:0
TEST.EXPECTED_USER_CODE:CDisplay_interface.Get_Display_state.p_state_U8
{{ strcmp((char*)(<<CDisplay_interface.Get_Display_state.p_state_U8>>),"OFF\n") == (0) }}

TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Test Case: DISPLAY_STATE_ON
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Get_Display_state
TEST.NEW
TEST.NAME:DISPLAY_STATE_ON
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.lcd_on_BOOL:true
TEST.VALUE_USER_CODE:CDisplay_interface.Get_Display_state.p_state_U8
<<CDisplay_interface.Get_Display_state.p_state_U8>> = &<<CDisplay_interface.<<GLOBAL>>.l_state>>;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_USER_CODE:CDisplay_interface.Get_Display_state.p_state_U8
char *state = (char*)(&l_state);
{{ strcmp(state, "ON\n") == 0 }}


TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Subprogram: Get_Display_state_Devctl

-- Test Case: DISPLAY_ESTATE_OFF
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Get_Display_state_Devctl
TEST.NEW
TEST.NAME:DISPLAY_ESTATE_OFF
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.lcd_on_BOOL:false
TEST.EXPECTED:CDisplay_interface.<<GLOBAL>>.l_state:MACRO=DISPLAY_ESTATE_OFF
TEST.VALUE_USER_CODE:CDisplay_interface.Get_Display_state_Devctl.p_value_U8
<<CDisplay_interface.Get_Display_state_Devctl.p_value_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_ESTATE_ON
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Get_Display_state_Devctl
TEST.NEW
TEST.NAME:DISPLAY_ESTATE_ON
TEST.VALUE:CDisplay_interface.<<GLOBAL>>.lcd_on_BOOL:true
TEST.EXPECTED:CDisplay_interface.<<GLOBAL>>.l_state:MACRO=DISPLAY_ESTATE_ON
TEST.VALUE_USER_CODE:CDisplay_interface.Get_Display_state_Devctl.p_value_U8
<<CDisplay_interface.Get_Display_state_Devctl.p_value_U8>> = &<<dk_bspal_display_proxy.<<GLOBAL>>.l_state>>;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: Init_Display

-- Test Case: set_direction_con_pin_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Init_Display
TEST.NEW
TEST.NAME:set_direction_con_pin_fail
TEST.VALUE:uut_prototype_stubs.dk_bspal_dio_set_direction.return:1
TEST.EXPECTED:CDisplay_interface.Init_Display.return:1
TEST.END

-- Test Case: set_direction_lcd_pin_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Init_Display
TEST.NEW
TEST.NAME:set_direction_lcd_pin_fail
TEST.VALUE:uut_prototype_stubs.dk_bspal_dio_set_value.return:1
TEST.EXPECTED:CDisplay_interface.Init_Display.return:1
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_direction.p_pin_U8:MACRO=DO_RESET_TFT
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_direction.p_direction_te:e_gpio_direction_out
TEST.END

-- Test Case: set_direction_reset_pin_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Init_Display
TEST.NEW
TEST.NAME:set_direction_reset_pin_fail
TEST.EXPECTED:CDisplay_interface.Init_Display.return:0
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_value.p_pin_U8:MACRO=DO_RESET_TFT
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_value.p_value_BOOL:false
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_direction.p_pin_U8:MACRO=DO_RESET_TFT
TEST.EXPECTED:uut_prototype_stubs.dk_bspal_dio_set_direction.p_direction_te:e_gpio_direction_out
TEST.END

-- Subprogram: Set_Display_State

-- Test Case: display_count_greater_then_1
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Set_Display_State
TEST.NEW
TEST.NAME:display_count_greater_then_1
TEST.VALUE:uut_prototype_stubs.screen_create_context.return:0
TEST.EXPECTED:CDisplay_interface.Set_Display_State.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.screen_get_context_property_iv.param
int32_t *l_param;
l_param = <<uut_prototype_stubs.screen_get_context_property_iv.param>>;
*l_param = 3;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: display_count_zero
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Set_Display_State
TEST.NEW
TEST.NAME:display_count_zero
TEST.VALUE:CDisplay_interface.Set_Display_State.p_onflag:1
TEST.VALUE:uut_prototype_stubs.screen_create_context.return:0
TEST.EXPECTED:CDisplay_interface.Set_Display_State.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.screen_get_context_property_iv.param
int32_t *l_param;
l_param = <<uut_prototype_stubs.screen_get_context_property_iv.param>>;
*l_param = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: display_state_off
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Set_Display_State
TEST.NEW
TEST.NAME:display_state_off
TEST.VALUE:CDisplay_interface.Set_Display_State.p_onflag:0
TEST.VALUE:uut_prototype_stubs.screen_create_context.return:0
TEST.EXPECTED:CDisplay_interface.Set_Display_State.return:0
TEST.EXPECTED:uut_prototype_stubs.screen_create_context.flags:MACRO=SCREEN_POWER_MANAGER_CONTEXT
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.screen_get_display_property_iv.param
int32_t *pow1;
pow1 = <<uut_prototype_stubs.screen_get_display_property_iv.param>>;
*pow1 = ( int ) SCREEN_POWER_MODE_OFF;


TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.screen_set_display_property_iv.param
int *power1;
power1 = <<uut_prototype_stubs.screen_set_display_property_iv.param>>;
*power1 = ((int)SCREEN_POWER_MODE_OFF);
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: display_state_on
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Set_Display_State
TEST.NEW
TEST.NAME:display_state_on
TEST.VALUE:CDisplay_interface.Set_Display_State.p_onflag:1
TEST.VALUE:uut_prototype_stubs.screen_create_context.return:0
TEST.EXPECTED:CDisplay_interface.Set_Display_State.return:0
TEST.EXPECTED:uut_prototype_stubs.screen_create_context.flags:MACRO=SCREEN_POWER_MANAGER_CONTEXT
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.screen_get_display_property_iv.param
int32_t *pow1;
pow1 = <<uut_prototype_stubs.screen_get_display_property_iv.param>>;
*pow1 = ( int ) SCREEN_POWER_MODE_ON;


TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.screen_set_display_property_iv.param
int *power1;
power1 = <<uut_prototype_stubs.screen_set_display_property_iv.param>>;
*power1 = ((int)SCREEN_POWER_MODE_ON);
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: display_state_vfn_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Set_Display_State
TEST.NEW
TEST.NAME:display_state_vfn_fail
TEST.VALUE:CDisplay_interface.Set_Display_State.p_onflag:0
TEST.VALUE:uut_prototype_stubs.screen_create_context.return:0
TEST.EXPECTED:CDisplay_interface.Set_Display_State.return:1
TEST.EXPECTED:uut_prototype_stubs.screen_create_context.flags:MACRO=SCREEN_POWER_MANAGER_CONTEXT
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.screen_get_display_property_iv.param
int32_t *pow1;
pow1 = <<uut_prototype_stubs.screen_get_display_property_iv.param>>;
*pow1 = ( int ) SCREEN_POWER_MODE_OFF;


TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.screen_set_display_property_iv.param
int *power1;
power1 = <<uut_prototype_stubs.screen_set_display_property_iv.param>>;
*power1 = ((int)SCREEN_POWER_MODE_ON);
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: screen_create_context_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Set_Display_State
TEST.NEW
TEST.NAME:screen_create_context_fail
TEST.VALUE:uut_prototype_stubs.screen_create_context.return:1
TEST.EXPECTED:CDisplay_interface.Set_Display_State.return:1
TEST.END

-- Test Case: screen_get_context_property_iv_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Set_Display_State
TEST.NEW
TEST.NAME:screen_get_context_property_iv_fail
TEST.VALUE:CDisplay_interface.Set_Display_State.p_onflag:1
TEST.VALUE:uut_prototype_stubs.screen_create_context.return:0
TEST.VALUE:uut_prototype_stubs.screen_get_context_property_iv.return:1
TEST.EXPECTED:CDisplay_interface.Set_Display_State.return:1
TEST.END

-- Test Case: screen_get_context_property_pv_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Set_Display_State
TEST.NEW
TEST.NAME:screen_get_context_property_pv_fail
TEST.VALUE:uut_prototype_stubs.screen_create_context.return:0
TEST.VALUE:uut_prototype_stubs.screen_get_context_property_iv.return:0
TEST.VALUE:uut_prototype_stubs.screen_get_context_property_pv.return:1
TEST.EXPECTED:CDisplay_interface.Set_Display_State.return:1
TEST.END

-- Test Case: screen_get_display_property_iv_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Set_Display_State
TEST.NEW
TEST.NAME:screen_get_display_property_iv_fail
TEST.VALUE:uut_prototype_stubs.screen_create_context.return:0
TEST.VALUE:uut_prototype_stubs.screen_get_context_property_iv.return:0
TEST.VALUE:uut_prototype_stubs.screen_get_context_property_pv.return:0
TEST.VALUE:uut_prototype_stubs.screen_get_display_property_iv.return:1
TEST.VALUE:uut_prototype_stubs.screen_set_display_property_iv.return:0
TEST.EXPECTED:CDisplay_interface.Set_Display_State.return:1
TEST.END

-- Test Case: screen_get_display_property_iv_fail_errno
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Set_Display_State
TEST.NEW
TEST.NAME:screen_get_display_property_iv_fail_errno
TEST.VALUE:uut_prototype_stubs.screen_create_context.return:0
TEST.VALUE:uut_prototype_stubs.screen_get_context_property_iv.return:0
TEST.VALUE:uut_prototype_stubs.screen_get_context_property_pv.return:0
TEST.VALUE:uut_prototype_stubs.screen_get_display_property_iv.return:1
TEST.VALUE:uut_prototype_stubs.screen_set_display_property_iv.return:0
TEST.EXPECTED:CDisplay_interface.Set_Display_State.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.__get_errno_ptr.return
int32_t val = 4;
<<uut_prototype_stubs.__get_errno_ptr.return>> = &(val );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: screen_set_display_property_iv_fail
TEST.UNIT:CDisplay_interface
TEST.SUBPROGRAM:Set_Display_State
TEST.NEW
TEST.NAME:screen_set_display_property_iv_fail
TEST.VALUE:uut_prototype_stubs.screen_create_context.return:0
TEST.VALUE:uut_prototype_stubs.screen_get_context_property_iv.return:0
TEST.VALUE:uut_prototype_stubs.screen_get_context_property_pv.return:0
TEST.VALUE:uut_prototype_stubs.screen_set_display_property_iv.return:1
TEST.EXPECTED:CDisplay_interface.Set_Display_State.return:1
TEST.END
