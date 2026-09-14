-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_UPDATEMAN
-- Unit(s) Under Test: UPDi_UpdateMan
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UPDi_UpdateMan

-- Subprogram: UPDUpdateMan_Activate

-- Test Case: UPDUpdateMan_Activate.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Activate
TEST.NEW
TEST.NAME:UPDUpdateMan_Activate.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.END

-- Test Case: UPDUpdateMan_Activate.002
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Activate
TEST.NEW
TEST.NAME:UPDUpdateMan_Activate.002
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.END

-- Test Case: UPDUpdateMan_Activate.003
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Activate
TEST.NEW
TEST.NAME:UPDUpdateMan_Activate.003
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.END

-- Test Case: UPDUpdateMan_Activate.004
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Activate
TEST.NEW
TEST.NAME:UPDUpdateMan_Activate.004
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.END

-- Test Case: UPDUpdateMan_Activate.005
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Activate
TEST.NEW
TEST.NAME:UPDUpdateMan_Activate.005
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.END

-- Test Case: UPDUpdateMan_Activate.006
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Activate
TEST.NEW
TEST.NAME:UPDUpdateMan_Activate.006
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.END

-- Test Case: UPDUpdateMan_Activate.007
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Activate
TEST.NEW
TEST.NAME:UPDUpdateMan_Activate.007
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.END

-- Test Case: UPDUpdateMan_Activate.008
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Activate
TEST.NEW
TEST.NAME:UPDUpdateMan_Activate.008
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Activate.return:0
TEST.END

-- Subprogram: UPDUpdateMan_BootSuccess

-- Test Case: UPDUpdateMan_BootSuccess.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_BootSuccess
TEST.NEW
TEST.NAME:UPDUpdateMan_BootSuccess.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_BootSuccess.return:1
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_BootSuccess.return:1
TEST.END

-- Subprogram: UPDUpdateMan_GetBank

-- Test Case: UPDUpdateMan_GetBank.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_GetBank
TEST.NEW
TEST.NAME:UPDUpdateMan_GetBank.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_GetBank.return:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_GetBank.return:eUPDiUpdate_BankActive
TEST.END

-- Test Case: UPDUpdateMan_GetBank.002
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_GetBank
TEST.NEW
TEST.NAME:UPDUpdateMan_GetBank.002
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_GetBank.return:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_GetBank.return:eUPDiUpdate_BankActive
TEST.END

-- Subprogram: UPDUpdateMan_GetState

-- Test Case: UPDUpdateMan_GetState.002
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_GetState
TEST.NEW
TEST.NAME:UPDUpdateMan_GetState.002
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 1>>
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_GetState.SessionID:<<malloc 1>>
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_GetState.SessionID[0]:1
TEST.VALUE:uut_prototype_stubs.UPDTarget_GetState.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE:uut_prototype_stubs.UPDTarget_GetState.return:eUPDiTarget_UninstFailed
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_GetState.SessionID[0]:1
TEST.EXPECTED:uut_prototype_stubs.UPDTarget_GetState.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE_USER_CODE:UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].Target
<<UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd>>.Sessions[0].Target = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDUpdateMan_GetUPDatedBank

-- Test Case: UPDUpdateMan_GetUPDatedBank.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_GetUPDatedBank
TEST.NEW
TEST.NAME:UPDUpdateMan_GetUPDatedBank.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_GetUPDatedBank.return:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_GetUPDatedBank.return:eUPDiUpdate_BankActive
TEST.END

-- Subprogram: UPDUpdateMan_GetUpdateBankType

-- Test Case: UPDUpdateMan_GetUpdateBankType.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_GetUpdateBankType
TEST.NEW
TEST.NAME:UPDUpdateMan_GetUpdateBankType.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_GetUpdateBankType.return:eUPDiUpdate_BankInvalid
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_GetUpdateBankType.return:eUPDiUpdate_BankInvalid
TEST.END

-- Subprogram: UPDUpdateMan_Init

-- Test Case: UPDUpdateMan_Init.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Init
TEST.NEW
TEST.NAME:UPDUpdateMan_Init.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Init.return:1
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Init.return:1
TEST.END

-- Subprogram: UPDUpdateMan_IsActivatePossible

-- Test Case: UPDUpdateMan_IsActivatePossible.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_IsActivatePossible
TEST.NEW
TEST.NAME:UPDUpdateMan_IsActivatePossible.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_IsActivatePossible.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_IsActivatePossible.return:0
TEST.END

-- Test Case: UPDUpdateMan_IsActivatePossible.002
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_IsActivatePossible
TEST.NEW
TEST.NAME:UPDUpdateMan_IsActivatePossible.002
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd.TargetsCount:0
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarget100.Ram:<<malloc 1>>
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarget100.Ram[0].State:eUPDiTarget_Uninstalled
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarRam.State:eUPDiTarget_Uninstalled
TEST.EXPECTED:UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd.TargetsCount:0
TEST.EXPECTED:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarget100.Ram[0].State:eUPDiTarget_Uninstalled
TEST.EXPECTED:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarRam.State:eUPDiTarget_Uninstalled
TEST.VALUE_USER_CODE:UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd.Targets
<<UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd>>.Targets = ( &sUPDiTarget100 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDUpdateMan_IsActivatePossible.004
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_IsActivatePossible
TEST.NEW
TEST.NAME:UPDUpdateMan_IsActivatePossible.004
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd.TargetsCount:1
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarget100.Ram:<<malloc 1>>
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarget100.Ram[0].State:eUPDiTarget_Uninstalled
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarRam.State:eUPDiTarget_Uninstalled
TEST.EXPECTED:UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd.TargetsCount:1
TEST.EXPECTED:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarget100.Ram[0].State:eUPDiTarget_Uninstalled
TEST.EXPECTED:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarRam.State:eUPDiTarget_Uninstalled
TEST.VALUE_USER_CODE:UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd.Targets
<<UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd>>.Targets = ( &updatemanTargets );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDUpdateMan_IsActivatePossible.005
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_IsActivatePossible
TEST.NEW
TEST.NAME:UPDUpdateMan_IsActivatePossible.005
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd.TargetsCount:1
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarget100.Ram:<<malloc 1>>
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarget100.Ram[0].State:eUPDiTarget_UninstErasing
TEST.VALUE:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarRam.State:eUPDiTarget_Uninstalled
TEST.EXPECTED:UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd.TargetsCount:1
TEST.EXPECTED:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarget100.Ram[0].State:eUPDiTarget_UninstErasing
TEST.EXPECTED:UPDi_UpdateMan.<<GLOBAL>>.sUPDiTarRam.State:eUPDiTarget_Uninstalled
TEST.VALUE_USER_CODE:UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd.Targets
<<UPDi_UpdateMan.<<GLOBAL>>.oUPDCdd>>.Targets = ( &updatemanTargets );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDUpdateMan_Rollback

-- Test Case: UPDUpdateMan_Rollback.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Rollback
TEST.NEW
TEST.NAME:UPDUpdateMan_Rollback.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.END

-- Test Case: UPDUpdateMan_Rollback.002
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Rollback
TEST.NEW
TEST.NAME:UPDUpdateMan_Rollback.002
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.END

-- Test Case: UPDUpdateMan_Rollback.003
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Rollback
TEST.NEW
TEST.NAME:UPDUpdateMan_Rollback.003
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.END

-- Test Case: UPDUpdateMan_Rollback.004
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Rollback
TEST.NEW
TEST.NAME:UPDUpdateMan_Rollback.004
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.END

-- Test Case: UPDUpdateMan_Rollback.005
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Rollback
TEST.NEW
TEST.NAME:UPDUpdateMan_Rollback.005
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.END

-- Test Case: UPDUpdateMan_Rollback.006
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Rollback
TEST.NEW
TEST.NAME:UPDUpdateMan_Rollback.006
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.END

-- Test Case: UPDUpdateMan_Rollback.007
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Rollback
TEST.NEW
TEST.NAME:UPDUpdateMan_Rollback.007
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Rollback.return:1
TEST.END

-- Subprogram: UPDUpdateMan_SetState

-- Test Case: UPDUpdateMan_SetState.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_SetState
TEST.NEW
TEST.NAME:UPDUpdateMan_SetState.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_SetState.lState:eUPDiUpdate_Idle
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_SetState.lState:eUPDiUpdate_Idle
TEST.END

-- Subprogram: UPDUpdateMan_StartUPDate

-- Test Case: UPDUpdateMan_StartUPDate.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_StartUPDate
TEST.NEW
TEST.NAME:UPDUpdateMan_StartUPDate.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.return:0
TEST.END

-- Test Case: UPDUpdateMan_StartUPDate.002
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_StartUPDate
TEST.NEW
TEST.NAME:UPDUpdateMan_StartUPDate.002
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.return:0
TEST.END

-- Test Case: UPDUpdateMan_StartUPDate.003
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_StartUPDate
TEST.NEW
TEST.NAME:UPDUpdateMan_StartUPDate.003
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.Bank:eUPDiUpdate_BankActive
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.Bank:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.return:0
TEST.END

-- Test Case: UPDUpdateMan_StartUPDate.004
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_StartUPDate
TEST.NEW
TEST.NAME:UPDUpdateMan_StartUPDate.004
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.Bank:eUPDiUpdate_BankActive
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.Bank:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.return:0
TEST.END

-- Test Case: UPDUpdateMan_StartUPDate.005
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_StartUPDate
TEST.NEW
TEST.NAME:UPDUpdateMan_StartUPDate.005
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_StartUPDate.return:0
TEST.END

-- Subprogram: UPDUpdateMan_Task

-- Test Case: UPDUpdateMan_Task.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Task
TEST.NEW
TEST.NAME:UPDUpdateMan_Task.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.END

-- Test Case: UPDUpdateMan_Task.002
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Task
TEST.NEW
TEST.NAME:UPDUpdateMan_Task.002
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.END

-- Test Case: UPDUpdateMan_Task.003
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Task
TEST.NEW
TEST.NAME:UPDUpdateMan_Task.003
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.END

-- Test Case: UPDUpdateMan_Task.004
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Task
TEST.NEW
TEST.NAME:UPDUpdateMan_Task.004
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.END

-- Test Case: UPDUpdateMan_Task.005
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Task
TEST.NEW
TEST.NAME:UPDUpdateMan_Task.005
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.END

-- Test Case: UPDUpdateMan_Task.006
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Task
TEST.NEW
TEST.NAME:UPDUpdateMan_Task.006
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.END

-- Test Case: UPDUpdateMan_Task.007
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Task
TEST.NEW
TEST.NAME:UPDUpdateMan_Task.007
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.END

-- Test Case: UPDUpdateMan_Task.008
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Task
TEST.NEW
TEST.NAME:UPDUpdateMan_Task.008
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.END

-- Test Case: UPDUpdateMan_Task.009
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Task
TEST.NEW
TEST.NAME:UPDUpdateMan_Task.009
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Task.return:0
TEST.END

-- Subprogram: UPDUpdateMan_Terminate

-- Test Case: UPDUpdateMan_Terminate.001
TEST.UNIT:UPDi_UpdateMan
TEST.SUBPROGRAM:UPDUpdateMan_Terminate
TEST.NEW
TEST.NAME:UPDUpdateMan_Terminate.001
TEST.VALUE:UPDi_UpdateMan.UPDUpdateMan_Terminate.return:1
TEST.EXPECTED:UPDi_UpdateMan.UPDUpdateMan_Terminate.return:1
TEST.END
