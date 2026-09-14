-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : SIG_DRV_TV2_VCAST_HT
-- Unit(s) Under Test: tv2_sigdrv
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: tv2_sigdrv

-- Subprogram: iris_sigdrv_sig0_clear_cnt_mode

-- Test Case: iris_sigdrv_sig0_clear_cnt_mode.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_clear_cnt_mode
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_clear_cnt_mode.001
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[83]:0
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win0_crc_b

-- Test Case: iris_sigdrv_sig0_get_win0_crc_b.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_crc_b.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[94]:0xFFFFFFFF
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win0_crc_b.return:0xFFFFFFFF
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winsy:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winey:INPUT_BASE=16
TEST.END

-- Test Case: iris_sigdrv_sig0_get_win0_crc_b.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_crc_b.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[94]:0x12345656
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win0_crc_b.return:0x12345656
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winsy:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winey:INPUT_BASE=16
TEST.END

-- Test Case: iris_sigdrv_sig0_get_win0_crc_b.003
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_crc_b.003
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[94]:0xFF000080
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win0_crc_b.return:0xFF000080
TEST.END

-- Test Case: iris_sigdrv_sig0_get_win0_crc_b.004
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_crc_b.004
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[94]:0xABCDEF,0xFDA123
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win0_crc_b.return:0xABCDEF,0xFDA123
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[92]::INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win0_crc_r.return::EXPECTED_BASE=16
TEST.END

-- Test Case: iris_sigdrv_sig0_get_win0_crc_b.005
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_crc_b.005
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[94]:0xFF0080
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win0_crc_b.return:0xFF0080
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win0_crc_g

-- Test Case: iris_sigdrv_sig0_get_win0_crc_g.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_crc_g.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[93]:0xFAFAFAFA
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win0_crc_g.return:0xFAFAFAFA
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[94]:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win0_crc_b.return:EXPECTED_BASE=16
TEST.END

-- Test Case: iris_sigdrv_sig0_get_win0_crc_g.001.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_crc_g.001.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[93]:0xDAD
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win0_crc_g.return:0xDAD
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win0_crc_r

-- Test Case: iris_sigdrv_sig0_get_win0_crc_r.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_crc_r.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[92]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win0_crc_r.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win0_status

-- Test Case: iris_sigdrv_sig0_get_win0_status.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_status.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0xDAD,0xFFFFFFFF,0x1234,0x565
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win0_status.return:(2)1,0,1
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win1_crc_b

-- Test Case: iris_sigdrv_sig0_get_win1_crc_b.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win1_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win1_crc_b.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[103]:0x0,0xDAD,0xFFFFFFFF,0x89010313
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win1_crc_b.return:0x0,0xDAD,0xFFFFFFFF,0x89010313
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[102]::INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win1_crc_g.return::EXPECTED_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win1_crc_g

-- Test Case: iris_sigdrv_sig0_get_win1_crc_g.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win1_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win1_crc_g.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[102]:0x0,0x7CCFFFFF,0xFFFAABB
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win1_crc_g.return:0x0,0x7CCFFFFF,0xFFFAABB
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win1_crc_r

-- Test Case: iris_sigdrv_sig0_get_win1_crc_r.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win1_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win1_crc_r.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[101]:0x0,0x7CCFFFFF,0xFFFAABB,0xFAF123
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win1_crc_r.return:0x0,0x7CCFFFFF,0xFFFAABB,0xFAF123
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win1_status

-- Test Case: iris_sigdrv_sig0_get_win1_status.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win1_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win1_status.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0xFF,0x1,0x2,0x0,0xDAD,0xFFFFFF80,0xFF000080
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win1_status.return:0x2,0x0,0x2,(4)0x0
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win2_crc_b

-- Test Case: iris_sigdrv_sig0_get_win2_crc_b.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win2_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win2_crc_b.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[112]:0x0,0xFFFF,0x29D5BF3,0xC
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win2_crc_b.return:0x0,0xFFFF,0x29D5BF3,0xC
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win2_crc_g

-- Test Case: iris_sigdrv_sig0_get_win2_crc_g.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win2_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win2_crc_g.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[111]:0x7B,0xADF,0x54F93EC,0x1,0x0,0x63,0x1234
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win2_crc_g.return:0x7B,0xADF,0x54F93EC,0x1,0x0,0x63,0x1234
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win2_crc_r

-- Test Case: iris_sigdrv_sig0_get_win2_crc_r.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win2_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win2_crc_r.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[110]:0x40AA106C,0xDAD,0xFAF,0x1,0x0,0xABCDEF
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win2_crc_r.return:0x40AA106C,0xDAD,0xFAF,0x1,0x0,0xABCDEF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win2_status

-- Test Case: iris_sigdrv_sig0_get_win2_status.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win2_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win2_status.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0x0,0x45,0xFF
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win2_status.return:0x0,(2)0x4
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:EXPECTED_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win3_crc_b

-- Test Case: iris_sigdrv_sig0_get_win3_crc_b.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win3_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win3_crc_b.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[121]:0xFFFF,0x12D687,0x0,0xABCDEF
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win3_crc_b.return:0xFFFF,0x12D687,0x0,0xABCDEF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win3_crc_g

-- Test Case: iris_sigdrv_sig0_get_win3_crc_g.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win3_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win3_crc_g.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[120]:123456789,2882382797,0,157
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win3_crc_g.return:123456789,2882382797,0,157
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win3_crc_r

-- Test Case: iris_sigdrv_sig0_get_win3_crc_r.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win3_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win3_crc_r.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[119]:0x0,0xA5CC4,0xDADDAD
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win3_crc_r.return:0x0,0xA5CC4,0xDADDAD
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win3_status

-- Test Case: iris_sigdrv_sig0_get_win3_status.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win3_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win3_status.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0x0,0xDD,0xA,0xFFAAFFAA,0xABCDEF
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win3_status.return:0x0,(4)0x8
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win1_status.return:EXPECTED_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win4_crc_b

-- Test Case: iris_sigdrv_sig0_get_win4_crc_b.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win4_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win4_crc_b.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[130]:0,43981,45567,4294967295,167
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win4_crc_b.return:0,43981,45567,4294967295,167
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win4_crc_g

-- Test Case: iris_sigdrv_sig0_get_win4_crc_g.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win4_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win4_crc_g.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[129]:0x1,0x0,0xDFDF,0xA,0x2855449E,0xFAFAFAD
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win4_crc_g.return:0x1,0x0,0xDFDF,0xA,0x2855449E,0xFAFAFAD
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[128]::INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win4_crc_r.return::EXPECTED_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win4_crc_r

-- Test Case: iris_sigdrv_sig0_get_win4_crc_r.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win4_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win4_crc_r.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[128]:0x0,0x3ADE68B1,0xADF,0xF,0xEFDA
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win4_crc_r.return:0x0,0x3ADE68B1,0xADF,0xF,0xEFDA
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win4_status

-- Test Case: iris_sigdrv_sig0_get_win4_status.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win4_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win4_status.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0x0,0x2,0xF,0xA,0xFF,0x123,0xDAD,0xFFFFFFFF,0xDABCDABC
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win4_status.return:(4)0x0,0x10,(2)0x0,(2)0x10
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win1_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win3_status.return:EXPECTED_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win5_crc_b

-- Test Case: iris_sigdrv_sig0_get_win5_crc_b.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win5_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win5_crc_b.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[139]:0x0,0xAB,0xDF,0x38DC,0x408AA5F,0xFF80
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win5_crc_b.return:0x0,0xAB,0xDF,0x38DC,0x408AA5F,0xFF80
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win5_crc_g

-- Test Case: iris_sigdrv_sig0_get_win5_crc_g.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win5_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win5_crc_g.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[138]:0x88FF0F,0x1,0x4,0xEDFAACDB,0xDD,0xFF0080
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win5_crc_g.return:0x88FF0F,0x1,0x4,0xEDFAACDB,0xDD,0xFF0080
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win5_crc_r

-- Test Case: iris_sigdrv_sig0_get_win5_crc_r.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win5_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win5_crc_r.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[137]:0x0,0x1,0x246C,0x1234,0x98765252,0xDAF,0xFF000080
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win5_crc_r.return:0x0,0x1,0x246C,0x1234,0x98765252,0xDAF,0xFF000080
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win5_status

-- Test Case: iris_sigdrv_sig0_get_win5_status.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win5_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win5_status.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0x0,0x1,0xEF,0xFFFFFF80,0xABCDABCD
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win5_status.return:(2)0x0,0x20,(2)0x0
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win1_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win3_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win4_status.return:EXPECTED_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win6_crc_b

-- Test Case: iris_sigdrv_sig0_get_win6_crc_b.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win6_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win6_crc_b.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[148]:0,1234,223,704474,123456789
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win6_crc_b.return:0,1234,223,704474,123456789
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win6_crc_g

-- Test Case: iris_sigdrv_sig0_get_win6_crc_g.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win6_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win6_crc_g.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[147]:(2)4294967295,0,987654321,67
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win6_crc_g.return:(2)4294967295,0,987654321,67
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win6_crc_r

-- Test Case: iris_sigdrv_sig0_get_win6_crc_r.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win6_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win6_crc_r.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[146]:429496729,291,10,16,67
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win6_crc_r.return:429496729,291,10,16,67
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[147]:INPUT_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win6_crc_g.return:EXPECTED_BASE=10
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win6_status

-- Test Case: iris_sigdrv_sig0_get_win6_status.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win6_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win6_status.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0x0,0x1,0xFFFF,0x1245
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win6_status.return:(2)0x0,(2)0x40
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win7_crc_b

-- Test Case: iris_sigdrv_sig0_get_win7_crc_b.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win7_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win7_crc_b.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[158]:0x4D2,0x10E1,0xAB1234DD,0x101
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win7_crc_b.return:0x4D2,0x10E1,0xAB1234DD,0x101
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win7_crc_g

-- Test Case: iris_sigdrv_sig0_get_win7_crc_g.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win7_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win7_crc_g.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[157]:0x10,0x40,0xDDD5,0x0,0x1,0x63,0xBABABABA
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win7_crc_g.return:0x10,0x40,0xDDD5,0x0,0x1,0x63,0xBABABABA
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win7_crc_r

-- Test Case: iris_sigdrv_sig0_get_win7_crc_r.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win7_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win7_crc_r.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[156]:4567890,16,255,0,99,9999
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win7_crc_r.return:4567890,16,255,0,99,9999
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win7_status

-- Test Case: iris_sigdrv_sig0_get_win7_status.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win7_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win7_status.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0x0,0x1,0xFFFF,0xABCDEF2
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win7_status.return:(2)0x0,(2)0x80
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win_status

-- Test Case: iris_sigdrv_sig0_get_win_status.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win_status.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0xCC
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:0xCC
TEST.END

-- Test Case: iris_sigdrv_sig0_get_win_status.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win_status.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0xFF
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:0xFF
TEST.END

-- Test Case: iris_sigdrv_sig0_get_win_status.003
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win_status.003
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0x1234
TEST.EXPECTED:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:0x34
TEST.END

-- Subprogram: iris_sigdrv_sig0_initialize

-- Test Case: iris_sigdrv_sig0_initialize.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_initialize
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_initialize.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:10
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].source:4
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].error_threshold:40
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].reset_threshold:20
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].panic_rgba:0xFF000080
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:10
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[1]:0x0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[81]:0xFF000080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[82]:0x14280001
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[83]:0x0
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:EXPECTED_BASE=16
TEST.END

-- Test Case: iris_sigdrv_sig0_initialize.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_initialize
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_initialize.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:10
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].source:7
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].error_threshold:10
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].reset_threshold:13
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].panic_rgba:0xFF80
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:10
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[1]:0x3
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[81]:0xFF80
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[82]:0xD0A0001
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[83]:0x0
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:EXPECTED_BASE=16
TEST.END

-- Test Case: iris_sigdrv_sig0_initialize.003
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_initialize
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_initialize.003
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:10
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].source:4
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].error_threshold:40
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].reset_threshold:20
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].panic_rgba:0xFF0080
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:10
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[1]:0x0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[81]:0xFF0080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[82]:0x14280001
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[83]:0x0
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:EXPECTED_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win0

-- Test Case: iris_sigdrv_sig0_ldcfg_win0.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win0
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win0.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x1
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win0.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win0
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win0.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFFFFFFFF
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFFFFFFFF
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win0.003
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win0
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win0.003
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xABCD
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xABCD
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win0.004
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win0
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win0.004
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x12345678
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x12345679
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win1

-- Test Case: iris_sigdrv_sig0_ldcfg_win1.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win1
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win1.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x2
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win1.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win1
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win1.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFFFFFFFF
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFFFFFFFF
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win1.003
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win1
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win1.003
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x1845
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x1847
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win1.004
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win1
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win1.004
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xABCD
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xABCF
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win2

-- Test Case: iris_sigdrv_sig0_ldcfg_win2.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win2
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win2.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x4
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win2.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win2
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win2.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x1
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x5
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win2.003
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win2
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win2.003
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFFAAFFAA
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFFAAFFAE
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win2.004
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win2
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win2.004
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xABCDABCD
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xABCDABCD
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win2.005
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win2
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win2.005
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xDAC
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xDAC
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win3

-- Test Case: iris_sigdrv_sig0_ldcfg_win3.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win3
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win3.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:8
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win3.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win3
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win3.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x12345678
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x12345678
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win3.003
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win3
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win3.003
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xDAD
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xDAD
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win4

-- Test Case: iris_sigdrv_sig0_ldcfg_win4.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win4
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win4.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x10
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win4.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win4
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win4.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFFFFFF80
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFFFFFF90
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win4.003
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win4
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win4.003
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFDCEA
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFDCFA
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win5

-- Test Case: iris_sigdrv_sig0_ldcfg_win5.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win5
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win5.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x20
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win5.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win5
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win5.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x1
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x21
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win5.003
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win5
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win5.003
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFACFAC
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFACFAC
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win5.004
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win5
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win5.004
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x156
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x176
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win6

-- Test Case: iris_sigdrv_sig0_ldcfg_win6.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win6
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win6.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x40
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win6.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win6
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win6.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x1
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x41
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win6.003
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win6
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win6.003
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x676767
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x676767
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win6.004
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win6
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win6.004
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xABCD
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xABCD
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win7

-- Test Case: iris_sigdrv_sig0_ldcfg_win7.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win7
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win7.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x80
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win7.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win7
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win7.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x1
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x81
TEST.END

-- Test Case: iris_sigdrv_sig0_ldcfg_win7.003
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win7
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win7.003
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFFFFF1
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0xFFFFF1
TEST.END

-- Subprogram: iris_sigdrv_sig0_lock

-- Test Case: iris_sigdrv_sig0_lock.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_lock
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_lock.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[0]:0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[0]:0
TEST.END

-- Test Case: iris_sigdrv_sig0_lock.001.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_lock
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_lock.001.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[0]:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[0]:1
TEST.END

-- Subprogram: iris_sigdrv_sig0_set_cnt_mode

-- Test Case: iris_sigdrv_sig0_set_cnt_mode.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_set_cnt_mode
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_set_cnt_mode.001
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[83]:1
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win0

-- Test Case: iris_sigdrv_sig0_setup_win0_true_val
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win0
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win0_true_val
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].control:0xE5AB
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winsx:150
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winsy:15
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winex:250
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winey:19
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].crc_ref_r:0xFF000080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].crc_ref_g:0xFF0080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].crc_ref_b:0xFF80
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[86]:0x103
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[87]:0xF0096
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[88]:1245434
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[89]:0xFF000080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[90]:0xFF0080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[91]:0xFF80
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[122]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[123..124]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[123..124]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125..127]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125..127]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125..127]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].control::INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_r::INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_g::INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_b::INPUT_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win1

-- Test Case: iris_sigdrv_sig0_setup_win1.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win1
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win1.001
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].control:0xDEF
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].winsx:400
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].winsy:19
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].winex:40
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].winey:17
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].crc_ref_r:0xFF000080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].crc_ref_g:0xFF0080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].crc_ref_b:0xFF80
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[95]:0x103
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[96]:0x130190
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[97]:0x110028
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[98]:0xFF000080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[99]:0xFF0080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[100]:0xFF80
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]::INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win7_status.return::EXPECTED_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win2

-- Test Case: iris_sigdrv_sig0_setup_win2.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win2
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win2.001
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].control:0xBDF
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winsx:650
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winsy:18
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winex:280
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winey:21
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].crc_ref_r:0xFF000080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].crc_ref_g:0xFF0080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].crc_ref_b:0xFF80
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[104]:0x303
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[105]:0x12028A
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[106]:0x150118
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[107]:0xFF000080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[108]:0xFF0080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[109]:0xFF80
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]::INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[95]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[96]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[97]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[98]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[99]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[100]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].crc_ref_r:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].crc_ref_g:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].crc_ref_b:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win7_status.return::EXPECTED_BASE=16
TEST.END

-- Test Case: iris_sigdrv_sig0_setup_win2.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win2
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win2.002
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].control:0xABCD
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winsx:700
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winsy:90
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winex:900
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winey:70
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].crc_ref_r:0x5467ACD
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].crc_ref_g:783829920
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].crc_ref_b:2334232211
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[104]:0x301
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[105]:5898940
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[106]:4588420
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[107]:0x5467ACD
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[108]:783829920
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[109]:2334232211
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[1]::INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win3

-- Test Case: iris_sigdrv_sig0_setup_win3.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win3
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win3.001
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].control:78272
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].winsx:130
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].winsy:24
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].winex:50
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].winey:21
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_r:0xFF000080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_g:0xFF0080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_b:0xFF80
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[113]:0x10100
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[114]:0x180082
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[115]:0x150032
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[116]:0xFF000080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[117]:0xFF0080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[118]:0xFF80
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[122]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[123..124]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[123..124]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125..127]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125..127]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125..127]::EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].control::INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_r::INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_g::INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_b::INPUT_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win4

-- Test Case: iris_sigdrv_sig0_setup_win4.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win4
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win4.001
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].control:0xBAD
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winsx:600
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winsy:21
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winex:10
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winey:16
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_r:0xFF000080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_g:0xFF0080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_b:0xFF80
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[122]:0x301
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[123]:0x150258
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[124]:0x10000A
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125]:0xFF000080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[126]:0xFF0080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[127]:0xFF80
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[113]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[114]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[115]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[116]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[117]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[118]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].control:INPUT_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_r:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_g:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_b:INPUT_BASE=16
TEST.END

-- Test Case: iris_sigdrv_sig0_setup_win4.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win4
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win4.002
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].control:0xFFFF
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winsx:300
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winsy:45
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winex:700
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winey:40
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_r:872621881
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_g:1234567899
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_b:987654321
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[122]:0x303
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[123]:0x2D012C
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[124]:0x2802BC
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125]:872621881
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[126]:1234567899
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[127]:987654321
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[113]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[114]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[115]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[116]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[117]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[118]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].control:INPUT_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_r:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_g:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_b:INPUT_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win5

-- Test Case: iris_sigdrv_sig0_setup_win5.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win5
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win5.001
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].control:0x8983
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].winsx:90
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].winsy:19
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].winex:10
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].winey:20
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].crc_ref_r:0xFF000080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].crc_ref_g:0xFF0080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].crc_ref_b:0xFF80
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[131]:0x103
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[132]:0x13005A
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[133]:0x14000A
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[134]:0xFF000080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[135]:0xFF0080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[136]:0xFF80
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[122]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[123]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[124]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[126]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[127]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_r:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_g:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_b:INPUT_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win6

-- Test Case: iris_sigdrv_sig0_setup_win6.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win6
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win6.001
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].control:0x67
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winsx:50
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winsy:26
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winex:40
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winey:20
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_r:0xFF000080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_g:0xFF0080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_b:0xFF80
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[140]:0x3
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[141]:0x1A0032
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[142]:0x140028
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[143]:0xFF000080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[144]:0xFF0080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[145]:0xFF80
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[122]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[123]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[124]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[126]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[127]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[131]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[132]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[133]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_r:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_g:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_b:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].control:INPUT_BASE=16
TEST.END

-- Test Case: iris_sigdrv_sig0_setup_win6.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win6
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win6.002
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].control:0x10
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winsx:32767
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winsy:20000
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winex:30000
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winey:15000
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_r:0xE53663A
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_g:0xA1332BE
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_b:0xFAE234
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[140]:0x0
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[141]:0xE203FFF
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[142]:0x3A983530
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[143]:0xE53663A
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[144]:0xA1332BE
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[145]:0xFAE234
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[122]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[123]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[124]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[126]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[127]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[131]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[132]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[133]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_r:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_g:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_b:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].control:INPUT_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win7

-- Test Case: iris_sigdrv_sig0_setup_win7.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win7
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win7.001
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].control:0x4567
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winsx:600
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winsy:22
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winex:10
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winey:22
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].crc_ref_r:0xFF000080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].crc_ref_g:0xFF0080
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].crc_ref_b:0xFF80
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[150]:0x103
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[151]:0x160258
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[152]:0x16000A
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[153]:0xFF000080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[154]:0xFF0080
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[155]:0xFF80
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[122]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[123]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[124]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[126]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[127]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[131]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[132]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[133]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[140]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[141]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[142]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[143]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[144]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[145]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_r:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_g:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_b:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_r:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_g:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_b:INPUT_BASE=16
TEST.END

-- Test Case: iris_sigdrv_sig0_setup_win7.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win7
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win7.002
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf:<<malloc 1>>
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].control:0x123FFFFF
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winsx:900
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winsy:40
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winex:700
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winey:20
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].crc_ref_r:0xDAFDF
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].crc_ref_g:0xFABFAB
TEST.VALUE:tv2_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].crc_ref_b:0x1246726
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[150]:0x10303
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[151]:0x280384
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[152]:0x1402BC
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[153]:0xDAFDF
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[154]:0xFABFAB
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[155]:0x1246726
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[122]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[123]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[124]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[125]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[126]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[127]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[131]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[132]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[133]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[140]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[141]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[142]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[143]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[144]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[145]:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_r:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_g:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_b:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].control:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_r:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_g:INPUT_BASE=16
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_b:INPUT_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_unlock

-- Test Case: iris_sigdrv_sig0_unlock.001
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_unlock
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_unlock.001
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[1]:0x5
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[1]:0x5
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.END

-- Test Case: iris_sigdrv_sig0_unlock.002
TEST.UNIT:tv2_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_unlock
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_unlock.002
TEST.VALUE:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[1]:0x2
TEST.EXPECTED:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[1]:0x2
TEST.ATTRIBUTES:tv2_sigdrv.<<GLOBAL>>.uHardwareReg[84]:INPUT_BASE=10,EXPECTED_BASE=10
TEST.ATTRIBUTES:tv2_sigdrv.iris_sigdrv_sig0_get_win_status.return:EXPECTED_BASE=16
TEST.END
