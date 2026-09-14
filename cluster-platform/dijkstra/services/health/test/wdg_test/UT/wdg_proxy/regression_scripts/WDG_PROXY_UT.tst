-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : WDG_PROXY_UT
-- Unit(s) Under Test: main wdg_proxy wdg_proxy_comm_if
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: main

-- Subprogram: VCAST_main

-- Test Case: VCAST_main.Pass
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.Pass
TEST.STUB:wdg_proxy.WdgProxy_onInit
TEST.STUB:wdg_proxy.WdgProxy_onStart
TEST.STUB:wdg_proxy.WdgProxy_worker
TEST.VALUE:wdg_proxy.WdgProxy_onInit.return:WP_OK
TEST.VALUE:wdg_proxy.WdgProxy_onStart.return:WP_OK
TEST.END

-- Test Case: VCAST_main.Pass.g_exit_U8_Zero
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.Pass.g_exit_U8_Zero
TEST.STUB:wdg_proxy.WdgProxy_onInit
TEST.STUB:wdg_proxy.WdgProxy_onStart
TEST.STUB:wdg_proxy.WdgProxy_worker
TEST.VALUE:main.<<GLOBAL>>.g_exit_U8:0
TEST.VALUE:wdg_proxy.WdgProxy_onInit.return:WP_OK
TEST.VALUE:wdg_proxy.WdgProxy_onStart.return:WP_OK
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Test Case: VCAST_main.Pass.onInit_Fail
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.Pass.onInit_Fail
TEST.STUB:wdg_proxy.WdgProxy_onInit
TEST.STUB:wdg_proxy.WdgProxy_onStart
TEST.STUB:wdg_proxy.WdgProxy_worker
TEST.VALUE:wdg_proxy.WdgProxy_onInit.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_onStart.return:WP_OK
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Test Case: VCAST_main.Pass.onStart_Fail
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.Pass.onStart_Fail
TEST.STUB:wdg_proxy.WdgProxy_onInit
TEST.STUB:wdg_proxy.WdgProxy_onStart
TEST.STUB:wdg_proxy.WdgProxy_worker
TEST.VALUE:wdg_proxy.WdgProxy_onInit.return:WP_OK
TEST.VALUE:wdg_proxy.WdgProxy_onStart.return:WP_FAIL
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Subprogram: handle_sigterm

-- Test Case: handle_sigterm.001
TEST.UNIT:main
TEST.SUBPROGRAM:handle_sigterm
TEST.NEW
TEST.NAME:handle_sigterm.001
TEST.END

-- Unit: wdg_proxy

-- Subprogram: WdgProxy_Attach

-- Test Case: WdgProxy_Attach.ham_attach_return_idx_false
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_Attach
TEST.NEW
TEST.NAME:WdgProxy_Attach.ham_attach_return_idx_false
TEST.STUB:wdg_proxy.WdgProxy_GetPID_Of
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].name:<<malloc 8>>
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].name:"sc-imx8"
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].isHbEnabled:false
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbLowMissAction:WP_ACTION_NONE
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbHighMissAction:WP_ACTION_NONE
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].deathAction:WP_ACTION_RESTART
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].maxRestartCount:20
TEST.VALUE:wdg_proxy.WdgProxy_GetPID_Of.return:123
TEST.VALUE:wdg_proxy.WdgProxy_Attach.idx:11
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = NULL;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_attach.return
<<uut_prototype_stubs.ham_attach.return>> = NULL;
TEST.END_STUB_VAL_USER_CODE:
TEST.EXPECTED_USER_CODE:wdg_proxy.WdgProxy_Attach.return
{{ <<wdg_proxy.WdgProxy_Attach.return>> == WP_OK }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Test Case: WdgProxy_Attach.ham_attach_return_null
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_Attach
TEST.NEW
TEST.NAME:WdgProxy_Attach.ham_attach_return_null
TEST.STUB:wdg_proxy.WdgProxy_GetPID_Of
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].name:<<malloc 8>>
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].name:"sc-imx8"
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].isHbEnabled:false
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbLowMissAction:WP_ACTION_NONE
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbHighMissAction:WP_ACTION_NONE
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].deathAction:WP_ACTION_RESTART
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].maxRestartCount:20
TEST.VALUE:wdg_proxy.WdgProxy_GetPID_Of.return:123
TEST.VALUE:wdg_proxy.WdgProxy_Attach.idx:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = NULL;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_attach.return
<<uut_prototype_stubs.ham_attach.return>> = NULL;
TEST.END_STUB_VAL_USER_CODE:
TEST.EXPECTED_USER_CODE:wdg_proxy.WdgProxy_Attach.return
{{ <<wdg_proxy.WdgProxy_Attach.return>> == WP_OK }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Test Case: WdgProxy_Attach.ham_entity_handle_return_not_null
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_Attach
TEST.NEW
TEST.NAME:WdgProxy_Attach.ham_entity_handle_return_not_null
TEST.STUB:wdg_proxy.WdgProxy_GetPID_Of
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:wdg_proxy.WdgProxy_GetPID_Of.return:123
TEST.VALUE:wdg_proxy.WdgProxy_Attach.idx:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = 1;


TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_Attach.ham_entity_handle_return_not_null->_get_errno_ptr_true
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_Attach
TEST.NEW
TEST.NAME:WdgProxy_Attach.ham_entity_handle_return_not_null->_get_errno_ptr_true
TEST.STUB:wdg_proxy.WdgProxy_GetPID_Of
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:wdg_proxy.WdgProxy_GetPID_Of.return:123
TEST.VALUE:wdg_proxy.WdgProxy_Attach.idx:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = NULL;


TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_Attach.procNum_!=-1
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_Attach
TEST.NEW
TEST.NAME:WdgProxy_Attach.procNum_!=-1
TEST.STUB:wdg_proxy.WdgProxy_GetPID_Of
TEST.VALUE:wdg_proxy.WdgProxy_GetPID_Of.return:123
TEST.VALUE:wdg_proxy.WdgProxy_Attach.idx:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = NULL;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_attach.return
<<uut_prototype_stubs.ham_attach.return>> = 1;
TEST.END_STUB_VAL_USER_CODE:
TEST.EXPECTED_USER_CODE:wdg_proxy.WdgProxy_Attach.return
{{ <<wdg_proxy.WdgProxy_Attach.return>> == 1 }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Test Case: WdgProxy_Attach.procNum_==-1
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_Attach
TEST.NEW
TEST.NAME:WdgProxy_Attach.procNum_==-1
TEST.STUB:wdg_proxy.WdgProxy_GetPID_Of
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.WdgProxy_GetPID_Of.return:-1
TEST.VALUE:wdg_proxy.WdgProxy_Attach.idx:0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_OK
TEST.EXPECTED_USER_CODE:wdg_proxy.WdgProxy_Attach.return
{{ <<wdg_proxy.WdgProxy_Attach.return>> == NULL }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Test Case: WdgProxy_Attach.procNum_==-1_RequestSLM_FAIL
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_Attach
TEST.NEW
TEST.NAME:WdgProxy_Attach.procNum_==-1_RequestSLM_FAIL
TEST.STUB:wdg_proxy.WdgProxy_GetPID_Of
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.WdgProxy_GetPID_Of.return:-1
TEST.VALUE:wdg_proxy.WdgProxy_Attach.idx:0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED_USER_CODE:wdg_proxy.WdgProxy_Attach.return
{{ <<wdg_proxy.WdgProxy_Attach.return>> == NULL }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Test Case: WdgProxy_Attach.procNum_==-1_RequestSLM_OK
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_Attach
TEST.NEW
TEST.NAME:WdgProxy_Attach.procNum_==-1_RequestSLM_OK
TEST.STUB:wdg_proxy.WdgProxy_GetPID_Of
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.WdgProxy_Attach.idx:0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = NULL;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_attach.return
<<uut_prototype_stubs.ham_attach.return>> = 1;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_GetPID_Of.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<wdg_proxy.WdgProxy_GetPID_Of.return>> = 123;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   <<wdg_proxy.WdgProxy_GetPID_Of.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.EXPECTED_USER_CODE:wdg_proxy.WdgProxy_Attach.return
{{ <<wdg_proxy.WdgProxy_Attach.return>> == 1 }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Subprogram: WdgProxy_CheckProcessExitedInSLM

-- Test Case: errno_ptr_failCase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_CheckProcessExitedInSLM
TEST.NEW
TEST.NAME:errno_ptr_failCase
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.STUB:uut_prototype_stubs.strcmp
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<null>>
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.read.return:0
TEST.VALUE:uut_prototype_stubs.write.return:-1
TEST.VALUE:uut_prototype_stubs.strcmp.return:1
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.open.VCAST_PARAM_1
<<uut_prototype_stubs.open.VCAST_PARAM_1>> = ( "dev/slm" );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strsep.return
<<uut_prototype_stubs.strsep.return>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: error_case
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_CheckProcessExitedInSLM
TEST.NEW
TEST.NAME:error_case
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.STUB:uut_prototype_stubs.strcmp
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:16
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.read.return:0
TEST.VALUE:uut_prototype_stubs.strcmp.return:1
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:"vmf"
TEST.EXPECTED:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.return:WP_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.open.VCAST_PARAM_1
<<uut_prototype_stubs.open.VCAST_PARAM_1>> = ( "dev/slm" );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strsep.return
<<uut_prototype_stubs.strsep.return>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: error_failcase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_CheckProcessExitedInSLM
TEST.NEW
TEST.NAME:error_failcase
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:-1
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.write.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.open.VCAST_PARAM_1
<<uut_prototype_stubs.open.VCAST_PARAM_1>> = ( "dev/slm" );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: readbytes
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_CheckProcessExitedInSLM
TEST.NEW
TEST.NAME:readbytes
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:16
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.read.return:8192
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:"vmf"
TEST.EXPECTED:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.return:WP_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.open.VCAST_PARAM_1
<<uut_prototype_stubs.open.VCAST_PARAM_1>> = ( "dev/slm" );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: readbytes.001
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_CheckProcessExitedInSLM
TEST.NEW
TEST.NAME:readbytes.001
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:16
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.read.return:10,0
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:"vmf"
TEST.EXPECTED:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.return:WP_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.open.VCAST_PARAM_1
<<uut_prototype_stubs.open.VCAST_PARAM_1>> = ( "dev/slm" );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: readbytes.003
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_CheckProcessExitedInSLM
TEST.NEW
TEST.NAME:readbytes.003
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.STUB:uut_prototype_stubs.strcmp
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:16
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.read.return:8191
TEST.VALUE:uut_prototype_stubs.strsep.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.strsep.return[0]:0x61
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.open.VCAST_PARAM_1
<<uut_prototype_stubs.open.VCAST_PARAM_1>> = ( "dev/slm" );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: readbytes.004
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_CheckProcessExitedInSLM
TEST.NEW
TEST.NAME:readbytes.004
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.STUB:uut_prototype_stubs.strcmp
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:16
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.read.return:8191
TEST.VALUE:uut_prototype_stubs.strsep.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.strsep.return[0]:0x61
TEST.VALUE:uut_prototype_stubs.strcmp.return:1,0
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.open.VCAST_PARAM_1
<<uut_prototype_stubs.open.VCAST_PARAM_1>> = ( "dev/slm" );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: readbytes.005
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_CheckProcessExitedInSLM
TEST.NEW
TEST.NAME:readbytes.005
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.STUB:uut_prototype_stubs.strcmp
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:16
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.read.return:8191
TEST.VALUE:uut_prototype_stubs.strsep.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.strsep.return[0]:0x0,0x61
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.open.VCAST_PARAM_1
<<uut_prototype_stubs.open.VCAST_PARAM_1>> = ( "dev/slm" );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: readbytes_failureCase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_CheckProcessExitedInSLM
TEST.NEW
TEST.NAME:readbytes_failureCase
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:16
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.read.return:8191
TEST.VALUE:uut_prototype_stubs.strsep.return:<<malloc 9>>
TEST.VALUE:uut_prototype_stubs.strsep.return:<<null>>
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName:"vmf"
TEST.EXPECTED:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.return:WP_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.open.VCAST_PARAM_1
<<uut_prototype_stubs.open.VCAST_PARAM_1>> = ( "dev/slm" );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strsep.__stringp.__stringp[0]
char buf[] = "abc\n";
<<uut_prototype_stubs.strsep.__stringp>>[0] =  (char **)&buf;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strsep.__stringp.__stringp[1]
char buf[] = "def\n";
<<uut_prototype_stubs.strsep.__stringp>>[0] =  (char **)&buf;

TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strsep.__delim
<<uut_prototype_stubs.strsep.__delim>> = ( "\t \n" );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: slm_fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_CheckProcessExitedInSLM
TEST.NEW
TEST.NAME:slm_fail
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.open.VCAST_PARAM_1
<<uut_prototype_stubs.open.VCAST_PARAM_1>> = ( "dev/slm" );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: WdgProxy_ExtractFilename

-- Test Case: WdgProxy_ExtractFilename.001
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ExtractFilename
TEST.NEW
TEST.NAME:WdgProxy_ExtractFilename.001
TEST.STUB:uut_prototype_stubs.strrchr
TEST.VALUE:uut_prototype_stubs.strrchr.return:1
TEST.END

-- Test Case: WdgProxy_ExtractFilename.002
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ExtractFilename
TEST.NEW
TEST.NAME:WdgProxy_ExtractFilename.002
TEST.STUB:uut_prototype_stubs.strrchr
TEST.VALUE:uut_prototype_stubs.strrchr.return:0
TEST.END

-- Subprogram: WdgProxy_GetPID_Of

-- Test Case: IsNumericFalseCase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_GetPID_Of
TEST.NEW
TEST.NAME:IsNumericFalseCase
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.opendir
TEST.STUB:uut_prototype_stubs.fclose
TEST.STUB:uut_prototype_stubs.fgets
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:wdg_proxy.WdgProxy_IsNumeric
TEST.STUB:wdg_proxy.WdgProxy_ExtractFilename
TEST.VALUE:uut_prototype_stubs.stat.__buf[0].st_mode:040755
TEST.VALUE:uut_prototype_stubs.closedir.return:1
TEST.VALUE:uut_prototype_stubs.fclose.return:1
TEST.VALUE:uut_prototype_stubs.fgets.return:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.fgets.return:"1"
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.VALUE:wdg_proxy.WdgProxy_IsNumeric.return:0
TEST.VALUE:wdg_proxy.WdgProxy_ExtractFilename.path:<<null>>
TEST.VALUE:wdg_proxy.WdgProxy_ExtractFilename.return:<<malloc 9>>
TEST.VALUE:wdg_proxy.WdgProxy_ExtractFilename.return:<<null>>
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)0x1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = (DIR *)1;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.readdir.return
static struct dirent test_dir1;
test_dir1.d_name[0] = '1';
test_dir1.d_name[1] = 0;
static int cnt = 0;
if (cnt == 0)
{
cnt = 1;
<<uut_prototype_stubs.readdir.return>>  = ( &test_dir1 );
}
else
{
<<uut_prototype_stubs.readdir.return>>  = NULL;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:wdg_proxy.WdgProxy_GetPID_Of.name
<<wdg_proxy.WdgProxy_GetPID_Of.name>> = ( "abc" );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: ProcessNameFailCase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_GetPID_Of
TEST.NEW
TEST.NAME:ProcessNameFailCase
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.opendir
TEST.STUB:uut_prototype_stubs.fclose
TEST.STUB:uut_prototype_stubs.fgets
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:wdg_proxy.WdgProxy_ExtractFilename
TEST.VALUE:uut_prototype_stubs.stat.__buf[0].st_mode:040755
TEST.VALUE:uut_prototype_stubs.closedir.return:1
TEST.VALUE:uut_prototype_stubs.fclose.return:1
TEST.VALUE:uut_prototype_stubs.fgets.return:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.fgets.return:"1"
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)0x1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = (DIR *)1;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.readdir.return
static struct dirent test_dir1;
test_dir1.d_name[0] = '1';
test_dir1.d_name[1] = 0;
static int cnt = 0;
if (cnt == 0)
{
cnt = 1;
<<uut_prototype_stubs.readdir.return>>  = ( &test_dir1 );
}
else
{
<<uut_prototype_stubs.readdir.return>>  = NULL;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_ExtractFilename.path
<<wdg_proxy.WdgProxy_ExtractFilename.path>> = ( NULL );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:wdg_proxy.WdgProxy_GetPID_Of.name
<<wdg_proxy.WdgProxy_GetPID_Of.name>> = ( "abc" );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: TrueCases
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_GetPID_Of
TEST.NEW
TEST.NAME:TrueCases
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.opendir
TEST.STUB:uut_prototype_stubs.fclose
TEST.STUB:uut_prototype_stubs.fgets
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:wdg_proxy.WdgProxy_ExtractFilename
TEST.VALUE:uut_prototype_stubs.stat.__buf[0].st_mode:040755
TEST.VALUE:uut_prototype_stubs.closedir.return:1
TEST.VALUE:uut_prototype_stubs.fclose.return:1
TEST.VALUE:uut_prototype_stubs.fgets.return:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.fgets.return:"1"
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)0x1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = (DIR *)1;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.readdir.return
static struct dirent test_dir1;
test_dir1.d_name[0] = '1';
test_dir1.d_name[1] = 0;
static int cnt = 0;
if (cnt == 0)
{
cnt = 1;
<<uut_prototype_stubs.readdir.return>>  = ( &test_dir1 );
}
else
{
<<uut_prototype_stubs.readdir.return>>  = NULL;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_ExtractFilename.return
<<wdg_proxy.WdgProxy_ExtractFilename.return>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:wdg_proxy.WdgProxy_GetPID_Of.name
<<wdg_proxy.WdgProxy_GetPID_Of.name>> = ( "abc" );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: fgetsFailCase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_GetPID_Of
TEST.NEW
TEST.NAME:fgetsFailCase
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.opendir
TEST.STUB:uut_prototype_stubs.fclose
TEST.STUB:uut_prototype_stubs.fgets
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:wdg_proxy.WdgProxy_ExtractFilename
TEST.VALUE:uut_prototype_stubs.stat.__buf[0].st_mode:040755
TEST.VALUE:uut_prototype_stubs.closedir.return:1
TEST.VALUE:uut_prototype_stubs.fclose.return:1
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)0x1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = (DIR *)1;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.readdir.return
static struct dirent test_dir1;
test_dir1.d_name[0] = '1';
test_dir1.d_name[1] = 0;
static int cnt = 0;
if (cnt == 0)
{
cnt = 1;
<<uut_prototype_stubs.readdir.return>>  = ( &test_dir1 );
}
else
{
<<uut_prototype_stubs.readdir.return>>  = NULL;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fgets.return
<<uut_prototype_stubs.fgets.return>> = ( NULL );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_ExtractFilename.return
<<wdg_proxy.WdgProxy_ExtractFilename.return>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:wdg_proxy.WdgProxy_GetPID_Of.name
<<wdg_proxy.WdgProxy_GetPID_Of.name>> = ( "abc" );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: fpFailCase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_GetPID_Of
TEST.NEW
TEST.NAME:fpFailCase
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.opendir
TEST.STUB:uut_prototype_stubs.fclose
TEST.STUB:uut_prototype_stubs.fgets
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:wdg_proxy.WdgProxy_ExtractFilename
TEST.VALUE:uut_prototype_stubs.stat.__buf[0].st_mode:040755
TEST.VALUE:uut_prototype_stubs.closedir.return:1
TEST.VALUE:uut_prototype_stubs.fclose.return:1
TEST.VALUE:uut_prototype_stubs.fgets.return:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.fgets.return:"1"
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( NULL );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = (DIR *)1;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.readdir.return
static struct dirent test_dir1;
test_dir1.d_name[0] = '1';
test_dir1.d_name[1] = 0;
static int cnt = 0;
if (cnt == 0)
{
cnt = 1;
<<uut_prototype_stubs.readdir.return>>  = ( &test_dir1 );
}
else
{
<<uut_prototype_stubs.readdir.return>>  = NULL;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_ExtractFilename.return
<<wdg_proxy.WdgProxy_ExtractFilename.return>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:wdg_proxy.WdgProxy_GetPID_Of.name
<<wdg_proxy.WdgProxy_GetPID_Of.name>> = ( "abc" );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: nameFailCase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_GetPID_Of
TEST.NEW
TEST.NAME:nameFailCase
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.opendir
TEST.STUB:uut_prototype_stubs.fclose
TEST.STUB:uut_prototype_stubs.fgets
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:wdg_proxy.WdgProxy_ExtractFilename
TEST.VALUE:uut_prototype_stubs.stat.__buf[0].st_mode:040755
TEST.VALUE:uut_prototype_stubs.closedir.return:1
TEST.VALUE:uut_prototype_stubs.fclose.return:1
TEST.VALUE:uut_prototype_stubs.fgets.return:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.fgets.return:"1"
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)0x1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = (DIR *)1;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.readdir.return
static struct dirent test_dir1;
test_dir1.d_name[0] = '1';
test_dir1.d_name[1] = 0;
static int cnt = 0;
if (cnt == 0)
{
cnt = 1;
<<uut_prototype_stubs.readdir.return>>  = ( &test_dir1 );
}
else
{
<<uut_prototype_stubs.readdir.return>>  = NULL;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_ExtractFilename.return
<<wdg_proxy.WdgProxy_ExtractFilename.return>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: openDir_fasleCase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_GetPID_Of
TEST.NEW
TEST.NAME:openDir_fasleCase
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.opendir
TEST.STUB:uut_prototype_stubs.fclose
TEST.STUB:uut_prototype_stubs.fgets
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:wdg_proxy.WdgProxy_ExtractFilename
TEST.VALUE:uut_prototype_stubs.stat.__buf[0].st_mode:040755
TEST.VALUE:uut_prototype_stubs.closedir.return:1
TEST.VALUE:uut_prototype_stubs.fclose.return:1
TEST.VALUE:uut_prototype_stubs.fgets.return:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.fgets.return:"1"
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)0x1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = NULL;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.readdir.return
static struct dirent test_dir1;
test_dir1.d_name[0] = '1';
test_dir1.d_name[1] = 0;
static int cnt = 0;
if (cnt == 0)
{
cnt = 1;
<<uut_prototype_stubs.readdir.return>>  = ( &test_dir1 );
}
else
{
<<uut_prototype_stubs.readdir.return>>  = NULL;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_ExtractFilename.return
<<wdg_proxy.WdgProxy_ExtractFilename.return>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:wdg_proxy.WdgProxy_GetPID_Of.name
<<wdg_proxy.WdgProxy_GetPID_Of.name>> = ( "abc" );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: stModeFalseCase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_GetPID_Of
TEST.NEW
TEST.NAME:stModeFalseCase
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.opendir
TEST.STUB:uut_prototype_stubs.fclose
TEST.STUB:uut_prototype_stubs.fgets
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:wdg_proxy.WdgProxy_ExtractFilename
TEST.VALUE:uut_prototype_stubs.stat.__buf[0].st_mode:2
TEST.VALUE:uut_prototype_stubs.closedir.return:1
TEST.VALUE:uut_prototype_stubs.fclose.return:1
TEST.VALUE:uut_prototype_stubs.fgets.return:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.fgets.return:"1"
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)0x1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = (DIR *)1;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.readdir.return
static struct dirent test_dir1;
test_dir1.d_name[0] = '1';
test_dir1.d_name[1] = 0;
static int cnt = 0;
if (cnt == 0)
{
cnt = 1;
<<uut_prototype_stubs.readdir.return>>  = ( &test_dir1 );
}
else
{
<<uut_prototype_stubs.readdir.return>>  = NULL;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_ExtractFilename.return
<<wdg_proxy.WdgProxy_ExtractFilename.return>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:wdg_proxy.WdgProxy_GetPID_Of.name
<<wdg_proxy.WdgProxy_GetPID_Of.name>> = ( "abc" );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: statFalseCase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_GetPID_Of
TEST.NEW
TEST.NAME:statFalseCase
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.opendir
TEST.STUB:uut_prototype_stubs.fclose
TEST.STUB:uut_prototype_stubs.fgets
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:wdg_proxy.WdgProxy_IsNumeric
TEST.STUB:wdg_proxy.WdgProxy_ExtractFilename
TEST.VALUE:uut_prototype_stubs.stat.return:-1
TEST.VALUE:uut_prototype_stubs.closedir.return:1
TEST.VALUE:uut_prototype_stubs.fclose.return:1
TEST.VALUE:uut_prototype_stubs.fgets.return:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.fgets.return:"1"
TEST.VALUE:uut_prototype_stubs.strcmp.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)0x1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = (DIR *)1;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.readdir.return
static struct dirent test_dir1;
test_dir1.d_name[0] = '1';
test_dir1.d_name[1] = 0;
static int cnt = 0;
if (cnt == 0)
{
cnt = 1;
<<uut_prototype_stubs.readdir.return>>  = ( &test_dir1 );
}
else
{
<<uut_prototype_stubs.readdir.return>>  = NULL;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_ExtractFilename.return
<<wdg_proxy.WdgProxy_ExtractFilename.return>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:wdg_proxy.WdgProxy_GetPID_Of.name
<<wdg_proxy.WdgProxy_GetPID_Of.name>> = ( "abc" );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: strCmpFailCase
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_GetPID_Of
TEST.NEW
TEST.NAME:strCmpFailCase
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.opendir
TEST.STUB:uut_prototype_stubs.fclose
TEST.STUB:uut_prototype_stubs.fgets
TEST.STUB:uut_prototype_stubs.strcmp
TEST.STUB:wdg_proxy.WdgProxy_ExtractFilename
TEST.VALUE:uut_prototype_stubs.stat.__buf[0].st_mode:040755
TEST.VALUE:uut_prototype_stubs.closedir.return:1
TEST.VALUE:uut_prototype_stubs.fclose.return:1
TEST.VALUE:uut_prototype_stubs.fgets.return:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.fgets.return:"1"
TEST.VALUE:uut_prototype_stubs.strcmp.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)0x1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = (DIR *)1;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.readdir.return
static struct dirent test_dir1;
test_dir1.d_name[0] = '1';
test_dir1.d_name[1] = 0;
static int cnt = 0;
if (cnt == 0)
{
cnt = 1;
<<uut_prototype_stubs.readdir.return>>  = ( &test_dir1 );
}
else
{
<<uut_prototype_stubs.readdir.return>>  = NULL;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_ExtractFilename.return
<<wdg_proxy.WdgProxy_ExtractFilename.return>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:wdg_proxy.WdgProxy_GetPID_Of.name
<<wdg_proxy.WdgProxy_GetPID_Of.name>> = ( "abc" );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: WdgProxy_IsNumeric

-- Test Case: WdgProxy_IsNumeric.001
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_IsNumeric
TEST.NEW
TEST.NAME:WdgProxy_IsNumeric.001
TEST.VALUE:wdg_proxy.WdgProxy_IsNumeric.return:0
TEST.VALUE_USER_CODE:wdg_proxy.WdgProxy_IsNumeric.str
<<wdg_proxy.WdgProxy_IsNumeric.str>> = ( "abc" );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: WdgProxy_IsNumeric.002
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_IsNumeric
TEST.NEW
TEST.NAME:WdgProxy_IsNumeric.002
TEST.VALUE:wdg_proxy.WdgProxy_IsNumeric.str:<<malloc 2>>
TEST.VALUE:wdg_proxy.WdgProxy_IsNumeric.str:"0"
TEST.END

-- Subprogram: WdgProxy_MonitorMemory

-- Test Case: WdgProxy_MonitorMemory.001
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_MonitorMemory
TEST.NEW
TEST.NAME:WdgProxy_MonitorMemory.001
TEST.END

-- Subprogram: WdgProxy_ProcessEvent

-- Test Case: WdgProxy_ProcessEvent.Default
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.Default
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:5
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x3
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:5
TEST.END

-- Test Case: WdgProxy_ProcessEvent.PCODE_TIMER_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.PCODE_TIMER_Pass
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:4
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x3
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:4
TEST.END

-- Test Case: WdgProxy_ProcessEvent.WdgProxy_RequestSLM_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.WdgProxy_RequestSLM_Fail
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbLowMissAction:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.WdgProxy_RequestSLM_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.WdgProxy_RequestSLM_Pass
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbLowMissAction:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.dataGreater_Than_Four
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.dataGreater_Than_Four
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:3
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x5
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:3
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x5
TEST.END

-- Test Case: WdgProxy_ProcessEvent.dataGreater_Than_expected
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.dataGreater_Than_expected
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:11
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:PROCESS_MONITOR_LIST_SIZE
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:11
TEST.END

-- Test Case: WdgProxy_ProcessEvent.deathAction_Default
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.deathAction_Default
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].deathAction:7
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:3
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:3
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.deathAction_FATAL_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.deathAction_FATAL_Pass
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].deathAction:2
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:3
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:3
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.hpHighMissAction_Default
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.hpHighMissAction_Default
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:2
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:2
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.hpHighMissAction_FATAL_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.hpHighMissAction_FATAL_Pass
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbHighMissAction:2
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:2
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:2
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.hpHighMissAction_WdgProxy_RequestSLM_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.hpHighMissAction_WdgProxy_RequestSLM_Fail
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbHighMissAction:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:2
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:2
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.hpHighMissAction_WdgProxy_RequestSLM_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.hpHighMissAction_WdgProxy_RequestSLM_Pass
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbHighMissAction:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:2
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_OK
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:2
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.hpLowMissAction_Dafault
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.hpLowMissAction_Dafault
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.hpLowMissAction_FATAL_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.hpLowMissAction_FATAL_Pass
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbLowMissAction:2
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.hpLowMissAction_WdgProxy_RequestSLM_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.hpLowMissAction_WdgProxy_RequestSLM_Fail
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbLowMissAction:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.hpLowMissAction_WdgProxy_RequestSLM_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.hpLowMissAction_WdgProxy_RequestSLM_Pass
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].hbLowMissAction:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_OK
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:1
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.data:0x0
TEST.END

-- Test Case: WdgProxy_ProcessEvent.pCfg->deathAction_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.pCfg->deathAction_Fail
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].deathAction:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:3
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x3
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:3
TEST.ATTRIBUTES:wdg_proxy.WdgProxy_ProcessEvent.data:EXPECTED_BASE=16
TEST.END

-- Test Case: WdgProxy_ProcessEvent.pCfg->deathAction_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ProcessEvent
TEST.NEW
TEST.NAME:WdgProxy_ProcessEvent.pCfg->deathAction_Pass
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].deathAction:1
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.event:3
TEST.VALUE:wdg_proxy.WdgProxy_ProcessEvent.data:0x3
TEST.EXPECTED:wdg_proxy.WdgProxy_ProcessEvent.event:3
TEST.END

-- Subprogram: WdgProxy_ReportFatalError

-- Test Case: WdgProxy_ReportFatalError.Fail1
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ReportFatalError
TEST.NEW
TEST.NAME:WdgProxy_ReportFatalError.Fail1
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].health_event_sent:1
TEST.VALUE:wdg_proxy.WdgProxy_ReportFatalError.idx:1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.WdgProxy_ReportFatalError.idx:1
TEST.EXPECTED:wdg_proxy.WdgProxy_ReportFatalError.return:-1
TEST.END

-- Test Case: WdgProxy_ReportFatalError.health_event.Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ReportFatalError
TEST.NEW
TEST.NAME:WdgProxy_ReportFatalError.health_event.Fail
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[1].health_event_sent:1
TEST.VALUE:wdg_proxy.WdgProxy_ReportFatalError.idx:1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.WdgProxy_ReportFatalError.idx:1
TEST.EXPECTED:wdg_proxy.WdgProxy_ReportFatalError.return:0
TEST.END

-- Test Case: WdgProxy_ReportFatalError.idx_fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ReportFatalError
TEST.NEW
TEST.NAME:WdgProxy_ReportFatalError.idx_fail
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].health_event_sent:1
TEST.VALUE:wdg_proxy.WdgProxy_ReportFatalError.idx:11
TEST.EXPECTED:wdg_proxy.WdgProxy_ReportFatalError.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxy_ReportFatalError_hdlr

-- Test Case: WdgProxy_ReportFatalError_hdlr.WP_PROCESS_ERROR_ST
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ReportFatalError_hdlr
TEST.NEW
TEST.NAME:WdgProxy_ReportFatalError_hdlr.WP_PROCESS_ERROR_ST
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_ERROR_ST
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:10
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:WP_UNKNOWN_ST_TMO_MS
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].event:WP_RESTART_EVENT_TYPE_LOW_HB_MISS
TEST.END

-- Test Case: WdgProxy_ReportFatalError_hdlr.WP_PROCESS_HEALTHY_ST
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_ReportFatalError_hdlr
TEST.NEW
TEST.NAME:WdgProxy_ReportFatalError_hdlr.WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:WP_PROCESS_HEALTHY_ST
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:10
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:WP_UNKNOWN_ST_TMO_MS
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].event:WP_RESTART_EVENT_TYPE_LOW_HB_MISS
TEST.END

-- Subprogram: WdgProxy_RequestSLM

-- Test Case: WdgProxy_RequestSLM.open_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.open_Fail
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:0
TEST.EXPECTED:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_RequestSLM.open_Fail.001
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.open_Fail.001
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:0
TEST.EXPECTED:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_RequestSLM.slm_action_0
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.slm_action_0
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:1024,0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.slm_action_0.001
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.slm_action_0.001
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.STUB:wdg_proxy.WdgProxy_GetPID_Of
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:1024,0
TEST.VALUE:wdg_proxy.WdgProxy_GetPID_Of.return:1
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.slm_action_0.write_fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.slm_action_0.write_fail
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:1024,0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:0
TEST.EXPECTED:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
    <<uut_prototype_stubs.write.return>> = -1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = ENOENT;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.slm_action_0_strstr_NULL
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.slm_action_0_strstr_NULL
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:1024,0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:0
TEST.EXPECTED:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.slm_action_0_strstr_NULL.001
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.slm_action_0_strstr_NULL.001
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.STUB:wdg_proxy.WdgProxy_GetPID_Of
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:1024,0
TEST.VALUE:wdg_proxy.WdgProxy_GetPID_Of.return:1
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.slm_action_1
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.slm_action_1
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:1024,0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:1
TEST.EXPECTED:wdg_proxy.WdgProxy_RequestSLM.return:WP_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.slm_action_1.write_fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.slm_action_1.write_fail
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.read.return:1024,0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
errno = ENOENT;
<<uut_prototype_stubs.write.return>> = -1;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.slm_action_1.write_fail->-get_errno_ptr_true
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.slm_action_1.write_fail->-get_errno_ptr_true
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.read.return:1024,0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:1
TEST.EXPECTED:wdg_proxy.WdgProxy_RequestSLM.return:WP_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
errno = ENOENT;
<<uut_prototype_stubs.write.return>> = -1;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.slm_action_1_strstr_!=NULL
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.slm_action_1_strstr_!=NULL
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:1024,0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.slm_action_default
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.slm_action_default
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:1024,0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:2
TEST.EXPECTED:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.slm_action_default_totalReadBytes_more_4096
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.slm_action_default_totalReadBytes_more_4096
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:9000,0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:2
TEST.EXPECTED:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.totalReadBytes_<0_slm_action_0
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.totalReadBytes_<0_slm_action_0
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:0
TEST.EXPECTED:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RequestSLM.totalReadBytes_<0_slm_action_1
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RequestSLM
TEST.NEW
TEST.NAME:WdgProxy_RequestSLM.totalReadBytes_<0_slm_action_1
TEST.STUB:uut_prototype_stubs.read
TEST.STUB:uut_prototype_stubs.write
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.read.return:0
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:<<malloc 4>>
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.pProcessName:"vmf"
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.slm_action:1
TEST.EXPECTED:wdg_proxy.WdgProxy_RequestSLM.return:WP_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.write.return
if(<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> == 1)
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 0;
   errno = 0;
   <<uut_prototype_stubs.write.return>> = 1;
}
else
{
   <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> = 1;
   errno = EBUSY;
   <<uut_prototype_stubs.write.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: WdgProxy_RunEventTimer

-- Test Case: WdgProxy_RunEventTimer.Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.Pass
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:0
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_OK
TEST.EXPECTED:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:1
TEST.END

-- Test Case: WdgProxy_RunEventTimer.Pass.WdgProxy_SetupHAM_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.Pass.WdgProxy_SetupHAM_Fail
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:2
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.END

-- Test Case: WdgProxy_RunEventTimer.Pass.pData->stateTimer>Zero
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.Pass.pData->stateTimer>Zero
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:2
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:2
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.END

-- Test Case: WdgProxy_RunEventTimer.ProcessMonitorData[idx].restartCount_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.ProcessMonitorData[idx].restartCount_Fail
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:3
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:2
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.END

-- Test Case: WdgProxy_RunEventTimer.ProcessMonitorData[idx].restartCount_Fail.001
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.ProcessMonitorData[idx].restartCount_Fail.001
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.STUB:wdg_proxy.WdgProxy_ReportFatalError
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:3
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:0
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.END

-- Test Case: WdgProxy_RunEventTimer.WdgProxy_RequestSLM_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.WdgProxy_RequestSLM_Fail
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.STUB:wdg_proxy.WdgProxy_CheckProcessExitedInSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:3
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:2
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_OK
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.return:0
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName
<<wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RunEventTimer.WdgProxy_RequestSLM_Fail.001
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.WdgProxy_RequestSLM_Fail.001
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.STUB:wdg_proxy.WdgProxy_CheckProcessExitedInSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:3
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:2
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.return:0
TEST.EXPECTED:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName
<<wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RunEventTimer.WdgProxy_RequestSLM_Fail.002
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.WdgProxy_RequestSLM_Fail.002
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.STUB:wdg_proxy.WdgProxy_CheckProcessExitedInSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:3
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:2
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.return:0
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName
<<wdg_proxy.WdgProxy_CheckProcessExitedInSLM.pProcessName>> = ( "abc" );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_RunEventTimer.msg_timer_cnt_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.msg_timer_cnt_Fail
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.msg_timer_cnt:500
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:5
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:2
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.END

-- Test Case: WdgProxy_RunEventTimer.pData->state_Equal_to_Four
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.pData->state_Equal_to_Four
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:4
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:2
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.END

-- Test Case: WdgProxy_RunEventTimer.pData->state_Equal_to_One
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.pData->state_Equal_to_One
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:1
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:2
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.END

-- Test Case: WdgProxy_RunEventTimer.pData->state_equalToThree
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.pData->state_equalToThree
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:3
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:0
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:2
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_OK
TEST.END

-- Test Case: WdgProxy_RunEventTimer.pData->state_incorrect
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_RunEventTimer
TEST.NEW
TEST.NAME:WdgProxy_RunEventTimer.pData->state_incorrect
TEST.STUB:wdg_proxy.WdgProxy_SetupHAM
TEST.STUB:wdg_proxy.WdgProxy_RequestSLM
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].state:5
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].stateTimer:2
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:1
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.VALUE:wdg_proxy.WdgProxy_RequestSLM.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.<<GLOBAL>>.ProcessMonitorData[0].restartCount:20
TEST.END

-- Subprogram: WdgProxy_SetupHAM

-- Test Case: WdgProxy_SetupHAM.errno_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.errno_Fail
TEST.STUB:wdg_proxy.WdgProxy_Attach
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].isHbEnabled:true
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:11
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_action_notify_pulse.return
<<uut_prototype_stubs.ham_action_notify_pulse.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<testcase>>
errno = 17;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: WdgProxy_SetupHAM.ham_action_notify_pulse_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.ham_action_notify_pulse_Fail
TEST.STUB:wdg_proxy.WdgProxy_Attach
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.VALUE:wdg_proxy.WdgProxy_Attach.idx:5
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_OK
TEST.EXPECTED:wdg_proxy.WdgProxy_Attach.idx:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_condition.return
<<uut_prototype_stubs.ham_condition.return>> = ( 2 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_Attach.return
<<wdg_proxy.WdgProxy_Attach.return>> = ( 4 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_SetupHAM.ham_action_notify_pulse_Incorrect
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.ham_action_notify_pulse_Incorrect
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].isHbEnabled:true
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_OK
TEST.ATTRIBUTES:wdg_proxy.WdgProxy_Attach.idx:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.__get_errno_ptr.return.return[0]
<<uut_prototype_stubs.__get_errno_ptr.return>>[0] = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_condition.return
<<uut_prototype_stubs.ham_condition.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_SetupHAM.ham_action_notify_pulse_Incorrect_errono_fai
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.ham_action_notify_pulse_Incorrect_errono_fai
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].isHbEnabled:true
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_OK
TEST.ATTRIBUTES:wdg_proxy.WdgProxy_Attach.idx:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_condition.return
<<uut_prototype_stubs.ham_condition.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_SetupHAM.ham_condition_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.ham_condition_Fail
TEST.STUB:wdg_proxy.WdgProxy_Attach
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.VALUE:wdg_proxy.WdgProxy_Attach.idx:5
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_OK
TEST.EXPECTED:wdg_proxy.WdgProxy_Attach.idx:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_action_notify_pulse.return
<<uut_prototype_stubs.ham_action_notify_pulse.return>> = ( 2 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_Attach.return
<<wdg_proxy.WdgProxy_Attach.return>> = ( 4 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_SetupHAM.ham_condition_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.ham_condition_Pass
TEST.STUB:wdg_proxy.WdgProxy_Attach
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.VALUE:wdg_proxy.WdgProxy_Attach.idx:5
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:0
TEST.EXPECTED:wdg_proxy.WdgProxy_Attach.idx:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_condition.return
<<uut_prototype_stubs.ham_condition.return>> = ( 2 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_action_notify_pulse.return
<<uut_prototype_stubs.ham_action_notify_pulse.return>> = ( 2 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:wdg_proxy.WdgProxy_Attach.return
<<wdg_proxy.WdgProxy_Attach.return>> = ( 4 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_SetupHAM.ham_condition_Return_NULL
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.ham_condition_Return_NULL
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].isHbEnabled:true
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_OK
TEST.ATTRIBUTES:wdg_proxy.WdgProxy_Attach.idx:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_action_notify_pulse.return
<<uut_prototype_stubs.ham_action_notify_pulse.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_SetupHAM.ham_condition_Return_witherrono
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.ham_condition_Return_witherrono
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].isHbEnabled:true
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_OK
TEST.ATTRIBUTES:wdg_proxy.WdgProxy_Attach.idx:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_action_notify_pulse.return
<<uut_prototype_stubs.ham_action_notify_pulse.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_SetupHAM.ham_condition_TRUE
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.ham_condition_TRUE
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].isHbEnabled:true
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_OK
TEST.ATTRIBUTES:wdg_proxy.WdgProxy_Attach.idx:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_condition.return
<<uut_prototype_stubs.ham_condition.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_action_notify_pulse.return
<<uut_prototype_stubs.ham_action_notify_pulse.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_SetupHAM.idx_fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.idx_fail
TEST.STUB:wdg_proxy.WdgProxy_Attach
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].isHbEnabled:true
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_action_notify_pulse.return
<<uut_prototype_stubs.ham_action_notify_pulse.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<testcase>>
errno = 17;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: WdgProxy_SetupHAM.isHbEnabled_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.isHbEnabled_Fail
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_SetupHAM.isHbEnabled_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.isHbEnabled_Pass
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_SetupHAM.ishabdisabled
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_SetupHAM
TEST.NEW
TEST.NAME:WdgProxy_SetupHAM.ishabdisabled
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:wdg_proxy.<<GLOBAL>>.ProcessMonitorList[0].isHbEnabled:false
TEST.VALUE:wdg_proxy.WdgProxy_SetupHAM.idx:0
TEST.EXPECTED:wdg_proxy.WdgProxy_SetupHAM.return:WP_FAIL
TEST.ATTRIBUTES:wdg_proxy.WdgProxy_Attach.idx:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_entity_handle.return
<<uut_prototype_stubs.ham_entity_handle.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.ham_action_notify_pulse.return
<<uut_prototype_stubs.ham_action_notify_pulse.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: WdgProxy_StartEventTimer

-- Test Case: WdgProxy_StartEventTimer.Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_StartEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StartEventTimer.Pass
TEST.EXPECTED:wdg_proxy.WdgProxy_StartEventTimer.return:WP_OK
TEST.END

-- Test Case: WdgProxy_StartEventTimer.Pass.TimesetTime_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_StartEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StartEventTimer.Pass.TimesetTime_Fail
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:uut_prototype_stubs.timer_settime.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_StartEventTimer.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_StartEventTimer.Pass.errono_fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_StartEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StartEventTimer.Pass.errono_fail
TEST.VALUE:uut_prototype_stubs.timer_settime.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_StartEventTimer.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_StartEventTimer.ShdGet_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_StartEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StartEventTimer.ShdGet_Fail
TEST.VALUE:uut_prototype_stubs.SchedGet.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_StartEventTimer.return:WP_OK
TEST.END

-- Test Case: WdgProxy_StartEventTimer.TimerCreate_Error_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_StartEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StartEventTimer.TimerCreate_Error_Fail
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:uut_prototype_stubs.timer_create.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_StartEventTimer.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_StartEventTimer.TimerCreate_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_StartEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StartEventTimer.TimerCreate_Fail
TEST.VALUE:uut_prototype_stubs.timer_create.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_StartEventTimer.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxy_StopEventTimer

-- Test Case: WdgProxy_StopEventTimer.Error_Num_fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_StopEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StopEventTimer.Error_Num_fail
TEST.VALUE:uut_prototype_stubs.timer_delete.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_StopEventTimer.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_StopEventTimer.Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_StopEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StopEventTimer.Pass
TEST.EXPECTED:wdg_proxy.WdgProxy_StopEventTimer.return:WP_OK
TEST.END

-- Test Case: WdgProxy_StopEventTimer.TimerDelete_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_StopEventTimer
TEST.NEW
TEST.NAME:WdgProxy_StopEventTimer.TimerDelete_Fail
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:uut_prototype_stubs.timer_delete.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_StopEventTimer.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxy_createDelayTimer

-- Test Case: WdgProxy_createDelayTimer.PASS
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_createDelayTimer
TEST.NEW
TEST.NAME:WdgProxy_createDelayTimer.PASS
TEST.STUB:uut_prototype_stubs.signal
TEST.VALUE:uut_prototype_stubs.timer_create.return:0
TEST.EXPECTED:wdg_proxy.WdgProxy_createDelayTimer.return:WP_OK
TEST.END

-- Test Case: WdgProxy_createDelayTimer.signal_fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_createDelayTimer
TEST.NEW
TEST.NAME:WdgProxy_createDelayTimer.signal_fail
TEST.STUB:uut_prototype_stubs.signal
TEST.VALUE:uut_prototype_stubs.timer_create.return:0
TEST.EXPECTED:wdg_proxy.WdgProxy_createDelayTimer.return:WP_FAIL
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.signal.return
<<uut_prototype_stubs.signal.return>> = -1;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_createDelayTimer.timer_create_fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_createDelayTimer
TEST.NEW
TEST.NAME:WdgProxy_createDelayTimer.timer_create_fail
TEST.STUB:uut_prototype_stubs.signal
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:EINVAL
TEST.VALUE:uut_prototype_stubs.timer_create.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_createDelayTimer.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_createDelayTimer.timer_create_fail_errno_null
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_createDelayTimer
TEST.NEW
TEST.NAME:WdgProxy_createDelayTimer.timer_create_fail_errno_null
TEST.STUB:uut_prototype_stubs.signal
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<null>>
TEST.VALUE:uut_prototype_stubs.timer_create.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_createDelayTimer.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxy_deleteDelayTimer

-- Test Case: WdgProxy_deleteDelayTimer.PASS
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_deleteDelayTimer
TEST.NEW
TEST.NAME:WdgProxy_deleteDelayTimer.PASS
TEST.VALUE:uut_prototype_stubs.timer_delete.return:0
TEST.EXPECTED:wdg_proxy.WdgProxy_deleteDelayTimer.return:WP_OK
TEST.END

-- Test Case: WdgProxy_deleteDelayTimer.timer_delete_fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_deleteDelayTimer
TEST.NEW
TEST.NAME:WdgProxy_deleteDelayTimer.timer_delete_fail
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:EINVAL
TEST.VALUE:uut_prototype_stubs.timer_delete.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_deleteDelayTimer.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_deleteDelayTimer.timer_delete_fail_errno_null
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_deleteDelayTimer
TEST.NEW
TEST.NAME:WdgProxy_deleteDelayTimer.timer_delete_fail_errno_null
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<null>>
TEST.VALUE:uut_prototype_stubs.timer_delete.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_deleteDelayTimer.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxy_onInit

-- Test Case: WdgProxy_onInit.access_!=_0
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_onInit
TEST.NEW
TEST.NAME:WdgProxy_onInit.access_!=_0
TEST.STUB:uut_prototype_stubs.access
TEST.VALUE:uut_prototype_stubs.access.return:-1
TEST.VALUE:wdg_proxy.WdgProxy_onInit.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.WdgProxy_onInit.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_onInit.access_pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_onInit
TEST.NEW
TEST.NAME:WdgProxy_onInit.access_pass
TEST.STUB:uut_prototype_stubs.access
TEST.VALUE:uut_prototype_stubs.access.return:0
TEST.VALUE:wdg_proxy.WdgProxy_onInit.return:WP_OK
TEST.EXPECTED:wdg_proxy.WdgProxy_onInit.return:WP_OK
TEST.END

-- Subprogram: WdgProxy_onShutdown

-- Test Case: WdgProxy_onShutdown.Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_onShutdown
TEST.NEW
TEST.NAME:WdgProxy_onShutdown.Pass
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_onShutdown.return:WP_OK
TEST.END

-- Subprogram: WdgProxy_onStart

-- Test Case: WdgProxy_onStart.channelCreate_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_onStart
TEST.NEW
TEST.NAME:WdgProxy_onStart.channelCreate_Fail
TEST.VALUE:uut_prototype_stubs.ChannelCreate.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_onStart.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_onStart.channelCreate_error_No
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_onStart
TEST.NEW
TEST.NAME:WdgProxy_onStart.channelCreate_error_No
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:uut_prototype_stubs.ChannelCreate.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_onStart.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_onStart.connectionAttach_Error_No
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_onStart
TEST.NEW
TEST.NAME:WdgProxy_onStart.connectionAttach_Error_No
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.ConnectAttach.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_onStart.return:WP_FAIL
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.__get_errno_ptr.return.return[0]
<<uut_prototype_stubs.__get_errno_ptr.return>>[0] = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: WdgProxy_onStart.connectionAttach_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_onStart
TEST.NEW
TEST.NAME:WdgProxy_onStart.connectionAttach_Fail
TEST.VALUE:uut_prototype_stubs.ConnectAttach.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_onStart.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_onStart_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_onStart
TEST.NEW
TEST.NAME:WdgProxy_onStart_Pass
TEST.STUB:wdg_proxy.WdgProxy_createDelayTimer
TEST.VALUE:wdg_proxy.WdgProxy_createDelayTimer.return:WP_OK
TEST.EXPECTED:wdg_proxy.WdgProxy_onStart.return:WP_OK
TEST.END

-- Subprogram: WdgProxy_onStop

-- Test Case: WdgProxy_onStop.001
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_onStop
TEST.NEW
TEST.NAME:WdgProxy_onStop.001
TEST.VALUE:uut_prototype_stubs.ham_detach_name.return:1
TEST.END

-- Test Case: WdgProxy_onStop.Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_onStop
TEST.NEW
TEST.NAME:WdgProxy_onStop.Pass
TEST.STUB:uut_prototype_stubs.access
TEST.VALUE:uut_prototype_stubs.access.return:-1
TEST.VALUE:wdg_proxy.WdgProxy_onStop.return:WP_FAIL
TEST.EXPECTED:wdg_proxy.WdgProxy_onStop.return:WP_OK
TEST.END

-- Subprogram: WdgProxy_startDelayTimer

-- Test Case: WdgProxy_startDelayTimer.PASS
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_startDelayTimer
TEST.NEW
TEST.NAME:WdgProxy_startDelayTimer.PASS
TEST.VALUE:uut_prototype_stubs.timer_settime.return:0
TEST.EXPECTED:wdg_proxy.WdgProxy_startDelayTimer.return:WP_OK
TEST.END

-- Test Case: WdgProxy_startDelayTimer.timer_settime_fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_startDelayTimer
TEST.NEW
TEST.NAME:WdgProxy_startDelayTimer.timer_settime_fail
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:EINVAL
TEST.VALUE:uut_prototype_stubs.timer_settime.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_startDelayTimer.return:WP_FAIL
TEST.END

-- Test Case: WdgProxy_startDelayTimer.timer_settime_fail_errno_null
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_startDelayTimer
TEST.NEW
TEST.NAME:WdgProxy_startDelayTimer.timer_settime_fail_errno_null
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<null>>
TEST.VALUE:uut_prototype_stubs.timer_settime.return:-1
TEST.EXPECTED:wdg_proxy.WdgProxy_startDelayTimer.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxy_worker

-- Test Case: WdgProxy_worker.MsgPulse_errno_4
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.MsgPulse_errno_4
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.__bytes:2
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.return:-1
TEST.VALUE:wdg_proxy.<<GLOBAL>>.fatal_error:true
TEST.EXPECTED:uut_prototype_stubs.MsgReceivePulse.__bytes:16
TEST.VALUE_USER_CODE:<<testcase>>
errno = 4;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: WdgProxy_worker.MsgPulse_errno_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.MsgPulse_errno_Fail
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.__bytes:2
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.return:-1
TEST.VALUE:wdg_proxy.<<GLOBAL>>.fatal_error:true
TEST.EXPECTED:uut_prototype_stubs.MsgReceivePulse.__bytes:16
TEST.VALUE_USER_CODE:<<testcase>>
errno = 4;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: WdgProxy_worker.MsgPulse_errno_pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.MsgPulse_errno_pass
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.__get_errno_ptr.return[0]:1
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.__bytes:2
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.return:-1
TEST.EXPECTED:uut_prototype_stubs.MsgReceivePulse.__bytes:16
TEST.END

-- Test Case: WdgProxy_worker.pulse.code_Fail
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.pulse.code_Fail
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.__chid:1
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.__pulse:<<null>>
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.__bytes:2
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.return:1
TEST.EXPECTED:uut_prototype_stubs.MsgReceivePulse.__bytes:16
TEST.END

-- Test Case: WdgProxy_worker.pulse.code_Pass
TEST.UNIT:wdg_proxy
TEST.SUBPROGRAM:WdgProxy_worker
TEST.NEW
TEST.NAME:WdgProxy_worker.pulse.code_Pass
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.g_pulse[0].code:4
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.__chid:1
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.__pulse:g_pulse
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.__bytes:2
TEST.VALUE:uut_prototype_stubs.MsgReceivePulse.return:1
TEST.EXPECTED:uut_prototype_stubs.MsgReceivePulse.__bytes:16
TEST.END

-- Unit: wdg_proxy_comm_if

-- Subprogram: WdgProxyCommIF_SendHealthEvent

-- Test Case: WdgProxyCommIF_SendHealthEvent.PASS
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIF_SendHealthEvent
TEST.NEW
TEST.NAME:WdgProxyCommIF_SendHealthEvent.PASS
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:VMF_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_OK
TEST.END

-- Test Case: WdgProxyCommIF_SendHealthEvent.vmf_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIF_SendHealthEvent
TEST.NEW
TEST.NAME:WdgProxyCommIF_SendHealthEvent.vmf_fail
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_FAIL
TEST.END

-- Test Case: WdgProxyCommIF_SendHealthEvent.vmf_init_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIF_SendHealthEvent
TEST.NEW
TEST.NAME:WdgProxyCommIF_SendHealthEvent.vmf_init_fail
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIF_SendHealthEvent.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxyCommIf_Init

-- Test Case: WdgProxyCommIf_Init.vmfConnect_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_Init
TEST.NEW
TEST.NAME:WdgProxyCommIf_Init.vmfConnect_fail
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:1
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.END

-- Test Case: WdgProxyCommIf_Init.vmfConnect_pass
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_Init
TEST.NEW
TEST.NAME:WdgProxyCommIf_Init.vmfConnect_pass
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:-1
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_FAIL
TEST.END

-- Test Case: WdgProxyCommIf_Init.vmf_client_id_positive_value
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_Init
TEST.NEW
TEST.NAME:WdgProxyCommIf_Init.vmf_client_id_positive_value
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:1
TEST.VALUE:wdg_proxy_comm_if.<<GLOBAL>>.vmf_client_id:0
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.END

-- Subprogram: WdgProxyCommIf_PackageDLTLogs

-- Test Case: WdgProxyCommIf_PackageDLTLogs.PASS
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_PackageDLTLogs
TEST.NEW
TEST.NAME:WdgProxyCommIf_PackageDLTLogs.PASS
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:VMF_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_PackageDLTLogs.return:WP_OK
TEST.END

-- Test Case: WdgProxyCommIf_PackageDLTLogs.PASS.vmf_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_PackageDLTLogs
TEST.NEW
TEST.NAME:WdgProxyCommIf_PackageDLTLogs.PASS.vmf_fail
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:1
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_PackageDLTLogs.return:WP_FAIL
TEST.END

-- Test Case: WdgProxyCommIf_PackageDLTLogs.PASS.vmf_init_fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_PackageDLTLogs
TEST.NEW
TEST.NAME:WdgProxyCommIf_PackageDLTLogs.PASS.vmf_init_fail
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:VMF_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_PackageDLTLogs.return:WP_FAIL
TEST.END

-- Subprogram: WdgProxyCommIf_SendFatalError

-- Test Case: WdgProxyCommIf_SendFatalError.WdgProxyCommIf_Init_Fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendFatalError
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendFatalError.WdgProxyCommIf_Init_Fail
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:2
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.idx:1
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.return:WP_FAIL
TEST.END

-- Test Case: WdgProxyCommIf_SendFatalError.nw_vmf_send_basic_Fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendFatalError
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendFatalError.nw_vmf_send_basic_Fail
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:-32768
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.idx:1
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.return:WP_FAIL
TEST.END

-- Test Case: WdgProxyCommIf_SendFatalError.nw_vmf_send_basic_pass
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendFatalError
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendFatalError.nw_vmf_send_basic_pass
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:VMF_OK
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.idx:1
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendFatalError.return:WP_OK
TEST.END

-- Subprogram: WdgProxyCommIf_SendHeartbeat

-- Test Case: WdgProxyCommIf_SendHeartbeat.WdgProxyCommIf_Init_Fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendHeartbeat
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendHeartbeat.WdgProxyCommIf_Init_Fail
TEST.STUB:wdg_proxy_comm_if.WdgProxyCommIf_Init
TEST.VALUE:wdg_proxy_comm_if.WdgProxyCommIf_Init.return:WP_FAIL
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendHeartbeat.return:WP_FAIL
TEST.END

-- Test Case: WdgProxyCommIf_SendHeartbeat.vmf_result_Fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendHeartbeat
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendHeartbeat.vmf_result_Fail
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:-32768
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendHeartbeat.return:WP_FAIL
TEST.END

-- Test Case: WdgProxyCommIf_SendHeartbeat.vmf_result_pass
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_SendHeartbeat
TEST.NEW
TEST.NAME:WdgProxyCommIf_SendHeartbeat.vmf_result_pass
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:VMF_OK
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_SendHeartbeat.return:WP_OK
TEST.END

-- Subprogram: WdgProxyCommIf_Shutdown

-- Test Case: WdgProxyCommIf_Shutdown.Pass
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_Shutdown
TEST.NEW
TEST.NAME:WdgProxyCommIf_Shutdown.Pass
TEST.VALUE:wdg_proxy_comm_if.<<GLOBAL>>.vmf_client_id:2
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown.return:WP_OK
TEST.END

-- Test Case: WdgProxyCommIf_Shutdown.vmf_client_Id_Fail
TEST.UNIT:wdg_proxy_comm_if
TEST.SUBPROGRAM:WdgProxyCommIf_Shutdown
TEST.NEW
TEST.NAME:WdgProxyCommIf_Shutdown.vmf_client_Id_Fail
TEST.EXPECTED:wdg_proxy_comm_if.WdgProxyCommIf_Shutdown.return:WP_OK
TEST.END
