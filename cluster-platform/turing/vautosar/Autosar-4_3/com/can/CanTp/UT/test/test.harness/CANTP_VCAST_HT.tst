-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : CANTP_VCAST_HT
-- Unit(s) Under Test: CanTp
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CanTp

-- Subprogram: CanTp_CanIfTransmitData

-- Test Case: CanTp_CanIfTransmitData.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CanIfTransmitData
TEST.NEW
TEST.NAME:CanTp_CanIfTransmitData.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_TX_CONNECTION
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.PduInfoPtr[0].SduDataPtr[0]:0x30
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.PduInfoPtr[0].SduDataPtr[1]:0
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.PduInfoPtr[0].SduLength:8
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.TxPduId:0
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.TransmitConnection:CANTP_TRANSMIT_BY_TX_CONNECTION
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.PaddingSupport:TRUE
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.PaddededLength:8
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.ChId:0
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:CANTP_TRANSMIT_NOT_OK
TEST.EXPECTED:CanTp.CanTp_CanIfTransmitData.return:CANTP_TRANSMIT_NOT_OK
TEST.END

-- Test Case: CanTp_CanIfTransmitData.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CanIfTransmitData
TEST.NEW
TEST.NAME:CanTp_CanIfTransmitData.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.ChId:CANTP_NUM_OF_CHANNELS
TEST.EXPECTED:CanTp.CanTp_CanIfTransmitData.return:CANTP_TRANSMIT_NOT_OK
TEST.END

-- Subprogram: CanTp_CancelReceive

-- Test Case: CanTp_CancelReceive.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelReceive
TEST.NEW
TEST.NAME:CanTp_CancelReceive.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_OFF
TEST.EXPECTED:CanTp.CanTp_CancelReceive.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelReceive.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelReceive
TEST.NEW
TEST.NAME:CanTp_CancelReceive.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.CanTp_CancelReceive.CanTpRxSduId:CANTP_RXNSDU_PDUID_NUM_OF_PDUID
TEST.EXPECTED:CanTp.CanTp_CancelReceive.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelReceive.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelReceive
TEST.NEW
TEST.NAME:CanTp_CancelReceive.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:CANTP_NUM_OF_RX_NSDU
TEST.VALUE:CanTp.CanTp_CancelReceive.CanTpRxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelReceive.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelReceive.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelReceive
TEST.NEW
TEST.NAME:CanTp_CancelReceive.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:CANTP_NUM_OF_CHANNELS
TEST.VALUE:CanTp.CanTp_CancelReceive.CanTpRxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelReceive.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelReceive.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelReceive
TEST.NEW
TEST.NAME:CanTp_CancelReceive.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:CANTP_NUM_OF_TX_NSDU
TEST.VALUE:CanTp.CanTp_CancelReceive.CanTpRxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelReceive.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelReceive.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelReceive
TEST.NEW
TEST.NAME:CanTp_CancelReceive.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CancelReceive.CanTpRxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelReceive.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelReceive.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelReceive
TEST.NEW
TEST.NAME:CanTp_CancelReceive.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:TRUE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CancelReceive.CanTpRxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelReceive.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelReceive.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelReceive
TEST.NEW
TEST.NAME:CanTp_CancelReceive.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:TRUE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CancelReceive.CanTpRxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelReceive.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelReceive.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelReceive
TEST.NEW
TEST.NAME:CanTp_CancelReceive.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:TRUE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CancelReceive.CanTpRxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelReceive.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelReceive.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelReceive
TEST.NEW
TEST.NAME:CanTp_CancelReceive.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:TRUE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CancelReceive.CanTpRxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelReceive.return:E_OK
TEST.END

-- Test Case: CanTp_CancelReceive.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelReceive
TEST.NEW
TEST.NAME:CanTp_CancelReceive.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:7
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:TRUE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CancelReceive.CanTpRxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelReceive.return:E_OK
TEST.END

-- Subprogram: CanTp_CancelTransmit

-- Test Case: CanTp_CancelTransmit.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelTransmit
TEST.NEW
TEST.NAME:CanTp_CancelTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_OFF
TEST.EXPECTED:CanTp.CanTp_CancelTransmit.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelTransmit.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelTransmit
TEST.NEW
TEST.NAME:CanTp_CancelTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.CanTp_CancelTransmit.CanTpTxSduId:CANTP_TXNSDU_PDUID_NUM_OF_PDUID
TEST.EXPECTED:CanTp.CanTp_CancelTransmit.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelTransmit.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelTransmit
TEST.NEW
TEST.NAME:CanTp_CancelTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:CANTP_NUM_OF_TX_NSDU
TEST.VALUE:CanTp.CanTp_CancelTransmit.CanTpTxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelTransmit.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelTransmit.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelTransmit
TEST.NEW
TEST.NAME:CanTp_CancelTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:CANTP_NUM_OF_CHANNELS
TEST.VALUE:CanTp.CanTp_CancelTransmit.CanTpTxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelTransmit.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelTransmit.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelTransmit
TEST.NEW
TEST.NAME:CanTp_CancelTransmit.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nas:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nbs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Ncs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:TRUE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:CANTP_STANDARD
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.CanTp_CancelTransmit.CanTpTxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelTransmit.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelTransmit.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelTransmit
TEST.NEW
TEST.NAME:CanTp_CancelTransmit.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nas:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nbs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Ncs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:CANTP_STANDARD
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.CanTp_CancelTransmit.CanTpTxSduId:0
TEST.EXPECTED:CanTp.CanTp_CancelTransmit.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CancelTransmit.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelTransmit
TEST.NEW
TEST.NAME:CanTp_CancelTransmit.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nas:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nbs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Ncs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:TRUE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:CANTP_STANDARD
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.CanTp_CancelTransmit.CanTpTxSduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.EXPECTED:CanTp.CanTp_CancelTransmit.return:E_OK
TEST.END

-- Test Case: CanTp_CancelTransmit.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelTransmit
TEST.NEW
TEST.NAME:CanTp_CancelTransmit.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nas:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nbs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Ncs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:TRUE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:CANTP_STANDARD
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.CanTp_CancelTransmit.CanTpTxSduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.EXPECTED:CanTp.CanTp_CancelTransmit.return:E_OK
TEST.END

-- Test Case: CanTp_CancelTransmit.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CancelTransmit
TEST.NEW
TEST.NAME:CanTp_CancelTransmit.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nas:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nbs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Ncs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:TRUE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:CANTP_STANDARD
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.CanTp_CancelTransmit.CanTpTxSduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT
TEST.EXPECTED:CanTp.CanTp_CancelTransmit.return:E_NOT_OK
TEST.END

-- Subprogram: CanTp_CheckAndDecodeRxDl

-- Test Case: CanTp_CheckAndDecodeRxDl.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:CANTP_MIXED
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 64>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0x11
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:64
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:E_OK
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 12>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[3]:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[4]:0x1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[5]:0xFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:12
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 64>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0x11
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:0x100
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:E_OK
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:CANTP_MIXED
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 64>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0x11
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:3
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PciType:1
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:17
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:64
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:0x1
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x7
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:8
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:7
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x7
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:8
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:7
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x7
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:7
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:CANTP_MIXED
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x7
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:8
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:3
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PciType:1
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:16
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:7
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:1793
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:CANTP_MIXED
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:2
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:3
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:3
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:3
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PciType:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:2
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:16
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:3
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:2
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:8
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:8
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:E_OK
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.012
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:2
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:7
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:8
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.013
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.013
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:2
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:3
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:3
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:E_OK
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.014
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.014
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:2
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:3
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.017
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.017
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0x21
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:8
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:E_OK
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.018
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.018
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_INVALID
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:8
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.022
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.022
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:3
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:3
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.023
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.023
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_UtilGetPaddingLength
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_UtilGetPaddingLength.return:9
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x7
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:0x1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:8
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:7
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.024
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.024
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x7
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:8
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:7
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.025
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.025
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:CANTP_STANDARD
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 4>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x9
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:0x10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[3]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:12
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTp_CheckAndDecodeRxDl.026
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_CheckAndDecodeRxDl
TEST.NEW
TEST.NAME:CanTp_CheckAndDecodeRxDl.026
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_UtilGetPaddingLength
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:7
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_UtilGetPaddingLength.return:7
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:CANTP_MIXED
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:CANTP_OFF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 5>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0x0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[1]:0x9
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:0x0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[3]:2
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[4]:10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:12
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanTp_GetVersionInfo

-- Test Case: CanTp_GetVersionInfo.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_GetVersionInfo
TEST.NEW
TEST.NAME:CanTp_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_GetVersionInfo.VersionInfo:<<malloc 1>>
TEST.EXPECTED:CanTp.CanTp_GetVersionInfo.VersionInfo[0].vendorID:51
TEST.END

-- Test Case: CanTp_GetVersionInfo.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_GetVersionInfo
TEST.NEW
TEST.NAME:CanTp_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_GetVersionInfo.VersionInfo:<<malloc 1>>
TEST.EXPECTED:CanTp.CanTp_GetVersionInfo.VersionInfo[0].vendorID:CANTP_VENDOR_ID
TEST.EXPECTED:CanTp.CanTp_GetVersionInfo.VersionInfo[0].moduleID:CANTP_MODULE_ID
TEST.EXPECTED:CanTp.CanTp_GetVersionInfo.VersionInfo[0].sw_major_version:CANTP_SW_MAJOR_VERSION
TEST.EXPECTED:CanTp.CanTp_GetVersionInfo.VersionInfo[0].sw_minor_version:CANTP_SW_MINOR_VERSION
TEST.EXPECTED:CanTp.CanTp_GetVersionInfo.VersionInfo[0].sw_patch_version:CANTP_SW_PATCH_VERSION
TEST.END

-- Subprogram: CanTp_Init

-- Test Case: CanTp_Init.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Init
TEST.NEW
TEST.NAME:CanTp_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_OFF
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:CANTP_INVALID_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[7]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_CONNECTION_NONE
TEST.END

-- Test Case: CanTp_Init.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Init
TEST.NEW
TEST.NAME:CanTp_Init.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_OFF
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:CANTP_INVALID_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_NONE
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_CONNECTION_NONE
TEST.ATTRIBUTES:CanTp.<<GLOBAL>>.CanTp_ChannelState.CanTp_ChannelState[0].TxConnection.DataBuffer[31]:EXPECTED_BASE=8
TEST.END

-- Subprogram: CanTp_InitChannels

-- Test Case: CanTp_InitChannels.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_InitChannels
TEST.NEW
TEST.NAME:CanTp_InitChannels.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanTp_InitRxConnection

-- Test Case: CanTp_InitRxConnection.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_InitRxConnection
TEST.NEW
TEST.NAME:CanTp_InitRxConnection.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_InitRxConnection.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_InitRxConnection.ChannelStatePtr[0].RxConnection.NsduId:CANTP_NUM_OF_RX_NSDU
TEST.VALUE:CanTp.CanTp_InitRxConnection.ConnectionNotificationType:CANTP_NOTIFY_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.ATTRIBUTES:CanTp.<<GLOBAL>>.CanTp_ChannelState.CanTp_ChannelState[0].TxConnection.DataBuffer[31]:EXPECTED_BASE=8
TEST.END

-- Subprogram: CanTp_InitTxConnection

-- Test Case: CanTp_InitTxConnection.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_InitTxConnection
TEST.NEW
TEST.NAME:CanTp_InitTxConnection.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_InitTxConnection.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_InitTxConnection.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.VALUE:CanTp.CanTp_InitTxConnection.ChannelStatePtr[0].TxConnection.NsduId:CANTP_NUM_OF_TX_NSDU
TEST.EXPECTED:CanTp.CanTp_InitTxConnection.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.END

-- Subprogram: CanTp_MainFunction

-- Test Case: CanTp_MainFunction.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_MainFunction
TEST.NEW
TEST.NAME:CanTp_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_OFF
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_InternalState:0
TEST.END

-- Test Case: CanTp_MainFunction.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_MainFunction
TEST.NEW
TEST.NAME:CanTp_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.END

-- Subprogram: CanTp_ProcessFlowControlConfirmation

-- Test Case: CanTp_ProcessFlowControlConfirmation.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessFlowControlConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessFlowControlConfirmation.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.NsduId:CANTP_NUM_OF_RX_NSDU
TEST.EXPECTED:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.END

-- Test Case: CanTp_ProcessFlowControlConfirmation.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessFlowControlConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessFlowControlConfirmation.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_ProcessFlowControlConfirmation.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessFlowControlConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessFlowControlConfirmation.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_CTS
TEST.EXPECTED:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.END

-- Test Case: CanTp_ProcessFlowControlConfirmation.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessFlowControlConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessFlowControlConfirmation.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_OVERFLOW
TEST.EXPECTED:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_ProcessFlowControlConfirmation.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessFlowControlConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessFlowControlConfirmation.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_WAIT
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:2
TEST.EXPECTED:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.EXPECTED:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.END

-- Test Case: CanTp_ProcessFlowControlConfirmation.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessFlowControlConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessFlowControlConfirmation.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_WAIT
TEST.VALUE:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.EXPECTED:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_NONE
TEST.EXPECTED:CanTp.CanTp_ProcessFlowControlConfirmation.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:0
TEST.END

-- Subprogram: CanTp_ProcessTxConfirmation

-- Test Case: CanTp_ProcessTxConfirmation.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:CANTP_NUM_OF_TX_NSDU
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.END

-- Test Case: CanTp_ProcessTxConfirmation.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.END

-- Test Case: CanTp_ProcessTxConfirmation.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.END

-- Test Case: CanTp_ProcessTxConfirmation.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.END

-- Test Case: CanTp_ProcessTxConfirmation.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.END

-- Test Case: CanTp_ProcessTxConfirmation.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.BlockSizeCounter:1
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.RemainingNsduLength:8
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.BlockSizeCounter:0
TEST.END

-- Test Case: CanTp_ProcessTxConfirmation.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.BlockSizeCounter:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.StMinValue:10
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.RemainingNsduLength:8
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_STMIN_WAIT
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.StMinValue:10
TEST.END

-- Test Case: CanTp_ProcessTxConfirmation.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.BlockSizeCounter:5
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.StMinValue:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.RemainingNsduLength:8
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.BlockSizeCounter:4
TEST.END

-- Test Case: CanTp_ProcessTxConfirmation.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_FF
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT
TEST.END

-- Test Case: CanTp_ProcessTxConfirmation.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.BlockSizeCounter:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.StMinValue:1
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.RemainingNsduLength:8
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_STMIN_WAIT
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.BlockSizeCounter:0
TEST.END

-- Test Case: CanTp_ProcessTxConfirmation.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.BlockSizeCounter:0
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.StMinValue:6
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.RemainingNsduLength:8
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_STMIN_WAIT
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.BlockSizeCounter:0
TEST.END

-- Test Case: CanTp_ProcessTxConfirmation.012
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_ProcessTxConfirmation
TEST.NEW
TEST.NAME:CanTp_ProcessTxConfirmation.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.CanTp_ProcessTxConfirmation.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.END

-- Subprogram: CanTp_RxChannelProcessing

-- Test Case: CanTp_RxChannelProcessing.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:CANTP_NUM_OF_CHANNELS
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxChannelProcessing.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.END

-- Test Case: CanTp_RxChannelProcessing.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0x0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.END

-- Test Case: CanTp_RxChannelProcessing.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_NONE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:1
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:CANTP_INVALID_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_NONE
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.END

-- Test Case: CanTp_RxChannelProcessing.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:1
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:CANTP_INVALID_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_NONE
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.END

-- Test Case: CanTp_RxChannelProcessing.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:10
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciProcessorFn:<<null>>
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciBufferProcessorFn:<<null>>
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.END

-- Test Case: CanTp_RxChannelProcessing.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:10
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciProcessorFn:<<null>>
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciBufferProcessorFn:<<null>>
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:9
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.END

-- Test Case: CanTp_RxChannelProcessing.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:10
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciProcessorFn:<<null>>
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciBufferProcessorFn:<<null>>
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:9
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.END

-- Test Case: CanTp_RxChannelProcessing.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:CANTP_NUM_OF_RX_NSDU
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:10
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:9
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.END

-- Test Case: CanTp_RxChannelProcessing.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:10
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciProcessorFn:<<null>>
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciBufferProcessorFn:<<null>>
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:9
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.END

-- Test Case: CanTp_RxChannelProcessing.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:10
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciProcessorFn:CanTp_RxSingleFrameProcessor
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciBufferProcessorFn:CanTp_RxSingleFrameBufferProcessor
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.END

-- Test Case: CanTp_RxChannelProcessing.012
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_RxChannelProcessing.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlStatus:0x1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:1
TEST.VALUE:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:4
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlStatus:0x1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.EXPECTED:CanTp.CanTp_RxChannelProcessing.ChannelId:0
TEST.END

-- Subprogram: CanTp_RxConsecutiveFrameBufferProcessor

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:CANTP_NUM_OF_RX_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_E_BUSY
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_E_BUSY
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_E_BUSY
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_E_BUSY
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_E_BUSY
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:3
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:14
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:2
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:14
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:14
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK,BUFREQ_E_NOT_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:20
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.ConnectionState:4
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:12
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:20
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:8
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:14
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:20
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.012
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:14
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:7
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK,BUFREQ_E_BUSY
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_CONF_WAIT
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.013
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.013
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:3
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:3
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:CANTP_NUM_OF_RX_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.014
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.014
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:20
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:21
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.015
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.015
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_UtilGetBlockSizeInBytes
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:19
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].TxConnection.RemainingNsduLength:19
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].TxConnection.AvailableBuffer:20
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.ConnectionState:4
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:19
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:20
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].RemainingNsduLength:1
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].AvailableBuffer:20
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.return:21
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.ConnectionState:4
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.016
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.016
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_E_BUSY
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:9
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_E_BUSY
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.017
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.017
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_UtilGetBlockSizeInBytes
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:19
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].TxConnection.RemainingNsduLength:19
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].TxConnection.AvailableBuffer:20
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.ConnectionState:4
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:3
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:19
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].RemainingNsduLength:1
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].AvailableBuffer:20
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.return:21
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:19
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:20
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].TxConnection.RemainingNsduLength:19
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].TxConnection.AvailableBuffer:20
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.ConnectionState:4
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:3
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:1
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:19
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:8
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameBufferProcessor.018
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameBufferProcessor.018
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_UtilGetBlockSizeInBytes
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:19
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].TxConnection.RemainingNsduLength:19
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].TxConnection.AvailableBuffer:20
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.ConnectionState:4
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:19
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:20
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:8
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].RemainingNsduLength:1
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].AvailableBuffer:0
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.return:21
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:19
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:20
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].TxConnection.RemainingNsduLength:19
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].TxConnection.AvailableBuffer:20
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameBufferProcessor.RxUpperLayerId:0
TEST.EXPECTED:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].RemainingNsduLength:11
TEST.EXPECTED:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].AvailableBuffer:20
TEST.END

-- Subprogram: CanTp_RxConsecutiveFrameProcessor

-- Test Case: CanTp_RxConsecutiveFrameProcessor.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameProcessor.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:CANTP_NUM_OF_RX_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameProcessor.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameProcessor.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:CANTP_NUM_OF_CHANNELS
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameProcessor.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameProcessor.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameProcessor.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameProcessor.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameProcessor.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameProcessor.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameProcessor.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameProcessor.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameProcessor.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameProcessor.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameProcessor.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameProcessor.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduLength:5
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameProcessor.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameProcessor.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:6
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.RemainingNsduLength:6
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduLength:5
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:6
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.RemainingNsduLength:6
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduLength:5
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameProcessor.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameProcessor.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.SequenceNumber:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduLength:5
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduLength:5
TEST.END

-- Test Case: CanTp_RxConsecutiveFrameProcessor.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxConsecutiveFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxConsecutiveFrameProcessor.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:10
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.RemainingNsduLength:10
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.FirstFrameDataLength:7
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduLength:7
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:10
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[1].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:1
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.CanTp_RxConsecutiveFrameProcessor.DataInfoPtr[0].SduLength:7
TEST.END

-- Subprogram: CanTp_RxFirstFrameBufferProcessor

-- Test Case: CanTp_RxFirstFrameBufferProcessor.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:12
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFirstFrameBufferProcessor.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_E_BUSY
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:100
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_E_BUSY
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:255
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.END

-- Test Case: CanTp_RxFirstFrameBufferProcessor.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_E_BUSY
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:100
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:255
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.ATTRIBUTES:CanTp.<<GLOBAL>>.CanTp_ChannelState.CanTp_ChannelState[0].TxConnection.DataBuffer[31]:EXPECTED_BASE=8
TEST.END

-- Test Case: CanTp_RxFirstFrameBufferProcessor.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_E_BUSY
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:100
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_E_OVFL
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_E_OVFL
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:10
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.END

-- Test Case: CanTp_RxFirstFrameBufferProcessor.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:100
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:10
TEST.END

-- Test Case: CanTp_RxFirstFrameBufferProcessor.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:10
TEST.END

-- Test Case: CanTp_RxFirstFrameBufferProcessor.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:100
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:10
TEST.END

-- Test Case: CanTp_RxFirstFrameBufferProcessor.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].TxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].TxConnection.AvailableBuffer:21
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].TxConnection.DataBufferLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:21
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].TxConnection.RemainingNsduLength:20
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].TxConnection.AvailableBuffer:21
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].TxConnection.DataBufferLength:20
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:21
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:20
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.END

-- Test Case: CanTp_RxFirstFrameBufferProcessor.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:10
TEST.END

-- Test Case: CanTp_RxFirstFrameBufferProcessor.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_E_BUSY
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_E_BUSY
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:10
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:10
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.END

-- Test Case: CanTp_RxFirstFrameBufferProcessor.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_UtilGetBlockSizeInBytes
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:20
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].AvailableBuffer:7
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.return:9
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.bufferSizePtr[0]:2
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:10
TEST.END

-- Test Case: CanTp_RxFirstFrameBufferProcessor.012
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameBufferProcessor.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_UtilGetBlockSizeInBytes
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:10
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].AvailableBuffer:7
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.return:9
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.bufferSizePtr[0]:2
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.RemainingNsduLength:2
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.FirstFrameDataLength:8
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:7
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameBufferProcessor.RxUpperLayerId:0
TEST.EXPECTED:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].AvailableBuffer:2
TEST.EXPECTED:uut_prototype_stubs.PduR_CanTpCopyRxData.bufferSizePtr[0]:10
TEST.END

-- Subprogram: CanTp_RxFirstFrameProcessor

-- Test Case: CanTp_RxFirstFrameProcessor.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameProcessor.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFirstFrameProcessor.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameProcessor.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:CANTP_NUM_OF_RX_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFirstFrameProcessor.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameProcessor.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:CANTP_NUM_OF_CHANNELS
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFirstFrameProcessor.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameProcessor.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_InitRxConnection
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlStatus:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.END

-- Test Case: CanTp_RxFirstFrameProcessor.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameProcessor.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_InitRxConnection
TEST.STUB:CanTp.CanTp_SendFlowControl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.END

-- Test Case: CanTp_RxFirstFrameProcessor.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameProcessor.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_InitRxConnection
TEST.STUB:CanTp.CanTp_SendFlowControl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:0x1
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:0x1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.END

-- Test Case: CanTp_RxFirstFrameProcessor.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameProcessor.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_InitRxConnection
TEST.STUB:CanTp.CanTp_SendFlowControl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:0x1
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:0x1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.END

-- Test Case: CanTp_RxFirstFrameProcessor.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameProcessor.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_InitRxConnection
TEST.STUB:CanTp.CanTp_SendFlowControl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:0x1
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:0x1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.END

-- Test Case: CanTp_RxFirstFrameProcessor.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFirstFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFirstFrameProcessor.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_InitRxConnection
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.STUB:CanTp.CanTp_SendFlowControl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:0x1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].Nar:10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].Nbr:10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].Ncr:10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxWftMax:10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].TpSTmin:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].BlockSize:10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxNsduAddressingFormatType:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxPaddingActivation:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxTaType:10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].UpperLayerPduId:2
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].FlowControlTxNPduId:10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].FlowControlTxLowerLayerPduId:10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].IsDataInStartOfReception:10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PciType:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].MetaDataPtr[0]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduLength:10
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.ReceivedNsduLengthPtr[0]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFirstFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:0x1
TEST.EXPECTED:CanTp.CanTp_RxFirstFrameProcessor.RxNsduId:0
TEST.END

-- Subprogram: CanTp_RxFlowControlFrameProcessor

-- Test Case: CanTp_RxFlowControlFrameProcessor.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:CANTP_NUM_OF_CHANNELS
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:CANTP_NUM_OF_TX_NSDU
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:CANTP_FUNCTIONAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:CANTP_NUM_OF_RX_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.012
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.ATTRIBUTES:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]::EXPECTED_BASE=16
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.013
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.013
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:5
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:25
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:127
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.ATTRIBUTES:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]::EXPECTED_BASE=16
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.014
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.014
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxTaType:3
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.ATTRIBUTES:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]::EXPECTED_BASE=16
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.015
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.015
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxTaType:3
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.ATTRIBUTES:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]::EXPECTED_BASE=16
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.016
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.016
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.ATTRIBUTES:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]::EXPECTED_BASE=16
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.017
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.017
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 4>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:0x7F
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[3]:0x7F
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:5
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:127
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.ATTRIBUTES:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:EXPECTED_BASE=16
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.018
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.018
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTp::CanTp_Detailed_Design::CanTp_ClassDiagram
Requirement_DICVA-13780
TEST.END_NOTES:
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:0x3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.019
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.019
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:0x1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxTaType:3
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:0x1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.020
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.020
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:0x2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxTaType:3
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:0x2
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.021
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.021
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:0x2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0x1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxTaType:3
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:0x2
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0x1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.022
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.022
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:0x2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0x1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxTaType:3
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:0x2
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0x1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.023
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.023
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:0x2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0x1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0xFF
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.RxNSduConfigPtr[0].RxTaType:3
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:1
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:0x2
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0x1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.024
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.024
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 4>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:245
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[3]:245
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[0]:245
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[1]:245
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[2]:245
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:5
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:0xF5
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[3]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[0]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[1]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[2]:245
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.025
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.025
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 4>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:250
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[0]:245
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[1]:245
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[2]:250
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:5
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:0xFA
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[0]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[1]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[2]:250
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.026
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.026
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:2
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[0]:2
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[0]:2
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[0]:2
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.027
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.027
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 4>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:245
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[3]:245
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[0]:245
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[1]:245
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[2]:245
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:5
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:0xF5
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[3]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[0]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[1]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[2]:245
TEST.END

-- Test Case: CanTp_RxFlowControlFrameProcessor.028
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxFlowControlFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxFlowControlFrameProcessor.028
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:3
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr:<<malloc 4>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[3]:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[0]:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[1]:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[2]:0
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxFlowControlFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxTaType:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[2]:0x0
TEST.EXPECTED:CanTp.CanTp_CheckAndDecodeRxDl.PduInfoPtr[0].SduDataPtr[3]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[0]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[1]:0
TEST.EXPECTED:CanTp.CanTp_RxFlowControlFrameProcessor.DataInfoPtr[0].SduDataPtr[2]:0
TEST.END

-- Subprogram: CanTp_RxIndication

-- Test Case: COND_10_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_10_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:26 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 26
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      (7) if (1 == ((PciType < 4U) ? 1 : 0)) ==> TRUE
      (9) if (1U == ChMode && 0U == TxConnectionPtr->ConnectionState || 0U == ChMode) ==> TRUE
      (10) if (PciProcessorFn != (void *)0) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #10, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set variable PciProcessorFn in branch 10 since it has a type which requires user code.
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Cannot set local variable RxNSduConfigPtr in branch 7
      Conflict: Unable to validate expression-to-expression comparison in branch 7
      Cannot set TxConnectionPtr due to assignment
      Cannot set local variable TxConnectionPtr in branch 9
      Cannot set local variable TxConnectionPtr in branch 10
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_10_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_10_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:25 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 25
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      (7) if (1 == ((PciType < 4U) ? 1 : 0)) ==> TRUE
      (9) if (1U == ChMode && 0U == TxConnectionPtr->ConnectionState || 0U == ChMode) ==> TRUE
      (10) if (PciProcessorFn != (void *)0) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #10, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set variable PciProcessorFn in branch 10 since it has a type which requires user code.
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Cannot set local variable RxNSduConfigPtr in branch 7
      Conflict: Unable to validate expression-to-expression comparison in branch 7
      Cannot set TxConnectionPtr due to assignment
      Cannot set local variable TxConnectionPtr in branch 9
      Cannot set local variable TxConnectionPtr in branch 10
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_11_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_11_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:13 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 13
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> FALSE
      (11) if (0U != ErrorId) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #11, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable ErrorId in branch 11
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_11_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_11_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:12 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 12
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> FALSE
      (11) if (0U != ErrorId) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #11, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable ErrorId in branch 11
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_1_ROW_1_PAIR_a_T
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_1_ROW_1_PAIR_a_T
TEST.MCDC_BASIS_PATH:2 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CanTp_InternalState) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #1, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_3_ROW_4_PAIR_a_FF
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_3_ROW_4_PAIR_a_FF
TEST.MCDC_BASIS_PATH:5 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      Row number 4 forms a pair with Row 2 for Condition #3, subcondition "a".
         Condition a ==> FALSE
         Condition b ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_4_ROW_1_PAIR_a_T
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_4_ROW_1_PAIR_a_T
TEST.MCDC_BASIS_PATH:9 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #4, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_4_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_4_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:8 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #4, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MAX>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_5_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_5_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:11 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #5, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable RxNsduId in branch 5
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_5_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_5_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:10 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #5, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable RxNsduId in branch 5
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_6_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_6_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:15 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 15
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #6, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_6_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_6_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:14 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 14
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #6, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_7_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_7_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:17 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 17
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      (7) if (1 == ((PciType < 4U) ? 1 : 0)) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #7, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 7
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Cannot set local variable RxNSduConfigPtr in branch 7
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_7_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_7_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:16 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 16
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      (7) if (1 == ((PciType < 4U) ? 1 : 0)) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #7, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 7
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Cannot set local variable RxNSduConfigPtr in branch 7
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_8_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_8_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:18 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 18
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      (7) if (1 == ((PciType < 4U) ? 1 : 0)) ==> TRUE
      (8) (PciType < 4U) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #8, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set PciType due to assignment
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Cannot set local variable RxNSduConfigPtr in branch 7
      Conflict: Unable to validate expression-to-expression comparison in branch 7
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_8_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_8_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:19 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 19
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      (7) if (1 == ((PciType < 4U) ? 1 : 0)) ==> TRUE
      (8) (PciType < 4U) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #8, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set PciType due to assignment
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Cannot set local variable RxNSduConfigPtr in branch 7
      Conflict: Unable to validate expression-to-expression comparison in branch 7
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_9_ROW_2_PAIR_a_TTF-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_9_ROW_2_PAIR_a_TTF-PARTIAL
TEST.MCDC_BASIS_PATH:21 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 21
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      (7) if (1 == ((PciType < 4U) ? 1 : 0)) ==> TRUE
      (9) if (1U == ChMode && 0U == TxConnectionPtr->ConnectionState || 0U == ChMode) ==> TRUE
      Row number 2 forms a pair with Row 6 for Condition #9, subcondition "a".
         Condition a ==> TRUE
         Condition b ==> TRUE
         Condition c ==> FALSE
   Test Case Generation Notes:
      Cannot set TxConnectionPtr due to assignment
      Cannot set local variable TxConnectionPtr in branch 9
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Cannot set local variable RxNSduConfigPtr in branch 7
      Conflict: Unable to validate expression-to-expression comparison in branch 7
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_9_ROW_4_PAIR_b_TFF-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_9_ROW_4_PAIR_b_TFF-PARTIAL
TEST.MCDC_BASIS_PATH:22 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 22
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      (7) if (1 == ((PciType < 4U) ? 1 : 0)) ==> TRUE
      (9) if (1U == ChMode && 0U == TxConnectionPtr->ConnectionState || 0U == ChMode) ==> FALSE
      Row number 4 forms a pair with Row 2 for Condition #9, subcondition "b".
         Condition a ==> TRUE
         Condition b ==> FALSE
         Condition c ==> FALSE
   Test Case Generation Notes:
      Cannot set TxConnectionPtr due to assignment
      Cannot set local variable TxConnectionPtr in branch 9
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Cannot set local variable RxNSduConfigPtr in branch 7
      Conflict: Unable to validate expression-to-expression comparison in branch 7
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:1
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_9_ROW_6_PAIR_a_FTF-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_9_ROW_6_PAIR_a_FTF-PARTIAL
TEST.MCDC_BASIS_PATH:20 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 20
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      (7) if (1 == ((PciType < 4U) ? 1 : 0)) ==> TRUE
      (9) if (1U == ChMode && 0U == TxConnectionPtr->ConnectionState || 0U == ChMode) ==> FALSE
      Row number 6 forms a pair with Row 2 for Condition #9, subcondition "a".
         Condition a ==> FALSE
         Condition b ==> TRUE
         Condition c ==> FALSE
   Test Case Generation Notes:
      Cannot set TxConnectionPtr due to assignment
      Cannot set local variable TxConnectionPtr in branch 9
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Cannot set local variable RxNSduConfigPtr in branch 7
      Conflict: Unable to validate expression-to-expression comparison in branch 7
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:2
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_9_ROW_7_PAIR_c_FFT-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_9_ROW_7_PAIR_c_FFT-PARTIAL
TEST.MCDC_BASIS_PATH:24 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 24
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      (7) if (1 == ((PciType < 4U) ? 1 : 0)) ==> TRUE
      (9) if (1U == ChMode && 0U == TxConnectionPtr->ConnectionState || 0U == ChMode) ==> TRUE
      Row number 7 forms a pair with Row 8 for Condition #9, subcondition "c".
         Condition a ==> FALSE
         Condition b ==> FALSE
         Condition c ==> TRUE
   Test Case Generation Notes:
      Cannot set TxConnectionPtr due to assignment
      Cannot set local variable TxConnectionPtr in branch 9
      Conflict: Trying to set variable ChMode: 'equal to' and 'not equal to' same value in branch 9
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Cannot set local variable RxNSduConfigPtr in branch 7
      Conflict: Unable to validate expression-to-expression comparison in branch 7
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:2
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_9_ROW_8_PAIR_c_FFF-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:COND_9_ROW_8_PAIR_c_FFF-PARTIAL
TEST.MCDC_BASIS_PATH:23 of 26
TEST.NOTES:
This is an automatically generated test case.
   Test Path 23
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= RxPduId) ==> FALSE
      (3) if ((void *)0 == PduInfoPtr || (void *)0 == PduInfoPtr->SduDataPtr) ==> FALSE
      (4) if (2U > RxPduId) ==> FALSE
      (5) if (2U > RxNsduId) ==> TRUE
      (6) if (2U > RxNSduConfigPtr->ChannelId) ==> TRUE
      (7) if (1 == ((PciType < 4U) ? 1 : 0)) ==> TRUE
      (9) if (1U == ChMode && 0U == TxConnectionPtr->ConnectionState || 0U == ChMode) ==> FALSE
      Row number 8 forms a pair with Row 7 for Condition #9, subcondition "c".
         Condition a ==> FALSE
         Condition b ==> FALSE
         Condition c ==> FALSE
   Test Case Generation Notes:
      Cannot set TxConnectionPtr due to assignment
      Cannot set local variable TxConnectionPtr in branch 9
      Conflict: Trying to set variable CanTp.CanTp_RxIndication.RxPduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable RxNsduId in branch 5
      Cannot set RxNSduConfigPtr due to assignment
      Cannot set local variable RxNSduConfigPtr in branch 6
      Cannot set local variable RxNSduConfigPtr in branch 7
      Conflict: Unable to validate expression-to-expression comparison in branch 7
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:2
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTp_RxIndication.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:CanTp_RxIndication.001
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_OFF
TEST.END

-- Test Case: CanTp_RxIndication.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:CanTp_RxIndication.005
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:CANTP_NUM_OF_RX_NSDU
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:CANTP_NUM_OF_CHANNELS
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:0
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxIndication.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:CanTp_RxIndication.006
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:CANTP_NUM_OF_CHANNELS
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:0
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxIndication.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:CanTp_RxIndication.007
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_HALF_DUPLEX
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:0
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[0]:0xF7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[1]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[2]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[3]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[4]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[5]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[7]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxIndication.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:CanTp_RxIndication.008
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_HALF_DUPLEX
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:0
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[0]:0x7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[1]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[2]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[3]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[4]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[5]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[7]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxIndication.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:CanTp_RxIndication.009
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciProcessorFn:<<null>>
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciBufferProcessorFn:<<null>>
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_HALF_DUPLEX
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdEnd:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdEnd:0
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:0
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[0]:0x7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[1]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[2]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[3]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[4]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[5]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[7]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxIndication.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:CanTp_RxIndication.010
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_FULL_DUPLEX
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdEnd:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdEnd:0
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:0
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[0]:0x7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[1]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[2]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[3]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[4]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[5]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[7]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxIndication.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:CanTp_RxIndication.011
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciProcessorFn:CanTp_RxSingleFrameProcessor
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciBufferProcessorFn:CanTp_RxSingleFrameBufferProcessor
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_FULL_DUPLEX
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdEnd:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdEnd:0
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:0
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[0]:0x7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[1]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[2]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[3]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[4]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[5]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[7]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxIndication.012
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:CanTp_RxIndication.012
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciProcessorFn:CanTp_RxSingleFrameProcessor
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciBufferProcessorFn:CanTp_RxSingleFrameBufferProcessor
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_FULL_DUPLEX
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdEnd:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdEnd:0
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:0
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[0]:0x7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[1]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[2]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[3]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[4]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[5]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[7]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.END

-- Test Case: CanTp_RxIndication.013
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxIndication
TEST.NEW
TEST.NAME:CanTp_RxIndication.013
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciProcessorFn:CanTp_RxSingleFrameProcessor
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_FrameProcessorConfig[0].RxPciBufferProcessorFn:CanTp_RxSingleFrameBufferProcessor
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_FULL_DUPLEX
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdEnd:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdEnd:0
TEST.VALUE:CanTp.CanTp_RxIndication.RxPduId:0
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[0]:0x7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[1]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[2]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[3]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[4]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[5]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduDataPtr[7]:7
TEST.VALUE:CanTp.CanTp_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.END

-- Subprogram: CanTp_RxSingleFrameBufferProcessor

-- Test Case: CanTp_RxSingleFrameBufferProcessor.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameBufferProcessor.001
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.AvailableBuffer:10
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBufferLength:7
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[6]:7
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.DataBuffer[7]:8
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.UpperlayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_E_BUSY
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.END

-- Test Case: CanTp_RxSingleFrameBufferProcessor.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameBufferProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameBufferProcessor.002
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.ChannelStatePtr[0].RxConnection.BufferState:BUFREQ_E_BUSY
TEST.VALUE:CanTp.CanTp_RxSingleFrameBufferProcessor.UpperlayerId:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyRxData.return:BUFREQ_E_BUSY
TEST.END

-- Subprogram: CanTp_RxSingleFrameProcessor

-- Test Case: CanTp_RxSingleFrameProcessor.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameProcessor.005
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:CANTP_NUM_OF_CHANNELS
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxSingleFrameProcessor.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameProcessor.006
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:CANTP_NUM_OF_RX_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.END

-- Test Case: CanTp_RxSingleFrameProcessor.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameProcessor.007
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.END

-- Test Case: CanTp_RxSingleFrameProcessor.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameProcessor.008
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.END

-- Test Case: CanTp_RxSingleFrameProcessor.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameProcessor.009
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.END

-- Test Case: CanTp_RxSingleFrameProcessor.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameProcessor.010
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.END

-- Test Case: CanTp_RxSingleFrameProcessor.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameProcessor.011
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.END

-- Test Case: CanTp_RxSingleFrameProcessor.012
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameProcessor.012
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:1
TEST.EXPECTED:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.END

-- Test Case: CanTp_RxSingleFrameProcessor.013
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameProcessor.013
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.return:BUFREQ_E_BUSY
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:1
TEST.EXPECTED:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.END

-- Test Case: CanTp_RxSingleFrameProcessor.014
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_RxSingleFrameProcessor
TEST.NEW
TEST.NAME:CanTp_RxSingleFrameProcessor.014
TEST.STUB:CanTp.CanTp_CheckAndDecodeRxDl
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:1
TEST.VALUE:CanTp.CanTp_CheckAndDecodeRxDl.return:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.DataInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_RxSingleFrameProcessor.MetaInfoPtr[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.info[0].MetaDataPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PduR_CanTpStartOfReception.return:BUFREQ_E_OVFL
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxPduToNsduMap[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].IsDataInStartOfReception:1
TEST.EXPECTED:CanTp.CanTp_RxSingleFrameProcessor.RxNsduId:0
TEST.END

-- Subprogram: CanTp_SendFlowControl

-- Test Case: CanTp_SendFlowControl.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_SendFlowControl
TEST.NEW
TEST.NAME:CanTp_SendFlowControl.001
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:CANTP_NUM_OF_RX_NSDU
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_CTS
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:CANTP_TRANSMIT_NOT_OK
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_CTS
TEST.END

-- Test Case: CanTp_SendFlowControl.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_SendFlowControl
TEST.NEW
TEST.NAME:CanTp_SendFlowControl.002
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:CANTP_NUM_OF_TX_NSDU
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_CTS
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:CANTP_TRANSMIT_NOT_OK
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_CTS
TEST.END

-- Test Case: CanTp_SendFlowControl.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_SendFlowControl
TEST.NEW
TEST.NAME:CanTp_SendFlowControl.003
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_TX_CONNECTION
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_CTS
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].TxRequestType:CANTP_TRANSMIT_BY_TX_CONNECTION
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:(2)CANTP_TRANSMIT_BUSY
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_CTS
TEST.END

-- Test Case: CanTp_SendFlowControl.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_SendFlowControl
TEST.NEW
TEST.NAME:CanTp_SendFlowControl.004
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_CTS
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:CANTP_TRANSMIT_NOT_OK
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_NONE
TEST.END

-- Test Case: CanTp_SendFlowControl.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_SendFlowControl
TEST.NEW
TEST.NAME:CanTp_SendFlowControl.005
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_CTS
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:CANTP_TRANSMIT_NOT_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_NONE
TEST.END

-- Test Case: CanTp_SendFlowControl.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_SendFlowControl
TEST.NEW
TEST.NAME:CanTp_SendFlowControl.006
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_CTS
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:CANTP_TRANSMIT_NOT_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_NONE
TEST.END

-- Test Case: CanTp_SendFlowControl.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_SendFlowControl
TEST.NEW
TEST.NAME:CanTp_SendFlowControl.007
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:1
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:CANTP_TRANSMIT_NOT_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:255
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:255
TEST.END

-- Test Case: CanTp_SendFlowControl.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_SendFlowControl
TEST.NEW
TEST.NAME:CanTp_SendFlowControl.008
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:2
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:CANTP_TRANSMIT_NOT_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:255
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:255
TEST.END

-- Test Case: CanTp_SendFlowControl.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_SendFlowControl
TEST.NEW
TEST.NAME:CanTp_SendFlowControl.009
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:1
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:2
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:CANTP_TRANSMIT_NOT_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:0
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:255
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:255
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:0
TEST.END

-- Test Case: CanTp_SendFlowControl.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_SendFlowControl
TEST.NEW
TEST.NAME:CanTp_SendFlowControl.010
TEST.STUB:CanTp.CanTp_CanIfTransmitData
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FC_TRANSMIT
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:1
TEST.VALUE:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:2
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.return:0
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:CANTP_TRANSMIT_NOT_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].FlowControlTxNPduId:0
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.ConnectionState:4
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.NsduId:0
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlStatus:1
TEST.EXPECTED:CanTp.CanTp_SendFlowControl.ChannelStatePtr[0].RxConnection.FlowControlWaitCounter:2
TEST.END

-- Subprogram: CanTp_Shutdown

-- Test Case: CanTp_Shutdown.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Shutdown
TEST.NEW
TEST.NAME:CanTp_Shutdown.001
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_OFF
TEST.END

-- Test Case: CanTp_Shutdown.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Shutdown
TEST.NEW
TEST.NAME:CanTp_Shutdown.002
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_OFF
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:CANTP_INVALID_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBuffer[7]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.NsduId:CANTP_INVALID_NSDU
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlStatus:CANTP_FC_STATUS_NONE
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.STminValue:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.BlockSizeCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FlowControlWaitCounter:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.SequenceNumber:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.Timer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.RemainingNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.FirstFrameDataLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.TotalNsduLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.AvailableBuffer:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[0]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[1]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[2]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[3]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[4]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[5]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[6]:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBuffer[7]:0
TEST.END

-- Subprogram: CanTp_Transmit

-- Test Case: COND_10_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_10_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:24 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 24
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> TRUE
      (7) if ((0U) != CanTpTxInfoPtr->SduLength) ==> TRUE
      (8) if (1U == ChMode && 0U == RxConnectionPtr->ConnectionState || 0U == ChMode) ==> TRUE
      (9) if (TxNSduConfigPtr->MaxLowerLayerDataLength > (0U)) ==> TRUE
      (10) if (CanTpTxInfoPtr->SduLength > TxNSduConfigPtr->MaxLowerLayerDataLength - (1U)) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #10, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
      Cannot set TxNSduConfigPtr due to assignment
      Cannot set RxConnectionPtr due to assignment
      Cannot set local variable RxConnectionPtr in branch 8
      Cannot set local variable RxConnectionPtr in branch 9
      Cannot set local variable TxNSduConfigPtr in branch 9
      Cannot set local variable TxNSduConfigPtr in branch 10
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:<<MIN>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_11_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_11_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:12 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 12
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> FALSE
      (11) if (0U != ErrorId) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #11, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable ErrorId in branch 11
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_11_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_11_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:11 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> FALSE
      (11) if (0U != ErrorId) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #11, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable ErrorId in branch 11
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_1_ROW_1_PAIR_a_T
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_1_ROW_1_PAIR_a_T
TEST.MCDC_BASIS_PATH:2 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U != CanTp_InternalState) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #1, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_1_ROW_2_PAIR_a_F
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_1_ROW_2_PAIR_a_F
TEST.MCDC_BASIS_PATH:1 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (1U != CanTp_InternalState) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #1, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_2_ROW_1_PAIR_a_T
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_2_ROW_1_PAIR_a_T
TEST.MCDC_BASIS_PATH:4 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #2, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MAX>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_2_ROW_2_PAIR_a_F
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_2_ROW_2_PAIR_a_F
TEST.MCDC_BASIS_PATH:3 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #2, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_3_ROW_2_PAIR_a_F
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_3_ROW_2_PAIR_a_F
TEST.MCDC_BASIS_PATH:5 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #3, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_4_ROW_1_PAIR_a_T
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_4_ROW_1_PAIR_a_T
TEST.MCDC_BASIS_PATH:8 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #4, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_4_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_4_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:7 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #4, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MAX>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_5_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_5_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:10 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #5, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable TxNsduId in branch 5
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_5_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_5_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:9 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #5, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable TxNsduId in branch 5
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_6_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_6_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:14 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 14
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #6, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set TxNSduConfigPtr due to assignment
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_6_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_6_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:13 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 13
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #6, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set TxNSduConfigPtr due to assignment
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_7_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_7_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:16 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 16
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> TRUE
      (7) if ((0U) != CanTpTxInfoPtr->SduLength) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #7, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
      Cannot set TxNSduConfigPtr due to assignment
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_7_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_7_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:15 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 15
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> TRUE
      (7) if ((0U) != CanTpTxInfoPtr->SduLength) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #7, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
      Cannot set TxNSduConfigPtr due to assignment
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_8_ROW_2_PAIR_a_TTF-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_8_ROW_2_PAIR_a_TTF-PARTIAL
TEST.MCDC_BASIS_PATH:18 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 18
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> TRUE
      (7) if ((0U) != CanTpTxInfoPtr->SduLength) ==> TRUE
      (8) if (1U == ChMode && 0U == RxConnectionPtr->ConnectionState || 0U == ChMode) ==> TRUE
      Row number 2 forms a pair with Row 6 for Condition #8, subcondition "a".
         Condition a ==> TRUE
         Condition b ==> TRUE
         Condition c ==> FALSE
   Test Case Generation Notes:
      Cannot set RxConnectionPtr due to assignment
      Cannot set local variable RxConnectionPtr in branch 8
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
      Cannot set TxNSduConfigPtr due to assignment
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_8_ROW_4_PAIR_b_TFF-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_8_ROW_4_PAIR_b_TFF-PARTIAL
TEST.MCDC_BASIS_PATH:19 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 19
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> TRUE
      (7) if ((0U) != CanTpTxInfoPtr->SduLength) ==> TRUE
      (8) if (1U == ChMode && 0U == RxConnectionPtr->ConnectionState || 0U == ChMode) ==> FALSE
      Row number 4 forms a pair with Row 2 for Condition #8, subcondition "b".
         Condition a ==> TRUE
         Condition b ==> FALSE
         Condition c ==> FALSE
   Test Case Generation Notes:
      Cannot set RxConnectionPtr due to assignment
      Cannot set local variable RxConnectionPtr in branch 8
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
      Cannot set TxNSduConfigPtr due to assignment
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_8_ROW_6_PAIR_a_FTF-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_8_ROW_6_PAIR_a_FTF-PARTIAL
TEST.MCDC_BASIS_PATH:17 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 17
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> TRUE
      (7) if ((0U) != CanTpTxInfoPtr->SduLength) ==> TRUE
      (8) if (1U == ChMode && 0U == RxConnectionPtr->ConnectionState || 0U == ChMode) ==> FALSE
      Row number 6 forms a pair with Row 2 for Condition #8, subcondition "a".
         Condition a ==> FALSE
         Condition b ==> TRUE
         Condition c ==> FALSE
   Test Case Generation Notes:
      Cannot set RxConnectionPtr due to assignment
      Cannot set local variable RxConnectionPtr in branch 8
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
      Cannot set TxNSduConfigPtr due to assignment
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:2
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_8_ROW_7_PAIR_c_FFT-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_8_ROW_7_PAIR_c_FFT-PARTIAL
TEST.MCDC_BASIS_PATH:21 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 21
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> TRUE
      (7) if ((0U) != CanTpTxInfoPtr->SduLength) ==> TRUE
      (8) if (1U == ChMode && 0U == RxConnectionPtr->ConnectionState || 0U == ChMode) ==> TRUE
      Row number 7 forms a pair with Row 8 for Condition #8, subcondition "c".
         Condition a ==> FALSE
         Condition b ==> FALSE
         Condition c ==> TRUE
   Test Case Generation Notes:
      Cannot set RxConnectionPtr due to assignment
      Cannot set local variable RxConnectionPtr in branch 8
      Conflict: Trying to set variable ChMode: 'equal to' and 'not equal to' same value in branch 8
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
      Cannot set TxNSduConfigPtr due to assignment
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:2
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_8_ROW_8_PAIR_c_FFF-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_8_ROW_8_PAIR_c_FFF-PARTIAL
TEST.MCDC_BASIS_PATH:20 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 20
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> TRUE
      (7) if ((0U) != CanTpTxInfoPtr->SduLength) ==> TRUE
      (8) if (1U == ChMode && 0U == RxConnectionPtr->ConnectionState || 0U == ChMode) ==> FALSE
      Row number 8 forms a pair with Row 7 for Condition #8, subcondition "c".
         Condition a ==> FALSE
         Condition b ==> FALSE
         Condition c ==> FALSE
   Test Case Generation Notes:
      Cannot set RxConnectionPtr due to assignment
      Cannot set local variable RxConnectionPtr in branch 8
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
      Cannot set TxNSduConfigPtr due to assignment
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:2
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_9_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_9_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:23 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 23
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> TRUE
      (7) if ((0U) != CanTpTxInfoPtr->SduLength) ==> TRUE
      (8) if (1U == ChMode && 0U == RxConnectionPtr->ConnectionState || 0U == ChMode) ==> TRUE
      (9) if (TxNSduConfigPtr->MaxLowerLayerDataLength > (0U)) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #9, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set TxNSduConfigPtr due to assignment
      Cannot set local variable TxNSduConfigPtr in branch 9
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
      Cannot set RxConnectionPtr due to assignment
      Cannot set local variable RxConnectionPtr in branch 8
      Cannot set local variable RxConnectionPtr in branch 9
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: COND_9_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:COND_9_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:22 of 25
TEST.NOTES:
This is an automatically generated test case.
   Test Path 22
      (1) if (1U != CanTp_InternalState) ==> FALSE
      (2) if (2U <= CanTpTxSduId) ==> FALSE
      (3) if ((void *)0 == CanTpTxInfoPtr) ==> FALSE
      (4) if (2U > CanTpTxSduId) ==> FALSE
      (5) if (2U > TxNsduId) ==> TRUE
      (6) if (2U > ChId) ==> TRUE
      (7) if ((0U) != CanTpTxInfoPtr->SduLength) ==> TRUE
      (8) if (1U == ChMode && 0U == RxConnectionPtr->ConnectionState || 0U == ChMode) ==> TRUE
      (9) if (TxNSduConfigPtr->MaxLowerLayerDataLength > (0U)) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #9, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set TxNSduConfigPtr due to assignment
      Cannot set local variable TxNSduConfigPtr in branch 9
      Conflict: Trying to set variable CanTp.CanTp_Transmit.CanTpTxSduId 'less than' and 'greater than' same value in branches 2/4
      Cannot set local variable TxNsduId in branch 5
      Cannot set local variable TxNSduConfigPtr in branch 6
      Cannot set RxConnectionPtr due to assignment
      Cannot set local variable RxConnectionPtr in branch 8
      Cannot set local variable RxConnectionPtr in branch 9
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:1
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:<<MIN>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTp_Transmit.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:CanTp_Transmit.001
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_OFF
TEST.EXPECTED:CanTp.CanTp_Transmit.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_Transmit.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:CanTp_Transmit.004
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:CANTP_NUM_OF_TX_NSDU
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.CanTp_Transmit.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_Transmit.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:CanTp_Transmit.005
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:CANTP_NUM_OF_CHANNELS
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.EXPECTED:CanTp.CanTp_Transmit.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_Transmit.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:CanTp_Transmit.006
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:0
TEST.EXPECTED:CanTp.CanTp_Transmit.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_Transmit.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:CanTp_Transmit.007
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nas:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nbs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Ncs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:CANTP_STANDARD
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_HALF_DUPLEX
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdEnd:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdEnd:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.EXPECTED:CanTp.CanTp_Transmit.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_Transmit.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:CanTp_Transmit.008
TEST.VALUE:<<OPTIONS>>.DATA_PARTITIONS:2
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:<<OPTIONS>>.EXPECTED_BEFORE_UUT_CALL:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.SequenceNumber:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.TotalNsduLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.RemainingNsduLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.AvailableBuffer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nas:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nbs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Ncs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:CANTP_STANDARD
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_HALF_DUPLEX
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdEnd:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdEnd:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:100
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:1
TEST.EXPECTED:CanTp.CanTp_Transmit.return:E_OK
TEST.END

-- Test Case: CanTp_Transmit.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:CanTp_Transmit.010
TEST.VALUE:<<OPTIONS>>.DATA_PARTITIONS:2
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:<<OPTIONS>>.EXPECTED_BEFORE_UUT_CALL:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.SequenceNumber:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.TotalNsduLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.RemainingNsduLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.AvailableBuffer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nas:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nbs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Ncs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:CANTP_STANDARD
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_HALF_DUPLEX
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdEnd:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdEnd:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:10
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_FF
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:100
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:6
TEST.EXPECTED:CanTp.CanTp_Transmit.return:E_OK
TEST.END

-- Test Case: CanTp_Transmit.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:CanTp_Transmit.011
TEST.VALUE:<<OPTIONS>>.DATA_PARTITIONS:2
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:<<OPTIONS>>.EXPECTED_BEFORE_UUT_CALL:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.SequenceNumber:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.TotalNsduLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.RemainingNsduLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.AvailableBuffer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nas:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nbs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Ncs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:CANTP_STANDARD
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_FULL_DUPLEX
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdEnd:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdEnd:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:100
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:1
TEST.EXPECTED:CanTp.CanTp_Transmit.return:E_OK
TEST.END

-- Test Case: CanTp_Transmit.012
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:CanTp_Transmit.012
TEST.VALUE:<<OPTIONS>>.DATA_PARTITIONS:2
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:<<OPTIONS>>.EXPECTED_BEFORE_UUT_CALL:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.SequenceNumber:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.TotalNsduLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.RemainingNsduLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.AvailableBuffer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nas:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nbs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Ncs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_FULL_DUPLEX
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdEnd:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdEnd:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:100
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:1
TEST.EXPECTED:CanTp.CanTp_Transmit.return:E_OK
TEST.END

-- Test Case: CanTp_Transmit.013
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_Transmit
TEST.NEW
TEST.NAME:CanTp_Transmit.013
TEST.VALUE:<<OPTIONS>>.DATA_PARTITIONS:2
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:<<OPTIONS>>.EXPECTED_BEFORE_UUT_CALL:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BlockSizeCounter:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinValue:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.SequenceNumber:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.TotalNsduLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.RemainingNsduLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.AvailableBuffer:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.ConnectionState:CANTP_RX_PROCESSING_FRAME
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nas:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Nbs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].Ncs:100
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TransmitCancellation:FALSE
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxPaddingActivation:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].TxTaType:CANTP_PHYSICAL
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].UpperLayerPduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].LowerLayerId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].CanTpRxFlowContorlNSduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].ChannelMode:CANTP_MODE_FULL_DUPLEX
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_RxNSduIdEnd:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdStart:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelConfig[0].CanTp_TxNSduIdEnd:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxSduId:0
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_Transmit.CanTpTxInfoPtr[0].SduLength:1
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:100
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:1
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].RxNsduAddressingFormatType:2
TEST.EXPECTED:CanTp.CanTp_Transmit.return:E_OK
TEST.END

-- Subprogram: CanTp_TxChannelProcessing

-- Test Case: CanTp_TxChannelProcessing.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_TxChannelProcessing.001
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.VALUE:CanTp.CanTp_TxChannelProcessing.ChannelId:CANTP_NUM_OF_CHANNELS
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.END

-- Test Case: CanTp_TxChannelProcessing.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_TxChannelProcessing.002
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:CANTP_NUM_OF_TX_NSDU
TEST.VALUE:CanTp.CanTp_TxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.END

-- Test Case: CanTp_TxChannelProcessing.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_TxChannelProcessing.003
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.END

-- Test Case: CanTp_TxChannelProcessing.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_TxChannelProcessing.004
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_STMIN_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0
TEST.VALUE:CanTp.CanTp_TxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_STMIN_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0
TEST.END

-- Test Case: CanTp_TxChannelProcessing.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_TxChannelProcessing.005
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_STMIN_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:1
TEST.VALUE:CanTp.CanTp_TxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:0
TEST.END

-- Test Case: CanTp_TxChannelProcessing.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_TxChannelProcessing.006
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_STMIN_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:5
TEST.VALUE:CanTp.CanTp_TxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_STMIN_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.StMinTimer:4
TEST.END

-- Test Case: CanTp_TxChannelProcessing.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_TxChannelProcessing.007
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:5
TEST.VALUE:CanTp.CanTp_TxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_FLOW_CONTROL_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:4
TEST.END

-- Test Case: CanTp_TxChannelProcessing.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_TxChannelProcessing.008
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_BUFFER_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:5
TEST.VALUE:CanTp.CanTp_TxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:0
TEST.END

-- Test Case: CanTp_TxChannelProcessing.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_TxChannelProcessing.009
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:1
TEST.VALUE:CanTp.CanTp_TxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:0
TEST.END

-- Test Case: CanTp_TxChannelProcessing.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxChannelProcessing
TEST.NEW
TEST.NAME:CanTp_TxChannelProcessing.010
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:5
TEST.VALUE:CanTp.CanTp_TxChannelProcessing.ChannelId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.ConnectionState:CANTP_TX_PROCESSING_TRANSMIT_CONFIRMATION_WAIT
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.Timer:0
TEST.END

-- Subprogram: CanTp_TxConfirmation

-- Test Case: CanTp_TxConfirmation.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxConfirmation
TEST.NEW
TEST.NAME:CanTp_TxConfirmation.001
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_OFF
TEST.END

-- Test Case: CanTp_TxConfirmation.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxConfirmation
TEST.NEW
TEST.NAME:CanTp_TxConfirmation.002
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.CanTp_TxConfirmation.TxPduId:CANTP_TXNSDU_PDUID_NUM_OF_PDUID
TEST.END

-- Test Case: CanTp_TxConfirmation.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxConfirmation
TEST.NEW
TEST.NAME:CanTp_TxConfirmation.003
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_TX_CONNECTION
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:CANTP_NUM_OF_TX_NSDU
TEST.VALUE:CanTp.CanTp_TxConfirmation.TxPduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_TX_CONNECTION
TEST.END

-- Test Case: CanTp_TxConfirmation.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxConfirmation
TEST.NEW
TEST.NAME:CanTp_TxConfirmation.004
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_TX_CONNECTION
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:CANTP_NUM_OF_CHANNELS
TEST.VALUE:CanTp.CanTp_TxConfirmation.TxPduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_TX_CONNECTION
TEST.END

-- Test Case: CanTp_TxConfirmation.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxConfirmation
TEST.NEW
TEST.NAME:CanTp_TxConfirmation.005
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_TX_CONNECTION
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_TxConfirmation.TxPduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_CONNECTION_NONE
TEST.END

-- Test Case: CanTp_TxConfirmation.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxConfirmation
TEST.NEW
TEST.NAME:CanTp_TxConfirmation.006
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_InternalState:CANTP_ON
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxPduToNsduMap[0]:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].ChannelId:0
TEST.VALUE:CanTp.CanTp_TxConfirmation.TxPduId:0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_CONNECTION_NONE
TEST.END

-- Subprogram: CanTp_TxFrameBufferProcessing

-- Test Case: CanTp_TxFrameBufferProcessing.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.001
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:CANTP_NUM_OF_TX_NSDU
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.002
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:6
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_OK
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.003
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:12
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:7
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_OK
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.004
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:12
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:10
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_OK
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.005
TEST.STUB:CanTp.CanTp_InitTxConnection
TEST.STUB:CanTp.CanTp_TxUpdateAndTransmitPci
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:12
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:0x4097
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:12
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:1
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:0x4097
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:6
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:6
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:0
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.006
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_FF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:6
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_OK
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.007
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:6
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_OK
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.008
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_E_BUSY
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_E_BUSY
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:6
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_OK
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.009
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_E_BUSY
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_E_NOT_OK
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:0
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.010
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.010
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.011
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.011
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.SequenceNumber:0xFF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:12
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:7
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_OK
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.012
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.012
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.SequenceNumber:0xFF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:12
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].RxConnection.DataBufferLength:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:7
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_OK
TEST.END

-- Test Case: CanTp_TxFrameBufferProcessing.013
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxFrameBufferProcessing
TEST.NEW
TEST.NAME:CanTp_TxFrameBufferProcessing.013
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.DataBufferLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].RxConnection.DataBufferLength:0
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr:<<malloc 2>>
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.BufferState:BUFREQ_OK
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_CF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.SequenceNumber:0xFF
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.TotalNsduLength:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.RemainingNsduLength:12
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[0]:1
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[1]:2
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[2]:3
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[3]:4
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[4]:5
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[5]:6
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBuffer[6]:7
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].RxConnection.DataBufferLength:0
TEST.VALUE:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[1].TxConnection.DataBufferLength:0
TEST.VALUE:uut_prototype_stubs.PduR_CanTpCopyTxData.return:BUFREQ_OK
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.ChannelStatePtr[0].TxConnection.DataBufferLength:7
TEST.EXPECTED:CanTp.CanTp_TxFrameBufferProcessing.return:E_OK
TEST.END

-- Subprogram: CanTp_TxUpdateAndTransmitPci

-- Test Case: CanTp_TxUpdateAndTransmitPci.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxUpdateAndTransmitPci
TEST.NEW
TEST.NAME:CanTp_TxUpdateAndTransmitPci.001
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:8
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanTp.CanTp_TxUpdateAndTransmitPci.return:E_OK
TEST.END

-- Test Case: CanTp_TxUpdateAndTransmitPci.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxUpdateAndTransmitPci
TEST.NEW
TEST.NAME:CanTp_TxUpdateAndTransmitPci.002
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:10
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanTp.CanTp_TxUpdateAndTransmitPci.return:E_OK
TEST.END

-- Test Case: CanTp_TxUpdateAndTransmitPci.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxUpdateAndTransmitPci
TEST.NEW
TEST.NAME:CanTp_TxUpdateAndTransmitPci.003
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_INVALID
TEST.EXPECTED:CanTp.CanTp_TxUpdateAndTransmitPci.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_TxUpdateAndTransmitPci.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxUpdateAndTransmitPci
TEST.NEW
TEST.NAME:CanTp_TxUpdateAndTransmitPci.004
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.NsduId:CANTP_NUM_OF_TX_NSDU
TEST.EXPECTED:CanTp.CanTp_TxUpdateAndTransmitPci.return:E_NOT_OK
TEST.END

-- Test Case: CanTp_TxUpdateAndTransmitPci.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxUpdateAndTransmitPci
TEST.NEW
TEST.NAME:CanTp_TxUpdateAndTransmitPci.005
TEST.STUB:CanTp.CanTp_CanIfTransmitData
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:10
TEST.VALUE:CanTp.CanTp_CanIfTransmitData.return:1
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.FramePciType:CANTP_PCI_TYPE_SF
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTp_TxUpdateAndTransmitPci.006
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxUpdateAndTransmitPci
TEST.NEW
TEST.NAME:CanTp_TxUpdateAndTransmitPci.006
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.FramePciType:0x2
TEST.EXPECTED:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.EXPECTED:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.FramePciType:2
TEST.EXPECTED:CanTp.CanTp_TxUpdateAndTransmitPci.return:0
TEST.END

-- Test Case: CanTp_TxUpdateAndTransmitPci.007
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxUpdateAndTransmitPci
TEST.NEW
TEST.NAME:CanTp_TxUpdateAndTransmitPci.007
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:10
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.FramePciType:0x1
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanTp.CanTp_TxUpdateAndTransmitPci.return:E_OK
TEST.END

-- Test Case: CanTp_TxUpdateAndTransmitPci.008
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxUpdateAndTransmitPci
TEST.NEW
TEST.NAME:CanTp_TxUpdateAndTransmitPci.008
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.TotalNsduLength:4096
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:10
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.FramePciType:0x1
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:0x9
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.TotalNsduLength:4096
TEST.EXPECTED:CanTp.CanTp_TxUpdateAndTransmitPci.return:E_OK
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:0x9
TEST.END

-- Test Case: CanTp_TxUpdateAndTransmitPci.009
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_TxUpdateAndTransmitPci
TEST.NEW
TEST.NAME:CanTp_TxUpdateAndTransmitPci.009
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.TotalNsduLength:4096
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:0x9
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.NsduId:0
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.FramePciType:0x1
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxConnection.TotalNsduLength:4096
TEST.VALUE:CanTp.CanTp_TxUpdateAndTransmitPci.ChannelStatePtr[0].TxRequestType:CANTP_TRANSMIT_BY_RX_CONNECTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:0x9
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_ChannelState[0].TxConnection.TotalNsduLength:4096
TEST.ATTRIBUTES:uut_prototype_stubs.<<GLOBAL>>.CanTp_TxNSduConfig.CanTp_TxNSduConfig[0].MaxLowerLayerDataLength:EXPECTED_BASE=16
TEST.END

-- Subprogram: CanTp_UtilGetBlockSizeInBytes

-- Test Case: CanTp_UtilGetBlockSizeInBytes.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilGetBlockSizeInBytes
TEST.NEW
TEST.NAME:CanTp_UtilGetBlockSizeInBytes.001
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].NsduId:CANTP_NUM_OF_RX_NSDU
TEST.EXPECTED:CanTp.CanTp_UtilGetBlockSizeInBytes.return:0
TEST.END

-- Test Case: CanTp_UtilGetBlockSizeInBytes.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilGetBlockSizeInBytes
TEST.NEW
TEST.NAME:CanTp_UtilGetBlockSizeInBytes.002
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].NsduId:0x0
TEST.EXPECTED:CanTp.CanTp_UtilGetBlockSizeInBytes.return:0
TEST.END

-- Test Case: CanTp_UtilGetBlockSizeInBytes.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilGetBlockSizeInBytes
TEST.NEW
TEST.NAME:CanTp_UtilGetBlockSizeInBytes.003
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:0x1
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].NsduId:0x0
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:0x1
TEST.EXPECTED:CanTp.CanTp_UtilGetBlockSizeInBytes.return:0
TEST.END

-- Test Case: CanTp_UtilGetBlockSizeInBytes.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilGetBlockSizeInBytes
TEST.NEW
TEST.NAME:CanTp_UtilGetBlockSizeInBytes.004
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:0x1
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].NsduId:0x0
TEST.VALUE:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].FirstFrameDataLength:0xFFFF
TEST.EXPECTED:CanTp.<<GLOBAL>>.CanTp_RxNSduConfig[0].BlockSize:0x1
TEST.EXPECTED:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].NsduId:0
TEST.EXPECTED:CanTp.CanTp_UtilGetBlockSizeInBytes.RxConnectionPtr[0].FirstFrameDataLength:65535
TEST.EXPECTED:CanTp.CanTp_UtilGetBlockSizeInBytes.return:65534
TEST.END

-- Subprogram: CanTp_UtilGetPaddingLength

-- Test Case: CanTp_UtilGetPaddingLength.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilGetPaddingLength
TEST.NEW
TEST.NAME:CanTp_UtilGetPaddingLength.001
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MinDataLength:1
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].MaxDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[0].PaddedDataLength:8
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MinDataLength:9
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].MaxDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[1].PaddedDataLength:12
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MinDataLength:13
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].MaxDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[2].PaddedDataLength:16
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MinDataLength:17
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].MaxDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[3].PaddedDataLength:20
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MinDataLength:21
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].MaxDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[4].PaddedDataLength:24
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MinDataLength:25
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].MaxDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[5].PaddedDataLength:32
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MinDataLength:33
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].MaxDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[6].PaddedDataLength:48
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MinDataLength:49
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].MaxDataLength:64
TEST.VALUE:CanTp.<<GLOBAL>>.CanTp_PaddedDataLengthRange[7].PaddedDataLength:64
TEST.VALUE:CanTp.CanTp_UtilGetPaddingLength.Length:0
TEST.EXPECTED:CanTp.CanTp_UtilGetPaddingLength.return:0
TEST.END

-- Subprogram: CanTp_UtilGetTimeInCyclicPeriod

-- Test Case: CanTp_UtilGetTimeInCyclicPeriod.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilGetTimeInCyclicPeriod
TEST.NEW
TEST.NAME:CanTp_UtilGetTimeInCyclicPeriod.001
TEST.VALUE:CanTp.CanTp_UtilGetTimeInCyclicPeriod.StMinValue:0x10
TEST.EXPECTED:CanTp.CanTp_UtilGetTimeInCyclicPeriod.StMinValue:0x10
TEST.END

-- Test Case: CanTp_UtilGetTimeInCyclicPeriod.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilGetTimeInCyclicPeriod
TEST.NEW
TEST.NAME:CanTp_UtilGetTimeInCyclicPeriod.002
TEST.VALUE:CanTp.CanTp_UtilGetTimeInCyclicPeriod.StMinValue:0x0
TEST.EXPECTED:CanTp.CanTp_UtilGetTimeInCyclicPeriod.StMinValue:0x0
TEST.END

-- Test Case: CanTp_UtilGetTimeInCyclicPeriod.003
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilGetTimeInCyclicPeriod
TEST.NEW
TEST.NAME:CanTp_UtilGetTimeInCyclicPeriod.003
TEST.VALUE:CanTp.CanTp_UtilGetTimeInCyclicPeriod.StMinValue:0x5
TEST.EXPECTED:CanTp.CanTp_UtilGetTimeInCyclicPeriod.StMinValue:0x5
TEST.END

-- Test Case: CanTp_UtilGetTimeInCyclicPeriod.004
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilGetTimeInCyclicPeriod
TEST.NEW
TEST.NAME:CanTp_UtilGetTimeInCyclicPeriod.004
TEST.VALUE:CanTp.CanTp_UtilGetTimeInCyclicPeriod.StMinValue:0x5
TEST.EXPECTED:CanTp.CanTp_UtilGetTimeInCyclicPeriod.StMinValue:0x5
TEST.END

-- Test Case: CanTp_UtilGetTimeInCyclicPeriod.005
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilGetTimeInCyclicPeriod
TEST.NEW
TEST.NAME:CanTp_UtilGetTimeInCyclicPeriod.005
TEST.VALUE:CanTp.CanTp_UtilGetTimeInCyclicPeriod.StMinValue:0x1
TEST.EXPECTED:CanTp.CanTp_UtilGetTimeInCyclicPeriod.StMinValue:0x1
TEST.END

-- Subprogram: CanTp_UtilMemCpy

-- Test Case: CanTp_UtilMemCpy.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilMemCpy
TEST.NEW
TEST.NAME:CanTp_UtilMemCpy.001
TEST.END

-- Test Case: CanTp_UtilMemCpy.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilMemCpy
TEST.NEW
TEST.NAME:CanTp_UtilMemCpy.002
TEST.VALUE:CanTp.CanTp_UtilMemCpy.DestPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_UtilMemCpy.SrcPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_UtilMemCpy.Length:0x1
TEST.EXPECTED:CanTp.CanTp_UtilMemCpy.Length:0x1
TEST.END

-- Subprogram: CanTp_UtilMemSet

-- Test Case: CanTp_UtilMemSet.001
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilMemSet
TEST.NEW
TEST.NAME:CanTp_UtilMemSet.001
TEST.END

-- Test Case: CanTp_UtilMemSet.002
TEST.UNIT:CanTp
TEST.SUBPROGRAM:CanTp_UtilMemSet
TEST.NEW
TEST.NAME:CanTp_UtilMemSet.002
TEST.VALUE:CanTp.CanTp_UtilMemSet.DestPtr:<<malloc 1>>
TEST.VALUE:CanTp.CanTp_UtilMemSet.Length:0x1
TEST.EXPECTED:CanTp.CanTp_UtilMemSet.Length:0x1
TEST.END
