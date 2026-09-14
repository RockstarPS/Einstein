-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : SIGCDD_IF_INFINEON_UT
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

-- Test Case: SigIf_sig_deinit_FAILURE
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_deinit
TEST.NEW
TEST.NAME:SigIf_sig_deinit_FAILURE
TEST.VALUE:uut_prototype_stubs.CyFssig_DrvDeInit.return:CYFSSIG_NOT_OK
TEST.END

-- Test Case: SigIf_sig_deinit_SUCCESS
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_deinit
TEST.NEW
TEST.NAME:SigIf_sig_deinit_SUCCESS
TEST.VALUE:uut_prototype_stubs.CyFssig_DrvDeInit.return:CYFSSIG_OK
TEST.END

-- Subprogram: SigIf_sig_driver_commit

-- Test Case: SigIf_sig_driver_commit.001
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_driver_commit
TEST.NEW
TEST.NAME:SigIf_sig_driver_commit.001
TEST.VALUE:SigIfCdd.SigIf_sig_driver_commit.p_sig_unit:0
TEST.VALUE:uut_prototype_stubs.CyFssig_DrvCommit.return:CYFSSIG_OK
TEST.EXPECTED:SigIfCdd.SigIf_sig_driver_commit.return:0
TEST.EXPECTED:uut_prototype_stubs.CyFssig_DrvCommit.commitGroupFlags:1
TEST.END

-- Test Case: SigIf_sig_driver_commit.002
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_driver_commit
TEST.NEW
TEST.NAME:SigIf_sig_driver_commit.002
TEST.VALUE:SigIfCdd.SigIf_sig_driver_commit.p_sig_unit:0
TEST.VALUE:uut_prototype_stubs.CyFssig_DrvGetCommitStatus.return:CYFSSIG_NOT_OK
TEST.EXPECTED:SigIfCdd.SigIf_sig_driver_commit.return:0
TEST.END

-- Subprogram: SigIf_sig_get_win_crc_data

-- Test Case: SigIf_sig_get_win_crc_data_S0W0
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data_S0W0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.winId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.calSignaturePtr[0].sigRed:0xFFFF0000
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.calSignaturePtr[0].sigGreen:0xFF00FF00
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.calSignaturePtr[0].sigBlue:0xFF0000FF
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.return:CYFSSIG_OK
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0xFFFF0000
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0xFF00FF00
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0xFF0000FF
TEST.END

-- Test Case: SigIf_sig_get_win_crc_data_S0W1
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_crc_data
TEST.NEW
TEST.NAME:SigIf_sig_get_win_crc_data_S0W1
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_info[0].window:1
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.winId:1
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.calSignaturePtr[0].sigRed:0xFF000000
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.calSignaturePtr[0].sigGreen:0xFF00FF00
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.calSignaturePtr[0].sigBlue:0xFF0000FF
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetWinCalSignature.return:CYFSSIG_OK
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_r:0xFF000000
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_g:0xFF00FF00
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_crc_data.p_sw_crc_rgb[0].crc_b:0xFF0000FF
TEST.END

-- Subprogram: SigIf_sig_get_win_status

-- Test Case: SigIf_sig_get_win_status_EVAL_CALCULATING
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status_EVAL_CALCULATING
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:3
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[0..1]:CYFSSIG_SIG_EVAL_DONE
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[2]:CYFSSIG_SIG_EVAL_DISABLED
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[3]:CYFSSIG_SIG_EVAL_CALCULATING
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[4..7]:CYFSSIG_SIG_EVAL_DONE
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[0]:CYFSSIG_SIG_SIGNATURE_NO_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[1]:CYFSSIG_SIG_SIGNATURE_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[2..7]:CYFSSIG_SIG_SIGNATURE_NO_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.return:CYFSSIG_OK
TEST.END

-- Test Case: SigIf_sig_get_win_status_EVAL_DISABLED
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status_EVAL_DISABLED
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:3
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[0..2]:CYFSSIG_SIG_EVAL_DONE
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[3]:CYFSSIG_SIG_EVAL_DISABLED
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[4..7]:CYFSSIG_SIG_EVAL_DONE
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[0]:CYFSSIG_SIG_SIGNATURE_NO_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[1]:CYFSSIG_SIG_SIGNATURE_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[2..7]:CYFSSIG_SIG_SIGNATURE_NO_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.return:CYFSSIG_OK
TEST.END

-- Test Case: SigIf_sig_get_win_status_NO_VIOLATION
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status_NO_VIOLATION
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[0..7]:CYFSSIG_SIG_EVAL_DONE
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[0..7]:CYFSSIG_SIG_SIGNATURE_NO_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.return:CYFSSIG_OK
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_win_status_VIOLATION
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_win_status
TEST.NEW
TEST.NAME:SigIf_sig_get_win_status_VIOLATION
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_get_win_status.p_sw_info[0].window:1
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[0..7]:CYFSSIG_SIG_EVAL_DONE
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[0]:CYFSSIG_SIG_SIGNATURE_NO_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[1]:CYFSSIG_SIG_SIGNATURE_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[2..7]:CYFSSIG_SIG_SIGNATURE_NO_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.return:CYFSSIG_OK
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_win_status.return:1
TEST.END

-- Subprogram: SigIf_sig_get_windows_status

-- Test Case: SigIf_sig_get_windows_status_EVAL_NOT_DONE
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_windows_status
TEST.NEW
TEST.NAME:SigIf_sig_get_windows_status_EVAL_NOT_DONE
TEST.VALUE:SigIfCdd.SigIf_sig_get_windows_status.p_sig_unit:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[0]:CYFSSIG_SIG_EVAL_DISABLED
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[1..7]:CYFSSIG_SIG_EVAL_DONE
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[0..7]:CYFSSIG_SIG_SIGNATURE_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.return:CYFSSIG_OK
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_windows_status.return:0xFE
TEST.END

-- Test Case: SigIf_sig_get_windows_status_NO_VIOLATION
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_windows_status
TEST.NEW
TEST.NAME:SigIf_sig_get_windows_status_NO_VIOLATION
TEST.VALUE:SigIfCdd.SigIf_sig_get_windows_status.p_sig_unit:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[0..7]:CYFSSIG_SIG_EVAL_DONE
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[0..7]:CYFSSIG_SIG_SIGNATURE_NO_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.return:CYFSSIG_OK
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_windows_status.return:0
TEST.END

-- Test Case: SigIf_sig_get_windows_status_VIOLATION
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_get_windows_status
TEST.NEW
TEST.NAME:SigIf_sig_get_windows_status_VIOLATION
TEST.VALUE:SigIfCdd.SigIf_sig_get_windows_status.p_sig_unit:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].evaluationState[0..7]:CYFSSIG_SIG_EVAL_DONE
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.sigStatusPtr[0].signatureResult[0..7]:CYFSSIG_SIG_SIGNATURE_VIOLATION
TEST.VALUE:uut_prototype_stubs.CyFssig_SigGetEvaluationStatus.return:CYFSSIG_OK
TEST.EXPECTED:SigIfCdd.SigIf_sig_get_windows_status.return:0xFF
TEST.END

-- Subprogram: SigIf_sig_init

-- Test Case: SigIf_sig_init_INIT_FAILURE
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_init
TEST.NEW
TEST.NAME:SigIf_sig_init_INIT_FAILURE
TEST.VALUE:uut_prototype_stubs.CyFssig_DrvInit.return:CYFSSIG_OK
TEST.END

-- Test Case: SigIf_sig_init_INIT_SUCCESS
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_init
TEST.NEW
TEST.NAME:SigIf_sig_init_INIT_SUCCESS
TEST.VALUE:uut_prototype_stubs.CyFssig_DrvInit.return:CYFSSIG_OK
TEST.END

-- Subprogram: SigIf_sig_set_ev_window

-- Test Case: SigIf_sig_set_ev_window_ENABLE_ALPHAMASK_S0W4
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:SigIf_sig_set_ev_window_ENABLE_ALPHAMASK_S0W4
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0x100
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:10
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:10
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:4
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinAlphaMaskMode.return:CYFSSIG_OK
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinPosition.return:CYFSSIG_OK
TEST.EXPECTED:SigIfCdd.SigIf_sig_set_ev_window.return:E_OK_t
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinAlphaMaskMode.dispId:0
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinAlphaMaskMode.winId:4
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinAlphaMaskMode.alphaMaskEnabled:1
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.dispId:0
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winId:4
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].topLeftX:0
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].topLeftY:0
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].width:10
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].height:10
TEST.END

-- Test Case: SigIf_sig_set_ev_window_ENABLE_CRC_S0W1
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:SigIf_sig_set_ev_window_ENABLE_CRC_S0W1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:1
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:10
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:10
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:1
TEST.EXPECTED:SigIfCdd.SigIf_sig_set_ev_window.return:E_OK_t
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.dispId:0
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winId:1
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].topLeftX:0
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].topLeftY:0
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].width:10
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].height:10
TEST.END

-- Test Case: SigIf_sig_set_ev_window_INVALID_HEIGHT_S0W3
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:SigIf_sig_set_ev_window_INVALID_HEIGHT_S0W3
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:12
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:100
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].crc_ref_r:0xFF00FF00
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].crc_ref_g:0xFF00FF00
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].crc_ref_b:0xFF00FF00
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:2
TEST.EXPECTED:SigIfCdd.SigIf_sig_set_ev_window.return:E_OK_t
TEST.END

-- Test Case: SigIf_sig_set_ev_window_INVALID_WIDTH_S0W2
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:SigIf_sig_set_ev_window_INVALID_WIDTH_S0W2
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].crc_ref_r:0xFF00FF00
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].crc_ref_g:0xFF00FF00
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].crc_ref_b:0xFF00FF00
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:2
TEST.EXPECTED:SigIfCdd.SigIf_sig_set_ev_window.return:E_OK_t
TEST.END

-- Test Case: SigIf_sig_set_ev_window_VALID_S0W0
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_set_ev_window
TEST.NEW
TEST.NAME:SigIf_sig_set_ev_window_VALID_S0W0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].control:0xFFFF
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsx:20
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winsy:20
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winex:60
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.EvWindow[0].winey:60
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_set_ev_window.p_window:0
TEST.EXPECTED:SigIfCdd.SigIf_sig_set_ev_window.return:E_OK_t
TEST.END

-- Subprogram: SigIf_sig_setup_win

-- Test Case: SigIf_sig_setup_win_INVALID_WIN
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win_INVALID_WIN
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].control:0xFFFF
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winsx:10
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winsy:10
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winex:30
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winey:30
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].crc_ref_r:0xAABBCCDD
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].crc_ref_g:0xAACCBBDD
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].crc_ref_b:0xAADDCCBB
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:9
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinPosition.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinPosition.winId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.winId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.refSignaturePtr[0].sigRed:0xAABBCCDD
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.refSignaturePtr[0].sigGreen:0xAACCBBDD
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.refSignaturePtr[0].sigBlue:0xAADDCCBB
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].topLeftX:10
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].topLeftY:10
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].width:20
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].height:20
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.dispId:0
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.winId:9
TEST.END

-- Test Case: SigIf_sig_setup_win_VALID
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_setup_win
TEST.NEW
TEST.NAME:SigIf_sig_setup_win_VALID
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf:<<malloc 1>>
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].control:0xFFFF
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winsx:10
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winsy:10
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winex:30
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].winey:30
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].crc_ref_r:0xAABBCCDD
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].crc_ref_g:0xAACCBBDD
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_swconf[0].crc_ref_b:0xAADDCCBB
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_sig_unit:0
TEST.VALUE:SigIfCdd.SigIf_sig_setup_win.p_window:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinPosition.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinPosition.winId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.dispId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.winId:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.refSignaturePtr[0].sigRed:0xAABBCCDD
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.refSignaturePtr[0].sigGreen:0xAACCBBDD
TEST.VALUE:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.refSignaturePtr[0].sigBlue:0xAADDCCBB
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].topLeftX:10
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].topLeftY:10
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].width:20
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinPosition.winPositionPtr[0].height:20
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.dispId:0
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigSetWinRefSignature.winId:0
TEST.END

-- Subprogram: SigIf_sig_stop_evaluation

-- Test Case: SigIf_sig_stop_evaluation.001
TEST.UNIT:SigIfCdd
TEST.SUBPROGRAM:SigIf_sig_stop_evaluation
TEST.NEW
TEST.NAME:SigIf_sig_stop_evaluation.001
TEST.VALUE:SigIfCdd.SigIf_sig_stop_evaluation.p_sig_unit:0
TEST.VALUE:uut_prototype_stubs.CyFssig_SigDisableWinEvaluation.return:CYFSSIG_OK
TEST.EXPECTED:uut_prototype_stubs.CyFssig_SigDisableWinEvaluation.dispId:0
TEST.END
