-- VectorCAST 6.4s (05/01/17)
-- Test Case Script
-- 
-- Environment    : SIGCDD_CDD_UT_VCAST_HT
-- Unit(s) Under Test: SigCdd
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: CSigCdd_Impl_sig_get_win_crc_data

-- Test Case: CSigCdd_Impl_sig_get_win_crc_data.001
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CSigCdd_Impl_sig_get_win_crc_data
TEST.NEW
TEST.NAME:CSigCdd_Impl_sig_get_win_crc_data.001
TEST.VALUE:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0
TEST.VALUE:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0
TEST.VALUE:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0
TEST.EXPECTED:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0x0
TEST.EXPECTED:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0x0
TEST.EXPECTED:SigCdd.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0x0
TEST.END

-- Subprogram: CmpActivation

-- Test Case: CmpActivation.001
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation.001
TEST.EXPECTED:SigCdd.CmpActivation.return:1
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.001
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.001
TEST.EXPECTED:SigCdd.CmpActive.return:1
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation.001
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.001
TEST.EXPECTED:SigCdd.CmpDeActivation.return:1
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit.001
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit.001
TEST.EXPECTED:SigCdd.CmpDeInit.return:1
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag.001
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.001
TEST.EXPECTED:SigCdd.CmpDiag.return:1
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn.001
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.001
TEST.EXPECTED:SigCdd.CmpDiagReturn.return:1
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit.001
TEST.UNIT:SigCdd
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.001
TEST.EXPECTED:SigCdd.CmpInit.return:1
TEST.END
