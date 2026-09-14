-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : SIGUNIT_RM_UT
-- Unit(s) Under Test: CSigUnit_HwIf CSigUnit_HwInit CSigUnit_RM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CSigUnit_HwIf

-- Subprogram: sigunit_eval_win_setup

-- Test Case: sigunit_eval_win_setup_invalidwinidfail1
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_eval_win_setup
TEST.NEW
TEST.NAME:sigunit_eval_win_setup_invalidwinidfail1
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_setup.p_SigUnitWinCfg_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_setup.p_SigUnitWinCfg_SP[0].eval_win_id_U8:9
TEST.EXPECTED:CSigUnit_HwIf.sigunit_eval_win_setup.return:-1
TEST.END

-- Test Case: sigunit_eval_win_setup_validwinidsuccess1
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_eval_win_setup
TEST.NEW
TEST.NAME:sigunit_eval_win_setup_validwinidsuccess1
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_setup.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_setup.p_SigUnitWinCfg_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_setup.p_SigUnitWinCfg_SP[0].eval_win_id_U8:0
TEST.EXPECTED:CSigUnit_HwIf.<<GLOBAL>>.evalwin_flag[0].flag_evalwin_BOOL:true
TEST.END

-- Subprogram: sigunit_eval_win_start

-- Test Case: sigunit_eval_win_start.invalidwinidfail1
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_eval_win_start
TEST.NEW
TEST.NAME:sigunit_eval_win_start.invalidwinidfail1
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.pDev[0].devnum_U8:3
TEST.EXPECTED:CSigUnit_HwIf.sigunit_eval_win_start.return:-1
TEST.END

-- Test Case: sigunit_eval_win_start.validwinidsuccess1
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_eval_win_start
TEST.NEW
TEST.NAME:sigunit_eval_win_start.validwinidsuccess1
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.<<GLOBAL>>.evalwin_flag[1].flag_evalwin_BOOL:true
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.pDev[0].devnum_U8:1
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.eval_win_id_U8:1
TEST.EXPECTED:CSigUnit_HwIf.sigunit_eval_win_start.return:0
TEST.END

-- Test Case: sigunit_eval_win_start.winnotsetupfail2
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_eval_win_start
TEST.NEW
TEST.NAME:sigunit_eval_win_start.winnotsetupfail2
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.<<GLOBAL>>.evalwin_flag[1].flag_evalwin_BOOL:false
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.pDev[0].devnum_U8:1
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.eval_win_id_U8:9
TEST.EXPECTED:CSigUnit_HwIf.sigunit_eval_win_start.return:-1
TEST.END

-- Test Case: sigunit_eval_win_start.winsetupsuccess2
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_eval_win_start
TEST.NEW
TEST.NAME:sigunit_eval_win_start.winsetupsuccess2
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.<<GLOBAL>>.evalwin_flag[1].flag_evalwin_BOOL:true
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.pDev[0].devnum_U8:1
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.eval_win_id_U8:0xFF
TEST.EXPECTED:CSigUnit_HwIf.sigunit_eval_win_start.return:0
TEST.END

-- Subprogram: sigunit_eval_win_status

-- Test Case: sigunit_eval_win_status_validwinidsuccess1
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_eval_win_status
TEST.NEW
TEST.NAME:sigunit_eval_win_status_validwinidsuccess1
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.<<GLOBAL>>.evalwin_flag[1].flag_contmode_on_flag_BOOL:true
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.p_SigUnitWinStatus_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.p_SigUnitWinStatus_SP[0].eval_win_id:1
TEST.EXPECTED:CSigUnit_HwIf.sigunit_eval_win_status.return:0
TEST.END

-- Test Case: sigunit_eval_win_status_wincontmodeenablesuccess2
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_eval_win_status
TEST.NEW
TEST.NAME:sigunit_eval_win_status_wincontmodeenablesuccess2
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.<<GLOBAL>>.evalwin_flag[1].flag_contmode_on_flag_BOOL:true
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.p_SigUnitWinStatus_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.p_SigUnitWinStatus_SP[0].eval_win_id:1
TEST.EXPECTED:CSigUnit_HwIf.sigunit_eval_win_status.return:0
TEST.END

-- Test Case: sigunit_eval_win_status_wincontmodeenablesuccess2.001
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_eval_win_status
TEST.NEW
TEST.NAME:sigunit_eval_win_status_wincontmodeenablesuccess2.001
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.<<GLOBAL>>.evalwin_flag[1].flag_contmode_on_flag_BOOL:false
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.p_SigUnitWinStatus_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.p_SigUnitWinStatus_SP[0].eval_win_id:9
TEST.EXPECTED:CSigUnit_HwIf.sigunit_eval_win_status.return:-1
TEST.END

-- Subprogram: sigunit_eval_win_stop

-- Test Case: sigunit_eval_win_stop_validwinidsuccess1
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_eval_win_stop
TEST.NEW
TEST.NAME:sigunit_eval_win_stop_validwinidsuccess1
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.<<GLOBAL>>.evalwin_flag[1].flag_contmode_on_flag_BOOL:true
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_stop.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_stop.eval_win_id_U8:1
TEST.EXPECTED:CSigUnit_HwIf.sigunit_eval_win_stop.return:0
TEST.END

-- Test Case: sigunit_eval_win_stopinvalidwinidfail1
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_eval_win_stop
TEST.NEW
TEST.NAME:sigunit_eval_win_stopinvalidwinidfail1
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_stop.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_stop.eval_win_id_U8:0x9
TEST.EXPECTED:CSigUnit_HwIf.sigunit_eval_win_stop.return:-1
TEST.END

-- Subprogram: sigunit_get_win_crc_r

-- Test Case: sigunit_get_win_crc_r.success
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_get_win_crc_r
TEST.NEW
TEST.NAME:sigunit_get_win_crc_r.success
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.sigunit_get_win_crc_r.pDev:<<malloc 1>>
TEST.EXPECTED:CSigUnit_HwIf.sigunit_get_win_crc_r.return:0
TEST.END

-- Subprogram: sigunit_initialize

-- Test Case: sigunit_initialize_invalidsigunitidfail1
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_initialize
TEST.NEW
TEST.NAME:sigunit_initialize_invalidsigunitidfail1
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.pDev[0].devnum_U8:4
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].error_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].reset_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].panic_rgba_U32:128
TEST.EXPECTED:CSigUnit_HwIf.sigunit_initialize.return:-1
TEST.END

-- Test Case: sigunit_initialize_validsigunitidsuccess1
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_initialize
TEST.NEW
TEST.NAME:sigunit_initialize_validsigunitidsuccess1
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].error_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].reset_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].panic_rgba_U32:128
TEST.EXPECTED:CSigUnit_HwIf.sigunit_initialize.return:0
TEST.END

-- Test Case: sigunit_initialize_validsigunitidsuccess1.001
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_initialize
TEST.NEW
TEST.NAME:sigunit_initialize_validsigunitidsuccess1.001
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].error_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].reset_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].panic_rgba_U32:0
TEST.EXPECTED:CSigUnit_HwIf.sigunit_initialize.return:0
TEST.END

-- Subprogram: sigunit_shutdown

-- Test Case: sigunit_shutdown_flag_bool
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_shutdown
TEST.NEW
TEST.NAME:sigunit_shutdown_flag_bool
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.<<GLOBAL>>.sigunit_flag[1].flag_sigunit_BOOL:true
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev[0].devnum_U8:4
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.return:-1
TEST.EXPECTED:CSigUnit_HwIf.<<GLOBAL>>.sigunit_flag[1].flag_sigunit_BOOL:true
TEST.EXPECTED:CSigUnit_HwIf.sigunit_shutdown.return:-1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_shutdown_flag_bool.001
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_shutdown
TEST.NEW
TEST.NAME:sigunit_shutdown_flag_bool.001
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_get_port32
TEST.VALUE:CSigUnit_HwIf.<<GLOBAL>>.sigunit_flag[1].flag_sigunit_BOOL:false
TEST.VALUE:CSigUnit_HwIf.sigunit_get_port32.return:0x100000
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev[0].devnum_U8:1
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev[0].regbase:22
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.return:-1
TEST.EXPECTED:CSigUnit_HwIf.<<GLOBAL>>.sigunit_flag[1].flag_sigunit_BOOL:false
TEST.EXPECTED:CSigUnit_HwIf.sigunit_shutdown.return:-1
TEST.END

-- Test Case: sigunit_shutdown_pdev_fail
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_shutdown
TEST.NEW
TEST.NAME:sigunit_shutdown_pdev_fail
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev[0].devnum_U8:3
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.return:-1
TEST.EXPECTED:CSigUnit_HwIf.sigunit_shutdown.return:-1
TEST.END

-- Test Case: sigunit_shutdown_pdev_true
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_shutdown
TEST.NEW
TEST.NAME:sigunit_shutdown_pdev_true
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwIf.<<GLOBAL>>.sigunit_flag[1].flag_sigunit_BOOL:true
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev[0].devnum_U8:1
TEST.EXPECTED:CSigUnit_HwIf.<<GLOBAL>>.sigunit_flag[1].flag_sigunit_BOOL:true
TEST.END

-- Test Case: sigunit_shutdown_pdev_true.001
TEST.UNIT:CSigUnit_HwIf
TEST.SUBPROGRAM:sigunit_shutdown
TEST.NEW
TEST.NAME:sigunit_shutdown_pdev_true.001
TEST.NOTES:
Requirement_AU29610-143724
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_get_port32
TEST.VALUE:CSigUnit_HwIf.<<GLOBAL>>.sigunit_flag[1].flag_sigunit_BOOL:true
TEST.VALUE:CSigUnit_HwIf.sigunit_get_port32.return:0x100000
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev:<<malloc 1>>
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev[0].devnum_U8:1
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.pDev[0].regbase:1
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.return:0
TEST.EXPECTED:CSigUnit_HwIf.sigunit_shutdown.return:0
TEST.END

-- Unit: CSigUnit_HwInit

-- Subprogram: sigunit_hw_fini

-- Test Case: sigunit_hw_fini_unmapfail1
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_fini
TEST.NEW
TEST.NAME:sigunit_hw_fini_unmapfail1
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.munmap_device_io.return:-1
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.p_sighwfini_SP:<<malloc 1>>
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_fini.return:false
TEST.END

-- Test Case: sigunit_hw_fini_unmapsuccess1
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_fini
TEST.NEW
TEST.NAME:sigunit_hw_fini_unmapsuccess1
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.munmap_device_io.return:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.p_sighwfini_SP:<<malloc 1>>
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_fini.return:true
TEST.END

-- Subprogram: sigunit_hw_init

-- Test Case: sigunit_hw_init_invalidsigunitfail3
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_invalidsigunitfail3
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:3
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.END

-- Test Case: sigunit_hw_init_invalidsigunitfail3.001
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_invalidsigunitfail3.001
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x8C
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:2
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_hw_init_invalidsigunitfail3.002
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_invalidsigunitfail3.002
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:4
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.END

-- Test Case: sigunit_hw_init_invalidsigunitfail3.003
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_invalidsigunitfail3.003
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:22
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:2
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.END

-- Test Case: sigunit_hw_init_sig0_EINVAL_mmapfail1
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig0_EINVAL_mmapfail1
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x140
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__io:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:0
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = EINVAL; 
{{ errno == EINVAL }}

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig0_ENOMEM_mmapfail2
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig0_ENOMEM_mmapfail2
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x140
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__io:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:0
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENOMEM;
{{ errno == ENOMEM }}

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig0_ENXIO_mmapfail3
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig0_ENXIO_mmapfail3
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x140
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__io:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:0
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENXIO;
{{ errno == ENXIO }}

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig0_mmapfail1
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig0_mmapfail1
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x140
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__io:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:0
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = EINVAL; 
{{ errno == EINVAL }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig0_mmapsuccess1
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig0_mmapsuccess1
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:4
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:0
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.END

-- Test Case: sigunit_hw_init_sig1_ENOMEM_mmapfail2
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig1_ENOMEM_mmapfail2
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x8C
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:1
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENOMEM; 
{{ errno == ENOMEM }}

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig1_ENXIO_mmapfail3
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig1_ENXIO_mmapfail3
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x8C
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:1
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENXIO; 
{{ errno == ENXIO }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig1_mmapfail2
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig1_mmapfail2
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:140
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:1
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = EINVAL; 
{{ errno == EINVAL }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig1_mmapsuccess2
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig1_mmapsuccess2
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:4
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:1
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.END

-- Test Case: sigunit_hw_init_sig2_EINVAL_mmapfail1
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig2_EINVAL_mmapfail1
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x8C
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:2
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = EINVAL; 
{{ errno == EINVAL }}

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig2_ENOMEM_mmapfail2.001
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig2_ENOMEM_mmapfail2.001
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x8C
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:2
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENOMEM; 
{{ errno == ENOMEM }}

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig2_ENXIO_mmapfail3.001
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig2_ENXIO_mmapfail3.001
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x8C
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:2
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENXIO; 
{{ errno == ENXIO }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig3_EINVAL_mmapfail1.001
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig3_EINVAL_mmapfail1.001
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x8C
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:3
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = EINVAL; 
{{ errno == EINVAL }}

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig3_ENOMEM_mmapfail2.002
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig3_ENOMEM_mmapfail2.002
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x8C
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:3
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENOMEM; 
{{ errno == ENOMEM }}

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: sigunit_hw_init_sig3_ENXIO_mmapfail3.002
TEST.UNIT:CSigUnit_HwInit
TEST.SUBPROGRAM:sigunit_hw_init
TEST.NEW
TEST.NAME:sigunit_hw_init_sig3_ENXIO_mmapfail3.002
TEST.NOTES:
Requirement_AU29610-143725
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.mmap_device_io.__len:0x8C
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:3
TEST.EXPECTED:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.VALUE_USER_CODE:<<testcase>>
errno = ENXIO; 
{{ errno == ENXIO }}
TEST.END_VALUE_USER_CODE:
TEST.END

-- Unit: CSigUnit_RM

-- Subprogram: VCAST_main

-- Test Case: VCAST_main.dispatch_block_EINTR_fail11
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.dispatch_block_EINTR_fail11
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.STUB:CSigUnit_RM.sigunit_init
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return[0].resmgr_context.dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].ctp_UP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.return:0
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:0
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.VALUE_USER_CODE:<<testcase>>
errno = EINTR;
{{ errno == EINTR }}

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: VCAST_main.dispatch_block_fail3
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.dispatch_block_fail3
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.STUB:CSigUnit_RM.sigunit_init
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return[0].resmgr_context.dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].ctp_UP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.return:0
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: VCAST_main.loggingfail1
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.loggingfail1
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_Debug.sigunit_enable_logging
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:CSigUnit_Debug.sigunit_enable_logging.return:1
TEST.VALUE:CSigUnit_RM.VCAST_main.argc:1
TEST.VALUE:CSigUnit_RM.VCAST_main.argv:<<malloc 1>>
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: VCAST_main.sigunithwinitfail2
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main.sigunithwinitfail2
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:false
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: VCAST_main_dispatch_handler_fail4
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_dispatch_handler_fail4
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.STUB:CSigUnit_HwInit.sigunit_hw_fini
TEST.STUB:CSigUnit_Debug.sigunit_enable_logging
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:1
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.return:true
TEST.VALUE:CSigUnit_Debug.sigunit_enable_logging.return:0
TEST.VALUE:CSigUnit_RM.VCAST_main.argc:2
TEST.VALUE:CSigUnit_RM.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:<<malloc 5>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:"main"
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:<<malloc 4>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:"-u0"
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: VCAST_main_invalid_device_option_fail5
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_invalid_device_option_fail5
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.STUB:CSigUnit_HwInit.sigunit_hw_fini
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:1
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.return:true
TEST.VALUE:CSigUnit_RM.VCAST_main.argc:2
TEST.VALUE:CSigUnit_RM.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:<<malloc 5>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:"main"
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:<<malloc 4>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:"-u3"
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: VCAST_main_sigunit_fini_fail7
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_sigunit_fini_fail7
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.STUB:CSigUnit_HwInit.sigunit_hw_fini
TEST.STUB:CSigUnit_Debug.sigunit_enable_logging
TEST.STUB:CSigUnit_RM.sigunit_fini
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.return:false
TEST.VALUE:CSigUnit_Debug.sigunit_enable_logging.return:0
TEST.VALUE:CSigUnit_RM.VCAST_main.argc:2
TEST.VALUE:CSigUnit_RM.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:<<malloc 5>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:"main"
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:<<malloc 4>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:"-u0"
TEST.VALUE:CSigUnit_RM.sigunit_fini.return:false
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: VCAST_main_sigunit_init_fail8
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_sigunit_init_fail8
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.STUB:CSigUnit_HwInit.sigunit_hw_fini
TEST.STUB:CSigUnit_Debug.sigunit_enable_logging
TEST.STUB:CSigUnit_RM.sigunit_init
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:1
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.return:true
TEST.VALUE:CSigUnit_Debug.sigunit_enable_logging.return:0
TEST.VALUE:CSigUnit_RM.sigunit_init.return:1
TEST.VALUE:CSigUnit_RM.VCAST_main.argc:2
TEST.VALUE:CSigUnit_RM.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:<<malloc 5>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:"main"
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:<<malloc 4>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:"-u0"
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: VCAST_main_sigunit_options_fail6
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_sigunit_options_fail6
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.STUB:CSigUnit_HwInit.sigunit_hw_fini
TEST.STUB:CSigUnit_Debug.sigunit_enable_logging
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:1
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.return:true
TEST.VALUE:CSigUnit_Debug.sigunit_enable_logging.return:0
TEST.VALUE:CSigUnit_RM.VCAST_main.argc:2
TEST.VALUE:CSigUnit_RM.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:<<malloc 5>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:"main"
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:<<malloc 4>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:"-p0"
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: VCAST_main_strtol_option_fail10
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_strtol_option_fail10
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.STUB:CSigUnit_HwInit.sigunit_hw_fini
TEST.STUB:CSigUnit_Debug.sigunit_enable_logging
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:1
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.return:true
TEST.VALUE:CSigUnit_Debug.sigunit_enable_logging.return:0
TEST.VALUE:CSigUnit_RM.VCAST_main.argc:2
TEST.VALUE:CSigUnit_RM.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:<<malloc 5>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:"main"
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:<<malloc 4>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:"-u0"
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.VALUE_USER_CODE:<<testcase>>
errno = 1;

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: VCAST_main_success1
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_success1
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.STUB:CSigUnit_HwInit.sigunit_hw_fini
TEST.STUB:CSigUnit_Debug.sigunit_enable_logging
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.return:true
TEST.VALUE:CSigUnit_Debug.sigunit_enable_logging.return:0
TEST.VALUE:CSigUnit_RM.VCAST_main.argc:2
TEST.VALUE:CSigUnit_RM.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:<<malloc 5>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:"main"
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:<<malloc 4>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:"-u0"
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:0
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: VCAST_main_threadctl_fail9
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:VCAST_main
TEST.NEW
TEST.NAME:VCAST_main_threadctl_fail9
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.STUB:CSigUnit_HwInit.sigunit_hw_fini
TEST.STUB:CSigUnit_Debug.sigunit_enable_logging
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_block.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_handler.return:0
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:1
TEST.VALUE:uut_prototype_stubs.ThreadCtl.return:-1
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.return:true
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.return:true
TEST.VALUE:CSigUnit_Debug.sigunit_enable_logging.return:0
TEST.VALUE:CSigUnit_RM.VCAST_main.argc:2
TEST.VALUE:CSigUnit_RM.VCAST_main.argv:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:<<malloc 5>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[0]:"main"
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:<<malloc 4>>
TEST.VALUE:CSigUnit_RM.VCAST_main.argv[1]:"-u0"
TEST.EXPECTED:CSigUnit_RM.VCAST_main.return:1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Subprogram: sigunit_exit_handler

-- Test Case: sigunit_exit_handler.success1
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_exit_handler
TEST.NEW
TEST.NAME:sigunit_exit_handler.success1
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:CSigUnit_RM.sigunit_exit_handler.sig:1
TEST.EXPECTED:CSigUnit_RM.sigunit_exit_handler.sig:1
TEST.END

-- Subprogram: sigunit_fini

-- Test Case: sigunit_fini_hw_fini_fail
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_fini
TEST.NEW
TEST.NAME:sigunit_fini_hw_fini_fail
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_fini
TEST.VALUE:uut_prototype_stubs.resmgr_detach.return:0
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.return:false
TEST.VALUE:CSigUnit_RM.sigunit_fini.p_sig_fini_dev_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_fini.p_sig_fini_dev_SP[0].ctp_UP:<<malloc 1>>
TEST.EXPECTED:CSigUnit_RM.sigunit_fini.return:true
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_fini_resmgr_detach_fail
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_fini
TEST.NEW
TEST.NAME:sigunit_fini_resmgr_detach_fail
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwInit.sigunit_hw_fini
TEST.VALUE:uut_prototype_stubs.resmgr_detach.return:-1
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_fini.return:false
TEST.VALUE:CSigUnit_RM.sigunit_fini.p_sig_fini_dev_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_fini.p_sig_fini_dev_SP[0].ctp_UP:<<malloc 1>>
TEST.EXPECTED:CSigUnit_RM.sigunit_fini.return:false
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Subprogram: sigunit_init

-- Test Case: sigunit_init.dispatchcontextallocfail4
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_init
TEST.NEW
TEST.NAME:sigunit_init.dispatchcontextallocfail4
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].devnum_U8:0
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].dpp_SP:<<malloc 1>>
TEST.EXPECTED:CSigUnit_RM.sigunit_init.return:12
TEST.END

-- Test Case: sigunit_init.dispathcontextallocsuccess4
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_init
TEST.NEW
TEST.NAME:sigunit_init.dispathcontextallocsuccess4
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:0
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].devnum_U8:0
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].dpp_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].id_INT32:0
TEST.EXPECTED:CSigUnit_RM.sigunit_init.return:0
TEST.END

-- Test Case: sigunit_init.dppfail1
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_init
TEST.NEW
TEST.NAME:sigunit_init.dppfail1
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].devnum_U8:0
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].dpp_SP:<<malloc 1>>
TEST.EXPECTED:CSigUnit_RM.sigunit_init.return:12
TEST.END

-- Test Case: sigunit_init.dppsuccess1
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_init
TEST.NEW
TEST.NAME:sigunit_init.dppsuccess1
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].devnum_U8:0
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].dpp_SP:<<malloc 1>>
TEST.EXPECTED:CSigUnit_RM.sigunit_init.return:12
TEST.END

-- Test Case: sigunit_init.procmgrabilityfail3
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_init
TEST.NEW
TEST.NAME:sigunit_init.procmgrabilityfail3
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:-1
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].devnum_U8:0
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].dpp_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].id_INT32:0
TEST.EXPECTED:CSigUnit_RM.sigunit_init.return:1
TEST.END

-- Test Case: sigunit_init.procmgrabilitysuccess3
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_init
TEST.NEW
TEST.NAME:sigunit_init.procmgrabilitysuccess3
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dispatch_context_alloc.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.procmgr_ability.return:0
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].devnum_U8:0
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].dpp_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].id_INT32:0
TEST.EXPECTED:CSigUnit_RM.sigunit_init.return:0
TEST.END

-- Test Case: sigunit_init.resmgrattachfail2
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_init
TEST.NEW
TEST.NAME:sigunit_init.resmgrattachfail2
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.resmgr_attach.return:-1
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].devnum_U8:0
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].dpp_SP:<<malloc 1>>
TEST.EXPECTED:CSigUnit_RM.sigunit_init.return:1
TEST.END

-- Test Case: sigunit_init.resmgrattachsuccess2
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_init
TEST.NEW
TEST.NAME:sigunit_init.resmgrattachsuccess2
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.dispatch_create.return:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].devnum_U8:0
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].dpp_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_init.p_sig_create_dev_SP[0].id_INT32:0
TEST.EXPECTED:CSigUnit_RM.sigunit_init.return:12
TEST.END

-- Subprogram: sigunit_io_devctl

-- Test Case: sigunit_io_devctl.001
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.001
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_shutdown
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.return:0
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.return:0
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.devctldefaultfail1
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.devctldefaultfail1
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:11
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_base:VECTORCAST_BUFFER
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:23
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:11
TEST.END

-- Test Case: sigunit_io_devctl.devctldefaultsuccess1
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.devctldefaultsuccess1
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_initialize
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].error_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].reset_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].panic_rgba_U32:128
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].o.ret_val:0
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:22
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.invaliddcmdfail2
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.invaliddcmdfail2
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_initialize
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].error_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].reset_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].panic_rgba_U32:128
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].o.ret_val:0
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:22
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.invaliddcmdsuccess2
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.invaliddcmdsuccess2
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_initialize
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].error_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].reset_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].panic_rgba_U32:128
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.return:-1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].o.ret_val:-1
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:22
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigevalwinsetupfail4
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigevalwinsetupfail4
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_eval_win_setup
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_setup.return:-1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:3
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:3
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].o.ret_val:-1
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:22
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigevalwinsetupsuccess4
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigevalwinsetupsuccess4
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_eval_win_setup
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_setup.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:3
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:3
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].o.ret_val:-1
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:-1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigevalwinstartfail5
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigevalwinstartfail5
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_eval_win_start
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.return:-1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:4
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:4
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].o.ret_val:-1
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:22
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigevalwinstartsuccess5
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigevalwinstartsuccess5
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_eval_win_start
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_start.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:4
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:4
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].o.ret_val:-1
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:-1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigevalwinstatusfail7
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigevalwinstatusfail7
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_eval_win_status
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.p_SigUnitWinStatus_SP[0].eval_win_id:1
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.return:-1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:6
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:6
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:22
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigevalwinstatussuccess7
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigevalwinstatussuccess7
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_eval_win_status
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.p_SigUnitWinStatus_SP[0].eval_win_id:1
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_status.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:6
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:6
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:-1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigevalwinstopfail6
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigevalwinstopfail6
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_eval_win_stop
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_stop.return:-1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:5
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:5
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:22
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigevalwinstopsuccess6
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigevalwinstopsuccess6
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_eval_win_stop
TEST.VALUE:CSigUnit_HwIf.sigunit_eval_win_stop.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:5
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:5
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:-1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigshutdownfail8
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigshutdownfail8
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_shutdown
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.return:1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:1282
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:1282
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_ocb_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_ocb_SP[0].ioflag:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.return:-1
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:-1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigshutdownsuccess8
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigshutdownsuccess8
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_shutdown
TEST.VALUE:CSigUnit_HwIf.sigunit_shutdown.return:-1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:1282
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:1282
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:22
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigunitintializefail3
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigunitintializefail3
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_initialize
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].error_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].reset_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].panic_rgba_U32:128
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.return:-1
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].o.ret_val:-1
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:22
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Test Case: sigunit_io_devctl.sigunitintializesuccess3
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_devctl
TEST.NEW
TEST.NAME:sigunit_io_devctl.sigunitintializesuccess3
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:CSigUnit_HwIf.sigunit_initialize
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].error_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].reset_threshold_U8:0
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.p_SigUnitCfg_SP[0].panic_rgba_U32:128
TEST.VALUE:CSigUnit_HwIf.sigunit_initialize.return:0
TEST.VALUE:uut_prototype_stubs.iofunc_devctl_default.return:-2147483647
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].rcvid:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].dpp:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].id:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].msg_max_size:2048
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].size:12
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.sigDevctlctp_p[0].iov[0].iov_len:256
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[0].i.dcmd:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].i.dcmd:1
TEST.VALUE:CSigUnit_RM.sigunit_io_devctl.p_msg_UP[1].o.ret_val:-1
TEST.EXPECTED:CSigUnit_RM.sigunit_io_devctl.return:-1
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.END

-- Subprogram: sigunit_io_open

-- Test Case: sigunit_io_open_fail1
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_open
TEST.NEW
TEST.NAME:sigunit_io_open_fail1
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.iofunc_open_default.return:-1
TEST.EXPECTED:CSigUnit_RM.sigunit_io_open.return:-1
TEST.END

-- Test Case: sigunit_io_open_success1
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_io_open
TEST.NEW
TEST.NAME:sigunit_io_open_success1
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.iofunc_open_default.return:0
TEST.EXPECTED:CSigUnit_RM.sigunit_io_open.return:0
TEST.END

-- Subprogram: sigunit_options

-- Test Case: sigunit_options_EINVAL_fail2
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_options
TEST.NEW
TEST.NAME:sigunit_options_EINVAL_fail2
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:CSigUnit_RM.sigunit_options.argc:2
TEST.VALUE:CSigUnit_RM.sigunit_options.argv:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[0]:<<malloc 5>>
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[0]:"main"
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[1]:<<malloc 4>>
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[1]:"-u0"
TEST.VALUE:CSigUnit_RM.sigunit_options.p_dev_options_SP:<<malloc 1>>
TEST.EXPECTED:CSigUnit_RM.sigunit_options.return:true
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = EINVAL;
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: sigunit_options_EOK_success1
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_options
TEST.NEW
TEST.NAME:sigunit_options_EOK_success1
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strtol
TEST.STUB:CSigUnit_HwInit.sigunit_hw_init
TEST.VALUE:CSigUnit_HwInit.sigunit_hw_init.p_sighwinit_SP[0].devnum_U8:5
TEST.VALUE:CSigUnit_RM.sigunit_options.argc:2
TEST.VALUE:CSigUnit_RM.sigunit_options.argv:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[0]:<<malloc 5>>
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[0]:"main"
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[1]:<<malloc 4>>
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[1]:"-u5"
TEST.VALUE:CSigUnit_RM.sigunit_options.p_dev_options_SP:<<malloc 1>>
TEST.VALUE:CSigUnit_RM.sigunit_options.p_dev_options_SP[0].devnum_U8:5
TEST.VALUE:CSigUnit_RM.sigunit_options.return:false
TEST.EXPECTED:CSigUnit_RM.sigunit_options.return:false
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
<<uut_prototype_stubs.strtol.return>> = ( 5 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: sigunit_options_ERANGE_fail1
TEST.UNIT:CSigUnit_RM
TEST.SUBPROGRAM:sigunit_options
TEST.NEW
TEST.NAME:sigunit_options_ERANGE_fail1
TEST.NOTES:
Requirement_AU29610-143726
TEST.END_NOTES:
TEST.STUB:uut_prototype_stubs.strtol
TEST.VALUE:CSigUnit_RM.sigunit_options.argc:2
TEST.VALUE:CSigUnit_RM.sigunit_options.argv:<<malloc 2>>
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[0]:<<malloc 5>>
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[0]:"main"
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[1]:<<malloc 4>>
TEST.VALUE:CSigUnit_RM.sigunit_options.argv[1]:"-u0"
TEST.VALUE:CSigUnit_RM.sigunit_options.p_dev_options_SP:<<malloc 1>>
TEST.EXPECTED:CSigUnit_RM.sigunit_options.return:false
TEST.ATTRIBUTES:CSigUnit_HwIf.sigunit_get_port32.return:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.strtol.return
errno = ERANGE;
<<uut_prototype_stubs.strtol.return>> = 0;
TEST.END_STUB_VAL_USER_CODE:
TEST.END
