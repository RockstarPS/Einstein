-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UTP_DISPLAY_RM
-- Unit(s) Under Test: CDisplay_RM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CDisplay_RM

-- Subprogram: CDisplay_Deinit

-- Test Case: CDisplay_Deinit.001
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_Deinit
TEST.NEW
TEST.NAME:CDisplay_Deinit.001
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.P_Dll_Hdl:<<null>>
TEST.VALUE:CDisplay_RM.CDisplay_Deinit.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_Deinit.return:0
TEST.END

-- Test Case: DEINIT_DISPLAY_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_Deinit
TEST.NEW
TEST.NAME:DEINIT_DISPLAY_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:1
TEST.VALUE:uut_prototype_stubs.dlclose.return:0
TEST.VALUE_USER_CODE:<<testcase>>
displayDev.drventry_S = &display_drv_entry_stub;
displayDev.P_Dll_Hdl = (int *) malloc(sizeof(int));
{{ CDisplay_Deinit()== 1 }}

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_DEINIT_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_Deinit
TEST.NEW
TEST.NAME:DISPLAY_DEINIT_SUCCESS
TEST.VALUE:uut_prototype_stubs.dlclose.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_Deinit.return:0
TEST.VALUE_USER_CODE:<<testcase>>
displayDev.drventry_S = &display_drv_entry_stub;
displayDev.P_Dll_Hdl = (int *) malloc(sizeof(int));
{{ CDisplay_Deinit()== 0 }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DLL_CLOSE_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_Deinit
TEST.NEW
TEST.NAME:DLL_CLOSE_FAIL
TEST.VALUE:uut_prototype_stubs.dlclose.return:1
TEST.VALUE_USER_CODE:<<testcase>>
displayDev.drventry_S = &display_drv_entry_stub;
displayDev.P_Dll_Hdl = (int *) malloc(sizeof(int));
{{ CDisplay_Deinit()== 1 }}

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DLL_NULL_DEINIT_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_Deinit
TEST.NEW
TEST.NAME:DLL_NULL_DEINIT_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:1
TEST.VALUE:uut_prototype_stubs.dlclose.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_Deinit.return:1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CDisplay_Hw_Init

-- Test Case: DISPLAY_DLL_LOAD_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_Hw_Init
TEST.NEW
TEST.NAME:DISPLAY_DLL_LOAD_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP[0].dl_load_path:<<malloc 17>>
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP[0].dl_load_path:"libdisplay_if.so"
TEST.VALUE:uut_prototype_stubs.dlopen.return:<<null>>
TEST.VALUE:uut_prototype_stubs.dlsym.return:<<null>>
TEST.EXPECTED:CDisplay_RM.CDisplay_Hw_Init.return:1
TEST.END

-- Test Case: DLL_SYM_LOAD_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_Hw_Init
TEST.NEW
TEST.NAME:DLL_SYM_LOAD_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP[0].dl_load_path:<<malloc 17>>
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP[0].dl_load_path:"libdisplay_if.so"
TEST.VALUE:uut_prototype_stubs.dlsym.return:<<null>>
TEST.EXPECTED:CDisplay_RM.CDisplay_Hw_Init.return:1
TEST.END

-- Test Case: HW_INIT_DISPLAY_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_Hw_Init
TEST.NEW
TEST.NAME:HW_INIT_DISPLAY_FAIL
TEST.STUB:CDisplay_RM.CDisplay_Dlload
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:1
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_Dlload.return:display_drv_entry_stub
TEST.EXPECTED:CDisplay_RM.CDisplay_Hw_Init.return:1
TEST.END

-- Test Case: HW_INIT_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_Hw_Init
TEST.NEW
TEST.NAME:HW_INIT_SUCCESS
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP[0].dl_load_path:<<malloc 17>>
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP[0].dl_load_path:"libdisplay_if.so"
TEST.VALUE:uut_prototype_stubs.dlopen.return:display_drv_entry_stub
TEST.VALUE:uut_prototype_stubs.dlsym.return:display_drv_entry_stub
TEST.EXPECTED:CDisplay_RM.CDisplay_Hw_Init.return:0
TEST.END

-- Test Case: HW_INIT_SUCCESS.001
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_Hw_Init
TEST.NEW
TEST.NAME:HW_INIT_SUCCESS.001
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP[0].dl_load_path:<<malloc 17>>
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.p_display_dev_SP[0].dl_load_path:"libdisplay_if.so"
TEST.VALUE:uut_prototype_stubs.dlopen.return:display_drv_entry_stub
TEST.VALUE:uut_prototype_stubs.dlsym.return:<<null>>
TEST.EXPECTED:CDisplay_RM.CDisplay_Hw_Init.return:1
TEST.END

-- Subprogram: CDisplay_RM_ExitSignal

-- Test Case: Display_RM_EXIT_SIGNAL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ExitSignal
TEST.NEW
TEST.NAME:Display_RM_EXIT_SIGNAL
TEST.VALUE:CDisplay_RM.CDisplay_RM_ExitSignal.p_signo_SINT:1
TEST.EXPECTED:CDisplay_RM.<<GLOBAL>>.t_display_done_SINT:1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_ExitSignal.p_signo_SINT:1
TEST.END

-- Subprogram: CDisplay_RM_Init

-- Test Case: CDISPLAY_RM_INIT_DISPATCH_CREATE_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:CDISPLAY_RM_INIT_DISPATCH_CREATE_FAIL
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:12
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:12
TEST.END

-- Test Case: RESMGR_ATTACH_DISPLAY_POWER_PATH_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:RESMGR_ATTACH_DISPLAY_POWER_PATH_FAIL
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:1
TEST.END

-- Test Case: RESMGR_ATTACH_DISPLAY_POWER_STATE_PATH_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:RESMGR_ATTACH_DISPLAY_POWER_STATE_PATH_FAIL
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1,-1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:1
TEST.END

-- Test Case: RESMGR_ATTACH_GAMMA_BLUE_VAL_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:RESMGR_ATTACH_GAMMA_BLUE_VAL_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.p_ctp_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:061
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(4)1,-1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:1
TEST.END

-- Test Case: RESMGR_ATTACH_GAMMA_GREEN_VAL_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:RESMGR_ATTACH_GAMMA_GREEN_VAL_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.p_ctp_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:061
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(3)1,-1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:1
TEST.END

-- Test Case: RESMGR_ATTACH_THEMAL_TEMP_TYPE_PATH_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:RESMGR_ATTACH_THEMAL_TEMP_TYPE_PATH_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.p_ctp_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:061
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(6)1,-1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:1
TEST.END

-- Test Case: RESMGR_ATTACH_THEMAL_TEMP_VAL_PATH_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:RESMGR_ATTACH_THEMAL_TEMP_VAL_PATH_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.p_ctp_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:061
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(5)1,-1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:1
TEST.END

-- Test Case: RESMGR_ATTACH_THERMAL_TEMP_TYPE_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:RESMGR_ATTACH_THERMAL_TEMP_TYPE_FAIL
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(3)1,-1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:1
TEST.END

-- Test Case: RESMGR_ATTACH_THERMAL_TEMP_VAL_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:RESMGR_ATTACH_THERMAL_TEMP_VAL_FAIL
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(2)1,-1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:1
TEST.END

-- Test Case: RM_INIT_DISPATCH_CONTEXT_ALLOC_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:RM_INIT_DISPATCH_CONTEXT_ALLOC_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:'1'
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(4)1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.END

-- Test Case: RM_INIT_DISPATCH_CONTEXT_ALLOC_FAIL.001
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:RM_INIT_DISPATCH_CONTEXT_ALLOC_FAIL.001
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.p_ctp_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:061
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(4)1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:1
TEST.ATTRIBUTES:CDisplay_RM.<<GLOBAL>>.UserParm[0]:EXPECTED_BASE=8
TEST.END

-- Test Case: RM_INIT_DISPATCH_CONTEXT_ALLOC_USER_PARAM_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Init
TEST.NEW
TEST.NAME:RM_INIT_DISPATCH_CONTEXT_ALLOC_USER_PARAM_FAIL
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:(4)1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.END

-- Subprogram: CDisplay_RM_ParseOptions

-- Test Case: OPTION_CASE_D_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_CASE_D_FAIL
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.STUB:uut_prototype_stubs.strlen
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg[0]:'0'
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:0144
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 2>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 3>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-:"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.strlen.return:1049
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.ATTRIBUTES:CDisplay_RM.getopt_chk.p_opt[0]:EXPECTED_BASE=8
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
if(strcmp(<<uut_prototype_stubs.strtoul.VCAST_PARAM_1>> , "1") == 0 )
{
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
}


TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: OPTION_CASE_L_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_CASE_L_FAIL
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.STUB:uut_prototype_stubs.strlen
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg[0]:'0'
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:0154
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 2>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 3>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-:"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.strlen.return:1049
TEST.VALUE:uut_prototype_stubs.getopt.return:112
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.ATTRIBUTES:CDisplay_RM.getopt_chk.p_opt[0]:EXPECTED_BASE=8
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
if(strcmp(<<uut_prototype_stubs.strtoul.VCAST_PARAM_1>> , "1") == 0 )
{
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
}


TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: OPTION_CASE_U
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_CASE_U
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg[0]:'0'
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:0125
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 2>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 3>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-:"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.VALUE:uut_prototype_stubs.getopt.return:112
TEST.EXPECTED:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
if(strcmp(<<uut_prototype_stubs.strtoul.VCAST_PARAM_1>> , "1") == 0 )
{
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
}


TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: OPTION_COLON_ERANGE_ERROR.001
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_COLON_ERANGE_ERROR.001
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_unit_U32:22
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg[0]:'0'
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:0160
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 2>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 3>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-:"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:026
TEST.EXPECTED:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
if(strcmp(<<uut_prototype_stubs.strtoul.VCAST_PARAM_1>> , "1") == 0 )
{
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
}


TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP.p_display_dev_SP[0].display_unit_U32
<<CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP>>[0].display_unit_U32 = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: OPTION_COLON_ERANGE_ERROR.002
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_COLON_ERANGE_ERROR.002
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:0164
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 2>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 3>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-:"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.optarg:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.optarg[0]:'2'
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.EXPECTED:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
if(strcmp(<<uut_prototype_stubs.strtoul.VCAST_PARAM_1>> , "1") == 0 )
{
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
}


TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: OPTION_COLON_ERANGE_ERROR.003
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_COLON_ERANGE_ERROR.003
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg[0]:'0'
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:0144
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 2>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 3>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-:"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.EXPECTED:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.ATTRIBUTES:CDisplay_RM.getopt_chk.p_opt[0]:EXPECTED_BASE=8
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
if(strcmp(<<uut_prototype_stubs.strtoul.VCAST_PARAM_1>> , "1") == 0 )
{
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
}


TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: OPTION_COLON_ERANGE_ERROR.004
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_COLON_ERANGE_ERROR.004
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optarg[0]:'0'
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:0154
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 2>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 3>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-:"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.VALUE:uut_prototype_stubs.getopt.return:112
TEST.EXPECTED:CDisplay_RM.<<GLOBAL>>.g_status:0
TEST.ATTRIBUTES:CDisplay_RM.getopt_chk.p_opt[0]:EXPECTED_BASE=8
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
if(strcmp(<<uut_prototype_stubs.strtoul.VCAST_PARAM_1>> , "1") == 0 )
{
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
}


TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: OPTION_COLON_ERANGE_ERROR.005
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_COLON_ERANGE_ERROR.005
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:077
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 2>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 3>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-:"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.getopt_chk.p_opt[0]:\0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
if(strcmp(<<uut_prototype_stubs.strtoul.VCAST_PARAM_1>> , "1") == 0 )
{
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
}


TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: OPTION_P_EINVAL_ERROR.001
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_P_EINVAL_ERROR.001
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:0160
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:4
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-p0"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[2]:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[2]:"-t0"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[3]:<<malloc 9>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[3]:"-llib.so"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:22
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
errno = EINVAL;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: OPTION_P_ERANGE_ERROR
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_P_ERANGE_ERROR
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:0160
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:4
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-p0"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[2]:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[2]:"-t0"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[3]:<<malloc 9>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[3]:"-llib.so"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[4]:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[4]:"-z0"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:026
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.ATTRIBUTES:CDisplay_RM.getopt_chk.p_opt[0]:EXPECTED_BASE=8
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: OPTION_T_EINVAL_ERROR.002
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_T_EINVAL_ERROR.002
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:0164
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:4
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-p0"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[2]:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[2]:"-t0"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[3]:<<malloc 9>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[3]:"-llib.so"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:026
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.ATTRIBUTES:CDisplay_RM.getopt_chk.p_opt[0]:EXPECTED_BASE=8
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
errno = EINVAL;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: OPTION_T_ERANGE_ERROR
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_T_ERANGE_ERROR
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:4
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-p0"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[2]:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[2]:"-t1"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[3]:<<malloc 9>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[3]:"-llib.so"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:026
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.ATTRIBUTES:CDisplay_RM.getopt_chk.p_opt[0]:INPUT_BASE=8,EXPECTED_BASE=8
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
if(strcmp(<<uut_prototype_stubs.strtoul.VCAST_PARAM_1>> , "1") == 0 )
{
errno = EINVAL;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
}


TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: OPTION_T_ERANGE_ERROR.001
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_ParseOptions
TEST.NEW
TEST.NAME:OPTION_T_ERANGE_ERROR.001
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.getopt_chk.p_opt[0]:0164
TEST.VALUE:CDisplay_RM.getopt_chk.return:true
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argc_SINT:4
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:<<malloc 5>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[0]:"main"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[1]:"-p0"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[2]:<<malloc 4>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[2]:"-t0"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[3]:<<malloc 9>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_argv_CHAR[3]:"-llib.so"
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.p_display_dev_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:026
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.ATTRIBUTES:CDisplay_RM.getopt_chk.p_opt[0]:EXPECTED_BASE=8
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: CDisplay_RM_Terminate

-- Test Case: DISPLAY_RM_TERMINATE_01
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Terminate
TEST.NEW
TEST.NAME:DISPLAY_RM_TERMINATE_01
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.p_dpp_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_destroy.return:-1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Terminate.return:1
TEST.END

-- Test Case: DISPLAY_RM_TERMINATE_02
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Terminate
TEST.NEW
TEST.NAME:DISPLAY_RM_TERMINATE_02
TEST.STUB:CDisplay_RM.CDisplay_Deinit
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_power_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_state_path_id_S32:2
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.thermal_temp_val_path_id_S32:3
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.thermal_temp_type_path_id_S32:4
TEST.VALUE:CDisplay_RM.CDisplay_Deinit.return:1
TEST.VALUE:uut_prototype_stubs.dlclose.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Terminate.return:1
TEST.END

-- Test Case: DISPLAY_RM_TERMINATE_03
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_Terminate
TEST.NEW
TEST.NAME:DISPLAY_RM_TERMINATE_03
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.p_dpp_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_destroy.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_Terminate.return:0
TEST.END

-- Subprogram: CDisplay_RM_io_devctl

-- Test Case: DISPLAY_GAMMA_RED_DEFAULT
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_RED_DEFAULT
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.END

-- Test Case: DISPLAY_GAMMA_RED_READ_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_RED_READ_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:4
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:uut_prototype_stubs.Get_Gamma_RGB_Devctl_FuncPtr.return:1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Get_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Get_Gamma_RGB_Devctl = ( Get_Gamma_RGB_Devctl_FuncPtr );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_RED_READ_SUCCEED
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_RED_READ_SUCCEED
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:4
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:uut_prototype_stubs.Get_Gamma_RGB_Devctl_FuncPtr.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Get_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Get_Gamma_RGB_Devctl = ( Get_Gamma_RGB_Devctl_FuncPtr );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_RED_WRITE_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_RED_WRITE_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:5
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:uut_prototype_stubs.Set_Gamma_RGB_Devctl_FuncPtr.return:1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Set_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Set_Gamma_RGB_Devctl = ( Set_Gamma_RGB_Devctl_FuncPtr );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_RED_WRITE_SUCCEED
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_RED_WRITE_SUCCEED
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:5
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:uut_prototype_stubs.Set_Gamma_RGB_Devctl_FuncPtr.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Set_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Set_Gamma_RGB_Devctl = ( Set_Gamma_RGB_Devctl_FuncPtr );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: INVALID_PATH_ID_FOR_DEVCTL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:INVALID_PATH_ID_FOR_DEVCTL
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:-1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:-1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: IOFUNC_DEVCTL_DEFAULT_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:IOFUNC_DEVCTL_DEFAULT_FAIL
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: POWER_ID_VALUE_INVALID_DEVCTL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:POWER_ID_VALUE_INVALID_DEVCTL
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:-1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: POWER_ID_VALUE_READ_DEVCTL_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:POWER_ID_VALUE_READ_DEVCTL_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: POWER_ID_VALUE_READ_DEVCTL_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:POWER_ID_VALUE_READ_DEVCTL_SUCCESS
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: POWER_ID_VALUE_WRITE_DEVCTL_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:POWER_ID_VALUE_WRITE_DEVCTL_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: POWER_ID_VALUE_WRITE_DEVCTL_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:POWER_ID_VALUE_WRITE_DEVCTL_SUCCESS
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: STATE_ID_VALUE_READ_DEVCTL_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:STATE_ID_VALUE_READ_DEVCTL_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_state_path_id = 1;
dev.display_state_path_id_S32 = l_state_path_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: STATE_ID_VALUE_READ_DEVCTL_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:STATE_ID_VALUE_READ_DEVCTL_SUCCESS
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_state_path_id = 1;
dev.display_state_path_id_S32 = l_state_path_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: STATE_ID_VALUE_READ_INVALID_DEVCTL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:STATE_ID_VALUE_READ_INVALID_DEVCTL
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:-1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_state_path_id = 1;
dev.display_state_path_id_S32 = l_state_path_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: THERMAL_TEMPERATURE_READ_DEVCTL_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:THERMAL_TEMPERATURE_READ_DEVCTL_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_tempval_id = 1;
dev.thermal_temp_val_path_id_S32 = l_tempval_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: THERMAL_TEMPERATURE_READ_DEVCTL_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:THERMAL_TEMPERATURE_READ_DEVCTL_SUCCESS
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_tempval_id = 1;
dev.thermal_temp_val_path_id_S32 = l_tempval_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: THERMAL_TEMPERATURE_READ_INVALID_DEVCTL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:THERMAL_TEMPERATURE_READ_INVALID_DEVCTL
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:-1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_tempval_id = 1;
dev.thermal_temp_val_path_id_S32 = l_tempval_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: THERMAL_TYPE_READ_DEVCTL_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:THERMAL_TYPE_READ_DEVCTL_SUCCESS
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_temptype_id = 1;
dev.thermal_temp_type_path_id_S32 = l_temptype_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: THERMAL_TYPE_READ_INVALID_DEVCTL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_devctl
TEST.NEW
TEST.NAME:THERMAL_TYPE_READ_INVALID_DEVCTL
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_msg_UP[0].i.dcmd:-1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_devctl.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_devctl.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_temptype_id = 1;
dev.thermal_temp_type_path_id_S32 = l_temptype_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CDisplay_RM_io_open

-- Test Case: CDisplay_RM_io_open.001
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_open
TEST.NEW
TEST.NAME:CDisplay_RM_io_open.001
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_open.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_open.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_open.p_handle_SP:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_open.return:0
TEST.END

-- Test Case: CDisplay_RM_io_open.002
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_open
TEST.NEW
TEST.NAME:CDisplay_RM_io_open.002
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_open.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_open.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_open.p_handle_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_open_default.return:28
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_open.return:12
TEST.END

-- Subprogram: CDisplay_RM_io_read

-- Test Case: DISPLAYPOWER_IO_READ_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:DISPLAYPOWER_IO_READ_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_power_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAYPOWER_IO_READ_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:DISPLAYPOWER_IO_READ_SUCCESS
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_power_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP[0].i.nbytes:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr[0].nbytes:1
TEST.VALUE:uut_prototype_stubs.min.return:1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAYSTATE_IO_READ_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:DISPLAYSTATE_IO_READ_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_power_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_statepath_id = 1;
dev.display_state_path_id_S32 = l_statepath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAYSTATE_IO_READ_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:DISPLAYSTATE_IO_READ_SUCCESS
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_power_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:0
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_statepath_id = 1;
dev.display_state_path_id_S32 = l_statepath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_BLUE_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_BLUE_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_green_path_id_S32:2
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_blue_path_id_S32:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:uut_prototype_stubs.Get_Gamma_RGB_Devctl_FuncPtr.return:1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:1
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Get_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Get_Gamma_RGB_Devctl = ( Get_Gamma_RGB_Devctl_FuncPtr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_BLUE_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_BLUE_SUCCESS
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_green_path_id_S32:2
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_blue_path_id_S32:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:uut_prototype_stubs.Get_Gamma_RGB_Devctl_FuncPtr.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:0
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Get_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Get_Gamma_RGB_Devctl = ( Get_Gamma_RGB_Devctl_FuncPtr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_GREEN_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_GREEN_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_green_path_id_S32:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:uut_prototype_stubs.Get_Gamma_RGB_Devctl_FuncPtr.return:1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:1
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Get_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Get_Gamma_RGB_Devctl = ( Get_Gamma_RGB_Devctl_FuncPtr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_GREEN_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_GREEN_SUCCESS
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_green_path_id_S32:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:uut_prototype_stubs.Get_Gamma_RGB_Devctl_FuncPtr.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:0
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Get_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Get_Gamma_RGB_Devctl = ( Get_Gamma_RGB_Devctl_FuncPtr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_RED_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_RED_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:uut_prototype_stubs.Get_Gamma_RGB_Devctl_FuncPtr.return:1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:1
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Get_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Get_Gamma_RGB_Devctl = ( Get_Gamma_RGB_Devctl_FuncPtr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_RED_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_RED_SUCCESS
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:0
TEST.VALUE:uut_prototype_stubs.Get_Gamma_RGB_Devctl_FuncPtr.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:0
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Get_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Get_Gamma_RGB_Devctl = ( Get_Gamma_RGB_Devctl_FuncPtr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: INVALID_PATHID
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:INVALID_PATHID
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_power_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP[0].i.nbytes:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr[0].nbytes:1
TEST.VALUE:uut_prototype_stubs.min.return:1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:-1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = -1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: IOFUNC_READ_VERIFY_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:IOFUNC_READ_VERIFY_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_power_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP[0].i.nbytes:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr[0].nbytes:1
TEST.VALUE:uut_prototype_stubs.min.return:1
TEST.VALUE:uut_prototype_stubs.iofunc_read_verify.return:1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: IO_READ_INVAID_MSG_TYPE
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:IO_READ_INVAID_MSG_TYPE
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_power_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP[0].i.nbytes:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP[0].i.xtype:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr[0].nbytes:1
TEST.VALUE:uut_prototype_stubs.min.return:1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:89
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: THERMAL_TEMP_TYPE_IO_READ_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:THERMAL_TEMP_TYPE_IO_READ_SUCCESS
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_power_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:0
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_tempval_id = 1;
dev.thermal_temp_type_path_id_S32 = l_tempval_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: THERMAL_TEMP_VAL_IO_READ_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:THERMAL_TEMP_VAL_IO_READ_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_power_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_tempval_id = 1;
dev.thermal_temp_val_path_id_S32 = l_tempval_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: THERMAL_TEMP_VAL_IO_READ_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_read
TEST.NEW
TEST.NAME:THERMAL_TEMP_VAL_IO_READ_SUCCESS
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_power_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_read.p_ocb_SP[0].attr:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_read.return:0
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_tempval_id = 1;
dev.thermal_temp_val_path_id_S32 = l_tempval_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: CDisplay_RM_io_write

-- Test Case: DISPLAY_GAMMA_BLUE_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_BLUE_FAIL
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_green_path_id_S32:2
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_blue_path_id_S32:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.Set_Gamma_RGB_Devctl_FuncPtr.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
errno = EINVAL;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Set_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Set_Gamma_RGB_Devctl = ( Set_Gamma_RGB_Devctl_FuncPtr );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_BLUE_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_BLUE_SUCCESS
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_green_path_id_S32:2
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_blue_path_id_S32:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.Set_Gamma_RGB_Devctl_FuncPtr.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:0
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Set_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Set_Gamma_RGB_Devctl = ( Set_Gamma_RGB_Devctl_FuncPtr );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_GREEN_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_GREEN_FAIL
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_green_path_id_S32:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.Set_Gamma_RGB_Devctl_FuncPtr.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
errno = EINVAL;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Set_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Set_Gamma_RGB_Devctl = ( Set_Gamma_RGB_Devctl_FuncPtr );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_GREEN_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_GREEN_SUCCESS
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_green_path_id_S32:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:2
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.Set_Gamma_RGB_Devctl_FuncPtr.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:0
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Set_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Set_Gamma_RGB_Devctl = ( Set_Gamma_RGB_Devctl_FuncPtr );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_RED_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_RED_FAIL
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:22
TEST.VALUE:uut_prototype_stubs.Set_Gamma_RGB_Devctl_FuncPtr.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:1
TEST.ATTRIBUTES:CDisplay_RM.getopt_chk.p_opt[0]::INPUT_BASE=8
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
errno = EINVAL;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Set_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Set_Gamma_RGB_Devctl = ( Set_Gamma_RGB_Devctl_FuncPtr );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_GAMMA_RED_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_GAMMA_RED_SUCCESS
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.displayDev.display_gamma_red_path_id_S32:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.VALUE:uut_prototype_stubs.Set_Gamma_RGB_Devctl_FuncPtr.return:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:0
TEST.VALUE_USER_CODE:CDisplay_RM.<<GLOBAL>>.displayDev.drventry_S.drventry_S[0].Set_Gamma_RGB_Devctl
<<CDisplay_RM.<<GLOBAL>>.displayDev>>.drventry_S[0].Set_Gamma_RGB_Devctl = ( Set_Gamma_RGB_Devctl_FuncPtr );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_POWER_WRITE_EINVAL_ERROR
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_POWER_WRITE_EINVAL_ERROR
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP[0].i.nbytes:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
errno = EINVAL;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_POWER_WRITE_EINVAL_ERROR.001
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_POWER_WRITE_EINVAL_ERROR.001
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP[0].i.nbytes:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:32
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_POWER_WRITE_ERANGE_ERROR
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_POWER_WRITE_ERANGE_ERROR
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP[0].i.nbytes:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:0
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_POWER_WRITE_ERANGE_ERROR.001
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_POWER_WRITE_ERANGE_ERROR.001
TEST.STUB:uut_prototype_stubs.strtoul
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP[0].i.nbytes:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<null>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtoul.return
errno = ERANGE;
<<uut_prototype_stubs.strtoul.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_POWER_WRITE_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_POWER_WRITE_FAIL
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.g_status:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP[0].i.nbytes:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP[0].attr:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_POWER_WRITE_INVALID_FILE_PATH
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_POWER_WRITE_INVALID_FILE_PATH
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP[0].i.nbytes:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP[0].attr:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.return:9
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:9
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = -1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: DISPLAY_POWER_WRITE_SUCCESS
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:DISPLAY_POWER_WRITE_SUCCESS
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP[0].i.nbytes:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP[0].attr:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:0
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: IOFUNC_WRITE_VERIFY_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:IOFUNC_WRITE_VERIFY_FAIL
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.iofunc_write_verify.return:1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: IO_WRITE_INPUTE_ZERO_BYTES
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:IO_WRITE_INPUTE_ZERO_BYTES
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP[0].i.nbytes:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP[0].attr:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:0
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: IO_WRITE_INVALID_MSG_TYPE
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:IO_WRITE_INVALID_MSG_TYPE
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP[0].i.xtype:3
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:89
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: IO_WRITE_RESMGR_MSGREAD_FAIL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:IO_WRITE_RESMGR_MSGREAD_FAIL
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_msgread.return:-1
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:1
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
errno = 1;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: MALICIOUS_WRITE_REQUEST
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:CDisplay_RM_io_write
TEST.NEW
TEST.NAME:MALICIOUS_WRITE_REQUEST
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ctp_SP[0].id:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP:<<malloc 1>>
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_msg_UP[0].i.nbytes:4294967295
TEST.VALUE:CDisplay_RM.CDisplay_RM_io_write.p_ocb_SP:<<malloc 1>>
TEST.EXPECTED:CDisplay_RM.CDisplay_RM_io_write.return:77
TEST.VALUE_USER_CODE:<<testcase>>
ts_display_dev dev;
dev.drventry_S = &display_drv_entry_stub;
int32_t l_powerpath_id = 1;
dev.display_power_path_id_S32 = l_powerpath_id;
<<CDisplay_RM.<<GLOBAL>>.displayDev>>=(dev);

TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: VCAST_main

-- Test Case: 01_UserParm
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:01_UserParm
TEST.VALUE:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0]:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.VALUE:CDisplay_RM.VCAST_main.return:0
TEST.VALUE:uut_prototype_stubs.getopt.return:-1
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.END

-- Test Case: 02_ret_display_enable_logging_BOOL
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:02_ret_display_enable_logging_BOOL
TEST.STUB:CDisplay_RM.CDisplay_RM_usage
TEST.STUB:CDisplay_RM.CDisplay_RM_Init
TEST.STUB:CDisplay_RM.CDisplay_Hw_Init
TEST.STUB:CDisplay_RM.CDisplay_RM_io_open
TEST.STUB:CDisplay_RM.CDisplay_RM_io_read
TEST.STUB:CDisplay_RM.CDisplay_RM_io_write
TEST.STUB:CDisplay_RM.CDisplay_RM_io_devctl
TEST.STUB:CDisplay_RM.CDisplay_RM_Set_Power
TEST.STUB:CDisplay_RM.getopt_chk
TEST.STUB:CDisplay_RM.CDisplay_RM_ParseOptions
TEST.STUB:CDisplay_RM.CDisplay_Dlload
TEST.STUB:CDisplay_RM.CDisplay_RM_ExitSignal
TEST.STUB:CDisplay_RM.CDisplay_RM_Terminate
TEST.STUB:CDisplay_RM.CDisplay_Deinit
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:CDisplay_RM.VCAST_main.return:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_ExitSignal.p_signo_SINT:1
TEST.EXPECTED:CDisplay_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CDisplay_RM.<<GLOBAL>>.UserParm[0]:INPUT_BASE=8,EXPECTED_BASE=8
TEST.END

-- Test Case: 03_CDisplay_RM_Init
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:03_CDisplay_RM_Init
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:0x30
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.optind:55
TEST.VALUE:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0]:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.VALUE:CDisplay_RM.VCAST_main.return:1
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.EXPECTED:CDisplay_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CDisplay_RM.<<GLOBAL>>.UserParm[0]:EXPECTED_BASE=8
TEST.END

-- Test Case: 04_procmgr_ability_AND_set_ids_from_arg
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:04_procmgr_ability_AND_set_ids_from_arg
TEST.STUB:CDisplay_RM.CDisplay_RM_ParseOptions
TEST.STUB:CDisplay_RM.CDisplay_RM_Terminate
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:0x30
TEST.VALUE:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0]:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.VALUE:CDisplay_RM.VCAST_main.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_Terminate.return:1
TEST.VALUE:uut_prototype_stubs.procmgr_ability.__pid:0
TEST.VALUE:uut_prototype_stubs.procmgr_ability.__ability:536936451
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:1
TEST.VALUE:uut_prototype_stubs.set_ids_from_arg.return:1
TEST.VALUE:uut_prototype_stubs.seteuid.return:-1
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.EXPECTED:uut_prototype_stubs.procmgr_ability.__pid:0
TEST.ATTRIBUTES:CDisplay_RM.<<GLOBAL>>.UserParm[0]:EXPECTED_BASE=8
TEST.END

-- Test Case: CDisplay_Hw_Init_0.1
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:CDisplay_Hw_Init_0.1
TEST.STUB:CDisplay_RM.CDisplay_RM_Init
TEST.STUB:CDisplay_RM.CDisplay_Hw_Init
TEST.STUB:CDisplay_RM.CDisplay_RM_ParseOptions
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:0x0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0]:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.VALUE:CDisplay_RM.VCAST_main.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.return:1
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:55
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.END

-- Test Case: CDisplay_Hw_Init_0.2
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:CDisplay_Hw_Init_0.2
TEST.STUB:CDisplay_RM.CDisplay_RM_ParseOptions
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:0x30
TEST.VALUE:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0]:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.VALUE:CDisplay_RM.VCAST_main.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:0
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:1
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.ATTRIBUTES:CDisplay_RM.<<GLOBAL>>.UserParm[0]:EXPECTED_BASE=8
TEST.END

-- Test Case: CDisplay_Hw_Init_0.3
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:CDisplay_Hw_Init_0.3
TEST.STUB:CDisplay_RM.CDisplay_RM_Init
TEST.STUB:CDisplay_RM.CDisplay_RM_ParseOptions
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:0x30
TEST.VALUE:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0]:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.VALUE:CDisplay_RM.VCAST_main.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:0
TEST.VALUE:uut_prototype_stubs.set_ids_from_arg.return:22
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.ATTRIBUTES:CDisplay_RM.<<GLOBAL>>.UserParm[0]:EXPECTED_BASE=8
TEST.END

-- Test Case: CDisplay_Hw_Init_0.4
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:CDisplay_Hw_Init_0.4
TEST.STUB:CDisplay_RM.CDisplay_RM_Init
TEST.STUB:CDisplay_RM.CDisplay_Hw_Init
TEST.STUB:CDisplay_RM.CDisplay_RM_ParseOptions
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:0x0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0]:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.VALUE:CDisplay_RM.VCAST_main.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:0
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.END

-- Test Case: CDisplay_Hw_Init_0.5
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:CDisplay_Hw_Init_0.5
TEST.STUB:CDisplay_RM.CDisplay_RM_Init
TEST.STUB:CDisplay_RM.CDisplay_RM_ParseOptions
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:0x30
TEST.VALUE:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0]:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.VALUE:CDisplay_RM.VCAST_main.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.set_ids_from_arg.return:22
TEST.VALUE:uut_prototype_stubs.seteuid.return:-1
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.ATTRIBUTES:CDisplay_RM.<<GLOBAL>>.UserParm[0]:EXPECTED_BASE=8
TEST.END

-- Test Case: CDisplay_Hw_Init_0.6
TEST.UNIT:CDisplay_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:CDisplay_Hw_Init_0.6
TEST.STUB:CDisplay_RM.CDisplay_RM_Init
TEST.STUB:CDisplay_RM.CDisplay_Hw_Init
TEST.STUB:CDisplay_RM.CDisplay_RM_ParseOptions
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:CDisplay_RM.<<GLOBAL>>.UserParm[0]:0x0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0]:<<malloc 1>>
TEST.VALUE:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.VALUE:CDisplay_RM.VCAST_main.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_Init.return:0
TEST.VALUE:CDisplay_RM.CDisplay_Hw_Init.return:0
TEST.VALUE:CDisplay_RM.CDisplay_RM_ParseOptions.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.ctp[0].resmgr_context.rcvid:1
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:12
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argc_SINT:0
TEST.EXPECTED:CDisplay_RM.VCAST_main.p_argv_CHAR[0][0]:'1'
TEST.END
