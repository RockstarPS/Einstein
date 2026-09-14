-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : QTD_SEC_MNT
-- Unit(s) Under Test: main
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

-- Test Case: VCAST_main_get_parse_conf_nok
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_get_parse_conf_nok
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.STUB:main.parse_config
TEST.VALUE:main.<<GLOBAL>>.optarg:<<malloc 14>>
TEST.VALUE:main.<<GLOBAL>>.optarg:"/path/to/file"
TEST.VALUE:main.parse_config.return:ENOENT
TEST.EXPECTED:main.VCAST_main.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.getopt.return
static unsigned char flg = 0;
if(flg == 0)
{	
	<<uut_prototype_stubs.getopt.return>> = ( 'c' );
	flg = 1;
}
else if(flg == 1)
{
	<<uut_prototype_stubs.getopt.return>> = 'd';
	flg = 2;
}
else
{
	<<uut_prototype_stubs.getopt.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: VCAST_main_get_part_info_nok
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_get_part_info_nok
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.STUB:main.parse_config
TEST.VALUE:main.<<GLOBAL>>.optarg:<<malloc 14>>
TEST.VALUE:main.<<GLOBAL>>.optarg:"/path/to/file"
TEST.VALUE:main.parse_config.return:EOK
TEST.EXPECTED:main.VCAST_main.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.getopt.return
static unsigned char flg = 0;
if(flg == 0)
{	
	<<uut_prototype_stubs.getopt.return>> = ( 'c' );
	flg = 1;
}
else if(flg == 1)
{
	<<uut_prototype_stubs.getopt.return>> = 'd';
	flg = 2;
}
else
{
	<<uut_prototype_stubs.getopt.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: VCAST_main_slog_reg_nok
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_slog_reg_nok
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.STUB:main.parse_config
TEST.VALUE:main.parse_config.return:EOK
TEST.EXPECTED:main.VCAST_main.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.getopt.return
static unsigned char flg = 0;
if(flg == 0)
{	
	<<uut_prototype_stubs.getopt.return>> = ( 'c' );
	flg = 1;
}
else if(flg == 1)
{
	<<uut_prototype_stubs.getopt.return>> = 'd';
	flg = 2;
}
else
{
	<<uut_prototype_stubs.getopt.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: VCAST_main_slog_reg_ok
TEST.UNIT:main
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_slog_reg_ok
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.STUB:main.parse_config
TEST.VALUE:main.parse_config.return:EOK
TEST.EXPECTED:main.VCAST_main.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.getopt.return
static unsigned char flg = 0;
if(flg == 0)
{	
	<<uut_prototype_stubs.getopt.return>> = ( 'c' );
	flg = 1;
}
else if(flg == 1)
{
	<<uut_prototype_stubs.getopt.return>> = 'd';
	flg = 2;
}
else
{
	<<uut_prototype_stubs.getopt.return>> = -1;
}
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: mount_fs

-- Test Case: mount_fs_error_2
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_error_2
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.devPr:<<malloc 5>>
TEST.VALUE:main.mount_fs.devPr:"test"
TEST.VALUE:main.mount_fs.fs_type:<<malloc 3>>
TEST.VALUE:main.mount_fs.fs_type:"ok"
TEST.VALUE:main.mount_fs.mnt:<<malloc 6>>
TEST.VALUE:main.mount_fs.mnt:"/path"
TEST.VALUE:uut_prototype_stubs.mount.return:-1
TEST.EXPECTED:main.mount_fs.return:-1
TEST.END

-- Test Case: mount_fs_error_3
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_error_3
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.devPr:<<malloc 5>>
TEST.VALUE:main.mount_fs.devPr:"test"
TEST.VALUE:main.mount_fs.fs_type:<<malloc 5>>
TEST.VALUE:main.mount_fs.fs_type:"test"
TEST.VALUE:uut_prototype_stubs.mount.return:-1
TEST.EXPECTED:main.mount_fs.return:-1
TEST.VALUE_USER_CODE:main.mount_fs.mnt
<<main.mount_fs.mnt>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: mount_fs_ok
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_ok
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.STUB:main.VCAST_main
TEST.VALUE:main.mount_fs.devPr:<<malloc 5>>
TEST.VALUE:main.mount_fs.devPr:"test"
TEST.VALUE:main.mount_fs.fs_type:<<malloc 3>>
TEST.VALUE:main.mount_fs.fs_type:"ok"
TEST.VALUE:main.mount_fs.mnt:<<malloc 6>>
TEST.VALUE:main.mount_fs.mnt:"/path"
TEST.VALUE:main.mount_fs.option:<<malloc 3>>
TEST.VALUE:main.mount_fs.option:"ro"
TEST.VALUE:main.VCAST_main.return:0
TEST.VALUE:uut_prototype_stubs.mount.return:1
TEST.END

-- Test Case: mount_fs_ok.001
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_ok.001
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.devPr:<<malloc 5>>
TEST.VALUE:main.mount_fs.devPr:"test"
TEST.VALUE:main.mount_fs.mnt:<<malloc 6>>
TEST.VALUE:main.mount_fs.mnt:"/path"
TEST.VALUE:uut_prototype_stubs.mount.return:1
TEST.EXPECTED:main.mount_fs.return:-1
TEST.END

-- Test Case: mount_fs_ok.002
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_ok.002
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.fs_type:<<malloc 3>>
TEST.VALUE:main.mount_fs.fs_type:"ok"
TEST.VALUE:uut_prototype_stubs.mount.return:1
TEST.EXPECTED:main.mount_fs.return:-1
TEST.END

-- Test Case: mount_fs_ok.003
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_ok.003
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.fs_type:<<malloc 3>>
TEST.VALUE:main.mount_fs.fs_type:"ok"
TEST.VALUE:main.mount_fs.mnt:<<malloc 6>>
TEST.VALUE:main.mount_fs.mnt:"/path"
TEST.VALUE:uut_prototype_stubs.mount.return:-1
TEST.EXPECTED:main.mount_fs.return:-1
TEST.END

-- Test Case: mount_fs_ok_mount_err
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_ok_mount_err
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.fs_type:<<malloc 3>>
TEST.VALUE:main.mount_fs.fs_type:"ok"
TEST.VALUE:main.mount_fs.mnt:<<malloc 6>>
TEST.VALUE:main.mount_fs.mnt:"/path"
TEST.VALUE:uut_prototype_stubs.mount.return:-2
TEST.EXPECTED:main.mount_fs.return:-1
TEST.END

-- Test Case: mount_fs_parm0_null
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_parm0_null
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.fs_type:<<malloc 4>>
TEST.VALUE:main.mount_fs.fs_type:"FAT"
TEST.VALUE:main.mount_fs.mnt:<<malloc 6>>
TEST.VALUE:main.mount_fs.mnt:"/path"
TEST.EXPECTED:main.mount_fs.return:-1
TEST.END

-- Test Case: mount_fs_parm1_null
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_parm1_null
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.mnt:<<malloc 6>>
TEST.VALUE:main.mount_fs.mnt:"/path"
TEST.EXPECTED:main.mount_fs.return:-1
TEST.VALUE_USER_CODE:main.mount_fs.fs_type
<<main.mount_fs.fs_type>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: mount_fs_parm2_null
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_parm2_null
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.fs_type:<<malloc 3>>
TEST.VALUE:main.mount_fs.fs_type:"ok"
TEST.EXPECTED:main.mount_fs.return:-1
TEST.VALUE_USER_CODE:main.mount_fs.mnt
<<main.mount_fs.mnt>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: mount_fs_parm2_null.001
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_parm2_null.001
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.fs_type:<<malloc 3>>
TEST.VALUE:main.mount_fs.fs_type:"ok"
TEST.VALUE:main.mount_fs.option:<<malloc 3>>
TEST.VALUE:main.mount_fs.option:"ro"
TEST.EXPECTED:main.mount_fs.return:-1
TEST.VALUE_USER_CODE:main.mount_fs.mnt
<<main.mount_fs.mnt>> = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: mount_fs_strncmp_failure
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_strncmp_failure
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.devPr:<<malloc 5>>
TEST.VALUE:main.mount_fs.devPr:"test"
TEST.VALUE:main.mount_fs.fs_type:<<malloc 3>>
TEST.VALUE:main.mount_fs.fs_type:"ok"
TEST.VALUE:main.mount_fs.mnt:<<malloc 6>>
TEST.VALUE:main.mount_fs.mnt:"/path"
TEST.VALUE:main.mount_fs.option:<<malloc 3>>
TEST.VALUE:main.mount_fs.option:"ro"
TEST.VALUE:uut_prototype_stubs.mount.return:1
TEST.END

-- Test Case: mount_fs_strncmp_pass
TEST.UNIT:main
TEST.SUBPROGRAM:mount_fs
TEST.NEW
TEST.NAME:mount_fs_strncmp_pass
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.VALUE:main.mount_fs.devPr:<<malloc 5>>
TEST.VALUE:main.mount_fs.devPr:"test"
TEST.VALUE:main.mount_fs.fs_type:<<malloc 3>>
TEST.VALUE:main.mount_fs.fs_type:"ok"
TEST.VALUE:main.mount_fs.mnt:<<malloc 6>>
TEST.VALUE:main.mount_fs.mnt:"/path"
TEST.VALUE:main.mount_fs.option:<<malloc 5>>
TEST.VALUE:main.mount_fs.option:"rofs"
TEST.VALUE:uut_prototype_stubs.mount.return:1
TEST.EXPECTED:main.mount_fs.return:1
TEST.END

-- Subprogram: parse_config

-- Test Case: parse_config.001
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config.001
TEST.END

-- Test Case: parse_config.002
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config.002
TEST.STUB:main.mount_fs
TEST.VALUE:main.mount_fs.return:-1
TEST.VALUE:main.parse_config.return:22
TEST.END

-- Test Case: parse_config_chk_mnt_condition_nok
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_chk_mnt_condition_nok
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.STUB:main.mount_fs
TEST.VALUE:main.mount_fs.return:22
TEST.VALUE:main.parse_config.return:22
TEST.END

-- Test Case: parse_config_chk_mnt_condition_nok.001
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_chk_mnt_condition_nok.001
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.STUB:main.mount_fs
TEST.VALUE:main.mount_fs.return:22
TEST.VALUE:main.parse_config.return:22
TEST.END

-- Test Case: parse_config_chk_push_ok_error
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_chk_push_ok_error
TEST.STUB:main.mount_fs
TEST.VALUE:main.mount_fs.return:22
TEST.VALUE:main.parse_config.return:22
TEST.END

-- Test Case: parse_config_dec_error
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_dec_error
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.EXPECTED:main.parse_config.return:-1
TEST.END

-- Test Case: parse_config_get_int_not_found_1
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_get_int_not_found_1
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.STUB:main.mount_fs
TEST.VALUE:main.mount_fs.return:-1
TEST.END

-- Test Case: parse_config_get_string_ok_1
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_get_string_ok_1
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.EXPECTED:main.parse_config.return:-1
TEST.END

-- Test Case: parse_config_get_string_ok_2
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_get_string_ok_2
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.EXPECTED:main.parse_config.return:-1
TEST.END

-- Test Case: parse_config_json_object_from_file_ok
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_json_object_from_file_ok
TEST.STUB:main.mount_fs
TEST.VALUE:main.mount_fs.return:22
TEST.VALUE:main.parse_config.return:22
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.json_object_from_file.return
<<uut_prototype_stubs.json_object_from_file.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: parse_config_json_object_from_file_ok.001
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_json_object_from_file_ok.001
TEST.STUB:main.mount_fs
TEST.VALUE:main.mount_fs.return:22
TEST.VALUE:main.parse_config.return:22
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.json_object_from_file.return
<<uut_prototype_stubs.json_object_from_file.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: parse_config_json_object_from_file_ok_strncmp_fail_strncmp_succ
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_json_object_from_file_ok_strncmp_fail_strncmp_succ
TEST.STUB:main.mount_fs
TEST.STUB:main.VCAST_main
TEST.STUB:uut_prototype_stubs.strncmp
TEST.VALUE:main.mount_fs.return:22
TEST.VALUE:main.parse_config.return:22
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.json_object_from_file.return
<<uut_prototype_stubs.json_object_from_file.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: parse_config_json_object_from_file_ok_strncmp_failure
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_json_object_from_file_ok_strncmp_failure
TEST.STUB:main.mount_fs
TEST.STUB:uut_prototype_stubs.strncmp
TEST.VALUE:main.mount_fs.return:22
TEST.VALUE:main.parse_config.return:22
TEST.VALUE:uut_prototype_stubs.strncmp.return:-1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.json_object_from_file.return
<<uut_prototype_stubs.json_object_from_file.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: parse_config_json_object_from_file_ok_strncmp_success
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_json_object_from_file_ok_strncmp_success
TEST.STUB:main.mount_fs
TEST.STUB:uut_prototype_stubs.strncmp
TEST.VALUE:main.mount_fs.return:22
TEST.VALUE:main.parse_config.return:22
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strncmp.VCAST_PARAM_1
<<uut_prototype_stubs.strncmp.VCAST_PARAM_1>> = ( "fs_type" );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strncmp.VCAST_PARAM_2
<<uut_prototype_stubs.strncmp.VCAST_PARAM_2>> = ( "fs_type" );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.json_object_from_file.return
<<uut_prototype_stubs.json_object_from_file.return>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: parse_config_parse_error
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_parse_error
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.EXPECTED:main.parse_config.return:-1
TEST.END

-- Test Case: parse_config_posix_spawn
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_posix_spawn
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.EXPECTED:main.parse_config.return:-1
TEST.END

-- Test Case: parse_config_posix_spawn_1
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_posix_spawn_1
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.EXPECTED:main.parse_config.return:-1
TEST.END

-- Test Case: parse_config_posix_spawn_2
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_posix_spawn_2
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.EXPECTED:main.parse_config.return:-1
TEST.END

-- Test Case: parse_config_push_error
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_push_error
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.EXPECTED:main.parse_config.return:-1
TEST.END

-- Test Case: parse_config_push_ok
TEST.UNIT:main
TEST.SUBPROGRAM:parse_config
TEST.NEW
TEST.NAME:parse_config_push_ok
TEST.NOTES:
Requirement_AU29610-144619
TEST.END_NOTES:
TEST.EXPECTED:main.parse_config.return:-1
TEST.END
