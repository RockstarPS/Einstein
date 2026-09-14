-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : COM_VCAST_HT
-- Unit(s) Under Test: Com
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: Com

-- Subprogram: Com_ActivateRxIpdu

-- Test Case: Com_ActivateRxIpdu.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ActivateRxIpdu
TEST.NEW
TEST.NAME:Com_ActivateRxIpdu.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ActivateRxIpdu.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ActivateRxIpdu
TEST.NEW
TEST.NAME:Com_ActivateRxIpdu.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ActivateRxIpdu.RxIpduId:2
TEST.EXPECTED:Com.Com_ActivateRxIpdu.RxIpduId:2
TEST.END

-- Subprogram: Com_ActivateTxIpdu

-- Test Case: Com_ActivateTxIpdu.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ActivateTxIpdu
TEST.NEW
TEST.NAME:Com_ActivateTxIpdu.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ActivateTxIpdu.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ActivateTxIpdu
TEST.NEW
TEST.NAME:Com_ActivateTxIpdu.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ActivateTxIpdu.TxIpduId:1
TEST.EXPECTED:Com.Com_ActivateTxIpdu.TxIpduId:1
TEST.END

-- Test Case: Com_ActivateTxIpdu.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ActivateTxIpdu
TEST.NEW
TEST.NAME:Com_ActivateTxIpdu.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ActivateTxIpdu.Initialize:1
TEST.EXPECTED:Com.Com_ActivateTxIpdu.Initialize:1
TEST.END

-- Subprogram: Com_ClearUpdateBits

-- Test Case: Com_ClearUpdateBits.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ClearUpdateBits
TEST.NEW
TEST.NAME:Com_ClearUpdateBits.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ClearUpdateBits.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ClearUpdateBits
TEST.NEW
TEST.NAME:Com_ClearUpdateBits.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].UBConfigId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].UBConfigId:1
TEST.END

-- Subprogram: Com_CopyRxData

-- Test Case: Com_CopyRxData.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyRxData
TEST.NEW
TEST.NAME:Com_CopyRxData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_CopyRxData.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_COPYRXDATA
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_CopyRxData.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyRxData
TEST.NEW
TEST.NAME:Com_CopyRxData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_CopyRxData.id:COM_NUM_OF_RX_IPDU_ID
TEST.EXPECTED:Com.Com_CopyRxData.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_COPYRXDATA
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_CopyRxData.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyRxData
TEST.NEW
TEST.NAME:Com_CopyRxData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_CopyRxData.id:0
TEST.VALUE:Com.Com_CopyRxData.info:<<null>>
TEST.VALUE:Com.Com_CopyRxData.bufferSizePtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_CopyRxData.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_COPYRXDATA
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_CopyRxData.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyRxData
TEST.NEW
TEST.NAME:Com_CopyRxData.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_CopyRxData.id:0
TEST.VALUE:Com.Com_CopyRxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyRxData.info[0].SduDataPtr:<<malloc 9>>
TEST.VALUE:Com.Com_CopyRxData.info[0].SduDataPtr:<<null>>
TEST.VALUE:Com.Com_CopyRxData.info[0].SduLength:0
TEST.VALUE:Com.Com_CopyRxData.bufferSizePtr:<<null>>
TEST.EXPECTED:Com.Com_CopyRxData.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_COPYRXDATA
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_CopyRxData.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyRxData
TEST.NEW
TEST.NAME:Com_CopyRxData.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_CopyRxData.id:0
TEST.VALUE:Com.Com_CopyRxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyRxData.info[0].SduDataPtr:<<malloc 9>>
TEST.VALUE:Com.Com_CopyRxData.info[0].SduDataPtr:<<null>>
TEST.VALUE:Com.Com_CopyRxData.info[0].SduLength:2
TEST.VALUE:Com.Com_CopyRxData.bufferSizePtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_CopyRxData.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_COPYRXDATA
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_CopyRxData.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyRxData
TEST.NEW
TEST.NAME:Com_CopyRxData.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:FALSE
TEST.VALUE:Com.Com_CopyRxData.id:0
TEST.VALUE:Com.Com_CopyRxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyRxData.bufferSizePtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.EXPECTED:Com.Com_CopyRxData.return:BUFREQ_E_NOT_OK
TEST.END

-- Test Case: Com_CopyRxData.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyRxData
TEST.NEW
TEST.NAME:Com_CopyRxData.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:Com.Com_CopyRxData.id:0
TEST.VALUE:Com.Com_CopyRxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyRxData.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_CopyRxData.info[0].SduLength:2
TEST.VALUE:Com.Com_CopyRxData.bufferSizePtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.EXPECTED:Com.Com_CopyRxData.return:BUFREQ_E_NOT_OK
TEST.END

-- Subprogram: Com_CopyTxData

-- Test Case: Com_CopyTxData.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_COPYTXDATA
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_CopyTxData.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.END

-- Test Case: Com_CopyTxData.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_CopyTxData.id:2
TEST.EXPECTED:Com.Com_CopyTxData.id:2
TEST.END

-- Test Case: Com_CopyTxData.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.END

-- Test Case: Com_CopyTxData.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduDataPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_CopyTxData.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduLength:1
TEST.EXPECTED:Com.Com_CopyTxData.info[0].SduLength:1
TEST.END

-- Test Case: Com_CopyTxData.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.availableDataPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_CopyTxData.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.availableDataPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.END

-- Test Case: Com_CopyTxData.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.availableDataPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.END

-- Test Case: Com_CopyTxData.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.retry:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.availableDataPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.END

-- Test Case: Com_CopyTxData.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.retry:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.retry[0].TpDataState:TP_DATARETRY
TEST.VALUE:Com.Com_CopyTxData.availableDataPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.Com_CopyTxData.retry[0].TpDataState:TP_DATARETRY
TEST.END

-- Test Case: Com_CopyTxData.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.availableDataPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:4
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.END

-- Test Case: Com_CopyTxData.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduLength:1
TEST.VALUE:Com.Com_CopyTxData.availableDataPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.Com_CopyTxData.info[0].SduLength:1
TEST.END

-- Test Case: Com_CopyTxData.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxTpIpduBufferConfig[0].BufferStartId:1
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.availableDataPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxTpIpduBufferConfig[0].BufferStartId:1
TEST.END

-- Test Case: Com_CopyTxData.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.availableDataPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:4
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.END

-- Test Case: Com_CopyTxData.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_CopyTxData
TEST.NEW
TEST.NAME:Com_CopyTxData.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.Com_CopyTxData.info:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_CopyTxData.info[0].SduLength:1
TEST.VALUE:Com.Com_CopyTxData.availableDataPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.Com_CopyTxData.info[0].SduLength:1
TEST.END

-- Subprogram: Com_DeInit

-- Test Case: Com_DeInit.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DeInit
TEST.NEW
TEST.NAME:Com_DeInit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_DEINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_DeInit.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DeInit
TEST.NEW
TEST.NAME:Com_DeInit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:TRUE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:FALSE
TEST.END

-- Test Case: Com_DeInit.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DeInit
TEST.NEW
TEST.NAME:Com_DeInit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:TRUE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:FALSE
TEST.END

-- Test Case: Com_DeInit.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DeInit
TEST.NEW
TEST.NAME:Com_DeInit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:0
TEST.END

-- Subprogram: Com_DeactivateRxIpdu

-- Test Case: Com_DeactivateRxIpdu.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DeactivateRxIpdu
TEST.NEW
TEST.NAME:Com_DeactivateRxIpdu.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Subprogram: Com_DeactivateTxIpdu

-- Test Case: Com_DeactivateTxIpdu.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DeactivateTxIpdu
TEST.NEW
TEST.NAME:Com_DeactivateTxIpdu.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_DeactivateTxIpdu.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DeactivateTxIpdu
TEST.NEW
TEST.NAME:Com_DeactivateTxIpdu.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_DeactivateTxIpdu.TxIpduId:1
TEST.EXPECTED:Com.Com_DeactivateTxIpdu.TxIpduId:1
TEST.END

-- Test Case: Com_DeactivateTxIpdu.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DeactivateTxIpdu
TEST.NEW
TEST.NAME:Com_DeactivateTxIpdu.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:1
TEST.END

-- Test Case: Com_DeactivateTxIpdu.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DeactivateTxIpdu
TEST.NEW
TEST.NAME:Com_DeactivateTxIpdu.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:1
TEST.END

-- Subprogram: Com_DisableReceptionDM

-- Test Case: Com_DisableReceptionDM.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DisableReceptionDM
TEST.NEW
TEST.NAME:Com_DisableReceptionDM.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_DisableReceptionDM.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DisableReceptionDM
TEST.NEW
TEST.NAME:Com_DisableReceptionDM.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.END

-- Test Case: Com_DisableReceptionDM.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DisableReceptionDM
TEST.NEW
TEST.NAME:Com_DisableReceptionDM.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_DisableReceptionDM.IpduGroupId:4
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.Com_DisableReceptionDM.IpduGroupId:4
TEST.END

-- Test Case: Com_DisableReceptionDM.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_DisableReceptionDM
TEST.NEW
TEST.NAME:Com_DisableReceptionDM.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[0].IpduGroupVectorMap[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[0].IpduGroupVectorMap[0]:1
TEST.END

-- Subprogram: Com_EnableReceptionDM

-- Test Case: Com_EnableReceptionDM.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_EnableReceptionDM
TEST.NEW
TEST.NAME:Com_EnableReceptionDM.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_EnableReceptionDM.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_EnableReceptionDM
TEST.NEW
TEST.NAME:Com_EnableReceptionDM.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.END

-- Test Case: Com_EnableReceptionDM.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_EnableReceptionDM
TEST.NEW
TEST.NAME:Com_EnableReceptionDM.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_EnableReceptionDM.IpduGroupId:4
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.Com_EnableReceptionDM.IpduGroupId:4
TEST.END

-- Test Case: Com_EnableReceptionDM.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_EnableReceptionDM
TEST.NEW
TEST.NAME:Com_EnableReceptionDM.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[0].IpduGroupVectorMap[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[0].IpduGroupVectorMap[0]:1
TEST.END

-- Subprogram: Com_GetStatus

-- Test Case: Com_GetStatus.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_GetStatus
TEST.NEW
TEST.NAME:Com_GetStatus.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:VARY FROM:COM_UNINIT TO:COM_INIT BY: 1
TEST.EXPECTED:Com.Com_GetStatus.return:COM_UNINIT..COM_INIT
TEST.END

-- Subprogram: Com_GetVersionInfo

-- Test Case: Com_GetVersionInfo.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_GetVersionInfo
TEST.NEW
TEST.NAME:Com_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_GetVersionInfo.VersionInfo:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_GETVERSIONINFO
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_GetVersionInfo.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_GetVersionInfo
TEST.NEW
TEST.NAME:Com_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_GetVersionInfo.VersionInfo:<<malloc 1>>
TEST.VALUE:Com.Com_GetVersionInfo.VersionInfo[0].vendorID:0
TEST.VALUE:Com.Com_GetVersionInfo.VersionInfo[0].moduleID:0
TEST.VALUE:Com.Com_GetVersionInfo.VersionInfo[0].sw_major_version:0
TEST.VALUE:Com.Com_GetVersionInfo.VersionInfo[0].sw_minor_version:0
TEST.VALUE:Com.Com_GetVersionInfo.VersionInfo[0].sw_patch_version:0
TEST.EXPECTED:Com.Com_GetVersionInfo.VersionInfo[0].vendorID:COM_VENDOR_ID
TEST.EXPECTED:Com.Com_GetVersionInfo.VersionInfo[0].moduleID:COM_MODULE_ID
TEST.EXPECTED:Com.Com_GetVersionInfo.VersionInfo[0].sw_major_version:COM_SW_MAJOR_VERSION
TEST.EXPECTED:Com.Com_GetVersionInfo.VersionInfo[0].sw_minor_version:COM_SW_MINOR_VERSION
TEST.EXPECTED:Com.Com_GetVersionInfo.VersionInfo[0].sw_patch_version:COM_SW_PATCH_VERSION
TEST.END

-- Subprogram: Com_Init

-- Test Case: Com_Init.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_Init
TEST.NEW
TEST.NAME:Com_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_Init.config:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_Init.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_Init
TEST.NEW
TEST.NAME:Com_Init.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.VALUE:Com.Com_Init.config:<<null>>
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.END

-- Subprogram: Com_InitRxIPduProperties

-- Test Case: Com_InitRxIPduProperties.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitRxIPduProperties
TEST.NEW
TEST.NAME:Com_InitRxIPduProperties.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_InitRxIPduProperties.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitRxIPduProperties
TEST.NEW
TEST.NAME:Com_InitRxIPduProperties.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_InitRxIPduProperties.RxIpduId:2
TEST.EXPECTED:Com.Com_InitRxIPduProperties.RxIpduId:2
TEST.END

-- Test Case: Com_InitRxIPduProperties.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitRxIPduProperties
TEST.NEW
TEST.NAME:Com_InitRxIPduProperties.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_InitRxIPduProperties.InitBuffer:1
TEST.EXPECTED:Com.Com_InitRxIPduProperties.InitBuffer:1
TEST.END

-- Test Case: Com_InitRxIPduProperties.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitRxIPduProperties
TEST.NEW
TEST.NAME:Com_InitRxIPduProperties.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MetaDataLength:8
TEST.VALUE:Com.Com_InitRxIPduProperties.InitBuffer:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MetaDataLength:8
TEST.EXPECTED:Com.Com_InitRxIPduProperties.InitBuffer:1
TEST.END

-- Test Case: Com_InitRxIPduProperties.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitRxIPduProperties
TEST.NEW
TEST.NAME:Com_InitRxIPduProperties.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:8
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MetaDataLength:8
TEST.VALUE:Com.Com_InitRxIPduProperties.InitBuffer:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MetaDataLength:8
TEST.EXPECTED:Com.Com_InitRxIPduProperties.InitBuffer:1
TEST.END

-- Test Case: Com_InitRxIPduProperties.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitRxIPduProperties
TEST.NEW
TEST.NAME:Com_InitRxIPduProperties.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:8
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MetaDataLength:8
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.VALUE:Com.Com_InitRxIPduProperties.InitBuffer:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MetaDataLength:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.EXPECTED:Com.Com_InitRxIPduProperties.InitBuffer:1
TEST.END

-- Subprogram: Com_InitRxIpdu

-- Test Case: Com_InitRxIpdu.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitRxIpdu
TEST.NEW
TEST.NAME:Com_InitRxIpdu.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_InitRxIpdu.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitRxIpdu
TEST.NEW
TEST.NAME:Com_InitRxIpdu.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].NoIpduGroupSupported:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].NoIpduGroupSupported:1
TEST.END

-- Subprogram: Com_InitTxDeadlineMonitoring

-- Test Case: Com_InitTxDeadlineMonitoring.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxDeadlineMonitoring
TEST.NEW
TEST.NAME:Com_InitTxDeadlineMonitoring.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Subprogram: Com_InitTxIpdu

-- Test Case: Com_InitTxIpdu.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpdu
TEST.NEW
TEST.NAME:Com_InitTxIpdu.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_InitTxIpdu.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpdu
TEST.NEW
TEST.NAME:Com_InitTxIpdu.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].NoIpduGroupSupported:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].NoIpduGroupSupported:1
TEST.END

-- Subprogram: Com_InitTxIpduBuffer

-- Test Case: Com_InitTxIpduBuffer.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduBuffer
TEST.NEW
TEST.NAME:Com_InitTxIpduBuffer.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_InitTxIpduBuffer.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduBuffer
TEST.NEW
TEST.NAME:Com_InitTxIpduBuffer.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_InitTxIpduBuffer.TxIpduId:1
TEST.EXPECTED:Com.Com_InitTxIpduBuffer.TxIpduId:1
TEST.END

-- Test Case: Com_InitTxIpduBuffer.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduBuffer
TEST.NEW
TEST.NAME:Com_InitTxIpduBuffer.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.END

-- Test Case: Com_InitTxIpduBuffer.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduBuffer
TEST.NEW
TEST.NAME:Com_InitTxIpduBuffer.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.END

-- Test Case: Com_InitTxIpduBuffer.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduBuffer
TEST.NEW
TEST.NAME:Com_InitTxIpduBuffer.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].SignalGroupStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].SignalGroupStartId:1
TEST.END

-- Test Case: Com_InitTxIpduBuffer.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduBuffer
TEST.NEW
TEST.NAME:Com_InitTxIpduBuffer.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].SignalGroupEndId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].SignalGroupEndId:1
TEST.END

-- Subprogram: Com_InitTxIpduProperties

-- Test Case: Com_InitTxIpduProperties.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduProperties
TEST.NEW
TEST.NAME:Com_InitTxIpduProperties.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_InitTxIpduProperties.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduProperties
TEST.NEW
TEST.NAME:Com_InitTxIpduProperties.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_InitTxIpduProperties.TxIpduId:1
TEST.EXPECTED:Com.Com_InitTxIpduProperties.TxIpduId:1
TEST.END

-- Test Case: Com_InitTxIpduProperties.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduProperties
TEST.NEW
TEST.NAME:Com_InitTxIpduProperties.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.END

-- Test Case: Com_InitTxIpduProperties.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduProperties
TEST.NEW
TEST.NAME:Com_InitTxIpduProperties.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.VALUE:Com.Com_InitTxIpduProperties.IsInitTxMode:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.Com_InitTxIpduProperties.IsInitTxMode:1
TEST.END

-- Subprogram: Com_InitTxIpduTxModeProperties

-- Test Case: Com_InitTxIpduTxModeProperties.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduTxModeProperties
TEST.NEW
TEST.NAME:Com_InitTxIpduTxModeProperties.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:FALSE
TEST.VALUE:Com.Com_InitTxIpduTxModeProperties.TxIpduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutValue:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TargetIpduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxPeriodicCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:COM_TX_MODE_MODE_TYPE_PERIODIC
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].RepetitionCount:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].RepetitionPeriod:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TimeOffset:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TimePeriod:1000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].TxModeModeType:COM_TX_MODE_MODE_TYPE_DIRECT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].RepetitionCount:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].RepetitionPeriod:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].TimeOffset:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].TimePeriod:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduRepetitionCount[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduRepetitionCycleCounter[0]:0
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_TxIpduBuffer[9]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferInitValues[10]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferInitValues[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferInitValues[1]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferInitValues[2]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferInitValues[3]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferInitValues[4]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferInitValues[5]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferInitValues[6]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferInitValues[7]:INPUT_BASE=16
TEST.END

-- Test Case: Com_InitTxIpduTxModeProperties.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduTxModeProperties
TEST.NEW
TEST.NAME:Com_InitTxIpduTxModeProperties.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_InitTxIpduTxModeProperties.TxIpduId:23
TEST.EXPECTED:Com.Com_InitTxIpduTxModeProperties.TxIpduId:23
TEST.END

-- Test Case: Com_InitTxIpduTxModeProperties.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduTxModeProperties
TEST.NEW
TEST.NAME:Com_InitTxIpduTxModeProperties.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_InitTxIpduTxModeProperties.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduTxModeProperties
TEST.NEW
TEST.NAME:Com_InitTxIpduTxModeProperties.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:2
TEST.END

-- Test Case: Com_InitTxIpduTxModeProperties.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduTxModeProperties
TEST.NEW
TEST.NAME:Com_InitTxIpduTxModeProperties.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:3
TEST.END

-- Test Case: Com_InitTxIpduTxModeProperties.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduTxModeProperties
TEST.NEW
TEST.NAME:Com_InitTxIpduTxModeProperties.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:3
TEST.END

-- Test Case: Com_InitTxIpduTxModeProperties.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InitTxIpduTxModeProperties
TEST.NEW
TEST.NAME:Com_InitTxIpduTxModeProperties.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:1
TEST.END

-- Subprogram: Com_InvalidateSignal

-- Test Case: Com_InvalidateSignal.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InvalidateSignal
TEST.NEW
TEST.NAME:Com_InvalidateSignal.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_InvalidateSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_INVALIDATESIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_InvalidateSignal.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InvalidateSignal
TEST.NEW
TEST.NAME:Com_InvalidateSignal.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_InvalidateSignal.SignalId:COM_NUM_OF_TX_SIGNAL_ID
TEST.EXPECTED:Com.Com_InvalidateSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_INVALIDATESIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_InvalidateSignal.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InvalidateSignal
TEST.NEW
TEST.NAME:Com_InvalidateSignal.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_InvalidateSignal.SignalId:0
TEST.END

-- Subprogram: Com_InvalidateSignalGroup

-- Test Case: Com_InvalidateSignalGroup.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InvalidateSignalGroup
TEST.NEW
TEST.NAME:Com_InvalidateSignalGroup.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_InvalidateSignalGroup.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_INVALIDATESIGNALGROUP
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_InvalidateSignalGroup.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InvalidateSignalGroup
TEST.NEW
TEST.NAME:Com_InvalidateSignalGroup.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_InvalidateSignalGroup.SignalGroupId:COM_NUM_OF_TX_SIGNAL_GROUP_ID
TEST.EXPECTED:Com.Com_InvalidateSignalGroup.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_INVALIDATESIGNALGROUP
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_InvalidateSignalGroup.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_InvalidateSignalGroup
TEST.NEW
TEST.NAME:Com_InvalidateSignalGroup.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_InvalidateSignalGroup.SignalGroupId:0
TEST.END

-- Subprogram: Com_IpduGroupStart

-- Test Case: Com_IpduGroupStart.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStart
TEST.NEW
TEST.NAME:Com_IpduGroupStart.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_IpduGroupStart.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStart
TEST.NEW
TEST.NAME:Com_IpduGroupStart.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.END

-- Test Case: Com_IpduGroupStart.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStart
TEST.NEW
TEST.NAME:Com_IpduGroupStart.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_IpduGroupStart.IpduGroupId:4
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.Com_IpduGroupStart.IpduGroupId:4
TEST.END

-- Test Case: Com_IpduGroupStart.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStart
TEST.NEW
TEST.NAME:Com_IpduGroupStart.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.END

-- Test Case: Com_IpduGroupStart.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStart
TEST.NEW
TEST.NAME:Com_IpduGroupStart.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapTxConfig[0].IpduGroupVectorMap[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapTxConfig[0].IpduGroupVectorMap[0]:1
TEST.END

-- Test Case: Com_IpduGroupStart.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStart
TEST.NEW
TEST.NAME:Com_IpduGroupStart.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.END

-- Test Case: Com_IpduGroupStart.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStart
TEST.NEW
TEST.NAME:Com_IpduGroupStart.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[0].IpduGroupVectorMap[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[0].IpduGroupVectorMap[0]:1
TEST.END

-- Subprogram: Com_IpduGroupStop

-- Test Case: Com_IpduGroupStop.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStop
TEST.NEW
TEST.NAME:Com_IpduGroupStop.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_IpduGroupStop.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStop
TEST.NEW
TEST.NAME:Com_IpduGroupStop.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.END

-- Test Case: Com_IpduGroupStop.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStop
TEST.NEW
TEST.NAME:Com_IpduGroupStop.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_IpduGroupStop.IpduGroupId:4
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.Com_IpduGroupStop.IpduGroupId:4
TEST.END

-- Test Case: Com_IpduGroupStop.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStop
TEST.NEW
TEST.NAME:Com_IpduGroupStop.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.END

-- Test Case: Com_IpduGroupStop.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStop
TEST.NEW
TEST.NAME:Com_IpduGroupStop.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapTxConfig[0].IpduGroupVectorMap[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapTxConfig[0].IpduGroupVectorMap[0]:1
TEST.END

-- Test Case: Com_IpduGroupStop.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStop
TEST.NEW
TEST.NAME:Com_IpduGroupStop.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.END

-- Test Case: Com_IpduGroupStop.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduGroupStop
TEST.NEW
TEST.NAME:Com_IpduGroupStop.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[0].IpduGroupVectorMap[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[0].IpduGroupVectorMap[0]:1
TEST.END

-- Subprogram: Com_IpduTxTransmit

-- Test Case: Com_IpduTxTransmit.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:COM_NUM_OF_TX_IPDU_ID
TEST.EXPECTED:Com.Com_IpduTxTransmit.return:E_NOT_OK
TEST.END

-- Test Case: Com_IpduTxTransmit.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:1
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xAA
TEST.VALUE:uut_prototype_stubs.PduR_ComTransmit.return:E_OK
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:TRUE
TEST.EXPECTED:Com.Com_IpduTxTransmit.return:E_OK
TEST.END

-- Test Case: Com_IpduTxTransmit.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xAA
TEST.VALUE:uut_prototype_stubs.PduR_ComTransmit.return:E_NOT_OK
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:FALSE
TEST.EXPECTED:Com.Com_IpduTxTransmit.return:E_NOT_OK
TEST.END

-- Test Case: Com_IpduTxTransmit.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:COM_TX_IPDU_BUFFER_SIZE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:COM_TX_IPDU_BUFFER_SIZE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xAA
TEST.VALUE:uut_prototype_stubs.PduR_ComTransmit.return:E_OK
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:FALSE
TEST.EXPECTED:Com.Com_IpduTxTransmit.return:E_NOT_OK
TEST.END

-- Test Case: Com_IpduTxTransmit.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xAA
TEST.VALUE:uut_prototype_stubs.PduR_ComTransmit.return:E_OK
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.END

-- Test Case: Com_IpduTxTransmit.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xAA
TEST.VALUE:uut_prototype_stubs.PduR_ComTransmit.return:E_NOT_OK
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:FALSE
TEST.EXPECTED:Com.Com_IpduTxTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduCalloutFunctId:1
TEST.END

-- Test Case: Com_IpduTxTransmit.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduCalloutFuncConfig[0]:PduR_ComTransmit
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xAA
TEST.VALUE:uut_prototype_stubs.PduR_ComTransmit.return:E_NOT_OK
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduCalloutFuncConfig[0]:PduR_ComTransmit
TEST.EXPECTED:Com.Com_IpduTxTransmit.return:E_NOT_OK
TEST.END

-- Test Case: Com_IpduTxTransmit.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_TriggerTransmit
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduCalloutFuncConfig[0]:Com_TriggerTransmit
TEST.VALUE:Com.Com_TriggerTransmit.return:0
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xAA
TEST.VALUE:uut_prototype_stubs.PduR_ComTransmit.return:E_NOT_OK
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduCalloutFuncConfig[0]:Com_TriggerTransmit
TEST.END

-- Test Case: Com_IpduTxTransmit.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:1
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xAA
TEST.VALUE:uut_prototype_stubs.PduR_ComTransmit.return:E_OK
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:TRUE
TEST.EXPECTED:Com.Com_IpduTxTransmit.return:E_OK
TEST.END

-- Test Case: Com_IpduTxTransmit.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:1
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xAA
TEST.VALUE:uut_prototype_stubs.PduR_ComTransmit.return:E_OK
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:TRUE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:0
TEST.EXPECTED:Com.Com_IpduTxTransmit.return:E_OK
TEST.END

-- Test Case: Com_IpduTxTransmit.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_TriggerTransmit
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduCalloutFuncConfig[0]:Com_TriggerTransmit
TEST.VALUE:Com.Com_TriggerTransmit.return:0
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MetaDataLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xAA
TEST.VALUE:uut_prototype_stubs.PduR_ComTransmit.return:E_NOT_OK
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduCalloutFuncConfig[0]:Com_TriggerTransmit
TEST.END

-- Test Case: Com_IpduTxTransmit.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IpduTxTransmit
TEST.NEW
TEST.NAME:Com_IpduTxTransmit.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:0
TEST.VALUE:Com.Com_IpduTxTransmit.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xAA
TEST.VALUE:uut_prototype_stubs.PduR_ComTransmit.return:E_OK
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:TRUE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:0
TEST.EXPECTED:Com.Com_IpduTxTransmit.return:E_OK
TEST.END

-- Subprogram: Com_IsTxSignalDataChanged

-- Test Case: Com_IsTxSignalDataChanged.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:212
TEST.EXPECTED:Com.Com_IsTxSignalDataChanged.SignalId:212
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_BOOLEAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.EXPECTED:Com.Com_IsTxSignalDataChanged.return:TRUE
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_FLOAT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:4
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:<<null>>
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT16
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:16
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:2
TEST.EXPECTED:Com.Com_IsTxSignalDataChanged.return:TRUE
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:24
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:3
TEST.EXPECTED:Com.Com_IsTxSignalDataChanged.return:TRUE
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:4
TEST.EXPECTED:Com.Com_IsTxSignalDataChanged.return:TRUE
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8_N
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:8
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:23
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:23
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT16
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:2
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:3
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8_N
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:0
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:8
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:4
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:6
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:8
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.017
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.017
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:8
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.018
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.018
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:8
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.019
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.019
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:9
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:8
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.020
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.020
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:8
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.021
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.021
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:8
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.022
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.022
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_FLOAT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:4
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.023
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.023
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[1].SignalType:12
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[1].ByteLength:1
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:1
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_BUFFER
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8_N
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[1].SignalType:12
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[1].ByteLength:1
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.024
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.024
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[1].SignalType:12
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[1].ByteLength:1
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:1
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_STR1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8_N
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[1].SignalType:12
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[1].ByteLength:1
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.025
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.025
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:4
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.026
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.026
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:4
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.END

-- Test Case: Com_IsTxSignalDataChanged.027
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_IsTxSignalDataChanged
TEST.NEW
TEST.NAME:Com_IsTxSignalDataChanged.027
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferLength[0]:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:20
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalId:0
TEST.VALUE:Com.Com_IsTxSignalDataChanged.SignalDataPtr:VECTORCAST_INT2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:4
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:20
TEST.END

-- Subprogram: Com_MainFunctionRouteSignals

-- Test Case: Com_MainFunctionRouteSignals.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRouteSignals
TEST.NEW
TEST.NAME:Com_MainFunctionRouteSignals.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.END

-- Subprogram: Com_MainFunctionRx

-- Test Case: Com_MainFunctionRx.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_MAINFUNCTIONRX
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_MainFunctionRx.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:FALSE
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:10
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:TRUE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:TRUE
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:TRUE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:TRUE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:0
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxToutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxToutFunctId:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[1]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_CbkRxToutFunctConfig[0]:Com_MainFunctionRx
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_CbkRxToutFunctConfig[0]:Com_MainFunctionRx
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:2
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:3
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSigGroupTimeoutCounterConfig[0].SignalGroupId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSigGroupTimeoutCounterConfig[0].SignalGroupId:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxDataTimeoutActionType:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxDataTimeoutActionType:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxDataTimeoutActionType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxToutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxDataTimeoutActionType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxToutFunctId:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_MainFunctionRx.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionRx
TEST.NEW
TEST.NAME:Com_MainFunctionRx.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_CbkRxToutFunctConfig[0]:ResumeAllInterrupts
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxDataTimeoutActionType:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_IMMEDIATE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:FALSE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterEndId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_CbkRxToutFunctConfig[0]:ResumeAllInterrupts
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxDataTimeoutActionType:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Subprogram: Com_MainFunctionTx

-- Test Case: Com_MainFunctionTx.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionTx
TEST.NEW
TEST.NAME:Com_MainFunctionTx.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_MAINFUNCTIONTX
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_MainFunctionTx.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionTx
TEST.NEW
TEST.NAME:Com_MainFunctionTx.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduDefferedNotificationStatus[0]:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutValue:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TargetIpduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxPeriodicCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduDefferedNotificationStatus[0]:FALSE
TEST.END

-- Test Case: Com_MainFunctionTx.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_MainFunctionTx
TEST.NEW
TEST.NAME:Com_MainFunctionTx.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduDefferedNotificationStatus[0]:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutValue:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TargetIpduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxPeriodicCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduDefferedNotificationStatus[0]:0
TEST.END

-- Subprogram: Com_ProcessBooleanSignalFilter

-- Test Case: Com_ProcessBooleanSignalFilter.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessBooleanSignalFilter
TEST.NEW
TEST.NAME:Com_ProcessBooleanSignalFilter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_ProcessBooleanSignalFilter.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessBooleanSignalFilter
TEST.NEW
TEST.NAME:Com_ProcessBooleanSignalFilter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.END

-- Test Case: Com_ProcessBooleanSignalFilter.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessBooleanSignalFilter
TEST.NEW
TEST.NAME:Com_ProcessBooleanSignalFilter.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterXBufferId:1
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterXBufferId:1
TEST.END

-- Test Case: Com_ProcessBooleanSignalFilter.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessBooleanSignalFilter
TEST.NEW
TEST.NAME:Com_ProcessBooleanSignalFilter.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessBooleanSignalFilter.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessBooleanSignalFilter
TEST.NEW
TEST.NAME:Com_ProcessBooleanSignalFilter.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr[0]:0
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_BooleanFilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr[0]:0
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_BooleanFilterXValueConfig[0]:1
TEST.END

-- Test Case: Com_ProcessBooleanSignalFilter.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessBooleanSignalFilter
TEST.NEW
TEST.NAME:Com_ProcessBooleanSignalFilter.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessBooleanSignalFilter.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessBooleanSignalFilter
TEST.NEW
TEST.NAME:Com_ProcessBooleanSignalFilter.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr[0]:0
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_BooleanFilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr[0]:0
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_BooleanFilterXValueConfig[0]:1
TEST.END

-- Test Case: Com_ProcessBooleanSignalFilter.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessBooleanSignalFilter
TEST.NEW
TEST.NAME:Com_ProcessBooleanSignalFilter.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessBooleanSignalFilter.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessBooleanSignalFilter
TEST.NEW
TEST.NAME:Com_ProcessBooleanSignalFilter.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalOldValue:1
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_BooleanFilterMaskValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.SignalOldValue:1
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_BooleanFilterMaskValueConfig[0]:1
TEST.END

-- Test Case: Com_ProcessBooleanSignalFilter.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessBooleanSignalFilter
TEST.NEW
TEST.NAME:Com_ProcessBooleanSignalFilter.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.END

-- Test Case: Com_ProcessBooleanSignalFilter.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessBooleanSignalFilter
TEST.NEW
TEST.NAME:Com_ProcessBooleanSignalFilter.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.EXPECTED:Com.Com_ProcessBooleanSignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.END

-- Subprogram: Com_ProcessConfirmationNotification

-- Test Case: Com_ProcessConfirmationNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessConfirmationNotification
TEST.NEW
TEST.NAME:Com_ProcessConfirmationNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ProcessConfirmationNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessConfirmationNotification
TEST.NEW
TEST.NAME:Com_ProcessConfirmationNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessConfirmationNotification.TxPduId:23
TEST.EXPECTED:Com.Com_ProcessConfirmationNotification.TxPduId:23
TEST.END

-- Test Case: Com_ProcessConfirmationNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessConfirmationNotification
TEST.NEW
TEST.NAME:Com_ProcessConfirmationNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:212
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:212
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:212
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:212
TEST.END

-- Test Case: Com_ProcessConfirmationNotification.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessConfirmationNotification
TEST.NEW
TEST.NAME:Com_ProcessConfirmationNotification.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TxAckFunctId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TxAckFunctId:1
TEST.END

-- Test Case: Com_ProcessConfirmationNotification.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessConfirmationNotification
TEST.NEW
TEST.NAME:Com_ProcessConfirmationNotification.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_CbkTxAckFunctConfig[0]:Com_DeInit
TEST.EXPECTED:Com.<<GLOBAL>>.Com_CbkTxAckFunctConfig[0]:Com_DeInit
TEST.END

-- Subprogram: Com_ProcessDeadlineMoitoring

-- Test Case: Com_ProcessDeadlineMoitoring.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessDeadlineMoitoring
TEST.NEW
TEST.NAME:Com_ProcessDeadlineMoitoring.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ProcessDeadlineMoitoring.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessDeadlineMoitoring
TEST.NEW
TEST.NAME:Com_ProcessDeadlineMoitoring.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:1
TEST.END

-- Test Case: Com_ProcessDeadlineMoitoring.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessDeadlineMoitoring
TEST.NEW
TEST.NAME:Com_ProcessDeadlineMoitoring.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:0
TEST.END

-- Test Case: Com_ProcessDeadlineMoitoring.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessDeadlineMoitoring
TEST.NEW
TEST.NAME:Com_ProcessDeadlineMoitoring.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTimeoutCounterConfig[0].TxIpduId:23
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTimeoutCounterConfig[0].TxIpduId:23
TEST.END

-- Test Case: Com_ProcessDeadlineMoitoring.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessDeadlineMoitoring
TEST.NEW
TEST.NAME:Com_ProcessDeadlineMoitoring.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TxToutFunctId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TxToutFunctId:1
TEST.END

-- Test Case: Com_ProcessDeadlineMoitoring.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessDeadlineMoitoring
TEST.NEW
TEST.NAME:Com_ProcessDeadlineMoitoring.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduCancellationSupport:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TxToutFunctId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduCancellationSupport:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TxToutFunctId:1
TEST.END

-- Test Case: Com_ProcessDeadlineMoitoring.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessDeadlineMoitoring
TEST.NEW
TEST.NAME:Com_ProcessDeadlineMoitoring.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_CbkTxToutFunctConfig[0]:Com_DeInit
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxTimeoutCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_CbkTxToutFunctConfig[0]:Com_DeInit
TEST.END

-- Subprogram: Com_ProcessInvalidateSignal

-- Test Case: Com_ProcessInvalidateSignal.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessInvalidateSignal.SignalId:9
TEST.EXPECTED:Com.Com_ProcessInvalidateSignal.SignalId:9
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:10
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:10
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:10
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:10
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:6
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:6
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:7
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:7
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:7
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:7
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:3
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:8
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:4
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:4
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:4
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:5
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.017
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.017
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:5
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.018
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.018
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.019
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.019
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.020
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.020
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.021
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.021
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.022
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.022
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.023
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.023
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:12
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:12
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.024
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.024
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:12
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:12
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.025
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.025
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:20
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:20
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.026
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.026
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:9
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:9
TEST.END

-- Test Case: Com_ProcessInvalidateSignal.027
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessInvalidateSignal
TEST.NEW
TEST.NAME:Com_ProcessInvalidateSignal.027
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:9
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:9
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].InvalidDataBufferStartId:1
TEST.END

-- Subprogram: Com_ProcessSendSignal

-- Test Case: Com_ProcessSendSignal.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:COM_NUM_OF_TX_SIGNAL_ID
TEST.EXPECTED:Com.Com_ProcessSendSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.END

-- Test Case: Com_ProcessSendSignal.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:<<null>>
TEST.EXPECTED:Com.Com_ProcessSendSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.END

-- Test Case: Com_ProcessSendSignal.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.END

-- Test Case: Com_ProcessSendSignal.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:1
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:1
TEST.EXPECTED:Com.Com_ProcessSendSignal.SignalId:0
TEST.END

-- Test Case: Com_ProcessSendSignal.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:4
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:4
TEST.EXPECTED:Com.Com_ProcessSendSignal.SignalId:0
TEST.END

-- Test Case: Com_ProcessSendSignal.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:2
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:2
TEST.EXPECTED:Com.Com_ProcessSendSignal.SignalId:0
TEST.END

-- Test Case: Com_ProcessSendSignal.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_IsTxSignalDataChanged
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:2
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_IsTxSignalDataChanged.return:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:2
TEST.EXPECTED:Com.Com_ProcessSendSignal.SignalId:0
TEST.END

-- Test Case: Com_ProcessSendSignal.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:3
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:3
TEST.EXPECTED:Com.Com_ProcessSendSignal.SignalId:0
TEST.END

-- Test Case: Com_ProcessSendSignal.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_IsTxSignalDataChanged
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:3
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_IsTxSignalDataChanged.return:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:3
TEST.EXPECTED:Com.Com_ProcessSendSignal.SignalId:0
TEST.END

-- Test Case: Com_ProcessSendSignal.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:1
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:1
TEST.END

-- Test Case: Com_ProcessSendSignal.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.END

-- Test Case: Com_ProcessSendSignal.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.END

-- Test Case: Com_ProcessSendSignal.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.END

-- Test Case: Com_ProcessSendSignal.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TxFilterId:1
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].TxFilterId:1
TEST.END

-- Test Case: Com_ProcessSendSignal.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignal
TEST.NEW
TEST.NAME:Com_ProcessSendSignal.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ProcessTxSignalFilterState
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalFilterState[0]:1
TEST.VALUE:Com.Com_ProcessSendSignal.SignalId:0
TEST.VALUE:Com.Com_ProcessSendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.return:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalFilterState[0]:1
TEST.END

-- Subprogram: Com_ProcessSendSignalGroup

-- Test Case: Com_ProcessSendSignalGroup.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignalGroup
TEST.NEW
TEST.NAME:Com_ProcessSendSignalGroup.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ProcessSendSignalGroup.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignalGroup
TEST.NEW
TEST.NAME:Com_ProcessSendSignalGroup.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSendSignalGroup.SignalGroupId:1
TEST.EXPECTED:Com.Com_ProcessSendSignalGroup.SignalGroupId:1
TEST.END

-- Test Case: Com_ProcessSendSignalGroup.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignalGroup
TEST.NEW
TEST.NAME:Com_ProcessSendSignalGroup.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ShadowBufferConfigId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ShadowBufferConfigId:1
TEST.END

-- Test Case: Com_ProcessSendSignalGroup.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignalGroup
TEST.NEW
TEST.NAME:Com_ProcessSendSignalGroup.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxShadowBufferConfig[0].BufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxShadowBufferConfig[0].BufferStartId:1
TEST.END

-- Test Case: Com_ProcessSendSignalGroup.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignalGroup
TEST.NEW
TEST.NAME:Com_ProcessSendSignalGroup.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ComPduId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ComPduId:1
TEST.END

-- Test Case: Com_ProcessSendSignalGroup.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignalGroup
TEST.NEW
TEST.NAME:Com_ProcessSendSignalGroup.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:8
TEST.END

-- Test Case: Com_ProcessSendSignalGroup.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignalGroup
TEST.NEW
TEST.NAME:Com_ProcessSendSignalGroup.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupTxTriggerStatus[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupTxTriggerStatus[0]:0
TEST.END

-- Test Case: Com_ProcessSendSignalGroup.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSendSignalGroup
TEST.NEW
TEST.NAME:Com_ProcessSendSignalGroup.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupTxTriggerStatus[0]:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupTxTriggerStatus[0]:0
TEST.END

-- Subprogram: Com_ProcessSint16SignalFilter

-- Test Case: Com_ProcessSint16SignalFilter.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint16FilterMaskValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalOldValue:1
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.SignalOldValue:1
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint16FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint16FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint16FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint16FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint16FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint16FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint16FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint16FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint16FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint16FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint16FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint16FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.END

-- Test Case: Com_ProcessSint16SignalFilter.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint16SignalFilter.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:20
TEST.EXPECTED:Com.Com_ProcessSint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:20
TEST.END

-- Subprogram: Com_ProcessSint32SignalFilter

-- Test Case: Com_ProcessSint32SignalFilter.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalOldValue:1
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_Sint32FilterMaskValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.SignalOldValue:1
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_Sint32FilterMaskValueConfig[0]:1
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint32FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint32FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint32FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint32FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint32FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint32FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint32FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint32FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint32FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint32FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint32FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint32FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.END

-- Test Case: Com_ProcessSint32SignalFilter.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint32SignalFilter.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.EXPECTED:Com.Com_ProcessSint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.END

-- Subprogram: Com_ProcessSint64SignalFilter

-- Test Case: Com_ProcessSint64SignalFilter.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint64FilterMaskValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalOldValue:1
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint64FilterMaskValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.SignalOldValue:1
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint64FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint64FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint64FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint64FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint64FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint64FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint64FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint64FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint64FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint64FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint64FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint64FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint64FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint64FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint64FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint64FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint64FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint64FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint64FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint64FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.END

-- Test Case: Com_ProcessSint64SignalFilter.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint64SignalFilter.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.EXPECTED:Com.Com_ProcessSint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.END

-- Subprogram: Com_ProcessSint8SignalFilter

-- Test Case: Com_ProcessSint8SignalFilter.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalOldValue:1
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_Sint8FilterMaskValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.SignalOldValue:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_Sint8FilterMaskValueConfig[0]:1
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterXBufferId:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterXBufferId:1
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint8FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint8FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint8FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint8FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterMaxBufferId:1
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterMaxBufferId:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint8FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint8FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint8FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint8FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterMaxBufferId:1
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterMaxBufferId:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint8FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Sint8FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint8FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Sint8FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessSint8SignalFilter.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessSint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessSint8SignalFilter.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.EXPECTED:Com.Com_ProcessSint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.END

-- Subprogram: Com_ProcessTransmitRequest

-- Test Case: Com_ProcessTransmitRequest.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTransmitRequest
TEST.NEW
TEST.NAME:Com_ProcessTransmitRequest.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ProcessTransmitRequest.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTransmitRequest
TEST.NEW
TEST.NAME:Com_ProcessTransmitRequest.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.END

-- Test Case: Com_ProcessTransmitRequest.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTransmitRequest
TEST.NEW
TEST.NAME:Com_ProcessTransmitRequest.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_ProcessTransmitRequest.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTransmitRequest
TEST.NEW
TEST.NAME:Com_ProcessTransmitRequest.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_ProcessTransmitRequest.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTransmitRequest
TEST.NEW
TEST.NAME:Com_ProcessTransmitRequest.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_ProcessTransmitRequest.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTransmitRequest
TEST.NEW
TEST.NAME:Com_ProcessTransmitRequest.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_ProcessTransmitRequest.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTransmitRequest
TEST.NEW
TEST.NAME:Com_ProcessTransmitRequest.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_ProcessTransmitRequest.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTransmitRequest
TEST.NEW
TEST.NAME:Com_ProcessTransmitRequest.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduRepetitionCycleCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduRepetitionCycleCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_ProcessTransmitRequest.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTransmitRequest
TEST.NEW
TEST.NAME:Com_ProcessTransmitRequest.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduRepetitionCycleCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduRepetitionCycleCounter[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_ProcessTransmitRequest.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTransmitRequest
TEST.NEW
TEST.NAME:Com_ProcessTransmitRequest.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduRepetitionCycleCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduRepetitionCycleCounter[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_ProcessTransmitRequest.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTransmitRequest
TEST.NEW
TEST.NAME:Com_ProcessTransmitRequest.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_IpduTxTransmit
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduRepetitionCycleCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.Com_IpduTxTransmit.return:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicTransmitRequest[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduRepetitionCycleCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduMinimumDelayCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduPeriodicCounter[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Subprogram: Com_ProcessTxConfirmation

-- Test Case: Com_ProcessTxConfirmation.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxConfirmation
TEST.NEW
TEST.NAME:Com_ProcessTxConfirmation.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ProcessTxConfirmation.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxConfirmation
TEST.NEW
TEST.NAME:Com_ProcessTxConfirmation.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessTxConfirmation.TxPduId:23
TEST.EXPECTED:Com.Com_ProcessTxConfirmation.TxPduId:23
TEST.END

-- Test Case: Com_ProcessTxConfirmation.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxConfirmation
TEST.NEW
TEST.NAME:Com_ProcessTxConfirmation.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:0
TEST.END

-- Test Case: Com_ProcessTxConfirmation.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxConfirmation
TEST.NEW
TEST.NAME:Com_ProcessTxConfirmation.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_ProcessTxConfirmation.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxConfirmation
TEST.NEW
TEST.NAME:Com_ProcessTxConfirmation.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduRepetitionCount[0]:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduRepetitionCount[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_ProcessTxConfirmation.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxConfirmation
TEST.NEW
TEST.NAME:Com_ProcessTxConfirmation.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:1
TEST.END

-- Test Case: Com_ProcessTxConfirmation.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxConfirmation
TEST.NEW
TEST.NAME:Com_ProcessTxConfirmation.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:1
TEST.END

-- Test Case: Com_ProcessTxConfirmation.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxConfirmation
TEST.NEW
TEST.NAME:Com_ProcessTxConfirmation.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:1
TEST.END

-- Subprogram: Com_ProcessTxSignalFilterState

-- Test Case: Com_ProcessTxSignalFilterState.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.TxSignalFilterId:1
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.Com_ProcessTxSignalFilterState.TxSignalFilterId:1
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:10
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:10
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:6
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:6
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:7
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:7
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:3
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:3
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:8
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:8
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:4
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:4
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:9
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:9
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:5
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:5
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:1
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:1
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalFilterConfig[0].FilterAlgorithmType:1
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalFilterConfig[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalFilterConfig[0].FilterAlgorithmType:1
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalFilterConfig[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalFilterConfig[0].FilterAlgorithmType:1
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalFilterConfig[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.017
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.017
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:12
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:12
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.018
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.018
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:12
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalFilterConfig[0].FilterAlgorithmType:1
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:12
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalFilterConfig[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessTxSignalFilterState.019
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessTxSignalFilterState
TEST.NEW
TEST.NAME:Com_ProcessTxSignalFilterState.019
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_ReadTxSignalFromIpdu
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:20
TEST.VALUE:Com.Com_ProcessTxSignalFilterState.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:20
TEST.END

-- Subprogram: Com_ProcessUint16SignalFilter

-- Test Case: Com_ProcessUint16SignalFilter.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterXBufferId:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterXBufferId:1
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint16FilterMaskValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalOldValue:1
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint16FilterMaskValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.SignalOldValue:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint16FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint16FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint16FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterMaxBufferId:1
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterMaxBufferId:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint16FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint16FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint16FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint16FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterMaxBufferId:1
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterMaxBufferId:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint16FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint16FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint16FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint16FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.END

-- Test Case: Com_ProcessUint16SignalFilter.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint16SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint16SignalFilter.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:20
TEST.EXPECTED:Com.Com_ProcessUint16SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:20
TEST.END

-- Subprogram: Com_ProcessUint32SignalFilter

-- Test Case: Com_ProcessUint32SignalFilter.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint32FilterMaskValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalOldValue:1
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint32FilterMaskValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.SignalOldValue:1
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint32FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint32FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint32FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint32FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint32FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint32FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint32FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint32FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint32FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint32FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint32FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint32FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.END

-- Test Case: Com_ProcessUint32SignalFilter.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint32SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint32SignalFilter.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.EXPECTED:Com.Com_ProcessUint32SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.END

-- Subprogram: Com_ProcessUint64SignalFilter

-- Test Case: Com_ProcessUint64SignalFilter.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalOldValue:1
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_Uint64FilterMaskValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.SignalOldValue:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_Uint64FilterMaskValueConfig[0]:1
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint64FilterMaskValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint64FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalOldValue:1
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint64FilterMaskValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint64FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.SignalOldValue:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint64FilterMaskValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint64FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalOldValue:1
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint64FilterMaskValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint64FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.SignalOldValue:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint64FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint64FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint64FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint64FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterMinBufferId:1
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint64FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint64FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint64FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint64FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.END

-- Test Case: Com_ProcessUint64SignalFilter.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint64SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint64SignalFilter.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.EXPECTED:Com.Com_ProcessUint64SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.END

-- Subprogram: Com_ProcessUint8SignalFilter

-- Test Case: Com_ProcessUint8SignalFilter.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterXBufferId:1
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterMaskBufferId:1
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterXBufferId:1
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint8FilterMaskValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalOldValue:1
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint8FilterMaskValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.SignalOldValue:1
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:1
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint8FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint8FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:2
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint8FilterXValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint8FilterXValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:3
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint8FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint8FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint8FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint8FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:6
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint8FilterMinValueConfig[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_Uint8FilterMaxValueConfig[0]:1
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint8FilterMinValueConfig[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_Uint8FilterMaxValueConfig[0]:1
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:5
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:7
TEST.END

-- Test Case: Com_ProcessUint8SignalFilter.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ProcessUint8SignalFilter
TEST.NEW
TEST.NAME:Com_ProcessUint8SignalFilter.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.SignalDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.EXPECTED:Com.Com_ProcessUint8SignalFilter.FilterConfigPtr[0].FilterAlgorithmType:10
TEST.END

-- Subprogram: Com_ReadRxSignalFromBuffer

-- Test Case: Com_ReadRxSignalFromBuffer.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadRxSignalFromBuffer
TEST.NEW
TEST.NAME:Com_ReadRxSignalFromBuffer.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ReadRxSignalFromBuffer.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadRxSignalFromBuffer
TEST.NEW
TEST.NAME:Com_ReadRxSignalFromBuffer.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.SignalDataPtr:VECTORCAST_INT1
TEST.END

-- Test Case: Com_ReadRxSignalFromBuffer.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadRxSignalFromBuffer
TEST.NEW
TEST.NAME:Com_ReadRxSignalFromBuffer.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_ReadRxSignalFromBuffer.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadRxSignalFromBuffer
TEST.NEW
TEST.NAME:Com_ReadRxSignalFromBuffer.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxIpduBufferPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_ReadRxSignalFromBuffer.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadRxSignalFromBuffer
TEST.NEW
TEST.NAME:Com_ReadRxSignalFromBuffer.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxIpduBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.END

-- Test Case: Com_ReadRxSignalFromBuffer.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadRxSignalFromBuffer
TEST.NEW
TEST.NAME:Com_ReadRxSignalFromBuffer.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalEndiannessType:1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxIpduBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalEndiannessType:1
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.END

-- Test Case: Com_ReadRxSignalFromBuffer.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadRxSignalFromBuffer
TEST.NEW
TEST.NAME:Com_ReadRxSignalFromBuffer.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalEndiannessType:1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalType:6
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxIpduBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalEndiannessType:1
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalType:6
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.END

-- Test Case: Com_ReadRxSignalFromBuffer.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadRxSignalFromBuffer
TEST.NEW
TEST.NAME:Com_ReadRxSignalFromBuffer.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalEndiannessType:1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalType:3
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxIpduBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalEndiannessType:1
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalType:3
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.END

-- Test Case: Com_ReadRxSignalFromBuffer.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadRxSignalFromBuffer
TEST.NEW
TEST.NAME:Com_ReadRxSignalFromBuffer.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalEndiannessType:1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalType:4
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxIpduBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalEndiannessType:1
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalType:4
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.END

-- Test Case: Com_ReadRxSignalFromBuffer.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadRxSignalFromBuffer
TEST.NEW
TEST.NAME:Com_ReadRxSignalFromBuffer.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalEndiannessType:1
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalType:5
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.RxIpduBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalEndiannessType:1
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.RxSignalConfigPtr[0].SignalType:5
TEST.EXPECTED:Com.Com_ReadRxSignalFromBuffer.MaximumLength:1
TEST.END

-- Subprogram: Com_ReadTxSignalFromIpdu

-- Test Case: Com_ReadTxSignalFromIpdu.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadTxSignalFromIpdu
TEST.NEW
TEST.NAME:Com_ReadTxSignalFromIpdu.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ReadTxSignalFromIpdu.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadTxSignalFromIpdu
TEST.NEW
TEST.NAME:Com_ReadTxSignalFromIpdu.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ReadTxSignalFromIpdu.SignalId:212
TEST.VALUE:Com.Com_ReadTxSignalFromIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.Com_ReadTxSignalFromIpdu.SignalId:212
TEST.END

-- Test Case: Com_ReadTxSignalFromIpdu.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadTxSignalFromIpdu
TEST.NEW
TEST.NAME:Com_ReadTxSignalFromIpdu.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_ReadTxSignalFromIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.END

-- Test Case: Com_ReadTxSignalFromIpdu.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadTxSignalFromIpdu
TEST.NEW
TEST.NAME:Com_ReadTxSignalFromIpdu.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:23
TEST.VALUE:Com.Com_ReadTxSignalFromIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:23
TEST.END

-- Test Case: Com_ReadTxSignalFromIpdu.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadTxSignalFromIpdu
TEST.NEW
TEST.NAME:Com_ReadTxSignalFromIpdu.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.VALUE:Com.Com_ReadTxSignalFromIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.END

-- Test Case: Com_ReadTxSignalFromIpdu.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadTxSignalFromIpdu
TEST.NEW
TEST.NAME:Com_ReadTxSignalFromIpdu.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.VALUE:Com.Com_ReadTxSignalFromIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.END

-- Test Case: Com_ReadTxSignalFromIpdu.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadTxSignalFromIpdu
TEST.NEW
TEST.NAME:Com_ReadTxSignalFromIpdu.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:6
TEST.VALUE:Com.Com_ReadTxSignalFromIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:6
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.END

-- Test Case: Com_ReadTxSignalFromIpdu.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadTxSignalFromIpdu
TEST.NEW
TEST.NAME:Com_ReadTxSignalFromIpdu.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:3
TEST.VALUE:Com.Com_ReadTxSignalFromIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:3
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.END

-- Test Case: Com_ReadTxSignalFromIpdu.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadTxSignalFromIpdu
TEST.NEW
TEST.NAME:Com_ReadTxSignalFromIpdu.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:4
TEST.VALUE:Com.Com_ReadTxSignalFromIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:4
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.END

-- Test Case: Com_ReadTxSignalFromIpdu.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReadTxSignalFromIpdu
TEST.NEW
TEST.NAME:Com_ReadTxSignalFromIpdu.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:5
TEST.VALUE:Com.Com_ReadTxSignalFromIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:5
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.END

-- Subprogram: Com_ReceiveDynSignal

-- Test Case: Com_ReceiveDynSignal.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveDynSignal
TEST.NEW
TEST.NAME:Com_ReceiveDynSignal.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RECEIVEDYNSIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_ReceiveDynSignal.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveDynSignal
TEST.NEW
TEST.NAME:Com_ReceiveDynSignal.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalId:COM_NUM_OF_RX_SIGNAL_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RECEIVEDYNSIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_ReceiveDynSignal.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveDynSignal
TEST.NEW
TEST.NAME:Com_ReceiveDynSignal.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalId:0
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalDataPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RECEIVEDYNSIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_ReceiveDynSignal.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveDynSignal
TEST.NEW
TEST.NAME:Com_ReceiveDynSignal.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalId:0
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_ReceiveDynSignal.Length:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RECEIVEDYNSIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_ReceiveDynSignal.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveDynSignal
TEST.NEW
TEST.NAME:Com_ReceiveDynSignal.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalId:0
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalDataPtr:VECTORCAST_BUFFER
TEST.VALUE:Com.Com_ReceiveDynSignal.Length:<<malloc 1>>
TEST.VALUE:Com.Com_ReceiveDynSignal.Length[0]:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8_DYN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBytePosition:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_ReceiveDynSignal.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveDynSignal
TEST.NEW
TEST.NAME:Com_ReceiveDynSignal.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:0
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalId:1
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalDataPtr:VECTORCAST_BUFFER
TEST.VALUE:Com.Com_ReceiveDynSignal.Length:<<malloc 1>>
TEST.VALUE:Com.Com_ReceiveDynSignal.Length[0]:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8_DYN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBytePosition:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:11
TEST.EXPECTED:Com.Com_ReceiveDynSignal.SignalId:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_ReceiveDynSignal.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveDynSignal
TEST.NEW
TEST.NAME:Com_ReceiveDynSignal.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalId:0
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalDataPtr:VECTORCAST_BUFFER
TEST.VALUE:Com.Com_ReceiveDynSignal.Length:<<malloc 1>>
TEST.VALUE:Com.Com_ReceiveDynSignal.Length[0]:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8_DYN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBytePosition:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_ReceiveDynSignal.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveDynSignal
TEST.NEW
TEST.NAME:Com_ReceiveDynSignal.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:2
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalId:0
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalDataPtr:VECTORCAST_BUFFER
TEST.VALUE:Com.Com_ReceiveDynSignal.Length:<<malloc 1>>
TEST.VALUE:Com.Com_ReceiveDynSignal.Length[0]:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8_DYN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBytePosition:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:2
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_ReceiveDynSignal.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveDynSignal
TEST.NEW
TEST.NAME:Com_ReceiveDynSignal.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalId:0
TEST.VALUE:Com.Com_ReceiveDynSignal.SignalDataPtr:VECTORCAST_BUFFER
TEST.VALUE:Com.Com_ReceiveDynSignal.Length:<<malloc 1>>
TEST.VALUE:Com.Com_ReceiveDynSignal.Length[0]:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8_DYN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBytePosition:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].BitSize:64
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Subprogram: Com_ReceiveSignal

-- Test Case: Com_ReceiveSignal.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignal
TEST.NEW
TEST.NAME:Com_ReceiveSignal.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_ReceiveSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RECEIVESIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_ReceiveSignal.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignal
TEST.NEW
TEST.NAME:Com_ReceiveSignal.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_ReceiveSignal.SignalId:COM_NUM_OF_RX_SIGNAL_ID
TEST.EXPECTED:Com.Com_ReceiveSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RECEIVESIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_ReceiveSignal.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignal
TEST.NEW
TEST.NAME:Com_ReceiveSignal.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_ReceiveSignal.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignal.SignalDataPtr:<<null>>
TEST.EXPECTED:Com.Com_ReceiveSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RECEIVESIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_ReceiveSignal.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignal
TEST.NEW
TEST.NAME:Com_ReceiveSignal.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0xAA
TEST.VALUE:Com.Com_ReceiveSignal.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignal.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].RxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].FirstTimeout:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].Timeout:1000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]:0xBB
TEST.EXPECTED:Com.Com_ReceiveSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.END

-- Subprogram: Com_ReceiveSignalGroup

-- Test Case: Com_ReceiveSignalGroup.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_ReceiveSignalGroup.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.END

-- Test Case: Com_ReceiveSignalGroup.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_ReceiveSignalGroup.SignalGroupId:2
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.Com_ReceiveSignalGroup.SignalGroupId:2
TEST.END

-- Test Case: Com_ReceiveSignalGroup.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].ComPduId:2
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].ComPduId:2
TEST.END

-- Test Case: Com_ReceiveSignalGroup.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:10
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:10
TEST.END

-- Test Case: Com_ReceiveSignalGroup.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:6
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:6
TEST.END

-- Test Case: Com_ReceiveSignalGroup.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:12
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:6
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:12
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:6
TEST.END

-- Test Case: Com_ReceiveSignalGroup.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:7
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:7
TEST.END

-- Test Case: Com_ReceiveSignalGroup.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:3
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:3
TEST.END

-- Test Case: Com_ReceiveSignalGroup.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:3
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:3
TEST.END

-- Test Case: Com_ReceiveSignalGroup.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:8
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:8
TEST.END

-- Test Case: Com_ReceiveSignalGroup.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:4
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:4
TEST.END

-- Test Case: Com_ReceiveSignalGroup.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:1
TEST.END

-- Test Case: Com_ReceiveSignalGroup.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:1
TEST.END

-- Test Case: Com_ReceiveSignalGroup.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:9
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:9
TEST.END

-- Test Case: Com_ReceiveSignalGroup.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:5
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:5
TEST.END

-- Test Case: Com_ReceiveSignalGroup.017
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.017
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:2
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:2
TEST.END

-- Test Case: Com_ReceiveSignalGroup.018
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.018
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:2
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:2
TEST.END

-- Test Case: Com_ReceiveSignalGroup.019
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.019
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:12
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:12
TEST.END

-- Test Case: Com_ReceiveSignalGroup.020
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.020
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:20
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:20
TEST.END

-- Test Case: Com_ReceiveSignalGroup.021
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.021
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:20
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:20
TEST.END

-- Test Case: Com_ReceiveSignalGroup.022
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroup
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroup.022
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:12
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:12
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:2
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:12
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:2
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:12
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:2
TEST.END

-- Subprogram: Com_ReceiveSignalGroupArray

-- Test Case: Com_ReceiveSignalGroupArray.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroupArray
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroupArray.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_ReceiveSignalGroupArray.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RECEIVESIGNALGROUPARRAY
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_ReceiveSignalGroupArray.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroupArray
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroupArray.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupId:COM_NUM_OF_RX_SIGNAL_GROUP_ID
TEST.EXPECTED:Com.Com_ReceiveSignalGroupArray.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RECEIVESIGNALGROUPARRAY
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_ReceiveSignalGroupArray.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroupArray
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroupArray.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupId:0
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupArrayPtr:<<malloc 9>>
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupArrayPtr:<<null>>
TEST.EXPECTED:Com.Com_ReceiveSignalGroupArray.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RECEIVESIGNALGROUPARRAY
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_ReceiveSignalGroupArray.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroupArray
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroupArray.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupId:0
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.Com_ReceiveSignalGroupArray.return:COM_SERVICE_NOT_AVAILABLE
TEST.END

-- Test Case: Com_ReceiveSignalGroupArray.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroupArray
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroupArray.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].ComPduId:2
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupId:0
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].ComPduId:2
TEST.EXPECTED:Com.Com_ReceiveSignalGroupArray.return:COM_SERVICE_NOT_AVAILABLE
TEST.END

-- Test Case: Com_ReceiveSignalGroupArray.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroupArray
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroupArray.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupId:0
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.EXPECTED:Com.Com_ReceiveSignalGroupArray.return:COM_SERVICE_NOT_AVAILABLE
TEST.END

-- Test Case: Com_ReceiveSignalGroupArray.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroupArray
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroupArray.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:2
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupId:0
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:2
TEST.EXPECTED:Com.Com_ReceiveSignalGroupArray.return:COM_SERVICE_NOT_AVAILABLE
TEST.END

-- Test Case: Com_ReceiveSignalGroupArray.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalGroupArray
TEST.NEW
TEST.NAME:Com_ReceiveSignalGroupArray.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupId:0
TEST.VALUE:Com.Com_ReceiveSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:36
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.END

-- Subprogram: Com_ReceiveSignalProcessing

-- Test Case: Com_ReceiveSignalProcessing.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:727
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:727
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:10
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:10
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:6
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:7
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:7
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:3
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:8
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:4
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:4
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:9
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:9
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:5
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:2
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:12
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:12
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:15
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:15
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:118
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:15
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].ComPduId:118
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:15
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:15
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:15
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:0
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.017
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.017
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:6
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:12
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:6
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:12
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.018
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.018
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:3
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.019
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.019
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.020
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.020
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:2
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Test Case: Com_ReceiveSignalProcessing.021
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_ReceiveSignalProcessing
TEST.NEW
TEST.NAME:Com_ReceiveSignalProcessing.021
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:12
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.VALUE:Com.Com_ReceiveSignalProcessing.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].SignalType:12
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_ReceiveSignalProcessing.SignalId:0
TEST.END

-- Subprogram: Com_RxBooleanSignalValidationAndNotification

-- Test Case: Com_RxBooleanSignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxBooleanSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxBooleanSignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxBooleanSignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxBooleanSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxBooleanSignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxBooleanSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxBooleanSignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxBooleanSignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxBooleanSignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxBooleanSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxBooleanSignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxBooleanSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxBooleanSignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:12
TEST.VALUE:Com.Com_RxBooleanSignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxBooleanSignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:12
TEST.EXPECTED:Com.Com_RxBooleanSignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxBooleanSignalValidationAndNotification.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxBooleanSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxBooleanSignalValidationAndNotification.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxBooleanSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxBooleanSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxBooleanSignalValidationAndNotification.BufferUpdateStatus:1
TEST.EXPECTED:Com.Com_RxBooleanSignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxBooleanSignalValidationAndNotification.BufferUpdateStatus:1
TEST.END

-- Subprogram: Com_RxDeadlineMonitoringControl

-- Test Case: Com_RxDeadlineMonitoringControl.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxDeadlineMonitoringControl
TEST.NEW
TEST.NAME:Com_RxDeadlineMonitoringControl.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxDeadlineMonitoringControl.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxDeadlineMonitoringControl
TEST.NEW
TEST.NAME:Com_RxDeadlineMonitoringControl.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxDeadlineMonitoringControl.RxIpduId:2
TEST.EXPECTED:Com.Com_RxDeadlineMonitoringControl.RxIpduId:2
TEST.END

-- Test Case: Com_RxDeadlineMonitoringControl.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxDeadlineMonitoringControl
TEST.NEW
TEST.NAME:Com_RxDeadlineMonitoringControl.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:1
TEST.END

-- Test Case: Com_RxDeadlineMonitoringControl.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxDeadlineMonitoringControl
TEST.NEW
TEST.NAME:Com_RxDeadlineMonitoringControl.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxDeadlineMonitoringControl.InitTimeout:1
TEST.EXPECTED:Com.Com_RxDeadlineMonitoringControl.InitTimeout:1
TEST.END

-- Test Case: Com_RxDeadlineMonitoringControl.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxDeadlineMonitoringControl
TEST.NEW
TEST.NAME:Com_RxDeadlineMonitoringControl.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxDeadlineMonitoringControl.InitTimeout:1
TEST.VALUE:Com.Com_RxDeadlineMonitoringControl.StateCheck:1
TEST.EXPECTED:Com.Com_RxDeadlineMonitoringControl.InitTimeout:1
TEST.EXPECTED:Com.Com_RxDeadlineMonitoringControl.StateCheck:1
TEST.END

-- Test Case: Com_RxDeadlineMonitoringControl.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxDeadlineMonitoringControl
TEST.NEW
TEST.NAME:Com_RxDeadlineMonitoringControl.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:1
TEST.VALUE:Com.Com_RxDeadlineMonitoringControl.InitTimeout:1
TEST.VALUE:Com.Com_RxDeadlineMonitoringControl.StateCheck:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:1
TEST.EXPECTED:Com.Com_RxDeadlineMonitoringControl.InitTimeout:1
TEST.EXPECTED:Com.Com_RxDeadlineMonitoringControl.StateCheck:1
TEST.END

-- Test Case: Com_RxDeadlineMonitoringControl.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxDeadlineMonitoringControl
TEST.NEW
TEST.NAME:Com_RxDeadlineMonitoringControl.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:1
TEST.VALUE:Com.Com_RxDeadlineMonitoringControl.InitTimeout:1
TEST.VALUE:Com.Com_RxDeadlineMonitoringControl.StateCheck:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SigGroupTimeoutCounterStartId:1
TEST.EXPECTED:Com.Com_RxDeadlineMonitoringControl.InitTimeout:1
TEST.EXPECTED:Com.Com_RxDeadlineMonitoringControl.StateCheck:1
TEST.END

-- Test Case: Com_RxDeadlineMonitoringControl.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxDeadlineMonitoringControl
TEST.NEW
TEST.NAME:Com_RxDeadlineMonitoringControl.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineMonitoringState[0]:1
TEST.VALUE:Com.Com_RxDeadlineMonitoringControl.InitTimeout:1
TEST.VALUE:Com.Com_RxDeadlineMonitoringControl.StateCheck:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSigGroupDeadlineMonitoringState[0]:1
TEST.EXPECTED:Com.Com_RxDeadlineMonitoringControl.InitTimeout:1
TEST.EXPECTED:Com.Com_RxDeadlineMonitoringControl.StateCheck:1
TEST.END

-- Subprogram: Com_RxFloat32SignalValidationAndNotification

-- Test Case: Com_RxFloat32SignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxFloat32SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxFloat32SignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxFloat32SignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxFloat32SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxFloat32SignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxFloat32SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxFloat32SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxFloat32SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxFloat32SignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxFloat32SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxFloat32SignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxFloat32SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxFloat32SignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxFloat32SignalValidationAndNotification.BufferUpdateStatus:1
TEST.EXPECTED:Com.Com_RxFloat32SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxFloat32SignalValidationAndNotification.BufferUpdateStatus:1
TEST.END

-- Subprogram: Com_RxFloat64SignalValidationAndNotification

-- Test Case: Com_RxFloat64SignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxFloat64SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxFloat64SignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxFloat64SignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxFloat64SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxFloat64SignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxFloat64SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxFloat64SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxFloat64SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxFloat64SignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxFloat64SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxFloat64SignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxFloat64SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxFloat64SignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxFloat64SignalValidationAndNotification.BufferUpdateStatus:1
TEST.EXPECTED:Com.Com_RxFloat64SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxFloat64SignalValidationAndNotification.BufferUpdateStatus:1
TEST.END

-- Subprogram: Com_RxIndication

-- Test Case: Com_RxIndication.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndication
TEST.NEW
TEST.NAME:Com_RxIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RXINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_RxIndication.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndication
TEST.NEW
TEST.NAME:Com_RxIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_RxIndication.RxPduId:COM_NUM_OF_RX_IPDU_ID
TEST.VALUE:Com.Com_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RXINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_RxIndication.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndication
TEST.NEW
TEST.NAME:Com_RxIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_RxIndication.RxPduId:0
TEST.VALUE:Com.Com_RxIndication.PduInfoPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RXINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_RxIndication.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndication
TEST.NEW
TEST.NAME:Com_RxIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_RxIndication.RxPduId:0
TEST.VALUE:Com.Com_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 9>>
TEST.VALUE:Com.Com_RxIndication.PduInfoPtr[0].SduDataPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_RXINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_RxIndication.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndication
TEST.NEW
TEST.NAME:Com_RxIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:FALSE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.Com_RxIndication.RxPduId:0
TEST.VALUE:Com.Com_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxIndication.PduInfoPtr[0].SduLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]:0xBB
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[1].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].DataInvalidActionType:COM_DATA_INVALID_ACTION_NOTIFY
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_REPLACE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBitPosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].MsBytePosition:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].LsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].BitSize:32
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].ByteLength:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalConfig[2].RxAckFunctId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeferredProcessingState[0]:TRUE
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Subprogram: Com_RxIndicationProcessing

-- Test Case: Com_RxIndicationProcessing.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndicationProcessing
TEST.NEW
TEST.NAME:Com_RxIndicationProcessing.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxIndicationProcessing.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndicationProcessing
TEST.NEW
TEST.NAME:Com_RxIndicationProcessing.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxIndicationProcessing.RxIpduId:118
TEST.EXPECTED:Com.Com_RxIndicationProcessing.RxIpduId:118
TEST.END

-- Test Case: Com_RxIndicationProcessing.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndicationProcessing
TEST.NEW
TEST.NAME:Com_RxIndicationProcessing.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_RxIndicationProcessing.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndicationProcessing
TEST.NEW
TEST.NAME:Com_RxIndicationProcessing.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.END

-- Test Case: Com_RxIndicationProcessing.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndicationProcessing
TEST.NEW
TEST.NAME:Com_RxIndicationProcessing.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.END

-- Test Case: Com_RxIndicationProcessing.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndicationProcessing
TEST.NEW
TEST.NAME:Com_RxIndicationProcessing.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduCalloutFunctConfig[0]:PduR_ComTransmit
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduCalloutFunctConfig[0]:PduR_ComTransmit
TEST.END

-- Test Case: Com_RxIndicationProcessing.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndicationProcessing
TEST.NEW
TEST.NAME:Com_RxIndicationProcessing.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.END

-- Test Case: Com_RxIndicationProcessing.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndicationProcessing
TEST.NEW
TEST.NAME:Com_RxIndicationProcessing.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr[0].SduLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.EXPECTED:Com.Com_RxIndicationProcessing.PduInfoPtr[0].SduLength:1
TEST.END

-- Test Case: Com_RxIndicationProcessing.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndicationProcessing
TEST.NEW
TEST.NAME:Com_RxIndicationProcessing.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr[0].SduLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.EXPECTED:Com.Com_RxIndicationProcessing.PduInfoPtr[0].SduLength:1
TEST.END

-- Test Case: Com_RxIndicationProcessing.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndicationProcessing
TEST.NEW
TEST.NAME:Com_RxIndicationProcessing.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:1
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr[0].SduLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:1
TEST.EXPECTED:Com.Com_RxIndicationProcessing.PduInfoPtr[0].SduLength:1
TEST.END

-- Test Case: Com_RxIndicationProcessing.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIndicationProcessing
TEST.NEW
TEST.NAME:Com_RxIndicationProcessing.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:1
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxIndicationProcessing.PduInfoPtr[0].SduLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:118
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:1
TEST.EXPECTED:Com.Com_RxIndicationProcessing.PduInfoPtr[0].SduLength:1
TEST.END

-- Subprogram: Com_RxIpduProcessing

-- Test Case: Com_RxIpduProcessing.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduProcessing
TEST.NEW
TEST.NAME:Com_RxIpduProcessing.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].RxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].FirstTimeout:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].Timeout:100
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:100
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_RxIpduProcessing.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduProcessing
TEST.NEW
TEST.NAME:Com_RxIpduProcessing.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:FALSE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].RxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].FirstTimeout:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].Timeout:100
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:0
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_RxIpduProcessing.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduProcessing
TEST.NEW
TEST.NAME:Com_RxIpduProcessing.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:0
TEST.VALUE:Com.Com_RxIpduProcessing.RxIpduId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].RxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].FirstTimeout:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].Timeout:100
TEST.EXPECTED:Com.Com_RxIpduProcessing.RxIpduId:2
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_RxIpduProcessing.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduProcessing
TEST.NEW
TEST.NAME:Com_RxIpduProcessing.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineMonitoringState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduDeadlineCounter[0]:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].RxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].FirstTimeout:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduTimeoutCounterConfig[0].Timeout:100
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:1
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Subprogram: Com_RxIpduSignalGroupProcessing

-- Test Case: Com_RxIpduSignalGroupProcessing.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxIpduSignalGroupProcessing.RxIpduId:2
TEST.EXPECTED:Com.Com_RxIpduSignalGroupProcessing.RxIpduId:2
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].UBConfigId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].UBConfigId:1
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:12
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:12
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_RxSignalValidationAndNotification
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.return:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_RxSignalValidationAndNotification
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].DataInvalidActionType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.return:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].DataInvalidActionType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_RxSignalValidationAndNotification
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxInvFunctId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.return:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxInvFunctId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_RxSignalValidationAndNotification
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_CbkRxInvFunctConfig[0]:Com_DeInit
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.return:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_CbkRxInvFunctConfig[0]:Com_DeInit
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_RxSignalValidationAndNotification
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].DataInvalidActionType:2
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.return:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].DataInvalidActionType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_RxSignalValidationAndNotification
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].DataInvalidActionType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.return:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]:5
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].DataInvalidActionType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBitPosition:2
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxAckFunctId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxAckFunctId:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_CbkRxAckFunctConfig[0]:Com_DeInit
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_CbkRxAckFunctConfig[0]:Com_DeInit
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.017
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.017
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_CbkRxAckFunctConfig[0]:Com_DeInit
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxSigGroupTimeoutCounterId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_CbkRxAckFunctConfig[0]:Com_DeInit
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].RxSigGroupTimeoutCounterId:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.END

-- Test Case: Com_RxIpduSignalGroupProcessing.018
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalGroupProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalGroupProcessing.018
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSigGroupDeadlineMonitoringState[0]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_CbkRxAckFunctConfig[0]:Com_DeInit
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSigGroupDeadlineMonitoringState[0]:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:11
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_CbkRxAckFunctConfig[0]:Com_DeInit
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupConfig[0].SignalGroupArrayBufferIdx:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalGroupUBConfig[0].UBBytePosition:1
TEST.END

-- Subprogram: Com_RxIpduSignalProcessing

-- Test Case: Com_RxIpduSignalProcessing.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalProcessing.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxIpduSignalProcessing.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalProcessing.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.END

-- Test Case: Com_RxIpduSignalProcessing.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalProcessing.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.END

-- Test Case: Com_RxIpduSignalProcessing.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalProcessing.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:119
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:119
TEST.END

-- Test Case: Com_RxIpduSignalProcessing.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalProcessing.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxIpduSignalProcessing.RxIpduId:2
TEST.EXPECTED:Com.Com_RxIpduSignalProcessing.RxIpduId:2
TEST.END

-- Test Case: Com_RxIpduSignalProcessing.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalProcessing.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_RxSignalValidationAndNotification
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:119
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.return:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:119
TEST.END

-- Test Case: Com_RxIpduSignalProcessing.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalProcessing.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_RxSignalValidationAndNotification
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:119
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxInvFunctId:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.return:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:119
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxInvFunctId:1
TEST.END

-- Test Case: Com_RxIpduSignalProcessing.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalProcessing.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.STUB:Com.Com_RxSignalValidationAndNotification
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:119
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxInvFunctId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_CbkRxInvFunctConfig[0]:Com_DeInit
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.return:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:119
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxInvFunctId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_CbkRxInvFunctConfig[0]:Com_DeInit
TEST.END

-- Test Case: Com_RxIpduSignalProcessing.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxIpduSignalProcessing
TEST.NEW
TEST.NAME:Com_RxIpduSignalProcessing.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:119
TEST.VALUE:Com.<<GLOBAL>>.Com_CbkRxAckFunctConfig[0]:Com_DeInit
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:727
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalConfig[0].RxAckFunctId:119
TEST.EXPECTED:Com.<<GLOBAL>>.Com_CbkRxAckFunctConfig[0]:Com_DeInit
TEST.END

-- Subprogram: Com_RxSignalGroupShadowBufferUpdate

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:10
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:10
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:6
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:6
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:7
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:7
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:3
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:3
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:3
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:3
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:8
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:8
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:4
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:4
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:1
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:1
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:1
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:1
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:9
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:9
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:5
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:5
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:2
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:2
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:2
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:2
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:12
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:12
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.017
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.017
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:11
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:11
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.018
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.018
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:11
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].RteShadowBufferIdx:2
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:11
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].RteShadowBufferIdx:2
TEST.END

-- Test Case: Com_RxSignalGroupShadowBufferUpdate.019
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalGroupShadowBufferUpdate
TEST.NEW
TEST.NAME:Com_RxSignalGroupShadowBufferUpdate.019
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:15
TEST.VALUE:Com.Com_RxSignalGroupShadowBufferUpdate.RxIpduSrcBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_RxSignalGroupShadowBufferUpdate.RxSignalConfigPtr[0].SignalType:15
TEST.END

-- Subprogram: Com_RxSignalValidationAndNotification

-- Test Case: Com_RxSignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_BOOLEAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_SINT8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_SINT16
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:16
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT16
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:16
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:24
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:3
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_SINT32
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:24
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:3
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_FLOAT32
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:24
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:3
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT64
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_SINT64
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8_N
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8_DYN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:2
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.EXPECTED:Com.Com_RxSignalValidationAndNotification.return:COM_SIGNAL_NOTIFY_ACK
TEST.END

-- Test Case: Com_RxSignalValidationAndNotification.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSignalValidationAndNotification.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxIpduBufferLength[0]:8
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].SignalType:20
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.RxIpduBufferOffset:0
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:Com.Com_RxSignalValidationAndNotification.BufferUpdateStatus:TRUE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferStartId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MinimumLength:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[1].MaximumLength:0
TEST.END

-- Subprogram: Com_RxSint16SignalValidationAndNotification

-- Test Case: Com_RxSint16SignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint16SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint16SignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxSint16SignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint16SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint16SignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint16SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint16SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint16SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxSint16SignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint16SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint16SignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint16SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint16SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_RxSint16SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint16SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_RxSint16SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxSint16SignalValidationAndNotification.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint16SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint16SignalValidationAndNotification.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint16SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint16SignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSint16SignalValidationAndNotification.BufferUpdateStatus:1
TEST.EXPECTED:Com.Com_RxSint16SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint16SignalValidationAndNotification.BufferUpdateStatus:1
TEST.END

-- Subprogram: Com_RxSint32SignalValidationAndNotification

-- Test Case: Com_RxSint32SignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint32SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint32SignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxSint32SignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint32SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint32SignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint32SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint32SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint32SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxSint32SignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint32SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint32SignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint32SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint32SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_RxSint32SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint32SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_RxSint32SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxSint32SignalValidationAndNotification.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint32SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint32SignalValidationAndNotification.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint32SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint32SignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSint32SignalValidationAndNotification.BufferUpdateStatus:1
TEST.EXPECTED:Com.Com_RxSint32SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint32SignalValidationAndNotification.BufferUpdateStatus:1
TEST.END

-- Subprogram: Com_RxSint64SignalValidationAndNotification

-- Test Case: Com_RxSint64SignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint64SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint64SignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxSint64SignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint64SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint64SignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint64SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint64SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint64SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxSint64SignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint64SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint64SignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint64SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint64SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_RxSint64SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint64SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_RxSint64SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxSint64SignalValidationAndNotification.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint64SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint64SignalValidationAndNotification.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint64SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint64SignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSint64SignalValidationAndNotification.BufferUpdateStatus:1
TEST.EXPECTED:Com.Com_RxSint64SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint64SignalValidationAndNotification.BufferUpdateStatus:1
TEST.END

-- Subprogram: Com_RxSint8SignalValidationAndNotification

-- Test Case: Com_RxSint8SignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint8SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint8SignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxSint8SignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint8SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint8SignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint8SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint8SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint8SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxSint8SignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint8SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint8SignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint8SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint8SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:12
TEST.VALUE:Com.Com_RxSint8SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint8SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:12
TEST.EXPECTED:Com.Com_RxSint8SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxSint8SignalValidationAndNotification.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxSint8SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxSint8SignalValidationAndNotification.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxSint8SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxSint8SignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxSint8SignalValidationAndNotification.BufferUpdateStatus:1
TEST.EXPECTED:Com.Com_RxSint8SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxSint8SignalValidationAndNotification.BufferUpdateStatus:1
TEST.END

-- Subprogram: Com_RxUint16SignalValidationAndNotification

-- Test Case: Com_RxUint16SignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint16SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint16SignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxUint16SignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint16SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint16SignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint16SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint16SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint16SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxUint16SignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint16SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint16SignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint16SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint16SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_RxUint16SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint16SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_RxUint16SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxUint16SignalValidationAndNotification.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint16SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint16SignalValidationAndNotification.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint16SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint16SignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxUint16SignalValidationAndNotification.BufferUpdateStatus:1
TEST.EXPECTED:Com.Com_RxUint16SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint16SignalValidationAndNotification.BufferUpdateStatus:1
TEST.END

-- Subprogram: Com_RxUint32SignalValidationAndNotification

-- Test Case: Com_RxUint32SignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint32SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint32SignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxUint32SignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint32SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint32SignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint32SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint32SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint32SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxUint32SignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint32SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint32SignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint32SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint32SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_RxUint32SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint32SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_RxUint32SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxUint32SignalValidationAndNotification.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint32SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint32SignalValidationAndNotification.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint32SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint32SignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxUint32SignalValidationAndNotification.BufferUpdateStatus:1
TEST.EXPECTED:Com.Com_RxUint32SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint32SignalValidationAndNotification.BufferUpdateStatus:1
TEST.END

-- Subprogram: Com_RxUint64SignalValidationAndNotification

-- Test Case: Com_RxUint64SignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint64SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint64SignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxUint64SignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint64SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint64SignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint64SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint64SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint64SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxUint64SignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint64SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint64SignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint64SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint64SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_RxUint64SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint64SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_RxUint64SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxUint64SignalValidationAndNotification.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint64SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint64SignalValidationAndNotification.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint64SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint64SignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxUint64SignalValidationAndNotification.BufferUpdateStatus:1
TEST.EXPECTED:Com.Com_RxUint64SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint64SignalValidationAndNotification.BufferUpdateStatus:1
TEST.END

-- Subprogram: Com_RxUint8ArrSignalValidationAndNotification

-- Test Case: Com_RxUint8ArrSignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint8ArrSignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint8ArrSignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Subprogram: Com_RxUint8SignalValidationAndNotification

-- Test Case: Com_RxUint8SignalValidationAndNotification.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint8SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint8SignalValidationAndNotification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_RxUint8SignalValidationAndNotification.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint8SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint8SignalValidationAndNotification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint8SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint8SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint8SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxUint8SignalValidationAndNotification.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint8SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint8SignalValidationAndNotification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint8SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint8SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:12
TEST.VALUE:Com.Com_RxUint8SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint8SignalValidationAndNotification.RxSignalConfigPtr[0].RteBufferIdx:12
TEST.EXPECTED:Com.Com_RxUint8SignalValidationAndNotification.BufferLength:1
TEST.END

-- Test Case: Com_RxUint8SignalValidationAndNotification.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_RxUint8SignalValidationAndNotification
TEST.NEW
TEST.NAME:Com_RxUint8SignalValidationAndNotification.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_RxUint8SignalValidationAndNotification.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_RxUint8SignalValidationAndNotification.BufferLength:1
TEST.VALUE:Com.Com_RxUint8SignalValidationAndNotification.BufferUpdateStatus:1
TEST.EXPECTED:Com.Com_RxUint8SignalValidationAndNotification.BufferLength:1
TEST.EXPECTED:Com.Com_RxUint8SignalValidationAndNotification.BufferUpdateStatus:1
TEST.END

-- Subprogram: Com_SendDynSignal

-- Test Case: Com_SendDynSignal.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendDynSignal
TEST.NEW
TEST.NAME:Com_SendDynSignal.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_SendDynSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_SENDDYNSIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_SendDynSignal.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendDynSignal
TEST.NEW
TEST.NAME:Com_SendDynSignal.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_SendDynSignal.SignalId:COM_NUM_OF_TX_SIGNAL_ID
TEST.EXPECTED:Com.Com_SendDynSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_SENDDYNSIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_SendDynSignal.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendDynSignal
TEST.NEW
TEST.NAME:Com_SendDynSignal.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_SendDynSignal.SignalId:0
TEST.VALUE:Com.Com_SendDynSignal.SignalDataPtr:<<null>>
TEST.EXPECTED:Com.Com_SendDynSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_SENDDYNSIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_SendDynSignal.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendDynSignal
TEST.NEW
TEST.NAME:Com_SendDynSignal.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_SendDynSignal.SignalId:0
TEST.VALUE:Com.Com_SendDynSignal.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_SendDynSignal.Length:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.END

-- Subprogram: Com_SendSignal

-- Test Case: Com_SendSignal.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignal
TEST.NEW
TEST.NAME:Com_SendSignal.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_SendSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_SENDSIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_SendSignal.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignal
TEST.NEW
TEST.NAME:Com_SendSignal.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_SendSignal.SignalId:COM_NUM_OF_TX_SIGNAL_ID
TEST.EXPECTED:Com.Com_SendSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_SENDSIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_SendSignal.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignal
TEST.NEW
TEST.NAME:Com_SendSignal.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_SendSignal.SignalId:0
TEST.VALUE:Com.Com_SendSignal.SignalDataPtr:<<null>>
TEST.EXPECTED:Com.Com_SendSignal.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_SENDSIGNAL
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_SendSignal.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignal
TEST.NEW
TEST.NAME:Com_SendSignal.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.MULTI_RETURN_SPANS_RANGE:TRUE
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0xA
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0
TEST.VALUE:Com.Com_SendSignal.SignalId:0,1,2,3,4
TEST.VALUE:Com.Com_SendSignal.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutValue:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TargetIpduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxPeriodicCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:COM_TX_MODE_MODE_TYPE_PERIODIC
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].RepetitionCount:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].RepetitionPeriod:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TimeOffset:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TimePeriod:1000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].TxModeModeType:COM_TX_MODE_MODE_TYPE_PERIODIC
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].RepetitionCount:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].RepetitionPeriod:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].TimeOffset:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].TimePeriod:1000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTimeoutCounterConfig[0].TxIpduId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].TransferPropertyType:COM_SIGNAL_TRANSFER_PROPERTY_TYPE_PENDING
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].TxAckFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[0].TxToutFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].TransferPropertyType:COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].TxAckFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[1].TxToutFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].TransferPropertyType:COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_ON_CHANGE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].TxAckFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[2].TxToutFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].TransferPropertyType:COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].TxAckFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[3].TxToutFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].TransferPropertyType:COM_SIGNAL_TRANSFER_PROPERTY_TYPE_TRIGGERED_WITHOUT_REPETITION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].TxAckFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[4].TxToutFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].TransferPropertyType:COM_SIGNAL_TRANSFER_PROPERTY_TYPE_PENDING
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].TxAckFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[5].TxToutFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].TransferPropertyType:COM_SIGNAL_TRANSFER_PROPERTY_TYPE_PENDING
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].TxAckFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[6].TxToutFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].TransferPropertyType:COM_SIGNAL_TRANSFER_PROPERTY_TYPE_PENDING
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].TxAckFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[7].TxToutFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].ComPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].InitialValueOnly:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].TransferPropertyType:COM_SIGNAL_TRANSFER_PROPERTY_TYPE_PENDING
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].MsBitPosition:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].LsBitPosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].MsBytePosition:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].LsBytePosition:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].BitSize:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].ByteLength:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].TxAckFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxSignalConfig[8].TxToutFunctId:COM_NUM_OF_TX_ACK_FUNCTION
TEST.EXPECTED:Com.Com_SendSignal.return:E_OK
TEST.END

-- Subprogram: Com_SendSignalGroup

-- Test Case: Com_SendSignalGroup.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroup
TEST.NEW
TEST.NAME:Com_SendSignalGroup.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_SendSignalGroup.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_SENDSIGNALGROUP
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_SendSignalGroup.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroup
TEST.NEW
TEST.NAME:Com_SendSignalGroup.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_SendSignalGroup.SignalGroupId:COM_NUM_OF_TX_SIGNAL_GROUP_ID
TEST.EXPECTED:Com.Com_SendSignalGroup.return:COM_SERVICE_NOT_AVAILABLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_SENDSIGNALGROUP
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_SendSignalGroup.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroup
TEST.NEW
TEST.NAME:Com_SendSignalGroup.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_SendSignalGroup.SignalGroupId:0
TEST.END

-- Subprogram: Com_SendSignalGroupArray

-- Test Case: Com_SendSignalGroupArray.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_SendSignalGroupArray.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.END

-- Test Case: Com_SendSignalGroupArray.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupId:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.Com_SendSignalGroupArray.SignalGroupId:1
TEST.END

-- Test Case: Com_SendSignalGroupArray.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.END

-- Test Case: Com_SendSignalGroupArray.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.END

-- Test Case: Com_SendSignalGroupArray.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ByteLength:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ByteLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.END

-- Test Case: Com_SendSignalGroupArray.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ByteLength:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr[0]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_SignalArrayOnChageMask[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ByteLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.EXPECTED:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr[0]:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_SignalArrayOnChageMask[0]:1
TEST.END

-- Test Case: Com_SendSignalGroupArray.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.END

-- Test Case: Com_SendSignalGroupArray.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.END

-- Test Case: Com_SendSignalGroupArray.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:4
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:4
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.END

-- Test Case: Com_SendSignalGroupArray.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ByteLength:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr[0]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_SignalArrayOnChageMask[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ByteLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.EXPECTED:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr[0]:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_SignalArrayOnChageMask[0]:1
TEST.END

-- Test Case: Com_SendSignalGroupArray.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:2
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:2
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.END

-- Test Case: Com_SendSignalGroupArray.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:8
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ByteLength:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr[0]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_SignalArrayOnChageMask[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].ByteLength:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.EXPECTED:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr[0]:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_SignalArrayOnChageMask[0]:1
TEST.END

-- Test Case: Com_SendSignalGroupArray.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SendSignalGroupArray
TEST.NEW
TEST.NAME:Com_SendSignalGroupArray.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:3
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.VALUE:Com.Com_SendSignalGroupArray.SignalGroupArrayPtr:<<malloc 1>>
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].TransferPropertyType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalGroupConfig[0].SignalGroupArrayAccess:1
TEST.END

-- Subprogram: Com_SetRxSignalInitValue

-- Test Case: Com_SetRxSignalInitValue.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]:0xAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0xAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]:0x1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_BOOLEAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0x1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0x1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]:0xAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_SINT8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0xAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU16InitBuffer[0]:0xAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT16
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:16
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:2
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU16Buffer[0]:0xAAAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer.Com_RxSignalU8InitBuffer[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU16InitBuffer[0]:0xAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_SINT16
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:16
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:2
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU16Buffer[0]:0xAAAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer.Com_RxSignalU8InitBuffer[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU32InitBuffer[0]:0xAAAAAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:3
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:4
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU32Buffer[0]:0xAAAAAAAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU16Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer.Com_RxSignalU8InitBuffer[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU32InitBuffer[0]:0xAAAAAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_SINT32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:3
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:4
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU32Buffer[0]:0xAAAAAAAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU16Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer.Com_RxSignalU8InitBuffer[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU32InitBuffer[0]:0xAAAAAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_FLOAT32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:3
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:4
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU32Buffer[0]:0xAAAAAAAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU16Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer.Com_RxSignalU8InitBuffer[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU64InitBuffer[0]:0xAAAAAAAAAAAAAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU64Buffer[0]:0xAAAAAAAAAAAAAAAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU16Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU64InitBuffer[0]:0xAAAAAAAAAAAAAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_SINT64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU64Buffer[0]:0xAAAAAAAAAAAAAAAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU16Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU64InitBuffer[0]:0xAAAAAAAAAAAAAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_FLOAT64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU64Buffer[0]:0xAAAAAAAAAAAAAAAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU16Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.012
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalArrInitBuffer[0]:0xAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8_N
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteArrBuffer[0]:0xAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU16Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer.Com_RxSignalU8InitBuffer[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.013
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalArrInitBuffer[0]:0xAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8_DYN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteArrBuffer[0]:0xAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU16Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer.Com_RxSignalU8InitBuffer[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.014
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:15
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0x0
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.015
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.016
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]:0xAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:12
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:12
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.017
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.017
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]:0xAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.018
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.018
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]:0xAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_BIG_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.019
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.019
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU16InitBuffer[0]:0xAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT16
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:16
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:2
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.020
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.020
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU16InitBuffer[0]:0xAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT16
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:16
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:2
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.021
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.021
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU16InitBuffer[0]:0xAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT16
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:16
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:2
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.022
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.022
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU32InitBuffer[0]:0xAAAAAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_FLOAT32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:3
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:4
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.023
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.023
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalU32InitBuffer[0]:0xAAAAAAAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_FLOAT32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:3
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:4
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.024
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.024
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_FLOAT32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:3
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:32
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:4
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.025
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.025
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_FLOAT64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.026
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.026
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_FLOAT64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.027
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.027
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_FLOAT64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:8
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:1
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.028
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.028
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalArrInitBuffer[0]:0xAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8_DYN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:2
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.029
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.029
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalArrInitBuffer[0]:0xAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8_DYN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:2
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:2
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Test Case: Com_SetRxSignalInitValue.030
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SetRxSignalInitValue
TEST.NEW
TEST.NAME:Com_SetRxSignalInitValue.030
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[1]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[2]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[3]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[4]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[5]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[6]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[7]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_RxSignalArrInitBuffer[0]:0xAA
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr:<<malloc 1>>
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ComPduId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitialValueOnly:FALSE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalEndiannessType:COM_SIGNAL_ENDIANNESS_TYPE_LITTLE_ENDIAN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].SignalType:COM_SIGNALTYPE_UINT8_DYN
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].DataInvalidActionType:COM_DATA_INVALID_ACTION_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxDataTimeoutActionType:COM_RX_DATA_TIMEOUT_ACTION_TYPE_NONE
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBitPosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBitPosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].MsBytePosition:7
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].LsBytePosition:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].BitSize:64
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].ByteLength:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RxAckFunctId:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].InitBufferIdx:0
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:2
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.VALUE:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferConfig[0].MaximumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[0]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[1]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[2]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[3]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[4]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[5]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[6]:0xAA
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[7]:0xAA
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteBufferIdx:2
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].RteShadowBufferIdx:1
TEST.EXPECTED:Com.Com_SetRxSignalInitValue.RxSignalConfigPtr[0].IsGroupSignal:1
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[0]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[1]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[2]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[3]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[4]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[5]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[6]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[7]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxIpduBuffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[125]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[8]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[9]::EXPECTED_BASE=16
TEST.ATTRIBUTES:Com.<<GLOBAL>>.Com_RxSignalRteU8Buffer[10]::EXPECTED_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[125]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[8]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[9]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduBufferInitValues[10]::INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_RxSignalU8InitBuffer[0]::INPUT_BASE=16
TEST.END

-- Subprogram: Com_StartOfReception

-- Test Case: Com_StartOfReception.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_StartOfReception
TEST.NEW
TEST.NAME:Com_StartOfReception.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_StartOfReception.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_STARTOFRECEPTION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_StartOfReception.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_StartOfReception
TEST.NEW
TEST.NAME:Com_StartOfReception.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_StartOfReception.id:COM_NUM_OF_RX_IPDU_ID
TEST.EXPECTED:Com.Com_StartOfReception.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_STARTOFRECEPTION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_StartOfReception.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_StartOfReception
TEST.NEW
TEST.NAME:Com_StartOfReception.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_StartOfReception.id:0
TEST.VALUE:Com.Com_StartOfReception.info:<<null>>
TEST.VALUE:Com.Com_StartOfReception.bufferSizePtr:<<null>>
TEST.EXPECTED:Com.Com_StartOfReception.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_STARTOFRECEPTION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_StartOfReception.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_StartOfReception
TEST.NEW
TEST.NAME:Com_StartOfReception.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_StartOfReception.id:0
TEST.VALUE:Com.Com_StartOfReception.info:<<malloc 1>>
TEST.VALUE:Com.Com_StartOfReception.bufferSizePtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_StartOfReception.return:BUFREQ_E_NOT_OK
TEST.END

-- Subprogram: Com_SwitchIpduTxMode

-- Test Case: Com_SwitchIpduTxMode.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SwitchIpduTxMode
TEST.NEW
TEST.NAME:Com_SwitchIpduTxMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_SWITCHIPDUTXMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_SwitchIpduTxMode.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SwitchIpduTxMode
TEST.NEW
TEST.NAME:Com_SwitchIpduTxMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_SwitchIpduTxMode.PduId:COM_NUM_OF_TX_IPDU_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_SWITCHIPDUTXMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_SwitchIpduTxMode.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SwitchIpduTxMode
TEST.NEW
TEST.NAME:Com_SwitchIpduTxMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:TRUE
TEST.VALUE:Com.Com_SwitchIpduTxMode.PduId:0
TEST.VALUE:Com.Com_SwitchIpduTxMode.Mode:FALSE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].RepetitionCount:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].RepetitionPeriod:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TimeOffset:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TimePeriod:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].TxModeModeType:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].RepetitionCount:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].RepetitionPeriod:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].TimeOffset:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduTxModeFalseConfig[0].TimePeriod:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:FALSE
TEST.END

-- Test Case: Com_SwitchIpduTxMode.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SwitchIpduTxMode
TEST.NEW
TEST.NAME:Com_SwitchIpduTxMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:FALSE
TEST.VALUE:Com.Com_SwitchIpduTxMode.PduId:0
TEST.VALUE:Com.Com_SwitchIpduTxMode.Mode:TRUE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:TRUE
TEST.END

-- Test Case: Com_SwitchIpduTxMode.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_SwitchIpduTxMode
TEST.NEW
TEST.NAME:Com_SwitchIpduTxMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:TRUE
TEST.VALUE:Com.Com_SwitchIpduTxMode.PduId:0
TEST.VALUE:Com.Com_SwitchIpduTxMode.Mode:TRUE
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:TRUE
TEST.END

-- Subprogram: Com_TpRxIndication

-- Test Case: Com_TpRxIndication.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TpRxIndication
TEST.NEW
TEST.NAME:Com_TpRxIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TPRXINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_TpRxIndication.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TpRxIndication
TEST.NEW
TEST.NAME:Com_TpRxIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_TpRxIndication.id:COM_NUM_OF_RX_IPDU_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TPRXINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_TpRxIndication.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TpRxIndication
TEST.NEW
TEST.NAME:Com_TpRxIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_TpRxIndication.id:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].SignalEndId:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[0].IpduCalloutFunctId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalStartId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].SignalEndId:COM_NUM_OF_RX_SIGNAL_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduTimeoutCounterId:COM_NUM_OF_RX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_RxIpduConfig[1].IpduCalloutFunctId:0
TEST.END

-- Subprogram: Com_TpTxConfirmation

-- Test Case: Com_TpTxConfirmation.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TpTxConfirmation
TEST.NEW
TEST.NAME:Com_TpTxConfirmation.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TPTXCONFIRMATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_TpTxConfirmation.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TpTxConfirmation
TEST.NEW
TEST.NAME:Com_TpTxConfirmation.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TPTXCONFIRMATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_TpTxConfirmation.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TpTxConfirmation
TEST.NEW
TEST.NAME:Com_TpTxConfirmation.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutValue:1000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TargetIpduId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxPeriodicCounterId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID
TEST.END

-- Test Case: Com_TpTxConfirmation.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TpTxConfirmation
TEST.NEW
TEST.NAME:Com_TpTxConfirmation.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_TpTxConfirmation.id:1
TEST.EXPECTED:Com.Com_TpTxConfirmation.id:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TPTXCONFIRMATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_TpTxConfirmation.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TpTxConfirmation
TEST.NEW
TEST.NAME:Com_TpTxConfirmation.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutValue:1000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TargetIpduId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxPeriodicCounterId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.END

-- Test Case: Com_TpTxConfirmation.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TpTxConfirmation
TEST.NEW
TEST.NAME:Com_TpTxConfirmation.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_TpTxConfirmation.result:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutValue:1000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TargetIpduId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxPeriodicCounterId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID
TEST.EXPECTED:Com.Com_TpTxConfirmation.result:1
TEST.END

-- Test Case: Com_TpTxConfirmation.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TpTxConfirmation
TEST.NEW
TEST.NAME:Com_TpTxConfirmation.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_TP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutValue:1000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TargetIpduId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxPeriodicCounterId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxTpIpduBufferState[0]:0
TEST.END

-- Subprogram: Com_TriggerDirectTransmission

-- Test Case: Com_TriggerDirectTransmission.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerDirectTransmission
TEST.NEW
TEST.NAME:Com_TriggerDirectTransmission.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_TriggerDirectTransmission.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerDirectTransmission
TEST.NEW
TEST.NAME:Com_TriggerDirectTransmission.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_TriggerDirectTransmission.TxIpduId:23
TEST.EXPECTED:Com.Com_TriggerDirectTransmission.TxIpduId:23
TEST.END

-- Test Case: Com_TriggerDirectTransmission.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerDirectTransmission
TEST.NEW
TEST.NAME:Com_TriggerDirectTransmission.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.END

-- Test Case: Com_TriggerDirectTransmission.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerDirectTransmission
TEST.NEW
TEST.NAME:Com_TriggerDirectTransmission.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:3
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:3
TEST.END

-- Test Case: Com_TriggerDirectTransmission.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerDirectTransmission
TEST.NEW
TEST.NAME:Com_TriggerDirectTransmission.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:1
TEST.END

-- Test Case: Com_TriggerDirectTransmission.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerDirectTransmission
TEST.NEW
TEST.NAME:Com_TriggerDirectTransmission.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:1
TEST.VALUE:Com.Com_TriggerDirectTransmission.IsRequestWithoutRepetition:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:1
TEST.EXPECTED:Com.Com_TriggerDirectTransmission.IsRequestWithoutRepetition:1
TEST.END

-- Test Case: Com_TriggerDirectTransmission.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerDirectTransmission
TEST.NEW
TEST.NAME:Com_TriggerDirectTransmission.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].RepetitionCount:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxMode[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].TxModeModeType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTxModeTrueConfig[0].RepetitionCount:1
TEST.END

-- Subprogram: Com_TriggerIPDUSend

-- Test Case: Com_TriggerIPDUSend.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerIPDUSend
TEST.NEW
TEST.NAME:Com_TriggerIPDUSend.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_TriggerIPDUSend.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TRIGGERIPDUSEND
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_TriggerIPDUSend.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerIPDUSend
TEST.NEW
TEST.NAME:Com_TriggerIPDUSend.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_TriggerIPDUSend.PduId:COM_NUM_OF_TX_IPDU_ID
TEST.EXPECTED:Com.Com_TriggerIPDUSend.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TRIGGERIPDUSEND
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_TriggerIPDUSend.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerIPDUSend
TEST.NEW
TEST.NAME:Com_TriggerIPDUSend.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.Com_TriggerIPDUSend.PduId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTransmitRequest[0]:TRUE
TEST.EXPECTED:Com.Com_TriggerIPDUSend.return:E_OK
TEST.END

-- Test Case: Com_TriggerIPDUSend.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerIPDUSend
TEST.NEW
TEST.NAME:Com_TriggerIPDUSend.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_TriggerIPDUSend.PduId:0
TEST.EXPECTED:Com.Com_TriggerIPDUSend.return:E_NOT_OK
TEST.END

-- Subprogram: Com_TriggerIPDUSendWithMetaData

-- Test Case: Com_TriggerIPDUSendWithMetaData.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerIPDUSendWithMetaData
TEST.NEW
TEST.NAME:Com_TriggerIPDUSendWithMetaData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_TriggerIPDUSendWithMetaData.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TRIGGERIPDUSENDWITHMETADATA
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_TriggerIPDUSendWithMetaData.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerIPDUSendWithMetaData
TEST.NEW
TEST.NAME:Com_TriggerIPDUSendWithMetaData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_TriggerIPDUSendWithMetaData.PduId:COM_NUM_OF_TX_IPDU_ID
TEST.EXPECTED:Com.Com_TriggerIPDUSendWithMetaData.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TRIGGERIPDUSENDWITHMETADATA
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_TriggerIPDUSendWithMetaData.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerIPDUSendWithMetaData
TEST.NEW
TEST.NAME:Com_TriggerIPDUSendWithMetaData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_TriggerIPDUSendWithMetaData.PduId:0
TEST.VALUE:Com.Com_TriggerIPDUSendWithMetaData.MetaData:<<malloc 9>>
TEST.VALUE:Com.Com_TriggerIPDUSendWithMetaData.MetaData:<<null>>
TEST.EXPECTED:Com.Com_TriggerIPDUSendWithMetaData.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TRIGGERIPDUSENDWITHMETADATA
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_TriggerIPDUSendWithMetaData.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerIPDUSendWithMetaData
TEST.NEW
TEST.NAME:Com_TriggerIPDUSendWithMetaData.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTransmitRequest[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.Com_TriggerIPDUSendWithMetaData.PduId:0
TEST.VALUE:Com.Com_TriggerIPDUSendWithMetaData.MetaData:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutValue:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TargetIpduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxPeriodicCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTransmitRequest[0]:1
TEST.END

-- Test Case: Com_TriggerIPDUSendWithMetaData.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerIPDUSendWithMetaData
TEST.NEW
TEST.NAME:Com_TriggerIPDUSendWithMetaData.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTransmitRequest[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:0
TEST.VALUE:Com.Com_TriggerIPDUSendWithMetaData.PduId:0
TEST.VALUE:Com.Com_TriggerIPDUSendWithMetaData.MetaData:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutValue:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TargetIpduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxPeriodicCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTransmitRequest[0]:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:0
TEST.END

-- Test Case: Com_TriggerIPDUSendWithMetaData.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerIPDUSendWithMetaData
TEST.NEW
TEST.NAME:Com_TriggerIPDUSendWithMetaData.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTransmitRequest[0]:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MetaDataLength:1
TEST.VALUE:Com.Com_TriggerIPDUSendWithMetaData.PduId:0
TEST.VALUE:Com.Com_TriggerIPDUSendWithMetaData.MetaData:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_NONE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:COM_IPDU_TYPE_NORMAL
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].SignalEndId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].MinimumDelayTime:10
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutValue:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TargetIpduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxPeriodicCounterId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxTimeoutCounterId:COM_NUM_OF_TX_IPDU_TIMEOUT_COUNTER_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:COM_NUM_OF_TX_IPDU_TRIGGER_TX_CALLOUT_FUNC_ID
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTransmitRequest[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MetaDataLength:1
TEST.END

-- Subprogram: Com_TriggerTransmit

-- Test Case: Com_TriggerTransmit.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerTransmit
TEST.NEW
TEST.NAME:Com_TriggerTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:Com.Com_TriggerTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TRIGGERTRANSMIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_TriggerTransmit.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerTransmit
TEST.NEW
TEST.NAME:Com_TriggerTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_TriggerTransmit.TxPduId:COM_NUM_OF_TX_IPDU_ID
TEST.EXPECTED:Com.Com_TriggerTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TRIGGERTRANSMIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_TriggerTransmit.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerTransmit
TEST.NEW
TEST.NAME:Com_TriggerTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_TriggerTransmit.TxPduId:0
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr:<<null>>
TEST.EXPECTED:Com.Com_TriggerTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TRIGGERTRANSMIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM_POINTER
TEST.END

-- Test Case: Com_TriggerTransmit.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerTransmit
TEST.NEW
TEST.NAME:Com_TriggerTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.Com_TriggerTransmit.TxPduId:0
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduLength:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[0]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[1]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[2]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[3]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[4]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[5]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[6]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[7]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduLength:8
TEST.END

-- Test Case: Com_TriggerTransmit.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerTransmit
TEST.NEW
TEST.NAME:Com_TriggerTransmit.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.Com_TriggerTransmit.TxPduId:0
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[0]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[1]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[2]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[3]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[4]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[5]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[6]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[7]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduLength:8
TEST.END

-- Test Case: Com_TriggerTransmit.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerTransmit
TEST.NEW
TEST.NAME:Com_TriggerTransmit.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:0
TEST.VALUE:Com.Com_TriggerTransmit.TxPduId:0
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduLength:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:0
TEST.END

-- Test Case: Com_TriggerTransmit.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerTransmit
TEST.NEW
TEST.NAME:Com_TriggerTransmit.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:0
TEST.VALUE:Com.Com_TriggerTransmit.TxPduId:0
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduLength:9
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:170
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:187
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:170
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:187
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:170
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:187
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:170
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:187
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.EXPECTED:Com.Com_TriggerTransmit.TxPduId:0
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduLength:9
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:3
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.END

-- Test Case: Com_TriggerTransmit.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerTransmit
TEST.NEW
TEST.NAME:Com_TriggerTransmit.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:8
TEST.VALUE:Com.Com_TriggerTransmit.TxPduId:0
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.EXPECTED:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:1
TEST.EXPECTED:Com.Com_TriggerTransmit.TxPduId:0
TEST.END

-- Test Case: Com_TriggerTransmit.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerTransmit
TEST.NEW
TEST.NAME:Com_TriggerTransmit.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:1
TEST.VALUE:Com.Com_TriggerTransmit.TxPduId:0
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduLength:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TriggerTxCalloutFunctId:1
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[0]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[1]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[2]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[3]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[4]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[5]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[6]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[7]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduLength:8
TEST.END

-- Test Case: Com_TriggerTransmit.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TriggerTransmit
TEST.NEW
TEST.NAME:Com_TriggerTransmit.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[0]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[1]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[2]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[3]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[4]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[5]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[6]:0xAA
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBuffer[7]:0xBB
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduGroupActiveState[0]:TRUE
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduTriggerTxCalloutFunctConfig[0]:PduR_ComTransmit
TEST.VALUE:Com.Com_TriggerTransmit.TxPduId:0
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:Com.Com_TriggerTransmit.PduInfoPtr[0].SduLength:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].TxIpduClearUpdateBitType:COM_TX_IPDU_CLEAR_UPDATE_BIT_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferEndId:7
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MinimumLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduBufferConfig[0].MaximumLength:8
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduTriggerTxCalloutFunctConfig[0]:PduR_ComTransmit
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[0]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[1]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[2]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[3]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[4]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[5]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[6]:0xAA
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduDataPtr[7]:0xBB
TEST.EXPECTED:Com.Com_TriggerTransmit.PduInfoPtr[0].SduLength:8
TEST.END

-- Subprogram: Com_TxConfirmation

-- Test Case: Com_TxConfirmation.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TxConfirmation
TEST.NEW
TEST.NAME:Com_TxConfirmation.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TXCONFIRMATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_UNINIT
TEST.END

-- Test Case: Com_TxConfirmation.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TxConfirmation
TEST.NEW
TEST.NAME:Com_TxConfirmation.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.Com_TxConfirmation.TxPduId:COM_NUM_OF_TX_IPDU_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:COM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:COM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COM_SID_TXCONFIRMATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COM_E_PARAM
TEST.END

-- Test Case: Com_TxConfirmation.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TxConfirmation
TEST.NEW
TEST.NAME:Com_TxConfirmation.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:FALSE
TEST.VALUE:Com.Com_TxConfirmation.TxPduId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:FALSE
TEST.END

-- Test Case: Com_TxConfirmation.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TxConfirmation
TEST.NEW
TEST.NAME:Com_TxConfirmation.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.COM_InitStatus:COM_INIT
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:FALSE
TEST.VALUE:Com.Com_TxConfirmation.TxPduId:0
TEST.VALUE:Com.Com_TxConfirmation.result:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Com_TxIpduConfig[0].IpduSignalProcessingType:COM_IPDU_SIGNAL_PROCESSING_TYPE_DEFERRED
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfirmationWaitStatus[0]:FALSE
TEST.EXPECTED:Com.Com_TxConfirmation.result:1
TEST.END

-- Subprogram: Com_TxTpIpduResetConnection

-- Test Case: Com_TxTpIpduResetConnection.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TxTpIpduResetConnection
TEST.NEW
TEST.NAME:Com_TxTpIpduResetConnection.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_TxTpIpduResetConnection.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_TxTpIpduResetConnection
TEST.NEW
TEST.NAME:Com_TxTpIpduResetConnection.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_TxTpIpduResetConnection.TxTpIpduId:1
TEST.EXPECTED:Com.Com_TxTpIpduResetConnection.TxTpIpduId:1
TEST.END

-- Subprogram: Com_UpdateTMS

-- Test Case: Com_UpdateTMS.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UpdateTMS
TEST.NEW
TEST.NAME:Com_UpdateTMS.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_UpdateTMS.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UpdateTMS
TEST.NEW
TEST.NAME:Com_UpdateTMS.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UpdateTMS.TxIpduId:1
TEST.EXPECTED:Com.Com_UpdateTMS.TxIpduId:1
TEST.END

-- Test Case: Com_UpdateTMS.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UpdateTMS
TEST.NEW
TEST.NAME:Com_UpdateTMS.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].SignalFilterStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].SignalFilterStartId:1
TEST.END

-- Test Case: Com_UpdateTMS.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UpdateTMS
TEST.NEW
TEST.NAME:Com_UpdateTMS.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalFilterState[0]:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalFilterState[0]:1
TEST.END

-- Subprogram: Com_UtilBitCopy

-- Test Case: Com_UtilBitCopy.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilBitCopy
TEST.NEW
TEST.NAME:Com_UtilBitCopy.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_UtilBitCopy.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilBitCopy
TEST.NEW
TEST.NAME:Com_UtilBitCopy.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:8
TEST.VALUE:Com.Com_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:8
TEST.END

-- Test Case: Com_UtilBitCopy.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilBitCopy
TEST.NEW
TEST.NAME:Com_UtilBitCopy.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:Com.Com_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Test Case: Com_UtilBitCopy.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilBitCopy
TEST.NEW
TEST.NAME:Com_UtilBitCopy.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:Com.Com_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Test Case: Com_UtilBitCopy.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilBitCopy
TEST.NEW
TEST.NAME:Com_UtilBitCopy.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:Com.Com_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Test Case: Com_UtilBitCopy.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilBitCopy
TEST.NEW
TEST.NAME:Com_UtilBitCopy.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:10
TEST.VALUE:Com.Com_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:10
TEST.END

-- Test Case: Com_UtilBitCopy.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilBitCopy
TEST.NEW
TEST.NAME:Com_UtilBitCopy.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcBufferEndianess:1
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:Com.Com_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcBufferEndianess:1
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Test Case: Com_UtilBitCopy.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilBitCopy
TEST.NEW
TEST.NAME:Com_UtilBitCopy.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcBufferEndianess:1
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestBufferEndianess:1
TEST.VALUE:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:Com.Com_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:16
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcBufferEndianess:1
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].DestBufferEndianess:1
TEST.EXPECTED:Com.Com_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.END

-- Subprogram: Com_UtilGetSignExtended16BitData

-- Test Case: Com_UtilGetSignExtended16BitData.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended16BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended16BitData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended16BitData.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_UtilGetSignExtended16BitData.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended16BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended16BitData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended16BitData.DataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilGetSignExtended16BitData.BitSize:16
TEST.EXPECTED:Com.Com_UtilGetSignExtended16BitData.BitSize:16
TEST.END

-- Test Case: Com_UtilGetSignExtended16BitData.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended16BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended16BitData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended16BitData.DataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilGetSignExtended16BitData.DataPtr[0]:1
TEST.VALUE:Com.Com_UtilGetSignExtended16BitData.BitSize:1
TEST.EXPECTED:Com.Com_UtilGetSignExtended16BitData.DataPtr[0]:65535
TEST.EXPECTED:Com.Com_UtilGetSignExtended16BitData.BitSize:1
TEST.END

-- Subprogram: Com_UtilGetSignExtended32BitData

-- Test Case: Com_UtilGetSignExtended32BitData.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended32BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended32BitData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended32BitData.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_UtilGetSignExtended32BitData.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended32BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended32BitData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended32BitData.DataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilGetSignExtended32BitData.BitSize:32
TEST.EXPECTED:Com.Com_UtilGetSignExtended32BitData.BitSize:32
TEST.END

-- Test Case: Com_UtilGetSignExtended32BitData.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended32BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended32BitData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended32BitData.DataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilGetSignExtended32BitData.DataPtr[0]:1
TEST.VALUE:Com.Com_UtilGetSignExtended32BitData.BitSize:1
TEST.EXPECTED:Com.Com_UtilGetSignExtended32BitData.DataPtr[0]:4294967295
TEST.EXPECTED:Com.Com_UtilGetSignExtended32BitData.BitSize:1
TEST.END

-- Subprogram: Com_UtilGetSignExtended64BitData

-- Test Case: Com_UtilGetSignExtended64BitData.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended64BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended64BitData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended64BitData.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_UtilGetSignExtended64BitData.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended64BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended64BitData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended64BitData.DataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilGetSignExtended64BitData.BitSize:64
TEST.EXPECTED:Com.Com_UtilGetSignExtended64BitData.BitSize:64
TEST.END

-- Test Case: Com_UtilGetSignExtended64BitData.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended64BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended64BitData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended64BitData.DataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilGetSignExtended64BitData.DataPtr[0]:1
TEST.VALUE:Com.Com_UtilGetSignExtended64BitData.BitSize:1
TEST.EXPECTED:Com.Com_UtilGetSignExtended64BitData.DataPtr[0]:18446744073709551615
TEST.EXPECTED:Com.Com_UtilGetSignExtended64BitData.BitSize:1
TEST.END

-- Subprogram: Com_UtilGetSignExtended8BitData

-- Test Case: Com_UtilGetSignExtended8BitData.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended8BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended8BitData.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended8BitData.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_UtilGetSignExtended8BitData.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended8BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended8BitData.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended8BitData.DataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilGetSignExtended8BitData.BitSize:8
TEST.EXPECTED:Com.Com_UtilGetSignExtended8BitData.BitSize:8
TEST.END

-- Test Case: Com_UtilGetSignExtended8BitData.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilGetSignExtended8BitData
TEST.NEW
TEST.NAME:Com_UtilGetSignExtended8BitData.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilGetSignExtended8BitData.DataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilGetSignExtended8BitData.DataPtr[0]:1
TEST.VALUE:Com.Com_UtilGetSignExtended8BitData.BitSize:1
TEST.EXPECTED:Com.Com_UtilGetSignExtended8BitData.DataPtr[0]:255
TEST.EXPECTED:Com.Com_UtilGetSignExtended8BitData.BitSize:1
TEST.END

-- Subprogram: Com_UtilMemCopy

-- Test Case: Com_UtilMemCopy.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilMemCopy
TEST.NEW
TEST.NAME:Com_UtilMemCopy.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_UtilMemCopy.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilMemCopy
TEST.NEW
TEST.NAME:Com_UtilMemCopy.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilMemCopy.DestPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilMemCopy.SrcPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilMemCopy.Length:1
TEST.EXPECTED:Com.Com_UtilMemCopy.Length:1
TEST.END

-- Subprogram: Com_UtilMemSet

-- Test Case: Com_UtilMemSet.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilMemSet
TEST.NEW
TEST.NAME:Com_UtilMemSet.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_UtilMemSet.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilMemSet
TEST.NEW
TEST.NAME:Com_UtilMemSet.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilMemSet.DestPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilMemSet.Length:1
TEST.END

-- Subprogram: Com_UtilSetClearBit

-- Test Case: Com_UtilSetClearBit.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilSetClearBit
TEST.NEW
TEST.NAME:Com_UtilSetClearBit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilSetClearBit.DataPtr:<<malloc 1>>
TEST.END

-- Test Case: Com_UtilSetClearBit.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilSetClearBit
TEST.NEW
TEST.NAME:Com_UtilSetClearBit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilSetClearBit.DataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilSetClearBit.SetMode:1
TEST.EXPECTED:Com.Com_UtilSetClearBit.SetMode:1
TEST.END

-- Subprogram: Com_UtilSetClearBitMask

-- Test Case: Com_UtilSetClearBitMask.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilSetClearBitMask
TEST.NEW
TEST.NAME:Com_UtilSetClearBitMask.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilSetClearBitMask.DataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilSetClearBitMask.DataPtr[0]:0
TEST.VALUE:Com.Com_UtilSetClearBitMask.BitMask:0x1
TEST.VALUE:Com.Com_UtilSetClearBitMask.SetMode:TRUE
TEST.EXPECTED:Com.Com_UtilSetClearBitMask.DataPtr[0]:0x1
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[5].IpduGroupVectorMap.IpduGroupVectorMap[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[0].IpduGroupVectorMap.IpduGroupVectorMap[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[1].IpduGroupVectorMap.IpduGroupVectorMap[0]:INPUT_BASE=16
TEST.END

-- Test Case: Com_UtilSetClearBitMask.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_UtilSetClearBitMask
TEST.NEW
TEST.NAME:Com_UtilSetClearBitMask.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_UtilSetClearBitMask.DataPtr:<<malloc 1>>
TEST.VALUE:Com.Com_UtilSetClearBitMask.BitMask:0x1
TEST.VALUE:Com.Com_UtilSetClearBitMask.SetMode:0
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[5].IpduGroupVectorMap.IpduGroupVectorMap[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[0].IpduGroupVectorMap.IpduGroupVectorMap[0]:INPUT_BASE=16
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.Com_IpduToIpduGroupMapRxConfig[1].IpduGroupVectorMap.IpduGroupVectorMap[0]:INPUT_BASE=16
TEST.END

-- Subprogram: Com_WriteTxSignalToIpdu

-- Test Case: Com_WriteTxSignalToIpdu.001
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_WriteTxSignalToIpdu
TEST.NEW
TEST.NAME:Com_WriteTxSignalToIpdu.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.END

-- Test Case: Com_WriteTxSignalToIpdu.002
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_WriteTxSignalToIpdu
TEST.NEW
TEST.NAME:Com_WriteTxSignalToIpdu.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.END

-- Test Case: Com_WriteTxSignalToIpdu.003
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_WriteTxSignalToIpdu
TEST.NEW
TEST.NAME:Com_WriteTxSignalToIpdu.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:23
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:23
TEST.END

-- Test Case: Com_WriteTxSignalToIpdu.004
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_WriteTxSignalToIpdu
TEST.NEW
TEST.NAME:Com_WriteTxSignalToIpdu.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.END

-- Test Case: Com_WriteTxSignalToIpdu.005
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_WriteTxSignalToIpdu
TEST.NEW
TEST.NAME:Com_WriteTxSignalToIpdu.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.EXPECTED:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.END

-- Test Case: Com_WriteTxSignalToIpdu.006
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_WriteTxSignalToIpdu
TEST.NEW
TEST.NAME:Com_WriteTxSignalToIpdu.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.EXPECTED:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.END

-- Test Case: Com_WriteTxSignalToIpdu.007
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_WriteTxSignalToIpdu
TEST.NEW
TEST.NAME:Com_WriteTxSignalToIpdu.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.EXPECTED:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.END

-- Test Case: Com_WriteTxSignalToIpdu.008
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_WriteTxSignalToIpdu
TEST.NEW
TEST.NAME:Com_WriteTxSignalToIpdu.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.EXPECTED:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.END

-- Test Case: Com_WriteTxSignalToIpdu.009
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_WriteTxSignalToIpdu
TEST.NEW
TEST.NAME:Com_WriteTxSignalToIpdu.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.EXPECTED:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.END

-- Test Case: Com_WriteTxSignalToIpdu.010
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_WriteTxSignalToIpdu
TEST.NEW
TEST.NAME:Com_WriteTxSignalToIpdu.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].TpConfigId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.EXPECTED:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.END

-- Test Case: Com_WriteTxSignalToIpdu.011
TEST.UNIT:Com
TEST.SUBPROGRAM:Com_WriteTxSignalToIpdu
TEST.NEW
TEST.NAME:Com_WriteTxSignalToIpdu.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Com::Com_Detailed_Design::Com_Class_Diagram
Requirement_DICVA-13833
TEST.END_NOTES:
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.VALUE:Com.<<GLOBAL>>.Com_TxTpIpduBufferConfig[0].BufferStartId:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.VALUE:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.SignalDataPtr:VECTORCAST_INT1
TEST.VALUE:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduConfig[0].IpduType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxIpduBufferConfig[0].BufferStartId:176
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxTpIpduBufferConfig[0].BufferStartId:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ComPduId:0
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalEndiannessType:1
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].SignalType:11
TEST.EXPECTED:Com.<<GLOBAL>>.Com_TxSignalConfig[0].ByteLength:1
TEST.EXPECTED:Com.Com_WriteTxSignalToIpdu.Length:1
TEST.END
