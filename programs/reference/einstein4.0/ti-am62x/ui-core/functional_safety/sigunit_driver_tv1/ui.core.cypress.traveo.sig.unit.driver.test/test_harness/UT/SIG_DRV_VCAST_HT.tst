-- VectorCAST 6.4s (05/01/17)
-- Test Case Script
-- 
-- Environment    : SIG_DRV_VCAST_HT
-- Unit(s) Under Test: iris_sigdrv
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: iris_sigdrv_sig0_get_win0_crc_b

-- Test Case: iris_sigdrv_sig0_get_win0_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_crc_b.001
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[15]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win0_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.ATTRIBUTES:iris_sigdrv.iris_sigdrv_sig0_get_win0_crc_r.return:EXPECTED_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win0_crc_g

-- Test Case: iris_sigdrv_sig0_get_win0_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[14]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win0_crc_g.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win0_crc_r

-- Test Case: iris_sigdrv_sig0_get_win0_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[0]:0
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[13]:0,1,400,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win0_crc_r.return:0,1,400,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win0_status

-- Test Case: iris_sigdrv_sig0_get_win0_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win0_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win0_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[5]:0x0,0x1,0x2,0x3,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win0_status.return:0,1,0,(2)1
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win1_crc_b

-- Test Case: iris_sigdrv_sig0_get_win1_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win1_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win1_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[24]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win1_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win1_crc_g

-- Test Case: iris_sigdrv_sig0_get_win1_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win1_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win1_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[23]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win1_crc_g.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win1_crc_r

-- Test Case: iris_sigdrv_sig0_get_win1_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win1_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win1_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[22]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win1_crc_r.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win1_status

-- Test Case: iris_sigdrv_sig0_get_win1_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win1_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win1_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[5]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win1_status.return:0,(2)1
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win2_crc_b

-- Test Case: iris_sigdrv_sig0_get_win2_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win2_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win2_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[33]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win2_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win2_crc_g

-- Test Case: iris_sigdrv_sig0_get_win2_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win2_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win2_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[32]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win2_crc_g.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win2_crc_r

-- Test Case: iris_sigdrv_sig0_get_win2_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win2_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win2_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[31]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win2_crc_r.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win2_status

-- Test Case: iris_sigdrv_sig0_get_win2_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win2_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win2_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[5]:0x0,0x1,0x2,0x3,0x4,0xFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win2_status.return:(4)0,(3)1
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win3_crc_b

-- Test Case: iris_sigdrv_sig0_get_win3_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win3_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win3_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[42]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win3_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win3_crc_g

-- Test Case: iris_sigdrv_sig0_get_win3_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win3_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win3_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[41]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win3_crc_g.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win3_crc_r

-- Test Case: iris_sigdrv_sig0_get_win3_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win3_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win3_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[40]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win3_crc_r.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win3_status

-- Test Case: iris_sigdrv_sig0_get_win3_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win3_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win3_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[5]:0x0,0x1,0x2,0x4,0x8,0x10,0xFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win3_status.return:(4)0,1,0,(2)1
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win4_crc_b

-- Test Case: iris_sigdrv_sig0_get_win4_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win4_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win4_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[51]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win4_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.ATTRIBUTES:iris_sigdrv.iris_sigdrv_sig0_get_win4_crc_g.return:EXPECTED_BASE=16
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win4_crc_g

-- Test Case: iris_sigdrv_sig0_get_win4_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win4_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win4_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[50]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win4_crc_g.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win4_crc_r

-- Test Case: iris_sigdrv_sig0_get_win4_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win4_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win4_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[49]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win4_crc_r.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win4_status

-- Test Case: iris_sigdrv_sig0_get_win4_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win4_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win4_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[5]:0x0,0xF,0x10,0xE0,0xFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win4_status.return:(2)0,1,0,(2)1
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win5_crc_b

-- Test Case: iris_sigdrv_sig0_get_win5_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win5_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win5_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[60]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win5_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win5_crc_g

-- Test Case: iris_sigdrv_sig0_get_win5_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win5_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win5_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[59]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win5_crc_g.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win5_crc_r

-- Test Case: iris_sigdrv_sig0_get_win5_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win5_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win5_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[58]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win5_crc_r.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win5_status

-- Test Case: iris_sigdrv_sig0_get_win5_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win5_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win5_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[5]:0x0,0x20,0xFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win5_status.return:0,(3)1
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win6_crc_b

-- Test Case: iris_sigdrv_sig0_get_win6_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win6_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win6_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[69]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win6_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win6_crc_g

-- Test Case: iris_sigdrv_sig0_get_win6_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win6_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win6_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[68]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win6_crc_g.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win6_crc_r

-- Test Case: iris_sigdrv_sig0_get_win6_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win6_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win6_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[67]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win6_crc_r.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win6_status

-- Test Case: iris_sigdrv_sig0_get_win6_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win6_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win6_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[5]:0x0,0x40,0xFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win6_status.return:0,(3)1
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win7_crc_b

-- Test Case: iris_sigdrv_sig0_get_win7_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win7_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win7_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[78]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win7_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win7_crc_g

-- Test Case: iris_sigdrv_sig0_get_win7_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win7_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win7_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[77]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win7_crc_g.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win7_crc_r

-- Test Case: iris_sigdrv_sig0_get_win7_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win7_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win7_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[76]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win7_crc_r.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_get_win7_status

-- Test Case: iris_sigdrv_sig0_get_win7_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_get_win7_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_get_win7_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[5]:0x0,0x7F,0x80,0xFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig0_get_win7_status.return:(2)0,(3)1
TEST.END

-- Subprogram: iris_sigdrv_sig0_initialize

-- Test Case: iris_sigdrv_sig0_initialize.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_initialize
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_initialize.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_initialize.p_setup:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].source:0,1,2,3,127,255
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].error_threshold:0,127,255
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].reset_threshold:0,127,255
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].unused:0
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_initialize.p_setup[0].panic_rgba:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[1]:0,1,2,(3)3
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[2]:0x0,0x7FFFFF80,0xFFFFFF80
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[3]:0x1,0x7F7F0001,0xFFFF0001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[4]:1
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win0

-- Test Case: iris_sigdrv_sig0_ldcfg_win0.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win0
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win0.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[6]:1
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win1

-- Test Case: iris_sigdrv_sig0_ldcfg_win1.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win1
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win1.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[6]:2
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win2

-- Test Case: iris_sigdrv_sig0_ldcfg_win2.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win2
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win2.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[6]:4
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win3

-- Test Case: iris_sigdrv_sig0_ldcfg_win3.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win3
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win3.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[6]:8
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win4

-- Test Case: iris_sigdrv_sig0_ldcfg_win4.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win4
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win4.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[6]:0x10
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win5

-- Test Case: iris_sigdrv_sig0_ldcfg_win5.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win5
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win5.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[6]:0x20
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win6

-- Test Case: iris_sigdrv_sig0_ldcfg_win6.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win6
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win6.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[6]:0x40
TEST.END

-- Subprogram: iris_sigdrv_sig0_ldcfg_win7

-- Test Case: iris_sigdrv_sig0_ldcfg_win7.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_ldcfg_win7
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_ldcfg_win7.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[6]:0x80
TEST.END

-- Subprogram: iris_sigdrv_sig0_lock

-- Test Case: iris_sigdrv_sig0_lock.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_lock
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_lock.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[0]:0x5651F763
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win0

-- Test Case: iris_sigdrv_sig0_setup_win0.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win0
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win0.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win0.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[7]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[8..9]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[10..12]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win1

-- Test Case: iris_sigdrv_sig0_setup_win1.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win1
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win1.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win1.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[16]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[17..18]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[19..21]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win2

-- Test Case: iris_sigdrv_sig0_setup_win2.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win2
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win2.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win2.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[25]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[26..27]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[28..30]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win3

-- Test Case: iris_sigdrv_sig0_setup_win3.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win3
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win3.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win3.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[34]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[35..36]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[37..39]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win4

-- Test Case: iris_sigdrv_sig0_setup_win4.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win4
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win4.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win4.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[43]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[44..45]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[46..48]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win5

-- Test Case: iris_sigdrv_sig0_setup_win5.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win5
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win5.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win5.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[52]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[53..54]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[55..57]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win6

-- Test Case: iris_sigdrv_sig0_setup_win6.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win6
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win6.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win6.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[61]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[62..63]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[64..66]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_setup_win7

-- Test Case: iris_sigdrv_sig0_setup_win7.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_setup_win7
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_setup_win7.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig0_setup_win7.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[70]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[71..72]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[73..75]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig0_uninitialize

-- Test Case: iris_sigdrv_sig0_uninitialize.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_uninitialize
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_uninitialize.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[5]:0x0,0x100000
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[4]:0
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[5]:0x0,0x100000
TEST.END

-- Subprogram: iris_sigdrv_sig0_unlock

-- Test Case: iris_sigdrv_sig0_unlock.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig0_unlock
TEST.NEW
TEST.NAME:iris_sigdrv_sig0_unlock.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[0]:0x691DB936
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win0_crc_b

-- Test Case: iris_sigdrv_sig1_get_win0_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win0_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win0_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[94]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win0_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win0_crc_g

-- Test Case: iris_sigdrv_sig1_get_win0_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win0_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win0_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[93]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win0_crc_g.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win0_crc_r

-- Test Case: iris_sigdrv_sig1_get_win0_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win0_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win0_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[92]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win0_crc_r.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win0_status

-- Test Case: iris_sigdrv_sig1_get_win0_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win0_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win0_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0x0,0x1,0x2,0x3,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win0_status.return:0,1,0,(2)1
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win1_crc_b

-- Test Case: iris_sigdrv_sig1_get_win1_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win1_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win1_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[103]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win1_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win1_crc_g

-- Test Case: iris_sigdrv_sig1_get_win1_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win1_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win1_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[102]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win1_crc_g.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win1_crc_r

-- Test Case: iris_sigdrv_sig1_get_win1_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win1_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win1_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[101]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win1_crc_r.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win1_status

-- Test Case: iris_sigdrv_sig1_get_win1_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win1_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win1_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win1_status.return:0,(2)1
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win2_crc_b

-- Test Case: iris_sigdrv_sig1_get_win2_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win2_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win2_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[112]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win2_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win2_crc_g

-- Test Case: iris_sigdrv_sig1_get_win2_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win2_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win2_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[111]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win2_crc_g.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win2_crc_r

-- Test Case: iris_sigdrv_sig1_get_win2_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win2_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win2_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[110]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win2_crc_r.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win2_status

-- Test Case: iris_sigdrv_sig1_get_win2_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win2_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win2_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0,1,2,3,4,255,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win2_status.return:(4)0,(3)1
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win3_crc_b

-- Test Case: iris_sigdrv_sig1_get_win3_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win3_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win3_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[121]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win3_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win3_crc_g

-- Test Case: iris_sigdrv_sig1_get_win3_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win3_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win3_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[120]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win3_crc_g.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win3_crc_r

-- Test Case: iris_sigdrv_sig1_get_win3_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win3_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win3_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[119]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win3_crc_r.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win3_status

-- Test Case: iris_sigdrv_sig1_get_win3_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win3_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win3_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0,1,2,4,8,16,255,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win3_status.return:(4)0,1,0,(2)1
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win4_crc_b

-- Test Case: iris_sigdrv_sig1_get_win4_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win4_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win4_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[130]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win4_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win4_crc_g

-- Test Case: iris_sigdrv_sig1_get_win4_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win4_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win4_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[129]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win4_crc_g.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win4_crc_r

-- Test Case: iris_sigdrv_sig1_get_win4_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win4_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win4_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[128]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win4_crc_r.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win4_status

-- Test Case: iris_sigdrv_sig1_get_win4_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win4_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win4_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0,15,16,224,255,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win4_status.return:(2)0,1,0,(2)1
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win5_crc_b

-- Test Case: iris_sigdrv_sig1_get_win5_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win5_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win5_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[139]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win5_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win5_crc_g

-- Test Case: iris_sigdrv_sig1_get_win5_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win5_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win5_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[138]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win5_crc_g.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win5_crc_r

-- Test Case: iris_sigdrv_sig1_get_win5_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win5_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win5_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[137]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win5_crc_r.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win5_status

-- Test Case: iris_sigdrv_sig1_get_win5_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win5_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win5_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0,32,255,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win5_status.return:0,(3)1
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win6_crc_b

-- Test Case: iris_sigdrv_sig1_get_win6_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win6_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win6_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[148]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win6_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win6_crc_g

-- Test Case: iris_sigdrv_sig1_get_win6_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win6_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win6_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[147]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win6_crc_g.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win6_crc_r

-- Test Case: iris_sigdrv_sig1_get_win6_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win6_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win6_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[146]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win6_crc_r.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win6_status

-- Test Case: iris_sigdrv_sig1_get_win6_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win6_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win6_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0,64,255,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win6_status.return:0,(3)1
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win7_crc_b

-- Test Case: iris_sigdrv_sig1_get_win7_crc_b.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win7_crc_b
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win7_crc_b.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[158]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win7_crc_b.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win7_crc_g

-- Test Case: iris_sigdrv_sig1_get_win7_crc_g.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win7_crc_g
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win7_crc_g.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[157]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win7_crc_g.return:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win7_crc_r

-- Test Case: iris_sigdrv_sig1_get_win7_crc_r.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win7_crc_r
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win7_crc_r.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[156]:0,2147483647,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win7_crc_r.return:0,2147483647,4294967295
TEST.END

-- Subprogram: iris_sigdrv_sig1_get_win7_status

-- Test Case: iris_sigdrv_sig1_get_win7_status.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_get_win7_status
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_get_win7_status.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0,127,128,255,4294967295
TEST.EXPECTED:iris_sigdrv.iris_sigdrv_sig1_get_win7_status.return:(2)0,(3)1
TEST.END

-- Subprogram: iris_sigdrv_sig1_initialize

-- Test Case: iris_sigdrv_sig1_initialize.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_initialize
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_initialize.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_initialize.p_setup:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_initialize.p_setup[0].source:0,1,2,3,127,255
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_initialize.p_setup[0].error_threshold:0,127,255
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_initialize.p_setup[0].reset_threshold:0,127,255
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_initialize.p_setup[0].unused:0
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_initialize.p_setup[0].panic_rgba:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[80]:0,1,2,(3)3
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[81]:0x0,0x7FFFFF80,0xFFFFFF80
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[82]:0x1,0x7F7F0001,0xFFFF0001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[83]:1
TEST.END

-- Subprogram: iris_sigdrv_sig1_ldcfg_win0

-- Test Case: iris_sigdrv_sig1_ldcfg_win0.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_ldcfg_win0
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_ldcfg_win0.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[149]:1
TEST.END

-- Subprogram: iris_sigdrv_sig1_ldcfg_win1

-- Test Case: iris_sigdrv_sig1_ldcfg_win1.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_ldcfg_win1
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_ldcfg_win1.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x2
TEST.END

-- Subprogram: iris_sigdrv_sig1_ldcfg_win2

-- Test Case: iris_sigdrv_sig1_ldcfg_win2.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_ldcfg_win2
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_ldcfg_win2.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x4
TEST.END

-- Subprogram: iris_sigdrv_sig1_ldcfg_win3

-- Test Case: iris_sigdrv_sig1_ldcfg_win3.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_ldcfg_win3
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_ldcfg_win3.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x8
TEST.END

-- Subprogram: iris_sigdrv_sig1_ldcfg_win4

-- Test Case: iris_sigdrv_sig1_ldcfg_win4.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_ldcfg_win4
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_ldcfg_win4.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x10
TEST.END

-- Subprogram: iris_sigdrv_sig1_ldcfg_win5

-- Test Case: iris_sigdrv_sig1_ldcfg_win5.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_ldcfg_win5
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_ldcfg_win5.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x20
TEST.END

-- Subprogram: iris_sigdrv_sig1_ldcfg_win6

-- Test Case: iris_sigdrv_sig1_ldcfg_win6.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_ldcfg_win6
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_ldcfg_win6.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x40
TEST.END

-- Subprogram: iris_sigdrv_sig1_ldcfg_win7

-- Test Case: iris_sigdrv_sig1_ldcfg_win7.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_ldcfg_win7
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_ldcfg_win7.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[149]:0x80
TEST.END

-- Subprogram: iris_sigdrv_sig1_lock

-- Test Case: iris_sigdrv_sig1_lock.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_lock
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_lock.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[79]:0x5651F763
TEST.END

-- Subprogram: iris_sigdrv_sig1_setup_win0

-- Test Case: iris_sigdrv_sig1_setup_win0.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_setup_win0
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_setup_win0.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win0.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win0.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win0.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win0.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win0.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win0.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win0.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win0.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win0.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[86]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[87..88]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[89..91]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_setup_win1

-- Test Case: iris_sigdrv_sig1_setup_win1.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_setup_win1
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_setup_win1.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win1.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win1.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win1.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win1.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win1.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win1.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win1.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win1.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win1.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[95]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[96..97]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[98..100]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_setup_win2

-- Test Case: iris_sigdrv_sig1_setup_win2.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_setup_win2
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_setup_win2.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win2.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win2.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win2.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win2.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win2.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win2.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win2.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win2.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win2.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[104]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[105..106]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[107..109]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_setup_win3

-- Test Case: iris_sigdrv_sig1_setup_win3.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_setup_win3
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_setup_win3.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win3.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win3.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win3.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win3.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win3.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win3.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win3.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win3.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win3.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[113]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[114..115]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[116..118]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_setup_win4

-- Test Case: iris_sigdrv_sig1_setup_win4.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_setup_win4
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_setup_win4.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win4.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win4.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win4.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win4.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win4.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win4.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win4.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win4.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win4.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[122]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[123..124]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[125..127]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_setup_win5

-- Test Case: iris_sigdrv_sig1_setup_win5.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_setup_win5
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_setup_win5.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win5.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win5.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win5.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win5.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win5.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win5.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win5.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win5.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win5.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[131]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[132..133]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[134..136]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_setup_win6

-- Test Case: iris_sigdrv_sig1_setup_win6.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_setup_win6
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_setup_win6.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win6.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win6.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win6.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win6.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win6.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win6.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win6.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win6.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win6.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[140]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[141..142]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[143..145]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_setup_win7

-- Test Case: iris_sigdrv_sig1_setup_win7.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_setup_win7
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_setup_win7.001
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win7.p_swconf:<<malloc 1>>
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win7.p_swconf[0].control:0x0,0x1,0x2,0x3,0x4,0x7F,0xFF,0x1FF,0x3FF,0xFFFF,0x1FFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win7.p_swconf[0].winsx:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win7.p_swconf[0].winsy:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win7.p_swconf[0].winex:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win7.p_swconf[0].winey:0,32767,65535
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win7.p_swconf[0].crc_ref_r:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win7.p_swconf[0].crc_ref_g:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.VALUE:iris_sigdrv.iris_sigdrv_sig1_setup_win7.p_swconf[0].crc_ref_b:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[150]:0x0,0x1,0x2,0x3,0x0,(2)0x3,0x103,(2)0x303,(2)0x10303
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[151..152]:0x0,(2)0x3FFF3FFF
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[153..155]:0x0,0x7FFFFFFF,0xFFFFFFFF
TEST.END

-- Subprogram: iris_sigdrv_sig1_uninitialize

-- Test Case: iris_sigdrv_sig1_uninitialize.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_uninitialize
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_uninitialize.001
TEST.VALUE:iris_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0x0,0x100000
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[83]:0
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[84]:0x0,0x100000
TEST.END

-- Subprogram: iris_sigdrv_sig1_unlock

-- Test Case: iris_sigdrv_sig1_unlock.001
TEST.UNIT:iris_sigdrv
TEST.SUBPROGRAM:iris_sigdrv_sig1_unlock
TEST.NEW
TEST.NAME:iris_sigdrv_sig1_unlock.001
TEST.EXPECTED:iris_sigdrv.<<GLOBAL>>.uHardwareReg[79]:0x691DB936
TEST.END
