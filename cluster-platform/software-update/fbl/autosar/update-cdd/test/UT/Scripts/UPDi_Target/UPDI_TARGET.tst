-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_TARGET
-- Unit(s) Under Test: UPDi_Target
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UPDi_Target

-- Subprogram: UPDTarget_CopyTo

-- Test Case: UPDTarget_CopyTo.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_CopyTo
TEST.NEW
TEST.NAME:UPDTarget_CopyTo.001
TEST.VALUE:UPDi_Target.UPDTarget_CopyTo.return:1
TEST.EXPECTED:UPDi_Target.UPDTarget_CopyTo.return:1
TEST.END

-- Subprogram: UPDTarget_Deploy

-- Test Case: UPDTarget_Deploy.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Deploy
TEST.NEW
TEST.NAME:UPDTarget_Deploy.001
TEST.VALUE:UPDi_Target.UPDTarget_Deploy.return:1
TEST.EXPECTED:UPDi_Target.UPDTarget_Deploy.return:1
TEST.END

-- Test Case: UPDTarget_Deploy.002
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Deploy
TEST.NEW
TEST.NAME:UPDTarget_Deploy.002
TEST.VALUE:UPDi_Target.UPDTarget_Deploy.return:1
TEST.EXPECTED:UPDi_Target.UPDTarget_Deploy.return:1
TEST.END

-- Test Case: UPDTarget_Deploy.003
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Deploy
TEST.NEW
TEST.NAME:UPDTarget_Deploy.003
TEST.VALUE:UPDi_Target.UPDTarget_Deploy.return:1
TEST.EXPECTED:UPDi_Target.UPDTarget_Deploy.return:1
TEST.END

-- Test Case: UPDTarget_Deploy.004
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Deploy
TEST.NEW
TEST.NAME:UPDTarget_Deploy.004
TEST.VALUE:UPDi_Target.UPDTarget_Deploy.return:1
TEST.EXPECTED:UPDi_Target.UPDTarget_Deploy.return:1
TEST.END

-- Test Case: UPDTarget_Deploy.005
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Deploy
TEST.NEW
TEST.NAME:UPDTarget_Deploy.005
TEST.VALUE:UPDi_Target.UPDTarget_Deploy.return:1
TEST.EXPECTED:UPDi_Target.UPDTarget_Deploy.return:1
TEST.END

-- Test Case: UPDTarget_Deploy.006
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Deploy
TEST.NEW
TEST.NAME:UPDTarget_Deploy.006
TEST.VALUE:UPDi_Target.UPDTarget_Deploy.return:1
TEST.EXPECTED:UPDi_Target.UPDTarget_Deploy.return:1
TEST.END

-- Subprogram: UPDTarget_Erase

-- Test Case: UPDTarget_Erase.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Erase
TEST.NEW
TEST.NAME:UPDTarget_Erase.001
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:10
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA:<<malloc 1>>
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:0
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_Erase.this
<<UPDi_Target.UPDTarget_Erase.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_GetManifest

-- Test Case: UPDTarget_GetManifest.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetManifest
TEST.NEW
TEST.NAME:UPDTarget_GetManifest.001
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].ActiveManifest.GoldenCrc:3
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].ActiveManifest.GoldenSha256:<<malloc 2>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].ActiveManifest.GoldenSha256:"w"
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].ActiveManifest.VersionMajor:3
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].ActiveManifest.VersionMinor:3
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].ActiveManifest.GoldenCrc:3
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].ActiveManifest.GoldenSha256:"w"
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].ActiveManifest.VersionMajor:3
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].ActiveManifest.VersionMinor:3
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetManifest.this
<<UPDi_Target.UPDTarget_GetManifest.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_GetManifest.002
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetManifest
TEST.NEW
TEST.NAME:UPDTarget_GetManifest.002
TEST.VALUE:UPDi_Target.UPDTarget_GetManifest.Bank:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi_Target.UPDTarget_GetManifest.Bank:eUPDiUpdate_BankActive
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetManifest.this
<<UPDi_Target.UPDTarget_GetManifest.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_GetManifest.003
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetManifest
TEST.NEW
TEST.NAME:UPDTarget_GetManifest.003
TEST.VALUE:UPDi_Target.UPDTarget_GetManifest.Bank:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi_Target.UPDTarget_GetManifest.Bank:eUPDiUpdate_BankActive
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetManifest.this
<<UPDi_Target.UPDTarget_GetManifest.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_GetManifest.005
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetManifest
TEST.NEW
TEST.NAME:UPDTarget_GetManifest.005
TEST.VALUE:UPDi_Target.UPDTarget_GetManifest.Bank:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi_Target.UPDTarget_GetManifest.Bank:eUPDiUpdate_BankActive
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetManifest.this
<<UPDi_Target.UPDTarget_GetManifest.this>> = ( &tUPDiTatarget );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_GetManifest.006
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetManifest
TEST.NEW
TEST.NAME:UPDTarget_GetManifest.006
TEST.VALUE:UPDi_Target.UPDTarget_GetManifest.Bank:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi_Target.UPDTarget_GetManifest.Bank:eUPDiUpdate_BankActive
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetManifest.this
<<UPDi_Target.UPDTarget_GetManifest.this>> = ( &tUPDiTatarget );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_GetManifest.007
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetManifest
TEST.NEW
TEST.NAME:UPDTarget_GetManifest.007
TEST.VALUE:UPDi_Target.UPDTarget_GetManifest.Bank:eUPDiUpdate_BankInactive
TEST.EXPECTED:UPDi_Target.UPDTarget_GetManifest.Bank:eUPDiUpdate_BankInactive
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetManifest.this
<<UPDi_Target.UPDTarget_GetManifest.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_GetPartition

-- Test Case: UPDTarget_GetPartition.002
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetPartition
TEST.NEW
TEST.NAME:UPDTarget_GetPartition.002
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInactive
TEST.EXPECTED:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInactive
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( &tUPDiTatarget );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_GetPartition.003
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetPartition
TEST.NEW
TEST.NAME:UPDTarget_GetPartition.003
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:1
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:1
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( &tUPDiTarget1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_GetPartition.004
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetPartition
TEST.NEW
TEST.NAME:UPDTarget_GetPartition.004
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:0
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:0
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( &tUPDiTarget1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_GetPartition.005
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetPartition
TEST.NEW
TEST.NAME:UPDTarget_GetPartition.005
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:0
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:0
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( &tUPDiTarget1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_GetPartition.006
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetPartition
TEST.NEW
TEST.NAME:UPDTarget_GetPartition.006
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:0
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInactive
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:0
TEST.EXPECTED:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInactive
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( &tUPDiTarget1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_GetPartition.007
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetPartition
TEST.NEW
TEST.NAME:UPDTarget_GetPartition.007
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:0
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInactive
TEST.VALUE:uut_prototype_stubs.UPDi_GetInactiveBank.return:1
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:0
TEST.EXPECTED:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInactive
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( &tUPDiTarget1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_GetPartition.008
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetPartition
TEST.NEW
TEST.NAME:UPDTarget_GetPartition.008
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitionGrou2.BankB[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:0
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankA[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartGroup.BankB[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankActive
TEST.VALUE:uut_prototype_stubs.UPDi_GetInactiveBank.return:1
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextPartitionIndex:0
TEST.EXPECTED:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankActive
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( &tUPDiTarget1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_GetState

-- Test Case: UPDTarget_GetState.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_GetState
TEST.NEW
TEST.NAME:UPDTarget_GetState.001
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Uninst
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Uninst
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_GetState.this
<<UPDi_Target.UPDTarget_GetState.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_Init

-- Test Case: UPDTarget_Init.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Init
TEST.NEW
TEST.NAME:UPDTarget_Init.001
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Uninst
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_UninstIdle
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_Init.this
<<UPDi_Target.UPDTarget_Init.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_InstallData

-- Test Case: UPDTarget_InstallData.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_InstallData
TEST.NEW
TEST.NAME:UPDTarget_InstallData.001
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitiontarget.IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiPartitiontarget.IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Uninst
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiBlockInstaller1.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_InstallData.pAddr:0x123
TEST.VALUE:UPDi_Target.UPDTarget_InstallData.pSize:1
TEST.VALUE:uut_prototype_stubs.UPDIoAdapter_Write.this[0].Ram:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.UPDIoAdapter_Write.pTarget[0].Ram:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.UPDIoAdapter_Write.pPartition[0].IoAdapter:<<malloc 1>>
TEST.EXPECTED:UPDi_Target.UPDTarget_InstallData.pAddr:291
TEST.EXPECTED:UPDi_Target.UPDTarget_InstallData.pSize:1
TEST.VALUE_USER_CODE:UPDi_Target.<<GLOBAL>>.sUPDiBlockInstaller1.Ram.Ram[0].pPartition
<<UPDi_Target.<<GLOBAL>>.sUPDiBlockInstaller1>>.Ram[0].pPartition = ( &sUPDiPartitiontarget );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_InstallData.this
<<UPDi_Target.UPDTarget_InstallData.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_InstallData.pInstaller
<<UPDi_Target.UPDTarget_InstallData.pInstaller>> = ( &sUPDiBlockInstaller1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_InstallExit

-- Test Case: UPDTarget_InstallExit.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_InstallExit
TEST.NEW
TEST.NAME:UPDTarget_InstallExit.001
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Uninst
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Uninstalled
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_InstallExit.this
<<UPDi_Target.UPDTarget_InstallExit.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_InstallStart

-- Test Case: UPDTarget_InstallStart.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_InstallStart
TEST.NEW
TEST.NAME:UPDTarget_InstallStart.001
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Uninst
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Installing
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_InstallStart.this
<<UPDi_Target.UPDTarget_InstallStart.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_Invalidate

-- Test Case: UPDTarget_Invalidate.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Invalidate
TEST.NEW
TEST.NAME:UPDTarget_Invalidate.001
TEST.VALUE:UPDi_Target.UPDTarget_Invalidate.return:1
TEST.EXPECTED:UPDi_Target.UPDTarget_Invalidate.return:1
TEST.END

-- Test Case: UPDTarget_Invalidate.002
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Invalidate
TEST.NEW
TEST.NAME:UPDTarget_Invalidate.002
TEST.VALUE:UPDi_Target.UPDTarget_Invalidate.return:1
TEST.EXPECTED:UPDi_Target.UPDTarget_Invalidate.return:1
TEST.END

-- Subprogram: UPDTarget_IoEraseConf

-- Test Case: UPDTarget_IoEraseConf.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_IoEraseConf
TEST.NEW
TEST.NAME:UPDTarget_IoEraseConf.001
TEST.STUB:UPDi_Target.UPDTarget_GetPartition
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextPartitionIndex:10
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:10
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].Address:0x123
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return:<<malloc 1>>
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextPartitionIndex:0
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:0
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].Address:291
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_IoEraseConf.this
<<UPDi_Target.UPDTarget_IoEraseConf.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_IoEraseIdle

-- Test Case: UPDTarget_IoEraseIdle.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_IoEraseIdle
TEST.NEW
TEST.NAME:UPDTarget_IoEraseIdle.001
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Uninst
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_UninstIdleEmpty
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_IoEraseIdle.this
<<UPDi_Target.UPDTarget_IoEraseIdle.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_IoHashConf

-- Test Case: UPDTarget_IoHashConf.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_IoHashConf
TEST.NEW
TEST.NAME:UPDTarget_IoHashConf.001
TEST.VALUE:UPDi_Target.UPDTarget_IoHashConf.return:0
TEST.EXPECTED:UPDi_Target.UPDTarget_IoHashConf.return:0
TEST.END

-- Subprogram: UPDTarget_IoReadConf

-- Test Case: UPDTarget_IoReadConf.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_IoReadConf
TEST.NEW
TEST.NAME:UPDTarget_IoReadConf.001
TEST.STUB:UPDi_Target.UPDTarget_GetPartition
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextPartitionIndex:10
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:10
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_IoReadConf.pBankType:eUPDiUpdate_BankActive
TEST.VALUE:UPDi_Target.UPDTarget_IoReadConf.return:0
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextPartitionIndex:0
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:0
TEST.EXPECTED:UPDi_Target.UPDTarget_IoReadConf.pBankType:eUPDiUpdate_BankActive
TEST.EXPECTED:UPDi_Target.UPDTarget_IoReadConf.return:0
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_IoReadConf.this
<<UPDi_Target.UPDTarget_IoReadConf.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_IoWriteConf

-- Test Case: UPDTarget_IoWriteConf.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_IoWriteConf
TEST.NEW
TEST.NAME:UPDTarget_IoWriteConf.001
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:10
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter[0].Ram[0].PendingCalls:0
TEST.VALUE:UPDi_Target.UPDTarget_IoWriteConf.IoReqSize:1
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:0
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter[0].Ram[0].PendingCalls:0
TEST.EXPECTED:UPDi_Target.UPDTarget_IoWriteConf.IoReqSize:1
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_IoWriteConf.this
<<UPDi_Target.UPDTarget_IoWriteConf.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_IoWriteConf.002
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_IoWriteConf
TEST.NEW
TEST.NAME:UPDTarget_IoWriteConf.002
TEST.STUB:UPDi_Target.UPDTarget_SetState
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter[0].Ram[0].PendingCalls:0
TEST.VALUE:UPDi_Target.UPDTarget_IoWriteConf.IoReqSize:1
TEST.VALUE:UPDi_Target.UPDTarget_IoWriteConf.pBankType:eUPDiUpdate_BankInvalid
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter[0].Ram[0].PendingCalls:0
TEST.EXPECTED:UPDi_Target.UPDTarget_IoWriteConf.IoReqSize:1
TEST.EXPECTED:UPDi_Target.UPDTarget_IoWriteConf.pBankType:eUPDiUpdate_BankInvalid
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_SetState.this
<<UPDi_Target.UPDTarget_SetState.this>> = ( &tUPDiTatarget );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_IoWriteConf.this
<<UPDi_Target.UPDTarget_IoWriteConf.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_IoWriteConf.003
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_IoWriteConf
TEST.NEW
TEST.NAME:UPDTarget_IoWriteConf.003
TEST.STUB:UPDi_Target.UPDTarget_SetState
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter[0].Ram[0].PendingCalls:0
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Groups[0].BankA[0].IoAdapter[0].Ram[0].PendingCalls:0
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_SetState.this
<<UPDi_Target.UPDTarget_SetState.this>> = ( &sUPDiTargeeet );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_IoWriteConf.this
<<UPDi_Target.UPDTarget_IoWriteConf.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_IoWriteConf.005
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_IoWriteConf
TEST.NEW
TEST.NAME:UPDTarget_IoWriteConf.005
TEST.STUB:UPDi_Target.UPDTarget_GetPartition
TEST.STUB:UPDi_Target.UPDTarget_SetState
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_IoWriteConf.IoReqSize:10
TEST.EXPECTED:UPDi_Target.UPDTarget_IoWriteConf.IoReqSize:10
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_SetState.this
<<UPDi_Target.UPDTarget_SetState.this>> = ( &tUPDiTatarget );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_IoWriteConf.this
<<UPDi_Target.UPDTarget_IoWriteConf.this>> = ( &tUPDiTatarget );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_RequestCopyStep

-- Test Case: UPDTarget_RequestCopyStep.004
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_RequestCopyStep
TEST.NEW
TEST.NAME:UPDTarget_RequestCopyStep.004
TEST.STUB:UPDi_Target.UPDTarget_GetPartition
TEST.STUB:UPDi_Target.UPDTarget_SetState
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextByte:10
TEST.VALUE:UPDi_Target.UPDTarget_RequestCopyStep.IsFirst:1
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_SetState.State:eUPDiTarget_UninstMask
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextByte:0
TEST.EXPECTED:UPDi_Target.UPDTarget_RequestCopyStep.IsFirst:1
TEST.EXPECTED:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.EXPECTED:UPDi_Target.UPDTarget_SetState.State:eUPDiTarget_Reading
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_SetState.this
<<UPDi_Target.UPDTarget_SetState.this>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_RequestCopyStep.this
<<UPDi_Target.UPDTarget_RequestCopyStep.this>> = ( &tUPDiTatarget );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_RequestCopyStep.005
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_RequestCopyStep
TEST.NEW
TEST.NAME:UPDTarget_RequestCopyStep.005
TEST.STUB:UPDi_Target.UPDTarget_GetPartition
TEST.STUB:UPDi_Target.UPDTarget_SetState
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextByte:10
TEST.VALUE:UPDi_Target.UPDTarget_RequestCopyStep.IsFirst:1
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_SetState.State:eUPDiTarget_UninstMask
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextByte:0
TEST.EXPECTED:UPDi_Target.UPDTarget_RequestCopyStep.IsFirst:1
TEST.EXPECTED:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.EXPECTED:UPDi_Target.UPDTarget_SetState.State:eUPDiTarget_Reading
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_SetState.this
<<UPDi_Target.UPDTarget_SetState.this>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_RequestCopyStep.this
<<UPDi_Target.UPDTarget_RequestCopyStep.this>> = ( &tUPDiTatarget );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_RequestCopyStep.006
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_RequestCopyStep
TEST.NEW
TEST.NAME:UPDTarget_RequestCopyStep.006
TEST.STUB:UPDi_Target.UPDTarget_GetPartition
TEST.STUB:UPDi_Target.UPDTarget_SetState
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextByte:10
TEST.VALUE:UPDi_Target.UPDTarget_RequestCopyStep.IsFirst:0
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_SetState.State:eUPDiTarget_UninstMask
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTarRam.nextByte:0
TEST.EXPECTED:UPDi_Target.UPDTarget_RequestCopyStep.IsFirst:0
TEST.EXPECTED:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_SetState.this
<<UPDi_Target.UPDTarget_SetState.this>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_RequestCopyStep.this
<<UPDi_Target.UPDTarget_RequestCopyStep.this>> = ( &tUPDiTatarget );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_RequestCrcStep

-- Test Case: UPDTarget_RequestCrcStep.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_RequestCrcStep
TEST.NEW
TEST.NAME:UPDTarget_RequestCrcStep.001
TEST.VALUE:UPDi_Target.UPDTarget_RequestCrcStep.return:0
TEST.EXPECTED:UPDi_Target.UPDTarget_RequestCrcStep.return:0
TEST.END

-- Subprogram: UPDTarget_RequestEraseStep

-- Test Case: UPDTarget_RequestEraseStep.002
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_RequestEraseStep
TEST.NEW
TEST.NAME:UPDTarget_RequestEraseStep.002
TEST.STUB:UPDi_Target.UPDTarget_GetPartition
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_RequestEraseStep.this
<<UPDi_Target.UPDTarget_RequestEraseStep.this>> = ( &tUPDiTatarget );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_RequestEraseStep.003
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_RequestEraseStep
TEST.NEW
TEST.NAME:UPDTarget_RequestEraseStep.003
TEST.STUB:UPDi_Target.UPDTarget_GetPartition
TEST.VALUE:UPDi_Target.UPDTarget_RequestEraseStep.IsFirst:1
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi_Target.UPDTarget_RequestEraseStep.IsFirst:1
TEST.EXPECTED:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_RequestEraseStep.this
<<UPDi_Target.UPDTarget_RequestEraseStep.this>> = ( &tUPDiTatarget );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDTarget_RequestEraseStep.004
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_RequestEraseStep
TEST.NEW
TEST.NAME:UPDTarget_RequestEraseStep.004
TEST.STUB:UPDi_Target.UPDTarget_GetPartition
TEST.VALUE:UPDi_Target.UPDTarget_RequestEraseStep.IsFirst:1
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_Target.UPDTarget_GetPartition.return[0].IoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.UPDIoAdapter_Erase.return:1
TEST.EXPECTED:UPDi_Target.UPDTarget_RequestEraseStep.IsFirst:1
TEST.EXPECTED:UPDi_Target.UPDTarget_GetPartition.Bank:eUPDiUpdate_BankInvalid
TEST.STUB_VAL_USER_CODE:UPDi_Target.UPDTarget_GetPartition.this
<<UPDi_Target.UPDTarget_GetPartition.this>> = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_RequestEraseStep.this
<<UPDi_Target.UPDTarget_RequestEraseStep.this>> = ( &tUPDiTatarget );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_SetState

-- Test Case: UPDTarget_SetState.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_SetState
TEST.NEW
TEST.NAME:UPDTarget_SetState.001
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].State:eUPDiTarget_Uninst
TEST.VALUE:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextPartitionIndex:1
TEST.EXPECTED:UPDi_Target.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextPartitionIndex:1
TEST.VALUE_USER_CODE:UPDi_Target.UPDTarget_SetState.this
<<UPDi_Target.UPDTarget_SetState.this>> = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDTarget_SwapBanks

-- Test Case: UPDTarget_SwapBanks.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_SwapBanks
TEST.NEW
TEST.NAME:UPDTarget_SwapBanks.001
TEST.VALUE:UPDi_Target.UPDTarget_SwapBanks.return:1
TEST.EXPECTED:UPDi_Target.UPDTarget_SwapBanks.return:1
TEST.END

-- Subprogram: UPDTarget_Verify

-- Test Case: UPDTarget_Verify.001
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Verify
TEST.NEW
TEST.NAME:UPDTarget_Verify.001
TEST.VALUE:UPDi_Target.UPDTarget_Verify.return:0
TEST.EXPECTED:UPDi_Target.UPDTarget_Verify.return:0
TEST.END

-- Test Case: UPDTarget_Verify.002
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Verify
TEST.NEW
TEST.NAME:UPDTarget_Verify.002
TEST.VALUE:UPDi_Target.UPDTarget_Verify.return:0
TEST.EXPECTED:UPDi_Target.UPDTarget_Verify.return:0
TEST.END

-- Test Case: UPDTarget_Verify.003
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Verify
TEST.NEW
TEST.NAME:UPDTarget_Verify.003
TEST.VALUE:UPDi_Target.UPDTarget_Verify.return:0
TEST.EXPECTED:UPDi_Target.UPDTarget_Verify.return:0
TEST.END

-- Test Case: UPDTarget_Verify.004
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Verify
TEST.NEW
TEST.NAME:UPDTarget_Verify.004
TEST.VALUE:UPDi_Target.UPDTarget_Verify.return:0
TEST.EXPECTED:UPDi_Target.UPDTarget_Verify.return:0
TEST.END

-- Test Case: UPDTarget_Verify.005
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Verify
TEST.NEW
TEST.NAME:UPDTarget_Verify.005
TEST.VALUE:UPDi_Target.UPDTarget_Verify.return:0
TEST.EXPECTED:UPDi_Target.UPDTarget_Verify.return:0
TEST.END

-- Test Case: UPDTarget_Verify.006
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Verify
TEST.NEW
TEST.NAME:UPDTarget_Verify.006
TEST.VALUE:UPDi_Target.UPDTarget_Verify.return:0
TEST.EXPECTED:UPDi_Target.UPDTarget_Verify.return:0
TEST.END

-- Test Case: UPDTarget_Verify.007
TEST.UNIT:UPDi_Target
TEST.SUBPROGRAM:UPDTarget_Verify
TEST.NEW
TEST.NAME:UPDTarget_Verify.007
TEST.VALUE:UPDi_Target.UPDTarget_Verify.return:0
TEST.EXPECTED:UPDi_Target.UPDTarget_Verify.return:0
TEST.END
