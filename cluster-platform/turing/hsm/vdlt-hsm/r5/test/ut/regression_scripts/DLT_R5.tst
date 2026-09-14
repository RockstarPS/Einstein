-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : DLT_R5
-- Unit(s) Under Test: vDLT_HSM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: vDLT_HSM

-- Subprogram: DltExt_Hsm_IpcAckEvent

-- Test Case: DltExt_Hsm_IpcAckEvent.001
TEST.UNIT:vDLT_HSM
TEST.SUBPROGRAM:DltExt_Hsm_IpcAckEvent
TEST.NEW
TEST.NAME:DltExt_Hsm_IpcAckEvent.001
TEST.VALUE:vDLT_HSM.DltExt_Hsm_IpcAckEvent.status:1
TEST.END

-- Test Case: DltExt_Hsm_IpcAckEvent.002
TEST.UNIT:vDLT_HSM
TEST.SUBPROGRAM:DltExt_Hsm_IpcAckEvent
TEST.NEW
TEST.NAME:DltExt_Hsm_IpcAckEvent.002
TEST.VALUE:vDLT_HSM.DltExt_Hsm_IpcAckEvent.status:0
TEST.END

-- Test Case: DltExt_Hsm_IpcAckEvent.003
TEST.UNIT:vDLT_HSM
TEST.SUBPROGRAM:DltExt_Hsm_IpcAckEvent
TEST.NEW
TEST.NAME:DltExt_Hsm_IpcAckEvent.003
TEST.VALUE:vDLT_HSM.DltExt_Hsm_IpcAckEvent.status:2
TEST.END

-- Subprogram: vDLTHSM_ClearBuffer

-- Test Case: vDLTHSM_ClearBuffer.001
TEST.UNIT:vDLT_HSM
TEST.SUBPROGRAM:vDLTHSM_ClearBuffer
TEST.NEW
TEST.NAME:vDLTHSM_ClearBuffer.001
TEST.VALUE:vDLT_HSM.vDLTHSM_ClearBuffer.status:1
TEST.EXPECTED:vDLT_HSM.vDLTHSM_ClearBuffer.status:1
TEST.END

-- Test Case: vDLTHSM_ClearBuffer.002
TEST.UNIT:vDLT_HSM
TEST.SUBPROGRAM:vDLTHSM_ClearBuffer
TEST.NEW
TEST.NAME:vDLTHSM_ClearBuffer.002
TEST.VALUE:vDLT_HSM.vDLTHSM_ClearBuffer.status:2
TEST.EXPECTED:vDLT_HSM.vDLTHSM_ClearBuffer.status:2
TEST.END

-- Test Case: vDLTHSM_ClearBuffer.003
TEST.UNIT:vDLT_HSM
TEST.SUBPROGRAM:vDLTHSM_ClearBuffer
TEST.NEW
TEST.NAME:vDLTHSM_ClearBuffer.003
TEST.VALUE:vDLT_HSM.vDLTHSM_ClearBuffer.status:1
TEST.VALUE:uut_prototype_stubs.vHsmCrypto_Command_SendData.s_vHsm_Commanddata.payLoadPtr_U8P:<<null>>
TEST.VALUE:uut_prototype_stubs.vHsmCrypto_Command_SendData.return:1
TEST.EXPECTED:vDLT_HSM.vDLTHSM_ClearBuffer.status:1
TEST.END

-- Subprogram: vDLTHSM_NotifyDltExt

-- Test Case: vDLTHSM_NotifyDltExt.001
TEST.UNIT:vDLT_HSM
TEST.SUBPROGRAM:vDLTHSM_NotifyDltExt
TEST.NEW
TEST.NAME:vDLTHSM_NotifyDltExt.001
TEST.VALUE:vDLT_HSM.vDLTHSM_NotifyDltExt.commanddata_addr:<<malloc 1>>
TEST.VALUE:vDLT_HSM.vDLTHSM_NotifyDltExt.commanddata_addr[0]:5
TEST.END

-- Test Case: vDLTHSM_NotifyDltExt.002
TEST.UNIT:vDLT_HSM
TEST.SUBPROGRAM:vDLTHSM_NotifyDltExt
TEST.NEW
TEST.NAME:vDLTHSM_NotifyDltExt.002
TEST.VALUE:vDLT_HSM.vDLTHSM_NotifyDltExt.commanddata_addr:<<malloc 1>>
TEST.VALUE:vDLT_HSM.vDLTHSM_NotifyDltExt.commanddata_addr[0]:10
TEST.END

-- Test Case: vDLTHSM_NotifyDltExt.003
TEST.UNIT:vDLT_HSM
TEST.SUBPROGRAM:vDLTHSM_NotifyDltExt
TEST.NEW
TEST.NAME:vDLTHSM_NotifyDltExt.003
TEST.VALUE:vDLT_HSM.vDLTHSM_NotifyDltExt.commanddata_addr:<<malloc 1>>
TEST.VALUE:vDLT_HSM.vDLTHSM_NotifyDltExt.commanddata_addr[0]:6
TEST.END
