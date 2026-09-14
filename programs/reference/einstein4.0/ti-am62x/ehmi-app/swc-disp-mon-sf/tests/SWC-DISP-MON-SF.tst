-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : SWC-DISP-MON-SF
-- Unit(s) Under Test: SafeTTCRCMonitoring SwcDispMonSf
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: SafeTTCRCMonitoring

-- Subprogram: processSafeTTCRC

-- Test Case: processSafeTTCRC.001
TEST.UNIT:SafeTTCRCMonitoring
TEST.SUBPROGRAM:processSafeTTCRC
TEST.NEW
TEST.NAME:processSafeTTCRC.001
TEST.NOTES:
Requirement_BMIC29130-29082
TEST.END_NOTES:
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:0
TEST.END

-- Test Case: processSafeTTCRC.002
TEST.UNIT:SafeTTCRCMonitoring
TEST.SUBPROGRAM:processSafeTTCRC
TEST.NEW
TEST.NAME:processSafeTTCRC.002
TEST.NOTES:
Requirement_BMIC29130-11027_BMIC29130-11027
TEST.END_NOTES:
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:1
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:3385683673
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:1
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0
TEST.END

-- Test Case: processSafeTTCRC.003
TEST.UNIT:SafeTTCRCMonitoring
TEST.SUBPROGRAM:processSafeTTCRC
TEST.NEW
TEST.NAME:processSafeTTCRC.003
TEST.NOTES:
Requirement_BMIC29130-11027_BMIC29130-11027
TEST.END_NOTES:
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:2
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:1688917312
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:2
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0
TEST.END

-- Test Case: processSafeTTCRC.004
TEST.UNIT:SafeTTCRCMonitoring
TEST.SUBPROGRAM:processSafeTTCRC
TEST.NEW
TEST.NAME:processSafeTTCRC.004
TEST.NOTES:
Requirement_BMIC29130-11041_Requirement_BMIC29130-29078
TEST.END_NOTES:
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:15
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:15
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:0
TEST.END

-- Test Case: processSafeTTCRC.005
TEST.UNIT:SafeTTCRCMonitoring
TEST.SUBPROGRAM:processSafeTTCRC
TEST.NEW
TEST.NAME:processSafeTTCRC.005
TEST.NOTES:
Requirement_BMIC29130-29078
TEST.END_NOTES:
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:15
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:1
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:3385683673
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:1
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0
TEST.END

-- Test Case: processSafeTTCRC.006
TEST.UNIT:SafeTTCRCMonitoring
TEST.SUBPROGRAM:processSafeTTCRC
TEST.NEW
TEST.NAME:processSafeTTCRC.006
TEST.NOTES:
Requirement_BMIC29130-29078
TEST.END_NOTES:
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:15
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:2
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:1688917312
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:2
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0
TEST.END

-- Test Case: processSafeTTCRC.008
TEST.UNIT:SafeTTCRCMonitoring
TEST.SUBPROGRAM:processSafeTTCRC
TEST.NEW
TEST.NAME:processSafeTTCRC.008
TEST.NOTES:
Requirement_BMIC29130-19878_BMIC29130-11041_BMIC29130-11037_BMIC29130-29089_BMIC29130-29084_BMIC29130-29080
TEST.END_NOTES:
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:14
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:2
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:1
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:14
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:1
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:2
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0
TEST.END

-- Test Case: processSafeTTCRC.009
TEST.UNIT:SafeTTCRCMonitoring
TEST.SUBPROGRAM:processSafeTTCRC
TEST.NEW
TEST.NAME:processSafeTTCRC.009
TEST.NOTES:
Requirement_BMIC29130-19878_BMIC29130-11041_BMIC29130-11037_BMIC29130-29089_BMIC29130-29084_BMIC29130-29080
TEST.END_NOTES:
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:14
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:1
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:1
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:14
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:1
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:1
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0
TEST.END

-- Test Case: processSafeTTCRC.011
TEST.UNIT:SafeTTCRCMonitoring
TEST.SUBPROGRAM:processSafeTTCRC
TEST.NEW
TEST.NAME:processSafeTTCRC.011
TEST.NOTES:
Requirement_BMIC29130-29084
TEST.END_NOTES:
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:2
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:1
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:1
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:2
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0
TEST.END

-- Test Case: processSafeTTCRC.012
TEST.UNIT:SafeTTCRCMonitoring
TEST.SUBPROGRAM:processSafeTTCRC
TEST.NEW
TEST.NAME:processSafeTTCRC.012
TEST.NOTES:
Requirement_BMIC29130-29084
TEST.END_NOTES:
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:1
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:1
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:1
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:1
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.EXPECTED:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:0
TEST.END

-- Test Case: processSafeTTCRC.014
TEST.UNIT:SafeTTCRCMonitoring
TEST.SUBPROGRAM:processSafeTTCRC
TEST.NEW
TEST.NAME:processSafeTTCRC.014
TEST.NOTES:
Branching coverage
TEST.END_NOTES:
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.VALUE:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:3
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:uut_prototype_stubs.CSigCdd_Impl_sig_get_win_crc_data.p_sw_crc_rgb[0].crc:1
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.u8DebounceTimer:1
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcDispMonSf_pp_AbsTTDispStatus_absTelltaleStatus:0
TEST.EXPECTED:SafeTTCRCMonitoring.<<GLOBAL>>.Rte_CSwcSafeTT_pp_DispMonSfAbsTTStatus_absTelltaleStatus:3
TEST.END

-- Unit: SwcDispMonSf

-- Subprogram: CSwcDispMonSf_Impl_MainFunction

-- Test Case: CSwcDispMonSf_Impl_MainFunction.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CSwcDispMonSf_Impl_MainFunction
TEST.NEW
TEST.NAME:CSwcDispMonSf_Impl_MainFunction.001
TEST.END

-- Test Case: CSwcDispMonSf_Impl_MainFunction.001.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CSwcDispMonSf_Impl_MainFunction
TEST.NEW
TEST.NAME:CSwcDispMonSf_Impl_MainFunction.001.001
TEST.END

-- Subprogram: CSwcDispMonSf_Impl_OnCommand

-- Test Case: CSwcDispMonSf_Impl_OnCommand.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CSwcDispMonSf_Impl_OnCommand
TEST.NEW
TEST.NAME:CSwcDispMonSf_Impl_OnCommand.001
TEST.END

-- Test Case: CSwcDispMonSf_Impl_OnCommand.001.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CSwcDispMonSf_Impl_OnCommand
TEST.NEW
TEST.NAME:CSwcDispMonSf_Impl_OnCommand.001.001
TEST.END

-- Subprogram: CmpActivation

-- Test Case: CmpActivation.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation.001
TEST.END

-- Test Case: CmpActivation.001.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation.001.001
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.001
TEST.NOTES:
Requirement_BMIC29130-11025
TEST.END_NOTES:
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.001
TEST.END

-- Test Case: CmpDeActivation.001.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.001.001
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit.001
TEST.END

-- Test Case: CmpDeInit.001.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit.001.001
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.001
TEST.END

-- Test Case: CmpDiag.001.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.001.001
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.001
TEST.END

-- Test Case: CmpDiagReturn.001.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.001.001
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.001
TEST.END

-- Test Case: CmpInit.001.001
TEST.UNIT:SwcDispMonSf
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.001.001
TEST.END
