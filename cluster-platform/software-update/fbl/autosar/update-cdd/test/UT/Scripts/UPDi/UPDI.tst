-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI
-- Unit(s) Under Test: UPDi
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UPDi

-- Subprogram: UPD_Deserialize

-- Test Case: UPD_Deserialize.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_Deserialize
TEST.NEW
TEST.NAME:UPD_Deserialize.001
TEST.VALUE:UPDi.UPD_Deserialize.SizeIn:1
TEST.VALUE:UPDi.UPD_Deserialize.data:<<malloc 2>>
TEST.VALUE:UPDi.UPD_Deserialize.data:"w"
TEST.EXPECTED:UPDi.UPD_Deserialize.SizeIn:1
TEST.EXPECTED:UPDi.UPD_Deserialize.data:"w"
TEST.END

-- Subprogram: UPD_IInstallation_CopyLast

-- Test Case: UPD_IInstallation_CopyLast.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_CopyLast
TEST.NEW
TEST.NAME:UPD_IInstallation_CopyLast.001
TEST.VALUE:UPDi.UPD_IInstallation_CopyLast.return:1
TEST.EXPECTED:UPDi.UPD_IInstallation_CopyLast.return:1
TEST.END

-- Subprogram: UPD_IInstallation_CopyLastToAllUninstalled

-- Test Case: UPD_IInstallation_CopyLastToAllUninstalled.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_CopyLastToAllUninstalled
TEST.NEW
TEST.NAME:UPD_IInstallation_CopyLastToAllUninstalled.001
TEST.VALUE:UPDi.UPD_IInstallation_CopyLastToAllUninstalled.return:1
TEST.EXPECTED:UPDi.UPD_IInstallation_CopyLastToAllUninstalled.return:1
TEST.END

-- Subprogram: UPD_IInstallation_Erase

-- Test Case: UPD_IInstallation_Erase.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_Erase
TEST.NEW
TEST.NAME:UPD_IInstallation_Erase.001
TEST.VALUE:UPDi.UPD_IInstallation_Erase.return:0
TEST.EXPECTED:UPDi.UPD_IInstallation_Erase.return:0
TEST.END

-- Subprogram: UPD_IInstallation_Resume

-- Test Case: UPD_IInstallation_Resume.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_Resume
TEST.NEW
TEST.NAME:UPD_IInstallation_Resume.001
TEST.VALUE:UPDi.UPD_IInstallation_Resume.return:1
TEST.EXPECTED:UPDi.UPD_IInstallation_Resume.return:1
TEST.END

-- Test Case: UPD_IInstallation_Resume.002
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_Resume
TEST.NEW
TEST.NAME:UPD_IInstallation_Resume.002
TEST.VALUE:UPDi.UPD_IInstallation_Resume.return:1
TEST.EXPECTED:UPDi.UPD_IInstallation_Resume.return:1
TEST.END

-- Test Case: UPD_IInstallation_Resume.003
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_Resume
TEST.NEW
TEST.NAME:UPD_IInstallation_Resume.003
TEST.VALUE:UPDi.UPD_IInstallation_Resume.return:1
TEST.EXPECTED:UPDi.UPD_IInstallation_Resume.return:1
TEST.END

-- Subprogram: UPD_IInstallation_Suspend

-- Test Case: UPD_IInstallation_Suspend.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_Suspend
TEST.NEW
TEST.NAME:UPD_IInstallation_Suspend.001
TEST.VALUE:UPDi.UPD_IInstallation_Suspend.return:1
TEST.EXPECTED:UPDi.UPD_IInstallation_Suspend.return:1
TEST.END

-- Subprogram: UPD_IInstallation_SuspendAll

-- Test Case: UPD_IInstallation_SuspendAll.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_SuspendAll
TEST.NEW
TEST.NAME:UPD_IInstallation_SuspendAll.001
TEST.VALUE:UPDi.UPD_IInstallation_SuspendAll.return:1
TEST.EXPECTED:UPDi.UPD_IInstallation_SuspendAll.return:1
TEST.END

-- Subprogram: UPD_IInstallation_TransferData

-- Test Case: UPD_IInstallation_TransferData.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_TransferData
TEST.NEW
TEST.NAME:UPD_IInstallation_TransferData.001
TEST.VALUE:UPDi.UPD_IInstallation_TransferData.SessionID:0
TEST.VALUE:UPDi.UPD_IInstallation_TransferData.Size:0
TEST.VALUE:UPDi.UPD_IInstallation_TransferData.data:<<malloc 2>>
TEST.VALUE:UPDi.UPD_IInstallation_TransferData.data:"0"
TEST.VALUE:UPDi.UPD_IInstallation_TransferData.return:0
TEST.EXPECTED:UPDi.UPD_IInstallation_TransferData.SessionID:0
TEST.EXPECTED:UPDi.UPD_IInstallation_TransferData.Size:0
TEST.EXPECTED:UPDi.UPD_IInstallation_TransferData.data:"0"
TEST.EXPECTED:UPDi.UPD_IInstallation_TransferData.return:0
TEST.END

-- Subprogram: UPD_IInstallation_TransferExit

-- Test Case: UPD_IInstallation_TransferExit.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_TransferExit
TEST.NEW
TEST.NAME:UPD_IInstallation_TransferExit.001
TEST.VALUE:UPDi.UPD_IInstallation_TransferExit.return:0
TEST.EXPECTED:UPDi.UPD_IInstallation_TransferExit.return:0
TEST.END

-- Test Case: UPD_IInstallation_TransferExit.002
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_TransferExit
TEST.NEW
TEST.NAME:UPD_IInstallation_TransferExit.002
TEST.STUB:UPDi.UPDi_GetTarget
TEST.VALUE:UPDi.UPD_IInstallation_TransferExit.return:0
TEST.VALUE:UPDi.UPDi_GetTarget.return:<<malloc 1>>
TEST.EXPECTED:UPDi.UPD_IInstallation_TransferExit.return:0
TEST.END

-- Subprogram: UPD_IInstallation_TransferStart

-- Test Case: UPD_IInstallation_TransferStart.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IInstallation_TransferStart
TEST.NEW
TEST.NAME:UPD_IInstallation_TransferStart.001
TEST.VALUE:UPDi.UPD_IInstallation_TransferStart.PackageSize:0
TEST.VALUE:UPDi.UPD_IInstallation_TransferStart.pSessionID:<<NULL>>
TEST.VALUE:UPDi.UPD_IInstallation_TransferStart.return:0
TEST.EXPECTED:UPDi.UPD_IInstallation_TransferStart.PackageSize:0
TEST.EXPECTED:UPDi.UPD_IInstallation_TransferStart.pSessionID:0
TEST.EXPECTED:UPDi.UPD_IInstallation_TransferStart.return:0
TEST.END

-- Subprogram: UPD_ITargets_AreAllTargetsVerfied

-- Test Case: UPD_ITargets_AreAllTargetsVerfied.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_AreAllTargetsVerfied
TEST.NEW
TEST.NAME:UPD_ITargets_AreAllTargetsVerfied.001
TEST.VALUE:UPDi.UPD_ITargets_AreAllTargetsVerfied.return:0
TEST.EXPECTED:UPDi.UPD_ITargets_AreAllTargetsVerfied.return:0
TEST.END

-- Test Case: UPD_ITargets_AreAllTargetsVerfied.002
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_AreAllTargetsVerfied
TEST.NEW
TEST.NAME:UPD_ITargets_AreAllTargetsVerfied.002
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_InstVerfiyng
TEST.EXPECTED:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_InstVerfiyng
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[0].Target = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[1].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[1].Target = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPD_ITargets_GetManifest

-- Test Case: UPD_ITargets_GetManifest.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_GetManifest
TEST.NEW
TEST.NAME:UPD_ITargets_GetManifest.001
TEST.VALUE:UPDi.UPD_ITargets_GetManifest.return:0
TEST.EXPECTED:UPDi.UPD_ITargets_GetManifest.return:0
TEST.END

-- Test Case: UPD_ITargets_GetManifest.002
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_GetManifest
TEST.NEW
TEST.NAME:UPD_ITargets_GetManifest.002
TEST.VALUE:UPDi.UPD_ITargets_GetManifest.Bank:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi.UPD_ITargets_GetManifest.Bank:eUPDiUpdate_BankActive
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Targets
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Targets = ( &Targetss );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPD_ITargets_GetTargetState

-- Test Case: UPD_ITargets_GetTargetState.002
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_GetTargetState
TEST.NEW
TEST.NAME:UPD_ITargets_GetTargetState.002
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 1>>
TEST.VALUE:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_UninstErasing
TEST.EXPECTED:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_UninstErasing
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[0].Target = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPD_ITargets_GetTargetState.005
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_GetTargetState
TEST.NEW
TEST.NAME:UPD_ITargets_GetTargetState.005
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankInvalid
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Targets
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Targets = ( &tUPDiTarget1 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[0].Target = ( &updatemanTargets );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[1].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[1].Target = ( &updatemanTargets );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPD_ITargets_GetTargetState.006
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_GetTargetState
TEST.NEW
TEST.NAME:UPD_ITargets_GetTargetState.006
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankInvalid
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Targets
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Targets = ( &sUPDiTarRam );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[0].Target = ( &updatemanTargets );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[1].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[1].Target = ( &updatemanTargets );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPD_ITargets_GetTargetState.010
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_GetTargetState
TEST.NEW
TEST.NAME:UPD_ITargets_GetTargetState.010
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankActive
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[0].Target = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[1].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[1].Target = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPD_ITargets_GetTargetState.011
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_GetTargetState
TEST.NEW
TEST.NAME:UPD_ITargets_GetTargetState.011
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankActive
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[0].Target = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[1].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[1].Target = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPD_ITargets_GetTargetState.014
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_GetTargetState
TEST.NEW
TEST.NAME:UPD_ITargets_GetTargetState.014
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_UninstErasing
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_UninstErasing
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankActive
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[0].Target = ( &sUPDiTarget101 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[1].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[1].Target = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPD_ITargets_GetTargetState.015
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_GetTargetState
TEST.NEW
TEST.NAME:UPD_ITargets_GetTargetState.015
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Installing
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.VALUE:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankInvalid
TEST.EXPECTED:UPDi.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Installing
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.pSession:1
TEST.EXPECTED:UPDi.UPD_ITargets_GetTargetState.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Targets
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Targets = ( &sUPDiTarRam );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[0].Target = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[1].Target
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Sessions[1].Target = ( &updatemanTargets );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPD_ITargets_VerifyAllTargets

-- Test Case: UPD_ITargets_VerifyAllTargets.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_ITargets_VerifyAllTargets
TEST.NEW
TEST.NAME:UPD_ITargets_VerifyAllTargets.001
TEST.VALUE:UPDi.UPD_ITargets_VerifyAllTargets.return:0
TEST.EXPECTED:UPDi.UPD_ITargets_VerifyAllTargets.return:0
TEST.END

-- Subprogram: UPD_IUpdate_Activate

-- Test Case: UPD_IUpdate_Activate.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IUpdate_Activate
TEST.NEW
TEST.NAME:UPD_IUpdate_Activate.001
TEST.VALUE:UPDi.UPD_IUpdate_Activate.return:0
TEST.EXPECTED:UPDi.UPD_IUpdate_Activate.return:0
TEST.END

-- Subprogram: UPD_IUpdate_BootSuccess

-- Test Case: UPD_IUpdate_BootSuccess.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IUpdate_BootSuccess
TEST.NEW
TEST.NAME:UPD_IUpdate_BootSuccess.001
TEST.VALUE:UPDi.UPD_IUpdate_BootSuccess.return:1
TEST.EXPECTED:UPDi.UPD_IUpdate_BootSuccess.return:1
TEST.END

-- Subprogram: UPD_IUpdate_GetState

-- Test Case: UPD_IUpdate_GetState.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IUpdate_GetState
TEST.NEW
TEST.NAME:UPD_IUpdate_GetState.001
TEST.VALUE:UPDi.UPD_IUpdate_GetState.return:eUPDiUpdate_Idle
TEST.EXPECTED:UPDi.UPD_IUpdate_GetState.return:eUPDiUpdate_Idle
TEST.END

-- Subprogram: UPD_IUpdate_Rollback

-- Test Case: UPD_IUpdate_Rollback.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IUpdate_Rollback
TEST.NEW
TEST.NAME:UPD_IUpdate_Rollback.001
TEST.VALUE:UPDi.UPD_IUpdate_Rollback.return:1
TEST.EXPECTED:UPDi.UPD_IUpdate_Rollback.return:1
TEST.END

-- Subprogram: UPD_IUpdate_StartUPDate

-- Test Case: UPD_IUpdate_StartUPDate.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IUpdate_StartUPDate
TEST.NEW
TEST.NAME:UPD_IUpdate_StartUPDate.001
TEST.VALUE:UPDi.UPD_IUpdate_StartUPDate.return:0
TEST.EXPECTED:UPDi.UPD_IUpdate_StartUPDate.return:0
TEST.END

-- Subprogram: UPD_IUpdate_Terminate

-- Test Case: UPD_IUpdate_Terminate.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IUpdate_Terminate
TEST.NEW
TEST.NAME:UPD_IUpdate_Terminate.001
TEST.VALUE:UPDi.UPD_IUpdate_Terminate.return:1
TEST.EXPECTED:UPDi.UPD_IUpdate_Terminate.return:1
TEST.END

-- Subprogram: UPD_Init

-- Test Case: UPD_Init.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_Init
TEST.NEW
TEST.NAME:UPD_Init.001
TEST.VALUE:UPDi.UPD_Init.return:0
TEST.EXPECTED:UPDi.UPD_Init.return:0
TEST.END

-- Test Case: UPD_Init.002
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_Init
TEST.NEW
TEST.NAME:UPD_Init.002
TEST.VALUE:UPDi.UPD_Init.return:0
TEST.EXPECTED:UPDi.UPD_Init.return:0
TEST.END

-- Test Case: UPD_Init.003
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_Init
TEST.NEW
TEST.NAME:UPD_Init.003
TEST.VALUE:UPDi.UPD_Init.return:1
TEST.VALUE:uut_prototype_stubs.UPDIoAdapter_Init.return:1
TEST.EXPECTED:UPDi.UPD_Init.return:1
TEST.END

-- Test Case: UPD_Init.004
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_Init
TEST.NEW
TEST.NAME:UPD_Init.004
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.TargetsCount:1
TEST.VALUE:UPDi.UPD_Init.return:1
TEST.VALUE:uut_prototype_stubs.UPDIoAdapter_Init.return:1
TEST.VALUE:uut_prototype_stubs.UPDTarget_Init.this[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi.<<GLOBAL>>.oUPDCdd.TargetsCount:1
TEST.EXPECTED:UPDi.UPD_Init.return:1
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Targets
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Targets = ( &Targetss );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPD_IsBusy

-- Test Case: UPD_IsBusy.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IsBusy
TEST.NEW
TEST.NAME:UPD_IsBusy.001
TEST.VALUE:UPDi.UPD_IsBusy.return:0
TEST.EXPECTED:UPDi.UPD_IsBusy.return:0
TEST.END

-- Test Case: UPD_IsBusy.002
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_IsBusy
TEST.NEW
TEST.NAME:UPD_IsBusy.002
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.IoAdaptersCount:1
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.IoAdapters:<<malloc 1>>
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.IoAdapters[0]:<<malloc 1>>
TEST.VALUE:UPDi.UPD_IsBusy.return:0
TEST.EXPECTED:UPDi.<<GLOBAL>>.oUPDCdd.IoAdaptersCount:1
TEST.EXPECTED:UPDi.UPD_IsBusy.return:0
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Installers
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Installers = ( &Installerss );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPD_Serialize

-- Test Case: UPD_Serialize.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_Serialize
TEST.NEW
TEST.NAME:UPD_Serialize.001
TEST.VALUE:UPDi.UPD_Serialize.return:0
TEST.EXPECTED:UPDi.UPD_Serialize.return:0
TEST.END

-- Test Case: UPD_Serialize.002
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_Serialize
TEST.NEW
TEST.NAME:UPD_Serialize.002
TEST.VALUE:UPDi.UPD_Serialize.return:0
TEST.EXPECTED:UPDi.UPD_Serialize.return:0
TEST.END

-- Test Case: UPD_Serialize.003
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_Serialize
TEST.NEW
TEST.NAME:UPD_Serialize.003
TEST.VALUE:UPDi.UPD_Serialize.return:0
TEST.EXPECTED:UPDi.UPD_Serialize.return:0
TEST.END

-- Test Case: UPD_Serialize.004
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_Serialize
TEST.NEW
TEST.NAME:UPD_Serialize.004
TEST.VALUE:UPDi.UPD_Serialize.return:0
TEST.EXPECTED:UPDi.UPD_Serialize.return:0
TEST.END

-- Test Case: UPD_Serialize.005
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_Serialize
TEST.NEW
TEST.NAME:UPD_Serialize.005
TEST.VALUE:UPDi.UPD_Serialize.return:0
TEST.EXPECTED:UPDi.UPD_Serialize.return:0
TEST.END

-- Subprogram: UPD_Task

-- Test Case: UPD_Task.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPD_Task
TEST.NEW
TEST.NAME:UPD_Task.001
TEST.VALUE:UPDi.UPD_Task.return:0
TEST.EXPECTED:UPDi.UPD_Task.return:0
TEST.END

-- Subprogram: UPDi_AcquireInstaller

-- Test Case: UPDi_AcquireInstaller.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_AcquireInstaller
TEST.NEW
TEST.NAME:UPDi_AcquireInstaller.001
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.IoAdapters:<<malloc 1>>
TEST.VALUE:UPDi.<<GLOBAL>>.oUPDCdd.IoAdapters[0]:<<malloc 1>>
TEST.VALUE:UPDi.UPDi_AcquireInstaller.pSession:<<malloc 1>>
TEST.VALUE:UPDi.UPDi_AcquireInstaller.pSession[0].InstalledSize:1
TEST.EXPECTED:UPDi.UPDi_AcquireInstaller.pSession[0].InstalledSize:1
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Installers
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Installers = ( &updatemanTargets );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDi_AcquireInstaller.003
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_AcquireInstaller
TEST.NEW
TEST.NAME:UPDi_AcquireInstaller.003
TEST.VALUE:UPDi.UPDi_AcquireInstaller.pSession:<<malloc 1>>
TEST.VALUE:UPDi.UPDi_AcquireInstaller.pSession[0].DataFormat:eUPDiDataFormat_Invalid
TEST.VALUE:UPDi.UPDi_AcquireInstaller.pCurrDataFormat:eUPDiDataFormat_Raw
TEST.EXPECTED:UPDi.UPDi_AcquireInstaller.pSession[0].DataFormat:eUPDiDataFormat_Invalid
TEST.EXPECTED:UPDi.UPDi_AcquireInstaller.pCurrDataFormat:eUPDiDataFormat_Raw
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Installers
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Installers = ( &Installerss );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDi_AcquireInstaller.004
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_AcquireInstaller
TEST.NEW
TEST.NAME:UPDi_AcquireInstaller.004
TEST.VALUE:UPDi.UPDi_AcquireInstaller.pSession:<<malloc 1>>
TEST.VALUE:UPDi.UPDi_AcquireInstaller.pSession[0].DataFormat:eUPDiDataFormat_Invalid
TEST.VALUE:UPDi.UPDi_AcquireInstaller.pCurrDataFormat:eUPDiDataFormat_Raw
TEST.VALUE:uut_prototype_stubs.UPDAbstractInstaller_GetDataFormat.pDataFormat[0]:eUPDiDataFormat_Invalid
TEST.EXPECTED:UPDi.UPDi_AcquireInstaller.pSession[0].DataFormat:eUPDiDataFormat_Invalid
TEST.EXPECTED:UPDi.UPDi_AcquireInstaller.pCurrDataFormat:eUPDiDataFormat_Raw
TEST.EXPECTED:uut_prototype_stubs.UPDAbstractInstaller_GetDataFormat.pDataFormat[0]:eUPDiDataFormat_Invalid
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Installers
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Installers = ( &Installerss );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDi_GetInactiveBank

-- Test Case: UPDi_GetInactiveBank.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_GetInactiveBank
TEST.NEW
TEST.NAME:UPDi_GetInactiveBank.001
TEST.VALUE:UPDi.UPDi_GetInactiveBank.return:0
TEST.EXPECTED:UPDi.UPDi_GetInactiveBank.return:0
TEST.END

-- Subprogram: UPDi_GetManifest

-- Test Case: UPDi_GetManifest.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_GetManifest
TEST.NEW
TEST.NAME:UPDi_GetManifest.001
TEST.VALUE:UPDi.UPDi_GetManifest.return:1
TEST.EXPECTED:UPDi.UPDi_GetManifest.return:1
TEST.END

-- Subprogram: UPDi_GetSession

-- Test Case: UPDi_GetSession.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_GetSession
TEST.NEW
TEST.NAME:UPDi_GetSession.001
TEST.VALUE:UPDi.UPDi_GetSession.return:<<null>>
TEST.EXPECTED:UPDi.UPDi_GetSession.return:<<null>>
TEST.END

-- Test Case: UPDi_GetSession.002
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_GetSession
TEST.NEW
TEST.NAME:UPDi_GetSession.002
TEST.VALUE:UPDi.UPDi_GetSession.return:<<null>>
TEST.EXPECTED:UPDi.UPDi_GetSession.return:<<null>>
TEST.END

-- Test Case: UPDi_GetSession.003
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_GetSession
TEST.NEW
TEST.NAME:UPDi_GetSession.003
TEST.VALUE:UPDi.UPDi_GetSession.Index:10
TEST.VALUE:UPDi.UPDi_GetSession.return:<<null>>
TEST.EXPECTED:UPDi.UPDi_GetSession.Index:10
TEST.EXPECTED:UPDi.UPDi_GetSession.return:<<null>>
TEST.END

-- Subprogram: UPDi_GetSessionCount

-- Test Case: UPDi_GetSessionCount.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_GetSessionCount
TEST.NEW
TEST.NAME:UPDi_GetSessionCount.001
TEST.VALUE:UPDi.UPDi_GetSessionCount.return:5
TEST.EXPECTED:UPDi.UPDi_GetSessionCount.return:5
TEST.END

-- Test Case: UPDi_GetSessionCount.002
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_GetSessionCount
TEST.NEW
TEST.NAME:UPDi_GetSessionCount.002
TEST.VALUE:UPDi.UPDi_GetSessionCount.return:5
TEST.EXPECTED:UPDi.UPDi_GetSessionCount.return:5
TEST.END

-- Subprogram: UPDi_GetTarget

-- Test Case: UPDi_GetTarget.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_GetTarget
TEST.NEW
TEST.NAME:UPDi_GetTarget.001
TEST.VALUE:UPDi.UPDi_GetTarget.Index:1
TEST.EXPECTED:UPDi.UPDi_GetTarget.Index:1
TEST.VALUE_USER_CODE:UPDi.<<GLOBAL>>.oUPDCdd.Targets
<<UPDi.<<GLOBAL>>.oUPDCdd>>.Targets = ( &updatemanTargets );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDi_GetTarget.003
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_GetTarget
TEST.NEW
TEST.NAME:UPDi_GetTarget.003
TEST.VALUE:UPDi.UPDi_GetTarget.Index:10
TEST.EXPECTED:UPDi.UPDi_GetTarget.Index:10
TEST.END

-- Subprogram: UPDi_GetTargetCount

-- Test Case: UPDi_GetTargetCount.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_GetTargetCount
TEST.NEW
TEST.NAME:UPDi_GetTargetCount.001
TEST.VALUE:UPDi.UPDi_GetTargetCount.return:0
TEST.EXPECTED:UPDi.UPDi_GetTargetCount.return:0
TEST.END

-- Subprogram: UPDi_GetTargetState

-- Test Case: UPDi_GetTargetState.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_GetTargetState
TEST.NEW
TEST.NAME:UPDi_GetTargetState.001
TEST.VALUE:UPDi.UPDi_GetTargetState.return:1
TEST.EXPECTED:UPDi.UPDi_GetTargetState.return:1
TEST.END

-- Subprogram: UPDi_ReleaseInstaller

-- Test Case: UPDi_ReleaseInstaller.001
TEST.UNIT:UPDi
TEST.SUBPROGRAM:UPDi_ReleaseInstaller
TEST.NEW
TEST.NAME:UPDi_ReleaseInstaller.001
TEST.VALUE:UPDi.UPDi_ReleaseInstaller.pInstaller:<<null>>
TEST.EXPECTED:UPDi.UPDi_ReleaseInstaller.pInstaller:<<null>>
TEST.END
