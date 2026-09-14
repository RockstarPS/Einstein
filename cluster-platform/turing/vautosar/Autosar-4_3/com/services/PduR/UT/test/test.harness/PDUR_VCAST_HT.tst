-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : PDUR_VCAST_HT
-- Unit(s) Under Test: PduR
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: PduR

-- Subprogram: PduR_DetReportError

-- Test Case: PduR_DetReportError.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_DetReportError
TEST.NEW
TEST.NAME:PduR_DetReportError.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Subprogram: PduR_DisableRouting

-- Test Case: PduR_DisableRouting_001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_DisableRouting
TEST.NEW
TEST.NAME:PduR_DisableRouting_001
TEST.BASIS_PATH:1 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((PDUR_UNINIT) == PduR_InitStatus) ==> FALSE
      (2) if (1U <= id) ==> FALSE
      (3) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable ErrorId in branch 3
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_DisableRouting.id:<<MIN>>
TEST.VALUE:PduR.PduR_DisableRouting.initialize:<<MIN>>
TEST.END

-- Test Case: PduR_DisableRouting_002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_DisableRouting
TEST.NEW
TEST.NAME:PduR_DisableRouting_002
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((PDUR_UNINIT) == PduR_InitStatus) ==> FALSE
      (2) if (1U <= id) ==> FALSE
      (3) if (0xffU != ErrorId) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable ErrorId in branch 3
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_DisableRouting.id:<<MIN>>
TEST.VALUE:PduR.PduR_DisableRouting.initialize:<<MIN>>
TEST.END

-- Test Case: PduR_DisableRouting_003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_DisableRouting
TEST.NEW
TEST.NAME:PduR_DisableRouting_003
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((PDUR_UNINIT) == PduR_InitStatus) ==> FALSE
      (2) if (1U <= id) ==> TRUE
      (3) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Cannot set ErrorId due to assignment
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_DisableRouting.id:<<MAX>>
TEST.VALUE:PduR.PduR_DisableRouting.initialize:<<MIN>>
TEST.END

-- Test Case: PduR_DisableRouting_004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_DisableRouting
TEST.NEW
TEST.NAME:PduR_DisableRouting_004
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((PDUR_UNINIT) == PduR_InitStatus) ==> TRUE
      (3) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Cannot set ErrorId due to assignment
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_UNINIT
TEST.VALUE:PduR.PduR_DisableRouting.id:<<MIN>>
TEST.VALUE:PduR.PduR_DisableRouting.initialize:<<MIN>>
TEST.END

-- Subprogram: PduR_EnableRouting

-- Test Case: PduR_EnableRouting_001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_EnableRouting
TEST.NEW
TEST.NAME:PduR_EnableRouting_001
TEST.BASIS_PATH:1 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((PDUR_UNINIT) == PduR_InitStatus) ==> FALSE
      (2) if (1U <= id) ==> FALSE
      (3) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable ErrorId in branch 3
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_EnableRouting.id:<<MIN>>
TEST.END

-- Test Case: PduR_EnableRouting_002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_EnableRouting
TEST.NEW
TEST.NAME:PduR_EnableRouting_002
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((PDUR_UNINIT) == PduR_InitStatus) ==> FALSE
      (2) if (1U <= id) ==> FALSE
      (3) if (0xffU != ErrorId) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable ErrorId in branch 3
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_EnableRouting.id:<<MIN>>
TEST.END

-- Test Case: PduR_EnableRouting_003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_EnableRouting
TEST.NEW
TEST.NAME:PduR_EnableRouting_003
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((PDUR_UNINIT) == PduR_InitStatus) ==> FALSE
      (2) if (1U <= id) ==> TRUE
      (3) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Cannot set ErrorId due to assignment
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_EnableRouting.id:<<MAX>>
TEST.END

-- Test Case: PduR_EnableRouting_004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_EnableRouting
TEST.NEW
TEST.NAME:PduR_EnableRouting_004
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((PDUR_UNINIT) == PduR_InitStatus) ==> TRUE
      (3) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Cannot set ErrorId due to assignment
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_UNINIT
TEST.VALUE:PduR.PduR_EnableRouting.id:<<MIN>>
TEST.END

-- Subprogram: PduR_GetConfigurationId

-- Test Case: PduR_GetConfigurationId.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_GetConfigurationId
TEST.NEW
TEST.NAME:PduR_GetConfigurationId.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.EXPECTED:PduR.PduR_GetConfigurationId.return:0
TEST.END

-- Test Case: PduR_GetConfigurationId.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_GetConfigurationId
TEST.NEW
TEST.NAME:PduR_GetConfigurationId.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_GetConfigurationId.return:0
TEST.END

-- Subprogram: PduR_GetVersionInfo

-- Test Case: PduR_GetVersionInfo.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_GetVersionInfo
TEST.NEW
TEST.NAME:PduR_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_GetVersionInfo.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_GetVersionInfo
TEST.NEW
TEST.NAME:PduR_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.PduR_GetVersionInfo.versionInfo:<<malloc 1>>
TEST.END

-- Subprogram: PduR_Init

-- Test Case: PduR_Init.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_Init
TEST.NEW
TEST.NAME:PduR_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_UNINIT
TEST.VALUE:PduR.PduR_Init.ConfigPtr:<<null>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_Init.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_Init
TEST.NEW
TEST.NAME:PduR_Init.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_Init.ConfigPtr:<<null>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Subprogram: PduR_LoRxIndication

-- Test Case: PduR_LoRxIndication.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_LoRxIndication.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoRxIndication.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoRxIndication.RxPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_LoRxIndication.RxPduId:6
TEST.END

-- Test Case: PduR_LoRxIndication.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoRxIndication.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_LoRxIndication.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.END

-- Test Case: PduR_LoRxIndication.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:1
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:1
TEST.END

-- Test Case: PduR_LoRxIndication.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.END

-- Test Case: PduR_LoRxIndication.009
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:PduR_LoRxIndication_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:1
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:PduR_LoRxIndication_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:1
TEST.END

-- Test Case: PduR_LoRxIndication.010
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:PduR_LoRxIndication_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:1
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:PduR_LoRxIndication_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:1
TEST.END

-- Test Case: PduR_LoRxIndication.011
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:PduR_LoRxIndication_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:1
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:PduR_LoRxIndication_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:1
TEST.END

-- Test Case: PduR_LoRxIndication.012
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:PduR_LoRxIndication_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:0
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:PduR_LoRxIndication_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:0
TEST.END

-- Test Case: PduR_LoRxIndication.013
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_UpTransmit
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:PduR_LoRxIndication_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:0
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:PduR_LoRxIndication_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:0
TEST.END

-- Test Case: PduR_LoRxIndication.014
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_UpTransmit
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:<<null>>
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:0
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:<<null>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:0
TEST.END

-- Test Case: PduR_LoRxIndication.015
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoRxIndication
TEST.NEW
TEST.NAME:PduR_LoRxIndication.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:<<null>>
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:1
TEST.VALUE:PduR.PduR_LoRxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfRxIndicationFunctPtr:<<null>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].PduDestDirection:1
TEST.END

-- Subprogram: PduR_LoTpCopyRxData

-- Test Case: PduR_LoTpCopyRxData.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyRxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyRxData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_LoTpCopyRxData.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyRxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyRxData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTpCopyRxData.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyRxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyRxData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTpCopyRxData.id:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_LoTpCopyRxData.id:6
TEST.END

-- Test Case: PduR_LoTpCopyRxData.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyRxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyRxData.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTpCopyRxData.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTpCopyRxData.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyRxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyRxData.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.VALUE:PduR.PduR_LoTpCopyRxData.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_LoTpCopyRxData.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyRxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyRxData.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.VALUE:PduR.PduR_LoTpCopyRxData.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.END

-- Test Case: PduR_LoTpCopyRxData.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyRxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyRxData.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyRxDataFunctPtr:PduR_LoTpCopyRxData_test
TEST.VALUE:PduR.PduR_LoTpCopyRxData.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyRxDataFunctPtr:PduR_LoTpCopyRxData_test
TEST.END

-- Test Case: PduR_LoTpCopyRxData.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyRxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyRxData.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyRxDataFunctPtr:PduR_LoTpCopyRxData_test
TEST.VALUE:PduR.PduR_LoTpCopyRxData.info:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyRxDataFunctPtr:PduR_LoTpCopyRxData_test
TEST.END

-- Test Case: PduR_LoTpCopyRxData.009
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyRxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyRxData.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyRxDataFunctPtr:PduR_LoTpCopyRxData_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:6
TEST.VALUE:PduR.PduR_LoTpCopyRxData.info:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyRxDataFunctPtr:PduR_LoTpCopyRxData_test
TEST.END

-- Test Case: PduR_LoTpCopyRxData.010
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyRxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyRxData.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyRxDataFunctPtr:<<null>>
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyTxDataFunctPtr:<<null>>
TEST.VALUE:PduR.PduR_LoTpCopyRxData.info:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyRxDataFunctPtr:<<null>>
TEST.END

-- Subprogram: PduR_LoTpCopyTxData

-- Test Case: PduR_LoTpCopyTxData.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyTxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyTxData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_LoTpCopyTxData.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyTxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyTxData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTpCopyTxData.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyTxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyTxData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTpCopyTxData.id:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_LoTpCopyTxData.id:6
TEST.END

-- Test Case: PduR_LoTpCopyTxData.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyTxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyTxData.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTpCopyTxData.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTpCopyTxData.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyTxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyTxData.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.VALUE:PduR.PduR_LoTpCopyTxData.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_LoTpCopyTxData.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyTxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyTxData.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].SrcModule:5
TEST.VALUE:PduR.PduR_LoTpCopyTxData.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].SrcModule:5
TEST.END

-- Test Case: PduR_LoTpCopyTxData.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyTxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyTxData.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyTxDataFunctPtr:PduR_LoTpCopyTxData_test
TEST.VALUE:PduR.PduR_LoTpCopyTxData.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyTxDataFunctPtr:PduR_LoTpCopyTxData_test
TEST.END

-- Test Case: PduR_LoTpCopyTxData.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyTxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyTxData.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyTxDataFunctPtr:PduR_LoTpCopyTxData_test
TEST.VALUE:PduR.PduR_LoTpCopyTxData.info:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyTxDataFunctPtr:PduR_LoTpCopyTxData_test
TEST.END

-- Test Case: PduR_LoTpCopyTxData.009
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyTxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyTxData.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyTxDataFunctPtr:PduR_LoTpCopyTxData_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].SrcModule:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].SrcPduId:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[1].SrcPduId:6
TEST.VALUE:PduR.PduR_LoTpCopyTxData.info:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyTxDataFunctPtr:PduR_LoTpCopyTxData_test
TEST.END

-- Test Case: PduR_LoTpCopyTxData.010
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpCopyTxData
TEST.NEW
TEST.NAME:PduR_LoTpCopyTxData.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyTxDataFunctPtr:PduR_LoTpCopyTxData_test
TEST.VALUE:PduR.PduR_LoTpCopyTxData.info:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyTxDataFunctPtr:<<null>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyTxDataFunctPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpCopyTxDataFunctPtr:<<null>>
TEST.END

-- Subprogram: PduR_LoTpRxIndication

-- Test Case: PduR_LoTpRxIndication.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpRxIndication
TEST.NEW
TEST.NAME:PduR_LoTpRxIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_LoTpRxIndication.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpRxIndication
TEST.NEW
TEST.NAME:PduR_LoTpRxIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTpRxIndication.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpRxIndication
TEST.NEW
TEST.NAME:PduR_LoTpRxIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTpRxIndication.id:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_LoTpRxIndication.id:6
TEST.END

-- Test Case: PduR_LoTpRxIndication.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpRxIndication
TEST.NEW
TEST.NAME:PduR_LoTpRxIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_LoTpRxIndication.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpRxIndication
TEST.NEW
TEST.NAME:PduR_LoTpRxIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.END

-- Test Case: PduR_LoTpRxIndication.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpRxIndication
TEST.NEW
TEST.NAME:PduR_LoTpRxIndication.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpRxIndicationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpRxIndicationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.END

-- Test Case: PduR_LoTpRxIndication.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpRxIndication
TEST.NEW
TEST.NAME:PduR_LoTpRxIndication.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpRxIndicationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpRxIndicationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.END

-- Test Case: PduR_LoTpRxIndication.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpRxIndication
TEST.NEW
TEST.NAME:PduR_LoTpRxIndication.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpRxIndicationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:7
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpRxIndicationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.END

-- Test Case: PduR_LoTpRxIndication.009
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpRxIndication
TEST.NEW
TEST.NAME:PduR_LoTpRxIndication.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpRxIndicationFunctPtr:<<null>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpRxIndicationFunctPtr:<<null>>
TEST.END

-- Subprogram: PduR_LoTpStartOfReception

-- Test Case: PduR_LoTpStartOfReception.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpStartOfReception
TEST.NEW
TEST.NAME:PduR_LoTpStartOfReception.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_LoTpStartOfReception.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpStartOfReception
TEST.NEW
TEST.NAME:PduR_LoTpStartOfReception.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTpStartOfReception.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpStartOfReception
TEST.NEW
TEST.NAME:PduR_LoTpStartOfReception.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTpStartOfReception.id:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_LoTpStartOfReception.id:6
TEST.END

-- Test Case: PduR_LoTpStartOfReception.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpStartOfReception
TEST.NEW
TEST.NAME:PduR_LoTpStartOfReception.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTpStartOfReception.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTpStartOfReception.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpStartOfReception
TEST.NEW
TEST.NAME:PduR_LoTpStartOfReception.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.VALUE:PduR.PduR_LoTpStartOfReception.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_LoTpStartOfReception.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpStartOfReception
TEST.NEW
TEST.NAME:PduR_LoTpStartOfReception.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.VALUE:PduR.PduR_LoTpStartOfReception.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.END

-- Test Case: PduR_LoTpStartOfReception.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpStartOfReception
TEST.NEW
TEST.NAME:PduR_LoTpStartOfReception.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpStartOfReceptionFunctPtr:PduR_LoTpStartOfReception_test
TEST.VALUE:PduR.PduR_LoTpStartOfReception.info:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpStartOfReceptionFunctPtr:PduR_LoTpStartOfReception_test
TEST.END

-- Test Case: PduR_LoTpStartOfReception.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpStartOfReception
TEST.NEW
TEST.NAME:PduR_LoTpStartOfReception.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTpStartOfReception.info:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTpStartOfReception.009
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpStartOfReception
TEST.NEW
TEST.NAME:PduR_LoTpStartOfReception.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[1].DestModuleId:6
TEST.VALUE:PduR.PduR_LoTpStartOfReception.info:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTpStartOfReception.010
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpStartOfReception
TEST.NEW
TEST.NAME:PduR_LoTpStartOfReception.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpStartOfReceptionFunctPtr:PduR_LoTpStartOfReception
TEST.VALUE:PduR.PduR_LoTpStartOfReception.info:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Subprogram: PduR_LoTpTxConfirmation

-- Test Case: PduR_LoTpTxConfirmation.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTpTxConfirmation.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_LoTpTxConfirmation.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTpTxConfirmation.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTpTxConfirmation.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTpTxConfirmation.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTpTxConfirmation.id:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_LoTpTxConfirmation.id:6
TEST.END

-- Test Case: PduR_LoTpTxConfirmation.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTpTxConfirmation.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_LoTpTxConfirmation.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTpTxConfirmation.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].SrcModule:5
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].SrcModule:5
TEST.END

-- Test Case: PduR_LoTpTxConfirmation.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTpTxConfirmation.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpTxConfirmationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpTxConfirmationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.END

-- Test Case: PduR_LoTpTxConfirmation.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTpTxConfirmation.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpTxConfirmationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpTxConfirmationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.END

-- Test Case: PduR_LoTpTxConfirmation.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTpTxConfirmation.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpTxConfirmationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_SourcePduCfg[0].SrcModule:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpTxConfirmationFunctPtr:PduR_LoTpTxConfirmation_test
TEST.END

-- Test Case: PduR_LoTpTxConfirmation.009
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTpTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTpTxConfirmation.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpTxConfirmationFunctPtr:<<null>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpTpTxConfirmationFunctPtr:<<null>>
TEST.END

-- Subprogram: PduR_LoTriggerTransmit

-- Test Case: PduR_LoTriggerTransmit.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTriggerTransmit
TEST.NEW
TEST.NAME:PduR_LoTriggerTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_LoTriggerTransmit.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTriggerTransmit
TEST.NEW
TEST.NAME:PduR_LoTriggerTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTriggerTransmit.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTriggerTransmit
TEST.NEW
TEST.NAME:PduR_LoTriggerTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTriggerTransmit.TxPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_LoTriggerTransmit.TxPduId:6
TEST.END

-- Test Case: PduR_LoTriggerTransmit.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTriggerTransmit
TEST.NEW
TEST.NAME:PduR_LoTriggerTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTriggerTransmit.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTriggerTransmit
TEST.NEW
TEST.NAME:PduR_LoTriggerTransmit.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].SrcPduId:6
TEST.VALUE:PduR.PduR_LoTriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].SrcPduId:6
TEST.END

-- Test Case: PduR_LoTriggerTransmit.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTriggerTransmit
TEST.NEW
TEST.NAME:PduR_LoTriggerTransmit.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].SrcModule:5
TEST.VALUE:PduR.PduR_LoTriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].SrcModule:5
TEST.END

-- Test Case: PduR_LoTriggerTransmit.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTriggerTransmit
TEST.NEW
TEST.NAME:PduR_LoTriggerTransmit.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfTriggerTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.VALUE:PduR.PduR_LoTriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfTriggerTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.END

-- Subprogram: PduR_LoTxConfirmation

-- Test Case: PduR_LoTxConfirmation.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTxConfirmation.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_LoTxConfirmation.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTxConfirmation.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_LoTxConfirmation.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTxConfirmation.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_LoTxConfirmation.TxPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_LoTxConfirmation.TxPduId:6
TEST.END

-- Test Case: PduR_LoTxConfirmation.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTxConfirmation.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].SrcPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].SrcPduId:6
TEST.END

-- Test Case: PduR_LoTxConfirmation.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTxConfirmation.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].SrcModule:5
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].SrcModule:5
TEST.END

-- Test Case: PduR_LoTxConfirmation.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_LoTxConfirmation
TEST.NEW
TEST.NAME:PduR_LoTxConfirmation.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfTxConfirmationFunctPtr:PduR_LoTxConfirmation_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].UpIfTxConfirmationFunctPtr:PduR_LoTxConfirmation_test
TEST.END

-- Subprogram: PduR_UpCancelReceive

-- Test Case: PduR_UpCancelReceive.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelReceive
TEST.NEW
TEST.NAME:PduR_UpCancelReceive.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_UpCancelReceive.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelReceive
TEST.NEW
TEST.NAME:PduR_UpCancelReceive.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_UpCancelReceive.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelReceive
TEST.NEW
TEST.NAME:PduR_UpCancelReceive.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_UpCancelReceive.RxPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_UpCancelReceive.RxPduId:6
TEST.END

-- Test Case: PduR_UpCancelReceive.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelReceive
TEST.NEW
TEST.NAME:PduR_UpCancelReceive.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.END

-- Test Case: PduR_UpCancelReceive.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelReceive
TEST.NEW
TEST.NAME:PduR_UpCancelReceive.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_UpCancelReceive.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelReceive
TEST.NEW
TEST.NAME:PduR_UpCancelReceive.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.END

-- Test Case: PduR_UpCancelReceive.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelReceive
TEST.NEW
TEST.NAME:PduR_UpCancelReceive.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelReceiveFunctPtr:PduR_UpCancelReceive_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelReceiveFunctPtr:PduR_UpCancelReceive_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.END

-- Test Case: PduR_UpCancelReceive.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelReceive
TEST.NEW
TEST.NAME:PduR_UpCancelReceive.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelReceiveFunctPtr:PduR_UpCancelReceive_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelReceiveFunctPtr:PduR_UpCancelReceive_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.END

-- Test Case: PduR_UpCancelReceive.009
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelReceive
TEST.NEW
TEST.NAME:PduR_UpCancelReceive.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelReceiveFunctPtr:PduR_UpCancelReceive_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelReceiveFunctPtr:PduR_UpCancelReceive_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.END

-- Test Case: PduR_UpCancelReceive.010
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelReceive
TEST.NEW
TEST.NAME:PduR_UpCancelReceive.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelReceiveFunctPtr:PduR_UpCancelReceive_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelReceiveFunctPtr:<<null>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelReceiveFunctPtr:<<null>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelReceiveFunctPtr:<<null>>
TEST.END

-- Subprogram: PduR_UpCancelTransmit

-- Test Case: PduR_UpCancelTransmit.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpCancelTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_UpCancelTransmit.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpCancelTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_UpCancelTransmit.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpCancelTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_UpCancelTransmit.TxPduId:7
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_UpCancelTransmit.TxPduId:7
TEST.END

-- Test Case: PduR_UpCancelTransmit.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpCancelTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.END

-- Subprogram: PduR_UpChangeParameter

-- Test Case: PduR_UpChangeParameter.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpChangeParameter
TEST.NEW
TEST.NAME:PduR_UpChangeParameter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_UpChangeParameter.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpChangeParameter
TEST.NEW
TEST.NAME:PduR_UpChangeParameter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_UpChangeParameter.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpChangeParameter
TEST.NEW
TEST.NAME:PduR_UpChangeParameter.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_UpChangeParameter.id:7
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_UpChangeParameter.id:7
TEST.END

-- Test Case: PduR_UpChangeParameter.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpChangeParameter
TEST.NEW
TEST.NAME:PduR_UpChangeParameter.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.END

-- Test Case: PduR_UpChangeParameter.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpChangeParameter
TEST.NEW
TEST.NAME:PduR_UpChangeParameter.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestStartPduId:6
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_UpChangeParameter.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpChangeParameter
TEST.NEW
TEST.NAME:PduR_UpChangeParameter.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.END

-- Test Case: PduR_UpChangeParameter.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpChangeParameter
TEST.NEW
TEST.NAME:PduR_UpChangeParameter.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpChangeParameterFunctPtr:PduR_UpChangeParameter_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpChangeParameterFunctPtr:PduR_UpChangeParameter_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.END

-- Test Case: PduR_UpChangeParameter.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpChangeParameter
TEST.NEW
TEST.NAME:PduR_UpChangeParameter.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpChangeParameterFunctPtr:PduR_UpChangeParameter_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpChangeParameterFunctPtr:<<null>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpChangeParameterFunctPtr:<<null>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpChangeParameterFunctPtr:<<null>>
TEST.END

-- Test Case: PduR_UpChangeParameter.009
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpChangeParameter
TEST.NEW
TEST.NAME:PduR_UpChangeParameter.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpChangeParameterFunctPtr:PduR_UpChangeParameter_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:7
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[1].DestModuleId:7
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.PduId:1
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_DestPduCfg[1].DestModuleId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_DestPduCfg[2].DestModuleId:7
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpChangeParameterFunctPtr:PduR_UpChangeParameter_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.END

-- Test Case: PduR_UpChangeParameter.010
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpChangeParameter
TEST.NEW
TEST.NAME:PduR_UpChangeParameter.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpChangeParameterFunctPtr:PduR_UpChangeParameter_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpChangeParameterFunctPtr:PduR_UpChangeParameter_test
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.END

-- Subprogram: PduR_UpIfCancelTransmit

-- Test Case: PduR_UpIfCancelTransmit.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpIfCancelTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_UpIfCancelTransmit.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpIfCancelTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.PduR_UpIfCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.END

-- Test Case: PduR_UpIfCancelTransmit.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpIfCancelTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.PduR_UpIfCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_UpIfCancelTransmit.PduRSourcePduCfgPtr[0].DestStartPduId:6
TEST.VALUE:PduR.PduR_UpIfCancelTransmit.PduRSourcePduCfgPtr[0].DestEndPduId:6
TEST.EXPECTED:PduR.PduR_UpIfCancelTransmit.PduRSourcePduCfgPtr[0].DestStartPduId:6
TEST.EXPECTED:PduR.PduR_UpIfCancelTransmit.PduRSourcePduCfgPtr[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_UpIfCancelTransmit.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpIfCancelTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.VALUE:PduR.PduR_UpIfCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.END

-- Test Case: PduR_UpIfCancelTransmit.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpIfCancelTransmit.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.VALUE:PduR.PduR_UpIfCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.END

-- Test Case: PduR_UpIfCancelTransmit.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpIfCancelTransmit.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.VALUE:PduR.PduR_UpIfCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.END

-- Test Case: PduR_UpIfCancelTransmit.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpIfCancelTransmit.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:6
TEST.VALUE:PduR.PduR_UpIfCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.END

-- Test Case: PduR_UpIfCancelTransmit.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpIfCancelTransmit.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfCancelTransmitFunctPtr:<<null>>
TEST.VALUE:PduR.PduR_UpIfCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.END

-- Subprogram: PduR_UpIfTransmit

-- Test Case: PduR_UpIfTransmit.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfTransmit
TEST.NEW
TEST.NAME:PduR_UpIfTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_UpIfTransmit.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfTransmit
TEST.NEW
TEST.NAME:PduR_UpIfTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.END

-- Test Case: PduR_UpIfTransmit.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfTransmit
TEST.NEW
TEST.NAME:PduR_UpIfTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr[0].DestStartPduId:6
TEST.VALUE:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr[0].DestEndPduId:6
TEST.EXPECTED:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr[0].DestStartPduId:6
TEST.EXPECTED:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_UpIfTransmit.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfTransmit
TEST.NEW
TEST.NAME:PduR_UpIfTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.VALUE:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.END

-- Test Case: PduR_UpIfTransmit.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfTransmit
TEST.NEW
TEST.NAME:PduR_UpIfTransmit.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.VALUE:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.END

-- Test Case: PduR_UpIfTransmit.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfTransmit
TEST.NEW
TEST.NAME:PduR_UpIfTransmit.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:7
TEST.VALUE:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:7
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.END

-- Test Case: PduR_UpIfTransmit.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfTransmit
TEST.NEW
TEST.NAME:PduR_UpIfTransmit.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:7
TEST.VALUE:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:7
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.END

-- Test Case: PduR_UpIfTransmit.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfTransmit
TEST.NEW
TEST.NAME:PduR_UpIfTransmit.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:7
TEST.VALUE:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:4
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.END

-- Test Case: PduR_UpIfTransmit.009
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpIfTransmit
TEST.NEW
TEST.NAME:PduR_UpIfTransmit.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:7
TEST.VALUE:PduR.PduR_UpIfTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_UpTransmit
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:4
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_UpTransmit
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:4
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.PduR_ModuleConfig[0].LoIfTransmitFunctPtr:PduR_UpTransmit
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:4
TEST.END

-- Subprogram: PduR_UpTpCancelTransmit

-- Test Case: PduR_UpTpCancelTransmit.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpTpCancelTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_UpTpCancelTransmit.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpTpCancelTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.PduR_UpTpCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.END

-- Test Case: PduR_UpTpCancelTransmit.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpTpCancelTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.PduR_UpTpCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_UpTpCancelTransmit.PduRSourcePduCfgPtr[0].DestStartPduId:6
TEST.VALUE:PduR.PduR_UpTpCancelTransmit.PduRSourcePduCfgPtr[0].DestEndPduId:6
TEST.EXPECTED:PduR.PduR_UpTpCancelTransmit.PduRSourcePduCfgPtr[0].DestStartPduId:6
TEST.EXPECTED:PduR.PduR_UpTpCancelTransmit.PduRSourcePduCfgPtr[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_UpTpCancelTransmit.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpTpCancelTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.VALUE:PduR.PduR_UpTpCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.END

-- Test Case: PduR_UpTpCancelTransmit.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpTpCancelTransmit.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.VALUE:PduR.PduR_UpTpCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.END

-- Test Case: PduR_UpTpCancelTransmit.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpTpCancelTransmit.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:6
TEST.VALUE:PduR.PduR_UpTpCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.END

-- Test Case: PduR_UpTpCancelTransmit.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpTpCancelTransmit.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:4
TEST.VALUE:PduR.PduR_UpTpCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelTransmitFunctPtr:PduR_UpCancelReceive_test
TEST.END

-- Test Case: PduR_UpTpCancelTransmit.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpCancelTransmit
TEST.NEW
TEST.NAME:PduR_UpTpCancelTransmit.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelTransmitFunctPtr:PduR_UpCancelReceive
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:4
TEST.VALUE:PduR.PduR_UpTpCancelTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpCancelTransmitFunctPtr:PduR_UpCancelReceive
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.PduR_ModuleConfig[4].LoTpCancelTransmitFunctPtr:PduR_UpCancelReceive
TEST.END

-- Subprogram: PduR_UpTpTransmit

-- Test Case: PduR_UpTpTransmit.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpTransmit
TEST.NEW
TEST.NAME:PduR_UpTpTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_UpTpTransmit.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpTransmit
TEST.NEW
TEST.NAME:PduR_UpTpTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.PduR_UpTpTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.END

-- Test Case: PduR_UpTpTransmit.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpTransmit
TEST.NEW
TEST.NAME:PduR_UpTpTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.PduR_UpTpTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_UpTpTransmit.PduRSourcePduCfgPtr[0].DestStartPduId:6
TEST.VALUE:PduR.PduR_UpTpTransmit.PduRSourcePduCfgPtr[0].DestEndPduId:6
TEST.EXPECTED:PduR.PduR_UpTpTransmit.PduRSourcePduCfgPtr[0].DestStartPduId:6
TEST.EXPECTED:PduR.PduR_UpTpTransmit.PduRSourcePduCfgPtr[0].DestEndPduId:6
TEST.END

-- Test Case: PduR_UpTpTransmit.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpTransmit
TEST.NEW
TEST.NAME:PduR_UpTpTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.VALUE:PduR.PduR_UpTpTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:5
TEST.END

-- Test Case: PduR_UpTpTransmit.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpTransmit
TEST.NEW
TEST.NAME:PduR_UpTpTransmit.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.VALUE:PduR.PduR_UpTpTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.END

-- Test Case: PduR_UpTpTransmit.006
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpTransmit
TEST.NEW
TEST.NAME:PduR_UpTpTransmit.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.VALUE:PduR.PduR_UpTpTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.END

-- Test Case: PduR_UpTpTransmit.007
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpTransmit
TEST.NEW
TEST.NAME:PduR_UpTpTransmit.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.VALUE:PduR.<<GLOBAL>>.PduR_DestPduCfg[0].DestModuleId:7
TEST.VALUE:PduR.PduR_UpTpTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpTransmitFunctPtr:PduR_LoTriggerTransmit_test
TEST.END

-- Test Case: PduR_UpTpTransmit.008
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTpTransmit
TEST.NEW
TEST.NAME:PduR_UpTpTransmit.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.STUB:PduR.PduR_IsDestPduGroupEnabled
TEST.VALUE:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpTransmitFunctPtr:<<null>>
TEST.VALUE:PduR.PduR_UpTpTransmit.PduRSourcePduCfgPtr:<<malloc 1>>
TEST.VALUE:PduR.PduR_IsDestPduGroupEnabled.return:1
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_ModuleConfig[0].LoTpTransmitFunctPtr:<<null>>
TEST.END

-- Subprogram: PduR_UpTransmit

-- Test Case: PduR_UpTransmit.001
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTransmit
TEST.NEW
TEST.NAME:PduR_UpTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.END

-- Test Case: PduR_UpTransmit.002
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTransmit
TEST.NEW
TEST.NAME:PduR_UpTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_UpTransmit.003
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTransmit
TEST.NEW
TEST.NAME:PduR_UpTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_UpTransmit.TxPduId:7
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.PduR_UpTransmit.TxPduId:7
TEST.END

-- Test Case: PduR_UpTransmit.004
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTransmit
TEST.NEW
TEST.NAME:PduR_UpTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.PduR_UpTransmit.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.END

-- Test Case: PduR_UpTransmit.005
TEST.UNIT:PduR
TEST.SUBPROGRAM:PduR_UpTransmit
TEST.NEW
TEST.NAME:PduR_UpTransmit.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::PduR::PduR_Detailed_Design::PduR_Class_Diagram 
Requirement_DICVA-13791
TEST.END_NOTES:
TEST.VALUE:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.VALUE:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.VALUE:PduR.PduR_UpTransmit.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_InitStatus:PDUR_ONLINE
TEST.EXPECTED:PduR.<<GLOBAL>>.PduR_SourcePduCfg[0].PduType:1
TEST.END
