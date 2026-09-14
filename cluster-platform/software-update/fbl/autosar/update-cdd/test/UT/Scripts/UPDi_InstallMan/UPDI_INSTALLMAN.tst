-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_INSTALLMAN
-- Unit(s) Under Test: UPDi_InstallMan
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: UPDInstallMan_AllocBuffer

-- Test Case: UPDInstallMan_AllocBuffer.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_AllocBuffer
TEST.NEW
TEST.NAME:UPDInstallMan_AllocBuffer.001
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.return:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.return:1
TEST.END

-- Test Case: UPDInstallMan_AllocBuffer.002
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_AllocBuffer
TEST.NEW
TEST.NAME:UPDInstallMan_AllocBuffer.002
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.return:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.return:1
TEST.END

-- Test Case: UPDInstallMan_AllocBuffer.003
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_AllocBuffer
TEST.NEW
TEST.NAME:UPDInstallMan_AllocBuffer.003
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Raw
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Raw
TEST.END

-- Test Case: UPDInstallMan_AllocBuffer.004
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_AllocBuffer
TEST.NEW
TEST.NAME:UPDInstallMan_AllocBuffer.004
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiBuferSet.Addr:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiBuferSet.Addr:"w"
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_Raw
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Raw
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff[0].Addr:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pOutputBuff:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pOutputBuff[0].Addr:<<malloc 2>>
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.sUPDiBuferSet.Addr:"w"
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_Raw
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Raw
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff[0].Addr:<<null>>
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pOutputBuff[0].Addr:<<null>>
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Buffer
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Buffer = ( &sUPDiBufpool );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDInstallMan_AllocBuffer.005
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_AllocBuffer
TEST.NEW
TEST.NAME:UPDInstallMan_AllocBuffer.005
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_Invalid
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Enc
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_Invalid
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Enc
TEST.END

-- Test Case: UPDInstallMan_AllocBuffer.006
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_AllocBuffer
TEST.NEW
TEST.NAME:UPDInstallMan_AllocBuffer.006
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_CmpRaw
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Enc
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_CmpRaw
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Enc
TEST.END

-- Test Case: UPDInstallMan_AllocBuffer.010
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_AllocBuffer
TEST.NEW
TEST.NAME:UPDInstallMan_AllocBuffer.010
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiBuferSet.Addr:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiBuferSet.Addr:"w"
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_Enc
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Raw
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff[0].Addr:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff[0].Addr:"w"
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.sUPDiBuferSet.Addr:"w"
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_Enc
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Raw
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff[0].Addr:"w"
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Buffer
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Buffer = ( &sUPDiBuferSet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDInstallMan_AllocBuffer.011
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_AllocBuffer
TEST.NEW
TEST.NAME:UPDInstallMan_AllocBuffer.011
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiBuferSet.Addr:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiBuferSet.Addr:"w"
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiBuferSet.Buffersize:10
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_Enc
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Raw
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff[0].Addr:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff[0].Addr:"w"
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff[0].Size:3
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.sUPDiBuferSet.Addr:"w"
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.sUPDiBuferSet.Buffersize:10
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pCurrInstallDataFormat:eUPDiDataFormat_Enc
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pSession[0].DataFormat:eUPDiDataFormat_Raw
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff[0].Addr:"w"
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_AllocBuffer.pInputBuff[0].Size:10
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Buffer
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Buffer = ( &sUPDiBuferSet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDInstallMan_CopyLast

-- Test Case: UPDInstallMan_CopyLast.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_CopyLast
TEST.NEW
TEST.NAME:UPDInstallMan_CopyLast.001
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_CopyLast.TargetName:<<malloc 4>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_CopyLast.TargetName:""w""
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_CopyLast.TargetName:""w""
TEST.END

-- Subprogram: UPDInstallMan_CopyLastToAllUninstalled

-- Test Case: UPDInstallMan_CopyLastToAllUninstalled.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_CopyLastToAllUninstalled
TEST.NEW
TEST.NAME:UPDInstallMan_CopyLastToAllUninstalled.001
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_CopyLastToAllUninstalled.return:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_CopyLastToAllUninstalled.return:1
TEST.END

-- Subprogram: UPDInstallMan_Deserialize

-- Test Case: UPDInstallMan_Deserialize.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Deserialize
TEST.NEW
TEST.NAME:UPDInstallMan_Deserialize.001
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Deserialize.data:<<malloc 4>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Deserialize.data:""w""
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Deserialize.data:""w""
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Installers
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Installers = ( &updatemanTargets );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDInstallMan_Deserialize.002
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Deserialize
TEST.NEW
TEST.NAME:UPDInstallMan_Deserialize.002
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Deserialize.SizeIn:2
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Deserialize.data:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Deserialize.data:"w"
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Deserialize.SizeIn:2
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Deserialize.data:"w"
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Installers
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Installers = ( &Installerss );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDInstallMan_Erase

-- Test Case: UPDInstallMan_Erase.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Erase
TEST.NEW
TEST.NAME:UPDInstallMan_Erase.001
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Erase.pSessionID:0
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Erase.pSessionID:0
TEST.END

-- Test Case: UPDInstallMan_Erase.002
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Erase
TEST.NEW
TEST.NAME:UPDInstallMan_Erase.002
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Erase.PackageSize:3
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Erase.pSessionID:1
TEST.VALUE:uut_prototype_stubs.UPDAbstractInstaller_InstallErase.Size:3
TEST.VALUE:uut_prototype_stubs.UPDi_AcquireInstaller.return:<<malloc 1>>
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Erase.PackageSize:3
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Erase.pSessionID:1
TEST.EXPECTED:uut_prototype_stubs.UPDAbstractInstaller_InstallErase.Size:3
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].RootInstaller
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Sessions[0].RootInstaller = ( &sUPDiAbInstaller );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDInstallMan_Init

-- Test Case: UPDInstallMan_Init.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Init
TEST.NEW
TEST.NAME:UPDInstallMan_Init.001
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.u16Used1:1
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.u16Used1:1
TEST.END

-- Subprogram: UPDInstallMan_Resume

-- Test Case: UPDInstallMan_Resume.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Resume
TEST.NEW
TEST.NAME:UPDInstallMan_Resume.001
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:<<malloc 4>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.END

-- Test Case: UPDInstallMan_Resume.002
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Resume
TEST.NEW
TEST.NAME:UPDInstallMan_Resume.002
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:<<malloc 4>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.END

-- Test Case: UPDInstallMan_Resume.003
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Resume
TEST.NEW
TEST.NAME:UPDInstallMan_Resume.003
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:<<malloc 4>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.END

-- Test Case: UPDInstallMan_Resume.004
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Resume
TEST.NEW
TEST.NAME:UPDInstallMan_Resume.004
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:<<malloc 4>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.END

-- Test Case: UPDInstallMan_Resume.005
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Resume
TEST.NEW
TEST.NAME:UPDInstallMan_Resume.005
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:<<malloc 4>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.END

-- Test Case: UPDInstallMan_Resume.006
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Resume
TEST.NEW
TEST.NAME:UPDInstallMan_Resume.006
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:<<malloc 4>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.END

-- Test Case: UPDInstallMan_Resume.007
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Resume
TEST.NEW
TEST.NAME:UPDInstallMan_Resume.007
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:<<malloc 4>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Resume.PackageName:""w""
TEST.END

-- Subprogram: UPDInstallMan_Serialize

-- Test Case: UPDInstallMan_Serialize.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Serialize
TEST.NEW
TEST.NAME:UPDInstallMan_Serialize.001
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Serialize.return:0
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Serialize.return:0
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Installers
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Installers = ( &updatemanTargets );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDInstallMan_Serialize.002
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Serialize
TEST.NEW
TEST.NAME:UPDInstallMan_Serialize.002
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Serialize.data:<<malloc 4>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Serialize.data:""w""
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Serialize.data:""w""
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Installers
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Installers = ( &Installerss );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UPDInstallMan_Suspend

-- Test Case: UPDInstallMan_Suspend.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_Suspend
TEST.NEW
TEST.NAME:UPDInstallMan_Suspend.001
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_Suspend.return:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_Suspend.return:1
TEST.END

-- Subprogram: UPDInstallMan_SuspendAll

-- Test Case: UPDInstallMan_SuspendAll.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_SuspendAll
TEST.NEW
TEST.NAME:UPDInstallMan_SuspendAll.001
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_SuspendAll.return:0
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_SuspendAll.return:0
TEST.END

-- Subprogram: UPDInstallMan_TransferData

-- Test Case: UPDInstallMan_TransferData.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferData
TEST.NEW
TEST.NAME:UPDInstallMan_TransferData.001
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferData.SessionID:0
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferData.Size:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferData.data:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferData.data:"w"
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferData.return:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferData.SessionID:0
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferData.Size:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferData.data:"w"
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferData.return:0
TEST.END

-- Test Case: UPDInstallMan_TransferData.002
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferData
TEST.NEW
TEST.NAME:UPDInstallMan_TransferData.002
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferData.SessionID:10
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferData.Size:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferData.data:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferData.data:"w"
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferData.return:1
TEST.VALUE:uut_prototype_stubs.UPDAbstractInstaller_InstallData.Data:"w"
TEST.VALUE:uut_prototype_stubs.UPDAbstractInstaller_InstallData.Size:3
TEST.VALUE:uut_prototype_stubs.UPDAbstractInstaller_InstallData.return:0
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferData.SessionID:10
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferData.Size:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferData.data:"w"
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferData.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UPDAbstractInstaller_InstallData.pSession.pSession[0].RootInstaller
<<uut_prototype_stubs.UPDAbstractInstaller_InstallData.pSession>>[0].RootInstaller = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: UPDInstallMan_TransferExit

-- Test Case: UPDInstallMan_TransferExit.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferExit
TEST.NEW
TEST.NAME:UPDInstallMan_TransferExit.001
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferExit.SessionID:0
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferExit.SessionID:0
TEST.END

-- Test Case: UPDInstallMan_TransferExit.002
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferExit
TEST.NEW
TEST.NAME:UPDInstallMan_TransferExit.002
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferExit.SessionID:10
TEST.VALUE:uut_prototype_stubs.UPDAbstractInstaller_InstallData.Data:"w"
TEST.VALUE:uut_prototype_stubs.UPDAbstractInstaller_InstallData.Size:2
TEST.VALUE:uut_prototype_stubs.UPDAbstractInstaller_InstallData.return:0
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferExit.SessionID:10
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UPDAbstractInstaller_InstallData.pSession.pSession[0].RootInstaller
<<uut_prototype_stubs.UPDAbstractInstaller_InstallData.pSession>>[0].RootInstaller = ( 1 );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: UPDInstallMan_TransferStart

-- Test Case: UPDInstallMan_TransferStart.001
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferStart
TEST.NEW
TEST.NAME:UPDInstallMan_TransferStart.001
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.return:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.return:1
TEST.END

-- Test Case: UPDInstallMan_TransferStart.002
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferStart
TEST.NEW
TEST.NAME:UPDInstallMan_TransferStart.002
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.return:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.return:1
TEST.END

-- Test Case: UPDInstallMan_TransferStart.003
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferStart
TEST.NEW
TEST.NAME:UPDInstallMan_TransferStart.003
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.return:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.return:1
TEST.END

-- Test Case: UPDInstallMan_TransferStart.004
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferStart
TEST.NEW
TEST.NAME:UPDInstallMan_TransferStart.004
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[0].IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiTargeeet.Ram:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:10
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.return:0
TEST.VALUE:uut_prototype_stubs.UPDi_AcquireInstaller.pSession[0].IsActive:1
TEST.VALUE:uut_prototype_stubs.UPDi_AcquireInstaller.return:<<malloc 1>>
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[0].IsActive:1
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.sUPDiTargeeet.Ram[0].nextByte:0
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.return:0
TEST.EXPECTED:uut_prototype_stubs.UPDi_AcquireInstaller.pSession[0].IsActive:0
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].Target
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Sessions[0].Target = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[1].Target
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Sessions[1].Target = ( &sUPDiTargeeet );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDInstallMan_TransferStart.005
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferStart
TEST.NEW
TEST.NAME:UPDInstallMan_TransferStart.005
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.uUPDiInstallSession.IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd1:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd1[0].Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.return:0
TEST.VALUE:uut_prototype_stubs.UPDi_AcquireInstaller.return:<<malloc 1>>
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.uUPDiInstallSession.IsActive:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.return:1
TEST.END

-- Test Case: UPDInstallMan_TransferStart.006
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferStart
TEST.NEW
TEST.NAME:UPDInstallMan_TransferStart.006
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[0].IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[1].IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.uUPDiInstallSession.IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd1:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd1[0].Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.return:0
TEST.VALUE:uut_prototype_stubs.UPDi_AcquireInstaller.return:<<malloc 1>>
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[0].IsActive:1
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[1].IsActive:1
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.uUPDiInstallSession.IsActive:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.return:0
TEST.END

-- Test Case: UPDInstallMan_TransferStart.007
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferStart
TEST.NEW
TEST.NAME:UPDInstallMan_TransferStart.007
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[0].IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[1].IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.uUPDiInstallSession.IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd1:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd1[0].Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.return:0
TEST.VALUE:uut_prototype_stubs.UPDi_AcquireInstaller.return:<<malloc 1>>
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[0].IsActive:1
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[1].IsActive:1
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.uUPDiInstallSession.IsActive:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.return:0
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Targets
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Targets = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDInstallMan_TransferStart.008
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferStart
TEST.NEW
TEST.NAME:UPDInstallMan_TransferStart.008
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[0].IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[1].IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.uUPDiInstallSession.IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd1:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd1[0].Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.return:0
TEST.VALUE:uut_prototype_stubs.UPDi_AcquireInstaller.return:<<malloc 1>>
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[0].IsActive:1
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[1].IsActive:1
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.uUPDiInstallSession.IsActive:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.return:0
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Targets
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Targets = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDInstallMan_TransferStart.009
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferStart
TEST.NEW
TEST.NAME:UPDInstallMan_TransferStart.009
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[1].IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.uUPDiInstallSession.IsActive:1
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget100.Ram:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget100.Ram[0].nextPartitionIndex:9
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget100.Ram[0].nextByte:10
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget101.Ram:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget101.Ram[0].nextPartitionIndex:9
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget101.Ram[0].nextByte:6
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd1:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd1[0].Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.return:0
TEST.VALUE:uut_prototype_stubs.UPDi_AcquireInstaller.return:<<malloc 1>>
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions[1].IsActive:1
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.uUPDiInstallSession.IsActive:1
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget100.Ram[0].nextPartitionIndex:9
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget100.Ram[0].nextByte:10
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget101.Ram[0].nextPartitionIndex:0
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget101.Ram[0].nextByte:0
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.return:0
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[0].Target
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Sessions[0].Target = ( &sUPDiTarget101 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[1].Target
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Sessions[1].Target = ( &sUPDiTarget101 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UPDInstallMan_TransferStart.012
TEST.UNIT:UPDi_InstallMan
TEST.SUBPROGRAM:UPDInstallMan_TransferStart
TEST.NEW
TEST.NAME:UPDInstallMan_TransferStart.012
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions:<<malloc 2>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget101.Ram:<<malloc 1>>
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget101.Ram[0].nextPartitionIndex:9
TEST.VALUE:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget101.Ram[0].nextByte:10
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.VALUE:UPDi_InstallMan.UPDInstallMan_TransferStart.return:1
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget101.Ram[0].nextPartitionIndex:9
TEST.EXPECTED:UPDi_InstallMan.<<GLOBAL>>.sUPDiTarget101.Ram[0].nextByte:10
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.PackageSize:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.pSessionID:1
TEST.EXPECTED:UPDi_InstallMan.UPDInstallMan_TransferStart.return:1
TEST.VALUE_USER_CODE:UPDi_InstallMan.<<GLOBAL>>.oUPDCdd.Sessions.Sessions[1].Target
<<UPDi_InstallMan.<<GLOBAL>>.oUPDCdd>>.Sessions[1].Target = ( &sUPDiTarget101 );
TEST.END_VALUE_USER_CODE:
TEST.END
