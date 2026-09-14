-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : NM_VCAST_HT
-- Unit(s) Under Test: Nm
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: Nm

-- Subprogram: Nm_BusNmNetworkRelease

-- Test Case: Nm_BusNmNetworkRelease.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmNetworkRelease
TEST.NEW
TEST.NAME:Nm_BusNmNetworkRelease.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.END

-- Test Case: Nm_BusNmNetworkRelease.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmNetworkRelease
TEST.NEW
TEST.NAME:Nm_BusNmNetworkRelease.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.END

-- Test Case: Nm_BusNmNetworkRelease.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmNetworkRelease
TEST.NEW
TEST.NAME:Nm_BusNmNetworkRelease.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmNetworkReleaseFunctPtr:Nm_NetworkRelease_test1
TEST.END

-- Subprogram: Nm_BusNmNetworkRequest

-- Test Case: Nm_BusNmNetworkRequest.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmNetworkRequest
TEST.NEW
TEST.NAME:Nm_BusNmNetworkRequest.001
TEST.MCDC_BASIS_PATH:1 of 6
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MAX>>
TEST.VALUE:Nm.Nm_BusNmNetworkRequest.ChannelIndex:<<MIN>>
TEST.END

-- Test Case: Nm_BusNmNetworkRequest.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmNetworkRequest
TEST.NEW
TEST.NAME:Nm_BusNmNetworkRequest.002
TEST.MCDC_BASIS_PATH:2 of 6
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmNetworkRequest.ChannelIndex:<<MIN>>
TEST.END

-- Test Case: Nm_BusNmNetworkRequest.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmNetworkRequest
TEST.NEW
TEST.NAME:Nm_BusNmNetworkRequest.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmNetworkRequestFunctPtr:Nm_NetworkRequest_test0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmNetworkRequest.ChannelIndex:<<MIN>>
TEST.END

-- Test Case: Nm_BusNmNetworkRequest.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmNetworkRequest
TEST.NEW
TEST.NAME:Nm_BusNmNetworkRequest.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmNetworkRequestFunctPtr:Nm_NetworkRequest_test1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmNetworkRequest.ChannelIndex:<<MIN>>
TEST.END

-- Subprogram: Nm_BusNmRequestBusSynchronization

-- Test Case: Nm_BusNmRequestBusSynchronization.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmRequestBusSynchronization
TEST.NEW
TEST.NAME:Nm_BusNmRequestBusSynchronization.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.END

-- Test Case: Nm_BusNmRequestBusSynchronization.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmRequestBusSynchronization
TEST.NEW
TEST.NAME:Nm_BusNmRequestBusSynchronization.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.END

-- Test Case: Nm_BusNmRequestBusSynchronization.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmRequestBusSynchronization
TEST.NEW
TEST.NAME:Nm_BusNmRequestBusSynchronization.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmRequestBusSynchronizationFunctPtr:Nm_BusNmNetworkRequest
TEST.END

-- Subprogram: Nm_BusNmSetSleepReadyBit

-- Test Case: Nm_BusNmSetSleepReadyBit.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmSetSleepReadyBit
TEST.NEW
TEST.NAME:Nm_BusNmSetSleepReadyBit.001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmCoordClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmSleepReadyBit:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.return:1
TEST.END

-- Test Case: Nm_BusNmSetSleepReadyBit.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmSetSleepReadyBit
TEST.NEW
TEST.NAME:Nm_BusNmSetSleepReadyBit.002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MAX>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmCoordClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmSleepReadyBit:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.return:<<MIN>>
TEST.END

-- Test Case: Nm_BusNmSetSleepReadyBit.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmSetSleepReadyBit
TEST.NEW
TEST.NAME:Nm_BusNmSetSleepReadyBit.003
TEST.BASIS_PATH:3 of 3 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmCoordClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmSleepReadyBit:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.return:<<MIN>>
TEST.END

-- Test Case: Nm_BusNmSetSleepReadyBit.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmSetSleepReadyBit
TEST.NEW
TEST.NAME:Nm_BusNmSetSleepReadyBit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmCoordClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmSleepReadyBit:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.return:<<MIN>>
TEST.END

-- Test Case: Nm_BusNmSetSleepReadyBit.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmSetSleepReadyBit
TEST.NEW
TEST.NAME:Nm_BusNmSetSleepReadyBit.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmCoordClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmSleepReadyBit:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.return:<<MIN>>
TEST.END

-- Test Case: Nm_BusNmSetSleepReadyBit.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusNmSetSleepReadyBit
TEST.NEW
TEST.NAME:Nm_BusNmSetSleepReadyBit.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmSetSleepReadyBitFunctPtr:Nm_BusNmSetSleepReadyBitFunct_test
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmCoordClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.nmSleepReadyBit:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.return:<<MIN>>
TEST.END

-- Subprogram: Nm_BusSleepMode

-- Test Case: Nm_BusSleepMode.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusSleepMode
TEST.NEW
TEST.NAME:Nm_BusSleepMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_BusSleepMode.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_BUSSLEEPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_BusSleepMode.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusSleepMode
TEST.NEW
TEST.NAME:Nm_BusSleepMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_BusSleepMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_BusSleepMode.Channel:1
TEST.END

-- Test Case: Nm_BusSleepMode.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusSleepMode
TEST.NEW
TEST.NAME:Nm_BusSleepMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_BusSleepMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_BusSleepMode.Channel:1
TEST.END

-- Test Case: Nm_BusSleepMode.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusSleepMode
TEST.NEW
TEST.NAME:Nm_BusSleepMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_BusSleepMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_BusSleepMode.Channel:1
TEST.END

-- Test Case: Nm_BusSleepMode.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusSleepMode
TEST.NEW
TEST.NAME:Nm_BusSleepMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:1
TEST.VALUE:Nm.Nm_BusSleepMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_BusSleepMode.Channel:1
TEST.END

-- Test Case: Nm_BusSleepMode.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusSleepMode
TEST.NEW
TEST.NAME:Nm_BusSleepMode.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_START
TEST.VALUE:Nm.Nm_BusSleepMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_BusSleepMode.Channel:1
TEST.END

-- Test Case: Nm_BusSleepMode.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_BusSleepMode
TEST.NEW
TEST.NAME:Nm_BusSleepMode.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_START
TEST.VALUE:Nm.Nm_BusSleepMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_BusSleepMode.Channel:1
TEST.END

-- Subprogram: Nm_CarWakeUpIndication

-- Test Case: Nm_CarWakeUpIndication.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CarWakeUpIndication
TEST.NEW
TEST.NAME:Nm_CarWakeUpIndication.001
TEST.BASIS_PATH:1 of 6 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MAX>>
TEST.VALUE:Nm.Nm_CarWakeUpIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_CarWakeUpIndication.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CarWakeUpIndication
TEST.NEW
TEST.NAME:Nm_CarWakeUpIndication.002
TEST.BASIS_PATH:3 of 6 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.Nm_CarWakeUpIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_CarWakeUpIndication.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CarWakeUpIndication
TEST.NEW
TEST.NAME:Nm_CarWakeUpIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmCarWakeUpCalloutFunctPtr:ComM_Nm_NetworkStartIndication
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.Nm_CarWakeUpIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_CarWakeUpIndication.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CarWakeUpIndication
TEST.NEW
TEST.NAME:Nm_CarWakeUpIndication.004
TEST.BASIS_PATH:5 of 6 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_CarWakeUpIndication.nmNetworkHandle:<<MAX>>
TEST.END

-- Test Case: Nm_CarWakeUpIndication.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CarWakeUpIndication
TEST.NEW
TEST.NAME:Nm_CarWakeUpIndication.005
TEST.BASIS_PATH:6 of 6 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:<<MIN>>
TEST.VALUE:Nm.Nm_CarWakeUpIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Subprogram: Nm_CheckRemoteSleepIndication

-- Test Case: Nm_CheckRemoteSleepIndication.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:Nm_CheckRemoteSleepIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:1
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_CheckRemoteSleepIndication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_CHECKREMOTESLEEPINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_UNINIT
TEST.END

-- Test Case: Nm_CheckRemoteSleepIndication.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:Nm_CheckRemoteSleepIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_CheckRemoteSleepIndication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_CHECKREMOTESLEEPINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_CheckRemoteSleepIndication.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:Nm_CheckRemoteSleepIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_CheckRemoteSleepIndication.return:E_NOT_OK
TEST.END

-- Test Case: Nm_CheckRemoteSleepIndication.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:Nm_CheckRemoteSleepIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:2
TEST.EXPECTED:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_CheckRemoteSleepIndication.return:E_NOT_OK
TEST.END

-- Test Case: Nm_CheckRemoteSleepIndication.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:Nm_CheckRemoteSleepIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_CheckRemoteSleepIndication.return:E_NOT_OK
TEST.END

-- Test Case: Nm_CheckRemoteSleepIndication.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:Nm_CheckRemoteSleepIndication.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_CheckRemoteSleepIndication.return:E_NOT_OK
TEST.END

-- Test Case: Nm_CheckRemoteSleepIndication.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:Nm_CheckRemoteSleepIndication.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmCheckRemoteSleepIndicationFunctPtr:Nm_CheckRemoteSleepIndication_test
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_CheckRemoteSleepIndication.nmNetworkHandle:0
TEST.END

-- Subprogram: Nm_CoordCheckAnyNetworkReq

-- Test Case: Nm_CoordCheckAnyNetworkReq.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordCheckAnyNetworkReq
TEST.NEW
TEST.NAME:Nm_CoordCheckAnyNetworkReq.001
TEST.MCDC_BASIS_PATH:1 of 4
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.Nm_PerClusterPtr[0].NmClusterIncNumChannel:0
TEST.END

-- Test Case: Nm_CoordCheckAnyNetworkReq.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordCheckAnyNetworkReq
TEST.NEW
TEST.NAME:Nm_CoordCheckAnyNetworkReq.002
TEST.MCDC_BASIS_PATH:3 of 4
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:1
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordCheckAnyNetworkReq.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordCheckAnyNetworkReq
TEST.NEW
TEST.NAME:Nm_CoordCheckAnyNetworkReq.003
TEST.MCDC_BASIS_PATH:4 of 4
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:<<MIN>>
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Subprogram: Nm_CoordCheckSleepConditions

-- Test Case: Nm_CoordCheckSleepConditions.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordCheckSleepConditions
TEST.NEW
TEST.NAME:Nm_CoordCheckSleepConditions.001
TEST.MCDC_BASIS_PATH:1 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_RemoteSleepInd:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.ChannelIndex:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.Nm_PerClusterPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_CoordCheckSleepConditions.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordCheckSleepConditions
TEST.NEW
TEST.NAME:Nm_CoordCheckSleepConditions.002
TEST.MCDC_BASIS_PATH:2 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_RemoteSleepInd:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.ChannelIndex:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.Nm_PerClusterPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_CoordCheckSleepConditions.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordCheckSleepConditions
TEST.NEW
TEST.NAME:Nm_CoordCheckSleepConditions.003
TEST.MCDC_BASIS_PATH:3 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_RemoteSleepInd:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.ChannelIndex:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.Nm_PerClusterPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_CoordCheckSleepConditions.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordCheckSleepConditions
TEST.NEW
TEST.NAME:Nm_CoordCheckSleepConditions.004
TEST.MCDC_BASIS_PATH:4 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_RemoteSleepInd:1
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.ChannelIndex:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.Nm_PerClusterPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_CoordCheckSleepConditions.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordCheckSleepConditions
TEST.NEW
TEST.NAME:Nm_CoordCheckSleepConditions.005
TEST.MCDC_BASIS_PATH:5 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_CoorRsbFlag:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.ChannelIndex:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.Nm_PerClusterPtr[0].NmTopMostCoordinator:1
TEST.END

-- Test Case: Nm_CoordCheckSleepConditions.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordCheckSleepConditions
TEST.NEW
TEST.NAME:Nm_CoordCheckSleepConditions.006
TEST.MCDC_BASIS_PATH:8 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_CoorRsbFlag:1
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.ChannelIndex:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.Nm_PerClusterPtr[0].NmTopMostCoordinator:0
TEST.END

-- Subprogram: Nm_CoordClusterProcess

-- Test Case: Nm_CoordClusterProcess.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordClusterProcess
TEST.NEW
TEST.NAME:Nm_CoordClusterProcess.001
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordCheckAnyNetworkReq
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_INIT
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.return:<<MIN>>
TEST.VALUE:Nm.Nm_CoordClusterProcess.ClusterIndex:<<MIN>>
TEST.END

-- Test Case: Nm_CoordClusterProcess.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordClusterProcess
TEST.NEW
TEST.NAME:Nm_CoordClusterProcess.002
TEST.BASIS_PATH:2 of 5
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordCheckAnyNetworkReq
TEST.STUB:Nm.Nm_CoordShutdownStartHandle
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_START
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.return:<<MIN>>
TEST.VALUE:Nm.Nm_CoordClusterProcess.ClusterIndex:<<MIN>>
TEST.END

-- Test Case: Nm_CoordClusterProcess.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordClusterProcess
TEST.NEW
TEST.NAME:Nm_CoordClusterProcess.003
TEST.BASIS_PATH:3 of 5
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordCheckAnyNetworkReq
TEST.STUB:Nm.Nm_CoordShutdownRunHandle
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_RUN
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.return:<<MIN>>
TEST.VALUE:Nm.Nm_CoordClusterProcess.ClusterIndex:<<MIN>>
TEST.END

-- Test Case: Nm_CoordClusterProcess.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordClusterProcess
TEST.NEW
TEST.NAME:Nm_CoordClusterProcess.004
TEST.BASIS_PATH:4 of 5
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordCheckAnyNetworkReq
TEST.STUB:Nm.Nm_CoordShutdownAbortHandle
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_ABORT
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.return:<<MIN>>
TEST.VALUE:Nm.Nm_CoordClusterProcess.ClusterIndex:<<MIN>>
TEST.END

-- Test Case: Nm_CoordClusterProcess.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordClusterProcess
TEST.NEW
TEST.NAME:Nm_CoordClusterProcess.005
TEST.BASIS_PATH:5 of 5
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordCheckAnyNetworkReq
TEST.STUB:Nm.Nm_CoordNetworkReqHandle
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_INIT
TEST.VALUE:Nm.Nm_CoordCheckAnyNetworkReq.return:1
TEST.VALUE:Nm.Nm_CoordClusterProcess.ClusterIndex:<<MIN>>
TEST.END

-- Subprogram: Nm_CoordNetworkReqHandle

-- Test Case: Nm_CoordNetworkReqHandle.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordNetworkReqHandle
TEST.NEW
TEST.NAME:Nm_CoordNetworkReqHandle.001
TEST.MCDC_BASIS_PATH:1 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:0
TEST.END

-- Test Case: Nm_CoordNetworkReqHandle.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordNetworkReqHandle
TEST.NEW
TEST.NAME:Nm_CoordNetworkReqHandle.002
TEST.MCDC_BASIS_PATH:3 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordNetworkReqHandle.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordNetworkReqHandle
TEST.NEW
TEST.NAME:Nm_CoordNetworkReqHandle.003
TEST.MCDC_BASIS_PATH:4 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordNetworkReqHandle.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordNetworkReqHandle
TEST.NEW
TEST.NAME:Nm_CoordNetworkReqHandle.004
TEST.MCDC_BASIS_PATH:6 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:1
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordNetworkReqHandle.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordNetworkReqHandle
TEST.NEW
TEST.NAME:Nm_CoordNetworkReqHandle.005
TEST.MCDC_BASIS_PATH:12 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_IsLowerLayNetworkRequested:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:<<MIN>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordNetworkReqHandle.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordNetworkReqHandle
TEST.NEW
TEST.NAME:Nm_CoordNetworkReqHandle.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[1].NmActiveCoordinator:1
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:2
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 2>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[1]:1
TEST.END

-- Test Case: Nm_CoordNetworkReqHandle.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordNetworkReqHandle
TEST.NEW
TEST.NAME:Nm_CoordNetworkReqHandle.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[1].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[1].Nm_RemoteSleepInd:1
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:2
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 2>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[1]:1
TEST.END

-- Test Case: Nm_CoordNetworkReqHandle.008
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordNetworkReqHandle
TEST.NEW
TEST.NAME:Nm_CoordNetworkReqHandle.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_IsLowerLayNetworkRequested:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:1
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordNetworkReqHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Subprogram: Nm_CoordReadySleepBitHandle

-- Test Case: Nm_CoorReadySleepBitHandle.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadySleepBitHandle
TEST.NEW
TEST.NAME:Nm_CoorReadySleepBitHandle.001
TEST.MCDC_BASIS_PATH:1 of 18
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmTopMostCoordinator:<<MIN>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_ReqCSRBitFlag:<<MIN>>
TEST.END

-- Test Case: Nm_CoorReadySleepBitHandle.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadySleepBitHandle
TEST.NEW
TEST.NAME:Nm_CoorReadySleepBitHandle.002
TEST.MCDC_BASIS_PATH:2 of 18
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmTopMostCoordinator:1
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_ReqCSRBitFlag:<<MIN>>
TEST.END

-- Test Case: Nm_CoorReadySleepBitHandle.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadySleepBitHandle
TEST.NEW
TEST.NAME:Nm_CoorReadySleepBitHandle.003
TEST.MCDC_BASIS_PATH:15 of 18
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmTopMostCoordinator:<<MIN>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_ReqCSRBitFlag:<<MIN>>
TEST.END

-- Test Case: Nm_CoorReadySleepBitHandle.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadySleepBitHandle
TEST.NEW
TEST.NAME:Nm_CoorReadySleepBitHandle.004
TEST.MCDC_BASIS_PATH:16 of 18
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmTopMostCoordinator:<<MIN>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_ReqCSRBitFlag:<<MIN>>
TEST.END

-- Test Case: Nm_CoorReadySleepBitHandle.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadySleepBitHandle
TEST.NEW
TEST.NAME:Nm_CoorReadySleepBitHandle.005
TEST.MCDC_BASIS_PATH:18 of 18
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmTopMostCoordinator:1
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_ReqCSRBitFlag:1
TEST.END

-- Test Case: Nm_CoorReadySleepBitHandle.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadySleepBitHandle
TEST.NEW
TEST.NAME:Nm_CoorReadySleepBitHandle.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_CoorRsbFlag:1
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmTopMostCoordinator:<<MIN>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_ReqCSRBitFlag:<<MIN>>
TEST.END

-- Test Case: Nm_CoorReadySleepBitHandle.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadySleepBitHandle
TEST.NEW
TEST.NAME:Nm_CoorReadySleepBitHandle.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_BusNmSetSleepReadyBit
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_CoorRsbFlag:1
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmTopMostCoordinator:<<MIN>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordReadySleepBitHandle.Nm_ReqCSRBitFlag:<<MIN>>
TEST.END

-- Subprogram: Nm_CoordReadyToSleepCancellation

-- Test Case: Nm_CoordReadyToSleepCancellation.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepCancellation
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepCancellation.001
TEST.MCDC_BASIS_PATH:1 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_CoordReadyToSleepCancellation.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_CoordReadyToSleepCancellation.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepCancellation
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepCancellation.002
TEST.MCDC_BASIS_PATH:2 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:<<MIN>>
TEST.VALUE:Nm.Nm_CoordReadyToSleepCancellation.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_CoordReadyToSleepCancellation.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepCancellation
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepCancellation.003
TEST.MCDC_BASIS_PATH:4 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_CoordReadyToSleepCancellation.nmNetworkHandle:<<MAX>>
TEST.END

-- Test Case: Nm_CoordReadyToSleepCancellation.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepCancellation
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepCancellation.004
TEST.MCDC_BASIS_PATH:5 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.Nm_CoordReadyToSleepCancellation.nmNetworkHandle:0
TEST.END

-- Test Case: Nm_CoordReadyToSleepCancellation.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepCancellation
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepCancellation.005
TEST.MCDC_BASIS_PATH:10 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.Nm_CoordReadyToSleepCancellation.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_CoordReadyToSleepCancellation.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepCancellation
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepCancellation.006
TEST.MCDC_BASIS_PATH:12 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.Nm_CoordReadyToSleepCancellation.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_CoordReadyToSleepCancellation.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepCancellation
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepCancellation.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.Nm_CoordReadyToSleepCancellation.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_CoordReadyToSleepCancellation.008
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepCancellation
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepCancellation.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_RUN
TEST.VALUE:Nm.Nm_CoordReadyToSleepCancellation.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_CoordReadyToSleepCancellation.009
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepCancellation
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepCancellation.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_ABORT
TEST.VALUE:Nm.Nm_CoordReadyToSleepCancellation.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Subprogram: Nm_CoordReadyToSleepIndication

-- Test Case: Nm_CoordReadyToSleepIndication.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepIndication
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepIndication.001
TEST.MCDC_BASIS_PATH:1 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_CoordReadyToSleepIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_CoordReadyToSleepIndication.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepIndication
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepIndication.002
TEST.MCDC_BASIS_PATH:2 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:<<MIN>>
TEST.VALUE:Nm.Nm_CoordReadyToSleepIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_CoordReadyToSleepIndication.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepIndication
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepIndication.003
TEST.MCDC_BASIS_PATH:4 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_CoordReadyToSleepIndication.nmNetworkHandle:<<MAX>>
TEST.END

-- Test Case: Nm_CoordReadyToSleepIndication.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordReadyToSleepIndication
TEST.NEW
TEST.NAME:Nm_CoordReadyToSleepIndication.004
TEST.MCDC_BASIS_PATH:7 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.Nm_CoordReadyToSleepIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Subprogram: Nm_CoordShutDownTimerHandle

-- Test Case: Nm_CoordShutDownTimerHandle.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutDownTimerHandle
TEST.NEW
TEST.NAME:Nm_CoordShutDownTimerHandle.001
TEST.MCDC_BASIS_PATH:1 of 18
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:0
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.SleepAllowPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_CoordShutDownTimerHandle.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutDownTimerHandle
TEST.NEW
TEST.NAME:Nm_CoordShutDownTimerHandle.002
TEST.MCDC_BASIS_PATH:6 of 18
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.SleepAllowPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_CoordShutDownTimerHandle.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutDownTimerHandle
TEST.NEW
TEST.NAME:Nm_CoordShutDownTimerHandle.003
TEST.MCDC_BASIS_PATH:7 of 18
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.SleepAllowPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_CoordShutDownTimerHandle.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutDownTimerHandle
TEST.NEW
TEST.NAME:Nm_CoordShutDownTimerHandle.004
TEST.MCDC_BASIS_PATH:9 of 18
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_ShutdownTimer:<<MAX>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.SleepAllowPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_CoordShutDownTimerHandle.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutDownTimerHandle
TEST.NEW
TEST.NAME:Nm_CoordShutDownTimerHandle.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_ShutdownTimer:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.SleepAllowPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_CoordShutDownTimerHandle.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutDownTimerHandle
TEST.NEW
TEST.NAME:Nm_CoordShutDownTimerHandle.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_ShutdownTimer:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_AllowShutdown:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.SleepAllowPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_CoordShutDownTimerHandle.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutDownTimerHandle
TEST.NEW
TEST.NAME:Nm_CoordShutDownTimerHandle.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_BusNmRequestBusSynchronization
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_ShutdownTimer:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_AllowShutdown:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.SleepAllowPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_CoordShutDownTimerHandle.008
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutDownTimerHandle
TEST.NEW
TEST.NAME:Nm_CoordShutDownTimerHandle.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_BusNmRequestBusSynchronization
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_ShutdownTimer:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_IsLowerLayNetworkRequested:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_AllowShutdown:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.SleepAllowPtr:<<malloc 1>>
TEST.END

-- Subprogram: Nm_CoordShutdownAbortHandle

-- Test Case: Nm_CoordShutdownAbortHandle.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownAbortHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownAbortHandle.001
TEST.MCDC_BASIS_PATH:1 of 12
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:0
TEST.END

-- Test Case: Nm_CoordShutdownAbortHandle.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownAbortHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownAbortHandle.002
TEST.MCDC_BASIS_PATH:3 of 12
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownAbortHandle.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownAbortHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownAbortHandle.003
TEST.MCDC_BASIS_PATH:4 of 12
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownAbortHandle.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownAbortHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownAbortHandle.004
TEST.MCDC_BASIS_PATH:5 of 12
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownAbortHandle.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownAbortHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownAbortHandle.005
TEST.MCDC_BASIS_PATH:8 of 12
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_BusNmSetSleepReadyBit
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:<<MIN>>
TEST.VALUE:Nm.Nm_BusNmSetSleepReadyBit.return:0
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownAbortHandle.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownAbortHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownAbortHandle.006
TEST.MCDC_BASIS_PATH:9 of 12
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_IsLowerLayNetworkRequested:1
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownAbortHandle.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownAbortHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownAbortHandle.007
TEST.MCDC_BASIS_PATH:11 of 12
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_BusNmNetworkRequest
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_IsLowerLayNetworkRequested:0
TEST.VALUE:Nm.Nm_BusNmNetworkRequest.return:0
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownAbortHandle.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Subprogram: Nm_CoordShutdownReady

-- Test Case: Nm_CoordShutdownReady.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownReady
TEST.NEW
TEST.NAME:Nm_CoordShutdownReady.001
TEST.MCDC_BASIS_PATH:1 of 20
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncNumChannel:0
TEST.END

-- Test Case: Nm_CoordShutdownReady.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownReady
TEST.NEW
TEST.NAME:Nm_CoordShutdownReady.002
TEST.MCDC_BASIS_PATH:5 of 20
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownReady.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownReady
TEST.NEW
TEST.NAME:Nm_CoordShutdownReady.003
TEST.MCDC_BASIS_PATH:6 of 20
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownReady.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownReady
TEST.NEW
TEST.NAME:Nm_CoordShutdownReady.004
TEST.MCDC_BASIS_PATH:12 of 20
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownReady.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownReady
TEST.NEW
TEST.NAME:Nm_CoordShutdownReady.005
TEST.MCDC_BASIS_PATH:14 of 20
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordCheckSleepConditions
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.return:1
TEST.END

-- Test Case: Nm_CoordShutdownReady.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownReady
TEST.NEW
TEST.NAME:Nm_CoordShutdownReady.006
TEST.MCDC_BASIS_PATH:16 of 20
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordCheckSleepConditions
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_RemoteSleepInd:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmTopMostCoordinator:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.return:<<MIN>>
TEST.END

-- Test Case: Nm_CoordShutdownReady.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownReady
TEST.NEW
TEST.NAME:Nm_CoordShutdownReady.007
TEST.MCDC_BASIS_PATH:17 of 20
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordCheckSleepConditions
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_RemoteSleepInd:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmTopMostCoordinator:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.return:<<MIN>>
TEST.END

-- Test Case: Nm_CoordShutdownReady.008
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownReady
TEST.NEW
TEST.NAME:Nm_CoordShutdownReady.008
TEST.MCDC_BASIS_PATH:19 of 20
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordCheckSleepConditions
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_RemoteSleepInd:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_LowerLayBusSyncPoint:0
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmTopMostCoordinator:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.return:<<MIN>>
TEST.END

-- Test Case: Nm_CoordShutdownReady.009
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownReady
TEST.NEW
TEST.NAME:Nm_CoordShutdownReady.009
TEST.MCDC_BASIS_PATH:20 of 20
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordCheckSleepConditions
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_RemoteSleepInd:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_LowerLayBusSyncPoint:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmTopMostCoordinator:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.VALUE:Nm.Nm_CoordCheckSleepConditions.return:<<MIN>>
TEST.END

-- Test Case: Nm_CoordShutdownReady.010
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownReady
TEST.NEW
TEST.NAME:Nm_CoordShutdownReady.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Subprogram: Nm_CoordShutdownRunHandle

-- Test Case: Nm_CoordShutdownRunHandl.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownRunHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownRunHandl.001
TEST.MCDC_BASIS_PATH:1 of 6
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordShutdownReady
TEST.VALUE:Nm.Nm_CoordShutdownRunHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownRunHandle.ClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.return:<<MIN>>
TEST.END

-- Test Case: Nm_CoordShutdownRunHandl.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownRunHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownRunHandl.002
TEST.MCDC_BASIS_PATH:2 of 6
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordShutdownReady
TEST.VALUE:Nm.Nm_CoordShutdownRunHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownRunHandle.ClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.return:1
TEST.END

-- Test Case: Nm_CoordShutdownRunHandl.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownRunHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownRunHandl.003
TEST.MCDC_BASIS_PATH:3 of 6
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordShutdownReady
TEST.STUB:Nm.Nm_CoordShutDownTimerHandle
TEST.VALUE:Nm.Nm_CoordShutdownRunHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownRunHandle.ClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.return:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.return:0
TEST.END

-- Test Case: Nm_CoordShutdownRunHandl.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownRunHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownRunHandl.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordShutdownReady
TEST.STUB:Nm.Nm_CoordShutDownTimerHandle
TEST.VALUE:Nm.Nm_CoordShutdownRunHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownRunHandle.ClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.return:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.SleepAllowPtr[0]:1
TEST.VALUE:Nm.Nm_CoordShutDownTimerHandle.return:1
TEST.END

-- Subprogram: Nm_CoordShutdownStartHandle

-- Test Case: Nm_CoordShutdownStartHandle.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownStartHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownStartHandle.001
TEST.MCDC_BASIS_PATH:1 of 4
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordShutdownReady
TEST.VALUE:Nm.Nm_CoordShutdownStartHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownStartHandle.ClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.return:<<MIN>>
TEST.END

-- Test Case: Nm_CoordShutdownStartHandle.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownStartHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownStartHandle.002
TEST.MCDC_BASIS_PATH:2 of 4
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordShutdownReady
TEST.VALUE:Nm.Nm_CoordShutdownStartHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownStartHandle.ClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.return:1
TEST.END

-- Test Case: Nm_CoordShutdownStartHandle.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownStartHandle
TEST.NEW
TEST.NAME:Nm_CoordShutdownStartHandle.003
TEST.MCDC_BASIS_PATH:3 of 4
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordShutdownReady
TEST.STUB:Nm.Nm_CoordShutdownTimerLoader
TEST.VALUE:Nm.Nm_CoordShutdownStartHandle.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownStartHandle.ClusterIndex:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownReady.return:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.return:1
TEST.END

-- Subprogram: Nm_CoordShutdownTimerLoader

-- Test Case: Nm_CoordShutdownTimerLoader.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownTimerLoader
TEST.NEW
TEST.NAME:Nm_CoordShutdownTimerLoader.001
TEST.MCDC_BASIS_PATH:1 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmSyncNetFlag:<<MIN>>
TEST.END

-- Test Case: Nm_CoordShutdownTimerLoader.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownTimerLoader
TEST.NEW
TEST.NAME:Nm_CoordShutdownTimerLoader.002
TEST.MCDC_BASIS_PATH:2 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmSyncNetFlag:1
TEST.END

-- Test Case: Nm_CoordShutdownTimerLoader.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownTimerLoader
TEST.NEW
TEST.NAME:Nm_CoordShutdownTimerLoader.003
TEST.MCDC_BASIS_PATH:7 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmSyncNetFlag:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownTimerLoader.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownTimerLoader
TEST.NEW
TEST.NAME:Nm_CoordShutdownTimerLoader.004
TEST.MCDC_BASIS_PATH:9 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmBusNmShutdownTime:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmSyncNetFlag:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownTimerLoader.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownTimerLoader
TEST.NEW
TEST.NAME:Nm_CoordShutdownTimerLoader.005
TEST.MCDC_BASIS_PATH:10 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmActiveCoordinator:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmBusNmShutdownTime:<<MAX>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmSyncNetFlag:<<MIN>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownTimerLoader.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownTimerLoader
TEST.NEW
TEST.NAME:Nm_CoordShutdownTimerLoader.006
TEST.MCDC_BASIS_PATH:14 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_LowerLayBusSyncPoint:0
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmSyncNetFlag:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownTimerLoader.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownTimerLoader
TEST.NEW
TEST.NAME:Nm_CoordShutdownTimerLoader.007
TEST.MCDC_BASIS_PATH:15 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_LowerLayBusSyncPoint:0
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmSyncNetFlag:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownTimerLoader.008
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownTimerLoader
TEST.NEW
TEST.NAME:Nm_CoordShutdownTimerLoader.008
TEST.MCDC_BASIS_PATH:16 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_LowerLayBusSyncPoint:0
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmSyncNetFlag:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Test Case: Nm_CoordShutdownTimerLoader.009
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_CoordShutdownTimerLoader
TEST.NEW
TEST.NAME:Nm_CoordShutdownTimerLoader.009
TEST.MCDC_BASIS_PATH:17 of 17
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_BusAwake:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_LowerLayBusSyncPoint:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmSyncNetFlag:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncNumChannel:1
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel:<<malloc 1>>
TEST.VALUE:Nm.Nm_CoordShutdownTimerLoader.Nm_PerClusterPtr[0].NmClusterIncChannel[0]:0
TEST.END

-- Subprogram: Nm_DetReportError

-- Test Case: Nm_DetReportError.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_DetReportError
TEST.NEW
TEST.NAME:Nm_DetReportError.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_DetReportError.ApiId:NM_SID_GETVERSIONINFO_API
TEST.VALUE:Nm.Nm_DetReportError.ErrorId:NM_E_PARAM_POINTER
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:NM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:NM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_GETVERSIONINFO_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_PARAM_POINTER
TEST.END

-- Subprogram: Nm_DisableCommunication

-- Test Case: Nm_DisableCommunication.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_DisableCommunication
TEST.NEW
TEST.NAME:Nm_DisableCommunication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_DisableCommunication.nmNetworkHandle:1
TEST.EXPECTED:Nm.Nm_DisableCommunication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_DISABLECOMMUNICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_UNINIT
TEST.END

-- Test Case: Nm_DisableCommunication.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_DisableCommunication
TEST.NEW
TEST.NAME:Nm_DisableCommunication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_DisableCommunication.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.EXPECTED:Nm.Nm_DisableCommunication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_DISABLECOMMUNICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_DisableCommunication.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_DisableCommunication
TEST.NEW
TEST.NAME:Nm_DisableCommunication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_DisableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_DisableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_DisableCommunication.return:E_NOT_OK
TEST.END

-- Test Case: Nm_DisableCommunication.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_DisableCommunication
TEST.NEW
TEST.NAME:Nm_DisableCommunication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_DisableCommunication.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:2
TEST.EXPECTED:Nm.Nm_DisableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_DisableCommunication.return:E_NOT_OK
TEST.END

-- Test Case: Nm_DisableCommunication.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_DisableCommunication
TEST.NEW
TEST.NAME:Nm_DisableCommunication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.VALUE:Nm.Nm_DisableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.EXPECTED:Nm.Nm_DisableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_DisableCommunication.return:E_NOT_OK
TEST.END

-- Test Case: Nm_DisableCommunication.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_DisableCommunication
TEST.NEW
TEST.NAME:Nm_DisableCommunication.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmDisableCommunicationFunctPtr:Nm_PassiveStartUp
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_DisableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_DisableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_DisableCommunication.return:E_NOT_OK
TEST.END

-- Subprogram: Nm_EnableCommunication

-- Test Case: Nm_EnableCommunication.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_EnableCommunication
TEST.NEW
TEST.NAME:Nm_EnableCommunication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_EnableCommunication.nmNetworkHandle:1
TEST.EXPECTED:Nm.Nm_EnableCommunication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_ENABLECOMMUNICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_UNINIT
TEST.END

-- Test Case: Nm_EnableCommunication.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_EnableCommunication
TEST.NEW
TEST.NAME:Nm_EnableCommunication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_EnableCommunication.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.EXPECTED:Nm.Nm_EnableCommunication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_ENABLECOMMUNICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_EnableCommunication.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_EnableCommunication
TEST.NEW
TEST.NAME:Nm_EnableCommunication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_EnableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_EnableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_EnableCommunication.return:E_NOT_OK
TEST.END

-- Test Case: Nm_EnableCommunication.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_EnableCommunication
TEST.NEW
TEST.NAME:Nm_EnableCommunication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_EnableCommunication.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:2
TEST.EXPECTED:Nm.Nm_EnableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_EnableCommunication.return:E_NOT_OK
TEST.END

-- Test Case: Nm_EnableCommunication.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_EnableCommunication
TEST.NEW
TEST.NAME:Nm_EnableCommunication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.VALUE:Nm.Nm_EnableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.EXPECTED:Nm.Nm_EnableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_EnableCommunication.return:E_NOT_OK
TEST.END

-- Test Case: Nm_EnableCommunication.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_EnableCommunication
TEST.NEW
TEST.NAME:Nm_EnableCommunication.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmEnableCommunicationFunctPtr:Nm_PassiveStartUp
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_EnableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_EnableCommunication.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_EnableCommunication.return:E_NOT_OK
TEST.END

-- Subprogram: Nm_FindClusterIndex

-- Test Case: Nm_FindClusterIndex.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_FindClusterIndex
TEST.NEW
TEST.NAME:Nm_FindClusterIndex.001
TEST.MCDC_BASIS_PATH:1 of 6
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordConfig.NmPerClusterPtr:<<null>>
TEST.VALUE:Nm.Nm_FindClusterIndex.ChannelIndex:<<MIN>>
TEST.VALUE:Nm.Nm_FindClusterIndex.ClusterIndexPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_FindClusterIndex.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_FindClusterIndex
TEST.NEW
TEST.NAME:Nm_FindClusterIndex.002
TEST.MCDC_BASIS_PATH:2 of 6
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordConfig.NmPerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_FindClusterIndex.ChannelIndex:<<MIN>>
TEST.VALUE:Nm.Nm_FindClusterIndex.ClusterIndexPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_FindClusterIndex.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_FindClusterIndex
TEST.NEW
TEST.NAME:Nm_FindClusterIndex.003
TEST.MCDC_BASIS_PATH:6 of 6
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmCoordClusterIndex:<<MIN>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordConfig.NmPerClusterPtr:<<malloc 1>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordConfig.NmPerClusterPtr[0].NmCoorClusterIndex:1
TEST.VALUE:Nm.Nm_FindClusterIndex.ChannelIndex:0
TEST.VALUE:Nm.Nm_FindClusterIndex.ClusterIndexPtr:<<malloc 1>>
TEST.END

-- Subprogram: Nm_GetChIndexFromComMIndex

-- Test Case: Nm_GetChIndexFromComMIndex.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetChIndexFromComMIndex
TEST.NEW
TEST.NAME:Nm_GetChIndexFromComMIndex.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.nmChannelHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.EXPECTED:Nm.Nm_GetChIndexFromComMIndex.return:NM_NO_COMM_TO_NM_CHIND
TEST.END

-- Subprogram: Nm_GetLocalNodeIdentifier

-- Test Case: Nm_GetLocalNodeIdentifier.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetLocalNodeIdentifier.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:1
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_GETLOCALNODEIDENTIFIER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_UNINIT
TEST.END

-- Test Case: Nm_GetLocalNodeIdentifier.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetLocalNodeIdentifier.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_GETLOCALNODEIDENTIFIER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_GetLocalNodeIdentifier.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetLocalNodeIdentifier.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetLocalNodeIdentifier.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetLocalNodeIdentifier.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:2
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetLocalNodeIdentifier.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetLocalNodeIdentifier.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetLocalNodeIdentifier.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetLocalNodeIdentifier.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetLocalNodeIdentifier.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetLocalNodeIdentifier.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmGetLocalNodeIdentifierFunctPtr:Nm_GetUserData
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetLocalNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetLocalNodeIdentifier.return:E_NOT_OK
TEST.END

-- Subprogram: Nm_GetNodeIdentifier

-- Test Case: Nm_GetNodeIdentifier.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetNodeIdentifier.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:1
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_GETNODEIDENTIFIER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_UNINIT
TEST.END

-- Test Case: Nm_GetNodeIdentifier.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetNodeIdentifier.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_GETNODEIDENTIFIER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_GetNodeIdentifier.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetNodeIdentifier.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetNodeIdentifier.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetNodeIdentifier.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:2
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetNodeIdentifier.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetNodeIdentifier.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetNodeIdentifier.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetNodeIdentifier.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetNodeIdentifier.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetNodeIdentifier
TEST.NEW
TEST.NAME:Nm_GetNodeIdentifier.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmGetNodeIdentifierFunctPtr:Nm_GetUserData
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetNodeIdentifier.return:E_NOT_OK
TEST.END

-- Subprogram: Nm_GetPduData

-- Test Case: Nm_GetPduData.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetPduData
TEST.NEW
TEST.NAME:Nm_GetPduData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetPduData.nmNetworkHandle:1
TEST.VALUE:Nm.Nm_GetPduData.nmPduDataPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_GETPDUDATA_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_UNINIT
TEST.END

-- Test Case: Nm_GetPduData.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetPduData
TEST.NEW
TEST.NAME:Nm_GetPduData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetPduData.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.VALUE:Nm.Nm_GetPduData.nmPduDataPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_GETPDUDATA_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_GetPduData.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetPduData
TEST.NEW
TEST.NAME:Nm_GetPduData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetPduData.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetPduData.nmPduDataPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetPduData.nmNetworkHandle:0
TEST.END

-- Test Case: Nm_GetPduData.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetPduData
TEST.NEW
TEST.NAME:Nm_GetPduData.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetPduData.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetPduData.nmPduDataPtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:2
TEST.EXPECTED:Nm.Nm_GetPduData.nmNetworkHandle:0
TEST.END

-- Test Case: Nm_GetPduData.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetPduData
TEST.NEW
TEST.NAME:Nm_GetPduData.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetPduData.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetPduData.nmNetworkHandle:0
TEST.END

-- Test Case: Nm_GetPduData.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetPduData
TEST.NEW
TEST.NAME:Nm_GetPduData.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.VALUE:Nm.Nm_GetPduData.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetPduData.nmPduDataPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetPduData.nmNetworkHandle:0
TEST.END

-- Test Case: Nm_GetPduData.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetPduData
TEST.NEW
TEST.NAME:Nm_GetPduData.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmGetPduDataFunctPtr:Nm_GetUserData
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetPduData.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetPduData.nmPduDataPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetPduData.nmNetworkHandle:0
TEST.END

-- Subprogram: Nm_GetState

-- Test Case: Nm_GetState.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetState
TEST.NEW
TEST.NAME:Nm_GetState.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetState.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_GetState.nmModePtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetState.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_GETSTATE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_UNINIT
TEST.END

-- Test Case: Nm_GetState.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetState
TEST.NEW
TEST.NAME:Nm_GetState.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetState.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.VALUE:Nm.Nm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_GetState.nmModePtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetState.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_GETSTATE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_GetState.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetState
TEST.NEW
TEST.NAME:Nm_GetState.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetState.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_GetState.nmModePtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetState.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetState.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetState.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetState
TEST.NEW
TEST.NAME:Nm_GetState.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetState.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_GetState.nmModePtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:2
TEST.EXPECTED:Nm.Nm_GetState.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetState.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetState.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetState
TEST.NEW
TEST.NAME:Nm_GetState.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetState.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetState.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetState.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetState.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetState
TEST.NEW
TEST.NAME:Nm_GetState.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetState.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetState.nmStatePtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetState.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetState.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetState.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetState
TEST.NEW
TEST.NAME:Nm_GetState.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.VALUE:Nm.Nm_GetState.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_GetState.nmModePtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetState.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_GetState.return:E_NOT_OK
TEST.END

-- Test Case: Nm_GetState.008
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetState
TEST.NEW
TEST.NAME:Nm_GetState.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_GetState.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:Nm.Nm_GetState.nmModePtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmGetStateFunctPtr:Nm_GetState_test
TEST.EXPECTED:Nm.Nm_GetState.nmNetworkHandle:0
TEST.END

-- Subprogram: Nm_GetUserData

-- Test Case: Nm_GetUserData.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetUserData
TEST.NEW
TEST.NAME:Nm_GetUserData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.END

-- Test Case: Nm_GetUserData.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetUserData
TEST.NEW
TEST.NAME:Nm_GetUserData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.END

-- Test Case: Nm_GetUserData.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetUserData
TEST.NEW
TEST.NAME:Nm_GetUserData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_GetUserData.nmNetworkHandle:3
TEST.END

-- Test Case: Nm_GetUserData.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetUserData
TEST.NEW
TEST.NAME:Nm_GetUserData.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:2
TEST.END

-- Test Case: Nm_GetUserData.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetUserData
TEST.NEW
TEST.NAME:Nm_GetUserData.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_GetUserData.nmUserDataPtr:<<malloc 1>>
TEST.END

-- Test Case: Nm_GetUserData.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetUserData
TEST.NEW
TEST.NAME:Nm_GetUserData.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.VALUE:Nm.Nm_GetUserData.nmUserDataPtr:<<malloc 1>>
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.END

-- Test Case: Nm_GetUserData.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetUserData
TEST.NEW
TEST.NAME:Nm_GetUserData.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmGetUserDataFunctPtr:Nm_GetPduData
TEST.VALUE:Nm.Nm_GetUserData.nmUserDataPtr:<<malloc 1>>
TEST.END

-- Subprogram: Nm_GetVersionInfo

-- Test Case: Nm_GetVersionInfo.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetVersionInfo
TEST.NEW
TEST.NAME:Nm_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_GetVersionInfo.nmVerInfoPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_GETVERSIONINFO_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_PARAM_POINTER
TEST.END

-- Test Case: Nm_GetVersionInfo.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_GetVersionInfo
TEST.NEW
TEST.NAME:Nm_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_GetVersionInfo.nmVerInfoPtr:<<malloc 1>>
TEST.EXPECTED:Nm.Nm_GetVersionInfo.nmVerInfoPtr[0].vendorID:NM_VENDOR_ID
TEST.EXPECTED:Nm.Nm_GetVersionInfo.nmVerInfoPtr[0].moduleID:NM_MODULE_ID
TEST.EXPECTED:Nm.Nm_GetVersionInfo.nmVerInfoPtr[0].sw_major_version:NM_SW_MAJOR_VERSION
TEST.EXPECTED:Nm.Nm_GetVersionInfo.nmVerInfoPtr[0].sw_minor_version:NM_SW_MINOR_VERSION
TEST.EXPECTED:Nm.Nm_GetVersionInfo.nmVerInfoPtr[0].sw_patch_version:NM_SW_PATCH_VERSION
TEST.END

-- Subprogram: Nm_Init

-- Test Case: Nm_Init.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_Init
TEST.NEW
TEST.NAME:Nm_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_Init.ConfigPtr:<<null>>
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.END

-- Test Case: Nm_Init.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_Init
TEST.NEW
TEST.NAME:Nm_Init.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.Nm_Init.ConfigPtr:<<null>>
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.END

-- Subprogram: Nm_InitMemory

-- Test Case: Nm_InitMemory.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_InitMemory
TEST.NEW
TEST.NAME:Nm_InitMemory.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_InitStatus:FALSE
TEST.END

-- Subprogram: Nm_MainFunction

-- Test Case: Nm_MainFunction.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_MainFunction
TEST.NEW
TEST.NAME:Nm_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.END

-- Test Case: Nm_MainFunction.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_MainFunction
TEST.NEW
TEST.NAME:Nm_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_CoordClusterProcess
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.END

-- Subprogram: Nm_NetworkMode

-- Test Case: Nm_NetworkMode.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkMode
TEST.NEW
TEST.NAME:Nm_NetworkMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_NetworkMode.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_NETWORKMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_NetworkMode.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkMode
TEST.NEW
TEST.NAME:Nm_NetworkMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_NetworkMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_NetworkMode.Channel:1
TEST.END

-- Test Case: Nm_NetworkMode.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkMode
TEST.NEW
TEST.NAME:Nm_NetworkMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_NetworkMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_NetworkMode.Channel:1
TEST.END

-- Test Case: Nm_NetworkMode.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkMode
TEST.NEW
TEST.NAME:Nm_NetworkMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_NetworkMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_NetworkMode.Channel:1
TEST.END

-- Test Case: Nm_NetworkMode.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkMode
TEST.NEW
TEST.NAME:Nm_NetworkMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_NetworkMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_NetworkMode.Channel:1
TEST.END

-- Test Case: Nm_NetworkMode.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkMode
TEST.NEW
TEST.NAME:Nm_NetworkMode.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_RUN
TEST.VALUE:Nm.Nm_NetworkMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_NetworkMode.Channel:1
TEST.END

-- Test Case: Nm_NetworkMode.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkMode
TEST.NEW
TEST.NAME:Nm_NetworkMode.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_ABORT
TEST.VALUE:Nm.Nm_NetworkMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_NetworkMode.Channel:1
TEST.END

-- Subprogram: Nm_NetworkRelease

-- Test Case: Nm_NetworkRelease.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRelease
TEST.NEW
TEST.NAME:Nm_NetworkRelease.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_NetworkRelease.nmNetworkHandle:1
TEST.EXPECTED:Nm.Nm_NetworkRelease.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_NETWORKRELEASE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_UNINIT
TEST.END

-- Test Case: Nm_NetworkRelease.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRelease
TEST.NEW
TEST.NAME:Nm_NetworkRelease.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_NetworkRelease.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.EXPECTED:Nm.Nm_NetworkRelease.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_NETWORKRELEASE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_NetworkRelease.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRelease
TEST.NEW
TEST.NAME:Nm_NetworkRelease.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_NetworkRelease.nmNetworkHandle:0
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.EXPECTED:Nm.Nm_NetworkRelease.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRelease.return:0
TEST.END

-- Test Case: Nm_NetworkRelease.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRelease
TEST.NEW
TEST.NAME:Nm_NetworkRelease.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_NetworkRelease.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:2
TEST.EXPECTED:Nm.Nm_NetworkRelease.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRelease.return:E_NOT_OK
TEST.END

-- Test Case: Nm_NetworkRelease.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRelease
TEST.NEW
TEST.NAME:Nm_NetworkRelease.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.VALUE:Nm.Nm_NetworkRelease.nmNetworkHandle:0
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.EXPECTED:Nm.Nm_NetworkRelease.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRelease.return:0
TEST.END

-- Test Case: Nm_NetworkRelease.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRelease
TEST.NEW
TEST.NAME:Nm_NetworkRelease.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmNetworkReleaseFunctPtr:Nm_PassiveStartUp
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmCoordClusterIndex:0xFF
TEST.VALUE:Nm.Nm_NetworkRelease.nmNetworkHandle:0
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmNetworkReleaseFunctPtr:Nm_PassiveStartUp
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.EXPECTED:Nm.Nm_NetworkRelease.nmNetworkHandle:0
TEST.END

-- Subprogram: Nm_NetworkRequest

-- Test Case: Nm_NetworkRequest.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRequest
TEST.NEW
TEST.NAME:Nm_NetworkRequest.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_NETWORKREQUEST_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_UNINIT
TEST.END

-- Test Case: Nm_NetworkRequest.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRequest
TEST.NEW
TEST.NAME:Nm_NetworkRequest.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_NetworkRequest.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.EXPECTED:Nm.Nm_NetworkRequest.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_NETWORKREQUEST_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_NetworkRequest.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRequest
TEST.NEW
TEST.NAME:Nm_NetworkRequest.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.return:E_NOT_OK
TEST.END

-- Test Case: Nm_NetworkRequest.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRequest
TEST.NEW
TEST.NAME:Nm_NetworkRequest.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:2
TEST.EXPECTED:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.return:E_NOT_OK
TEST.END

-- Test Case: Nm_NetworkRequest.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRequest
TEST.NEW
TEST.NAME:Nm_NetworkRequest.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.VALUE:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.EXPECTED:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.return:E_NOT_OK
TEST.END

-- Test Case: Nm_NetworkRequest.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRequest
TEST.NEW
TEST.NAME:Nm_NetworkRequest.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmNetworkRequestFunctPtr:Nm_PassiveStartUp
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.return:E_NOT_OK
TEST.END

-- Test Case: Nm_NetworkRequest.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRequest
TEST.NEW
TEST.NAME:Nm_NetworkRequest.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmNetworkRequestFunctPtr:Nm_PassiveStartUp
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmCoordClusterIndex:0xFF
TEST.VALUE:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.return:E_NOT_OK
TEST.END

-- Test Case: Nm_NetworkRequest.008
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRequest
TEST.NEW
TEST.NAME:Nm_NetworkRequest.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmNetworkRequestFunctPtr:Nm_PassiveStartUp
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.return:E_NOT_OK
TEST.END

-- Test Case: Nm_NetworkRequest.009
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRequest
TEST.NEW
TEST.NAME:Nm_NetworkRequest.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmNetworkRequestFunctPtr:Nm_PassiveStartUp
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_RUN
TEST.VALUE:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.return:E_NOT_OK
TEST.END

-- Test Case: Nm_NetworkRequest.010
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkRequest
TEST.NEW
TEST.NAME:Nm_NetworkRequest.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmNetworkRequestFunctPtr:Nm_PassiveStartUp
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_ABORT
TEST.VALUE:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_NetworkRequest.return:E_NOT_OK
TEST.END

-- Subprogram: Nm_NetworkStartIndication

-- Test Case: Nm_NetworkStartIndication.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkStartIndication
TEST.NEW
TEST.NAME:Nm_NetworkStartIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_NetworkStartIndication.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_NETWORKSTARTINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_NetworkStartIndication.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_NetworkStartIndication
TEST.NEW
TEST.NAME:Nm_NetworkStartIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_NetworkStartIndication.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_NetworkStartIndication.Channel:1
TEST.END

-- Subprogram: Nm_PassiveStartUp

-- Test Case: Nm_PassiveStartUp.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PassiveStartUp
TEST.NEW
TEST.NAME:Nm_PassiveStartUp.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_PassiveStartUp.nmNetworkHandle:1
TEST.EXPECTED:Nm.Nm_PassiveStartUp.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_PASSIVESTARTUP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_UNINIT
TEST.END

-- Test Case: Nm_PassiveStartUp.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PassiveStartUp
TEST.NEW
TEST.NAME:Nm_PassiveStartUp.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_PassiveStartUp.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.EXPECTED:Nm.Nm_PassiveStartUp.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_PASSIVESTARTUP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_PassiveStartUp.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PassiveStartUp
TEST.NEW
TEST.NAME:Nm_PassiveStartUp.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_PassiveStartUp.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_PassiveStartUp.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_PASSIVESTARTUP_API
TEST.END

-- Test Case: Nm_PassiveStartUp.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PassiveStartUp
TEST.NEW
TEST.NAME:Nm_PassiveStartUp.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_PassiveStartUp.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:3
TEST.EXPECTED:Nm.Nm_PassiveStartUp.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_PASSIVESTARTUP_API
TEST.END

-- Test Case: Nm_PassiveStartUp.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PassiveStartUp
TEST.NEW
TEST.NAME:Nm_PassiveStartUp.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:2
TEST.VALUE:Nm.Nm_PassiveStartUp.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_PassiveStartUp.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_PASSIVESTARTUP_API
TEST.END

-- Test Case: Nm_PassiveStartUp.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PassiveStartUp
TEST.NEW
TEST.NAME:Nm_PassiveStartUp.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmPassiveStartUpFunctPtr:Nm_EnableCommunication
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_PassiveStartUp.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_PassiveStartUp.return:E_NOT_OK
TEST.END

-- Test Case: Nm_PassiveStartUp.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PassiveStartUp
TEST.NEW
TEST.NAME:Nm_PassiveStartUp.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmPassiveStartUpFunctPtr:Nm_EnableCommunication
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_PassiveStartUp.nmNetworkHandle:0
TEST.EXPECTED:Nm.Nm_PassiveStartUp.return:E_NOT_OK
TEST.END

-- Subprogram: Nm_PduRxIndication

-- Test Case: Nm_PduRxIndication.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PduRxIndication
TEST.NEW
TEST.NAME:Nm_PduRxIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_PduRxIndication.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_PDURXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_UNINIT
TEST.END

-- Test Case: Nm_PduRxIndication.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PduRxIndication
TEST.NEW
TEST.NAME:Nm_PduRxIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_PduRxIndication.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_PDURXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_PduRxIndication.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PduRxIndication
TEST.NEW
TEST.NAME:Nm_PduRxIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:NM_NUM_OF_BUS_NM_SUPPORTED
TEST.VALUE:Nm.Nm_PduRxIndication.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_PDURXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_PduRxIndication.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PduRxIndication
TEST.NEW
TEST.NAME:Nm_PduRxIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmPduRxIndicationFunctPtr:<<null>>
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_PduRxIndication.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_PDURXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_FUNCTION_PTR_IS_NULL
TEST.END

-- Test Case: Nm_PduRxIndication.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PduRxIndication
TEST.NEW
TEST.NAME:Nm_PduRxIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:TRUE
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmPduRxIndicationFunctPtr:ComM_Nm_NetworkMode
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:0
TEST.VALUE:Nm.Nm_PduRxIndication.nmNetworkHandle:0
TEST.END

-- Subprogram: Nm_PrepareBusSleepMode

-- Test Case: Nm_PrepareBusSleepMode.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PrepareBusSleepMode
TEST.NEW
TEST.NAME:Nm_PrepareBusSleepMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_PrepareBusSleepMode.nmNetworkHandle:NM_COMM_NUMBER_OF_CHANNELS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:NM_SID_PREPAREBUSSLEEPMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:NM_E_HANDLE_UNDEF
TEST.END

-- Test Case: Nm_PrepareBusSleepMode.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PrepareBusSleepMode
TEST.NEW
TEST.NAME:Nm_PrepareBusSleepMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_PrepareBusSleepMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_PrepareBusSleepMode.Channel:1
TEST.END

-- Test Case: Nm_PrepareBusSleepMode.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PrepareBusSleepMode
TEST.NEW
TEST.NAME:Nm_PrepareBusSleepMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_PrepareBusSleepMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_PrepareBusSleepMode.Channel:1
TEST.END

-- Test Case: Nm_PrepareBusSleepMode.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PrepareBusSleepMode
TEST.NEW
TEST.NAME:Nm_PrepareBusSleepMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.Nm_PrepareBusSleepMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_PrepareBusSleepMode.Channel:1
TEST.END

-- Test Case: Nm_PrepareBusSleepMode.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_PrepareBusSleepMode
TEST.NEW
TEST.NAME:Nm_PrepareBusSleepMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].ComMChRef:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:1
TEST.VALUE:Nm.Nm_PrepareBusSleepMode.nmNetworkHandle:0
TEST.EXPECTED:uut_prototype_stubs.ComM_Nm_PrepareBusSleepMode.Channel:1
TEST.END

-- Subprogram: Nm_ProcessStateChange

-- Test Case: Nm_ProcessStateChange.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_ProcessStateChange
TEST.NEW
TEST.NAME:Nm_ProcessStateChange.001
TEST.MCDC_BASIS_PATH:1 of 4
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_ProcessStateChange.nmPreviousState:<<MIN>>
TEST.VALUE:Nm.Nm_ProcessStateChange.nmCurrentState:NM_STATE_UNINIT
TEST.END

-- Test Case: Nm_ProcessStateChange.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_ProcessStateChange
TEST.NEW
TEST.NAME:Nm_ProcessStateChange.002
TEST.MCDC_BASIS_PATH:2 of 4
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_ProcessStateChange.nmPreviousState:<<MIN>>
TEST.VALUE:Nm.Nm_ProcessStateChange.nmCurrentState:NM_STATE_REPEAT_MESSAGE
TEST.END

-- Test Case: Nm_ProcessStateChange.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_ProcessStateChange
TEST.NEW
TEST.NAME:Nm_ProcessStateChange.003
TEST.MCDC_BASIS_PATH:4 of 4
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_ProcessStateChange.nmPreviousState:<<MIN>>
TEST.VALUE:Nm.Nm_ProcessStateChange.nmCurrentState:NM_STATE_NORMAL_OPERATION
TEST.END

-- Test Case: Nm_ProcessStateChange.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_ProcessStateChange
TEST.NEW
TEST.NAME:Nm_ProcessStateChange.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_ProcessStateChange.nmPreviousState:NM_STATE_BUS_SLEEP
TEST.VALUE:Nm.Nm_ProcessStateChange.nmCurrentState:NM_STATE_REPEAT_MESSAGE
TEST.END

-- Test Case: Nm_ProcessStateChange.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_ProcessStateChange
TEST.NEW
TEST.NAME:Nm_ProcessStateChange.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_ProcessStateChange.nmPreviousState:NM_STATE_PREPARE_BUS_SLEEP
TEST.VALUE:Nm.Nm_ProcessStateChange.nmCurrentState:NM_STATE_REPEAT_MESSAGE
TEST.END

-- Test Case: Nm_ProcessStateChange.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_ProcessStateChange
TEST.NEW
TEST.NAME:Nm_ProcessStateChange.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_ProcessStateChange.nmPreviousState:NM_STATE_READY_SLEEP
TEST.VALUE:Nm.Nm_ProcessStateChange.nmCurrentState:NM_STATE_REPEAT_MESSAGE
TEST.END

-- Test Case: Nm_ProcessStateChange.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_ProcessStateChange
TEST.NEW
TEST.NAME:Nm_ProcessStateChange.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_ProcessStateChange.nmPreviousState:NM_STATE_NORMAL_OPERATION
TEST.VALUE:Nm.Nm_ProcessStateChange.nmCurrentState:NM_STATE_REPEAT_MESSAGE
TEST.END

-- Test Case: Nm_ProcessStateChange.008
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_ProcessStateChange
TEST.NEW
TEST.NAME:Nm_ProcessStateChange.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_ProcessStateChange.nmPreviousState:NM_STATE_REPEAT_MESSAGE
TEST.VALUE:Nm.Nm_ProcessStateChange.nmCurrentState:NM_STATE_NORMAL_OPERATION
TEST.END

-- Test Case: Nm_ProcessStateChange.009
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_ProcessStateChange
TEST.NEW
TEST.NAME:Nm_ProcessStateChange.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.Nm_ProcessStateChange.nmPreviousState:NM_STATE_READY_SLEEP
TEST.VALUE:Nm.Nm_ProcessStateChange.nmCurrentState:NM_STATE_NORMAL_OPERATION
TEST.END

-- Subprogram: Nm_RemoteSleepCancellation

-- Test Case: Nm_RemoteSleepCancellation.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepCancellation
TEST.NEW
TEST.NAME:Nm_RemoteSleepCancellation.001
TEST.MCDC_BASIS_PATH:1 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_RemoteSleepCancellation.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_RemoteSleepCancellation.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepCancellation
TEST.NEW
TEST.NAME:Nm_RemoteSleepCancellation.002
TEST.MCDC_BASIS_PATH:2 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:<<MIN>>
TEST.VALUE:Nm.Nm_RemoteSleepCancellation.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_RemoteSleepCancellation.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepCancellation
TEST.NEW
TEST.NAME:Nm_RemoteSleepCancellation.003
TEST.MCDC_BASIS_PATH:4 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_RemoteSleepCancellation.nmNetworkHandle:<<MAX>>
TEST.END

-- Test Case: Nm_RemoteSleepCancellation.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepCancellation
TEST.NEW
TEST.NAME:Nm_RemoteSleepCancellation.004
TEST.MCDC_BASIS_PATH:7 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.Nm_RemoteSleepCancellation.nmNetworkHandle:0
TEST.END

-- Test Case: Nm_RemoteSleepCancellation.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepCancellation
TEST.NEW
TEST.NAME:Nm_RemoteSleepCancellation.005
TEST.MCDC_BASIS_PATH:10 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:0
TEST.VALUE:Nm.Nm_RemoteSleepCancellation.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_RemoteSleepCancellation.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepCancellation
TEST.NEW
TEST.NAME:Nm_RemoteSleepCancellation.006
TEST.MCDC_BASIS_PATH:12 of 13
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:0
TEST.VALUE:Nm.Nm_RemoteSleepCancellation.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_RemoteSleepCancellation.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepCancellation
TEST.NEW
TEST.NAME:Nm_RemoteSleepCancellation.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:0
TEST.VALUE:Nm.Nm_RemoteSleepCancellation.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_RemoteSleepCancellation.008
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepCancellation
TEST.NEW
TEST.NAME:Nm_RemoteSleepCancellation.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_RUN
TEST.VALUE:Nm.Nm_RemoteSleepCancellation.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_RemoteSleepCancellation.009
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepCancellation
TEST.NEW
TEST.NAME:Nm_RemoteSleepCancellation.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_ABORT
TEST.VALUE:Nm.Nm_RemoteSleepCancellation.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Subprogram: Nm_RemoteSleepIndication

-- Test Case: Nm_RemoteSleepIndication.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepIndication
TEST.NEW
TEST.NAME:Nm_RemoteSleepIndication.001
TEST.MCDC_BASIS_PATH:1 of 6
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_RemoteSleepIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_RemoteSleepIndication.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepIndication
TEST.NEW
TEST.NAME:Nm_RemoteSleepIndication.002
TEST.MCDC_BASIS_PATH:2 of 6
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:<<MIN>>
TEST.VALUE:Nm.Nm_RemoteSleepIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_RemoteSleepIndication.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RemoteSleepIndication
TEST.NEW
TEST.NAME:Nm_RemoteSleepIndication.003
TEST.MCDC_BASIS_PATH:4 of 6
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_RemoteSleepIndication.nmNetworkHandle:<<MAX>>
TEST.END

-- Subprogram: Nm_RepeatMessageIndication

-- Test Case: Nm_RepeatMessageIndication.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RepeatMessageIndication
TEST.NEW
TEST.NAME:Nm_RepeatMessageIndication.001
TEST.MCDC_BASIS_PATH:1 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_RepeatMessageIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_RepeatMessageIndication.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RepeatMessageIndication
TEST.NEW
TEST.NAME:Nm_RepeatMessageIndication.002
TEST.MCDC_BASIS_PATH:2 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:<<MIN>>
TEST.VALUE:Nm.Nm_RepeatMessageIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_RepeatMessageIndication.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RepeatMessageIndication
TEST.NEW
TEST.NAME:Nm_RepeatMessageIndication.003
TEST.MCDC_BASIS_PATH:4 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_RepeatMessageIndication.nmNetworkHandle:<<MAX>>
TEST.END

-- Test Case: Nm_RepeatMessageIndication.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RepeatMessageIndication
TEST.NEW
TEST.NAME:Nm_RepeatMessageIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_OemFunctConfig[0].UlRepeatMessageIndicationFunctPtr:Nm_RepeatMessageIndicationFunct_test
TEST.VALUE:Nm.Nm_RepeatMessageIndication.nmNetworkHandle:<<MIN>>
TEST.END

-- Subprogram: Nm_RepeatMessageRequest

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RepeatMessageRequest
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 6 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MAX>>
TEST.VALUE:Nm.Nm_RepeatMessageRequest.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RepeatMessageRequest
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:3 of 6 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.Nm_RepeatMessageRequest.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RepeatMessageRequest
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_GetChIndexFromComMIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.Nm_RepeatMessageRequest.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:3
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RepeatMessageRequest
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_BusNmFunctConfig[0].BusNmRepeatMessageRequestFunctPtr:Nm_PassiveStartUp
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].BusNmFunctConfigId:<<MIN>>
TEST.VALUE:Nm.Nm_RepeatMessageRequest.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RepeatMessageRequest
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:5 of 6 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_RepeatMessageRequest.nmNetworkHandle:<<MAX>>
TEST.VALUE:Nm.Nm_GetChIndexFromComMIndex.return:<<MAX>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_RepeatMessageRequest
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:6 of 6 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:<<MIN>>
TEST.VALUE:Nm.Nm_RepeatMessageRequest.nmNetworkHandle:<<MIN>>
TEST.END

-- Subprogram: Nm_StateChangeNotification

-- Test Case: Nm_StateChangeNotification.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_StateChangeNotification
TEST.NEW
TEST.NAME:Nm_StateChangeNotification.001
TEST.BASIS_PATH:1 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmStateReportEnabled:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmPreviousState:NM_STATE_OFFLINE
TEST.VALUE:Nm.Nm_StateChangeNotification.nmCurrentState:NM_STATE_OFFLINE
TEST.END

-- Test Case: Nm_StateChangeNotification.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_StateChangeNotification
TEST.NEW
TEST.NAME:Nm_StateChangeNotification.002
TEST.BASIS_PATH:4 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_StateChangeNotification.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmPreviousState:<<MAX>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmCurrentState:<<MIN>>
TEST.END

-- Test Case: Nm_StateChangeNotification.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_StateChangeNotification
TEST.NEW
TEST.NAME:Nm_StateChangeNotification.003
TEST.BASIS_PATH:6 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_StateChangeNotification.nmNetworkHandle:<<MAX>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmPreviousState:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmCurrentState:<<MIN>>
TEST.END

-- Test Case: Nm_StateChangeNotification.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_StateChangeNotification
TEST.NEW
TEST.NAME:Nm_StateChangeNotification.004
TEST.BASIS_PATH:7 of 7 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmPreviousState:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmCurrentState:<<MIN>>
TEST.END

-- Test Case: Nm_StateChangeNotification.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_StateChangeNotification
TEST.NEW
TEST.NAME:Nm_StateChangeNotification.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_StateChangeNotification.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmPreviousState:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmCurrentState:<<MAX>>
TEST.END

-- Test Case: Nm_StateChangeNotification.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_StateChangeNotification
TEST.NEW
TEST.NAME:Nm_StateChangeNotification.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_StateChangeNotification.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmPreviousState:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmCurrentState:NM_STATE_BUS_SLEEP
TEST.END

-- Test Case: Nm_StateChangeNotification.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_StateChangeNotification
TEST.NEW
TEST.NAME:Nm_StateChangeNotification.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmStateReportEnabled:1
TEST.VALUE:Nm.Nm_StateChangeNotification.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmPreviousState:<<MIN>>
TEST.VALUE:Nm.Nm_StateChangeNotification.nmCurrentState:NM_STATE_BUS_SLEEP
TEST.END

-- Subprogram: Nm_SynchronizationPoint

-- Test Case: Nm_SynchronizationPoint.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_SynchronizationPoint
TEST.NEW
TEST.NAME:Nm_SynchronizationPoint.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.END

-- Test Case: Nm_SynchronizationPoint.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_SynchronizationPoint
TEST.NEW
TEST.NAME:Nm_SynchronizationPoint.002
TEST.MCDC_BASIS_PATH:1 of 15
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_SynchronizationPoint.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_SynchronizationPoint.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_SynchronizationPoint
TEST.NEW
TEST.NAME:Nm_SynchronizationPoint.003
TEST.MCDC_BASIS_PATH:4 of 15
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_SynchronizationPoint.nmNetworkHandle:<<MAX>>
TEST.END

-- Test Case: Nm_SynchronizationPoint.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_SynchronizationPoint
TEST.NEW
TEST.NAME:Nm_SynchronizationPoint.004
TEST.MCDC_BASIS_PATH:6 of 15
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.Nm_SynchronizationPoint.nmNetworkHandle:0
TEST.END

-- Test Case: Nm_SynchronizationPoint.005
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_SynchronizationPoint
TEST.NEW
TEST.NAME:Nm_SynchronizationPoint.005
TEST.MCDC_BASIS_PATH:10 of 15
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.Nm_SynchronizationPoint.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_SynchronizationPoint.006
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_SynchronizationPoint
TEST.NEW
TEST.NAME:Nm_SynchronizationPoint.006
TEST.MCDC_BASIS_PATH:11 of 15
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.Nm_SynchronizationPoint.nmNetworkHandle:<<MIN>>
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_SynchronizationPoint.007
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_SynchronizationPoint
TEST.NEW
TEST.NAME:Nm_SynchronizationPoint.007
TEST.MCDC_BASIS_PATH:12 of 15
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.Nm_SynchronizationPoint.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_SynchronizationPoint.008
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_SynchronizationPoint
TEST.NEW
TEST.NAME:Nm_SynchronizationPoint.008
TEST.MCDC_BASIS_PATH:14 of 15
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:1
TEST.VALUE:Nm.Nm_SynchronizationPoint.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_SynchronizationPoint.009
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_SynchronizationPoint
TEST.NEW
TEST.NAME:Nm_SynchronizationPoint.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_START
TEST.VALUE:Nm.Nm_SynchronizationPoint.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_SynchronizationPoint.010
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_SynchronizationPoint
TEST.NEW
TEST.NAME:Nm_SynchronizationPoint.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_START
TEST.VALUE:Nm.Nm_SynchronizationPoint.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Test Case: Nm_SynchronizationPoint.011
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_SynchronizationPoint
TEST.NEW
TEST.NAME:Nm_SynchronizationPoint.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.STUB:Nm.Nm_FindClusterIndex
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmChannelSleepMaster:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ChannelConfig[0].NmSynchronizingNetwork:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_CoordStatus[0].Nm_UpperLayNetworkReq:0
TEST.VALUE:Nm.<<GLOBAL>>.Nm_ShutdownState[0]:NM_SHUTDOWN_START
TEST.VALUE:Nm.Nm_SynchronizationPoint.nmNetworkHandle:0
TEST.VALUE:Nm.Nm_FindClusterIndex.return:0
TEST.END

-- Subprogram: Nm_TxTimeoutException

-- Test Case: Nm_TxTimeoutException.001
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_TxTimeoutException
TEST.NEW
TEST.NAME:Nm_TxTimeoutException.001
TEST.MCDC_BASIS_PATH:1 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_TxTimeoutException.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_TxTimeoutException.002
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_TxTimeoutException
TEST.NEW
TEST.NAME:Nm_TxTimeoutException.002
TEST.MCDC_BASIS_PATH:2 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:<<MIN>>
TEST.VALUE:Nm.Nm_TxTimeoutException.nmNetworkHandle:<<MIN>>
TEST.END

-- Test Case: Nm_TxTimeoutException.003
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_TxTimeoutException
TEST.NEW
TEST.NAME:Nm_TxTimeoutException.003
TEST.MCDC_BASIS_PATH:4 of 8
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.Nm_TxTimeoutException.nmNetworkHandle:<<MAX>>
TEST.END

-- Test Case: Nm_TxTimeoutException.004
TEST.UNIT:Nm
TEST.SUBPROGRAM:Nm_TxTimeoutException
TEST.NEW
TEST.NAME:Nm_TxTimeoutException.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Nm::Nm_Detailed_Design::Nm_Class_Diagram 
Requirement_DICVA-13838
TEST.END_NOTES:
TEST.VALUE:Nm.<<GLOBAL>>.Nm_InitStatus:1
TEST.VALUE:Nm.<<GLOBAL>>.Nm_OemFunctConfig[0].UlTxTimeoutExceptionFunctPtr:Nm_TxTimeoutExceptionFunct_test
TEST.VALUE:Nm.Nm_TxTimeoutException.nmNetworkHandle:<<MIN>>
TEST.END
