-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_RES_MON
-- Unit(s) Under Test: debug main res_mon_comm_if res_mon_ddr_mx8 res_mon_dlt_if res_mon_extract_package res_mon_package res_mon_procfs res_mon_qcom
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: debug

-- Subprogram: res_mon_enable_logging

-- Test Case: slog2_register_false
TEST.UNIT:debug
TEST.SUBPROGRAM:res_mon_enable_logging
TEST.NEW
TEST.NAME:slog2_register_false
TEST.VALUE:debug.res_mon_enable_logging.return:0
TEST.VALUE:uut_prototype_stubs.slog2_register.return:0
TEST.END

-- Test Case: slog2_register_true
TEST.UNIT:debug
TEST.SUBPROGRAM:res_mon_enable_logging
TEST.NEW
TEST.NAME:slog2_register_true
TEST.VALUE:debug.res_mon_enable_logging.return:1
TEST.VALUE:uut_prototype_stubs.slog2_register.return:-1
TEST.END

-- Unit: main

-- Subprogram: VCAST_main

-- Test Case: ResMonCommIf_Init_fail
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:ResMonCommIf_Init_fail
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:res_mon_comm_if.ResMonCommIf_Init.return:-1
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Test Case: ResMonExtractPackage_Init_fail
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:ResMonExtractPackage_Init_fail
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Init.return:-1
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Test Case: ThreadCtl_fail
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:ThreadCtl_fail
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:-1
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Test Case: UserParm_not_NULL
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:UserParm_not_NULL
TEST.STUB:res_mon_qcom.ResMonQcom_EnableGPUBusyStats
TEST.VALUE:main.<<GLOBAL>>.optarg:<<malloc 2>>
TEST.VALUE:main.<<GLOBAL>>.optarg:"1"
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.<<GLOBAL>>.UserParm:<<malloc 1>>
TEST.VALUE:main.VCAST_main.argc:2
TEST.VALUE:main.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[1]:<<malloc 5>>
TEST.VALUE:main.VCAST_main.argv[1]:"-U10"
TEST.VALUE:res_mon_qcom.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:main.<<GLOBAL>>.g_loop_flag:0
TEST.EXPECTED:main.VCAST_main.return:0
TEST.EXPECTED:res_mon_qcom.<<GLOBAL>>.slog2_handle:1
TEST.END

-- Test Case: UserPharam_NULL
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:UserPharam_NULL
TEST.STUB:res_mon_qcom.ResMonQcom_EnableGPUBusyStats
TEST.VALUE:main.<<GLOBAL>>.optarg:<<malloc 2>>
TEST.VALUE:main.<<GLOBAL>>.optarg:"1"
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.<<GLOBAL>>.UserParm:<<malloc 9>>
TEST.VALUE:main.<<GLOBAL>>.UserParm:<<null>>
TEST.VALUE:main.VCAST_main.argc:2
TEST.VALUE:main.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[1]:<<malloc 5>>
TEST.VALUE:main.VCAST_main.argv[1]:"-U10"
TEST.VALUE:res_mon_qcom.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:main.<<GLOBAL>>.g_loop_flag:0
TEST.EXPECTED:main.VCAST_main.return:0
TEST.EXPECTED:res_mon_qcom.<<GLOBAL>>.slog2_handle:1
TEST.END

-- Test Case: delay_arg_INT_MAX
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:delay_arg_INT_MAX
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.VCAST_main.argc:2
TEST.VALUE:main.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[1]:<<malloc 13>>
TEST.VALUE:main.VCAST_main.argv[1]:"-d2147483647"
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Test Case: delay_arg_INT_MAX_value
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:delay_arg_INT_MAX_value
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.VALUE:uut_prototype_stubs.strtol.return:-2147483648
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.VCAST_main.argc:2
TEST.VALUE:main.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[1]:<<malloc 13>>
TEST.VALUE:main.VCAST_main.argv[1]:"-d4147483647"
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Test Case: encrypt_arg
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:encrypt_arg
TEST.STUB:res_mon_dlt_if.ResMonDltIf_Init
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.VCAST_main.argc:2
TEST.VALUE:main.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[1]:<<malloc 3>>
TEST.VALUE:main.VCAST_main.argv[1]:"-e"
TEST.VALUE:res_mon_dlt_if.ResMonDltIf_Init.return:1
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Test Case: g_loop_flag_true
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:g_loop_flag_true
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.STUB:res_mon_procfs.ResMonProcfs_Log
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:1
TEST.VALUE:main.VCAST_main.return:0
TEST.EXPECTED:main.<<GLOBAL>>.g_loop_flag:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.slog2f.return
<<main.<<GLOBAL>>.g_loop_flag>>=(0);
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: gpu_busy_stats
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:gpu_busy_stats
TEST.STUB:res_mon_qcom.ResMonQcom_EnableGPUBusyStats
TEST.VALUE:main.<<GLOBAL>>.optarg:<<malloc 2>>
TEST.VALUE:main.<<GLOBAL>>.optarg:"1"
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.VCAST_main.argc:2
TEST.VALUE:main.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[1]:<<malloc 5>>
TEST.VALUE:main.VCAST_main.argv[1]:"-g10"
TEST.VALUE:res_mon_qcom.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:main.<<GLOBAL>>.g_loop_flag:0
TEST.EXPECTED:main.VCAST_main.return:0
TEST.EXPECTED:res_mon_qcom.<<GLOBAL>>.slog2_handle:1
TEST.END

-- Test Case: illegal_arg
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:illegal_arg
TEST.STUB:res_mon_qcom.ResMonQcom_EnableGPUBusyStats
TEST.VALUE:main.<<GLOBAL>>.optarg:<<malloc 2>>
TEST.VALUE:main.<<GLOBAL>>.optarg:"1"
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.VCAST_main.argc:2
TEST.VALUE:main.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[1]:<<malloc 3>>
TEST.VALUE:main.VCAST_main.argv[1]:"-x"
TEST.VALUE:res_mon_qcom.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:main.<<GLOBAL>>.g_loop_flag:0
TEST.EXPECTED:main.VCAST_main.return:0
TEST.EXPECTED:res_mon_qcom.<<GLOBAL>>.slog2_handle:1
TEST.END

-- Test Case: perf_arg
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:perf_arg
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_ddr_mx8.ResMonDDR_Init
TEST.STUB:res_mon_ddr_mx8.ResMonDDR_Log
TEST.STUB:res_mon_ddr_mx8.ResMonDDR_Shutdown
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.STUB:res_mon_procfs.ResMonProcfs_Log
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:1
TEST.VALUE:main.VCAST_main.argc:2
TEST.VALUE:main.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[0]:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[0]:"2"
TEST.VALUE:main.VCAST_main.argv[1]:<<malloc 3>>
TEST.VALUE:main.VCAST_main.argv[1]:"-p"
TEST.VALUE:res_mon_ddr_mx8.ResMonDDR_Init.return:0
TEST.EXPECTED:main.<<GLOBAL>>.g_loop_flag:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.slog2f.return
<<main.<<GLOBAL>>.g_loop_flag>>=(0);
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: perf_arg_ResMonDDR_Init_fail
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:perf_arg_ResMonDDR_Init_fail
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_ddr_mx8.ResMonDDR_Init
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.VCAST_main.argc:2
TEST.VALUE:main.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[1]:<<malloc 3>>
TEST.VALUE:main.VCAST_main.argv[1]:"-p"
TEST.VALUE:res_mon_ddr_mx8.ResMonDDR_Init.return:-1
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Test Case: procmgr_ability_true
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:procmgr_ability_true
TEST.STUB:debug.res_mon_enable_logging
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_ddr_mx8.ResMonDDR_Init
TEST.STUB:res_mon_ddr_mx8.ResMonDDR_Log
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.STUB:res_mon_qcom.ResMonQcom_EnableGPUBusyStats
TEST.VALUE:debug.res_mon_enable_logging.return:1
TEST.VALUE:uut_prototype_stubs.seteuid.return:-1
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:-1
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:-1
TEST.VALUE:uut_prototype_stubs.set_ids_from_arg.return:EOK
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.<<GLOBAL>>.UserParm:<<malloc 3>>
TEST.VALUE:main.<<GLOBAL>>.UserParm:"-1"
TEST.EXPECTED:main.<<GLOBAL>>.g_loop_flag:0
TEST.END

-- Test Case: procmgr_ability_true_pass
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:procmgr_ability_true_pass
TEST.STUB:debug.res_mon_enable_logging
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_ddr_mx8.ResMonDDR_Init
TEST.STUB:res_mon_ddr_mx8.ResMonDDR_Log
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.STUB:res_mon_qcom.ResMonQcom_EnableGPUBusyStats
TEST.VALUE:debug.res_mon_enable_logging.return:1
TEST.VALUE:uut_prototype_stubs.seteuid.return:0
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:-1
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:0,-1
TEST.VALUE:uut_prototype_stubs.set_ids_from_arg.return:EOK
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.<<GLOBAL>>.UserParm:<<malloc 3>>
TEST.VALUE:main.<<GLOBAL>>.UserParm:"-1"
TEST.EXPECTED:main.<<GLOBAL>>.g_loop_flag:0
TEST.END

-- Test Case: set_ids
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:set_ids
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.STUB:res_mon_procfs.ResMonProcfs_Log
TEST.VALUE:uut_prototype_stubs.seteuid.return:-1
TEST.VALUE:uut_prototype_stubs.set_ids_from_arg.return:-1
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.<<GLOBAL>>.UserParm:<<malloc 3>>
TEST.VALUE:main.<<GLOBAL>>.UserParm:"-1"
TEST.EXPECTED:main.<<GLOBAL>>.g_loop_flag:0
TEST.END

-- Test Case: seteuid_return_-1
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:seteuid_return_-1
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.STUB:res_mon_procfs.ResMonProcfs_Log
TEST.VALUE:uut_prototype_stubs.seteuid.return:-1
TEST.VALUE:uut_prototype_stubs.set_ids_from_arg.return:0
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.<<GLOBAL>>.UserParm:<<malloc 3>>
TEST.VALUE:main.<<GLOBAL>>.UserParm:"-1"
TEST.EXPECTED:main.<<GLOBAL>>.g_loop_flag:0
TEST.END

-- Test Case: upload_arg_ResMonDltIf_Init_fail
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:upload_arg_ResMonDltIf_Init_fail
TEST.STUB:res_mon_comm_if.ResMonCommIf_Init
TEST.STUB:res_mon_comm_if.ResMonCommIf_Shutdown
TEST.STUB:res_mon_dlt_if.ResMonDltIf_Init
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Init
TEST.STUB:res_mon_qcom.ResMonQcom_EnableGPUBusyStats
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.VCAST_main.argc:2
TEST.VALUE:main.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[1]:<<malloc 3>>
TEST.VALUE:main.VCAST_main.argv[1]:"-u"
TEST.VALUE:res_mon_dlt_if.ResMonDltIf_Init.return:-1
TEST.EXPECTED:main.VCAST_main.return:0
TEST.END

-- Test Case: user_parm_ResMonCommif_Shutdown
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:user_parm_ResMonCommif_Shutdown
TEST.STUB:res_mon_qcom.ResMonQcom_EnableGPUBusyStats
TEST.VALUE:main.<<GLOBAL>>.optarg:<<malloc 2>>
TEST.VALUE:main.<<GLOBAL>>.optarg:"1"
TEST.VALUE:main.<<GLOBAL>>.g_loop_flag:0
TEST.VALUE:main.<<GLOBAL>>.UserParm:<<malloc 3>>
TEST.VALUE:main.<<GLOBAL>>.UserParm:"-1"
TEST.VALUE:main.VCAST_main.argc:2
TEST.VALUE:main.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:main.VCAST_main.argv[1]:<<malloc 3>>
TEST.VALUE:main.VCAST_main.argv[1]:"-u"
TEST.VALUE:res_mon_qcom.<<GLOBAL>>.slog2_handle:-1
TEST.EXPECTED:main.<<GLOBAL>>.g_loop_flag:0
TEST.EXPECTED:main.VCAST_main.return:0
TEST.EXPECTED:res_mon_qcom.<<GLOBAL>>.slog2_handle:-1
TEST.END

-- Unit: res_mon_comm_if

-- Subprogram: ResMonCommIf_Init

-- Test Case: 01_already_init
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_Init
TEST.NEW
TEST.NAME:01_already_init
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.vmf_client_id:0
TEST.EXPECTED:res_mon_comm_if.ResMonCommIf_Init.return:RM_OK
TEST.END

-- Test Case: 02_first_init_failed
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_Init
TEST.NEW
TEST.NAME:02_first_init_failed
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:-1
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.vmf_client_id:-1
TEST.EXPECTED:res_mon_comm_if.ResMonCommIf_Init.return:RM_FAILED
TEST.END

-- Test Case: 03_first_init_register_failed
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_Init
TEST.NEW
TEST.NAME:03_first_init_register_failed
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:0
TEST.VALUE:uut_prototype_stubs.nw_vmf_register_msg_group.return:-1
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.vmf_client_id:-1
TEST.EXPECTED:res_mon_comm_if.ResMonCommIf_Init.return:RM_FAILED
TEST.END

-- Test Case: 05_first_init_pass
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_Init
TEST.NEW
TEST.NAME:05_first_init_pass
TEST.VALUE:uut_prototype_stubs.pthread_create.return:0
TEST.VALUE:uut_prototype_stubs.nw_vmf_connect.return:0
TEST.VALUE:uut_prototype_stubs.nw_vmf_register_msg_group.return:VMF_OK
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.vmf_client_id:-1
TEST.EXPECTED:res_mon_comm_if.ResMonCommIf_Init.return:RM_OK
TEST.END

-- Subprogram: ResMonCommIf_ReceiveThread

-- Test Case: 01_no_data
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_ReceiveThread
TEST.NEW
TEST.NAME:01_no_data
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag:TRUE
TEST.FLOW
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
  uut_prototype_stubs.nw_vmf_receive
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
TEST.END_FLOW
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.nw_vmf_receive.return
<<res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag>>=(FALSE);
<<uut_prototype_stubs.nw_vmf_receive.return>> = ( 0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 02_data_invalid
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_ReceiveThread
TEST.NEW
TEST.NAME:02_data_invalid
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag:TRUE
TEST.FLOW
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
  uut_prototype_stubs.nw_vmf_receive
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
TEST.END_FLOW
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.nw_vmf_receive.return
<<res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag>>=(FALSE);
<<uut_prototype_stubs.nw_vmf_receive.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 03_invalid_hdr_size
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_ReceiveThread
TEST.NEW
TEST.NAME:03_invalid_hdr_size
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].grp_id:0xC0
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].evt_id:0x1
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].payload_len:0
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag:TRUE
TEST.FLOW
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
  uut_prototype_stubs.nw_vmf_receive
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
TEST.END_FLOW
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.nw_vmf_receive.return
<<res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag>>=(FALSE);
<<uut_prototype_stubs.nw_vmf_receive.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 04_valid_hdr_extract_fail
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_ReceiveThread
TEST.NEW
TEST.NAME:04_valid_hdr_extract_fail
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Start
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].grp_id:0xC0
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].evt_id:0x1
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].payload_len:RES_MON_DUMP_GET_HDR_SIZE
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag:TRUE
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Start.return:-1
TEST.FLOW
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
  uut_prototype_stubs.nw_vmf_receive
  res_mon_extract_package.c.ResMonExtractPackage_Start
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
TEST.END_FLOW
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.nw_vmf_receive.return
<<res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag>>=(FALSE);
<<uut_prototype_stubs.nw_vmf_receive.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 05_valid_hdr_extract_pass
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_ReceiveThread
TEST.NEW
TEST.NAME:05_valid_hdr_extract_pass
TEST.STUB:res_mon_comm_if.ResMonCommIf_SendHeaderInfo
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Start
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].grp_id:0xC0
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].evt_id:0x1
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].payload_len:RES_MON_DUMP_GET_HDR_SIZE
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag:TRUE
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Start.return:RM_OK
TEST.FLOW
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
  uut_prototype_stubs.nw_vmf_receive
  res_mon_extract_package.c.ResMonExtractPackage_Start
  res_mon_comm_if.c.ResMonCommIf_SendHeaderInfo
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
TEST.END_FLOW
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.nw_vmf_receive.return
<<res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag>>=(FALSE);
<<uut_prototype_stubs.nw_vmf_receive.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 06_data_extract_fail
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_ReceiveThread
TEST.NEW
TEST.NAME:06_data_extract_fail
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Read
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].grp_id:0xC0
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].evt_id:0x2
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].payload_len:0
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag:TRUE
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Read.return:-1
TEST.FLOW
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
  uut_prototype_stubs.nw_vmf_receive
  res_mon_extract_package.c.ResMonExtractPackage_Read
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
TEST.END_FLOW
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.nw_vmf_receive.return
<<res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag>>=(FALSE);
<<uut_prototype_stubs.nw_vmf_receive.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 07_data_extract_pass
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_ReceiveThread
TEST.NEW
TEST.NAME:07_data_extract_pass
TEST.STUB:res_mon_comm_if.ResMonCommIf_SendData
TEST.STUB:res_mon_extract_package.ResMonExtractPackage_Read
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].grp_id:0xC0
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].evt_id:0x2
TEST.VALUE:uut_prototype_stubs.nw_vmf_receive.p_vmf_msg[0].payload_len:0
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag:TRUE
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Read.return:RM_OK
TEST.FLOW
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
  uut_prototype_stubs.nw_vmf_receive
  res_mon_extract_package.c.ResMonExtractPackage_Read
  res_mon_comm_if.c.ResMonCommIf_SendData
  res_mon_comm_if.c.ResMonCommIf_ReceiveThread
TEST.END_FLOW
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.nw_vmf_receive.return
<<res_mon_comm_if.<<GLOBAL>>.g_vmf_loop_flag>>=(FALSE);
<<uut_prototype_stubs.nw_vmf_receive.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: ResMonCommIf_SendData

-- Test Case: 01_send_fail
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_SendData
TEST.NEW
TEST.NAME:01_send_fail
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:-1
TEST.EXPECTED:res_mon_comm_if.ResMonCommIf_SendData.return:RM_FAILED
TEST.END

-- Test Case: 02_send_pass
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_SendData
TEST.NEW
TEST.NAME:02_send_pass
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:0
TEST.EXPECTED:res_mon_comm_if.ResMonCommIf_SendData.return:RM_OK
TEST.END

-- Subprogram: ResMonCommIf_SendHeaderInfo

-- Test Case: 01_send_fail
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_SendHeaderInfo
TEST.NEW
TEST.NAME:01_send_fail
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:-1
TEST.VALUE:res_mon_comm_if.ResMonCommIf_SendHeaderInfo.hdr:<<malloc 1>>
TEST.EXPECTED:res_mon_comm_if.ResMonCommIf_SendHeaderInfo.return:RM_FAILED
TEST.END

-- Test Case: 02_send_pass
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_SendHeaderInfo
TEST.NEW
TEST.NAME:02_send_pass
TEST.VALUE:uut_prototype_stubs.nw_vmf_send_basic.return:0
TEST.VALUE:res_mon_comm_if.ResMonCommIf_SendHeaderInfo.hdr:<<malloc 1>>
TEST.EXPECTED:res_mon_comm_if.ResMonCommIf_SendHeaderInfo.return:RM_OK
TEST.END

-- Subprogram: ResMonCommIf_Shutdown

-- Test Case: 01_already_shutdown
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_Shutdown
TEST.NEW
TEST.NAME:01_already_shutdown
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.vmf_client_id:-1
TEST.EXPECTED:res_mon_comm_if.ResMonCommIf_Shutdown.return:RM_OK
TEST.END

-- Test Case: 02_first_shutdown_failed
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_Shutdown
TEST.NEW
TEST.NAME:02_first_shutdown_failed
TEST.VALUE:uut_prototype_stubs.nw_vmf_disconnect.return:-1
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.vmf_client_id:0
TEST.EXPECTED:res_mon_comm_if.ResMonCommIf_Shutdown.return:RM_OK
TEST.END

-- Test Case: 03_first_shutdown_pass
TEST.UNIT:res_mon_comm_if
TEST.SUBPROGRAM:ResMonCommIf_Shutdown
TEST.NEW
TEST.NAME:03_first_shutdown_pass
TEST.VALUE:uut_prototype_stubs.nw_vmf_disconnect.return:0
TEST.VALUE:res_mon_comm_if.<<GLOBAL>>.vmf_client_id:0
TEST.EXPECTED:res_mon_comm_if.ResMonCommIf_Shutdown.return:RM_OK
TEST.END

-- Unit: res_mon_ddr_mx8

-- Subprogram: ResMonDDR_Init

-- Test Case: 01_mmap_device_io_fail
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ResMonDDR_Init
TEST.NEW
TEST.NAME:01_mmap_device_io_fail
TEST.STUB:res_mon_ddr_mx8.ddr_mon_enable
TEST.STUB:res_mon_ddr_mx8.ddr_mon_event_enable
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:MAP_FAILED
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.stub_qtime:<<malloc 1>>
TEST.EXPECTED:res_mon_ddr_mx8.ResMonDDR_Init.return:RM_FAILED
TEST.END

-- Test Case: 02_mmap_device_io_pass
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ResMonDDR_Init
TEST.NEW
TEST.NAME:02_mmap_device_io_pass
TEST.STUB:res_mon_ddr_mx8.ddr_mon_enable
TEST.STUB:res_mon_ddr_mx8.ddr_mon_event_enable
TEST.VALUE:uut_prototype_stubs.mmap_device_io.return:1
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.stub_qtime:<<malloc 1>>
TEST.EXPECTED:res_mon_ddr_mx8.ResMonDDR_Init.return:RM_OK
TEST.END

-- Subprogram: ResMonDDR_Log

-- Test Case: 01_no_evt
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ResMonDDR_Log
TEST.NEW
TEST.NAME:01_no_evt
TEST.VALUE:uut_prototype_stubs.in32.return:0
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.evt:1
TEST.EXPECTED:res_mon_ddr_mx8.ResMonDDR_Log.return:RM_OK
TEST.END

-- Test Case: 02_no_evt_in32_pass
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ResMonDDR_Log
TEST.NEW
TEST.NAME:02_no_evt_in32_pass
TEST.STUB:res_mon_ddr_mx8.ddr_mon_enable
TEST.VALUE:uut_prototype_stubs.in32.return:1
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.evt:1
TEST.EXPECTED:res_mon_ddr_mx8.ResMonDDR_Log.return:RM_OK
TEST.END

-- Test Case: 03_evt_in32_fail
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ResMonDDR_Log
TEST.NEW
TEST.NAME:03_evt_in32_fail
TEST.STUB:res_mon_ddr_mx8.ddr_mon_read_counter
TEST.VALUE:uut_prototype_stubs.in32.return:0
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.events[1]:cycles
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.evt:2
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.cps:1000
TEST.EXPECTED:res_mon_ddr_mx8.ResMonDDR_Log.return:RM_OK
TEST.END

-- Test Case: 04_evt_twice_in32_fail
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ResMonDDR_Log
TEST.NEW
TEST.NAME:04_evt_twice_in32_fail
TEST.STUB:res_mon_ddr_mx8.ddr_mon_read_counter
TEST.STUB:res_mon_ddr_mx8.get_speed_mb
TEST.VALUE:uut_prototype_stubs.in32.return:0
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.events[1]:read_cycles
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.events[2]:write_cycles
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.evt:3
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.cps:1000
TEST.EXPECTED:res_mon_ddr_mx8.ResMonDDR_Log.return:RM_OK
TEST.END

-- Test Case: 05_evt_twice_in32_pass
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ResMonDDR_Log
TEST.NEW
TEST.NAME:05_evt_twice_in32_pass
TEST.STUB:res_mon_ddr_mx8.ddr_mon_enable
TEST.STUB:res_mon_ddr_mx8.ddr_mon_event_enable
TEST.STUB:res_mon_ddr_mx8.ddr_mon_read_counter
TEST.VALUE:uut_prototype_stubs.in32.return:1
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.events[1]:cycles
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.evt:2
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.cps:1000
TEST.EXPECTED:res_mon_ddr_mx8.ResMonDDR_Log.return:RM_OK
TEST.END

-- Subprogram: ResMonDDR_Shutdown

-- Test Case: 01_shutdown
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ResMonDDR_Shutdown
TEST.NEW
TEST.NAME:01_shutdown
TEST.VALUE:uut_prototype_stubs.munmap_device_io.return:0
TEST.EXPECTED:res_mon_ddr_mx8.ResMonDDR_Shutdown.return:RM_OK
TEST.END

-- Subprogram: ddr_mon_enable

-- Test Case: 01_enable_true
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ddr_mon_enable
TEST.NEW
TEST.NAME:01_enable_true
TEST.VALUE:res_mon_ddr_mx8.ddr_mon_enable.enable:true
TEST.FLOW
  res_mon_ddr_mx8.c.ddr_mon_enable
  uut_prototype_stubs.out32
  uut_prototype_stubs.out32
  res_mon_ddr_mx8.c.ddr_mon_enable
TEST.END_FLOW
TEST.END

-- Test Case: 02_enable_false
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ddr_mon_enable
TEST.NEW
TEST.NAME:02_enable_false
TEST.VALUE:res_mon_ddr_mx8.ddr_mon_enable.enable:false
TEST.FLOW
  res_mon_ddr_mx8.c.ddr_mon_enable
  uut_prototype_stubs.in32
  uut_prototype_stubs.out32
  res_mon_ddr_mx8.c.ddr_mon_enable
TEST.END_FLOW
TEST.END

-- Subprogram: ddr_mon_event_enable

-- Test Case: 01_enable_true
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ddr_mon_event_enable
TEST.NEW
TEST.NAME:01_enable_true
TEST.VALUE:res_mon_ddr_mx8.ddr_mon_event_enable.enable:true
TEST.FLOW
  res_mon_ddr_mx8.c.ddr_mon_event_enable
  uut_prototype_stubs.out32
  uut_prototype_stubs.out32
  res_mon_ddr_mx8.c.ddr_mon_event_enable
TEST.END_FLOW
TEST.END

-- Test Case: 02_enable_false
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ddr_mon_event_enable
TEST.NEW
TEST.NAME:02_enable_false
TEST.VALUE:res_mon_ddr_mx8.ddr_mon_event_enable.enable:false
TEST.FLOW
  res_mon_ddr_mx8.c.ddr_mon_event_enable
  uut_prototype_stubs.in32
  uut_prototype_stubs.out32
  res_mon_ddr_mx8.c.ddr_mon_event_enable
TEST.END_FLOW
TEST.END

-- Subprogram: ddr_mon_read_counter

-- Test Case: 01_read
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:ddr_mon_read_counter
TEST.NEW
TEST.NAME:01_read
TEST.VALUE:uut_prototype_stubs.in32.return:1
TEST.EXPECTED:res_mon_ddr_mx8.ddr_mon_read_counter.return:1
TEST.END

-- Subprogram: get_speed_mb

-- Test Case: get_speed_mb.001
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:get_speed_mb
TEST.NEW
TEST.NAME:get_speed_mb.001
TEST.STUB:res_mon_ddr_mx8.ddr_mon_event_enable
TEST.STUB:res_mon_ddr_mx8.ddr_mon_read_counter
TEST.VALUE:uut_prototype_stubs.in32.return:1
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.slog2_handle:1
TEST.VALUE:res_mon_ddr_mx8.ddr_mon_event_enable.enable:true
TEST.VALUE:res_mon_ddr_mx8.ddr_mon_read_counter.return:1
TEST.VALUE:res_mon_ddr_mx8.get_speed_mb.event_cycles:1
TEST.VALUE:res_mon_ddr_mx8.get_speed_mb.time_diff_us:1
TEST.VALUE:res_mon_ddr_mx8.get_speed_mb.return:1
TEST.EXPECTED:res_mon_ddr_mx8.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_ddr_mx8.get_speed_mb.event_cycles:1
TEST.EXPECTED:res_mon_ddr_mx8.get_speed_mb.time_diff_us:1
TEST.END

-- Test Case: get_speed_mb.002
TEST.UNIT:res_mon_ddr_mx8
TEST.SUBPROGRAM:get_speed_mb
TEST.NEW
TEST.NAME:get_speed_mb.002
TEST.STUB:res_mon_ddr_mx8.ddr_mon_event_enable
TEST.STUB:res_mon_ddr_mx8.ddr_mon_read_counter
TEST.VALUE:uut_prototype_stubs.in32.return:1
TEST.VALUE:res_mon_ddr_mx8.<<GLOBAL>>.slog2_handle:1
TEST.VALUE:res_mon_ddr_mx8.ddr_mon_event_enable.enable:true
TEST.VALUE:res_mon_ddr_mx8.ddr_mon_read_counter.return:1
TEST.VALUE:res_mon_ddr_mx8.get_speed_mb.event_cycles:0
TEST.VALUE:res_mon_ddr_mx8.get_speed_mb.time_diff_us:0
TEST.VALUE:res_mon_ddr_mx8.get_speed_mb.return:0
TEST.EXPECTED:res_mon_ddr_mx8.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_ddr_mx8.get_speed_mb.event_cycles:0
TEST.EXPECTED:res_mon_ddr_mx8.get_speed_mb.time_diff_us:0
TEST.END

-- Unit: res_mon_dlt_if

-- Subprogram: ResMonDltIf_Init

-- Test Case: 01_init
TEST.UNIT:res_mon_dlt_if
TEST.SUBPROGRAM:ResMonDltIf_Init
TEST.NEW
TEST.NAME:01_init
TEST.EXPECTED:res_mon_dlt_if.ResMonDltIf_Init.return:RM_OK
TEST.END

-- Subprogram: ResMonDltIf_InjectionCbk

-- Test Case: 01_service_id_invalid
TEST.UNIT:res_mon_dlt_if
TEST.SUBPROGRAM:ResMonDltIf_InjectionCbk
TEST.NEW
TEST.NAME:01_service_id_invalid
TEST.VALUE:res_mon_dlt_if.ResMonDltIf_InjectionCbk.service_id:0
TEST.EXPECTED:res_mon_dlt_if.ResMonDltIf_InjectionCbk.return:RM_FAILED
TEST.END

-- Test Case: 02_service_id_UPLOAD_ENCRYPT_LOG_DUMP
TEST.UNIT:res_mon_dlt_if
TEST.SUBPROGRAM:ResMonDltIf_InjectionCbk
TEST.NEW
TEST.NAME:02_service_id_UPLOAD_ENCRYPT_LOG_DUMP
TEST.STUB:res_mon_package.ResMonPackage_Create
TEST.VALUE:res_mon_dlt_if.ResMonDltIf_InjectionCbk.service_id:0x1002
TEST.VALUE:res_mon_package.ResMonPackage_Create.return:RM_OK
TEST.EXPECTED:res_mon_dlt_if.ResMonDltIf_InjectionCbk.return:RM_OK
TEST.END

-- Test Case: 03_service_id_UPLOAD_PLAIN_LOG_DUMP
TEST.UNIT:res_mon_dlt_if
TEST.SUBPROGRAM:ResMonDltIf_InjectionCbk
TEST.NEW
TEST.NAME:03_service_id_UPLOAD_PLAIN_LOG_DUMP
TEST.STUB:res_mon_package.ResMonPackage_Create
TEST.VALUE:res_mon_dlt_if.<<GLOBAL>>.always_encrypt:FALSE
TEST.VALUE:res_mon_dlt_if.ResMonDltIf_InjectionCbk.service_id:0x1001
TEST.VALUE:res_mon_package.ResMonPackage_Create.return:RM_OK
TEST.EXPECTED:res_mon_dlt_if.ResMonDltIf_InjectionCbk.return:RM_OK
TEST.END

-- Test Case: 04_service_id_UPLOAD_PLAIN_LOG_DUMP_enc
TEST.UNIT:res_mon_dlt_if
TEST.SUBPROGRAM:ResMonDltIf_InjectionCbk
TEST.NEW
TEST.NAME:04_service_id_UPLOAD_PLAIN_LOG_DUMP_enc
TEST.STUB:res_mon_package.ResMonPackage_Create
TEST.VALUE:res_mon_dlt_if.<<GLOBAL>>.always_encrypt:TRUE
TEST.VALUE:res_mon_dlt_if.ResMonDltIf_InjectionCbk.service_id:0x1001
TEST.VALUE:res_mon_package.ResMonPackage_Create.return:RM_OK
TEST.EXPECTED:res_mon_dlt_if.ResMonDltIf_InjectionCbk.return:RM_OK
TEST.END

-- Subprogram: ResMonDltIf_Send

-- Test Case: 01_dlt_user_log_file_infoAbout_fail
TEST.UNIT:res_mon_dlt_if
TEST.SUBPROGRAM:ResMonDltIf_Send
TEST.NEW
TEST.NAME:01_dlt_user_log_file_infoAbout_fail
TEST.VALUE:uut_prototype_stubs.dlt_user_log_file_infoAbout.return:-1
TEST.EXPECTED:res_mon_dlt_if.ResMonDltIf_Send.return:RM_FAILED
TEST.END

-- Test Case: 02_dlt_user_log_file_complete_fail
TEST.UNIT:res_mon_dlt_if
TEST.SUBPROGRAM:ResMonDltIf_Send
TEST.NEW
TEST.NAME:02_dlt_user_log_file_complete_fail
TEST.VALUE:uut_prototype_stubs.dlt_user_log_file_infoAbout.return:0
TEST.VALUE:uut_prototype_stubs.dlt_user_log_file_complete.return:-1
TEST.EXPECTED:res_mon_dlt_if.ResMonDltIf_Send.return:RM_FAILED
TEST.END

-- Test Case: 03_success
TEST.UNIT:res_mon_dlt_if
TEST.SUBPROGRAM:ResMonDltIf_Send
TEST.NEW
TEST.NAME:03_success
TEST.VALUE:uut_prototype_stubs.dlt_user_log_file_infoAbout.return:0
TEST.VALUE:uut_prototype_stubs.dlt_user_log_file_complete.return:0
TEST.EXPECTED:res_mon_dlt_if.ResMonDltIf_Send.return:RM_OK
TEST.END

-- Unit: res_mon_extract_package

-- Subprogram: ResMonExtractPackage_Close

-- Test Case: 01_cleanup
TEST.UNIT:res_mon_extract_package
TEST.SUBPROGRAM:ResMonExtractPackage_Close
TEST.NEW
TEST.NAME:01_cleanup
TEST.STUB:uut_prototype_stubs.fclose
TEST.STUB:uut_prototype_stubs.remove
TEST.EXPECTED:res_mon_extract_package.ResMonExtractPackage_Close.return:RM_OK
TEST.END

-- Subprogram: ResMonExtractPackage_Init

-- Test Case: ResMonExtractPackage_Init.001
TEST.UNIT:res_mon_extract_package
TEST.SUBPROGRAM:ResMonExtractPackage_Init
TEST.NEW
TEST.NAME:ResMonExtractPackage_Init.001
TEST.VALUE:res_mon_extract_package.<<GLOBAL>>.file_bytes_sent:1
TEST.EXPECTED:res_mon_extract_package.<<GLOBAL>>.file_bytes_sent:0
TEST.EXPECTED:res_mon_extract_package.ResMonExtractPackage_Init.return:RM_OK
TEST.VALUE_USER_CODE:res_mon_extract_package.<<GLOBAL>>.fp
<<res_mon_extract_package.<<GLOBAL>>.fp>> = (FILE *)1;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:res_mon_extract_package.<<GLOBAL>>.fp
{{ <<res_mon_extract_package.<<GLOBAL>>.fp>> == ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: ResMonExtractPackage_Read

-- Test Case: 01_data_arg_null
TEST.UNIT:res_mon_extract_package
TEST.SUBPROGRAM:ResMonExtractPackage_Read
TEST.NEW
TEST.NAME:01_data_arg_null
TEST.VALUE:res_mon_extract_package.<<GLOBAL>>.file_bytes_sent:1
TEST.EXPECTED:res_mon_extract_package.ResMonExtractPackage_Read.return:RM_FAILED
TEST.VALUE_USER_CODE:res_mon_extract_package.<<GLOBAL>>.file_stat
<<res_mon_extract_package.<<GLOBAL>>.file_stat.st_size>> = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:res_mon_extract_package.ResMonExtractPackage_Read.data
<<res_mon_extract_package.ResMonExtractPackage_Read.data>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:res_mon_extract_package.ResMonExtractPackage_Read.size
<<res_mon_extract_package.ResMonExtractPackage_Read.size>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 02_data_arg_not_null
TEST.UNIT:res_mon_extract_package
TEST.SUBPROGRAM:ResMonExtractPackage_Read
TEST.NEW
TEST.NAME:02_data_arg_not_null
TEST.VALUE:res_mon_extract_package.<<GLOBAL>>.file_bytes_sent:1
TEST.EXPECTED:res_mon_extract_package.ResMonExtractPackage_Read.return:RM_FAILED
TEST.VALUE_USER_CODE:res_mon_extract_package.<<GLOBAL>>.file_stat
<<res_mon_extract_package.<<GLOBAL>>.file_stat.st_size>> = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:res_mon_extract_package.ResMonExtractPackage_Read.data
<<res_mon_extract_package.ResMonExtractPackage_Read.data>> = (uint8_t *)1;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:res_mon_extract_package.ResMonExtractPackage_Read.size
<<res_mon_extract_package.ResMonExtractPackage_Read.size>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 03_size_arg_not_null
TEST.UNIT:res_mon_extract_package
TEST.SUBPROGRAM:ResMonExtractPackage_Read
TEST.NEW
TEST.NAME:03_size_arg_not_null
TEST.VALUE:res_mon_extract_package.<<GLOBAL>>.file_bytes_sent:1
TEST.EXPECTED:res_mon_extract_package.ResMonExtractPackage_Read.return:RM_FAILED
TEST.VALUE_USER_CODE:res_mon_extract_package.<<GLOBAL>>.file_stat
<<res_mon_extract_package.<<GLOBAL>>.file_stat.st_size>> = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:res_mon_extract_package.ResMonExtractPackage_Read.data
<<res_mon_extract_package.ResMonExtractPackage_Read.data>> = (uint8_t *)1;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:res_mon_extract_package.ResMonExtractPackage_Read.size
<<res_mon_extract_package.ResMonExtractPackage_Read.size>> = (uint32_t *)1;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 04_fread_zero
TEST.UNIT:res_mon_extract_package
TEST.SUBPROGRAM:ResMonExtractPackage_Read
TEST.NEW
TEST.NAME:04_fread_zero
TEST.STUB:uut_prototype_stubs.fread
TEST.VALUE:uut_prototype_stubs.fread.return:0
TEST.VALUE:res_mon_extract_package.<<GLOBAL>>.file_bytes_sent:0
TEST.EXPECTED:res_mon_extract_package.ResMonExtractPackage_Read.return:RM_FAILED
TEST.VALUE_USER_CODE:res_mon_extract_package.<<GLOBAL>>.file_stat
<<res_mon_extract_package.<<GLOBAL>>.file_stat.st_size>> = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:res_mon_extract_package.ResMonExtractPackage_Read.data
<<res_mon_extract_package.ResMonExtractPackage_Read.data>> = (uint8_t *)1;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:res_mon_extract_package.ResMonExtractPackage_Read.size
uint32_t size_arg;
<<res_mon_extract_package.ResMonExtractPackage_Read.size>> = &size_arg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 05_fread_valid
TEST.UNIT:res_mon_extract_package
TEST.SUBPROGRAM:ResMonExtractPackage_Read
TEST.NEW
TEST.NAME:05_fread_valid
TEST.STUB:uut_prototype_stubs.fread
TEST.VALUE:uut_prototype_stubs.fread.return:1
TEST.VALUE:res_mon_extract_package.<<GLOBAL>>.file_bytes_sent:0
TEST.EXPECTED:res_mon_extract_package.ResMonExtractPackage_Read.return:RM_OK
TEST.VALUE_USER_CODE:res_mon_extract_package.<<GLOBAL>>.file_stat
<<res_mon_extract_package.<<GLOBAL>>.file_stat.st_size>> = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:res_mon_extract_package.ResMonExtractPackage_Read.data
<<res_mon_extract_package.ResMonExtractPackage_Read.data>> = (uint8_t *)1;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:res_mon_extract_package.ResMonExtractPackage_Read.size
uint32_t size_arg;
<<res_mon_extract_package.ResMonExtractPackage_Read.size>> = &size_arg;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: ResMonExtractPackage_Start

-- Test Case: 01_ResMonPackage_Create_fail
TEST.UNIT:res_mon_extract_package
TEST.SUBPROGRAM:ResMonExtractPackage_Start
TEST.NEW
TEST.NAME:01_ResMonPackage_Create_fail
TEST.STUB:res_mon_package.ResMonPackage_Create
TEST.VALUE:res_mon_package.ResMonPackage_Create.return:RM_FAILED
TEST.EXPECTED:res_mon_extract_package.ResMonExtractPackage_Start.return:RM_FAILED
TEST.END

-- Test Case: 02_fopen_fail
TEST.UNIT:res_mon_extract_package
TEST.SUBPROGRAM:ResMonExtractPackage_Start
TEST.NEW
TEST.NAME:02_fopen_fail
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:res_mon_package.ResMonPackage_Create
TEST.VALUE:res_mon_package.ResMonPackage_Create.return:RM_OK
TEST.EXPECTED:res_mon_extract_package.ResMonExtractPackage_Start.return:RM_FAILED
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)NULL );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 02_fopen_pass_fstat_fail
TEST.UNIT:res_mon_extract_package
TEST.SUBPROGRAM:ResMonExtractPackage_Start
TEST.NEW
TEST.NAME:02_fopen_pass_fstat_fail
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.fseek
TEST.STUB:uut_prototype_stubs.fstat
TEST.STUB:uut_prototype_stubs.fileno
TEST.STUB:res_mon_package.ResMonPackage_Create
TEST.VALUE:uut_prototype_stubs.fstat.return:-1
TEST.VALUE:uut_prototype_stubs.fileno.return:1
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Start.file_hdr:<<malloc 1>>
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Start.file_hdr[0].filename:<<malloc 25>>
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Start.file_hdr[0].filename:"..//stubs/testfile.txt"
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Start.file_hdr[0].filesize:1024
TEST.VALUE:res_mon_package.ResMonPackage_Create.return:RM_OK
TEST.EXPECTED:res_mon_extract_package.ResMonExtractPackage_Start.return:RM_FAILED
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
char *filename = "../stubs/testfile.txt";
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)filename );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 02_fopen_pass_fstat_pass
TEST.UNIT:res_mon_extract_package
TEST.SUBPROGRAM:ResMonExtractPackage_Start
TEST.NEW
TEST.NAME:02_fopen_pass_fstat_pass
TEST.STUB:uut_prototype_stubs.fopen
TEST.STUB:uut_prototype_stubs.fseek
TEST.STUB:uut_prototype_stubs.fstat
TEST.STUB:uut_prototype_stubs.fileno
TEST.STUB:res_mon_package.ResMonPackage_Create
TEST.VALUE:uut_prototype_stubs.fstat.return:0
TEST.VALUE:uut_prototype_stubs.fileno.return:1
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Start.file_hdr:<<malloc 1>>
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Start.file_hdr[0].filename:<<malloc 25>>
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Start.file_hdr[0].filename:"..//stubs/testfile.txt"
TEST.VALUE:res_mon_extract_package.ResMonExtractPackage_Start.file_hdr[0].filesize:1024
TEST.VALUE:res_mon_package.ResMonPackage_Create.return:RM_OK
TEST.EXPECTED:res_mon_extract_package.ResMonExtractPackage_Start.return:RM_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.fopen.return
char *filename = "../stubs/testfile.txt";
<<uut_prototype_stubs.fopen.return>> = ( (FILE*)filename );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Unit: res_mon_package

-- Subprogram: ParseFileExtensionsInDirectory

-- Test Case: directory_pass
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ParseFileExtensionsInDirectory
TEST.NEW
TEST.NAME:directory_pass
TEST.STUB:uut_prototype_stubs.strncmp
TEST.VALUE:uut_prototype_stubs.strncmp.VCAST_PARAM_3:0
TEST.VALUE:uut_prototype_stubs.strncmp.return:-1
TEST.VALUE:res_mon_package.ParseFileExtensionsInDirectory.directory:<<null>>
TEST.VALUE:res_mon_package.ParseFileExtensionsInDirectory.return:1
TEST.END

-- Test Case: file_extension_pass
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ParseFileExtensionsInDirectory
TEST.NEW
TEST.NAME:file_extension_pass
TEST.STUB:uut_prototype_stubs.strncmp
TEST.VALUE:uut_prototype_stubs.strncmp.VCAST_PARAM_3:2
TEST.VALUE:uut_prototype_stubs.strncmp.return:0
TEST.VALUE:res_mon_package.ParseFileExtensionsInDirectory.directory:<<malloc 1>>
TEST.VALUE:res_mon_package.ParseFileExtensionsInDirectory.directory[0].d_name:<<malloc 2>>
TEST.VALUE:res_mon_package.ParseFileExtensionsInDirectory.directory[0].d_name:"1"
TEST.VALUE:res_mon_package.ParseFileExtensionsInDirectory.return:1
TEST.END

-- Subprogram: ResMonPackage_Create

-- Test Case: 01_clock_gettime_fail
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_Create
TEST.NEW
TEST.NAME:01_clock_gettime_fail
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:-1
TEST.EXPECTED:res_mon_package.ResMonPackage_Create.return:RM_FAILED
TEST.END

-- Test Case: 02_posix_spawn_fail
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_Create
TEST.NEW
TEST.NAME:02_posix_spawn_fail
TEST.VALUE:uut_prototype_stubs.posix_spawn.return:-1
TEST.EXPECTED:res_mon_package.ResMonPackage_Create.return:RM_FAILED
TEST.END

-- Test Case: 03_waitpid_fail
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_Create
TEST.NEW
TEST.NAME:03_waitpid_fail
TEST.VALUE:uut_prototype_stubs.waitpid.return:-1
TEST.EXPECTED:res_mon_package.ResMonPackage_Create.return:RM_FAILED
TEST.END

-- Test Case: 04_encrypt_false_pass
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_Create
TEST.NEW
TEST.NAME:04_encrypt_false_pass
TEST.EXPECTED:res_mon_package.ResMonPackage_Create.return:RM_OK
TEST.VALUE_USER_CODE:res_mon_package.ResMonPackage_Create.file
 char tmp_file[PACKAGE_PATH_MAX];
<<res_mon_package.ResMonPackage_Create.file>> = ( &tmp_file );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 05_posix_spawn_encrypt_fail
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_Create
TEST.NEW
TEST.NAME:05_posix_spawn_encrypt_fail
TEST.VALUE:uut_prototype_stubs.posix_spawn.return:0,-1
TEST.VALUE:res_mon_package.ResMonPackage_Create.encrypt:1
TEST.EXPECTED:res_mon_package.ResMonPackage_Create.return:RM_FAILED
TEST.VALUE_USER_CODE:res_mon_package.ResMonPackage_Create.file
 char tmp_file[PACKAGE_PATH_MAX];
<<res_mon_package.ResMonPackage_Create.file>> = ( &tmp_file );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 06_waitpid_encrypt_fail
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_Create
TEST.NEW
TEST.NAME:06_waitpid_encrypt_fail
TEST.VALUE:uut_prototype_stubs.waitpid.return:0,-1
TEST.VALUE:res_mon_package.ResMonPackage_Create.encrypt:1
TEST.EXPECTED:res_mon_package.ResMonPackage_Create.return:RM_FAILED
TEST.VALUE_USER_CODE:res_mon_package.ResMonPackage_Create.file
 char tmp_file[PACKAGE_PATH_MAX];
<<res_mon_package.ResMonPackage_Create.file>> = ( &tmp_file );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 07_encrypt_true_pass
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_Create
TEST.NEW
TEST.NAME:07_encrypt_true_pass
TEST.VALUE:res_mon_package.ResMonPackage_Create.encrypt:1
TEST.EXPECTED:res_mon_package.ResMonPackage_Create.return:RM_OK
TEST.VALUE_USER_CODE:res_mon_package.ResMonPackage_Create.file
 char tmp_file[PACKAGE_PATH_MAX];
<<res_mon_package.ResMonPackage_Create.file>> = ( &tmp_file );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: 08_posix_spawn_snprintf_fail
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_Create
TEST.NEW
TEST.NAME:08_posix_spawn_snprintf_fail
TEST.VALUE:uut_prototype_stubs.posix_spawn.return:-1
TEST.EXPECTED:res_mon_package.ResMonPackage_Create.return:RM_FAILED
TEST.END

-- Test Case: 09_posix_spawn_snprintf_encrypt_fail
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_Create
TEST.NEW
TEST.NAME:09_posix_spawn_snprintf_encrypt_fail
TEST.VALUE:uut_prototype_stubs.posix_spawn.return:0,-1
TEST.VALUE:res_mon_package.ResMonPackage_Create.encrypt:1
TEST.EXPECTED:res_mon_package.ResMonPackage_Create.return:RM_FAILED
TEST.VALUE_USER_CODE:res_mon_package.ResMonPackage_Create.file
 char tmp_file[PACKAGE_PATH_MAX];
<<res_mon_package.ResMonPackage_Create.file>> = ( &tmp_file );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: ResMonPackage_CreatePackageWithDLTLogs

-- Test Case: clock_get_time_fail
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_CreatePackageWithDLTLogs
TEST.NEW
TEST.NAME:clock_get_time_fail
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:-1
TEST.EXPECTED:res_mon_package.ResMonPackage_CreatePackageWithDLTLogs.return:RM_FAILED
TEST.END

-- Test Case: posix_spawn_fail
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_CreatePackageWithDLTLogs
TEST.NEW
TEST.NAME:posix_spawn_fail
TEST.VALUE:uut_prototype_stubs.posix_spawn.return:-1
TEST.VALUE:uut_prototype_stubs.waitpid.return:-1
TEST.VALUE:res_mon_package.<<GLOBAL>>.slog2_handle:1
TEST.VALUE:res_mon_package.ResMonPackage_CreatePackageWithDLTLogs.return:0
TEST.EXPECTED:res_mon_package.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_package.ResMonPackage_CreatePackageWithDLTLogs.return:RM_FAILED
TEST.END

-- Test Case: posix_spawn_pass
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:ResMonPackage_CreatePackageWithDLTLogs
TEST.NEW
TEST.NAME:posix_spawn_pass
TEST.VALUE:uut_prototype_stubs.clock_gettime.return:0
TEST.VALUE:uut_prototype_stubs.posix_spawn.return:0
TEST.VALUE:uut_prototype_stubs.waitpid.return:-1
TEST.EXPECTED:res_mon_package.ResMonPackage_CreatePackageWithDLTLogs.return:RM_FAILED
TEST.END

-- Subprogram: alphasort

-- Test Case: alphasort_pass
TEST.UNIT:res_mon_package
TEST.SUBPROGRAM:alphasort
TEST.NEW
TEST.NAME:alphasort_pass
TEST.STUB:res_mon_package.ParseFileExtensionsInDirectory
TEST.VALUE:uut_prototype_stubs.strcoll.VCAST_PARAM_1[0]:'1'
TEST.VALUE:uut_prototype_stubs.strcoll.VCAST_PARAM_2[0]:'1'
TEST.VALUE:uut_prototype_stubs.strcoll.return:0
TEST.VALUE:res_mon_package.ParseFileExtensionsInDirectory.directory[0].d_name:<<malloc 2>>
TEST.VALUE:res_mon_package.ParseFileExtensionsInDirectory.directory[0].d_name:"1"
TEST.VALUE:res_mon_package.ParseFileExtensionsInDirectory.return:1
TEST.VALUE:res_mon_package.alphasort.a:<<malloc 1>>
TEST.VALUE:res_mon_package.alphasort.a[0]:<<malloc 1>>
TEST.VALUE:res_mon_package.alphasort.a[0][0].d_name:<<malloc 2>>
TEST.VALUE:res_mon_package.alphasort.a[0][0].d_name:"1"
TEST.VALUE:res_mon_package.alphasort.b:<<malloc 1>>
TEST.VALUE:res_mon_package.alphasort.b[0]:<<malloc 1>>
TEST.VALUE:res_mon_package.alphasort.b[0][0].d_name:<<malloc 2>>
TEST.VALUE:res_mon_package.alphasort.b[0][0].d_name:"1"
TEST.VALUE:res_mon_package.alphasort.return:-1
TEST.END

-- Unit: res_mon_procfs

-- Subprogram: ResMonProcFs_CpuInfo

-- Test Case: 01_open_fail
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_CpuInfo
TEST.NEW
TEST.NAME:01_open_fail
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.VALUE:uut_prototype_stubs.ClockTime_r.return:-1
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.VALUE:res_mon_procfs.<<GLOBAL>>._syspage_ptr:<<malloc 1>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>._syspage_ptr[0].num_cpu:-1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.END

-- Test Case: 02_clocktime_devctl_fail
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_CpuInfo
TEST.NEW
TEST.NAME:02_clocktime_devctl_fail
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.ClockTime_r.return:0
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>._syspage_ptr:<<malloc 1>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>._syspage_ptr[0].num_cpu:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.END

-- Test Case: 03_clocktime_devctl_pass
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_CpuInfo
TEST.NEW
TEST.NAME:03_clocktime_devctl_pass
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.VALUE:uut_prototype_stubs.ClockTime_r.__id:2
TEST.VALUE:uut_prototype_stubs.ClockTime_r.return:-1
TEST.VALUE:uut_prototype_stubs.devctl.return:0
TEST.VALUE:res_mon_procfs.<<GLOBAL>>._syspage_ptr:<<malloc 1>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>._syspage_ptr[0].num_cpu:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.END

-- Subprogram: ResMonProcFs_MemInfo

-- Test Case: 01_strncmp_stat_fail
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_MemInfo
TEST.NEW
TEST.NAME:01_strncmp_stat_fail
TEST.STUB:uut_prototype_stubs.strncmp
TEST.VALUE:uut_prototype_stubs.stat.return:-1
TEST.VALUE:uut_prototype_stubs.strncmp.return:-1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.stub_asinfo:<<malloc 1>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.stub_strings:<<null>>
TEST.FLOW
  res_mon_procfs.c.ResMonProcFs_MemInfo
  uut_prototype_stubs.strncmp
  uut_prototype_stubs.stat
  res_mon_procfs.c.ResMonProcFs_MemInfo
TEST.END_FLOW
TEST.END

-- Test Case: 02_strncmp_stat_pass
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_MemInfo
TEST.NEW
TEST.NAME:02_strncmp_stat_pass
TEST.STUB:uut_prototype_stubs.strncmp
TEST.VALUE:uut_prototype_stubs.slog2f.return:1
TEST.VALUE:uut_prototype_stubs.stat.return:0
TEST.VALUE:uut_prototype_stubs.strncmp.return:0
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.stub_asinfo:<<malloc 1>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.stub_asinfo[0].name:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.stub_strings:<<null>>
TEST.END

-- Subprogram: ResMonProcFs_ProcessInfo

-- Test Case: clock_get_time_return_fail
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_ProcessInfo
TEST.NEW
TEST.NAME:clock_get_time_return_fail
TEST.STUB:uut_prototype_stubs.read
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:-1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:<<malloc 3>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:"-1"
TEST.VALUE:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.END

-- Test Case: clocktime_r_true
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_ProcessInfo
TEST.NEW
TEST.NAME:clocktime_r_true
TEST.STUB:uut_prototype_stubs.read
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:-1
TEST.VALUE:uut_prototype_stubs.ClockTime_r.return:-1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:<<malloc 3>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:"-1"
TEST.VALUE:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.END

-- Test Case: membufs_01_0x4_true
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_ProcessInfo
TEST.NEW
TEST.NAME:membufs_01_0x4_true
TEST.STUB:uut_prototype_stubs.read
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:-1
TEST.VALUE:uut_prototype_stubs.ClockTime_r.return:-1
TEST.VALUE:uut_prototype_stubs.devctl.dev_info_ptr[0]:1
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:<<malloc 3>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:"-1"
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.membufs[0].flags:0x400
TEST.VALUE:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.END

-- Test Case: membufs_0x1_fail
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_ProcessInfo
TEST.NEW
TEST.NAME:membufs_0x1_fail
TEST.STUB:uut_prototype_stubs.read
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:-1
TEST.VALUE:uut_prototype_stubs.ClockTime_r.return:-1
TEST.VALUE:uut_prototype_stubs.devctl.dev_info_ptr[0]:1
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:<<malloc 3>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:"-1"
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.membufs[0].flags:0x10
TEST.VALUE:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.END

-- Test Case: membufs_0x1_true
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_ProcessInfo
TEST.NEW
TEST.NAME:membufs_0x1_true
TEST.STUB:uut_prototype_stubs.read
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:-1
TEST.VALUE:uut_prototype_stubs.ClockTime_r.return:-1
TEST.VALUE:uut_prototype_stubs.devctl.dev_info_ptr[0]:1
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:<<malloc 3>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:"-1"
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.membufs[0].flags:0x20100
TEST.VALUE:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.END

-- Test Case: membufs_0x3_true
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_ProcessInfo
TEST.NEW
TEST.NAME:membufs_0x3_true
TEST.STUB:uut_prototype_stubs.read
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:-1
TEST.VALUE:uut_prototype_stubs.ClockTime_r.return:-1
TEST.VALUE:uut_prototype_stubs.devctl.dev_info_ptr[0]:1
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:<<malloc 3>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:"-1"
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.membufs[0].flags:0x300
TEST.VALUE:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.END

-- Test Case: membufs_0x4_fail
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_ProcessInfo
TEST.NEW
TEST.NAME:membufs_0x4_fail
TEST.STUB:uut_prototype_stubs.read
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:-1
TEST.VALUE:uut_prototype_stubs.ClockTime_r.return:-1
TEST.VALUE:uut_prototype_stubs.devctl.dev_info_ptr[0]:1
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:<<malloc 3>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:"-1"
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.membufs[0].flags:0x203000
TEST.VALUE:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.END

-- Test Case: membufs_0x4_true
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_ProcessInfo
TEST.NEW
TEST.NAME:membufs_0x4_true
TEST.STUB:uut_prototype_stubs.read
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:-1
TEST.VALUE:uut_prototype_stubs.ClockTime_r.return:-1
TEST.VALUE:uut_prototype_stubs.devctl.dev_info_ptr[0]:1
TEST.VALUE:uut_prototype_stubs.devctl.return:-1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:<<malloc 3>>
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.cmdline:"-1"
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.membufs[0].flags:0x401000
TEST.VALUE:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.ResMonProcFs_ProcessInfo.pid:1
TEST.END

-- Test Case: proc_as_cmd_open_fd_fail
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_ProcessInfo
TEST.NEW
TEST.NAME:proc_as_cmd_open_fd_fail
TEST.VALUE:debug.<<GLOBAL>>.slog2_handle:-1
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.END

-- Test Case: size_fail
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcFs_ProcessInfo
TEST.NEW
TEST.NAME:size_fail
TEST.STUB:uut_prototype_stubs.read
TEST.VALUE:uut_prototype_stubs.open.return:1
TEST.VALUE:uut_prototype_stubs.read.return:1
TEST.VALUE:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.EXPECTED:res_mon_procfs.<<GLOBAL>>.slog2_handle:1
TEST.END

-- Subprogram: ResMonProcfs_Log

-- Test Case: 01_opendir_fail
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcfs_Log
TEST.NEW
TEST.NAME:01_opendir_fail
TEST.STUB:res_mon_procfs.ResMonProcFs_CpuInfo
TEST.STUB:res_mon_procfs.ResMonProcFs_MemInfo
TEST.FLOW
  res_mon_procfs.c.ResMonProcfs_Log
  res_mon_procfs.c.ResMonProcFs_CpuInfo
  res_mon_procfs.c.ResMonProcFs_MemInfo
  uut_prototype_stubs.opendir
  uut_prototype_stubs.slog2f
  res_mon_procfs.c.ResMonProcfs_Log
TEST.END_FLOW
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = ( NULL );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 02_readdir_non_digit
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcfs_Log
TEST.NEW
TEST.NAME:02_readdir_non_digit
TEST.STUB:res_mon_procfs.ResMonProcFs_CpuInfo
TEST.STUB:res_mon_procfs.ResMonProcFs_MemInfo
TEST.FLOW
  res_mon_procfs.c.ResMonProcfs_Log
  res_mon_procfs.c.ResMonProcFs_CpuInfo
  res_mon_procfs.c.ResMonProcFs_MemInfo
  uut_prototype_stubs.opendir
  uut_prototype_stubs.readdir
  uut_prototype_stubs.readdir
  uut_prototype_stubs.closedir
  res_mon_procfs.c.ResMonProcfs_Log
TEST.END_FLOW
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.opendir.return
<<uut_prototype_stubs.opendir.return>> = (DIR *)1;
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.readdir.return
static struct dirent test_dir1;
test_dir1.d_name[0] = 'A';

static int cnt = 0;

if (cnt == 0)
{
  cnt = 1;
  <<uut_prototype_stubs.readdir.return>> = ( &test_dir1 );
}
else
{
  <<uut_prototype_stubs.readdir.return>> = NULL;
}

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 03_readdir_digit_valid
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcfs_Log
TEST.NEW
TEST.NAME:03_readdir_digit_valid
TEST.STUB:res_mon_procfs.ResMonProcFs_CpuInfo
TEST.STUB:res_mon_procfs.ResMonProcFs_MemInfo
TEST.STUB:res_mon_procfs.ResMonProcFs_ProcessInfo
TEST.FLOW
  res_mon_procfs.c.ResMonProcfs_Log
  res_mon_procfs.c.ResMonProcFs_CpuInfo
  res_mon_procfs.c.ResMonProcFs_MemInfo
  uut_prototype_stubs.opendir
  uut_prototype_stubs.readdir
  res_mon_procfs.c.ResMonProcFs_ProcessInfo
  uut_prototype_stubs.readdir
  uut_prototype_stubs.closedir
  res_mon_procfs.c.ResMonProcfs_Log
TEST.END_FLOW
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
  <<uut_prototype_stubs.readdir.return>> = ( &test_dir1 );
}
else
{
  <<uut_prototype_stubs.readdir.return>> = NULL;
}

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 04_readdir_digit_INT_MIN
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcfs_Log
TEST.NEW
TEST.NAME:04_readdir_digit_INT_MIN
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:res_mon_procfs.ResMonProcFs_CpuInfo
TEST.STUB:res_mon_procfs.ResMonProcFs_MemInfo
TEST.STUB:res_mon_procfs.ResMonProcFs_ProcessInfo
TEST.VALUE:uut_prototype_stubs.strtol.return:-2147483648
TEST.FLOW
  res_mon_procfs.c.ResMonProcfs_Log
  res_mon_procfs.c.ResMonProcFs_CpuInfo
  res_mon_procfs.c.ResMonProcFs_MemInfo
  uut_prototype_stubs.opendir
  uut_prototype_stubs.readdir
  uut_prototype_stubs.strtol
  uut_prototype_stubs.readdir
  uut_prototype_stubs.closedir
  res_mon_procfs.c.ResMonProcfs_Log
TEST.END_FLOW
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
  <<uut_prototype_stubs.readdir.return>> = ( &test_dir1 );
}
else
{
  <<uut_prototype_stubs.readdir.return>> = NULL;
}

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: 05_readdir_digit_INT_MAX
TEST.UNIT:res_mon_procfs
TEST.SUBPROGRAM:ResMonProcfs_Log
TEST.NEW
TEST.NAME:05_readdir_digit_INT_MAX
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:res_mon_procfs.ResMonProcFs_CpuInfo
TEST.STUB:res_mon_procfs.ResMonProcFs_MemInfo
TEST.STUB:res_mon_procfs.ResMonProcFs_ProcessInfo
TEST.VALUE:uut_prototype_stubs.strtol.return:2147483647
TEST.FLOW
  res_mon_procfs.c.ResMonProcfs_Log
  res_mon_procfs.c.ResMonProcFs_CpuInfo
  res_mon_procfs.c.ResMonProcFs_MemInfo
  uut_prototype_stubs.opendir
  uut_prototype_stubs.readdir
  uut_prototype_stubs.strtol
  uut_prototype_stubs.readdir
  uut_prototype_stubs.closedir
  res_mon_procfs.c.ResMonProcfs_Log
TEST.END_FLOW
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
  <<uut_prototype_stubs.readdir.return>> = ( &test_dir1 );
}
else
{
  <<uut_prototype_stubs.readdir.return>> = NULL;
}

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Unit: res_mon_qcom

-- Subprogram: ResMonQcom_EnableGPUBusyStats

-- Test Case: ResMonQcom_EnableGPUBusyStats.001
TEST.UNIT:res_mon_qcom
TEST.SUBPROGRAM:ResMonQcom_EnableGPUBusyStats
TEST.NEW
TEST.NAME:ResMonQcom_EnableGPUBusyStats.001
TEST.VALUE:uut_prototype_stubs.open.return:-1
TEST.END

-- Test Case: ResMonQcom_EnableGPUBusyStats.002
TEST.UNIT:res_mon_qcom
TEST.SUBPROGRAM:ResMonQcom_EnableGPUBusyStats
TEST.NEW
TEST.NAME:ResMonQcom_EnableGPUBusyStats.002
TEST.VALUE:uut_prototype_stubs.open.return:0
TEST.END
