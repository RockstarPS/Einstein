-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_UPDATECDD
-- Unit(s) Under Test: UPDi_UpdateCdd
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: UPDUpdateCdd_GetManifest

-- Test Case: UPDUpdateCdd_GetManifest.001
TEST.UNIT:UPDi_UpdateCdd
TEST.SUBPROGRAM:UPDUpdateCdd_GetManifest
TEST.NEW
TEST.NAME:UPDUpdateCdd_GetManifest.001
TEST.VALUE:UPDi_UpdateCdd.UPDUpdateCdd_GetManifest.return:0
TEST.EXPECTED:UPDi_UpdateCdd.UPDUpdateCdd_GetManifest.return:0
TEST.END

-- Subprogram: UPDUpdateCdd_GetSession

-- Test Case: UPDUpdateCdd_GetSession.001
TEST.UNIT:UPDi_UpdateCdd
TEST.SUBPROGRAM:UPDUpdateCdd_GetSession
TEST.NEW
TEST.NAME:UPDUpdateCdd_GetSession.001
TEST.VALUE:UPDi_UpdateCdd.UPDUpdateCdd_GetSession.Index:0
TEST.EXPECTED:UPDi_UpdateCdd.UPDUpdateCdd_GetSession.Index:0
TEST.END

-- Subprogram: UPDUpdateCdd_GetSessionCount

-- Test Case: UPDUpdateCdd_GetSessionCount.001
TEST.UNIT:UPDi_UpdateCdd
TEST.SUBPROGRAM:UPDUpdateCdd_GetSessionCount
TEST.NEW
TEST.NAME:UPDUpdateCdd_GetSessionCount.001
TEST.VALUE:UPDi_UpdateCdd.UPDUpdateCdd_GetSessionCount.return:0
TEST.EXPECTED:UPDi_UpdateCdd.UPDUpdateCdd_GetSessionCount.return:0
TEST.END

-- Subprogram: UPDUpdateCdd_GetTarget

-- Test Case: UPDUpdateCdd_GetTarget.001
TEST.UNIT:UPDi_UpdateCdd
TEST.SUBPROGRAM:UPDUpdateCdd_GetTarget
TEST.NEW
TEST.NAME:UPDUpdateCdd_GetTarget.001
TEST.VALUE:UPDi_UpdateCdd.UPDUpdateCdd_GetTarget.Index:0
TEST.EXPECTED:UPDi_UpdateCdd.UPDUpdateCdd_GetTarget.Index:0
TEST.END

-- Subprogram: UPDUpdateCdd_GetTargetCount

-- Test Case: UPDUpdateCdd_GetTargetCount.001
TEST.UNIT:UPDi_UpdateCdd
TEST.SUBPROGRAM:UPDUpdateCdd_GetTargetCount
TEST.NEW
TEST.NAME:UPDUpdateCdd_GetTargetCount.001
TEST.VALUE:UPDi_UpdateCdd.UPDUpdateCdd_GetTargetCount.return:0
TEST.EXPECTED:UPDi_UpdateCdd.UPDUpdateCdd_GetTargetCount.return:0
TEST.END

-- Subprogram: UPDUpdateCdd_GetTargetState

-- Test Case: UPDUpdateCdd_GetTargetState.001
TEST.UNIT:UPDi_UpdateCdd
TEST.SUBPROGRAM:UPDUpdateCdd_GetTargetState
TEST.NEW
TEST.NAME:UPDUpdateCdd_GetTargetState.001
TEST.VALUE:UPDi_UpdateCdd.UPDUpdateCdd_GetTargetState.return:1
TEST.EXPECTED:UPDi_UpdateCdd.UPDUpdateCdd_GetTargetState.return:1
TEST.END

-- Subprogram: UPDUpdateCdd_Init

-- Test Case: UPDUpdateCdd_Init.001
TEST.UNIT:UPDi_UpdateCdd
TEST.SUBPROGRAM:UPDUpdateCdd_Init
TEST.NEW
TEST.NAME:UPDUpdateCdd_Init.001
TEST.END

-- Subprogram: UPDUpdateCdd_IsBusy

-- Test Case: UPDUpdateCdd_IsBusy.001
TEST.UNIT:UPDi_UpdateCdd
TEST.SUBPROGRAM:UPDUpdateCdd_IsBusy
TEST.NEW
TEST.NAME:UPDUpdateCdd_IsBusy.001
TEST.VALUE:UPDi_UpdateCdd.UPDUpdateCdd_IsBusy.return:0
TEST.EXPECTED:UPDi_UpdateCdd.UPDUpdateCdd_IsBusy.return:0
TEST.END

-- Subprogram: UPDUpdateCdd_ReleaseInstaller

-- Test Case: UPDUpdateCdd_ReleaseInstaller.001
TEST.UNIT:UPDi_UpdateCdd
TEST.SUBPROGRAM:UPDUpdateCdd_ReleaseInstaller
TEST.NEW
TEST.NAME:UPDUpdateCdd_ReleaseInstaller.001
TEST.VALUE:UPDi_UpdateCdd.UPDUpdateCdd_ReleaseInstaller.pInstaller:<<null>>
TEST.EXPECTED:UPDi_UpdateCdd.UPDUpdateCdd_ReleaseInstaller.pInstaller:<<null>>
TEST.END

-- Subprogram: UPDUpdateCdd_Task

-- Test Case: UPDUpdateCdd_Task.001
TEST.UNIT:UPDi_UpdateCdd
TEST.SUBPROGRAM:UPDUpdateCdd_Task
TEST.NEW
TEST.NAME:UPDUpdateCdd_Task.001
TEST.END
