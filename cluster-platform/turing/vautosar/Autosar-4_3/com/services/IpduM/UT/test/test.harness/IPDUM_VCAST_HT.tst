-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : IPDUM_VCAST_HT
-- Unit(s) Under Test: IpduM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: IpduM

-- Subprogram: IpduM_CopySegmentstoTxBuffer

-- Test Case: IpduM_CopySegmentstoTxBuffer.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_CopySegmentstoTxBuffer
TEST.NEW
TEST.NAME:IpduM_CopySegmentstoTxBuffer.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PdumTxPduId:IPDUM_PDU_TX_NUM_OF_PARTS
TEST.EXPECTED:IpduM.IpduM_CopySegmentstoTxBuffer.PdumTxPduId:IPDUM_PDU_TX_NUM_OF_PARTS
TEST.END

-- Test Case: IpduM_CopySegmentstoTxBuffer.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_CopySegmentstoTxBuffer
TEST.NEW
TEST.NAME:IpduM_CopySegmentstoTxBuffer.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].TxIpduId:IPDUM_NUM_OF_TX_MESSAGE
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PdumTxPduId:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].TxIpduId:IPDUM_NUM_OF_TX_MESSAGE
TEST.END

-- Test Case: IpduM_CopySegmentstoTxBuffer.003
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_CopySegmentstoTxBuffer
TEST.NEW
TEST.NAME:IpduM_CopySegmentstoTxBuffer.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].SegmentStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].SegmentEndIdx:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].TxIpduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentMsByteIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentLsByteIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentMsByteIdx:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentLsByteIdx:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentMsByteIdx:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentLsByteIdx:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferSize:4
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PdumTxPduId:0
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr:<<malloc 4>>
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduLength:4
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[1]:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[2]:3
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[3]:4
TEST.END

-- Test Case: IpduM_CopySegmentstoTxBuffer.004
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_CopySegmentstoTxBuffer
TEST.NEW
TEST.NAME:IpduM_CopySegmentstoTxBuffer.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].SegmentStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].SegmentEndIdx:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].TxIpduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentMsByteIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentLsByteIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentMsByteIdx:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentLsByteIdx:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentMsByteIdx:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentLsByteIdx:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferSize:4
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PdumTxPduId:0
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr:<<malloc 4>>
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduLength:4
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[1]:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[2]:3
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[3]:4
TEST.END

-- Test Case: IpduM_CopySegmentstoTxBuffer.005
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_CopySegmentstoTxBuffer
TEST.NEW
TEST.NAME:IpduM_CopySegmentstoTxBuffer.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBuffer[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBuffer[1]:6
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBuffer[2]:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBuffer[3]:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].SegmentStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].SegmentEndIdx:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].TxIpduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentMsByteIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentLsByteIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentMsByteIdx:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentLsByteIdx:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentMsByteIdx:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentLsByteIdx:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferStartIdx:IPDUM_TX_BUFFER_SIZE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferSize:4
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PdumTxPduId:0
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr:<<malloc 4>>
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduLength:4
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[0]:5
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[1]:6
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[2]:7
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[3]:8
TEST.END

-- Test Case: IpduM_CopySegmentstoTxBuffer.006
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_CopySegmentstoTxBuffer
TEST.NEW
TEST.NAME:IpduM_CopySegmentstoTxBuffer.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBuffer[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBuffer[1]:6
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBuffer[2]:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBuffer[3]:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].SegmentStartIdx:IPDUM_NUM_OF_TX_SEGMENTS
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].SegmentEndIdx:IPDUM_NUM_OF_TX_SEGMENTS
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[0].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentMsByteIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentLsByteIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[1].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentMsByteIdx:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentLsByteIdx:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[2].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentMsByteIdx:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentLsByteIdx:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxSegmentConfig[3].SegmentByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferStartIdx:IPDUM_TX_BUFFER_SIZE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferSize:4
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PdumTxPduId:0
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr:<<malloc 4>>
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:IpduM.IpduM_CopySegmentstoTxBuffer.PduInfoPtr[0].SduLength:4
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[0]:5
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[1]:6
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[2]:7
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBuffer[3]:8
TEST.END

-- Subprogram: IpduM_GetVersionInfo

-- Test Case: IpduM_GetVersionInfo.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_GetVersionInfo
TEST.NEW
TEST.NAME:IpduM_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_GetVersionInfo.VersionInfo:<<malloc 1>>
TEST.END

-- Test Case: IpduM_GetVersionInfo.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_GetVersionInfo
TEST.NEW
TEST.NAME:IpduM_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_GetVersionInfo.VersionInfo:<<null>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_GETVERSIONINFO_API
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_PARAM_POINTER
TEST.EXPECTED:IpduM.IpduM_GetVersionInfo.VersionInfo:<<null>>
TEST.END

-- Subprogram: IpduM_Init

-- Test Case: IpduM_Init.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Init
TEST.NEW
TEST.NAME:IpduM_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:FALSE
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.END

-- Test Case: IpduM_Init.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Init
TEST.NEW
TEST.NAME:IpduM_Init.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_INIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_ALREADY_INITIALIZED
TEST.END

-- Subprogram: IpduM_MainFunction

-- Test Case: IpduM_MainFunction.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_MainFunction
TEST.NEW
TEST.NAME:IpduM_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduProcessPendingSts[0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:5
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:4
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:4
TEST.END

-- Test Case: IpduM_MainFunction.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_MainFunction
TEST.NEW
TEST.NAME:IpduM_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:FALSE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:5
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_UNINIT
TEST.END

-- Test Case: IpduM_MainFunction.003
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_MainFunction
TEST.NEW
TEST.NAME:IpduM_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduProcessPendingSts[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:5
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:4
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:4
TEST.END

-- Test Case: IpduM_MainFunction.004
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_MainFunction
TEST.NEW
TEST.NAME:IpduM_MainFunction.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduProcessPendingSts[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:5
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:4
TEST.END

-- Subprogram: IpduM_ProcessContainerTxPdu

-- Test Case: IpduM_ProcessContainerTxPdu.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:5
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:IPDUM_MAX_CONTAINER_BUFFER
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.003
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:IPDUM_MAX_CONTAINER_QUEUE_SIZE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.004
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduTrigger:IPDUM_TRIGGER_NEVER
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduHeaderId:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxTriggerModeType:IPDUM_TX_TRIGGER_MODE_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerHeaderSize:IPDUM_HEADER_SIZE_TYPE_LONG
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:10
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][1]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][2]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][3]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][4]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][5]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][6]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][7]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][8]:7
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][9]:8
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.005
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduTrigger:IPDUM_TRIGGER_NEVER
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduHeaderId:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxTriggerModeType:IPDUM_TX_TRIGGER_MODE_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerHeaderSize:IPDUM_HEADER_SIZE_TYPE_SHORT
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:6
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][1]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][2]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][3]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][4]:7
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][5]:8
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][6]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][7]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][8]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][9]:0
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.006
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduTrigger:IPDUM_TRIGGER_NEVER
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduHeaderId:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxTriggerModeType:IPDUM_TX_TRIGGER_MODE_TYPE_DIRECT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerHeaderSize:IPDUM_HEADER_SIZE_TYPE_SHORT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxSizeThreshold:10
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:6
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][1]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][2]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][3]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][4]:7
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][5]:8
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][6]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][7]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][8]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][9]:0
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.007
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduTrigger:IPDUM_TRIGGER_NEVER
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduHeaderId:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxTriggerModeType:IPDUM_TX_TRIGGER_MODE_TYPE_DIRECT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerHeaderSize:IPDUM_HEADER_SIZE_TYPE_SHORT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].LowerLayerTransmitId:4
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxSizeThreshold:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduLength:2
TEST.VALUE:uut_prototype_stubs.PduR_IpduMTransmit.Info[0].SduDataPtr:<<malloc 6>>
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][1]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][2]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][3]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][4]:7
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][5]:8
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][6]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][7]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][8]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][9]:0
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMTransmit.Id:4
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMTransmit.Info[0].SduDataPtr[0]:1
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMTransmit.Info[0].SduDataPtr[1]:0
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMTransmit.Info[0].SduDataPtr[2]:0
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMTransmit.Info[0].SduDataPtr[3]:0
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMTransmit.Info[0].SduDataPtr[4]:7
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMTransmit.Info[0].SduDataPtr[5]:8
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMTransmit.Info[0].SduLength:6
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.008
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduTrigger:IPDUM_TRIGGER_ALWAYS
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduHeaderId:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxTriggerModeType:IPDUM_TX_TRIGGER_MODE_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerHeaderSize:IPDUM_HEADER_SIZE_TYPE_SHORT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].LowerLayerTransmitId:4
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxSizeThreshold:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][1]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][2]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][3]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][4]:7
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][5]:8
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][6]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][7]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][8]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][9]:0
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMTransmit.Id:4
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.009
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:5
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.010
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduTrigger:IPDUM_TRIGGER_ALWAYS
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduHeaderId:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxTriggerModeType:IPDUM_TX_TRIGGER_MODE_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerHeaderSize:IPDUM_HEADER_SIZE_TYPE_SHORT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].LowerLayerTransmitId:4
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxSizeThreshold:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduLength:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][1]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][2]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][3]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][6]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][7]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][8]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][9]:0
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.011
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:65
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduTrigger:IPDUM_TRIGGER_NEVER
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduHeaderId:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxTriggerModeType:IPDUM_TX_TRIGGER_MODE_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerHeaderSize:IPDUM_HEADER_SIZE_TYPE_LONG
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][1]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][2]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][3]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][4]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][5]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][6]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][7]:0
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.012
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:65
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduTrigger:IPDUM_TRIGGER_ALWAYS
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduHeaderId:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxTriggerModeType:IPDUM_TX_TRIGGER_MODE_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerHeaderSize:IPDUM_HEADER_SIZE_TYPE_SHORT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].LowerLayerTransmitId:4
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxSizeThreshold:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][1]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][2]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][3]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][6]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][7]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][8]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][9]:0
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMTransmit.Id:4
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.013
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:65
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduTrigger:IPDUM_TRIGGER_ALWAYS
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxPduHeaderId:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxTriggerModeType:IPDUM_TX_TRIGGER_MODE_TYPE_TRIGGER_TRANSMIT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerHeaderSize:IPDUM_HEADER_SIZE_TYPE_SHORT
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].LowerLayerTransmitId:4
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainerTxSizeThreshold:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.PduInfoPtr[0].SduLength:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxQueueIndex[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBufferConfig[0][0].IpduTxMBufferIndex:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][1]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][2]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][3]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][6]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][7]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][8]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxBuffer[0][9]:0
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMTransmit.Id:4
TEST.END

-- Test Case: IpduM_ProcessContainerTxPdu.014
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessContainerTxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessContainerTxPdu.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedTxPduConfig[0].TxInContainerPduId:0
TEST.VALUE:IpduM.IpduM_ProcessContainerTxPdu.DestIpduMId:19
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:5
TEST.END

-- Subprogram: IpduM_ProcessDeferredContainerRxPdu

-- Test Case: IpduM_ProcessDeferredContainerRxPdu.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessDeferredContainerRxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessDeferredContainerRxPdu.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxQueueIndex[0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxBufferConfig[0][0].IpduMSduLength:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxBufferConfig[0][0].IpduMBufferIndex:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxBuffer[0][1]:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxBuffer[0][2]:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduConfig[0].ContainedIpduStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduConfig[0].ContainedIpduEndIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedRxPduConfig[0].UpperLayerNotifyPduId:5
TEST.VALUE:IpduM.IpduM_ProcessDeferredContainerRxPdu.PduId:0
TEST.EXPECTED:uut_prototype_stubs.PduR_IpduMRxIndication.Id:5
TEST.END

-- Test Case: IpduM_ProcessDeferredContainerRxPdu.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessDeferredContainerRxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessDeferredContainerRxPdu.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_ProcessDeferredContainerRxPdu.PduId:4
TEST.END

-- Subprogram: IpduM_ProcessImmediateContainerRxPdu

-- Test Case: IpduM_ProcessImmediateContainerRxPdu.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessImmediateContainerRxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessImmediateContainerRxPdu.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduConfig[0].ContainedIpduStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduConfig[0].ContainedIpduEndIdx:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedRxPduConfig[0].UpperLayerNotifyPduId:5
TEST.VALUE:IpduM.IpduM_ProcessImmediateContainerRxPdu.PduId:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_ProcessImmediateContainerRxPdu.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_ProcessImmediateContainerRxPdu
TEST.NEW
TEST.NAME:IpduM_ProcessImmediateContainerRxPdu.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduConfig[0].ContainedIpduStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduConfig[0].ContainedIpduEndIdx:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainedRxPduConfig[0].UpperLayerNotifyPduId:5
TEST.VALUE:IpduM.IpduM_ProcessImmediateContainerRxPdu.PduId:4
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: IpduM_RxIndication

-- Test Case: IpduM_RxIndication.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_RxIndication.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_RxIndication.003
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxBufferConfig[0].BufferStartIdx:10
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxBufferConfig[0].BufferEndIdx:12
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_RxIndication.004
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_RxIndication.005
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:FALSE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_UNINIT
TEST.END

-- Test Case: IpduM_RxIndication.006
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:255
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_PARAM
TEST.END

-- Test Case: IpduM_RxIndication.007
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_PARAM_POINTER
TEST.END

-- Test Case: IpduM_RxIndication.008
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].IsStaticPartExist:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].StaticPartUpperPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_RxIndication.009
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 9>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_PARAM_POINTER
TEST.END

-- Test Case: IpduM_RxIndication.010
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxBufferConfig[0].BufferStartIdx:IPDUM_RX_BUFFER_SIZE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_RxIndication.011
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxBufferConfig[0].BufferSize:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].SelectorFieldValue:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].SelectorFieldValue:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[2].SelectorFieldValue:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[3].SelectorFieldValue:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[4].SelectorFieldValue:4
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[5].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[6].SelectorFieldValue:6
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[7].SelectorFieldValue:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[8].SelectorFieldValue:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:IPDUM_NUM_OF_RX_DYNAMIC_PARTS
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr[0]:25
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_RxIndication.012
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduConfig[0].ContainerPduProcessingType:IPDUM_PROCESSING_DEFERRED
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduMapConfig[0].DestIpduMId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduMapConfig[0].IpduMPduIdType:IPDUM_ID_TYPE_CONTAINER
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_RxIndication.013
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduConfig[0].ContainerPduProcessingType:IPDUM_PROCESSING_IMMEDIATE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduMapConfig[0].DestIpduMId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduMapConfig[0].IpduMPduIdType:IPDUM_ID_TYPE_CONTAINER
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_RxIndication.014
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxBufferConfig[0].BufferSize:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].SelectorFieldValue:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].SelectorFieldValue:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[2].SelectorFieldValue:2
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[3].SelectorFieldValue:3
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[4].SelectorFieldValue:4
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[5].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[6].SelectorFieldValue:6
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[7].SelectorFieldValue:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[8].SelectorFieldValue:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:IPDUM_NUM_OF_RX_DYNAMIC_PARTS
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr[0]:25
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_RxPduMapConfig[0].DestIpduMId:5
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_RxIndication.015
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_RxIndication
TEST.NEW
TEST.NAME:IpduM_RxIndication.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[0].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].SelectorFieldValue:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxDynPartConfig[1].DynPartUpperPduId:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldMsBitIdx:7
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsByteIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldLsBitIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldBitLength:8
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].SelectorFieldByteLength:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].ByteOrder:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduConfig[0].RxDynPartEndIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxPduConfig[0].ContainerPduProcessingType:IPDUM_PROCESSING_IMMEDIATE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduMapConfig[0].DestIpduMId:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_RxPduMapConfig[0].IpduMPduIdType:IPDUM_ID_TYPE_CONTAINER
TEST.VALUE:IpduM.IpduM_RxIndication.RxPduId:0
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: IpduM_StoreToContainerBuffer

-- Test Case: IpduM_StoreToContainerBuffer.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_StoreToContainerBuffer
TEST.NEW
TEST.NAME:IpduM_StoreToContainerBuffer.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxBufferConfig[0][0].IpduMBufferIndex:1
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduId:0
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxQueueIndex[0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxBufferConfig[0][0].IpduMPduId:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxBufferConfig[0][0].IpduMSduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxBufferConfig[0][0].IpduMBufferIndex:3
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxBuffer[0][1]:7
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxBuffer[0][2]:8
TEST.END

-- Test Case: IpduM_StoreToContainerBuffer.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_StoreToContainerBuffer
TEST.NEW
TEST.NAME:IpduM_StoreToContainerBuffer.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxQueueIndex[0]:IPDUM_MAX_CONTAINER_QUEUE_SIZE
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduId:0
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxQueueIndex[0]:IPDUM_MAX_CONTAINER_QUEUE_SIZE
TEST.END

-- Test Case: IpduM_StoreToContainerBuffer.003
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_StoreToContainerBuffer
TEST.NEW
TEST.NAME:IpduM_StoreToContainerBuffer.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxBufferConfig[0][0].IpduMBufferIndex:IPDUM_MAX_CONTAINER_BUFFER
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduId:0
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxQueueIndex[0]:0
TEST.END

-- Test Case: IpduM_StoreToContainerBuffer.004
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_StoreToContainerBuffer
TEST.NEW
TEST.NAME:IpduM_StoreToContainerBuffer.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxBufferConfig[0][0].IpduMBufferIndex:IPDUM_MAX_CONTAINER_BUFFER
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduId:2
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxQueueIndex[0]:0
TEST.END

-- Test Case: IpduM_StoreToContainerBuffer.005
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_StoreToContainerBuffer
TEST.NEW
TEST.NAME:IpduM_StoreToContainerBuffer.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxQueueIndex[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerRxBufferConfig[0][0].IpduMBufferIndex:65
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduId:0
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr[0]:7
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduDataPtr[1]:8
TEST.VALUE:IpduM.IpduM_StoreToContainerBuffer.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxQueueIndex[0]:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxBufferConfig[0][0].IpduMPduId:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerRxBufferConfig[0][0].IpduMSduLength:2
TEST.END

-- Subprogram: IpduM_Transmit

-- Test Case: IpduM_Transmit.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.003
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.IpduM_Transmit.PdumTxPduId:37
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.004
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.005
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.006
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduMapConfig[0].IpduMPduIdType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.007
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduMapConfig[0].DestIpduMId:37
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.008
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPartConfig[0].TxIpduId:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.009
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.010
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.011
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.012
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].IsStaticPartExist:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.013
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].PartType:1
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].IsStaticPartExist:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.014
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.014
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].PartType:0
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].IsStaticPartExist:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.015
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.015
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].StaticPartPduRef:37
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].PartType:1
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].IsStaticPartExist:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].StaticPartPduRef:37
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.016
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.016
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].StaticPartPduRef:37
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].PartType:1
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].IsStaticPartExist:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].StaticPartPduRef:37
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferStartIdx:57
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.017
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.017
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].StaticPartPduRef:37
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].PartType:1
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxTriggerMode:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].IsStaticPartExist:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].StaticPartPduRef:37
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferStartIdx:57
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.018
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.018
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].StaticPartPduRef:37
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].PartType:0
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxTriggerMode:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].IsStaticPartExist:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].StaticPartPduRef:37
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferStartIdx:57
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.019
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.019
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].PartType:0
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].IsStaticPartExist:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.020
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.020
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].PartType:0
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxTriggerMode:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].IsStaticPartExist:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.021
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.021
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].PartType:0
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxTriggerMode:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].IsStaticPartExist:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_Transmit.022
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.022
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.IpduM_Transmit.PdumTxPduId:0x43
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:IpduM.IpduM_Transmit.PdumTxPduId:0x43
TEST.END

-- Test Case: IpduM_Transmit.023
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.023
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduMapConfig[0].DestIpduMId:43
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduMapConfig[0].DestIpduMId:43
TEST.END

-- Test Case: IpduM_Transmit.024
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.024
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferStartIdx:65
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxBufferConfig[0].BufferStartIdx:65
TEST.END

-- Test Case: IpduM_Transmit.025
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_Transmit
TEST.NEW
TEST.NAME:IpduM_Transmit.025
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_PduInfo.SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].StaticPartPduRef:0x43
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsJitUpdateSupported:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].IsTxConfirmationEnabled:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPartConfig[0].PartType:1
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:IpduM.IpduM_Transmit.PduInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].TxConfirmationTimeout:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.IpduM_TxPduConfig[0].IsStaticPartExist:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_TxPduConfig[0].StaticPartPduRef:0x43
TEST.END

-- Subprogram: IpduM_TriggerTransmit

-- Test Case: IpduM_TriggerTransmit.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TriggerTransmit
TEST.NEW
TEST.NAME:IpduM_TriggerTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.IpduM_TriggerTransmit.TxPduId:0
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:IpduM.IpduM_TriggerTransmit.return:E_OK
TEST.END

-- Test Case: IpduM_TriggerTransmit.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TriggerTransmit
TEST.NEW
TEST.NAME:IpduM_TriggerTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:FALSE
TEST.VALUE:IpduM.IpduM_TriggerTransmit.TxPduId:0
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:IpduM.IpduM_TriggerTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_TRIGGERTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_UNINIT
TEST.END

-- Test Case: IpduM_TriggerTransmit.003
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TriggerTransmit
TEST.NEW
TEST.NAME:IpduM_TriggerTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.IpduM_TriggerTransmit.TxPduId:255
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:IpduM.IpduM_TriggerTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_TRIGGERTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_PARAM
TEST.END

-- Test Case: IpduM_TriggerTransmit.004
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TriggerTransmit
TEST.NEW
TEST.NAME:IpduM_TriggerTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.IpduM_TriggerTransmit.TxPduId:0
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr:<<null>>
TEST.EXPECTED:IpduM.IpduM_TriggerTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_TRIGGERTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_PARAM_POINTER
TEST.END

-- Test Case: IpduM_TriggerTransmit.005
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TriggerTransmit
TEST.NEW
TEST.NAME:IpduM_TriggerTransmit.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.IpduM_TriggerTransmit.TxPduId:0
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<malloc 9>>
TEST.VALUE:IpduM.IpduM_TriggerTransmit.PduInfoPtr[0].SduDataPtr:<<null>>
TEST.EXPECTED:IpduM.IpduM_TriggerTransmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_TRIGGERTRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_PARAM_POINTER
TEST.END

-- Subprogram: IpduM_TxConfirmation

-- Test Case: IpduM_TxConfirmation.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TxConfirmation
TEST.NEW
TEST.NAME:IpduM_TxConfirmation.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMLastTransmitTxPart[0]:0
TEST.VALUE:IpduM.IpduM_TxConfirmation.TxPduId:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.END

-- Test Case: IpduM_TxConfirmation.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TxConfirmation
TEST.NEW
TEST.NAME:IpduM_TxConfirmation.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMLastTransmitTxPart[0]:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.END

-- Test Case: IpduM_TxConfirmation.003
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TxConfirmation
TEST.NEW
TEST.NAME:IpduM_TxConfirmation.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMLastTransmitTxPart[0]:IPDUM_PDU_TX_NUM_OF_PARTS
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.END

-- Test Case: IpduM_TxConfirmation.004
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TxConfirmation
TEST.NEW
TEST.NAME:IpduM_TxConfirmation.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:FALSE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMLastTransmitTxPart[0]:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_TXCONFIRMATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_UNINIT
TEST.END

-- Test Case: IpduM_TxConfirmation.005
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TxConfirmation
TEST.NEW
TEST.NAME:IpduM_TxConfirmation.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMTxConfirmationTimeoutVal[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduMLastTransmitTxPart[0]:0
TEST.VALUE:IpduM.IpduM_TxConfirmation.TxPduId:255
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:IPDUM_TXCONFIRMATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:IPDUM_E_PARAM
TEST.END

-- Test Case: IpduM_TxConfirmation.006
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TxConfirmation
TEST.NEW
TEST.NAME:IpduM_TxConfirmation.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduMapConfig[0].IpduMPduIdType:IPDUM_ID_TYPE_CONTAINER
TEST.VALUE:IpduM.IpduM_TxConfirmation.TxPduId:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.END

-- Test Case: IpduM_TxConfirmation.007
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_TxConfirmation
TEST.NEW
TEST.NAME:IpduM_TxConfirmation.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_InitStatus:TRUE
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:5
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainedIpduStartIdx:0
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_ContainerTxPduConfig[0].ContainedIpduEndIdx:1
TEST.VALUE:IpduM.<<GLOBAL>>.IpduM_TxPduMapConfig[0].IpduMPduIdType:IPDUM_ID_TYPE_CONTAINER
TEST.VALUE:IpduM.IpduM_TxConfirmation.TxPduId:0
TEST.EXPECTED:IpduM.<<GLOBAL>>.IpduM_ContainerTxConfirmationTimeout[0]:0
TEST.END

-- Subprogram: IpduM_UtilBitCopy

-- Test Case: IpduM_UtilBitCopy.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilBitCopy
TEST.NEW
TEST.NAME:IpduM_UtilBitCopy.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr[0]:5
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:0
TEST.EXPECTED:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:0
TEST.END

-- Test Case: IpduM_UtilBitCopy.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilBitCopy
TEST.NEW
TEST.NAME:IpduM_UtilBitCopy.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsByte:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr[0]:5
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:0
TEST.EXPECTED:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:0
TEST.END

-- Test Case: IpduM_UtilBitCopy.003
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilBitCopy
TEST.NEW
TEST.NAME:IpduM_UtilBitCopy.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr[0]:7
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:0
TEST.EXPECTED:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:1
TEST.END

-- Test Case: IpduM_UtilBitCopy.004
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilBitCopy
TEST.NEW
TEST.NAME:IpduM_UtilBitCopy.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr[0]:7
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:0
TEST.EXPECTED:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:2
TEST.END

-- Test Case: IpduM_UtilBitCopy.005
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilBitCopy
TEST.NEW
TEST.NAME:IpduM_UtilBitCopy.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr[0]:7
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:2
TEST.END

-- Test Case: IpduM_UtilBitCopy.006
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilBitCopy
TEST.NEW
TEST.NAME:IpduM_UtilBitCopy.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcBufferEndianess:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestBufferEndianess:IPDUM_LITTLE_ENDIAN
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr[0]:7
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:0
TEST.EXPECTED:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:2
TEST.END

-- Test Case: IpduM_UtilBitCopy.007
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilBitCopy
TEST.NEW
TEST.NAME:IpduM_UtilBitCopy.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr[0]:7
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:0
TEST.EXPECTED:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:1
TEST.END

-- Test Case: IpduM_UtilBitCopy.008
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilBitCopy
TEST.NEW
TEST.NAME:IpduM_UtilBitCopy.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:9
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr[0]:7
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_UtilBitCopy.009
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilBitCopy
TEST.NEW
TEST.NAME:IpduM_UtilBitCopy.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:9
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr[0]:7
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: IpduM_UtilBitCopy.010
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilBitCopy
TEST.NEW
TEST.NAME:IpduM_UtilBitCopy.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsBit:7
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SrcLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsBit:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].DestLsByte:0
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxSrcBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].MaxDestBufferSize:1
TEST.VALUE:IpduM.IpduM_UtilBitCopy.UtilBitCopyPropsPtr[0].SignalLengthInBits:5
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.SrcBufferPtr[0]:7
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilBitCopy.DestBufferPtr[0]:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: IpduM_UtilMemCpy

-- Test Case: IpduM_UtilMemCpy.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilMemCpy
TEST.NEW
TEST.NAME:IpduM_UtilMemCpy.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_UtilMemCpy.DestPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilMemCpy.DestPtr[0]:0
TEST.VALUE:IpduM.IpduM_UtilMemCpy.SrcPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilMemCpy.SrcPtr[0]:7
TEST.VALUE:IpduM.IpduM_UtilMemCpy.Length:1
TEST.EXPECTED:IpduM.IpduM_UtilMemCpy.DestPtr[0]:7
TEST.END

-- Subprogram: IpduM_UtilMemSet

-- Test Case: IpduM_UtilMemSet.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilMemSet
TEST.NEW
TEST.NAME:IpduM_UtilMemSet.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_UtilMemSet.DestPtr:<<malloc 3>>
TEST.VALUE:IpduM.IpduM_UtilMemSet.DestPtr[0]:0
TEST.VALUE:IpduM.IpduM_UtilMemSet.DestPtr[1]:0
TEST.VALUE:IpduM.IpduM_UtilMemSet.DestPtr[2]:0
TEST.VALUE:IpduM.IpduM_UtilMemSet.Value:2
TEST.VALUE:IpduM.IpduM_UtilMemSet.Length:3
TEST.EXPECTED:IpduM.IpduM_UtilMemSet.DestPtr[0]:2
TEST.EXPECTED:IpduM.IpduM_UtilMemSet.DestPtr[1]:2
TEST.EXPECTED:IpduM.IpduM_UtilMemSet.DestPtr[2]:2
TEST.END

-- Subprogram: IpduM_UtilSetClearBitMask

-- Test Case: IpduM_UtilSetClearBitMask.001
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilSetClearBitMask
TEST.NEW
TEST.NAME:IpduM_UtilSetClearBitMask.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_UtilSetClearBitMask.DataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilSetClearBitMask.DataPtr[0]:0
TEST.VALUE:IpduM.IpduM_UtilSetClearBitMask.BitMask:7
TEST.VALUE:IpduM.IpduM_UtilSetClearBitMask.SetMode:TRUE
TEST.EXPECTED:IpduM.IpduM_UtilSetClearBitMask.DataPtr[0]:7
TEST.END

-- Test Case: IpduM_UtilSetClearBitMask.002
TEST.UNIT:IpduM
TEST.SUBPROGRAM:IpduM_UtilSetClearBitMask
TEST.NEW
TEST.NAME:IpduM_UtilSetClearBitMask.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::IpduM::IpduM_Detailed_Design::IpduM_Class_Diagram 
Requirement_DICVA-13788
TEST.END_NOTES:
TEST.VALUE:IpduM.IpduM_UtilSetClearBitMask.DataPtr:<<malloc 1>>
TEST.VALUE:IpduM.IpduM_UtilSetClearBitMask.DataPtr[0]:0xFF
TEST.VALUE:IpduM.IpduM_UtilSetClearBitMask.BitMask:7
TEST.VALUE:IpduM.IpduM_UtilSetClearBitMask.SetMode:FALSE
TEST.EXPECTED:IpduM.IpduM_UtilSetClearBitMask.DataPtr[0]:0xF8
TEST.END
