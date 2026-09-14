-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : SIGCDD_IF_UT_VCAST_HT
-- Unit(s) Under Test: SigIfCdd
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: SigIfCdd

-- Subprogram: SigIf_sig_deinit

-- Test Case: SigIf_sig_deinit.001
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_deinit
TEST.NEW
TEST.NAME:SigIf_sig_deinit.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: SigIf_sig_get_win_crc_data

-- Test Case: SigIf_sig_get_win_crc_data.001
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data.001
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_r.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_g.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_b.return:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.END

-- Test Case: SigIf_sig_get_win_crc_data.002
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data.002
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:1
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_r.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_g.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_b.return:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.END

-- Test Case: SigIf_sig_get_win_crc_data.003
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data.003
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:2
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_r.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_g.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_b.return:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.END

-- Test Case: SigIf_sig_get_win_crc_data.004
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data.004
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:3
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_r.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_g.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_b.return:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.END

-- Test Case: SigIf_sig_get_win_crc_data.005
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data.005
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:4
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_r.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_g.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_b.return:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.END

-- Test Case: SigIf_sig_get_win_crc_data.006
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data.006
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:5
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_r.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_g.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_b.return:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.END

-- Test Case: SigIf_sig_get_win_crc_data.007
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data.007
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:6
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_r.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_g.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_b.return:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.END

-- Test Case: SigIf_sig_get_win_crc_data.008
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data.008
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:7
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_r.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_g.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_b.return:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.END

-- Test Case: SigIf_sig_get_win_crc_data.009
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data.009
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:1
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_r.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_g.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_b.return:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.END

-- Test Case: SigIf_sig_get_win_crc_data.010
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data.010
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:8
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_r.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_g.return:0x0
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_crc_b.return:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.END

-- Subprogram: SigIf_sig_get_win_status

-- Test Case: SigIf_sig_get_win_status.001
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status.001
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_win_status.002
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status.002
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:1
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_win_status.003
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status.003
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:2
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_win_status.004
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status.004
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:3
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_win_status.005
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status.005
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:4
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_win_status.006
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status.006
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:5
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_win_status.007
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status.007
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:6
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_win_status.008
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status.008
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:7
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_win_status.009
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status.009
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:8
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_win_status.010
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status.010
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:1
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_win_status.011
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status.011
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.return:1
TEST.VALUE:uut_prototype_stubs.iris_sigdrv_sig0_get_win0_status.return:1
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:1
TEST.END

-- Subprogram: SigIf_sig_get_windows_status

-- Test Case: SigIf_sig_get_windows_status.001
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_windows_status
TEST.NEW
TEST.NAME:SigIf_sig_get_windows_status.001
TEST.VALUE:SigIfCdd.SigIf_sig_get_windows_status.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_windows_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_windows_status.002
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_windows_status
TEST.NEW
TEST.NAME:SigIf_sig_get_windows_status.002
TEST.VALUE:SigIfCdd.SigIf_sig_get_windows_status.p_sig_unit:1
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_windows_status.return:0
TEST.END

-- Subprogram: SigIf_sig_init

-- Test Case: SigIf_sig_init.001
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_init
TEST.NEW
TEST.NAME:SigIf_sig_init.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: SigIf_sig_ldcfg_win

-- Test Case: SigIf_sig_ldcfg_win.001
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_ldcfg_win
TEST.NEW
TEST.NAME:SigIf_sig_ldcfg_win.001
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_window:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_window:0
TEST.END

-- Test Case: SigIf_sig_ldcfg_win.002
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_ldcfg_win
TEST.NEW
TEST.NAME:SigIf_sig_ldcfg_win.002
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_window:1
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_window:1
TEST.END

-- Test Case: SigIf_sig_ldcfg_win.003
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_ldcfg_win
TEST.NEW
TEST.NAME:SigIf_sig_ldcfg_win.003
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_window:2
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_window:2
TEST.END

-- Test Case: SigIf_sig_ldcfg_win.004
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_ldcfg_win
TEST.NEW
TEST.NAME:SigIf_sig_ldcfg_win.004
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_window:3
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_window:3
TEST.END

-- Test Case: SigIf_sig_ldcfg_win.005
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_ldcfg_win
TEST.NEW
TEST.NAME:SigIf_sig_ldcfg_win.005
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_window:4
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_window:4
TEST.END

-- Test Case: SigIf_sig_ldcfg_win.006
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_ldcfg_win
TEST.NEW
TEST.NAME:SigIf_sig_ldcfg_win.006
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_window:5
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_window:5
TEST.END

-- Test Case: SigIf_sig_ldcfg_win.007
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_ldcfg_win
TEST.NEW
TEST.NAME:SigIf_sig_ldcfg_win.007
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_window:6
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_window:6
TEST.END

-- Test Case: SigIf_sig_ldcfg_win.008
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_ldcfg_win
TEST.NEW
TEST.NAME:SigIf_sig_ldcfg_win.008
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_window:7
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_window:7
TEST.END

-- Test Case: SigIf_sig_ldcfg_win.009
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_ldcfg_win
TEST.NEW
TEST.NAME:SigIf_sig_ldcfg_win.009
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:1
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_window:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:1
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_window:0
TEST.END

-- Test Case: SigIf_sig_ldcfg_win.010
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_ldcfg_win
TEST.NEW
TEST.NAME:SigIf_sig_ldcfg_win.010
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_ldcfg_win.p_window:8
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_ldcfg_win.p_window:8
TEST.END

-- Subprogram: SigIf_sig_set_ev_window

-- Test Case: SigIf_sig_set_ev_window.001
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:SigIf_sig_set_ev_window.001
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_set_ev_window.return:E_OK_t
TEST.END

-- Test Case: SigIf_sig_set_ev_window.002
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:SigIf_sig_set_ev_window.002
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_set_ev_window.return:E_OK_t
TEST.END

-- Subprogram: SigIf_sig_setup_win

-- Test Case: SigIf_sig_setup_win.001
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win.001
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_window:0
TEST.END

-- Test Case: SigIf_sig_setup_win.002
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win.002
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:1
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_window:1
TEST.END

-- Test Case: SigIf_sig_setup_win.003
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win.003
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:2
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_window:2
TEST.END

-- Test Case: SigIf_sig_setup_win.004
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win.004
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:3
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_window:3
TEST.END

-- Test Case: SigIf_sig_setup_win.005
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win.005
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:4
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_window:4
TEST.END

-- Test Case: SigIf_sig_setup_win.006
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win.006
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:5
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_window:5
TEST.END

-- Test Case: SigIf_sig_setup_win.007
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win.007
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:6
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_window:6
TEST.END

-- Test Case: SigIf_sig_setup_win.008
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win.008
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:7
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_window:7
TEST.END

-- Test Case: SigIf_sig_setup_win.009
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win.009
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:8
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_window:8
TEST.END

-- Test Case: SigIf_sig_setup_win.010
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win.010
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:1
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:1
TEST.EXPECTED:SigIfCdd.SigIf_sig_setup_win.p_window:0
TEST.END

-- Subprogram: SigIf_sig_stop_evaluation

-- Test Case: SigIf_sig_stop_evaluation.001
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_stop_evaluation
TEST.NEW
TEST.NAME:SigIf_sig_stop_evaluation.001
TEST.VALUE:SigIfCdd.SigIf_sig_stop_evaluation.p_sig_unit:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_stop_evaluation.p_sig_unit:0
TEST.END

-- Test Case: SigIf_sig_stop_evaluation.002
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_stop_evaluation
TEST.NEW
TEST.NAME:SigIf_sig_stop_evaluation.002
TEST.VALUE:SigIfCdd.SigIf_sig_stop_evaluation.p_sig_unit:1
TEST.EXPECTED:SigIfCdd.SigIf_sig_stop_evaluation.p_sig_unit:1
TEST.END
